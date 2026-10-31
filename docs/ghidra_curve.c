
==== FUN_140318840 @ 140318840 size 227 ====
CALLERS: FUN_140315e90 FUN_14031bca0 FUN_1403174a0 FUN_14031ee60
CALLEES:

void FUN_140318840(float param_1,longlong param_2,longlong param_3,float *param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_5 == 0) {
    return;
  }
  uVar5 = 0;
  if (1 < param_5) {
    uVar4 = 1;
    do {
      if (param_1 < *(float *)(param_2 + uVar4 * 0x10)) break;
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      uVar5 = uVar5 + 1;
    } while (uVar3 < param_5);
  }
  if (uVar5 == param_5 - 1) {
    if (1 < param_5) {
      uVar4 = (ulonglong)uVar5;
      uVar6 = (ulonglong)(uVar5 - 1);
      fVar1 = *(float *)(param_2 + uVar6 * 0x10);
      fVar2 = *(float *)(param_2 + uVar4 * 0x10);
      if (fVar2 == fVar1) {
        *param_4 = *(float *)(param_3 + uVar4 * 0x10);
        return;
      }
      *param_4 = ((*(float *)(param_3 + uVar4 * 0x10) - *(float *)(param_3 + uVar6 * 0x10)) /
                 (fVar2 - fVar1)) * (param_1 - fVar1) + *(float *)(param_3 + uVar6 * 0x10);
      return;
    }
  }
  else {
    uVar4 = (ulonglong)uVar5;
    fVar1 = *(float *)(param_2 + (ulonglong)(uVar5 + 1) * 0x10);
    fVar2 = *(float *)(param_2 + uVar4 * 0x10);
    if (fVar1 != fVar2) {
      *param_4 = ((param_1 - fVar2) / (fVar1 - fVar2)) *
                 (*(float *)(param_3 + (ulonglong)(uVar5 + 1) * 0x10) -
                 *(float *)(param_3 + uVar4 * 0x10)) + *(float *)(param_3 + uVar4 * 0x10);
      return;
    }
  }
  *param_4 = *(float *)(param_3 + (ulonglong)uVar5 * 0x10);
  return;
}



==== FUN_140318930 @ 140318930 size 271 ====
CALLERS: FUN_140315e90 FUN_14031ee60
CALLEES:

void FUN_140318930(float param_1,longlong param_2,longlong param_3,float *param_4,uint param_5)

