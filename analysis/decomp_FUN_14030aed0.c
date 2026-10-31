
undefined8 FUN_14030aed0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 0x10) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *(uint *)(param_3 + 8);
    if (*(longlong *)(param_3 + 0x10) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar5 = 0;
      uVar3 = uVar5;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      uVar1 = *(longlong *)(param_3 + 0x18) + param_2;
      *(ulonglong *)(param_3 + 0x10) = uVar3;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 0x18) + (ulonglong)uVar2 * 6 + param_2 <= param_1[1])) {
        uVar3 = uVar5;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 0x18) = uVar3;
        uVar1 = *(longlong *)(param_3 + 0x28) + param_2;
        if (*param_1 <= uVar1) {
          uVar2 = *(uint *)(param_3 + 0x20);
          if (*(longlong *)(param_3 + 0x28) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
            uVar3 = uVar5;
            if (uVar2 != 0) {
              uVar3 = uVar1;
            }
            uVar1 = *(longlong *)(param_3 + 0x30) + param_2;
            *(ulonglong *)(param_3 + 0x28) = uVar3;
            if ((*param_1 <= uVar1) &&
               (*(longlong *)(param_3 + 0x30) + (ulonglong)uVar2 * 6 + param_2 <= param_1[1])) {
              if (uVar2 != 0) {
                uVar5 = uVar1;
              }
              *(ulonglong *)(param_3 + 0x30) = uVar5;
              uVar4 = FUN_14030ec80(param_1,param_2,param_3 + 0x38);
              if (-1 < (int)uVar4) {
                uVar4 = FUN_14030ec80(param_1);
                if (-1 < (int)uVar4) {
                  uVar4 = FUN_14030eb00(param_1);
                  if (-1 < (int)uVar4) {
                    uVar4 = FUN_14030eb00(param_1,param_2,param_3 + 0x80);
                    if (-1 < (int)uVar4) {
                      uVar4 = 0;
                    }
                  }
                }
              }
              return uVar4;
            }
          }
        }
      }
    }
  }
  return 0x80004005;
}

