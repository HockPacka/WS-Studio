
ulonglong FUN_140253a90(longlong param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  float fVar7;
  uint auStackX_8 [2];
  longlong *plStackX_10;
  undefined8 in_stack_ffffffffffffff58;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 in_stack_ffffffffffffff60;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 in_stack_ffffffffffffff70;
  uint uVar14;
  ulonglong uVar13;
  undefined4 auStack_78 [2];
  longlong lStack_70;
  code *pcStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined8 uStack_3c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uVar1 = (uint)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  uVar14 = (uint)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  *(undefined4 *)(param_1 + 0x30) = 0x17;
  uVar6 = 0;
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x640) = DAT_140c77760;
  *(undefined4 *)(param_1 + 0x644) = DAT_140c77764;
  *(undefined4 *)(param_1 + 0x648) = DAT_140c77760;
  *(undefined4 *)(param_1 + 0x64c) = DAT_140c77764;
  *(undefined4 *)(param_1 + 0x650) = DAT_140c77760;
  *(undefined4 *)(param_1 + 0x654) = DAT_140c77764;
  puVar2 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x2d0))();
  uVar12 = *puVar2;
  *(undefined4 *)(param_1 + 0x660) = 0;
  *(undefined4 *)(param_1 + 0x658) = uVar12;
  uVar13 = (ulonglong)uVar14 << 0x20;
  uVar8 = CONCAT44(uVar5,0x100);
  lVar4 = (ulonglong)uVar1 << 0x20;
  uVar3 = (**(code **)(*DAT_140c65670 + 0x50))
                    (DAT_140c65670,L"Art\\Dev\\MaterialConstant.dds",0,1,lVar4,uVar8,0,uVar13,
                     param_1 + 0x6f0);
  if (-1 < (int)uVar3) {
    uVar13 = uVar13 & 0xffffffff00000000;
    uVar11 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x100);
    uVar8 = CONCAT44((int)((ulonglong)lVar4 >> 0x20),1);
    uVar3 = (**(code **)(*DAT_140c65670 + 0x50))
                      (DAT_140c65670,L"Art\\Dev\\MaterialData.dds",0,1,uVar8,uVar11,0,uVar13,
                       param_1 + 0x6f8);
    if (-1 < (int)uVar3) {
      uVar10 = param_1 + 0x700;
      uVar13 = uVar13 & 0xffffffff00000000;
      uVar11 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),0x100);
      uVar9 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
      uVar3 = (**(code **)(*DAT_140c65670 + 0x50))
                        (DAT_140c65670,L"Art\\Dev\\MaterialData.dds",0,1,uVar9,uVar11,0,uVar13,
                         uVar10);
      uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
      if (-1 < (int)uVar3) {
        lVar4 = (**(code **)(*DAT_140c65670 + 0x2c8))();
        uVar5 = 1;
        if (*(int *)(lVar4 + 0x54) != 0) {
          uVar5 = 4;
        }
        uVar10 = uVar10 & 0xffffffff00000000;
        uVar13 = uVar13 & 0xffffffff00000000;
        uVar9 = uVar9 & 0xffffffff00000000;
        uVar3 = (**(code **)(*DAT_140c65670 + 0x58))
                          (DAT_140c65670,0xc,2,1,uVar9,CONCAT44(uVar12,uVar5),0,uVar13,uVar10,
                           param_1 + 0x708);
        if (-1 < (int)uVar3) {
          uVar8 = CONCAT44((int)(uVar9 >> 0x20),0x14);
          uVar3 = (**(code **)(*DAT_140c65670 + 0x58))
                            (DAT_140c65670,0xc,2,1,uVar8,1,0,uVar13 & 0xffffffff00000000,
                             uVar10 & 0xffffffff00000000,param_1 + 0x710);
          if (-1 < (int)uVar3) {
            uVar13 = param_1 + 0x718;
            uVar10 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
            uVar3 = (**(code **)(*DAT_140c65670 + 0x70))
                              (DAT_140c65670,L"Art\\Dev\\SkyReflection.dds",0,1,uVar10,0x15,0,uVar13
                              );
            if (-1 < (int)uVar3) {
              plStackX_10 = (longlong *)0x0;
              uVar1 = (**(code **)(*DAT_140c65670 + 0x50))
                                (DAT_140c65670,L"Art\\Dev\\MaterialConstant.dds",0,0,
                                 uVar10 & 0xffffffff00000000,0x100,0,uVar13 & 0xffffffff00000000,
                                 &plStackX_10);
              uVar3 = (ulonglong)uVar1;
              if (-1 < (int)uVar1) {
                lVar4 = (**(code **)(*plStackX_10 + 0x18))();
                FUN_140052360(param_1 + 0x450,*(undefined4 *)(lVar4 + 8));
                lVar4 = (**(code **)(*plStackX_10 + 0x48))(plStackX_10,0,auStackX_8,1);
                if (lVar4 != 0) {
                  if (*(longlong *)(param_1 + 0x458) != 0) {
                    do {
                      fVar7 = (float)FUN_1401c9770(lVar4 + 8);
                      uVar6 = uVar6 + 1;
                      *(int *)(*(longlong *)(param_1 + 0x450) + -4 + uVar6 * 4) = (int)fVar7;
                      lVar4 = lVar4 + (ulonglong)auStackX_8[0];
                    } while (uVar6 < *(ulonglong *)(param_1 + 0x458));
                  }
                  if (plStackX_10 != (longlong *)0x0) {
                    (**(code **)(*plStackX_10 + 8))();
                  }
                  uStack_48 = 0xff7fffff;
                  uStack_58 = 0;
                  uStack_50 = 0;
                  uStack_3c = 1;
                  uStack_28 = 0x3f800000;
                  uStack_24 = 0x3f800000;
                  uStack_20 = 0x3f800000;
                  uStack_1c = 0x3f800000;
                  uStack_44 = 0x7f7fffff;
                  uStack_40 = 0;
                  uVar3 = (**(code **)(*DAT_140c65670 + 200))
                                    (DAT_140c65670,param_1 + 0x808,&uStack_58);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x40))
                                    (DAT_140c65670,0x48,0,1,param_1 + 0x810);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  lVar4 = param_1 + 0x818;
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,0x30,0,1,lVar4);
                  uVar12 = (undefined4)((ulonglong)lVar4 >> 0x20);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x80,1,param_1 + 0x820)
                  ;
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65680 + 0x20))
                                    (DAT_140c65680,L"Arial Unicode MS",7,0x3f800000,
                                     CONCAT44(uVar12,0x10),param_1 + 0x828);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0xb8))(DAT_140c65670,param_1 + 0x830);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\SimplePS.sho",param_1 + 0x838);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x90))
                                    (DAT_140c65670,L"Shaders\\SimpleVS.sho",param_1 + 0x840);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\fogSkyPS.sho",param_1 + 0x848);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\FillPS.sho",param_1 + 0x850);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x90))
                                    (DAT_140c65670,L"Shaders\\StencilVS.sho",param_1 + 0x858);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\StencilPS.sho",param_1 + 0x860);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\CompositePS.sho",param_1 + 0x868);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\TelegraphPS.sho",param_1 + 0x870);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\DecalPS.sho",param_1 + 0x878);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\LightPS.sho",param_1 + 0x880);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\LightSunSkyPS.sho",param_1 + 0x888);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x90))
                                    (DAT_140c65670,L"Shaders\\FogVS.sho",param_1 + 0x890);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\FogPS.sho",param_1 + 0x898);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\FogDepthPS.sho",param_1 + 0x8a0);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\PortalPS.sho",param_1 + 0x8a8);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\DebugPS.sho",param_1 + 0x8b0);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\Downsample1_2PS.sho",param_1 + 0x8b8);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\BrightPassPS.sho",param_1 + 0x8c0);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\GaussianBlurPS.sho",param_1 + 0x8c8);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\AccPS.sho",param_1 + 0x8d0);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\WorldPS.sho",param_1 + 0x8d8);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\scatterPS.sho",param_1 + 0x8e0);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\FxaaPS.sho",param_1 + 0x8e8);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0x98))
                                    (DAT_140c65670,L"Shaders\\LinearZPS.sho",param_1 + 0x8f0);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  uVar3 = (**(code **)(*DAT_140c65670 + 0xc0))(DAT_140c65670,param_1 + 0x8f8);
                  if ((int)uVar3 < 0) {
                    return uVar3;
                  }
                  pcStack_68 = FUN_140254390;
                  auStack_78[0] = 0;
                  uStack_60 = 0;
                  lStack_70 = param_1;
                  (**(code **)(**(longlong **)(param_1 + 0x8f8) + 0x18))
                            (*(longlong **)(param_1 + 0x8f8),0,auStack_78);
                  pcStack_68 = FUN_140001b70;
                  auStack_78[0] = 0;
                  uStack_60 = 0;
                  lStack_70 = param_1;
                  (**(code **)(**(longlong **)(param_1 + 0x8f8) + 0x18))
                            (*(longlong **)(param_1 + 0x8f8),1,auStack_78);
                  FUN_140254390(param_1);
                  *(undefined8 *)(param_1 + 0x918) = 0;
                  *(undefined8 *)(param_1 + 0x920) = 0;
                  *(undefined4 *)(param_1 + 0x928) = 0;
                  *(undefined4 *)(param_1 + 0x92c) = 0x3f800000;
                  *(undefined8 *)(param_1 + 0x930) = 0;
                  *(undefined8 *)(param_1 + 0x938) = 0;
                  *(undefined8 *)(param_1 + 0x940) = 0;
                  *(undefined8 *)(param_1 + 0x948) = 0;
                  *(undefined8 *)(param_1 + 0x950) = 0;
                  *(undefined8 *)(param_1 + 0x958) = 0;
                  *(undefined8 *)(param_1 + 0x960) = 7;
                  *(undefined8 *)(param_1 + 0x968) = 0;
                  *(undefined8 *)(param_1 + 0x970) = 0;
                  *(undefined8 *)(param_1 + 0x978) = 0;
                  *(undefined4 *)(param_1 + 0x980) = 7;
                  return 0;
                }
                uVar3 = 0x80004005;
              }
              if (plStackX_10 != (longlong *)0x0) {
                (**(code **)(*plStackX_10 + 8))();
              }
            }
          }
        }
      }
    }
  }
  return uVar3;
}

