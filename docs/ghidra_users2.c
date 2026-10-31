
==== FUN_140314d80 @ 140314d80 size 4284 ====
CALLERS:
CALLEES: FUN_140318540 FUN_14032da00 FUN_1403146b0 FUN_140313c20 FUN_14018b280 FUN_14032fe20 FUN_1401c3280 FUN_1401afc20 FUN_1401c9800 FUN_140317cf0 FUN_1403174a0 FUN_1401afb10 __security_check_cookie memcpy FUN_1408fde98 FUN_14018db00

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140314d80(longlong *param_1,undefined8 *param_2,float *param_3,float *param_4)

{
  undefined1 (*pauVar1) [16];
  undefined8 *puVar2;
  float *pfVar3;
  short sVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined8 uVar22;
  int iVar23;
  uint uVar24;
  longlong lVar25;
  undefined8 *puVar26;
  ulonglong uVar27;
  undefined1 (*pauVar28) [12];
  void *_Dst;
  longlong lVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  undefined2 uVar32;
  uint uVar33;
  float *pfVar34;
  undefined4 *puVar35;
  longlong lVar36;
  uint uVar37;
  uint uVar38;
  undefined4 uVar39;
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  float fVar45;
  float fVar46;
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auStack_428 [32];
  undefined1 (*local_408) [16];
  undefined8 *local_400;
  undefined1 *local_3f8;
  float *local_3f0;
  float *local_3e8;
  undefined1 local_3d8 [16];
  undefined8 local_3c8;
  float local_3b8 [4];
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  undefined8 local_388;
  undefined8 uStack_380;
  float local_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  undefined8 local_368;
  undefined8 uStack_360;
  float local_358;
  float fStack_354;
  float fStack_350;
  float fStack_34c;
  undefined4 local_348;
  undefined4 uStack_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  undefined4 local_328;
  undefined4 uStack_324;
  undefined4 uStack_320;
  undefined4 uStack_31c;
  undefined4 local_318;
  undefined4 uStack_314;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined1 local_308 [64];
  undefined4 *local_2c8 [2];
  undefined4 local_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined4 local_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 local_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined4 local_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined8 *local_278;
  float *local_270;
  undefined1 local_228 [32];
  float local_208;
  undefined4 local_148 [16];
  float local_108 [16];
  ulonglong local_c8;
  
  local_c8 = DAT_140c0f7b0 ^ (ulonglong)auStack_428;
  local_3a8 = *param_2;
  uStack_3a0 = param_2[1];
  local_398 = param_2[2];
  uStack_390 = param_2[3];
  uVar30 = 0;
  local_388 = param_2[4];
  uStack_380 = param_2[5];
  local_378 = *(float *)(param_2 + 6);
  fStack_374 = *(float *)((longlong)param_2 + 0x34);
  fStack_370 = *(float *)(param_2 + 7);
  fStack_36c = *(float *)((longlong)param_2 + 0x3c);
  local_3c8 = param_3;
  auVar42._0_4_ = fStack_374;
  if ((*(int *)(param_1[1] + 0x28) != 0) && (*(int *)(param_1[1] + 8) == 2)) {
    plVar5 = *(longlong **)(*(longlong *)(param_1[5] + 0x10) + 0x1e8);
    auVar42._0_4_ = 0.0;
    if (plVar5 != (longlong *)0x0) {
      local_408 = (undefined1 (*) [16])0x0;
      local_3b8[1] = fStack_374 + fRam0000000140c77874;
      local_3b8[0] = local_378 + _DAT_140c77870;
      local_3b8[3] = fStack_36c + fRam0000000140c7787c;
      local_3b8[2] = fStack_370 + fRam0000000140c77878;
      iVar23 = (**(code **)(*plVar5 + 0x1b8))(plVar5,local_3b8,local_228,1);
      if (iVar23 != 0) {
        auVar42._0_4_ = local_208;
      }
    }
  }
  fStack_374 = auVar42._0_4_;
  FUN_140313c20(param_1);
  FUN_14032fe20(param_1,&local_3a8,param_3,param_4);
  local_278 = &local_3a8;
  FUN_1401afc20(&local_278,local_308);
  auVar42._0_4_ = DAT_140b79ed0;
  uVar33 = *(uint *)(param_1[5] + 0x5b0);
  uVar38 = 100;
  if (uVar33 < 100) {
    uVar38 = uVar33;
  }
  if ((*(short *)(param_1[0x34] + 8) == 0xc) && (param_1[2] != *(longlong *)(param_1[5] + 0x4c0))) {
    puVar35 = &DAT_140af1508;
    *(undefined4 *)((longlong)param_1 + 0x3dc) = 0;
    fVar46 = 0.0;
    uVar27 = uVar30;
    do {
      uVar33 = (uint)uVar27;
      iVar23 = (**(code **)(**(longlong **)(param_1[5] + 0x4c0) + 0x350))
                         (*(longlong **)(param_1[5] + 0x4c0),*puVar35);
      if (iVar23 == 0) break;
      if (param_1[4] == 0) {
        lVar25 = FUN_14018b280(0x40);
        param_1[4] = lVar25;
      }
      puVar26 = (undefined8 *)
                (**(code **)(**(longlong **)(param_1[5] + 0x4c0) + 0x358))
                          (*(longlong **)(param_1[5] + 0x4c0),&local_368,*puVar35,0);
      uVar22 = puVar26[1];
      puVar2 = (undefined8 *)(param_1[4] + uVar27 * 0x10);
      *puVar2 = *puVar26;
      puVar2[1] = uVar22;
      if (uVar33 != 0) {
        pfVar34 = (float *)(param_1[4] + uVar27 * 0x10);
        pfVar3 = (float *)(param_1[4] + (ulonglong)(uVar33 - 1) * 0x10);
        fVar46 = fVar46 + SQRT((*pfVar34 - *pfVar3) * (*pfVar34 - *pfVar3) +
                               (pfVar34[1] - pfVar3[1]) * (pfVar34[1] - pfVar3[1]) +
                               (pfVar34[2] - pfVar3[2]) * (pfVar34[2] - pfVar3[2]));
      }
      uVar33 = uVar33 + 1;
      uVar27 = (ulonglong)uVar33;
      *(float *)((longlong)param_1 + -0x140af112c + (longlong)puVar35) = fVar46;
      puVar35 = puVar35 + 1;
    } while (uVar33 < 4);
    *(uint *)(param_1 + 3) = uVar33;
    if (uVar33 == 0) {
      return;
    }
    uVar27 = uVar30;
    uVar37 = 0;
    if (3 < (int)uVar33) {
      uVar24 = (uVar33 - 4 >> 2) + 1;
      uVar31 = (ulonglong)uVar24;
      fVar45 = auVar42._0_4_ / fVar46;
      uVar37 = uVar24 * 4;
      uVar27 = (ulonglong)uVar24 * 4;
      pfVar34 = (float *)(param_1 + 0x7c);
      do {
        pfVar34[-1] = fVar45 * pfVar34[-1];
        *pfVar34 = fVar45 * *pfVar34;
        pfVar34[1] = fVar45 * pfVar34[1];
        pfVar34[2] = fVar45 * pfVar34[2];
        uVar31 = uVar31 - 1;
        pfVar34 = pfVar34 + 4;
      } while (uVar31 != 0);
    }
    if (uVar37 < uVar33) {
      uVar31 = (ulonglong)(uVar33 - uVar37);
      pfVar34 = (float *)((longlong)param_1 + (uVar27 + 0xf7) * 4);
      do {
        *pfVar34 = (auVar42._0_4_ / fVar46) * *pfVar34;
        uVar31 = uVar31 - 1;
        pfVar34 = pfVar34 + 1;
      } while (uVar31 != 0);
    }
    param_1[2] = *(longlong *)(param_1[5] + 0x4c0);
    param_3 = local_3c8;
  }
  fVar46 = *(float *)(param_1 + 0x5a);
  fVar45 = *(float *)((longlong)param_1 + 0x2d4);
  fVar9 = *(float *)(param_1 + 0x5b);
  fVar10 = param_4[5];
  fVar11 = param_4[6];
  fVar12 = param_4[7];
  fVar13 = param_4[1];
  fVar14 = param_4[2];
  fVar15 = param_4[3];
  fVar16 = param_4[9];
  fVar17 = param_4[10];
  fVar18 = param_4[0xb];
  *(float *)(param_1 + 0x76) = fVar45 * param_4[4] + fVar46 * *param_4 + fVar9 * param_4[8];
  *(float *)((longlong)param_1 + 0x3b4) = fVar45 * fVar10 + fVar46 * fVar13 + fVar9 * fVar16;
  *(float *)(param_1 + 0x77) = fVar45 * fVar11 + fVar46 * fVar14 + fVar9 * fVar17;
  *(float *)((longlong)param_1 + 0x3bc) = fVar45 * fVar12 + fVar46 * fVar15 + fVar9 * fVar18;
  if ((*(byte *)(param_1[0x34] + 0xec8) & 2) == 0) {
    *(float *)(param_1 + 0x78) = local_378;
    *(float *)((longlong)param_1 + 0x3c4) = fStack_374;
    *(float *)(param_1 + 0x79) = fStack_370;
    *(float *)((longlong)param_1 + 0x3cc) = fStack_36c;
  }
  else {
    fVar46 = *(float *)(param_1 + 0x6e);
    fVar45 = *(float *)((longlong)param_1 + 0x374);
    fVar9 = *(float *)(param_1 + 0x6f);
    *(float *)(param_1 + 0x78) =
         fVar45 * (float)local_398 + fVar46 * (float)local_3a8 + fVar9 * (float)local_388 +
         local_378;
    *(float *)((longlong)param_1 + 0x3c4) =
         fVar45 * local_398._4_4_ + fVar46 * local_3a8._4_4_ + fVar9 * local_388._4_4_ + fStack_374;
    *(float *)(param_1 + 0x79) =
         fVar45 * (float)uStack_390 + fVar46 * (float)uStack_3a0 + fVar9 * (float)uStack_380 +
         fStack_370;
    *(float *)((longlong)param_1 + 0x3cc) =
         fVar45 * uStack_390._4_4_ + fVar46 * uStack_3a0._4_4_ + fVar9 * uStack_380._4_4_ +
         fStack_36c;
  }
  uVar27 = uVar30;
  if (*(int *)(*(longlong *)(param_1[5] + 0x40) + 0x308) != 0) {
    do {
      lVar25 = param_1[5];
      lVar36 = *(longlong *)(*(longlong *)(lVar25 + 0x40) + 0x310);
      sVar4 = *(short *)(lVar36 + 2 + uVar27 * 0x50);
      if (sVar4 == 0) {
        pfVar34 = (float *)((ulonglong)*(ushort *)(lVar36 + uVar27 * 0x50) * 0x40 + 0x30 +
                           *(longlong *)(lVar25 + 0x338));
        fVar46 = *pfVar34;
        fVar45 = pfVar34[1];
        fVar9 = pfVar34[2];
        fVar10 = param_3[5];
        fVar11 = param_3[6];
        fVar12 = param_3[7];
        fVar13 = param_3[1];
        fVar14 = param_3[2];
        fVar15 = param_3[3];
        fVar16 = param_3[9];
        fVar17 = param_3[10];
        fVar18 = param_3[0xb];
        fVar19 = param_3[0xd];
        fVar20 = param_3[0xe];
        fVar21 = param_3[0xf];
        local_108[uVar27 * 4] =
             fVar45 * param_3[4] + fVar46 * *param_3 + fVar9 * param_3[8] + param_3[0xc];
        local_108[uVar27 * 4 + 1] = fVar45 * fVar10 + fVar46 * fVar13 + fVar9 * fVar16 + fVar19;
        local_108[uVar27 * 4 + 2] = fVar45 * fVar11 + fVar46 * fVar14 + fVar9 * fVar17 + fVar20;
        local_108[uVar27 * 4 + 3] = fVar45 * fVar12 + fVar46 * fVar15 + fVar9 * fVar18 + fVar21;
      }
      else if (sVar4 == 1) {
        local_278 = (undefined8 *)
                    ((ulonglong)*(ushort *)(lVar36 + uVar27 * 0x50) * 0x40 +
                    *(longlong *)(lVar25 + 0x338));
        local_3d8._8_8_ = param_3;
        local_3d8._0_8_ = local_278;
        uVar31 = uVar27;
        local_270 = param_3;
        FUN_1401afb10(&local_278,&local_348);
        local_2c8[0] = &local_348;
        FUN_1401afc20(local_2c8,&local_2b8);
        local_348 = local_2b8;
        uStack_344 = local_2a8;
        uStack_340 = local_298;
        uStack_33c = local_288;
        local_148[uVar27 * 4] = uStack_2b4;
        local_148[uVar27 * 4 + 1] = uStack_2a4;
        local_148[uVar27 * 4 + 2] = uStack_294;
        local_148[uVar27 * 4 + 3] = uStack_284;
        local_328 = uStack_2b0;
        uStack_324 = uStack_2a0;
        uStack_320 = uStack_290;
        uStack_31c = uStack_280;
        local_318 = uStack_2ac;
        uStack_314 = uStack_29c;
        uStack_310 = uStack_28c;
        uStack_30c = uStack_27c;
        uVar27 = uVar31;
      }
      uVar33 = (int)uVar27 + 1;
      uVar27 = (ulonglong)uVar33;
    } while (uVar33 < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x308));
  }
  lVar25 = param_1[5];
  local_3d8._0_4_ = 0.0 - *(float *)(lVar25 + 0xb0);
  local_3d8._4_4_ = 0.0 - *(float *)(lVar25 + 0xb4);
  local_3d8._8_4_ = 0.0 - *(float *)(lVar25 + 0xb8);
  local_3d8._12_4_ = 0.0 - *(float *)(lVar25 + 0xbc);
  if ((*(char *)param_1[0x34] != '\x02') || (lVar25 = param_1[0x8d], lVar25 == 0))
  goto LAB_1403154c6;
  lVar36 = lVar25 * 0x1c;
  do {
    lVar6 = param_1[0x8c];
    lVar29 = lVar36 + -0x1c;
    *(float *)(lVar29 + lVar6) = (float)local_3d8._0_4_ + *(float *)(lVar29 + lVar6);
    *(float *)(lVar36 + -0x18 + lVar6) = (float)local_3d8._4_4_ + *(float *)(lVar36 + -0x18 + lVar6)
    ;
    *(float *)(lVar36 + -0x14 + lVar6) = (float)local_3d8._8_4_ + *(float *)(lVar36 + -0x14 + lVar6)
    ;
    lVar25 = lVar25 + -1;
    lVar36 = lVar29;
  } while (lVar25 != 0);
  uVar33 = *(uint *)((longlong)param_1 + 0x584);
  uVar37 = *(uint *)(*(longlong *)(param_1[5] + 0x10) + 0xd0);
  if (uVar37 < uVar33) {
    fVar46 = (float)(uVar37 - (int)param_1[0xb0]);
    auVar44._0_4_ = fVar46 * (*(float *)(param_1 + 0xae) - *(float *)(param_1 + 0xac));
    auVar44._4_4_ =
         fVar46 * (*(float *)((longlong)param_1 + 0x574) - *(float *)((longlong)param_1 + 0x564));
    auVar44._8_4_ = fVar46 * (*(float *)(param_1 + 0xaf) - *(float *)(param_1 + 0xad));
    auVar44._12_4_ =
         fVar46 * (*(float *)((longlong)param_1 + 0x57c) - *(float *)((longlong)param_1 + 0x56c));
    auVar49._0_4_ = (float)(uVar33 - (int)param_1[0xb0]);
    auVar49._4_4_ = auVar49._0_4_;
    auVar49._8_4_ = auVar49._0_4_;
    auVar49._12_4_ = auVar49._0_4_;
    auVar49 = divps(auVar44,auVar49);
    *(float *)(param_1 + 0xaa) = auVar49._0_4_ + *(float *)(param_1 + 0xac);
    *(float *)((longlong)param_1 + 0x554) = auVar49._4_4_ + *(float *)((longlong)param_1 + 0x564);
    *(float *)(param_1 + 0xab) = auVar49._8_4_ + *(float *)(param_1 + 0xad);
    *(float *)((longlong)param_1 + 0x55c) = auVar49._12_4_ + *(float *)((longlong)param_1 + 0x56c);
    goto LAB_1403154c6;
  }
  plVar5 = (longlong *)param_1[7];
  lVar25 = param_1[0x34];
  *(uint *)(param_1 + 0xb0) = uVar33;
  if ((int)param_1[0xb1] == 0) {
    iVar23 = (**(code **)(*plVar5 + 0x40))
                       (plVar5,*(undefined4 *)(lVar25 + 0xeac),*(undefined4 *)(lVar25 + 0xeb0));
    pauVar1 = (undefined1 (*) [16])(param_1 + 0xae);
    local_3b8[0] = 0.0;
    local_3b8[1] = 0.0;
    local_3b8[2] = 0.0;
    local_3b8[3] = 0.0;
    *(int *)((longlong)param_1 + 0x584) = iVar23 + *(int *)(*(longlong *)(param_1[5] + 0x10) + 0xd0)
    ;
    local_3e8 = local_3b8;
    param_1[0xac] = *(longlong *)*pauVar1;
    param_1[0xad] = param_1[0xaf];
    local_3f8 = local_308;
    local_400 = &local_3a8;
    local_408 = pauVar1;
    local_3f0 = param_3;
    iVar23 = FUN_14032da00(param_1,0,1,&local_368);
    if (iVar23 == 0) {
      auVar49 = *(undefined1 (*) [16])(param_1 + 0xac);
      *pauVar1 = auVar49;
      goto LAB_14031545f;
    }
    fVar46 = (float)(uint)(*(int *)(*(longlong *)(param_1[5] + 0x10) + 0xd0) - (int)param_1[0xb0]);
    auVar43._0_4_ = fVar46 * (*(float *)*pauVar1 - *(float *)(param_1 + 0xac));
    auVar43._4_4_ =
         fVar46 * (*(float *)((longlong)param_1 + 0x574) - *(float *)((longlong)param_1 + 0x564));
    auVar43._8_4_ = fVar46 * (*(float *)(param_1 + 0xaf) - *(float *)(param_1 + 0xad));
    auVar43._12_4_ =
         fVar46 * (*(float *)((longlong)param_1 + 0x57c) - *(float *)((longlong)param_1 + 0x56c));
    auVar40._0_4_ = (float)(uint)(*(int *)((longlong)param_1 + 0x584) - (int)param_1[0xb0]);
    auVar40._4_4_ = auVar40._0_4_;
    auVar40._8_4_ = auVar40._0_4_;
    auVar40._12_4_ = auVar40._0_4_;
    auVar49 = divps(auVar43,auVar40);
    *(float *)(param_1 + 0xaa) = auVar49._0_4_ + *(float *)(param_1 + 0xac);
    *(float *)((longlong)param_1 + 0x554) = auVar49._4_4_ + *(float *)((longlong)param_1 + 0x564);
    *(float *)(param_1 + 0xab) = auVar49._8_4_ + *(float *)(param_1 + 0xad);
    *(float *)((longlong)param_1 + 0x55c) = auVar49._12_4_ + *(float *)((longlong)param_1 + 0x56c);
  }
  else {
    iVar23 = (**(code **)(*plVar5 + 0x40))
                       (plVar5,*(undefined4 *)(lVar25 + 0xea4),*(undefined4 *)(lVar25 + 0xea8));
    *(int *)((longlong)param_1 + 0x584) = iVar23 + *(int *)(*(longlong *)(param_1[5] + 0x10) + 0xd0)
    ;
    auVar49 = *(undefined1 (*) [16])(param_1 + 0xae);
    *(undefined1 (*) [16])(param_1 + 0xac) = auVar49;
LAB_14031545f:
    *(undefined1 (*) [16])(param_1 + 0xaa) = auVar49;
  }
  *(uint *)(param_1 + 0xb1) = (uint)((int)param_1[0xb1] == 0);
