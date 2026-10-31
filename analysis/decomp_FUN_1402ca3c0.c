
undefined8 FUN_1402ca3c0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
    }
  }
  return 0x80004005;
}

