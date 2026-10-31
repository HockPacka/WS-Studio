
==== FUN_14030c6a0 @ 14030c6a0 size 294 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030c3d0 FUN_14030ed20 FUN_14030eb90 FUN_14030bcc0

undefined8 FUN_14030c6a0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = param_2;
  uVar2 = FUN_14030ed20(param_1,param_2,param_3 + 0x38);
  if (-1 < (int)uVar2) {
    uVar2 = FUN_14030eb90(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (*(longlong *)(param_3 + 0x90) == -1) {
      *(undefined8 *)(param_3 + 0x90) = 0;
    }
    else {
      uVar1 = *(longlong *)(param_3 + 0x90) + lVar3;
      if (uVar1 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < uVar1 + 0xed0) {
        return 0x80004005;
      }
      *(ulonglong *)(param_3 + 0x90) = uVar1;
      uVar2 = FUN_14030bcc0(param_1,uVar1 + 0xed0,param_1[2] + uVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    if (*(longlong *)(param_3 + 0x98) == -1) {
      *(undefined8 *)(param_3 + 0x98) = 0;
    }
    else {
      uVar1 = *(longlong *)(param_3 + 0x98) + param_2;
      if ((uVar1 < *param_1) || (param_1[1] < uVar1 + 0x4a8)) {
        return 0x80004005;
      }
      *(ulonglong *)(param_3 + 0x98) = uVar1;
      uVar2 = FUN_14030c3d0(param_1,uVar1 + 0x4b0,param_1[2] + uVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



==== FUN_14030bcc0 @ 14030bcc0 size 1803 ====
CALLERS: FUN_14030c6a0
CALLEES: FUN_1402ca3c0 FUN_14030ed20 FUN_14030eb90 FUN_14030ebf0 FUN_14030ba20 FUN_14030eb00

undefined8 FUN_14030bcc0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar3;
  
  uVar1 = FUN_14030ba20(param_1,param_2,param_3 + 8);
  if ((((((((-1 < (int)uVar1) &&
           (uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x68), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
         ((uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1 &&
          (uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1)))) &&
        (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
       (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
         (uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1)) &&
        ((uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1 &&
         (((uVar1 = FUN_14030ebf0(param_1), -1 < (int)uVar1 &&
           (uVar1 = FUN_14030ebf0(param_1,param_2,param_3 + 0x140), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x158), -1 < (int)uVar1)))))))) &&
      ((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
       (uVar1 = FUN_14030ebf0(param_1), -1 < (int)uVar1)))) &&
     (((uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x1a0), -1 < (int)uVar1 &&
       (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
         (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
        ((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
         (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
           (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)))))))) &&
      (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
        (uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1)) &&
       (uVar1 = FUN_14030eb00(param_1), -1 < (int)uVar1)))))) {
    uVar5 = 0;
    uVar4 = uVar5;
    do {
      uVar3 = uVar5;
      do {
        uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + ((uVar3 + uVar4 * 5) * 3 + 0x53) * 8);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      uVar2 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar2;
      uVar3 = uVar5;
    } while (uVar2 < 2);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0x388);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar4 + 0x2b) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x30) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0x500);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0x578);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0x5f8);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0x670);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + (uVar4 + 0x4a) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x4f) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + (uVar4 + 0x5a) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x5f) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    uVar1 = FUN_14030ed20(param_1);
    uVar4 = uVar5;
    if (-1 < (int)uVar1) {
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0x9a0);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0xa18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + (uVar4 + 0x71) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x76) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0xb90);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0xc08);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0xc88);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0xd00);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + (uVar4 + 0x90) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x95) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      uVar4 = *(longlong *)(param_3 + 0xec0) + param_2;
      if ((uVar4 < *param_1) ||
         (param_1[1] <
          *(longlong *)(param_3 + 0xec0) + (ulonglong)*(uint *)(param_3 + 0xeb8) * 2 + param_2)) {
        uVar1 = 0x80004005;
      }
      else {
        if (*(uint *)(param_3 + 0xeb8) != 0) {
          uVar5 = uVar4;
        }
        uVar1 = 0;
        *(ulonglong *)(param_3 + 0xec0) = uVar5;
      }
    }
  }
  return uVar1;
}



