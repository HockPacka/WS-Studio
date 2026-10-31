
ulonglong FUN_14049d6d0(undefined8 param_1,longlong param_2,int param_3,int param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if ((param_2 == 0) || (param_2 != *(longlong *)(DAT_140c65898 + 0x78))) {
    return 0;
  }
  uVar3 = 0;
  uVar4 = 0;
  plVar1 = (longlong *)
           (DAT_140c65898 + 0xac0 + (ulonglong)*(uint *)(DAT_140c65898 + 0x6dec) * 0x180);
  uVar2 = uVar4;
  while ((*plVar1 == 0 || (*(int *)(*plVar1 + 0x118) != param_4))) {
    uVar2 = uVar2 + 1;
    plVar1 = plVar1 + 1;
    if (0xb < uVar2) {
LAB_14049d731:
      if (param_3 == 1) {
        uVar4 = (ulonglong)uVar3;
      }
      else if (param_3 == 2) {
        return (ulonglong)(uVar3 == 0);
      }
      return uVar4;
    }
  }
  uVar3 = 1;
  goto LAB_14049d731;
}

