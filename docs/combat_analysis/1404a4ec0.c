
bool FUN_1404a4ec0(undefined8 param_1,longlong param_2,int param_3,int param_4)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  
  if (param_2 == 0) {
    return false;
  }
  lVar1 = *(longlong *)(param_2 + 0x15c8);
  bVar2 = false;
  do {
    bVar4 = false;
    if (lVar1 == 0) {
LAB_1404a4f19:
      if ((param_3 != 1) && (bVar4 = false, param_3 == 2)) {
        return !bVar2;
      }
      return bVar4;
    }
    iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x38) + 8))();
    if (iVar3 == param_4) {
      bVar2 = true;
      bVar4 = true;
      goto LAB_1404a4f19;
    }
    lVar1 = *(longlong *)(lVar1 + 0x18);
  } while( true );
}