LAB_1403154c6:
  fVar46 = DAT_140b7a034;
  if ((uVar38 != 0) && (lVar25 = param_1[0x8d], lVar25 != 0)) {
    lVar36 = lVar25 * 0x1c;
    do {
      lVar36 = lVar36 + -0x1c;
      lVar25 = lVar25 + -1;
      pfVar34 = (float *)(param_1[0x8c] + lVar36);
      if (0 < *(short *)(pfVar34 + 5)) {
        local_408 = (undefined1 (*) [16])local_148;
        FUN_1403174a0(param_1,pfVar34,uVar38,local_108);
      }
      if (*(char *)param_1[0x34] == '\x02') {
        fVar45 = *pfVar34;
        if (fVar45 < 0.0) {
          fVar45 = (float)FUN_1408fde98(fVar45 - fVar46);
          fVar45 = fVar45 + fVar46;
        }
        else {
          fVar45 = (float)FUN_1408fde98(fVar45 + fVar46);
          fVar45 = fVar45 - fVar46;
        }
        *pfVar34 = fVar45;
        fVar45 = pfVar34[1];
        if (fVar45 < 0.0) {
          fVar45 = (float)FUN_1408fde98(fVar45 - fVar46);
          fVar45 = fVar45 + fVar46;
        }
        else {
          fVar45 = (float)FUN_1408fde98(fVar45 + fVar46);
          fVar45 = fVar45 - fVar46;
        }
        pfVar34[1] = fVar45;
        fVar45 = pfVar34[2];
        if (fVar45 < 0.0) {
          fVar45 = (float)FUN_1408fde98(fVar45 - fVar46);
          fVar45 = fVar45 + fVar46;
        }
        else {
          fVar45 = (float)FUN_1408fde98(fVar45 + fVar46);
          fVar45 = fVar45 - fVar46;
        }
        pfVar34[2] = fVar45;
      }
      if (*(short *)(pfVar34 + 5) < 1) {
        if (lVar25 != param_1[0x8d] + -1) {
          lVar6 = param_1[0x8c];
          lVar29 = param_1[0x8d] * 0x1c;
          *(undefined4 *)(lVar6 + lVar36) = *(undefined4 *)(lVar29 + -0x1c + lVar6);
          *(undefined4 *)(lVar6 + 4 + lVar36) = *(undefined4 *)(lVar29 + -0x18 + lVar6);
          *(undefined4 *)(lVar6 + 8 + lVar36) = *(undefined4 *)(lVar29 + -0x14 + lVar6);
          *(undefined4 *)(lVar6 + 0xc + lVar36) = *(undefined4 *)(lVar29 + -0x10 + lVar6);
          *(undefined2 *)(lVar6 + 0x10 + lVar36) = *(undefined2 *)(lVar29 + -0xc + lVar6);
          *(undefined2 *)(lVar6 + 0x12 + lVar36) = *(undefined2 *)(lVar29 + -10 + lVar6);
          *(undefined2 *)(lVar6 + 0x14 + lVar36) = *(undefined2 *)(lVar29 + -8 + lVar6);
          *(undefined2 *)(lVar6 + 0x16 + lVar36) = *(undefined2 *)(lVar29 + -6 + lVar6);
          *(undefined2 *)(lVar6 + 0x18 + lVar36) = *(undefined2 *)(lVar29 + -4 + lVar6);
          *(undefined2 *)(lVar6 + 0x1a + lVar36) = *(undefined2 *)(lVar29 + -2 + lVar6);
        }
        FUN_140317cf0(param_1 + 0x8c,param_1[0x8d] + -1);
      }
    } while (lVar25 != 0);
  }
  iVar23 = (**(code **)(*param_1 + 0x48))(param_1);
  if ((iVar23 != 0) &&
     ((*(short *)(param_1[0x34] + 8) != 0xc ||
      (DAT_140b79e48 <
       *(float *)((ulonglong)
                  *(ushort *)
                   ((ulonglong)*(ushort *)param_1[1] * 0x160 + 6 +
                   *(longlong *)(*(longlong *)(param_1[5] + 0x40) + 0x188)) * 0x60 + 0x30 +
                 *(longlong *)(param_1[5] + 0x1f0)))))) {
    if (*(char *)((longlong)param_1 + 0x191) == '\0') {
      FUN_140318540(param_1[1] + 0x50,param_1 + 10,param_1 + 0x31);
      *(undefined1 *)((longlong)param_1 + 0x191) = 1;
    }
    lVar25 = param_1[10];
    for (puVar2 = (undefined8 *)param_1[0x31]; puVar2 != (undefined8 *)0x0;
        puVar2 = (undefined8 *)puVar2[2]) {
      (**(code **)*puVar2)(puVar2,param_1[6]);
    }
    if ((int)param_1[10] != 0) {
      FUN_1403146b0(param_1);
      for (puVar2 = (undefined8 *)param_1[0x85]; puVar2 != (undefined8 *)0x0;
          puVar2 = (undefined8 *)puVar2[2]) {
        (**(code **)*puVar2)(puVar2,param_1[6]);
      }
      if ((int)lVar25 == 0) {
        fVar46 = *(float *)(param_1 + 0x84);
        if (*(float *)(param_1 + 0x84) <= auVar42._0_4_) {
          fVar46 = auVar42._0_4_;
        }
        *(float *)(param_1 + 0x84) = fVar46;
      }
      iVar23 = (**(code **)(*(longlong *)param_1[7] + 0x40))
                         ((longlong *)param_1[7],(int)param_1[0x40],(int)param_1[0x42]);
      if (iVar23 < 1) {
        uVar33 = 1;
      }
      else {
        uVar33 = (**(code **)(*(longlong *)param_1[7] + 0x40))
                           ((longlong *)param_1[7],(int)param_1[0x40],(int)param_1[0x42]);
      }
      plVar5 = (longlong *)param_1[5];
      uVar38 = *(uint *)(plVar5 + 0xb6);
      if (100 < uVar38) {
        uVar38 = 100;
      }
      uVar37 = DAT_140c42500;
      if ((int)*DAT_140c63750 < (int)DAT_140c42500) {
        uVar37 = *DAT_140c63750;
      }
      uVar27 = (ulonglong)(int)uVar37;
      auVar47 = ZEXT416((uint)((float)uVar38 / (float)uVar33));
      if (((&DAT_140c42510)[uVar27] != '\0') &&
         (uVar27 = (**(code **)(*plVar5 + 0xf8))(plVar5), DAT_140b79cc4 < *(float *)(uVar27 + 8))) {
        lVar25 = (**(code **)(*(longlong *)param_1[5] + 0xf8))();
        auVar42._0_4_ = *(float *)((longlong)param_1 + 0x394) / *(float *)(lVar25 + 8);
        uVar37 = *DAT_140c63750;
        uVar24 = DAT_140c42540;
        if ((int)uVar37 < (int)DAT_140c42540) {
          uVar24 = uVar37;
        }
        uVar27 = (ulonglong)uVar24;
        if (*(float *)(&DAT_140c42550 + (longlong)(int)uVar24 * 4) <= auVar42._0_4_) {
          uVar24 = DAT_140c425a0;
          if ((int)uVar37 < (int)DAT_140c425a0) {
            uVar24 = uVar37;
          }
          uVar27 = (ulonglong)(int)uVar24;
          if (auVar42._0_4_ < *(float *)(&DAT_140c425b0 + uVar27 * 4)) {
            uVar24 = DAT_140c42540;
            if ((int)uVar37 < (int)DAT_140c42540) {
              uVar24 = uVar37;
            }
            uVar27 = (ulonglong)(int)uVar24;
            auVar47 = ZEXT416((uint)(((float)uVar38 / (float)uVar33) *
                                    (auVar42._0_4_ - *(float *)(&DAT_140c42550 + uVar27 * 4)) *
                                    _DAT_140c79e08));
          }
        }
        else {
          auVar47 = ZEXT816(0);
        }
      }
      uVar33 = (uint)uVar27;
      if (*(char *)((longlong)param_1 + 0x426) == '\0') {
        uVar33 = DAT_140c42600;
        if ((int)*DAT_140c63750 < (int)DAT_140c42600) {
          uVar33 = *DAT_140c63750;
        }
        auVar47._0_4_ = auVar47._0_4_ * *(float *)(&DAT_140c42610 + (longlong)(int)uVar33 * 4);
      }
      auVar42._0_4_ = auVar47._0_4_ + *(float *)(param_1 + 0x84);
      iVar23 = (int)auVar42._0_4_;
      *(float *)(param_1 + 0x84) = auVar42._0_4_;
      if ((iVar23 != -0x80000000) && ((float)iVar23 != auVar42._0_4_)) {
        auVar42._4_4_ = auVar42._0_4_;
        auVar42._8_8_ = 0;
        uVar33 = movmskps(uVar33,auVar42);
        auVar42._0_4_ = (float)(int)(iVar23 - (uVar33 & 1));
      }
      iVar23 = (**(code **)(*(longlong *)param_1[7] + 0x40))
                         ((longlong *)param_1[7],(int)param_1[0x3c],(int)param_1[0x3e]);
      uVar38 = iVar23 * (int)(longlong)auVar42._0_4_;
      uVar33 = *(uint *)(param_1 + 0x4c);
      if (0x400 < *(uint *)(param_1 + 0x4c)) {
        uVar33 = 0x400;
      }
      *(float *)(param_1 + 0x84) = *(float *)(param_1 + 0x84) - auVar42._0_4_;
      if (((ulonglong)uVar33 < (ulonglong)uVar38 + param_1[0x8d]) &&
         (uVar38 = 0, *(uint *)(param_1 + 0x8d) < uVar33)) {
        uVar38 = uVar33 - *(uint *)(param_1 + 0x8d);
      }
      if ((*(byte *)(param_1[0x34] + 10) & 1) != 0) {
        sVar4 = *(short *)(param_1[0x34] + 8);
        if (sVar4 == 1) {
          uVar39 = (**(code **)(*(longlong *)param_1[7] + 0x38))
                             ((longlong *)param_1[7],(float *)param_1[0x36],
                              *(float *)param_1[0x36] / (float)uVar38);
          *(undefined4 *)((longlong)param_1 + 0x3d4) = uVar39;
        }
        else if (sVar4 == 5) {
          uVar39 = (**(code **)(*(longlong *)param_1[7] + 0x38))
                             ((longlong *)param_1[7],param_1[0x36],*(undefined4 *)param_1[0x37]);
          *(undefined4 *)((longlong)param_1 + 0x3d4) = uVar39;
          uVar39 = (**(code **)(*(longlong *)param_1[7] + 0x38))
                             ((longlong *)param_1[7],(float *)param_1[0x38],
                              (*(float *)param_1[0x39] - *(float *)param_1[0x38]) / (float)uVar38);
          *(undefined4 *)(param_1 + 0x7b) = uVar39;
        }
      }
      pfVar34 = local_3c8;
      fVar46 = DAT_140b7a124;
      auVar42._0_4_ = DAT_140b7a0e8;
      auVar41._0_4_ = (float)uVar38;
      auVar48._0_4_ = *(float *)(param_1 + 0x74) - local_378;
      auVar48._4_4_ = *(float *)((longlong)param_1 + 0x3a4) - fStack_374;
      auVar48._8_4_ = *(float *)(param_1 + 0x75) - fStack_370;
      auVar48._12_4_ = *(float *)((longlong)param_1 + 0x3ac) - fStack_36c;
      auVar41._4_4_ = auVar41._0_4_;
      auVar41._8_4_ = auVar41._0_4_;
      auVar41._12_4_ = auVar41._0_4_;
      auVar49 = divps(auVar48,auVar41);
      if (uVar38 != 0) {
        do {
          if ((int)param_1[0x72] == 0) {
            local_368 = 0;
            uStack_360 = 0;
            local_3e8 = (float *)&local_368;
          }
          else {
            fStack_34c = (float)((uVar38 - (int)uVar30) - 1);
            local_3e8 = &local_358;
            local_358 = fStack_34c * auVar49._0_4_;
            fStack_354 = fStack_34c * auVar49._4_4_;
            fStack_350 = fStack_34c * auVar49._8_4_;
            fStack_34c = fStack_34c * auVar49._12_4_;
          }
          local_3f0 = pfVar34;
          local_3f8 = local_308;
          local_400 = &local_3a8;
          local_408 = (undefined1 (*) [16])local_3b8;
          iVar23 = FUN_14032da00(param_1,uVar30,uVar38,local_3d8);
          if (iVar23 != 0) {
            iVar23 = (**(code **)(*(longlong *)param_1[7] + 0x40))
                               ((longlong *)param_1[7],(int)param_1[0x48],(int)param_1[0x4a]);
            lVar25 = *(longlong *)param_1[7];
            fVar45 = (float)(**(code **)(lVar25 + 0x38))
                                      ((longlong *)param_1[7],lVar25,(int)param_1[0x6c]);
            lVar25 = param_1[0x8d];
            plVar5 = param_1 + 0x8c;
            FUN_140317cf0(plVar5,lVar25 + 1);
            lVar25 = lVar25 * 0x1c;
            *(undefined2 *)(lVar25 + 0x1a + *plVar5) = *(undefined2 *)((longlong)param_1 + 0x424);
            lVar36 = *plVar5;
            *(undefined4 *)(lVar25 + lVar36) = local_3d8._0_4_;
            *(undefined4 *)(lVar25 + 4 + lVar36) = local_3d8._4_4_;
            *(undefined4 *)(lVar25 + 8 + lVar36) = local_3d8._8_4_;
            FUN_1401c9800(&local_3c8,local_3b8);
            lVar36 = *plVar5;
            if (auVar42._0_4_ <= fVar45) {
              fVar45 = auVar42._0_4_;
            }
            *(undefined4 *)(lVar25 + 0xc + lVar36) = (undefined4)local_3c8;
            *(undefined2 *)(lVar25 + 0x10 + lVar36) = local_3c8._4_2_;
            uVar32 = (undefined2)iVar23;
            if (0x7fff < iVar23) {
              uVar32 = 0x7fff;
            }
            *(undefined2 *)(lVar25 + 0x16 + *plVar5) = uVar32;
            *(undefined2 *)(lVar25 + 0x14 + *plVar5) = uVar32;
            *(short *)(lVar25 + 0x18 + *plVar5) = (short)(int)(fVar45 * fVar46);
            *(short *)((longlong)param_1 + 0x424) = *(short *)((longlong)param_1 + 0x424) + 1;
            if (((int)param_1[0x2f] != -1) &&
               (iVar23 = (int)param_1[0x2f] + -1, *(int *)(param_1 + 0x2f) = iVar23, iVar23 == 0))
            break;
          }
          uVar33 = (int)uVar30 + 1;
          uVar30 = (ulonglong)uVar33;
        } while (uVar33 < uVar38);
      }
    }
  }
  lVar25 = lRam0000000140c798c8;
  uVar27 = 0;
  param_1[0x1a] = _DAT_140c798c0;
  param_1[0x1b] = lVar25;
  lVar25 = lRam0000000140c798d8;
  param_1[0x1c] = _DAT_140c798d0;
  param_1[0x1d] = lVar25;
  uVar30 = uVar27;
  if (param_1[0x8d] != 0) {
    do {
      uVar31 = (ulonglong)((int)uVar30 + 1);
      pauVar28 = (undefined1 (*) [12])(uVar30 * 0x1c + param_1[0x8c]);
      auVar7._12_4_ = 0;
      auVar7._0_12_ = *pauVar28;
      auVar42 = minps(*(undefined1 (*) [16])(param_1 + 0x1a),auVar7);
      auVar8._12_4_ = 0;
      auVar8._0_12_ = *pauVar28;
      auVar49 = maxps(*(undefined1 (*) [16])(param_1 + 0x1c),auVar8);
      *(undefined1 (*) [16])(param_1 + 0x1a) = auVar42;
      *(undefined1 (*) [16])(param_1 + 0x1c) = auVar49;
      uVar30 = uVar31;
    } while (uVar31 < (ulonglong)param_1[0x8d]);
    auVar42._0_4_ = *(float *)((longlong)param_1 + 0x394);
    *(float *)(param_1 + 0x1a) = *(float *)(param_1 + 0x1a) - auVar42._0_4_;
    *(float *)((longlong)param_1 + 0xd4) = *(float *)((longlong)param_1 + 0xd4) - auVar42._0_4_;
    *(float *)(param_1 + 0x1b) = *(float *)(param_1 + 0x1b) - auVar42._0_4_;
    *(float *)((longlong)param_1 + 0xdc) = *(float *)((longlong)param_1 + 0xdc) - auVar42._0_4_;
    *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) + auVar42._0_4_;
    *(float *)((longlong)param_1 + 0xe4) = *(float *)((longlong)param_1 + 0xe4) + auVar42._0_4_;
    *(float *)(param_1 + 0x1d) = *(float *)(param_1 + 0x1d) + auVar42._0_4_;
    *(float *)((longlong)param_1 + 0xec) = *(float *)((longlong)param_1 + 0xec) + auVar42._0_4_;
  }
  *(undefined4 *)(param_1 + 0x72) = 1;
  *(float *)(param_1 + 0x74) = local_378;
  *(float *)((longlong)param_1 + 0x3a4) = fStack_374;
  *(float *)(param_1 + 0x75) = fStack_370;
  *(float *)((longlong)param_1 + 0x3ac) = fStack_36c;
  if ((int)param_1[0x86] != 0) {
    uVar30 = param_1[0x8d];
    if ((ulonglong)param_1[0x8f] <= uVar30) {
      _Dst = (void *)FUN_14018db00(param_1[0x8e],uVar30,4);
      if ((void *)param_1[0x8e] != _Dst) {
        memcpy(_Dst,(void *)param_1[0x8e],param_1[0x8f] << 2);
        lVar25 = param_1[0x8e];
        if (lVar25 != 0) {
          (**(code **)(*(longlong *)(lVar25 + -0x10) + 8))(lVar25 + -0x10);
        }
        param_1[0x8e] = (longlong)_Dst;
      }
    }
    param_1[0x8f] = uVar30;
    if (param_1[0x8d] != 0) {
      do {
        *(int *)(param_1[0x8e] + uVar27 * 4) = (int)uVar27;
        uVar27 = uVar27 + 1;
      } while (uVar27 < (ulonglong)param_1[0x8d]);
    }
    FUN_1401c3280(&LAB_140313390,param_1[0x8e],param_1[0x8f],param_1[0x8c]);
  }
  return;
}



==== FUN_14031d490 @ 14031d490 size 2561 ====
CALLERS:
CALLEES: FUN_14032f6f0 FUN_1402626b0 FUN_14031e520 FUN_14018b280 FUN_14031e170 FUN_14032f8b0 FUN_140052360

undefined8 FUN_14031d490(longlong param_1,undefined8 param_2,longlong param_3)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  undefined2 uVar6;
  char *pcVar7;
  longlong lVar8;
  undefined1 auVar9 [16];
  undefined4 uVar10;
  undefined4 uVar11;
  float fVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  uint uVar18;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  ulonglong uVar22;
  uint uVar23;
  longlong lVar24;
  longlong lVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined8 in_stack_ffffffffffffff78;
  longlong *plVar30;
  longlong local_68 [10];
  
  *(undefined8 *)(param_1 + 0x4e8) = *(undefined8 *)(param_3 + 0x98);
  uVar15 = FUN_14032f6f0();
  if ((int)uVar15 < 0) {
    return uVar15;
  }
  uVar17 = 0;
  uVar20 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0xd0);
  *(undefined4 *)(param_1 + 0x544) = 0;
  *(undefined4 *)(param_1 + 0x580) = uVar20;
  *(undefined4 *)(param_1 + 0x538) = uVar20;
  iVar19 = *(int *)(*(longlong *)(param_1 + 8) + 0x1c);
  uVar20 = 4;
  uVar23 = 1;
  uVar22 = 1;
  if (iVar19 == 0) {
    *(undefined4 *)(param_1 + 0x54c) = 1;
    *(undefined8 *)(param_1 + 0x554) = 5;
  }
  else {
    if (iVar19 == 1) {
      *(undefined4 *)(param_1 + 0x54c) = 0;
      *(undefined8 *)(param_1 + 0x550) = 8;
      *(undefined4 *)(param_1 + 0x558) = 0;
      goto LAB_14031d571;
    }
    if (iVar19 != 2) {
      if (iVar19 == 3) {
        *(undefined4 *)(param_1 + 0x54c) = 0;
        *(undefined4 *)(param_1 + 0x550) = 8;
        *(undefined8 *)(param_1 + 0x554) = 2;
      }
      goto LAB_14031d571;
    }
    *(undefined4 *)(param_1 + 0x54c) = 0;
    *(undefined8 *)(param_1 + 0x554) = 1;
  }
  *(undefined4 *)(param_1 + 0x550) = 4;
