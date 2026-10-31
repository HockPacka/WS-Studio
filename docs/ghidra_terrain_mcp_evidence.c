// WildStar64.exe / WSG, read-only Ghidra MCP force_decompile 1402da040

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



// WildStar64.exe / WSG, read-only Ghidra MCP force_decompile 140381070

void FUN_140381070(longlong *param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  int *piVar4;
  longlong lVar5;
  longlong alStack_298 [59];
  undefined8 uStack_c0;
  undefined1 local_98 [128];
  
  if ((*(uint *)(*param_1 + 0xe8) & 0x4000) != 0) {
    uStack_c0 = 0x1403810b8;
    FUN_1407e4830(local_98,0,0x80);
    plVar2 = param_1 + 7;
    uVar3 = 0;
    do {
      if (*plVar2 != 0) {
        piVar4 = (int *)(*plVar2 + 0x78);
        uVar1 = 0;
        do {
          if (*piVar4 != 0) {
            uStack_c0 = 0x1403810eb;
            FUN_140354790(*param_1,*piVar4,local_98 + (uVar3 + uVar1) * 8);
          }
          uVar1 = uVar1 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar1 < 4);
      }
      uVar3 = uVar3 + 4;
      plVar2 = plVar2 + 1;
    } while (uVar3 < 0x10);
    lVar5 = 0x10;
    plVar2 = param_1 + 0x40;
    do {
      if ((longlong *)*plVar2 != (longlong *)0x0) {
        uStack_c0 = 0x140381130;
        (**(code **)(*(longlong *)*plVar2 + 8))();
        *plVar2 = 0;
      }
      *plVar2 = *(longlong *)(((longlong)alStack_298 - (longlong)param_1) + (longlong)plVar2);
      lVar5 = lVar5 + -1;
      plVar2 = plVar2 + 1;
    } while (lVar5 != 0);
  }
  return;
}



// WildStar64.exe / WSG, read-only Ghidra MCP force_decompile 140381300

undefined8 FUN_140381300(longlong *param_1)

