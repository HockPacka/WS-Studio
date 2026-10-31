
==== FUN_14030f5b0 @ 14030f5b0 size 163 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030aab0

undefined8 FUN_14030f5b0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar4 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0x40 + param_2 <= param_1[1]
     )) {
    uVar5 = 0;
    uVar2 = uVar5;
    if (uVar4 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    if (uVar4 != 0) {
      do {
        uVar3 = FUN_14030aab0(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *param_3);
    }
    return 0;
  }
  return 0x80004005;
}



==== FUN_14030f710 @ 14030f710 size 166 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030c930

undefined8 FUN_14030f710(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar4 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0xa0 + param_2 <= param_1[1]
     )) {
    uVar5 = 0;
    uVar2 = uVar5;
    if (uVar4 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    if (uVar4 != 0) {
      do {
        uVar3 = FUN_14030c930(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *param_3);
    }
    return 0;
  }
  return 0x80004005;
}



==== FUN_14030f340 @ 14030f340 size 166 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030b170

undefined8 FUN_14030f340(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar4 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 200 + param_2 <= param_1[1])
     ) {
    uVar5 = 0;
    uVar2 = uVar5;
    if (uVar4 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    if (uVar4 != 0) {
      do {
        uVar3 = FUN_14030b170(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *param_3);
    }
    return 0;
  }
  return 0x80004005;
}



==== FUN_14030ed80 @ 14030ed80 size 223 ====
CALLERS: FUN_14030f3f0
CALLEES:

undefined8 FUN_14030ed80(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar6) {
    uVar5 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar5 * 0x20 + param_2 <= param_1[1]) {
      uVar1 = 0;
      if (uVar5 != 0) {
        uVar1 = uVar6;
      }
      uVar6 = 0;
      *(ulonglong *)(param_3 + 2) = uVar1;
      lVar4 = (ulonglong)uVar5 * 0x20 + uVar1;
      if (uVar5 != 0) {
        do {
          lVar3 = uVar6 * 0x20 + param_1[2] + *(longlong *)(param_3 + 2);
          uVar1 = *(longlong *)(lVar3 + 0x10) + lVar4;
          if (uVar1 < *param_1) {
            return 0x80004005;
          }
          uVar5 = *(uint *)(lVar3 + 8);
          if (param_1[1] < *(longlong *)(lVar3 + 0x10) + (ulonglong)uVar5 * 4 + lVar4) {
            return 0x80004005;
          }
          uVar2 = 0;
          if (uVar5 != 0) {
            uVar2 = uVar1;
          }
          *(ulonglong *)(lVar3 + 0x10) = uVar2;
          uVar1 = *(longlong *)(lVar3 + 0x18) + lVar4;
          if (uVar1 < *param_1) {
            return 0x80004005;
          }
          if (param_1[1] < *(longlong *)(lVar3 + 0x18) + (ulonglong)uVar5 * 2 + lVar4) {
            return 0x80004005;
          }
          uVar2 = 0;
          if (uVar5 != 0) {
            uVar2 = uVar1;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
          *(ulonglong *)(lVar3 + 0x18) = uVar2;
        } while (uVar5 < *param_3);
      }
      return 0;
    }
  }
  return 0x80004005;
}



==== FUN_14030c7d0 @ 14030c7d0 size 351 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ed20 FUN_1402ca3c0

undefined8 FUN_14030c7d0(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x10);
  if (-1 < (int)uVar1) {
    uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x28);
    if (-1 < (int)uVar1) {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x40);
      if (-1 < (int)uVar1) {
        uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + 0x58);
        if (-1 < (int)uVar1) {
          uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + 0x70);
          if (-1 < (int)uVar1) {
            uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x88);
            if (-1 < (int)uVar1) {
              uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xa0);
              if (-1 < (int)uVar1) {
                uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xb8);
                if (-1 < (int)uVar1) {
                  uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xd0);
                  if (-1 < (int)uVar1) {
                    uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xe8);
                    if (-1 < (int)uVar1) {
                      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x100);
                      if (-1 < (int)uVar1) {
                        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x118);
                        if (-1 < (int)uVar1) {
                          uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x130);
                          if (-1 < (int)uVar1) {
                            uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x148);
                            if (-1 < (int)uVar1) {
                              uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x160);
                              if (-1 < (int)uVar1) {
                                uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x178);
                                if (-1 < (int)uVar1) {
                                  uVar1 = 0;
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
  return uVar1;
}



