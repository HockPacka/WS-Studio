"""Prove the animation fixture passes through the real ABI2 native DLL."""
import base64
import struct
import unittest
from tests.make_animation_demo import make_animated_demo
from native_m3 import read_m3_native

class TestSkeletonAnimationNative(unittest.TestCase):
 def test_synthetic_weighted_animated_asset(self):
  model=read_m3_native(make_animated_demo(),'AnimatedCrystal.m3')
  self.assertEqual(model['stats']['meshes'],3)
  self.assertEqual(len(model['m3Details']['bones']),1)
  for mesh in model['sections']:
   bones=base64.b64decode(mesh['boneIndices'])
   weights=base64.b64decode(mesh['boneWeights'])
   self.assertEqual(len(bones),mesh['vertices']*4)
   self.assertEqual(len(weights),mesh['vertices']*4)
   self.assertTrue(all(weights[i]==255 for i in range(0,len(weights),4)))
  trans=model['m3Details']['bones'][0]['tracks']['translation']
  self.assertEqual(trans['count'],2)
  self.assertEqual(struct.unpack('<2I',base64.b64decode(trans['times'])),(0,1500))
  self.assertAlmostEqual(struct.unpack('<6f',base64.b64decode(trans['values']))[3],1.7,places=5)
