BLOCK-ID-CANDIDATE 16 1402ca127 FUN_1402c9db0
BLOCK-ID-CANDIDATE 16 1402d34ce FUN_1402d3300
BLOCK-ID-CANDIDATE 17 1402e77c7 FUN_1402e76e0
BLOCK-ID-CANDIDATE 27 1402e77da FUN_1402e76e0
BLOCK-ID-CANDIDATE 27 1402e7b8f FUN_1402e76e0
BLOCK-ID-CANDIDATE 16 1402e7cd0 FUN_1402e76e0
BLOCK-ID-CANDIDATE 16 1402e7d9e FUN_1402e76e0
BLOCK-ID-CANDIDATE 16 1402e7e5a FUN_1402e76e0
BLOCK-ID-CANDIDATE 16 1402e7f20 FUN_1402e76e0
BLOCK-ID-CANDIDATE 16 1402e844a FUN_1402e76e0
BLOCK-ID-CANDIDATE 13 1402e86fa FUN_1402e8680
BLOCK-ID-CANDIDATE 13 1402e870d FUN_1402e8680
BLOCK-ID-CANDIDATE 16 1402e8a42 FUN_1402e89f0
BLOCK-ID-CANDIDATE 16 1402e8a55 FUN_1402e89f0
BLOCK-ID-CANDIDATE 16 1402f4290 FUN_1402f39e0
BLOCK-ID-CANDIDATE 16 1402f42a9 FUN_1402f39e0
BLOCK-ID-CANDIDATE 16 14030a729 FUN_14030a710
BLOCK-ID-CANDIDATE 16 14030a7eb FUN_14030a7c0
BLOCK-ID-CANDIDATE 16 14032a088 FUN_1403283c0
BLOCK-ID-CANDIDATE 16 14032a2f1 FUN_1403283c0
BLOCK-ID-CANDIDATE 16 140331743 FUN_140331620
BLOCK-ID-CANDIDATE 16 140331aa8 FUN_140331990
BLOCK-ID-CANDIDATE 16 140331ac7 FUN_140331990
BLOCK-ID-CANDIDATE 17 14033334c FUN_1403331c0
BLOCK-ID-CANDIDATE 16 140335c17 FUN_1403355e0
BLOCK-ID-CANDIDATE 16 1403371ae FUN_140337160
BLOCK-ID-CANDIDATE 16 1403391aa FUN_1403390d0
BLOCK-ID-CANDIDATE 16 140339482 FUN_140339440
BLOCK-ID-CANDIDATE 16 14033bca7 FUN_14033bc50
BLOCK-ID-CANDIDATE 16 14033be32 FUN_14033bde0
BLOCK-ID-CANDIDATE 16 14033d6c8 FUN_14033d650

==== FUN_1402c9db0 @ 1402c9db0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1402c9db0(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  wchar_t *pwVar6;
  undefined1 auStackY_b48 [32];
  undefined **local_b18;
  longlong local_b10;
  LPVOID local_b08;
  wchar_t local_b00 [4];
  undefined **local_af8;
  undefined8 uStack_af0;
  undefined8 local_ae8;
  undefined8 uStack_ae0;
  undefined **local_ad8;
  wchar_t *local_ad0;
  LPVOID local_ac8;
  undefined8 local_ac0;
  undefined **local_ab8;
  longlong local_ab0;
  LPVOID local_aa8;
  undefined **local_a98;
  wchar_t *local_a90;
  LPVOID local_a88;
  undefined8 local_a80;
  undefined4 local_a78;
  undefined4 uStack_a74;
  undefined4 uStack_a70;
  undefined4 uStack_a6c;
  undefined4 local_a68;
  undefined4 uStack_a64;
  int iStack_a60;
  undefined4 uStack_a5c;
  wchar_t local_a58 [8];
  wchar_t local_a48;
  undefined1 local_a46 [510];
  wchar_t local_848 [256];
  wchar_t local_648 [256];
  wchar_t local_448 [256];
  wchar_t local_248 [264];
  ulonglong local_38;
  ulonglong uVar5;
  
  local_38 = DAT_140c0f7b0 ^ (ulonglong)auStackY_b48;
  iVar2 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0x28))(*(longlong **)(param_1 + 0x20),0);
  uVar5 = 0;
  if (-1 < iVar2) {
    uVar3 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x20))();
    *(undefined8 *)(param_1 + 0x40) = uVar3;
    local_b10 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x10))();
    local_b18 = *(undefined ***)(param_1 + 0x40);
    local_b10 = local_b10 + (longlong)local_b18;
    local_b08 = (LPVOID)0x0;
    iVar2 = FUN_1402c9270(&local_b18,local_b18 + 0x2e);
    if (-1 < iVar2) {
      iVar2 = *(int *)(*(longlong *)(param_1 + 0x40) + 0x20);
      if (iVar2 == 0) {
        return;
      }
      FUN_1402ca240(param_1 + 0x50,iVar2);
      if (*(int *)(*(longlong *)(param_1 + 0x40) + 0x20) == 0) {
        return;
      }
      while( true ) {
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28);
        _wsplitpath(*(wchar_t **)(param_1 + 0x10),local_a58,local_648,local_848,local_448);
        local_b00[0] = L'.';
        local_b00[1] = L'\0';
        local_a48 = L'\0';
        FUN_1407e4830(local_a46,0,0x1fe);
        wcscat_s(&local_a48,0x100,local_848);
        wcscat_s(&local_a48,0x100,local_b00);
        wcscat_s(&local_a48,0x100,
                 (wchar_t *)
                 (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x128) +
                 (ulonglong)
                 *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x138) +
                          (ulonglong)*(uint *)(uVar5 * 0x40 + lVar1) * 4) * 2));
        _wmakepath(local_248,local_a58,local_648,&local_a48,local_448);
        pwVar6 = (wchar_t *)(uVar5 * 0xb0 + *(longlong *)(param_1 + 0x58));
        local_af8 = (undefined **)((ulonglong)local_af8 & 0xffffffff00000000);
        local_ae8 = FUN_1402d3250;
        *(longlong *)(pwVar6 + 0x10) = param_1;
        uStack_ae0 = 0;
        uStack_af0 = pwVar6;
        iVar2 = FUN_1401b6de0();
        if (iVar2 < 0) break;
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
        if (*(uint *)(*(longlong *)(param_1 + 0x40) + 0x20) <= uVar4) {
          return;
        }
      }
      FUN_1401c5690(0x1b0,pwVar6 + 4,0);
      uVar3 = (**(code **)(**(longlong **)(pwVar6 + 4) + 0x20))();
      *(undefined8 *)(pwVar6 + 8) = uVar3;
      FUN_1407e4830(uVar3,0,0x1b0);
    }
  }
  if (iVar2 != -0x5fdcfffe) {
    local_b10 = 0;
    local_b18 = &PTR_LAB_140b5e648;
    local_b08 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_b18);
    local_ab8 = local_b18;
    local_ab0 = local_b10;
    local_af8 = &PTR_LAB_140b5e648;
    uStack_af0 = L"Result";
    local_aa8 = local_b08;
    local_ae8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_af8);
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    uStack_ae0 = CONCAT44(uStack_ae0._4_4_,iVar2);
    local_ad8 = &PTR_LAB_140b5e648;
    local_af8 = &PTR_FUN_140b5e640;
    local_a68 = (undefined4)local_ae8;
    uStack_a64 = local_ae8._4_4_;
    uStack_a5c = uStack_ae0._4_4_;
    local_ad0 = L"FileName";
    local_a78 = 0x40b5e640;
    uStack_a74 = 1;
    uStack_a70 = (undefined4)uStack_af0;
    uStack_a6c = uStack_af0._4_4_;
    iStack_a60 = iVar2;
    local_ac8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_ad8);
    local_a90 = local_ad0;
    local_ad8 = &PTR_LAB_140b5e638;
    local_a98 = &PTR_LAB_140b5e638;
    builtin_wcsncpy(local_a58,L"꩸䇞\x01",4);
    local_a88 = local_ac8;
    local_ac0 = uVar3;
    local_a80 = uVar3;
    iVar2 = FUN_1401971e0(&DAT_140c8a564,0x10,local_a58,&local_a98);
    local_ad8 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_ac8);
    local_af8 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_ae8);
    local_b18 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_b08);
    if (iVar2 != 0) {
      DebugBreak();
    }
  }
  if (*(longlong **)(param_1 + 0x28) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x28) + 8))();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  FUN_1401c5690(0x170,param_1 + 0x28,0);
  uVar3 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x20))();
  *(undefined8 *)(param_1 + 0x40) = uVar3;
  FUN_1407e4830(uVar3,0,0x170);
  return;
}



==== FUN_1402d3300 @ 1402d3300 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1402d3300(undefined8 *param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  undefined1 auStack_888 [32];
  undefined8 local_868;
  undefined ***local_860;
  undefined **local_858;
  longlong local_850;
  LPVOID local_848;
  undefined8 local_840;
  undefined **local_838;
  longlong local_830;
  LPVOID local_828;
  undefined1 local_818 [2048];
  ulonglong local_18;
  
  local_18 = DAT_140c0f7b0 ^ (ulonglong)auStack_888;
  iVar7 = (**(code **)(*(longlong *)*param_1 + 0x28))((longlong *)*param_1,0);
  if (-1 < iVar7) {
    uVar8 = (**(code **)(*(longlong *)param_1[1] + 0x20))();
    param_1[2] = uVar8;
    local_850 = (**(code **)(*(longlong *)param_1[1] + 0x10))();
    local_858 = (undefined **)param_1[2];
    local_850 = local_850 + (longlong)local_858;
    local_848 = (LPVOID)0x0;
    iVar7 = FUN_1402d2e30(&local_858,local_858 + 0x36);
    if (-1 < iVar7) {
      lVar1 = param_1[2];
      param_1[6] = lVar1 + 0x88;
      uVar8 = *(undefined8 *)(lVar1 + 0x128);
      param_1[8] = *(undefined8 *)(lVar1 + 0x120);
      param_1[9] = uVar8;
      uVar4 = *(undefined4 *)(lVar1 + 0x134);
      uVar5 = *(undefined4 *)(lVar1 + 0x138);
      uVar6 = *(undefined4 *)(lVar1 + 0x13c);
      *(undefined4 *)(param_1 + 10) = *(undefined4 *)(lVar1 + 0x130);
      *(undefined4 *)((longlong)param_1 + 0x54) = uVar4;
      *(undefined4 *)(param_1 + 0xb) = uVar5;
      *(undefined4 *)((longlong)param_1 + 0x5c) = uVar6;
      FUN_1402d4aa0(param_1 + 0x11,*(undefined4 *)(param_1[2] + 0x68));
      puVar2 = (undefined4 *)param_1[0x13];
      for (puVar9 = (undefined4 *)param_1[0x12]; puVar9 != puVar2; puVar9 = puVar9 + 1) {
        *puVar9 = 0;
      }
      FUN_1402d1490(param_1 + 0xd,*(undefined4 *)(param_1[2] + 0x180));
      puVar3 = (undefined8 *)param_1[0xf];
      for (puVar10 = (undefined8 *)param_1[0xe]; puVar10 != puVar3; puVar10 = puVar10 + 1) {
        *puVar10 = 0;
      }
      if ((*(int *)(param_1[2] + 0x38) == 0) ||
         (iVar7 = (**(code **)(*DAT_140c65670 + 0x38))
                            (DAT_140c65670,*(int *)(param_1[2] + 0x38) << 5,1,param_1 + 0xc),
         -1 < iVar7)) {
        FUN_1402d35b0(param_1);
        return;
      }
    }
  }
  if (iVar7 != -0x5fdcfffe) {
    FUN_1401b3450(local_818,0x400,iVar7);
    local_850 = 0;
    local_858 = &PTR_LAB_140b5e648;
    local_848 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_858);
    local_838 = local_858;
    local_830 = local_850;
    local_828 = local_848;
    local_868 = *(undefined8 *)(param_1[4] + 0x10);
    local_840 = 0x141deabe0;
    local_860 = &local_838;
    iVar7 = FUN_1401971e0(&DAT_140c8a568,0x10,&local_840,local_818);
    local_858 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_848);
    if (iVar7 != 0) {
      DebugBreak();
    }
  }
  if ((longlong *)param_1[0xc] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xc] + 8))();
    param_1[0xc] = 0;
  }
  if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 8))();
    param_1[1] = 0;
  }
  FUN_1401c5690(0x1b0,param_1 + 1,0);
  uVar8 = (**(code **)(*(longlong *)param_1[1] + 0x20))();
  param_1[2] = uVar8;
  FUN_1407e4830(uVar8,0,0x1b0);
  return;
}