{
  float *pfVar1;
  float *pfVar2;
  undefined8 *puVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined8 uVar13;
  uint uVar14;
  ulonglong uVar15;
  longlong lVar16;
  uint uVar17;
  float fVar18;
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  float fVar21;
  
  if (param_5 == 0) {
    return;
  }
  uVar17 = 0;
  if (1 < param_5) {
    uVar15 = 1;
    do {
      if (param_1 < *(float *)(param_2 + uVar15 * 0x10)) break;
      uVar14 = (int)uVar15 + 1;
      uVar15 = (ulonglong)uVar14;
      uVar17 = uVar17 + 1;
    } while (uVar14 < param_5);
  }
  if (uVar17 == param_5 - 1) {
    if (param_5 < 2) {
      puVar3 = (undefined8 *)((ulonglong)uVar17 * 0x20 + param_3);
      uVar13 = puVar3[1];
      *(undefined8 *)param_4 = *puVar3;
      *(undefined8 *)(param_4 + 2) = uVar13;
      return;
    }
    uVar15 = (ulonglong)uVar17;
    fVar18 = *(float *)(param_2 + uVar15 * 0x10);
    fVar5 = *(float *)(param_2 + (ulonglong)(uVar17 - 1) * 0x10);
    if (fVar18 != fVar5) {
      fVar18 = fVar18 - fVar5;
      lVar16 = (ulonglong)(uVar17 - 1) * 0x20;
      param_1 = param_1 - fVar5;
      pfVar1 = (float *)(uVar15 * 0x20 + param_3);
      pfVar2 = (float *)(lVar16 + param_3);
      auVar19._0_4_ = *pfVar1 - *pfVar2;
      auVar19._4_4_ = pfVar1[1] - pfVar2[1];
      auVar19._8_4_ = pfVar1[2] - pfVar2[2];
      auVar19._12_4_ = pfVar1[3] - pfVar2[3];
      auVar20._4_4_ = fVar18;
      auVar20._0_4_ = fVar18;
      auVar20._8_4_ = fVar18;
      auVar20._12_4_ = fVar18;
      auVar20 = divps(auVar19,auVar20);
      pfVar1 = (float *)(lVar16 + param_3);
      fVar18 = pfVar1[1];
      fVar5 = pfVar1[2];
      fVar6 = pfVar1[3];
      *param_4 = param_1 * auVar20._0_4_ + *pfVar1;
      param_4[1] = param_1 * auVar20._4_4_ + fVar18;
      param_4[2] = param_1 * auVar20._8_4_ + fVar5;
      param_4[3] = param_1 * auVar20._12_4_ + fVar6;
      return;
    }
    lVar16 = uVar15 << 5;
  }
  else {
    lVar16 = (ulonglong)uVar17 * 0x20;
    fVar18 = *(float *)(param_2 + (ulonglong)(uVar17 + 1) * 0x10);
    fVar5 = *(float *)(param_2 + (ulonglong)uVar17 * 0x10);
    if (fVar18 != fVar5) {
      pfVar1 = (float *)((ulonglong)(uVar17 + 1) * 0x20 + param_3);
      fVar6 = pfVar1[1];
      fVar7 = pfVar1[2];
      fVar8 = pfVar1[3];
      fVar21 = (param_1 - fVar5) / (fVar18 - fVar5);
      pfVar2 = (float *)(lVar16 + param_3);
      fVar18 = pfVar2[1];
      fVar5 = pfVar2[2];
      fVar9 = pfVar2[3];
      pfVar4 = (float *)(lVar16 + param_3);
      fVar10 = pfVar4[1];
      fVar11 = pfVar4[2];
      fVar12 = pfVar4[3];
      *param_4 = fVar21 * (*pfVar1 - *pfVar2) + *pfVar4;
      param_4[1] = fVar21 * (fVar6 - fVar18) + fVar10;
      param_4[2] = fVar21 * (fVar7 - fVar5) + fVar11;
      param_4[3] = fVar21 * (fVar8 - fVar9) + fVar12;
      return;
    }
  }
  uVar13 = ((undefined8 *)(lVar16 + param_3))[1];
  *(undefined8 *)param_4 = *(undefined8 *)(lVar16 + param_3);
  *(undefined8 *)(param_4 + 2) = uVar13;
  return;
}



==== FUN_140318a40 @ 140318a40 size 307 ====
CALLERS: FUN_140315e90
CALLEES:

