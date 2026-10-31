
==== FUN_14034dc80 @ 14034dc80 size 3591 ====
CALLERS: FUN_14034cb80
CALLEES: FUN_140232e40 FUN_1403512d0 FUN_14034ea90 FUN_140032640 FUN_1401ae310 FUN_14018b280 FUN_14034ca50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14034dc80(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int *piVar8;
  uint uVar9;
  ulonglong uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined8 in_stack_fffffffffffffec8;
  undefined4 uVar15;
  ulonglong in_stack_fffffffffffffee8;
  uint local_108;
  uint local_104;
  longlong local_100;
  code *local_f8;
  undefined8 local_f0;
  uint local_e8;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined1 local_d0 [184];
  
  uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffec8 >> 0x20);
  puVar4 = (uint *)FUN_14034ca50(local_d0,&DAT_140c43e88,param_2);
  fVar14 = (float)puVar4[9];
  if ((float)puVar4[9] <= DAT_140c43e74) {
    fVar14 = DAT_140c43e74;
  }
  fVar13 = (float)puVar4[5];
  if (DAT_140c43e64 <= (float)puVar4[5]) {
    fVar13 = DAT_140c43e64;
  }
  fVar11 = (float)puVar4[2];
  if (DAT_140c43e58 <= (float)puVar4[2]) {
    fVar11 = DAT_140c43e58;
  }
  fVar12 = (float)puVar4[3];
  if (DAT_140c43e5c <= (float)puVar4[3]) {
    fVar12 = DAT_140c43e5c;
  }
  local_108 = *puVar4 & _DAT_140c43e50;
  local_104 = puVar4[1] & _DAT_140c43e54;
  uVar9 = puVar4[4];
  if ((int)DAT_140c43e60 < (int)puVar4[4]) {
    uVar9 = DAT_140c43e60;
  }
  uVar1 = puVar4[6];
  if ((int)DAT_140c43e68 < (int)puVar4[6]) {
    uVar1 = DAT_140c43e68;
  }
  local_f8 = (code *)CONCAT44(local_f8._4_4_,uVar9);
  uVar2 = puVar4[7];
  if ((int)DAT_140c43e6c < (int)puVar4[7]) {
    uVar2 = DAT_140c43e6c;
  }
  local_e8 = puVar4[8];
  if (puVar4[8] < DAT_140c43e70) {
    local_e8 = DAT_140c43e70;
  }
  local_f0 = CONCAT44(uVar2,uVar1);
  local_e0 = puVar4[10];
  if (DAT_140c43e78 < puVar4[10]) {
    local_e0 = DAT_140c43e78;
  }
  local_dc = puVar4[0xb];
  if (DAT_140c43e7c < puVar4[0xb]) {
    local_dc = DAT_140c43e7c;
  }
  local_d8 = puVar4[0xc];
  if (DAT_140c43e80 < puVar4[0xc]) {
    local_d8 = DAT_140c43e80;
  }
  *(uint *)(param_1 + 0x10) = local_108;
  *(uint *)(param_1 + 0x14) = local_104;
  *(float *)(param_1 + 0x18) = fVar11;
  *(float *)(param_1 + 0x1c) = fVar12;
  *(uint *)(param_1 + 0x20) = uVar9;
  *(float *)(param_1 + 0x24) = fVar13;
  *(uint *)(param_1 + 0x28) = uVar1;
  *(uint *)(param_1 + 0x2c) = uVar2;
  *(uint *)(param_1 + 0x30) = local_e8;
  *(float *)(param_1 + 0x34) = fVar14;
  *(uint *)(param_1 + 0x38) = local_e0;
  *(uint *)(param_1 + 0x3c) = local_dc;
  *(uint *)(param_1 + 0x40) = local_d8;
  lVar5 = (**(code **)(*DAT_140c65670 + 0x2c8))();
  uVar9 = *(uint *)(param_1 + 0x38);
  if (*(uint *)(lVar5 + 0x38) < *(uint *)(param_1 + 0x38)) {
    uVar9 = *(uint *)(lVar5 + 0x38);
  }
  *(uint *)(param_1 + 0x38) = uVar9;
  uVar9 = *(uint *)(param_1 + 0x3c);
  if (*(uint *)(lVar5 + 0x38) < *(uint *)(param_1 + 0x3c)) {
    uVar9 = *(uint *)(lVar5 + 0x38);
  }
  *(uint *)(param_1 + 0x3c) = uVar9;
  uVar9 = *(uint *)(param_1 + 0x40);
  if (*(uint *)(lVar5 + 0x38) < *(uint *)(param_1 + 0x40)) {
    uVar9 = *(uint *)(lVar5 + 0x38);
  }
  *(uint *)(param_1 + 0x40) = uVar9;
  uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                    (DAT_140c65670,L"Shaders\\SimpleVS.sho",param_1 + 0x50);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                    (DAT_140c65670,L"Shaders\\SimplePS.sho",param_1 + 0x58);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  uVar6 = (**(code **)(*DAT_140c65670 + 0x98))(DAT_140c65670,L"Shaders\\FillPS.sho",param_1 + 0x60);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if ((*(byte *)(param_1 + 0x10) & 4) != 0) {
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\LandVS.sho",param_1 + 0x68);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\LandPS.sho",param_1 + 0x70);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x884,1,param_1 + 0x78);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\landRoadTrailPS.sho",param_1 + 0x80);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\LandDepthVS.sho",param_1 + 0x88);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\LandDepthPS.sho",param_1 + 0x90);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
  }
  if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\LandWaterDepthVS.sho",param_1 + 0x98);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\LandWaterDepthPS.sho",param_1 + 0xa0);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\LandWaterVS.sho",param_1 + 0xa8);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\LandWaterPS.sho",param_1 + 0xb0);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\LightShaftVS.sho",param_1 + 400);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\LightShaftPS.sho",param_1 + 0x198);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
      uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                        (DAT_140c65670,L"Shaders\\OceanDepthVS.sho",param_1 + 0xb8);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                        (DAT_140c65670,L"Shaders\\OceanDepthPS.sho",param_1 + 0xc0);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                        (DAT_140c65670,L"Shaders\\OceanVS.sho",param_1 + 200);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                        (DAT_140c65670,L"Shaders\\OceanPS.sho",param_1 + 0xd0);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar6 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x40,1,param_1 + 0xd8);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
    }
  }
  if ((*(uint *)(param_1 + 0x10) & 0x4001) == 0x4001) {
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\ClutterVS.sho",param_1 + 0x140);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\ClutterPS.sho",param_1 + 0x148);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
  }
  if (((*(uint *)(param_1 + 0x14) & 0x4000000) != 0) &&
     (uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                        (DAT_140c65670,L"Shaders\\TopoMapPS.sho",param_1 + 0x150), (int)uVar6 < 0))
  {
    return uVar6;
  }
  uVar10 = 0;
  if ((*(uint *)(param_1 + 0x10) & 0x880) == 0x880) {
    in_stack_fffffffffffffee8 = param_1 + 0x180;
    uVar6 = (**(code **)(*DAT_140c65670 + 0x50))
                      (DAT_140c65670,L"Art\\Dev\\Default_Shadow_Blob.tex",0,1,CONCAT44(uVar15,1),0,0
                       ,0,in_stack_fffffffffffffee8);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
  }
  if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
    if ((*(byte *)(param_1 + 0x14) & 0x88) != 0) {
      uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                        (DAT_140c65670,L"Shaders\\LandEdgeVS.sho",param_1 + 0xe0);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                        (DAT_140c65670,L"Shaders\\LandEdgePS.sho",param_1 + 0xe8);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      iVar3 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,0x1800,0,1,param_1 + 0xf0);
      if (iVar3 < 0) {
        return 0xa0140001;
      }
    }
    if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
      if (((*(uint *)(param_1 + 0x14) & 0x2200004) != 0) &&
         (uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\LandGridPS.sho",param_1 + 0xf8),
         (int)uVar6 < 0)) {
        return uVar6;
      }
      if ((((*(byte *)(param_1 + 0x10) & 1) != 0) && ((*(uint *)(param_1 + 0x14) & 0x200) != 0)) &&
         (uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\LandSlopePS.sho",param_1 + 0x100),
         (int)uVar6 < 0)) {
        return uVar6;
      }
    }
  }
  if (((byte)*(undefined4 *)(param_1 + 0x10) & 9) == 9) {
    uVar6 = (**(code **)(*DAT_140c65670 + 0x90))
                      (DAT_140c65670,L"Shaders\\LandLowVS.sho",param_1 + 0x108);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                      (DAT_140c65670,L"Shaders\\LandLowPS.sho",param_1 + 0x110);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x2648,1,param_1 + 0x118);
    uVar7 = uVar10;
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    do {
      iVar3 = (**(code **)(*DAT_140c65670 + 0x40))
                        (DAT_140c65670,0x360c,0,1,param_1 + (uVar7 + 0x24) * 8);
      if (iVar3 < 0) {
        return 0xa0140001;
      }
      uVar9 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar9;
    } while (uVar9 < 4);
  }
  iVar3 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,0x48,0,1,param_1 + 0x158);
  if (-1 < iVar3) {
    uVar7 = param_1 + 0x160;
    iVar3 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,0x30,0,1,uVar7);
    if (-1 < iVar3) {
      in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;
      uVar7 = uVar7 & 0xffffffff00000000;
      uVar6 = (**(code **)(*DAT_140c65670 + 0x58))
                        (DAT_140c65670,1,1,0,uVar7,1,0,0,in_stack_fffffffffffffee8,param_1 + 0x168);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;
      uVar7 = uVar7 & 0xffffffff00000000;
      uVar6 = (**(code **)(*DAT_140c65670 + 0x58))
                        (DAT_140c65670,1,1,0,uVar7,1,0,0,in_stack_fffffffffffffee8,param_1 + 0x170);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      in_stack_fffffffffffffee8 = in_stack_fffffffffffffee8 & 0xffffffff00000000;
      uVar6 = (**(code **)(*DAT_140c65670 + 0x58))
                        (DAT_140c65670,1,1,0,uVar7 & 0xffffffff00000000,1,0,0,
                         in_stack_fffffffffffffee8,param_1 + 0x178);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      *(undefined4 *)(param_1 + 0x1a8) = 0x22;
      *(undefined4 *)(param_1 + 0x1b8) = 0xc0;
      uVar6 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x330,1,param_1 + 0x1a0);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar7 = param_1 + 0x1b0;
      uVar6 = (**(code **)(*DAT_140c65670 + 0x40))
                        (DAT_140c65670,*(int *)(param_1 + 0x1b8) * 2,0,1,uVar7);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      if (((*(byte *)(param_1 + 0x10) & 0x10) != 0) &&
         (uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\RipplePS.sho",param_1 + 0x188), (int)uVar6 < 0
         )) {
        return uVar6;
      }
      if (((*(byte *)(param_1 + 0x10) & 1) != 0) &&
         (uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\edgePS.sho",param_1 + 0x1c0), (int)uVar6 < 0))
      {
        return uVar6;
      }
      if ((*(uint *)(param_1 + 0x10) & 0x4800) != 0) {
        uVar7 = param_1 + 0x1c8;
        uVar6 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,12000,0,1,uVar7);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\WindSine2dPS.sho",param_1 + 0x1d0);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\WindLocalPS.sho",param_1 + 0x1d8);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\WindPhysicsPS.sho",param_1 + 0x1e0);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\WindVisualPS.sho",param_1 + 0x1e8);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      uVar15 = (undefined4)(uVar7 >> 0x20);
      if ((*(uint *)(param_1 + 0x14) & 0x1800000) != 0) {
        uVar7 = uVar7 & 0xffffffff00000000;
        uVar6 = (**(code **)(*DAT_140c65670 + 0x58))
                          (DAT_140c65670,0x100,1,1,uVar7,1,0,0,
                           in_stack_fffffffffffffee8 & 0xffffffff00000000,param_1 + 0x1f0);
        uVar15 = (undefined4)(uVar7 >> 0x20);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      if ((*(uint *)(param_1 + 0x14) & 0x100000) != 0) {
        lVar5 = param_1 + 0x1f8;
        uVar6 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,0x1800,0,1,lVar5);
        uVar15 = (undefined4)((ulonglong)lVar5 >> 0x20);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      if (((*(uint *)(param_1 + 0x10) & 0x20001) == 0x20001) &&
         (lVar5 = (**(code **)(*DAT_140c65670 + 0x2c8))(), *(int *)(lVar5 + 0x50) == 0)) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffdffff;
      }
      if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
        uVar6 = (**(code **)(*DAT_140c65670 + 0x50))
                          (DAT_140c65670,L"Art\\Dev\\TelegraphGray_Ramp.tex",0,1,CONCAT44(uVar15,1),
                           0,0,0,param_1 + 0x200);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\TelegraphColorPS.sho",param_1 + 0x208);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      }
      if ((ulonglong *)(param_1 + 0x48) == (ulonglong *)0x0) {
        return 0x80004003;
      }
      lVar5 = FUN_14018b280(0x18);
      uVar7 = uVar10;
      if (lVar5 != 0) {
        uVar7 = FUN_1401ae310(lVar5);
      }
      *(ulonglong *)(param_1 + 0x48) = uVar7;
      lVar5 = FUN_140232e40(2);
      if (lVar5 != 0) {
        *(undefined4 *)(param_1 + 0xb00) = *(undefined4 *)(lVar5 + 4);
      }
      (**(code **)(*DAT_140c65670 + 0x2c8))();
      *(undefined4 *)(param_1 + 0x238) = 0;
      *(undefined4 *)(param_1 + 0x23c) = 1;
      *(undefined4 *)(param_1 + 0x240) = 2;
      *(undefined4 *)(param_1 + 0x244) = 7;
      *(undefined4 *)(param_1 + 0x248) = 7;
      *(undefined4 *)(param_1 + 0x24c) = 8;
      *(undefined4 *)(param_1 + 0x250) = 7;
      *(undefined4 *)(param_1 + 0x254) = 7;
      *(undefined4 *)(param_1 + 600) = 4;
      *(undefined4 *)(param_1 + 0x25c) = 3;
      *(undefined4 *)(param_1 + 0x260) = 6;
      uVar6 = (**(code **)(*DAT_140c65670 + 0xb8))(DAT_140c65670,param_1 + 0x210);
      if (-1 < (int)uVar6) {
        uVar6 = (**(code **)(*DAT_140c65670 + 0xc0))(DAT_140c65670,param_1 + 0x218);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        local_f8 = FUN_14034ea90;
        local_108 = 0;
        local_f0 = 0;
        local_100 = param_1;
        (**(code **)(**(longlong **)(param_1 + 0x218) + 0x18))
                  (*(longlong **)(param_1 + 0x218),0,&local_108);
        local_f8 = (code *)&LAB_140350400;
        local_108 = 0;
        local_f0 = 0;
        local_100 = param_1;
        (**(code **)(**(longlong **)(param_1 + 0x218) + 0x18))
                  (*(longlong **)(param_1 + 0x218),1,&local_108);
        FUN_14034ea90(param_1);
        uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\VisualizeEnvMapPS.sho",param_1 + 0x220);
        if (-1 < (int)uVar6) {
          uVar6 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\SampleCubeMapPS.sho",param_1 + 0x228);
          if (-1 < (int)uVar6) {
            lVar5 = param_1 + 0x4ec;
            do {
              FUN_1403512d0(lVar5 + -0xc,uVar10);
              piVar8 = (int *)FUN_140032640(param_1 + 0xae0,lVar5);
              lVar5 = lVar5 + 0x80;
              *piVar8 = (int)uVar10;
              uVar9 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar9;
            } while (uVar9 < 0xc);
            *(undefined4 *)(param_1 + 0x44) = 0;
            return 0;
          }
          return uVar6;
        }
        return uVar6;
      }
      return uVar6;
    }
  }
  return 0xa0140001;
}



