
undefined8 FUN_140444240(longlong param_1)

{
  undefined1 auVar1 [16];
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *_Dst;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined8 *_Src;
  undefined8 *puVar10;
  undefined8 *puVar11;
  uint uVar12;
  
  puVar10 = (undefined8 *)0x0;
  FUN_140236320();
  FUN_140236ba0();
  if (DAT_140c63838 == (code *)0x0) {
    uVar2 = 0;
    if ((DAT_140c64b2c == 0) && (iVar3 = FUN_14020e980(), -1 < iVar3)) {
      uVar2 = (**(code **)(*DAT_140c64298 + 0x28))();
    }
  }
  else {
    uVar2 = (*DAT_140c63838)(&PTR_u_ItemSpecial_140a6b010,DAT_140c63858);
  }
  _Src = puVar10;
  puVar11 = puVar10;
  puVar9 = puVar10;
  if (uVar2 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        puVar5 = puVar10;
        if (DAT_140c64b2c == 0) {
          iVar3 = FUN_14020e980();
          if (iVar3 < 0) {
            puVar5 = (undefined8 *)0x0;
          }
          else {
            puVar5 = (undefined8 *)(**(code **)(*DAT_140c64298 + 0x20))(DAT_140c64298,puVar9);
          }
        }
      }
      else {
        puVar5 = (undefined8 *)(*DAT_140c63848)(&PTR_u_ItemSpecial_140a6b010,puVar9,DAT_140c63858);
      }
      iVar3 = *(int *)((longlong)puVar5 + 0xc);
      if (iVar3 == 0) {
LAB_140444379:
        iVar3 = *(int *)(puVar5 + 2);
        if (iVar3 != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c64d94 != 0) || (iVar4 = FUN_140236320(), iVar4 < 0)) goto LAB_140444469;
            lVar6 = (**(code **)(*DAT_140c653f0 + 0x18))(DAT_140c653f0,iVar3);
          }
          else {
            lVar6 = (*DAT_140c63840)(&PTR_u_Spell4_140a6d0a8,iVar3,DAT_140c63858);
          }
          if (lVar6 == 0) goto LAB_140444469;
        }
        iVar3 = *(int *)((longlong)puVar5 + 4);
        if (iVar3 != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c647d0 != 0) || (iVar4 = FUN_140225760(), iVar4 < 0)) goto LAB_140444469;
            lVar6 = (**(code **)(*DAT_140c64208 + 0x18))(DAT_140c64208,iVar3);
          }
          else {
            lVar6 = (*DAT_140c63840)(&PTR_u_Prerequisite_140a6c2e0,iVar3,DAT_140c63858);
          }
          if ((lVar6 == 0) || (*(int *)((longlong)puVar5 + 0xc) != 0)) goto LAB_140444469;
        }
        _Dst = (undefined8 *)FUN_14018db00(_Src,(longlong)puVar11 + 1,8);
        _Dst[(longlong)puVar11] = puVar5;
        puVar5 = _Src;
        if ((_Src != _Dst) &&
           (memcpy(_Dst,_Src,(longlong)puVar11 * 8), puVar5 = _Dst, _Src != (undefined8 *)0x0)) {
          (**(code **)(_Src[-2] + 8))(_Src + -2);
        }
        puVar11 = (undefined8 *)((longlong)puVar11 + 1);
        _Src = puVar5;
      }
      else if (DAT_140c63840 == (code *)0x0) {
        if ((DAT_140c64d94 == 0) && (iVar4 = FUN_140236320(), -1 < iVar4)) {
          lVar6 = (**(code **)(*DAT_140c653f0 + 0x18))(DAT_140c653f0,iVar3);
          goto LAB_140444370;
        }
      }
      else {
        lVar6 = (*DAT_140c63840)(&PTR_u_Spell4_140a6d0a8,iVar3,DAT_140c63858);
LAB_140444370:
        if (lVar6 != 0) goto LAB_140444379;
      }
LAB_140444469:
      uVar12 = (int)puVar9 + 1;
      puVar9 = (undefined8 *)(ulonglong)uVar12;
    } while (uVar12 < uVar2);
  }
  puVar5 = (undefined8 *)FUN_14018b280(0x28);
  puVar9 = puVar10;
  if (puVar5 != (undefined8 *)0x0) {
    *puVar5 = 0;
    uVar7 = FUN_1401a40c0(puVar11);
    puVar5[1] = uVar7;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar7;
    uVar8 = SUB168(ZEXT816(8) * auVar1,0);
    if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
      uVar8 = 0xffffffffffffffff;
    }
    uVar8 = FUN_14018b280(uVar8,0);
    puVar5[2] = uVar8;
    FUN_1407e4830(uVar8,0,puVar5[1] << 3);
    puVar5[3] = FUN_1400522d0;
    puVar5[4] = FUN_1400522e0;
    puVar9 = puVar5;
  }
  *(undefined8 **)(param_1 + 0x60) = puVar9;
  if (puVar11 != (undefined8 *)0x0) {
    do {
      FUN_1400bd4a0(*(undefined8 *)(param_1 + 0x60),_Src[(longlong)puVar10],_Src[(longlong)puVar10])
      ;
      puVar10 = (undefined8 *)((longlong)puVar10 + 1);
    } while (puVar10 < puVar11);
  }
  if (_Src != (undefined8 *)0x0) {
    (**(code **)(_Src[-2] + 8))(_Src + -2);
  }
  return 0;
}

