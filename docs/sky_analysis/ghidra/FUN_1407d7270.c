
undefined8 FUN_1407d7270(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = *(longlong *)(param_3 + 2) + param_2;
  if (uVar6 < *param_1) {
    return 0x80004005;
  }
  uVar5 = *param_3;
  if (param_1[1] < (ulonglong)uVar5 * 0x18 + *(longlong *)(param_3 + 2) + param_2) {
    return 0x80004005;
  }
  uVar1 = 0;
  if (uVar5 != 0) {
    uVar1 = uVar6;
  }
  uVar6 = 0;
  lVar4 = ((ulonglong)uVar5 * 0x18 + 0xf & 0xfffffffffffffff0) + uVar1;
  *(ulonglong *)(param_3 + 2) = uVar1;
  if (uVar5 != 0) {
    do {
      puVar3 = (uint *)(param_1[2] + uVar6 * 0x18 + *(longlong *)(param_3 + 2));
      uVar1 = *(longlong *)(puVar3 + 2) + lVar4;
      if (uVar1 < *param_1) {
        return 0x80004005;
      }
      uVar5 = *puVar3;
      if (param_1[1] < *(longlong *)(puVar3 + 2) + (ulonglong)uVar5 * 4 + lVar4) {
        return 0x80004005;
      }
      uVar2 = 0;
      if (uVar5 != 0) {
        uVar2 = uVar1;
      }
      uVar1 = *(longlong *)(puVar3 + 4) + lVar4;
      *(ulonglong *)(puVar3 + 2) = uVar2;
      if (uVar1 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < (ulonglong)uVar5 * 0x10 + *(longlong *)(puVar3 + 4) + lVar4) {
        return 0x80004005;
      }
      uVar2 = 0;
      if (uVar5 != 0) {
        uVar2 = uVar1;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      *(ulonglong *)(puVar3 + 4) = uVar2;
    } while (uVar5 < *param_3);
  }
  return 0;
}

