
==== FUN_14030dbb0 @ 14030dbb0 size 2043 ====
CALLERS: FUN_14030d8a0 FUN_1402ec800
CALLEES: FUN_14030fbf0 FUN_14018b280 FUN_14030f870 FUN_14030fa00 FUN_140327210 FUN_1402eca50 FUN_14030e510 memcpy FUN_14030e690 FUN_14018b900 FUN_1407e4830 FUN_140326380 FUN_1400035b0 FUN_14021a4e0

void FUN_14030dbb0(longlong param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  longlong lVar15;
  int *piVar16;
  ushort *puVar17;
  undefined8 *puVar18;
  longlong lVar19;
  longlong lVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  longlong lVar23;
  uint *puVar24;
  uint uVar25;
  uint *puVar26;
  longlong lVar27;
  undefined8 *puVar28;
  undefined8 *puVar29;
  uint uVar30;
  int iVar31;
  
  uVar30 = *(uint *)(*(longlong *)(param_1 + 0x38) + 0x10);
  uVar21 = 0;
  iVar31 = 0;
  if (uVar30 != 0) {
    auVar6 = ZEXT816(0x70) * ZEXT416(uVar30);
    uVar11 = auVar6._0_8_;
    if (auVar6._8_8_ != 0) {
      uVar11 = 0xffffffffffffffff;
    }
    uVar11 = FUN_14018b280(uVar11,0);
    *(undefined8 *)(param_1 + 0x90) = uVar11;
    uVar22 = uVar21;
    uVar14 = uVar21;
    if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x10) != 0) {
      do {
        lVar15 = *(longlong *)(param_1 + 0x90);
        lVar20 = uVar22 * 0x70;
        lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x18);
        uVar3 = *(undefined2 *)(lVar20 + lVar23);
        if (DAT_140c63840 == (code *)0x0) {
          uVar12 = uVar21;
          if (DAT_140c64964 == 0) {
            iVar9 = FUN_14021a4e0();
            if (iVar9 < 0) {
              uVar12 = 0;
            }
            else {
              uVar12 = (**(code **)(*DAT_140c652e8 + 0x18))(DAT_140c652e8,uVar3);
            }
          }
        }
        else {
          uVar12 = (*DAT_140c63840)(&PTR_u_ModelSequence_140a6b9b0,uVar3,DAT_140c63858);
        }
        *(uint *)(lVar20 + lVar15) = (uint)*(ushort *)(lVar20 + lVar23);
        *(uint *)(lVar20 + 4 + lVar15) = (uint)*(ushort *)(lVar20 + 2 + lVar23);
        iVar9 = iVar31;
        if (uVar12 != 0) {
          iVar9 = *(int *)(uVar12 + 0x14);
        }
        *(int *)(lVar20 + 8 + lVar15) = iVar9;
        *(uint *)(lVar20 + 0xc + lVar15) = (uint)*(ushort *)(lVar20 + 4 + lVar23);
        *(uint *)(lVar20 + 0x10 + lVar15) = (uint)*(ushort *)(lVar20 + 6 + lVar23);
        *(int *)(lVar20 + 0x14 + lVar15) =
             *(int *)(lVar20 + 0x10 + lVar23) - *(int *)(lVar20 + 0xc + lVar23);
        *(uint *)(lVar20 + 0x18 + lVar15) = (uint)*(ushort *)(lVar20 + 10 + lVar23);
        *(undefined4 *)(lVar20 + 0x1c + lVar15) = *(undefined4 *)(lVar20 + 0x14 + lVar23);
        puVar13 = (undefined8 *)(lVar20 + 0x20 + lVar23);
        uVar11 = puVar13[1];
        puVar28 = (undefined8 *)(lVar20 + 0x20 + lVar15);
        *puVar28 = *puVar13;
        puVar28[1] = uVar11;
        puVar13 = (undefined8 *)(lVar20 + 0x30 + lVar23);
        uVar11 = puVar13[1];
        puVar28 = (undefined8 *)(lVar20 + 0x30 + lVar15);
        *puVar28 = *puVar13;
        puVar28[1] = uVar11;
        puVar13 = (undefined8 *)(lVar20 + 0x40 + lVar23);
        uVar11 = puVar13[1];
        puVar28 = (undefined8 *)(lVar20 + 0x40 + lVar15);
        *puVar28 = *puVar13;
        puVar28[1] = uVar11;
        puVar1 = (undefined4 *)(lVar20 + 0x50 + lVar23);
        uVar10 = puVar1[1];
        uVar7 = puVar1[2];
        uVar8 = puVar1[3];
        puVar2 = (undefined4 *)(lVar20 + 0x50 + lVar15);
        *puVar2 = *puVar1;
        puVar2[1] = uVar10;
        puVar2[2] = uVar7;
        puVar2[3] = uVar8;
        *(undefined4 *)(lVar20 + 0x60 + lVar15) = 0;
        if (*(int *)(lVar20 + lVar15) != (int)uVar14) {
          uVar14 = (ulonglong)*(uint *)(lVar20 + lVar15);
        }
        *(undefined8 *)(lVar20 + 0x68 + lVar15) = *(undefined8 *)(lVar20 + 0x68 + lVar23);
        uVar30 = (int)uVar22 + 1;
        uVar22 = (ulonglong)uVar30;
      } while (uVar30 < *(uint *)(*(longlong *)(param_1 + 0x38) + 0x10));
    }
  }
  uVar30 = *(uint *)(*(longlong *)(param_1 + 0x38) + 0x80);
  if (uVar30 != 0) {
    auVar6 = ZEXT816(0x20) * ZEXT416(uVar30);
    uVar11 = auVar6._0_8_;
    if (auVar6._8_8_ != 0) {
      uVar11 = 0xffffffffffffffff;
    }
    uVar11 = FUN_14018b280(uVar11,0);
    *(undefined8 *)(param_1 + 0x98) = uVar11;
    uVar22 = uVar21;
    uVar14 = uVar21;
    if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x80) != 0) {
      do {
        puVar26 = (uint *)(uVar14 * 0x20 + *(longlong *)(param_1 + 0x98));
        puVar17 = (ushort *)(uVar14 * 0x30 + *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x88));
        uVar4 = *puVar17;
        *puVar26 = (uint)uVar4;
        puVar26[1] = (uint)puVar17[1];
        puVar26[2] = *(int *)(puVar17 + 6) - *(int *)(puVar17 + 4);
        if ((uint)uVar4 != (uint)uVar22) {
          uVar22 = (ulonglong)uVar4;
        }
        puVar26[3] = (uint)puVar17[3];
        uVar30 = *(uint *)(puVar17 + 8);
        puVar26[5] = 0;
        puVar26[4] = uVar30;
        uVar30 = (int)uVar14 + 1;
        *(undefined8 *)(puVar26 + 6) = *(undefined8 *)(puVar17 + 0x14);
        uVar14 = (ulonglong)uVar30;
      } while (uVar30 < *(uint *)(*(longlong *)(param_1 + 0x38) + 0x80));
    }
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 600);
  *(longlong *)(param_1 + 0x40) = lVar15;
  FUN_140327210(param_1 + 0xd8,lVar15 + 0x18);
  lVar15 = *(longlong *)(param_1 + 0x40);
  if (((*(char *)(lVar15 + 0x20) != '\x01') && ((*(ushort *)(lVar15 + 0x1e) & 0x200) == 0)) &&
     (*(byte *)(lVar15 + 0x1c) < 0x21)) {
    if ((*(ushort *)(lVar15 + 0x1e) & 0xf0) != 0) {
      *(undefined4 *)(param_1 + 0xa8) = 8;
      goto LAB_14030de68;
    }
    if (*(byte *)(lVar15 + 0x1c) < 0x11) {
      *(undefined4 *)(param_1 + 0xa8) = 7;
      goto LAB_14030de68;
    }
    FUN_1400035b0(6,0,0,*(undefined8 *)(param_1 + 0x18));
  }
  *(undefined4 *)(param_1 + 0xa8) = 9;
