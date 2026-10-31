
undefined8 FUN_1405a4ce0(longlong param_1,int *param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = DAT_140c65898;
  iVar1 = FUN_1403bad30(DAT_140c65898,*(undefined4 *)(param_1 + 0x40),
                        *(undefined1 *)(DAT_140c65898 + 0x6dec));
  if (((iVar1 != 0) &&
      ((((*(longlong *)(lVar2 + 0x78) != 0 && (lVar2 != 0)) &&
        (lVar2 = FUN_1405a5b90(lVar2,iVar1), lVar2 != 0)) ||
       (lVar2 = FUN_1407a0fd0(DAT_140c65b70,iVar1), lVar2 != 0)))) &&
     (*(int *)(*(longlong *)(lVar2 + 0x70) + 0x194) != 0)) {
    iVar1 = FUN_1403a8000();
    if (iVar1 == 0) {
      return 1;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = iVar1;
    }
    return 2;
  }
  return 0;
}

