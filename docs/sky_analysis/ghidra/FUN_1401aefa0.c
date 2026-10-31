
void FUN_1401aefa0(longlong *param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  longlong lVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  pfVar2 = (float *)*param_1;
  pfVar5 = param_2 + 0x1c;
  fVar11 = *pfVar2;
  fVar12 = pfVar2[1];
  fVar13 = pfVar2[2];
  pfVar2 = (float *)param_1[1];
  pfVar3 = (float *)param_1[2];
  fVar1 = pfVar3[2];
  fVar6 = (*pfVar2 + fVar11) * 0.5;
  fVar7 = (pfVar2[1] + fVar12) * 0.5;
  fVar8 = (pfVar2[2] + fVar13) * 0.5;
  lVar4 = 5;
  fVar9 = -pfVar3[1];
  fVar10 = -*pfVar3;
  *param_2 = fVar6 * 5.317362;
  fVar11 = (fVar11 - fVar6) * 3.0699801;
  fVar12 = (fVar12 - fVar7) * 3.0699801;
  fVar13 = (fVar13 - fVar8) * 3.0699801;
  param_2[0xc] = fVar7 * 5.317362;
  param_2[0x18] = fVar8 * 5.317362;
  param_2[1] = fVar11 * fVar9;
  param_2[2] = fVar11 * fVar1;
  param_2[0xd] = fVar12 * fVar9;
  param_2[3] = fVar11 * fVar10;
  param_2[0x19] = fVar13 * fVar9;
  param_2[0x1a] = fVar13 * fVar1;
  param_2[0x1b] = fVar13 * fVar10;
  param_2[0xe] = fVar12 * fVar1;
  param_2[0xf] = fVar12 * fVar10;
  do {
    pfVar5[-0x18] = 0.0;
    pfVar5[-0xc] = 0.0;
    *pfVar5 = 0.0;
    pfVar5 = pfVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}

