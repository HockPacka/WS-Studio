
==== FUN_140317ec0 @ 140317ec0 size 254 ====
CALLERS: FUN_140313c20 FUN_14031aa90 FUN_14031a8b0 FUN_14031ec20 FUN_1403146b0 FUN_14031ab20
CALLEES: FUN_1401c9770 FUN_14018b280 FUN_140317c90

void FUN_140317ec0(uint *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  
  if (1 < *param_1) {
    puVar2 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = &PTR_FUN_140b64230;
      puVar2[3] = param_2;
      puVar2[4] = param_1;
      *(undefined8 *)((longlong)puVar2 + 0x2c) = 0;
      *(undefined4 *)(puVar2 + 5) = 0;
    }
    if (param_2[1] != 0) {
      FUN_140317c90();
    }
    param_2[1] = puVar2;
    if ((param_3 != (longlong *)0x0) && (puVar2[1] == 0)) {
      puVar2[1] = param_3;
      plVar1 = puVar2 + 2;
      *plVar1 = *param_3;
      *param_3 = (longlong)puVar2;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 8) = plVar1;
      }
    }
    return;
  }
  if (*param_1 == 0) {
    if (param_2[1] != 0) {
      FUN_140317c90();
    }
    *param_2 = 0;
    param_2[1] = 0;
    return;
  }
  uVar3 = FUN_1401c9770(*(undefined8 *)(param_1 + 4));
  *(undefined4 *)param_2 = uVar3;
  return;
}



==== FUN_140317fc0 @ 140317fc0 size 267 ====
CALLERS: FUN_140313c20 FUN_14031a8b0 FUN_14031ec20
CALLEES: FUN_14018b280 FUN_140317c90

void FUN_140317fc0(uint *param_1,float *param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  
  if (1 < *param_1) {
    puVar2 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = &PTR_FUN_140b64228;
      puVar2[3] = param_2;
      puVar2[4] = param_1;
      *(undefined8 *)((longlong)puVar2 + 0x2c) = 0;
      *(undefined4 *)(puVar2 + 5) = 0;
    }
    if (*(longlong *)(param_2 + 2) != 0) {
      FUN_140317c90();
    }
    *(undefined8 **)(param_2 + 2) = puVar2;
    if ((param_3 != (longlong *)0x0) && (puVar2[1] == 0)) {
      puVar2[1] = param_3;
      plVar1 = puVar2 + 2;
      *plVar1 = *param_3;
      *param_3 = (longlong)puVar2;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 8) = plVar1;
      }
    }
    return;
  }
  if (*param_1 == 0) {
    if (*(longlong *)(param_2 + 2) != 0) {
      FUN_140317c90();
    }
    param_2[0] = 0.0;
    param_2[1] = 0.0;
    param_2[2] = 0.0;
    param_2[3] = 0.0;
    return;
  }
  *param_2 = (float)**(byte **)(param_1 + 4) * DAT_140b79d20;
  return;
}



==== FUN_140318300 @ 140318300 size 299 ====
CALLERS: FUN_140313c20 FUN_14031ec20
CALLEES: FUN_14018b280 FUN_140317c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140318300(uint *param_1,undefined1 (*param_2) [16],longlong *param_3)

