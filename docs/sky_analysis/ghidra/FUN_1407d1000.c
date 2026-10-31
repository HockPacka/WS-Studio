
undefined8 FUN_1407d1000(ulonglong *param_1,longlong param_2,int *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int *piVar6;
  
  if (*param_3 != 0x58534b59) {
    return 0xa01b0001;
  }
  if (param_3[1] != 0x10) {
    return 0xa01b0002;
  }
  uVar3 = FUN_1402ca420(param_1,param_2,param_3 + 6);
  if ((((((-1 < (int)uVar3) && (uVar3 = FUN_1407d0f30(param_1), -1 < (int)uVar3)) &&
        (uVar3 = FUN_1407d0f30(param_1,param_2,param_3 + 0x30), -1 < (int)uVar3)) &&
       ((uVar3 = FUN_1407d0f30(param_1,param_2,param_3 + 0x56), -1 < (int)uVar3 &&
        (uVar3 = FUN_1407d0f30(param_1,param_2,param_3 + 0x7c), -1 < (int)uVar3)))) &&
      ((uVar3 = FUN_1407d7800(param_1,param_2,param_3 + 0xa2), -1 < (int)uVar3 &&
       ((uVar3 = FUN_1407d7770(param_1,param_2,param_3 + 0xa8), -1 < (int)uVar3 &&
        (uVar3 = FUN_1407d7800(param_1,param_2,param_3 + 0xae), -1 < (int)uVar3)))))) &&
     ((uVar3 = FUN_1407d7890(param_1,param_2,param_3 + 0xb4), -1 < (int)uVar3 &&
      ((uVar3 = FUN_1407d7920(param_1,param_2,param_3 + 0xba), -1 < (int)uVar3 &&
       (uVar3 = FUN_1407d7a20(param_1,param_2,param_3 + 0xbe), -1 < (int)uVar3)))))) {
    uVar1 = *(longlong *)(param_3 + 0xc6) + param_2;
    if (*param_1 <= uVar1) {
      uVar2 = param_3[0xc4];
      if (*(longlong *)(param_3 + 0xc6) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
        uVar5 = 0;
        uVar4 = uVar5;
        if (uVar2 != 0) {
          uVar4 = uVar1;
        }
        *(ulonglong *)(param_3 + 0xc6) = uVar4;
        uVar1 = *(longlong *)(param_3 + 200) + param_2;
        if ((*param_1 <= uVar1) &&
           (*(longlong *)(param_3 + 200) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])) {
          uVar4 = uVar5;
          if (uVar2 != 0) {
            uVar4 = uVar1;
          }
          *(ulonglong *)(param_3 + 200) = uVar4;
          uVar1 = *(longlong *)(param_3 + 0xcc) + param_2;
          if (*param_1 <= uVar1) {
            uVar2 = param_3[0xca];
            if (*(longlong *)(param_3 + 0xcc) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
              uVar4 = uVar5;
              if (uVar2 != 0) {
                uVar4 = uVar1;
              }
              *(ulonglong *)(param_3 + 0xcc) = uVar4;
              uVar1 = *(longlong *)(param_3 + 0xce) + param_2;
              if ((*param_1 <= uVar1) &&
                 (*(longlong *)(param_3 + 0xce) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])) {
                uVar4 = uVar5;
                if (uVar2 != 0) {
                  uVar4 = uVar1;
                }
                *(ulonglong *)(param_3 + 0xce) = uVar4;
                uVar3 = FUN_1402d4b30(param_1,param_2,param_3 + 0xd0);
                if ((int)uVar3 < 0) {
                  return uVar3;
                }
                uVar3 = FUN_1402ca420(param_1,param_2,param_3 + 0xd4);
                if ((int)uVar3 < 0) {
                  return uVar3;
                }
                uVar3 = FUN_1407d7800(param_1);
                if ((int)uVar3 < 0) {
                  return uVar3;
                }
                uVar3 = FUN_1402ca420(param_1,param_2,param_3 + 0xde);
                if ((int)uVar3 < 0) {
                  return uVar3;
                }
                uVar3 = FUN_1402ca420(param_1);
                if ((int)uVar3 < 0) {
                  return uVar3;
                }
                uVar1 = *(longlong *)(param_3 + 0xe8) + param_2;
                if (*param_1 <= uVar1) {
                  uVar2 = param_3[0xe6];
                  if (*(longlong *)(param_3 + 0xe8) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])
                  {
                    uVar4 = uVar5;
                    if (uVar2 != 0) {
                      uVar4 = uVar1;
                    }
                    *(ulonglong *)(param_3 + 0xe8) = uVar4;
                    uVar1 = *(longlong *)(param_3 + 0xea) + param_2;
                    if ((*param_1 <= uVar1) &&
                       (*(longlong *)(param_3 + 0xea) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]
                       )) {
                      uVar4 = uVar5;
                      if (uVar2 != 0) {
                        uVar4 = uVar1;
                      }
                      *(ulonglong *)(param_3 + 0xea) = uVar4;
                      uVar3 = FUN_1407d7800(param_1,param_2,param_3 + 0xec);
                      if ((int)uVar3 < 0) {
                        return uVar3;
                      }
                      uVar3 = FUN_1407d7800(param_1,param_2,param_3 + 0xf2);
                      if ((int)uVar3 < 0) {
                        return uVar3;
                      }
                      piVar6 = param_3 + 0xf8;
                      do {
                        uVar3 = FUN_1407d7770(param_1,param_2,piVar6);
                        if ((int)uVar3 < 0) {
                          return uVar3;
                        }
                        uVar5 = uVar5 + 1;
                        piVar6 = piVar6 + 6;
                      } while (uVar5 < 8);
                      uVar3 = FUN_1407d7ab0(param_1,param_2,param_3 + 0x128);
                      if ((int)uVar3 < 0) {
                        return uVar3;
                      }
                      uVar3 = FUN_1402ca420(param_1,param_2,param_3 + 300);
                      if ((int)uVar3 < 0) {
                        return uVar3;
                      }
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar3 = 0x80004005;
  }
  return uVar3;
}

