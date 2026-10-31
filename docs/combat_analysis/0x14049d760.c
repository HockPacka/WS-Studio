
ulonglong FUN_14049d760(undefined8 param_1,longlong param_2,int param_3,undefined4 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if ((param_2 != 0) && (param_2 == *(longlong *)(DAT_140c65898 + 0x78))) {
    uVar1 = FUN_1403cdf50(DAT_140c65898,param_4,*(undefined1 *)(DAT_140c65898 + 0x6dec),0);
    uVar2 = uVar1;
    if ((param_3 != 1) && (uVar2 = 0, param_3 == 2)) {
      uVar2 = (ulonglong)((int)uVar1 == 0);
    }
    return uVar2;
  }
  return 0;
}

