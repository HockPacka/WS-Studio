
undefined8 FUN_14030f4e0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((uVar1 < *param_1) ||
     (uVar4 = *param_3, param_1[1] < *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0x50 + param_2)
     ) {
    return 0x80004005;
  }
  uVar5 = 0;
  uVar2 = uVar5;
  if (uVar4 != 0) {
    uVar2 = uVar1;
  }
  *(ulonglong *)(param_3 + 2) = uVar2;
  if (uVar4 != 0) {
    do {
      uVar3 = FUN_14030ed20(param_1);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar3 = FUN_14030ed20(param_1);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar3 = FUN_14030ed20(param_1);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *param_3);
  }
  return 0;
}

