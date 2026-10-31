
undefined4 FUN_1407d5a60(longlong param_1,uint param_2,ulonglong param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x118))
                    (*(longlong **)(param_1 + 0x18),
                     *(undefined4 *)
                      (*(longlong *)(*(longlong *)(param_1 + 8) + 800) + (ulonglong)param_2 * 4));
  if (lVar1 != 0) {
    lVar1 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x108))
                      (*(longlong **)(param_1 + 0x18),
                       *(undefined4 *)(lVar1 + 8 + (param_3 & 0xffffffff) * 4));
    if (lVar1 != 0) {
      return *(undefined4 *)(lVar1 + 4);
    }
  }
  return 0;
}

