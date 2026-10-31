
undefined8 FUN_1403729c0(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  lVar2 = FUN_140350b90(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),
                        *(undefined4 *)(param_1 + 0x20));
  if (lVar2 != 0) {
    lVar4 = 0;
    if (*(longlong **)(param_1 + 0x30) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x30) + 8))();
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
    if (*(longlong **)(param_1 + 0x28) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x28) + 8))();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
    uVar1 = *(ulonglong *)(lVar2 + 8);
    if ((uVar1 != 0) && (uVar1 <= DAT_140c3fe70)) {
      lVar4 = DAT_140c3fe68 + uVar1;
    }
    uVar3 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x18))
                      (*(longlong **)(param_1 + 0x18),lVar4,param_1 + 0x28);
    if (-1 < (int)uVar3) {
      (**(code **)(**(longlong **)(param_1 + 0x28) + 0x28))();
      FUN_1401b6bf0();
      uVar3 = 0;
      *(int *)(param_1 + 0x38) = *(int *)(*(longlong *)(param_1 + 0x10) + 0x350) + -1;
    }
    return uVar3;
  }
  return 0x80004005;
}