==== FUN_14024aea0 @ 14024aea0 size 515 ====
CALLERS: FUN_140010240 FUN_14024b100 FUN_14024b0b0 FUN_14024b160
CALLEES: FUN_1407be740 FUN_1407c1390 FUN_1407c1090 FUN_1401e84a0 FUN_14018b280 FUN_1407c0c50 FUN_1407befc0

int FUN_14024aea0(void)

{
  undefined8 *puVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)0x0;
  if (DAT_140c65348 == (longlong *)0x0) {
    if ((DAT_140c63970 == (undefined8 *)0x0) || (iVar2 = FUN_1401e84a0(L"WorldClutter"), iVar2 == 0)
       ) {
      iVar2 = DAT_140c1e48c;
      if (DAT_140c64c84 != 0) {
        iVar2 = DAT_140c63c44;
      }
      if (iVar2 == 0) {
        plVar3 = (longlong *)FUN_14018b280(0x30);
        if (plVar3 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 1) = 1;
          plVar3[3] = 0;
          *plVar3 = (longlong)&PTR_FUN_140b798c0;
          plVar3[4] = 0;
          plVar3[2] = (longlong)&PTR_u_WorldClutter_140a71a80;
          plVar3[5] = 0;
          plVar5 = plVar3;
        }
        iVar2 = (**(code **)(*plVar5 + 0x60))(plVar5,L"DB\\WorldClutter.tbl");
        if (iVar2 < 0) {
          (**(code **)(*plVar5 + 8))(plVar5);
          return iVar2;
        }
      }
      else {
        plVar3 = (longlong *)FUN_14018b280(0x30);
        if (plVar3 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 1) = 1;
          plVar3[3] = 0;
          plVar3[2] = (longlong)&PTR_u_WorldClutter_140a71a80;
          plVar3[4] = 0;
          *plVar3 = (longlong)&PTR_FUN_140b79850;
          plVar3[5] = 0;
          plVar5 = plVar3;
        }
        lVar4 = FUN_1407c0c50((&DAT_140c66660)[DAT_140c66658],plVar5[2]);
        plVar5[5] = lVar4;
        if (lVar4 == 0) {
          (**(code **)(*plVar5 + 8))(plVar5);
          return -0x7fffbffb;
        }
      }
    }
    else {
      plVar3 = (longlong *)FUN_14018b280(0x50,0);
      puVar1 = DAT_140c63970;
      if (plVar3 != (longlong *)0x0) {
        *(undefined4 *)(plVar3 + 1) = 1;
        *plVar3 = (longlong)&PTR_FUN_140b79650;
        *(undefined4 *)(plVar3 + 4) = 0;
        plVar3[2] = (longlong)puVar1;
        plVar3[5] = 0;
        *(undefined4 *)(plVar3 + 6) = 0;
        plVar3[3] = (longlong)&PTR_u_WorldClutter_140a71a80;
        plVar3[7] = 0;
        plVar3[8] = 0;
        *(undefined4 *)(plVar3 + 9) = 0;
        (**(code **)*puVar1)();
        plVar5 = plVar3;
      }
      iVar2 = FUN_1407befc0(plVar5,0);
      if (iVar2 < 0) {
        if (plVar5 == (longlong *)0x0) {
          return iVar2;
        }
        (**(code **)(*plVar5 + 8))(plVar5);
        return iVar2;
      }
    }
    DAT_140c65348 = plVar5;
    if (plVar5 == (longlong *)0x0) {
      return 0;
    }
  }
  DAT_140c64e10 = 0;
  return 0;
}