{
  float *pfVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  float fVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  void *_Dst;
  void *_Dst_00;
  ulonglong uVar12;
  longlong *plVar13;
  longlong lVar14;
  uint uVar15;
  int *piVar17;
  uint uVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  bool bVar22;
  longlong local_res8;
  undefined1 local_res10 [8];
  undefined4 local_a8 [4];
  longlong *local_98;
  code *local_90;
  undefined4 local_88 [4];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  longlong *local_60;
  code *local_58;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong uVar16;
  
  if (((*(uint *)(*param_1 + 0xe8) & 0x4000) == 0) || ((int)param_1[0x62] == 0)) {
    return 1;
  }
  uVar12 = 0;
  local_a8[0] = 0;
  uVar10 = (**(code **)(*(longlong *)param_1[2] + 0x30))((longlong *)param_1[2],local_a8);
  if ((int)uVar10 == 0) {
    return uVar10;
  }
  plVar13 = (longlong *)param_1[0x6c];
  if (plVar13 == (longlong *)0x0) {
    FUN_14003d8f0(local_res10,*param_1 + 0x9d0);
    lVar14 = *(longlong *)(*param_1 + 0x9f8);
    if (lVar14 == 0) {
      FUN_14003d880(local_res10);
      return 0;
    }
    param_1[0x6e] = lVar14;
    if (*(undefined8 **)(lVar14 + 0x520) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar14 + 0x520) = *(undefined8 *)(lVar14 + 0x528);
    }
    if (*(longlong *)(lVar14 + 0x528) != 0) {
      *(undefined8 *)(*(longlong *)(lVar14 + 0x528) + 0x520) = *(undefined8 *)(lVar14 + 0x520);
    }
    *(undefined8 *)(lVar14 + 0x520) = 0;
    *(undefined8 *)(lVar14 + 0x528) = 0;
    FUN_14003d880(local_res10);
    if ((longlong *)param_1[0x5e] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[0x5e] + 8))();
      param_1[0x5e] = 0;
    }
    if ((longlong *)param_1[0x61] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[0x61] + 8))();
      param_1[0x61] = 0;
    }
    lVar14 = 0xc0;
    plVar13 = param_1 + 7;
    param_1[0x5c] = 0;
    param_1[0x5d] = 0;
    param_1[0x5f] = 0;
    param_1[0x60] = 0;
    lVar19 = 0x80;
    lVar20 = 4;
    *(undefined4 *)(param_1 + 0x6d) = *(undefined4 *)(*param_1 + 0x98);
    do {
      lVar5 = *plVar13;
      if (lVar5 == 0) {
        puVar11 = (undefined8 *)(lVar19 + param_1[0x6e]);
        *puVar11 = 0;
        puVar11[1] = 0;
        local_78 = 0;
        uStack_70 = 0;
        *(undefined4 *)(lVar14 + param_1[0x6e]) = 0x3a83126f;
      }
      else {
        uVar8 = *(undefined4 *)(lVar5 + 0x24);
        uVar6 = *(undefined4 *)(lVar5 + 0x28);
        uVar7 = *(undefined4 *)(lVar5 + 0x2c);
        puVar3 = (undefined4 *)(lVar19 + param_1[0x6e]);
        *puVar3 = *(undefined4 *)(lVar5 + 0x20);
        puVar3[1] = uVar8;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        *(undefined4 *)(lVar14 + param_1[0x6e]) = *(undefined4 *)(lVar5 + 0x6c);
      }
      lVar19 = lVar19 + 0x10;
      plVar13 = plVar13 + 1;
      lVar14 = lVar14 + 4;
      lVar20 = lVar20 + -1;
    } while (lVar20 != 0);
    plVar13 = param_1 + 0x40;
    local_res8 = 0x10;
    uVar21 = uVar12;
    do {
      if (*plVar13 == 0) {
        *(undefined1 *)(param_1[0x6e] + 0x110 + uVar21) = 0;
      }
      else {
        *(undefined1 *)(param_1[0x6e] + 0x110 + uVar21) = 1;
        *(undefined4 *)(param_1[0x6e] + 0x114 + uVar21) = *(undefined4 *)(*plVar13 + 0x28);
        uVar8 = FUN_140374780(*plVar13);
        *(undefined4 *)(param_1[0x6e] + 0x118 + uVar21) = uVar8;
        lVar14 = uVar21 + 0x120;
        uVar16 = uVar12;
        do {
          puVar11 = (undefined8 *)FUN_140374820(*plVar13,uVar16);
          lVar19 = param_1[0x6e];
          if (*(undefined8 **)(lVar14 + lVar19) != puVar11) {
            if (puVar11 != (undefined8 *)0x0) {
              (**(code **)*puVar11)(puVar11);
            }
            if (*(longlong **)(lVar14 + lVar19) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(lVar14 + lVar19) + 8))();
            }
            *(undefined8 **)(lVar14 + lVar19) = puVar11;
          }
          uVar18 = (int)uVar16 + 1;
          uVar16 = (ulonglong)uVar18;
          lVar14 = lVar14 + 8;
        } while (uVar18 < 6);
      }
      plVar13 = plVar13 + 1;
      uVar21 = uVar21 + 0x40;
      local_res8 = local_res8 + -1;
    } while (local_res8 != 0);
    *(undefined4 *)(param_1[0x6e] + 0x20) = 0;
    FUN_1407e4830(param_1[0x6e] + 0x24,0,0x40);
    uVar21 = 0x24;
    plVar13 = param_1 + 0x40;
    do {
      lVar14 = *plVar13;
      if (lVar14 != 0) {
        fVar4 = *(float *)(lVar14 + 0x28);
        pfVar1 = (float *)(param_1[0x6e] + 0x20);
        if (*pfVar1 <= fVar4 && fVar4 != *pfVar1) {
          *(float *)(param_1[0x6e] + 0x20) = fVar4;
        }
        uVar18 = FUN_140374780(lVar14);
        uVar16 = uVar12;
        if (uVar18 != 0) {
          do {
            lVar19 = FUN_140374820(lVar14,uVar16);
            uVar15 = (int)uVar16 + 1;
            uVar16 = (ulonglong)uVar15;
            *(float *)(param_1[0x6e] + uVar21) =
                 *(float *)(lVar19 + 0x28) + *(float *)(param_1[0x6e] + uVar21);
          } while (uVar15 < uVar18);
        }
      }
      uVar21 = uVar21 + 4;
      plVar13 = plVar13 + 1;
    } while (uVar21 < 100);
    local_90 = FUN_140381970;
    local_58 = FUN_140381970;
    local_68 = 0xc;
    local_64 = 2;
    local_50 = 0;
    local_48 = 1;
    local_98 = param_1;
    local_60 = param_1;
    iVar9 = FUN_14019dca0(&local_68,0,0,param_1 + 0x6c);
    if (-1 < iVar9) {
      return 0;
    }
    lVar14 = *param_1;
    piVar17 = (int *)(lVar14 + 0x9d0);
    iVar9 = GetCurrentThreadId();
    if (*piVar17 == iVar9) {
      *(longlong *)(lVar14 + 0x9d8) = *(longlong *)(lVar14 + 0x9d8) + 1;
    }
    else {
      do {
        LOCK();
        bVar22 = *(longlong *)(lVar14 + 0x9d8) == 0;
        if (bVar22) {
          *(longlong *)(lVar14 + 0x9d8) = 1;
        }
        UNLOCK();
        if (bVar22) {
          *piVar17 = iVar9;
          goto LAB_140381704;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < 0x400);
      FUN_14019fb60(piVar17);
    }
LAB_140381704:
    lVar19 = param_1[0x6e];
    plVar13 = (longlong *)(*param_1 + 0x9f8);
    if (*(longlong *)(lVar19 + 0x520) == 0) {
      *(longlong **)(lVar19 + 0x520) = plVar13;
      plVar2 = (longlong *)(lVar19 + 0x528);
      *plVar2 = *plVar13;
      *plVar13 = lVar19;
      if (*plVar2 != 0) {
        *(longlong **)(*plVar2 + 0x520) = plVar2;
      }
    }
    param_1[0x6e] = 0;
    if (1 < *(ulonglong *)(lVar14 + 0x9d8)) {
      *(longlong *)(lVar14 + 0x9d8) = *(longlong *)(lVar14 + 0x9d8) + -1;
      return 1;
    }
    *piVar17 = 0;
    LOCK();
    *(undefined8 *)(lVar14 + 0x9d8) = 0;
    UNLOCK();
    if (*(longlong *)(lVar14 + 0x9e0) == 0) {
      return 1;
    }
    if (*(longlong *)(lVar14 + 0x9e8) == 0) {
      lVar19 = CreateEventW(0,0,0,0);
      LOCK();
      bVar22 = *(longlong *)(lVar14 + 0x9e8) == 0;
      if (bVar22) {
        *(longlong *)(lVar14 + 0x9e8) = lVar19;
      }
      UNLOCK();
      if (!bVar22) {
        CloseHandle();
      }
    }
    SetEvent(*(undefined8 *)(lVar14 + 0x9e8));
    return 1;
  }
  local_88[0] = 0;
  iVar9 = (**(code **)(*plVar13 + 0x20))(plVar13,local_88);
  if (iVar9 == 0) {
    return 0;
  }
  iVar9 = (**(code **)(*(longlong *)param_1[0x6c] + 0x28))((longlong *)param_1[0x6c],0);
  if (-1 < iVar9) {
    lVar14 = *(longlong *)(param_1[0x6e] + 0x18);
    if ((lVar14 != 0) && (*(longlong *)(param_1[0x6e] + 8) != 0)) {
      plVar13 = param_1 + 0x5e;
      iVar9 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,(int)lVar14 * 0x38,1,plVar13);
      if (-1 < iVar9) {
        plVar2 = param_1 + 0x61;
        iVar9 = (**(code **)(*DAT_140c65670 + 0x40))
                          (DAT_140c65670,(int)*(undefined8 *)(param_1[0x6e] + 8) * 2,0,1,plVar2);
        if ((-1 < iVar9) &&
           (_Dst = (void *)(**(code **)(*(longlong *)*plVar13 + 0x38))
                                     ((longlong *)*plVar13,0,
                                      (int)*(undefined8 *)(param_1[0x6e] + 0x18) * 0x38,2),
           _Dst != (void *)0x0)) {
          _Dst_00 = (void *)(**(code **)(*(longlong *)*plVar2 + 0x38))
                                      ((longlong *)*plVar2,0,
                                       (int)*(undefined8 *)(param_1[0x6e] + 8) * 2,2);
          if (_Dst_00 != (void *)0x0) {
            memcpy(_Dst,*(void **)(param_1[0x6e] + 0x10),*(longlong *)(param_1[0x6e] + 0x18) * 0x38)
            ;
            memcpy(_Dst_00,*(void **)param_1[0x6e],((undefined8 *)param_1[0x6e])[1] * 2);
            (**(code **)(*(longlong *)*plVar13 + 0x40))();
            (**(code **)(*(longlong *)*plVar2 + 0x40))();
            goto LAB_14038192f;
          }
          (**(code **)(*(longlong *)*plVar13 + 0x40))();
        }
      }
      if ((longlong *)*plVar13 != (longlong *)0x0) {
        (**(code **)(*(longlong *)*plVar13 + 8))();
        *plVar13 = 0;
      }
      if ((longlong *)param_1[0x61] != (longlong *)0x0) {
        (**(code **)(*(longlong *)param_1[0x61] + 8))();
        param_1[0x61] = 0;
      }
    }
  }
LAB_14038192f:
  FUN_140383760(param_1);
  return 1;
}



// WildStar64.exe / WSG, read-only Ghidra MCP force_decompile 140381970

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140381970(longlong param_1)

