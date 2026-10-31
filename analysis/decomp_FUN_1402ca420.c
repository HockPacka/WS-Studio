
undefined8 FUN_1402ca420(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (*(longlong *)(param_3 + 2) + (ulonglong)*param_3 * 2 + param_2 <= param_1[1])) {
    uVar2 = 0;
    if (*param_3 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    return 0;
  }
  return 0x80004005;
}

