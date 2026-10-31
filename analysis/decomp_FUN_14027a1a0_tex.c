
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_14027a1a0(longlong param_1,short *param_2,longlong *param_3)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 extraout_XMM0_Da;
  undefined4 uVar12;
  undefined1 auStack_1a8 [32];
  int *local_188;
  undefined8 *local_180;
  longlong *local_178;
  undefined8 local_170;
  ulonglong local_168;
  undefined8 local_160;
  uint local_158;
  uint local_154;
  int local_150;
  uint local_14c;
  longlong *local_148;
  uint local_140;
  int local_13c;
  int local_138;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  undefined4 local_120;
  int local_11c;
  int local_118;
  undefined4 *local_110;
  undefined8 local_108;
  undefined4 local_100;
  int local_fc;
  short *local_f8;
  int *local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  uint local_d8;
  uint uStack_d4;
  int iStack_d0;
  int iStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 *puStack_a0;
  undefined8 local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  int iStack_64;
  undefined4 local_60;
  int iStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = DAT_140c0f7b0 ^ (ulonglong)auStack_1a8;
  if (((param_2 == (short *)0x0) || (*param_2 == 0)) || (param_3 == (longlong *)0x0)) {
    return -0x7ff8ffa9;
  }
  local_f8 = param_2;
  lVar4 = FUN_1407dd8d8(param_2,0x2e);
  if (lVar4 == 0) {
    return -0x7fffbffb;
  }
  iVar2 = FUN_14018e2c0(lVar4,L".tex");
  if (iVar2 != 0) {
    iVar2 = FUN_14018e2c0(lVar4,L".tga");
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = FUN_14018e2c0(lVar4,L".dds");
      if (iVar2 == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_14018e2c0(lVar4,L".png");
        if (iVar2 == 0) {
          iVar2 = 3;
        }
        else {
          iVar2 = FUN_14018e2c0(lVar4,L".bmp");
          if (iVar2 == 0) {
            iVar2 = 4;
          }
          else {
            iVar2 = FUN_14018e2c0(lVar4,L".jpg");
            if ((iVar2 != 0) && (iVar2 = FUN_14018e2c0(lVar4,L".jpeg"), iVar2 != 0)) {
              return -0x7fffbffb;
            }
            iVar2 = 5;
          }
        }
      }
    }
    uVar5 = 0;
    local_168 = 0;
    local_160 = 0;
    FUN_14003d8f0(&local_178,param_1 + 0x18e0);
    local_e8 = 0;
    uStack_e0 = 0;
    puVar9 = (undefined8 *)0x0;
    puStack_a0 = (undefined8 *)0x0;
    local_98 = 0;
    if (*(longlong *)(param_1 + 0x18c0) == 0) {
      iVar3 = -0x7ff8ffa9;
    }
    else {
      iVar3 = FUN_1402b40b0(*(longlong *)(param_1 + 0x18c0),*(undefined8 *)(param_1 + 0x18d0),
                            param_3,&local_e8);
      puVar9 = puStack_a0;
      if (-1 < iVar3) {
        if (iVar2 == 1) {
          if (puStack_a0[5] != 0) {
            iVar3 = FUN_1402b5460(puStack_a0,&local_168);
            uVar5 = local_160;
            goto joined_r0x00014027a48f;
          }
          iVar3 = -0x7fffbffd;
        }
        else if (iVar2 == 2) {
          local_50 = 0;
          uStack_4c = 0;
          local_78 = *puStack_a0;
          local_70 = puStack_a0[1];
          local_68 = 1;
          iStack_64 = 0;
          local_60 = 1;
          iStack_5c = 0;
          local_58 = 1;
          uStack_54 = 0;
          local_48 = CONCAT44(3,*(undefined4 *)(puStack_a0 + 2));
          iVar3 = FUN_1402b6eb0(puStack_a0,&local_78,&local_168);
          uVar5 = local_160;
joined_r0x00014027a48f:
          local_160 = uVar5;
          if (-1 < iVar3) {
LAB_14027a49a:
            if (puVar9 != (undefined8 *)0x0) {
              FUN_14018b900(puVar9,0);
            }
            if (local_98 != 0) {
              FUN_14018b900(local_98,0);
            }
            FUN_14003d880(&local_178);
            local_178 = (longlong *)0x0;
            iVar3 = FUN_1401c5810(local_168,uVar5,&local_178);
            plVar1 = local_178;
            if ((-1 < iVar3) && (iVar3 = FUN_1401b6f30(extraout_XMM0_Da,param_2), -1 < iVar3)) {
              if (plVar1 != (longlong *)0x0) {
                (**(code **)(*plVar1 + 8))(plVar1);
              }
              if (local_168 == 0) {
                return 0;
              }
              FUN_14018b900(local_168,0);
              return 0;
            }
            if (plVar1 != (longlong *)0x0) {
              (**(code **)(*plVar1 + 8))(plVar1);
            }
            goto LAB_14027a55e;
          }
        }
        else if (iVar2 == 3) {
          uVar5 = FUN_1402b2280(2);
          if (puVar9[5] != 0) {
LAB_14027a3e1:
            iVar3 = FUN_1402b7ed0(puVar9,uVar5,&local_168);
            uVar5 = local_160;
            goto joined_r0x00014027a48f;
          }
          iVar3 = -0x7fffbffd;
        }
        else if (iVar2 == 4) {
          uVar5 = FUN_1402b2280(0);
          if (puVar9[5] != 0) goto LAB_14027a3e1;
          iVar3 = -0x7fffbffd;
        }
        else {
          if (iVar2 != 5) goto LAB_14027a49a;
          uVar5 = FUN_1402b2280(1);
          if (puVar9[5] != 0) goto LAB_14027a3e1;
          iVar3 = -0x7fffbffd;
        }
      }
    }
    if (puVar9 != (undefined8 *)0x0) {
      FUN_14018b900(puVar9,0);
    }
    if (local_98 != 0) {
      FUN_14018b900(local_98,0);
    }
    FUN_14003d880(&local_178);