{
  longlong lVar1;
  short sVar2;
  short sVar3;
  char cVar4;
  char cVar7;
  undefined1 auVar8 [15];
  undefined1 auVar9 [15];
  undefined1 auVar10 [14];
  undefined1 auVar11 [15];
  undefined1 auVar12 [15];
  undefined1 auVar13 [15];
  undefined1 auVar14 [15];
  undefined1 auVar15 [15];
  undefined1 auVar16 [15];
  undefined1 auVar17 [15];
  unkuint9 Var18;
  undefined1 auVar19 [15];
  undefined1 auVar20 [13];
  undefined1 auVar21 [14];
  undefined1 auVar22 [15];
  uint6 uVar23;
  undefined1 auVar24 [16];
  int iVar25;
  longlong lVar26;
  void *_Dst;
  ulonglong uVar27;
  ulonglong uVar28;
  longlong *plVar29;
  uint uVar30;
  uint uVar31;
  longlong lVar32;
  longlong *plVar33;
  char *pcVar34;
  longlong lVar35;
  uint uVar36;
  undefined4 *puVar37;
  float *pfVar38;
  float *pfVar39;
  uint *puVar40;
  ushort uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  undefined1 uVar56;
  undefined1 uVar57;
  undefined8 uVar49;
  int iVar55;
  int iVar60;
  undefined1 auVar50 [12];
  undefined8 uVar61;
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 uVar59;
  ushort uVar58;
  undefined1 auVar54 [16];
  int iVar62;
  short sVar63;
  short sVar64;
  float fVar66;
  float fVar67;
  float fVar68;
  float fVar69;
  undefined1 uVar70;
  undefined1 uVar71;
  undefined1 uVar72;
  undefined1 uVar73;
  undefined1 uVar74;
  float fVar75;
  float fVar76;
  float fVar77;
  undefined1 auStack_418 [32];
  undefined4 local_3f8;
  undefined2 local_3f4;
  float local_3f0;
  undefined2 local_3ec;
  float local_3e8;
  undefined2 local_3e4;
  int local_3e0;
  undefined8 local_3d8;
  undefined8 local_3d0;
  undefined8 local_3c8;
  float local_3b8;
  float fStack_3b4;
  float fStack_3b0;
  float fStack_3ac;
  undefined1 local_3a8 [8];
  float fStack_3a0;
  float fStack_39c;
  float local_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  float local_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  undefined8 local_378;
  undefined8 uStack_370;
  ulonglong local_368;
  longlong local_360;
  int *local_358;
  undefined8 local_348;
  undefined8 uStack_340;
  longlong local_338;
  longlong local_330;
  longlong *local_328;
  undefined8 local_318;
  float fStack_310;
  float fStack_30c;
  longlong local_308;
  float fStack_300;
  float fStack_2fc;
  undefined4 local_2f8 [4];
  float local_2e8;
  float fStack_2e4;
  float fStack_2e0;
  float fStack_2dc;
  undefined1 local_2d8 [32];
  undefined1 local_2b8 [16];
  float local_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float fStack_29c;
  undefined1 local_298 [16];
  undefined1 local_288 [16];
  undefined1 local_278 [16];
  undefined4 local_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined1 *local_258;
  float *local_250;
  float local_238;
  float fStack_234;
  float fStack_230;
  float fStack_22c;
  float local_228;
  float fStack_224;
  float fStack_220;
  float fStack_21c;
  int local_218;
  byte local_1e8;
  int aiStack_1e0 [6];
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined4 local_1a8;
  uint local_e8 [4];
  ulonglong local_d8;
  char cVar5;
  char cVar6;
  undefined1 auVar53 [16];
  undefined6 uVar65;
  
  local_d8 = DAT_140c0f7b0 ^ (ulonglong)auStack_418;
  local_338 = param_1;
  FUN_140389e30(*(longlong *)(param_1 + 0x370) + 0x10,0);
  FUN_1401cfd00(*(undefined8 *)(param_1 + 0x370),0);
  FUN_140389f50(*(longlong *)(param_1 + 0x370) + 0x68,0);
  lVar32 = 4;
  local_360 = 0xd0;
  local_330 = 4;
  lVar26 = 0xd0;
  do {
    *(undefined8 *)(lVar26 + 8 + *(longlong *)(param_1 + 0x370)) = 0;
    lVar32 = lVar32 + -1;
    lVar26 = lVar26 + 0x10;
  } while (lVar32 != 0);
  lVar26 = FUN_14018b280(0x18);
  if (lVar26 == 0) {
    local_328 = (longlong *)0x0;
  }
  else {
    local_328 = (longlong *)FUN_1401ae310(lVar26);
  }
  plVar33 = local_328;
  local_358 = (int *)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x28))();
  (**(code **)(*plVar33 + 0x10))(plVar33,local_358[1] * 0x800 + *local_358);
  uVar36 = 0;
  local_3d8 = (int *)((ulonglong)local_3d8._4_4_ << 0x20);
  local_3d0 = (uint *)((ulonglong)local_3d0._4_4_ << 0x20);
  local_e8[0] = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_3c8 = (ulonglong)local_3c8._4_4_ << 0x20;
  uVar30 = (int)(longlong)*(float *)(*(longlong *)(param_1 + 0x370) + 0x20) << 4;
  if (8000 < uVar30) {
    uVar30 = 8000;
  }
  uVar30 = uVar30 >> ((byte)*(undefined4 *)
                             (&DAT_140b65cc8 + (longlong)*(int *)(param_1 + 0x368) * 4) & 0x1f);
  local_368 = (ulonglong)uVar30;
  local_3f0 = 0.0;
  if (uVar30 != 0) {
LAB_140381b30:
    fVar75 = local_3f0;
    uVar42 = (**(code **)(*plVar33 + 0x48))(plVar33);
    uVar43 = (**(code **)(*plVar33 + 0x48))(plVar33);
    local_378 = CONCAT44(uVar42,uVar43);
    uStack_370 = 0;
    fVar44 = (float)(**(code **)(*plVar33 + 0x38))(plVar33);
    fVar45 = (float)(**(code **)(*plVar33 + 0x38))(plVar33);
    fVar46 = (float)(**(code **)(*plVar33 + 0x38))(plVar33);
    fVar47 = (float)(**(code **)(*plVar33 + 0x38))(plVar33);
    fVar48 = (float)(**(code **)(*plVar33 + 0x38))(plVar33);
    (**(code **)(**(longlong **)(param_1 + 0x10) + 0xc0))
              (*(longlong **)(param_1 + 0x10),&local_378,&local_258,0x1411);
    if ((local_218 == 0) && ((local_1e8 & 0x20) == 0)) {
      lVar26 = *(longlong *)(param_1 + 0x370);
      uVar27 = 0;
      pfVar38 = (float *)&local_348;
      fVar66 = *(float *)(lVar26 + 0xc0) * local_238;
      fVar67 = *(float *)(lVar26 + 0xc4) * fStack_234;
      fVar68 = *(float *)(lVar26 + 200) * fStack_230;
      fVar69 = *(float *)(lVar26 + 0xcc) * fStack_22c;
      fVar66 = fVar66 * fVar66;
      fVar67 = fVar67 * fVar67;
      fVar68 = fVar68 * fVar68;
      fVar69 = fVar69 * fVar69;
      fVar77 = fStack_234 * 1.0 + fStack_22c * 1.0 + local_238 * 1.0 + fStack_230 * 1.0;
      fVar76 = fVar77 / (fVar67 + fVar69 + fVar66 + fVar68);
      fVar66 = fVar76 * fVar66;
      fVar67 = fVar76 * fVar67;
      fVar68 = fVar76 * fVar68;
      fVar76 = fVar76 * fVar69;
      local_348 = (undefined1 *)CONCAT44(fVar67,fVar66);
      uStack_340 = (float *)CONCAT44(fVar76,fVar68);
      do {
        fVar44 = fVar44 - *pfVar38;
        if (fVar44 <= 0.0) break;
        uVar30 = (int)uVar27 + 1;
        uVar27 = (ulonglong)uVar30;
        pfVar38 = pfVar38 + 1;
      } while (uVar30 < 4);
      if (((int)uVar27 == 4) ||
         (pfVar38 = (float *)((longlong)&local_348 + uVar27 * 4),
         *pfVar38 <= 0.25 && *pfVar38 != 0.25)) goto LAB_1403820fd;
      uVar28 = (ulonglong)(uint)(aiStack_1e0[uVar27] + (int)uVar27 * 4);
      fVar44 = *(float *)(lVar26 + 0x24 + uVar28 * 4);
      if ((fVar44 == 0.0) ||
         ((pcVar34 = (char *)(lVar26 + 0x110 + uVar28 * 0x40), *pcVar34 == '\0' ||
          (fVar45 = fVar45 * *(float *)(lVar26 + 0x20),
          *(float *)(pcVar34 + 4) <= fVar45 && fVar45 != *(float *)(pcVar34 + 4)))))
      goto LAB_1403820fd;
      uVar30 = *(uint *)(pcVar34 + 8);
      uVar28 = 0;
      lVar26 = 0;
      fVar46 = fVar46 * fVar44;
      uVar56 = SUB41(fVar46,0);
      uVar57 = (undefined1)((uint)fVar46 >> 8);
      uVar59 = (undefined1)((uint)fVar46 >> 0x10);
      uVar70 = (undefined1)((uint)fVar46 >> 0x18);
      if (3 < (int)uVar30) {
        plVar29 = (longlong *)(pcVar34 + 0x10);
        do {
          fVar46 = (float)CONCAT13(uVar70,CONCAT12(uVar59,CONCAT11(uVar57,uVar56))) -
                   *(float *)(*plVar29 + 0x28);
          if (fVar46 <= 0.0) goto LAB_140381d91;
          fVar46 = fVar46 - *(float *)(plVar29[1] + 0x28);
          iVar25 = (int)uVar28;
          if (fVar46 <= 0.0) {
            uVar28 = (ulonglong)(iVar25 + 1);
            goto LAB_140381d91;
          }
          fVar46 = fVar46 - *(float *)(plVar29[2] + 0x28);
          if (fVar46 <= 0.0) {
            uVar28 = (ulonglong)(iVar25 + 2);
            goto LAB_140381d91;
          }
          fVar46 = fVar46 - *(float *)(plVar29[3] + 0x28);
          uVar56 = SUB41(fVar46,0);
          uVar57 = (undefined1)((uint)fVar46 >> 8);
          uVar59 = (undefined1)((uint)fVar46 >> 0x10);
          uVar70 = (undefined1)((uint)fVar46 >> 0x18);
          if (fVar46 <= 0.0) {
            uVar28 = (ulonglong)(iVar25 + 3);
            goto LAB_140381d91;
          }
          uVar28 = (ulonglong)(iVar25 + 4U);
          lVar26 = lVar26 + 4;
          plVar29 = plVar29 + 4;
        } while (iVar25 + 4U < uVar30 - 3);
      }
      if ((uint)uVar28 < uVar30) {
        plVar29 = (longlong *)(pcVar34 + (lVar26 + 2) * 8);
        do {
          fVar46 = (float)CONCAT13(uVar70,CONCAT12(uVar59,CONCAT11(uVar57,uVar56))) -
                   *(float *)(*plVar29 + 0x28);
          uVar56 = SUB41(fVar46,0);
          uVar57 = (undefined1)((uint)fVar46 >> 8);
          uVar59 = (undefined1)((uint)fVar46 >> 0x10);
          uVar70 = (undefined1)((uint)fVar46 >> 0x18);
          if (fVar46 <= 0.0) goto LAB_140381d91;
          uVar31 = (int)uVar28 + 1;
          uVar28 = (ulonglong)uVar31;
          plVar29 = plVar29 + 1;
        } while (uVar31 < uVar30);
      }
      goto LAB_140381d96;
    }
    goto LAB_1403820fd;
  }
