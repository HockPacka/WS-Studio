
ulonglong FUN_1404a5440(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  ulonglong *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 local_res10 [2];
  
  lVar1 = *(longlong *)(param_1 + 8);
  local_res10[0] = param_2;
  uVar4 = (**(code **)(lVar1 + 0x18))(local_res10);
  puVar2 = *(ulonglong **)(*(longlong *)(lVar1 + 0x10) + (uVar4 % *(ulonglong *)(lVar1 + 8)) * 8);
  while( true ) {
    if (puVar2 == (ulonglong *)0x0) {
      return 0;
    }
    if ((uVar4 == *puVar2) &&
       (iVar3 = (**(code **)(lVar1 + 0x20))(local_res10,puVar2 + 2), iVar3 != 0)) break;
    puVar2 = (ulonglong *)puVar2[1];
  }
  if (puVar2 + 3 == (ulonglong *)0x0) {
    return 0;
  }
  return puVar2[3];
}

