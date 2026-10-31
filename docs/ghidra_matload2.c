
==== FUN_14030f290 @ 14030f290 size 174 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030b010

undefined8 FUN_14030f290(ulonglong *param_1,longlong param_2,uint *param_3)

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
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 0x30 + param_2 <= param_1[1]) {
      uVar6 = 0;
      uVar3 = uVar6;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      if (uVar2 != 0) {
        do {
          uVar4 = FUN_14030b010(param_1,(ulonglong)uVar2 * 0x30 + uVar3,
                                uVar6 * 0x30 + param_1[2] + *(longlong *)(param_3 + 2));
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



==== FUN_14030f3f0 @ 14030f3f0 size 234 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ee60 FUN_14030ed80

undefined8 FUN_14030f3f0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (uVar1 < *param_1) {
    return 0x80004005;
  }
  uVar4 = *param_3;
  if (param_1[1] < (ulonglong)uVar4 * 0x28 + *(longlong *)(param_3 + 2) + param_2) {
    return 0x80004005;
  }
  uVar5 = 0;
  uVar2 = uVar5;
  if (uVar4 != 0) {
    uVar2 = uVar1;
  }
  *(ulonglong *)(param_3 + 2) = uVar2;
  lVar7 = ((ulonglong)uVar4 * 0x28 + 0xf & 0xfffffffffffffff0) + uVar2;
  if (uVar4 != 0) {
    do {
      lVar6 = param_1[2] + uVar5 * 0x28 + *(longlong *)(param_3 + 2);
      uVar3 = FUN_14030ed80(param_1,lVar7,lVar6 + 8);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar3 = FUN_14030ee60(param_1,lVar7,lVar6 + 0x18);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *param_3);
  }
  return 0;
}



==== FUN_14030f4e0 @ 14030f4e0 size 208 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ed20

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



==== FUN_14030f7c0 @ 14030f7c0 size 167 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ed20

undefined8 FUN_14030f7c0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar4 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0x20 + param_2 <= param_1[1]
     )) {
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
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *param_3);
    }
    return 0;
  }
  return 0x80004005;
}



==== FUN_14030b340 @ 14030b340 size 146 ====
CALLERS: FUN_14030cac0
CALLEES:

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



==== FUN_14030ee60 @ 14030ee60 size 167 ====
CALLERS: FUN_14030f3f0 FUN_14030cac0
CALLEES: FUN_14030eb90

undefined8 FUN_14030ee60(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if ((*param_1 <= uVar1) &&
     (uVar4 = *param_3, *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0x20 + param_2 <= param_1[1]
     )) {
    uVar5 = 0;
    uVar2 = uVar5;
    if (uVar4 != 0) {
      uVar2 = uVar1;
    }
    *(ulonglong *)(param_3 + 2) = uVar2;
    if (uVar4 != 0) {
      do {
        uVar3 = FUN_14030eb90(param_1);
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



==== FUN_14030ac30 @ 14030ac30 size 263 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030eb90 FUN_1402ca3c0

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


