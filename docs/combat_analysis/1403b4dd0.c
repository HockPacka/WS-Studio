
undefined4 FUN_1403b4dd0(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x1c00);
  lVar3 = lVar1;
  lVar2 = *(longlong *)(lVar1 + 8);
  while (lVar2 != 0) {
    if (*(int *)(lVar2 + 0x20) < 0x1a) {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    else {
      lVar3 = lVar2;
      lVar2 = *(longlong *)(lVar2 + 0x10);
    }
  }
  local_res8 = lVar1;
  if (((lVar3 != lVar1) && (*(int *)(lVar3 + 0x20) < 0x1b)) &&
     ((*(int *)(lVar3 + 0x20) < 0x1a || (*(int *)(lVar3 + 0x24) == 0)))) {
    local_res8 = lVar3;
  }
  if ((local_res8 != lVar1) && (*(int *)(local_res8 + 0x30) == 1)) {
    return *(undefined4 *)(local_res8 + 0x34);
  }
  return 0;
}

