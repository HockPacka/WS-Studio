
undefined8 FUN_1402ddc50(int param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  
  lVar7 = (longlong)param_1;
  if (param_4 == (undefined8 *)0x0) {
    uVar5 = 0x80070057;
  }
  else {
    puVar6 = (undefined8 *)FUN_14018b280(0x30);
    if (puVar6 == (undefined8 *)0x0) {
      uVar5 = 0x8007000e;
    }
    else {
      *(undefined4 *)(puVar6 + 1) = 1;
      *puVar6 = &PTR_FUN_140b62e18;
      puVar6[4] = 0;
      puVar6[3] = 0;
      puVar6[5] = 0;
      *(int *)((longlong)puVar6 + 0xc) = param_1;
      iVar1 = (&DAT_140c4135c)[lVar7 * 0xe];
      iVar2 = *(int *)(&DAT_140c41358 + lVar7 * 0x38);
      iVar3 = *(int *)(&DAT_140c41368 + lVar7 * 0x38);
      iVar4 = (&DAT_140c4136c)[lVar7 * 0xe];
      puVar6[3] = param_2;
      puVar6[4] = param_3;
      puVar6[2] = param_2 - (iVar2 * iVar3 + iVar1 * iVar4);
      (**(code **)*param_3)(param_3);
      *param_4 = puVar6;
      uVar5 = 0;
    }
  }
  return uVar5;
}