LAB_14030de68:
  uVar30 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0x80);
  if (uVar30 != 0) {
    auVar6 = ZEXT816(8) * ZEXT416(uVar30);
    uVar11 = auVar6._0_8_;
    if (auVar6._8_8_ != 0) {
      uVar11 = 0xffffffffffffffff;
    }
    uVar11 = FUN_14018b280(uVar11,0);
    *(undefined8 *)(param_1 + 0xb0) = uVar11;
    uVar22 = uVar21;
    if (*(int *)(*(longlong *)(param_1 + 0x40) + 0x80) != 0) {
      do {
        lVar15 = *(longlong *)(param_1 + 0xb0);
        lVar23 = uVar22 * 0x70 + *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x88);
        uVar10 = FUN_14030e510(param_1,lVar23);
        *(undefined4 *)(lVar15 + uVar22 * 8) = uVar10;
        uVar10 = FUN_14030e690(param_1,lVar23);
        uVar30 = (int)uVar22 + 1;
        *(undefined4 *)(lVar15 + 4 + uVar22 * 8) = uVar10;
        uVar22 = (ulonglong)uVar30;
      } while (uVar30 < *(uint *)(*(longlong *)(param_1 + 0x40) + 0x80));
    }
  }
  puVar13 = (undefined8 *)
            FUN_1402eca50(*(undefined8 *)(param_1 + 0x10),*(longlong *)(param_1 + 0x38) + 0x10);
  if (*(undefined8 **)(param_1 + 0xb8) != puVar13) {
    if (puVar13 != (undefined8 *)0x0) {
      (**(code **)*puVar13)(puVar13);
    }
    if (*(longlong **)(param_1 + 0xb8) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0xb8) + 8))();
    }
    *(undefined8 **)(param_1 + 0xb8) = puVar13;
  }
  auVar6 = ZEXT816(4) * ZEXT416(*(uint *)(*(longlong *)(param_1 + 0x38) + 0x180));
  uVar11 = auVar6._0_8_;
  if (auVar6._8_8_ != 0) {
    uVar11 = 0xffffffffffffffff;
  }
  uVar11 = FUN_14018b280(uVar11,0);
  *(undefined8 *)(param_1 + 0xd0) = uVar11;
  FUN_1407e4830(uVar11,0,(ulonglong)*(uint *)(*(longlong *)(param_1 + 0x38) + 0x180) << 2);
  auVar6 = ZEXT816(4) *
           ZEXT416((uint)(*(int *)(*(longlong *)(param_1 + 0x10) + 0x8c4) +
                         *(int *)(*(longlong *)(param_1 + 0x38) + 0x180)));
  uVar11 = auVar6._0_8_;
  if (auVar6._8_8_ != 0) {
    uVar11 = 0xffffffffffffffff;
  }
  puVar26 = (uint *)FUN_14018b280(uVar11,8);
  uVar30 = 1;
  *puVar26 = 0;
  uVar22 = 1;
  if (1 < *(uint *)(*(longlong *)(param_1 + 0x10) + 0x8c4)) {
    do {
      lVar15 = *(longlong *)(param_1 + 0x38);
      uVar25 = *(uint *)(uVar22 * 0xc4 + *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x8c8));
      if ((uVar25 < *(uint *)(lVar15 + 400)) &&
         (uVar4 = *(ushort *)(*(longlong *)(lVar15 + 0x198) + (ulonglong)uVar25 * 2),
         (uint)uVar4 < *(uint *)(lVar15 + 0x180))) {
        *(uint *)(*(longlong *)(param_1 + 0xd0) + (ulonglong)uVar4 * 4) = uVar30;
        uVar14 = (ulonglong)uVar30;
        uVar30 = uVar30 + 1;
        puVar26[uVar14] = (uint)uVar22;
      }
      uVar25 = (uint)uVar22 + 1;
      uVar22 = (ulonglong)uVar25;
    } while (uVar25 < *(uint *)(*(longlong *)(param_1 + 0x10) + 0x8c4));
  }
  uVar22 = uVar21;
  if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x180) != 0) {
    do {
      lVar15 = *(longlong *)(param_1 + 0xd0);
      puVar24 = (uint *)(lVar15 + uVar22 * 4);
      if (*(int *)(lVar15 + uVar22 * 4) == 0) {
        lVar23 = *(longlong *)(param_1 + 0x38);
        lVar20 = uVar22 * 0x160 + *(longlong *)(lVar23 + 0x188);
        uVar4 = *(ushort *)(lVar20 + 4);
        if ((uint)uVar4 < *(uint *)(lVar23 + 0x180)) {
          if (((*(ushort *)
                 ((ulonglong)
                  *(ushort *)((ulonglong)uVar4 * 0x160 + 6 + *(longlong *)(lVar23 + 0x188)) * 0xb8 +
                 *(longlong *)(lVar23 + 0xf8)) ^
               *(ushort *)((ulonglong)*(ushort *)(lVar20 + 6) * 0xb8 + *(longlong *)(lVar23 + 0xf8))
               ) & 0x7f8) == 0) {
            *puVar24 = *(uint *)(lVar15 + (ulonglong)(uint)uVar4 * 4);
          }
          else {
            *puVar24 = uVar30;
            uVar14 = (ulonglong)uVar30;
            uVar30 = uVar30 + 1;
            puVar26[uVar14] =
                 *(uint *)(*(longlong *)(param_1 + 0xd0) + (ulonglong)*(ushort *)(lVar20 + 4) * 4);
          }
        }
      }
      uVar25 = (int)uVar22 + 1;
      uVar22 = (ulonglong)uVar25;
    } while (uVar25 < *(uint *)(*(longlong *)(param_1 + 0x38) + 0x180));
  }
  uVar22 = CONCAT44(0,uVar30);
  *(uint *)(param_1 + 200) = uVar30;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = uVar22;
  uVar11 = SUB168(ZEXT816(0xc4) * auVar6,0);
  if (SUB168(ZEXT816(0xc4) * auVar6,8) != 0) {
    uVar11 = 0xffffffffffffffff;
  }
  uVar11 = FUN_14018b280(uVar11,0);
  *(undefined8 *)(param_1 + 0xc0) = uVar11;
  uVar14 = uVar21;
  puVar24 = puVar26;
  if (uVar30 != 0) {
    do {
      puVar13 = (undefined8 *)
                ((ulonglong)*puVar24 * 0xc4 + *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x8c8));
      puVar28 = (undefined8 *)(*(longlong *)(param_1 + 0xc0) + uVar14);
      if ((((uint)puVar13 | (uint)puVar28) & 0xf) == 0) {
        lVar15 = 1;
        do {
          puVar29 = puVar28;
          puVar18 = puVar13;
          uVar11 = puVar18[1];
          *puVar29 = *puVar18;
          puVar29[1] = uVar11;
          uVar11 = puVar18[3];
          puVar29[2] = puVar18[2];
          puVar29[3] = uVar11;
          uVar11 = puVar18[5];
          puVar29[4] = puVar18[4];
          puVar29[5] = uVar11;
          uVar11 = puVar18[7];
          puVar29[6] = puVar18[6];
          puVar29[7] = uVar11;
          uVar11 = puVar18[9];
          puVar29[8] = puVar18[8];
          puVar29[9] = uVar11;
          uVar11 = puVar18[0xb];
          puVar29[10] = puVar18[10];
          puVar29[0xb] = uVar11;
          uVar11 = puVar18[0xd];
          puVar29[0xc] = puVar18[0xc];
          puVar29[0xd] = uVar11;
          uVar11 = puVar18[0xf];
          puVar29[0xe] = puVar18[0xe];
          puVar29[0xf] = uVar11;
          lVar15 = lVar15 + -1;
          puVar13 = puVar18 + 0x10;
          puVar28 = puVar29 + 0x10;
        } while (lVar15 != 0);
        uVar11 = puVar18[0x11];
        puVar29[0x10] = puVar18[0x10];
        puVar29[0x11] = uVar11;
        uVar11 = puVar18[0x13];
        puVar29[0x12] = puVar18[0x12];
        puVar29[0x13] = uVar11;
        uVar11 = puVar18[0x15];
        puVar29[0x14] = puVar18[0x14];
        puVar29[0x15] = uVar11;
        uVar11 = puVar18[0x17];
        puVar29[0x16] = puVar18[0x16];
        puVar29[0x17] = uVar11;
        *(undefined4 *)(puVar29 + 0x18) = *(undefined4 *)(puVar18 + 0x18);
      }
      else {
        memcpy(puVar28,puVar13,0xc4);
      }
      uVar22 = uVar22 - 1;
      uVar14 = uVar14 + 0xc4;
      puVar24 = puVar24 + 1;
    } while (uVar22 != 0);
  }
  FUN_14018b900(puVar26,0);
  if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x180) != 0) {
    do {
      lVar15 = *(longlong *)(param_1 + 0xc0);
      uVar30 = *(uint *)(*(longlong *)(param_1 + 0xd0) + uVar21 * 4);
      lVar20 = uVar21 * 0x160 + *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x188);
      lVar23 = (ulonglong)uVar30 * 0xc4;
      uVar4 = *(ushort *)(lVar20 + 4);
      if ((uint)uVar4 < *(uint *)(*(longlong *)(param_1 + 0x38) + 0x180)) {
        uVar25 = *(uint *)(*(longlong *)(param_1 + 0xd0) + (ulonglong)uVar4 * 4);
        if (uVar30 != uVar25) {
          piVar16 = (int *)(lVar15 + 8 + lVar23);
          lVar19 = 0x2f;
          lVar27 = (lVar15 + 8 + (ulonglong)uVar25 * 0xc4) - (longlong)piVar16;
          do {
            if (*piVar16 == -1) {
              *piVar16 = *(int *)(lVar27 + (longlong)piVar16);
            }
            piVar16 = piVar16 + 1;
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
          goto LAB_14030e2c3;
        }
      }
      else {
        lVar19 = 0x2f;
        piVar16 = (int *)(lVar15 + 8 + lVar23);
        do {
          if (*piVar16 == -1) {
            *piVar16 = 0;
          }
          piVar16 = piVar16 + 1;
          lVar19 = lVar19 + -1;
        } while (lVar19 != 0);
LAB_14030e2c3:
        *(uint *)(lVar23 + 4 + lVar15) =
             (uint)*(ushort *)
                    ((ulonglong)*(ushort *)(lVar20 + 6) * 0xb8 +
                    *(longlong *)(*(longlong *)(param_1 + 0x38) + 0xf8));
      }
      uVar30 = (int)uVar21 + 1;
      uVar21 = (ulonglong)uVar30;
    } while (uVar30 < *(uint *)(*(longlong *)(param_1 + 0x38) + 0x180));
  }
  iVar9 = *(int *)(*(longlong *)(param_1 + 0x40) + 0x18);
  if (iVar9 != 0) {
    iVar5 = *(int *)(param_1 + 0xa8);
    if (iVar5 == 7) {
      iVar31 = 0x10;
    }
    else if (iVar5 == 8) {
      iVar31 = 0x20;
    }
    else if (iVar5 == 9) {
      iVar31 = 0x30;
    }
    (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,iVar9 * iVar31,1,param_1 + 0xa0);
  }
  if (*(longlong *)(param_1 + 0xa0) != 0) {
    iVar31 = *(int *)(param_1 + 0xa8);
    if (iVar31 == 7) {
      FUN_14030f870(param_1);
    }
    else if (iVar31 == 8) {
      FUN_14030fa00(param_1);
    }
    else if (iVar31 == 9) {
      FUN_14030fbf0(param_1);
    }
  }
  for (lVar15 = *(longlong *)(param_1 + 0x1d8); lVar15 != 0; lVar15 = *(longlong *)(lVar15 + 0x68))
  {
    FUN_140326380(lVar15);
  }
  return;
}