==== FUN_1402e76e0 @ 1402e76e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1402e76e0(longlong param_1)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar11;
  float fVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  ulonglong uVar21;
  longlong lVar22;
  ulonglong uVar23;
  uint uVar24;
  int *piVar25;
  undefined1 (*pauVar26) [16];
  float *pfVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  uint uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  longlong lVar34;
  longlong lVar35;
  longlong lVar36;
  float fVar37;
  longlong lVar38;
  byte bVar39;
  uint uVar40;
  longlong lVar41;
  longlong lVar42;
  longlong lVar43;
  longlong lVar44;
  undefined1 auVar45 [16];
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
  float fVar62;
  float fVar63;
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  float fVar64;
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar70 [16];
  undefined1 auVar72 [16];
  float fVar73;
  undefined1 auVar74 [16];
  uint uVar75;
  uint uVar76;
  uint uVar77;
  uint uVar78;
  uint uVar79;
  uint uVar80;
  float fVar81;
  float fVar82;
  float fVar83;
  float fVar84;
  undefined1 auStack_698 [32];
  undefined4 local_678;
  uint local_668;
  uint local_664;
  int local_660 [4];
  int local_650 [6];
  uint local_638 [4];
  longlong *local_628;
  longlong *local_620;
  longlong *local_618;
  longlong local_610;
  longlong *local_608;
  longlong *local_600;
  longlong *local_5f8;
  longlong local_5f0;
  longlong *local_5e8;
  longlong *local_5e0;
  longlong local_5d8;
  longlong local_5d0;
  longlong local_5c8;
  longlong local_5c0;
  undefined1 local_5b8 [16];
  longlong local_5a8;
  undefined1 local_598 [16];
  longlong local_588;
  longlong local_580;
  longlong local_578;
  longlong local_570;
  longlong local_568;
  longlong local_560;
  longlong local_558;
  undefined8 local_548;
  undefined8 uStack_540;
  longlong local_538;
  longlong local_530;
  longlong local_528;
  longlong local_520;
  byte local_518 [16];
  float local_508;
  byte bStack_504;
  undefined8 local_500;
  float local_4f8 [4];
  float local_4e8 [4];
  float local_4d8 [2];
  undefined8 uStack_4d0;
  float local_3d8 [64];
  float local_2d8 [2];
  undefined8 uStack_2d0;
  undefined8 local_1d8;
  float afStack_1d0 [62];
  ulonglong local_d8;
  undefined1 auVar69 [16];
  undefined1 auVar71 [16];
  
  local_d8 = DAT_140c0f7b0 ^ (ulonglong)auStack_698;
  local_580 = param_1;
  if (*(longlong **)(param_1 + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x40) + 8))();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (*(longlong **)(param_1 + 0xc0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xc0) + 8))();
    *(undefined8 *)(param_1 + 0xc0) = 0;
  }
  if (*(longlong **)(param_1 + 200) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 200) + 8))();
    *(undefined8 *)(param_1 + 200) = 0;
  }
  if (*(longlong **)(param_1 + 0x110) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x110) + 8))();
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  if ((((*(longlong *)(param_1 + 0x108) != 0) &&
       (*(float *)(*(longlong *)(param_1 + 0x20) + 0x60) != 0.0)) &&
      ((*(byte *)(*(longlong *)(param_1 + 0x20) + 0x38) & 2) != 0)) &&
     ((iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                          (*(longlong **)(param_1 + 0x28),1), iVar13 == 0 &&
      ((iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                           (*(longlong **)(param_1 + 0x28),0x11), iVar13 == 0 ||
       (iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                           (*(longlong **)(param_1 + 0x28),0x1b), iVar13 == 0)))))) {
    local_628 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),1,&local_628);
    lVar17 = (**(code **)(*local_628 + 0x18))();
    local_620 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),1,&local_620);
    piVar18 = (int *)(**(code **)(*local_620 + 0x18))();
    FUN_1402ddac0(1,param_1 + 0x40);
    piVar19 = (int *)(**(code **)(**(longlong **)(param_1 + 0x40) + 0x18))();
    uVar33 = 0;
    *piVar19 = *piVar18;
    local_638[0] = 0;
    local_638[1] = 0;
    local_638[2] = 0;
    local_638[3] = 0;
    local_548 = 0;
    uStack_540 = 0;
    piVar19[1] = piVar18[1];
    piVar19[2] = piVar18[2];
    piVar19[3] = piVar18[3];
    local_650[3] = DAT_140c79784;
    local_660[3] = DAT_140c79784;
    local_650[1] = DAT_140c7977c;
    _local_508 = 0;
    local_500 = 0;
    local_518[0] = 0;
    local_518[1] = 0;
    local_518[2] = 0;
    local_518[3] = 0;
    local_518[4] = 0;
    local_518[5] = 0;
    local_518[6] = 0;
    local_518[7] = 0;
    local_518[8] = 0;
    local_518[9] = 0;
    local_518[10] = 0;
    local_518[0xb] = 0;
    local_518[0xc] = 0;
    local_518[0xd] = 0;
    local_518[0xe] = 0;
    local_518[0xf] = 0;
    local_660[1] = DAT_140c7977c;
    local_650[0] = DAT_140c79778;
    local_650[2] = DAT_140c79780;
    local_660[0] = DAT_140c79778;
    local_660[2] = DAT_140c79780;
    uVar32 = uVar33;
    uVar23 = uVar33;
    uVar21 = uVar33;
    do {
      iVar13 = (int)uVar21;
      fVar37 = (float)uVar23;
      if (*(int *)(((longlong)piVar18 - (longlong)local_650) +
                  (longlong)((longlong)local_650 + uVar32)) != 0) {
        *(int *)((longlong)local_650 + uVar32) = iVar13;
        *(undefined4 *)((longlong)local_638 + uVar32) = 0x3f800000;
        *(float *)((longlong)&local_508 + uVar32) = fVar37;
        pbVar2 = local_518 + uVar32;
        pbVar2[0] = 3;
        pbVar2[1] = 0;
        pbVar2[2] = 0;
        pbVar2[3] = 0;
      }
      iVar4 = *(int *)(uVar32 + lVar17);
      piVar20 = piVar19;
      uVar23 = uVar33;
      if (iVar4 != 0) {
        do {
          uVar21 = uVar33;
          piVar25 = piVar19;
          if (*piVar20 == iVar4) {
            local_660[uVar23] = iVar13;
            *(undefined4 *)((longlong)&local_548 + uVar23 * 4) = 0x3f800000;
            local_4e8[uVar23] = fVar37;
            local_4f8[uVar23] = 4.2039e-45;
            if ((uint)uVar23 < 4) goto LAB_1402e7a05;
            break;
          }
          uVar24 = (uint)uVar23 + 1;
          piVar20 = piVar20 + 1;
          uVar23 = (ulonglong)uVar24;
        } while (uVar24 < 4);
        do {
          if (*piVar25 == 0) {
            piVar19[uVar21] = iVar4;
            local_660[uVar21] = iVar13;
            *(undefined4 *)((longlong)&local_548 + uVar21 * 4) = 0x3f800000;
            local_4e8[uVar21] = fVar37;
            local_4f8[uVar21] = 4.2039e-45;
            break;
          }
          uVar24 = (int)uVar21 + 1;
          uVar21 = (ulonglong)uVar24;
          piVar25 = piVar25 + 1;
        } while (uVar24 < 4);
      }
LAB_1402e7a05:
      uVar23 = (ulonglong)((int)fVar37 + 2U);
      uVar21 = (ulonglong)(iVar13 + 1);
      uVar32 = uVar32 + 4;
    } while ((int)fVar37 + 2U < 8);
    local_538 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x18))();
    local_5e8 = (longlong *)0x0;
    local_608 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x11,&local_5e8);
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x12,&local_608);
    local_570 = (**(code **)(*local_5e8 + 0x18))();
    lVar22 = (**(code **)(*local_608 + 0x18))();
    local_5f8 = (longlong *)0x0;
    local_600 = (longlong *)0x0;
    local_5a8 = lVar22;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x11,&local_5f8);
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x12,&local_600);
    local_528 = (**(code **)(*local_5f8 + 0x18))();
    lVar17 = (**(code **)(*local_600 + 0x18))();
    local_5d8 = 0;
    local_5d0 = 0;
    local_5c8 = lVar17;
    iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                       (*(longlong **)(param_1 + 0x28),0x11);
    if (iVar13 == 0) {
      FUN_1402ddac0(0x11,param_1 + 0xc0);
      FUN_1402ddac0(0x12,param_1 + 200);
      local_5d8 = (**(code **)(**(longlong **)(param_1 + 0xc0) + 0x18))();
      local_5d0 = (**(code **)(**(longlong **)(param_1 + 200) + 0x18))();
    }
    local_618 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x1b,&local_618);
    local_588 = (**(code **)(*local_618 + 0x18))();
    local_5e0 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x1b,&local_5e0);
    local_560 = (**(code **)(*local_5e0 + 0x18))();
    local_610 = 0;
    iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                       (*(longlong **)(param_1 + 0x28),0x1b);
    if (iVar13 == 0) {
      FUN_1402ddac0(0x1b,param_1 + 0x110);
      local_610 = (**(code **)(**(longlong **)(param_1 + 0x110) + 0x18))();
    }
    fVar12 = DAT_140b79ed0;
    fVar11 = DAT_140b79e48;
    fVar37 = DAT_140b79d20;
    auVar7._4_4_ = local_638[1];
    auVar7._0_4_ = local_638[0];
    auVar7._8_4_ = local_638[2];
    auVar7._12_4_ = local_638[3];
    local_664 = 0;
    uVar24 = _DAT_140b608c0;
    uVar16 = _UNK_140b608c4;
    uVar75 = _UNK_140b608c8;
    uVar76 = _UNK_140b608cc;
    fVar73 = _DAT_140c58780;
    fVar49 = fRam0000000140c58784;
    fVar52 = fRam0000000140c58788;
    fVar55 = fRam0000000140c5878c;
    uVar77 = _DAT_140b60d90;
    uVar78 = _UNK_140b60d94;
    uVar79 = _UNK_140b60d98;
    uVar80 = _UNK_140b60d9c;
    fVar81 = DAT_140b60de0;
    fVar82 = _UNK_140b60de4;
    fVar83 = _UNK_140b60de8;
    fVar84 = _UNK_140b60dec;
    do {
      local_668 = 0;
      uVar40 = local_664;
      do {
        auVar74._0_4_ = ~uVar24 & _DAT_140b60900;
        auVar74._4_4_ = ~uVar16 & _UNK_140b60904;
        auVar74._8_4_ = ~uVar75 & _UNK_140b60908;
        auVar74._12_4_ = ~uVar76 & _UNK_140b6090c;
        local_558 = (longlong)(int)(local_668 * DAT_140c41720 + uVar40 * DAT_140c41724);
        uVar31 = *(uint *)(local_558 + local_570);
        uVar14 = *(uint *)(local_558 + 2 + local_570);
        auVar58._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar58._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar58._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar58._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar65._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar65._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar65._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar65._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar58 = auVar58 | auVar74;
        auVar65 = auVar65 | auVar74;
        fVar47 = auVar58._0_4_;
        fVar50 = auVar58._4_4_;
        fVar53 = auVar58._8_4_;
        fVar56 = auVar58._12_4_;
        if (*(ushort *)(local_558 + 2 + local_570) < *(ushort *)(local_558 + local_570)) {
          fVar57 = auVar65._0_4_ - fVar47;
          fVar62 = auVar65._4_4_ - fVar50;
          fVar63 = auVar65._8_4_ - fVar53;
          fVar64 = auVar65._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar65._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar65._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar65._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar65._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + local_570);
        lVar36 = 0x10;
        pauVar26 = (undefined1 (*) [16])local_4d8;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar58;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar65;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar36 = lVar36 + -1;
        } while (lVar36 != 0);
        uVar31 = *(uint *)(local_558 + lVar22);
        uVar14 = *(uint *)(local_558 + 2 + lVar22);
        auVar59._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar59._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar59._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar59._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar66._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar66._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar66._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar66._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar59 = auVar59 | auVar74;
        auVar66 = auVar66 | auVar74;
        fVar47 = auVar59._0_4_;
        fVar50 = auVar59._4_4_;
        fVar53 = auVar59._8_4_;
        fVar56 = auVar59._12_4_;
        if (*(ushort *)(local_558 + 2 + lVar22) < *(ushort *)(local_558 + lVar22)) {
          fVar57 = auVar66._0_4_ - fVar47;
          fVar62 = auVar66._4_4_ - fVar50;
          fVar63 = auVar66._8_4_ - fVar53;
          fVar64 = auVar66._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar66._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar66._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar66._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar66._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + lVar22);
        pauVar26 = (undefined1 (*) [16])local_2d8;
        lVar22 = 0x10;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar59;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar66;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar22 = lVar22 + -1;
        } while (lVar22 != 0);
        uVar31 = *(uint *)(local_558 + local_528);
        uVar14 = *(uint *)(local_558 + 2 + local_528);
        auVar60._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar60._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar60._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar60._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar67._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar67._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar67._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar67._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar60 = auVar60 | auVar74;
        auVar67 = auVar67 | auVar74;
        fVar47 = auVar60._0_4_;
        fVar50 = auVar60._4_4_;
        fVar53 = auVar60._8_4_;
        fVar56 = auVar60._12_4_;
        if (*(ushort *)(local_558 + 2 + local_528) < *(ushort *)(local_558 + local_528)) {
          fVar57 = auVar67._0_4_ - fVar47;
          fVar62 = auVar67._4_4_ - fVar50;
          fVar63 = auVar67._8_4_ - fVar53;
          fVar64 = auVar67._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar67._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar67._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar67._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar67._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + local_528);
        lVar22 = 0x10;
        pauVar26 = (undefined1 (*) [16])local_3d8;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar60;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar67;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar22 = lVar22 + -1;
        } while (lVar22 != 0);
        uVar31 = *(uint *)(local_558 + lVar17);
        uVar14 = *(uint *)(local_558 + 2 + lVar17);
        auVar61._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar61._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar61._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar61._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar68._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar68._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar68._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar68._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar61 = auVar61 | auVar74;
        auVar68 = auVar68 | auVar74;
        fVar47 = auVar61._0_4_;
        fVar50 = auVar61._4_4_;
        fVar53 = auVar61._8_4_;
        fVar56 = auVar61._12_4_;
        if (*(ushort *)(local_558 + 2 + lVar17) < *(ushort *)(local_558 + lVar17)) {
          fVar57 = auVar68._0_4_ - fVar47;
          fVar62 = auVar68._4_4_ - fVar50;
          fVar63 = auVar68._8_4_ - fVar53;
          fVar64 = auVar68._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar68._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar68._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar68._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar68._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + lVar17);
        pauVar26 = (undefined1 (*) [16])&local_1d8;
        lVar17 = 0x10;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar61;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar68;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        uVar31 = uVar40 * 4;
        uVar14 = local_668 * 4;
        lVar22 = 0;
        uVar15 = uVar31 + 4;
        local_638[2] = uVar14 + 4;
        local_638[0] = uVar14;
        local_638[1] = uVar31;
        local_5f0 = 0;
        local_638[3] = uVar15;
        lVar17 = 0;
        lVar36 = local_558;
        if ((int)uVar31 < (int)uVar15) {
          lVar43 = (longlong)(int)uVar31;
          do {
            if ((int)uVar14 < (int)local_638[2]) {
              lVar42 = (longlong)local_660[0];
              lVar36 = (longlong)local_650[0];
              lVar17 = (longlong)local_650[1];
              lVar38 = (longlong)local_650[2];
              lVar41 = (longlong)local_650[3];
              lVar34 = lVar22 << 4;
              local_530 = lVar42;
              local_5c0 = lVar36;
              local_578 = lVar17;
              local_5f0 = local_5f0 + (ulonglong)(local_638[2] - uVar14);
              local_520 = lVar38;
              local_568 = lVar41;
              lVar44 = (longlong)(int)uVar14;
              lVar35 = lVar34;
              uVar24 = uVar14;
              do {
                fVar73 = 0.0;
                if ((uVar31 < 0x41) && (uVar24 < 0x41)) {
                  fVar73 = (float)*(byte *)(DAT_140c4191c * lVar43 + 1 +
                                           DAT_140c41918 * lVar44 + local_538) * fVar37 *
                           *(float *)(*(longlong *)(local_580 + 0x20) + 0x60);
                  lVar36 = local_5c0;
                }
                if (fVar11 <= *(float *)((longlong)&uStack_4d0 + lVar34 + 4)) {
                  local_4f8[0] = (_DAT_140b7a790 * *(float *)((longlong)local_2d8 + lVar34) +
                                 *(float *)((longlong)local_4d8 + lVar34)) - _DAT_140b7b240;
                  local_4f8[1] = (_UNK_140b7a794 * *(float *)((longlong)local_2d8 + lVar34 + 4) +
                                 *(float *)((longlong)local_4d8 + lVar34 + 4)) - _UNK_140b7b244;
                  local_4f8[2] = (_UNK_140b7a798 * *(float *)((longlong)&uStack_2d0 + lVar34) +
                                 *(float *)((longlong)&uStack_4d0 + lVar34)) - DAT_140b7b248;
                  local_4f8[3] = ((fVar12 - local_4f8[0]) - local_4f8[1]) - local_4f8[2];
                  auVar9._4_4_ = local_4f8[1];
                  auVar9._0_4_ = local_4f8[0];
                  auVar9._8_4_ = local_4f8[2];
                  auVar9._12_4_ = local_4f8[3];
                  auVar58 = maxps(ZEXT816(0),auVar9);
                  auVar6._4_4_ = _UNK_140b7b244;
                  auVar6._0_4_ = _DAT_140b7b240;
                  auVar6._8_4_ = DAT_140b7b248;
                  auVar6._12_4_ = _UNK_140b7b24c;
                  local_5b8 = minps(auVar58,auVar6);
                }
                else {
                  local_5b8 = ZEXT816(0);
                }
                auVar58 = *(undefined1 (*) [16])((longlong)&local_1d8 + lVar34);
                lVar22 = (longlong)local_660[1];
                auVar70._4_4_ = *(undefined4 *)(local_5b8 + (longlong)local_660[2] * 4);
                auVar70._0_4_ = *(undefined4 *)(local_5b8 + lVar42 * 4);
                fVar49 = *(float *)((longlong)local_3d8 + lVar34);
                fVar52 = *(float *)((longlong)local_3d8 + lVar34 + 4);
                fVar55 = *(float *)((longlong)local_3d8 + lVar34 + 8);
                fVar81 = *(float *)((longlong)local_3d8 + lVar34 + 0xc);
                auVar70._8_4_ = *(undefined4 *)(local_5b8 + (longlong)local_660[2] * 4);
                auVar70._12_4_ = *(undefined4 *)(local_5b8 + (longlong)local_660[3] * 4);
                auVar69._8_8_ = auVar70._8_8_;
                auVar69._4_4_ = *(undefined4 *)(local_5b8 + lVar22 * 4);
                auVar69._0_4_ = *(undefined4 *)(local_5b8 + lVar42 * 4);
                auVar8._8_8_ = uStack_540;
                auVar8._0_8_ = local_548;
                auVar65 = minps(auVar69,auVar8);
                *(float *)((longlong)local_4d8 + lVar34) = auVar65._0_4_ * fVar73;
                *(float *)((longlong)local_4d8 + lVar34 + 4) = auVar65._4_4_ * fVar73;
                *(float *)((longlong)&uStack_4d0 + lVar34) = auVar65._8_4_ * fVar73;
                *(float *)((longlong)&uStack_4d0 + lVar34 + 4) = auVar65._12_4_ * fVar73;
                if (fVar11 <= fVar81) {
                  local_4e8[0] = (_DAT_140b7a790 * auVar58._0_4_ + fVar49) - _DAT_140b7b240;
                  local_4e8[1] = (_UNK_140b7a794 * auVar58._4_4_ + fVar52) - _UNK_140b7b244;
                  local_4e8[2] = (_UNK_140b7a798 * auVar58._8_4_ + fVar55) - DAT_140b7b248;
                  local_4e8[3] = ((fVar12 - local_4e8[0]) - local_4e8[1]) - local_4e8[2];
                  auVar10._4_4_ = local_4e8[1];
                  auVar10._0_4_ = local_4e8[0];
                  auVar10._8_4_ = local_4e8[2];
                  auVar10._12_4_ = local_4e8[3];
                  auVar58 = maxps(ZEXT816(0),auVar10);
                  auVar5._4_4_ = _UNK_140b7b244;
                  auVar5._0_4_ = _DAT_140b7b240;
                  auVar5._8_4_ = DAT_140b7b248;
                  auVar5._12_4_ = _UNK_140b7b24c;
                  local_598 = minps(auVar58,auVar5);
                }
                else {
                  local_598 = ZEXT816(0);
                }
                auVar72._4_4_ = *(undefined4 *)(local_598 + lVar38 * 4);
                auVar72._0_4_ = *(undefined4 *)(local_598 + lVar36 * 4);
                fVar73 = fVar12 - fVar73;
                auVar72._8_4_ = *(undefined4 *)(local_598 + lVar38 * 4);
                auVar72._12_4_ = *(undefined4 *)(local_598 + lVar41 * 4);
                auVar71._8_8_ = auVar72._8_8_;
                auVar71._4_4_ = *(undefined4 *)(local_598 + lVar17 * 4);
                auVar71._0_4_ = *(undefined4 *)(local_598 + lVar36 * 4);
                auVar58 = minps(auVar71,auVar7);
                *(float *)((longlong)local_3d8 + lVar34) = fVar73 * auVar58._0_4_;
                *(float *)((longlong)local_3d8 + lVar34 + 4) = fVar73 * auVar58._4_4_;
                *(float *)((longlong)local_3d8 + lVar34 + 8) = fVar73 * auVar58._8_4_;
                *(float *)((longlong)local_3d8 + lVar34 + 0xc) = fVar73 * auVar58._12_4_;
                if (((local_610 != 0) && (uVar31 < 0x40)) && (uVar24 < 0x40)) {
                  lVar17 = (longlong)(int)(DAT_140c41950 * uVar24 + uVar31 * DAT_140c41954);
                  bVar3 = *(byte *)(lVar17 + local_588);
                  bVar30 = *(byte *)(lVar17 + local_560);
                  bVar39 = bVar30;
                  if (*(float *)((longlong)local_3d8 + lVar35 + 0xc) <
                      *(float *)((longlong)&uStack_4d0 + lVar35 + 4)) {
                    bVar39 = bVar3;
                  }
                  bVar28 = bVar30;
                  if (*(float *)((longlong)local_3d8 + lVar35 + 8) <
                      *(float *)((longlong)&uStack_4d0 + lVar35)) {
                    bVar28 = bVar3;
                  }
                  bVar29 = bVar30;
                  if (*(float *)((longlong)local_3d8 + lVar35 + 4) <
                      *(float *)((longlong)local_4d8 + lVar35 + 4)) {
                    bVar29 = bVar3;
                  }
                  if (*(float *)((longlong)local_3d8 + lVar35) <
                      *(float *)((longlong)local_4d8 + lVar35)) {
                    bVar30 = bVar3;
                  }
                  *(byte *)(lVar17 + local_610) =
                       (((bVar39 >> (local_500._4_1_ & 0x1f) & local_518[0xc]) << 2 |
                        bVar28 >> ((byte)local_500 & 0x1f) & local_518[8]) << 2 |
                       bVar29 >> (bStack_504 & 0x1f) & local_518[4]) << 2 |
                       bVar30 >> (local_508._0_1_ & 0x1f) & local_518[0];
                  lVar22 = local_610;
                  lVar36 = local_5c0;
                  lVar17 = local_578;
                  lVar38 = local_520;
                  lVar41 = local_568;
                  lVar42 = local_530;
                }
                fVar73 = *(float *)((longlong)local_3d8 + lVar34) +
                         *(float *)((longlong)local_4d8 + lVar34);
                fVar49 = *(float *)((longlong)local_3d8 + lVar34 + 4) +
                         *(float *)((longlong)local_4d8 + lVar34 + 4);
                fVar52 = *(float *)((longlong)local_3d8 + lVar34 + 8) +
                         *(float *)((longlong)&uStack_4d0 + lVar34);
                fVar55 = *(float *)((longlong)local_3d8 + lVar34 + 0xc) +
                         *(float *)((longlong)&uStack_4d0 + lVar34 + 4);
                *(float *)((longlong)local_4d8 + lVar34) = fVar73;
                *(float *)((longlong)local_4d8 + lVar34 + 4) = fVar49;
                *(float *)((longlong)&uStack_4d0 + lVar34) = fVar52;
                *(float *)((longlong)&uStack_4d0 + lVar34 + 4) = fVar55;
                auVar45._4_4_ = -(uint)(fVar49 != 0.0);
                auVar45._0_4_ = -(uint)(fVar73 != 0.0);
                auVar45._8_4_ = -(uint)(fVar52 != 0.0);
                auVar45._12_4_ = -(uint)(fVar55 != 0.0);
                iVar13 = movmskps((int)lVar22,auVar45);
                if (iVar13 != 0) {
                  *(undefined4 *)((longlong)&uStack_4d0 + lVar34 + 4) = 0x3f800000;
                }
                uVar24 = uVar24 + 1;
                lVar35 = lVar35 + 0x10;
                lVar34 = lVar34 + 0x10;
                lVar44 = lVar44 + 1;
                lVar22 = local_5f0;
                uVar14 = local_638[0];
                uVar15 = local_638[3];
              } while ((int)uVar24 < (int)local_638[2]);
            }
            uVar31 = uVar31 + 1;
            lVar43 = lVar43 + 1;
            lVar36 = local_558;
            uVar24 = _DAT_140b608c0;
            uVar16 = _UNK_140b608c4;
            uVar75 = _UNK_140b608c8;
            uVar76 = _UNK_140b608cc;
            fVar73 = _DAT_140c58780;
            fVar49 = fRam0000000140c58784;
            fVar52 = fRam0000000140c58788;
            fVar55 = fRam0000000140c5878c;
            uVar77 = _DAT_140b60d90;
            uVar78 = _UNK_140b60d94;
            uVar79 = _UNK_140b60d98;
            uVar80 = _UNK_140b60d9c;
            fVar81 = DAT_140b60de0;
            fVar82 = _UNK_140b60de4;
            fVar83 = _UNK_140b60de8;
            fVar84 = _UNK_140b60dec;
            uVar40 = local_664;
          } while ((int)uVar31 < (int)uVar15);
        }
        if (local_5d8 != 0) {
          uVar32 = 0;
          do {
            uVar23 = uVar32 + 0x10;
            *(undefined8 *)((longlong)&local_1d8 + uVar32) =
                 *(undefined8 *)((longlong)local_4d8 + uVar32);
            *(undefined8 *)((longlong)afStack_1d0 + uVar32) =
                 *(undefined8 *)((longlong)&uStack_4d0 + uVar32);
            uVar32 = uVar23;
          } while (uVar23 < 0x100);
          puVar1 = (uint *)(lVar36 + local_5d8);
          local_678 = 0x40000;
          FUN_140267380(puVar1,&local_1d8,CONCAT71((int7)((ulonglong)lVar17 >> 8),1));
          uVar24 = *puVar1;
          uVar16 = *(uint *)((longlong)puVar1 + 2);
          fVar73 = (float)((uint)((float)(int)(uVar24 & _UNK_140b60d98) * _UNK_140b60de8 *
                                 fRam0000000140c58788) & _DAT_140b608c0 |
                          ~_DAT_140b608c0 & _DAT_140b60900);
          fVar49 = (float)((uint)((float)(int)(uVar24 & _UNK_140b60d94) * _UNK_140b60de4 *
                                 fRam0000000140c58784) & _UNK_140b608c4 |
                          ~_UNK_140b608c4 & _UNK_140b60904);
          fVar52 = (float)((uint)((float)(int)(uVar24 & _DAT_140b60d90) * DAT_140b60de0 *
                                 _DAT_140c58780) & _UNK_140b608c8 | ~_UNK_140b608c8 & _UNK_140b60908
                          );
          fVar55 = (float)((uint)((float)(int)(uVar24 & _UNK_140b60d9c) * _UNK_140b60dec *
                                 fRam0000000140c5878c) & _UNK_140b608cc |
                          ~_UNK_140b608cc & _UNK_140b6090c);
          fVar81 = (float)((uint)((float)(int)(uVar16 & _UNK_140b60d98) * _UNK_140b60de8 *
                                 fRam0000000140c58788) & _DAT_140b608c0 |
                          ~_DAT_140b608c0 & _DAT_140b60900);
          fVar82 = (float)((uint)((float)(int)(uVar16 & _UNK_140b60d94) * _UNK_140b60de4 *
                                 fRam0000000140c58784) & _UNK_140b608c4 |
                          ~_UNK_140b608c4 & _UNK_140b60904);
          fVar83 = (float)((uint)((float)(int)(uVar16 & _DAT_140b60d90) * DAT_140b60de0 *
                                 _DAT_140c58780) & _UNK_140b608c8 | ~_UNK_140b608c8 & _UNK_140b60908
                          );
          fVar84 = (float)((uint)((float)(int)(uVar16 & _UNK_140b60d9c) * _UNK_140b60dec *
                                 fRam0000000140c5878c) & _UNK_140b608cc |
                          ~_UNK_140b608cc & _UNK_140b6090c);
          if (*(ushort *)((longlong)puVar1 + 2) < (ushort)*puVar1) {
            fVar47 = _DAT_140b7ac10 * (fVar81 - fVar73);
            fVar50 = _UNK_140b7ac14 * (fVar82 - fVar49);
            fVar53 = _UNK_140b7ac18 * (fVar83 - fVar52);
            fVar56 = _UNK_140b7ac1c * (fVar84 - fVar55);
            fVar57 = _DAT_140b7ac70 * (fVar81 - fVar73) + fVar73;
            fVar62 = _UNK_140b7ac74 * (fVar82 - fVar49) + fVar49;
            fVar63 = _UNK_140b7ac78 * (fVar83 - fVar52) + fVar52;
            fVar64 = _UNK_140b7ac7c * (fVar84 - fVar55) + fVar55;
          }
          else {
            fVar57 = 0.0;
            fVar62 = 0.0;
            fVar63 = 0.0;
            fVar64 = 0.0;
            fVar47 = (fVar81 - fVar73) * _DAT_140b7ac50;
            fVar50 = (fVar82 - fVar49) * _UNK_140b7ac54;
            fVar53 = (fVar83 - fVar52) * _UNK_140b7ac58;
            fVar56 = (fVar84 - fVar55) * _UNK_140b7ac5c;
          }
          uVar24 = puVar1[1];
          pfVar27 = local_2d8;
          lVar17 = 0x10;
          do {
            uVar16 = uVar24 & 3;
            if (uVar16 == 0) {
              *pfVar27 = fVar73;
              pfVar27[1] = fVar49;
              pfVar27[2] = fVar52;
              pfVar27[3] = fVar55;
            }
            else if (uVar16 == 1) {
              *pfVar27 = fVar81;
              pfVar27[1] = fVar82;
              pfVar27[2] = fVar83;
              pfVar27[3] = fVar84;
            }
            else if (uVar16 == 2) {
              *pfVar27 = fVar47 + fVar73;
              pfVar27[1] = fVar50 + fVar49;
              pfVar27[2] = fVar53 + fVar52;
              pfVar27[3] = fVar56 + fVar55;
            }
            else {
              *pfVar27 = fVar57;
              pfVar27[1] = fVar62;
              pfVar27[2] = fVar63;
              pfVar27[3] = fVar64;
            }
            pfVar27 = pfVar27 + 4;
            uVar24 = uVar24 >> 2;
            lVar17 = lVar17 + -1;
          } while (lVar17 != 0);
          uVar32 = 0;
          do {
            fVar73 = *(float *)((longlong)local_4d8 + uVar32 + 4);
            fVar49 = *(float *)((longlong)&uStack_4d0 + uVar32);
            uVar23 = uVar32 + 0x10;
            fVar52 = *(float *)((longlong)&uStack_2d0 + uVar32);
            *(float *)((longlong)local_2d8 + uVar32) =
                 (_DAT_140b7ac50 +
                 (*(float *)((longlong)local_4d8 + uVar32) -
                 *(float *)((longlong)local_2d8 + uVar32)) * _DAT_140b7ac50) * _DAT_140b7b1b0;
            *(float *)((longlong)local_2d8 + uVar32 + 4) =
                 (_UNK_140b7ac54 +
                 (fVar73 - *(float *)((longlong)local_2d8 + uVar32 + 4)) * _UNK_140b7ac54) *
                 _UNK_140b7b1b4;
            *(float *)((longlong)&uStack_2d0 + uVar32) =
                 (_UNK_140b7ac58 + (fVar49 - fVar52) * _UNK_140b7ac58) * _UNK_140b7b1b8;
            *(float *)((longlong)&uStack_2d0 + uVar32 + 4) = fVar12 * _UNK_140b7b1bc;
            uVar32 = uVar23;
          } while (uVar23 < 0x100);
          uVar32 = 0;
          do {
            uVar23 = uVar32 + 0x10;
            *(undefined8 *)((longlong)&local_1d8 + uVar32) =
                 *(undefined8 *)((longlong)local_2d8 + uVar32);
            *(undefined8 *)((longlong)afStack_1d0 + uVar32) =
                 *(undefined8 *)((longlong)&uStack_2d0 + uVar32);
            uVar32 = uVar23;
          } while (uVar23 < 0x100);
          local_678 = 0x40000;
          FUN_140267380(local_5d0 + lVar36,&local_1d8,1);
          uVar24 = _DAT_140b608c0;
          uVar16 = _UNK_140b608c4;
          uVar75 = _UNK_140b608c8;
          uVar76 = _UNK_140b608cc;
          fVar73 = _DAT_140c58780;
          fVar49 = fRam0000000140c58784;
          fVar52 = fRam0000000140c58788;
          fVar55 = fRam0000000140c5878c;
          uVar77 = _DAT_140b60d90;
          uVar78 = _UNK_140b60d94;
          uVar79 = _UNK_140b60d98;
          uVar80 = _UNK_140b60d9c;
          fVar81 = DAT_140b60de0;
          fVar82 = _UNK_140b60de4;
          fVar83 = _UNK_140b60de8;
          fVar84 = _UNK_140b60dec;
          uVar40 = local_664;
        }
        local_668 = local_668 + 1;
        lVar17 = local_5c8;
        lVar22 = local_5a8;
      } while (local_668 < 0x11);
      local_664 = uVar40 + 1;
    } while (local_664 < 0x11);
    if (local_5e0 != (longlong *)0x0) {
      (**(code **)(*local_5e0 + 8))();
    }
    if (local_618 != (longlong *)0x0) {
      (**(code **)(*local_618 + 8))();
    }
    if (local_600 != (longlong *)0x0) {
      (**(code **)(*local_600 + 8))();
    }
    if (local_5f8 != (longlong *)0x0) {
      (**(code **)(*local_5f8 + 8))();
    }
    if (local_608 != (longlong *)0x0) {
      (**(code **)(*local_608 + 8))();
    }
    if (local_5e8 != (longlong *)0x0) {
      (**(code **)(*local_5e8 + 8))();
    }
    if (local_620 != (longlong *)0x0) {
      (**(code **)(*local_620 + 8))();
    }
    if (local_628 != (longlong *)0x0) {
      (**(code **)(*local_628 + 8))();
    }
  }
  return;
}



