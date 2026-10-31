
undefined8 FUN_140225a20(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_140c63848 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140225a49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*DAT_140c63848)(&PTR_u_Prerequisite_140a6c2e0,param_1,DAT_140c63858);
    return uVar2;
  }
  if (DAT_140c647d0 == 0) {
    iVar1 = FUN_140225760();
    if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x000140225a77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*DAT_140c64208 + 0x20))(DAT_140c64208,param_1);
      return uVar2;
    }
  }
  return 0;
}

