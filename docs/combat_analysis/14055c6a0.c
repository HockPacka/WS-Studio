
undefined8 FUN_14055c6a0(void)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined4 uVar4;
  
  FUN_140236320();
  FUN_140238520();
  FUN_140236ba0();
  if (DAT_140c65b70 != (undefined8 *)0x0) {
    (**(code **)*DAT_140c65b70)();
    return 0;
  }
  lVar2 = FUN_14018b280(0x810,0);
  plVar3 = (longlong *)0x0;
  uVar4 = 0;
  if (lVar2 != 0) {
    plVar3 = (longlong *)FUN_14055c940(lVar2);
  }
  iVar1 = (**(code **)(*plVar3 + 0x18))(plVar3);
  if (-1 < iVar1) {
    DAT_140c65b70 = plVar3;
    lVar2 = FUN_140200220(100);
    if (lVar2 != 0) {
      uVar4 = *(undefined4 *)(lVar2 + 4);
    }
    DAT_140c6664c = uVar4;
    return 0;
  }
  (**(code **)(*plVar3 + 8))(plVar3);
  return 0x80004005;
}