==== FUN_140268120 @ 140268120 size 1798 ====
CALLERS: FUN_1402e8680
CALLEES: FUN_1407e4830 FUN_140267380 __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140268120(undefined8 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  longlong lVar16;
  undefined4 *puVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  uint uVar20;
  float *pfVar21;
  float *pfVar22;
  uint uVar23;
  ulonglong uVar24;
  float fVar25;
  undefined1 auStack_1d8 [32];
  uint local_1b8;
  float local_1a8 [16];
  undefined4 local_168 [7];
  float local_14c [57];
  ulonglong local_68;
  
  local_68 = DAT_140c0f7b0 ^ (ulonglong)auStack_1d8;
  lVar16 = 0x10;
  puVar17 = param_2;
  do {
    uVar3 = *puVar17;
    uVar4 = puVar17[1];
    uVar5 = puVar17[2];
    uVar6 = puVar17[3];
    puVar17 = puVar17 + 4;
    puVar2 = (undefined4 *)((longlong)local_1a8 + (0x30 - (longlong)param_2) + (longlong)puVar17);
    *puVar2 = uVar3;
    puVar2[1] = uVar4;
    puVar2[2] = uVar5;
    puVar2[3] = uVar6;
    lVar16 = lVar16 + -1;
  } while (lVar16 != 0);
  *param_1 = 0;
  uVar20 = param_3 & 0x20000;
  if (uVar20 != 0) {
    FUN_1407e4830(local_1a8,0,0x40);
  }
  fVar13 = DAT_140b7a040;
  fVar12 = DAT_140b79e48;
  fVar11 = DAT_140b79e3c;
  fVar10 = DAT_140b79e14;
  fVar9 = DAT_140b79de0;
  fVar8 = DAT_140b79d94;
  fVar7 = DAT_140b79d90;
  pfVar22 = local_1a8 + 1;
  pfVar21 = local_14c;
  uVar24 = 3;
  do {
    fVar25 = pfVar21[-4];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[-1];
    }
    uVar19 = uVar24 - 3;
    uVar23 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + (uVar19 >> 3) * 4) =
         *(uint *)((longlong)param_1 + (uVar19 >> 3) * 4) >> 4 | uVar23 << 0x1c;
    if (uVar20 != 0) {
      uVar14 = (uint)uVar19 & 3;
      fVar25 = fVar25 - (float)uVar23 * fVar8;
      if (uVar14 != 3) {
        *pfVar22 = fVar25 * fVar11 + *pfVar22;
      }
      if (uVar19 < 0xc) {
        if ((uVar19 & 3) != 0) {
          pfVar22[2] = fVar25 * fVar9 + pfVar22[2];
        }
        pfVar22[3] = fVar25 * fVar10 + pfVar22[3];
        if (uVar14 != 3) {
          pfVar22[4] = fVar25 * fVar7 + pfVar22[4];
        }
      }
    }
    fVar25 = *pfVar21;
    if (uVar20 != 0) {
      fVar25 = fVar25 + *pfVar22;
    }
    uVar1 = uVar24 - 2;
    uVar23 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + (uVar1 >> 3) * 4) =
         *(uint *)((longlong)param_1 + (uVar1 >> 3) * 4) >> 4 | uVar23 << 0x1c;
    if (uVar20 != 0) {
      uVar14 = (uint)uVar1 & 3;
      fVar25 = fVar25 - (float)uVar23 * fVar8;
      if (uVar14 != 3) {
        pfVar22[1] = fVar25 * fVar11 + pfVar22[1];
      }
      if (uVar1 < 0xc) {
        if ((uVar1 & 3) != 0) {
          pfVar22[3] = fVar25 * fVar9 + pfVar22[3];
        }
        pfVar22[4] = fVar25 * fVar10 + pfVar22[4];
        if (uVar14 != 3) {
          pfVar22[5] = fVar25 * fVar7 + pfVar22[5];
        }
      }
    }
    fVar25 = pfVar21[4];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[1];
    }
    uVar18 = uVar24 - 1 >> 3;
    uVar14 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + uVar18 * 4) =
         uVar14 << 0x1c | *(uint *)((longlong)param_1 + uVar18 * 4) >> 4;
    uVar23 = (uint)uVar24;
    if (uVar20 != 0) {
      uVar15 = uVar23 - 1 & 3;
      fVar25 = fVar25 - (float)uVar14 * fVar8;
      if (uVar15 != 3) {
        pfVar22[2] = fVar25 * fVar11 + pfVar22[2];
      }
      if (uVar24 - 1 < 0xc) {
        if (uVar15 != 0) {
          pfVar22[4] = fVar25 * fVar9 + pfVar22[4];
        }
        pfVar22[5] = fVar25 * fVar10 + pfVar22[5];
        if (uVar15 != 3) {
          pfVar22[6] = fVar25 * fVar7 + pfVar22[6];
        }
      }
    }
    fVar25 = pfVar21[8];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[2];
    }
    uVar14 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + (uVar24 >> 3) * 4) =
         uVar14 << 0x1c | *(uint *)((longlong)param_1 + (uVar24 >> 3) * 4) >> 4;
    if (uVar20 != 0) {
      fVar25 = fVar25 - (float)uVar14 * fVar8;
      if ((uVar23 & 3) != 3) {
        pfVar22[3] = fVar25 * fVar11 + pfVar22[3];
      }
      if (uVar24 < 0xc) {
        if ((uVar24 & 3) != 0) {
          pfVar22[5] = fVar25 * fVar9 + pfVar22[5];
        }
        pfVar22[6] = fVar25 * fVar10 + pfVar22[6];
        if ((uVar23 & 3) != 3) {
          pfVar22[7] = fVar25 * fVar7 + pfVar22[7];
        }
      }
    }
    fVar25 = pfVar21[0xc];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[3];
    }
    uVar18 = uVar24 + 1 >> 3;
    uVar14 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + uVar18 * 4) =
         *(uint *)((longlong)param_1 + uVar18 * 4) >> 4 | uVar14 << 0x1c;
    if (uVar20 != 0) {
      uVar15 = (uint)uVar19 & 3;
      fVar25 = fVar25 - (float)uVar14 * fVar8;
      if (uVar15 != 3) {
        pfVar22[4] = fVar25 * fVar11 + pfVar22[4];
      }
      if (uVar24 + 1 < 0xc) {
        if ((uVar19 & 3) != 0) {
          pfVar22[6] = fVar25 * fVar9 + pfVar22[6];
        }
        pfVar22[7] = fVar25 * fVar10 + pfVar22[7];
        if (uVar15 != 3) {
          pfVar22[8] = fVar25 * fVar7 + pfVar22[8];
        }
      }
    }
    fVar25 = pfVar21[0x10];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[4];
    }
    uVar19 = uVar24 + 2 >> 3;
    uVar14 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + uVar19 * 4) =
         *(uint *)((longlong)param_1 + uVar19 * 4) >> 4 | uVar14 << 0x1c;
    if (uVar20 != 0) {
      uVar15 = (uint)uVar1 & 3;
      fVar25 = fVar25 - (float)uVar14 * fVar8;
      if (uVar15 != 3) {
        pfVar22[5] = fVar25 * fVar11 + pfVar22[5];
      }
      if (uVar24 + 2 < 0xc) {
        if ((uVar1 & 3) != 0) {
          pfVar22[7] = fVar25 * fVar9 + pfVar22[7];
        }
        pfVar22[8] = fVar25 * fVar10 + pfVar22[8];
        if (uVar15 != 3) {
          pfVar22[9] = fVar25 * fVar7 + pfVar22[9];
        }
      }
    }
    fVar25 = pfVar21[0x14];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[5];
    }
    uVar19 = uVar24 + 3 >> 3;
    uVar14 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + uVar19 * 4) =
         *(uint *)((longlong)param_1 + uVar19 * 4) >> 4 | uVar14 << 0x1c;
    if (uVar20 != 0) {
      uVar15 = uVar23 - 1 & 3;
      fVar25 = fVar25 - (float)uVar14 * fVar8;
      if (uVar15 != 3) {
        pfVar22[6] = fVar25 * fVar11 + pfVar22[6];
      }
      if (uVar24 + 3 < 0xc) {
        if (uVar15 != 0) {
          pfVar22[8] = fVar25 * fVar9 + pfVar22[8];
        }
        pfVar22[9] = fVar25 * fVar10 + pfVar22[9];
        if (uVar15 != 3) {
          pfVar22[10] = fVar25 * fVar7 + pfVar22[10];
        }
      }
    }
    fVar25 = pfVar21[0x18];
    if (uVar20 != 0) {
      fVar25 = fVar25 + pfVar22[6];
    }
    uVar19 = uVar24 + 4 >> 3;
    uVar14 = (uint)(fVar25 * fVar13 + fVar12);
    *(uint *)((longlong)param_1 + uVar19 * 4) =
         uVar14 << 0x1c | *(uint *)((longlong)param_1 + uVar19 * 4) >> 4;
    if (uVar20 != 0) {
      fVar25 = fVar25 - (float)uVar14 * fVar8;
      if ((uVar23 & 3) != 3) {
        pfVar22[7] = fVar25 * fVar11 + pfVar22[7];
      }
      if (uVar24 + 4 < 0xc) {
        if ((uVar24 & 3) != 0) {
          pfVar22[9] = fVar25 * fVar9 + pfVar22[9];
        }
        pfVar22[10] = fVar25 * fVar10 + pfVar22[10];
        if ((uVar23 & 3) != 3) {
          pfVar22[0xb] = fVar25 * fVar7 + pfVar22[0xb];
        }
      }
    }
    pfVar21 = pfVar21 + 0x20;
    pfVar22 = pfVar22 + 8;
    uVar19 = uVar24 + 5;
    uVar24 = uVar24 + 8;
  } while (uVar19 < 0x10);
  local_1b8 = param_3;
  FUN_140267380(param_1 + 1,local_168,0,0);
  return;
}