==== FUN_140314d80 @ 140314d80 size 4284 ====
CALLERS:
CALLEES: FUN_1403174a0 FUN_1408fde98 FUN_140317cf0 FUN_1403146b0 FUN_1401afb10 FUN_14032fe20 FUN_14018b280 FUN_14032da00 FUN_14018db00 __security_check_cookie FUN_1401afc20 FUN_1401c3280 memcpy FUN_140318540 FUN_140313c20 FUN_1401c9800

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



==== FUN_14031a220 @ 14031a220 size 86 ====
CALLERS:
CALLEES: FUN_14032d6b0

undefined8 FUN_14031a220(longlong param_1)

{
  short *psVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_14032d6b0();
  if (-1 < (int)uVar3) {
    psVar1 = *(short **)(*(longlong *)(param_1 + 0x1a0) + 0xec0);
    if ((psVar1 != (short *)0x0) && (*psVar1 != 0)) {
      plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x10);
      (**(code **)(*plVar2 + 0x28))(plVar2,psVar1,param_1 + 0x438,0);
      return 0;
    }
    uVar3 = 0x80070057;
  }
  return uVar3;
}



==== FUN_14031a5c0 @ 14031a5c0 size 617 ====
CALLERS:
CALLEES:

void FUN_14031a5c0(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  dVar4 = DAT_140b7a078;
  dVar3 = DAT_140b79db0;
  uVar8 = 0;
  if (*(longlong *)(param_1 + 0x448) != 0) {
    do {
      lVar7 = uVar8 * 0x70 + *(longlong *)(param_1 + 0x440);
      lVar2 = *(longlong *)(lVar7 + 0x50);
      if (lVar2 == 0) {
        plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x10);
        iVar5 = (**(code **)(*plVar1 + 0x28))
                          (plVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x1a0) + 0xec0),
                           (undefined8 *)(lVar7 + 0x50),0);
        if (-1 < iVar5) {
          uVar6 = (**(code **)(DAT_140c77890 + 0x18))(&DAT_140c77890);
          plVar1 = *(longlong **)(lVar7 + 0x50);
          local_58 = 0x96;
          local_50 = 0x3f800000;
          local_48 = 0;
          local_40 = 0;
          local_54 = (undefined4)(longlong)((double)uVar6 * dVar3 * dVar4);
          (**(code **)(*plVar1 + 0x248))(plVar1,0,&local_58);
        }
      }
      else if ((*(float *)(lVar7 + 0x68) != 0.0) && (*(longlong *)(lVar2 + 0x168) == 0)) {
        *(longlong **)(lVar2 + 0x168) = param_2;
        plVar1 = (longlong *)(lVar2 + 0x170);
        *plVar1 = *param_2;
        *param_2 = lVar2;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x168) = plVar1;
        }
      }
      uVar8 = (ulonglong)((int)uVar8 + 1);
    } while (uVar8 < *(ulonglong *)(param_1 + 0x448));
  }
  for (lVar2 = *(longlong *)(param_1 + 0x450); lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x78)) {
    lVar7 = *(longlong *)(lVar2 + 0x50);
    if (lVar7 == 0) {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x10);
      iVar5 = (**(code **)(*plVar1 + 0x28))
                        (plVar1,*(undefined8 *)(*(longlong *)(param_1 + 0x1a0) + 0xec0),lVar2 + 0x50
                         ,0);
      if (-1 < iVar5) {
        uVar6 = (**(code **)(DAT_140c77890 + 0x18))(&DAT_140c77890);
        local_58 = 0x96;
        local_50 = 0x3f800000;
        local_48 = 0;
        local_40 = 0;
        local_54 = (undefined4)(longlong)((double)uVar6 * dVar3 * dVar4);
        (**(code **)(**(longlong **)(lVar2 + 0x50) + 0x248))
                  (*(longlong **)(lVar2 + 0x50),0,&local_58);
      }
    }
    else if ((*(float *)(lVar2 + 0x68) != 0.0) && (*(longlong *)(lVar7 + 0x168) == 0)) {
      *(longlong **)(lVar7 + 0x168) = param_2;
      plVar1 = (longlong *)(lVar7 + 0x170);
      *plVar1 = *param_2;
      *param_2 = lVar7;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 0x168) = plVar1;
      }
    }
  }
  return;
}