==== FUN_1402d4b30 @ 1402d4b30 size 184 ====
CALLERS: FUN_1407d1000 FUN_14030cac0 FUN_1402d2e30
CALLEES:

undefined8 FUN_1402d4b30(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  uVar5 = *(longlong *)(param_3 + 2) + param_2;
  if (uVar5 < *param_1) {
    return 0x80004005;
  }
  uVar4 = *param_3;
  if (param_1[1] < *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0x10 + param_2) {
    return 0x80004005;
  }
  uVar1 = 0;
  if (uVar4 != 0) {
    uVar1 = uVar5;
  }
  uVar5 = 0;
  *(ulonglong *)(param_3 + 2) = uVar1;
  lVar6 = (ulonglong)uVar4 * 0x10 + uVar1;
  if (uVar4 != 0) {
    do {
      puVar3 = (uint *)(uVar5 * 0x10 + param_1[2] + *(longlong *)(param_3 + 2));
      uVar1 = *(longlong *)(puVar3 + 2) + lVar6;
      if (uVar1 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *(longlong *)(puVar3 + 2) + (ulonglong)*puVar3 * 2 + lVar6) {
        return 0x80004005;
      }
      uVar2 = 0;
      if (*puVar3 != 0) {
        uVar2 = uVar1;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      *(ulonglong *)(puVar3 + 2) = uVar2;
    } while (uVar4 < *param_3);
  }
  return 0;
}



==== FUN_14030f660 @ 14030f660 size 171 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ca00

undefined8 FUN_14030f660(ulonglong *param_1,longlong param_2,uint *param_3)

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
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 0x68 + param_2 <= param_1[1]) {
      uVar6 = 0;
      uVar3 = uVar6;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      if (uVar2 != 0) {
        do {
          uVar4 = FUN_14030ca00(param_1,((ulonglong)uVar2 * 0x68 + 0xf & 0xfffffffffffffff0) + uVar3
                                ,uVar6 * 0x68 + param_1[2] + *(longlong *)(param_3 + 2));
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



==== FUN_14030c930 @ 14030c930 size 194 ====
CALLERS: FUN_14030f710
CALLEES: FUN_14030ed20 FUN_1402ca3c0

undefined8 FUN_14030c930(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar3 = FUN_14030ed20(param_1,param_2,param_3 + 0x28);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar1 = *(longlong *)(param_3 + 0x48) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *(uint *)(param_3 + 0x40);
    if (*(longlong *)(param_3 + 0x48) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar4 = 0;
      if (uVar2 != 0) {
        uVar4 = uVar1;
      }
      *(ulonglong *)(param_3 + 0x48) = uVar4;
      uVar1 = *(longlong *)(param_3 + 0x50) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 0x50) + (ulonglong)uVar2 * 2 + param_2 <= param_1[1])) {
        uVar4 = 0;
        if (uVar2 != 0) {
          uVar4 = uVar1;
        }
        *(ulonglong *)(param_3 + 0x50) = uVar4;
        uVar3 = FUN_1402ca3c0(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar3 = FUN_1402ca3c0(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar3 = FUN_1402ca3c0(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        return 0;
      }
    }
  }
  return 0x80004005;
}



==== FUN_14030f1e0 @ 14030f1e0 size 174 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030aed0

undefined8 FUN_14030f1e0(ulonglong *param_1,longlong param_2,uint *param_3)

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
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 0x98 + param_2 <= param_1[1]) {
      uVar6 = 0;
      uVar3 = uVar6;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      if (uVar2 != 0) {
        do {
          uVar4 = FUN_14030aed0(param_1,((ulonglong)uVar2 * 0x98 + 0xf & 0xfffffffffffffff0) + uVar3
                                ,uVar6 * 0x98 + param_1[2] + *(longlong *)(param_3 + 2));
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



==== FUN_14030f080 @ 14030f080 size 166 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030aba0

undefined8 FUN_14030f080(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar4 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0xb8 + param_2 <= param_1[1]
     )) {
    uVar5 = 0;
    uVar2 = uVar5;
    if (uVar4 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    if (uVar4 != 0) {
      do {
        uVar3 = FUN_14030aba0(param_1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *param_3);
    }
    return 0;
  }
  return 0x80004005;
}



==== FUN_14030efa0 @ 14030efa0 size 216 ====
CALLERS: FUN_14030cac0
CALLEES:

undefined8 FUN_14030efa0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  uVar7 = *(longlong *)(param_3 + 2) + param_2;
  if (uVar7 < *param_1) {
    return 0x80004005;
  }
  uVar6 = *param_3;
  if (param_1[1] < *(longlong *)(param_3 + 2) + (ulonglong)uVar6 * 0x30 + param_2) {
    return 0x80004005;
  }
  uVar3 = 0;
  if (uVar6 != 0) {
    uVar3 = uVar7;
  }
  uVar7 = 0;
  *(ulonglong *)(param_3 + 2) = uVar3;
  lVar8 = (ulonglong)uVar6 * 0x30 + uVar3;
  if (uVar6 != 0) {
    do {
      lVar1 = *(longlong *)(param_3 + 2);
      lVar5 = uVar7 * 0x30 + param_1[2];
      lVar2 = *(longlong *)(lVar5 + 0x28 + lVar1);
      uVar3 = lVar2 + lVar8;
      if ((uVar3 < *param_1) ||
         (uVar6 = *(uint *)(lVar5 + 0x20 + lVar1), param_1[1] < lVar2 + (ulonglong)uVar6 * 2 + lVar8
         )) {
        return 0x80004005;
      }
      uVar4 = 0;
      if (uVar6 != 0) {
        uVar4 = uVar3;
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      *(ulonglong *)(lVar5 + 0x28 + lVar1) = uVar4;
    } while (uVar6 < *param_3);
  }
  return 0;
}



==== FUN_14030f130 @ 14030f130 size 174 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ad40

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



==== FUN_14030f870 @ 14030f870 size 391 ====
CALLERS: FUN_1402ebf40 FUN_14030dbb0
CALLEES:

void FUN_14030f870(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  byte *pbVar3;
  ulonglong uVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  
  lVar2 = (**(code **)(**(longlong **)(param_1 + 0xa0) + 0x38))
                    (*(longlong **)(param_1 + 0xa0),0,0,2);
  if (lVar2 != 0) {
    uVar5 = 0;
    if (*(int *)(*(longlong *)(param_1 + 0x40) + 0x18) != 0) {
      puVar9 = (undefined4 *)(lVar2 + 0xc);
      do {
        uVar8 = (ulonglong)uVar5;
        uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x140) * uVar8 + *(longlong *)(param_1 + 0xe8));
        *(ulonglong *)(puVar9 + -3) =
             CONCAT26(((uVar1 >> 8) - 0x80) * 0x100 + (uVar1 & 0xff),
                      *(undefined6 *)
                       ((ulonglong)uVar5 * *(longlong *)(param_1 + 0x130) +
                       *(longlong *)(param_1 + 0xd8)));
        pbVar3 = (byte *)((ulonglong)uVar5 * *(longlong *)(param_1 + 0x148) +
                         *(longlong *)(param_1 + 0xf0));
        sVar7 = (ushort)pbVar3[1] * 0x100 + (ushort)*pbVar3;
        uVar4 = (ulonglong)uVar5;
        uVar5 = uVar5 + 1;
        pbVar3 = (byte *)(uVar4 * *(longlong *)(param_1 + 0x138) + *(longlong *)(param_1 + 0xe0));
        sVar6 = (ushort)pbVar3[1] * 0x100 + (ushort)*pbVar3;
        puVar9[-1] = (uint)(byte)((ushort)sVar7 >> 8) * 0x1000000 +
                     (uint)(byte)((ushort)sVar6 >> 8) * 0x100 + (uint)(byte)sVar6 * 0x10000 +
                     (uint)(byte)sVar7;
        *puVar9 = *(undefined4 *)
                   (uVar8 * *(longlong *)(param_1 + 0x170) + *(longlong *)(param_1 + 0x118));
        puVar9 = puVar9 + 4;
      } while (uVar5 < *(uint *)(*(longlong *)(param_1 + 0x40) + 0x18));
    }
    (**(code **)(**(longlong **)(param_1 + 0xa0) + 0x40))();
  }
  return;
}


