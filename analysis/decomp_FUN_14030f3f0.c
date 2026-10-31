
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