==== FUN_1402e8680 @ 1402e8680 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1402e8680(longlong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  float fVar13;
  undefined1 auStack_2c8 [32];
  uint local_2a8;
  uint local_2a4;
  longlong *local_2a0;
  longlong *local_298;
  longlong local_290;
  uint local_288;
  uint local_284;
  int local_280;
  int local_27c;
  longlong local_278;
  longlong local_270;
  longlong local_268;
  float local_258 [64];
  float local_158 [64];
  ulonglong local_58;
  
  local_58 = DAT_140c0f7b0 ^ (ulonglong)auStack_2c8;
  if (*(longlong **)(param_1 + 0xa0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xa0) + 8))();
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  if ((((*(longlong *)(param_1 + 0x108) != 0) &&
       (*(float *)(*(longlong *)(param_1 + 0x20) + 0x60) != 0.0)) &&
      ((*(byte *)(*(longlong *)(param_1 + 0x20) + 0x38) & 2) != 0)) &&
     ((iVar5 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x40))
                         (*(longlong **)(param_1 + 0x18),0xd), iVar5 == 0 ||
      (iVar5 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                         (*(longlong **)(param_1 + 0x28),0xd), iVar5 == 0)))) {
    lVar6 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x18))();
    local_2a0 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0xd,&local_2a0);
    lVar7 = (**(code **)(*local_2a0 + 0x18))();
    local_298 = (longlong *)0x0;
    local_290 = lVar7;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))(*(longlong **)(param_1 + 0x28),0xd);
    lVar8 = (**(code **)(*local_298 + 0x18))();
    local_278 = lVar8;
    FUN_1402ddac0(0xd,param_1 + 0xa0);
    local_268 = (**(code **)(**(longlong **)(param_1 + 0xa0) + 0x18))();
    fVar4 = DAT_140b79d20;
    local_2a4 = 0;
    do {
      local_2a8 = 0;
      do {
        lVar10 = (longlong)(int)(DAT_140c41640 * local_2a8 + DAT_140c41644 * local_2a4);
        local_270 = lVar10;
        FUN_140268060(local_258,lVar10 + lVar8);
        FUN_140268060(local_158,lVar10 + lVar7);
        lVar7 = 0;
        local_288 = local_2a8 * 4;
        local_284 = local_2a4 * 4;
        local_280 = local_288 + 4;
        local_27c = local_284 + 4;
        if ((int)local_284 < local_27c) {
          lVar10 = (longlong)(int)local_284;
          uVar11 = local_284;
          do {
            if ((int)local_288 < local_280) {
              lVar12 = (longlong)(int)local_288;
              lVar8 = lVar7 << 4;
              lVar7 = lVar7 + (ulonglong)(local_280 + local_2a8 * -4);
              uVar9 = local_288;
              do {
                fVar13 = 0.0;
                if ((uVar11 < 0x41) && (uVar9 < 0x41)) {
                  fVar13 = (float)*(byte *)(DAT_140c41918 * lVar12 + 2 +
                                           DAT_140c4191c * lVar10 + lVar6) * fVar4 *
                           *(float *)(*(longlong *)(param_1 + 0x20) + 0x60);
                }
                fVar1 = *(float *)((longlong)local_158 + lVar8 + 4);
                fVar2 = *(float *)((longlong)local_158 + lVar8 + 8);
                fVar3 = *(float *)((longlong)local_158 + lVar8 + 0xc);
                uVar9 = uVar9 + 1;
                lVar12 = lVar12 + 1;
                *(float *)((longlong)local_258 + lVar8) =
                     (*(float *)((longlong)local_258 + lVar8) -
                     *(float *)((longlong)local_158 + lVar8)) * fVar13 +
                     *(float *)((longlong)local_158 + lVar8);
                *(float *)((longlong)local_258 + lVar8 + 4) =
                     (*(float *)((longlong)local_258 + lVar8 + 4) - fVar1) * fVar13 + fVar1;
                *(float *)((longlong)local_258 + lVar8 + 8) =
                     (*(float *)((longlong)local_258 + lVar8 + 8) - fVar2) * fVar13 + fVar2;
                *(float *)((longlong)local_258 + lVar8 + 0xc) =
                     (*(float *)((longlong)local_258 + lVar8 + 0xc) - fVar3) * fVar13 + fVar3;
                lVar8 = lVar8 + 0x10;
              } while ((int)uVar9 < local_280);
            }
            uVar11 = uVar11 + 1;
            lVar10 = lVar10 + 1;
            lVar8 = local_278;
          } while ((int)uVar11 < local_27c);
        }
        FUN_140268120(local_268 + local_270,local_258,0);
        local_2a8 = local_2a8 + 1;
        lVar7 = local_290;
      } while (local_2a8 < 0x11);
      local_2a4 = local_2a4 + 1;
    } while (local_2a4 < 0x11);
    if (local_298 != (longlong *)0x0) {
      (**(code **)(*local_298 + 8))();
    }
    if (local_2a0 != (longlong *)0x0) {
      (**(code **)(*local_2a0 + 8))();
    }
  }
  return;
}



==== FUN_1402e89f0 @ 1402e89f0 ====

void FUN_1402e89f0(longlong param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  byte *pbVar6;
  longlong lVar7;
  longlong lVar8;
  byte *pbVar9;
  longlong lVar10;
  longlong lVar11;
  byte *pbVar12;
  longlong lVar13;
  longlong lVar14;
  longlong *local_res8;
  longlong *local_res10;
  
  if (*(longlong **)(param_1 + 0xb8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xb8) + 8))();
    *(undefined8 *)(param_1 + 0xb8) = 0;
  }
  if (((*(longlong *)(param_1 + 0x108) != 0) &&
      (*(float *)(*(longlong *)(param_1 + 0x20) + 0x60) != 0.0)) &&
     ((*(byte *)(*(longlong *)(param_1 + 0x20) + 0x38) & 8) != 0)) {
    iVar4 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x40))
                      (*(longlong **)(param_1 + 0x18),0x10);
    if ((iVar4 != 0) &&
       (iVar4 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                          (*(longlong **)(param_1 + 0x28),0x10), iVar4 != 0)) {
      return;
    }
    lVar5 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x18))();
    local_res10 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x10,&local_res10);
    pbVar6 = (byte *)(**(code **)(*local_res10 + 0x18))();
    local_res8 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x10,&local_res8);
    lVar7 = (**(code **)(*local_res8 + 0x18))();
    FUN_1402ddac0(0x10,param_1 + 0xb8);
    lVar8 = (**(code **)(**(longlong **)(param_1 + 0xb8) + 0x18))();
    fVar2 = DAT_140b79e48;
    fVar1 = DAT_140b79d20;
    lVar14 = 0x40;
    do {
      lVar11 = lVar8 - (longlong)pbVar6;
      pbVar12 = (byte *)(lVar5 + 5);
      lVar10 = 0x10;
      lVar13 = -(longlong)pbVar6;
      pbVar9 = pbVar6;
      do {
        if (fVar2 <= (float)pbVar12[-4] * fVar1 * *(float *)(*(longlong *)(param_1 + 0x20) + 0x60))
        {
          bVar3 = (pbVar9[lVar7 - (longlong)pbVar6] ^ *pbVar9) & 0x18 ^
                  pbVar9[lVar7 - (longlong)pbVar6];
        }
        else {
          bVar3 = *pbVar9;
        }
        pbVar9[lVar11] = bVar3;
        if (fVar2 <= (float)*pbVar12 * fVar1 * *(float *)(*(longlong *)(param_1 + 0x20) + 0x60)) {
          pbVar9[lVar11 + 1] =
               (pbVar9[lVar7 + lVar13 + 1] ^ pbVar9[1]) & 0x18 ^ pbVar9[lVar7 + lVar13 + 1];
        }
        else {
          pbVar9[lVar11 + 1] = pbVar9[1];
        }
        if (fVar2 <= (float)pbVar12[4] * fVar1 * *(float *)(*(longlong *)(param_1 + 0x20) + 0x60)) {
          pbVar9[lVar11 + 2] =
               (pbVar9[lVar7 + lVar13 + 2] ^ pbVar9[2]) & 0x18 ^ pbVar9[lVar7 + lVar13 + 2];
        }
        else {
          pbVar9[lVar11 + 2] = pbVar9[2];
        }
        if (fVar2 <= (float)pbVar12[8] * fVar1 * *(float *)(*(longlong *)(param_1 + 0x20) + 0x60)) {
          pbVar9[lVar11 + 3] =
               (pbVar9[lVar7 + lVar13 + 3] ^ pbVar9[3]) & 0x18 ^ pbVar9[lVar7 + lVar13 + 3];
        }
        else {
          pbVar9[lVar11 + 3] = pbVar9[3];
        }
        pbVar9 = pbVar9 + 4;
        pbVar12 = pbVar12 + 0x10;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      lVar5 = lVar5 + DAT_140c4191c;
      lVar10 = (longlong)DAT_140c416ec;
      pbVar6 = pbVar6 + lVar10;
      lVar7 = lVar7 + lVar10;
      lVar8 = lVar8 + lVar10;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(*local_res8 + 8))();
    }
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 8))();
    }
  }
  return;
}



==== FUN_1402f39e0 @ 1402f39e0 ====

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



==== FUN_14030a710 @ 14030a710 ====

void FUN_14030a710(longlong *param_1,ulonglong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  
  if ((ulonglong)param_1[1] <= param_2) {
    puVar2 = (undefined8 *)FUN_14018db00(*param_1);
    if ((undefined8 *)*param_1 != puVar2) {
      uVar5 = 0;
      if (param_1[1] != 0) {
        puVar3 = puVar2;
        do {
          if (puVar3 != (undefined8 *)0x0) {
            puVar4 = (undefined8 *)((longlong)puVar3 + (*param_1 - (longlong)puVar2));
            *puVar3 = *puVar4;
            *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(puVar4 + 1);
          }
          uVar5 = uVar5 + 1;
          puVar3 = puVar3 + 2;
        } while (uVar5 < (ulonglong)param_1[1]);
      }
      lVar1 = *param_1;
      if (lVar1 != 0) {
        (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
      }
      *param_1 = (longlong)puVar2;
    }
    param_1[1] = param_2;
    return;
  }
  param_1[1] = param_2;
  return;
}



==== FUN_14030a7c0 @ 14030a7c0 ====

longlong FUN_14030a7c0(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  
  lVar1 = param_1[1];
  puVar3 = (undefined8 *)FUN_14018db00(*param_1,lVar1 + 1);
  puVar4 = puVar3 + lVar1 * 2;
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = *param_2;
    *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(param_2 + 1);
  }
  if ((undefined8 *)*param_1 != puVar3) {
    uVar6 = 0;
    if (param_1[1] != 0) {
      puVar4 = puVar3;
      do {
        if (puVar4 != (undefined8 *)0x0) {
          puVar5 = (undefined8 *)((longlong)puVar4 + (*param_1 - (longlong)puVar3));
          *puVar4 = *puVar5;
          *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(puVar5 + 1);
        }
        uVar6 = uVar6 + 1;
        puVar4 = puVar4 + 2;
      } while (uVar6 < (ulonglong)param_1[1]);
    }
    lVar2 = *param_1;
    if (lVar2 != 0) {
      (**(code **)(*(longlong *)(lVar2 + -0x10) + 8))(lVar2 + -0x10);
    }
    *param_1 = (longlong)puVar3;
  }
  param_1[1] = lVar1 + 1;
  return lVar1;
}



==== FUN_1403283c0 @ 1403283c0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_1403283c0(longlong param_1,int param_2,uint param_3,longlong *param_4,ulonglong param_5,
             longlong param_6)