LAB_14031d571:
  pcVar7 = *(char **)(param_1 + 0x4e8);
  bVar4 = pcVar7[4];
  if (bVar4 == 0) {
    *(undefined4 *)(param_1 + 0x55c) = 1;
  }
  else if (bVar4 < 3) {
    uVar21 = *(uint *)(pcVar7 + 8);
    *(uint *)(param_1 + 0x55c) = uVar21;
    if (uVar21 < 2) {
      return 0x80070057;
    }
  }
  else if (bVar4 == 4) {
    *(undefined4 *)(param_1 + 0x55c) = 4;
  }
  else {
    *(uint *)(param_1 + 0x55c) = (uint)*(ushort *)(pcVar7 + 0x24);
  }
  fVar12 = DAT_140b79ed0;
  fVar27 = DAT_140b7a1c8;
  if (*(int *)(param_1 + 0x55c) != 1) {
    fVar27 = DAT_140b79ed0 / (float)(*(int *)(param_1 + 0x55c) - 1);
  }
  *(float *)(param_1 + 0x600) = fVar27;
  if (*pcVar7 == '\0') {
    uVar21 = ((int)((int)((ulonglong)(*(ushort *)(pcVar7 + 2) + 999) /
                         (ulonglong)(longlong)(int)(uint)*(ushort *)(pcVar7 + 2)) *
                   (uint)*(ushort *)(pcVar7 + 0x26)) / 1000) * 2 + 0x20;
  }
  else {
    if ((*(ushort *)(pcVar7 + 2) & 1) == 0) {
      *(ushort *)(pcVar7 + 2) = *(ushort *)(pcVar7 + 2) + 1;
    }
    uVar18 = *(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2) + 1;
    uVar21 = 2;
    if (2 < uVar18) {
      uVar21 = uVar18;
    }
  }
  *(uint *)(param_1 + 0x520) = uVar21;
  iVar19 = (*(int *)(param_1 + 0x55c) + 7) * 0x10;
  *(int *)(param_1 + 0x524) = iVar19;
  uVar15 = FUN_14018b280(iVar19 * uVar21,0);
  *(undefined8 *)(param_1 + 0x518) = uVar15;
  *(undefined8 *)(param_1 + 0x52c) = 0;
  *(undefined4 *)(param_1 + 0x528) = 0;
  uVar15 = FUN_14018b280(iVar19,0);
  *(undefined8 *)(param_1 + 0x588) = uVar15;
  uVar15 = FUN_14018b280(iVar19,0);
  *(undefined8 *)(param_1 + 0x590) = uVar15;
  lVar25 = *(longlong *)(param_1 + 0x588);
  uVar15 = *(undefined8 *)(param_1 + 0x1c8);
  *(undefined8 *)(lVar25 + 0x20) = *(undefined8 *)(param_1 + 0x1c0);
  *(undefined8 *)(lVar25 + 0x28) = uVar15;
  lVar25 = *(longlong *)(param_1 + 0x588);
  uVar15 = *(undefined8 *)(param_1 + 0x268);
  *(undefined8 *)(lVar25 + 0x30) = *(undefined8 *)(param_1 + 0x260);
  *(undefined8 *)(lVar25 + 0x38) = uVar15;
  *(undefined4 *)(*(longlong *)(param_1 + 0x588) + 4) = *(undefined4 *)(param_1 + 0x350);
  *(undefined4 *)(*(longlong *)(param_1 + 0x588) + 8) = *(undefined4 *)(param_1 + 0x3f0);
  *(uint *)(*(longlong *)(param_1 + 0x588) + 0x18) =
       (uint)*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 0x26);
  *(undefined4 *)(*(longlong *)(param_1 + 0x588) + 0x14) = *(undefined4 *)(param_1 + 0x538);
  lVar25 = *(longlong *)(param_1 + 0x590);
  uVar15 = *(undefined8 *)(param_1 + 0x248);
  *(undefined8 *)(lVar25 + 0x20) = *(undefined8 *)(param_1 + 0x240);
  *(undefined8 *)(lVar25 + 0x28) = uVar15;
  lVar25 = *(longlong *)(param_1 + 0x590);
  uVar3 = *(undefined4 *)(param_1 + 0x2e4);
  uVar10 = *(undefined4 *)(param_1 + 0x2e8);
  uVar11 = *(undefined4 *)(param_1 + 0x2ec);
  *(undefined4 *)(lVar25 + 0x30) = *(undefined4 *)(param_1 + 0x2e0);
  *(undefined4 *)(lVar25 + 0x34) = uVar3;
  *(undefined4 *)(lVar25 + 0x38) = uVar10;
  *(undefined4 *)(lVar25 + 0x3c) = uVar11;
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 4) = *(undefined4 *)(param_1 + 0x390);
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 8) = *(undefined4 *)(param_1 + 0x430);
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 0x18) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 0x14) = *(undefined4 *)(param_1 + 0x538);
  if (*(uint *)(param_1 + 0x55c) < 2) {
    fVar27 = 0.0;
  }
  else {
    fVar27 = (float)(*(int *)(*(longlong *)(param_1 + 0x4e8) + 8) - 3) /
             (float)(*(uint *)(param_1 + 0x55c) - 1);
  }
  *(float *)(param_1 + 0x548) = fVar27;
  if (*(char *)(*(longlong *)(param_1 + 0x4e8) + 4) != '\x04') {
    uVar20 = *(undefined4 *)(*(longlong *)(param_1 + 0x4e8) + 8);
  }
  FUN_1402626b0(param_1 + 0x620,uVar20);
  FUN_1402626b0(param_1 + 0x630,uVar20);
  FUN_1402626b0(param_1 + 0x640,uVar20);
  FUN_1402626b0(param_1 + 0x650,uVar20);
  FUN_1402626b0(param_1 + 0x660,uVar20);
  uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  *(undefined8 *)(param_1 + 0x6a0) = 0;
  if (**(char **)(param_1 + 0x4e8) == '\x01') {
    uVar16 = uVar17;
    if (*(short *)(*(char **)(param_1 + 0x4e8) + 2) != 0) {
      do {
        uVar21 = (int)uVar16 + 1;
        local_68[0] = 0;
        local_68[1] = 0;
        FUN_14031e520(param_1,param_1 + 0x630,local_68,
                      (ulonglong)(*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 0x26) * uVar21) /
                      (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2));
        uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
        iVar19 = *(int *)(param_1 + 0x52c);
        if (iVar19 == 0) {
          iVar19 = *(int *)(param_1 + 0x520);
        }
        *(int *)((ulonglong)(uint)((iVar19 + -1) * *(int *)(param_1 + 0x524)) + 0x14 +
                *(longlong *)(param_1 + 0x518)) = (*(int *)(param_1 + 0x538) - (int)uVar16) + -1;
        uVar16 = (ulonglong)uVar21;
      } while (uVar21 < *(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2));
    }
    *(uint *)(*(longlong *)(param_1 + 0x590) + 0x14) =
         (*(int *)(param_1 + 0x538) - (uint)*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2)) + -1;
    FUN_1402626b0(param_1 + 0x5d0,*(undefined4 *)(param_1 + 0x55c));
    FUN_1402626b0(param_1 + 0x5e0,*(undefined4 *)(param_1 + 0x55c));
  }
  cVar5 = *(char *)(*(longlong *)(param_1 + 0x4e8) + 4);
  if (cVar5 == '\x01') {
    plVar30 = (longlong *)(param_1 + 0x560);
    FUN_140052360(plVar30,*(undefined4 *)(param_1 + 0x55c));
    fVar27 = 0.0;
    *(undefined4 *)*plVar30 = 0;
    if (1 < *(uint *)(param_1 + 0x55c)) {
      lVar25 = *plVar30;
      do {
        uVar16 = (ulonglong)uVar23;
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x4e8) + 0x10);
        uVar17 = (ulonglong)(uVar23 - 1);
        uVar23 = uVar23 + 1;
        fVar26 = *(float *)(lVar8 + uVar17 * 0xc) - *(float *)(lVar8 + uVar16 * 0xc);
        fVar28 = *(float *)(lVar8 + 4 + uVar17 * 0xc) - *(float *)(lVar8 + 4 + uVar16 * 0xc);
        fVar29 = *(float *)(lVar8 + 8 + uVar17 * 0xc) - *(float *)(lVar8 + 8 + uVar16 * 0xc);
        *(float *)(lVar25 + uVar16 * 4) = SQRT(fVar26 * fVar26 + fVar28 * fVar28 + fVar29 * fVar29);
        lVar25 = *plVar30;
        fVar27 = fVar27 + *(float *)(lVar25 + uVar16 * 4);
      } while (uVar23 < *(uint *)(param_1 + 0x55c));
      if (1 < *(uint *)(param_1 + 0x55c)) {
        do {
          if (fVar27 == 0.0) {
            fVar26 = 0.0;
          }
          else {
            fVar26 = *(float *)(*plVar30 + uVar22 * 4) / fVar27 +
                     *(float *)(*plVar30 + (ulonglong)((int)uVar22 - 1) * 4);
          }
          uVar23 = (int)uVar22 + 1;
          *(float *)(*plVar30 + uVar22 * 4) = fVar26;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 < *(uint *)(param_1 + 0x55c));
      }
    }
  }
  else if (cVar5 == '\x02') {
    plVar30 = (longlong *)(param_1 + 0x560);
    FUN_140052360(plVar30,*(undefined4 *)(param_1 + 0x55c));
    fVar27 = 0.0;
    *(undefined4 *)*plVar30 = 0;
    if (1 < *(uint *)(param_1 + 0x55c)) {
      lVar25 = *plVar30;
      uVar17 = uVar22;
      do {
        fVar26 = 0.0;
        if ((uVar17 & 1) != 0) {
          lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x4e8) + 0x10);
          uVar16 = (ulonglong)((int)uVar17 - 1);
          fVar26 = *(float *)(lVar8 + uVar16 * 0xc) - *(float *)(lVar8 + uVar17 * 0xc);
          fVar28 = *(float *)(lVar8 + 4 + uVar16 * 0xc) - *(float *)(lVar8 + 4 + uVar17 * 0xc);
          fVar29 = *(float *)(lVar8 + 8 + uVar16 * 0xc) - *(float *)(lVar8 + 8 + uVar17 * 0xc);
          fVar26 = SQRT(fVar26 * fVar26 + fVar28 * fVar28 + fVar29 * fVar29);
        }
        uVar23 = (int)uVar17 + 1;
        *(float *)(lVar25 + uVar17 * 4) = fVar26;
        lVar25 = *plVar30;
        fVar27 = fVar27 + *(float *)(lVar25 + uVar17 * 4);
        uVar17 = (ulonglong)uVar23;
      } while (uVar23 < *(uint *)(param_1 + 0x55c));
      if (1 < *(uint *)(param_1 + 0x55c)) {
        do {
          if (fVar27 == 0.0) {
            fVar26 = 0.0;
          }
          else {
            fVar26 = *(float *)(*plVar30 + uVar22 * 4) / fVar27 +
                     *(float *)(*plVar30 + (ulonglong)((int)uVar22 - 1) * 4);
          }
          uVar23 = (int)uVar22 + 1;
          *(float *)(*plVar30 + uVar22 * 4) = fVar26;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 < *(uint *)(param_1 + 0x55c));
      }
    }
  }
  else if (cVar5 == '\x03') {
    local_68[1] = 0;
    local_68[0] = 0;
    FUN_1402626b0(local_68,*(undefined4 *)(*(longlong *)(param_1 + 0x4e8) + 8));
    lVar25 = local_68[0];
    if (*(int *)(*(longlong *)(param_1 + 0x4e8) + 8) != 0) {
      do {
        uVar23 = (int)uVar17 + 1;
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x4e8) + 0x10);
        auVar9._4_4_ = *(undefined4 *)(lVar8 + 4 + uVar17 * 0xc);
        auVar9._0_4_ = *(undefined4 *)(lVar8 + uVar17 * 0xc);
        auVar9._8_4_ = *(undefined4 *)(lVar8 + 8 + uVar17 * 0xc);
        auVar9._12_4_ = 0;
        *(undefined1 (*) [16])(local_68[0] + uVar17 * 0x10) = auVar9;
        uVar17 = (ulonglong)uVar23;
      } while (uVar23 < *(uint *)(*(longlong *)(param_1 + 0x4e8) + 8));
    }
    iVar19 = *(int *)(param_1 + 0x52c);
    uVar6 = *(undefined2 *)(*(longlong *)(param_1 + 0x4e8) + 0x26);
    local_68[2] = 0;
    local_68[3] = 0;
    iVar13 = iVar19;
    if (iVar19 == 0) {
      iVar13 = *(int *)(param_1 + 0x520);
    }
    iVar14 = iVar19 + 1;
    *(int *)(param_1 + 0x52c) = iVar14;
    if (iVar14 == *(int *)(param_1 + 0x520)) {
      iVar14 = 0;
    }
    *(int *)(param_1 + 0x52c) = iVar14;
    if (*(int *)(param_1 + 0x530) == *(int *)(param_1 + 0x520)) {
      *(undefined4 *)(param_1 + 0x528) = *(undefined4 *)(param_1 + 0x52c);
    }
    else {
      *(int *)(param_1 + 0x530) = *(int *)(param_1 + 0x530) + 1;
    }
    plVar30 = local_68 + 2;
    FUN_14031e170(param_1,(ulonglong)(uint)(*(int *)(param_1 + 0x524) * iVar19) +
                          *(longlong *)(param_1 + 0x518),
                  (ulonglong)(uint)((iVar13 + -1) * *(int *)(param_1 + 0x524)) +
                  *(longlong *)(param_1 + 0x518),local_68,plVar30,uVar6,1);
    uVar20 = (undefined4)((ulonglong)plVar30 >> 0x20);
    plVar30 = (longlong *)(param_1 + 0x560);
    FUN_140052360(plVar30,*(undefined4 *)(param_1 + 0x55c));
    fVar27 = 0.0;
    *(undefined4 *)*plVar30 = 0;
    lVar8 = *(longlong *)(param_1 + 0x518);
    if (1 < *(uint *)(param_1 + 0x55c)) {
      lVar24 = *plVar30;
      uVar17 = uVar22;
      do {
        uVar23 = (int)uVar17 + 1;
        pfVar1 = (float *)(lVar8 + ((ulonglong)((int)uVar17 - 1) + 7) * 0x10);
        pfVar2 = (float *)(lVar8 + (uVar17 + 7) * 0x10);
        *(float *)(lVar24 + uVar17 * 4) =
             SQRT((*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +
                  (pfVar1[1] - pfVar2[1]) * (pfVar1[1] - pfVar2[1]) +
                  (pfVar1[2] - pfVar2[2]) * (pfVar1[2] - pfVar2[2]));
        lVar24 = *plVar30;
        fVar27 = fVar27 + *(float *)(lVar24 + uVar17 * 4);
        uVar17 = (ulonglong)uVar23;
      } while (uVar23 < *(uint *)(param_1 + 0x55c));
      if (1 < *(uint *)(param_1 + 0x55c)) {
        do {
          if (fVar27 == 0.0) {
            fVar26 = 0.0;
          }
          else {
            fVar26 = *(float *)(*plVar30 + uVar22 * 4) / fVar27 +
                     *(float *)(*plVar30 + (ulonglong)((int)uVar22 - 1) * 4);
          }
          uVar23 = (int)uVar22 + 1;
          *(float *)(*plVar30 + uVar22 * 4) = fVar26;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 < *(uint *)(param_1 + 0x55c));
      }
    }
    *(undefined8 *)(param_1 + 0x52c) = 0;
    *(undefined4 *)(param_1 + 0x528) = 0;
    if (lVar25 != 0) {
      (**(code **)(*(longlong *)(lVar25 + -0x10) + 8))(lVar25 + -0x10);
    }
  }
  uVar23 = *(uint *)(*(longlong *)(param_1 + 0x4e8) + 0x28);
  uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x4e8) + 0x3c8);
  FUN_14032f8b0(uVar3,param_1 + 0x4f0,uVar23 & 0x80,uVar23 & 0x100,CONCAT44(uVar20,uVar3));
  lVar25 = *(longlong *)(param_1 + 0x4e8);
  uVar20 = 0x18;
  if (*(short *)(lVar25 + 0x404) != 0) {
    uVar20 = 0x24;
  }
  *(undefined4 *)(param_1 + 0x598) = uVar20;
  uVar20 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                     (*(longlong **)(param_1 + 0x38),*(undefined4 *)(lVar25 + 0x3e0),
                      *(undefined4 *)(lVar25 + 0x3e4));
  fVar26 = DAT_140b7a1c0;
  *(undefined4 *)(param_1 + 0x57c) = uVar20;
  fVar27 = *(float *)(*(longlong *)(param_1 + 0x4e8) + 0x3b4);
  fVar28 = fVar26;
  if (fVar27 != 0.0) {
    fVar28 = fVar12 / fVar27;
  }
  *(float *)(param_1 + 0x5f8) = fVar28;
  fVar27 = *(float *)(*(longlong *)(param_1 + 0x4e8) + 0x3b8);
  if (fVar27 != 0.0) {
    fVar26 = fVar12 / fVar27;
  }
  *(float *)(param_1 + 0x5fc) = fVar26;
  return 0;
}



==== FUN_140394a10 @ 140394a10 size 1422 ====
CALLERS:
CALLEES: FUN_1407c2c10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140394a10(longlong param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar11;
  float fVar12;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  float local_d0;
  undefined4 local_cc;
  float local_c8;
  undefined8 local_c4;
  undefined1 local_b8 [12];
  undefined4 local_ac;
  
  if (param_2 == 0) {
    return;
  }
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x128))(*(longlong **)(param_1 + 0x10),1);
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x140))(*(longlong **)(param_1 + 0x10),1);
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x70))(*(longlong **)(param_1 + 0x10),param_3);
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x80))(*(longlong **)(param_1 + 0x10),param_4);
  lVar5 = *(longlong *)(param_1 + 8);
  if (*(int *)(lVar5 + 0x68) == 0) {
    lVar5 = *(longlong *)(lVar5 + 0x20);
  }
  plVar1 = *(longlong **)(lVar5 + 0x150);
  if (plVar1 == (longlong *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_1407c2c10(plVar1,*(undefined8 *)(*plVar1 + *(longlong *)(lVar5 + 0x160) * 8));
  }
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x100))(*(longlong **)(param_1 + 0x10),uVar6);
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x150))
            (*(longlong **)(param_1 + 0x10),
             ~(*(uint *)(*(longlong *)(param_1 + 8) + 0x168) >> 8) & 1);
  if (((*(uint *)(param_1 + 0x18) & 2) == 0) && ((*(uint *)(param_1 + 0x18) & 4) == 0)) {
    return;
  }
  iVar4 = DAT_140c44400;
  if (*DAT_140c63750 < DAT_140c44400) {
    iVar4 = *DAT_140c63750;
  }
  if (((&DAT_140c44410)[iVar4] == '\0') ||
     ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x10) + 0x80) & 0x8000000) == 0)) {
    bVar3 = false;
  }
  else {
    bVar2 = true;
    iVar4 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x548))();
    bVar3 = true;
    if (iVar4 != 0) {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x10);
      (**(code **)(*plVar1 + 0x1c0))(plVar1,*(longlong *)(param_1 + 8) + 0xe0,&local_e8,3);
      lVar5 = *(longlong *)(param_1 + 8);
      fVar19 = SQRT((float)local_e8 * (float)local_e8 + local_e8._4_4_ * local_e8._4_4_ +
                    (float)uStack_e0 * (float)uStack_e0);
      fVar15 = local_e8._4_4_ * *(float *)(lVar5 + 0x100) +
               (float)local_e8 * *(float *)(lVar5 + 0xf0) +
               (float)uStack_e0 * *(float *)(lVar5 + 0x110);
      fVar16 = local_e8._4_4_ * *(float *)(lVar5 + 0x104) +
               (float)local_e8 * *(float *)(lVar5 + 0xf4) +
               (float)uStack_e0 * *(float *)(lVar5 + 0x114);
      fVar17 = local_e8._4_4_ * *(float *)(lVar5 + 0x108) +
               (float)local_e8 * *(float *)(lVar5 + 0xf8) +
               (float)uStack_e0 * *(float *)(lVar5 + 0x118);
      fVar18 = local_e8._4_4_ * *(float *)(lVar5 + 0x10c) +
               (float)local_e8 * *(float *)(lVar5 + 0xfc) +
               (float)uStack_e0 * *(float *)(lVar5 + 0x11c);
      fVar16 = fVar16 * fVar16;
      fVar13 = fVar17 * fVar17;
      fVar18 = fVar18 * fVar18;
      fVar14 = fVar15 * fVar15 + fVar16 + fVar13;
      auVar9._4_4_ = fVar16;
      auVar9._0_4_ = fVar14;
      auVar9._8_4_ = fVar13;
      auVar9._12_4_ = fVar18;
      auVar10._4_4_ = fVar16;
      auVar10._0_4_ = fVar14;
      auVar10._8_4_ = fVar13;
      auVar10._12_4_ = fVar18;
      auVar10 = rsqrtss(auVar9,auVar10);
      fVar13 = auVar10._0_4_;
      fVar13 = (DAT_140b79fa0 - fVar14 * fVar13 * fVar13) * DAT_140b79e48 * fVar13;
      if (fVar13 <= 0.0) {
        fVar13 = 0.0;
      }
      fVar16 = fVar13 * fVar15 * fVar19;
      fVar13 = fVar13 * fVar17 * fVar19;
      goto LAB_140394c7d;
    }
  }
  bVar2 = bVar3;
  fVar19 = 0.0;
  local_e8 = 0;
  uStack_e0 = 0;
  fVar16 = 0.0;
  fVar13 = 0.0;
LAB_140394c7d:
  fVar14 = DAT_140b79ed0;
  fVar18 = *(float *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x10) + 0x37c);
  if (DAT_140b79d80 <= fVar18) {
    fVar18 = DAT_140b79d80;
  }
  if ((*(byte *)(param_1 + 0x18) & 2) != 0) {
    fVar15 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x560))();
    fVar15 = fVar14 - fVar15;
    *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) * fVar15;
    *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * fVar15;
    *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) * fVar15;
    *(float *)(param_1 + 0x2c) = *(float *)(param_1 + 0x2c) * fVar15;
    fVar7 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x558))();
    fVar15 = *(float *)(param_1 + 0x30);
    fVar17 = *(float *)(param_1 + 0x34);
    fVar11 = *(float *)(param_1 + 0x38);
    fVar12 = *(float *)(param_1 + 0x3c);
    fVar8 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x550))();
    *(float *)(param_1 + 0x20) =
         *(float *)(param_1 + 0x20) + (fVar8 * fVar16 - fVar15 * fVar7) * fVar18;
    *(float *)(param_1 + 0x24) =
         *(float *)(param_1 + 0x24) + (fVar8 * fVar13 - fVar17 * fVar7) * fVar18;
    *(float *)(param_1 + 0x28) =
         *(float *)(param_1 + 0x28) + (fVar8 * fVar16 - fVar11 * fVar7) * fVar18;
    *(float *)(param_1 + 0x2c) =
         *(float *)(param_1 + 0x2c) + (fVar8 * fVar13 - fVar12 * fVar7) * fVar18;
    fVar15 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x560))();
    fVar13 = _UNK_140b7ac54;
    fVar16 = _DAT_140b7ac50;
    fVar15 = fVar14 - fVar15;
    fVar17 = *(float *)(param_1 + 0x30) * fVar15;
    fVar11 = *(float *)(param_1 + 0x34) * fVar15;
    fVar12 = *(float *)(param_1 + 0x38) * fVar15;
    fVar15 = *(float *)(param_1 + 0x3c) * fVar15;
    *(float *)(param_1 + 0x30) = fVar17;
    *(float *)(param_1 + 0x34) = fVar11;
    *(float *)(param_1 + 0x38) = fVar12;
    *(float *)(param_1 + 0x3c) = fVar15;
    fVar17 = fVar17 + *(float *)(param_1 + 0x20) * fVar18;
    fVar11 = fVar11 + *(float *)(param_1 + 0x24) * fVar18;
    *(float *)(param_1 + 0x30) = fVar17;
    *(float *)(param_1 + 0x34) = fVar11;
    *(float *)(param_1 + 0x38) = fVar12 + *(float *)(param_1 + 0x28) * fVar18;
    *(float *)(param_1 + 0x3c) = fVar15 + *(float *)(param_1 + 0x2c) * fVar18;
    fVar16 = fVar16 + fVar17 * _DAT_140c1e5dc * DAT_140b79e48;
    fVar13 = fVar13 + fVar11 * _DAT_140c1e5dc * DAT_140b79e48;
    if (fVar14 <= fVar16) {
      fVar16 = fVar14;
    }
    fVar15 = 0.0;
    if (0.0 <= fVar16) {
      fVar15 = fVar16;
    }
    lVar5 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x1c8))
                      (*(longlong **)(param_1 + 0x10),0xa9,0);
    local_d8 = 0xa9;
    local_d0 = 0.0;
    local_c8 = 1.0;
    local_c4 = 0x11;
    local_cc = (undefined4)(longlong)(fVar15 * (float)*(uint *)(lVar5 + 8));
    (**(code **)(**(longlong **)(param_1 + 0x10) + 600))(*(longlong **)(param_1 + 0x10),1,&local_d8)
    ;
    if (fVar14 <= fVar13) {
      fVar13 = fVar14;
    }
    fVar16 = 0.0;
    if (0.0 <= fVar13) {
      fVar16 = fVar13;
    }
    lVar5 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x1c8))
                      (*(longlong **)(param_1 + 0x10),0xaa,0);
    local_d8 = 0xaa;
    local_d0 = 0.0;
    local_c8 = 1.0;
    local_c4 = 0x11;
    local_cc = (undefined4)(longlong)(fVar16 * (float)*(uint *)(lVar5 + 8));
    (**(code **)(**(longlong **)(param_1 + 0x10) + 600))(*(longlong **)(param_1 + 0x10),2,&local_d8)
    ;
  }
  if ((bVar2) && ((*(byte *)(param_1 + 0x18) & 4) != 0)) {
    fVar16 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x560))();
    *(float *)(param_1 + 0x1c) = (fVar14 - fVar16) * *(float *)(param_1 + 0x1c);
    fVar16 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x568))();
    fVar16 = fVar16 * fVar19 * fVar18 + *(float *)(param_1 + 0x1c);
    *(float *)(param_1 + 0x1c) = fVar16;
    fVar16 = fVar16 * _DAT_140c1e5dc;
    if (fVar14 <= fVar16) {
      fVar16 = fVar14;
    }
    fVar13 = 0.0;
    if (0.0 <= fVar16) {
      fVar13 = fVar16;
    }
    (**(code **)(**(longlong **)(param_1 + 0x10) + 0x260))
              (*(longlong **)(param_1 + 0x10),3,local_b8);
    local_d0 = (float)(**(code **)(**(longlong **)(param_1 + 0x10) + 0x570))();
    local_d8 = 0xab;
    local_cc = local_ac;
    local_c4 = 0x13;
    local_d0 = local_d0 * fVar13;
    local_c8 = fVar13;
    (**(code **)(**(longlong **)(param_1 + 0x10) + 600))(*(longlong **)(param_1 + 0x10),3,&local_d8)
    ;
  }
  return;
}



