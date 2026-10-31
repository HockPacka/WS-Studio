
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

