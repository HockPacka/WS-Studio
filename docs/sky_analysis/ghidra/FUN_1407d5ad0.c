
undefined8
FUN_1407d5ad0(longlong param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5,
             undefined4 *param_6,longlong *param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_4;
  lVar1 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x118))
                    (*(longlong **)(param_1 + 0x18),
                     *(undefined4 *)
                      (*(longlong *)(*(longlong *)(param_1 + 8) + 800) + (ulonglong)param_2 * 4));
  if (((((lVar1 != 0) &&
        (lVar1 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x108))
                           (*(longlong **)(param_1 + 0x18),
                            *(undefined4 *)(lVar1 + 8 + (ulonglong)param_3 * 4)), lVar1 != 0)) &&
       (param_4 < 0xc)) &&
      ((param_2 < *(uint *)(*(longlong *)(param_1 + 8) + 0x310) && (param_3 < 6)))) &&
     (param_4 < *(uint *)(lVar1 + 4))) {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(lVar1 + 8 + uVar2 * 4);
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = *(undefined4 *)(lVar1 + 0x38 + uVar2 * 4);
    }
    if (param_7 != (longlong *)0x0) {
      uVar2 = *(ulonglong *)(lVar1 + 0x68 + uVar2 * 8);
      if ((uVar2 == 0) || (DAT_140c3fe70 < uVar2)) {
        *param_7 = 0;
        return 0;
      }
      *param_7 = DAT_140c3fe68 + uVar2;
    }
    return 0;
  }
  return 0x80070057;
}

