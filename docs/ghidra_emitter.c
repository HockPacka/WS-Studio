
==== FUN_140315e90 @ 140315e90 size 5635 ====
CALLERS:
CALLEES: __security_check_cookie FUN_14018cdf0 FUN_140318840 FUN_1401afb10 FUN_140262750 FUN_140315e40 FUN_140262d50 memcpy FUN_140318930 FUN_1401afc20 FUN_1403135b0 FUN_140313a00 FUN_140318a40

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140315e90(longlong param_1,float *param_2,undefined8 *param_3,float *param_4,float *param_5
                  ,undefined4 *param_6,float *param_7,longlong param_8,undefined4 *param_9,
                  uint param_10,longlong param_11,uint param_12)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  uint uVar31;
  int iVar32;
  undefined4 *puVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  longlong lVar36;
  ulonglong uVar37;
  ulonglong uVar38;
  longlong lVar39;
  longlong *plVar40;
  undefined4 *puVar41;
  bool bVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  undefined4 uVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  undefined1 auStack_408 [32];
  ulonglong local_3e8;
  undefined4 *local_3d8;
  undefined8 local_3c8;
  undefined8 uStack_3c0;
  longlong local_3b8;
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  undefined8 local_388;
  undefined8 uStack_380;
  undefined8 local_378;
  undefined8 uStack_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  float *local_348;
  float *local_340;
  float local_338;
  float fStack_334;
  float fStack_330;
  float local_328;
  float fStack_324;
  float fStack_320;
  float local_318;
  float fStack_314;
  float fStack_310;
  undefined4 local_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  float local_2d8 [13];
  float local_2a4;
  float local_268;
  float fStack_264;
  float fStack_260;
  float fStack_25c;
  float local_258 [13];
  float local_224;
  float *local_218;
  float *local_210;
  undefined1 local_1c8 [32];
  float local_1a8;
  ulonglong local_e8;
  
  local_e8 = DAT_140c0f7b0 ^ (ulonglong)auStack_408;
  local_3d8 = param_6;
  local_348 = param_7;
  local_3b8 = param_8;
  local_340 = param_4;
  if (*(longlong *)(param_1 + 0x28) == 0) {
    FUN_14018cdf0();
  }
  if (*(longlong *)(param_1 + 0x468) == 0) {
    return;
  }
  if (*(short *)(param_11 + 0x34) == 0) {
    return;
  }
  if ((*(float *)(param_11 + 0x20) == 0.0) && (*(float *)(param_11 + 0x24) == 0.0)) {
    return;
  }
  plVar40 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x598);
  if ((plVar40 != (longlong *)0x0) &&
     (uVar31 = (**(code **)(*plVar40 + 0x20))(), (param_12 & uVar31) == 0)) {
    return;
  }
  if (*(longlong *)(param_1 + 0x480) == 0) {
    FUN_1403135b0(param_1);
  }
  local_2e8 = *param_3;
  uStack_2e0 = param_3[1];
  fVar44 = *(float *)(param_3 + 6);
  fVar45 = *(float *)((longlong)param_3 + 0x34);
  fVar48 = *(float *)(param_3 + 7);
  fVar43 = *(float *)((longlong)param_3 + 0x3c);
  local_2f8 = param_3[2];
  uStack_2f0 = param_3[3];
  local_3a8 = param_3[4];
  uStack_3a0 = param_3[5];
  uVar37 = 0;
  local_268 = fVar44;
  fStack_264 = fVar45;
  fStack_260 = fVar48;
  fStack_25c = fVar43;
  if ((*(int *)(*(longlong *)(param_1 + 8) + 0x28) == 0) ||
     (*(int *)(*(longlong *)(param_1 + 8) + 8) == 2)) {
    local_398 = *(undefined8 *)(param_2 + 0xc);
    uStack_390 = *(undefined8 *)(param_2 + 0xe);
    fVar44 = *param_2;
    fVar45 = param_2[1];
    fVar48 = param_2[2];
    local_378 = *(undefined8 *)(param_5 + 4);
    uStack_370 = *(undefined8 *)(param_5 + 6);
    fVar43 = param_2[4];
    fVar52 = param_2[5];
    fVar53 = param_2[6];
    fVar49 = param_2[8];
    fVar50 = param_2[9];
    fVar51 = param_2[10];
    local_388 = *(undefined8 *)param_5;
    uStack_380 = *(undefined8 *)(param_5 + 2);
    local_358 = *(undefined8 *)(param_5 + 0xc);
    uStack_350 = *(undefined8 *)(param_5 + 0xe);
    local_368 = *(undefined8 *)(param_5 + 8);
    uStack_360 = *(undefined8 *)(param_5 + 10);
  }
  else {
    local_218 = param_4;
    FUN_1401afc20(&local_218,&local_338);
    uStack_3c0 = &local_338;
    local_3c8 = param_2;
    local_218 = param_2;
    local_210 = uStack_3c0;
    FUN_1401afb10(&local_218,local_258);
    local_218 = param_4;
    FUN_1401afc20(&local_218,&local_338);
    uStack_3c0 = &local_338;
    local_3c8 = param_5;
    local_218 = param_5;
    local_210 = uStack_3c0;
    FUN_1401afb10(&local_218,local_2d8);
    plVar40 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x1e8);
    local_2a4 = 0.0;
    if (plVar40 != (longlong *)0x0) {
      local_3e8 = 0;
      local_398 = CONCAT44(fVar45 + fRam0000000140c77874,fVar44 + _DAT_140c77870);
      uStack_390 = CONCAT44(fVar43 + fRam0000000140c7787c,fVar48 + fRam0000000140c77878);
      iVar32 = (**(code **)(*plVar40 + 0x1b8))(plVar40,&local_398,local_1c8,1);
      if (iVar32 != 0) {
        local_2a4 = local_1a8;
      }
    }
    local_3c8 = local_258;
    uStack_3c0 = param_4;
    fStack_264 = local_2a4;
    local_224 = local_2a4;
    local_218 = local_3c8;
    local_210 = param_4;
    FUN_1401afb10(&local_218,&local_338);
    local_3c8 = local_2d8;
    uStack_3c0 = param_4;
    local_218 = local_3c8;
    local_210 = param_4;
    FUN_1401afb10(&local_218,&local_388);
    local_398 = CONCAT44(uStack_304,local_308);
    uStack_390 = CONCAT44(uStack_2fc,uStack_300);
    fVar44 = local_338;
    fVar45 = fStack_334;
    fVar48 = fStack_330;
    fVar49 = local_318;
    fVar50 = fStack_314;
    fVar51 = fStack_310;
    fVar43 = local_328;
    fVar52 = fStack_324;
    fVar53 = fStack_320;
  }
  fVar30 = fStack_260;
  fVar29 = fStack_264;
  fVar28 = local_268;
  local_218 = (float *)&local_388;
  FUN_1401afc20(&local_218,&local_338);
  lVar39 = *(longlong *)(param_1 + 0x1a0);
  lVar36 = *DAT_140c65670;
  fVar47 = *(float *)(param_1 + 0x3c0);
  fVar3 = *(float *)(param_1 + 0x3c4);
  fVar4 = *(float *)(param_1 + 0x3c8);
  local_3c8 = (float *)CONCAT44(fVar3 * local_378._4_4_ + fVar47 * local_388._4_4_ +
                                fVar4 * local_368._4_4_ + local_358._4_4_,
                                fVar3 * (float)local_378 + fVar47 * (float)local_388 +
                                fVar4 * (float)local_368 + (float)local_358);
  uStack_3c0 = (float *)CONCAT44(fVar3 * uStack_370._4_4_ + fVar47 * uStack_380._4_4_ +
                                 fVar4 * uStack_360._4_4_ + uStack_350._4_4_,
                                 fVar3 * (float)uStack_370 + fVar47 * (float)uStack_380 +
                                 fVar4 * (float)uStack_360 + (float)uStack_350);
  plVar40 = DAT_140c65670;
  iVar32 = FUN_140315e40(param_1);
  (**(code **)(lVar36 + 0x140))
            (plVar40,*(undefined8 *)
                      (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x10) +
                      0x828),
             (*(uint *)(lVar39 + 0xec8) >> 0xb & 1) +
             ((((uint)(*(char *)(lVar39 + 0x858) != '\0') +
               (iVar32 + ((uint)*(ushort *)(lVar39 + 0x998) + (uint)*(ushort *)(lVar39 + 0x998) * 2
                         + (uint)*(ushort *)(*(longlong *)(param_1 + 8) + 0x18)) * 5) * 2) * 3 +
              (uint)*(ushort *)(lVar39 + 0x804)) * 5 + (uint)*(byte *)(lVar39 + 1)) * 2);
  local_3e8 = local_3e8 & 0xffffffff00000000;
  puVar33 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0xdd0,0,0);
  fVar47 = DAT_140b79ed0;
  local_3c8 = (float *)puVar33;
  if (puVar33 != (undefined4 *)0x0) {
    uVar46 = local_3d8[1];
    uVar5 = local_3d8[2];
    uVar6 = local_3d8[3];
    uVar7 = local_3d8[8];
    uVar8 = local_3d8[9];
    uVar9 = local_3d8[10];
    uVar10 = local_3d8[0xb];
    uVar11 = local_3d8[6];
    uVar12 = local_3d8[7];
    uVar13 = local_3d8[0xe];
    uVar14 = local_3d8[0xf];
    uVar15 = local_3d8[0xc];
    uVar16 = local_3d8[0xd];
    uVar17 = local_3d8[4];
    uVar18 = local_3d8[5];
    *puVar33 = *local_3d8;
    puVar33[1] = uVar17;
    puVar33[2] = uVar7;
    puVar33[3] = uVar15;
    puVar33[4] = uVar46;
    puVar33[5] = uVar18;
    puVar33[6] = uVar8;
    puVar33[7] = uVar16;
    puVar33[8] = uVar5;
    puVar33[9] = uVar11;
    puVar33[10] = uVar9;
    puVar33[0xb] = uVar13;
    puVar33[0xc] = uVar6;
    puVar33[0xd] = uVar12;
    puVar33[0xe] = uVar10;
    puVar33[0xf] = uVar14;
    fVar3 = param_4[4];
    fVar4 = param_4[5];
    fVar19 = param_4[6];
    fVar20 = param_4[0xc];
    fVar21 = param_4[0xd];
    fVar22 = param_4[0xe];
    fVar23 = param_4[1];
    fVar24 = param_4[2];
    fVar25 = param_4[8];
    fVar26 = param_4[9];
    fVar27 = param_4[10];
    puVar33[0x10] = *param_4;
    puVar33[0x11] = fVar3;
    puVar33[0x12] = fVar25;
    puVar33[0x13] = fVar20;
    puVar33[0x14] = fVar23;
    puVar33[0x15] = fVar4;
    puVar33[0x16] = fVar26;
    puVar33[0x17] = fVar21;
    puVar33[0x18] = fVar24;
    puVar33[0x19] = fVar19;
    puVar33[0x1a] = fVar27;
    puVar33[0x1b] = fVar22;
    puVar33[0x1c] = (float)local_388;
    puVar33[0x1d] = (float)local_378;
    puVar33[0x1e] = (float)local_368;
    puVar33[0x1f] = (float)local_358;
    puVar33[0x20] = local_388._4_4_;
    puVar33[0x21] = local_378._4_4_;
    puVar33[0x22] = local_368._4_4_;
    puVar33[0x23] = local_358._4_4_;
    puVar33[0x24] = (float)uStack_380;
    puVar33[0x25] = (float)uStack_370;
    puVar33[0x26] = (float)uStack_360;
    puVar33[0x27] = (float)uStack_350;
    puVar33[0x28] = local_338;
    puVar33[0x29] = local_328;
    puVar33[0x2a] = local_318;
    puVar33[0x2b] = local_308;
    puVar33[0x2c] = fStack_334;
    puVar33[0x2d] = fStack_324;
    puVar33[0x2e] = fStack_314;
    puVar33[0x2f] = uStack_304;
    puVar33[0x30] = fStack_330;
    puVar33[0x31] = fStack_320;
    puVar33[0x32] = fStack_310;
    puVar33[0x33] = uStack_300;
    puVar33[0x34] = (undefined4)local_2e8;
    puVar33[0x35] = (undefined4)local_2f8;
    puVar33[0x36] = (float)local_3a8;
    puVar33[0x37] = fVar28;
    puVar33[0x38] = local_2e8._4_4_;
    puVar33[0x39] = local_2f8._4_4_;
    puVar33[0x3a] = local_3a8._4_4_;
    puVar33[0x3b] = fVar29;
    puVar33[0x3c] = (undefined4)uStack_2e0;
    puVar33[0x3d] = (undefined4)uStack_2f0;
    puVar33[0x3e] = (float)uStack_3a0;
    puVar33[0x3f] = fVar30;
    puVar33[0x40] = fVar44;
    puVar33[0x41] = fVar43;
    puVar33[0x42] = fVar49;
    puVar33[0x43] = (undefined4)local_398;
    puVar33[0x44] = fVar45;
    puVar33[0x45] = fVar52;
    puVar33[0x46] = fVar50;
    puVar33[0x47] = local_398._4_4_;
    puVar33[0x48] = fVar48;
    puVar33[0x49] = fVar53;
    puVar33[0x4a] = fVar51;
    puVar33[0x4b] = (undefined4)uStack_390;
    uVar34 = *(undefined8 *)(param_1 + 0x448);
    *(undefined8 *)(puVar33 + 0x4c) = *(undefined8 *)(param_1 + 0x440);
    *(undefined8 *)(puVar33 + 0x4e) = uVar34;
    uVar34 = *(undefined8 *)(param_1 + 0x458);
    *(undefined8 *)(puVar33 + 0x50) = *(undefined8 *)(param_1 + 0x450);
    *(undefined8 *)(puVar33 + 0x52) = uVar34;
    fVar43 = *(float *)(param_1 + 0x3c0);
    fVar52 = *(float *)(param_1 + 0x3c4);
    fVar53 = *(float *)(param_1 + 0x3c8);
    puVar33[0x54] =
         fVar52 * (float)local_378 + fVar43 * (float)local_388 + fVar53 * (float)local_368 +
         (float)local_358;
    puVar33[0x55] =
         fVar52 * local_378._4_4_ + fVar43 * local_388._4_4_ + fVar53 * local_368._4_4_ +
         local_358._4_4_;
    puVar33[0x56] =
         fVar52 * (float)uStack_370 + fVar43 * (float)uStack_380 + fVar53 * (float)uStack_360 +
         (float)uStack_350;
    puVar33[0x57] =
         fVar52 * uStack_370._4_4_ + fVar43 * uStack_380._4_4_ + fVar53 * uStack_360._4_4_ +
         uStack_350._4_4_;
    puVar33[0x58] = *param_9;
    puVar33[0x59] = param_9[1];
    puVar33[0x5a] = param_9[2];
    puVar33[0x5b] = 0;
    FUN_140262d50(param_8,puVar33 + 0x5c);
    uVar34 = *(undefined8 *)(param_8 + 0xb8);
    *(undefined8 *)(puVar33 + 0x78) = *(undefined8 *)(param_8 + 0xb0);
    *(undefined8 *)(puVar33 + 0x7a) = uVar34;
    puVar33[0x7c] = *(undefined4 *)(param_8 + 0x90);
    puVar33[0x7d] = *(undefined4 *)(param_8 + 0x94);
    puVar33[0x7e] = *(undefined4 *)(param_8 + 0x98);
    puVar33[0x7f] = *(undefined4 *)(param_8 + 0x2b4);
    puVar33[0x80] = *(undefined4 *)(param_8 + 0xa0);
    puVar33[0x81] = *(undefined4 *)(param_8 + 0xa4);
    puVar33[0x82] = *(undefined4 *)(param_8 + 0xa8);
    puVar33[0x83] = *(undefined4 *)(param_8 + 0x2b0);
    FUN_140262750();
    puVar33[0x90] = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x864);
    puVar33[0x91] = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x868);
    local_3d8 = *(undefined4 **)(*(longlong *)(param_1 + 0x1a0) + 0xe7c);
    *(undefined4 **)(puVar33 + 0x92) = local_3d8;
    fVar43 = (float)*(uint *)(*(longlong *)(param_1 + 0x1a0) + 0xe78);
    if (fVar43 <= fVar47) {
      fVar43 = fVar47;
    }
    puVar33[0x94] = fVar43;
    puVar33[0x95] = (float)*(uint *)(*(longlong *)(param_1 + 0x1a0) + 0xe8c);
    iVar32 = *(int *)(*(longlong *)(param_1 + 0x1a0) + 0xe8c);
    uVar38 = uVar37;
    if (iVar32 != 0) {
      uVar38 = (ulonglong)(iVar32 - 1);
    }
    puVar33[0x96] = (float)uVar38;
    puVar33[0x97] =
         (float)(1 << ((byte)*(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0xe84) & 0x1f));
    uVar34 = *(undefined8 *)(param_1 + 0x3b8);
    *(undefined8 *)(puVar33 + 0x98) = *(undefined8 *)(param_1 + 0x3b0);
    *(undefined8 *)(puVar33 + 0x9a) = uVar34;
    puVar33[0x9c] = SQRT(fVar44 * fVar44 + fVar45 * fVar45 + fVar48 * fVar48);
    puVar33[0x9d] = *(undefined4 *)(param_1 + 0x488);
    puVar33[0xa0] = *(undefined4 *)(*(longlong *)(param_1 + 0x418) + 0x20);
    puVar33[0xa4] = (float)(*(char *)(*(longlong *)(param_1 + 0x1a0) + 0x858) == '\x02');
    puVar33[0xa5] = (float)(*(char *)(*(longlong *)(param_1 + 0x1a0) + 0x858) == '\x01');
    fVar44 = fVar47;
    if ((*(uint *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x1000) == 0) {
      fVar44 = 0.0;
    }
    puVar33[0xa6] = fVar44;
    fVar44 = fVar47;
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 4) == 0) {
      fVar44 = 0.0;
    }
    puVar33[0xa7] = fVar44;
    fVar44 = fVar47;
    if ((*(uint *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x100) == 0) {
      fVar44 = 0.0;
    }
    puVar33[0xa8] = fVar44;
    uVar38 = uVar37;
    do {
      FUN_140313a00((longlong)puVar33 + uVar38 + 0x2b0,*(longlong *)(param_1 + 0x480) + uVar38);
      uVar38 = uVar38 + 0x40;
    } while (uVar38 < 0x800);
    puVar41 = puVar33 + 0x2ac;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x400);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x4d8),*(undefined8 *)(param_1 + 0x4d0),puVar41)
      ;
      uVar38 = uVar38 + 4;
      puVar41 = puVar41 + 4;
    } while (uVar38 < 0x28);
    puVar33 = puVar33 + 0x2ad;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x4f8);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x4a8),*(undefined8 *)(param_1 + 0x4a0),puVar33)
      ;
      puVar41 = local_3c8;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    puVar33 = local_3c8 + 0x2ae;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x5f0);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x4b8),*(undefined8 *)(param_1 + 0x4b0),puVar33)
      ;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x294) != 0) {
      puVar33 = puVar41 + 0x324;
      uVar38 = uVar37;
      do {
        uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x294);
        local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
        FUN_140318930(uVar1,*(undefined8 *)(param_1 + 0x4c8),*(undefined8 *)(param_1 + 0x4c0),
                      puVar33);
        uVar38 = uVar38 + 4;
        puVar33 = puVar33 + 4;
      } while (uVar38 < 0x28);
      puVar33 = puVar41 + 0x34c;
      uVar38 = uVar37;
      do {
        uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x294);
        local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
        FUN_140318930(uVar1,*(undefined8 *)(param_1 + 0x4c8),
                      (ulonglong)(uint)uVar1 * 0x20 + *(longlong *)(param_1 + 0x4c0),puVar33);
        uVar38 = uVar38 + 4;
        puVar33 = puVar33 + 4;
      } while (uVar38 < 0x28);
    }
    puVar33 = puVar41 + 0x2af;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x86c);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x4f8),*(undefined8 *)(param_1 + 0x4f0),puVar33)
      ;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 8) == 0) {
      *(undefined8 *)(puVar41 + 0x2d4) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2d8) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2dc) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2e0) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2e4) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2e8) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2ec) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2f0) = 0x3f0000003f000000;
      local_3d8 = (undefined4 *)0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2f4) = 0x3f0000003f000000;
      *(undefined8 *)(puVar41 + 0x2f8) = 0x3f0000003f000000;
    }
    else {
      puVar33 = puVar41 + 0x2d4;
      uVar38 = uVar37;
      do {
        uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x6e8);
        local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
        FUN_140318a40(uVar1,*(undefined8 *)(param_1 + 0x4e8),*(undefined8 *)(param_1 + 0x4e0),
                      puVar33);
        uVar38 = uVar38 + 4;
        puVar33 = puVar33 + 4;
      } while (uVar38 < 0x28);
    }
    puVar33 = puVar41 + 0x2d7;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xd78);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x548),*(undefined8 *)(param_1 + 0x540),puVar33)
      ;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    puVar33 = puVar41 + 0x2fc;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x99c);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x508),*(undefined8 *)(param_1 + 0x500),puVar33)
      ;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    puVar33 = puVar41 + 0x2fd;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xa90);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x518),*(undefined8 *)(param_1 + 0x510),puVar33)
      ;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    puVar33 = puVar41 + 0x2fe;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xb88);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x528),*(undefined8 *)(param_1 + 0x520),puVar33)
      ;
      param_8 = local_3b8;
      uVar38 = uVar38 + 4;
      puVar33 = puVar33 + 4;
    } while (uVar38 < 0x28);
    puVar41 = puVar41 + 0x2ff;
    uVar38 = uVar37;
    do {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xc80);
      local_3e8 = CONCAT44(local_3e8._4_4_,(uint)uVar1);
      FUN_140318840(uVar1,*(undefined8 *)(param_1 + 0x538),*(undefined8 *)(param_1 + 0x530),puVar41)
      ;
      uVar38 = uVar38 + 4;
      puVar41 = puVar41 + 4;
    } while (uVar38 < 0x28);
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  lVar39 = *(longlong *)(param_1 + 0x1a0);
  bVar42 = (param_10 & 0x224) != 0;
  lVar36 = *(longlong *)(param_1 + 8);
  local_3b8 = CONCAT44(local_3b8._4_4_,(uint)*(ushort *)(lVar39 + 0x984));
  local_3c8 = (float *)CONCAT44(local_3c8._4_4_,(uint)*(ushort *)(lVar39 + 0x998));
  uVar31 = (uint)(0.0 < *(float *)(param_8 + 0x2f4));
  local_3d8 = (undefined4 *)CONCAT44(local_3d8._4_4_,uVar31);
  if ((*(int *)(lVar36 + 0x14) == 0) ||
     (iVar32 = 1, (**(byte **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x10) & 1) != 0
     )) {
    iVar32 = 0;
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,
             *(undefined8 *)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x10) + 0x830),
             *(int *)(lVar36 + 0x1c) +
             (iVar32 + ((~param_12 & 1) +
                       uVar31 * 2 +
                       ((uint)*(ushort *)(lVar39 + 0x984) * 2 +
                       ((uint)*(ushort *)(lVar36 + 0x18) +
                       ((*(uint *)(lVar39 + 0xec8) >> 2 & 1) +
                       ((uint)bVar42 + (uint)*(ushort *)(lVar39 + 0x998) + (uint)bVar42 * 2) * 2) *
                       3) * 10) * 2) * 2) * 4);
  local_3e8 = local_3e8 & 0xffffffff00000000;
  puVar33 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x150,0,0);
  if (puVar33 != (undefined4 *)0x0) {
    *puVar33 = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x988);
    fVar44 = *(float *)(*(longlong *)(param_1 + 0x1a0) + 0x98c) -
             *(float *)(*(longlong *)(param_1 + 0x1a0) + 0x988);
    if (fVar44 == 0.0) {
      fVar44 = 0.0;
    }
    else {
      fVar44 = fVar47 / fVar44;
    }
    puVar33[1] = fVar44;
    puVar33[2] = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x290);
    puVar33[3] = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x7e0);
    fVar44 = local_348[1];
    auVar2._4_4_ = *local_348 - fVar44;
    auVar2._0_4_ = *local_348 * fVar44;
    auVar2._8_4_ = fVar44;
    auVar2._12_4_ = 0;
    *(undefined1 (*) [16])(puVar33 + 8) = auVar2;
    *(undefined8 *)(puVar33 + 4) =
         *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x550);
    lVar39 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10);
    local_3a8 = CONCAT44(*(float *)(lVar39 + 0x554) * _UNK_140b7ac54,
                         *(float *)(lVar39 + 0x550) * _DAT_140b7ac50);
    uStack_3a0 = CONCAT44(*(float *)(lVar39 + 0x55c) * _UNK_140b7ac5c,
                          *(float *)(lVar39 + 0x558) * _UNK_140b7ac58);
    *(undefined8 *)(puVar33 + 6) = local_3a8;
    FUN_140262d50(param_8,puVar33 + 0xc);
    uVar34 = *(undefined8 *)(param_8 + 0xb8);
    *(undefined8 *)(puVar33 + 0x28) = *(undefined8 *)(param_8 + 0xb0);
    *(undefined8 *)(puVar33 + 0x2a) = uVar34;
    puVar33[0x2c] = *(undefined4 *)(param_8 + 0x90);
    puVar33[0x2d] = *(undefined4 *)(param_8 + 0x94);
    puVar33[0x2e] = *(undefined4 *)(param_8 + 0x98);
    puVar33[0x2f] = *(undefined4 *)(param_8 + 0x2b4);
    puVar33[0x30] = *(undefined4 *)(param_8 + 0xa0);
    puVar33[0x31] = *(undefined4 *)(param_8 + 0xa4);
    puVar33[0x32] = *(undefined4 *)(param_8 + 0xa8);
    puVar33[0x33] = *(undefined4 *)(param_8 + 0x2b0);
    FUN_140262750();
    fVar45 = DAT_140b7a23c;
    lVar39 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10);
    uVar34 = *(undefined8 *)(lVar39 + 0x568);
    *(undefined8 *)(puVar33 + 0x40) = *(undefined8 *)(lVar39 + 0x560);
    *(undefined8 *)(puVar33 + 0x42) = uVar34;
    fVar44 = fVar47;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x980) != 0) {
      fVar44 = fVar45;
    }
    puVar33[0x44] = fVar44;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x982) == 0) {
      fVar45 = fVar47;
    }
    puVar33[0x45] = fVar45;
    puVar33[0x46] = *(undefined4 *)(param_11 + 0x2c);
    fVar44 = *(float *)(*(longlong *)(param_1 + 8) + 0x88);
    fVar45 = DAT_140b7a1cc;
    if (DAT_140b79cc4 < (float)((uint)fVar44 & DAT_140b7b500)) {
      fVar45 = fVar47 / fVar44;
    }
    puVar33[0x47] = fVar45;
    lVar39 = *(longlong *)(param_1 + 0x1a0);
    puVar33[0x48] = *(undefined4 *)(lVar39 + 0x7f0);
    puVar33[0x49] = *(undefined4 *)(lVar39 + 0x7f4);
    puVar33[0x4a] = *(undefined4 *)(lVar39 + 0x7f8);
    lVar39 = *(longlong *)(param_1 + 0x28);
    uVar34 = _DAT_140b7a740;
    uVar35 = _UNK_140b7a748;
    if (*(float *)(lVar39 + 0x10c) != 0.0) {
      uVar34 = *(undefined8 *)(lVar39 + 0x100);
      uVar35 = *(undefined8 *)(lVar39 + 0x108);
    }
    fVar44 = *(float *)(param_1 + 0x60);
    local_3a8._0_4_ = (float)uVar34;
    local_3a8._4_4_ = (float)((ulonglong)uVar34 >> 0x20);
    uStack_3a0._0_4_ = (float)uVar35;
    uStack_3a0._4_4_ = (float)((ulonglong)uVar35 >> 0x20);
    puVar33[0x50] = (float)local_3a8 * fVar44;
    puVar33[0x51] = local_3a8._4_4_ * fVar44;
    puVar33[0x52] = (float)uStack_3a0 * fVar44;
    puVar33[0x53] = uStack_3a0._4_4_ * fVar44;
    puVar33[0x4b] = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x800);
    if (**(char **)(param_1 + 0x1a0) == '\x02') {
      fVar47 = DAT_140b7a220;
    }
    puVar33[0x4c] = fVar47;
    uVar46 = 0;
    if (**(char **)(param_1 + 0x1a0) == '\x02') {
      uVar46 = DAT_140b79fc0;
    }
    puVar33[0x4d] = uVar46;
    puVar33[0x4e] = *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x990);
    local_3a8 = uVar34;
    uStack_3a0 = uVar35;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,0);
  (**(code **)(*DAT_140c65670 + 0x198))
            (DAT_140c65670,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x24));
  uVar34 = 7;
  if (*(int *)(*(longlong *)(param_1 + 8) + 0x20) != 0) {
    uVar34 = 1;
  }
  (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,uVar34);
  iVar32 = *(int *)(*(longlong *)(param_1 + 8) + 0x1c);
  if (iVar32 == 0) {
    uVar34 = 5;
LAB_1403171ac:
    uVar35 = 4;
  }
  else if (iVar32 == 1) {
    uVar34 = 0;
    uVar35 = 8;
  }
  else {
    if (iVar32 == 2) {
      uVar34 = 1;
      goto LAB_1403171ac;
    }
    if (iVar32 != 3) goto LAB_1403171c4;
    uVar35 = 8;
    uVar34 = 2;
  }
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,uVar35,uVar34,0);
LAB_1403171c4:
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x978);
  if ((uint)uVar1 < *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x1c0)) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,0,
               *(undefined8 *)
                (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x420) + 0x10 +
                (ulonglong)uVar1 * 0x18));
  }
  else {
    local_3e8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,0,0);
  }
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x994);
  if ((uint)uVar1 < *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x1c0)) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,1,
               *(undefined8 *)
                (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x420) + 0x10 +
                (ulonglong)uVar1 * 0x18));
  }
  else {
    local_3e8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,1,0,0);
  }
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x996);
  if ((uint)uVar1 < *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x1c0)) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,2,
               *(undefined8 *)
                (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x420) + 0x10 +
                (ulonglong)uVar1 * 0x18),0);
  }
  else {
    local_3e8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,2,0,0);
  }
  uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x99a);
  if ((uint)uVar1 < *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x1c0)) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,4,
               *(undefined8 *)
                (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x420) + 0x10 +
                (ulonglong)uVar1 * 0x18));
  }
  else {
    local_3e8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,4);
  }
  puVar33 = (undefined4 *)
            (**(code **)(*DAT_140c65670 + 0xe0))
                      (DAT_140c65670,(int)*(undefined8 *)(param_1 + 0x468) * 0x1c,0xc,1);
  if (puVar33 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x430) == 0) {
      memcpy(puVar33,*(void **)(param_1 + 0x460),*(longlong *)(param_1 + 0x468) * 0x1c);
    }
    else if (*(longlong *)(param_1 + 0x468) != 0) {
      do {
        lVar39 = *(longlong *)(param_1 + 0x460);
        uVar37 = uVar37 + 1;
        lVar36 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x470) + -4 + uVar37 * 4) * 0x1c;
        *puVar33 = *(undefined4 *)(lVar36 + lVar39);
        puVar33[1] = *(undefined4 *)(lVar36 + 4 + lVar39);
        puVar33[2] = *(undefined4 *)(lVar36 + 8 + lVar39);
        puVar33[3] = *(undefined4 *)(lVar36 + 0xc + lVar39);
        puVar33[4] = *(undefined4 *)(lVar36 + 0x10 + lVar39);
        puVar33[5] = *(undefined4 *)(lVar36 + 0x14 + lVar39);
        puVar33[6] = *(undefined4 *)(lVar36 + 0x18 + lVar39);
        puVar33 = puVar33 + 7;
      } while (uVar37 < *(ulonglong *)(param_1 + 0x468));
    }
    (**(code **)(*DAT_140c65670 + 0xe8))();
  }
  (**(code **)(*DAT_140c65670 + 0x130))
            (DAT_140c65670,
             *(undefined8 *)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x38) + 0x10) + 0x8b8),
             0xc);
  local_3e8 = CONCAT44(local_3e8._4_4_,*(undefined4 *)(param_1 + 0x468));
  (**(code **)(*DAT_140c65670 + 0x288))(DAT_140c65670,4,0);
  return;
}



