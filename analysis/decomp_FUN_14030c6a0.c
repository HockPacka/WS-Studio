
undefined8 FUN_14030c6a0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = param_2;
  uVar2 = FUN_14030ed20(param_1,param_2,param_3 + 0x38);
  if (-1 < (int)uVar2) {
    uVar2 = FUN_14030eb90(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (*(longlong *)(param_3 + 0x90) == -1) {
      *(undefined8 *)(param_3 + 0x90) = 0;
    }
    else {
      uVar1 = *(longlong *)(param_3 + 0x90) + lVar3;
      if (uVar1 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < uVar1 + 0xed0) {
        return 0x80004005;
      }
      *(ulonglong *)(param_3 + 0x90) = uVar1;
      uVar2 = FUN_14030bcc0(param_1,uVar1 + 0xed0,param_1[2] + uVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    if (*(longlong *)(param_3 + 0x98) == -1) {
      *(undefined8 *)(param_3 + 0x98) = 0;
    }
    else {
      uVar1 = *(longlong *)(param_3 + 0x98) + param_2;
      if ((uVar1 < *param_1) || (param_1[1] < uVar1 + 0x4a8)) {
        return 0x80004005;
      }
      *(ulonglong *)(param_3 + 0x98) = uVar1;
      uVar2 = FUN_14030c3d0(param_1,uVar1 + 0x4b0,param_1[2] + uVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

