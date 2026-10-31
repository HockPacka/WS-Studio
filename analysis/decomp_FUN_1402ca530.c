
undefined8 FUN_1402ca530(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar2 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 0x20 + param_2 <= param_1[1]
     )) {
    uVar6 = 0;
    uVar3 = uVar6;
    if (uVar2 != 0) {
      uVar3 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar3;
    if (uVar2 != 0) {
      do {
        iVar5 = (int)uVar6;
        uVar4 = FUN_1402ca420(param_1);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        uVar6 = (ulonglong)(iVar5 + 1U);
      } while (iVar5 + 1U < *param_3);
    }
    return 0;
  }
  return 0x80004005;
}

