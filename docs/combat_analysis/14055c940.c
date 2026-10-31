
undefined8 * FUN_14055c940(undefined8 *param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined8 *puVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  longlong lVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  
  FUN_1407a0980();
  *param_1 = &PTR_FUN_140b6c720;
  FUN_1403fb600(param_1 + 0xc4);
  puVar20 = (undefined8 *)0x0;
  param_1[0xc9] = 0;
  puVar14 = (undefined1 *)FUN_14018b280(0x40,0);
  param_1[0xcc] = 0;
  param_1[0xcb] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xcb] + 8) = 0;
  *(undefined8 *)(param_1[0xcb] + 0x10) = param_1[0xcb];
  *(undefined8 *)(param_1[0xcb] + 0x18) = param_1[0xcb];
  puVar14 = (undefined1 *)FUN_14018b280(0x28,0);
  param_1[0xd0] = 0;
  param_1[0xcf] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xcf] + 8) = 0;
  *(undefined8 *)(param_1[0xcf] + 0x10) = param_1[0xcf];
  *(undefined8 *)(param_1[0xcf] + 0x18) = param_1[0xcf];
  puVar14 = (undefined1 *)FUN_14018b280(0x28,0);
  param_1[0xd4] = 0;
  param_1[0xd3] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xd3] + 8) = 0;
  *(undefined8 *)(param_1[0xd3] + 0x10) = param_1[0xd3];
  *(undefined8 *)(param_1[0xd3] + 0x18) = param_1[0xd3];
  FUN_1400b6000(param_1 + 0xd6,0);
  puVar14 = (undefined1 *)FUN_14018b280(0x30,0);
  param_1[0xdd] = 0;
  param_1[0xdc] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xdc] + 8) = 0;
  *(undefined8 *)(param_1[0xdc] + 0x10) = param_1[0xdc];
  *(undefined8 *)(param_1[0xdc] + 0x18) = param_1[0xdc];
  puVar14 = (undefined1 *)FUN_14018b280(0x30,0);
  param_1[0xe1] = 0;
  param_1[0xe0] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xe0] + 8) = 0;
  *(undefined8 *)(param_1[0xe0] + 0x10) = param_1[0xe0];
  *(undefined8 *)(param_1[0xe0] + 0x18) = param_1[0xe0];
  puVar14 = (undefined1 *)FUN_14018b280(0x30,0);
  param_1[0xe5] = 0;
  param_1[0xe4] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xe4] + 8) = 0;
  *(undefined8 *)(param_1[0xe4] + 0x10) = param_1[0xe4];
  *(undefined8 *)(param_1[0xe4] + 0x18) = param_1[0xe4];
  puVar14 = (undefined1 *)FUN_14018b280(0x30,0);
  param_1[0xe9] = 0;
  param_1[0xe8] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xe8] + 8) = 0;
  *(undefined8 *)(param_1[0xe8] + 0x10) = param_1[0xe8];
  *(undefined8 *)(param_1[0xe8] + 0x18) = param_1[0xe8];
  puVar14 = (undefined1 *)FUN_14018b280(0x30,0);
  param_1[0xed] = 0;
  param_1[0xec] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xec] + 8) = 0;
  *(undefined8 *)(param_1[0xec] + 0x10) = param_1[0xec];
  *(undefined8 *)(param_1[0xec] + 0x18) = param_1[0xec];
  puVar14 = (undefined1 *)FUN_14018b280(0x30,0);
  param_1[0xf2] = 0;
  param_1[0xf1] = puVar14;
  *puVar14 = 0;
  *(undefined8 *)(param_1[0xf1] + 8) = 0;
  *(undefined8 *)(param_1[0xf1] + 0x10) = param_1[0xf1];
  *(undefined8 *)(param_1[0xf1] + 0x18) = param_1[0xf1];
  FUN_1405662d0(param_1 + 0xf4);
  param_1[0xf9] = 0;
  param_1[0xfa] = 0;
  param_1[0xfb] = 0;
  param_1[0xfd] = 0;
  param_1[0xfc] = 0;
  param_1[0xff] = 0;
  param_1[0xfe] = 0;
  param_1[0x101] = 0;
  param_1[0x100] = 0;
  puVar15 = (undefined8 *)FUN_14018b280(0x28,0);
  uVar12 = 0;
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64d94 == 0) && (iVar13 = FUN_140236320(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar1,0);
    if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xa8] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64d94 == 0) && (iVar13 = FUN_140236320(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar2,0);
    if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xa9] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64d94 == 0) && (iVar13 = FUN_140236320(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar3,0);
    if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xaa] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64d94 == 0) && (iVar13 = FUN_140236320(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar4,0);
    if (SUB168(ZEXT816(8) * auVar4,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xab] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64d94 == 0) && (iVar13 = FUN_140236320(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar5._8_8_ = 0;
    auVar5._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar5,0);
    if (SUB168(ZEXT816(8) * auVar5,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xac] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64d94 == 0) && (iVar13 = FUN_140236320(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar6,0);
    if (SUB168(ZEXT816(8) * auVar6,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xad] = puVar19;
  lVar18 = FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (lVar18 != 0) {
    if (DAT_140c63838 == (code *)0x0) {
      if (DAT_140c64d94 == 0) {
        iVar13 = FUN_140236320();
        if (iVar13 < 0) {
          puVar19 = (undefined8 *)FUN_1400b6000(lVar18,0);
        }
        else {
          uVar11 = (**(code **)(*DAT_140c653f0 + 0x28))();
          puVar19 = (undefined8 *)FUN_1400b6000(lVar18,uVar11);
        }
      }
      else {
        puVar19 = (undefined8 *)FUN_1400b6000(lVar18,0);
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8,DAT_140c63858);
      puVar19 = (undefined8 *)FUN_1400b6000(lVar18,uVar11);
    }
  }
  param_1[0xae] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c644e4 == 0) && (iVar13 = FUN_140238520(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c63ba0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4Effects_140a6d268,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar7._8_8_ = 0;
    auVar7._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar7,0);
    if (SUB168(ZEXT816(8) * auVar7,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xaf] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64c94 == 0) && (iVar13 = FUN_14023d1a0(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c64fe8 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4Visual_140a6d658,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar8,0);
    if (SUB168(ZEXT816(8) * auVar8,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xef] = puVar19;
  puVar15 = (undefined8 *)FUN_14018b280(0x28);
  puVar19 = puVar20;
  if (puVar15 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar11 = uVar12;
      if ((DAT_140c64510 == 0) && (iVar13 = FUN_140236ba0(), -1 < iVar13)) {
        uVar11 = (**(code **)(*DAT_140c654e0 + 0x28))();
      }
    }
    else {
      uVar11 = (*DAT_140c63838)(&PTR_u_Spell4Base_140a6d118,DAT_140c63858);
    }
    *puVar15 = 0;
    uVar16 = FUN_1401a40c0(uVar11);
    puVar15[1] = uVar16;
    auVar9._8_8_ = 0;
    auVar9._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar9,0);
    if (SUB168(ZEXT816(8) * auVar9,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar15[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar15[1] << 3);
    puVar15[3] = FUN_1400522d0;
    puVar15[4] = FUN_1400522e0;
    puVar19 = puVar15;
  }
  param_1[0xc3] = puVar19;
  puVar19 = (undefined8 *)FUN_14018b280(0x28);
  if (puVar19 != (undefined8 *)0x0) {
    if (DAT_140c63838 == (code *)0x0) {
      if ((DAT_140c64920 == 0) && (iVar13 = FUN_1401fc880(), -1 < iVar13)) {
        uVar12 = (**(code **)(*DAT_140c65540 + 0x28))();
      }
    }
    else {
      uVar12 = (*DAT_140c63838)(&PTR_u_DistanceDamageModifier_140a6a130,DAT_140c63858);
    }
    *puVar19 = 0;
    uVar16 = FUN_1401a40c0(uVar12);
    puVar19[1] = uVar16;
    auVar10._8_8_ = 0;
    auVar10._0_8_ = uVar16;
    uVar17 = SUB168(ZEXT816(8) * auVar10,0);
    if (SUB168(ZEXT816(8) * auVar10,8) != 0) {
      uVar17 = 0xffffffffffffffff;
    }
    uVar17 = FUN_14018b280(uVar17,0);
    puVar19[2] = uVar17;
    FUN_1407e4830(uVar17,0,puVar19[1] << 3);
    puVar19[3] = FUN_1400522d0;
    puVar19[4] = FUN_1400522e0;
    puVar20 = puVar19;
  }
  param_1[0xb1] = puVar20;
  FUN_1407e4830(param_1 + 0x9e,0,0x2c);
  return param_1;
}