{
  undefined8 *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [15];
  undefined1 auVar5 [14];
  undefined1 auVar6 [15];
  undefined1 auVar7 [15];
  undefined1 auVar8 [15];
  undefined1 auVar9 [15];
  undefined1 auVar10 [15];
  undefined1 auVar11 [15];
  undefined1 auVar12 [15];
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined1 auVar27 [15];
  unkuint9 Var28;
  undefined1 auVar29 [15];
  undefined1 auVar30 [13];
  undefined1 auVar31 [14];
  undefined1 auVar32 [15];
  uint6 uVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  longlong *plVar38;
  undefined4 *puVar39;
  short *psVar40;
  longlong lVar41;
  undefined4 *puVar42;
  undefined8 *puVar43;
  undefined8 uVar44;
  float *pfVar45;
  float *pfVar46;
  longlong *plVar47;
  uint uVar48;
  undefined4 uVar49;
  uint uVar50;
  int *piVar51;
  ulonglong uVar52;
  uint uVar53;
  uint uVar54;
  longlong lVar55;
  int *piVar56;
  int *piVar57;
  longlong *plVar58;
  undefined8 *puVar59;
  byte bVar60;
  uint uVar61;
  uint uVar62;
  longlong lVar63;
  ushort *puVar64;
  ulonglong uVar65;
  longlong lVar66;
  int *piVar67;
  uint uVar68;
  ulonglong uVar69;
  float fVar70;
  float fVar71;
  undefined8 extraout_XMM0_Qa;
  float fVar73;
  float fVar74;
  undefined8 extraout_XMM0_Qb;
  undefined8 uVar75;
  ushort uVar76;
  float fVar77;
  undefined1 auVar78 [12];
  undefined1 uVar85;
  undefined1 uVar86;
  undefined1 uVar87;
  undefined1 auVar79 [16];
  undefined1 auVar82 [16];
  undefined4 uVar88;
  undefined4 uVar89;
  undefined4 uVar90;
  float fVar91;
  undefined1 auStack_498 [32];
  undefined8 local_478;
  undefined4 local_470;
  undefined4 local_468;
  int local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  uint local_440;
  float local_438;
  float fStack_434;
  int local_430;
  uint local_42c;
  longlong local_428;
  uint local_420;
  undefined4 *local_418;
  longlong local_410;
  int local_408;
  longlong *local_400;
  uint local_3f8;
  uint local_3f4;
  uint local_3f0;
  int local_3ec;
  undefined8 local_3e8;
  undefined8 uStack_3e0;
  undefined4 local_3d4;
  longlong local_3c8;
  int *local_3c0;
  longlong local_3b8;
  longlong local_3b0;
  uint local_3a8;
  int local_3a4;
  float local_3a0;
  longlong *local_398;
  longlong local_390;
  ulonglong local_388;
  longlong *local_380;
  int *local_378;
  float *local_370;
  longlong *local_368;
  float *local_360;
  ulonglong local_358;
  longlong local_350;
  longlong *local_338;
  undefined8 local_328;
  undefined4 *puStack_320;
  undefined8 local_318;
  undefined4 *puStack_310;
  undefined4 *local_308;
  undefined8 uStack_300;
  undefined4 local_2f8;
  undefined4 uStack_2f4;
  uint local_2e8;
  uint local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined8 local_2c4;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined8 local_2b0;
  uint local_2a8;
  longlong local_2a0 [8];
  undefined8 local_260;
  undefined8 local_258;
  longlong local_250 [6];
  longlong local_220 [10];
  longlong local_1d0 [6];
  undefined4 local_1a0 [8];
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178 [6];
  longlong alStack_160 [8];
  undefined8 local_120;
  undefined8 local_118;
  longlong local_110 [7];
  undefined4 *local_d8;
  longlong local_d0;
  ulonglong local_88;
  undefined1 auVar72 [16];
  undefined1 auVar80 [16];
  undefined1 auVar83 [16];
  undefined1 auVar81 [16];
  undefined1 auVar84 [16];
  
  local_88 = DAT_140c0f7b0 ^ (ulonglong)auStack_498;
  lVar63 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
  local_3b8 = *param_4;
  plVar47 = *(longlong **)(local_3b8 + 0x30);
  plVar58 = *(longlong **)(local_3b8 + 0x48);
  local_358 = plVar47[7];
  lVar41 = plVar47[8];
  local_418 = *(undefined4 **)(local_3b8 + 0x40);
  local_3a0 = *(float *)(local_3b8 + 0x50);
  local_360 = *(float **)(local_3b8 + 0x38);
  piVar67 = (int *)(*(longlong *)(lVar41 + 0x1f8) + 8 +
                   (ulonglong)*(ushort *)((longlong)local_418 + 0x16) * 0x30);
  lVar55 = (ulonglong)*(ushort *)((longlong)local_418 + 0x16) * 0x60 + plVar47[0x8a];
  local_398 = (longlong *)0x0;
  local_388 = 0;
  local_410 = 0;
  local_3c0 = (int *)0x0;
  local_390 = 0;
  local_438 = 0.0;
  local_370 = (float *)0x0;
  local_368 = (longlong *)0x0;
  local_430 = param_2;
  local_428 = param_1;
  local_420 = param_3;
  local_400 = plVar47;
  local_3c8 = lVar63;
  local_3b0 = lVar55;
  local_380 = plVar58;
  local_378 = piVar67;
  local_350 = lVar41;
  local_338 = param_4;
  plVar38 = (longlong *)(**(code **)(*DAT_140c65688 + 0xe0))();
  local_3a4 = *(int *)(*plVar38 + (ulonglong)*(byte *)(lVar55 + 0x58) * 4);
  if ((plVar58 != (longlong *)0x0) && (*(short *)(*plVar58 + 6) == 3)) {
    uVar69 = (ulonglong)*(ushort *)(*plVar58 + 0xe);
    piVar67 = (int *)(*(longlong *)(lVar41 + 0x1f8) + 8 + uVar69 * 0x30);
    local_3b0 = uVar69 * 0x60 + plVar47[0x8a];
    local_378 = piVar67;
  }
  if (param_6 != 0) {
    local_398 = *(longlong **)(param_6 + 0x30);
    local_410 = *(longlong *)(param_6 + 0x40);
    local_388 = local_398[7];
    piVar56 = (int *)((ulonglong)*(ushort *)(local_410 + 0x16) * 0x30 +
                     *(longlong *)(local_398[8] + 0x1f8) + 8);
    if (*piVar67 == *piVar56) {
      local_438 = *(float *)(param_6 + 0x50);
      local_370 = *(float **)(param_6 + 0x38);
      local_390 = (ulonglong)*(ushort *)(local_410 + 0x16) * 0x60 + local_398[0x8a];
      local_368 = *(longlong **)(param_6 + 0x48);
      local_3c0 = piVar56;
    }
  }
  FUN_1407e4830(&local_2e8,0,0x208);
  uVar50 = local_2e4;
  uVar54 = local_2e8;
  local_2b8 = (**(code **)(*DAT_140c65688 + 0x110))();
  lVar41 = local_428;
  if (param_6 == 0) {
    FUN_140312840(*(undefined8 *)(local_428 + 0x10),local_430);
  }
  fVar73 = DAT_140b79ed0;
  uVar68 = piVar67[1];
  if (((uVar68 & 4) == 0) &&
     (uVar53 = *(uint *)(*(longlong *)(lVar41 + 0x10) + 0x570), (uVar53 & 0xc0) == 0)) {
    if ((uVar53 >> 8 & 1) == 0) {
      local_2e0 = 1;
    }
    else {
      local_2e0 = 2;
    }
  }
  else {
    local_2e0 = 0;
  }
  uVar49 = 4;
  local_44c = 1;
  uVar53 = *(uint *)(*(longlong *)(lVar41 + 0x10) + 0x570);
  local_454 = 0;
  local_458 = 0;
  local_444 = 1;
  local_450 = 0;
  local_448 = 0;
  uVar61 = uVar53 & 4;
  if (uVar61 == 0) {
    if (((uVar53 >> 9 & 1) != 0) && (local_430 == 1)) {
      local_44c = 4;
      local_454 = 5;
      local_458 = 0;
      local_444 = 4;
      local_450 = 5;
      local_448 = 0;
    }
  }
  else {
    local_44c = 1;
    local_454 = 1;
    local_444 = 1;
    local_450 = 1;
    local_458 = 3;
    local_448 = 3;
  }
  local_3ec = piVar67[3];
  local_440 = 0xf;
  if (local_3c0 == (int *)0x0) {
    local_408 = 0xf;
  }
  else {
    local_408 = local_3c0[3];
  }
  if (local_430 != 5) goto LAB_140328979;
  if (local_380 != (longlong *)0x0) {
    if (local_3ec == 0) {
      local_3ec = 3;
    }
    else if ((local_3ec == 1) || (lVar63 = local_3c8, *(short *)(*local_380 + 6) == 2)) {
      local_3ec = 4;
    }
  }
  if (local_368 != (longlong *)0x0) {
    if (local_408 == 0) {
      local_408 = 3;
    }
    else if ((local_408 == 1) || (*(short *)(*local_368 + 6) == 2)) {
      local_408 = 4;
    }
  }
  if ((local_380 == (longlong *)0x0) || (*(short *)(*local_380 + 6) != 2)) {
    switch(local_3ec) {
    case 3:
      goto switchD_1403287a0_caseD_3;
    case 4:
      local_458 = 0;
      local_448 = 0;
      local_44c = 4;
      local_454 = 1;
      local_450 = 1;
      local_444 = 7;
      break;
    case 5:
      goto switchD_1403287a0_caseD_5;
    case 6:
      local_450 = 1;
      local_44c = 8;
      local_454 = 2;
      local_458 = 0;
      local_448 = 0;
      local_444 = 7;
      break;
    default:
      local_44c = 4;
      local_454 = 5;
      goto LAB_14032882f;
    case 8:
      goto switchD_1403287a0_caseD_8;
    case 9:
      goto switchD_1403287a0_caseD_9;
    case 10:
      local_44c = 1;
      local_454 = 3;
      local_458 = 0;
      local_450 = 1;
      local_448 = 0;
      local_444 = 7;
    }
    goto LAB_140328979;
  }
  switch(*(undefined2 *)(*local_380 + 0x16)) {
  case 3:
switchD_1403287a0_caseD_3:
    local_454 = 1;
    goto LAB_14032882b;
  case 4:
    local_454 = 1;
    local_44c = 4;
    goto LAB_14032882f;
  case 5:
switchD_1403287a0_caseD_5:
    local_450 = 1;
    local_44c = 8;
    local_454 = 0;
    local_444 = 7;
    local_448 = 0;
    local_458 = 0;
    break;
  case 6:
    local_44c = 8;
    local_454 = 2;
    goto LAB_14032882f;
  default:
    local_450 = 1;
    local_458 = 0;
    local_448 = 0;
    local_44c = 4;
    local_454 = 5;
    local_444 = 7;
    break;
  case 8:
switchD_1403287a0_caseD_8:
    uVar49 = 3;
  case 9:
switchD_1403287a0_caseD_9:
    local_44c = 1;
    local_454 = 1;
    local_444 = 7;
    local_450 = 1;
    local_448 = 0;
    local_458 = uVar49;
    break;
  case 10:
    local_454 = 3;
LAB_14032882b:
    local_44c = 1;
LAB_14032882f:
    local_450 = 1;
    local_444 = 7;
    local_458 = 0;
    local_448 = 0;
  }
LAB_140328979:
  iVar36 = local_3ec;
  local_2cc = local_450;
  local_2c8 = local_448;
  if ((uVar53 & 8) == 0) {
    if (local_430 == 5) {
      local_440 = 0x8f;
      if ((uVar53 & 0x40) == 0) {
        local_440 = 7;
      }
      if (((uVar53 & 0x20) == 0) &&
         ((*(longlong **)(local_3b8 + 0x48) == (longlong *)0x0 ||
          (*(short *)(**(longlong **)(local_3b8 + 0x48) + 6) != 2)))) {
        local_42c = ~(uVar68 >> 1) & 1;
      }
      else {
        local_42c = 0;
      }
    }
    else {
      if (local_430 != 4) {
        if (uVar61 == 0) {
          if ((uVar53 & 0x20) == 0) {
            local_440 = 0xfff;
            if ((uVar53 >> 0xc & 1) != 0) {
              local_440 = 0x2fff;
            }
            if ((local_430 == 0) && ((*(byte *)(plVar47 + 0xe4) & 1) != 0)) {
              local_440 = local_440 | 0x2000;
            }
            if ((uVar68 >> 0x10 & 1) != 0) {
              local_440 = 0;
              local_2b8 = 0;
            }
          }
          else {
            local_440 = 0xff7;
          }
        }
        else {
          local_440 = 0xf;
        }
      }
      local_42c = 1;
    }
    local_2c4 = CONCAT44(local_42c,local_440);
  }
  else {
    local_42c = 0;
    local_440 = 0;
    local_2c4 = 0;
  }
  if (((uVar53 & 0x20) == 0) && ((uVar68 & 1) == 0)) {
    local_2bc = 3;
  }
  else {
    local_2bc = 7;
  }
  uVar68 = local_2e8 | 0x5f;
  uVar53 = local_2e4 | 0x5f;
  local_3f8 = uVar68;
  local_3f4 = uVar53;
  local_2e8 = uVar68;
  local_2e4 = uVar53;
  local_2dc = local_44c;
  local_2d8 = local_454;
  local_2d4 = local_458;
  local_2d0 = local_444;
  if (uVar61 == 0) {
    if ((local_410 == 0) || (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0))
    {
      if ((*(byte *)(local_418 + 0xe) & 1) == 0) {
        fVar74 = 0.0;
        uVar49 = 0;
      }
      else {
        uVar49 = 0xfffffff8;
        fVar74 = DAT_140b7a23c;
      }
      goto LAB_140328b88;
    }
  }
  else if (param_6 == 0) {
    uVar49 = 8;
    fVar74 = DAT_140b79ed0;
LAB_140328b88:
    (**(code **)(*DAT_140c65670 + 0x188))(DAT_140c65670,uVar49,fVar74);
  }
  if (local_398 == (longlong *)0x0) {
LAB_140328c08:
    bVar60 = 0;
    if (local_430 == 0) {
      iVar34 = (**(code **)(*plVar47 + 0x118))(plVar47);
      bVar60 = -(iVar34 != 0) & 0x40;
    }
    if ((local_398 == (longlong *)0x0) ||
       ((uint)(0.0 < *(float *)((longlong)local_398 + 0x694)) -
        (uint)(*(float *)((longlong)local_398 + 0x694) < 0.0) !=
        (uint)(0.0 < *(float *)((longlong)plVar47 + 0x694)) -
        (uint)(*(float *)((longlong)plVar47 + 0x694) < 0.0))) {
      bVar60 = bVar60 | (&DAT_140b62cb1)
                        [(ulonglong)(0.0 < *(float *)((longlong)plVar47 + 0x694)) -
                         (ulonglong)(*(float *)((longlong)plVar47 + 0x694) < 0.0)];
    }
    (**(code **)(*DAT_140c65688 + 0x108))(DAT_140c65688,bVar60,0x78);
  }
  else {
    iVar34 = (**(code **)(*local_398 + 0x118))();
    iVar35 = (**(code **)(*local_400 + 0x118))(local_400);
    plVar47 = local_400;
    if ((iVar34 != iVar35) ||
       ((uint)(0.0 < *(float *)((longlong)local_398 + 0x694)) -
        (uint)(*(float *)((longlong)local_398 + 0x694) < 0.0) !=
        (uint)(0.0 < *(float *)((longlong)local_400 + 0x694)) -
        (uint)(*(float *)((longlong)local_400 + 0x694) < 0.0))) goto LAB_140328c08;
  }
  piVar56 = local_3c0;
  if (*piVar67 != 0) {
    if (*piVar67 != 1) {
      local_3a8 = local_420;
      local_3f0 = local_420;
      goto LAB_14032a409;
    }
    if (local_3c0 == (int *)0x0) {
      local_478 = (undefined *)((ulonglong)local_478._4_4_ << 0x20);
      puVar39 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x80,0);
      if (puVar39 != (undefined4 *)0x0) {
        lVar41 = *(longlong *)(local_428 + 0x10);
        uVar49 = *(undefined4 *)(lVar41 + 0x594);
        uVar89 = *(undefined4 *)(lVar41 + 0x598);
        uVar88 = *(undefined4 *)(lVar41 + 0x59c);
        uVar90 = *(undefined4 *)(lVar41 + 0x5b0);
        uVar13 = *(undefined4 *)(lVar41 + 0x5b4);
        uVar14 = *(undefined4 *)(lVar41 + 0x5b8);
        uVar15 = *(undefined4 *)(lVar41 + 0x5bc);
        uVar16 = *(undefined4 *)(lVar41 + 0x5a8);
        uVar17 = *(undefined4 *)(lVar41 + 0x5ac);
        uVar18 = *(undefined4 *)(lVar41 + 0x5c8);
        uVar19 = *(undefined4 *)(lVar41 + 0x5cc);
        uVar20 = *(undefined4 *)(lVar41 + 0x5a0);
        uVar21 = *(undefined4 *)(lVar41 + 0x5a4);
        uVar22 = *(undefined4 *)(lVar41 + 0x5c0);
        uVar23 = *(undefined4 *)(lVar41 + 0x5c4);
        *puVar39 = *(undefined4 *)(lVar41 + 0x590);
        puVar39[1] = uVar20;
        puVar39[2] = uVar90;
        puVar39[3] = uVar22;
        puVar39[4] = uVar49;
        puVar39[5] = uVar21;
        puVar39[6] = uVar13;
        puVar39[7] = uVar23;
        puVar39[8] = uVar89;
        puVar39[9] = uVar16;
        puVar39[10] = uVar14;
        puVar39[0xb] = uVar18;
        puVar39[0xc] = uVar88;
        puVar39[0xd] = uVar17;
        puVar39[0xe] = uVar15;
        puVar39[0xf] = uVar19;
        FUN_140262750(*(longlong *)(local_428 + 0x10) + 0x230,puVar39 + 0x10,
                      *(longlong *)(local_428 + 0x10) + 0xf0);
        puVar39[0x1c] = *(undefined4 *)(*(longlong *)(local_428 + 0x10) + 0x510);
        (**(code **)(*DAT_140c65670 + 0x108))();
      }
    }
    piVar56 = local_3c0;
    local_3a8 = 1;
    local_3f0 = 10;
    if ((local_3c0 == (int *)0x0) || (*(int *)(local_3b8 + 0x54) != *(int *)(param_6 + 0x54))) {
      (**(code **)(*DAT_140c65670 + 0x140))
                (DAT_140c65670,*(undefined8 *)(lVar63 + 0x808),*(undefined4 *)(local_3b8 + 0x54));
    }
    lVar41 = local_428;
    if (piVar56 == (int *)0x0) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      lVar55 = (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xb0,0,0);
      lVar41 = local_428;
      if (lVar55 != 0) {
        FUN_140262d50(*(longlong *)(local_428 + 0x10) + 0x230);
        lVar66 = *(longlong *)(lVar41 + 0x10);
        uVar44 = *(undefined8 *)(lVar66 + 0x2e8);
        *(undefined8 *)(lVar55 + 0x70) = *(undefined8 *)(lVar66 + 0x2e0);
        *(undefined8 *)(lVar55 + 0x78) = uVar44;
        *(undefined4 *)(lVar55 + 0x80) = *(undefined4 *)(lVar66 + 0x2c0);
        *(undefined4 *)(lVar55 + 0x84) = *(undefined4 *)(lVar66 + 0x2c4);
        *(undefined4 *)(lVar55 + 0x88) = *(undefined4 *)(lVar66 + 0x2c8);
        *(undefined4 *)(lVar55 + 0x8c) = *(undefined4 *)(lVar66 + 0x4e4);
        *(undefined4 *)(lVar55 + 0x90) = *(undefined4 *)(lVar66 + 0x2d0);
        *(undefined4 *)(lVar55 + 0x94) = *(undefined4 *)(lVar66 + 0x2d4);
        *(undefined4 *)(lVar55 + 0x98) = *(undefined4 *)(lVar66 + 0x2d8);
        *(undefined4 *)(lVar55 + 0x9c) = *(undefined4 *)(lVar66 + 0x4e0);
        *(undefined8 *)(lVar55 + 0xa0) = *(undefined8 *)(*(longlong *)(lVar41 + 0x10) + 0x550);
        lVar66 = *(longlong *)(lVar41 + 0x10);
        local_3e8 = (undefined4 *)
                    CONCAT44(*(float *)(lVar66 + 0x554) * _UNK_140b7ac54,
                             *(float *)(lVar66 + 0x550) * _DAT_140b7ac50);
        uStack_3e0 = CONCAT44(*(float *)(lVar66 + 0x55c) * _UNK_140b7ac5c,
                              *(float *)(lVar66 + 0x558) * _UNK_140b7ac58);
        *(undefined4 **)(lVar55 + 0xa8) = local_3e8;
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
    if (iVar36 < 3) {
LAB_14032a046:
      local_2a0[4] = *(undefined8 *)(*(longlong *)(lVar41 + 0x10) + 0x578);
    }
    else if (iVar36 < 5) {
      local_2a0[4] = *(undefined8 *)(lVar63 + 0x878);
    }
    else if (iVar36 == 5) {
      local_2a0[4] = *(undefined8 *)(lVar63 + 0x880);
    }
    else {
      if (iVar36 != 6) goto LAB_14032a046;
      local_2a0[4] = *(undefined8 *)(lVar63 + 0x888);
    }
    uVar68 = 0;
    alStack_160[4] = 0;
    local_1a0[4] = 0;
    if ((piVar56 == (int *)0x0) || (iVar36 != local_408)) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,1,0xb);
      fVar73 = DAT_140b79e48;
      if (pfVar46 != (float *)0x0) {
        if (iVar36 < 3) {
LAB_14032a123:
          *pfVar46 = DAT_140c79700;
          pfVar46[1] = DAT_140c79704;
          pfVar46[2] = DAT_140c79708;
          pfVar46[3] = 1.0;
        }
        else if (iVar36 < 5) {
          *pfVar46 = DAT_140c79700;
          pfVar46[1] = DAT_140c79704;
          pfVar46[2] = DAT_140c79708;
          pfVar46[3] = 0.0;
        }
        else if (iVar36 == 5) {
          *pfVar46 = DAT_140c79710;
          pfVar46[1] = DAT_140c79714;
          pfVar46[2] = DAT_140c79718;
          pfVar46[3] = 0.0;
        }
        else {
          if (iVar36 != 6) goto LAB_14032a123;
          *pfVar46 = DAT_140b79e48;
          pfVar46[1] = fVar73;
          pfVar46[2] = fVar73;
          pfVar46[3] = 0.0;
        }
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
    pfVar46 = local_360;
    lVar63 = local_3c8;
    iVar36 = local_3ec;
    puVar64 = *(ushort **)(piVar67 + 8);
    local_2a0[5] = *(undefined8 *)(*(longlong *)(lVar41 + 0x10) + 0x580);
    uVar54 = uVar54 | 0x185f;
    uVar50 = uVar50 | 0x185f;
    local_1a0[5] = 0;
    alStack_160[5] = 0;
    uVar53 = *(uint *)(local_350 + 0x1c0);
    puVar39 = local_1a0;
    plVar47 = local_2a0;
    puVar42 = local_1a0 + 2;
    plVar58 = local_2a0 + 2;
    do {
      uVar61 = 0x80 << ((byte)uVar68 & 0x1f);
      if (*puVar64 < uVar53) {
        plVar47[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)*puVar64 * 0x18);
        *puVar39 = 0;
      }
      else {
        *plVar47 = *(longlong *)(local_3c8 + 0x860);
        *puVar39 = 0;
        plVar47[0x28] = 0;
      }
      uVar48 = 0x80 << ((byte)uVar68 + 2 & 0x1f);
      uVar54 = uVar54 | uVar61 | uVar48;
      uVar50 = uVar50 | uVar61 | uVar48;
      if (puVar64[1] < uVar53) {
        plVar58[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)puVar64[1] * 0x18);
        *puVar42 = 0;
      }
      else {
        *plVar58 = *(longlong *)(local_3c8 + 0x868);
        *puVar42 = 0;
        plVar58[0x28] = 0;
      }
      uVar68 = uVar68 + 1;
      puVar42 = puVar42 + 1;
      plVar58 = plVar58 + 1;
      puVar64 = puVar64 + 0x94;
      puVar39 = puVar39 + 1;
      plVar47 = plVar47 + 1;
    } while (uVar68 < 2);
    local_258 = *(undefined8 *)(local_3c8 + 0x898);
    local_17c = 0;
    local_118 = 0;
    if (((local_360 != local_370) || (local_3ec != local_408)) ||
       (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0)) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      local_2e8 = uVar54;
      local_2e4 = uVar50;
      pfVar45 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,2,0xc);
      if (pfVar45 != (float *)0x0) {
        if (iVar36 - 5U < 2) {
          *pfVar45 = DAT_140c79710;
          pfVar45[1] = DAT_140c79714;
          pfVar45[2] = DAT_140c79718;
        }
        else {
          *pfVar45 = *pfVar46;
          pfVar45[1] = pfVar46[1];
          pfVar45[2] = pfVar46[2];
        }
        pfVar45[3] = pfVar46[8];
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
    local_2b0 = *(undefined8 *)(lVar63 + 0x810);
    uVar68 = uVar54 | 0x10020;
    uVar53 = uVar50 | 0x10020;
    local_2a8 = *(uint *)(local_3b8 + 0x58);
    local_42c = local_2c4._4_4_;
    local_440 = (uint)local_2c4;
    local_448 = local_2c8;
    local_450 = local_2cc;
    local_444 = local_2d0;
    local_458 = local_2d4;
    local_454 = local_2d8;
    local_44c = local_2dc;
    local_2e8 = uVar68;
    local_2e4 = uVar53;
    goto LAB_14032a409;
  }
  if (local_3c0 == (int *)0x0) {
    local_478 = (undefined *)((ulonglong)local_478._4_4_ << 0x20);
    puVar39 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x40,0);
    if (puVar39 != (undefined4 *)0x0) {
      lVar41 = *(longlong *)(local_428 + 0x10);
      uVar49 = *(undefined4 *)(lVar41 + 0x594);
      uVar89 = *(undefined4 *)(lVar41 + 0x598);
      uVar88 = *(undefined4 *)(lVar41 + 0x59c);
      uVar90 = *(undefined4 *)(lVar41 + 0x5b0);
      uVar13 = *(undefined4 *)(lVar41 + 0x5b4);
      uVar14 = *(undefined4 *)(lVar41 + 0x5b8);
      uVar15 = *(undefined4 *)(lVar41 + 0x5bc);
      uVar16 = *(undefined4 *)(lVar41 + 0x5a8);
      uVar17 = *(undefined4 *)(lVar41 + 0x5ac);
      uVar18 = *(undefined4 *)(lVar41 + 0x5c8);
      uVar19 = *(undefined4 *)(lVar41 + 0x5cc);
      uVar20 = *(undefined4 *)(lVar41 + 0x5a0);
      uVar21 = *(undefined4 *)(lVar41 + 0x5a4);
      uVar22 = *(undefined4 *)(lVar41 + 0x5c0);
      uVar23 = *(undefined4 *)(lVar41 + 0x5c4);
      *puVar39 = *(undefined4 *)(lVar41 + 0x590);
      puVar39[1] = uVar20;
      puVar39[2] = uVar90;
      puVar39[3] = uVar22;
      puVar39[4] = uVar49;
      puVar39[5] = uVar21;
      puVar39[6] = uVar13;
      puVar39[7] = uVar23;
      puVar39[8] = uVar89;
      puVar39[9] = uVar16;
      puVar39[10] = uVar14;
      puVar39[0xb] = uVar18;
      puVar39[0xc] = uVar88;
      puVar39[0xd] = uVar17;
      puVar39[0xe] = uVar15;
      puVar39[0xf] = uVar19;
      (**(code **)(*DAT_140c65670 + 0x108))();
    }
  }
  if (piVar56 == (int *)0x0) {
LAB_140328e30:
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    puVar39 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x80,1);
    if (puVar39 != (undefined4 *)0x0) {
      uVar61 = 0;
      lVar63 = 0;
      puVar64 = (ushort *)(local_418 + 0xc);
      do {
        uVar48 = 3;
        if (uVar61 < (uint)piVar67[6]) {
          uVar48 = *(uint *)(*(longlong *)(piVar67 + 8) + 0x120 + lVar63);
        }
        lVar41 = (ulonglong)uVar48 * 0x40;
        puVar42 = (undefined4 *)(&DAT_140c79e10 + lVar41);
        if (*puVar64 == 0xffff) {
          uVar49 = *puVar42;
          uVar89 = *(undefined4 *)(lVar41 + 0x140c79e14);
          auVar81 = *(undefined1 (*) [16])(&DAT_140c79e30 + lVar41);
          auVar83._0_8_ = auVar81._0_8_;
          uVar88 = *(undefined4 *)(&DAT_140c79e20 + lVar41);
          uVar90 = *(undefined4 *)(lVar41 + 0x140c79e24);
          auVar83._8_4_ = auVar81._4_4_;
          auVar83._12_4_ = auVar81._12_4_;
          auVar82._8_8_ = auVar83._8_8_;
          auVar82._0_4_ = auVar81._0_4_;
          auVar82._4_4_ = *(undefined4 *)(&DAT_140c79e40 + lVar41);
          auVar81._0_12_ = auVar82._0_12_;
          auVar81._12_4_ = *(undefined4 *)(lVar41 + 0x140c79e44);
        }
        else {
          uStack_3e0 = (ulonglong)*puVar64 * 0x110 + 0xd0 + plVar47[0x6a];
          local_3e8 = puVar42;
          local_d8 = puVar42;
          local_d0 = uStack_3e0;
          FUN_1401afb10(&local_d8,&local_328);
          auVar80._8_4_ = (int)((ulonglong)local_308 >> 0x20);
          auVar80._0_8_ = local_308;
          auVar80._12_4_ = (int)((ulonglong)uStack_300 >> 0x20);
          auVar79._8_8_ = auVar80._8_8_;
          auVar79._0_4_ = SUB84(local_308,0);
          auVar79._4_4_ = local_2f8;
          auVar81._0_12_ = auVar79._0_12_;
          auVar81._12_4_ = uStack_2f4;
          uVar49 = (undefined4)local_328;
          uVar88 = (undefined4)local_318;
          uVar89 = local_328._4_4_;
          uVar90 = local_318._4_4_;
        }
        uVar61 = uVar61 + 1;
        puVar64 = puVar64 + 1;
        lVar63 = lVar63 + 0x128;
        *puVar39 = uVar49;
        puVar39[1] = uVar88;
        puVar39[2] = auVar81._0_4_;
        puVar39[3] = auVar81._4_4_;
        puVar39[4] = uVar89;
        puVar39[5] = uVar90;
        puVar39[6] = auVar81._8_4_;
        puVar39[7] = auVar81._12_4_;
        puVar39 = puVar39 + 8;
      } while (uVar61 < 4);
      (**(code **)(*DAT_140c65670 + 0x108))();
      piVar56 = local_3c0;
      lVar63 = local_3c8;
    }
  }
  else {
    if (piVar67 != piVar56) {
      uVar61 = piVar67[6];
      uVar48 = piVar56[6];
      uVar69 = (ulonglong)uVar48;
      uVar37 = uVar61;
      if (uVar48 < uVar61) {
        uVar37 = uVar48;
      }
      uVar62 = 0;
      if (uVar37 != 0) {
        piVar51 = (int *)(*(longlong *)(piVar67 + 8) + 0x120);
        piVar57 = (int *)(*(longlong *)(piVar56 + 8) + 0x120);
        do {
          if (*piVar51 != *piVar57) goto LAB_140328e30;
          uVar62 = uVar62 + 1;
          piVar57 = piVar57 + 0x4a;
          piVar51 = piVar51 + 0x4a;
        } while (uVar62 < uVar37);
      }
      if (uVar48 < uVar61) {
        piVar51 = (int *)(uVar69 * 0x128 + 0x120 + *(longlong *)(piVar67 + 8));
        do {
          if (*piVar51 != 3) goto LAB_140328e30;
          uVar48 = (int)uVar69 + 1;
          uVar69 = (ulonglong)uVar48;
          piVar51 = piVar51 + 0x4a;
        } while (uVar48 < uVar61);
      }
    }
    if (plVar47 == local_398) {
      iVar36 = memcmp(local_418 + 0xc,(void *)(local_410 + 0x30),8);
      if (iVar36 != 0) goto LAB_140328e30;
    }
    else {
      uVar61 = 0;
      if (piVar67[6] != 0) {
        psVar40 = (short *)(local_418 + 0xc);
        do {
          if (*psVar40 != -1) goto LAB_140328e30;
          uVar61 = uVar61 + 1;
          psVar40 = psVar40 + 1;
        } while (uVar61 < (uint)piVar67[6]);
      }
      uVar61 = 0;
      if (piVar56[6] != 0) {
        psVar40 = (short *)(local_410 + 0x30);
        do {
          if (*psVar40 != -1) goto LAB_140328e30;
          uVar61 = uVar61 + 1;
          psVar40 = psVar40 + 1;
        } while (uVar61 < (uint)piVar56[6]);
      }
    }
  }
  local_3a8 = 2;
  local_3f0 = 0xe;
  if ((piVar56 == (int *)0x0) || (*(int *)(local_3b8 + 0x54) != *(int *)(param_6 + 0x54))) {
    (**(code **)(*DAT_140c65670 + 0x140))
              (DAT_140c65670,*(undefined8 *)(lVar63 + 0x7f8),*(undefined4 *)(local_3b8 + 0x54));
  }
  lVar63 = local_428;
  if (piVar56 == (int *)0x0) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    lVar41 = (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xd0,0);
    lVar63 = local_428;
    if (lVar41 != 0) {
      lVar55 = lVar41;
      FUN_140262d50(*(longlong *)(local_428 + 0x10) + 0x230,lVar41);
      FUN_140262750(*(longlong *)(lVar63 + 0x10) + 0x230,lVar55 + 0x70,
                    *(longlong *)(lVar63 + 0x10) + 0xf0);
      *(undefined8 *)(lVar41 + 0xa0) = 0;
      local_3e8 = (undefined4 *)
                  CONCAT44(*(float *)(*(longlong *)(lVar63 + 0x10) + 0x544) - _UNK_140b7b244,
                           *(float *)(*(longlong *)(lVar63 + 0x10) + 0x540) - _DAT_140b7b240);
      *(undefined4 **)(lVar41 + 0xa8) = local_3e8;
      *(undefined8 *)(lVar41 + 0xb0) = *(undefined8 *)(*(longlong *)(lVar63 + 0x10) + 0x550);
      lVar55 = *(longlong *)(lVar63 + 0x10);
      local_3e8 = (undefined4 *)
                  CONCAT44(*(float *)(lVar55 + 0x554) * _UNK_140b7ac54,
                           *(float *)(lVar55 + 0x550) * _DAT_140b7ac50);
      uStack_3e0 = CONCAT44(*(float *)(lVar55 + 0x55c) * _UNK_140b7ac5c,
                            *(float *)(lVar55 + 0x558) * _UNK_140b7ac58);
      *(undefined4 **)(lVar41 + 0xb8) = local_3e8;
      fVar74 = *(float *)(*(longlong *)(lVar63 + 0x10) + 0x1b0);
      fVar70 = *(float *)(*(longlong *)(lVar63 + 0x10) + 0x1b4);
      auVar3._4_4_ = fVar74 - fVar70;
      auVar3._0_4_ = fVar74 * fVar70;
      auVar3._8_4_ = fVar70;
      auVar3._12_4_ = 0;
      *(undefined1 (*) [16])(lVar41 + 0xc0) = auVar3;
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
  }
  iVar36 = local_430;
  if ((*(uint *)(*(longlong *)(lVar63 + 0x10) + 0x570) & 0x224) == 0) {
    if ((local_430 == 1) || (local_430 == 4)) {
      puVar43 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xc0))();
      uVar68 = uVar54 | 0x2005f;
      uVar53 = uVar50 | 0x2005f;
      local_250[0] = *puVar43;
      local_178[0] = 0;
      local_110[0] = 0;
      local_3f8 = uVar68;
      local_3f4 = uVar53;
    }
    if (iVar36 == 5) {
      lVar63 = (**(code **)(*DAT_140c65688 + 200))();
      local_260 = *(undefined8 *)(lVar63 + 0x20);
      local_180 = 0;
      local_120 = 0;
      lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
      uVar68 = uVar68 | 0x28000;
      uVar53 = uVar53 | 0x28000;
      local_250[0] = *(undefined8 *)(lVar63 + 0x38);
      local_178[0] = 0;
      local_110[0] = 0;
    }
    else if (iVar36 != 4) goto LAB_140329241;
    uVar44 = (**(code **)(*DAT_140c65688 + 0xd8))();
    lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
    uVar68 = uVar68 | 0x40000;
    uVar53 = uVar53 | 0x40000;
    local_250[1] = *(undefined8 *)(lVar63 + 0x48);
    local_178[1] = 0;
    local_3f8 = uVar68;
    local_3f4 = uVar53;
    local_110[1] = uVar44;
  }
