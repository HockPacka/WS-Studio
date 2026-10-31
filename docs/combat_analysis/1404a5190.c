
void FUN_1404a5190(undefined8 param_1,longlong *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  if ((param_2 != (longlong *)0x0) && (param_3 != (undefined4 *)0x0)) {
    *(undefined4 *)param_2 = *param_3;
    uVar3 = 0;
    piVar2 = param_3 + 2;
    *(undefined4 *)((longlong)param_2 + 4) = param_3[1];
    do {
      param_2 = param_2 + 1;
      if (*piVar2 == 0) {
        return;
      }
      piVar1 = (int *)FUN_14018b280();
      if (piVar1 != (int *)0x0) {
        piVar1[0] = 0;
        piVar1[1] = 0;
        piVar1[2] = 0;
        piVar1[3] = 0;
      }
      *param_2 = (longlong)piVar1;
      uVar3 = uVar3 + 1;
      *piVar1 = *piVar2;
      *(int *)(*param_2 + 4) = piVar2[3];
      *(int *)(*param_2 + 8) = piVar2[6];
      piVar1 = piVar2 + 9;
      piVar2 = piVar2 + 1;
      *(int *)(*param_2 + 0xc) = *piVar1;
    } while (uVar3 < 3);
  }
  return;
}

