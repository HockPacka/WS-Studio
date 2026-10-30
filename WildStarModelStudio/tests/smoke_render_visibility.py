"""Regression: a mocked working WebGL2 API must issue drawElements for M3 models.

Run with: PYTHONPATH=. python tests/smoke_render_visibility.py
Playwright/Chromium are development-time test dependencies, not required by the app.
"""
from pathlib import Path
from playwright.sync_api import sync_playwright
from native_m3 import read_m3_native
from tests.make_animation_demo import make_animated_demo

BASE = Path(__file__).resolve().parents[1]

with sync_playwright() as p:
    browser = p.chromium.launch(executable_path='/usr/bin/chromium', headless=True,
                                args=['--no-sandbox', '--disable-dev-shm-usage'])
    page = browser.new_page(viewport={'width': 1200, 'height': 800})
    errors = []
    page.on('pageerror', lambda error: errors.append(str(error)))
    html = (BASE / 'index.html').read_text().replace('<link rel="stylesheet" href="/style.css">', '')
    scripts = ['m3_explorer.js', 'material_animation.js', 'skeleton_animation.js', 'material_renderer.js', 'app.js']
    for script in scripts:
        html = html.replace(f'<script src="/{script}"></script>', '')
    page.set_content(html)
    page.add_style_tag(content=(BASE / 'style.css').read_text())
    page.evaluate("""() => {
      window.__draws=[];
      window.__skinUniforms=[];
      let lastTexture=0;
      const overrides={
        NO_ERROR:0, TEXTURE0:33984, TEXTURE_2D:3553,
        MAX_VERTEX_TEXTURE_IMAGE_UNITS:35660,MAX_TEXTURE_SIZE:3379,
        createShader:()=>({}), createProgram:()=>({}), createTexture:()=>({id:++lastTexture}),
        createVertexArray:()=>({}),createBuffer:()=>({}),
        getShaderParameter:()=>true,getProgramParameter:()=>true,
        getUniformLocation:(_,name)=>name,
        getParameter:()=>16384,getError:()=>0,
        drawElements:(...args)=>window.__draws.push(args),
        uniform1i:(name,v)=>{if(name==='uSkinning')window.__skinUniforms.push(v);}
      };
      const fake=new Proxy(overrides,{
        get(obj,key){if(key in obj)return obj[key];
          if(typeof key!=='string')return undefined;
          return key === key.toUpperCase() ? 1 : (...args)=>undefined;
        }
      });
      document.querySelector('#glcanvas').getContext=(mode)=>mode==='webgl2'?fake:null;
      window.fetch=async()=>({ok:true,json:async()=>({nativeM3:true,abi:2})});
    }""")
    for script in scripts:
        page.add_script_tag(content=(BASE / script).read_text())
    page.wait_for_timeout(200)
    model = read_m3_native(make_animated_demo(), 'AnimatedCrystal.m3')
    page.evaluate('(data)=>applyModel(data)', model)
    page.wait_for_timeout(300)
    assert page.evaluate('!!gl'), 'WebGL mock was not installed'
    draws = page.evaluate('window.__draws.length')
    assert draws >= 3, f'Expected 3 rendered meshes, got {draws}; errors={errors}'
    assert 1 in page.evaluate('window.__skinUniforms'), 'Skinning was not enabled for weighted meshes'
    # GPU failures must fall back to the static geometry rather than hiding the model.
    page.evaluate('''() => {
      window.__draws=[];window.__skinUniforms=[];
      const previous=window.WSSkeletonAnimation.evaluate;
      window.WSSkeletonAnimation.evaluate=()=>{throw Error('Simulierter Skinning-Fehler');};
      state.skinLastTime=NaN;
      state.skeletonEnabled=true;
      render(800);
      window.WSSkeletonAnimation.evaluate=previous;
    }''')
    assert page.evaluate('window.__draws.length') >= 3, 'Fallback failed to draw meshes'
    assert page.evaluate('state.skeletonEnabled === false'), 'Faulty GPU skinning was not disabled'
    assert 0 in page.evaluate('window.__skinUniforms'), 'Fallback did not disable vertex skinning'
    assert not errors, errors
    print('PASS: 3 M3 meshes rendered with skinning; failed skinning falls back to static geometry')
    browser.close()