==== FUN_1402f39e0 @ 1402f39e0 size 6894 ====
CALLERS: FUN_1402f5550
CALLEES: FUN_1400037c0 FUN_1402f2170 DebugBreak FUN_1402f1300 FUN_1402f9480 FUN_1402f96a0 FUN_14018b280 TlsGetValue FUN_1401971e0 FUN_1402f5e70 FUN_1402338a0 FUN_140312ff0 TlsSetValue FUN_14031ce90 FUN_1407e4830 FUN_140319e40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1402f39e0(longlong *param_1)

{
  char cVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 auVar4 [16];
  double dVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint *puVar17;
  longlong *plVar18;
  longlong *plVar19;
  undefined1 *puVar20;
  uint *puVar21;
  longlong lVar22;
  undefined8 *puVar23;
  longlong *plVar24;
  int iVar25;
  uint uVar26;
  longlong *plVar27;
  longlong *plVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  undefined8 local_res8;
  undefined4 local_res10;
  longlong *local_res18;
  undefined **local_1b8;
  undefined8 local_1b0;
  LPVOID local_1a8;
  undefined **local_1a0;
  wchar_t *local_198;
  LPVOID local_190;
  undefined8 local_188;
  undefined **local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  int iStack_168;
  undefined4 uStack_164;
  undefined **local_158;
  undefined8 local_150;
  LPVOID local_148;
  undefined **local_138;
  wchar_t *local_130;
  LPVOID local_128;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  int iStack_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  float local_88;
  float local_68;
  
  puVar20 = (undefined1 *)0x0;
  for (lVar11 = param_1[0x9a]; lVar11 != 0; lVar11 = *(longlong *)(lVar11 + 0x4e0)) {
    uVar26 = *(uint *)(lVar11 + 0x4b0);
    puVar15 = puVar20;
    if ((uVar26 != 0) && (lVar22 = param_1[8], uVar26 < *(uint *)(lVar22 + 0x270))) {
      uVar2 = *(ushort *)(*(longlong *)(lVar22 + 0x278) + (longlong)(int)uVar26 * 2);
      if ((uint)uVar2 < *(uint *)(lVar22 + 0x260)) {
        puVar15 = (undefined1 *)(*(longlong *)(lVar22 + 0x268) + (ulonglong)uVar2 * 4);
      }
      else {
        puVar15 = (undefined1 *)0x0;
      }
    }
    *(undefined1 **)(lVar11 + 0x4b8) = puVar15;
  }
  uVar26 = *(uint *)(param_1[7] + 200);
  auVar4 = ZEXT816(0x158) * ZEXT416(uVar26);
  uVar10 = auVar4._0_8_;
  if (auVar4._8_8_ != 0) {
    uVar10 = 0xffffffffffffffff;
  }
  lVar11 = FUN_14018b280(uVar10,0);
  if (lVar11 == 0) {
    lVar11 = 0;
  }
  else {
    iVar25 = uVar26 - 1;
    if (-1 < iVar25) {
      lVar22 = lVar11 + 0x108;
      do {
        FUN_1400037c0(lVar22 + -0x50,0x14,4,&LAB_140306720);
        FUN_1400037c0(lVar22,0x14,4,&LAB_140306720);
        *(undefined8 *)(lVar22 + -0xa0) = 0;
        *(undefined4 *)(lVar22 + -0x98) = 0;
        *(undefined4 *)(lVar22 + -0x54) = 0;
        lVar22 = lVar22 + 0x158;
        iVar25 = iVar25 + -1;
      } while (-1 < iVar25);
    }
  }
  lVar22 = param_1[7];
  param_1[0x65] = lVar11;
  if (*(int *)(param_1[8] + 0x180) == 0) {
    lVar11 = *(longlong *)(lVar22 + 0x10) + 0x6a0;
  }
  else {
    lVar11 = (ulonglong)**(uint **)(lVar22 + 0xd0) * 0x158 + lVar11;
  }
  param_1[0x66] = lVar11;
  puVar15 = puVar20;
  if (*(int *)(lVar22 + 200) != 0) {
    do {
      uVar26 = (int)puVar15 + 1;
      *(longlong *)((longlong)puVar15 * 0x158 + param_1[0x65]) =
           (longlong)puVar15 * 0xc4 + *(longlong *)(param_1[7] + 0xc0);
      puVar15 = (undefined1 *)(ulonglong)uVar26;
    } while (uVar26 < *(uint *)(param_1[7] + 200));
  }
  if (*(uint *)(param_1[8] + 0x180) != 0) {
    auVar4 = ZEXT816(0x40) * ZEXT416(*(uint *)(param_1[8] + 0x180));
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    param_1[0x67] = lVar11;
    uVar26 = *(uint *)(param_1[8] + 0x180);
    uVar12 = SUB168(ZEXT816(0x160) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x160) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 0x10;
    if (0xffffffffffffffef < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      puVar21 = puVar13 + 4;
      *puVar13 = uVar26;
      puVar13 = puVar21;
      while (uVar26 = uVar26 - 1, -1 < (int)uVar26) {
        FUN_1402f1300(puVar13);
        puVar13 = puVar13 + 0x58;
      }
    }
    param_1[0x69] = (longlong)puVar21;
    auVar4 = ZEXT816(0x30) * ZEXT416(*(uint *)(param_1[8] + 0x1b0));
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    param_1[0x68] = lVar11;
    puVar15 = puVar20;
    if (*(int *)(param_1[8] + 0x180) != 0) {
      do {
        uVar26 = (int)puVar15 + 1;
        *(ulonglong *)((longlong)puVar15 * 0x160 + param_1[0x69]) =
             (ulonglong)*(uint *)(*(longlong *)(param_1[7] + 0xd0) + (longlong)puVar15 * 4) * 0x158
             + param_1[0x65];
        puVar15 = (undefined1 *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x180));
    }
  }
  *(undefined4 *)(param_1 + 0x6b) = 0;
  if (*(uint *)(param_1[8] + 0xf0) != 0) {
    auVar4 = ZEXT816(0x60) * ZEXT416(*(uint *)(param_1[8] + 0xf0));
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    param_1[0x3e] = lVar11;
    uVar26 = *(uint *)(param_1[8] + 0xf0);
    auVar4 = ZEXT816(0xc0) * ZEXT416(uVar26);
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    puVar14 = (undefined1 *)FUN_14018b280(uVar10,0);
    uVar9 = _UNK_140b7b24c;
    uVar8 = DAT_140b7b248;
    uVar7 = _UNK_140b7b244;
    uVar3 = _DAT_140b7b240;
    puVar15 = puVar20;
    if ((puVar14 != (undefined1 *)0x0) && (iVar25 = uVar26 - 1, puVar15 = puVar14, -1 < iVar25)) {
      puVar23 = (undefined8 *)(puVar14 + 0x40);
      do {
        *(undefined4 *)(puVar23 + -6) = uVar3;
        *(undefined4 *)((longlong)puVar23 + -0x2c) = uVar7;
        *(undefined4 *)(puVar23 + -5) = uVar8;
        *(undefined4 *)((longlong)puVar23 + -0x24) = uVar9;
        iVar25 = iVar25 + -1;
        puVar23[-4] = 0;
        puVar23[-3] = 0;
        puVar23[-2] = 0;
        puVar23[-1] = 0;
        *puVar23 = 0;
        puVar23[1] = 0;
        puVar23[2] = 0x3f800000;
        local_c8 = uVar3;
        uStack_c4 = uVar7;
        uStack_c0 = uVar8;
        uStack_bc = uVar9;
        local_d8 = 0;
        uStack_d0 = 0;
        local_f8 = 0;
        uStack_f0 = 0;
        puVar23[3] = 0;
        puVar23[4] = 0;
        puVar23[5] = 0;
        puVar23[6] = 0;
        puVar23[7] = 0x3f800000;
        puVar23[8] = 0;
        *(undefined4 *)(puVar23 + 9) = 0;
        *(undefined1 *)((longlong)puVar23 + 0x4c) = 1;
        puVar23[10] = 0;
        puVar23[0xb] = 0;
        puVar23[0xc] = 0;
        puVar23[0xd] = 0;
        puVar23[0xe] = 0;
        puVar23[0xf] = 0;
        puVar23 = puVar23 + 0x18;
      } while (-1 < iVar25);
    }
    param_1[0x3f] = (longlong)puVar15;
    puVar15 = puVar20;
    if (*(int *)(param_1[8] + 0xf0) != 0) {
      do {
        lVar22 = (longlong)puVar15 * 0xb8;
        *(undefined2 *)((longlong)puVar15 * 0x60 + 0x36 + param_1[0x3e]) =
             *(undefined2 *)(lVar22 + *(longlong *)(param_1[8] + 0xf8));
        lVar11 = (longlong)puVar15 * 0xc0;
        uVar26 = (int)puVar15 + 1;
        puVar15 = (undefined1 *)(ulonglong)uVar26;
        *(undefined8 *)(lVar11 + param_1[0x3f]) =
             *(undefined8 *)
              ((ulonglong)*(ushort *)(*(longlong *)(param_1[8] + 0xf8) + 4 + lVar22) * 0x160 +
              param_1[0x69]);
      } while (uVar26 < *(uint *)(param_1[8] + 0xf0));
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x328);
  if (uVar26 != 0) {
    uVar10 = SUB168(ZEXT816(0x20) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x20) * ZEXT416(uVar26),8) != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    puVar14 = (undefined1 *)FUN_14018b280(uVar10,0);
    puVar15 = puVar20;
    if ((puVar14 != (undefined1 *)0x0) && (iVar25 = uVar26 - 1, puVar15 = puVar14, -1 < iVar25)) {
      puVar23 = (undefined8 *)(puVar14 + 8);
      do {
        iVar25 = iVar25 + -1;
        *puVar23 = 0;
        puVar23[1] = 0;
        *(undefined4 *)(puVar23 + 2) = 0;
        puVar23 = puVar23 + 4;
      } while (-1 < iVar25);
    }
    param_1[0x5c] = (longlong)puVar15;
    puVar15 = puVar20;
    if (*(int *)(param_1[8] + 0x328) != 0) {
      do {
        lVar22 = (longlong)puVar15 * 0x20;
        lVar11 = (longlong)puVar15 * 0x38;
        uVar26 = (int)puVar15 + 1;
        puVar15 = (undefined1 *)(ulonglong)uVar26;
        *(undefined8 *)(lVar22 + param_1[0x5c]) =
             *(undefined8 *)
              ((ulonglong)*(ushort *)(lVar11 + 2 + *(longlong *)(param_1[8] + 0x330)) * 0x160 +
              param_1[0x69]);
      } while (uVar26 < *(uint *)(param_1[8] + 0x328));
    }
  }
  lVar11 = param_1[8];
  if (*(ushort *)(lVar11 + 0x348) == 0xffff) {
    param_1[0x5d] = 0;
  }
  else {
    param_1[0x5d] = *(longlong *)((ulonglong)*(ushort *)(lVar11 + 0x348) * 0x160 + param_1[0x69]);
  }
  if (*(ushort *)(lVar11 + 0x368) == 0xffff) {
    param_1[0x61] = 0;
  }
  else {
    param_1[0x61] = *(longlong *)((ulonglong)*(ushort *)(lVar11 + 0x368) * 0x160 + param_1[0x69]);
  }
  uVar26 = *(uint *)(lVar11 + 0x1e0);
  if (uVar26 != 0) {
    uVar10 = SUB168(ZEXT816(0x110) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x110) * ZEXT416(uVar26),8) != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    puVar14 = (undefined1 *)FUN_14018b280(uVar10,0);
    uVar9 = _UNK_140b7b24c;
    uVar8 = DAT_140b7b248;
    uVar7 = _UNK_140b7b244;
    uVar3 = _DAT_140b7b240;
    puVar15 = puVar20;
    if ((puVar14 != (undefined1 *)0x0) && (iVar25 = uVar26 - 1, puVar15 = puVar14, -1 < iVar25)) {
      puVar23 = (undefined8 *)(puVar14 + 0x30);
      do {
        *(undefined4 *)(puVar23 + -4) = uVar3;
        *(undefined4 *)((longlong)puVar23 + -0x1c) = uVar7;
        *(undefined4 *)(puVar23 + -3) = uVar8;
        *(undefined4 *)((longlong)puVar23 + -0x14) = uVar9;
        iVar25 = iVar25 + -1;
        puVar23[-2] = 0;
        puVar23[-1] = 0;
        *puVar23 = 0;
        local_b8 = uVar3;
        uStack_b4 = uVar7;
        uStack_b0 = uVar8;
        uStack_ac = uVar9;
        local_e8 = 0;
        uStack_e0 = 0;
        puVar23[1] = 0;
        puVar23[2] = 0;
        puVar23[3] = 0;
        uStack_9c = uRam0000000140c7845c;
        uStack_a0 = uRam0000000140c78458;
        uStack_a4 = uRam0000000140c78454;
        local_a8 = _DAT_140c78450;
        *(undefined4 *)(puVar23 + 4) = _DAT_140c78450;
        *(undefined4 *)((longlong)puVar23 + 0x24) = uStack_a4;
        *(undefined4 *)(puVar23 + 5) = uStack_a0;
        *(undefined4 *)((longlong)puVar23 + 0x2c) = uStack_9c;
        puVar23[6] = 0;
        puVar23[7] = 0;
        puVar23[8] = 0;
        puVar23[9] = 0;
        puVar23[10] = 0;
        puVar23[0xb] = 0;
        puVar23[0xc] = 0;
        puVar23[0xd] = 0;
        puVar23[0xe] = 0;
        puVar23[0xf] = 0;
        puVar23[0x10] = 0;
        puVar23[0x11] = 0;
        puVar23[0x12] = 0;
        puVar23[0x13] = 0;
        puVar23 = puVar23 + 0x22;
      } while (-1 < iVar25);
    }
    param_1[0x6a] = (longlong)puVar15;
    puVar15 = puVar20;
    if (*(int *)(param_1[8] + 0x1e0) != 0) {
      do {
        uVar26 = (int)puVar15 + 1;
        *(undefined8 *)((longlong)puVar15 * 0x110 + param_1[0x6a]) =
             *(undefined8 *)
              ((ulonglong)*(uint *)((longlong)puVar15 * 0x98 + *(longlong *)(param_1[8] + 0x1e8)) *
               0x160 + param_1[0x69]);
        puVar15 = (undefined1 *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x1e0));
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x200);
  if (uVar26 != 0) {
    uVar10 = SUB168(ZEXT816(0x14) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x14) * ZEXT416(uVar26),8) != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    puVar16 = (undefined1 *)FUN_14018b280(uVar10,0);
    puVar14 = puVar20;
    puVar15 = puVar16;
    if (puVar16 != (undefined1 *)0x0) {
      while (uVar26 = uVar26 - 1, puVar14 = puVar16, -1 < (int)uVar26) {
        *puVar15 = 1;
        *(undefined8 *)(puVar15 + 4) = 0;
        *(undefined8 *)(puVar15 + 0xc) = 0;
        puVar15 = puVar15 + 0x14;
      }
    }
    param_1[0x81] = (longlong)puVar14;
  }
  plVar27 = param_1 + 0x98;
  lVar11 = *plVar27;
  plVar24 = param_1;
  while ((lVar11 != 0 && ((int)plVar24[0x96] == 0))) {
    plVar24 = (longlong *)*plVar27;
    plVar27 = plVar24 + 0x98;
    lVar11 = *plVar27;
  }
  if ((*(uint *)(plVar24 + 6) & 8) != 0) {
    *(uint *)(plVar24 + 6) = *(uint *)(plVar24 + 6) & 0xfffffff7;
    for (lVar11 = plVar24[0x98]; (lVar11 != 0 && ((*(uint *)(lVar11 + 0x30) & 4) != 0));
        lVar11 = *(longlong *)(lVar11 + 0x4c0)) {
      *(uint *)(lVar11 + 0x30) = *(uint *)(lVar11 + 0x30) & 0xfffffffb;
    }
    if ((*(uint *)((longlong)plVar24 + 0x34) & 1) != 0) {
      LOCK();
      *(uint *)((longlong)plVar24 + 0x34) = *(uint *)((longlong)plVar24 + 0x34) & 0xfffffffe;
      UNLOCK();
      for (lVar11 = plVar24[0x98]; (lVar11 != 0 && ((*(uint *)(lVar11 + 0x34) & 0x20) != 0));
          lVar11 = *(longlong *)(lVar11 + 0x4c0)) {
        LOCK();
        *(uint *)(lVar11 + 0x34) = *(uint *)(lVar11 + 0x34) & 0xffffffdf;
        UNLOCK();
      }
    }
  }
  for (lVar11 = plVar24[0x9a]; lVar11 != 0; lVar11 = *(longlong *)(lVar11 + 0x4e0)) {
    if (*(int *)(lVar11 + 0x4b0) == 0) {
      FUN_1402f5e70(lVar11);
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x1c0);
  if (uVar26 != 0) {
    uVar12 = SUB168(ZEXT816(0x18) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x18) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 8;
    if (0xfffffffffffffff7 < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      *puVar13 = uVar26;
      puVar21 = puVar13 + 2;
      while (uVar26 = uVar26 - 1, -1 < (int)uVar26) {
        puVar17 = puVar13 + 6;
        puVar13[2] = 0;
        puVar13[3] = 0;
        puVar13[4] = 0;
        puVar13[5] = 0;
        puVar17[0] = 0;
        puVar17[1] = 0;
        puVar13 = puVar17;
      }
    }
    param_1[0x84] = (longlong)puVar21;
  }
  uVar26 = *(uint *)(param_1[8] + 0x1f0);
  if (uVar26 != 0) {
    uVar12 = SUB168(ZEXT816(0x60) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x60) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 0x10;
    if (0xffffffffffffffef < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      iVar25 = uVar26 - 1;
      *puVar13 = uVar26;
      puVar21 = puVar13 + 4;
      if (-1 < iVar25) {
        uVar10 = CONCAT44(_UNK_140b7b244,_DAT_140b7b240);
        uVar6 = CONCAT44(_UNK_140b7b24c,DAT_140b7b248);
        puVar13 = puVar13 + 0xc;
        do {
          FUN_1400037c0(puVar13 + -4,0x10,2,FUN_14001c280);
          FUN_1400037c0(puVar13 + 4,0x10,2,FUN_14001c280);
          iVar25 = iVar25 + -1;
          puVar13[0xc] = 0;
          puVar13[0xd] = 0;
          puVar13[-6] = 0;
          puVar13[-5] = 0;
          *(undefined8 *)puVar13 = uVar10;
          *(undefined8 *)(puVar13 + 2) = uVar6;
          *(undefined8 *)(puVar13 + -4) = uVar10;
          *(undefined8 *)(puVar13 + -2) = uVar6;
          puVar13[8] = 0;
          puVar13[9] = 0;
          puVar13[10] = 0;
          puVar13[0xb] = 0;
          puVar13[4] = 0;
          puVar13[5] = 0;
          puVar13[6] = 0;
          puVar13[7] = 0;
          puVar13 = puVar13 + 0x18;
        } while (-1 < iVar25);
      }
    }
    param_1[0x8a] = (longlong)puVar21;
    puVar15 = puVar20;
    if (*(int *)(param_1[8] + 0x1f0) != 0) {
      do {
        puVar13 = (uint *)((longlong)puVar15 * 0x30 + *(longlong *)(param_1[8] + 0x1f8));
        puVar23 = (undefined8 *)((longlong)puVar15 * 0x60 + param_1[0x8a]);
        *puVar23 = *(undefined8 *)((ulonglong)*puVar13 * 0x160 + param_1[0x69]);
        uVar26 = puVar13[8];
        auVar4 = ZEXT816(0xe0) * ZEXT416(uVar26);
        uVar10 = auVar4._0_8_;
        if (auVar4._8_8_ != 0) {
          uVar10 = 0xffffffffffffffff;
        }
        puVar16 = (undefined1 *)FUN_14018b280(uVar10,0);
        uVar9 = _UNK_140b7b24c;
        uVar8 = DAT_140b7b248;
        uVar7 = _UNK_140b7b244;
        uVar3 = _DAT_140b7b240;
        puVar14 = puVar20;
        if ((puVar16 != (undefined1 *)0x0) && (iVar25 = uVar26 - 1, puVar14 = puVar16, -1 < iVar25))
        {
          puVar16 = puVar16 + 0x2c;
          do {
            *(undefined8 *)(puVar16 + -0x2c) = 0x3f800000;
            iVar25 = iVar25 + -1;
            *(undefined8 *)(puVar16 + -0x24) = 0;
            *(undefined4 *)(puVar16 + -0x1c) = 0;
            *(undefined8 *)(puVar16 + -0x18) = 0x3f800000;
            *(undefined8 *)(puVar16 + -0x10) = 0;
            *(undefined4 *)(puVar16 + -8) = 0;
            *(undefined8 *)(puVar16 + -4) = 0x3f800000;
            *(undefined8 *)(puVar16 + 4) = 0;
            *(undefined8 *)(puVar16 + 0xc) = 0;
            *(undefined8 *)(puVar16 + 0x14) = 0;
            *(undefined8 *)(puVar16 + 0x1c) = 0;
            *(undefined8 *)(puVar16 + 0x24) = 0;
            *(undefined8 *)(puVar16 + 0x2c) = 0;
            *(undefined4 *)(puVar16 + 0x34) = 0;
            *(undefined8 *)(puVar16 + 0x38) = 0x3f800000;
            *(undefined8 *)(puVar16 + 0x40) = 0;
            *(undefined8 *)(puVar16 + 0x48) = 0;
            *(undefined8 *)(puVar16 + 0x50) = 0;
            *(undefined8 *)(puVar16 + 0x58) = 0;
            *(undefined8 *)(puVar16 + 0x60) = 0;
            *(undefined8 *)(puVar16 + 0x68) = 0;
            *(undefined8 *)(puVar16 + 0x70) = 0;
            *(undefined8 *)(puVar16 + 0x78) = 0;
            *(undefined8 *)(puVar16 + 0x80) = 0;
            *(undefined4 *)(puVar16 + 0x94) = uVar3;
            *(undefined4 *)(puVar16 + 0x98) = uVar7;
            *(undefined4 *)(puVar16 + 0x9c) = uVar8;
            *(undefined4 *)(puVar16 + 0xa0) = uVar9;
            *(undefined8 *)(puVar16 + 0xa4) = 0;
            *(undefined8 *)(puVar16 + 0xac) = 0;
            puVar16 = puVar16 + 0xe0;
          } while (-1 < iVar25);
        }
        puVar23[1] = puVar14;
        uVar26 = (int)puVar15 + 1;
        puVar15 = (undefined1 *)(ulonglong)uVar26;
        *(char *)(puVar23 + 0xb) = (char)puVar13[6];
        *(char *)((longlong)puVar23 + 0x59) = (char)puVar13[7];
      } while (uVar26 < *(uint *)(param_1[8] + 0x1f0));
    }
  }
  fVar35 = 0.0;
  if (*(uint *)(param_1[8] + 0x2c8) == 0) {
LAB_1402f4572:
    lVar11 = lRam0000000140c798a8;
    if ((*(byte *)(param_1 + 5) & 0x20) == 0) {
      param_1[200] = _DAT_140c798a0;
      param_1[0xc9] = lVar11;
      lVar11 = lRam0000000140c798b8;
      param_1[0xca] = _DAT_140c798b0;
      param_1[0xcb] = lVar11;
      uVar8 = uRam0000000140c783dc;
      uVar7 = uRam0000000140c783d8;
      uVar3 = uRam0000000140c783d4;
      *(undefined4 *)(param_1 + 0xcc) = _DAT_140c783d0;
      *(undefined4 *)((longlong)param_1 + 0x664) = uVar3;
      *(undefined4 *)(param_1 + 0xcd) = uVar7;
      *(undefined4 *)((longlong)param_1 + 0x66c) = uVar8;
      *(undefined4 *)(param_1 + 0xce) = DAT_140c783e0;
      goto LAB_1402f464c;
    }
  }
  else {
    auVar4 = ZEXT816(4) * ZEXT416(*(uint *)(param_1[8] + 0x2c8));
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    param_1[0x8b] = lVar11;
    auVar4 = ZEXT816(4) * ZEXT416(*(uint *)(param_1[8] + 0x2c8));
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    param_1[0x8c] = lVar11;
    puVar15 = puVar20;
    if (*(int *)(param_1[8] + 0x2c8) == 0) goto LAB_1402f4572;
    do {
      *(undefined4 *)(param_1[0x8b] + (longlong)puVar15 * 4) =
           *(undefined4 *)(*(longlong *)(param_1[8] + 0x2d0) + 4 + (longlong)puVar15 * 8);
      uVar3 = *(undefined4 *)(param_1[0x8b] + (longlong)puVar15 * 4);
      if (DAT_140c63840 == (code *)0x0) {
        if ((DAT_140c64ca4 == 0) && (iVar25 = FUN_1402338a0(), -1 < iVar25)) {
          lVar11 = (**(code **)(*DAT_140c63d88 + 0x18))(DAT_140c63d88,uVar3);
          goto LAB_1402f4529;
        }
LAB_1402f4550:
        *(undefined4 *)(param_1[0x8c] + (longlong)puVar15 * 4) = 0;
      }
      else {
        lVar11 = (*DAT_140c63840)(&PTR_u_SoundEvent_140a6ce78,uVar3);
LAB_1402f4529:
        if (lVar11 == 0) goto LAB_1402f4550;
        fVar29 = *(float *)(lVar11 + 0x14);
        *(undefined4 *)(param_1[0x8c] + (longlong)puVar15 * 4) = *(undefined4 *)(lVar11 + 0x38);
        if (fVar35 <= fVar29) {
          fVar35 = fVar29;
        }
      }
      uVar26 = (int)puVar15 + 1;
      puVar15 = (undefined1 *)(ulonglong)uVar26;
    } while (uVar26 < *(uint *)(param_1[8] + 0x2c8));
    if (fVar35 == 0.0) goto LAB_1402f4572;
  }
  lVar11 = param_1[8];
  fVar35 = fVar35 * DAT_140b79eec;
  fVar29 = *(float *)(lVar11 + 0x414);
  fVar30 = *(float *)(lVar11 + 0x418);
  fVar31 = *(float *)(lVar11 + 0x41c);
  *(float *)(param_1 + 200) = *(float *)(lVar11 + 0x410) - fVar35;
  *(float *)((longlong)param_1 + 0x644) = fVar29 - fVar35;
  *(float *)(param_1 + 0xc9) = fVar30 - fVar35;
  *(float *)((longlong)param_1 + 0x64c) = fVar31 - fVar35;
  lVar11 = param_1[8];
  fVar29 = *(float *)(lVar11 + 0x420) + fVar35;
  fVar30 = *(float *)(lVar11 + 0x424) + fVar35;
  fVar31 = *(float *)(lVar11 + 0x428) + fVar35;
  fVar35 = *(float *)(lVar11 + 0x42c) + fVar35;
  *(float *)(param_1 + 0xca) = fVar29;
  *(float *)((longlong)param_1 + 0x654) = fVar30;
  *(float *)(param_1 + 0xcb) = fVar31;
  *(float *)((longlong)param_1 + 0x65c) = fVar35;
  fVar32 = fVar29 - *(float *)(param_1 + 200);
  fVar33 = fVar30 - *(float *)((longlong)param_1 + 0x644);
  fVar34 = fVar31 - *(float *)(param_1 + 0xc9);
  fVar30 = (*(float *)((longlong)param_1 + 0x644) + fVar30) * _UNK_140b7ac54;
  fVar31 = (*(float *)(param_1 + 0xc9) + fVar31) * _UNK_140b7ac58;
  fVar35 = (*(float *)((longlong)param_1 + 0x64c) + fVar35) * _UNK_140b7ac5c;
  *(float *)(param_1 + 0xcc) = (*(float *)(param_1 + 200) + fVar29) * _DAT_140b7ac50;
  *(float *)((longlong)param_1 + 0x664) = fVar30;
  *(float *)(param_1 + 0xcd) = fVar31;
  *(float *)((longlong)param_1 + 0x66c) = fVar35;
  local_88 = SQRT(fVar32 * fVar32 + fVar33 * fVar33 + fVar34 * fVar34) * DAT_140b79e48;
  *(float *)(param_1 + 0xce) = local_88;
  local_68 = local_88;
LAB_1402f464c:
  uVar26 = *(uint *)(param_1[8] + 0x2b8);
  if (uVar26 != 0) {
    uVar12 = SUB168(ZEXT816(0x28) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x28) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 8;
    if (0xfffffffffffffff7 < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      iVar25 = uVar26 - 1;
      *puVar13 = uVar26;
      puVar21 = puVar13 + 2;
      if (-1 < iVar25) {
        puVar13 = puVar13 + 6;
        do {
          iVar25 = iVar25 + -1;
          puVar13[-4] = 0;
          puVar13[-3] = 0;
          puVar13[-2] = 0;
          puVar13[-1] = 0;
          *puVar13 = 0;
          puVar13[2] = 0;
          puVar13[3] = 0;
          puVar13[4] = 0;
          puVar13[5] = 0;
          puVar13 = puVar13 + 10;
        } while (-1 < iVar25);
      }
    }
    param_1[0x8d] = (longlong)puVar21;
    if (*(int *)(param_1[8] + 0x2b8) != 0) {
      do {
        uVar12 = 0;
        lVar11 = *(longlong *)(param_1[8] + 0x2c0);
        puVar23 = (undefined8 *)(param_1[0x8d] + (longlong)puVar20 * 0x28);
        iVar25 = (**(code **)(*DAT_140c65848 + 0x28))(DAT_140c65848,puVar23);
        if (iVar25 < 0) {
          local_1b0 = 0;
          local_1b8 = &PTR_LAB_140b5e648;
          local_1a8 = TlsGetValue(DAT_140c63720);
          TlsSetValue(DAT_140c63720,&local_1b8);
          local_158 = local_1b8;
          local_150 = local_1b0;
          local_180 = &PTR_LAB_140b5e648;
          uStack_178 = L"Result";
          local_148 = local_1a8;
          local_170 = TlsGetValue(DAT_140c63720);
          TlsSetValue(DAT_140c63720,&local_180);
          local_180 = &PTR_FUN_140b5e640;
          local_108 = (undefined4)local_170;
          uStack_104 = local_170._4_4_;
          uStack_fc = uStack_164;
          local_118 = 0x40b5e640;
          uStack_114 = 1;
          uStack_110 = (undefined4)uStack_178;
          uStack_10c = uStack_178._4_4_;
          uVar10 = *(undefined8 *)(param_1[7] + 0x18);
          local_1a0 = &PTR_LAB_140b5e648;
          local_198 = L"FileName";
          iStack_168 = iVar25;
          iStack_100 = iVar25;
          local_190 = TlsGetValue(DAT_140c63720);
          TlsSetValue(DAT_140c63720,&local_1a0);
          local_130 = local_198;
          local_1a0 = &PTR_LAB_140b5e638;
          local_138 = &PTR_LAB_140b5e638;
          local_res8 = 0x141deb9e0;
          local_128 = local_190;
          local_188 = uVar10;
          local_120 = uVar10;
          iVar25 = FUN_1401971e0(&DAT_140c8a5f8,6,&local_res8,&local_138,&local_118,&local_158);
          local_1a0 = &PTR_LAB_140b5e648;
          TlsSetValue(DAT_140c63720,local_190);
          local_180 = &PTR_LAB_140b5e648;
          TlsSetValue(DAT_140c63720,local_170);
          local_1b8 = &PTR_LAB_140b5e648;
          TlsSetValue(DAT_140c63720,local_1a8);
          if (iVar25 != 0) {
            DebugBreak();
          }
        }
        if (*(int *)(param_1[8] + 0x2e8) != 0) {
          do {
            (**(code **)(*(longlong *)*puVar23 + 0x48))
                      ((longlong *)*puVar23,
                       *(undefined4 *)(*(longlong *)(param_1[8] + 0x2f0) + uVar12 * 8));
            uVar26 = (int)uVar12 + 1;
            uVar12 = (ulonglong)uVar26;
          } while (uVar26 < *(uint *)(param_1[8] + 0x2e8));
        }
        uVar26 = *(uint *)(lVar11 + 8 + (longlong)puVar20 * 0x28);
        if (uVar26 != 0) {
          uVar10 = SUB168(ZEXT816(0x14) * ZEXT416(uVar26),0);
          if (SUB168(ZEXT816(0x14) * ZEXT416(uVar26),8) != 0) {
            uVar10 = 0xffffffffffffffff;
          }
          lVar22 = FUN_14018b280(uVar10,0);
          if (lVar22 == 0) {
            lVar22 = 0;
          }
          else if (-1 < (int)(uVar26 - 1)) {
            FUN_1407e4830(lVar22,0);
          }
          puVar23[3] = lVar22;
        }
        uVar26 = *(uint *)(lVar11 + 0x18 + (longlong)puVar20 * 0x28);
        if (uVar26 != 0) {
          auVar4._8_8_ = 0;
          auVar4._0_8_ = CONCAT44(0,uVar26);
          uVar10 = SUB168(ZEXT816(0x14) * auVar4,0);
          if (SUB168(ZEXT816(0x14) * auVar4,8) != 0) {
            uVar10 = 0xffffffffffffffff;
          }
          lVar22 = FUN_14018b280(uVar10,0);
          if (lVar22 == 0) {
            lVar22 = 0;
          }
          else if (-1 < (int)(uVar26 - 1)) {
            FUN_1407e4830(lVar22,0,CONCAT44(0,uVar26) * 0x14);
          }
          puVar23[4] = lVar22;
          auVar4 = ZEXT816(8) * ZEXT416(*(uint *)(lVar11 + 0x18 + (longlong)puVar20 * 0x28));
          uVar10 = auVar4._0_8_;
          if (auVar4._8_8_ != 0) {
            uVar10 = 0xffffffffffffffff;
          }
          uVar10 = FUN_14018b280(uVar10,0);
          puVar23[1] = uVar10;
          *(undefined4 *)(puVar23 + 2) = *(undefined4 *)(lVar11 + 0x18 + (longlong)puVar20 * 0x28);
          FUN_1407e4830(uVar10,0);
        }
        uVar26 = (int)puVar20 + 1;
        puVar20 = (undefined1 *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x2b8));
    }
  }
  plVar27 = (longlong *)0x0;
  uVar26 = *(uint *)(param_1[8] + 0x308);
  if (uVar26 != 0) {
    uVar10 = SUB168(ZEXT816(0x48) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x48) * ZEXT416(uVar26),8) != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    plVar18 = (longlong *)FUN_14018b280(uVar10,0);
    plVar24 = plVar27;
    if ((plVar18 != (longlong *)0x0) && (iVar25 = uVar26 - 1, plVar24 = plVar18, -1 < iVar25)) {
      puVar20 = (undefined1 *)((longlong)plVar18 + 0x1c);
      do {
        iVar25 = iVar25 + -1;
        *(undefined8 *)(puVar20 + -0x14) = 0;
        *(undefined8 *)(puVar20 + -0xc) = 0;
        *(undefined8 *)(puVar20 + -4) = 0;
        *(undefined8 *)(puVar20 + 4) = 0;
        *(undefined8 *)(puVar20 + 0xc) = 0;
        *(undefined8 *)(puVar20 + 0x14) = 0;
        *(undefined8 *)(puVar20 + 0x1c) = 0;
        *(undefined4 *)(puVar20 + 0x24) = 0;
        puVar20 = puVar20 + 0x48;
      } while (-1 < iVar25);
    }
    param_1[0xb1] = (longlong)plVar24;
    plVar24 = plVar27;
    if (*(int *)(param_1[8] + 0x308) != 0) {
      do {
        uVar26 = (int)plVar24 + 1;
        *(undefined8 *)(param_1[0xb1] + (longlong)plVar24 * 0x48) =
             *(undefined8 *)
              ((ulonglong)*(ushort *)(*(longlong *)(param_1[8] + 0x310) + (longlong)plVar24 * 0x50)
               * 0x160 + param_1[0x69]);
        plVar24 = (longlong *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x308));
    }
  }
  if (*(uint *)(param_1[8] + 0x2f8) != 0) {
    auVar4 = ZEXT816(8) * ZEXT416(*(uint *)(param_1[8] + 0x2f8));
    uVar10 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    param_1[0xb2] = lVar11;
    FUN_1407e4830(lVar11,0);
    plVar24 = plVar27;
    if (*(int *)(param_1[8] + 0x2f8) != 0) {
      do {
        lVar11 = (longlong)plVar24 * 0xa0 + *(longlong *)(param_1[8] + 0x300);
        iVar25 = *(int *)(lVar11 + 4);
        plVar18 = plVar27;
        if (iVar25 == 0) {
          cVar1 = **(char **)(lVar11 + 0x90);
          if (cVar1 != '\0') {
            if (cVar1 == '\x01') {
              lVar11 = FUN_14018b280(0x5a0,0);
              if (lVar11 != 0) {
                plVar18 = (longlong *)FUN_140319e40(lVar11);
              }
              goto LAB_1402f4c18;
            }
            if (cVar1 != '\x02') goto LAB_1402f4c46;
          }
          lVar11 = FUN_14018b280(0x590,0);
          if (lVar11 != 0) {
            plVar18 = (longlong *)FUN_140312ff0(lVar11);
          }
LAB_1402f4c18:
          iVar25 = (**(code **)(*plVar18 + 0x18))(plVar18);
          if (iVar25 < 0) {
            (**(code **)(*plVar18 + 0x10))(plVar18);
          }
          else {
            *(longlong **)(param_1[0xb2] + (longlong)plVar24 * 8) = plVar18;
          }
        }
        else if (iVar25 == 1) {
          lVar11 = FUN_14018b280(0x6b0,0);
          if (lVar11 != 0) {
            plVar18 = (longlong *)FUN_14031ce90(lVar11);
          }
          goto LAB_1402f4c18;
        }
LAB_1402f4c46:
        if (((*(longlong *)(param_1[0xb2] + (longlong)plVar24 * 8) != 0) &&
            ((int)param_1[0xb4] != 0)) && (*(int *)((longlong)param_1 + 0x5a4) != 0)) {
          (**(code **)(**(longlong **)(param_1[0xb2] + (longlong)plVar24 * 8) + 0x40))();
        }
        uVar26 = (int)plVar24 + 1;
        plVar24 = (longlong *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x2f8));
    }
    plVar24 = *(longlong **)(param_1[2] + 0x1e8);
    if (plVar24 != (longlong *)0x0) {
      (**(code **)(*plVar24 + 0xf0))(plVar24,param_1 + 0xb3);
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x318);
  if (uVar26 != 0) {
    uVar12 = SUB168(ZEXT816(0x1b0) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x1b0) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 0x10;
    if (0xffffffffffffffef < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      puVar21 = puVar13 + 4;
      *puVar13 = uVar26;
      puVar13 = puVar21;
      while (uVar26 = uVar26 - 1, -1 < (int)uVar26) {
        FUN_1402f2170(puVar13);
        puVar13 = puVar13 + 0x6c;
      }
    }
    param_1[0xb7] = (longlong)puVar21;
    if ((*(longlong *)(param_1[2] + 0x1e8) != 0) &&
       (plVar24 = plVar27, *(int *)(param_1[8] + 0x318) != 0)) {
      do {
        (**(code **)(**(longlong **)(param_1[2] + 0x1e8) + 0xe8))
                  (*(longlong **)(param_1[2] + 0x1e8),
                   (longlong)plVar24 * 0x1b0 + param_1[0xb7] + 0x1a8);
        uVar26 = (int)plVar24 + 1;
        plVar24 = (longlong *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x318));
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x560);
  if (uVar26 != 0) {
    uVar12 = SUB168(ZEXT816(0x88) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x88) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 8;
    if (0xfffffffffffffff7 < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      iVar25 = uVar26 - 1;
      *puVar13 = uVar26;
      puVar21 = puVar13 + 2;
      if (-1 < iVar25) {
        puVar13 = puVar13 + 6;
        do {
          iVar25 = iVar25 + -1;
          puVar13[0] = 0;
          puVar13[1] = 0;
          puVar13[2] = 0;
          puVar13[3] = 0;
          puVar13[4] = 0;
          puVar13[5] = 0;
          puVar13[6] = 0;
          puVar13[7] = 0;
          puVar13[8] = 0;
          puVar13[9] = 0;
          puVar13[10] = 0;
          puVar13[0xb] = 0;
          puVar13[0xc] = 0;
          puVar13[0xd] = 0;
          puVar13[0xe] = 0;
          puVar13[0xf] = 0;
          puVar13[0x10] = 0;
          puVar13[0x11] = 0;
          puVar13[0x12] = 0;
          puVar13[0x13] = 0;
          puVar13[0x14] = 0;
          puVar13[0x15] = 0;
          puVar13[0x16] = 0;
          puVar13[0x17] = 0;
          puVar13[0x18] = 0;
          puVar13[0x19] = 0;
          puVar13[0x1a] = 0;
          puVar13[0x1b] = 0;
          puVar13[0x1c] = 0;
          puVar13 = puVar13 + 0x22;
        } while (-1 < iVar25);
      }
    }
    param_1[0xb8] = (longlong)puVar21;
    if (*(int *)(param_1[8] + 0x560) != 0) {
      local_res8 = CONCAT44(local_res8._4_4_,0x100);
      local_res10 = 1;
      plVar24 = plVar27;
      do {
        uVar26 = (int)plVar24 + 1;
        plVar18 = (longlong *)((longlong)plVar24 * 0x88 + param_1[0xb8]);
        lVar11 = *(longlong *)(param_1[8] + 0x568);
        *(undefined4 *)(plVar18 + 4) = 0;
        *(undefined2 *)((longlong)plVar18 + 0x34) = 0;
        *(undefined4 *)(plVar18 + 9) = 0xff7f7f7f;
        *(undefined4 *)((longlong)plVar18 + 0x5c) = 0x100;
        *(undefined4 *)(plVar18 + 0xe) = 1;
        *plVar18 = (longlong)plVar24 * 0xa0 + lVar11;
        plVar24 = (longlong *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x560));
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x570);
  if (uVar26 != 0) {
    uVar12 = SUB168(ZEXT816(0x30) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x30) * ZEXT416(uVar26),8) != 0) {
      uVar12 = 0xffffffffffffffff;
    }
    lVar11 = uVar12 + 8;
    if (0xfffffffffffffff7 < uVar12) {
      lVar11 = -1;
    }
    puVar13 = (uint *)FUN_14018b280(lVar11,0);
    if (puVar13 == (uint *)0x0) {
      puVar21 = (uint *)0x0;
    }
    else {
      iVar25 = uVar26 - 1;
      *puVar13 = uVar26;
      puVar21 = puVar13 + 2;
      if (-1 < iVar25) {
        puVar13 = puVar13 + 4;
        do {
          iVar25 = iVar25 + -1;
          puVar13[0] = 0;
          puVar13[1] = 0;
          puVar13[2] = 0;
          puVar13[3] = 0;
          puVar13[4] = 0;
          puVar13[6] = 0;
          puVar13[7] = 0;
          puVar13[8] = 0;
          puVar13[9] = 0;
          puVar13 = puVar13 + 0xc;
        } while (-1 < iVar25);
      }
    }
    param_1[0xba] = (longlong)puVar21;
    plVar24 = plVar27;
    if (*(int *)(param_1[8] + 0x570) != 0) {
      do {
        uVar26 = (int)plVar24 + 1;
        *(longlong *)(param_1[0xba] + (longlong)plVar24 * 0x30) =
             (longlong)plVar24 * 0x20 + *(longlong *)(param_1[8] + 0x578);
        plVar24 = (longlong *)(ulonglong)uVar26;
      } while (uVar26 < *(uint *)(param_1[8] + 0x570));
    }
  }
  uVar26 = *(uint *)(param_1[8] + 0x540);
  if (uVar26 != 0) {
    uVar10 = SUB168(ZEXT816(0x80) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x80) * ZEXT416(uVar26),8) != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    plVar18 = (longlong *)FUN_14018b280(uVar10,0);
    plVar24 = plVar27;
    if ((plVar18 != (longlong *)0x0) && (iVar25 = uVar26 - 1, plVar24 = plVar18, -1 < iVar25)) {
      plVar18 = plVar18 + 8;
      do {
        iVar25 = iVar25 + -1;
        plVar18[-8] = 0;
        plVar18[-7] = 0;
        *(undefined4 *)(plVar18 + -6) = 0;
        plVar18[-4] = 0;
        plVar18[-3] = 0;
        plVar18[-2] = 0;
        plVar18[-1] = 0;
        *plVar18 = 0;
        plVar18[1] = 0;
        plVar18[2] = 0;
        plVar18[3] = 0;
        plVar18[4] = 0;
        plVar18[5] = 0;
        plVar18[6] = 0;
        plVar18[7] = 0;
        plVar18 = plVar18 + 0x10;
      } while (-1 < iVar25);
    }
    param_1[0xd0] = (longlong)plVar24;
  }
  uVar26 = *(uint *)(param_1[8] + 0x588);
  if (uVar26 != 0) {
    uVar10 = SUB168(ZEXT816(0x14) * ZEXT416(uVar26),0);
    if (SUB168(ZEXT816(0x14) * ZEXT416(uVar26),8) != 0) {
      uVar10 = 0xffffffffffffffff;
    }
    lVar11 = FUN_14018b280(uVar10,0);
    if (lVar11 == 0) {
      lVar11 = 0;
    }
    else if (-1 < (int)(uVar26 - 1)) {
      FUN_1407e4830(lVar11,0,(ulonglong)uVar26 * 0x14);
    }
    param_1[0xd1] = lVar11;
  }
  fVar35 = *(float *)(param_1[8] + 0x5e0);
  fVar29 = *(float *)(param_1[8] + 0x5d8);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)((longlong)param_1 + 0x6c4) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x5e4);
  fVar29 = *(float *)(param_1[8] + 0x5dc);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)(param_1 + 0xd9) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x5f0);
  fVar29 = *(float *)(param_1[8] + 0x5e8);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)((longlong)param_1 + 0x6cc) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x5f4);
  fVar29 = *(float *)(param_1[8] + 0x5ec);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)(param_1 + 0xda) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x600);
  fVar29 = *(float *)(param_1[8] + 0x5f8);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)((longlong)param_1 + 0x6d4) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x604);
  fVar29 = *(float *)(param_1[8] + 0x5fc);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)(param_1 + 0xdb) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x610);
  fVar29 = *(float *)(param_1[8] + 0x608);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)((longlong)param_1 + 0x6dc) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x614);
  fVar29 = *(float *)(param_1[8] + 0x60c);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)(param_1 + 0xdc) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x620);
  fVar29 = *(float *)(param_1[8] + 0x618);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)((longlong)param_1 + 0x6e4) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  fVar35 = *(float *)(param_1[8] + 0x624);
  fVar29 = *(float *)(param_1[8] + 0x61c);
  dVar5 = (double)(**(code **)(DAT_140c77890 + 0x28))(&DAT_140c77890);
  *(float *)(param_1 + 0xdd) = (float)(dVar5 * (double)(fVar35 - fVar29)) + fVar29;
  plVar24 = plVar27;
  do {
    lVar11 = param_1[8];
    uVar12 = (ulonglong)(int)plVar24[0x2815e283];
    if (((uVar12 < *(uint *)(lVar11 + 0x210)) &&
        (uVar2 = *(ushort *)(*(longlong *)(lVar11 + 0x218) + uVar12 * 2), uVar2 != 0xffff)) &&
       ((*(byte *)(*(longlong *)(lVar11 + 0x208) + 2 + (ulonglong)uVar2 * 4) & 1) != 0)) {
      (**(code **)(*param_1 + 0x2d8))(param_1,uVar12,1);
    }
    plVar24 = (longlong *)((longlong)plVar24 + 4);
    plVar18 = plVar27;
    plVar28 = plVar27;
  } while (plVar24 < &DAT_00000010);
  do {
    if ((*(int *)((longlong)plVar18 + param_1[8] + 0x20) != 0) ||
       (*(int *)((longlong)plVar18 + param_1[8] + 0x90) != 0)) {
      plVar19 = (longlong *)FUN_14018b280(0x20);
      plVar24 = plVar27;
      if (plVar19 != (longlong *)0x0) {
        plVar19[1] = 0;
        plVar19[2] = 0;
        plVar19[3] = 0;
        *(int *)plVar19 = (int)plVar28;
        plVar24 = plVar19;
      }
      param_1[(ulonglong)*(uint *)(param_1 + 0x71) + 0x72] = (longlong)plVar24;
      *(int *)(param_1 + 0x71) = (int)param_1[0x71] + 1;
      if (*(int *)((longlong)plVar18 + param_1[8] + 0x20) != 0) {
        FUN_1402f9480(param_1);
      }
      if (*(int *)((longlong)plVar18 + param_1[8] + 0x90) != 0) {
        FUN_1402f96a0(param_1);
      }
    }
    uVar26 = (int)plVar28 + 1;
    plVar18 = plVar18 + 3;
    plVar28 = (longlong *)(ulonglong)uVar26;
  } while (uVar26 < 4);
  local_res18 = (longlong *)0x0;
  if (param_1[9] != 0) {
    do {
      plVar27 = (longlong *)param_1[9];
      if ((longlong *)plVar27[2] != (longlong *)0x0) {
        *(longlong *)plVar27[2] = plVar27[3];
      }
      plVar24 = plVar27 + 3;
      if (plVar27[3] != 0) {
        *(longlong *)(plVar27[3] + 0x10) = plVar27[2];
      }
      *plVar24 = 0;
      plVar27[2] = (longlong)&local_res18;
      *plVar24 = (longlong)local_res18;
      if (*plVar24 != 0) {
        *(longlong **)(*plVar24 + 0x10) = plVar24;
      }
      local_res18 = plVar27;
    } while (param_1[9] != 0);
    while ((local_res18 != (longlong *)0x0 &&
           ((**(code **)(*local_res18 + 8))(local_res18), local_res18 != (longlong *)0x0))) {
      (**(code **)*local_res18)(local_res18,1);
    }
  }
  return;
}