LAB_140329241:
  lVar63 = local_3b0;
  if ((local_3b0 != local_390) || (local_3a0 != local_438)) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    local_3e8 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x1e0,1);
    piVar56 = local_378;
    lVar41 = local_3b0;
    auVar72._8_8_ = extraout_XMM0_Qb;
    auVar72._0_8_ = extraout_XMM0_Qa;
    if (local_3e8 != (undefined4 *)0x0) {
      local_438 = (float)piVar67[6];
      if (4 < (uint)piVar67[6]) {
        local_438 = (float)4;
      }
      uVar69 = (ulonglong)(uint)local_438;
      if (local_438 != 0.0) {
        lVar63 = 0;
        lVar55 = 0;
        puVar39 = local_3e8 + 0x20;
        pfVar46 = (float *)(local_3e8 + 100);
        fVar74 = DAT_140b79d04;
        do {
          local_328 = puVar39 + -0x20;
          puStack_320 = puVar39 + -0x10;
          lVar66 = *(longlong *)(lVar41 + 8) + lVar63;
          puStack_310 = puVar39 + 0x10;
          local_308 = puVar39 + 0x20;
          local_318 = puVar39;
          FUN_1403282e0(auVar72._0_8_,&local_328,*(longlong *)(piVar56 + 8) + lVar55,lVar66);
          uVar44 = *(undefined8 *)(lVar66 + 200);
          lVar55 = lVar55 + 0x128;
          lVar63 = lVar63 + 0xe0;
          *(undefined8 *)(puVar39 + 0x30) = *(undefined8 *)(lVar66 + 0xc0);
          *(undefined8 *)(puVar39 + 0x32) = uVar44;
          fVar70 = *(float *)(lVar66 + 100);
          if (fVar70 <= 0.0) {
            fVar70 = 0.0;
          }
          pfVar46[-4] = fVar70;
          fVar70 = *(float *)(lVar66 + 0x78) + fVar74;
          auVar72 = ZEXT416((uint)fVar70);
          *pfVar46 = fVar70;
          pfVar46[4] = *(float *)(lVar66 + 0x8c);
          pfVar46[8] = *(float *)(lVar66 + 0xa0);
          uVar69 = uVar69 - 1;
          puVar39 = puVar39 + 4;
          pfVar46 = pfVar46 + 1;
        } while (uVar69 != 0);
        uVar69 = (ulonglong)(uint)local_438;
        lVar63 = local_3b0;
        piVar67 = local_378;
        uVar68 = local_3f8;
        uVar53 = local_3f4;
      }
      if ((uint)uVar69 < 4) {
        puVar43 = (undefined8 *)(local_3e8 + (uVar69 + 8) * 4);
        uVar52 = (ulonglong)(4 - (uint)uVar69);
        puVar39 = local_3e8 + uVar69 + 100;
        do {
          puVar43[-0x10] = 0;
          puVar43[-0xf] = 0;
          puVar43[-8] = 0;
          puVar43[-7] = 0;
          *puVar43 = 0;
          puVar43[1] = 0;
          puVar43[8] = 0;
          puVar43[9] = 0;
          puVar43[0x10] = 0;
          puVar43[0x11] = 0;
          puVar43[0x18] = 0;
          puVar43[0x19] = 0;
          puVar39[-4] = 0;
          *puVar39 = 0;
          puVar39[4] = 0;
          puVar39[8] = 0;
          puVar43 = puVar43 + 2;
          uVar52 = uVar52 - 1;
          puVar39 = puVar39 + 1;
        } while (uVar52 != 0);
      }
      piVar56 = DAT_140c63750;
      bVar60 = *(byte *)(lVar63 + 0x59);
      uVar54 = (uint)bVar60;
      if (((uint)bVar60 < *(uint *)(local_3c8 + 0x8d0)) &&
         ((uint)local_3a0 < (uint)*(float *)(local_3c8 + 0x8d4))) {
        uVar54 = *(uint *)(*(longlong *)(local_3c8 + 0x8d8) +
                          (ulonglong)
                          ((uint)bVar60 * (int)*(float *)(local_3c8 + 0x8d4) + (int)local_3a0) * 4);
      }
      bVar60 = *(byte *)(lVar63 + 0x58);
      uVar50 = (uint)bVar60;
      if (((uint)bVar60 < *(uint *)(local_3c8 + 0x8d0)) &&
         ((uint)local_3a0 < (uint)*(float *)(local_3c8 + 0x8d4))) {
        uVar50 = *(uint *)(*(longlong *)(local_3c8 + 0x8d8) +
                          (ulonglong)
                          ((int)*(float *)(local_3c8 + 0x8d4) * (uint)bVar60 + (int)local_3a0) * 4);
      }
      fVar74 = *(float *)(*(longlong *)(local_3b8 + 0x30) + 0x35c);
      local_438 = (float)uVar50;
      if (0.0 <= fVar74) {
        local_438 = fVar74;
      }
      fVar74 = *(float *)(*(longlong *)(local_3b8 + 0x30) + 0x360);
      fStack_434 = (float)uVar54;
      if (0.0 <= fVar74) {
        fStack_434 = fVar74;
      }
      *(ulonglong *)(local_3e8 + 0x70) = CONCAT44(fStack_434,local_438);
      uVar69 = DAT_140c67498;
      if ((piVar67[1] & 0x2000U) != 0) {
        iVar36 = *piVar56;
        iVar34 = DAT_140c422a0;
        if (iVar36 < DAT_140c422a0) {
          iVar34 = iVar36;
        }
        if ((&DAT_140c422b0)[iVar34] != '\0') {
          fStack_434 = 0.0;
          iVar34 = DAT_140c422e0;
          if (iVar36 < DAT_140c422e0) {
            iVar34 = iVar36;
          }
          local_438 = *(float *)(&DAT_140c422f0 + (longlong)iVar34 * 4);
          uVar69 = (ulonglong)(uint)local_438;
        }
      }
      *(ulonglong *)(local_3e8 + 0x74) = uVar69;
      if ((piVar67[1] & 0x4000U) == 0) {
LAB_1403295a9:
        *(ulonglong *)(local_3e8 + 0x76) = DAT_140c67498;
        uVar69 = DAT_140c67498;
      }
      else {
        iVar36 = *piVar56;
        iVar34 = DAT_140c42340;
        if (iVar36 < DAT_140c42340) {
          iVar34 = iVar36;
        }
        if ((&DAT_140c42350)[iVar34] == '\0') goto LAB_1403295a9;
        iVar34 = DAT_140c42380;
        if (iVar36 < DAT_140c42380) {
          iVar34 = iVar36;
        }
        fStack_434 = 0.0;
        *(ulonglong *)(local_3e8 + 0x76) =
             (ulonglong)*(uint *)(&DAT_140c42390 + (longlong)iVar34 * 4);
        iVar36 = DAT_140c423e0;
        if (*piVar56 < DAT_140c423e0) {
          iVar36 = *piVar56;
        }
        local_438 = *(float *)(&DAT_140c423f0 + (longlong)iVar36 * 4);
        uVar69 = (ulonglong)(uint)local_438;
      }
      *(ulonglong *)(local_3e8 + 0x72) = uVar69;
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
  }
  pfVar46 = local_360;
  iVar36 = local_3ec;
  puVar39 = local_418;
  fVar70 = DAT_140b79e48;
  fVar74 = DAT_140b79d20;
  if ((((local_3ec != local_408) || (local_360 != local_370)) || (lVar63 != local_390)) ||
     (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0)) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    pfVar45 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xb0,2);
    if (pfVar45 != (float *)0x0) {
      if (iVar36 < 3) {
LAB_1403296c2:
        *pfVar45 = DAT_140c79700;
        pfVar45[1] = DAT_140c79704;
        pfVar45[2] = DAT_140c79708;
        pfVar45[3] = 1.0;
      }
      else if (iVar36 < 5) {
        *pfVar45 = DAT_140c79700;
        pfVar45[1] = DAT_140c79704;
        pfVar45[2] = DAT_140c79708;
        pfVar45[3] = 0.0;
      }
      else if (iVar36 == 5) {
        *pfVar45 = DAT_140c79710;
        pfVar45[1] = DAT_140c79714;
        pfVar45[2] = DAT_140c79718;
        pfVar45[3] = 0.0;
      }
      else {
        if (iVar36 != 6) goto LAB_1403296c2;
        *pfVar45 = fVar70;
        pfVar45[1] = fVar70;
        pfVar45[2] = fVar70;
        pfVar45[3] = 0.0;
      }
      fVar77 = DAT_140b79ec8;
      if (iVar36 == 0) {
        if ((pfVar46[8] <= DAT_140b79ec8 && DAT_140b79ec8 != pfVar46[8]) ||
           ((fVar71 = fVar73, (*(byte *)(puVar39 + 0xe) & 1) != 0 &&
            ((*(byte *)(*(longlong *)(local_428 + 0x10) + 0x570) & 4) == 0)))) {
          fVar71 = 0.0;
        }
        pfVar45[4] = fVar71;
        fVar71 = fVar74;
        if (fVar77 < pfVar46[8] || fVar77 == pfVar46[8]) {
          fVar71 = 0.0;
        }
        pfVar45[5] = fVar71;
      }
      else if (iVar36 == 1) {
        pfVar45[4] = 1.0;
        pfVar45[5] = 0.5;
      }
      else {
        pfVar45[4] = 0.0;
        pfVar45[5] = 0.003921569;
      }
      pfVar45[6] = pfVar46[9];
      pfVar45[7] = pfVar46[10];
      pfVar45[8] = (float)((uint)~piVar67[1] >> 0xf & 1);
      pfVar45[9] = 0.0;
      pfVar45[10] = 0.0;
      pfVar45[0xb] = 0.0;
      if (iVar36 - 3U < 4) {
        uVar44 = 0;
        uVar75 = 0;
        pfVar45[0xc] = 0.0;
        pfVar45[0xd] = 0.0;
        pfVar45[0xe] = 0.0;
        pfVar45[0xf] = 0.0;
        pfVar45[0x10] = 0.0;
        pfVar45[0x11] = 0.0;
        pfVar45[0x12] = 0.0;
        pfVar45[0x13] = 0.0;
      }
      else {
        uVar44 = *(undefined8 *)(pfVar46 + 6);
        *(undefined8 *)(pfVar45 + 0xc) = *(undefined8 *)(pfVar46 + 4);
        *(undefined8 *)(pfVar45 + 0xe) = uVar44;
        uVar44 = *(undefined8 *)(lVar63 + 0x38);
        *(undefined8 *)(pfVar45 + 0x10) = *(undefined8 *)(lVar63 + 0x30);
        *(undefined8 *)(pfVar45 + 0x12) = uVar44;
        uVar44 = *(undefined8 *)(lVar63 + 0x40);
        uVar75 = *(undefined8 *)(lVar63 + 0x48);
      }
      *(undefined8 *)(pfVar45 + 0x14) = uVar44;
      *(undefined8 *)(pfVar45 + 0x16) = uVar75;
      if (iVar36 - 5U < 2) {
        uVar44 = CONCAT44(_UNK_140b7b244,_DAT_140b7b240);
        uVar75 = CONCAT44(_UNK_140b7b24c,DAT_140b7b248);
        *(undefined8 *)(pfVar45 + 0x18) = uVar44;
        *(undefined8 *)(pfVar45 + 0x1a) = uVar75;
        *(undefined8 *)(pfVar45 + 0x1c) = uVar44;
        *(undefined8 *)(pfVar45 + 0x1e) = uVar75;
      }
      else {
        fVar77 = *(float *)(lVar63 + 0x14);
        fVar71 = *(float *)(lVar63 + 0x18);
        fVar24 = *(float *)(lVar63 + 0x1c);
        fVar91 = pfVar46[1];
        fVar25 = pfVar46[2];
        fVar26 = pfVar46[3];
        pfVar45[0x18] = *(float *)(lVar63 + 0x10) * *pfVar46;
        pfVar45[0x19] = fVar77 * fVar91;
        pfVar45[0x1a] = fVar71 * fVar25;
        pfVar45[0x1b] = fVar24 * fVar26;
        fVar77 = *(float *)(lVar63 + 0x24);
        fVar71 = *(float *)(lVar63 + 0x28);
        fVar24 = *(float *)(lVar63 + 0x2c);
        fVar91 = pfVar46[1];
        fVar25 = pfVar46[2];
        fVar26 = pfVar46[3];
        pfVar45[0x1c] = *(float *)(lVar63 + 0x20) * *pfVar46;
        pfVar45[0x1d] = fVar77 * fVar91;
        pfVar45[0x1e] = fVar71 * fVar25;
        pfVar45[0x1f] = fVar24 * fVar26;
      }
      if (local_3a4 == 1) {
        auVar2._12_4_ = 0;
        auVar2._0_12_ = *(undefined1 (*) [12])(puVar39 + 0x18);
        *(undefined1 (*) [16])(pfVar45 + 0x20) = auVar2;
      }
      else {
        pfVar45[0x20] = 0.0;
        pfVar45[0x21] = 0.0;
        pfVar45[0x22] = 0.0;
        pfVar45[0x23] = 0.0;
      }
      fVar91 = fVar73 / (pfVar46[0x13] + DAT_140b79cc4);
      fVar77 = pfVar46[0x11];
      fVar71 = pfVar46[0x12];
      fVar24 = pfVar46[0x13];
      pfVar45[0x24] = pfVar46[0x10] * fVar91;
      pfVar45[0x25] = fVar77 * fVar91;
      pfVar45[0x26] = fVar71 * fVar91;
      pfVar45[0x27] = fVar24 * fVar73;
      *(undefined1 (*) [16])(pfVar45 + 0x28) = ZEXT416((uint)(pfVar46[0x14] + DAT_140b79cc4));
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
  }
  uVar54 = piVar67[6];
  uVar50 = 0;
  if (uVar54 != 0) {
    puVar39 = local_1a0;
    plVar47 = local_2a0;
    uVar61 = *(uint *)(local_350 + 0x1c0);
    puVar42 = local_1a0 + 4;
    puVar64 = *(ushort **)(local_378 + 8);
    plVar58 = local_2a0 + 4;
    do {
      uVar48 = 0x80 << ((byte)uVar50 & 0x1f);
      if (*puVar64 < uVar61) {
        plVar47[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)*puVar64 * 0x18);
        *puVar39 = 0;
      }
      else {
        *plVar47 = *(longlong *)(local_3c8 + 0x860);
        *puVar39 = 0;
        plVar47[0x28] = 0;
      }
      uVar37 = 0x80 << ((byte)uVar50 + 4 & 0x1f);
      uVar68 = uVar68 | uVar48 | uVar37;
      uVar53 = uVar53 | uVar48 | uVar37;
      if (puVar64[1] < uVar61) {
        plVar58[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)puVar64[1] * 0x18);
        *puVar42 = 0;
      }
      else {
        *plVar58 = *(longlong *)(local_3c8 + 0x868);
        *puVar42 = 0;
        plVar58[0x28] = 0;
      }
      uVar50 = uVar50 + 1;
      puVar42 = puVar42 + 1;
      plVar58 = plVar58 + 1;
      puVar64 = puVar64 + 0x94;
      puVar39 = puVar39 + 1;
      plVar47 = plVar47 + 1;
    } while (uVar50 < uVar54);
    local_42c = local_2c4._4_4_;
    local_440 = (uint)local_2c4;
    local_448 = local_2c8;
    local_450 = local_2cc;
    local_444 = local_2d0;
    local_458 = local_2d4;
    local_454 = local_2d8;
    local_44c = local_2dc;
    local_2e8 = uVar68;
    local_2e4 = uVar53;
  }
  if (local_3a4 == 1) {
    lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
    local_258 = *(undefined8 *)(lVar63 + 0x50);
  }
  else {
    local_258 = *(undefined8 *)(local_3c8 + 0x898);
  }
  uVar50 = uVar68 | 0x10000;
  uVar54 = uVar53 | 0x10000;
  local_118 = 0;
  local_17c = 0;
  if (local_380 != (longlong *)0x0) {
    lVar63 = local_380[1];
    lVar41 = *local_380;
    local_178[2] = 0;
    if ((uint)*(ushort *)(lVar41 + 4) < *(uint *)(*(longlong *)(lVar63 + 0x40) + 0x1c0)) {
      local_1d0[2] = *(undefined8 *)
                      (*(longlong *)(lVar63 + 0x420) + 0x10 +
                      (ulonglong)*(ushort *)(lVar41 + 4) * 0x18);
    }
    else {
      local_250[2] = 0;
      local_110[2] = 0;
    }
    uVar76 = *(ushort *)(lVar41 + 10);
    lVar55 = *(longlong *)(lVar63 + 0x420);
    uVar50 = uVar68 | 0x190000;
    uVar54 = uVar53 | 0x190000;
    local_178[3] = 0;
    local_1d0[3] = *(undefined8 *)(lVar55 + 0x10 + (ulonglong)uVar76 * 0x18);
    if (local_380 != local_368) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x40,3);
      if (pfVar46 != (float *)0x0) {
        fVar77 = fVar73;
        if ((*(ushort *)(lVar41 + 0x12) & 2) == 0) {
          fVar77 = 0.0;
        }
        if ((*(ushort *)(lVar41 + 0x12) & 1) == 0) {
          fVar74 = 0.0;
        }
        *pfVar46 = *(float *)(local_380 + 4) * DAT_140b79f58;
        pfVar46[1] = fVar74;
        pfVar46[2] = fVar77;
        plVar47 = *(longlong **)(lVar55 + 0x10 + (ulonglong)uVar76 * 0x18);
        if ((plVar47 == (longlong *)0x0) ||
           (plVar47 = (longlong *)(**(code **)(*plVar47 + 0x38))(), plVar47 == (longlong *)0x0)) {
          pfVar46[3] = 0.0;
        }
        else {
          uVar76 = *(ushort *)((longlong)local_380 + 0x34);
          lVar55 = (**(code **)(*plVar47 + 0x18))(plVar47);
          pfVar46[3] = ((float)uVar76 + fVar70) / (float)*(uint *)(lVar55 + 8);
        }
        local_3e8 = (undefined4 *)
                    CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x5d),
                             (float)(int)*(char *)((longlong)local_380 + 0x5c));
        uStack_3e0 = CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x5f),
                              (float)(int)*(char *)((longlong)local_380 + 0x5e));
        *(undefined4 **)(pfVar46 + 4) = local_3e8;
        *(longlong *)(pfVar46 + 6) = uStack_3e0;
        local_3e8 = (undefined4 *)
                    CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x71),
                             (float)(int)(char)local_380[0xe]);
        uStack_3e0 = CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x73),
                              (float)(int)*(char *)((longlong)local_380 + 0x72));
        *(undefined4 **)(pfVar46 + 8) = local_3e8;
        *(longlong *)(pfVar46 + 10) = uStack_3e0;
        if (*(short *)(lVar41 + 6) == 2) {
          uVar49 = (undefined4)local_380[9];
          auVar78._0_8_ = CONCAT44(uVar49,uVar49);
          auVar78._8_4_ = uVar49;
          auVar84._12_4_ = uVar49;
          auVar84._0_12_ = auVar78;
          uVar87 = (undefined1)((uint)uVar49 >> 0x18);
          auVar4[0xd] = 0;
          auVar4._0_13_ = auVar84._0_13_;
          auVar4[0xe] = uVar87;
          uVar86 = (undefined1)((uint)uVar49 >> 0x10);
          auVar6[0xc] = uVar86;
          auVar6._0_12_ = auVar78;
          auVar6._13_2_ = auVar4._13_2_;
          auVar7[0xb] = 0;
          auVar7._0_11_ = auVar78._0_11_;
          auVar7._12_3_ = auVar6._12_3_;
          uVar85 = (undefined1)((uint)uVar49 >> 8);
          auVar8[10] = uVar85;
          auVar8._0_10_ = auVar78._0_10_;
          auVar8._11_4_ = auVar7._11_4_;
          auVar9[9] = 0;
          auVar9._0_9_ = auVar78._0_9_;
          auVar9._10_5_ = auVar8._10_5_;
          auVar10[8] = (byte)uVar49;
          auVar10._0_8_ = auVar78._0_8_;
          auVar10._9_6_ = auVar9._9_6_;
          auVar27._7_8_ = 0;
          auVar27._0_7_ = auVar10._8_7_;
          Var28 = CONCAT81(SUB158(auVar27 << 0x40,7),uVar87);
          auVar32._9_6_ = 0;
          auVar32._0_9_ = Var28;
          auVar11[4] = uVar86;
          auVar11._0_4_ = uVar49;
          auVar11._5_10_ = SUB1510(auVar32 << 0x30,5);
          auVar29._11_4_ = 0;
          auVar29._0_11_ = auVar11._4_11_;
          auVar30._1_12_ = SUB1512(auVar29 << 0x20,3);
          auVar30[0] = uVar85;
          uVar76 = CONCAT11(0,(byte)uVar49);
          auVar12._2_13_ = auVar30;
          auVar12._0_2_ = uVar76;
          auVar5._10_2_ = 0;
          auVar5._0_10_ = auVar12._0_10_;
          auVar5._12_2_ = (short)Var28;
          uVar33 = CONCAT42(auVar5._10_4_,auVar11._4_2_);
          auVar31._6_8_ = 0;
          auVar31._0_6_ = uVar33;
          fVar73 = _UNK_140b7b274 *
                   (float)(int)CONCAT82(SUB148(auVar31 << 0x40,6),auVar30._0_2_) * _UNK_140b7ab74;
          fVar74 = _UNK_140b7b278 * (float)uVar76 * _UNK_140b7ab78;
          fVar70 = _UNK_140b7b27c * (float)(auVar5._10_4_ >> 0x10) * _UNK_140b7ab7c;
          pfVar46[0xc] = _DAT_140b7b270 * (float)(int)uVar33 * _DAT_140b7ab70;
          pfVar46[0xd] = fVar73;
          pfVar46[0xe] = fVar74;
          pfVar46[0xf] = fVar70;
        }
        else if (*(short *)(lVar41 + 6) == 3) {
          lVar63 = *(longlong *)
                    ((ulonglong)*(ushort *)(lVar41 + 0xe) * 0x60 + 8 + *(longlong *)(lVar63 + 0x450)
                    );
          fVar74 = *(float *)(lVar63 + 0xc4);
          fVar70 = *(float *)(lVar63 + 200);
          pfVar46[0xc] = *(float *)(lVar63 + 0xc0);
          pfVar46[0xd] = fVar74;
          pfVar46[0xe] = fVar70;
          pfVar46[0xf] = fVar73;
        }
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
  }
  if (local_3b0 != local_390) {
    local_478 = (undefined *)0x0;
    (**(code **)(*DAT_140c65670 + 0x160))();
  }
  local_2a8 = *(uint *)(local_3b8 + 0x58);
  if (local_430 == 5) {
    if (0.0 < *(float *)(*(longlong *)(local_428 + 0x10) + 0x524)) {
      if ((local_420 & 2) == 0) {
        local_2a8 = local_2a8 + 0xb400;
      }
      else {
        local_2a8 = local_2a8 + 0xc600;
      }
    }
    else if ((local_420 & 1) == 0) {
      local_2a8 = local_2a8 + 0xa200;
    }
    else {
      local_2a8 = local_2a8 + 0x9000;
    }
  }
  else if ((local_430 == 1) && ((*(uint *)(*(longlong *)(local_428 + 0x10) + 0x570) & 0x200) != 0))
  {
    local_2a8 = local_2a8 +
                (0xc - ((int)((ulonglong)local_2a8 / 0x1200) +
                       (int)(((ulonglong)local_2a8 / 0x1200) / 0xd) * -0xd)) * 0x1200;
  }
  if (*(longlong *)(local_3b0 + 0x50) != 0) {
    local_2a8 = local_2a8 + 1;
  }
  uVar68 = uVar50 | 0x20;
  uVar53 = uVar54 | 0x20;
  local_2b0 = *(undefined8 *)(local_3c8 + 0x800);
  lVar63 = local_3c8;
  local_2e8 = uVar68;
  local_2e4 = uVar53;
