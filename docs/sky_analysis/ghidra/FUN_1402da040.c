
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1402da040(longlong *param_1,float *param_2,float *param_3,uint param_4)

{
  byte bVar1;
  undefined1 auVar2 [16];
  longlong *plVar3;
  longlong *plVar4;
  int iVar5;
  float *pfVar6;
  longlong lVar7;
  longlong lVar8;
  byte *pbVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  byte *pbVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ushort *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint *puVar23;
  uint uVar24;
  float *pfVar25;
  uint uVar26;
  undefined1 auVar27 [16];
  float fVar28;
  float fVar29;
  float fVar30;
  undefined1 auVar31 [12];
  undefined1 auVar32 [12];
  undefined1 auVar33 [16];
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  undefined1 auStack_1f8 [32];
  longlong *local_1d8;
  uint local_1d0;
  int local_1cc;
  longlong *local_1c8 [2];
  float local_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float local_1a8;
  float fStack_1a4;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  float local_188 [4];
  undefined1 local_178 [16];
  float local_168 [16];
  uint local_128 [16];
  float local_e8 [16];
  ulonglong local_a8;
  
  local_a8 = DAT_140c0f7b0 ^ (ulonglong)auStack_1f8;
  local_1b8 = SUB84(param_2,0);
  fStack_1b4 = (float)((ulonglong)param_2 >> 0x20);
  local_198 = CONCAT44(local_198._4_4_,0xffffffff);
  local_1d0 = param_4;
  (**(code **)(*param_1 + 0x30))(param_1,&local_198);
  if ((param_4 & 0x308) != 0) {
    if ((param_4 & 8) != 0) {
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,1,&local_1d8);
      pfVar6 = (float *)(**(code **)(*local_1d8 + 0x18))();
      param_3[4] = *pfVar6;
      param_3[5] = pfVar6[1];
      param_3[6] = pfVar6[2];
      param_3[7] = pfVar6[3];
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
    }
    if ((param_4 & 0x300) != 0) {
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,6,&local_1d8);
      lVar7 = (**(code **)(*local_1d8 + 0x10))();
      local_1c8[0] = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,7,local_1c8);
      lVar8 = (**(code **)(*local_1c8[0] + 0x10))();
      uVar13 = 0;
      pfVar6 = (float *)(**(code **)(*local_1d8 + 0x18))();
      pbVar9 = (byte *)(**(code **)(*local_1c8[0] + 0x18))();
      uVar26 = 0;
      fVar30 = *param_2;
      fVar34 = param_2[1];
      do {
        fVar29 = fVar34;
        if (uVar26 == 0) {
          fVar29 = 1.0 - fVar34;
        }
        fVar28 = (1.0 - fVar30) * fVar29;
        if ((*pfVar6 != 0.0) && (*pbVar9 != 0)) {
          local_e8[uVar13] = *pfVar6;
          bVar1 = *pbVar9;
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar28;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        if ((pfVar6[1] != 0.0) && (pbVar9[1] != 0)) {
          local_e8[uVar13] = pfVar6[1];
          bVar1 = pbVar9[1];
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar28;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        if ((pfVar6[2] != 0.0) && (pbVar9[2] != 0)) {
          local_e8[uVar13] = pfVar6[2];
          bVar1 = pbVar9[2];
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar28;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        if ((pfVar6[3] != 0.0) && (pbVar9[3] != 0)) {
          local_e8[uVar13] = pfVar6[3];
          bVar1 = pbVar9[3];
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar28;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        pfVar25 = (float *)((longlong)*(int *)(lVar7 + 0x28) + (longlong)pfVar6);
        pbVar16 = pbVar9 + *(int *)(lVar8 + 0x28);
        fVar29 = fVar30 * fVar29;
        if ((*pfVar25 != 0.0) && (*pbVar16 != 0)) {
          local_e8[uVar13] = *pfVar25;
          bVar1 = *pbVar16;
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar29;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        if ((pfVar25[1] != 0.0) && (pbVar16[1] != 0)) {
          local_e8[uVar13] = pfVar25[1];
          bVar1 = pbVar16[1];
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar29;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        if ((pfVar25[2] != 0.0) && (pbVar16[2] != 0)) {
          local_e8[uVar13] = pfVar25[2];
          bVar1 = pbVar16[2];
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar29;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        if ((pfVar25[3] != 0.0) && (pbVar16[3] != 0)) {
          local_e8[uVar13] = pfVar25[3];
          bVar1 = pbVar16[3];
          local_128[uVar13] = (uint)uVar13;
          local_168[uVar13] = (float)bVar1 * 0.003921569 * fVar29;
          uVar13 = (ulonglong)((uint)uVar13 + 1);
        }
        uVar26 = uVar26 + 1;
        pfVar6 = (float *)((longlong)pfVar6 + (longlong)*(int *)(lVar7 + 0x2c));
        pbVar9 = pbVar9 + *(int *)(lVar8 + 0x2c);
      } while (uVar26 < 2);
      uVar26 = (uint)uVar13;
      FUN_1401c3280(&LAB_1402d9dd0,local_128,uVar13,local_e8);
      uVar12 = 0;
      uVar17 = uVar12;
      if (uVar26 != 0) {
        while( true ) {
          uVar14 = (int)uVar17 + 1;
          uVar11 = (ulonglong)uVar14;
          if (uVar26 <= uVar14) break;
          uVar18 = uVar11;
          if (3 < (int)(uVar26 - uVar14)) {
            uVar14 = local_128[uVar17];
            fVar30 = local_e8[uVar14];
            do {
              uVar24 = local_128[uVar11];
              if (fVar30 != local_e8[uVar24]) goto LAB_1402da4f1;
              local_168[uVar14] = local_168[uVar14] + local_168[uVar24];
              local_168[uVar24] = 0.0;
              uVar24 = local_128[uVar11 + 1];
              iVar5 = (int)uVar18;
              if (fVar30 != local_e8[uVar24]) {
                uVar18 = (ulonglong)(iVar5 + 1);
                goto LAB_1402da4f1;
              }
              local_168[uVar14] = local_168[uVar14] + local_168[uVar24];
              local_168[uVar24] = 0.0;
              uVar24 = local_128[uVar11 + 2];
              if (fVar30 != local_e8[uVar24]) {
                uVar18 = (ulonglong)(iVar5 + 2);
                goto LAB_1402da4f1;
              }
              local_168[uVar14] = local_168[uVar14] + local_168[uVar24];
              local_168[uVar24] = 0.0;
              uVar24 = local_128[uVar11 + 3];
              if (fVar30 != local_e8[uVar24]) {
                uVar18 = (ulonglong)(iVar5 + 3);
                goto LAB_1402da4f1;
              }
              uVar18 = (ulonglong)(iVar5 + 4U);
              uVar11 = uVar11 + 4;
              local_168[uVar14] = local_168[uVar14] + local_168[uVar24];
              local_168[uVar24] = 0.0;
            } while (iVar5 + 4U < uVar26 - 3);
          }
          if (uVar26 <= (uint)uVar18) break;
          uVar14 = local_128[uVar17];
          fVar30 = local_e8[uVar14];
          puVar23 = local_128 + uVar11;
          while (uVar24 = *puVar23, fVar30 == local_e8[uVar24]) {
            uVar15 = (int)uVar18 + 1;
            uVar18 = (ulonglong)uVar15;
            puVar23 = puVar23 + 1;
            local_168[uVar14] = local_168[uVar14] + local_168[uVar24];
            local_168[uVar24] = 0.0;
            if (uVar26 <= uVar15) goto LAB_1402da4f9;
          }
LAB_1402da4f1:
          uVar17 = uVar18;
          if (uVar26 <= (uint)uVar18) break;
        }
      }
LAB_1402da4f9:
      FUN_1401c3280(&LAB_1402d9df0,local_128,uVar13,local_168);
      if (4 < uVar26) {
        uVar13 = 4;
      }
      uVar26 = (uint)uVar13;
      uVar13 = uVar12;
      if (3 < (int)uVar26) {
        pfVar6 = param_3 + 0x18;
        pfVar25 = param_3 + 0x14;
        do {
          fVar30 = local_168[local_128[uVar12]];
          if (fVar30 <= 0.0) goto LAB_1402da611;
          *pfVar25 = local_e8[local_128[uVar12]];
          uVar14 = local_128[uVar12 + 1];
          *pfVar6 = fVar30;
          fVar30 = local_168[uVar14];
          iVar5 = (int)uVar13;
          if (fVar30 <= 0.0) {
            uVar13 = (ulonglong)(iVar5 + 1);
            goto LAB_1402da611;
          }
          pfVar25[1] = local_e8[uVar14];
          uVar14 = local_128[uVar12 + 2];
          pfVar6[1] = fVar30;
          fVar30 = local_168[uVar14];
          if (fVar30 <= 0.0) {
            uVar13 = (ulonglong)(iVar5 + 2);
            goto LAB_1402da611;
          }
          pfVar25[2] = local_e8[uVar14];
          uVar14 = local_128[uVar12 + 3];
          pfVar6[2] = fVar30;
          fVar30 = local_168[uVar14];
          if (fVar30 <= 0.0) {
            uVar13 = (ulonglong)(iVar5 + 3);
            goto LAB_1402da611;
          }
          uVar13 = (ulonglong)(iVar5 + 4U);
          uVar12 = uVar12 + 4;
          pfVar25[3] = local_e8[uVar14];
          pfVar25 = pfVar25 + 4;
          pfVar6[3] = fVar30;
          pfVar6 = pfVar6 + 4;
        } while (iVar5 + 4U < uVar26 - 3);
      }
      if ((uint)uVar13 < uVar26) {
        pfVar6 = param_3 + uVar12 + 0x18;
        do {
          uVar14 = *(uint *)(((longlong)local_188 - (longlong)param_3) + (longlong)pfVar6);
          if (local_168[uVar14] <= 0.0) break;
          fVar30 = local_e8[uVar14];
          uVar24 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar24;
          *pfVar6 = local_168[uVar14];
          pfVar6[-4] = fVar30;
          pfVar6 = pfVar6 + 1;
        } while (uVar24 < uVar26);
      }
LAB_1402da611:
      if ((uint)uVar13 < 4) {
        pfVar6 = param_3 + uVar13 + 0x18;
        uVar13 = (ulonglong)(4 - (uint)uVar13);
        do {
          pfVar6[-4] = 0.0;
          *pfVar6 = 0.0;
          pfVar6 = pfVar6 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      if (local_1c8[0] != (longlong *)0x0) {
        (**(code **)(*local_1c8[0] + 8))();
      }
      param_4 = local_1d0;
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
        param_4 = local_1d0;
      }
    }
  }
  if ((param_4 & 7) == 0) goto LAB_1402da9f5;
  local_1d8 = (longlong *)0x0;
  iVar21 = (int)(*param_2 * 16.0);
  iVar22 = (int)(param_2[1] * 16.0);
  local_1a8 = *param_2 * 16.0 - (float)iVar21;
  fStack_1a4 = param_2[1] * 16.0 - (float)iVar22;
  uStack_1a0 = 0;
  (**(code **)(*param_1 + 0x48))(param_1,0,&local_1d8,1);
  lVar7 = (**(code **)(*local_1d8 + 0x10))();
  iVar5 = *(int *)(lVar7 + 0x2c);
  iVar20 = *(int *)(lVar7 + 0x28);
  lVar8 = (**(code **)(*local_1d8 + 0x18))();
  puVar19 = (ushort *)(lVar8 + (iVar5 * iVar22 + iVar20 * iVar21));
  if ((param_4 & 1) != 0) {
    param_3[0x10] = (float)(uint)(*puVar19 >> 0xf);
  }
  if ((param_4 & 6) != 0) {
    fVar36 = (float)(*puVar19 & 0x7fff) * DAT_140c41b9c - DAT_140c41b94;
    fVar35 = (float)(puVar19[1] & 0x7fff) * DAT_140c41b9c - DAT_140c41b94;
    fVar37 = (float)(*(ushort *)((longlong)*(int *)(lVar7 + 0x2c) + (longlong)puVar19) & 0x7fff) *
             DAT_140c41b9c - DAT_140c41b94;
    fVar28 = (float)(*(ushort *)((longlong)*(int *)(lVar7 + 0x2c) + 2 + (longlong)puVar19) & 0x7fff)
             * DAT_140c41b9c - DAT_140c41b94;
    fVar30 = 1.0 / ((fVar35 - fVar37) * (fVar35 - fVar37) + 1.0);
    fVar34 = 1.0 / ((fVar36 - fVar28) * (fVar36 - fVar28) + 1.0);
    fVar29 = local_1a8 + fStack_1a4;
    fStack_1a4 = fStack_1a4 - local_1a8;
    local_1a8 = fVar29 - 1.0;
    fVar30 = ((fVar37 + fVar35) * fVar30 + (fVar28 + fVar36) * fVar34) * (0.5 / (fVar30 + fVar34));
    uStack_1a0 = 0;
    if ((param_4 & 2) != 0) {
      if (0.0 <= fStack_1a4) {
        fVar34 = (fVar37 - fVar30) * fStack_1a4;
        if (0.0 <= local_1a8) goto LAB_1402da8c7;
        fVar29 = fVar30 - fVar36;
      }
      else {
        fVar34 = (fVar30 - fVar35) * fStack_1a4;
        if (0.0 <= local_1a8) {
LAB_1402da8c7:
          fVar29 = fVar28 - fVar30;
        }
        else {
          fVar29 = fVar30 - fVar36;
        }
      }
      param_3[0x11] = fVar29 * local_1a8 + fVar30 + fVar34;
    }
    if ((param_4 & 4) != 0) {
      fVar30 = fVar30 * 2.0;
      if (0.0 <= fStack_1a4) {
        if (0.0 <= local_1a8) {
          fVar29 = fVar37 - fVar28;
          fVar34 = (fVar30 - fVar37) - fVar28;
        }
        else {
          fVar34 = fVar36 - fVar37;
          fVar29 = (fVar37 + fVar36) - fVar30;
        }
LAB_1402da99a:
        auVar32._4_4_ = DAT_140c41ba0 * DAT_140c41ba0;
        auVar32._0_4_ = fVar29 * fVar29;
        auVar32._8_4_ = fVar34 * fVar34;
        auVar33._0_4_ = fVar29 * fVar29 + DAT_140c41ba0 * DAT_140c41ba0 + fVar34 * fVar34;
        auVar33._4_8_ = auVar32._4_8_;
        auVar33._12_4_ = 0;
        auVar33 = rsqrtss(auVar33,auVar33);
        fVar30 = auVar33._0_4_;
        fVar29 = fVar30 * fVar29;
        fVar34 = fVar30 * fVar34;
      }
      else {
        if (local_1a8 < 0.0) {
          fVar29 = fVar36 - fVar35;
          fVar34 = (fVar35 + fVar36) - fVar30;
          goto LAB_1402da99a;
        }
        fVar34 = fVar35 - fVar28;
        fVar28 = (fVar30 - fVar35) - fVar28;
        auVar31._4_4_ = DAT_140c41ba0 * DAT_140c41ba0;
        auVar31._0_4_ = fVar28 * fVar28;
        auVar31._8_4_ = fVar34 * fVar34;
        auVar27._0_4_ = fVar28 * fVar28 + DAT_140c41ba0 * DAT_140c41ba0 + fVar34 * fVar34;
        auVar27._4_8_ = auVar31._4_8_;
        auVar27._12_4_ = 0;
        auVar33 = rsqrtss(auVar27,auVar27);
        fVar30 = auVar33._0_4_;
        fVar29 = fVar30 * fVar28;
        fVar34 = fVar30 * fVar34;
      }
      fVar28 = fVar30 * DAT_140c41ba0;
      *param_3 = fVar29;
      param_3[1] = fVar28;
      param_3[2] = fVar34;
      param_3[3] = fVar30 * 0.0;
    }
  }
  if (local_1d8 != (longlong *)0x0) {
    (**(code **)(*local_1d8 + 8))();
  }
  param_2 = (float *)CONCAT44(fStack_1b4,local_1b8);
LAB_1402da9f5:
  auVar33 = _DAT_140b7b240;
  if ((param_4 & 0x1cf0) != 0) {
    fVar28 = *param_2 * 64.0;
    fVar35 = param_2[1] * 64.0;
    local_1d0 = (uint)fVar28;
    _local_1a8 = CONCAT44(fVar35,fVar28);
    uStack_1a0 = CONCAT44(param_2[3] * 64.0,param_2[2] * 64.0);
    local_1cc = (int)fVar35;
    fVar30 = (float)DAT_140b7b240;
    fVar34 = DAT_140b7b240._4_4_;
    fVar29 = DAT_140b7b240._8_4_;
    local_198 = CONCAT44(fVar35 - (float)local_1cc,fVar28 - (float)(int)local_1d0);
    uStack_190 = 0;
    local_188[0] = fVar30 - (fVar28 - (float)(int)local_1d0);
    local_188[1] = fVar34 - (fVar35 - (float)local_1cc);
    local_188[2] = fVar29 - 0.0;
    local_188[3] = DAT_140b7b240._12_4_ - 0.0;
    if ((param_4 & 0x10) != 0) {
      local_1c8[0] = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,0x11,local_1c8,1);
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,0x12,&local_1d8,1);
      plVar4 = local_1c8[0];
      plVar3 = local_1d8;
      lVar7 = (**(code **)(*local_1d8 + 0x10))(local_1d8);
      uVar10 = (**(code **)(*plVar3 + 0x18))(plVar3);
      pfVar6 = (float *)FUN_140250f60(&local_1b8,uVar10,*(undefined4 *)(lVar7 + 0x2c),&local_1a8);
      lVar7 = (**(code **)(*plVar4 + 0x10))(plVar4);
      uVar10 = (**(code **)(*plVar4 + 0x18))(plVar4);
      pfVar25 = (float *)FUN_140250f60(local_178,uVar10,*(undefined4 *)(lVar7 + 0x2c),&local_1a8);
      if (0.5 < pfVar25[3] || pfVar25[3] == 0.5) {
        local_1b8 = (*pfVar25 + *pfVar6 * 2.0666666) - fVar30;
        fStack_1b4 = (pfVar25[1] + pfVar6[1] * 2.032258) - fVar34;
        fStack_1b0 = (pfVar25[2] + pfVar6[2] * 2.0666666) - fVar29;
        fStack_1ac = ((1.0 - local_1b8) - fStack_1b4) - fStack_1b0;
        auVar2._4_4_ = fStack_1b4;
        auVar2._0_4_ = local_1b8;
        auVar2._8_4_ = fStack_1b0;
        auVar2._12_4_ = fStack_1ac;
        auVar27 = maxps(ZEXT816(0),auVar2);
        auVar33 = minps(auVar27,auVar33);
      }
      else {
        auVar33 = ZEXT816(0);
      }
      *(undefined1 (*) [16])(param_3 + 8) = auVar33;
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
      if (local_1c8[0] != (longlong *)0x0) {
        (**(code **)(*local_1c8[0] + 8))();
      }
    }
    if ((param_4 & 0x60) != 0) {
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,0xd,&local_1d8);
      plVar3 = local_1d8;
      lVar7 = (**(code **)(*local_1d8 + 0x10))(local_1d8);
      uVar10 = (**(code **)(*plVar3 + 0x18))(plVar3);
      FUN_140251170(&local_1b8,uVar10,*(undefined4 *)(lVar7 + 0x2c),&local_1a8);
      param_3[0xc] = local_1b8;
      param_3[0xd] = fStack_1b4;
      param_3[0xe] = fStack_1b0;
      param_3[0xf] = 1.0;
      param_3[0x12] = fStack_1ac;
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
    }
    if ((char)param_4 < '\0') {
      iVar5 = (**(code **)(*param_1 + 0x40))(param_1,0x1c);
      local_1d8 = (longlong *)0x0;
      if (iVar5 == 0) {
        (**(code **)(*param_1 + 0x48))(param_1,0x10);
        lVar7 = (**(code **)(*local_1d8 + 0x10))();
        iVar5 = *(int *)(lVar7 + 0x28) * local_1d0;
        iVar20 = *(int *)(lVar7 + 0x2c) * local_1cc;
        lVar7 = (**(code **)(*local_1d8 + 0x18))();
        bVar1 = *(byte *)(lVar7 + (iVar20 + iVar5));
        local_1c8[0] = (longlong *)0x0;
        (**(code **)(*param_1 + 0x48))(param_1,0x1c,local_1c8);
        lVar7 = (**(code **)(*local_1c8[0] + 0x18))();
        param_3[0x13] = *(float *)(lVar7 + (ulonglong)(bVar1 >> 3 & 3) * 4);
        if (local_1c8[0] != (longlong *)0x0) {
          (**(code **)(*local_1c8[0] + 8))();
        }
      }
      else {
        (**(code **)(*param_1 + 0x48))(param_1,5,&local_1d8);
        pfVar6 = (float *)(**(code **)(*local_1d8 + 0x18))();
        param_3[0x13] = *pfVar6;
      }
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
    }
    if ((param_4 >> 10 & 1) != 0) {
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,0x10,&local_1d8);
      lVar7 = (**(code **)(*local_1d8 + 0x10))();
      iVar5 = *(int *)(lVar7 + 0x28) * local_1d0;
      iVar20 = *(int *)(lVar7 + 0x2c) * local_1cc;
      lVar7 = (**(code **)(*local_1d8 + 0x18))();
      param_3[0x1c] = (float)(uint)*(byte *)(lVar7 + (iVar20 + iVar5));
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
    }
    if ((param_4 >> 0xb & 1) != 0) {
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,0x22,&local_1d8);
      lVar7 = (**(code **)(*local_1d8 + 0x10))();
      iVar5 = local_1d0 * *(int *)(lVar7 + 0x28);
      iVar20 = *(int *)(lVar7 + 0x2c) * local_1cc;
      lVar8 = (**(code **)(*local_1d8 + 0x18))();
      puVar19 = (ushort *)(lVar8 + (iVar20 + iVar5));
      param_3[0x1d] =
           ((float)puVar19[1] * local_188[1] * (float)local_198 +
            (float)*puVar19 * local_188[1] * local_188[0] +
            (float)*(ushort *)((longlong)*(int *)(lVar7 + 0x2c) + (longlong)puVar19) *
            local_198._4_4_ * local_188[0] +
           (float)*(ushort *)((longlong)*(int *)(lVar7 + 0x2c) + 2 + (longlong)puVar19) *
           local_198._4_4_ * (float)local_198) * 1.5259022e-05;
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
    }
    if ((param_4 >> 0xc & 1) != 0) {
      local_1d8 = (longlong *)0x0;
      (**(code **)(*param_1 + 0x48))(param_1,0x1b,&local_1d8);
      lVar7 = (**(code **)(*local_1d8 + 0x10))();
      iVar5 = local_1d0 * *(int *)(lVar7 + 0x28);
      iVar20 = *(int *)(lVar7 + 0x2c) * local_1cc;
      lVar7 = (**(code **)(*local_1d8 + 0x18))();
      bVar1 = *(byte *)(lVar7 + (iVar20 + iVar5));
      param_3[0x1e] = (float)(bVar1 & 3);
      param_3[0x20] = (float)(bVar1 >> 4 & 3);
      param_3[0x21] = (float)(uint)(bVar1 >> 6);
      param_3[0x1f] = (float)(bVar1 >> 2 & 3);
      if (local_1d8 != (longlong *)0x0) {
        (**(code **)(*local_1d8 + 8))();
      }
    }
  }
  return 1;
}

