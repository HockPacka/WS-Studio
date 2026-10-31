
void FUN_1401af0b0(longlong *param_1,float *param_2)

{
  float fVar1;
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
  float fVar12;
  float fVar13;
  
  pfVar2 = (float *)param_1[1];
  fVar12 = pfVar2[2];
  fVar13 = pfVar2[1];
  fVar4 = fVar12 * 0.48860252;
  fVar1 = *pfVar2;
  pfVar2 = (float *)*param_1;
  fVar3 = fVar13 * -0.48860252;
  fVar10 = fVar12 * fVar13 * -1.0925485;
  fVar6 = *pfVar2 * 2.956793;
  fVar7 = pfVar2[1] * 2.956793;
  fVar8 = pfVar2[2] * 2.956793;
  fVar5 = fVar1 * -0.48860252;
  fVar11 = (fVar12 * 3.0 * fVar12 - 1.0) * 0.31539157;
  fVar9 = fVar1 * fVar13 * 1.0925485;
  fVar12 = fVar1 * fVar12 * -1.0925485;
  *param_2 = fVar6 * 0.2820948;
  param_2[0xc] = fVar7 * 0.2820948;
  fVar13 = (fVar1 * fVar1 - fVar13 * fVar13) * 0.54627424;
  param_2[0x18] = fVar8 * 0.2820948;
  param_2[1] = fVar3 * fVar6;
  param_2[0xd] = fVar3 * fVar7;
  param_2[0x19] = fVar3 * fVar8;
  param_2[2] = fVar4 * fVar6;
  param_2[0xe] = fVar4 * fVar7;
  param_2[0x1a] = fVar4 * fVar8;
  param_2[3] = fVar5 * fVar6;
  param_2[0xf] = fVar5 * fVar7;
  param_2[0x1b] = fVar5 * fVar8;
  param_2[4] = fVar9 * fVar6;
  param_2[0x10] = fVar9 * fVar7;
  param_2[0x1c] = fVar9 * fVar8;
  param_2[5] = fVar10 * fVar6;
  param_2[0x11] = fVar10 * fVar7;
  param_2[0x1d] = fVar10 * fVar8;
  param_2[6] = fVar11 * fVar6;
  param_2[0x1e] = fVar11 * fVar8;
  param_2[0x12] = fVar11 * fVar7;
  param_2[7] = fVar12 * fVar6;
  param_2[0x13] = fVar12 * fVar7;
  param_2[0x1f] = fVar12 * fVar8;
  param_2[0x20] = fVar13 * fVar8;
  param_2[8] = fVar13 * fVar6;
  param_2[0x14] = fVar13 * fVar7;
  return;
}

