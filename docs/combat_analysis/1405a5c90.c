
void FUN_1405a5c90(longlong param_1,short *param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  short *local_res10;
  longlong *local_res18;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  if ((param_2 != (short *)0x0) && (*param_2 != 0)) {
    plVar1 = (longlong *)(param_1 + 0x6d48);
    local_res10 = param_2;
    uVar5 = (**(code **)(param_1 + 28000))(&local_res10);
    for (puVar7 = *(ulonglong **)
                   (*(longlong *)(param_1 + 0x6d58) + (uVar5 % *(ulonglong *)(param_1 + 0x6d50)) * 8
                   ); puVar7 != (ulonglong *)0x0; puVar7 = (ulonglong *)puVar7[1]) {
      if ((uVar5 == *puVar7) &&
         (iVar4 = (**(code **)(param_1 + 0x6d68))(&local_res10,puVar7 + 2), iVar4 != 0)) {
        if (puVar7 + 3 != (ulonglong *)0x0) {
          (*(code *)**(undefined8 **)puVar7[3])();
          return;
        }
        break;
      }
    }
    iVar4 = (**(code **)(**(longlong **)(param_1 + 0x7250) + 0x28))
                      (*(longlong **)(param_1 + 0x7250),local_res10,&local_res18,0);
    plVar3 = local_res18;
    if (-1 < iVar4) {
      puVar6 = (ulonglong *)FUN_14018b280(0x28);
      puVar7 = (ulonglong *)0x0;
      puVar10 = puVar7;
      if (puVar6 != (ulonglong *)0x0) {
        *puVar6 = (ulonglong)&PTR_FUN_140b6cfe0;
        puVar6[3] = 0;
        puVar6[4] = 0;
        *(undefined4 *)(puVar6 + 1) = 1;
        puVar6[2] = (ulonglong)plVar3;
        (**(code **)*plVar3)(plVar3);
        puVar10 = puVar6;
      }
      if (*plVar1 == *(longlong *)(param_1 + 0x6d50)) {
        FUN_1400290d0(plVar1);
      }
      uVar5 = (**(code **)(param_1 + 28000))(&local_res10);
      lVar8 = *(longlong *)(param_1 + 0x6d58);
      uVar9 = uVar5 % *(ulonglong *)(param_1 + 0x6d50);
      puVar6 = (ulonglong *)FUN_14018b280(0x20);
      if (puVar6 != (ulonglong *)0x0) {
        uVar2 = *(ulonglong *)(lVar8 + uVar9 * 8);
        *puVar6 = uVar5;
        puVar6[1] = uVar2;
        puVar6[3] = (ulonglong)puVar10;
        puVar6[2] = (ulonglong)local_res10;
        puVar7 = puVar6;
      }
      *(ulonglong **)(lVar8 + uVar9 * 8) = puVar7;
      *plVar1 = *plVar1 + 1;
      lVar8 = (**(code **)(**(longlong **)(param_1 + 0x7248) + 0x48))();
      local_38 = *(undefined4 *)(lVar8 + 0x20);
      local_30 = 0;
      local_34 = *(undefined4 *)(lVar8 + 0x24);
      (**(code **)(*local_res18 + 0xf0))(local_res18,&local_38);
      local_38 = 0;
      iVar4 = (**(code **)(*local_res18 + 0x18))(local_res18,&local_38,0);
      if ((iVar4 == 0) && (puVar7 = (ulonglong *)(param_1 + 0x6d70), puVar10[3] == 0)) {
        puVar10[3] = (ulonglong)puVar7;
        puVar6 = puVar10 + 4;
        *puVar6 = *puVar7;
        *puVar7 = (ulonglong)puVar10;
        if (*puVar6 != 0) {
          *(ulonglong **)(*puVar6 + 0x18) = puVar6;
        }
      }
      if (local_res18 != (longlong *)0x0) {
        (**(code **)(*local_res18 + 8))();
      }
    }
  }
  return;
}