==== FUN_14037c090 @ 14037c090 size 592 ====
CALLERS: FUN_140355440
CALLEES: FUN_1407e4830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_14037c090(longlong *param_1,longlong param_2)

{
  undefined8 uVar1;
  
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  *(undefined4 *)(param_1 + 0x37) = 0x544e5645;
  *(undefined4 *)((longlong)param_1 + 0x1fc) = 0;
  param_1[0xab] = 0;
  param_1[0xaa] = 0;
  param_1[0xad] = 0;
  param_1[0xac] = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = 0;
  param_1[0xb0] = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  param_1[0xb5] = 0;
  param_1[0xb6] = 0;
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = 0;
  param_1[0xba] = 0;
  *param_1 = param_2;
  *(int *)(param_2 + 0x870) = *(int *)(param_2 + 0x870) + 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  param_1[0x16] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x5e] = 0;
  param_1[0x61] = 0;
  param_1[0x6c] = 0;
  param_1[0x6e] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_1407e4830(param_1 + 0x40,0,0x80);
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0x70] = 0;
  param_1[0x6f] = 0;
  param_1[0x7a] = 0;
  param_1[0x7c] = 0;
  param_1[0x7e] = 0;
  uVar1 = _DAT_140c79888;
  param_1[0x82] = 0;
  *(undefined8 *)((longlong)param_1 + 0x3fc) = uVar1;
  param_1[0x81] = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  return param_1;
}



