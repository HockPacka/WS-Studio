
undefined8 FUN_140758510(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined **local_28;
  undefined4 local_20;
  longlong local_18;
  undefined4 local_10;
  
  if (*(longlong *)(DAT_140c65898 + 0x78) == 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    return 1;
  }
  local_28 = &PTR_FUN_140b569f0;
  local_10 = 1;
  local_18 = param_1;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  uVar2 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar1 + 1) = 5;
  *puVar1 = uVar2;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  local_20 = FUN_1400578c0(param_1);
  uVar6 = 0;
  do {
    lVar3 = FUN_1403c1ea0(DAT_140c65898,uVar6,*(undefined1 *)(DAT_140c65898 + 0x6dec));
    if (lVar3 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(lVar3 + 0x118);
    }
    FUN_1400fa9e0(&local_28,uVar5);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0xc);
  lVar3 = local_18;
  puVar4 = (undefined8 *)
           FUN_14005c3c0(*(undefined8 *)(*(longlong *)(local_18 + 0x20) + 0xa0),local_20);
  puVar1 = *(undefined8 **)(lVar3 + 0x10);
  uVar2 = *puVar4;
  *puVar1 = uVar2;
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(puVar4 + 1);
  *(longlong *)(lVar3 + 0x10) = *(longlong *)(lVar3 + 0x10) + 0x10;
  FUN_1400579e0(lVar3,uVar2,local_20);
  return 1;
}

