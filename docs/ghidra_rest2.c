
==== FUN_14030aab0 @ 14030aab0 size 225 ====
CALLERS: FUN_14030f5b0
CALLEES:

undefined8 FUN_14030aab0(ulonglong *param_1,longlong param_2,uint *param_3)

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
       (*(longlong *)(param_3 + 6) + (ulonglong)param_3[4] * 0xc + param_2 <= param_1[1])) {
      uVar2 = uVar3;
      if (param_3[4] != 0) {
        uVar2 = uVar1;
      }
      *(ulonglong *)(param_3 + 6) = uVar2;
      uVar1 = *(longlong *)(param_3 + 10) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 10) + (ulonglong)param_3[8] * 4 + param_2 <= param_1[1])) {
        uVar2 = uVar3;
        if (param_3[8] != 0) {
          uVar2 = uVar1;
        }
        *(ulonglong *)(param_3 + 10) = uVar2;
        uVar1 = *(longlong *)(param_3 + 0xe) + param_2;
        if ((*param_1 <= uVar1) &&
           (*(longlong *)(param_3 + 0xe) + (ulonglong)param_3[0xc] * 0x14 + param_2 <= param_1[1]))
        {
          if (param_3[0xc] != 0) {
            uVar3 = uVar1;
          }
          *(ulonglong *)(param_3 + 0xe) = uVar3;
          return 0;
        }
      }
    }
  }
  return 0x80004005;
}



==== FUN_14030b170 @ 14030b170 size 451 ====
CALLERS: FUN_14030f340
CALLEES: FUN_1402cb010 FUN_14030ece0

undefined8 FUN_14030b170(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar1 = *(longlong *)(param_3 + 0x10) + param_2;
  if ((*param_1 <= uVar1) &&
     (*(longlong *)(param_3 + 0x10) + (ulonglong)*(uint *)(param_3 + 8) * 4 + param_2 <= param_1[1])
     ) {
    uVar4 = 0;
    uVar3 = uVar4;
    if (*(uint *)(param_3 + 8) != 0) {
      uVar3 = uVar1;
    }
    *(ulonglong *)(param_3 + 0x10) = uVar3;
    uVar1 = *(longlong *)(param_3 + 0x40) + param_2;
    if ((*param_1 <= uVar1) &&
       (*(longlong *)(param_3 + 0x40) + (ulonglong)*(uint *)(param_3 + 0x38) + param_2 <= param_1[1]
       )) {
      uVar3 = uVar4;
      if (*(uint *)(param_3 + 0x38) != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 0x40) = uVar3;
      uVar1 = *(longlong *)(param_3 + 0x50) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 0x50) + (ulonglong)*(uint *)(param_3 + 0x48) * 4 + param_2 <=
          param_1[1])) {
        uVar3 = uVar4;
        if (*(uint *)(param_3 + 0x48) != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 0x50) = uVar3;
        uVar1 = *(longlong *)(param_3 + 0x60) + param_2;
        if ((*param_1 <= uVar1) &&
           (*(longlong *)(param_3 + 0x60) + (ulonglong)*(uint *)(param_3 + 0x58) * 4 + param_2 <=
            param_1[1])) {
          uVar3 = uVar4;
          if (*(uint *)(param_3 + 0x58) != 0) {
            uVar3 = uVar1;
          }
          *(ulonglong *)(param_3 + 0x60) = uVar3;
          uVar1 = *(longlong *)(param_3 + 0x78) + param_2;
          if ((*param_1 <= uVar1) &&
             (*(longlong *)(param_3 + 0x78) + (ulonglong)*(uint *)(param_3 + 0x70) + param_2 <=
              param_1[1])) {
            uVar3 = uVar4;
            if (*(uint *)(param_3 + 0x70) != 0) {
              uVar3 = uVar1;
            }
            *(ulonglong *)(param_3 + 0x78) = uVar3;
            uVar2 = FUN_14030ece0(param_1,param_2,param_3 + 0x80);
            if ((int)uVar2 < 0) {
              return uVar2;
            }
            uVar1 = *(longlong *)(param_3 + 0xa0) + param_2;
            if ((*param_1 <= uVar1) &&
               (*(longlong *)(param_3 + 0xa0) + (ulonglong)*(uint *)(param_3 + 0x98) * 4 + param_2
                <= param_1[1])) {
              uVar3 = uVar4;
              if (*(uint *)(param_3 + 0x98) != 0) {
                uVar3 = uVar1;
              }
              *(ulonglong *)(param_3 + 0xa0) = uVar3;
              uVar1 = *(longlong *)(param_3 + 0xb0) + param_2;
              if ((*param_1 <= uVar1) &&
                 (*(longlong *)(param_3 + 0xb0) + (ulonglong)*(uint *)(param_3 + 0xa8) * 2 + param_2
                  <= param_1[1])) {
                if (*(uint *)(param_3 + 0xa8) != 0) {
                  uVar4 = uVar1;
                }
                *(ulonglong *)(param_3 + 0xb0) = uVar4;
                uVar2 = FUN_1402cb010(param_1);
                if ((int)uVar2 < 0) {
                  return uVar2;
                }
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 0x80004005;
}



==== FUN_14030ca00 @ 14030ca00 size 191 ====
CALLERS: FUN_14030f660
CALLEES: FUN_14030ed20 FUN_1402ca3c0 FUN_14030ebf0

undefined8 FUN_14030ca00(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar3 = FUN_14030ed20(param_1,param_2,param_3 + 8);
  if ((((int)uVar3 < 0) || (uVar3 = FUN_1402ca3c0(param_1), (int)uVar3 < 0)) ||
     (uVar3 = FUN_14030ebf0(param_1), (int)uVar3 < 0)) {
    return uVar3;
  }
  uVar1 = *(longlong *)(param_3 + 0x58) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *(uint *)(param_3 + 0x50);
    if (*(longlong *)(param_3 + 0x58) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar4 = 0;
      if (uVar2 != 0) {
        uVar4 = uVar1;
      }
      *(ulonglong *)(param_3 + 0x58) = uVar4;
      uVar1 = *(longlong *)(param_3 + 0x60) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 0x60) + (ulonglong)uVar2 * 8 + param_2 <= param_1[1])) {
        uVar4 = 0;
        if (uVar2 != 0) {
          uVar4 = uVar1;
        }
        *(ulonglong *)(param_3 + 0x60) = uVar4;
        return 0;
      }
    }
  }
  return 0x80004005;
}