LAB_14038286c:
  (**(code **)(*plVar33 + 8))(plVar33);
  return 0;
LAB_140381d91:
  if (uVar30 <= (uint)uVar28) {
LAB_140381d96:
    uVar28 = (ulonglong)(uVar30 - 1);
  }
  lVar26 = *(longlong *)(pcVar34 + uVar28 * 8 + 0x10);
  local_2f8[0] = 0xffffffff;
  plVar29 = *(longlong **)(lVar26 + 0x10);
  if ((plVar29 != (longlong *)0x0) &&
     (iVar25 = (**(code **)(*plVar29 + 0x20))(plVar29,local_2f8), iVar25 != 0)) {
    FUN_140373540(lVar26);
    if (*(longlong **)(lVar26 + 0x10) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(lVar26 + 0x10) + 8))();
      *(undefined8 *)(lVar26 + 0x10) = 0;
    }
  }
  if (*(longlong *)(lVar26 + 0x50) != 0) {
    lVar32 = *(longlong *)(*(longlong *)(lVar26 + 0x50) + 600);
    if ((0x4000 < (uint)((int)local_3d0 + *(int *)(lVar32 + 0x18))) ||
       (0x10000 < *(int *)(lVar32 + 0x68) + uVar36)) goto LAB_14038210f;
    FUN_140387000(param_1,&local_378,&local_1c8,3);
    uVar28 = (ulonglong)local_3d8 & 0xffffffff;
    local_3e0 = (int)local_3d8 + 1;
    FUN_140389f50(*(longlong *)(param_1 + 0x370) + 0x68,local_3e0);
    puVar37 = (undefined4 *)(uVar28 * 0x80 + *(longlong *)(*(longlong *)(param_1 + 0x370) + 0x68));
    FUN_1401c95b0(&local_3f8,&local_378);
    *puVar37 = local_3f8;
    fVar46 = (float)local_358[0xc];
    fVar75 = (float)local_358[8];
    fVar44 = (float)local_358[8];
    puVar37[5] = local_1a8;
    puVar37[4] = (fVar46 - fVar75) * (float)local_378 + fVar44;
    puVar37[6] = ((float)local_358[0xe] - (float)local_358[10]) * local_378._4_4_ +
                 (float)local_358[10];
    *(undefined8 *)(puVar37 + 8) = local_1c8;
    *(undefined8 *)(puVar37 + 10) = uStack_1c0;
    FUN_1401c9800(&local_3e8);
    puVar37[0xc] = local_3e8;
    *(undefined2 *)(puVar37 + 0xd) = local_3e4;
    (**(code **)(**(longlong **)(param_1 + 0x10) + 0xc0))
              (*(longlong **)(param_1 + 0x10),&local_378,&local_258,0x20);
    if ((*(byte *)(lVar26 + 0x24) & 4) == 0) {
      puVar37[0x10] = local_228;
      puVar37[0x11] = fStack_224;
      puVar37[0x13] = 0x3f800000;
      puVar37[0x12] = fStack_220;
      *(undefined8 *)(puVar37 + 0x14) = 0;
      *(undefined8 *)(puVar37 + 0x16) = 0;
    }
    else {
      lVar35 = *(longlong *)(param_1 + 0x370);
      pfVar38 = (float *)(lVar35 + (uVar27 + 8) * 0x10);
      fVar46 = *pfVar38;
      fVar75 = pfVar38[1];
      fStack_300 = pfVar38[2];
      local_308 = *(longlong *)pfVar38;
      fStack_2fc = pfVar38[3];
      fVar44 = (1.0 - fVar77) * 0.5;
      fVar45 = (fVar44 + fVar67 * *(float *)(lVar35 + 0x90) + fVar66 * *(float *)(lVar35 + 0x80) +
                         fVar68 * *(float *)(lVar35 + 0xa0) + fVar76 * *(float *)(lVar35 + 0xb0)) *
               local_228;
      fVar69 = (fVar44 + fVar67 * *(float *)(lVar35 + 0x94) + fVar66 * *(float *)(lVar35 + 0x84) +
                         fVar68 * *(float *)(lVar35 + 0xa4) + fVar76 * *(float *)(lVar35 + 0xb4)) *
               fStack_224;
      fStack_310 = (fVar44 + fVar67 * *(float *)(lVar35 + 0x98) + fVar66 * *(float *)(lVar35 + 0x88)
                             + fVar68 * *(float *)(lVar35 + 0xa8) +
                             fVar76 * *(float *)(lVar35 + 0xb8)) * fStack_220;
      local_318 = CONCAT44(fVar69,fVar45);
      fStack_30c = (fVar44 + fVar67 * *(float *)(lVar35 + 0x9c) + fVar66 * *(float *)(lVar35 + 0x8c)
                             + fVar68 * *(float *)(lVar35 + 0xac) +
                             fVar76 * *(float *)(lVar35 + 0xbc)) * fStack_21c;
      if (fVar46 <= fVar45) {
        puVar37[0x10] = 0x3f800000;
        puVar37[0x14] = fVar45 - fVar46;
      }
      else {
        puVar37[0x14] = 0;
        puVar37[0x10] = fVar45 / fVar46;
      }
      if (fVar75 <= fVar69) {
        puVar37[0x11] = 0x3f800000;
        puVar37[0x15] = fVar69 - fVar75;
      }
      else {
        puVar37[0x15] = 0;
        puVar37[0x11] = fVar69 / fVar75;
      }
      if (fStack_300 <= fStack_310) {
        puVar37[0x12] = 0x3f800000;
        puVar37[0x13] = 0x3f800000;
        puVar37[0x16] = fStack_310 - fStack_300;
        puVar37[0x17] = 0;
      }
      else {
        puVar37[0x16] = 0;
        puVar37[0x13] = 0x3f800000;
        puVar37[0x17] = 0;
        puVar37[0x12] = fStack_310 / fStack_300;
      }
    }
    uVar30 = local_e8[uVar27];
    puVar37[0x18] = *(undefined4 *)(lVar26 + 0x38);
    puVar37[0x19] = (1.0 - *(float *)(lVar26 + 0x2c)) * fVar47 + *(float *)(lVar26 + 0x2c);
    fVar46 = *(float *)(lVar26 + 0x34);
    fVar75 = *(float *)(lVar26 + 0x30);
    fVar44 = *(float *)(lVar26 + 0x30);
    *(longlong *)(puVar37 + 0x1c) = lVar26;
    lVar35 = (uVar27 + 0xd) * 0x10;
    puVar37[0x1a] = (fVar46 - fVar75) * fVar48 + fVar44;
    uVar36 = uVar30 + 1;
    FUN_140052360(*(longlong *)(param_1 + 0x370) + lVar35,uVar36);
    lVar26 = *(longlong *)(param_1 + 0x370);
    local_e8[uVar27] = uVar36;
    *(int *)(*(longlong *)(lVar35 + lVar26) + (ulonglong)uVar30 * 4) = (int)local_3d8;
    local_3d8 = (int *)CONCAT44(local_3d8._4_4_,local_3e0);
    uVar36 = (int)local_3c8 + *(int *)(lVar32 + 0x68);
    local_3c8 = CONCAT44(local_3c8._4_4_,uVar36);
    local_3d0 = (uint *)CONCAT44(local_3d0._4_4_,(int)local_3d0 + *(int *)(lVar32 + 0x18));
    fVar75 = local_3f0;
  }
