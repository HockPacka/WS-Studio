
longlong FUN_1403acd90(undefined8 param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_3 != 0) {
    if (*(longlong *)(DAT_140c65898 + 0x78) == param_3) {
      bVar2 = true;
    }
    else {
      bVar2 = *(longlong *)(DAT_140c65898 + 0x6490) == param_3;
    }
    lVar1 = 0;
    if (bVar2) {
      lVar1 = DAT_140c65898;
    }
    if ((lVar1 != 0) && (lVar1 = FUN_1405a5b90(), lVar1 != 0)) {
      return lVar1;
    }
  }
  lVar1 = FUN_1407a0fd0(param_1);
  return lVar1;
}

