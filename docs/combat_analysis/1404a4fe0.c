
bool FUN_1404a4fe0(undefined8 param_1,longlong param_2,int param_3,int param_4)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  
  if (param_2 == 0) {
    return false;
  }
  plVar1 = *(longlong **)(param_2 + 0x15d0);
  bVar2 = false;
  do {
    bVar4 = false;
    if (plVar1 == (longlong *)0x0) {
LAB_1404a5038:
      if ((param_3 != 1) && (bVar4 = false, param_3 == 2)) {
        return !bVar2;
      }
      return bVar4;
    }
    iVar3 = (**(code **)(*plVar1 + 0x30))(plVar1);
    if (iVar3 == param_4) {
      bVar2 = true;
      bVar4 = true;
      goto LAB_1404a5038;
    }
    plVar1 = (longlong *)plVar1[6];
  } while( true );
}

