
undefined8 FUN_1407d7920(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  
  uVar5 = *(longlong *)(param_3 + 2) + param_2;
  if (uVar5 < *param_1) {
    return 0x80004005;
  }
  uVar4 = *param_3;
  if (param_1[1] < *(longlong *)(param_3 + 2) + (ulonglong)uVar4 * 0x30 + param_2) {
    return 0x80004005;
  }
  uVar1 = 0;
  if (uVar4 != 0) {
    uVar1 = uVar5;
  }
  uVar5 = 0;
  *(ulonglong *)(param_3 + 2) = uVar1;
  lVar6 = (ulonglong)uVar4 * 0x30 + uVar1;
  if (uVar4 != 0) {
    do {
      lVar7 = uVar5 * 0x30 + param_1[2] + *(longlong *)(param_3 + 2);
      uVar1 = *(longlong *)(lVar7 + 0x10) + lVar6;
      if ((uVar1 < *param_1) ||
         (param_1[1] < *(longlong *)(lVar7 + 0x10) + (ulonglong)*(uint *)(lVar7 + 8) * 2 + lVar6)) {
        return 0x80004005;
      }
      uVar2 = 0;
      if (*(uint *)(lVar7 + 8) != 0) {
        uVar2 = uVar1;
      }
      *(ulonglong *)(lVar7 + 0x10) = uVar2;
      uVar3 = FUN_1407d7770(param_1,lVar6);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *param_3);
  }
  return 0;
}

