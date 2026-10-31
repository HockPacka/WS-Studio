
undefined8
FUN_1407d5f20(longlong param_1,uint *param_2,uint param_3,uint *param_4,uint *param_5,float *param_6
             )

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 == 0) {
    return 0;
  }
  if (param_3 == 1) {
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0.0;
    return 1;
  }
  uVar6 = 0;
  if (param_3 != 0) {
    uVar5 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0x520);
    puVar4 = param_2;
    do {
      if (uVar5 < *puVar4) break;
      uVar6 = uVar6 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar6 < param_3);
    uVar2 = uVar6;
    if (uVar6 != 0) goto LAB_1407d5fb1;
  }
  uVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x520) + 0x15180;
  uVar2 = param_3;
LAB_1407d5fb1:
  uVar2 = uVar2 - 1;
  uVar1 = param_2[uVar2];
  if (uVar6 == param_3) {
    uVar6 = 0;
  }
  uVar3 = param_2[uVar6] - uVar1;
  if (uVar6 < uVar2) {
    uVar3 = uVar3 + 0x15180;
  }
  *param_4 = uVar2;
  *param_5 = uVar6;
  *param_6 = (float)(uVar5 - uVar1) / (float)uVar3;
  return 2;
}

