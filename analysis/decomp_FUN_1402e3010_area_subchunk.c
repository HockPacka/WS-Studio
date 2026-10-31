
undefined8
FUN_1402e3010(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  if (param_4 == (undefined8 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = (undefined8 *)FUN_14018b280(0x28);
    if (puVar2 == (undefined8 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      *(undefined4 *)(puVar2 + 1) = 1;
      *puVar2 = &PTR_FUN_140b63120;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      if (param_3 == (undefined8 *)0x0) {
        FUN_1402e2c80(puVar2);
        uVar1 = 0x80070057;
      }
      else {
        puVar2[2] = param_2;
        puVar2[3] = param_1;
        puVar2[4] = param_3;
        (**(code **)*param_3)(param_3);
        *param_4 = puVar2;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

