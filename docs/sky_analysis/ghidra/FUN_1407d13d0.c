
void FUN_1407d13d0(uint param_1,uint *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  uint uVar14;
  ulonglong uVar15;
  uint uVar16;
  float fVar17;
  
  uVar4 = *param_2;
  if ((uVar4 != 0) && (param_3 != (float *)0x0)) {
    uVar15 = 0;
    if (uVar4 != 0) {
      uVar16 = uVar4;
      do {
        uVar14 = (uVar16 - (int)uVar15 >> 1) + (int)uVar15;
        if (*(uint *)(*(longlong *)(param_2 + 2) + (ulonglong)uVar14 * 4) <= param_1) {
          uVar15 = (ulonglong)(uVar14 + 1);
          uVar14 = uVar16;
        }
        uVar16 = uVar14;
      } while ((uint)uVar15 < uVar16);
    }
    uVar16 = (uint)uVar15;
    uVar14 = uVar16 - 1;
    if (uVar16 == 0) {
      puVar13 = *(undefined8 **)(param_2 + 4);
      uVar12 = puVar13[1];
      *(undefined8 *)param_3 = *puVar13;
      *(undefined8 *)(param_3 + 2) = uVar12;
      uVar12 = puVar13[3];
      *(undefined8 *)(param_3 + 4) = puVar13[2];
      *(undefined8 *)(param_3 + 6) = uVar12;
      return;
    }
    if (uVar4 != uVar16) {
      lVar3 = (ulonglong)uVar14 * 4;
      uVar4 = *(uint *)(lVar3 + *(longlong *)(param_2 + 2));
      if (param_1 != uVar4) {
        pfVar1 = (float *)(*(longlong *)(param_2 + 4) + (ulonglong)uVar14 * 0x20);
        fVar6 = pfVar1[1];
        fVar7 = pfVar1[2];
        fVar8 = pfVar1[3];
        pfVar2 = (float *)(uVar15 * 0x20 + *(longlong *)(param_2 + 4));
        fVar9 = pfVar2[1];
        fVar10 = pfVar2[2];
        fVar11 = pfVar2[3];
        fVar17 = (float)(param_1 - uVar4) /
                 (float)(*(int *)(*(longlong *)(param_2 + 2) + uVar15 * 4) - uVar4);
        *param_3 = fVar17 * (*pfVar2 - *pfVar1) + *pfVar1;
        param_3[1] = fVar17 * (fVar9 - fVar6) + fVar6;
        param_3[2] = fVar17 * (fVar10 - fVar7) + fVar7;
        param_3[3] = fVar17 * (fVar11 - fVar8) + fVar8;
        pfVar1 = (float *)(uVar15 * 0x20 + 0x10 + *(longlong *)(param_2 + 4));
        fVar6 = pfVar1[1];
        fVar7 = pfVar1[2];
        fVar8 = pfVar1[3];
        pfVar2 = (float *)(*(longlong *)(param_2 + 4) + 0x10 + (ulonglong)uVar14 * 0x20);
        fVar9 = pfVar2[1];
        fVar10 = pfVar2[2];
        fVar11 = pfVar2[3];
        lVar5 = *(longlong *)(param_2 + 2);
        fVar17 = (float)(param_1 - *(int *)(lVar5 + lVar3)) /
                 (float)(uint)(*(int *)(lVar5 + uVar15 * 4) - *(int *)(lVar5 + lVar3));
        param_3[4] = fVar17 * (*pfVar1 - *pfVar2) + *pfVar2;
        param_3[5] = fVar17 * (fVar6 - fVar9) + fVar9;
        param_3[6] = fVar17 * (fVar7 - fVar10) + fVar10;
        param_3[7] = fVar17 * (fVar8 - fVar11) + fVar11;
        return;
      }
    }
    puVar13 = (undefined8 *)((ulonglong)uVar14 * 0x20 + *(longlong *)(param_2 + 4));
    uVar12 = puVar13[1];
    *(undefined8 *)param_3 = *puVar13;
    *(undefined8 *)(param_3 + 2) = uVar12;
    uVar12 = puVar13[3];
    *(undefined8 *)(param_3 + 4) = puVar13[2];
    *(undefined8 *)(param_3 + 6) = uVar12;
  }
  return;
}

