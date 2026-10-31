
undefined8 FUN_1405eda10(longlong param_1)

{
  undefined4 *puVar1;
  double *pdVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  undefined **local_78;
  uint local_70;
  longlong local_68;
  undefined4 local_60;
  undefined1 local_58 [8];
  longlong local_50;
  ulonglong uVar10;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  if (((((*(undefined4 **)(param_1 + 0x10) <= puVar1) || (puVar1 == &DAT_140a12138)) ||
       (puVar1[2] != 0)) &&
      ((lVar4 = FUN_140056ab0(param_1,1,"Game.Spell"), lVar4 != 0 && (*(longlong *)(lVar4 + 8) != 0)
       ))) && (lVar4 = FUN_1403acd90(DAT_140c65b70,*(undefined4 *)(*(longlong *)(lVar4 + 8) + 8),
                                     *(undefined8 *)(DAT_140c65898 + 0x78)), lVar4 != 0)) {
    local_78 = &PTR_FUN_140b569f0;
    local_60 = 1;
    local_68 = param_1;
    if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
        *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
      FUN_14005e2c0(param_1);
    }
    puVar13 = *(undefined8 **)(param_1 + 0x10);
    uVar5 = FUN_14005c1b0(param_1,0,0);
    *(undefined4 *)(puVar13 + 1) = 5;
    *puVar13 = uVar5;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    local_70 = FUN_1400578c0(param_1);
    uVar12 = (ulonglong)local_70;
    if ((*(longlong *)(lVar4 + 0x30) != 0) && (uVar10 = 0, *(int *)(lVar4 + 0x28) != 0)) {
      do {
        if ((*(int *)(uVar10 * 0xa8 + 0x10 + *(longlong *)(lVar4 + 0x30)) == 0x1a) &&
           ((lVar6 = FUN_1403acd90(DAT_140c65b70,*(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x40)
                                  ), lVar6 != 0 && (*(longlong *)(lVar6 + 0x50) != 0)))) {
          if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
              *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
            FUN_14005e2c0(param_1);
          }
          puVar13 = *(undefined8 **)(param_1 + 0x10);
          uVar5 = FUN_14005c1b0(param_1,0);
          *(undefined4 *)(puVar13 + 1) = 5;
          *puVar13 = uVar5;
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          uVar3 = FUN_1400578c0(param_1);
          uVar9 = *(uint *)(*(longlong *)(lVar6 + 0x50) + 4);
          puVar7 = (undefined8 *)
                   FUN_14005c3c0(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0xa0),uVar3);
          puVar13 = *(undefined8 **)(param_1 + 0x10);
          *puVar13 = *puVar7;
          *(undefined4 *)(puVar13 + 1) = *(undefined4 *)(puVar7 + 1);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          lVar8 = FUN_14018f0e0(local_58,L"fMaxTime");
          if (*(longlong *)(lVar8 + 8) == 0) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
            *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          }
          else {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (*(char *)(*(longlong *)(lVar8 + 8) + lVar11) != '\0');
            FUN_140058710(param_1);
          }
          if (local_50 != 0) {
            FUN_14018b900(local_50,0);
          }
          pdVar2 = *(double **)(param_1 + 0x10);
          *(undefined4 *)(pdVar2 + 1) = 3;
          *pdVar2 = (double)((float)uVar9 * 0.001);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          uVar5 = FUN_1400580e0(param_1,0xfffffffd);
          FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                        *(longlong *)(param_1 + 0x10) + -0x10);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x30;
          uVar9 = **(uint **)(lVar6 + 0x50);
          puVar13 = *(undefined8 **)(param_1 + 0x10);
          puVar7 = (undefined8 *)
                   FUN_14005c3c0(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0xa0),uVar3);
          *puVar13 = *puVar7;
          *(undefined4 *)(puVar13 + 1) = *(undefined4 *)(puVar7 + 1);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          lVar8 = FUN_14018f0e0(local_58,L"fInitialDelay");
          if (*(longlong *)(lVar8 + 8) == 0) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
            *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          }
          else {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (*(char *)(*(longlong *)(lVar8 + 8) + lVar11) != '\0');
            FUN_140058710(param_1);
          }
          if (local_50 != 0) {
            FUN_14018b900(local_50,0);
          }
          pdVar2 = *(double **)(param_1 + 0x10);
          *(undefined4 *)(pdVar2 + 1) = 3;
          *pdVar2 = (double)((float)uVar9 * 0.001);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          uVar5 = FUN_1400580e0(param_1,0xfffffffd);
          FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                        *(longlong *)(param_1 + 0x10) + -0x10);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x30;
          uVar9 = *(uint *)(*(longlong *)(lVar6 + 0x50) + 8);
          puVar13 = *(undefined8 **)(param_1 + 0x10);
          puVar7 = (undefined8 *)
                   FUN_14005c3c0(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0xa0),uVar3);
          *puVar13 = *puVar7;
          *(undefined4 *)(puVar13 + 1) = *(undefined4 *)(puVar7 + 1);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          lVar6 = FUN_14018f0e0(local_58,L"fPulseTime");
          if (*(longlong *)(lVar6 + 8) == 0) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
            *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          }
          else {
            lVar8 = -1;
            do {
              lVar8 = lVar8 + 1;
            } while (*(char *)(*(longlong *)(lVar6 + 8) + lVar8) != '\0');
            FUN_140058710(param_1);
          }
          if (local_50 != 0) {
            FUN_14018b900(local_50,0);
          }
          pdVar2 = *(double **)(param_1 + 0x10);
          *(undefined4 *)(pdVar2 + 1) = 3;
          *pdVar2 = (double)((float)uVar9 * 0.001);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          uVar5 = FUN_1400580e0(param_1,0xfffffffd);
          FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                        *(longlong *)(param_1 + 0x10) + -0x10);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x30;
          FUN_1400fb1d0(&local_78,uVar3);
          FUN_1400579e0(param_1);
        }
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(lVar4 + 0x28));
      uVar12 = (ulonglong)local_70;
      param_1 = local_68;
    }
    puVar7 = (undefined8 *)
             FUN_14005c3c0(*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0xa0),uVar12);
    puVar13 = *(undefined8 **)(param_1 + 0x10);
    *puVar13 = *puVar7;
    uVar3 = *(undefined4 *)(puVar7 + 1);
    *(undefined4 *)(puVar13 + 1) = uVar3;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    FUN_1400579e0(param_1,uVar3,uVar12 & 0xffffffff);
    return 1;
  }
  return 0;
}