LAB_14027a55e:
    if (local_168 != 0) {
      FUN_14018b900(local_168,0);
    }
    return iVar3;
  }
  FUN_1407e4830(&local_e8,0,0x70);
  local_e8 = 0x300474658;
  local_c8 = 0;
  (**(code **)(*param_3 + 0x38))(param_3,&local_13c);
  local_178 = (longlong *)0x0;
  if (local_13c == 3) {
    (**(code **)(*param_3 + 0x50))(param_3,&local_78);
    local_154 = (uint)local_78;
    uStack_d4 = local_70._4_4_;
    local_158 = local_78._4_4_;
    uStack_e0 = local_78;
    local_150 = (uint)local_70;
    iStack_d0 = (uint)local_70;
    local_14c = 1;
    local_d8 = 1;
    iStack_cc = FUN_14027a000(local_68);
    iVar2 = (uint)local_70;
    uVar11 = local_70._4_4_;
    if (iStack_5c == 3) goto LAB_14027a74e;
    iStack_5c = 3;
    local_58 = 0;
    uStack_54 = 0x20000;
    local_50 = 0;
    iVar3 = (**(code **)(**(longlong **)(param_1 + 0x18c0) + 0x28))
                      (*(longlong **)(param_1 + 0x18c0),&local_78,0,&local_178);
    if (iVar3 < 0) {
      local_170 = 0x141de2cb0;
      goto LAB_14027a6f3;
    }
LAB_14027a712:
    plVar1 = local_178;
    if (local_178 != param_3) {
      FUN_14003d8f0(&local_170,param_1 + 0x18e0);
      (**(code **)(**(longlong **)(param_1 + 0x18d0) + 0x178))
                (*(longlong **)(param_1 + 0x18d0),local_178,param_3);
      FUN_14003d880(&local_170);
      plVar1 = local_178;
    }
  }
  else {
    if (local_13c != 4) {
      iVar3 = -0x7fffbffb;
      goto LAB_14027aa0d;
    }
    (**(code **)(*param_3 + 0x50))(param_3,&local_78);
    local_154 = (uint)local_78;
    local_150 = local_70._4_4_;
    local_158 = local_78._4_4_;
    uStack_e0 = local_78;
    uStack_d4 = 1;
    iStack_d0 = local_70._4_4_;
    local_14c = (uint)local_70;
    local_d8 = (uint)local_70;
    iStack_cc = FUN_14027a000(local_68);
    iVar2 = local_70._4_4_;
    uVar11 = 1;
    if (iStack_64 != 3) {
      iStack_64 = 3;
      local_60 = 0;
      iStack_5c = 0x20000;
      local_58 = 0;
      iVar3 = (**(code **)(**(longlong **)(param_1 + 0x18c0) + 0x30))
                        (*(longlong **)(param_1 + 0x18c0),&local_78,0,&local_178);
      if (-1 < iVar3) goto LAB_14027a712;
      local_170 = 0x141de2c18;
LAB_14027a6f3:
      FUN_1401a3130(0xe,2,&local_170,iVar3);
      goto LAB_14027aa0d;
    }
LAB_14027a74e:
    plVar1 = local_178;
    if ((local_178 != param_3) &&
       ((**(code **)(*param_3 + 8))(param_3), plVar1 = param_3, local_178 != (longlong *)0x0)) {
      (**(code **)(*local_178 + 0x10))();
      plVar1 = param_3;
    }
  }
  local_178 = plVar1;
  uVar5 = FUN_14029bdc0(&local_e8);
  local_148 = (longlong *)0x0;
  iVar3 = FUN_1401c5690(uVar5,&local_148,0);
  plVar1 = local_148;
  if (-1 < iVar3) {
    uVar5 = (**(code **)(*local_148 + 0x10))(local_148);
    uVar6 = (**(code **)(*plVar1 + 0x20))(plVar1);
    FUN_1407e4830(uVar6,0,uVar5);
    puVar9 = (undefined8 *)(**(code **)(*plVar1 + 0x20))(plVar1);
    *puVar9 = local_e8;
    puVar9[1] = uStack_e0;
    puVar9[2] = CONCAT44(uStack_d4,local_d8);
    puVar9[3] = CONCAT44(iStack_cc,iStack_d0);
    puVar9[4] = CONCAT44(uStack_c4,local_c8);
    puVar9[5] = uStack_c0;
    puVar9[6] = local_b8;
    puVar9[7] = uStack_b0;
    puVar9[8] = local_a8;
    puVar9[9] = puStack_a0;
    *(undefined4 *)(puVar9 + 10) = (undefined4)local_98;
    *(undefined4 *)((longlong)puVar9 + 0x54) = local_98._4_4_;
    *(undefined4 *)(puVar9 + 0xb) = uStack_90;
    *(undefined4 *)((longlong)puVar9 + 0x5c) = uStack_8c;
    *(undefined4 *)(puVar9 + 0xc) = local_88;
    *(undefined4 *)((longlong)puVar9 + 100) = uStack_84;
    *(undefined4 *)(puVar9 + 0xd) = uStack_80;
    *(undefined4 *)((longlong)puVar9 + 0x6c) = uStack_7c;
    FUN_14003d8f0(&local_170,param_1 + 0x18e0);
    lVar4 = (**(code **)(*plVar1 + 0x20))(plVar1);
    lVar4 = lVar4 + 0x70;
    if (iVar2 != 0) {
      local_124 = iStack_cc;
      puVar10 = &DAT_140ae5200 + (longlong)iStack_cc * 0xb;
      local_f0 = &DAT_140ae5224 + (longlong)iStack_cc * 0xb;
      local_110 = puVar10;
      do {
        iVar2 = iVar2 + -1;
        local_148 = (longlong *)CONCAT44(local_148._4_4_,iVar2);
        bVar7 = (byte)iVar2;
        local_130 = (local_154 >> (bVar7 & 0x1f)) + (uint)(local_154 >> (bVar7 & 0x1f) == 0);
        local_12c = (local_158 >> (bVar7 & 0x1f)) + (uint)(local_158 >> (bVar7 & 0x1f) == 0);
        local_138 = (local_14c >> (bVar7 & 0x1f)) + (uint)(local_14c >> (bVar7 & 0x1f) == 0);
        uVar8 = ((uint)(puVar10[1] + local_130) >> ((byte)puVar10[2] & 0x1f)) * *local_f0 + 3;
        iVar3 = ((uint)(puVar10[4] + local_12c) >> ((byte)puVar10[5] & 0x1f)) * (uVar8 & 0xfffffffc)
        ;
        local_168 = CONCAT44(iVar3,uVar8) & 0xfffffffffffffffc;
        local_140 = ((uint)(puVar10[7] + local_138) >> ((byte)puVar10[8] & 0x1f)) * iVar3;
        local_160 = CONCAT44(local_160._4_4_,local_140);
        local_128 = local_138;
        uVar8 = 0;
        if (uVar11 != 0) {
          do {
            local_180 = &local_108;
            local_188 = (int *)((ulonglong)local_188 & 0xffffffff00000000);
            iVar3 = (**(code **)(**(longlong **)(param_1 + 0x18d0) + 0x70))
                              (*(longlong **)(param_1 + 0x18d0),local_178,iVar2,1);
            puVar10 = local_110;
            if (iVar3 < 0) {
              FUN_14003d880(&local_170);
              goto LAB_14027a9fa;
            }
            local_120 = local_100;
            local_11c = local_fc;
            local_118 = ((uint)(local_110[7] + local_138) >> ((byte)local_110[8] & 0x1f)) * local_fc
            ;
            local_180 = (undefined8 *)&local_120;
            local_188 = &local_130;
            FUN_1402645d0(lVar4,&local_130,&local_168,local_108);
            (**(code **)(**(longlong **)(param_1 + 0x18d0) + 0x78))
                      (*(longlong **)(param_1 + 0x18d0),local_178,iVar2);
            iVar2 = iVar2 + local_150;
            uVar8 = uVar8 + 1;
            lVar4 = lVar4 + (ulonglong)local_140;
          } while (uVar8 < uStack_d4);
          uVar11 = uStack_d4;
          iVar2 = (int)local_148;
        }
      } while (iVar2 != 0);
    }
    uVar12 = FUN_14003d880(&local_170);
    iVar3 = FUN_1401b6f30(uVar12,local_f8);
    if (-1 < iVar3) {
      (**(code **)(*plVar1 + 8))(plVar1);
      if (local_178 != (longlong *)0x0) {
        (**(code **)(*local_178 + 0x10))();
      }
      return 0;
    }
  }
LAB_14027a9fa:
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))(plVar1);
  }
LAB_14027aa0d:
  if (local_178 != (longlong *)0x0) {
    (**(code **)(*local_178 + 0x10))(local_178);
    return iVar3;
  }
  return iVar3;
}