void FUN_140318a40(float param_1,longlong param_2,longlong param_3,undefined8 *param_4,uint param_5)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  
  if (param_5 == 0) {
    return;
  }
  uVar7 = 0;
  if (1 < param_5) {
    uVar5 = 1;
    do {
      if (param_1 < *(float *)(param_2 + uVar5 * 0x10)) break;
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      uVar7 = uVar7 + 1;
    } while (uVar4 < param_5);
  }
  if (uVar7 == param_5 - 1) {
    if (param_5 < 2) {
      *param_4 = *(undefined8 *)((ulonglong)uVar7 * 0x20 + param_3);
      return;
    }
    uVar5 = (ulonglong)uVar7;
    fVar8 = *(float *)(param_2 + uVar5 * 0x10);
    fVar3 = *(float *)(param_2 + (ulonglong)(uVar7 - 1) * 0x10);
    if (fVar8 != fVar3) {
      fVar8 = fVar8 - fVar3;
      lVar6 = (ulonglong)(uVar7 - 1) * 0x20;
      pfVar1 = (float *)(uVar5 * 0x20 + param_3);
      pfVar2 = (float *)(lVar6 + param_3);
      auVar9._0_4_ = *pfVar1 - *pfVar2;
      auVar9._4_4_ = pfVar1[1] - pfVar2[1];
      auVar9._8_4_ = pfVar1[2] - pfVar2[2];
      auVar9._12_4_ = pfVar1[3] - pfVar2[3];
      auVar10._4_4_ = fVar8;
      auVar10._0_4_ = fVar8;
      auVar10._8_4_ = fVar8;
      auVar10._12_4_ = fVar8;
      auVar10 = divps(auVar9,auVar10);
      pfVar1 = (float *)(lVar6 + param_3);
      *param_4 = CONCAT44((param_1 - fVar3) * auVar10._4_4_ + pfVar1[1],
                          (param_1 - fVar3) * auVar10._0_4_ + *pfVar1);
      return;
    }
    lVar6 = uVar5 << 5;
  }
  else {
    lVar6 = (ulonglong)uVar7 * 0x20;
    fVar8 = *(float *)(param_2 + (ulonglong)(uVar7 + 1) * 0x10);
    fVar3 = *(float *)(param_2 + (ulonglong)uVar7 * 0x10);
    if (fVar8 != fVar3) {
      pfVar1 = (float *)((ulonglong)(uVar7 + 1) * 0x20 + param_3);
      fVar8 = (param_1 - fVar3) / (fVar8 - fVar3);
      *param_4 = CONCAT44(fVar8 * (pfVar1[1] - ((float *)(lVar6 + param_3))[1]) +
                          ((float *)(lVar6 + param_3))[1],
                          fVar8 * (*pfVar1 - *(float *)(lVar6 + param_3)) +
                          *(float *)(lVar6 + param_3));
      return;
    }
  }
  *param_4 = *(undefined8 *)(lVar6 + param_3);
  return;
}



==== FUN_140313a00 @ 140313a00 size 231 ====
CALLERS: FUN_140315e90
CALLEES:

void FUN_140313a00(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  fVar2 = DAT_140b79ed0;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[3] = param_2[0xc];
  param_1[7] = (float)(uint)param_2[0xe];
  fVar3 = DAT_140b79fa0;
  param_1[0xb] = (float)(uint)param_2[0xf];
  uVar1 = param_2[0xd];
  fVar4 = fVar3;
  if ((uVar1 & 1) != 0) {
    fVar4 = fVar2;
  }
  if ((uVar1 & 2) != 0) {
    fVar3 = fVar2;
  }
  uStack_10 = 0x3f800000;
  if ((uVar1 & 4) == 0) {
    uStack_10 = 0x40400000;
  }
  uStack_c = 0x3f800000;
  if ((uVar1 & 8) == 0) {
    uStack_c = 0x40400000;
  }
  fVar6 = fVar2;
  if ((uVar1 & 0x10) != 0) {
    fVar6 = DAT_140b7a23c;
  }
  fVar5 = DAT_140b7a23c;
  if ((uVar1 & 0x20) == 0) {
    fVar5 = fVar2;
  }
  *(ulonglong *)(param_1 + 0xc) = CONCAT44(fVar3 * fVar5,fVar4 * fVar6);
  *(ulonglong *)(param_1 + 0xe) = CONCAT44(uStack_c,uStack_10);
  return;
}



==== FUN_1403135b0 @ 1403135b0 size 1091 ====
CALLERS: FUN_140315e90
CALLEES: FUN_14018b280

