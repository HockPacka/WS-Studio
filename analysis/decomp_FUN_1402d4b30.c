
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

