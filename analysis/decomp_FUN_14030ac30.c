
undefined8 FUN_14030ac30(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar5 = 0;
      uVar3 = uVar5;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])) {
        uVar3 = uVar5;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        uVar1 = *(longlong *)(param_3 + 8) + param_2;
        if (*param_1 <= uVar1) {
          uVar2 = param_3[6];
          if (*(longlong *)(param_3 + 8) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
            uVar3 = uVar5;
            if (uVar2 != 0) {
              uVar3 = uVar1;
            }
            *(ulonglong *)(param_3 + 8) = uVar3;
            uVar1 = *(longlong *)(param_3 + 10) + param_2;
            if ((*param_1 <= uVar1) &&
               (*(longlong *)(param_3 + 10) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])) {
              if (uVar2 != 0) {
                uVar5 = uVar1;
              }
              *(ulonglong *)(param_3 + 10) = uVar5;
              uVar4 = FUN_14030eb90(param_1,param_2,param_3 + 0xc);
              if (-1 < (int)uVar4) {
                uVar4 = FUN_14030eb90(param_1);
                if (-1 < (int)uVar4) {
                  uVar4 = FUN_1402ca3c0(param_1);
                  if (-1 < (int)uVar4) {
                    uVar4 = 0;
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

