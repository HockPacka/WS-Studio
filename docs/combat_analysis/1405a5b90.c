
undefined8 FUN_1405a5b90(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x7d18);
  local_res8 = lVar1;
  lVar2 = *(longlong *)(lVar1 + 8);
  while (lVar2 != 0) {
    if (*(uint *)(lVar2 + 0x20) < param_2) {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    else {
      local_res8 = lVar2;
      lVar2 = *(longlong *)(lVar2 + 0x10);
    }
  }
  if ((local_res8 == lVar1) || (param_2 < *(uint *)(local_res8 + 0x20))) {
    local_res8 = lVar1;
  }
  if (local_res8 != lVar1) {
    return *(undefined8 *)(local_res8 + 0x28);
  }
  return 0;
}

