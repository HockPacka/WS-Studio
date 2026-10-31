
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