LAB_1403820fd:
  local_3f0 = (float)((int)fVar75 + 1);
  if ((uint)(float)local_368 <= (uint)local_3f0) goto LAB_14038210f;
  goto LAB_140381b30;
LAB_14038210f:
  if (uVar36 != 0) {
    uVar27 = (ulonglong)uVar36;
    plVar33 = *(longlong **)(param_1 + 0x370);
    if ((ulonglong)plVar33[1] <= uVar27) {
      _Dst = (void *)FUN_14018db00(*plVar33,uVar27,2);
      if ((void *)*plVar33 != _Dst) {
        memcpy(_Dst,(void *)*plVar33,plVar33[1] * 2);
        lVar26 = *plVar33;
        if (lVar26 != 0) {
          (**(code **)(*(longlong *)(lVar26 + -0x10) + 8))(lVar26 + -0x10);
        }
        *plVar33 = (longlong)_Dst;
      }
    }
    plVar33[1] = uVar27;
    FUN_140389e30(*(longlong *)(param_1 + 0x370) + 0x10,(ulonglong)local_3d0 & 0xffffffff);
    lVar32 = 0;
    local_3d8 = (int *)(param_1 + 0x2f8);
    local_368 = (*(undefined8 **)(param_1 + 0x370))[2];
    lVar35 = 0;
    lVar26 = (longlong)local_e8 - param_1;
    local_358 = (int *)**(undefined8 **)(param_1 + 0x370);
    local_3c8 = 0;
    local_378 = lVar26;
    do {
      auVar24 = _DAT_140b7b240;
      uVar30 = *(uint *)(lVar26 + -0x2f8 + (longlong)local_3d8);
      if (uVar30 != 0) {
        local_308 = lVar35;
        puVar40 = *(uint **)(local_360 + *(longlong *)(param_1 + 0x370));
        local_318 = lVar32;
        local_3d0 = puVar40 + uVar30;
        if (puVar40 < puVar40 + uVar30) {
          do {
            uVar30 = *puVar40;
            puVar40 = puVar40 + 1;
            local_2f8[0] = 0xffffffff;
            pfVar38 = (float *)((ulonglong)uVar30 * 0x80 +
                               *(longlong *)(*(longlong *)(param_1 + 0x370) + 0x68));
            lVar26 = *(longlong *)(pfVar38 + 0x1c);
            if ((*(longlong **)(lVar26 + 0x10) != (longlong *)0x0) &&
               (iVar25 = (**(code **)(**(longlong **)(lVar26 + 0x10) + 0x20))(), iVar25 != 0)) {
              FUN_140373540(lVar26);
              if (*(longlong **)(lVar26 + 0x10) != (longlong *)0x0) {
                (**(code **)(**(longlong **)(lVar26 + 0x10) + 8))();
                *(undefined8 *)(lVar26 + 0x10) = 0;
              }
            }
            lVar1 = *(longlong *)(*(longlong *)(lVar26 + 0x50) + 600);
            if (pfVar38[0x1a] == 0.0) {
              uVar56 = DAT_140c783a0;
              uVar57 = DAT_140c783a0._1_1_;
              uVar59 = DAT_140c783a0._2_1_;
              uVar70 = DAT_140c783a0._3_1_;
              uVar71 = DAT_140c783a0._4_1_;
              uVar72 = DAT_140c783a0._5_1_;
              uVar73 = DAT_140c783a0._6_1_;
              uVar74 = DAT_140c783a0._7_1_;
              fVar46 = DAT_140c783a0._8_4_;
              fVar75 = DAT_140c783a0._12_4_;
              fStack_3ac = fRam0000000140c7839c;
              _local_3a8 = _DAT_140c783a0;
              fStack_38c = fRam0000000140c783bc;
              fVar44 = _DAT_140c78390;
              fVar45 = fRam0000000140c78394;
              fVar47 = fRam0000000140c78398;
              fVar48 = _DAT_140c783b0;
              fVar66 = fRam0000000140c783b4;
              fVar67 = fRam0000000140c783b8;
              uVar49 = _DAT_140c783c0;
              uVar61 = uRam0000000140c783c8;
            }
            else {
              fVar66 = (float)FUN_1408fe3d0();
              fVar67 = (float)FUN_1408fc950();
              fVar68 = (float)FUN_1408fe3d0();
              fVar69 = (float)FUN_1408fc950();
              fStack_3ac = 0.0;
              fStack_38c = 0.0;
              local_3a8._0_4_ = fVar67 * fVar68 * fVar66 - fVar66 * fVar67;
              local_3a8._4_4_ = fVar66 * fVar68 * fVar66 + fVar67 * fVar67;
              fVar46 = fVar69 * fVar66;
              fStack_3a0 = fVar46;
              fStack_39c = 0.0;
              uVar56 = (undefined1)local_3a8._0_4_;
              uVar57 = (undefined1)((uint)local_3a8._0_4_ >> 8);
              uVar59 = (undefined1)((uint)local_3a8._0_4_ >> 0x10);
              uVar70 = (undefined1)((uint)local_3a8._0_4_ >> 0x18);
              uVar71 = (undefined1)local_3a8._4_4_;
              uVar72 = (undefined1)((uint)local_3a8._4_4_ >> 8);
              uVar73 = (undefined1)((uint)local_3a8._4_4_ >> 0x10);
              uVar74 = (undefined1)((uint)local_3a8._4_4_ >> 0x18);
              fVar75 = 0.0;
              fVar44 = fVar67 * fVar69;
              fVar45 = fVar66 * fVar69;
              fVar47 = -fVar68;
              fVar48 = fVar66 * fVar66 + fVar67 * fVar68 * fVar67;
              fVar66 = fVar66 * fVar68 * fVar67 - fVar67 * fVar66;
              fVar67 = fVar69 * fVar67;
              uVar49 = _DAT_140c78440;
              uVar61 = uRam0000000140c78448;
            }
            uVar27 = local_368;
            if ((*(byte *)(lVar26 + 0x24) & 2) != 0) {
              auVar50 = *(undefined1 (*) [12])(pfVar38 + 8);
              uVar56 = auVar50[0];
              uVar57 = auVar50[1];
              uVar59 = auVar50[2];
              uVar70 = auVar50[3];
              uVar71 = auVar50[4];
              uVar72 = auVar50[5];
              uVar73 = auVar50[6];
              uVar74 = auVar50[7];
              fVar46 = auVar50._8_4_;
              fVar75 = auVar50._0_4_;
              fVar68 = auVar50._4_4_;
              fVar48 = fVar46 * fVar45 - fVar68 * fVar47;
              fVar66 = fVar75 * fVar47 - fVar46 * fVar44;
              fVar47 = fVar68 * fVar44 - fVar75 * fVar45;
              fVar67 = fStack_39c * fStack_3ac - fStack_39c * fStack_3ac;
              fVar44 = fVar66 * fVar66;
              auVar51._4_4_ = fVar44;
              auVar51._0_4_ = fVar44;
              auVar51._8_4_ = fVar44;
              auVar51._12_4_ = fVar44;
              fVar45 = fVar48 * fVar48 + fVar44 + fVar47 * fVar47;
              auVar52._4_4_ = fVar44;
              auVar52._0_4_ = fVar45;
              auVar52._8_4_ = fVar47 * fVar47;
              auVar52._12_4_ = fVar67 * fVar67;
              auVar52 = rsqrtss(auVar51,auVar52);
              fVar67 = auVar52._0_4_;
              fVar67 = (3.0 - fVar45 * fVar67 * fVar67) * 0.5 * fVar67;
              if (fVar67 <= 0.0) {
                fVar67 = 0.0;
              }
              fVar48 = fVar67 * fVar48;
              fVar66 = fVar67 * fVar66;
              fVar67 = fVar67 * fVar47;
              fVar44 = fVar67 * fVar68 - fVar66 * fVar46;
              fVar45 = fVar48 * fVar46 - fVar67 * fVar75;
              fVar47 = fVar66 * fVar75 - fVar48 * fVar68;
              fVar75 = fStack_39c;
            }
            fVar68 = pfVar38[0x19];
            fStack_384 = (float)((ulonglong)uVar49 >> 0x20);
            local_3e0 = 0;
            _local_3b8 = CONCAT44(fVar45 * fVar68,fVar44 * fVar68);
            fStack_3b0 = fVar47 * fVar68;
            fStack_3ac = fStack_3ac * fVar68;
            fVar44 = pfVar38[0x19];
            fVar45 = (float)CONCAT13(uVar74,CONCAT12(uVar73,CONCAT11(uVar72,uVar71))) * fVar44;
            local_3a8[4] = SUB41(fVar45,0);
            local_3a8._0_4_ =
                 (float)CONCAT13(uVar70,CONCAT12(uVar59,CONCAT11(uVar57,uVar56))) * fVar44;
            local_3a8[5] = (char)((uint)fVar45 >> 8);
            local_3a8[6] = (char)((uint)fVar45 >> 0x10);
            local_3a8[7] = (char)((uint)fVar45 >> 0x18);
            fStack_3a0 = fVar46 * fVar44;
            fStack_39c = fVar75 * fVar44;
            fVar46 = pfVar38[0x19];
            local_388 = (float)uVar49;
            _local_398 = CONCAT44(fVar66 * fVar46,fVar48 * fVar46);
            fStack_390 = fVar67 * fVar46;
            fStack_38c = fStack_38c * fVar46;
            fStack_380 = (float)uVar61;
            _local_388 = CONCAT44(fStack_384 + pfVar38[5],local_388 + pfVar38[4]);
            fStack_37c = (float)((ulonglong)uVar61 >> 0x20);
            _fStack_380 = CONCAT44(fStack_37c,fStack_380 + pfVar38[6]);
            auVar52 = maxps(ZEXT816(0),*(undefined1 (*) [16])(pfVar38 + 0x14));
            auVar52 = minps(auVar52,auVar24);
            iVar25 = (int)(auVar52._0_4_ * 255.0 + 0.5);
            iVar55 = (int)(auVar52._4_4_ * 255.0 + 0.5);
            iVar60 = (int)(auVar52._8_4_ * 255.0 + 0.5);
            sVar2 = (short)iVar60;
            cVar4 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar60 - (0xff < sVar2);
            sVar2 = (short)((uint)iVar60 >> 0x10);
            sVar63 = CONCAT11((0 < sVar2) * (sVar2 < 0x100) * (char)((uint)iVar60 >> 0x10) -
                              (0xff < sVar2),cVar4);
            sVar2 = (short)iVar55;
            cVar5 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar55 - (0xff < sVar2);
            sVar2 = (short)((uint)iVar55 >> 0x10);
            uVar42 = CONCAT13((0 < sVar2) * (sVar2 < 0x100) * (char)((uint)iVar55 >> 0x10) -
                              (0xff < sVar2),CONCAT12(cVar5,sVar63));
            sVar2 = (short)iVar25;
            cVar6 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar25 - (0xff < sVar2);
            sVar3 = (short)((uint)iVar25 >> 0x10);
            sVar2 = (short)((uint)uVar42 >> 0x10);
            sVar3 = (short)(CONCAT15((0 < sVar3) * (sVar3 < 0x100) * (char)((uint)iVar25 >> 0x10) -
                                     (0xff < sVar3),CONCAT14(cVar6,uVar42)) >> 0x20);
            uVar28 = (ulonglong)
                     CONCAT12((0 < sVar3) * (sVar3 < 0x100) * cVar6 - (0xff < sVar3),
                              CONCAT11((0 < sVar2) * (sVar2 < 0x100) * cVar5 - (0xff < sVar2),
                                       (0 < sVar63) * (sVar63 < 0x100) * cVar4 - (0xff < sVar63)));
            if (*(int *)(lVar1 + 0x18) != 0) {
              uVar30 = 0;
              local_348 = local_298;
              uStack_340 = &local_3b8;
              do {
                puVar37 = (undefined4 *)((ulonglong)uVar30 * 0x4c + *(longlong *)(lVar26 + 0x138));
                pfVar39 = (float *)(((ulonglong)uVar30 + lVar35) * 0x38 + uVar27);
                local_298._12_4_ = 0;
                local_298._0_12_ = *(undefined1 (*) [12])(puVar37 + 3);
                local_288._12_4_ = 0;
                local_288._0_12_ = *(undefined1 (*) [12])(puVar37 + 6);
                uStack_260 = puVar37[2];
                uStack_264 = puVar37[1];
                local_278._12_4_ = 0;
                local_278._0_12_ = *(undefined1 (*) [12])(puVar37 + 9);
                local_268 = *puVar37;
                uStack_25c = 0x3f800000;
                local_258 = local_298;
                local_250 = &local_3b8;
                FUN_1401afb10(&local_258,local_2d8);
                *pfVar39 = local_2a8;
                pfVar39[1] = fStack_2a4;
                pfVar39[2] = fStack_2a0;
                FUN_1401c9800(&local_3e8,local_2d8);
                pfVar39[3] = local_3e8;
                *(undefined2 *)(pfVar39 + 4) = local_3e4;
                pfVar39[5] = pfVar38[0xc];
                *(undefined2 *)(pfVar39 + 6) = *(undefined2 *)(pfVar38 + 0xd);
                FUN_1401c9800(&local_3f0,local_2b8);
                pfVar39[7] = local_3f0;
                *(undefined2 *)(pfVar39 + 8) = local_3ec;
                pfVar39[9] = (float)puVar37[0x10];
                pfVar39[10] = *pfVar38;
                pfVar39[0xb] = pfVar38[0x18];
                uVar42 = puVar37[0xe];
                auVar50._0_8_ = CONCAT44(uVar42,uVar42);
                auVar50._8_4_ = uVar42;
                auVar53._12_4_ = uVar42;
                auVar53._0_12_ = auVar50;
                uVar59 = (undefined1)((uint)uVar42 >> 0x18);
                auVar8[0xd] = 0;
                auVar8._0_13_ = auVar53._0_13_;
                auVar8[0xe] = uVar59;
                uVar57 = (undefined1)((uint)uVar42 >> 0x10);
                auVar9[0xc] = uVar57;
                auVar9._0_12_ = auVar50;
                auVar9._13_2_ = auVar8._13_2_;
                auVar11[0xb] = 0;
                auVar11._0_11_ = auVar50._0_11_;
                auVar11._12_3_ = auVar9._12_3_;
                uVar56 = (undefined1)((uint)uVar42 >> 8);
                auVar12[10] = uVar56;
                auVar12._0_10_ = auVar50._0_10_;
                auVar12._11_4_ = auVar11._11_4_;
                auVar13[9] = 0;
                auVar13._0_9_ = auVar50._0_9_;
                auVar13._10_5_ = auVar12._10_5_;
                auVar14[8] = (byte)uVar42;
                auVar14._0_8_ = auVar50._0_8_;
                auVar14._9_6_ = auVar13._9_6_;
                auVar17._7_8_ = 0;
                auVar17._0_7_ = auVar14._8_7_;
                Var18 = CONCAT81(SUB158(auVar17 << 0x40,7),uVar59);
                auVar22._9_6_ = 0;
                auVar22._0_9_ = Var18;
                auVar15[4] = uVar57;
                auVar15._0_4_ = uVar42;
                auVar15._5_10_ = SUB1510(auVar22 << 0x30,5);
                auVar19._11_4_ = 0;
                auVar19._0_11_ = auVar15._4_11_;
                auVar20._1_12_ = SUB1512(auVar19 << 0x20,3);
                auVar20[0] = uVar56;
                uVar41 = CONCAT11(0,(byte)uVar42);
                auVar16._2_13_ = auVar20;
                auVar16._0_2_ = uVar41;
                uVar58 = (ushort)Var18;
                auVar10._10_2_ = 0;
                auVar10._0_10_ = auVar16._0_10_;
                auVar10._12_2_ = uVar58;
                uVar23 = CONCAT42(auVar10._10_4_,auVar15._4_2_);
                auVar21._6_8_ = 0;
                auVar21._0_6_ = uVar23;
                auVar54._0_4_ = pfVar38[0x10] * (float)(int)uVar23 * 0.003921569;
                auVar54._4_4_ =
                     pfVar38[0x11] *
                     (float)(int)CONCAT82(SUB148(auVar21 << 0x40,6),auVar20._0_2_) * 0.003921569;
                auVar54._8_4_ = pfVar38[0x12] * (float)uVar41 * 0.003921569;
                auVar54._12_4_ = pfVar38[0x13] * (float)uVar58 * 0.003921569;
                auVar52 = maxps(ZEXT816(0),auVar54);
                auVar52 = minps(auVar52,auVar24);
                iVar25 = (int)(auVar52._0_4_ * 255.0 + 0.5);
                iVar55 = (int)(auVar52._4_4_ * 255.0 + 0.5);
                iVar60 = (int)(auVar52._8_4_ * 255.0 + 0.5);
                iVar62 = (int)(auVar52._12_4_ * 255.0 + 0.5);
                sVar2 = (short)iVar60;
                cVar4 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar60 - (0xff < sVar2);
                sVar2 = (short)((uint)iVar60 >> 0x10);
                sVar64 = CONCAT11((0 < sVar2) * (sVar2 < 0x100) * (char)((uint)iVar60 >> 0x10) -
                                  (0xff < sVar2),cVar4);
                sVar2 = (short)iVar55;
                cVar5 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar55 - (0xff < sVar2);
                sVar2 = (short)((uint)iVar55 >> 0x10);
                uVar42 = CONCAT13((0 < sVar2) * (sVar2 < 0x100) * (char)((uint)iVar55 >> 0x10) -
                                  (0xff < sVar2),CONCAT12(cVar5,sVar64));
                sVar2 = (short)iVar25;
                cVar6 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar25 - (0xff < sVar2);
                sVar2 = (short)((uint)iVar25 >> 0x10);
                uVar65 = CONCAT15((0 < sVar2) * (sVar2 < 0x100) * (char)((uint)iVar25 >> 0x10) -
                                  (0xff < sVar2),CONCAT14(cVar6,uVar42));
                sVar2 = (short)iVar62;
                cVar7 = (0 < sVar2) * (sVar2 < 0x100) * (char)iVar62 - (0xff < sVar2);
                sVar63 = (short)((uint)iVar62 >> 0x10);
                sVar2 = (short)((uint)uVar42 >> 0x10);
                sVar3 = (short)((uint6)uVar65 >> 0x20);
                sVar63 = (short)(CONCAT17((0 < sVar63) * (sVar63 < 0x100) *
                                          (char)((uint)iVar62 >> 0x10) - (0xff < sVar63),
                                          CONCAT16(cVar7,uVar65)) >> 0x30);
                pfVar39[0xc] = (float)CONCAT13((0 < sVar63) * (sVar63 < 0x100) * cVar7 -
                                               (0xff < sVar63),
                                               CONCAT12((0 < sVar3) * (sVar3 < 0x100) * cVar6 -
                                                        (0xff < sVar3),
                                                        CONCAT11((0 < sVar2) * (sVar2 < 0x100) *
                                                                 cVar5 - (0xff < sVar2),
                                                                 (0 < sVar64) * (sVar64 < 0x100) *
                                                                 cVar4 - (0xff < sVar64))));
                pfVar39[0xd] = (float)((uint)*(byte *)(puVar37 + 0x12) << 0x18 | (uint)uVar28);
                local_2e8 = local_2a8 - local_388;
                fStack_2e4 = fStack_2a4 - fStack_384;
                fStack_2e0 = fStack_2a0 - fStack_380;
                fStack_2dc = fStack_29c - fStack_37c;
                FUN_1401c9800(&local_3f8,&local_2e8);
                *(undefined2 *)((longlong)pfVar39 + 0x1a) = local_3f8._2_2_;
                uVar30 = uVar30 + 1;
                *(undefined2 *)((longlong)pfVar39 + 0x22) = local_3f4;
                *(undefined2 *)((longlong)pfVar39 + 0x12) = (undefined2)local_3f8;
                param_1 = local_338;
                lVar32 = local_3c8;
              } while (uVar30 < *(uint *)(lVar1 + 0x18));
            }
            lVar26 = *(longlong *)(lVar1 + 0x78);
            uVar27 = 0;
            if (*(int *)(lVar1 + 0x68) != 0) {
              do {
                uVar30 = (int)uVar27 + 1;
                *(short *)((longlong)local_358 + (uVar27 + lVar32) * 2) =
                     *(short *)(lVar26 + uVar27 * 2) + (short)lVar35;
                uVar27 = (ulonglong)uVar30;
              } while (uVar30 < *(uint *)(lVar1 + 0x68));
            }
            lVar35 = lVar35 + (ulonglong)*(uint *)(lVar1 + 0x18);
            lVar32 = lVar32 + (ulonglong)*(uint *)(lVar1 + 0x68);
            local_3c8 = lVar32;
          } while (puVar40 < local_3d0);
        }
        local_3d8[-6] = (int)lVar35 - (int)local_308;
        *local_3d8 = (int)lVar32 - (int)local_318;
        lVar26 = local_378;
      }
      local_360 = local_360 + 0x10;
      local_3d8 = local_3d8 + 1;
      local_330 = local_330 + -1;
      plVar33 = local_328;
    } while (local_330 != 0);
  }
  goto LAB_14038286c;
}



