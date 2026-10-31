
undefined8 FUN_14030b340(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     ((ulonglong)*param_3 * 0x10 + *(longlong *)(param_3 + 2) + param_2 <= param_1[1])) {
    uVar3 = 0;
    uVar2 = uVar3;
    if (*param_3 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    uVar1 = *(longlong *)(param_3 + 6) + param_2;
    if ((*param_1 <= uVar1) &&
       (*(longlong *)(param_3 + 6) + (ulonglong)param_3[4] * 4 + param_2 <= param_1[1])) {
      uVar2 = uVar3;
      if (param_3[4] != 0) {
        uVar2 = uVar1;
      }
      *(ulonglong *)(param_3 + 6) = uVar2;
      uVar1 = *(longlong *)(param_3 + 10) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 10) + (ulonglong)param_3[8] * 4 + param_2 <= param_1[1])) {
        if (param_3[8] != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 10) = uVar3;
        return 0;
      }
    }
  }
  return 0x80004005;
}

