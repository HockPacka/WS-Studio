
ulonglong FUN_14049d680(undefined8 param_1,longlong param_2,int param_3,undefined4 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if ((param_2 == 0) || ((*(int *)(param_2 + 0x80) != 0x14 && (*(int *)(param_2 + 0x80) != 0x17))))
  {
    uVar2 = 0;
  }
  else {
    uVar1 = FUN_1403bb170(DAT_140c65898,param_4);
    uVar2 = uVar1;
    if ((param_3 != 1) && (uVar2 = 0, param_3 == 2)) {
      return (ulonglong)((int)uVar1 == 0);
    }
  }
  return uVar2;
}