void FUN_1403135b0(longlong param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  bool bVar10;
  undefined4 uVar11;
  
  if (*(longlong *)(param_1 + 0x480) == 0) {
    uVar6 = FUN_14018b280(0x800,0);
    lVar9 = *(longlong *)(param_1 + 0x1a0);
    *(undefined8 *)(param_1 + 0x480) = uVar6;
    uVar3 = DAT_140b7b530;
    uVar2 = DAT_140b79ed0;
    uVar5 = *(uint *)(lVar9 + 0xec8);
    bVar10 = (uVar5 >> 0xd & 1) != 0;
    uVar8 = (uint)bVar10;
    if ((uVar5 >> 0xe & 1) != 0) {
      uVar8 = bVar10 | 2;
    }
    if ((uVar5 >> 0xf & 1) != 0) {
      uVar8 = uVar8 | 4;
    }
    if ((uVar5 >> 0x10 & 1) != 0) {
      uVar8 = uVar8 | 8;
    }
    if (*(short *)(lVar9 + 0x980) == 1) {
      uVar8 = uVar8 | 0x10;
    }
    if (*(short *)(lVar9 + 0x982) == 1) {
      uVar8 = uVar8 | 0x20;
    }
    lVar7 = 0x20;
    lVar9 = 0;
    do {
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),0,uVar2);
      *(undefined4 *)(lVar9 + 0x30 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x808),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x80c));
      *(undefined4 *)(lVar9 + 8 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x810),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x814));
      *(undefined4 *)(lVar9 + 0x18 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x818),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x81c));
      *(undefined4 *)(lVar9 + 0x28 + *(longlong *)(param_1 + 0x480)) = uVar11;
      if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x10) != 0) &&
         (iVar4 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                            (*(longlong **)(param_1 + 0x38),0,1), iVar4 != 0)) {
        *(uint *)(lVar9 + 8 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 8 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
        *(uint *)(lVar9 + 0x18 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 0x18 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
        *(uint *)(lVar9 + 0x28 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 0x28 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
      }
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x820),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x824));
      *(undefined4 *)(lVar9 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x828),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x82c));
      *(undefined4 *)(lVar9 + 0x10 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x830),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x834));
      *(undefined4 *)(lVar9 + 0x20 + *(longlong *)(param_1 + 0x480)) = uVar11;
      if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x20) != 0) &&
         (iVar4 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                            (*(longlong **)(param_1 + 0x38),0,1), iVar4 != 0)) {
        *(uint *)(lVar9 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
        *(uint *)(lVar9 + 0x10 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 0x10 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
        *(uint *)(lVar9 + 0x20 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 0x20 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
      }
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x838),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x83c));
      *(undefined4 *)(lVar9 + 4 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x840),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x844));
      *(undefined4 *)(lVar9 + 0x14 + *(longlong *)(param_1 + 0x480)) = uVar11;
      lVar1 = **(longlong **)(param_1 + 0x38);
      uVar11 = (**(code **)(lVar1 + 0x38))
                         (*(longlong **)(param_1 + 0x38),lVar1,
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x84c));
      *(undefined4 *)(lVar9 + 0x24 + *(longlong *)(param_1 + 0x480)) = uVar11;
      if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x40) != 0) &&
         (iVar4 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                            (*(longlong **)(param_1 + 0x38),0,1), iVar4 != 0)) {
        *(uint *)(lVar9 + 4 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 4 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
        *(uint *)(lVar9 + 0x14 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 0x14 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
        *(uint *)(lVar9 + 0x24 + *(longlong *)(param_1 + 0x480)) =
             *(uint *)(lVar9 + 0x24 + *(longlong *)(param_1 + 0x480)) ^ uVar3;
      }
      uVar5 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x18))();
      *(uint *)(lVar9 + 0x34 + *(longlong *)(param_1 + 0x480)) = uVar5 & uVar8;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0xe70),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0xe74));
      *(undefined4 *)(lVar9 + 0x38 + *(longlong *)(param_1 + 0x480)) = uVar11;
      uVar11 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                         (*(longlong **)(param_1 + 0x38),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x85c),
                          *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x860));
      *(undefined4 *)(lVar9 + 0x3c + *(longlong *)(param_1 + 0x480)) = uVar11;
      lVar7 = lVar7 + -1;
      lVar9 = lVar9 + 0x40;
    } while (lVar7 != 0);
  }
  return;
}



==== FUN_140315e40 @ 140315e40 size 65 ====
CALLERS: FUN_140315e90
CALLEES:

uint FUN_140315e40(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x1a0) + 0xec8);
  if (-1 < (char)uVar1) {
    return 0;
  }
  if (((uVar1 & 0x400) != 0) && ((uVar1 >> 9 & 1) != 0)) {
    return 4;
  }
  if ((uVar1 & 0x400) != 0) {
    return 2;
  }
  return (uVar1 & 0x200 | 0x100) >> 8;
}


