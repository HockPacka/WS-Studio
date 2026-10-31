
void FUN_1407d9700(uint *param_1,uint param_2,float *param_3,undefined8 param_4,uint *param_5)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong lVar15;
  undefined8 *puVar16;
  float *pfVar17;
  uint uVar18;
  float *pfVar19;
  ulonglong uVar20;
  uint uVar21;
  float *pfVar22;
  uint uVar23;
  float fVar25;
  uint local_res20 [2];
  ulonglong uVar24;
  
  uVar21 = *param_1;
  if (uVar21 == 0) {
    if ((DAT_140dc5050 & 1) == 0) {
      DAT_140dc5050 = DAT_140dc5050 | 1;
    }
    puVar16 = (undefined8 *)&DAT_140dc5070;
    lVar14 = 0x10;
    *param_3 = DAT_140dc5060;
    param_3[1] = DAT_140dc5064;
    do {
      uVar12 = *puVar16;
      uVar13 = puVar16[1];
      puVar16 = puVar16 + 2;
      *(undefined8 *)((longlong)(param_3 + -0x5037141c) + (longlong)puVar16) = uVar12;
      ((undefined8 *)((longlong)(param_3 + -0x5037141c) + (longlong)puVar16))[1] = uVar13;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    return;
  }
  if (uVar21 == 1) {
    pfVar19 = *(float **)(param_1 + 4);
    pfVar17 = pfVar19 + 4;
    *param_3 = *pfVar19;
    param_3[1] = pfVar19[1];
    lVar14 = 0x10;
    do {
      uVar12 = *(undefined8 *)pfVar17;
      uVar13 = *(undefined8 *)(pfVar17 + 2);
      pfVar17 = pfVar17 + 4;
      puVar16 = (undefined8 *)((longlong)param_3 + (-0x10 - (longlong)pfVar19) + (longlong)pfVar17);
      *puVar16 = uVar12;
      puVar16[1] = uVar13;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    return;
  }
  if (param_5 == (uint *)0x0) {
    param_5 = local_res20;
  }
  else {
    uVar18 = *param_5;
    uVar21 = *(uint *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar18 * 4);
    if (uVar21 <= param_2) {
      uVar23 = *(uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(uVar18 + 1) * 4);
      if (param_2 < uVar23) {
        pfVar19 = (float *)((ulonglong)(uVar18 + 1) * 0x110 + *(longlong *)(param_1 + 4));
        pfVar22 = (float *)((ulonglong)uVar18 * 0x110 + *(longlong *)(param_1 + 4));
        lVar14 = 0x10;
        fVar25 = (float)(param_2 - uVar21) / (float)(uVar23 - uVar21);
        *param_3 = (*pfVar19 - *pfVar22) * fVar25 + *pfVar22;
        param_3[1] = (pfVar19[1] - pfVar22[1]) * fVar25 + pfVar22[1];
        pfVar17 = pfVar22 + 4;
        do {
          pfVar1 = (float *)(((longlong)pfVar19 - (longlong)pfVar22) + (longlong)pfVar17);
          fVar3 = pfVar1[1];
          fVar4 = pfVar1[2];
          fVar5 = pfVar1[3];
          fVar6 = pfVar17[1];
          fVar7 = pfVar17[2];
          fVar8 = pfVar17[3];
          fVar9 = pfVar17[1];
          fVar10 = pfVar17[2];
          fVar11 = pfVar17[3];
          pfVar2 = (float *)((longlong)param_3 + (-0x10 - (longlong)pfVar22) +
                            (longlong)(pfVar17 + 4));
          *pfVar2 = (*pfVar1 - *pfVar17) * fVar25 + *pfVar17;
          pfVar2[1] = (fVar3 - fVar6) * fVar25 + fVar9;
          pfVar2[2] = (fVar4 - fVar7) * fVar25 + fVar10;
          pfVar2[3] = (fVar5 - fVar8) * fVar25 + fVar11;
          lVar14 = lVar14 + -1;
          pfVar17 = pfVar17 + 4;
        } while (lVar14 != 0);
        return;
      }
    }
    uVar23 = uVar18 + 1;
    uVar24 = (ulonglong)uVar23;
    *param_5 = uVar23;
    uVar21 = *param_1;
    if (((uVar23 < uVar21 - 1) &&
        (lVar14 = *(longlong *)(param_1 + 2), *(uint *)(lVar14 + uVar24 * 4) <= param_2)) &&
       (param_2 < *(uint *)(lVar14 + (ulonglong)(uVar18 + 2) * 4))) {
      pfVar22 = (float *)((ulonglong)(uVar18 + 2) * 0x110 + *(longlong *)(param_1 + 4));
      pfVar19 = (float *)((ulonglong)uVar23 * 0x110 + *(longlong *)(param_1 + 4));
      fVar25 = (float)(param_2 - *(int *)(lVar14 + uVar24 * 4)) /
               (float)(uint)(*(int *)(lVar14 + (ulonglong)(uVar18 + 2) * 4) -
                            *(int *)(lVar14 + uVar24 * 4));
      *param_3 = (*pfVar22 - *pfVar19) * fVar25 + *pfVar19;
      param_3[1] = (pfVar22[1] - pfVar19[1]) * fVar25 + pfVar19[1];
      lVar14 = 0x10;
      pfVar17 = pfVar19 + 4;
      do {
        pfVar1 = (float *)(((longlong)pfVar22 - (longlong)pfVar19) + (longlong)pfVar17);
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        fVar6 = pfVar17[1];
        fVar7 = pfVar17[2];
        fVar8 = pfVar17[3];
        fVar9 = pfVar17[1];
        fVar10 = pfVar17[2];
        fVar11 = pfVar17[3];
        pfVar2 = (float *)((longlong)param_3 + (-0x10 - (longlong)pfVar19) + (longlong)(pfVar17 + 4)
                          );
        *pfVar2 = (*pfVar1 - *pfVar17) * fVar25 + *pfVar17;
        pfVar2[1] = (fVar3 - fVar6) * fVar25 + fVar9;
        pfVar2[2] = (fVar4 - fVar7) * fVar25 + fVar10;
        pfVar2[3] = (fVar5 - fVar8) * fVar25 + fVar11;
        lVar14 = lVar14 + -1;
        pfVar17 = pfVar17 + 4;
      } while (lVar14 != 0);
      return;
    }
  }
  uVar24 = 0;
  if (uVar21 != 0) {
    uVar18 = uVar21;
    do {
      uVar23 = (uVar18 - (int)uVar24 >> 1) + (int)uVar24;
      if (*(uint *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar23 * 4) <= param_2) {
        uVar24 = (ulonglong)(uVar23 + 1);
        uVar23 = uVar18;
      }
      uVar18 = uVar23;
    } while ((uint)uVar24 < uVar18);
  }
  uVar18 = (uint)uVar24;
  uVar23 = uVar18 - 1;
  uVar20 = (ulonglong)uVar23;
  if (uVar18 != 0) {
    if (uVar21 != uVar18) {
      lVar14 = *(longlong *)(param_1 + 2);
      pfVar19 = (float *)((ulonglong)uVar23 * 0x110 + *(longlong *)(param_1 + 4));
      pfVar22 = (float *)(uVar24 * 0x110 + *(longlong *)(param_1 + 4));
      lVar15 = 0x10;
      fVar25 = (float)(param_2 - *(int *)(lVar14 + uVar20 * 4)) /
               (float)(uint)(*(int *)(lVar14 + uVar24 * 4) - *(int *)(lVar14 + uVar20 * 4));
      *param_3 = (*pfVar22 - *pfVar19) * fVar25 + *pfVar19;
      param_3[1] = (pfVar22[1] - pfVar19[1]) * fVar25 + pfVar19[1];
      pfVar17 = pfVar19 + 4;
      do {
        pfVar1 = (float *)(((longlong)pfVar22 - (longlong)pfVar19) + (longlong)pfVar17);
        fVar3 = pfVar1[1];
        fVar4 = pfVar1[2];
        fVar5 = pfVar1[3];
        fVar6 = pfVar17[1];
        fVar7 = pfVar17[2];
        fVar8 = pfVar17[3];
        fVar9 = pfVar17[1];
        fVar10 = pfVar17[2];
        fVar11 = pfVar17[3];
        pfVar2 = (float *)((longlong)param_3 + (-0x10 - (longlong)pfVar19) + (longlong)(pfVar17 + 4)
                          );
        *pfVar2 = (*pfVar1 - *pfVar17) * fVar25 + *pfVar17;
        pfVar2[1] = (fVar3 - fVar6) * fVar25 + fVar9;
        pfVar2[2] = (fVar4 - fVar7) * fVar25 + fVar10;
        pfVar2[3] = (fVar5 - fVar8) * fVar25 + fVar11;
        lVar15 = lVar15 + -1;
        pfVar17 = pfVar17 + 4;
      } while (lVar15 != 0);
      *param_5 = uVar23;
      return;
    }
    FUN_1407d0dc0(param_3,uVar20 * 0x110 + *(longlong *)(param_1 + 4));
    *param_5 = *param_1 - 2;
    return;
  }
  pfVar19 = *(float **)(param_1 + 4);
  pfVar17 = pfVar19 + 4;
  *param_3 = *pfVar19;
  param_3[1] = pfVar19[1];
  lVar14 = 0x10;
  do {
    uVar12 = *(undefined8 *)pfVar17;
    uVar13 = *(undefined8 *)(pfVar17 + 2);
    pfVar17 = pfVar17 + 4;
    puVar16 = (undefined8 *)((longlong)param_3 + (-0x10 - (longlong)pfVar19) + (longlong)pfVar17);
    *puVar16 = uVar12;
    puVar16[1] = uVar13;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  *param_5 = 0;
  return;
}