==== FUN_140326800 @ 140326800 size 1270 ====
CALLERS: FUN_1403266d0
CALLEES: FUN_14018db00 FUN_140326f00 memcpy FUN_14030e510 FUN_14018dbc0 FUN_140326e40 FUN_14030e690

/* WARNING: Removing unreachable block (ram,0x00014032684b) */

void FUN_140326800(longlong *param_1,longlong param_2,longlong param_3)

{
  undefined4 *puVar1;
  short sVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined4 uVar11;
  void *pvVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  ulonglong uVar18;
  uint *puVar19;
  uint *puVar20;
  int iVar21;
  uint local_res10;
  
  uVar3 = *(uint *)(param_2 + 0x14);
  param_1[1] = 0;
  iVar21 = (uVar3 >> 1) + (uVar3 & 1);
  FUN_140326f00(param_1,iVar21);
  param_1[3] = 0;
  pvVar12 = (void *)FUN_14018dbc0(param_1[2],iVar21,8);
  if ((void *)param_1[2] != pvVar12) {
    memcpy(pvVar12,(void *)param_1[2],param_1[3] << 3);
    lVar4 = param_1[2];
    if (lVar4 != 0) {
      (**(code **)(*(longlong *)(lVar4 + -0x10) + 8))(lVar4 + -0x10);
    }
    param_1[2] = (longlong)pvVar12;
  }
  uVar18 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x40);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x38);
  local_res10 = 0;
  uVar13 = uVar18;
  uVar14 = uVar18;
  if (*(int *)(param_2 + 0x14) != 0) {
    do {
      uVar10 = (uint)uVar13;
      uVar13 = 0;
      iVar21 = (int)uVar18;
      puVar19 = (uint *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x20) + uVar18 * 4) * 0x70 +
                        *(longlong *)(lVar4 + 0x88));
      uVar3 = puVar19[2];
      if ((uint)*(ushort *)((longlong)puVar19 + 0x1e) < *(uint *)(lVar5 + 0x200)) {
        sVar2 = *(short *)(*(longlong *)(lVar5 + 0x208) +
                          (ulonglong)*(ushort *)((longlong)puVar19 + 0x1e) * 4);
        if (sVar2 == 0) {
          uVar18 = (ulonglong)(iVar21 + 1);
          local_res10 = uVar10;
        }
        else {
          do {
            if (sVar2 == *(short *)(param_3 + uVar13 * 2)) break;
            uVar13 = uVar13 + 1;
          } while (uVar13 < 4);
          if (uVar13 == 4) {
            uVar18 = (ulonglong)(iVar21 + 1);
            local_res10 = uVar10;
          }
          else {
            uVar10 = (int)uVar14 + 1;
            uVar13 = (ulonglong)uVar10;
            FUN_140326e40(param_1,uVar10);
            if ((ulonglong)param_1[3] <= uVar13) {
              pvVar12 = (void *)FUN_14018db00(param_1[2],uVar13,8);
              if ((void *)param_1[2] != pvVar12) {
                memcpy(pvVar12,(void *)param_1[2],param_1[3] << 3);
                lVar6 = param_1[2];
                if (lVar6 != 0) {
                  (**(code **)(*(longlong *)(lVar6 + -0x10) + 8))(lVar6 + -0x10);
                }
                param_1[2] = (longlong)pvVar12;
              }
            }
            param_1[3] = uVar13;
            puVar17 = (uint *)(uVar14 * 0x70 + *param_1);
            puVar1 = (undefined4 *)(param_1[2] + uVar14 * 8);
            uVar18 = (ulonglong)(iVar21 + 1U);
            *puVar17 = *puVar19;
            puVar17[1] = puVar19[1];
            puVar17[2] = puVar19[2];
            puVar17[3] = puVar19[3];
            *(short *)(puVar17 + 4) = (short)puVar19[4];
            *(undefined2 *)((longlong)puVar17 + 0x12) = *(undefined2 *)((longlong)puVar19 + 0x12);
            *(short *)(puVar17 + 5) = (short)puVar19[5];
            *(undefined2 *)((longlong)puVar17 + 0x16) = *(undefined2 *)((longlong)puVar19 + 0x16);
            *(short *)(puVar17 + 6) = (short)puVar19[6];
            *(undefined2 *)((longlong)puVar17 + 0x1a) = *(undefined2 *)((longlong)puVar19 + 0x1a);
            *(short *)(puVar17 + 7) = (short)puVar19[7];
            *(undefined2 *)((longlong)puVar17 + 0x1e) = *(undefined2 *)((longlong)puVar19 + 0x1e);
            *(short *)(puVar17 + 8) = (short)puVar19[8];
            *(undefined2 *)((longlong)puVar17 + 0x22) = *(undefined2 *)((longlong)puVar19 + 0x22);
            *(short *)(puVar17 + 9) = (short)puVar19[9];
            *(undefined2 *)((longlong)puVar17 + 0x26) = *(undefined2 *)((longlong)puVar19 + 0x26);
            *(undefined8 *)(puVar17 + 10) = *(undefined8 *)(puVar19 + 10);
            *(undefined8 *)(puVar17 + 0xc) = *(undefined8 *)(puVar19 + 0xc);
            *(char *)(puVar17 + 0xe) = (char)puVar19[0xe];
            *(undefined1 *)((longlong)puVar17 + 0x39) = *(undefined1 *)((longlong)puVar19 + 0x39);
            *(undefined1 *)((longlong)puVar17 + 0x3a) = *(undefined1 *)((longlong)puVar19 + 0x3a);
            uVar9 = *(undefined8 *)(puVar19 + 0x12);
            *(undefined8 *)(puVar17 + 0x10) = *(undefined8 *)(puVar19 + 0x10);
            *(undefined8 *)(puVar17 + 0x12) = uVar9;
            uVar16 = puVar19[0x15];
            uVar7 = puVar19[0x16];
            uVar8 = puVar19[0x17];
            puVar17[0x14] = puVar19[0x14];
            puVar17[0x15] = uVar16;
            puVar17[0x16] = uVar7;
            puVar17[0x17] = uVar8;
            puVar17[0x18] = puVar19[0x18];
            puVar17[0x19] = puVar19[0x19];
            uVar16 = puVar19[0x1a];
            *(undefined4 *)((longlong)puVar17 + 0x22) = 0;
            puVar17[0x1a] = uVar16;
            *(undefined2 *)((longlong)puVar17 + 0x26) = 0;
            *puVar17 = local_res10;
            *(undefined2 *)((longlong)puVar17 + 0x1e) = 0xffff;
            if (iVar21 + 1U < *(uint *)(param_2 + 0x14)) {
              while( true ) {
                uVar13 = 0;
                puVar20 = (uint *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x20) + uVar18 * 4)
                                   * 0x70 + *(longlong *)(lVar4 + 0x88));
                if ((*(uint *)(lVar5 + 0x200) <= (uint)*(ushort *)((longlong)puVar20 + 0x1e)) ||
                   (sVar2 = *(short *)(*(longlong *)(lVar5 + 0x208) +
                                      (ulonglong)(uint)*(ushort *)((longlong)puVar20 + 0x1e) * 4),
                   uVar14 = uVar13, sVar2 == 0)) break;
                do {
                  if (sVar2 == *(short *)(param_3 + uVar14 * 2)) {
                    uVar18 = (ulonglong)((int)uVar18 + 1);
                    break;
                  }
                  uVar14 = uVar14 + 1;
                } while (uVar14 < 4);
                if (uVar14 == 4) break;
                if ((((((short)puVar19[4] != (short)puVar20[4]) ||
                      (*(short *)((longlong)puVar19 + 0x12) != *(short *)((longlong)puVar20 + 0x12))
                      ) || (*(short *)((longlong)puVar19 + 0x16) !=
                            *(short *)((longlong)puVar20 + 0x16))) ||
                    (((ushort)puVar19[6] != (ushort)puVar20[6] ||
                     ((short)puVar19[7] != (short)puVar20[7])))) ||
                   ((*(short *)((longlong)puVar19 + 0x1a) != *(short *)((longlong)puVar20 + 0x1a) ||
                    ((char)puVar19[0xe] != (char)puVar20[0xe])))) goto LAB_140326c8a;
                puVar15 = puVar17 + 10;
                do {
                  if ((((ushort)*puVar15 &
                       *(ushort *)(((longlong)puVar20 - (longlong)puVar17) + (longlong)puVar15)) ==
                       0) || ((ushort)puVar15[2] !=
                              *(ushort *)
                               (((longlong)puVar20 - (longlong)puVar17) + 8 + (longlong)puVar15))) {
                    if ((uint)uVar13 < 4) goto LAB_140326c8a;
                    break;
                  }
                  uVar16 = (uint)uVar13 + 1;
                  uVar13 = (ulonglong)uVar16;
                  puVar15 = (uint *)((longlong)puVar15 + 2);
                } while (uVar16 < 4);
                if ((puVar19 != puVar20) &&
                   ((*(byte *)((ulonglong)(ushort)puVar19[6] * 0xb8 + *(longlong *)(lVar5 + 0xf8)) &
                    1) != 0)) goto LAB_140326c8a;
                puVar17[2] = puVar17[2] + puVar20[2];
                if (puVar20[1] < puVar17[1]) {
                  puVar17[3] = puVar17[3] + (puVar17[1] - puVar20[1]);
                  puVar17[1] = puVar20[1];
                }
                if (puVar17[1] + puVar17[3] < puVar20[3] + puVar20[1]) {
                  puVar17[3] = (puVar20[3] - puVar17[1]) + puVar20[1];
                }
                if ((ushort)puVar17[5] < (ushort)puVar20[5]) {
                  *(ushort *)(puVar17 + 5) = (ushort)puVar20[5];
                }
                uVar16 = (int)uVar18 + 1;
                uVar18 = (ulonglong)uVar16;
                *(ushort *)(puVar17 + 10) = (ushort)puVar17[10] & (ushort)puVar20[10];
                *(ushort *)((longlong)puVar17 + 0x2a) =
                     *(ushort *)((longlong)puVar17 + 0x2a) & *(ushort *)((longlong)puVar20 + 0x2a);
                *(ushort *)(puVar17 + 0xb) = (ushort)puVar17[0xb] & (ushort)puVar20[0xb];
                *(ushort *)((longlong)puVar17 + 0x2e) =
                     *(ushort *)((longlong)puVar17 + 0x2e) & *(ushort *)((longlong)puVar20 + 0x2e);
                if (*(uint *)(param_2 + 0x14) <= uVar16) goto LAB_140326c8a;
              }
              uVar18 = (ulonglong)((int)uVar18 + 1);
            }
LAB_140326c8a:
            uVar11 = FUN_14030e510(*(undefined8 *)(param_2 + 8),puVar17);
            *puVar1 = uVar11;
            uVar11 = FUN_14030e690(*(undefined8 *)(param_2 + 8),puVar17);
            uVar14 = (ulonglong)uVar10;
            puVar1[1] = uVar11;
          }
        }
      }
      else {
        uVar18 = (ulonglong)(iVar21 + 1);
        local_res10 = uVar10;
      }
      local_res10 = local_res10 + uVar3;
      uVar13 = (ulonglong)local_res10;
    } while ((uint)uVar18 < *(uint *)(param_2 + 0x14));
  }
  return;
}


