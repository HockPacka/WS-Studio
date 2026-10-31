
void FUN_1407cb5a0(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  int *piVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  short *psVar9;
  ushort uVar10;
  undefined4 *puVar11;
  short sVar12;
  uint uVar13;
  longlong lVar14;
  int iVar15;
  short *psVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  short sVar20;
  undefined **ppuVar21;
  longlong lVar22;
  float fVar23;
  
  iVar7 = (**(code **)(**(longlong **)(param_1 + 0x17a8) + 0x28))();
  if (iVar7 == 0) {
    *(undefined4 *)(param_1 + 0x17b8) = 0;
    puVar8 = (undefined4 *)
             (**(code **)(**(longlong **)(param_1 + 0x17a8) + 0x38))
                       (*(longlong **)(param_1 + 0x17a8),0,0,2);
    piVar5 = DAT_140c63750;
    if (puVar8 != (undefined4 *)0x0) {
      ppuVar21 = &PTR_PTR_140c3acf8;
      lVar22 = 0xe;
      iVar7 = *(int *)(PTR_PTR_140c3acf0 + 0x10);
      if (*DAT_140c63750 < *(int *)(PTR_PTR_140c3acf0 + 0x10)) {
        iVar7 = *DAT_140c63750;
      }
      puVar18 = puVar8 + 4;
      uVar2 = *(undefined4 *)(PTR_PTR_140c3acf0 + (longlong)iVar7 * 4 + 0x20);
      *puVar8 = 0;
      puVar8[3] = 0;
      iVar15 = 1;
      puVar8[1] = uVar2;
      puVar8[2] = 0;
      *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
      iVar7 = *(int *)(PTR_PTR_140c3acf0 + 0x10);
      if (*piVar5 < *(int *)(PTR_PTR_140c3acf0 + 0x10)) {
        iVar7 = *piVar5;
      }
      fVar23 = *(float *)(PTR_PTR_140c3acf0 + (longlong)iVar7 * 4 + 0x20);
      do {
        iVar7 = *(int *)(*ppuVar21 + 0x10);
        if (*piVar5 < iVar7) {
          iVar7 = *piVar5;
        }
        fVar23 = fVar23 - *(float *)(*ppuVar21 + (longlong)iVar7 * 4 + 0x20);
        lVar14 = 4;
        puVar8 = puVar18 + 4;
        puVar11 = (undefined4 *)(param_1 + 0x16ac);
        do {
          puVar19 = puVar18;
          uVar2 = puVar11[-1];
          uVar3 = *puVar11;
          puVar8[-1] = iVar15;
          puVar18 = puVar19 + 0x20;
          *puVar19 = uVar2;
          puVar19[1] = fVar23;
          puVar19[2] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[1];
          uVar3 = puVar11[2];
          puVar8[3] = iVar15;
          *puVar8 = uVar2;
          puVar8[1] = fVar23;
          puVar8[2] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[3];
          uVar3 = puVar11[4];
          puVar8[7] = iVar15;
          puVar8[4] = uVar2;
          puVar8[5] = fVar23;
          puVar8[6] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[5];
          uVar3 = puVar11[6];
          puVar8[0xb] = iVar15;
          puVar8[8] = uVar2;
          puVar8[9] = fVar23;
          puVar8[10] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[7];
          uVar3 = puVar11[8];
          puVar8[0xf] = iVar15;
          puVar8[0xc] = uVar2;
          puVar8[0xd] = fVar23;
          puVar8[0xe] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[9];
          uVar3 = puVar11[10];
          puVar8[0x13] = iVar15;
          puVar8[0x10] = uVar2;
          puVar8[0x11] = fVar23;
          puVar8[0x12] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[0xb];
          uVar3 = puVar11[0xc];
          puVar8[0x17] = iVar15;
          puVar8[0x14] = uVar2;
          puVar8[0x15] = fVar23;
          puVar8[0x16] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          uVar2 = puVar11[0xd];
          uVar3 = puVar11[0xe];
          puVar8[0x1b] = iVar15;
          puVar8[0x18] = uVar2;
          puVar8[0x19] = fVar23;
          puVar8[0x1a] = uVar3;
          *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
          lVar14 = lVar14 + -1;
          puVar8 = puVar8 + 0x20;
          puVar11 = puVar11 + 0x10;
        } while (lVar14 != 0);
        iVar15 = iVar15 + 1;
        ppuVar21 = ppuVar21 + 1;
        lVar22 = lVar22 + -1;
      } while (lVar22 != 0);
      iVar7 = *(int *)(PTR_PTR_140c3ad68 + 0x10);
      if (*piVar5 < *(int *)(PTR_PTR_140c3ad68 + 0x10)) {
        iVar7 = *piVar5;
      }
      fVar4 = *(float *)(PTR_PTR_140c3ad68 + (longlong)iVar7 * 4 + 0x20);
      *puVar18 = 0;
      puVar19[0x23] = 0xf;
      puVar19[0x21] = fVar23 - fVar4;
      puVar19[0x22] = 0;
      *(int *)(param_1 + 0x17b8) = *(int *)(param_1 + 0x17b8) + 1;
      (**(code **)(**(longlong **)(param_1 + 0x17a8) + 0x40))();
    }
  }
  iVar7 = (**(code **)(**(longlong **)(param_1 + 0x17b0) + 0x28))();
  if (iVar7 == 0) {
    psVar9 = (short *)(**(code **)(**(longlong **)(param_1 + 0x17b0) + 0x38))
                                (*(longlong **)(param_1 + 0x17b0),0,0,2);
    *(undefined4 *)(param_1 + 0x17bc) = 0;
    if (psVar9 != (short *)0x0) {
      uVar13 = 0;
      do {
        *psVar9 = 0;
        uVar10 = (short)uVar13 + 1;
        uVar13 = uVar13 + 1;
        psVar16 = psVar9 + 3;
        psVar9[1] = (uVar10 & 0x1f) + 1;
        psVar9[2] = uVar10;
        *(int *)(param_1 + 0x17bc) = *(int *)(param_1 + 0x17bc) + 3;
        psVar9 = psVar16;
      } while (uVar13 < 0x20);
      uVar13 = 0;
      do {
        uVar17 = 0;
        sVar20 = (short)uVar13 * 0x20;
        psVar9 = psVar16;
        do {
          sVar1 = (short)uVar17;
          psVar16 = psVar9 + 6;
          *psVar9 = sVar1 + sVar20 + 1;
          sVar6 = sVar1 + sVar20 + 0x21;
          sVar12 = (sVar1 + 1U & 0x1f) + sVar20;
          uVar17 = uVar17 + 1;
          sVar1 = sVar12 + 1;
          psVar9[1] = sVar1;
          psVar9[2] = sVar6;
          psVar9[3] = sVar6;
          psVar9[4] = sVar1;
          psVar9[5] = sVar12 + 0x21;
          *(int *)(param_1 + 0x17bc) = *(int *)(param_1 + 0x17bc) + 6;
          psVar9 = psVar16;
        } while (uVar17 < 0x20);
        uVar13 = uVar13 + 1;
      } while (uVar13 < 0xd);
      uVar13 = 0;
      do {
        sVar20 = (short)uVar13;
        *psVar16 = sVar20 + 0x1a1;
        uVar13 = uVar13 + 1;
        psVar16[1] = (sVar20 + 1U & 0x1f) + 0x1a1;
        psVar16[2] = 0x1c1;
        *(int *)(param_1 + 0x17bc) = *(int *)(param_1 + 0x17bc) + 3;
        psVar16 = psVar16 + 3;
      } while (uVar13 < 0x20);
      (**(code **)(**(longlong **)(param_1 + 0x17b0) + 0x40))();
    }
  }
  (**(code **)(*DAT_140c65670 + 0x140))(DAT_140c65670,*(undefined8 *)(param_1 + 0x1678),param_2);
  (**(code **)(*DAT_140c65670 + 0x178))(DAT_140c65670,*(undefined8 *)(param_1 + 0x1680),param_3);
  (**(code **)(*DAT_140c65670 + 0x130))(DAT_140c65670,*(undefined8 *)(param_1 + 0x17a8),0x15);
  (**(code **)(*DAT_140c65670 + 0x138))(DAT_140c65670,*(undefined8 *)(param_1 + 0x17b0));
  (**(code **)(*DAT_140c65670 + 0x290))
            (DAT_140c65670,3,0,*(undefined4 *)(param_1 + 0x17bc),0,*(undefined4 *)(param_1 + 0x17b8)
             ,0,1);
  return;
}

