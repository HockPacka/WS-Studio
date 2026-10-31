
undefined4 FUN_1403bad30(longlong param_1,uint param_2,byte param_3)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  longlong local_res20;
  
  if (param_2 != 0) {
    lVar1 = *(longlong *)(param_1 + 0xaa8);
    local_res20 = lVar1;
    lVar2 = *(longlong *)(lVar1 + 8);
    while (lVar2 != 0) {
      if (*(uint *)(lVar2 + 0x20) < param_2) {
        lVar2 = *(longlong *)(lVar2 + 0x18);
      }
      else {
        local_res20 = lVar2;
        lVar2 = *(longlong *)(lVar2 + 0x10);
      }
    }
    if ((local_res20 == lVar1) || (param_2 < *(uint *)(local_res20 + 0x20))) {
      local_res20 = lVar1;
    }
    if (local_res20 != lVar1) {
      bVar3 = (char)(*(longlong **)(local_res20 + 0x28))[1] - 1;
      if (bVar3 < param_3) {
        param_3 = bVar3;
      }
      return *(undefined4 *)
              (*(longlong *)(**(longlong **)(local_res20 + 0x28) + (ulonglong)param_3 * 8) + 4);
    }
  }
  return 0;
}