{
  longlong *plVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  uint uVar5;
  float fVar6;
  undefined1 auVar7 [14];
  undefined1 auVar8 [12];
  unkbyte10 Var9;
  undefined1 auVar10 [12];
  undefined8 *puVar11;
  uint uVar12;
  undefined2 uVar28;
  undefined1 uVar26;
  undefined1 uVar27;
  undefined1 auVar13 [12];
  undefined1 auVar23 [16];
  undefined1 in_XMM1_Ba;
  undefined1 in_XMM1_Bb;
  undefined1 in_XMM1_Bc;
  undefined1 in_XMM1_Bd;
  undefined1 in_XMM1_Be;
  undefined1 in_XMM1_Bf;
  undefined1 in_XMM1_Bg;
  undefined1 in_XMM1_Bh;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar24 [16];
  undefined1 auVar19 [16];
  undefined1 auVar14 [16];
  undefined1 auVar20 [16];
  undefined1 auVar25 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar15 [16];
  
  if (1 < *param_1) {
    puVar11 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar11 != (undefined8 *)0x0) {
      puVar11[1] = 0;
      puVar11[2] = 0;
      *puVar11 = &PTR_FUN_140b64250;
      puVar11[3] = param_2;
      puVar11[4] = param_1;
      *(undefined8 *)((longlong)puVar11 + 0x2c) = 0;
      *(undefined4 *)(puVar11 + 5) = 0;
    }
    if (*(longlong *)param_2[1] != 0) {
      FUN_140317c90();
    }
    *(undefined8 **)param_2[1] = puVar11;
    if ((param_3 != (longlong *)0x0) && (puVar11[1] == 0)) {
      puVar11[1] = param_3;
      plVar1 = puVar11 + 2;
      *plVar1 = *param_3;
      *param_3 = (longlong)puVar11;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 8) = plVar1;
      }
    }
    return;
  }
  if (*param_1 == 0) {
    if (*(longlong *)param_2[1] != 0) {
      FUN_140317c90();
    }
    *(undefined8 *)*param_2 = 0;
    *(undefined8 *)(*param_2 + 8) = 0;
    *(undefined8 *)param_2[1] = 0;
    *(undefined8 *)(param_2[1] + 8) = 0;
    return;
  }
  uVar4 = CONCAT13(in_XMM1_Bd,CONCAT12(in_XMM1_Bc,CONCAT11(in_XMM1_Bb,in_XMM1_Ba))) ^
          CONCAT13(in_XMM1_Bd,CONCAT12(in_XMM1_Bc,CONCAT11(in_XMM1_Bb,in_XMM1_Ba)));
  uVar5 = CONCAT13(in_XMM1_Bh,CONCAT12(in_XMM1_Bg,CONCAT11(in_XMM1_Bf,in_XMM1_Be))) ^
          CONCAT13(in_XMM1_Bh,CONCAT12(in_XMM1_Bg,CONCAT11(in_XMM1_Bf,in_XMM1_Be)));
  uVar2 = **(uint **)(param_1 + 4);
  uVar12 = uVar2 | 0xff000000;
  auVar13._0_8_ = CONCAT44(uVar2,uVar2) | 0xff000000ff000000;
  auVar13._8_4_ = uVar12;
  auVar14._12_4_ = uVar12;
  auVar14._0_12_ = auVar13;
  auVar22._0_14_ = auVar14._0_14_;
  auVar22[0xe] = (char)(uVar12 >> 0x18);
  auVar22[0xf] = (char)(uVar5 >> 0x18);
  auVar21._14_2_ = auVar22._14_2_;
  auVar21._0_13_ = auVar14._0_13_;
  auVar21[0xd] = (char)(uVar5 >> 0x10);
  uVar27 = (undefined1)(uVar2 >> 0x10);
  auVar20._13_3_ = auVar21._13_3_;
  auVar20[0xc] = uVar27;
  auVar20._0_12_ = auVar13;
  auVar19._12_4_ = auVar20._12_4_;
  auVar19._0_11_ = auVar13._0_11_;
  auVar19[0xb] = (char)(uVar5 >> 8);
  uVar26 = (undefined1)(uVar2 >> 8);
  auVar18._11_5_ = auVar19._11_5_;
  auVar18._0_10_ = auVar13._0_10_;
  auVar18[10] = uVar26;
  auVar17._10_6_ = auVar18._10_6_;
  auVar17._0_9_ = auVar13._0_9_;
  auVar17[9] = (char)uVar5;
  auVar16._9_7_ = auVar17._9_7_;
  auVar16[8] = (char)uVar2;
  auVar16._0_8_ = auVar13._0_8_;
  Var9 = CONCAT91(CONCAT81(auVar16._8_8_,(char)(uVar4 >> 0x18)),(char)(auVar13._0_8_ >> 0x18));
  auVar8._2_10_ = Var9;
  auVar8[1] = (char)(uVar4 >> 0x10);
  auVar8[0] = uVar27;
  auVar7._2_12_ = auVar8;
  auVar7[1] = (char)(uVar4 >> 8);
  auVar7[0] = uVar26;
  uVar28 = CONCAT11((char)uVar4,(char)uVar2);
  auVar15._2_14_ = auVar7;
  auVar25._0_12_ = auVar15._0_12_;
  auVar25._12_2_ = (short)Var9;
  auVar25._14_2_ = (short)(uVar5 >> 0x10);
  auVar24._12_4_ = auVar25._12_4_;
  auVar24._0_10_ = auVar15._0_10_;
  auVar24._10_2_ = (short)uVar5;
  auVar23._10_6_ = auVar24._10_6_;
  auVar23._0_8_ = auVar15._0_8_;
  auVar23._8_2_ = auVar8._0_2_;
  auVar10._4_8_ = auVar23._8_8_;
  auVar10._2_2_ = (short)(uVar4 >> 0x10);
  auVar10._0_2_ = auVar7._0_2_;
  fVar6 = (float)auVar10._0_4_ * _UNK_140b7ab74;
  auVar3[4] = SUB41(fVar6,0);
  auVar3._0_4_ = (float)auVar23._8_4_ * _DAT_140b7ab70;
  auVar3[5] = (char)((uint)fVar6 >> 8);
  auVar3[6] = (char)((uint)fVar6 >> 0x10);
  auVar3[7] = (char)((uint)fVar6 >> 0x18);
  auVar3._8_4_ = (float)CONCAT22((short)uVar4,uVar28) * _UNK_140b7ab78;
  auVar3._12_4_ = (float)auVar24._12_4_ * _UNK_140b7ab7c;
  *param_2 = auVar3;
  return;
}



