
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140373540(longlong param_1)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  byte bVar4;
  ushort uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined **ppuVar12;
  undefined1 auVar13 [12];
  int iVar14;
  undefined **ppuVar15;
  undefined8 uVar16;
  longlong lVar17;
  longlong lVar18;
  float *pfVar19;
  ulonglong uVar20;
  undefined *puVar21;
  longlong *plVar22;
  short *psVar23;
  ushort *puVar24;
  ulonglong uVar25;
  longlong lVar26;
  float *pfVar27;
  longlong lVar28;
  uint uVar29;
  ulonglong uVar30;
  float fVar31;
  float fVar32;
  wchar_t *pwVar36;
  undefined1 auVar33 [16];
  float fVar37;
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar58;
  float fVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  undefined1 auStack_a98 [32];
  undefined8 *local_a78;
  undefined ***local_a70;
  undefined4 local_a68;
  undefined4 local_a64;
  undefined **local_a58;
  longlong local_a50;
  LPVOID local_a48;
  undefined8 local_a38;
  undefined **local_a30;
  float *pfStack_a28;
  float *local_a20;
  int iStack_a18;
  undefined4 uStack_a14;
  undefined **local_a08;
  wchar_t *local_a00;
  LPVOID local_9f8;
  undefined8 local_9f0;
  undefined **local_9e8;
  wchar_t *pwStack_9e0;
  LPVOID local_9d8;
  undefined8 local_9d0;
  undefined **local_9c8;
  undefined8 local_9c0;
  LPVOID local_9b8;
  longlong local_9a8;
  longlong local_998 [256];
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  float local_168;
  float fStack_164;
  float fStack_160;
  undefined8 local_148;
  undefined8 local_140;
  float *local_138;
  undefined8 local_130;
  float *local_128;
  float *local_120;
  ulonglong local_d8;
  undefined1 auVar34 [16];
  undefined2 uVar35;
  
  local_d8 = DAT_140c0f7b0 ^ (ulonglong)auStack_a98;
  iVar14 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x28))(*(longlong **)(param_1 + 0x10),0);
  uVar20 = 0;
  if (iVar14 < 0) {
    if (iVar14 == -0x5fdcfffe) goto LAB_14037387a;
    local_a50 = 0;
    local_a58 = &PTR_LAB_140b5e648;
    local_a48 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a58);
    local_9c8 = local_a58;
    local_9c0 = local_a50;
    local_a30 = &PTR_LAB_140b5e648;
    pfStack_a28 = (float *)0x140a42c90;
    local_9b8 = local_a48;
    local_a20 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a30);
    uStack_180 = CONCAT44(uStack_a14,iVar14);
    uVar16 = *(undefined8 *)(param_1 + 0x40);
    local_a08 = &PTR_LAB_140b5e648;
    local_188 = local_a20;
    local_a30 = &PTR_FUN_140b5e640;
    local_a00 = L"FileName";
    local_198 = &PTR_FUN_140b5e640;
    uStack_190 = pfStack_a28;
    iStack_a18 = iVar14;
    local_9f8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a08);
    puVar21 = &DAT_140c8a67c;
    local_a38 = 0x141def7e0;
  }
  else {
    ppuVar15 = (undefined **)(**(code **)(**(longlong **)(param_1 + 0x18) + 0x20))();
    local_a58 = ppuVar15;
    local_a50 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x10))();
    local_a50 = local_a50 + (longlong)ppuVar15;
    local_a48 = (LPVOID)0x0;
    iVar14 = FUN_14030cac0(&local_a58,ppuVar15 + 0xc6,ppuVar15);
    if (-1 < iVar14) {
      *(undefined ***)(param_1 + 0x50) = ppuVar15;
      FUN_140327210(param_1 + 0x58,ppuVar15[0x4b] + 0x18);
      auVar40 = ZEXT816(0x70) * ZEXT416(*(uint *)(*(longlong *)(param_1 + 0x50) + 0x180));
      uVar16 = auVar40._0_8_;
      if (auVar40._8_8_ != 0) {
        uVar16 = 0xffffffffffffffff;
      }
      lVar17 = FUN_14018b280(uVar16,8);
      auVar40 = ZEXT816(0x40) * ZEXT416(*(uint *)(*(longlong *)(param_1 + 0x50) + 0x180));
      uVar16 = auVar40._0_8_;
      if (auVar40._8_8_ != 0) {
        uVar16 = 0xffffffffffffffff;
      }
      lVar18 = FUN_14018b280(uVar16,0);
      uVar25 = uVar20;
      local_9a8 = lVar18;
      if (*(int *)(*(longlong *)(param_1 + 0x50) + 0x180) != 0) {
        do {
          lVar28 = uVar25 * 0x160 + *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x188);
          pfVar27 = (float *)(uVar25 * 0x70 + lVar17);
          if (*(int *)(lVar28 + 0x10) == 0) {
            ppuVar15 = (undefined **)0x3f8000003f800000;
            pwVar36 = (wchar_t *)0x3f8000003f800000;
          }
          else {
            FUN_1401adb90(&local_9e8,*(undefined8 *)(lVar28 + 0x20));
            ppuVar15 = local_9e8;
            pwVar36 = pwStack_9e0;
          }
          *(undefined ***)pfVar27 = ppuVar15;
          *(wchar_t **)(pfVar27 + 2) = pwVar36;
          if (*(int *)(lVar28 + 0x40) != 0) {
            uVar16 = *(undefined8 *)(lVar28 + 0x50);
            fVar31 = (float)FUN_1401c9770(uVar16);
            if (1e-05 < ABS(fVar31)) {
              fVar31 = (float)FUN_1401c9770(uVar16);
              *pfVar27 = *pfVar27 / fVar31;
            }
            lVar26 = *(longlong *)(lVar28 + 0x50);
            fVar31 = (float)FUN_1401c9770(lVar26 + 2);
            if (1e-05 < ABS(fVar31)) {
              fVar31 = (float)FUN_1401c9770(lVar26 + 2);
              pfVar27[1] = pfVar27[1] / fVar31;
            }
            lVar26 = *(longlong *)(lVar28 + 0x50) + 4;
            fVar31 = (float)FUN_1401c9770(lVar26);
            if (1e-05 < ABS(fVar31)) {
              fVar31 = (float)FUN_1401c9770(lVar26);
              pfVar27[2] = pfVar27[2] / fVar31;
            }
          }
          uVar16 = uRam0000000140c78458;
          local_178 = pfVar27 + 4;
          if (*(int *)(lVar28 + 0x70) == 0) {
            *(undefined8 *)local_178 = _DAT_140c78450;
            *(undefined8 *)(pfVar27 + 6) = uVar16;
          }
          else {
            uVar30 = **(ulonglong **)(lVar28 + 0x80);
            uVar35 = (undefined2)(uVar30 >> 0x30);
            auVar34._8_4_ = 0;
            auVar34._0_8_ = uVar30;
            auVar34._12_2_ = uVar35;
            auVar34._14_2_ = uVar35;
            uVar35 = (undefined2)(uVar30 >> 0x20);
            auVar33._12_4_ = auVar34._12_4_;
            auVar33._8_2_ = 0;
            auVar33._0_8_ = uVar30;
            auVar33._10_2_ = uVar35;
            auVar40._10_6_ = auVar33._10_6_;
            auVar40._8_2_ = uVar35;
            auVar40._0_8_ = uVar30;
            uVar35 = (undefined2)(uVar30 >> 0x10);
            auVar13._4_8_ = auVar40._8_8_;
            auVar13._2_2_ = uVar35;
            auVar13._0_2_ = uVar35;
            *local_178 = (float)(int)(short)uVar30 * 6.1035156e-05;
            pfVar27[5] = (float)(auVar13._0_4_ >> 0x10) * 6.1035156e-05;
            pfVar27[6] = (float)(auVar40._8_4_ >> 0x10) * 6.1035156e-05;
            pfVar27[7] = (float)(auVar33._12_4_ >> 0x10) * 6.1035156e-05;
          }
          uStack_170 = pfVar27 + 8;
          if (*(int *)(lVar28 + 0xa0) == 0) {
            uStack_170[0] = 0.0;
            uStack_170[1] = 0.0;
            pfVar27[10] = 0.0;
            pfVar27[0xb] = 0.0;
          }
          else {
            pfVar19 = *(float **)(lVar28 + 0xb0);
            fVar31 = pfVar19[1];
            fVar52 = pfVar19[2];
            *uStack_170 = *pfVar19;
            pfVar27[9] = fVar31;
            pfVar27[10] = fVar52;
            pfVar27[0xb] = 0.0;
          }
          if (*(ushort *)(lVar28 + 4) != 0xffff) {
            pfVar19 = (float *)((ulonglong)*(ushort *)(lVar28 + 4) * 0x70 + lVar17);
            fVar31 = pfVar19[1];
            fVar52 = pfVar19[2];
            fVar53 = pfVar19[3];
            *pfVar27 = *pfVar19 * *pfVar27;
            pfVar27[1] = fVar31 * pfVar27[1];
            pfVar27[2] = fVar52 * pfVar27[2];
            pfVar27[3] = fVar53 * pfVar27[3];
            fVar31 = pfVar27[7];
            fVar52 = *local_178;
            fVar53 = pfVar19[4];
            fVar54 = pfVar19[7];
            fVar55 = pfVar27[6];
            fVar56 = pfVar19[5];
            fVar57 = pfVar27[5];
            fVar58 = pfVar19[6];
            *local_178 = (fVar53 * fVar31 + fVar52 * fVar54 + fVar55 * fVar56) - fVar57 * fVar58;
            pfVar27[5] = (fVar57 * fVar54 - fVar55 * fVar53) + fVar56 * fVar31 + fVar58 * fVar52;
            pfVar27[6] = ((fVar57 * fVar53 + fVar55 * fVar54) - fVar56 * fVar52) + fVar58 * fVar31;
            pfVar27[7] = ((fVar31 * fVar54 - fVar53 * fVar52) - fVar57 * fVar56) - fVar58 * fVar55;
            fVar31 = *uStack_170;
            fVar52 = pfVar27[9];
            fVar53 = pfVar27[10];
            fVar54 = pfVar19[0x11];
            fVar55 = pfVar19[0x12];
            fVar56 = pfVar19[0x13];
            fVar57 = pfVar19[0xd];
            fVar58 = pfVar19[0xe];
            fVar59 = pfVar19[0xf];
            fVar60 = pfVar19[0x15];
            fVar61 = pfVar19[0x16];
            fVar62 = pfVar19[0x17];
            fVar63 = pfVar19[0x19];
            fVar64 = pfVar19[0x1a];
            fVar32 = pfVar19[0x1b];
            *uStack_170 = fVar52 * pfVar19[0x10] + fVar31 * pfVar19[0xc] + fVar53 * pfVar19[0x14] +
                          pfVar19[0x18];
            pfVar27[9] = fVar52 * fVar54 + fVar31 * fVar57 + fVar53 * fVar60 + fVar63;
            pfVar27[10] = fVar52 * fVar55 + fVar31 * fVar58 + fVar53 * fVar61 + fVar64;
            pfVar27[0xb] = fVar52 * fVar56 + fVar31 * fVar59 + fVar53 * fVar62 + fVar32;
          }
          local_198 = (undefined **)0x0;
          local_148 = 0;
          uStack_190 = (float *)0x0;
          uStack_180 = 0;
          pfVar19 = pfVar27 + 0xc;
          local_140 = 0;
          local_130 = 0;
          local_188 = pfVar27;
          local_138 = pfVar27;
          local_128 = local_178;
          local_120 = uStack_170;
          FUN_1401aff00(&local_148);
          local_a30 = (undefined **)(lVar28 + 0x110);
          pfStack_a28 = pfVar19;
          local_198 = local_a30;
          uStack_190 = pfVar19;
          FUN_1401afb10(&local_198,lVar18 + uVar25 * 0x40);
          uVar29 = (int)uVar25 + 1;
          uVar25 = (ulonglong)uVar29;
        } while (uVar29 < *(uint *)(*(longlong *)(param_1 + 0x50) + 0x180));
      }
      FUN_14018b900(lVar17,0);
      lVar17 = *(longlong *)(param_1 + 0x50);
      if (*(uint *)(lVar17 + 0x1b0) != 0) {
        puVar24 = *(ushort **)(lVar17 + 0x1b8);
        uVar25 = (ulonglong)*(uint *)(lVar17 + 0x1b0);
        plVar22 = local_998;
        do {
          uVar5 = *puVar24;
          puVar24 = puVar24 + 1;
          *plVar22 = (ulonglong)uVar5 * 0x40 + lVar18;
          uVar25 = uVar25 - 1;
          plVar22 = plVar22 + 1;
        } while (uVar25 != 0);
      }
      ppuVar12 = *(undefined ***)(lVar17 + 600);
      ppuVar15 = (undefined **)(param_1 + 0x138);
      local_a30 = ppuVar15;
      local_9e8 = ppuVar12;
      FUN_140374d60(ppuVar15,*(undefined4 *)(ppuVar12 + 3));
      local_a38._0_4_ = 0;
      uVar29 = (uint)local_a38;
      local_a38._0_4_ = 0;
      if (*(int *)(ppuVar12 + 3) != 0) {
        uVar25 = uVar20;
        uVar30 = uVar20;
        fVar31 = (float)local_178;
        fVar52 = local_178._4_4_;
        fVar53 = (float)uStack_170;
        fVar54 = uStack_170._4_4_;
        fVar55 = (float)local_188;
        fVar56 = local_188._4_4_;
        fVar57 = (float)uStack_180;
        fVar58 = uStack_180._4_4_;
        fVar59 = (float)local_198;
        fVar60 = local_198._4_4_;
        fVar61 = (float)uStack_190;
        fVar62 = uStack_190._4_4_;
        fVar63 = local_168;
        fVar64 = fStack_164;
        fVar32 = fStack_160;
        do {
          pfVar27 = (float *)(*ppuVar15 + uVar20 * 0x4c);
          lVar17 = *(longlong *)(param_1 + 0xb0) * uVar20;
          if (*(int *)(param_1 + 0x108) == 1) {
            lVar18 = *(longlong *)(param_1 + 0x58);
            local_a64 = *(float *)(lVar17 + 4 + lVar18);
            fVar51 = *(float *)(lVar17 + lVar18);
            local_a68 = *(float *)(lVar17 + 8 + lVar18);
          }
          else {
            psVar23 = (short *)(lVar17 + *(longlong *)(param_1 + 0x58));
            fVar51 = (float)(int)*psVar23 * 0.0009765625;
            local_a64 = (float)(int)psVar23[1] * 0.0009765625;
            local_198 = (undefined **)CONCAT44(local_a64,fVar51);
            local_a68 = (float)(int)psVar23[2] * 0.0009765625;
          }
          pfVar19 = (float *)FUN_1407b08c0(*(longlong *)(param_1 + 0xb8) * uVar20 +
                                           *(longlong *)(param_1 + 0x60),&local_a08);
          fVar45 = *pfVar19;
          fVar47 = pfVar19[1];
          fVar49 = pfVar19[2];
          pfVar19 = (float *)FUN_1407b08c0(uVar20 * *(longlong *)(param_1 + 0xc0) +
                                           *(longlong *)(param_1 + 0x68),&local_9c8);
          fVar37 = *pfVar19;
          fVar50 = pfVar19[1];
          fVar1 = pfVar19[2];
          pfVar19 = (float *)FUN_1407b08c0(*(longlong *)(param_1 + 200) * uVar20 +
                                           *(longlong *)(param_1 + 0x70),&local_a58);
          fVar46 = *pfVar19;
          fVar48 = pfVar19[1];
          fVar2 = pfVar19[2];
          fVar6 = *(float *)(uVar20 * *(longlong *)(param_1 + 0xd0) + *(longlong *)(param_1 + 0x78))
          ;
          fVar7 = *(float *)(*(longlong *)(param_1 + 0xd8) * uVar20 + *(longlong *)(param_1 + 0x80))
          ;
          fVar8 = *(float *)(uVar20 * *(longlong *)(param_1 + 0xe0) + *(longlong *)(param_1 + 0x88))
          ;
          fVar9 = *(float *)(*(longlong *)(param_1 + 0xe8) * uVar20 + *(longlong *)(param_1 + 0x90))
          ;
          fVar10 = *(float *)(uVar20 * *(longlong *)(param_1 + 0xf0) + *(longlong *)(param_1 + 0x98)
                             );
          fVar11 = *(float *)(*(longlong *)(param_1 + 0xf8) * uVar20 + *(longlong *)(param_1 + 0xa0)
                             );
          uVar3 = *(undefined1 *)
                   (uVar20 * *(longlong *)(param_1 + 0x100) + *(longlong *)(param_1 + 0xa8));
          *pfVar27 = fVar51;
          pfVar27[1] = local_a64;
          pfVar27[3] = fVar45;
          pfVar27[6] = fVar37;
          pfVar27[9] = fVar46;
          pfVar27[0xd] = fVar7;
          pfVar27[0xc] = fVar6;
          pfVar27[4] = fVar47;
          pfVar27[7] = fVar50;
          pfVar27[10] = fVar48;
          pfVar27[5] = fVar49;
          pfVar27[8] = fVar1;
          pfVar27[0xb] = fVar2;
          pfVar27[0xe] = fVar8;
          pfVar27[0xf] = fVar9;
          pfVar27[2] = local_a68;
          pfVar27[0x10] = fVar10;
          pfVar27[0x11] = fVar11;
          *(undefined1 *)(pfVar27 + 0x12) = uVar3;
          fVar51 = pfVar27[0xd];
          if ((fVar51 != (float)uVar25) || (fVar6 != (float)uVar30)) {
            uVar30 = (ulonglong)(uint)pfVar27[0xc];
            uVar25 = (ulonglong)(uint)fVar51;
            lVar17 = 0;
            pfVar19 = (float *)local_998[uVar30 & 0xff];
            local_a64 = pfVar27[0xc];
            uVar29 = 1;
            fVar32 = (float)((uint)fVar51 & 0xff) * 0.003921569;
            fVar59 = *pfVar19 * fVar32;
            fVar60 = pfVar19[1] * fVar32;
            fVar61 = pfVar19[2] * fVar32;
            fVar62 = pfVar19[3] * fVar32;
            fVar55 = pfVar19[4] * fVar32;
            fVar56 = pfVar19[5] * fVar32;
            fVar57 = pfVar19[6] * fVar32;
            fVar58 = pfVar19[7] * fVar32;
            fVar31 = pfVar19[8] * fVar32;
            fVar52 = pfVar19[9] * fVar32;
            fVar53 = pfVar19[10] * fVar32;
            fVar54 = pfVar19[0xb] * fVar32;
            fVar63 = pfVar19[0xc] * fVar32;
            fVar64 = pfVar19[0xd] * fVar32;
            fVar32 = pfVar19[0xe] * fVar32;
            do {
              bVar4 = *(byte *)((longlong)&local_a68 + lVar17 + 1);
              local_a68 = fVar51;
              if (bVar4 == 0) break;
              lVar18 = lVar17 + 1;
              uVar29 = uVar29 + 1;
              lVar17 = lVar17 + 1;
              pfVar19 = (float *)local_998[*(byte *)((longlong)&local_a64 + lVar18)];
              fVar37 = (float)bVar4 * 0.003921569;
              fVar59 = *pfVar19 * fVar37 + fVar59;
              fVar60 = pfVar19[1] * fVar37 + fVar60;
              fVar61 = pfVar19[2] * fVar37 + fVar61;
              fVar62 = pfVar19[3] * fVar37 + fVar62;
              fVar55 = pfVar19[4] * fVar37 + fVar55;
              fVar56 = pfVar19[5] * fVar37 + fVar56;
              fVar57 = pfVar19[6] * fVar37 + fVar57;
              fVar58 = pfVar19[7] * fVar37 + fVar58;
              fVar31 = pfVar19[8] * fVar37 + fVar31;
              fVar52 = pfVar19[9] * fVar37 + fVar52;
              fVar53 = pfVar19[10] * fVar37 + fVar53;
              fVar54 = pfVar19[0xb] * fVar37 + fVar54;
              fVar63 = pfVar19[0xc] * fVar37 + fVar63;
              fVar64 = pfVar19[0xd] * fVar37 + fVar64;
              fVar32 = pfVar19[0xe] * fVar37 + fVar32;
            } while (uVar29 < 4);
          }
          fVar51 = pfVar27[2];
          fVar37 = pfVar27[1];
          fVar46 = *pfVar27;
          *pfVar27 = fVar46 * fVar59 + fVar37 * fVar55 + fVar51 * fVar31 + fVar63;
          pfVar27[1] = fVar46 * fVar60 + fVar37 * fVar56 + fVar51 * fVar52 + fVar64;
          pfVar27[2] = fVar46 * fVar61 + fVar37 * fVar57 + fVar51 * fVar53 + fVar32;
          fVar37 = fVar45 * fVar59 + fVar47 * fVar55 + fVar49 * fVar31;
          fVar46 = fVar45 * fVar60 + fVar47 * fVar56 + fVar49 * fVar52;
          fVar48 = fVar45 * fVar61 + fVar47 * fVar57 + fVar49 * fVar53;
          fVar51 = fVar45 * fVar62 + fVar47 * fVar58 + fVar49 * fVar54;
          auVar38._4_4_ = fVar46 * fVar46;
          auVar38._0_4_ = fVar37 * fVar37;
          auVar38._8_4_ = fVar48 * fVar48;
          auVar38._12_4_ = fVar51 * fVar51;
          auVar39._4_12_ = auVar38._4_12_;
          auVar39._0_4_ = fVar37 * fVar37 + fVar46 * fVar46 + fVar48 * fVar48;
          auVar40 = rsqrtss(auVar39,auVar39);
          fVar51 = auVar40._0_4_;
          pfVar27[3] = fVar51 * fVar37;
          pfVar27[4] = fVar51 * fVar46;
          pfVar27[5] = fVar51 * fVar48;
          fVar51 = pfVar27[6];
          fVar45 = fVar51 * fVar59 + fVar50 * fVar55 + fVar1 * fVar31;
          fVar47 = fVar51 * fVar60 + fVar50 * fVar56 + fVar1 * fVar52;
          fVar49 = fVar51 * fVar61 + fVar50 * fVar57 + fVar1 * fVar53;
          fVar51 = fVar51 * fVar62 + fVar50 * fVar58 + fVar1 * fVar54;
          auVar41._4_4_ = fVar47 * fVar47;
          auVar41._0_4_ = fVar45 * fVar45;
          auVar41._8_4_ = fVar49 * fVar49;
          auVar41._12_4_ = fVar51 * fVar51;
          auVar42._4_12_ = auVar41._4_12_;
          auVar42._0_4_ = fVar45 * fVar45 + fVar47 * fVar47 + fVar49 * fVar49;
          local_a38._0_4_ = (uint)local_a38 + 1;
          uVar20 = (ulonglong)(uint)local_a38;
          auVar40 = rsqrtss(auVar42,auVar42);
          fVar51 = auVar40._0_4_;
          pfVar27[6] = fVar51 * fVar45;
          pfVar27[7] = fVar51 * fVar47;
          pfVar27[8] = fVar51 * fVar49;
          fVar51 = pfVar27[0xb];
          fVar45 = pfVar27[10];
          fVar47 = pfVar27[9];
          fVar49 = fVar47 * fVar59 + fVar45 * fVar55 + fVar51 * fVar31;
          fVar37 = fVar47 * fVar60 + fVar45 * fVar56 + fVar51 * fVar52;
          fVar50 = fVar47 * fVar61 + fVar45 * fVar57 + fVar51 * fVar53;
          fVar51 = fVar47 * fVar62 + fVar45 * fVar58 + fVar51 * fVar54;
          auVar43._4_4_ = fVar37 * fVar37;
          auVar43._0_4_ = fVar49 * fVar49;
          auVar43._8_4_ = fVar50 * fVar50;
          auVar43._12_4_ = fVar51 * fVar51;
          auVar44._4_12_ = auVar43._4_12_;
          auVar44._0_4_ = fVar49 * fVar49 + fVar37 * fVar37 + fVar50 * fVar50;
          auVar40 = rsqrtss(auVar44,auVar44);
          fVar51 = auVar40._0_4_;
          pfVar27[9] = fVar51 * fVar49;
          pfVar27[10] = fVar51 * fVar37;
          pfVar27[0xb] = fVar51 * fVar50;
          ppuVar15 = local_a30;
          uVar29 = (uint)local_a38;
        } while ((uint)local_a38 < *(uint *)(local_9e8 + 3));
      }
      local_a38._0_4_ = uVar29;
      FUN_14018b900(local_9a8,0);
      return;
    }
    local_a50 = 0;
    local_a58 = &PTR_LAB_140b5e648;
    local_a48 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a58);
    local_9c8 = local_a58;
    local_9c0 = local_a50;
    local_a30 = &PTR_LAB_140b5e648;
    pfStack_a28 = (float *)0x140a42c90;
    local_9b8 = local_a48;
    local_a20 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a30);
    uVar16 = *(undefined8 *)(param_1 + 0x40);
    local_a08 = &PTR_LAB_140b5e648;
    uStack_180 = CONCAT44(uStack_a14,iVar14);
    local_a30 = &PTR_FUN_140b5e640;
    local_188 = local_a20;
    local_a00 = L"FileName";
    local_198 = &PTR_FUN_140b5e640;
    uStack_190 = pfStack_a28;
    iStack_a18 = iVar14;
    local_9f8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a08);
    puVar21 = &DAT_140c8a678;
    local_a38 = 0x141def790;
  }
  local_a08 = &PTR_LAB_140b5e638;
  local_a70 = &local_9c8;
  local_9e8 = &PTR_LAB_140b5e638;
  pwStack_9e0 = local_a00;
  local_a78 = &local_198;
  local_9d8 = local_9f8;
  local_9f0 = uVar16;
  local_9d0 = uVar16;
  iVar14 = FUN_1401971e0(puVar21,0x14,&local_a38,&local_9e8);
  local_a08 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_9f8);
  local_a30 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_a20);
  local_a58 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_a48);
  if (iVar14 != 0) {
    DebugBreak();
  }
LAB_14037387a:
  if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x18) + 8))();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  return;
}

