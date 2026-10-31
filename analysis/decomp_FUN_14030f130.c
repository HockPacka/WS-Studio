
undefined8 FUN_14030f130(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 0x160 + param_2 <= param_1[1]) {
      uVar6 = 0;
      uVar3 = uVar6;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      if (uVar2 != 0) {
        do {
          uVar4 = FUN_14030ad40(param_1,(ulonglong)uVar2 * 0x160 + uVar3,
                                uVar6 * 0x160 + param_1[2] + *(longlong *)(param_3 + 2));
          if ((int)uVar4 < 0) {
            return uVar4;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *param_3);
      }
      return 0;
    }
  }
  return 0x80004005;
}

