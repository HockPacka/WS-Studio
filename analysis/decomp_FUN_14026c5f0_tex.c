
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_14026c5f0(short *param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  byte bVar10;
  ulonglong uVar11;
  longlong *plVar12;
  uint uVar13;
  longlong *plVar14;
  ulonglong uVar15;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 extraout_XMM0_Da_01;
  undefined4 extraout_XMM0_Da_02;
  undefined4 extraout_XMM0_Da_03;
  undefined1 auStack_208 [32];
  int *local_1e8;
  int *local_1e0;
  longlong *local_1d8;
  longlong *local_1d0;
  int local_1c8;
  uint local_1c4;
  uint local_1c0;
  uint local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  uint local_1a0;
  int local_19c;
  uint local_198;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  undefined8 local_160;
  short *local_158;
  undefined4 *local_150;
  int local_148 [2];
  undefined8 local_140;
  undefined4 local_138;
  undefined4 uStack_134;
  uint uStack_130;
  uint uStack_12c;
  uint local_128;
  uint uStack_124;
  int iStack_120;
  int iStack_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  int local_c8 [2];
  undefined8 local_c0;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  int local_a8 [6];
  uint local_90;
  uint local_8c;
  undefined1 local_88 [32];
  undefined1 local_68 [32];
  ulonglong local_48;
  
  local_48 = DAT_140c0f7b0 ^ (ulonglong)auStack_208;
  if (((param_1 == (short *)0x0) || (param_2 == (longlong *)0x0)) || (*param_1 == 0)) {
    return 0x80070057;
  }
  local_158 = param_1;
  lVar5 = FUN_1407dd8d8(param_1,0x2e);
  uVar11 = 0;
  if (lVar5 == 0) {
    uVar11 = 4;
LAB_14026cca3:
    local_1d8 = (longlong *)0x0;
    if (DAT_140c656e8 == (code *)0x0) {
      uVar11 = 0x80070057;
    }
    else {
      uVar13 = (*DAT_140c656e8)(&local_1d8,uVar11,param_2,0);
      plVar1 = local_1d8;
      uVar11 = (ulonglong)uVar13;
      if (-1 < (int)uVar13) {
        local_1d0 = (longlong *)0x0;
        uVar4 = (**(code **)(*local_1d8 + 0x20))(local_1d8);
        uVar7 = (**(code **)(*plVar1 + 0x18))(plVar1);
        uVar13 = FUN_1401c5810(uVar7,uVar4,&local_1d0);
        plVar1 = local_1d0;
        if ((-1 < (int)uVar13) &&
           (uVar13 = FUN_1401b6f30(extraout_XMM0_Da_03,param_1), -1 < (int)uVar13)) {
          if (plVar1 != (longlong *)0x0) {
            (**(code **)(*plVar1 + 8))(plVar1);
          }
          if (local_1d8 != (longlong *)0x0) {
            (**(code **)(*local_1d8 + 0x10))();
          }
          return 0;
        }
        uVar11 = (ulonglong)uVar13;
        if (plVar1 != (longlong *)0x0) {
          (**(code **)(*plVar1 + 8))(plVar1);
        }
      }
    }
    if (local_1d8 != (longlong *)0x0) {
      (**(code **)(*local_1d8 + 0x10))(local_1d8);
    }
    return uVar11;
  }
  iVar2 = FUN_14018e2c0(lVar5,L".tex");
  if (iVar2 != 0) {
    iVar2 = FUN_14018e2c0(lVar5,L".bmp");
    if (iVar2 != 0) {
      iVar2 = FUN_14018e2c0(lVar5,L".jpg");
      if (iVar2 == 0) {
        uVar11 = 1;
      }
      else {
        iVar2 = FUN_14018e2c0(lVar5,L".tga");
        if (iVar2 == 0) {
          uVar11 = 2;
        }
        else {
          iVar2 = FUN_14018e2c0(lVar5,L".png");
          if (iVar2 == 0) {
            uVar11 = 3;
          }
          else {
            iVar2 = FUN_14018e2c0(lVar5,L".hdr");
            uVar11 = 4;
            if (iVar2 == 0) {
              uVar11 = 7;
            }
          }
        }
      }
    }
    goto LAB_14026cca3;
  }
  FUN_1407e4830(&local_138,0,0x70);
  local_138 = 0x474658;
  uStack_134 = 3;
  iVar2 = (**(code **)(*param_2 + 0x68))(param_2);
  local_118 = 0;
  iStack_120 = iVar2;
  local_190 = (**(code **)(*param_2 + 0x50))(param_2);
  if (local_190 == 3) {
    uVar6 = (**(code **)(*param_2 + 0x88))(param_2,0,local_a8);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar13 = 1;
LAB_14026c77c:
    local_128 = 1;
    uStack_130 = local_90;
    uStack_12c = local_8c;
  }
  else {
    if (local_190 != 4) {
      if (local_190 != 5) {
        local_1c4 = uStack_12c;
        local_1c0 = uStack_130;
        uVar13 = uStack_124;
        goto LAB_14026c7a5;
      }
      uVar6 = (**(code **)(*param_2 + 0x88))(param_2,0,local_a8);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      uVar13 = 6;
      goto LAB_14026c77c;
    }
    uVar6 = (**(code **)(*param_2 + 0x88))(param_2,0,local_c8);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar13 = 1;
    uStack_130 = local_b8;
    uStack_12c = local_b4;
    local_128 = local_b0;
    local_a8[0] = local_c8[0];
  }
  local_1c4 = uStack_12c;
  local_1c0 = uStack_130;
  uStack_124 = uVar13;
  iStack_11c = FUN_14026c430(local_a8[0]);
LAB_14026c7a5:
  uVar7 = FUN_14029bdc0(&local_138);
  local_1d0 = (longlong *)0x0;
  uVar3 = FUN_1401c5690(uVar7,&local_1d0,0);
  plVar1 = local_1d0;
  uVar6 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar7 = (**(code **)(*local_1d0 + 0x10))(local_1d0);
    uVar8 = (**(code **)(*plVar1 + 0x20))(plVar1);
    FUN_1407e4830(uVar8,0,uVar7);
    puVar9 = (undefined8 *)(**(code **)(*plVar1 + 0x20))(plVar1);
    *puVar9 = CONCAT44(uStack_134,local_138);
    puVar9[1] = CONCAT44(uStack_12c,uStack_130);
    puVar9[2] = CONCAT44(uStack_124,local_128);
    puVar9[3] = CONCAT44(iStack_11c,iStack_120);
    puVar9[4] = CONCAT44(uStack_114,local_118);
    puVar9[5] = uStack_110;
    puVar9[6] = local_108;
    puVar9[7] = uStack_100;
    puVar9[8] = local_f8;
    puVar9[9] = uStack_f0;
    *(undefined4 *)(puVar9 + 10) = local_e8;
    *(undefined4 *)((longlong)puVar9 + 0x54) = uStack_e4;
    *(undefined4 *)(puVar9 + 0xb) = uStack_e0;
    *(undefined4 *)((longlong)puVar9 + 0x5c) = uStack_dc;
    *(undefined4 *)(puVar9 + 0xc) = local_d8;
    *(undefined4 *)((longlong)puVar9 + 100) = uStack_d4;
    *(undefined4 *)(puVar9 + 0xd) = uStack_d0;
    *(undefined4 *)((longlong)puVar9 + 0x6c) = uStack_cc;
    lVar5 = (**(code **)(*plVar1 + 0x20))(plVar1);
    lVar5 = lVar5 + 0x70;
    uVar4 = extraout_XMM0_Da;
    if (iVar2 != 0) {
      local_1a4 = iStack_11c;
      plVar14 = (longlong *)(&DAT_140ae5224 + (longlong)iStack_11c * 0xb);
      plVar12 = (longlong *)(&DAT_140ae5200 + (longlong)iStack_11c * 0xb);
      local_1d8 = plVar12;
      local_1d0 = plVar14;
      do {
        iVar2 = iVar2 + -1;
        bVar10 = (byte)iVar2;
        local_1b0 = (local_1c0 >> (bVar10 & 0x1f)) + (uint)(local_1c0 >> (bVar10 & 0x1f) == 0);
        local_1b4 = (local_1c4 >> (bVar10 & 0x1f)) + (uint)(local_1c4 >> (bVar10 & 0x1f) == 0);
        local_1b8 = (local_128 >> (bVar10 & 0x1f)) + (uint)(local_128 >> (bVar10 & 0x1f) == 0);
        local_1a0 = ((uint)(*(int *)((longlong)plVar12 + 4) + local_1b0) >>
                    ((byte)(int)plVar12[1] & 0x1f)) * (int)*plVar14 + 3 & 0xfffffffc;
        local_19c = ((uint)((int)plVar12[2] + local_1b4) >>
                    ((byte)*(undefined4 *)((longlong)plVar12 + 0x14) & 0x1f)) * local_1a0;
        local_1bc = ((uint)(*(int *)((longlong)plVar12 + 0x1c) + local_1b8) >>
                    ((byte)(int)plVar12[4] & 0x1f)) * local_19c;
        local_1c8 = iVar2;
        local_1ac = local_1b4;
        local_1a8 = local_1b8;
        local_198 = local_1bc;
        if (local_190 == 3) {
          uVar3 = (**(code **)(*param_2 + 0x88))(param_2,iVar2,local_88);
          uVar6 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) goto LAB_14026cbcb;
          local_1e8 = (int *)CONCAT44(local_1e8._4_4_,0x10);
          uVar3 = (**(code **)(*param_2 + 0x98))(param_2,iVar2,local_c8,0);
          uVar6 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) goto LAB_14026cbcb;
          local_17c = ((uint)((int)local_1d8[2] + local_1b4) >>
                      ((byte)*(undefined4 *)((longlong)local_1d8 + 0x14) & 0x1f)) * local_c8[0];
          local_178 = ((uint)(*(int *)((longlong)local_1d8 + 0x1c) + local_1b8) >>
                      ((byte)(int)local_1d8[4] & 0x1f)) * local_17c;
          local_1e0 = &local_180;
          uVar7 = local_c0;
LAB_14026cb02:
          local_1e8 = &local_1b0;
          FUN_1402645d0(lVar5,&local_1b0,&local_1a0,uVar7);
          uVar3 = (**(code **)(*param_2 + 0xa0))(param_2,iVar2);
          uVar6 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) goto LAB_14026cbcb;
          lVar5 = lVar5 + (ulonglong)local_1bc;
          plVar12 = local_1d8;
          plVar14 = local_1d0;
          uVar4 = extraout_XMM0_Da_02;
        }
        else {
          if (local_190 == 4) {
            uVar3 = (**(code **)(*param_2 + 0x88))(param_2,iVar2,local_a8);
            uVar6 = (ulonglong)uVar3;
            if (-1 < (int)uVar3) {
              local_1e8 = (int *)CONCAT44(local_1e8._4_4_,0x10);
              uVar3 = (**(code **)(*param_2 + 0x98))(param_2,iVar2,&local_168,0);
              uVar6 = (ulonglong)uVar3;
              if (-1 < (int)uVar3) {
                local_174 = local_168;
                local_170 = local_164;
                local_16c = ((uint)(*(int *)((longlong)local_1d8 + 0x1c) + local_1b8) >>
                            ((byte)(int)local_1d8[4] & 0x1f)) * local_164;
                local_1e0 = &local_174;
                uVar7 = local_160;
                goto LAB_14026cb02;
              }
            }
            goto LAB_14026cbcb;
          }
          if (local_190 == 5) {
            uVar3 = (**(code **)(*param_2 + 0x88))(param_2,iVar2,local_68);
            uVar6 = (ulonglong)uVar3;
            if ((int)uVar3 < 0) goto LAB_14026cbcb;
            plVar12 = local_1d8;
            plVar14 = local_1d0;
            uVar15 = uVar11;
            uVar4 = extraout_XMM0_Da_00;
            iVar2 = local_1c8;
            if (uVar13 != 0) {
              do {
                local_150 = &DAT_140ae7b00 + uVar15;
                local_1e0 = (int *)CONCAT44(local_1e0._4_4_,0x10);
                local_1e8 = (int *)0x0;
                uVar3 = (**(code **)(*param_2 + 0x98))
                                  (param_2,(&DAT_140ae7b00)[uVar15],local_1c8,local_148);
                uVar6 = (ulonglong)uVar3;
                if ((int)uVar3 < 0) goto LAB_14026cbcb;
                local_18c = local_148[0];
                local_188 = ((uint)((int)local_1d8[2] + local_1b4) >>
                            ((byte)*(undefined4 *)((longlong)local_1d8 + 0x14) & 0x1f)) *
                            local_148[0];
                local_184 = ((uint)(*(int *)((longlong)local_1d8 + 0x1c) + local_1b8) >>
                            ((byte)(int)local_1d8[4] & 0x1f)) * local_188;
                local_1e0 = &local_18c;
                local_1e8 = &local_1b0;
                FUN_1402645d0(lVar5,&local_1b0,&local_1a0,local_140);
                uVar3 = (**(code **)(*param_2 + 0xa0))(param_2,*local_150,local_1c8);
                uVar6 = (ulonglong)uVar3;
                if ((int)uVar3 < 0) goto LAB_14026cbcb;
                uVar3 = (int)uVar15 + 1;
                uVar15 = (ulonglong)uVar3;
                lVar5 = lVar5 + (ulonglong)local_1bc;
                plVar12 = local_1d8;
                plVar14 = local_1d0;
                uVar4 = extraout_XMM0_Da_01;
                iVar2 = local_1c8;
              } while (uVar3 < uVar13);
            }
          }
        }
      } while (iVar2 != 0);
    }
    uVar13 = FUN_1401b6f30(uVar4,local_158);
    uVar6 = (ulonglong)uVar13;
    if (-1 < (int)uVar13) {
      (**(code **)(*plVar1 + 8))(plVar1);
      return 0;
    }
  }
LAB_14026cbcb:
  if (plVar1 == (longlong *)0x0) {
    return uVar6;
  }
  (**(code **)(*plVar1 + 8))(plVar1);
  return uVar6;
}

