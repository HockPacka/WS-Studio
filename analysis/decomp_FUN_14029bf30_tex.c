
void FUN_14029bf30(longlong param_1)

{
  int iVar1;
  LPVOID pvVar2;
  int *piVar3;
  longlong *plVar4;
  
  if (DAT_140c63758 == 0) {
LAB_14029bf62:
    plVar4 = (longlong *)0x0;
  }
  else {
    pvVar2 = TlsGetValue(*(DWORD *)(DAT_140c63758 + 4));
    if ((pvVar2 == (LPVOID)0x0) || (*(longlong *)((longlong)pvVar2 + 8) == 0)) goto LAB_14029bf62;
    plVar4 = *(longlong **)(*(longlong *)((longlong)pvVar2 + 8) + 0x60);
  }
  iVar1 = (**(code **)(*plVar4 + 0x28))(plVar4,0);
  if (iVar1 < 0) {
    FUN_14029c120(param_1,iVar1);
    return;
  }
  piVar3 = (int *)(**(code **)(**(longlong **)(param_1 + 0x40) + 0x20))();
  if ((*piVar3 == 0x474658) && (piVar3[1] == 3)) {
    if ((piVar3[4] == 1) && (piVar3[5] == 1)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else if (piVar3[5] == 1) {
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    else {
      if (((piVar3[2] != piVar3[3]) || (piVar3[4] != 1)) || (piVar3[5] != 6)) goto LAB_14029c02a;
      *(undefined4 *)(param_1 + 0x18) = 2;
    }
    *(int *)(param_1 + 0x1c) = piVar3[2];
    *(int *)(param_1 + 0x20) = piVar3[3];
    *(int *)(param_1 + 0x24) = piVar3[4];
    *(int *)(param_1 + 0x28) = piVar3[6];
    if (piVar3[8] == 0) {
      *(int *)(param_1 + 0x2c) = piVar3[7];
      FUN_14029c120(param_1,0);
      return;
    }
    if (piVar3[8] == 1) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
      FUN_14029c120(param_1);
      return;
    }
  }
LAB_14029c02a:
  FUN_14029c120(param_1,0x80004005);
  return;
}

