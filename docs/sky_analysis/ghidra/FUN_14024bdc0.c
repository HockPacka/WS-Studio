
undefined8 FUN_14024bdc0(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (DAT_140c63840 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00014024bde9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*DAT_140c63840)(&PTR_u_WorldSky_140a6e260,param_1,DAT_140c63858);
    return uVar2;
  }
  if (DAT_140c649d8 == 0) {
    iVar1 = FUN_14024bb60();
    if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x00014024be17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*DAT_140c64cd0 + 0x18))(DAT_140c64cd0,param_1);
      return uVar2;
    }
  }
  return 0;
}

