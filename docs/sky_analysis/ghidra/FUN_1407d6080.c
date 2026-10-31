
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1407d6080(longlong *param_1,uint param_2,uint param_3,float param_4,float *param_5)

{
  float fVar1;
  longlong *plVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  bool bVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  float *pfVar9;
  undefined1 (*pauVar10) [16];
  ulonglong uVar11;
  float *pfVar12;
  longlong *plVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar25;
  undefined1 auVar24 [16];
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined1 auStack_1d8 [32];
  undefined1 local_1b8 [4];
  undefined1 auStack_1b4 [4];
  undefined8 uStack_1b0;
  undefined4 local_1a8;
  undefined8 local_1a4;
  undefined4 local_19c;
  undefined1 local_198 [8];
  float fStack_190;
  undefined4 uStack_18c;
  float local_188;
  float local_184;
  float local_180;
  undefined4 local_17c;
  float local_178;
  float local_174;
  float local_170;
  undefined4 local_16c;
  float local_168;
  float local_164;
  float local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  float local_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float local_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float local_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  float *local_108;
  float *local_100;
  ulonglong local_b8;
  
  local_b8 = DAT_140c0f7b0 ^ (ulonglong)auStack_1d8;
  uVar7 = (ulonglong)param_2;
  uVar11 = uVar7;
  if (param_1[0x26] != 0) {
    if ((ulonglong)param_1[0x26] < (ulonglong)param_1[0x24]) {
      return;
    }
    uVar11 = (ulonglong)*(uint *)(param_1[0x25] + uVar7 * 4);
  }
  plVar13 = (longlong *)(uVar11 * 0x20 + param_1[0x23]);
  plVar2 = (longlong *)*plVar13;
  if (plVar2 != (longlong *)0x0) {
    uVar11 = 0;
    bVar5 = false;
    auVar24._12_4_ = 0;
    auVar24._0_12_ = _auStack_1b4;
    _local_1b8 = auVar24 << 0x20;
    iVar6 = (**(code **)(*plVar2 + 0x10))(plVar2,local_1b8,0);
    if (iVar6 != 0) {
      uVar14 = ~(param_3 >> 7) & 1;
      if (uVar14 != 0) {
        if (((param_3 & 0x20) == 0) &&
           (uVar7 = (**(code **)(*param_1 + 0xc0))(param_1,uVar7), (uVar7 & 2) != 0)) {
          lVar8 = (**(code **)(*plVar2 + 0x1a8))(plVar2,0x96,0);
          _local_1b8 = ZEXT812(0x96);
          local_1a8 = 0;
          local_1a4 = 3;
          local_19c = 0;
          uStack_1b0._4_4_ = (uint)(*(int *)(param_1[3] + 0x520) * *(int *)(lVar8 + 0x14)) / 0x15180
          ;
          (**(code **)(*plVar2 + 0x248))(plVar2,0,local_1b8);
        }
        fVar28 = DAT_140c3b438 * 0.0055555557 * *(float *)((longlong)plVar13 + 0xc);
        fVar26 = DAT_140c3b438 * 0.0055555557 * *(float *)(plVar13 + 1);
        fVar15 = (float)FUN_1408fe3d0(fVar26);
        fVar26 = (float)FUN_1408fc950(fVar26);
        fVar16 = (float)FUN_1408fe3d0(fVar28);
        fVar28 = (float)FUN_1408fc950(fVar28);
        fVar17 = (float)FUN_1408fe3d0(0);
        fVar18 = (float)FUN_1408fc950(0);
        local_17c = 0;
        local_16c = 0;
        local_15c = 0;
        local_184 = fVar17 * fVar28;
        local_188 = fVar18 * fVar28;
        local_180 = -fVar16;
        local_178 = fVar18 * fVar16 * fVar15 - fVar17 * fVar26;
        local_174 = fVar18 * fVar26 + fVar17 * fVar16 * fVar15;
        local_168 = fVar18 * fVar16 * fVar26 + fVar17 * fVar15;
        local_158 = _DAT_140c78440;
        uStack_150 = uRam0000000140c78448;
        local_164 = fVar17 * fVar16 * fVar26 - fVar18 * fVar15;
        local_170 = fVar28 * fVar15;
        local_160 = fVar28 * fVar26;
        if ((param_3 & 2) != 0) {
          local_108 = &local_188;
          local_100 = &local_148;
          local_118 = _DAT_140c78440;
          uStack_110 = uRam0000000140c78448;
          local_148 = _DAT_140c78410 * 1.0;
          fStack_144 = fRam0000000140c78414 * 1.0;
          fStack_140 = fRam0000000140c78418 * 1.0;
          fStack_13c = fRam0000000140c7841c * 1.0;
          uStack_1b0 = local_100;
          _local_1b8 = local_108;
          local_138 = _DAT_140c78420 * -1.0;
          fStack_134 = fRam0000000140c78424 * -1.0;
          fStack_130 = fRam0000000140c78428 * -1.0;
          fStack_12c = fRam0000000140c7842c * -1.0;
          local_128 = _DAT_140c78430 * 1.0;
          fStack_124 = fRam0000000140c78434 * 1.0;
          fStack_120 = fRam0000000140c78438 * 1.0;
          fStack_11c = fRam0000000140c7843c * 1.0;
          FUN_1401afb10(&local_108,&local_188);
        }
        (**(code **)(*plVar2 + 0x48))(plVar2,&local_188);
        (**(code **)(*plVar2 + 0x70))(plVar2,param_4 * *(float *)((longlong)plVar13 + 0x1c));
        (**(code **)(*plVar2 + 0xb0))(plVar2,plVar13 + 2);
        (**(code **)(*plVar2 + 0xf0))(plVar2,param_1[3] + 0xb9c);
      }
      pfVar9 = (float *)(**(code **)(*plVar2 + 0x488))(plVar2);
      pauVar10 = (undefined1 (*) [16])(**(code **)(*plVar2 + 0x50))(plVar2);
      fVar15 = *(float *)pauVar10[2];
      fVar26 = *(float *)(pauVar10[2] + 4);
      fVar16 = *(float *)(pauVar10[2] + 8);
      auVar24 = *pauVar10;
      fVar28 = *(float *)pauVar10[1];
      fVar17 = *(float *)(pauVar10[1] + 4);
      fVar18 = *(float *)(pauVar10[1] + 8);
      fVar23 = auVar24._0_4_;
      fVar20 = auVar24._4_4_;
      fVar25 = auVar24._8_4_;
      fVar29 = fVar15 * fVar15 + fVar26 * fVar26 + fVar16 * fVar16;
      fVar27 = fVar28 * fVar28 + fVar17 * fVar17 + fVar18 * fVar18;
      fVar22 = fVar23 * fVar23 + fVar20 * fVar20 + fVar25 * fVar25;
      if (fVar22 <= fVar27) {
        fVar22 = fVar27;
      }
      fVar27 = pfVar9[8];
      fVar1 = pfVar9[9];
      fVar21 = pfVar9[10];
      if (fVar22 <= fVar29) {
        fVar22 = fVar29;
      }
      auVar24 = sqrtps(auVar24,ZEXT416((uint)fVar22));
      uVar7 = uVar11;
      pfVar12 = param_5;
      do {
        if (auVar24._0_4_ * pfVar9[0xc] <
            (fVar27 * fVar23 + fVar1 * fVar28 + fVar21 * fVar15 + *(float *)pauVar10[3]) * *pfVar12
            + (fVar27 * fVar20 + fVar1 * fVar17 + fVar21 * fVar26 + *(float *)(pauVar10[3] + 4)) *
              pfVar12[1] +
            (fVar27 * fVar25 + fVar1 * fVar18 + fVar21 * fVar16 + *(float *)(pauVar10[3] + 8)) *
            pfVar12[2] + pfVar12[3]) goto LAB_1407d676c;
        uVar7 = uVar7 + 1;
        pfVar12 = pfVar12 + 4;
      } while (uVar7 < 6);
      auVar4 = *(undefined1 (*) [12])pauVar10[3];
      auVar3 = *(undefined1 (*) [12])pauVar10[3];
      fVar15 = *(float *)*pauVar10;
      fVar26 = *pfVar9;
      fVar16 = pfVar9[4];
      local_198._0_4_ = auVar3._0_4_;
      local_1b8 = auVar4._0_4_;
      fVar28 = fVar16;
      fVar17 = fVar26;
      if (0.0 < fVar15) {
        fVar28 = fVar26;
        fVar17 = fVar16;
      }
      fVar18 = pfVar9[1];
      fVar22 = pfVar9[5];
      fVar23 = *(float *)pauVar10[1];
      fVar20 = fVar22;
      fVar25 = fVar18;
      if (0.0 < fVar23) {
        fVar20 = fVar18;
        fVar25 = fVar22;
      }
      fVar27 = pfVar9[2];
      fVar29 = pfVar9[6];
      fVar1 = *(float *)pauVar10[2];
      fVar19 = fVar27;
      fVar21 = fVar29;
      if (0.0 < fVar1) {
        fVar19 = fVar29;
        fVar21 = fVar27;
      }
      local_198._0_4_ = (float)local_198._0_4_ + fVar28 * fVar15 + fVar20 * fVar23 + fVar21 * fVar1;
      local_198._4_4_ = auVar3._4_4_;
      local_1b8 = (undefined1  [4])
                  ((float)local_1b8 + fVar17 * fVar15 + fVar25 * fVar23 + fVar19 * fVar1);
      fVar15 = *(float *)(*pauVar10 + 4);
      fVar28 = fVar16;
      fVar17 = fVar26;
      if (0.0 < fVar15) {
        fVar28 = fVar26;
        fVar17 = fVar16;
      }
      fVar23 = *(float *)(pauVar10[1] + 4);
      auStack_1b4 = auVar4._4_4_;
      fVar20 = fVar22;
      fVar25 = fVar18;
      if (0.0 < fVar23) {
        fVar20 = fVar18;
        fVar25 = fVar22;
      }
      fVar1 = *(float *)(pauVar10[2] + 4);
      fVar21 = fVar29;
      fVar19 = fVar27;
      if (0.0 < fVar1) {
        fVar21 = fVar27;
        fVar19 = fVar29;
      }
      auStack_1b4 = (undefined1  [4])
                    ((float)auStack_1b4 + fVar17 * fVar15 + fVar25 * fVar23 + fVar19 * fVar1);
      fVar17 = *(float *)(*pauVar10 + 8);
      local_198._4_4_ = (float)local_198._4_4_ + fVar28 * fVar15 + fVar20 * fVar23 + fVar21 * fVar1;
      fVar26 = fVar26 * fVar17;
      fStack_190 = auVar3._8_4_;
      uStack_1b0._0_4_ = auVar4._8_4_;
      fVar15 = fVar16 * fVar17;
      if (0.0 < fVar17) {
        fVar15 = fVar26;
        fVar26 = fVar16 * fVar17;
      }
      fVar16 = *(float *)(pauVar10[1] + 8);
      fVar18 = fVar18 * fVar16;
      fVar28 = fVar22 * fVar16;
      if (0.0 < fVar16) {
        fVar28 = fVar18;
        fVar18 = fVar22 * fVar16;
      }
      fVar16 = *(float *)(pauVar10[2] + 8);
      fVar27 = fVar27 * fVar16;
      fVar17 = fVar29 * fVar16;
      if (0.0 < fVar16) {
        fVar17 = fVar27;
        fVar27 = fVar29 * fVar16;
      }
      uStack_1b0._0_4_ = (float)uStack_1b0 + fVar26 + fVar18 + fVar27;
      fStack_190 = fStack_190 + fVar15 + fVar28 + fVar17;
      uStack_1b0._4_4_ = 0;
      uStack_18c = 0;
      do {
        if (0.0 < (float)(~-(uint)(0.0 < *param_5) & (uint)local_1b8 |
                         -(uint)(0.0 < *param_5) & local_198._0_4_) * *param_5 +
                  (float)(~-(uint)(0.0 < param_5[1]) & (uint)auStack_1b4 |
                         -(uint)(0.0 < param_5[1]) & local_198._4_4_) * param_5[1] +
                  (float)(~-(uint)(0.0 < param_5[2]) & (uint)(float)uStack_1b0 |
                         -(uint)(0.0 < param_5[2]) & (uint)fStack_190) * param_5[2] + param_5[3])
        goto LAB_1407d676c;
        uVar11 = uVar11 + 1;
        param_5 = param_5 + 4;
      } while (uVar11 < 6);
      bVar5 = true;
LAB_1407d676c:
      if (uVar14 != 0) {
        if ((!bVar5) && ((param_3 & 0x20) == 0)) {
          return;
        }
        (**(code **)(*plVar2 + 0x128))(plVar2,1);
      }
      if (bVar5) {
        (**(code **)(*plVar2 + 0x140))(plVar2,1);
      }
    }
  }
  return;
}