==== FUN_14037c2e0 @ 14037c2e0 size 1569 ====
CALLERS: FUN_1403522c0 FUN_140355440
CALLEES: FUN_140195d70 FUN_14018b900 FUN_1401a4a00 FUN_140377fe0 FUN_140389c40 FUN_140383760 FUN_140367760

void FUN_14037c2e0(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  
  FUN_140383760();
  uVar6 = 0;
  if ((longlong *)param_1[2] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[2] + 8))();
    param_1[2] = 0;
  }
  lVar3 = 4;
  plVar7 = param_1 + 0xb;
  lVar4 = 4;
  do {
    if ((longlong *)plVar7[-4] != (longlong *)0x0) {
      (**(code **)(*(longlong *)plVar7[-4] + 8))();
      plVar7[-4] = 0;
    }
    if ((longlong *)*plVar7 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar7 + 8))();
      *plVar7 = 0;
    }
    if ((longlong *)plVar7[4] != (longlong *)0x0) {
      (**(code **)(*(longlong *)plVar7[4] + 8))();
      plVar7[4] = 0;
    }
    plVar7 = plVar7 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if ((longlong *)param_1[0x14] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x14] + 8))();
    param_1[0x14] = 0;
  }
  FUN_14018b900(param_1[0x13],0);
  if ((longlong *)param_1[0x16] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x16] + 8))();
    param_1[0x16] = 0;
  }
  if ((longlong *)param_1[0x30] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x30] + 8))();
    param_1[0x30] = 0;
  }
  if ((longlong *)param_1[0x31] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x31] + 8))();
    param_1[0x31] = 0;
  }
  if ((longlong *)param_1[0x32] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x32] + 8))();
    param_1[0x32] = 0;
  }
  if ((longlong *)param_1[0x33] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x33] + 8))();
    param_1[0x33] = 0;
  }
  if ((longlong *)param_1[0x34] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x34] + 8))();
    param_1[0x34] = 0;
  }
  plVar7 = param_1 + 0x40;
  lVar4 = 0x10;
  do {
    if ((longlong *)*plVar7 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar7 + 8))();
      *plVar7 = 0;
    }
    plVar7 = plVar7 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  plVar7 = param_1 + 0x54;
  lVar4 = 4;
  do {
    if ((longlong *)plVar7[-4] != (longlong *)0x0) {
      (**(code **)(*(longlong *)plVar7[-4] + 8))();
      plVar7[-4] = 0;
    }
    if ((longlong *)*plVar7 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar7 + 8))();
      *plVar7 = 0;
    }
    plVar7 = plVar7 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if ((longlong *)param_1[0x5e] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x5e] + 8))();
    param_1[0x5e] = 0;
  }
  if ((longlong *)param_1[0x61] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x61] + 8))();
    param_1[0x61] = 0;
  }
  uVar5 = uVar6;
  if (param_1[0x6f] != 0) {
    do {
      plVar7 = *(longlong **)(param_1[0x70] + uVar5 * 8);
      piVar1 = (int *)((longlong)plVar7 + 0x41c);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_140377fe0(plVar7);
      }
      (**(code **)(*plVar7 + 8))(plVar7);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (ulonglong)param_1[0x6f]);
  }
  FUN_14018b900(param_1[0x70],0);
  if ((longlong *)param_1[0x7a] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x7a] + 8))();
    param_1[0x7a] = 0;
  }
  if ((longlong *)param_1[0x7c] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x7c] + 8))();
    param_1[0x7c] = 0;
  }
  if ((longlong *)param_1[0x7e] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x7e] + 8))();
    param_1[0x7e] = 0;
  }
  if (param_1[0x81] != 0) {
    do {
      lVar4 = param_1[0x82];
      plVar7 = *(longlong **)(lVar4 + uVar6 * 8);
      if (plVar7 != (longlong *)0x0) {
        (**(code **)(*plVar7 + 8))();
        *(undefined8 *)(lVar4 + uVar6 * 8) = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < (ulonglong)param_1[0x81]);
  }
  FUN_14018b900(param_1[0x82],0);
  plVar7 = param_1 + 0x8d;
  lVar4 = 4;
  do {
    if ((longlong *)*plVar7 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar7 + 8))();
      *plVar7 = 0;
    }
    plVar7 = plVar7 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if ((longlong *)param_1[0x91] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x91] + 8))();
    param_1[0x91] = 0;
  }
  if ((longlong *)param_1[0x92] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x92] + 8))();
    param_1[0x92] = 0;
  }
  if ((longlong *)param_1[0x93] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x93] + 8))();
    param_1[0x93] = 0;
  }
  plVar7 = param_1 + 0x9c;
  do {
    if ((longlong *)*plVar7 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar7 + 8))();
      *plVar7 = 0;
    }
    plVar7 = plVar7 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if ((longlong *)param_1[0xa0] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xa0] + 8))();
    param_1[0xa0] = 0;
  }
  if ((longlong *)param_1[0xa1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xa1] + 8))();
    param_1[0xa1] = 0;
  }
  FUN_140389c40(param_1);
  if (param_1[0xb5] != 0) {
    *(int *)(*param_1 + 0x874) = *(int *)(*param_1 + 0x874) + -1;
  }
  if (param_1[0xb7] != 0) {
    *(int *)(*param_1 + 0x878) = *(int *)(*param_1 + 0x878) + -1;
  }
  if (param_1[0xb9] != 0) {
    *(int *)(*param_1 + 0x87c) = *(int *)(*param_1 + 0x87c) + -1;
  }
  *(int *)(*param_1 + 0x870) = *(int *)(*param_1 + 0x870) + -1;
  lVar3 = param_1[3];
  if (lVar3 != 0) {
    if (*(longlong *)(lVar3 + 0x20) != 0) {
      for (lVar4 = *(longlong *)(lVar3 + 0x30); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x18)) {
        lVar2 = *(longlong *)(lVar4 + 8);
        piVar1 = (int *)(lVar2 + 0x420);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          FUN_140367760(*(undefined8 *)(lVar2 + 0x10),lVar2);
          (**(code **)(**(longlong **)(lVar2 + 0x30) + 0x18))();
        }
      }
    }
    *(undefined8 *)(lVar3 + 0x20) = 0;
    (**(code **)(*(longlong *)param_1[3] + 8))();
  }
  if ((longlong *)param_1[0xb9] != (longlong *)0x0) {
    *(longlong *)param_1[0xb9] = param_1[0xba];
  }
  if (param_1[0xba] != 0) {
    *(longlong *)(param_1[0xba] + 0x5c8) = param_1[0xb9];
  }
  param_1[0xb9] = 0;
  param_1[0xba] = 0;
  if ((longlong *)param_1[0xb7] != (longlong *)0x0) {
    *(longlong *)param_1[0xb7] = param_1[0xb8];
  }
  if (param_1[0xb8] != 0) {
    *(longlong *)(param_1[0xb8] + 0x5b8) = param_1[0xb7];
  }
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  if ((longlong *)param_1[0xb5] != (longlong *)0x0) {
    *(longlong *)param_1[0xb5] = param_1[0xb6];
  }
  if (param_1[0xb6] != 0) {
    *(longlong *)(param_1[0xb6] + 0x5a8) = param_1[0xb5];
  }
  param_1[0xb5] = 0;
  param_1[0xb6] = 0;
  if ((longlong *)param_1[0xb3] != (longlong *)0x0) {
    *(longlong *)param_1[0xb3] = param_1[0xb4];
  }
  if (param_1[0xb4] != 0) {
    *(longlong *)(param_1[0xb4] + 0x598) = param_1[0xb3];
  }
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  if ((longlong *)param_1[0xb1] != (longlong *)0x0) {
    *(longlong *)param_1[0xb1] = param_1[0xb2];
  }
  if (param_1[0xb2] != 0) {
    *(longlong *)(param_1[0xb2] + 0x588) = param_1[0xb1];
  }
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  if ((longlong *)param_1[0xaf] != (longlong *)0x0) {
    *(longlong *)param_1[0xaf] = param_1[0xb0];
  }
  if (param_1[0xb0] != 0) {
    *(longlong *)(param_1[0xb0] + 0x578) = param_1[0xaf];
  }
  param_1[0xaf] = 0;
  param_1[0xb0] = 0;
  if (param_1[0xae] != 0) {
    FUN_1401a4a00();
  }
  lVar3 = param_1[0xac];
  if (lVar3 != 0) {
    (**(code **)(*(longlong *)(lVar3 + -0x10) + 8))(lVar3 + -0x10);
  }
  lVar3 = param_1[0xaa];
  if (lVar3 != 0) {
    (**(code **)(*(longlong *)(lVar3 + -0x10) + 8))(lVar3 + -0x10);
  }
  FUN_140195d70(param_1 + 0x37);
  *(undefined4 *)(param_1 + 0x37) = 0;
  if ((longlong *)param_1[0x39] != (longlong *)0x0) {
    *(longlong *)param_1[0x39] = param_1[0x3a];
  }
  if ((longlong *)param_1[0x3a] != (longlong *)0x0) {
    *(longlong *)param_1[0x3a] = param_1[0x39];
  }
  param_1[0x3a] = 0;
  param_1[0x39] = 0;
  return;
}



==== FUN_140323d50 @ 140323d50 size 6099 ====
CALLERS:
CALLEES: FUN_1401afc20 __security_check_cookie FUN_1408fc7f0 FUN_140321360 FUN_140322ce0 FUN_1408fe170 FUN_140262d50 FUN_1401afb10 FUN_1403220c0 FUN_140262750 FUN_140323590 FUN_1401c3280 FUN_140262900 FUN_140052360

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140323d50(longlong *param_1,float *param_2,undefined8 *param_3,undefined8 param_4,
                  float *param_5,undefined8 param_6,float *param_7,longlong param_8,
                  undefined8 param_9,uint param_10,longlong param_11,uint param_12)

