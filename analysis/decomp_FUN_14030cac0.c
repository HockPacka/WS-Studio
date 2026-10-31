
undefined8 FUN_14030cac0(ulonglong *param_1,longlong param_2,int *param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  ulonglong uVar8;
  
  if (*param_3 != 0x4d4f444c) {
    return 0xa0060001;
  }
  if (param_3[1] != 100) {
    return 0xa0060002;
  }
  uVar3 = param_2 + *(longlong *)(param_3 + 6);
  if ((uVar3 < *param_1) ||
     (uVar5 = param_3[4],
     param_1[1] < *(longlong *)(param_3 + 6) + (ulonglong)uVar5 * 0x70 + param_2)) {
    return 0x80004005;
  }
  uVar8 = 0;
  uVar2 = uVar8;
  if (uVar5 != 0) {
    uVar2 = uVar3;
  }
  *(ulonglong *)(param_3 + 6) = uVar2;
  uVar3 = uVar8;
  if (uVar5 != 0) {
    do {
      iVar7 = (int)uVar3;
      uVar1 = FUN_1402ca420(param_1);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar3 = (ulonglong)(iVar7 + 1U);
    } while (iVar7 + 1U < (uint)param_3[4]);
  }
  piVar6 = param_3 + 8;
  uVar3 = uVar8;
  do {
    uVar1 = FUN_14030eb90(param_1,param_2,piVar6);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    uVar3 = uVar3 + 1;
    piVar6 = piVar6 + 6;
  } while (uVar3 < 4);
  uVar1 = FUN_14030efa0(param_1);
  if (-1 < (int)uVar1) {
    piVar6 = param_3 + 0x24;
    uVar3 = uVar8;
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,piVar6);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar3 = uVar3 + 1;
      piVar6 = piVar6 + 6;
    } while (uVar3 < 4);
    uVar1 = FUN_14030f080(param_1);
    if ((((((-1 < (int)uVar1) &&
           (uVar1 = FUN_14030ac30(param_1,param_2,param_3 + 0x40), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030f130(param_1), -1 < (int)uVar1)) &&
         ((uVar1 = FUN_1402ca420(param_1,param_2,param_3 + 100), -1 < (int)uVar1 &&
          (uVar1 = FUN_1402ca420(param_1), -1 < (int)uVar1)))) &&
        ((uVar1 = FUN_1402ca420(param_1), -1 < (int)uVar1 &&
         ((uVar1 = FUN_1402ca530(param_1), -1 < (int)uVar1 &&
          (uVar1 = FUN_1402ca420(param_1,param_2,param_3 + 0x74), -1 < (int)uVar1)))))) &&
       ((uVar1 = FUN_14030f1e0(param_1), -1 < (int)uVar1 &&
        (uVar1 = FUN_14030f290(param_1,param_2,param_3 + 0x7c), -1 < (int)uVar1)))) {
      uVar3 = *(longlong *)(param_3 + 0x82) + param_2;
      if ((*param_1 <= uVar3) &&
         (*(longlong *)(param_3 + 0x82) + (ulonglong)(uint)param_3[0x80] * 4 + param_2 <= param_1[1]
         )) {
        uVar2 = uVar8;
        if (param_3[0x80] != 0) {
          uVar2 = uVar3;
        }
        *(ulonglong *)(param_3 + 0x82) = uVar2;
        uVar3 = *(longlong *)(param_3 + 0x86) + param_2;
        if ((*param_1 <= uVar3) &&
           (*(longlong *)(param_3 + 0x86) + (ulonglong)(uint)param_3[0x84] * 2 + param_2 <=
            param_1[1])) {
          uVar2 = uVar8;
          if (param_3[0x84] != 0) {
            uVar2 = uVar3;
          }
          *(ulonglong *)(param_3 + 0x86) = uVar2;
          uVar1 = FUN_14030b0c0(param_1,param_2,param_3 + 0x88);
          if ((int)uVar1 < 0) {
            return uVar1;
          }
          uVar1 = FUN_14030f340();
          if ((int)uVar1 < 0) {
            return uVar1;
          }
          uVar3 = *(longlong *)(param_3 + 0x9a) + param_2;
          if ((*param_1 <= uVar3) &&
             (*(longlong *)(param_3 + 0x9a) + (ulonglong)(uint)param_3[0x98] * 4 + param_2 <=
              param_1[1])) {
            uVar2 = uVar8;
            if (param_3[0x98] != 0) {
              uVar2 = uVar3;
            }
            *(ulonglong *)(param_3 + 0x9a) = uVar2;
            uVar3 = *(longlong *)(param_3 + 0x9e) + param_2;
            if ((*param_1 <= uVar3) &&
               (*(longlong *)(param_3 + 0x9e) + (ulonglong)(uint)param_3[0x9c] * 2 + param_2 <=
                param_1[1])) {
              uVar2 = uVar8;
              if (param_3[0x9c] != 0) {
                uVar2 = uVar3;
              }
              *(ulonglong *)(param_3 + 0x9e) = uVar2;
              uVar3 = *(longlong *)(param_3 + 0xa2) + param_2;
              if ((*param_1 <= uVar3) &&
                 (*(longlong *)(param_3 + 0xa2) + (ulonglong)(uint)param_3[0xa0] * 8 + param_2 <=
                  param_1[1])) {
                uVar2 = uVar8;
                if (param_3[0xa0] != 0) {
                  uVar2 = uVar3;
                }
                *(ulonglong *)(param_3 + 0xa2) = uVar2;
                uVar3 = *(longlong *)(param_3 + 0xa6) + param_2;
                if (*param_1 <= uVar3) {
                  uVar5 = param_3[0xa4];
                  if (*(longlong *)(param_3 + 0xa6) + (ulonglong)uVar5 * 4 + param_2 <= param_1[1])
                  {
                    uVar2 = uVar8;
                    if (uVar5 != 0) {
                      uVar2 = uVar3;
                    }
                    *(ulonglong *)(param_3 + 0xa6) = uVar2;
                    uVar3 = *(longlong *)(param_3 + 0xa8) + param_2;
                    if ((*param_1 <= uVar3) &&
                       (*(longlong *)(param_3 + 0xa8) + (ulonglong)uVar5 * 2 + param_2 <= param_1[1]
                       )) {
                      uVar2 = uVar8;
                      if (uVar5 != 0) {
                        uVar2 = uVar3;
                      }
                      *(ulonglong *)(param_3 + 0xa8) = uVar2;
                      uVar1 = FUN_1402d4b30(param_1,param_2,param_3 + 0xaa);
                      if ((int)uVar1 < 0) {
                        return uVar1;
                      }
                      uVar1 = FUN_14030f3f0(param_1,param_2,param_3 + 0xae);
                      if ((int)uVar1 < 0) {
                        return uVar1;
                      }
                      uVar3 = *(longlong *)(param_3 + 0xb4) + param_2;
                      if ((*param_1 <= uVar3) &&
                         (*(longlong *)(param_3 + 0xb4) + (ulonglong)(uint)param_3[0xb2] * 8 +
                          param_2 <= param_1[1])) {
                        uVar2 = uVar8;
                        if (param_3[0xb2] != 0) {
                          uVar2 = uVar3;
                        }
                        *(ulonglong *)(param_3 + 0xb4) = uVar2;
                        uVar3 = *(longlong *)(param_3 + 0xb8) + param_2;
                        if ((*param_1 <= uVar3) &&
                           (*(longlong *)(param_3 + 0xb8) + (ulonglong)(uint)param_3[0xb6] * 2 +
                            param_2 <= param_1[1])) {
                          uVar2 = uVar8;
                          if (param_3[0xb6] != 0) {
                            uVar2 = uVar3;
                          }
                          *(ulonglong *)(param_3 + 0xb8) = uVar2;
                          uVar3 = *(longlong *)(param_3 + 0xbc) + param_2;
                          if ((*param_1 <= uVar3) &&
                             (*(longlong *)(param_3 + 0xbc) + (ulonglong)(uint)param_3[0xba] * 8 +
                              param_2 <= param_1[1])) {
                            uVar2 = uVar8;
                            if (param_3[0xba] != 0) {
                              uVar2 = uVar3;
                            }
                            *(ulonglong *)(param_3 + 0xbc) = uVar2;
                            uVar3 = *(longlong *)(param_3 + 0xc0) + param_2;
                            if (*param_1 <= uVar3) {
                              uVar5 = param_3[0xbe];
                              if (*(longlong *)(param_3 + 0xc0) + (ulonglong)uVar5 * 0xa0 + param_2
                                  <= param_1[1]) {
                                uVar2 = uVar8;
                                if (uVar5 != 0) {
                                  uVar2 = uVar3;
                                }
                                *(ulonglong *)(param_3 + 0xc0) = uVar2;
                                uVar3 = uVar8;
                                if (uVar5 != 0) {
                                  do {
                                    uVar1 = FUN_14030c6a0(param_1,(ulonglong)uVar5 * 0xa0 + uVar2,
                                                          uVar3 * 0xa0 +
                                                          *(longlong *)(param_3 + 0xc0) + param_1[2]
                                                         );
                                    if ((int)uVar1 < 0) {
                                      return uVar1;
                                    }
                                    uVar4 = (int)uVar3 + 1;
                                    uVar3 = (ulonglong)uVar4;
                                  } while (uVar4 < (uint)param_3[0xbe]);
                                }
                                uVar1 = FUN_14030f4e0(param_1,param_2,param_3 + 0xc2);
                                if ((int)uVar1 < 0) {
                                  return uVar1;
                                }
                                uVar3 = *(longlong *)(param_3 + 200) + param_2;
                                if ((*param_1 <= uVar3) &&
                                   (uVar5 = param_3[0xc6],
                                   *(longlong *)(param_3 + 200) + (ulonglong)uVar5 * 400 + param_2
                                   <= param_1[1])) {
                                  uVar2 = uVar8;
                                  if (uVar5 != 0) {
                                    uVar2 = uVar3;
                                  }
                                  *(ulonglong *)(param_3 + 200) = uVar2;
                                  uVar3 = uVar8;
                                  if (uVar5 != 0) {
                                    do {
                                      uVar1 = FUN_14030c7d0(param_1);
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar5 = (int)uVar3 + 1;
                                      uVar3 = (ulonglong)uVar5;
                                    } while (uVar5 < (uint)param_3[0xc6]);
                                  }
                                  uVar3 = *(longlong *)(param_3 + 0xcc) + param_2;
                                  if ((*param_1 <= uVar3) &&
                                     (uVar5 = param_3[0xca],
                                     *(longlong *)(param_3 + 0xcc) + (ulonglong)uVar5 * 0x38 +
                                     param_2 <= param_1[1])) {
                                    uVar2 = uVar8;
                                    if (uVar5 != 0) {
                                      uVar2 = uVar3;
                                    }
                                    *(ulonglong *)(param_3 + 0xcc) = uVar2;
                                    uVar3 = uVar8;
                                    if (uVar5 != 0) {
                                      do {
                                        uVar1 = FUN_14030ed20(param_1);
                                        if ((int)uVar1 < 0) {
                                          return uVar1;
                                        }
                                        uVar5 = (int)uVar3 + 1;
                                        uVar3 = (ulonglong)uVar5;
                                      } while (uVar5 < (uint)param_3[0xca]);
                                    }
                                    uVar1 = FUN_1402ca420(param_1,param_2,param_3 + 0xce);
                                    if ((int)uVar1 < 0) {
                                      return uVar1;
                                    }
                                    uVar1 = FUN_1402ca3c0(param_1);
                                    if ((int)uVar1 < 0) {
                                      return uVar1;
                                    }
                                    uVar1 = FUN_1402ca3c0(param_1);
                                    if ((int)uVar1 < 0) {
                                      return uVar1;
                                    }
                                    uVar1 = FUN_14030f5b0(param_1);
                                    if ((int)uVar1 < 0) {
                                      return uVar1;
                                    }
                                    uVar3 = *(longlong *)(param_3 + 0x12a) + param_2;
                                    if ((*param_1 <= uVar3) &&
                                       (*(longlong *)(param_3 + 0x12a) +
                                        (ulonglong)(uint)param_3[0x128] * 4 + param_2 <= param_1[1])
                                       ) {
                                      uVar2 = uVar8;
                                      if (param_3[0x128] != 0) {
                                        uVar2 = uVar3;
                                      }
                                      *(ulonglong *)(param_3 + 0x12a) = uVar2;
                                      uVar1 = FUN_14030b340(param_1,param_2,param_3 + 0x144);
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar1 = FUN_14030f660();
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar1 = FUN_1402ca420(param_1,param_2,param_3 + 0x154);
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar1 = FUN_14030f710(param_1);
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar1 = FUN_14030ee60(param_1,param_2,param_3 + 0x15c);
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar1 = FUN_14030f7c0(param_1,param_2,param_3 + 0x162);
                                      if ((int)uVar1 < 0) {
                                        return uVar1;
                                      }
                                      uVar3 = *(longlong *)(param_3 + 0x168) + param_2;
                                      if ((*param_1 <= uVar3) &&
                                         ((ulonglong)(uint)param_3[0x166] * 0x4c +
                                          *(longlong *)(param_3 + 0x168) + param_2 <= param_1[1])) {
                                        if (param_3[0x166] != 0) {
                                          uVar8 = uVar3;
                                        }
                                        *(ulonglong *)(param_3 + 0x168) = uVar8;
                                        uVar1 = FUN_1402ca420(param_1,param_2,param_3 + 0x16a);
                                        if ((int)uVar1 < 0) {
                                          return uVar1;
                                        }
                                        uVar1 = FUN_14030eb90(param_1);
                                        if ((int)uVar1 < 0) {
                                          return uVar1;
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
                    }
                  }
                }
              }
            }
          }
        }
      }
      uVar1 = 0x80004005;
    }
  }
  return uVar1;
}

