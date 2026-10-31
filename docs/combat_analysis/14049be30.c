
int FUN_14049be30(void)

{
  int iVar1;
  longlong *plVar2;
  
  if (DAT_140c659a0 != (longlong *)0x0) {
    return 0;
  }
  plVar2 = (longlong *)FUN_14018b280(0x78);
  if (plVar2 == (longlong *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    FUN_1404a1be0(plVar2);
    *plVar2 = (longlong)&PTR_FUN_140b67740;
  }
  iVar1 = (**(code **)(*plVar2 + 8))(plVar2);
  if (iVar1 < 0) {
    (**(code **)*plVar2)(plVar2,1);
    return iVar1;
  }
  DAT_140c659a0 = plVar2;
  return 0;
}