LAB_14032a409:
  uVar54 = local_2a8;
  uVar52 = local_358;
  uVar69 = local_388;
  local_410 = local_2b0;
  if ((local_358 != local_388) || (local_400[0x8f] != local_398[0x8f])) {
    (**(code **)(*DAT_140c65670 + 0x138))();
  }
  if (uVar52 != uVar69) {
    (**(code **)(*DAT_140c65670 + 0x130))
              (DAT_140c65670,*(undefined8 *)(uVar52 + 0xa0),*(undefined4 *)(uVar52 + 0xa8),0);
  }
  if (local_3c0 == (int *)0x0) {
    (**(code **)(*DAT_140c65670 + 0x130))
              (DAT_140c65670,*(undefined8 *)(lVar63 + 0x8a8),*(undefined4 *)(uVar52 + 0xa8),1);
  }
  lVar63 = (**(code **)(*DAT_140c65670 + 0x2c8))();
  iVar36 = *(int *)(lVar63 + 0x30) - local_3f0;
  local_438 = (float)((uint)*(ushort *)((longlong)local_418 + 0x12) * 2 + 1 +
                     (uint)*(ushort *)((longlong)local_418 + 0x12));
  local_358 = (ulonglong)(iVar36 - 1) / (ulonglong)(uint)local_438;
  local_388 = 0;
  if (param_5 != 0) {
    local_420 = iVar36 * 0x10;
    puVar39 = local_418;
    do {
      plVar47 = local_338;
      uVar69 = local_388;
      fVar73 = local_438;
      local_478 = (undefined *)CONCAT44(local_478._4_4_,local_420);
      uVar52 = param_5 - local_388;
      if (local_358 < param_5 - local_388) {
        uVar52 = local_358;
      }
      iVar36 = (int)uVar52;
      pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x100))
                                   (DAT_140c65670,(iVar36 * (int)local_438 + 1) * 0x10,local_3a8,
                                    local_3f0);
      if (pfVar46 != (float *)0x0) {
        pfVar45 = pfVar46 + 4;
        uVar65 = 0;
        fVar73 = (float)(uint)fVar73;
        *pfVar46 = fVar73;
        pfVar46[1] = fVar73;
        pfVar46[2] = fVar73;
        pfVar46[3] = fVar73;
        if (uVar52 != 0) {
          do {
            lVar63 = plVar47[uVar69 + uVar65];
            lVar41 = *(longlong *)(lVar63 + 0x38);
            fVar73 = *(float *)(lVar41 + 0x3c);
            fVar74 = *(float *)(lVar41 + 0x38);
            fVar70 = *(float *)(lVar41 + 0x2c);
            *pfVar45 = *(float *)(lVar41 + 0x20);
            pfVar45[1] = fVar70;
            pfVar45[2] = fVar74;
            pfVar45[3] = fVar73;
            puVar43 = (undefined8 *)
                      ((ulonglong)*(ushort *)(puVar39 + 4) * 0x30 +
                      *(longlong *)(*(longlong *)(lVar63 + 0x30) + 0x340));
            iVar34 = (uint)*(ushort *)((longlong)puVar39 + 0x12) +
                     (uint)*(ushort *)((longlong)puVar39 + 0x12) * 2;
            if (iVar34 != 0) {
              lVar63 = (longlong)iVar34;
              puVar59 = puVar43;
              do {
                uVar44 = *puVar59;
                uVar75 = puVar59[1];
                puVar59 = puVar59 + 2;
                puVar1 = (undefined8 *)(((longlong)pfVar45 - (longlong)puVar43) + (longlong)puVar59)
                ;
                *puVar1 = uVar44;
                puVar1[1] = uVar75;
                lVar63 = lVar63 + -1;
              } while (lVar63 != 0);
            }
            uVar65 = uVar65 + 1;
            pfVar45 = pfVar45 + (longlong)iVar34 * 4 + 4;
          } while (uVar65 < uVar52);
        }
        (**(code **)(*DAT_140c65670 + 0x108))();
      }
      lVar63 = local_410;
      if (((local_430 == 0) && ((*(byte *)(*(longlong *)(local_428 + 0x10) + 0x570) & 1) != 0)) &&
         (local_3a4 == 1)) {
        (**(code **)(*DAT_140c65670 + 0x1f8))();
        (**(code **)(*DAT_140c65670 + 0x200))();
        lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
        uStack_3e0 = *(longlong *)(lVar63 + 0x50);
        local_3e8 = (undefined4 *)CONCAT44(local_3e8._4_4_,1);
        local_3d4 = 0;
        local_478 = &DAT_140c3fe88;
        (**(code **)(*DAT_140c65670 + 0x208))
                  (DAT_140c65670,&local_3e8,&DAT_140c3fe88,&DAT_140c3fe88);
        (**(code **)(*DAT_140c65670 + 0x210))(DAT_140c65670,&DAT_140c3fe88,0);
        (**(code **)(*DAT_140c65670 + 0x1c0))(DAT_140c65670,1);
        (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,0);
        (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,1,3);
        (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,2);
        (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,7);
        uVar50 = 0;
        puVar39 = local_1a0;
        plVar47 = local_220;
        do {
          if ((uVar68 & 0x80 << ((byte)uVar50 & 0x1f)) != 0) {
            if (*plVar47 == 0) {
              if (plVar47[-0x10] != 0) {
                local_478 = (undefined *)plVar47[0x18];
                (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,uVar50,plVar47[-0x10],*puVar39);
              }
            }
            else {
              (**(code **)(*DAT_140c65670 + 0x168))(DAT_140c65670,uVar50,*plVar47,*puVar39);
            }
          }
          uVar50 = uVar50 + 1;
          plVar47 = plVar47 + 1;
          puVar39 = puVar39 + 1;
        } while (uVar50 < 9);
        local_478 = (undefined *)0x0;
        (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,9,0);
        uVar50 = 10;
        puVar39 = local_178;
        plVar47 = local_1d0;
        do {
          if ((uVar68 & 0x80 << ((byte)uVar50 & 0x1f)) != 0) {
            if (*plVar47 == 0) {
              if (plVar47[-0x10] != 0) {
                local_478 = (undefined *)plVar47[0x18];
                (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,uVar50,plVar47[-0x10],*puVar39);
              }
            }
            else {
              (**(code **)(*DAT_140c65670 + 0x168))(DAT_140c65670,uVar50,*plVar47,*puVar39);
            }
          }
          lVar63 = local_410;
          uVar50 = uVar50 + 1;
          plVar47 = plVar47 + 1;
          puVar39 = puVar39 + 1;
        } while (uVar50 < 0x10);
        (**(code **)(*DAT_140c65670 + 0x178))
                  (DAT_140c65670,local_410,uVar54 + ((uVar54 / 0x1200) % 0xd) * -0x1200);
        puVar39 = local_418;
        local_470 = local_418[3];
        local_468 = 0;
        local_478 = (undefined *)CONCAT44(local_478._4_4_,local_418[1]);
        local_460 = iVar36;
        (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,*local_418,local_418[2]);
        (**(code **)(*DAT_140c65670 + 0x2a0))();
        (**(code **)(*DAT_140c65670 + 0x228))();
        (**(code **)(*DAT_140c65670 + 0x220))();
        uVar53 = uVar53 | 0x1003f;
        local_2e4 = uVar53;
      }
      if (uVar53 != 0) {
        if ((uVar53 & 1) != 0) {
          (**(code **)(*DAT_140c65670 + 0x1c0))(DAT_140c65670,local_440);
        }
        if ((uVar53 & 4) != 0) {
          (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,local_2e0);
        }
        if ((uVar53 & 8) != 0) {
          local_468 = local_448;
          local_470 = local_450;
          local_478 = (undefined *)CONCAT44(local_478._4_4_,local_444);
          (**(code **)(*DAT_140c65670 + 0x1c8))(DAT_140c65670,local_44c,local_454,local_458);
        }
        if ((uVar53 & 0x10) != 0) {
          (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,local_2bc);
        }
        if ((uVar53 & 2) != 0) {
          (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,local_42c);
        }
        if ((uVar53 & 0x40) != 0) {
          (**(code **)(*DAT_140c65670 + 0x1a0))(DAT_140c65670,local_2b8,0);
        }
        if ((uVar53 & 0x20) != 0) {
          (**(code **)(*DAT_140c65670 + 0x178))(DAT_140c65670,lVar63,uVar54);
        }
        if ((uVar53 & 0x7fff80) != 0) {
          uVar50 = 0;
          puVar39 = local_1a0;
          plVar47 = local_220;
          do {
            if ((uVar53 & 0x80 << ((byte)uVar50 & 0x1f)) != 0) {
              if (*plVar47 == 0) {
                if (plVar47[-0x10] != 0) {
                  local_478 = (undefined *)plVar47[0x18];
                  (**(code **)(*DAT_140c65670 + 0x160))
                            (DAT_140c65670,uVar50,plVar47[-0x10],*puVar39);
                }
              }
              else {
                (**(code **)(*DAT_140c65670 + 0x168))(DAT_140c65670,uVar50,*plVar47,*puVar39);
              }
            }
            uVar50 = uVar50 + 1;
            plVar47 = plVar47 + 1;
            puVar39 = puVar39 + 1;
          } while (uVar50 < 0x10);
        }
        uVar53 = 0;
        local_2e4 = 0;
        puVar39 = local_418;
      }
      local_470 = puVar39[3];
      local_468 = 0;
      local_478 = (undefined *)CONCAT44(local_478._4_4_,puVar39[1]);
      local_460 = iVar36;
      (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,*puVar39,puVar39[2]);
      local_388 = local_388 + uVar52;
    } while (local_388 < param_5);
  }
  return 0;
}



==== FUN_140331620 @ 140331620 ====

undefined4
FUN_140331620(longlong *param_1,longlong *param_2,undefined4 *param_3,longlong param_4,uint *param_5
             )

{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  undefined1 *puVar4;
  longlong lVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  undefined1 local_b8 [8];
  longlong local_b0;
  undefined **local_98;
  undefined4 local_90;
  ulonglong *local_88;
  uint *local_80;
  undefined8 local_78;
  undefined8 local_70;
  longlong local_68;
  ulonglong local_60;
  ulonglong local_58;
  uint *local_50;
  longlong local_48;
  longlong local_40;
  int local_38;
  
  if (param_5 == (uint *)0x0) {
    return 0xe;
  }
  *(undefined4 *)((longlong)param_1 + 0x74) = 1;
  if (((param_4 == 0) || (param_2 == (longlong *)0x0)) || (param_3 == (undefined4 *)0x0)) {
    *(undefined4 *)((longlong)param_1 + 0x74) = 0;
    return 0xc;
  }
  uVar7 = (ulonglong)*param_5;
  if (uVar7 < 6) {
    *(undefined4 *)((longlong)param_1 + 0x74) = 0;
    return 5;
  }
  local_48 = uVar7 + (longlong)param_5;
  local_50 = param_5;
  local_80 = param_5;
  local_88 = &local_60;
  local_98 = &PTR_FUN_140b64918;
  uVar6 = 0;
  local_38 = 0;
  local_90 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = uVar7;
  local_58 = uVar7;
  local_40 = local_48;
  iVar2 = FUN_140336c60(&local_98,&param_5,0x20);
  if ((iVar2 < 0) || (iVar2 = FUN_140336c60(&local_98,&param_5,0x10), puVar1 = param_5, iVar2 < 0))
  {
    uVar6 = 0xc;
    goto LAB_140331940;
  }
  *param_3 = (int)param_5;
  lVar3 = (**(code **)(*param_1 + 0x130))(param_1,(ulonglong)param_5 & 0xffffffff);
  if (lVar3 == 0) {
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_b8,"Message Id #%d",(ulonglong)puVar1 & 0xffffffff);
      puVar4 = local_b8;
    }
    else {
      puVar4 = (undefined1 *)FUN_140335f10(local_b8,(ulonglong)puVar1 & 0xffffffff);
    }
    param_5 = (uint *)0x141debb58;
    FUN_1401a2e50(0xb,0,&param_5,(ulonglong)puVar1 & 0xffffffff,*(undefined8 *)(puVar4 + 8));
    if (local_b0 != 0) {
      FUN_14018b900(local_b0,0);
    }
  }
  else {
    FUN_140334a70(lVar3 + 0x50,uVar7,2);
    *(undefined8 *)(param_4 + 0x30) = *(undefined8 *)(param_4 + 0x20);
    if (*(ulonglong *)(param_4 + 0x18) < *(ulonglong *)(lVar3 + 8)) {
      param_5 = (uint *)0x141debc20;
      FUN_1401a2e50(0xb,0,&param_5);
      FUN_14018b900(param_4,0);
      uVar6 = 4;
      goto LAB_140331940;
    }
    lVar5 = FUN_1403374e0(param_4 + 0x10);
    if (lVar5 == 0) {
      uVar6 = 6;
      goto LAB_140331940;
    }
    *param_2 = lVar5;
    *(undefined4 *)(param_1 + 0xe) = 0;
    if (*(code **)(lVar3 + 0x20) == (code *)0x0) {
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(local_b8,"Message Id #%d",(ulonglong)puVar1 & 0xffffffff);
        puVar4 = local_b8;
      }
      else {
        puVar4 = (undefined1 *)FUN_140335f10(local_b8,(ulonglong)puVar1 & 0xffffffff);
      }
      param_5 = (uint *)0x141debbb0;
      uVar6 = 0xb;
      FUN_1401a3130(0xb,0,&param_5,(ulonglong)puVar1 & 0xffffffff,*(undefined8 *)(puVar4 + 8));
      if (local_b0 != 0) {
        FUN_14018b900(local_b0,0);
      }
      goto LAB_140331940;
    }
    iVar2 = (**(code **)(lVar3 + 0x20))(&local_98,param_4 + 0x10,lVar5);
    if (-1 < iVar2) goto LAB_140331940;
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_b8,"Message Id #%d",(ulonglong)puVar1 & 0xffffffff);
      puVar4 = local_b8;
    }
    else {
      puVar4 = (undefined1 *)FUN_140335f10(local_b8,(ulonglong)puVar1 & 0xffffffff);
    }
    param_5 = (uint *)0x141debc88;
    FUN_1401a2e50(0xb,0,&param_5,(ulonglong)puVar1 & 0xffffffff,*(undefined8 *)(puVar4 + 8));
    if (local_b0 != 0) {
      FUN_14018b900(local_b0,0);
      uVar6 = 8;
      goto LAB_140331940;
    }
  }
  uVar6 = 8;
LAB_140331940:
  *(undefined4 *)((longlong)param_1 + 0x74) = 0;
  local_98 = &PTR_FUN_140b64918;
  if (local_68 != 0) {
    FUN_14018b900(local_68,0);
    local_68 = 0;
  }
  if (local_38 != 0) {
    FUN_14018b900(local_50,0);
  }
  return uVar6;
}



==== FUN_140331990 @ 140331990 ====

undefined8 FUN_140331990(longlong *param_1,longlong param_2,longlong param_3)