{
  ushort uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  short sVar6;
  short sVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  undefined4 *puVar15;
  byte bVar16;
  short sVar17;
  short sVar18;
  uint uVar19;
  ulonglong uVar20;
  short *psVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  uint uVar24;
  int iVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  uint uVar28;
  float *pfVar29;
  uint uVar30;
  longlong lVar31;
  bool bVar32;
  float fVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  undefined1 auStack_918 [32];
  ulonglong local_8f8;
  undefined1 *local_8f0;
  float **local_8e8;
  undefined4 local_8e0;
  float local_8d8;
  float **local_8d0;
  float *local_8c8;
  undefined1 *puStack_8c0;
  uint local_8b8;
  int local_8b4;
  ulonglong local_8b0;
  undefined4 uStack_8a8;
  undefined4 uStack_8a4;
  undefined1 local_898 [8];
  undefined8 uStack_890;
  longlong local_888;
  undefined8 local_880;
  longlong local_878;
  float *local_870;
  undefined1 local_868 [16];
  float *local_858;
  undefined8 uStack_850;
  undefined8 local_848;
  float local_840;
  undefined4 local_83c;
  float *local_838;
  longlong local_828;
  float *local_820;
  float *local_818;
  undefined8 uStack_810;
  float local_808;
  undefined4 local_804;
  undefined8 local_7f8;
  undefined8 uStack_7f0;
  undefined8 local_7e8;
  undefined8 uStack_7e0;
  undefined8 local_7d8;
  undefined8 uStack_7d0;
  undefined8 local_7c8;
  undefined8 uStack_7c0;
  float *local_7b8;
  undefined8 uStack_7b0;
  undefined8 local_7a8;
  undefined8 uStack_7a0;
  float local_798;
  float fStack_794;
  float fStack_790;
  float fStack_78c;
  float local_788;
  float fStack_784;
  float fStack_780;
  float fStack_77c;
  undefined8 local_778;
  undefined8 uStack_770;
  undefined8 local_768;
  undefined8 uStack_760;
  float *local_758;
  undefined8 uStack_750;
  float local_748;
  float fStack_744;
  float fStack_740;
  float fStack_73c;
  float local_738;
  float fStack_734;
  float fStack_730;
  float fStack_72c;
  float local_728;
  float fStack_724;
  float fStack_720;
  float fStack_71c;
  float local_718;
  float local_714;
  float local_710;
  undefined4 local_708;
  undefined4 uStack_704;
  undefined4 uStack_700;
  undefined4 uStack_6fc;
  undefined4 local_6f8;
  undefined4 uStack_6f4;
  undefined4 uStack_6f0;
  undefined4 uStack_6ec;
  undefined4 local_6e8;
  undefined4 uStack_6e4;
  undefined4 uStack_6e0;
  undefined4 uStack_6dc;
  undefined4 local_6d8;
  undefined4 uStack_6d4;
  undefined4 uStack_6d0;
  undefined4 uStack_6cc;
  undefined8 local_6c8;
  undefined8 uStack_6c0;
  undefined4 local_6b8;
  undefined4 uStack_6b4;
  undefined4 uStack_6b0;
  undefined4 uStack_6ac;
  undefined8 local_6a8;
  undefined8 uStack_6a0;
  float local_698;
  float fStack_694;
  float fStack_690;
  float fStack_68c;
  undefined8 local_688;
  undefined8 uStack_680;
  undefined8 local_678;
  undefined8 uStack_670;
  undefined8 local_668;
  undefined8 uStack_660;
  undefined8 local_658;
  undefined8 uStack_650;
  float local_648;
  float fStack_644;
  float fStack_640;
  float fStack_63c;
  float local_638;
  float fStack_634;
  float fStack_630;
  float fStack_62c;
  float local_628;
  float fStack_624;
  float fStack_620;
  float fStack_61c;
  float local_618;
  float fStack_614;
  float fStack_610;
  float fStack_60c;
  float local_608;
  float fStack_604;
  float fStack_600;
  undefined4 uStack_5fc;
  float local_5f8;
  float fStack_5f4;
  float fStack_5f0;
  float fStack_5ec;
  float local_5e8;
  float fStack_5e4;
  float fStack_5e0;
  float fStack_5dc;
  float local_5d8;
  float fStack_5d4;
  float fStack_5d0;
  float fStack_5cc;
  float local_5c8;
  float fStack_5c4;
  float fStack_5c0;
  float fStack_5bc;
  float local_5b8;
  float fStack_5b4;
  float fStack_5b0;
  float fStack_5ac;
  float local_5a8 [13];
  float local_574;
  float local_568 [13];
  float local_534;
  undefined1 local_528 [64];
  undefined1 local_4e8 [64];
  undefined1 local_4a8 [64];
  float *local_468;
  undefined8 local_460;
  float *local_418;
  undefined8 local_410;
  float *local_3c8;
  undefined1 *local_3c0;
  float *local_378;
  undefined1 *local_370;
  undefined8 *local_328;
  undefined8 local_320;
  undefined8 local_2d8 [10];
  undefined8 *local_288 [10];
  undefined8 *local_238 [10];
  undefined8 local_1e8 [10];
  undefined1 local_198 [32];
  float local_178;
  ulonglong local_b8;
  undefined8 extraout_XMM0_Qb;
  
  local_b8 = DAT_140c0f7b0 ^ (ulonglong)auStack_918;
  local_838 = param_7;
  local_888 = param_8;
  if (*(uint *)(param_1 + 0xa6) < 2) {
    return;
  }
  if (*(short *)(param_11 + 0x34) == 0) {
    return;
  }
  if ((*(float *)(param_11 + 0x20) == 0.0) && (*(float *)(param_11 + 0x24) == 0.0)) {
    return;
  }
  local_880 = param_4;
  if (*(char *)param_1[0x9d] == '\x01') {
    if ((int)param_1[10] == 0) {
      return;
    }
    iVar12 = (**(code **)(*param_1 + 0x48))();
    if (iVar12 == 0) {
      return;
    }
  }
  local_6c8 = *param_3;
  uStack_6c0 = param_3[1];
  local_6b8 = *(undefined4 *)(param_3 + 2);
  uStack_6b4 = *(undefined4 *)((longlong)param_3 + 0x14);
  uStack_6b0 = *(undefined4 *)(param_3 + 3);
  uStack_6ac = *(undefined4 *)((longlong)param_3 + 0x1c);
  uVar23 = 0;
  fVar41 = *(float *)(param_3 + 6);
  fVar42 = *(float *)((longlong)param_3 + 0x34);
  fVar45 = *(float *)(param_3 + 7);
  fVar44 = *(float *)((longlong)param_3 + 0x3c);
  local_6a8 = param_3[4];
  uStack_6a0 = param_3[5];
  local_698 = fVar41;
  fStack_694 = fVar42;
  fStack_690 = fVar45;
  fStack_68c = fVar44;
  if ((*(int *)(param_1[1] + 0x28) == 0) || (*(int *)(param_1[1] + 8) == 2)) {
    local_688 = *(undefined8 *)param_2;
    uStack_680 = *(undefined8 *)(param_2 + 2);
    local_678 = *(undefined8 *)(param_2 + 4);
    uStack_670 = *(undefined8 *)(param_2 + 6);
    local_668 = *(undefined8 *)(param_2 + 8);
    uStack_660 = *(undefined8 *)(param_2 + 10);
    local_658 = *(undefined8 *)(param_2 + 0xc);
    uStack_650 = *(undefined8 *)(param_2 + 0xe);
    local_7f8 = *(undefined8 *)param_5;
    uStack_7f0 = *(undefined8 *)(param_5 + 2);
    local_7e8 = *(undefined8 *)(param_5 + 4);
    uStack_7e0 = *(undefined8 *)(param_5 + 6);
    local_7d8 = *(undefined8 *)(param_5 + 8);
    uStack_7d0 = *(undefined8 *)(param_5 + 10);
    local_7c8 = *(undefined8 *)(param_5 + 0xc);
    uStack_7c0 = *(undefined8 *)(param_5 + 0xe);
  }
  else {
    local_2d8[0] = param_4;
    FUN_1401afc20(local_2d8,local_528);
    puStack_8c0 = local_528;
    local_8c8 = param_2;
    local_3c8 = param_2;
    local_3c0 = puStack_8c0;
    FUN_1401afb10(&local_3c8,local_5a8);
    local_1e8[0] = param_4;
    FUN_1401afc20(local_1e8,local_4e8);
    puStack_8c0 = local_4e8;
    local_8c8 = param_5;
    local_378 = param_5;
    local_370 = puStack_8c0;
    FUN_1401afb10(&local_378,local_568);
    plVar2 = *(longlong **)(*(longlong *)(param_1[5] + 0x10) + 0x1e8);
    local_574 = 0.0;
    if (plVar2 != (longlong *)0x0) {
      local_8f8 = 0;
      local_628 = _DAT_140c77870;
      fStack_624 = fRam0000000140c77874;
      fStack_620 = fRam0000000140c77878;
      fStack_61c = fRam0000000140c7787c;
      local_798 = fVar41 + _DAT_140c77870;
      fStack_794 = fVar42 + fRam0000000140c77874;
      fStack_790 = fVar45 + fRam0000000140c77878;
      fStack_78c = fVar44 + fRam0000000140c7787c;
      iVar12 = (**(code **)(*plVar2 + 0x1b8))(plVar2,&local_798,local_198,1);
      if (iVar12 != 0) {
        local_574 = local_178;
      }
    }
    local_8c8 = local_5a8;
    puStack_8c0 = (undefined1 *)param_4;
    fStack_694 = local_574;
    local_534 = local_574;
    local_418 = local_8c8;
    local_410 = param_4;
    FUN_1401afb10(&local_418,&local_688);
    local_8c8 = local_568;
    puStack_8c0 = (undefined1 *)param_4;
    local_468 = local_8c8;
    local_460 = param_4;
    FUN_1401afb10(&local_468,&local_7f8);
  }
  local_288[0] = &local_7f8;
  FUN_1401afc20(local_288,local_4a8);
  FUN_140052360(&DAT_140c79de8,(int)param_1[0xa4] + 1);
  FUN_140052360(&DAT_140c79df8,(int)param_1[0xa4] + 1);
  local_238[0] = &local_7f8;
  fVar45 = SQRT(*param_2 * *param_2 + param_2[1] * param_2[1] + param_2[2] * param_2[2]);
  FUN_1401afc20(local_238,&local_748);
  auVar5._4_4_ = local_714;
  auVar5._0_4_ = local_718;
  auVar5._8_4_ = local_710;
  local_898._4_4_ = local_714;
  local_898._0_4_ = local_718;
  uStack_890._0_4_ = local_710;
  local_608 = _DAT_140b7a8c0;
  fStack_604 = _UNK_140b7a8c4;
  fStack_600 = _UNK_140b7a8c8;
  uStack_5fc = _UNK_140b7a8cc;
  uStack_890._4_4_ = 0.0;
  local_5c8 = _UNK_140b7a8c4 * local_738 + _DAT_140b7a8c0 * local_748 + _UNK_140b7a8c8 * local_728;
  fStack_5c4 = _UNK_140b7a8c4 * fStack_734 + _DAT_140b7a8c0 * fStack_744 +
               _UNK_140b7a8c8 * fStack_724;
  fStack_5c0 = _UNK_140b7a8c4 * fStack_730 + _DAT_140b7a8c0 * fStack_740 +
               _UNK_140b7a8c8 * fStack_720;
  fStack_5bc = _UNK_140b7a8c4 * fStack_72c + _DAT_140b7a8c0 * fStack_73c +
               _UNK_140b7a8c8 * fStack_71c;
  fVar41 = fStack_5c4 * fStack_5c4;
  auVar36._4_4_ = fVar41;
  auVar36._0_4_ = fVar41;
  auVar36._8_4_ = fVar41;
  auVar36._12_4_ = fVar41;
  fVar42 = local_5c8 * local_5c8 + fVar41 + fStack_5c0 * fStack_5c0;
  auVar37._4_4_ = fVar41;
  auVar37._0_4_ = fVar42;
  auVar37._8_4_ = fStack_5c0 * fStack_5c0;
  auVar37._12_4_ = fStack_5bc * fStack_5bc;
  auVar37 = rsqrtss(auVar36,auVar37);
  fStack_5dc = auVar37._0_4_;
  fStack_5dc = (DAT_140b79fa0 - fVar42 * fStack_5dc * fStack_5dc) * DAT_140b79e48 * fStack_5dc;
  if (fStack_5dc <= 0.0) {
    fStack_5dc = 0.0;
  }
  fVar41 = fStack_5dc * local_5c8;
  fVar42 = fStack_5dc * fStack_5c4;
  fVar44 = fStack_5dc * fStack_5c0;
  fStack_5dc = fStack_5dc * fStack_5bc;
  uVar20 = uVar23;
  if ((int)param_1[0xa6] != -1) {
    do {
      *(int *)(DAT_140c79de8 + uVar20 * 4) = (int)uVar20;
      uVar19 = (int)uVar20 + 1;
      uVar20 = (ulonglong)uVar19;
    } while (uVar19 < (int)param_1[0xa6] + 1U);
  }
  local_7a8 = _DAT_140b7a700;
  uStack_7a0 = _UNK_140b7a708;
  local_5e8 = fVar41;
  fStack_5e4 = fVar42;
  fStack_5e0 = fVar44;
  FUN_140262900(param_8,&local_8c8,&local_7a8);
  fVar9 = DAT_140b79ed0;
  fVar8 = DAT_140b79ce0;
  plVar2 = param_1 + 0xa3;
  lVar31 = *plVar2;
  iVar12 = *(int *)(param_1[0xb2] + 0x18);
  uVar19 = *(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5];
  iVar13 = *(int *)((ulonglong)uVar19 + 0x18 + lVar31);
  fVar43 = DAT_140b79ed0;
  if (iVar13 != iVar12) {
    uVar1 = *(ushort *)(param_1[0x9d] + 0x26);
    fVar43 = (float)(int)((uint)uVar1 - iVar13) * (DAT_140b79ed0 / (float)uVar1);
    fVar33 = (DAT_140b79ed0 - fVar43) /
             ((float)(int)((uint)uVar1 - iVar12) * (DAT_140b79ed0 / (float)uVar1) - fVar43);
    if (DAT_140b79ed0 <= fVar33) {
      fVar33 = DAT_140b79ed0;
    }
    fVar43 = 0.0;
    if (0.0 <= fVar33) {
      fVar43 = fVar33;
    }
  }
  fVar40 = (*(float *)(param_1[0xb2] + 0xc) - *(float *)((ulonglong)uVar19 + 0xc + lVar31)) * fVar43
           + *(float *)((ulonglong)uVar19 + 0xc + lVar31);
  *(float *)(param_1 + 0xa2) = fVar40;
  fVar33 = *(float *)(param_1[0xb1] + 0xc) - fVar40;
  if (fVar8 < fVar33) {
LAB_140324327:
    fVar33 = fVar9 / fVar33;
  }
  else {
    iVar12 = *(int *)((longlong)param_1 + 0x52c);
    if (iVar12 == 0) {
      iVar12 = (int)param_1[0xa4];
    }
    fVar33 = *(float *)((ulonglong)(uint)((iVar12 + -1) * *(int *)((longlong)param_1 + 0x524)) + 0xc
                       + *plVar2) - fVar40;
    if (fVar8 < fVar33) goto LAB_140324327;
    fVar33 = 0.0;
  }
  lVar31 = param_1[0x9d];
  *(float *)((longlong)param_1 + 0x514) = fVar33;
  if (*(char *)(lVar31 + 4) == '\0') {
    iVar12 = (int)param_1[0xa6] + 2;
    local_8b4 = iVar12 * 3;
    local_8b8 = 3;
    if (*(short *)(lVar31 + 0x404) == 0) {
      uVar22 = 10;
      iVar12 = iVar12 * 0x48;
    }
    else {
      uVar22 = 0xb;
      iVar12 = iVar12 * 0x6c;
    }
    local_878 = (**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,iVar12,uVar22);
    if (local_878 == 0) {
      return;
    }
    local_870 = (float *)0x0;
    auVar5._12_4_ = 0;
    local_848 = (float *)0x0;
    local_858 = local_8c8;
    uStack_850 = puStack_8c0;
    if ((*(short *)(param_1[1] + 0x18) == 0) ||
       (local_83c = 1, *(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_83c = 0;
    }
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb2];
      local_638 = pfVar29[0x14] - local_718;
      fStack_634 = pfVar29[0x15] - local_714;
      fStack_630 = pfVar29[0x16] - local_710;
      fStack_62c = pfVar29[0x17] - 0.0;
      *pfVar29 = local_638 * fVar41 + fStack_634 * fVar42 + fStack_630 * fVar44;
      *DAT_140c79df8 = *(undefined4 *)param_1[0xb2];
    }
    if ((*(short *)(param_1[1] + 0x18) == 0) || (*(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_8d0 = &local_7b8;
      local_7b8 = _DAT_140b7b240;
      uStack_7b0 = _DAT_140b7b248;
      uVar19 = (int)param_1[0xa5] * *(int *)((longlong)param_1 + 0x524);
    }
    else {
      local_8d0 = &local_8c8;
      uVar19 = *(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5];
    }
    local_8e8 = (float **)&local_848;
    local_8f0 = local_898;
    local_8f8 = CONCAT44(local_8f8._4_4_,fVar43);
    local_8d8 = fVar45;
    local_868 = auVar5;
    local_840 = fVar45;
    FUN_140321360(param_1,&local_878,(ulonglong)uVar19 + *plVar2);
    fVar8 = DAT_140b7a204;
    uVar35 = local_898._0_4_;
    uVar10 = local_898._4_4_;
    fVar33 = (float)uStack_890;
    fVar40 = uStack_890._4_4_;
    iVar12 = (int)param_1[0xa5];
    fVar45 = (float)((int)(longlong)
                          ((float)(*(int *)(param_1[0xb2] + 0x18) -
                                  *(int *)((ulonglong)
                                           (uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) +
                                           0x18 + *plVar2)) * fVar43) +
                    *(int *)((ulonglong)(uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) + 0x18
                            + *plVar2));
    uVar20 = (ulonglong)(uint)fVar45;
    uVar19 = 3;
    local_8b0 = uVar20;
    if ((int)param_1[0xa6] != 0) {
      do {
        pfVar29 = (float *)((ulonglong)(uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) +
                           *plVar2);
        if (*(int *)((longlong)param_1 + 0x54c) != 0) {
          local_618 = pfVar29[0x14] - (float)uVar35;
          fStack_614 = pfVar29[0x15] - (float)uVar10;
          fStack_610 = pfVar29[0x16] - fVar33;
          fStack_60c = pfVar29[0x17] - fVar40;
          fVar45 = local_618 * fVar41 + fStack_614 * fVar42 + fStack_610 * fVar44;
          *pfVar29 = fVar45;
          DAT_140c79df8[(int)uVar23 + 1] = fVar45;
        }
        local_870 = pfVar29;
        if (*(char *)param_1[0x9d] == '\0') {
          iVar13 = *DAT_140c63750;
          fVar45 = (float)FUN_1408fe170();
          iVar25 = DAT_140c42240;
          if (iVar13 < DAT_140c42240) {
            iVar25 = iVar13;
          }
          uVar34 = FUN_1408fc7f0(&PTR_PTR_140c42230,
                                 fVar45 * *(float *)(&DAT_140c42250 + (longlong)iVar25 * 4) *
                                 (float)(uint)((int)pfVar29[6] - (int)uVar20) * fVar8);
          local_848 = (float *)CONCAT44(uVar34,(undefined4)local_848);
        }
        FUN_1403220c0(param_1,&local_878);
        fVar45 = pfVar29[6];
        uVar20 = (ulonglong)(uint)fVar45;
        iVar12 = iVar12 + 1;
        if (iVar12 == (int)param_1[0xa4]) {
          iVar12 = 0;
        }
        uVar28 = (int)uVar23 + 1;
        uVar23 = (ulonglong)uVar28;
        uVar19 = local_8b8;
      } while (uVar28 < *(uint *)(param_1 + 0xa6));
    }
    local_8b0 = uVar20;
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb1];
      local_5f8 = pfVar29[0x14] - (float)uVar35;
      fStack_5f4 = pfVar29[0x15] - (float)uVar10;
      fStack_5f0 = pfVar29[0x16] - fVar33;
      fStack_5ec = pfVar29[0x17] - fVar40;
      *pfVar29 = local_5f8 * fVar41 + fStack_5f4 * fVar42 + fStack_5f0 * fVar44;
      DAT_140c79df8[(int)param_1[0xa6] + 1] = *(undefined4 *)param_1[0xb1];
    }
    if (*(char *)param_1[0x9d] == '\0') {
      iVar12 = *DAT_140c63750;
      auVar38._0_8_ = FUN_1408fe170();
      auVar38._8_8_ = extraout_XMM0_Qb;
      iVar13 = DAT_140c42240;
      if (iVar12 < DAT_140c42240) {
        iVar13 = iVar12;
      }
      auVar39._4_12_ = auVar38._4_12_;
      auVar39._0_4_ =
           (float)auVar38._0_8_ * *(float *)(&DAT_140c42250 + (longlong)iVar13 * 4) *
           (float)(uint)(*(int *)(param_1[0xb1] + 0x18) - (int)fVar45) * fVar8;
      uVar35 = FUN_1408fc7f0(auVar39._0_8_);
      local_848 = (float *)CONCAT44(uVar35,(undefined4)local_848);
    }
    local_870 = (float *)param_1[0xb1];
    FUN_1403220c0(param_1,&local_878);
    (**(code **)(*DAT_140c65670 + 0xe8))();
  }
  else {
    uVar19 = *(uint *)((longlong)param_1 + 0x55c);
    local_8b4 = ((int)param_1[0xa6] + 2) * uVar19;
    if (*(short *)(lVar31 + 0x404) == 0) {
      uVar22 = 10;
      iVar12 = local_8b4 * 0x18;
    }
    else {
      uVar22 = 0xb;
      iVar12 = local_8b4 * 0x24;
    }
    local_828 = (**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,iVar12,uVar22);
    if (local_828 == 0) {
      return;
    }
    local_820 = (float *)0x0;
    local_818 = local_8c8;
    uStack_810 = puStack_8c0;
    if ((*(short *)(param_1[1] + 0x18) == 0) ||
       (local_804 = 1, *(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_804 = 0;
    }
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb2];
      local_5d8 = pfVar29[0x14] - local_718;
      fStack_5d4 = pfVar29[0x15] - local_714;
      fStack_5d0 = pfVar29[0x16] - local_710;
      fStack_5cc = pfVar29[0x17] - 0.0;
      *pfVar29 = local_5d8 * fVar41 + fStack_5d4 * fVar42 + fStack_5d0 * fVar44;
      *DAT_140c79df8 = *(undefined4 *)param_1[0xb2];
    }
    if ((*(short *)(param_1[1] + 0x18) == 0) || (*(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_8e8 = &local_758;
      local_758 = _DAT_140b7b240;
      uStack_750 = _DAT_140b7b248;
    }
    else {
      local_8e8 = &local_8c8;
    }
    local_8f0 = (undefined1 *)CONCAT44(local_8f0._4_4_,fVar45);
    local_8f8 = CONCAT44(local_8f8._4_4_,fVar43);
    local_808 = fVar45;
    FUN_140322ce0(param_1,&local_828,
                  (ulonglong)(uint)((int)param_1[0xa5] * *(int *)((longlong)param_1 + 0x524)) +
                  *plVar2);
    iVar12 = (int)param_1[0xa5];
    if ((int)param_1[0xa6] != 0) {
      do {
        local_820 = (float *)((ulonglong)(uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) +
                             *plVar2);
        if (*(int *)((longlong)param_1 + 0x54c) != 0) {
          local_648 = local_820[0x14] - local_718;
          fStack_644 = local_820[0x15] - local_714;
          fStack_640 = local_820[0x16] - local_710;
          fStack_63c = local_820[0x17] - 0.0;
          fVar45 = local_648 * fVar41 + fStack_644 * fVar42 + fStack_640 * fVar44;
          *local_820 = fVar45;
          DAT_140c79df8[(int)uVar23 + 1] = fVar45;
        }
        FUN_140323590(param_1,&local_828);
        iVar12 = iVar12 + 1;
        if (iVar12 == (int)param_1[0xa4]) {
          iVar12 = 0;
        }
        uVar28 = (int)uVar23 + 1;
        uVar23 = (ulonglong)uVar28;
      } while (uVar28 < *(uint *)(param_1 + 0xa6));
    }
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb1];
      local_5b8 = pfVar29[0x14] - local_718;
      fStack_5b4 = pfVar29[0x15] - local_714;
      fStack_5b0 = pfVar29[0x16] - local_710;
      fStack_5ac = pfVar29[0x17] - 0.0;
      *pfVar29 = local_5b8 * fVar41 + fStack_5b4 * fVar42 + fStack_5b0 * fVar44;
      *DAT_140c79df8 = *(undefined4 *)param_1[0xb1];
    }
    local_820 = (float *)param_1[0xb1];
    FUN_140323590(param_1,&local_828);
    (**(code **)(*DAT_140c65670 + 0xe8))();
  }
  uVar23 = 0;
  if (*(int *)((longlong)param_1 + 0x54c) != 0) {
    FUN_1401c3280(&LAB_14031ce60,DAT_140c79de8,(int)param_1[0xa6] + 1);
  }
  sVar7 = (short)uVar19;
  if (*(char *)(param_1[0x9d] + 4) == '\x02') {
    iVar12 = (uVar19 - 2) * ((int)param_1[0xa6] + 1);
    local_8b8 = iVar12 * 6;
    psVar14 = (short *)(**(code **)(*DAT_140c65670 + 0xf0))(DAT_140c65670,iVar12 * 0xc);
    if (psVar14 == (short *)0x0) {
      return;
    }
    uVar28 = *(uint *)(param_1 + 0xa5);
    if ((int)param_1[0xa6] != -1) {
      uVar19 = uVar19 >> 1;
      uVar20 = uVar23;
      do {
        lVar31 = 2;
        uVar27 = uVar23;
        do {
          psVar21 = psVar14;
          uVar26 = uVar23;
          if (uVar19 != 1) {
            do {
              sVar11 = (short)uVar27;
              sVar6 = (short)uVar26;
              sVar17 = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4);
              if (((int)uVar26 + (int)uVar20 & 1U) == 1 - (uVar28 & 1)) {
                *psVar21 = sVar17 * sVar7 + sVar11 + sVar6;
                psVar21[1] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 +
                             sVar11 + sVar6;
                psVar21[2] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + 1 + sVar11
                             + sVar6;
                psVar21[3] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + 1 + sVar11
                             + sVar6;
                psVar21[4] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 +
                             sVar11 + sVar6;
                sVar17 = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1;
              }
              else {
                *psVar21 = (sVar17 + 1) * sVar7 + sVar11 + sVar6;
                psVar21[1] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + sVar11 +
                             sVar6;
                psVar21[2] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 + 1 +
                             sVar11 + sVar6;
                psVar21[3] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 + 1 +
                             sVar11 + sVar6;
                psVar21[4] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + sVar11 +
                             sVar6;
                sVar17 = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4);
              }
              uVar24 = (int)uVar26 + 1;
              psVar14 = psVar21 + 6;
              psVar21[5] = sVar6 + 1 + sVar17 * sVar7 + sVar11;
              psVar21 = psVar14;
              uVar26 = (ulonglong)uVar24;
            } while (uVar24 < uVar19 - 1);
          }
          uVar27 = (ulonglong)((int)uVar27 + uVar19);
          lVar31 = lVar31 + -1;
        } while (lVar31 != 0);
        uVar24 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar24;
      } while (uVar24 < (int)param_1[0xa6] + 1U);
    }
    (**(code **)(*DAT_140c65670 + 0xf8))();
  }
  else {
    uVar28 = uVar19 - 1;
    iVar12 = ((int)param_1[0xa6] + 1) * uVar28;
    local_8b8 = iVar12 * 6;
    psVar14 = (short *)(**(code **)(*DAT_140c65670 + 0xf0))(DAT_140c65670,iVar12 * 0xc,0);
    if (psVar14 == (short *)0x0) {
      return;
    }
    uVar24 = *(uint *)(param_1 + 0xa5);
    uVar30 = 0;
    if ((int)param_1[0xa6] != -1) {
      do {
        iVar12 = *(int *)(DAT_140c79de8 + (ulonglong)uVar30 * 4) * uVar19;
        if (uVar28 != 0) {
          iVar13 = uVar19 + 1;
          sVar6 = (short)iVar13;
          iVar25 = iVar13 + iVar12;
          uVar23 = (ulonglong)uVar28;
          do {
            sVar17 = (short)iVar25;
            if ((((uVar30 - iVar13) - iVar12) + iVar25 & 1) == 1 - (uVar24 & 1)) {
              sVar18 = sVar17 + (sVar7 - sVar6);
              *psVar14 = sVar17 + -sVar6;
              psVar14[1] = sVar18;
              sVar11 = sVar17 + (1 - sVar6);
              psVar14[2] = sVar11;
              psVar14[3] = sVar11;
              psVar14[4] = sVar18;
              psVar14[5] = sVar17;
            }
            else {
              *psVar14 = sVar17 + (sVar7 - sVar6);
              sVar11 = sVar17 + -sVar6;
              psVar14[1] = sVar11;
              psVar14[2] = sVar17;
              psVar14[3] = sVar17;
              psVar14[4] = sVar11;
              psVar14[5] = sVar17 + (1 - sVar6);
            }
            psVar14 = psVar14 + 6;
            iVar25 = iVar25 + 1;
            uVar23 = uVar23 - 1;
          } while (uVar23 != 0);
        }
        uVar30 = uVar30 + 1;
      } while (uVar30 < (int)param_1[0xa6] + 1U);
    }
    (**(code **)(*DAT_140c65670 + 0xf8))();
  }
  if ((*(byte *)(param_1[0x9d] + 0x28) & 1) == 0) {
    fVar41 = *(float *)((longlong)param_1 + 0x574);
    if (fVar41 <= fVar9) {
      if (DAT_140b7a23c <= fVar41) goto LAB_140324d33;
      fVar41 = fVar41 + fVar9;
    }
    else {
      fVar41 = fVar41 - fVar9;
    }
    *(float *)((longlong)param_1 + 0x574) = fVar41;
  }
  else {
    fVar41 = *(float *)((longlong)param_1 + 0x574);
    fVar42 = *(float *)(param_1[0xb1] + 0xc) - *(float *)(param_1 + 0xa2);
    if (fVar41 <= fVar42) {
      if (fVar41 < fVar42 * DAT_140b7a23c) {
        *(float *)((longlong)param_1 + 0x574) = fVar41 + fVar42;
      }
    }
    else {
      *(float *)((longlong)param_1 + 0x574) = fVar41 - fVar42;
    }
  }
