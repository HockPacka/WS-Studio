
==== FUN_14030b010 @ 14030b010 size 175 ====
CALLERS: FUN_14030f290
CALLEES: FUN_14030a9d0

undefined8 FUN_14030b010(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar1 = *(longlong *)(param_3 + 0x28) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *(uint *)(param_3 + 0x20);
    if (*(longlong *)(param_3 + 0x28) + (ulonglong)uVar2 * 0x128 + param_2 <= param_1[1]) {
      uVar6 = 0;
      uVar3 = uVar6;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 0x28) = uVar3;
      if (uVar2 != 0) {
        do {
          uVar4 = FUN_14030a9d0(param_1,((ulonglong)uVar2 * 0x128 + 0xf & 0xfffffffffffffff0) +
                                        uVar3,
                                uVar6 * 0x128 + *(longlong *)(param_3 + 0x28) + param_1[2]);
          if ((int)uVar4 < 0) {
            return uVar4;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(uint *)(param_3 + 0x20));
      }
      return 0;
    }
  }
  return 0x80004005;
}



==== FUN_14030aed0 @ 14030aed0 size 315 ====
CALLERS: FUN_14030f1e0
CALLEES: FUN_14030ec80 FUN_14030eb00

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



==== FUN_14030b010 @ 14030b010 size 175 ====
CALLERS: FUN_14030f290
CALLEES: FUN_14030a9d0

undefined8 FUN_14030b010(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar1 = *(longlong *)(param_3 + 0x28) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *(uint *)(param_3 + 0x20);
    if (*(longlong *)(param_3 + 0x28) + (ulonglong)uVar2 * 0x128 + param_2 <= param_1[1]) {
      uVar6 = 0;
      uVar3 = uVar6;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 0x28) = uVar3;
      if (uVar2 != 0) {
        do {
          uVar4 = FUN_14030a9d0(param_1,((ulonglong)uVar2 * 0x128 + 0xf & 0xfffffffffffffff0) +
                                        uVar3,
                                uVar6 * 0x128 + *(longlong *)(param_3 + 0x28) + param_1[2]);
          if ((int)uVar4 < 0) {
            return uVar4;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(uint *)(param_3 + 0x20));
      }
      return 0;
    }
  }
  return 0x80004005;
}



==== FUN_14030ad40 @ 14030ad40 size 388 ====
CALLERS: FUN_14030f130
CALLEES: FUN_14030eb00 FUN_14030ebf0

undefined8 FUN_14030ad40(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar3 = FUN_14030ebf0(param_1,param_2,param_3 + 0x10);
  if (((((int)uVar3 < 0) || (uVar3 = FUN_14030ebf0(param_1,param_2,param_3 + 0x28), (int)uVar3 < 0))
      || (uVar3 = FUN_14030ebf0(param_1,param_2,param_3 + 0x40), (int)uVar3 < 0)) ||
     (uVar3 = FUN_14030ebf0(param_1,param_2), (int)uVar3 < 0)) {
    return uVar3;
  }
  uVar1 = *(longlong *)(param_3 + 0x78) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *(uint *)(param_3 + 0x70);
    if (*(longlong *)(param_3 + 0x78) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar5 = 0;
      uVar4 = uVar5;
      if (uVar2 != 0) {
        uVar4 = uVar1;
      }
      *(ulonglong *)(param_3 + 0x78) = uVar4;
      uVar1 = *(longlong *)(param_3 + 0x80) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 0x80) + (ulonglong)uVar2 * 8 + param_2 <= param_1[1])) {
        uVar4 = uVar5;
        if (uVar2 != 0) {
          uVar4 = uVar1;
        }
        *(ulonglong *)(param_3 + 0x80) = uVar4;
        uVar1 = *(longlong *)(param_3 + 0x90) + param_2;
        if (*param_1 <= uVar1) {
          uVar2 = *(uint *)(param_3 + 0x88);
          if (*(longlong *)(param_3 + 0x90) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
            uVar4 = uVar5;
            if (uVar2 != 0) {
              uVar4 = uVar1;
            }
            *(ulonglong *)(param_3 + 0x90) = uVar4;
            uVar1 = *(longlong *)(param_3 + 0x98) + param_2;
            if ((*param_1 <= uVar1) &&
               (*(longlong *)(param_3 + 0x98) + (ulonglong)uVar2 * 8 + param_2 <= param_1[1])) {
              if (uVar2 != 0) {
                uVar5 = uVar1;
              }
              *(ulonglong *)(param_3 + 0x98) = uVar5;
              uVar3 = FUN_14030eb00(param_1,param_2,param_3 + 0xa0);
              if ((int)uVar3 < 0) {
                return uVar3;
              }
              uVar3 = FUN_14030eb00(param_1,param_2,param_3 + 0xb8);
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
  return 0x80004005;
}


