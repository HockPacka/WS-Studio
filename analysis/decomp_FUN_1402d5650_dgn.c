
ulonglong FUN_1402d5650(ulonglong *param_1,longlong param_2,int *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  if (*param_3 != 0x444e474e) {
    return 0xa0100001;
  }
  if (param_3[1] != 6) {
    return 0xa0100002;
  }
  uVar1 = *(longlong *)(param_3 + 4) + param_2;
  if ((uVar1 < *param_1) ||
     (param_1[1] < *(longlong *)(param_3 + 4) + (ulonglong)(uint)param_3[2] * 2 + param_2)) {
    return 0x80004005;
  }
  uVar4 = 0;
  uVar3 = uVar4;
  if (param_3[2] != 0) {
    uVar3 = uVar1;
  }
  *(ulonglong *)(param_3 + 4) = uVar3;
  uVar1 = *(longlong *)(param_3 + 8) + param_2;
  if ((*param_1 <= uVar1) &&
     (*(longlong *)(param_3 + 8) + (ulonglong)(uint)param_3[6] * 2 + param_2 <= param_1[1])) {
    uVar3 = uVar4;
    if (param_3[6] != 0) {
      uVar3 = uVar1;
    }
    *(ulonglong *)(param_3 + 8) = uVar3;
    uVar1 = *(longlong *)(param_3 + 0xc) + param_2;
    if ((*param_1 <= uVar1) &&
       (*(longlong *)(param_3 + 0xc) + (ulonglong)(uint)param_3[10] * 2 + param_2 <= param_1[1])) {
      uVar3 = uVar4;
      if (param_3[10] != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 0xc) = uVar3;
      uVar2 = FUN_1402ca6c0(param_1);
      if ((int)uVar2 < 0) {
        uVar4 = (ulonglong)uVar2;
      }
      return uVar4;
    }
  }
  return 0x80004005;
}