LAB_140324d33:
  uVar1 = *(ushort *)(param_1[0x9d] + 0x3c4);
  if ((uint)uVar1 < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,0,
               *(undefined8 *)(*(longlong *)(param_1[5] + 0x420) + 0x10 + (ulonglong)uVar1 * 0x18));
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,0);
  }
  if ((uint)*(ushort *)(param_1[0x9d] + 0x3dc) < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)
     ) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,1,
               *(undefined8 *)
                (*(longlong *)(param_1[5] + 0x420) + 0x10 +
                (ulonglong)*(ushort *)(param_1[0x9d] + 0x3dc) * 0x18));
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,1,0);
  }
  if ((uint)*(ushort *)(param_1[0x9d] + 0x3de) < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)
     ) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,2,
               *(undefined8 *)
                (*(longlong *)(param_1[5] + 0x420) + 0x10 +
                (ulonglong)*(ushort *)(param_1[0x9d] + 0x3de) * 0x18),0);
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,2,0,0);
  }
  if ((uint)*(ushort *)(param_1[0x9d] + 0x406) < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)
     ) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,4,
               *(undefined8 *)
                (*(longlong *)(param_1[5] + 0x420) + 0x10 +
                (ulonglong)*(ushort *)(param_1[0x9d] + 0x406) * 0x18));
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,4);
  }
  (**(code **)(*DAT_140c65670 + 0x1d0))
            (DAT_140c65670,(int)param_1[0xaa],*(undefined4 *)((longlong)param_1 + 0x554),
             (int)param_1[0xab]);
  (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,*(undefined4 *)(param_1[1] + 0x24));
  uVar22 = 7;
  if (*(int *)(param_1[1] + 0x20) != 0) {
    uVar22 = 1;
  }
  (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,uVar22);
  (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,0);
  (**(code **)(*DAT_140c65670 + 0x140))
            (DAT_140c65670,
             *(undefined8 *)(*(longlong *)(*(longlong *)(param_1[5] + 0x10) + 0x10) + 0x838),
             (*(uint *)(param_1[0x9d] + 0x28) & 1) +
             ((uint)(*(short *)(param_1[1] + 0x18) == 2) +
             (uint)*(ushort *)(param_1[0x9d] + 0x404) * 2) * 2);
  local_8f8 = local_8f8 & 0xffffffff00000000;
  puVar15 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x100,0);
  lVar31 = local_888;
  if (puVar15 != (undefined4 *)0x0) {
    local_328 = &local_7f8;
    uStack_890 = param_6;
    local_898 = (undefined1  [8])local_328;
    local_320 = param_6;
    FUN_1401afb10(&local_328,&local_708);
    lVar31 = local_888;
    *puVar15 = local_708;
    puVar15[1] = local_6f8;
    puVar15[2] = local_6e8;
    puVar15[3] = local_6d8;
    puVar15[4] = uStack_704;
    puVar15[5] = uStack_6f4;
    puVar15[6] = uStack_6e4;
    puVar15[7] = uStack_6d4;
    puVar15[8] = uStack_700;
    puVar15[9] = uStack_6f0;
    puVar15[10] = uStack_6e0;
    puVar15[0xb] = uStack_6d0;
    puVar15[0xc] = uStack_6fc;
    puVar15[0xd] = uStack_6ec;
    puVar15[0xe] = uStack_6dc;
    puVar15[0xf] = uStack_6cc;
    puVar15[0x10] = (undefined4)local_7f8;
    puVar15[0x11] = (undefined4)local_7e8;
    puVar15[0x12] = (undefined4)local_7d8;
    puVar15[0x13] = (undefined4)local_7c8;
    puVar15[0x14] = local_7f8._4_4_;
    puVar15[0x15] = local_7e8._4_4_;
    puVar15[0x16] = local_7d8._4_4_;
    puVar15[0x17] = local_7c8._4_4_;
    puVar15[0x18] = (undefined4)uStack_7f0;
    puVar15[0x19] = (undefined4)uStack_7e0;
    puVar15[0x1a] = (undefined4)uStack_7d0;
    puVar15[0x1b] = (undefined4)uStack_7c0;
    puVar15[0x1c] = uStack_7f0._4_4_;
    puVar15[0x1d] = uStack_7e0._4_4_;
    puVar15[0x1e] = uStack_7d0._4_4_;
    puVar15[0x1f] = uStack_7c0._4_4_;
    puVar15[0x20] = (int)param_1[0xa2];
    puVar15[0x21] = *(undefined4 *)((longlong)param_1 + 0x514);
    lVar3 = param_1[0x9f];
    *(longlong *)(puVar15 + 0x24) = param_1[0x9e];
    *(longlong *)(puVar15 + 0x26) = lVar3;
    lVar3 = param_1[0xa1];
    *(longlong *)(puVar15 + 0x28) = param_1[0xa0];
    *(longlong *)(puVar15 + 0x2a) = lVar3;
    lVar3 = param_1[0x9d];
    if (((*(uint *)(lVar3 + 0x28) & 5) == 0) || ((*(uint *)(lVar3 + 0x28) >> 9 & 1) == 0)) {
      local_8b0 = 0;
      uStack_8a8 = 0x3f800000;
      uStack_8a4 = 0x3f800000;
      *(undefined8 *)(puVar15 + 0x2c) = 0;
      *(undefined8 *)(puVar15 + 0x2e) = 0x3f8000003f800000;
    }
    else {
      fVar41 = *(float *)(lVar3 + 0x3ec);
      fVar42 = *(float *)(lVar3 + 0x3f0);
      uVar19 = *(uint *)((longlong)param_1 + 0x57c);
      bVar16 = (byte)*(undefined4 *)(lVar3 + 0x3f4);
      puVar15[0x2c] = (float)((1 << (bVar16 & 0x1f)) - 1U & uVar19) * fVar41;
      puVar15[0x2d] = (float)(uVar19 >> (bVar16 & 0x1f)) * fVar42;
      puVar15[0x2e] = fVar41;
      puVar15[0x2f] = fVar42;
    }
    uVar22 = *(undefined8 *)(local_888 + 0xb8);
    *(undefined8 *)(puVar15 + 0x30) = *(undefined8 *)(local_888 + 0xb0);
    *(undefined8 *)(puVar15 + 0x32) = uVar22;
    FUN_140262750(local_888,puVar15 + 0x34,local_880);
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  bVar32 = (param_10 & 0x224) != 0;
  lVar3 = param_1[1];
  if ((*(int *)(lVar3 + 0x14) == 0) ||
     (iVar12 = 1, (**(byte **)(*(longlong *)(param_1[5] + 0x10) + 0x10) & 1) != 0)) {
    iVar12 = 0;
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,
             *(undefined8 *)(*(longlong *)(*(longlong *)(param_1[5] + 0x10) + 0x10) + 0x840),
             *(int *)(lVar3 + 0x1c) +
             (iVar12 + ((~param_12 & 1) +
                       ((uint)(0.0 < *(float *)(lVar31 + 0x2f4)) +
                       (uint)(*(int *)(lVar3 + 0x20) != 0) * 2 +
                       ((uint)*(ushort *)(param_1[0x9d] + 0x3cc) * 2 +
                       ((uint)*(ushort *)(lVar3 + 0x18) +
                       ((uint)bVar32 + (uint)*(ushort *)(param_1[0x9d] + 0x404) + (uint)bVar32 * 2)
                       * 3) * 10) * 2) * 2) * 2) * 4);
  local_8f8 = local_8f8 & 0xffffffff00000000;
  puVar15 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x130,0,0);
  if (puVar15 != (undefined4 *)0x0) {
    *puVar15 = *(undefined4 *)(param_1[0x9d] + 0x3d0);
    fVar41 = *(float *)(param_1[0x9d] + 0x3d4) - *(float *)(param_1[0x9d] + 0x3d0);
    if (fVar41 == 0.0) {
      fVar41 = 0.0;
    }
    else {
      fVar41 = fVar9 / fVar41;
    }
    puVar15[1] = fVar41;
    puVar15[2] = *(undefined4 *)(param_1[0x9d] + 0x400);
    *(undefined8 *)(puVar15 + 4) = *(undefined8 *)(*(longlong *)(param_1[5] + 0x10) + 0x550);
    lVar3 = *(longlong *)(param_1[5] + 0x10);
    local_788 = *(float *)(lVar3 + 0x550) * _DAT_140b7ac50;
    fStack_784 = *(float *)(lVar3 + 0x554) * _UNK_140b7ac54;
    fStack_780 = *(float *)(lVar3 + 0x558) * _UNK_140b7ac58;
    fStack_77c = *(float *)(lVar3 + 0x55c) * _UNK_140b7ac5c;
    *(ulonglong *)(puVar15 + 6) = CONCAT44(fStack_784,local_788);
    fVar41 = local_838[1];
    auVar4._4_4_ = *local_838 - fVar41;
    auVar4._0_4_ = *local_838 * fVar41;
    auVar4._8_4_ = fVar41;
    auVar4._12_4_ = 0;
    *(undefined1 (*) [16])(puVar15 + 8) = auVar4;
    lVar3 = param_1[5];
    if (*(float *)(lVar3 + 0x10c) == 0.0) {
      pfVar29 = (float *)&local_778;
      local_778 = _DAT_140b7a740;
      uStack_770 = _UNK_140b7a748;
    }
    else {
      pfVar29 = (float *)&local_768;
      local_768 = *(undefined8 *)(lVar3 + 0x100);
      uStack_760 = *(undefined8 *)(lVar3 + 0x108);
    }
    fVar41 = *(float *)(param_1 + 0xc);
    fVar42 = pfVar29[1];
    fVar45 = pfVar29[2];
    fVar44 = pfVar29[3];
    puVar15[0x48] = *pfVar29 * fVar41;
    puVar15[0x49] = fVar42 * fVar41;
    puVar15[0x4a] = fVar45 * fVar41;
    puVar15[0x4b] = fVar44 * fVar41;
    FUN_140262d50(lVar31,puVar15 + 0xc);
    uVar22 = *(undefined8 *)(lVar31 + 0xb8);
    *(undefined8 *)(puVar15 + 0x28) = *(undefined8 *)(lVar31 + 0xb0);
    *(undefined8 *)(puVar15 + 0x2a) = uVar22;
    puVar15[0x2c] = *(undefined4 *)(lVar31 + 0x90);
    puVar15[0x2d] = *(undefined4 *)(lVar31 + 0x94);
    puVar15[0x2e] = *(undefined4 *)(lVar31 + 0x98);
    puVar15[0x2f] = *(undefined4 *)(lVar31 + 0x2b4);
    puVar15[0x30] = *(undefined4 *)(lVar31 + 0xa0);
    puVar15[0x31] = *(undefined4 *)(lVar31 + 0xa4);
    puVar15[0x32] = *(undefined4 *)(lVar31 + 0xa8);
    puVar15[0x33] = *(undefined4 *)(lVar31 + 0x2b0);
    FUN_140262750();
    uVar22 = *(undefined8 *)(*(longlong *)(param_1[5] + 0x10) + 0x568);
    *(undefined8 *)(puVar15 + 0x40) = *(undefined8 *)(*(longlong *)(param_1[5] + 0x10) + 0x560);
    *(undefined8 *)(puVar15 + 0x42) = uVar22;
    puVar15[0x44] = *(undefined4 *)(param_11 + 0x2c);
    fVar41 = DAT_140b7a1cc;
    if (DAT_140b79cc4 < (float)((uint)*(float *)(param_1[1] + 0x88) & DAT_140b7b500)) {
      fVar41 = fVar9 / *(float *)(param_1[1] + 0x88);
    }
    puVar15[0x45] = fVar41;
    puVar15[0x46] = *(undefined4 *)(param_1[0x9d] + 0x3d8);
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  local_8e0 = 1;
  local_8e8 = (float **)((ulonglong)local_8e8 & 0xffffffff00000000);
  local_8f0 = (undefined1 *)CONCAT44(local_8f0._4_4_,local_8b4);
  local_8f8 = local_8f8 & 0xffffffff00000000;
  (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,0,local_8b8);
  return;
}



==== FUN_1402ea750 @ 1402ea750 size 828 ====
CALLERS: FUN_1402ea5b0
CALLEES: FUN_1407e4830

longlong FUN_1402ea750(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  FUN_1407e4830(param_1 + 0x20,0,0x60);
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  FUN_1407e4830(param_1 + 0x90,0,0x60);
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x130) = 0;
  *(undefined8 *)(param_1 + 0x138) = 0;
  *(undefined8 *)(param_1 + 0x140) = 0;
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(undefined8 *)(param_1 + 0x160) = 0;
  *(undefined8 *)(param_1 + 0x168) = 0;
  *(undefined8 *)(param_1 + 0x170) = 0;
  *(undefined8 *)(param_1 + 0x180) = 0;
  *(undefined8 *)(param_1 + 0x188) = 0;
  *(undefined8 *)(param_1 + 400) = 0;
  *(undefined8 *)(param_1 + 0x198) = 0;
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  *(undefined8 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1b0) = 0;
  *(undefined8 *)(param_1 + 0x1b8) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1d8) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0;
  *(undefined8 *)(param_1 + 0x1f0) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = 0;
  *(undefined8 *)(param_1 + 0x200) = 0;
  *(undefined8 *)(param_1 + 0x208) = 0;
  *(undefined8 *)(param_1 + 0x210) = 0;
  *(undefined8 *)(param_1 + 0x218) = 0;
  *(undefined8 *)(param_1 + 0x220) = 0;
  *(undefined8 *)(param_1 + 0x228) = 0;
  *(undefined8 *)(param_1 + 0x230) = 0;
  *(undefined8 *)(param_1 + 0x238) = 0;
  *(undefined8 *)(param_1 + 0x240) = 0;
  *(undefined8 *)(param_1 + 0x248) = 0;
  *(undefined8 *)(param_1 + 0x250) = 0;
  *(undefined8 *)(param_1 + 600) = 0;
  *(undefined8 *)(param_1 + 0x260) = 0;
  *(undefined8 *)(param_1 + 0x268) = 0;
  *(undefined8 *)(param_1 + 0x270) = 0;
  *(undefined8 *)(param_1 + 0x278) = 0;
  *(undefined8 *)(param_1 + 0x280) = 0;
  *(undefined8 *)(param_1 + 0x288) = 0;
  *(undefined8 *)(param_1 + 0x290) = 0;
  *(undefined8 *)(param_1 + 0x298) = 0;
  *(undefined8 *)(param_1 + 0x2a0) = 0;
  *(undefined8 *)(param_1 + 0x2a8) = 0;
  *(undefined8 *)(param_1 + 0x2b0) = 0;
  *(undefined8 *)(param_1 + 0x2b8) = 0;
  *(undefined8 *)(param_1 + 0x2c0) = 0;
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  *(undefined8 *)(param_1 + 0x2d0) = 0;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined8 *)(param_1 + 0x2e0) = 0;
  *(undefined8 *)(param_1 + 0x2e8) = 0;
  *(undefined8 *)(param_1 + 0x2f0) = 0;
  *(undefined8 *)(param_1 + 0x2f8) = 0;
  *(undefined8 *)(param_1 + 0x300) = 0;
  *(undefined8 *)(param_1 + 0x308) = 0;
  *(undefined8 *)(param_1 + 0x310) = 0;
  *(undefined8 *)(param_1 + 0x318) = 0;
  *(undefined8 *)(param_1 + 800) = 0;
  *(undefined8 *)(param_1 + 0x328) = 0;
  *(undefined8 *)(param_1 + 0x330) = 0;
  *(undefined8 *)(param_1 + 0x338) = 0;
  *(undefined8 *)(param_1 + 0x340) = 0;
  *(undefined8 *)(param_1 + 0x350) = 0;
  *(undefined8 *)(param_1 + 0x358) = 0;
  *(undefined8 *)(param_1 + 0x360) = 0;
  *(undefined8 *)(param_1 + 0x370) = 0;
  *(undefined8 *)(param_1 + 0x378) = 0;
  *(undefined8 *)(param_1 + 0x380) = 0;
  *(undefined8 *)(param_1 + 0x490) = 0;
  *(undefined8 *)(param_1 + 0x498) = 0;
  *(undefined8 *)(param_1 + 0x4a0) = 0;
  *(undefined8 *)(param_1 + 0x4a8) = 0;
  *(undefined8 *)(param_1 + 0x510) = 0;
  *(undefined8 *)(param_1 + 0x518) = 0;
  *(undefined8 *)(param_1 + 0x520) = 0;
  *(undefined8 *)(param_1 + 0x528) = 0;
  *(undefined8 *)(param_1 + 0x530) = 0;
  *(undefined8 *)(param_1 + 0x538) = 0;
  *(undefined8 *)(param_1 + 0x540) = 0;
  *(undefined8 *)(param_1 + 0x548) = 0;
  *(undefined8 *)(param_1 + 0x550) = 0;
  *(undefined8 *)(param_1 + 0x558) = 0;
  *(undefined8 *)(param_1 + 0x560) = 0;
  *(undefined8 *)(param_1 + 0x568) = 0;
  *(undefined8 *)(param_1 + 0x570) = 0;
  *(undefined8 *)(param_1 + 0x578) = 0;
  *(undefined8 *)(param_1 + 0x588) = 0;
  *(undefined8 *)(param_1 + 0x590) = 0;
  *(undefined8 *)(param_1 + 0x598) = 0;
  *(undefined8 *)(param_1 + 0x5a0) = 0;
  *(undefined8 *)(param_1 + 0x5a8) = 0;
  *(undefined8 *)(param_1 + 0x5b0) = 0;
  *(undefined8 *)(param_1 + 0x5c0) = 0;
  *(undefined8 *)(param_1 + 0x5c8) = 0;
  *(undefined8 *)(param_1 + 0x5d0) = 0;
  return param_1;
}