{
  ulonglong *puVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined8 local_res18;
  ulonglong local_res20;
  undefined8 in_stack_ffffffffffffff48;
  undefined4 uVar12;
  undefined8 uVar11;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar14;
  undefined8 uVar13;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar15;
  undefined8 in_stack_ffffffffffffff60;
  undefined4 uVar16;
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar17;
  undefined8 local_88;
  ulonglong local_80;
  undefined1 local_78 [8];
  longlong local_70;
  undefined1 local_58 [8];
  longlong local_50;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  local_res18 = CONCAT44(local_res18._4_4_,*(int *)(param_3 + 8));
  if (*(longlong *)(param_3 + 0x10) == 0) {
LAB_140331a31:
    iVar3 = FUN_140336d60(param_3,&local_res20,0x20);
    if (iVar3 < 0) {
      return 0xc;
    }
    uVar10 = (uint)local_res20;
  }
  else {
    puVar1 = *(ulonglong **)(param_3 + 0x18);
    lVar6 = *(longlong *)(param_3 + 0x20);
    if ((ulonglong)
        ((*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x20) * 8 + (longlong)puVar1 * -8) - lVar6)
        < 0x40) goto LAB_140331a31;
    uVar10 = (uint)(*puVar1 >> ((byte)lVar6 & 0x3f));
    if (0x40 < (lVar6 + 0x27U & 0xfffffffffffffff8)) {
      uVar10 = uVar10 | (uint)(byte)puVar1[1] << (0x40 - (byte)lVar6 & 0x3f);
    }
    *(ulonglong *)(param_3 + 0x20) = (ulonglong)((uint)lVar6 & 7);
    lVar6 = (lVar6 + 0x20U >> 3) + (longlong)puVar1;
    *(longlong *)(param_3 + 0x18) = lVar6;
    *(int *)(param_3 + 8) = ((int)lVar6 - (int)puVar1) + *(int *)(param_3 + 8);
  }
  if (*(longlong *)(param_3 + 0x10) == 0) {
LAB_140331ac3:
    iVar3 = FUN_140336d60(param_3,&local_res20,0x10);
    uVar7 = local_res20;
  }
  else {
    lVar6 = *(longlong *)(param_3 + 0x18);
    if ((ulonglong)
        ((*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x20) * 8 + lVar6 * -8) -
        *(longlong *)(param_3 + 0x20)) < 0x40) goto LAB_140331ac3;
    uVar7 = FUN_1400a71c0(param_3 + 0x18,(longlong *)(param_3 + 0x20),0x10);
    *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + (*(int *)(param_3 + 0x18) - (int)lVar6);
    iVar3 = 0;
  }
  if (iVar3 < 0) {
    return 0xc;
  }
  if (*(int *)(param_2 + 0x20) == 1) {
    uVar7 = (ulonglong)((uint)uVar7 | 0x10000);
  }
  iVar3 = (int)uVar7;
  lVar6 = (**(code **)(*param_1 + 0x130))(param_1,uVar7 & 0xffffffff);
  if (lVar6 == 0) {
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_58,"Message Id #%d");
      puVar8 = local_58;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_58,*(undefined4 *)(param_2 + 0x318));
    }
    uVar9 = *(undefined8 *)(puVar8 + 8);
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_78,"Message Id #%d",uVar7 & 0xffffffff);
      puVar8 = local_78;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_78,uVar7 & 0xffffffff);
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar11 = *(undefined8 *)(puVar8 + 8);
    if (*(char *)(lVar6 + 200) == '\0') {
      FUN_140334d90();
    }
    local_res20 = 0x141debc30;
    FUN_1401a2e50(0xb,0,&local_res20,lVar6 + 200,CONCAT44(uVar12,*(undefined4 *)(param_2 + 0x10)),
                  uVar11,CONCAT44(uVar15,uVar10),CONCAT44(uVar16,*(undefined4 *)(param_2 + 0x318)),
                  uVar9);
    lVar6 = local_50;
    if (local_70 != 0) {
      FUN_14018b900(local_70,0);
      lVar6 = local_50;
    }
  }
  else {
    uVar4 = FUN_140335ec0(uVar7 & 0xffffffff);
    local_res20 = CONCAT44(local_res20._4_4_,uVar4);
    local_80 = (ulonglong)((float)uVar4 * DAT_140b79f58);
    if (uVar10 <= uVar4) {
      if ((uint)(longlong)((float)uVar4 * DAT_140b79eb0) < uVar10) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        lVar2 = *(longlong *)(param_2 + 0x18);
        local_88 = *(undefined8 *)(puVar8 + 8);
        uVar9 = local_88;
        if (*(char *)(lVar2 + 200) == '\0') {
          FUN_140334d90();
          uVar9 = local_88;
        }
        local_88 = 0x141debcc0;
        uVar13 = CONCAT44(uVar14,(undefined4)local_res20);
        uVar11 = CONCAT44(uVar12,uVar10);
        FUN_1401a2e50(0xb,1,&local_88,lVar2 + 200,uVar11,uVar13,uVar9);
        uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar15 = (undefined4)((ulonglong)uVar9 >> 0x20);
        uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
        if (local_50 != 0) {
          FUN_14018b900(local_50,0);
        }
      }
      *(int *)(param_2 + 0x318) = iVar3;
      FUN_140334a70(lVar6 + 0x50,uVar10,2);
      param_1[0xc] = param_1[10];
      param_1[8] = local_80 & 0xffffffff;
      puVar8 = (undefined1 *)FUN_1403374e0(param_1 + 8,*(undefined8 *)(lVar6 + 8));
      if (puVar8 == (undefined1 *)0x0) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        local_res20 = 0x141debfb0;
        FUN_1401a3130(0xb,0,&local_res20,uVar7 & 0xffffffff,*(undefined8 *)(puVar8 + 8),
                      *(undefined8 *)(lVar6 + 8));
        if (local_50 != 0) {
          FUN_14018b900(local_50,0);
        }
        iVar3 = *(int *)(param_3 + 8);
        if (*(longlong *)(param_3 + 0x20) != 0) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = iVar3 - (int)local_res18;
        if ((uVar4 != 0) && (uVar4 < uVar10)) {
          FUN_1403370c0(param_3,uVar10 - uVar4);
        }
        return 4;
      }
      if (*(code **)(lVar6 + 0x20) == (code *)0x0) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        local_res20 = 0x141debf40;
        FUN_1401a3130(0xb,0,&local_res20,uVar7 & 0xffffffff,*(undefined8 *)(puVar8 + 8));
        if (local_50 != 0) {
          FUN_14018b900(local_50,0);
        }
        iVar3 = *(int *)(param_3 + 8);
        if (*(longlong *)(param_3 + 0x20) != 0) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = iVar3 - (int)local_res18;
        if ((uVar4 != 0) && (uVar4 < uVar10)) {
          FUN_1403370c0(param_3,uVar10 - uVar4);
        }
        return 0xb;
      }
      iVar5 = (**(code **)(lVar6 + 0x20))(param_3,param_1 + 8,puVar8);
      if (iVar5 < 0) {
        iVar3 = *(int *)(param_3 + 8);
        if (*(longlong *)(param_3 + 0x20) != 0) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = iVar3 - (int)local_res18;
        if ((uVar4 != 0) && (uVar4 < uVar10)) {
          FUN_1403370c0(param_3,uVar10 - uVar4);
        }
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        lVar6 = *(longlong *)(param_2 + 0x18);
        uVar9 = *(undefined8 *)(puVar8 + 8);
        if (*(char *)(lVar6 + 200) == '\0') {
          FUN_140334d90();
        }
        local_res18 = 0x141dec040;
        FUN_1401a2e50(0xb,0,&local_res18,lVar6 + 200,uVar9,CONCAT44(uVar14,uVar4),
                      CONCAT44(uVar15,uVar10));
        if (local_50 == 0) {
          return 8;
        }
        FUN_14018b900(local_50,0);
        return 8;
      }
      if (iVar3 == 0) {
        local_res18 = CONCAT71(local_res18._1_7_,*puVar8);
        (**(code **)(*param_1 + 0xf0))(param_1,*(undefined4 *)(param_2 + 0x10),1,&local_res18);
      }
      else if (iVar3 == 1) {
        FUN_140333790(param_1,*(undefined4 *)(param_2 + 0x10),puVar8);
      }
      else if (iVar3 != 2) {
        lVar6 = *(longlong *)param_1[0xf];
        if (*(int *)(param_2 + 0x20) == 0) {
          iVar3 = (**(code **)(lVar6 + 0x10))();
          if (iVar3 < 0) {
            if (DAT_140c65828 == 0) {
              FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
              puVar8 = local_58;
            }
            else {
              puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
            }
            lVar6 = *(longlong *)(param_2 + 0x18);
            uVar9 = *(undefined8 *)(puVar8 + 8);
            if (*(char *)(lVar6 + 200) == '\0') {
              FUN_140334d90();
            }
            local_res18 = 0x141dec018;
            FUN_1401a2e50(0xb,0,&local_res18,lVar6 + 200,uVar9);
LAB_14033212d:
            if (local_50 != 0) {
              FUN_14018b900(local_50,0);
            }
            return 0xe;
          }
        }
        else {
          iVar3 = (**(code **)(lVar6 + 0x18))
                            ((longlong *)param_1[0xf],param_1,*(undefined4 *)(param_2 + 0x10),
                             *(int *)(param_2 + 0x20),CONCAT44(uVar12,iVar3),puVar8);
          if (iVar3 < 0) {
            if (DAT_140c65828 == 0) {
              FUN_14018ee90(local_78,"Message Id #%d",uVar7 & 0xffffffff);
              puVar8 = local_78;
            }
            else {
              puVar8 = (undefined1 *)FUN_140335f10(local_78,uVar7 & 0xffffffff);
            }
            lVar6 = *(longlong *)(param_2 + 0x18);
            uVar9 = *(undefined8 *)(puVar8 + 8);
            if (*(char *)(lVar6 + 200) == '\0') {
              FUN_140334d90();
            }
            local_res18 = 0x141dec0d8;
            FUN_1401a2e50(0xb,0,&local_res18,lVar6 + 200,uVar9);
            local_50 = local_70;
            goto LAB_14033212d;
          }
        }
      }
      return 0;
    }
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_78,"Message Id #%d");
      puVar8 = local_78;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_78,*(undefined4 *)(param_2 + 0x318));
    }
    uVar9 = *(undefined8 *)(puVar8 + 8);
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
      puVar8 = local_58;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar11 = *(undefined8 *)(puVar8 + 8);
    if (*(char *)(lVar6 + 200) == '\0') {
      FUN_140334d90();
    }
    local_88 = 0x141debd30;
    FUN_1401a2e50(0xb,0,&local_88,lVar6 + 200,CONCAT44(uVar12,*(undefined4 *)(param_2 + 0x10)),
                  CONCAT44(uVar14,uVar10),CONCAT44(uVar15,(undefined4)local_res20),uVar11,
                  CONCAT44(uVar17,*(undefined4 *)(param_2 + 0x318)),uVar9);
    lVar6 = local_70;
    if (local_50 != 0) {
      FUN_14018b900(local_50,0);
      lVar6 = local_70;
    }
  }
  if (lVar6 != 0) {
    FUN_14018b900(lVar6,0);
  }
  iVar3 = *(int *)(param_3 + 8);
  if (*(longlong *)(param_3 + 0x20) != 0) {
    iVar3 = iVar3 + 1;
  }
  uVar4 = iVar3 - (int)local_res18;
  if ((uVar4 != 0) && (uVar4 < uVar10)) {
    FUN_1403370c0(param_3,uVar10 - uVar4);
    return 8;
  }
  return 8;
}



==== FUN_1403331c0 @ 1403331c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1403331c0(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  LARGE_INTEGER local_res8;
  undefined4 local_28 [2];
  longlong *local_20;
  
  if (DAT_140c796cc == 0) {
    if ((uint)(DAT_140c636a8 - _DAT_140c785b0) < 0x7531) {
      FUN_1401c4fb0(0);
    }
    else {
      DAT_140c796cc = 1;
    }
  }
  QueryPerformanceCounter(&local_res8);
  lVar4 = local_res8.QuadPart - _DAT_140c87988;
  while( true ) {
    local_28[0] = 6;
    local_20 = (longlong *)0x0;
    iVar2 = (**(code **)(*(longlong *)param_1[6] + 0x30))((longlong *)param_1[6],local_28);
    plVar1 = local_20;
    if (iVar2 != 0) break;
    switch(local_28[0]) {
    case 0:
      if (local_20 != (longlong *)0x0) {
        (**(code **)*local_20)(local_20);
      }
      local_res8.QuadPart = (LONGLONG)plVar1;
      if (plVar1 != (longlong *)0x0) {
        (**(code **)*plVar1)(plVar1);
      }
      (*(code *)**(undefined8 **)param_1[0xf])((undefined8 *)param_1[0xf],param_1,&local_res8);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 8))(plVar1);
      }
      break;
    case 1:
      uVar3 = (**(code **)(*param_1 + 0x40))(param_1,&local_20);
      FUN_1403315a0(param_1,uVar3,1);
      break;
    case 2:
      uVar3 = (**(code **)(*param_1 + 0x40))(param_1,&local_20);
      FUN_1403315a0(param_1,uVar3,10);
      break;
    case 3:
      FUN_1403323a0(param_1,&local_20);
      break;
    case 4:
      uVar3 = (**(code **)(*param_1 + 0x40))(param_1,&local_20);
      FUN_1403315a0(param_1,uVar3,2);
      break;
    case 5:
      uVar3 = (**(code **)(*param_1 + 0x40))(param_1,&local_20);
      FUN_1403315a0(param_1,uVar3,0x11);
      break;
    default:
      local_res8.QuadPart = 0x141dec288;
      FUN_1401a2e50(0xb,0,&local_res8);
    }
    if (local_20 != (longlong *)0x0) {
      (**(code **)(*local_20 + 8))();
    }
  }
  if (local_20 != (longlong *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  QueryPerformanceCounter(&local_res8);
  if (DAT_140c796cc == 0) {
    if (30000 < (uint)(DAT_140c636a8 - _DAT_140c785b0)) {
      DAT_140c796cc = 1;
      return;
    }
    FUN_1401c5100(L"H Network_Incoming",0,(local_res8.QuadPart - lVar4) - _DAT_140c87988,1);
  }
  return;
}



==== FUN_1403355e0 @ 1403355e0 ====

int FUN_1403355e0(longlong param_1,uint *param_2,undefined8 param_3,ulonglong *param_4,
                 longlong *param_5)

{
  size_t _Size;
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  void *_Src;
  int iVar4;
  int iVar5;
  size_t sVar6;
  undefined ***pppuVar7;
  undefined1 *puVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined *puVar12;
  char *pcVar13;
  ulonglong uVar14;
  uint uVar15;
  ulonglong uVar16;
  float fVar17;
  longlong local_res10;
  undefined8 local_res18;
  undefined8 in_stack_ffffffffffffff40;
  ulonglong uVar18;
  undefined4 uVar19;
  undefined8 local_a8;
  undefined **local_a0;
  undefined8 local_98;
  LPVOID local_90;
  undefined **local_88;
  void *local_80;
  LPVOID local_78;
  undefined1 local_68 [8];
  longlong local_60;
  ulonglong local_48 [2];
  
  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff40 >> 0x20);
  local_res18 = param_3;
  if (*(code **)(param_2 + 4) != (code *)0x0) {
    local_48[0] = *(ulonglong *)(param_2 + 2);
    local_res10 = 0x10;
    (**(code **)(param_2 + 4))(param_3,&local_res10,local_48);
    if ((param_2[0x12] - 1 & 0xfffffffd) != 0) {
      local_res10 = local_res10 + 0x20;
    }
    uVar16 = local_res10 + 7U >> 3;
    if (param_4 != (ulonglong *)0x0) {
      *param_4 = uVar16;
    }
    uVar2 = *param_2;
    lVar11 = 0;
    uVar15 = 0x1fffe;
    if (2 < uVar2) {
      if (uVar2 < DAT_140c1e564) {
        uVar3 = *(uint *)(DAT_140c65828 + (ulonglong)(uVar2 - 3) * 0x10);
        uVar15 = 0x1fffe;
        if (uVar3 != 0) {
          uVar15 = uVar3;
        }
      }
      else {
        uVar15 = 0x1fffe;
        if (((uVar2 >> 0x10) - 1 & 0xfffffffd) != 0) {
          uVar15 = 0;
        }
      }
    }
    uVar14 = (ulonglong)((float)uVar15 * DAT_140b79f58);
    fVar17 = (float)(uVar14 & 0xffffffff) * DAT_140b79eb0;
    if (uVar15 < uVar16) {
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(&local_88,"Message Id #%d");
        pppuVar7 = &local_88;
      }
      else {
        pppuVar7 = (undefined ***)FUN_140335f10(&local_88,uVar2);
      }
      local_a8 = 0x141dec590;
      FUN_1401a3130(0xb,0,&local_a8,*param_2,pppuVar7[1],uVar16,uVar15);
      if (local_80 == (void *)0x0) {
        return 1;
      }
      FUN_14018b900(local_80,0);
      return 1;
    }
    if (((longlong)((float)uVar15 * DAT_140b79eb0) & 0xffffffffU) < uVar16) {
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(&local_88,"Message Id #%d");
        pppuVar7 = &local_88;
      }
      else {
        pppuVar7 = (undefined ***)FUN_140335f10(&local_88,uVar2);
      }
      local_a8 = 0x141dec4a0;
      uVar18 = uVar16;
      FUN_1401a3130(0xb,1,&local_a8,*param_2,pppuVar7[1],uVar16,uVar15);
      uVar19 = (undefined4)(uVar18 >> 0x20);
      if (local_80 != (void *)0x0) {
        FUN_14018b900(local_80,0);
      }
    }
    if ((uVar14 & 0xffffffff) < uVar16) {
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(&local_88,"Message Id #%d");
        pppuVar7 = &local_88;
      }
      else {
        pppuVar7 = (undefined ***)FUN_140335f10(&local_88,*param_2);
      }
      local_a8 = 0x141dec750;
      FUN_1401a3130(0xb,0,&local_a8,*param_2,pppuVar7[1],local_48[0],(int)uVar14);
      if (local_80 == (void *)0x0) {
        return 1;
      }
      FUN_14018b900(local_80,0);
      return 1;
    }
    if (((longlong)fVar17 & 0xffffffffU) < local_48[0]) {
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(&local_88,"Message Id #%d");
        pppuVar7 = &local_88;
      }
      else {
        pppuVar7 = (undefined ***)FUN_140335f10(&local_88,*param_2);
      }
      local_a8 = 0x141dec670;
      uVar18 = local_48[0];
      FUN_1401a3130(0xb,1,&local_a8,*param_2,pppuVar7[1],local_48[0],(int)uVar14);
      uVar19 = (undefined4)(uVar18 >> 0x20);
      if (local_80 != (void *)0x0) {
        FUN_14018b900(local_80,0);
      }
    }
    if ((*(longlong *)(param_1 + 8) == 0) && (*(longlong *)(param_1 + 0x18) == 0)) {
      if (param_5 == (longlong *)0x0) {
        local_98 = 0;
        local_a0 = &PTR_LAB_140b5e648;
        local_90 = TlsGetValue(DAT_140c63720);
        TlsSetValue(DAT_140c63720,&local_a0);
        local_88 = local_a0;
        local_80 = (void *)local_98;
        local_78 = local_90;
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_68,"Message Id #%d");
          puVar8 = local_68;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_68,*param_2);
        }
        local_a8 = 0x141dec870;
        iVar4 = FUN_1401971e0(&DAT_140c8a628,0xb,&local_a8,*param_2,*(undefined8 *)(puVar8 + 8),
                              &local_88);
        if (local_60 != 0) {
          FUN_14018b900(local_60,0);
        }
        local_a0 = &PTR_LAB_140b5e648;
        TlsSetValue(DAT_140c63720,local_90);
        if (iVar4 == 0) {
          return -0x7fffbffb;
        }
        DebugBreak();
        return -0x7fffbffb;
      }
      lVar9 = FUN_14018b280(0x40);
      lVar10 = lVar11;
      if (lVar9 != 0) {
        lVar10 = FUN_140335530(lVar9,uVar16);
      }
      *(longlong *)(param_1 + 8) = lVar10 + 0x10;
      *param_5 = lVar10;
    }
    FUN_140334a70(param_2 + 0x14,uVar16,1);
    if (*(longlong *)(param_1 + 0x10) != 0) {
      *(undefined8 *)(param_1 + 0x10) = 0;
      plVar1 = (longlong *)(*(longlong *)(param_1 + 8) + 0x20);
      *plVar1 = *plVar1 + 1;
    }
    if (*(longlong *)(param_1 + 0x20) == 0) {
      lVar11 = FUN_1403366f0(param_1);
    }
    else {
      lVar10 = *(longlong *)(param_1 + 8);
      if (lVar10 == 0) {
        *(undefined8 *)(param_1 + 0x28) = 0;
      }
      else {
        *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8);
        lVar11 = *(longlong *)(param_1 + 0x10) +
                 (*(longlong *)(lVar10 + 0x20) - *(longlong *)(lVar10 + 0x10)) * 8;
      }
    }
    if (param_2[0x12] == 3) {
LAB_140335d18:
      if (*(code **)(param_2 + 6) == (code *)0x0) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_68,"Message Id #%d");
          puVar8 = local_68;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_68,*param_2);
        }
        local_a8 = 0x141dec910;
        FUN_1401a3130(0xb,0,&local_a8,*param_2,*(undefined8 *)(puVar8 + 8));
        if (local_60 != 0) {
          FUN_14018b900(local_60,0);
        }
        return -0x7fffbffb;
      }
      iVar4 = (**(code **)(param_2 + 6))(param_1,local_res18);
      if (iVar4 < 0) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_68,"Message Id #%d");
          puVar8 = local_68;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_68,*param_2);
        }
        local_a8 = 0x141decab0;
        FUN_1401a3130(0xb,0,&local_a8,*param_2,*(undefined8 *)(puVar8 + 8),CONCAT44(uVar19,iVar4));
        if (local_60 != 0) {
          FUN_14018b900(local_60,0);
          return iVar4;
        }
        return iVar4;
      }
      lVar10 = FUN_140336750(param_1);
      if ((lVar10 - lVar11 != local_res10) && (param_2[0x12] == 0)) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_68,"Message Id #%d");
          puVar8 = local_68;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_68,*param_2);
        }
        local_a8 = 0x141dec9d0;
        FUN_1401a2e50(0xb,0,&local_a8,*(undefined8 *)(puVar8 + 8),lVar10 - lVar11,local_res10);
        if (local_60 != 0) {
          FUN_14018b900(local_60,0);
        }
      }
      if (*(longlong *)(param_1 + 0x10) != 0) {
        *(undefined8 *)(param_1 + 0x10) = 0;
        plVar1 = (longlong *)(*(longlong *)(param_1 + 8) + 0x20);
        *plVar1 = *plVar1 + 1;
      }
      return 0;
    }
    iVar4 = FUN_140336380(param_1,uVar16 & 0xffffffff,0x20);
    if (iVar4 < 0) {
      local_98 = 0;
      local_a0 = &PTR_LAB_140b5e648;
      local_90 = TlsGetValue(DAT_140c63720);
      TlsSetValue(DAT_140c63720,&local_a0);
      local_88 = local_a0;
      local_80 = (void *)local_98;
      local_78 = local_90;
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(local_68,"Message Id #%d");
        puVar8 = local_68;
      }
      else {
        puVar8 = (undefined1 *)FUN_140335f10(local_68,*param_2);
      }
      local_a8 = 0x141dec820;
      puVar12 = &DAT_140c8a624;
    }
    else {
      iVar4 = FUN_140336380(param_1,(short)*param_2,0x10);
      if (-1 < iVar4) goto LAB_140335d18;
      local_98 = 0;
      local_a0 = &PTR_LAB_140b5e648;
      local_90 = TlsGetValue(DAT_140c63720);
      TlsSetValue(DAT_140c63720,&local_a0);
      local_88 = local_a0;
      local_80 = (void *)local_98;
      local_78 = local_90;
      if (DAT_140c65828 == 0) {
        FUN_14018ee90(local_68,"Message Id #%d");
        puVar8 = local_68;
      }
      else {
        puVar8 = (undefined1 *)FUN_140335f10(local_68,*param_2);
      }
      local_a8 = 0x141dec970;
      puVar12 = &DAT_140c8a620;
    }
    iVar5 = FUN_1401971e0(puVar12,0xb,&local_a8,*param_2,*(undefined8 *)(puVar8 + 8),&local_88);
    if (local_60 != 0) {
      FUN_14018b900(local_60,0);
    }
    local_a0 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_90);
    if (iVar5 != 0) {
      DebugBreak();
      return iVar4;
    }
    return iVar4;
  }
  uVar2 = *param_2;
  if (DAT_140c65828 == 0) {
    pcVar13 = "Message Id #%d";
  }
  else if (uVar2 < 3) {
    pcVar13 = "Base Message Id #%d";
  }
  else {
    if ((uVar2 < DAT_140c1e564) &&
       (_Src = *(void **)(DAT_140c65828 + 8 + (ulonglong)(uVar2 - 3) * 0x10), _Src != (void *)0x0))
    {
      local_80 = (void *)0x0;
      _Size = 0xffffffffffffffff;
      do {
        sVar6 = _Size;
        _Size = sVar6 + 1;
      } while (*(char *)((longlong)_Src + sVar6 + 1) != '\0');
      if (sVar6 + 2 != -1) {
        local_80 = (void *)FUN_14018b280(sVar6 + 2,0);
      }
      memcpy(local_80,_Src,_Size);
      if ((undefined1 *)(_Size + (longlong)local_80) != (undefined1 *)0x0) {
        *(undefined1 *)(_Size + (longlong)local_80) = 0;
      }
      goto LAB_1403356bb;
    }
    pcVar13 = "Invalid or foreign Message Id #%d";
  }
  FUN_14018ee90(&local_88,pcVar13);
LAB_1403356bb:
  local_a8 = 0x141dec410;
  FUN_1401a3130(0xb,0,&local_a8,*param_2,local_80);
  if (local_80 != (void *)0x0) {
    FUN_14018b900(local_80,0);
  }
  return -0x7fffbffb;
}



==== FUN_140337160 @ 140337160 ====

int FUN_140337160(undefined8 param_1,undefined8 *param_2,ulonglong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 local_res10;
  undefined1 uStackX_11;
  undefined2 uStackX_12;
  undefined4 uStackX_14;
  
  iVar1 = 0;
  if ((param_3 & 1) != 0) {
    iVar1 = FUN_140336c60(param_1,&local_res10,8);
    param_3 = param_3 - 1;
    *(undefined1 *)param_2 = local_res10;
    param_2 = (undefined8 *)((longlong)param_2 + 1);
  }
  puVar2 = param_2;
  if (((param_3 & 2) != 0) && (-1 < iVar1)) {
    iVar1 = FUN_140336c60(param_1,&local_res10,0x10);
    param_3 = param_3 - 2;
    puVar2 = (undefined8 *)((longlong)param_2 + 2);
    *(ushort *)param_2 = CONCAT11(uStackX_11,local_res10);
  }
  puVar3 = puVar2;
  if (((param_3 & 4) != 0) && (-1 < iVar1)) {
    iVar1 = FUN_140336c60(param_1,&local_res10,0x20);
    param_3 = param_3 - 4;
    puVar3 = (undefined8 *)((longlong)puVar2 + 4);
    *(uint *)puVar2 = CONCAT22(uStackX_12,CONCAT11(uStackX_11,local_res10));
  }
  while ((param_3 != 0 && (-1 < iVar1))) {
    iVar1 = FUN_140336c60(param_1,&local_res10,0x40);
    *puVar3 = CONCAT44(uStackX_14,CONCAT22(uStackX_12,CONCAT11(uStackX_11,local_res10)));
    param_3 = param_3 - 8;
    puVar3 = puVar3 + 1;
  }
  return iVar1;
}