// WildStar64.exe / WSG, read-only Ghidra MCP force_decompile 140374420


undefined8 FUN_140374420(longlong param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  longlong *plVar7;

  int iVar8;

  longlong lVar9;

  longlong *plVar10;

  float *pfVar11;

  longlong lVar12;

  short *psVar13;

  ulonglong uVar14;

  ulonglong *puVar15;

  longlong lVar16;

  

  lVar9 = FUN_140350f40(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),

                        *(undefined4 *)(param_1 + 0x18));

  if (lVar9 == 0) {

    return 0x80004005;

  }

  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(lVar9 + 0x14);

  lVar16 = 6;

  plVar10 = (longlong *)(param_1 + 0x30);

  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(lVar9 + 0x10);

  lVar12 = 6;

  do {

    if ((longlong *)*plVar10 != (longlong *)0x0) {

      (**(code **)(*(longlong *)*plVar10 + 8))();

      *plVar10 = 0;

    }

    plVar10 = plVar10 + 1;

    lVar12 = lVar12 + -1;

  } while (lVar12 != 0);

  puVar15 = (ulonglong *)(lVar9 + 0x18);

  *(undefined4 *)(param_1 + 0x2c) = 0;

  pfVar11 = (float *)(lVar9 + 0x48);

  do {

    uVar14 = *puVar15;

    fVar5 = pfVar11[6];

    fVar1 = *pfVar11;

    fVar2 = pfVar11[0xc];

    fVar3 = pfVar11[0x12];

    fVar4 = pfVar11[0x18];

    fVar6 = pfVar11[0x1e];

    if (uVar14 == 0) {

      psVar13 = (short *)0x0;

    }

    else if (DAT_140c3fe70 < uVar14) {

      psVar13 = (short *)0x0;

    }

    else {

      psVar13 = (short *)(DAT_140c3fe68 + uVar14);

    }

    if (((fVar1 != 0.0) && (psVar13 != (short *)0x0)) && (*psVar13 != 0)) {

      plVar10 = (longlong *)FUN_14018b280(0x148,0);

      if (plVar10 == (longlong *)0x0) {

        plVar10 = (longlong *)0x0;

      }

      else {

        *plVar10 = (longlong)&PTR_FUN_140b65aa0;

        FUN_140327110(plVar10 + 0xb);

        plVar10[0x28] = 0;

        plVar10[0x27] = 0;

        *(undefined4 *)(plVar10 + 1) = 1;

        plVar10[2] = 0;

        plVar10[3] = 0;

        plVar10[8] = 0;

        plVar10[9] = 0;

        plVar10[10] = 0;

      }

      iVar8 = FUN_140373470(plVar10,param_1,fVar5,fVar1,fVar2,fVar3,fVar4,fVar6,psVar13);

      if (iVar8 < 0) {

        if (plVar10 != (longlong *)0x0) {

          FUN_1403733c0(plVar10);

          FUN_14018b900(plVar10);

        }

      }

      else {

        uVar14 = (ulonglong)*(uint *)(param_1 + 0x2c);

        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) + 1;

        if (*(longlong **)(param_1 + 0x30 + uVar14 * 8) != plVar10) {

          if (plVar10 != (longlong *)0x0) {

            (**(code **)*plVar10)(plVar10);

          }

          plVar7 = *(longlong **)(param_1 + 0x30 + uVar14 * 8);

          if (plVar7 != (longlong *)0x0) {

            (**(code **)(*plVar7 + 8))();

          }

          *(longlong **)(param_1 + 0x30 + uVar14 * 8) = plVar10;

        }

        if (plVar10 != (longlong *)0x0) {

          (**(code **)(*plVar10 + 8))(plVar10);

        }

      }

    }

    pfVar11 = pfVar11 + 1;

    puVar15 = puVar15 + 1;

    lVar16 = lVar16 + -1;

  } while (lVar16 != 0);

  *(undefined8 *)(param_1 + 0x1c) = 0;

  return 0;

}



