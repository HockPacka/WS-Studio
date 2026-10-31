
undefined8 FUN_14030c3d0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = *(longlong *)(param_3 + 0x10) + param_2;
  if ((uVar6 < *param_1) ||
     (param_1[1] < *(longlong *)(param_3 + 0x10) + (ulonglong)*(uint *)(param_3 + 8) * 0xc + param_2
     )) {
    return 0x80004005;
  }
  uVar3 = 0;
  if (*(uint *)(param_3 + 8) != 0) {
    uVar3 = uVar6;
  }
  *(ulonglong *)(param_3 + 0x10) = uVar3;
  uVar2 = FUN_14030ebf0(param_1,param_2,param_3 + 0x30);
  if (-1 < (int)uVar2) {
    uVar6 = 0;
    do {
      uVar3 = 0;
      do {
        uVar2 = FUN_1402ca3c0(param_1,param_2,param_3 + ((uVar3 + uVar6 * 5) * 3 + 10) * 8);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        uVar5 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar5;
      } while (uVar5 < 5);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 2);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + uVar6 * 0x18 + 0x140);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + uVar6 * 0x18 + 0x1c0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + (uVar6 * 3 + 0x47) * 8);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar5 = 0;
    puVar4 = (ulonglong *)(param_3 + 0x2c8);
    do {
      uVar6 = puVar4[-1] + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      uVar1 = (uint)puVar4[-2];
      if (param_1[1] < puVar4[-1] + (ulonglong)uVar1 * 4 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      puVar4[-1] = uVar3;
      uVar6 = *puVar4 + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *puVar4 + (ulonglong)uVar1 * 2 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      uVar5 = uVar5 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 3;
    } while (uVar5 < 5);
    uVar5 = 0;
    puVar4 = (ulonglong *)(param_3 + 0x340);
    do {
      uVar6 = puVar4[-1] + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      uVar1 = (uint)puVar4[-2];
      if (param_1[1] < puVar4[-1] + (ulonglong)uVar1 * 4 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      puVar4[-1] = uVar3;
      uVar6 = *puVar4 + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *puVar4 + (ulonglong)uVar1 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      uVar5 = uVar5 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 3;
    } while (uVar5 < 5);
    uVar2 = FUN_14030ed20(param_1,param_2,param_3 + 0x418);
    if ((((-1 < (int)uVar2) && (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)) &&
        (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)) &&
       ((uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2 &&
        (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)))) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