==== FUN_14032da00 @ 14032da00 size 5889 ====
CALLERS: FUN_140314d80 FUN_14031b080
CALLEES: __security_check_cookie FUN_1408fe3d0 FUN_1401afb10 FUN_14032ca60 FUN_14030a8a0 FUN_1408fc950 FUN_1407b08c0 FUN_1401c9770

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_14032da00(longlong param_1,uint param_2,uint param_3,float *param_4,float *param_5,
             float *param_6,float *param_7,float *param_8,float *param_9)

{
  byte bVar1;
  ushort uVar2;
  longlong *plVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  ulonglong uVar7;
  float *pfVar8;
  longlong lVar9;
  char cVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  float *pfVar14;
  short *psVar15;
  longlong lVar16;
  uint uVar17;
  ulonglong uVar18;
  uint uVar19;
  longlong lVar20;
  uint uVar21;
  longlong lVar22;
  ulonglong uVar23;
  longlong lVar24;
  int *piVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined8 uVar29;
  undefined8 extraout_XMM0_Qb;
  undefined8 extraout_XMM0_Qb_00;
  undefined8 extraout_XMM0_Qb_01;
  undefined8 extraout_XMM0_Qb_02;
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  float fVar32;
  float fVar33;
  float fVar40;
  float fVar41;
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  float fVar42;
  float fVar48;
  float fVar49;
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  float fVar65;
  float fVar66;
  float fVar67;
  float fVar68;
  float fVar69;
  float fVar70;
  float fVar71;
  float fVar72;
  float fVar73;
  float fVar74;
  undefined1 auStack_2c8 [32];
  undefined4 local_2a8;
  undefined4 local_298;
  undefined4 local_294;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined4 local_278;
  undefined8 local_268;
  undefined8 uStack_260;
  longlong local_258;
  undefined8 local_248;
  undefined8 uStack_240;
  float local_238;
  float fStack_234;
  float fStack_230;
  float fStack_22c;
  float *local_228;
  float *local_220;
  longlong local_218;
  float *local_210;
  longlong local_208;
  float *local_200;
  float *local_1f8;
  undefined1 local_1e8 [16];
  undefined1 local_1d8 [16];
  float local_1c8 [7];
  float fStack_1ac;
  float local_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float local_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float *local_178;
  float *local_170;
  float local_148;
  uint local_144;
  undefined8 local_128;
  float local_120;
  float afStack_118 [12];
  ulonglong local_e8;
  
  fVar59 = DAT_140b7a228;
  fVar27 = DAT_140b79fa0;
  fVar26 = DAT_140b79ed0;
  fVar28 = DAT_140b79e48;
  local_e8 = DAT_140c0f7b0 ^ (ulonglong)auStack_2c8;
  local_268._0_4_ = 0.0;
  local_268._4_4_ = 0.0;
  uStack_260._0_4_ = 0.0;
  uStack_260._4_4_ = 0.0;
  local_228 = param_7;
  lVar16 = *(longlong *)(param_1 + 0x1a0);
  local_210 = param_8;
  uVar2 = *(ushort *)(lVar16 + 8);
  local_200 = param_5;
  local_220 = param_6;
  local_1f8 = param_4;
  local_128 = param_1;
  if (7 < uVar2) {
    if (uVar2 == 0xc) {
      if (*(uint *)(param_1 + 0x18) < 2) {
        return 0;
      }
      if (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x4c0) == 0) {
        return 0;
      }
      fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
      uVar19 = 0;
      uVar21 = *(int *)(param_1 + 0x18) - 2;
      uVar11 = uVar19;
      if (3 < (int)uVar21) {
        uVar17 = 2;
        do {
          pfVar5 = (float *)(param_1 + 0x3dc + (ulonglong)(uVar17 - 1) * 4);
          if (fVar26 < *pfVar5 || fVar26 == *pfVar5) goto LAB_14032e0fe;
          pfVar5 = (float *)(param_1 + 0x3dc + (ulonglong)uVar17 * 4);
          if (fVar26 < *pfVar5 || fVar26 == *pfVar5) {
            uVar19 = uVar19 + 1;
            goto LAB_14032e0fe;
          }
          pfVar5 = (float *)(param_1 + 0x3dc + (ulonglong)(uVar17 + 1) * 4);
          if (fVar26 < *pfVar5 || fVar26 == *pfVar5) {
            uVar19 = uVar19 + 2;
            goto LAB_14032e0fe;
          }
          pfVar5 = (float *)(param_1 + 0x3dc + (ulonglong)(uVar17 + 2) * 4);
          if (fVar26 < *pfVar5 || fVar26 == *pfVar5) {
            uVar19 = uVar19 + 3;
            goto LAB_14032e0fe;
          }
          uVar19 = uVar19 + 4;
          uVar17 = uVar17 + 4;
          uVar11 = uVar19;
        } while (uVar19 < *(int *)(param_1 + 0x18) - 5U);
      }
      do {
        uVar19 = uVar11;
        if (uVar21 <= uVar19) break;
        pfVar5 = (float *)(param_1 + 0x3dc + (ulonglong)(uVar19 + 1) * 4);
        uVar11 = uVar19 + 1;
      } while (*pfVar5 <= fVar26 && fVar26 != *pfVar5);
LAB_14032e0fe:
      uVar18 = (ulonglong)uVar19;
      fVar59 = *(float *)(param_1 + 0x3dc + uVar18 * 4);
      fVar72 = *(float *)(param_1 + 0x3dc + (ulonglong)(uVar19 + 1) * 4);
      if (fVar72 - fVar59 == 0.0) {
        if (*(longlong *)(param_1 + 0x20) == 0) {
          fVar26 = 0.0;
          fVar59 = 0.0;
          fVar72 = 0.0;
          fVar73 = 0.0;
        }
        else {
          pfVar5 = (float *)(*(longlong *)(param_1 + 0x20) + uVar18 * 0x10);
          fVar26 = *pfVar5;
          fVar59 = pfVar5[1];
          fVar72 = pfVar5[2];
          fVar73 = pfVar5[3];
        }
      }
      else {
        plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x4c0);
        pfVar5 = (float *)(**(code **)(*plVar3 + 0x358))
                                    (plVar3,&local_238,(&DAT_140af1508)[uVar19 + 1],0);
        plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x4c0);
        pfVar6 = (float *)(**(code **)(*plVar3 + 0x358))
                                    (plVar3,&local_288,(&DAT_140af1508)[uVar18],0);
        fVar73 = (fVar26 - fVar59) / (fVar72 - fVar59);
        fVar26 = fVar73 * (*pfVar5 - *pfVar6) + *pfVar6;
        fVar59 = fVar73 * (pfVar5[1] - pfVar6[1]) + pfVar6[1];
        fVar72 = fVar73 * (pfVar5[2] - pfVar6[2]) + pfVar6[2];
        fVar73 = fVar73 * (pfVar5[3] - pfVar6[3]) + pfVar6[3];
      }
      *param_4 = fVar26;
      param_4[1] = fVar59;
      param_4[2] = fVar72;
      param_4[3] = fVar73;
      plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x4c0);
      iVar4 = (**(code **)(*plVar3 + 0x350))(plVar3,0x1f);
      if (iVar4 == 0) {
        pfVar5 = *(float **)(param_1 + 0x20);
        fVar72 = *param_4;
        fVar73 = param_4[1];
        fVar74 = param_4[2];
        if (pfVar5 != (float *)0x0) {
          fVar72 = fVar72 - *pfVar5;
          fVar73 = fVar73 - pfVar5[1];
          fVar74 = fVar74 - pfVar5[2];
        }
      }
      else {
        plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x4c0);
        (**(code **)(*plVar3 + 0x358))(plVar3,&local_288,0x1f);
        fVar72 = *param_4 - (float)local_288;
        fVar73 = param_4[1] - local_288._4_4_;
        fVar74 = param_4[2] - (float)uStack_280;
      }
    }
    else if (uVar2 == 8) {
LAB_14032e2e4:
      local_258 = *(longlong *)(param_1 + 0x28);
LAB_14032e2ed:
      lVar20 = *(longlong *)(*(longlong *)(local_258 + 0x38) + 0x40);
      if (*(int *)(lVar20 + 0xa8) == 0) {
        return 0;
      }
      lVar22 = *(longlong *)(lVar20 + 0xb0);
      lVar24 = *(longlong *)(lVar20 + 0xc0);
      uVar18 = 0;
      uVar19 = 0;
      if ((*(byte *)(lVar16 + 10) & 4) == 0) {
        uVar29 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
        uVar13 = 1;
        auVar39._8_4_ = (int)extraout_XMM0_Qb_02;
        auVar39._0_8_ = uVar29;
        auVar39._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_02 >> 0x20);
        uVar12 = (ulonglong)*(uint *)(lVar20 + 0x80);
        if (1 < (ulonglong)*(uint *)(lVar20 + 0x80)) {
          do {
            uVar7 = (uVar12 - uVar13 >> 1) + uVar13;
            fVar59 = (float)FUN_1401c9770(lVar22 + (ulonglong)*(uint *)(lVar24 + uVar7 * 4) * 2);
            if (fVar59 <= auVar39._0_4_) {
              uVar13 = uVar7 + 1;
              uVar7 = uVar12;
            }
            uVar12 = uVar7;
          } while (uVar13 < uVar7);
        }
        uVar12 = (ulonglong)*(uint *)(lVar24 + uVar13 * 4);
        piVar25 = (int *)((uVar13 - 1) * 0x70 + *(longlong *)(lVar20 + 0x88));
        iVar4 = *(int *)(lVar24 + (uVar13 - 1) * 4);
        uVar13 = (ulonglong)(iVar4 + 1);
        if (uVar13 < uVar12) {
          do {
            uVar7 = (uVar12 - uVar13 >> 1) + uVar13;
            fVar59 = (float)FUN_1401c9770(lVar22 + uVar7 * 2);
            if (fVar59 <= auVar39._0_4_) {
              uVar13 = uVar7 + 1;
              uVar7 = uVar12;
            }
            uVar12 = uVar7;
          } while (uVar13 < uVar7);
        }
        iVar4 = (int)uVar13 - iVar4;
      }
      else {
        if (*(longlong *)(param_1 + 0x408) == 0) {
          return 0;
        }
        uVar29 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
        uVar13 = 1;
        auVar43._8_4_ = (int)extraout_XMM0_Qb;
        auVar43._0_8_ = uVar29;
        auVar43._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
        if (1 < (ulonglong)*(uint *)(lVar20 + 0x80)) {
          uVar12 = (ulonglong)*(uint *)(lVar20 + 0x80);
          do {
            uVar7 = (uVar12 - uVar13 >> 1) + uVar13;
            if (*(float *)(*(longlong *)(param_1 + 0x400) + uVar7 * 4) <= (float)uVar29) {
              uVar13 = uVar7 + 1;
              uVar7 = uVar12;
            }
            uVar12 = uVar7;
          } while (uVar13 < uVar7);
        }
        fVar59 = *(float *)(*(longlong *)(param_1 + 0x400) + -4 + uVar13 * 4);
        piVar25 = (int *)((uVar13 - 1) * 0x70 + *(longlong *)(lVar20 + 0x88));
        fVar72 = *(float *)(*(longlong *)(param_1 + 0x400) + uVar13 * 4) - fVar59;
        if (fVar72 < DAT_140b79cc4) {
          return 0;
        }
        local_278 = *(int *)(lVar24 + -4 + uVar13 * 4);
        uVar12 = (ulonglong)*(uint *)(lVar24 + uVar13 * 4);
        lVar16 = lVar22 + (ulonglong)(local_278 + 1U) * 2;
        uVar13 = (ulonglong)(local_278 + 1U);
        uVar29 = FUN_1401c9770(lVar22 + uVar12 * 2);
        auVar36._8_4_ = (int)extraout_XMM0_Qb_00;
        auVar36._0_8_ = uVar29;
        auVar36._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_00 >> 0x20);
        fVar73 = (float)FUN_1401c9770(lVar16);
        cVar10 = 'q';
        fVar72 = (auVar36._0_4_ - fVar73) * ((auVar43._0_4_ - fVar59) / fVar72);
        fVar59 = ABS(fVar72);
        if (0x337fffff < (uint)fVar59) {
          if ((uint)fVar59 < 0x387ff000) {
            uVar19 = (((uint)fVar72 & 0x7fffff | 0x800000) >>
                     (0x71U - (char)((uint)fVar59 >> 0x17) & 0x1f)) + 0x1000 >> 0xd;
          }
          else if ((uint)fVar59 < 0x47fff000) {
            uVar19 = (int)fVar59 + 0xc8001000U >> 0xd;
          }
          else {
            uVar19 = 0x43ff;
          }
        }
        uVar11 = uVar19 & 0x7fff;
        if ((uVar19 & 0x7c00) == 0) {
          if ((uVar19 & 0x3ff) != 0) {
            iVar4 = 0x71;
            for (uVar11 = (uVar19 & 0x3ff) << 0xd; uVar11 < 0x800000; uVar11 = uVar11 * 2) {
              iVar4 = iVar4 + -1;
            }
            uVar11 = iVar4 << 0x17 | uVar11 & 0x7fffff;
          }
        }
        else {
          uVar11 = (uVar11 + 0x1c000) * 0x2000;
        }
        local_298 = (float)(uVar11 | (uVar19 & 0x8000 | (uint)fVar72 >> 0x10 & 0x8000) << 0x10);
        fVar59 = (float)FUN_1401c9770(lVar16);
        local_298 = fVar59 + local_298;
        fVar59 = ABS(local_298);
        uVar7 = uVar18;
        if (0x337fffff < (uint)fVar59) {
          if ((uint)fVar59 < 0x387ff000) {
            uVar7 = (ulonglong)
                    ((((uint)local_298 & 0x7fffff | 0x800000) >>
                     (cVar10 - (char)((uint)fVar59 >> 0x17) & 0x1fU)) + 0x1000 >> 0xd);
          }
          else if ((uint)fVar59 < 0x47fff000) {
            uVar7 = (ulonglong)((int)fVar59 + 0xc8001000U >> 0xd);
          }
          else {
            uVar7 = 0x43ff;
          }
        }
        local_294 = (float)CONCAT22(local_294._2_2_,
                                    (ushort)uVar7 | (ushort)((uint)local_298 >> 0x10) & 0x8000);
        uVar29 = FUN_1401c9770(&local_294);
        auVar37._8_4_ = (int)extraout_XMM0_Qb_01;
        auVar37._0_8_ = uVar29;
        auVar37._12_4_ = (int)((ulonglong)extraout_XMM0_Qb_01 >> 0x20);
        if (uVar13 < uVar12) {
          do {
            uVar7 = (uVar12 - uVar13 >> 1) + uVar13;
            fVar59 = (float)FUN_1401c9770(lVar22 + uVar7 * 2);
            if (fVar59 <= auVar37._0_4_) {
              uVar13 = uVar7 + 1;
              uVar7 = uVar12;
            }
            uVar12 = uVar7;
          } while (uVar13 < uVar7);
        }
        iVar4 = (int)uVar13 - local_278;
      }
      fVar60 = DAT_140b79d20;
      fVar59 = (float)piVar25[1];
      fVar72 = 0.0;
      fVar73 = 0.0;
      fVar74 = 0.0;
      lVar20 = *(longlong *)(local_258 + 0x38);
      lVar22 = *(longlong *)(*(longlong *)(lVar20 + 0x40) + 0x78);
      lVar16 = *(longlong *)(*(longlong *)(local_258 + 0x40) + 0x1b8) +
               (ulonglong)*(ushort *)(piVar25 + 4) * 2;
      cVar10 = *(char *)(*(longlong *)(lVar20 + 0x40) + 0x6d);
      uVar19 = (iVar4 + -1) * 3 + *piVar25;
      local_218 = 0;
      local_294 = (float)CONCAT31(local_294._1_3_,cVar10);
      local_208 = 3;
      lVar24 = local_258;
      uVar13 = uVar18;
      uVar12 = uVar18;
      fVar42 = local_1a8;
      fVar48 = fStack_1a4;
      fVar49 = fStack_1a0;
      fVar41 = fStack_19c;
      fVar61 = local_1c8[4];
      fVar63 = local_1c8[5];
      fVar65 = local_1c8[6];
      fVar67 = fStack_1ac;
      fVar69 = local_1c8[0];
      fVar62 = local_1c8[1];
      fVar64 = local_1c8[2];
      fVar66 = local_1c8[3];
      fVar68 = local_198;
      fVar70 = fStack_194;
      fVar71 = fStack_190;
      fVar32 = fStack_18c;
      local_298 = fVar59;
      do {
        if (cVar10 == '\x01') {
          uVar11 = (uint)*(ushort *)(lVar22 + (ulonglong)uVar19 * 2);
        }
        else {
          uVar11 = *(uint *)(lVar22 + (ulonglong)uVar19 * 4);
        }
        uVar7 = (ulonglong)(uVar11 + (int)fVar59);
        fVar40 = *(float *)(*(longlong *)(lVar20 + 0x150) * uVar7 + *(longlong *)(lVar20 + 0xf8));
        local_144 = *(uint *)(*(longlong *)(lVar20 + 0x158) * uVar7 + *(longlong *)(lVar20 + 0x100))
        ;
        uVar23 = (ulonglong)local_144;
        if (*(int *)(lVar20 + 0x188) == 1) {
          pfVar5 = (float *)(*(longlong *)(lVar20 + 0x130) * uVar7 + *(longlong *)(lVar20 + 0xd8));
          fVar33 = *pfVar5;
          fVar56 = pfVar5[1];
          fVar57 = pfVar5[2];
          fVar58 = 0.0;
        }
        else {
          psVar15 = (short *)(*(longlong *)(lVar20 + 0x130) * uVar7 + *(longlong *)(lVar20 + 0xd8));
          fVar33 = (float)(int)*psVar15 * _DAT_140b7ab30;
          fVar56 = (float)(int)psVar15[1] * _UNK_140b7ab34;
          fVar57 = (float)(int)psVar15[2] * _UNK_140b7ab38;
          fVar58 = _UNK_140b7ab3c * 0.0;
        }
        local_248 = (float *)CONCAT44(fVar56,fVar33);
        uStack_240 = (float *)CONCAT44(fVar58,fVar57);
        local_148 = fVar40;
        FUN_1407b08c0(*(longlong *)(lVar20 + 0x140) * uVar7 + *(longlong *)(lVar20 + 0xe8),
                      &local_238);
        local_288 = (float *)CONCAT44(fStack_234,local_238);
        uStack_280 = (float *)CONCAT44(fStack_22c,fStack_230);
        if (((float)uVar12 != fVar40) || ((int)uVar13 != (int)uVar23)) {
          plVar3 = (longlong *)(lVar24 + 0x338);
          uVar12 = (ulonglong)(uint)fVar40;
          uVar13 = uVar23 & 0xffffffff;
          pfVar5 = (float *)((ulonglong)*(ushort *)(lVar16 + (ulonglong)local_148._0_1_ * 2) * 0x40
                            + *plVar3);
          local_278 = (int)uVar23;
          uVar11 = 1;
          fVar32 = (float)(local_144 & 0xff) * fVar60;
          fVar69 = *pfVar5 * fVar32;
          fVar62 = pfVar5[1] * fVar32;
          fVar64 = pfVar5[2] * fVar32;
          fVar66 = pfVar5[3] * fVar32;
          fVar61 = pfVar5[4] * fVar32;
          fVar63 = pfVar5[5] * fVar32;
          fVar65 = pfVar5[6] * fVar32;
          fVar67 = pfVar5[7] * fVar32;
          fVar42 = pfVar5[8] * fVar32;
          fVar48 = pfVar5[9] * fVar32;
          fVar49 = pfVar5[10] * fVar32;
          fVar41 = pfVar5[0xb] * fVar32;
          fVar68 = pfVar5[0xc] * fVar32;
          fVar70 = pfVar5[0xd] * fVar32;
          fVar71 = pfVar5[0xe] * fVar32;
          fVar32 = pfVar5[0xf] * fVar32;
          uVar7 = uVar18;
          do {
            bVar1 = *(byte *)((longlong)&local_278 + uVar7 + 1);
            lVar24 = local_258;
            local_298 = fVar40;
            if (bVar1 == 0) break;
            lVar9 = uVar7 + 1;
            uVar11 = uVar11 + 1;
            uVar7 = uVar7 + 1;
            pfVar5 = (float *)((ulonglong)
                               *(ushort *)
                                (lVar16 + (ulonglong)*(byte *)((longlong)&local_298 + lVar9) * 2) *
                               0x40 + *plVar3);
            fVar33 = (float)bVar1 * fVar60;
            fVar69 = *pfVar5 * fVar33 + fVar69;
            fVar62 = pfVar5[1] * fVar33 + fVar62;
            fVar64 = pfVar5[2] * fVar33 + fVar64;
            fVar66 = pfVar5[3] * fVar33 + fVar66;
            fVar61 = pfVar5[4] * fVar33 + fVar61;
            fVar63 = pfVar5[5] * fVar33 + fVar63;
            fVar65 = pfVar5[6] * fVar33 + fVar65;
            fVar67 = pfVar5[7] * fVar33 + fVar67;
            fVar42 = pfVar5[8] * fVar33 + fVar42;
            fVar48 = pfVar5[9] * fVar33 + fVar48;
            fVar49 = pfVar5[10] * fVar33 + fVar49;
            fVar41 = pfVar5[0xb] * fVar33 + fVar41;
            fVar68 = pfVar5[0xc] * fVar33 + fVar68;
            fVar70 = pfVar5[0xd] * fVar33 + fVar70;
            fVar71 = pfVar5[0xe] * fVar33 + fVar71;
            fVar32 = pfVar5[0xf] * fVar33 + fVar32;
          } while (uVar11 < 4);
        }
        lVar9 = local_218 + 0x10;
        uVar19 = uVar19 + 1;
        local_208 = local_208 + -1;
        *(float *)((longlong)afStack_118 + local_218) =
             (float)local_248 * fVar69 + local_248._4_4_ * fVar61 + (float)uStack_240 * fVar42 +
             fVar68;
        *(float *)((longlong)afStack_118 + local_218 + 4) =
             (float)local_248 * fVar62 + local_248._4_4_ * fVar63 + (float)uStack_240 * fVar48 +
             fVar70;
        *(float *)((longlong)afStack_118 + local_218 + 8) =
             (float)local_248 * fVar64 + local_248._4_4_ * fVar65 + (float)uStack_240 * fVar49 +
             fVar71;
        *(float *)((longlong)afStack_118 + local_218 + 0xc) =
             (float)local_248 * fVar66 + local_248._4_4_ * fVar67 + (float)uStack_240 * fVar41 +
             fVar32;
        fVar33 = local_238 * fVar69 + fStack_234 * fVar61 + fStack_230 * fVar42;
        fVar56 = local_238 * fVar62 + fStack_234 * fVar63 + fStack_230 * fVar48;
        fVar57 = local_238 * fVar64 + fStack_234 * fVar65 + fStack_230 * fVar49;
        fVar58 = local_238 * fVar66 + fStack_234 * fVar67 + fStack_230 * fVar41;
        fVar40 = fVar56 * fVar56;
        auVar44._4_4_ = fVar40;
        auVar44._0_4_ = fVar33 * fVar33;
        auVar44._8_4_ = fVar57 * fVar57;
        auVar44._12_4_ = fVar58 * fVar58;
        auVar30._4_4_ = fVar40;
        auVar30._0_4_ = fVar40;
        auVar30._8_4_ = fVar40;
        auVar30._12_4_ = fVar40;
        auVar45._4_12_ = auVar44._4_12_;
        auVar45._0_4_ = fVar33 * fVar33 + fVar40 + fVar57 * fVar57;
        auVar39 = rsqrtss(auVar30,auVar45);
        fVar40 = auVar39._0_4_;
        fVar40 = (fVar27 - auVar45._0_4_ * fVar40 * fVar40) * fVar28 * fVar40;
        if (fVar40 <= 0.0) {
          fVar40 = 0.0;
        }
        *(float *)((longlong)local_1c8 + local_218) = fVar40 * fVar33;
        *(float *)((longlong)local_1c8 + local_218 + 4) = fVar40 * fVar56;
        *(float *)((longlong)local_1c8 + local_218 + 8) = fVar40 * fVar57;
        *(float *)((longlong)local_1c8 + local_218 + 0xc) = fVar40 * fVar58;
        param_1 = local_128;
        cVar10 = (char)local_294;
        local_218 = lVar9;
      } while (local_208 != 0);
      fVar28 = (float)(**(code **)(**(longlong **)(local_128 + 0x38) + 0x38))();
      local_128 = CONCAT44(local_128._4_4_,fVar28);
      fVar27 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
      pfVar5 = (float *)&local_128;
      lVar16 = 3;
      local_128 = CONCAT44(fVar27,(float)local_128);
      local_1f8[0] = 0.0;
      local_1f8[1] = 0.0;
      local_1f8[2] = 0.0;
      local_1f8[3] = 0.0;
      local_120 = (fVar26 - fVar28) - fVar27;
      do {
        fVar28 = *pfVar5;
        fVar26 = *(float *)((longlong)afStack_118 + uVar18 + 4);
        fVar27 = *(float *)((longlong)afStack_118 + uVar18 + 8);
        fVar59 = *(float *)((longlong)afStack_118 + uVar18 + 0xc);
        pfVar5 = pfVar5 + 1;
        fVar60 = *(float *)((longlong)local_1c8 + uVar18);
        fVar42 = *(float *)((longlong)local_1c8 + uVar18 + 4);
        fVar48 = *(float *)((longlong)local_1c8 + uVar18 + 8);
        *local_1f8 = *local_1f8 + *(float *)((longlong)afStack_118 + uVar18) * fVar28;
        local_1f8[1] = local_1f8[1] + fVar26 * fVar28;
        local_1f8[2] = local_1f8[2] + fVar27 * fVar28;
        local_1f8[3] = local_1f8[3] + fVar59 * fVar28;
        fVar72 = fVar60 * fVar28 + fVar72;
        fVar73 = fVar42 * fVar28 + fVar73;
        fVar74 = fVar48 * fVar28 + fVar74;
        lVar16 = lVar16 + -1;
        uVar18 = uVar18 + 0x10;
        param_4 = local_1f8;
        param_5 = local_200;
        param_6 = local_220;
        fVar28 = DAT_140b79e48;
        fVar27 = DAT_140b79fa0;
      } while (lVar16 != 0);
    }
    else {
      if (uVar2 == 9) {
LAB_14032e25c:
        lVar20 = *(longlong *)(param_1 + 0x28);
      }
      else {
        if (uVar2 == 10) {
          local_258 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x4c0);
          if (local_258 == 0) goto LAB_14032e2e4;
          goto LAB_14032e2ed;
        }
        if (uVar2 != 0xb) {
          return 0;
        }
        lVar20 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x4c0);
        if (lVar20 == 0) goto LAB_14032e25c;
      }
      lVar22 = *(longlong *)(*(longlong *)(lVar20 + 0x38) + 0x40);
      if ((*(byte *)(lVar16 + 10) & 4) == 0) {
        if (*(int *)(lVar22 + 0x90) == 0) {
          return 0;
        }
        uVar19 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                           (*(longlong **)(param_1 + 0x38),0,*(int *)(lVar22 + 0x90) + -1);
        uVar18 = 1;
        if (1 < (ulonglong)*(uint *)(lVar22 + 0x80)) {
          uVar13 = (ulonglong)*(uint *)(lVar22 + 0x80);
          do {
            uVar12 = (uVar13 - uVar18 >> 1) + uVar18;
            if (*(uint *)(*(longlong *)(lVar22 + 0xa0) + uVar12 * 4) <= uVar19) {
              uVar18 = uVar12 + 1;
              uVar12 = uVar13;
            }
            uVar13 = uVar12;
          } while (uVar18 < uVar12);
        }
        lVar16 = *(longlong *)(lVar22 + 0xa0);
      }
      else {
        if (*(int *)(param_1 + 0x3ec) == 0) {
          return 0;
        }
        uVar19 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                           (*(longlong **)(param_1 + 0x38),0,*(int *)(param_1 + 0x3ec) + -1);
        uVar18 = 1;
        if (1 < (ulonglong)*(uint *)(lVar22 + 0x80)) {
          uVar13 = (ulonglong)*(uint *)(lVar22 + 0x80);
          do {
            uVar12 = (uVar13 - uVar18 >> 1) + uVar18;
            if (*(uint *)(*(longlong *)(param_1 + 0x3f0) + uVar12 * 4) <= uVar19) {
              uVar18 = uVar12 + 1;
              uVar12 = uVar13;
            }
            uVar13 = uVar12;
          } while (uVar18 < uVar12);
        }
        lVar16 = *(longlong *)(param_1 + 0x3f0);
      }
      lVar22 = (uVar18 - 1) * 0x70 + *(longlong *)(lVar22 + 0x88);
      uVar18 = (ulonglong)((*(int *)(lVar22 + 4) - *(int *)(lVar16 + -4 + uVar18 * 4)) + uVar19);
      lVar16 = *(longlong *)(*(longlong *)(lVar20 + 0x40) + 0x1b8) +
               (ulonglong)*(ushort *)(lVar22 + 0x10) * 2;
      lVar22 = *(longlong *)(lVar20 + 0x38);
      fVar28 = *(float *)(*(longlong *)(lVar22 + 0x150) * uVar18 + *(longlong *)(lVar22 + 0xf8));
      fVar26 = *(float *)(*(longlong *)(lVar22 + 0x158) * uVar18 + *(longlong *)(lVar22 + 0x100));
      local_198 = fVar28;
      fStack_194 = fVar26;
      pfVar8 = (float *)FUN_14030a8a0(lVar22 + 0xd8,local_1e8,uVar18);
      FUN_1407b08c0(*(longlong *)(*(longlong *)(lVar20 + 0x38) + 0x140) * uVar18 +
                    *(longlong *)(*(longlong *)(lVar20 + 0x38) + 0xe8),&local_288);
      local_248 = local_288;
      pfVar5 = local_248;
      uStack_240 = uStack_280;
      pfVar6 = uStack_240;
      if ((fVar28 != 0.0) ||
         (fVar59 = local_1a8, fVar73 = fStack_1a4, fVar74 = fStack_1a0, fVar72 = fStack_19c,
         fVar60 = local_1c8[4], fVar42 = local_1c8[5], fVar48 = local_1c8[6], fVar49 = fStack_1ac,
         fVar41 = local_1c8[0], fVar61 = local_1c8[1], fVar63 = local_1c8[2], fVar65 = local_1c8[3],
         fVar67 = local_198, fVar69 = fStack_194, fVar26 != 0.0)) {
        local_294 = fVar28;
        pfVar14 = (float *)((ulonglong)*(ushort *)(lVar16 + (ulonglong)local_198._0_1_ * 2) * 0x40 +
                           *(longlong *)(lVar20 + 0x338));
        lVar22 = 0;
        uVar19 = 1;
        fStack_18c = (float)((uint)fStack_194 & 0xff) * DAT_140b79d20;
        fVar41 = *pfVar14 * fStack_18c;
        fVar61 = pfVar14[1] * fStack_18c;
        fVar63 = pfVar14[2] * fStack_18c;
        fVar65 = pfVar14[3] * fStack_18c;
        fVar60 = pfVar14[4] * fStack_18c;
        fVar42 = pfVar14[5] * fStack_18c;
        fVar48 = pfVar14[6] * fStack_18c;
        fVar49 = pfVar14[7] * fStack_18c;
        fVar59 = pfVar14[8] * fStack_18c;
        fVar73 = pfVar14[9] * fStack_18c;
        fVar74 = pfVar14[10] * fStack_18c;
        fVar72 = pfVar14[0xb] * fStack_18c;
        fVar67 = pfVar14[0xc] * fStack_18c;
        fVar69 = pfVar14[0xd] * fStack_18c;
        fStack_190 = pfVar14[0xe] * fStack_18c;
        fStack_18c = pfVar14[0xf] * fStack_18c;
        do {
          bVar1 = *(byte *)((longlong)&local_298 + lVar22 + 1);
          local_298 = fVar26;
          if (bVar1 == 0) break;
          lVar24 = lVar22 + 1;
          uVar19 = uVar19 + 1;
          lVar22 = lVar22 + 1;
          pfVar14 = (float *)((ulonglong)
                              *(ushort *)
                               (lVar16 + (ulonglong)*(byte *)((longlong)&local_294 + lVar24) * 2) *
                              0x40 + *(longlong *)(lVar20 + 0x338));
          fVar28 = (float)bVar1 * DAT_140b79d20;
          fVar41 = *pfVar14 * fVar28 + fVar41;
          fVar61 = pfVar14[1] * fVar28 + fVar61;
          fVar63 = pfVar14[2] * fVar28 + fVar63;
          fVar65 = pfVar14[3] * fVar28 + fVar65;
          fVar60 = pfVar14[4] * fVar28 + fVar60;
          fVar42 = pfVar14[5] * fVar28 + fVar42;
          fVar48 = pfVar14[6] * fVar28 + fVar48;
          fVar49 = pfVar14[7] * fVar28 + fVar49;
          fVar59 = pfVar14[8] * fVar28 + fVar59;
          fVar73 = pfVar14[9] * fVar28 + fVar73;
          fVar74 = pfVar14[10] * fVar28 + fVar74;
          fVar72 = pfVar14[0xb] * fVar28 + fVar72;
          fVar67 = pfVar14[0xc] * fVar28 + fVar67;
          fVar69 = pfVar14[0xd] * fVar28 + fVar69;
          fStack_190 = pfVar14[0xe] * fVar28 + fStack_190;
          fStack_18c = pfVar14[0xf] * fVar28 + fStack_18c;
        } while (uVar19 < 4);
      }
      fVar28 = pfVar8[2];
      fVar26 = pfVar8[1];
      fVar62 = *pfVar8;
      local_248._4_4_ = (float)((ulonglong)local_288 >> 0x20);
      uStack_240._0_4_ = SUB84(uStack_280,0);
      local_248._0_4_ = SUB84(local_288,0);
      *param_4 = fVar26 * fVar60 + fVar62 * fVar41 + fVar28 * fVar59 + fVar67;
      param_4[1] = fVar26 * fVar42 + fVar62 * fVar61 + fVar28 * fVar73 + fVar69;
      param_4[2] = fVar26 * fVar48 + fVar62 * fVar63 + fVar28 * fVar74 + fStack_190;
      param_4[3] = fVar26 * fVar49 + fVar62 * fVar65 + fVar28 * fVar72 + fStack_18c;
      fVar72 = local_248._4_4_ * fVar60 + (float)local_248 * fVar41 + (float)uStack_240 * fVar59;
      fVar73 = local_248._4_4_ * fVar42 + (float)local_248 * fVar61 + (float)uStack_240 * fVar73;
      fVar74 = local_248._4_4_ * fVar48 + (float)local_248 * fVar63 + (float)uStack_240 * fVar74;
      param_5 = local_200;
      param_6 = local_220;
      fVar28 = DAT_140b79e48;
      local_248 = pfVar5;
      uStack_240 = pfVar6;
    }
    fVar26 = *param_4;
    fVar59 = param_4[1];
    fVar60 = param_4[2];
    fVar42 = local_210[5];
    fVar48 = local_210[6];
    fVar49 = local_210[7];
    fVar41 = local_210[1];
    fVar61 = local_210[2];
    fVar63 = local_210[3];
    fVar65 = local_210[9];
    fVar67 = local_210[10];
    fVar69 = local_210[0xb];
    fVar62 = local_210[0xd];
    fVar64 = local_210[0xe];
    fVar66 = local_210[0xf];
    *param_4 = fVar59 * local_210[4] + fVar26 * *local_210 + fVar60 * local_210[8] + local_210[0xc];
    param_4[1] = fVar59 * fVar42 + fVar26 * fVar41 + fVar60 * fVar65 + fVar62;
    param_4[2] = fVar59 * fVar48 + fVar26 * fVar61 + fVar60 * fVar67 + fVar64;
    param_4[3] = fVar59 * fVar49 + fVar26 * fVar63 + fVar60 * fVar69 + fVar66;
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 10) & 2) != 0) {
      local_1d8._4_4_ = **(float **)(param_1 + 0x1c8);
      local_1d8._0_4_ = **(float **)(param_1 + 0x1b8);
      local_1d8._8_4_ = **(float **)(param_1 + 0x1d8);
      local_1d8._12_4_ = 0;
      fVar26 = *param_4;
      fVar59 = param_4[1];
      fVar60 = param_4[2];
      local_1e8._4_4_ = **(float **)(param_1 + 0x1c0);
      local_1e8._0_4_ = **(float **)(param_1 + 0x1b0);
      local_1e8._8_4_ = **(float **)(param_1 + 0x1d0);
      local_1e8._12_4_ = 0;
      fVar42 = fVar59 * local_228[4] + fVar26 * *local_228 + fVar60 * local_228[8] + local_228[0xc];
      fVar48 = fVar59 * local_228[5] + fVar26 * local_228[1] + fVar60 * local_228[9] +
               local_228[0xd];
      fVar49 = fVar59 * local_228[6] + fVar26 * local_228[2] + fVar60 * local_228[10] +
               local_228[0xe];
      local_288 = (float *)CONCAT44(fVar48,fVar42);
      uStack_280 = (float *)CONCAT44(fVar59 * local_228[7] + fVar26 * local_228[3] +
                                     fVar60 * local_228[0xb] + local_228[0xf],fVar49);
      if (((((fVar42 < **(float **)(param_1 + 0x1b0)) || (**(float **)(param_1 + 0x1b8) <= fVar42))
           || (fVar48 < **(float **)(param_1 + 0x1c0))) ||
          ((**(float **)(param_1 + 0x1c8) <= fVar48 || (fVar49 < **(float **)(param_1 + 0x1d0)))))
         || (**(float **)(param_1 + 0x1d8) <= fVar49)) {
switchD_14032daf7_caseD_2:
        return 0;
      }
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 1) == 0) {
      local_288 = local_210;
      uStack_280 = local_228;
      local_178 = local_210;
      local_170 = local_228;
      FUN_1401afb10(&local_178,local_1c8);
      local_268._0_4_ = fVar73 * local_1c8[4] + fVar72 * local_1c8[0] + fVar74 * local_1a8;
      local_268._4_4_ = fVar73 * local_1c8[5] + fVar72 * local_1c8[1] + fVar74 * fStack_1a4;
      uStack_260._0_4_ = fVar73 * local_1c8[6] + fVar72 * local_1c8[2] + fVar74 * fStack_1a0;
      fVar59 = fVar73 * fStack_1ac + fVar72 * local_1c8[3] + fVar74 * fStack_19c;
      fVar26 = local_268._4_4_ * local_268._4_4_;
      auVar46._4_4_ = fVar26;
      auVar46._0_4_ = (float)local_268 * (float)local_268;
      auVar46._8_4_ = (float)uStack_260 * (float)uStack_260;
      auVar46._12_4_ = fVar59 * fVar59;
      auVar31._4_4_ = fVar26;
      auVar31._0_4_ = fVar26;
      auVar31._8_4_ = fVar26;
      auVar31._12_4_ = fVar26;
      auVar47._4_12_ = auVar46._4_12_;
      auVar47._0_4_ =
           (float)local_268 * (float)local_268 + fVar26 + (float)uStack_260 * (float)uStack_260;
      auVar39 = rsqrtss(auVar31,auVar47);
      uStack_260._4_4_ = auVar39._0_4_;
      uStack_260._4_4_ =
           (fVar27 - auVar47._0_4_ * uStack_260._4_4_ * uStack_260._4_4_) * fVar28 *
           uStack_260._4_4_;
      if (uStack_260._4_4_ <= 0.0) {
        uStack_260._4_4_ = 0.0;
      }
      local_2a8 = *(undefined4 *)(param_1 + 0x300);
      local_268._0_4_ = uStack_260._4_4_ * (float)local_268;
      local_268._4_4_ = uStack_260._4_4_ * local_268._4_4_;
      uStack_260._0_4_ = uStack_260._4_4_ * (float)uStack_260;
      uStack_260._4_4_ = uStack_260._4_4_ * fVar59;
      FUN_14032ca60(param_1,&local_238,param_1 + 0x270);
      local_2a8 = *(undefined4 *)(param_1 + 0x330);
      FUN_14032ca60(param_1,&local_268,&local_268);
      fVar28 = *(float *)(param_1 + 0x340);
      fVar26 = *(float *)(param_1 + 0x310);
      fVar48 = fVar28 * (float)local_268 + fVar26 * local_238;
      fVar49 = fVar28 * local_268._4_4_ + fVar26 * fStack_234;
      fVar41 = fVar28 * (float)uStack_260 + fVar26 * fStack_230;
      *param_5 = fVar48;
      param_5[1] = fVar49;
      param_5[2] = fVar41;
      param_5[3] = fVar28 * uStack_260._4_4_ + fVar26 * fStack_22c;
      fVar28 = param_6[5];
      fVar26 = param_6[6];
      fVar27 = param_6[7];
      fVar59 = param_6[1];
      fVar72 = param_6[2];
      fVar73 = param_6[3];
      fVar74 = param_6[9];
      fVar60 = param_6[10];
      fVar42 = param_6[0xb];
      *param_5 = fVar49 * param_6[4] + fVar48 * *param_6 + fVar41 * param_6[8];
      param_5[1] = fVar49 * fVar28 + fVar48 * fVar59 + fVar41 * fVar74;
      param_5[2] = fVar49 * fVar26 + fVar48 * fVar72 + fVar41 * fVar60;
      param_5[3] = fVar49 * fVar27 + fVar48 * fVar73 + fVar41 * fVar42;
      local_2a8 = *(undefined4 *)(param_1 + 0x300);
      FUN_14032ca60(param_1,&local_238,param_1 + 0x290);
      local_238 = local_238 + *param_5;
      fStack_234 = fStack_234 + param_5[1];
      fStack_230 = fStack_230 + param_5[2];
      fStack_22c = fStack_22c + param_5[3];
    }
    else {
      fVar59 = *(float *)(param_1 + 0x3c0) - *param_4;
      fVar72 = *(float *)(param_1 + 0x3c4) - param_4[1];
      fVar73 = *(float *)(param_1 + 0x3c8) - param_4[2];
      fVar74 = *(float *)(param_1 + 0x3cc) - param_4[3];
      fVar26 = fVar72 * fVar72;
      auVar54._4_4_ = fVar26;
      auVar54._0_4_ = fVar59 * fVar59;
      auVar54._8_4_ = fVar73 * fVar73;
      auVar54._12_4_ = fVar74 * fVar74;
      auVar38._4_4_ = fVar26;
      auVar38._0_4_ = fVar26;
      auVar38._8_4_ = fVar26;
      auVar38._12_4_ = fVar26;
      auVar55._4_12_ = auVar54._4_12_;
      auVar55._0_4_ = fVar59 * fVar59 + fVar26 + fVar73 * fVar73;
      auVar39 = rsqrtss(auVar38,auVar55);
      fVar26 = auVar39._0_4_;
      fVar26 = (fVar27 - auVar55._0_4_ * fVar26 * fVar26) * fVar28 * fVar26;
      if (fVar26 <= 0.0) {
        fVar26 = 0.0;
      }
      fStack_22c = *(float *)(param_1 + 0x310);
      local_238 = fStack_22c * fVar26 * fVar59;
      fStack_234 = fStack_22c * fVar26 * fVar72;
      fStack_230 = fStack_22c * fVar26 * fVar73;
      fStack_22c = fStack_22c * fVar26 * fVar74;
    }
    *param_5 = local_238;
    param_5[1] = fStack_234;
    param_5[2] = fStack_230;
    param_5[3] = fStack_22c;
    fVar28 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
    goto LAB_14032f099;
  }
  switch(uVar2) {
  case 0:
    param_4[0] = 0.0;
    param_4[1] = 0.0;
    param_4[2] = 0.0;
    param_4[3] = 0.0;
    break;
  case 1:
    fVar26 = **(float **)(param_1 + 0x1b0);
    if ((*(byte *)(lVar16 + 10) & 1) == 0) {
      fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                                (*(longlong **)(param_1 + 0x38),fVar26 * DAT_140b7a228,
                                 fVar26 * DAT_140b79e48);
      param_4[1] = 0.0;
      param_4[2] = 0.0;
      *param_4 = fVar26;
    }
    else {
      fVar59 = *(float *)(param_1 + 0x3d4);
      fVar72 = fVar26 * DAT_140b79e48;
      param_4[1] = 0.0;
      param_4[2] = 0.0;
      *param_4 = (fVar59 - fVar72) + ((float)param_2 * fVar26) / (float)param_3;
    }
    break;
  default:
    goto switchD_14032daf7_caseD_2;
  case 3:
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                              (*(longlong **)(param_1 + 0x38),
                               **(float **)(param_1 + 0x1b0) * DAT_140b7a228,
                               **(float **)(param_1 + 0x1b0) * DAT_140b79e48);
    param_4[1] = 0.0;
    *param_4 = fVar26;
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                              (*(longlong **)(param_1 + 0x38),
                               **(float **)(param_1 + 0x1b8) * DAT_140b7a228,
                               **(float **)(param_1 + 0x1b8) * fVar28);
    param_4[2] = fVar26;
    local_268 = *(undefined8 *)param_4;
    uStack_260 = *(undefined8 *)(param_4 + 2);
    goto LAB_14032de1c;
  case 4:
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                              (*(longlong **)(param_1 + 0x38),
                               **(float **)(param_1 + 0x1b0) * DAT_140b7a228,
                               **(float **)(param_1 + 0x1b0) * DAT_140b79e48);
    *param_4 = fVar26;
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                              (*(longlong **)(param_1 + 0x38),**(float **)(param_1 + 0x1b8) * fVar59
                               ,**(float **)(param_1 + 0x1b8) * fVar28);
    param_4[1] = fVar26;
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                              (*(longlong **)(param_1 + 0x38),**(float **)(param_1 + 0x1c0) * fVar59
                               ,**(float **)(param_1 + 0x1c0) * fVar28);
    param_4[2] = fVar26;
    local_268 = *(undefined8 *)param_4;
    uStack_260 = *(undefined8 *)(param_4 + 2);
    goto LAB_14032de1c;
  case 5:
    if ((*(byte *)(lVar16 + 10) & 1) == 0) {
      fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
      (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
    }
    else {
      fVar26 = *(float *)(param_1 + 0x3d4);
    }
    fVar59 = (float)FUN_1408fc950();
    param_4[1] = 0.0;
    *param_4 = fVar59 * fVar26;
    fVar59 = (float)FUN_1408fe3d0();
    param_4[2] = fVar59 * fVar26;
    break;
  case 6:
    do {
      fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
      *param_4 = fVar26;
      fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
      param_4[1] = fVar26;
      fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
      param_4[2] = fVar26;
      if ((*param_4 != 0.0) || (param_4[1] != 0.0)) break;
    } while (fVar26 == 0.0);
    fVar26 = *param_4;
    fVar59 = param_4[1];
    fVar72 = param_4[2];
    fVar73 = param_4[3];
    fVar74 = fVar59 * fVar59;
    auVar50._4_4_ = fVar74;
    auVar50._0_4_ = fVar26 * fVar26;
    auVar50._8_4_ = fVar72 * fVar72;
    auVar50._12_4_ = fVar73 * fVar73;
    auVar34._4_4_ = fVar74;
    auVar34._0_4_ = fVar74;
    auVar34._8_4_ = fVar74;
    auVar34._12_4_ = fVar74;
    auVar51._4_12_ = auVar50._4_12_;
    auVar51._0_4_ = fVar26 * fVar26 + fVar74 + fVar72 * fVar72;
    auVar39 = rsqrtss(auVar34,auVar51);
    fVar74 = auVar39._0_4_;
    fVar74 = (fVar27 - auVar51._0_4_ * fVar74 * fVar74) * fVar28 * fVar74;
    if (fVar74 <= 0.0) {
      fVar74 = 0.0;
    }
    *param_4 = fVar74 * fVar26;
    param_4[1] = fVar74 * fVar59;
    param_4[2] = fVar74 * fVar72;
    param_4[3] = fVar74 * fVar73;
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
    *param_4 = *param_4 * fVar26;
    param_4[1] = param_4[1] * fVar26;
    param_4[2] = param_4[2] * fVar26;
    param_4[3] = param_4[3] * fVar26;
  }
  local_268 = *(undefined8 *)param_4;
  uStack_260 = *(undefined8 *)(param_4 + 2);
LAB_14032de1c:
  if (**(char **)(param_1 + 0x1a0) == '\x02') {
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
    *param_4 = fVar26;
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
    param_4[1] = fVar26;
    fVar26 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
    param_4[2] = fVar26;
  }
  fVar26 = *param_4;
  fVar59 = param_4[1];
  fVar72 = param_4[2];
  fVar73 = *param_9 + fVar26 * *param_6 + fVar59 * param_6[4] + fVar72 * param_6[8] + param_6[0xc];
  fVar74 = param_9[1] +
           fVar26 * param_6[1] + fVar59 * param_6[5] + fVar72 * param_6[9] + param_6[0xd];
  fVar60 = param_9[2] +
           fVar26 * param_6[2] + fVar59 * param_6[6] + fVar72 * param_6[10] + param_6[0xe];
  fVar26 = param_9[3] +
           fVar26 * param_6[3] + fVar59 * param_6[7] + fVar72 * param_6[0xb] + param_6[0xf];
  *param_4 = fVar73;
  param_4[1] = fVar74;
  param_4[2] = fVar60;
  param_4[3] = fVar26;
  if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 1) == 0) {
    local_2a8 = *(undefined4 *)(param_1 + 0x300);
    FUN_14032ca60(param_1,&local_288,param_1 + 0x270);
    local_2a8 = *(undefined4 *)(param_1 + 0x330);
    FUN_14032ca60(param_1,&local_268,&local_268);
    fVar28 = *(float *)(param_1 + 0x340);
    fVar26 = *(float *)(param_1 + 0x310);
    fVar48 = fVar28 * (float)local_268 + fVar26 * (float)local_288;
    fVar49 = fVar28 * local_268._4_4_ + fVar26 * local_288._4_4_;
    fVar41 = fVar28 * (float)uStack_260 + fVar26 * (float)uStack_280;
    *param_5 = fVar48;
    param_5[1] = fVar49;
    param_5[2] = fVar41;
    param_5[3] = fVar28 * uStack_260._4_4_ + fVar26 * uStack_280._4_4_;
    fVar28 = param_6[1];
    fVar26 = param_6[2];
    fVar27 = param_6[3];
    fVar59 = param_6[5];
    fVar72 = param_6[6];
    fVar73 = param_6[7];
    fVar74 = param_6[9];
    fVar60 = param_6[10];
    fVar42 = param_6[0xb];
    *param_5 = fVar48 * *param_6 + fVar49 * param_6[4] + fVar41 * param_6[8];
    param_5[1] = fVar48 * fVar28 + fVar49 * fVar59 + fVar41 * fVar74;
    param_5[2] = fVar48 * fVar26 + fVar49 * fVar72 + fVar41 * fVar60;
    param_5[3] = fVar48 * fVar27 + fVar49 * fVar73 + fVar41 * fVar42;
    local_2a8 = *(undefined4 *)(param_1 + 0x300);
    FUN_14032ca60(param_1,&local_288,param_1 + 0x290);
    local_288._0_4_ = *param_5 + (float)local_288;
    local_288._4_4_ = param_5[1] + local_288._4_4_;
    uStack_280._0_4_ = param_5[2] + (float)uStack_280;
    uStack_280._4_4_ = param_5[3] + uStack_280._4_4_;
  }
  else {
    fVar73 = *(float *)(param_1 + 0x3c0) - fVar73;
    fVar74 = *(float *)(param_1 + 0x3c4) - fVar74;
    fVar60 = *(float *)(param_1 + 0x3c8) - fVar60;
    fVar26 = *(float *)(param_1 + 0x3cc) - fVar26;
    fVar59 = fVar74 * fVar74;
    auVar52._4_4_ = fVar59;
    auVar52._0_4_ = fVar73 * fVar73;
    auVar52._8_4_ = fVar60 * fVar60;
    auVar52._12_4_ = fVar26 * fVar26;
    auVar35._4_4_ = fVar59;
    auVar35._0_4_ = fVar59;
    auVar35._8_4_ = fVar59;
    auVar35._12_4_ = fVar59;
    auVar53._4_12_ = auVar52._4_12_;
    auVar53._0_4_ = fVar73 * fVar73 + fVar59 + fVar60 * fVar60;
    auVar39 = rsqrtss(auVar35,auVar53);
    fVar59 = auVar39._0_4_;
    fVar59 = (fVar27 - auVar53._0_4_ * fVar59 * fVar59) * fVar28 * fVar59;
    if (fVar59 <= 0.0) {
      fVar59 = 0.0;
    }
    uStack_280._4_4_ = *(float *)(param_1 + 0x310);
    local_288._0_4_ = uStack_280._4_4_ * fVar59 * fVar73;
    local_288._4_4_ = uStack_280._4_4_ * fVar59 * fVar74;
    uStack_280._0_4_ = uStack_280._4_4_ * fVar59 * fVar60;
    uStack_280._4_4_ = uStack_280._4_4_ * fVar59 * fVar26;
  }
  *param_5 = (float)local_288;
  param_5[1] = local_288._4_4_;
  param_5[2] = (float)uStack_280;
  param_5[3] = uStack_280._4_4_;
  fVar28 = (float)(**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))();
LAB_14032f099:
  *param_5 = *param_5 * fVar28;
  param_5[1] = param_5[1] * fVar28;
  param_5[2] = param_5[2] * fVar28;
  param_5[3] = param_5[3] * fVar28;
  return 1;
}


