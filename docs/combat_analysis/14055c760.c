
undefined8 FUN_14055c760(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 local_res8;
  
  uVar3 = (**(code **)(*(longlong *)*param_1 + 8))();
  lVar1 = *(longlong *)(param_2 + 8);
  local_res8 = lVar1;
  lVar2 = *(longlong *)(lVar1 + 8);
  while (lVar2 != 0) {
    if (*(uint *)(lVar2 + 0x20) < uVar3) {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    else {
      local_res8 = lVar2;
      lVar2 = *(longlong *)(lVar2 + 0x10);
    }
  }
  if ((local_res8 == lVar1) || (uVar3 < *(uint *)(local_res8 + 0x20))) {
    local_res8 = lVar1;
  }
  if (local_res8 != lVar1) {
    (**(code **)(**(longlong **)(*param_1 + 0x138) + 8))
              (*(longlong **)(*param_1 + 0x138),
               *(undefined4 *)(*(longlong *)(local_res8 + 0x28) + 0x80));
  }
  return 1;
}