==== FUN_1403390d0 @ 1403390d0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1403390d0(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_a8 [32];
  longlong local_88;
  undefined8 *local_78;
  undefined **local_70;
  undefined8 local_68;
  LPVOID local_60;
  undefined **local_58;
  undefined8 local_50;
  LPVOID local_48;
  sockaddr local_38;
  ulonglong local_28;
  
  local_28 = DAT_140c0f7b0 ^ (ulonglong)auStack_a8;
  if (*(int *)(*param_2 + 0x118) != 2) {
    local_68 = 0;
    local_70 = &PTR_LAB_140b5e648;
    local_60 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_70);
    local_58 = local_70;
    local_78 = (undefined8 *)0x141ded038;
    local_48 = local_60;
    local_50 = local_68;
    iVar3 = FUN_140196f30(&DAT_140c8a640,0xb,&local_78,&local_58);
    local_70 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_60);
    if (iVar3 != 0) {
      DebugBreak();
    }
  }
  lVar1 = *param_2;
  local_38._0_4_ = *(undefined4 *)(lVar1 + 0x90);
  local_38.sa_data._2_4_ = *(undefined4 *)(lVar1 + 0x94);
  local_38.sa_data._6_4_ = *(undefined4 *)(lVar1 + 0x98);
  local_38.sa_data._10_4_ = *(undefined4 *)(lVar1 + 0x9c);
  iVar3 = connect(*(SOCKET *)(lVar1 + 0x110),&local_38,0x10);
  iVar4 = WSAGetLastError();
  if (iVar3 == -1) {
    if ((iVar4 - 0x2726U < 0x10) && ((0xa001U >> (iVar4 - 0x2726U & 0x1f) & 1) != 0)) {
      lVar1 = *param_2;
      if (*(short *)(lVar1 + 0xde) == 0) {
        FUN_140334d90();
      }
      lVar2 = *param_2;
      if (*(short *)(lVar2 + 0x5e) == 0) {
        FUN_140334d90();
      }
      local_78 = (undefined8 *)0x141ded100;
      local_88 = lVar1 + 0xde;
      FUN_1401a3130(0xb,3,&local_78,lVar2 + 0x5e);
      goto LAB_140339369;
    }
    if (iVar4 != 0x2748) {
      lVar1 = *param_2;
      iVar3 = WSAGetLastError();
      FUN_140338eb0(L"connect",iVar3,lVar1 + 0x90);
      *(undefined4 *)(*param_2 + 0x118) = 5;
      if ((longlong *)*param_2 != (longlong *)0x0) {
        (**(code **)(*(longlong *)*param_2 + 8))();
      }
      return 0x80004005;
    }
    lVar1 = *param_2;
    if (*(short *)(lVar1 + 0xde) == 0) {
      FUN_140334d90();
    }
    lVar2 = *param_2;
    if (*(short *)(lVar2 + 0x5e) == 0) {
      FUN_140334d90();
    }
    local_78 = (undefined8 *)0x141ded0b0;
  }
  else {
    lVar1 = *param_2;
    if (*(short *)(lVar1 + 0xde) == 0) {
      FUN_140334d90();
    }
    lVar2 = *param_2;
    if (*(short *)(lVar2 + 0x5e) == 0) {
      FUN_140334d90();
    }
    local_78 = (undefined8 *)0x141ded150;
  }
  local_88 = lVar1 + 0xde;
  FUN_1401a3130(0xb,1,&local_78,lVar2 + 0x5e);
  *(undefined4 *)(*param_2 + 0x118) = 3;
  local_78 = (undefined8 *)*param_2;
  if (local_78 != (undefined8 *)0x0) {
    (**(code **)*local_78)();
  }
  FUN_140338df0(param_1,1,&local_78);
LAB_140339369:
  if ((longlong *)*param_2 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_2 + 8))();
  }
  return 0;
}



==== FUN_140339440 @ 140339440 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * FUN_140339440(undefined8 param_1,longlong *param_2,undefined4 *param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 auStack_58 [32];
  SOCKET local_38;
  sockaddr local_30;
  ulonglong local_20;
  
  local_20 = DAT_140c0f7b0 ^ (ulonglong)auStack_58;
  plVar2 = (longlong *)FUN_140338f90(param_1,&local_38);
  if (-1 < (int)plVar2) {
    local_30._0_4_ = *param_3;
    local_30.sa_data._2_4_ = param_3[1];
    local_30.sa_data._6_4_ = param_3[2];
    local_30.sa_data._10_4_ = param_3[3];
    iVar1 = bind(local_38,&local_30,0x10);
    if (iVar1 == 0) {
      lVar3 = FUN_14018b280(0x1f0,0);
      plVar2 = (longlong *)0x0;
      plVar4 = plVar2;
      if (lVar3 != 0) {
        plVar4 = (longlong *)FUN_14033e900(lVar3,local_38);
      }
      *(undefined4 *)((longlong)plVar4 + 0x11c) = 2;
      iVar1 = listen(local_38,0x7fffffff);
      if (iVar1 == 0) {
        if (*(short *)((longlong)plVar4 + 0x5e) == 0) {
          FUN_140334d90();
        }
        local_38 = 0x141dece40;
        FUN_1401a3130(0xb,1,&local_38,(longlong)plVar4 + 0x5e);
        *(undefined4 *)(plVar4 + 0x23) = 4;
        if ((longlong *)*param_2 != plVar4) {
          (**(code **)*plVar4)(plVar4);
          if ((longlong *)*param_2 != (longlong *)0x0) {
            (**(code **)(*(longlong *)*param_2 + 8))();
          }
          *param_2 = (longlong)plVar4;
        }
      }
      else {
        WSAGetLastError();
        *(undefined4 *)(plVar4 + 0x23) = 5;
        iVar1 = WSAGetLastError();
        FUN_140338eb0(L"listen",iVar1,param_3);
        plVar2 = (longlong *)0x80004005;
      }
      (**(code **)(*plVar4 + 8))(plVar4);
    }
    else {
      iVar1 = WSAGetLastError();
      FUN_140338eb0(L"bind",iVar1,param_3);
      plVar2 = (longlong *)0x80004005;
    }
  }
  return plVar2;
}



==== FUN_14033bc50 @ 14033bc50 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14033bc50(longlong param_1,longlong *param_2,undefined8 param_3)

{
  int iVar1;
  DWORD DVar2;
  undefined8 uVar3;
  longlong *CompletionKey;
  HANDLE pvVar4;
  undefined1 auStack_e8 [32];
  HANDLE local_c8;
  sockaddr local_c0;
  sockaddr local_a8 [2];
  longlong local_88;
  ulonglong local_28;
  
  local_28 = DAT_140c0f7b0 ^ (ulonglong)auStack_e8;
  uVar3 = FUN_14033bb50(param_1,&local_c8);
  if (-1 < (int)uVar3) {
    FUN_140334bb0(local_a8,0,0);
    local_c0.sa_family = local_a8[0].sa_family;
    local_c0.sa_data[0] = local_a8[0].sa_data[0];
    local_c0.sa_data[1] = local_a8[0].sa_data[1];
    local_c0.sa_data[2] = local_a8[0].sa_data[2];
    local_c0.sa_data[3] = local_a8[0].sa_data[3];
    local_c0.sa_data[4] = local_a8[0].sa_data[4];
    local_c0.sa_data[5] = local_a8[0].sa_data[5];
    local_c0.sa_data[6] = local_a8[0].sa_data[6];
    local_c0.sa_data[7] = local_a8[0].sa_data[7];
    local_c0.sa_data[8] = local_a8[0].sa_data[8];
    local_c0.sa_data[9] = local_a8[0].sa_data[9];
    local_c0.sa_data[10] = local_a8[0].sa_data[10];
    local_c0.sa_data[0xb] = local_a8[0].sa_data[0xb];
    local_c0.sa_data[0xc] = local_a8[0].sa_data[0xc];
    local_c0.sa_data[0xd] = local_a8[0].sa_data[0xd];
    iVar1 = bind((SOCKET)local_c8,&local_c0,0x10);
    if (iVar1 == 0) {
      CompletionKey = (longlong *)FUN_14018b280(0x218,0);
      if (CompletionKey == (longlong *)0x0) {
        CompletionKey = (longlong *)0x0;
      }
      else {
        FUN_14033ea90(CompletionKey,local_c8,param_3);
        *CompletionKey = (longlong)&PTR_FUN_140b64a88;
        CompletionKey[0x3e] = 0;
        CompletionKey[0x3f] = 0;
        CompletionKey[0x40] = 0;
        CompletionKey[0x41] = 0;
      }
      uVar3 = 0;
      *(undefined4 *)(CompletionKey + 0x23) = 2;
      pvVar4 = CreateIoCompletionPort
                         (local_c8,*(HANDLE *)(param_1 + 0x90),(ULONG_PTR)CompletionKey,0);
      if (pvVar4 == (HANDLE)0x0) {
        DVar2 = GetLastError();
        FUN_14033b860(L"CreateIoCompletionPort",DVar2,0);
        uVar3 = 0x80004005;
      }
      else if ((longlong *)*param_2 != CompletionKey) {
        (**(code **)*CompletionKey)(CompletionKey);
        if ((longlong *)*param_2 != (longlong *)0x0) {
          (**(code **)(*(longlong *)*param_2 + 8))();
        }
        *param_2 = (longlong)CompletionKey;
      }
      (**(code **)(*CompletionKey + 8))(CompletionKey);
    }
    else {
      iVar1 = WSAGetLastError();
      FUN_14033b860(L"bind",iVar1,0);
      uVar3 = 0x80004005;
    }
    if (local_88 != 0) {
      FUN_14018b900(local_88,0);
    }
  }
  return uVar3;
}



==== FUN_14033bde0 @ 14033bde0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * FUN_14033bde0(longlong param_1,longlong *param_2,undefined4 *param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *CompletionKey;
  HANDLE pvVar4;
  undefined1 auStack_68 [32];
  HANDLE local_48;
  sockaddr local_40;
  ulonglong local_30;
  
  local_30 = DAT_140c0f7b0 ^ (ulonglong)auStack_68;
  plVar2 = (longlong *)FUN_14033bb50(param_1,&local_48);
  if (-1 < (int)plVar2) {
    local_40._0_4_ = *param_3;
    local_40.sa_data._2_4_ = param_3[1];
    local_40.sa_data._6_4_ = param_3[2];
    local_40.sa_data._10_4_ = param_3[3];
    iVar1 = bind((SOCKET)local_48,&local_40,0x10);
    if (iVar1 == 0) {
      lVar3 = FUN_14018b280(0x218,0);
      plVar2 = (longlong *)0x0;
      CompletionKey = plVar2;
      if (lVar3 != 0) {
        CompletionKey = (longlong *)FUN_14033ae10(lVar3,local_48);
      }
      *(undefined4 *)((longlong)CompletionKey + 0x11c) = 2;
      iVar1 = listen((SOCKET)local_48,0x7fffffff);
      if (iVar1 == -1) {
        *(undefined4 *)(CompletionKey + 0x23) = 5;
        iVar1 = WSAGetLastError();
        FUN_14033b860(L"CNetworkDriverIOCompletion::ListenSocket listen",iVar1,0);
        plVar2 = (longlong *)0x80004005;
      }
      else {
        FUN_14033b950(L"listen",CompletionKey + 2,L"established");
        *(undefined4 *)(CompletionKey + 0x23) = 4;
        pvVar4 = CreateIoCompletionPort
                           (local_48,*(HANDLE *)(param_1 + 0x90),(ULONG_PTR)CompletionKey,0);
        if (pvVar4 == (HANDLE)0x0) {
          iVar1 = WSAGetLastError();
          FUN_14033b860(L"CNetworkDriverIOCompletion::ListenSocket CreateIoCompletionPort",iVar1,0);
          plVar2 = (longlong *)0x80004005;
        }
        else if ((longlong *)*param_2 != CompletionKey) {
          (**(code **)*CompletionKey)(CompletionKey);
          if ((longlong *)*param_2 != (longlong *)0x0) {
            (**(code **)(*(longlong *)*param_2 + 8))();
          }
          *param_2 = (longlong)CompletionKey;
        }
      }
      (**(code **)(*CompletionKey + 8))(CompletionKey);
    }
    else {
      iVar1 = WSAGetLastError();
      FUN_14033b860(L"CNetworkDriverIOCompletion::ListenSocket bind",iVar1,0);
      plVar2 = (longlong *)0x80004005;
    }
  }
  return plVar2;
}



==== FUN_14033d650 @ 14033d650 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14033d650(longlong param_1,undefined8 *param_2)

{
  DWORD *pDVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  DWORD DVar9;
  undefined8 *puVar10;
  HANDLE pvVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  bool bVar14;
  undefined1 auStack_f8 [32];
  wchar_t *local_d8;
  ulonglong local_d0;
  ulonglong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  PROCESS_MEMORY_COUNTERS local_98;
  ulonglong local_48;
  
  local_48 = DAT_140c0f7b0 ^ (ulonglong)auStack_f8;
  puVar10 = (undefined8 *)FUN_14018b280(0x30);
  puVar12 = (undefined8 *)0x0;
  puVar13 = puVar12;
  if (puVar10 != (undefined8 *)0x0) {
    *puVar10 = &PTR_FUN_140b64a10;
    *(undefined4 *)(puVar10 + 1) = 1;
    puVar10[3] = 0;
    puVar10[4] = 0;
    puVar10[5] = 0;
    puVar13 = puVar10;
  }
  FUN_14033a7e0(puVar13 + 2,0x10);
  local_d0 = (ulonglong)*(uint *)(param_1 + 0xa8);
  puVar10 = (undefined8 *)puVar13[4];
  local_d8 = L"threads created";
  if (puVar10 == (undefined8 *)puVar13[5]) {
    local_c8 = local_d0;
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"threads created";
      puVar10[1] = local_d0;
      puVar10[2] = local_d0;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  uVar2 = *(uint *)(param_1 + 0xac);
  local_d0 = (ulonglong)uVar2;
  local_d8 = L"threads active";
  if (*(uint *)(param_1 + 0x164) < uVar2) {
    *(uint *)(param_1 + 0x164) = uVar2;
  }
  puVar10 = (undefined8 *)puVar13[4];
  local_c8 = (ulonglong)*(uint *)(param_1 + 0x164);
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"threads active";
      puVar10[1] = local_d0;
      puVar10[2] = local_c8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  pDVar1 = (DWORD *)(param_1 + 0xb8);
  DVar9 = GetCurrentThreadId();
  puVar10 = puVar12;
  if (*pDVar1 == DVar9) {
    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + 1;
  }
  else {
    do {
      LOCK();
      bVar14 = *(longlong *)(param_1 + 0xc0) == 0;
      if (bVar14) {
        *(longlong *)(param_1 + 0xc0) = 1;
      }
      UNLOCK();
      if (bVar14) {
        *pDVar1 = DVar9;
        goto LAB_14033d7b6;
      }
      puVar10 = (undefined8 *)((longlong)puVar10 + 1);
    } while (puVar10 < (undefined8 *)0x400);
    FUN_14019fb60(pDVar1);
  }
LAB_14033d7b6:
  lVar3 = *(longlong *)(param_1 + 0x58);
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_1 + 0x30);
  lVar6 = *(longlong *)(param_1 + 0x38);
  lVar7 = *(longlong *)(param_1 + 0x20);
  lVar8 = *(longlong *)(param_1 + 0x48);
  if (*(ulonglong *)(param_1 + 0xc0) < 2) {
    *pDVar1 = 0;
    LOCK();
    *(undefined8 *)(param_1 + 0xc0) = 0;
    UNLOCK();
    if (*(longlong *)(param_1 + 200) != 0) {
      if (*(longlong *)(param_1 + 0xd0) == 0) {
        pvVar11 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        LOCK();
        bVar14 = *(longlong *)(param_1 + 0xd0) == 0;
        if (bVar14) {
          *(longlong *)(param_1 + 0xd0) = (longlong)pvVar11;
        }
        UNLOCK();
        if (!bVar14) {
          CloseHandle(pvVar11);
        }
      }
      SetEvent(*(HANDLE *)(param_1 + 0xd0));
    }
  }
  else {
    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + -1;
  }
  puVar10 = (undefined8 *)puVar13[4];
  local_c8 = (ulonglong)*(uint *)(param_1 + 0x158);
  local_d0 = (ulonglong)
             ((int)(lVar5 - lVar7 >> 4) + -0x1f +
             (int)(lVar3 - lVar6 >> 3) * 0x1f + (int)(lVar4 - lVar8 >> 4));
  local_d8 = L"resultQueueLength";
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"resultQueueLength";
      puVar10[1] = local_d0;
      puVar10[2] = local_c8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  puVar10 = (undefined8 *)puVar13[4];
  local_d0 = (ulonglong)*(uint *)(param_1 + 0x14c);
  local_c8 = (ulonglong)*(uint *)(param_1 + 0x15c);
  local_d8 = L"send Operations in progress";
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"send Operations in progress";
      puVar10[1] = local_d0;
      puVar10[2] = local_c8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  puVar10 = (undefined8 *)puVar13[4];
  local_d0 = (ulonglong)*(uint *)(param_1 + 0x150);
  local_c8 = (ulonglong)*(uint *)(param_1 + 0x160);
  local_d8 = L"recv Operations in progress";
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"recv Operations in progress";
      puVar10[1] = local_d0;
      puVar10[2] = local_c8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  local_d8 = L"socket count";
  DVar9 = GetCurrentThreadId();
  if (*pDVar1 == DVar9) {
    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + 1;
  }
  else {
    do {
      LOCK();
      bVar14 = *(longlong *)(param_1 + 0xc0) == 0;
      if (bVar14) {
        *(longlong *)(param_1 + 0xc0) = 1;
      }
      UNLOCK();
      if (bVar14) {
        *pDVar1 = DVar9;
        goto LAB_14033d977;
      }
      puVar12 = (undefined8 *)((longlong)puVar12 + 1);
    } while (puVar12 < (undefined8 *)0x400);
    FUN_14019fb60(pDVar1);
  }
LAB_14033d977:
  local_d0 = (ulonglong)*(uint *)(param_1 + 0x70);
  if (*(ulonglong *)(param_1 + 0xc0) < 2) {
    *pDVar1 = 0;
    LOCK();
    *(undefined8 *)(param_1 + 0xc0) = 0;
    UNLOCK();
    if (*(longlong *)(param_1 + 200) != 0) {
      if (*(longlong *)(param_1 + 0xd0) == 0) {
        pvVar11 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        LOCK();
        bVar14 = *(longlong *)(param_1 + 0xd0) == 0;
        if (bVar14) {
          *(longlong *)(param_1 + 0xd0) = (longlong)pvVar11;
        }
        UNLOCK();
        if (!bVar14) {
          CloseHandle(pvVar11);
        }
      }
      SetEvent(*(HANDLE *)(param_1 + 0xd0));
    }
  }
  else {
    *(longlong *)(param_1 + 0xc0) = *(longlong *)(param_1 + 0xc0) + -1;
  }
  local_c8 = (ulonglong)*(uint *)(param_1 + 0x154);
  puVar10 = (undefined8 *)puVar13[4];
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = local_d8;
      puVar10[1] = local_d0;
      puVar10[2] = local_c8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  (**(code **)(*DAT_140c65808 + 0xd8))(DAT_140c65808,&local_c0);
  puVar10 = (undefined8 *)puVar13[4];
  local_d0 = local_b0;
  local_d8 = L"overlappedPlusFree";
  local_c8 = local_a8;
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"overlappedPlusFree";
      puVar10[1] = local_b0;
      puVar10[2] = local_a8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  puVar10 = (undefined8 *)puVar13[4];
  local_d0 = local_c0;
  local_c8 = local_b8;
  local_d8 = L"numBuffersFree";
  if (puVar10 == (undefined8 *)puVar13[5]) {
    FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
  }
  else {
    if (puVar10 != (undefined8 *)0x0) {
      *puVar10 = L"numBuffersFree";
      puVar10[1] = local_c0;
      puVar10[2] = local_b8;
    }
    puVar13[4] = puVar13[4] + 0x18;
  }
  DVar9 = GetCurrentProcessId();
  pvVar11 = OpenProcess(0x410,0,DVar9);
  if (pvVar11 != (HANDLE)0x0) {
    GetProcessMemoryInfo(pvVar11,&local_98,0x48);
    puVar10 = (undefined8 *)puVar13[4];
    local_d0 = (ulonglong)local_98.PageFaultCount;
    local_c8 = 0;
    local_d8 = L"PageFaultCount";
    if (puVar10 == (undefined8 *)puVar13[5]) {
      FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
    }
    else {
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = L"PageFaultCount";
        puVar10[1] = local_d0;
        puVar10[2] = 0;
      }
      puVar13[4] = puVar13[4] + 0x18;
    }
    puVar10 = (undefined8 *)puVar13[4];
    local_d0 = local_98.WorkingSetSize;
    local_c8 = local_98.PeakWorkingSetSize;
    local_d8 = L"WorkingSetSize";
    if (puVar10 == (undefined8 *)puVar13[5]) {
      FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
    }
    else {
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = L"WorkingSetSize";
        puVar10[1] = local_98.WorkingSetSize;
        puVar10[2] = local_98.PeakWorkingSetSize;
      }
      puVar13[4] = puVar13[4] + 0x18;
    }
    puVar10 = (undefined8 *)puVar13[4];
    local_d0 = local_98.PagefileUsage;
    local_c8 = local_98.PeakPagefileUsage;
    local_d8 = L"PagefileUsage";
    if (puVar10 == (undefined8 *)puVar13[5]) {
      FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
    }
    else {
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = L"PagefileUsage";
        puVar10[1] = local_98.PagefileUsage;
        puVar10[2] = local_98.PeakPagefileUsage;
      }
      puVar13[4] = puVar13[4] + 0x18;
    }
    puVar10 = (undefined8 *)puVar13[4];
    local_d0 = local_98.QuotaPagedPoolUsage;
    local_c8 = local_98.QuotaPeakPagedPoolUsage;
    local_d8 = L"QuotaPagedPoolUsage";
    if (puVar10 == (undefined8 *)puVar13[5]) {
      FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
    }
    else {
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = L"QuotaPagedPoolUsage";
        puVar10[1] = local_98.QuotaPagedPoolUsage;
        puVar10[2] = local_98.QuotaPeakPagedPoolUsage;
      }
      puVar13[4] = puVar13[4] + 0x18;
    }
    puVar10 = (undefined8 *)puVar13[4];
    local_d0 = local_98.QuotaNonPagedPoolUsage;
    local_c8 = local_98.QuotaPeakNonPagedPoolUsage;
    local_d8 = L"QuotaNonPagedPoolUsage";
    if (puVar10 == (undefined8 *)puVar13[5]) {
      FUN_14033a9d0(puVar13 + 2,puVar10,&local_d8);
    }
    else {
      if (puVar10 != (undefined8 *)0x0) {
        *puVar10 = L"QuotaNonPagedPoolUsage";
        puVar10[1] = local_98.QuotaNonPagedPoolUsage;
        puVar10[2] = local_98.QuotaPeakNonPagedPoolUsage;
      }
      puVar13[4] = puVar13[4] + 0x18;
    }
  }
  *param_2 = puVar13;
  return;
}