==== FUN_1403180d0 @ 1403180d0 size 271 ====
CALLERS: FUN_140313c20 FUN_14031a8b0 FUN_14031ec20 FUN_1403146b0 FUN_14031ab20
CALLEES: FUN_1401adb90 FUN_14018b280 FUN_140317c90

void FUN_1403180d0(uint *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (1 < *param_1) {
    puVar2 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = &PTR_FUN_140b64220;
      puVar2[3] = param_2;
      puVar2[4] = param_1;
      *(undefined8 *)((longlong)puVar2 + 0x2c) = 0;
      *(undefined4 *)(puVar2 + 5) = 0;
    }
    if (param_2[2] != 0) {
      FUN_140317c90();
    }
    param_2[2] = puVar2;
    if ((param_3 != (longlong *)0x0) && (puVar2[1] == 0)) {
      puVar2[1] = param_3;
      plVar1 = puVar2 + 2;
      *plVar1 = *param_3;
      *param_3 = (longlong)puVar2;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 8) = plVar1;
      }
    }
    return;
  }
  if (*param_1 == 0) {
    if (param_2[2] != 0) {
      FUN_140317c90();
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    return;
  }
  FUN_1401adb90(&local_18,*(undefined8 *)(param_1 + 4));
  *param_2 = local_18;
  param_2[1] = uStack_10;
  return;
}



==== FUN_1403181e0 @ 1403181e0 size 282 ====
CALLERS: FUN_140313c20 FUN_14031a8b0
CALLEES: FUN_14018b280 FUN_140317c90

void FUN_1403181e0(uint *param_1,undefined1 (*param_2) [16],longlong *param_3)

{
  longlong *plVar1;
  undefined1 auVar2 [16];
  undefined8 *puVar3;
  
  if (1 < *param_1) {
    puVar3 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar3 != (undefined8 *)0x0) {
      puVar3[1] = 0;
      puVar3[2] = 0;
      *puVar3 = &PTR_FUN_140b64218;
      puVar3[3] = param_2;
      puVar3[4] = param_1;
      *(undefined8 *)((longlong)puVar3 + 0x2c) = 0;
      *(undefined4 *)(puVar3 + 5) = 0;
    }
    if (*(longlong *)param_2[1] != 0) {
      FUN_140317c90();
    }
    *(undefined8 **)param_2[1] = puVar3;
    if ((param_3 != (longlong *)0x0) && (puVar3[1] == 0)) {
      puVar3[1] = param_3;
      plVar1 = puVar3 + 2;
      *plVar1 = *param_3;
      *param_3 = (longlong)puVar3;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 8) = plVar1;
      }
    }
    return;
  }
  if (*param_1 == 0) {
    if (*(longlong *)param_2[1] != 0) {
      FUN_140317c90();
    }
    *(undefined8 *)*param_2 = 0;
    *(undefined8 *)(*param_2 + 8) = 0;
    *(undefined8 *)param_2[1] = 0;
    *(undefined8 *)(param_2[1] + 8) = 0;
    return;
  }
  auVar2._12_4_ = 0;
  auVar2._0_12_ = **(undefined1 (**) [12])(param_1 + 4);
  *param_2 = auVar2;
  return;
}



==== FUN_140318430 @ 140318430 size 271 ====
CALLERS: FUN_140313c20
CALLEES: FUN_1401b2ce0 FUN_14018b280 FUN_140317c90

void FUN_140318430(uint *param_1,undefined8 *param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (1 < *param_1) {
    puVar2 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar2 != (undefined8 *)0x0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = &PTR_FUN_140b64248;
      puVar2[3] = param_2;
      puVar2[4] = param_1;
      *(undefined8 *)((longlong)puVar2 + 0x2c) = 0;
      *(undefined4 *)(puVar2 + 5) = 0;
    }
    if (param_2[2] != 0) {
      FUN_140317c90();
    }
    param_2[2] = puVar2;
    if ((param_3 != (longlong *)0x0) && (puVar2[1] == 0)) {
      puVar2[1] = param_3;
      plVar1 = puVar2 + 2;
      *plVar1 = *param_3;
      *param_3 = (longlong)puVar2;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 8) = plVar1;
      }
    }
    return;
  }
  if (*param_1 == 0) {
    if (param_2[2] != 0) {
      FUN_140317c90();
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    return;
  }
  FUN_1401b2ce0(&local_18,*(undefined8 *)(param_1 + 4));
  *param_2 = local_18;
  param_2[1] = uStack_10;
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


