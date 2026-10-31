
undefined8 FUN_1405e96a0(longlong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  double *pdVar3;
  longlong lVar4;
  
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  if (((*(undefined4 **)(param_1 + 0x10) <= puVar2) || (puVar2 == &DAT_140a12138)) ||
     (puVar2[2] != 0)) {
    lVar4 = FUN_140056ab0(param_1,1,"Game.Spell");
    if ((lVar4 != 0) && (*(longlong *)(lVar4 + 8) != 0)) {
      lVar4 = FUN_1403acd90(DAT_140c65b70,*(undefined4 *)(*(longlong *)(lVar4 + 8) + 8),
                            *(undefined8 *)(DAT_140c65898 + 0x78));
      if (lVar4 != 0) {
        pdVar3 = *(double **)(param_1 + 0x10);
        iVar1 = *(int *)(*(longlong *)(lVar4 + 0x70) + 4);
        *(undefined4 *)(pdVar3 + 1) = 3;
        *pdVar3 = (double)iVar1;
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
        return 1;
      }
    }
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  return 1;
}

