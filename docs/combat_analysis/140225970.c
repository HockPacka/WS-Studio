
undefined8 FUN_140225970(void)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_140c63838 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000140225992. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*DAT_140c63838)(&PTR_u_Prerequisite_140a6c2e0,DAT_140c63858);
    return uVar2;
  }
  if (DAT_140c647d0 == 0) {
    iVar1 = FUN_140225760();
    if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x0001402259bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*DAT_140c64208 + 0x28))();
      return uVar2;
    }
  }
  return 0;
}

