
undefined8 FUN_140350b90(longlong param_1,undefined4 param_2)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 local_res10 [2];
  
  local_res10[0] = param_2;
  uVar3 = (**(code **)(param_1 + 0x378))(local_res10);
  puVar1 = *(ulonglong **)
            (*(longlong *)(param_1 + 0x370) + (uVar3 % *(ulonglong *)(param_1 + 0x368)) * 8);
  do {
    if (puVar1 == (ulonglong *)0x0) {
LAB_140350bf1:
      uVar4 = FUN_14024bdc0(local_res10[0]);
      return uVar4;
    }
    if ((uVar3 == *puVar1) &&
       (iVar2 = (**(code **)(param_1 + 0x380))(local_res10,puVar1 + 2), iVar2 != 0)) {
      if (puVar1 + 3 != (ulonglong *)0x0) {
        return *(undefined8 *)(puVar1[3] + 8);
      }
      goto LAB_140350bf1;
    }
    puVar1 = (ulonglong *)puVar1[1];
  } while( true );
}

