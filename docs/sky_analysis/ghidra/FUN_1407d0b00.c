
undefined8 FUN_1407d0b00(longlong param_1,undefined4 *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  
  plVar1 = (longlong *)(param_1 + 0x19f0);
  uVar5 = (**(code **)(param_1 + 0x1a08))(param_2);
  puVar9 = *(ulonglong **)
            (*(longlong *)(param_1 + 0x1a00) + (uVar5 % *(ulonglong *)(param_1 + 0x19f8)) * 8);
  do {
    if (puVar9 == (ulonglong *)0x0) {
LAB_1407d0b5c:
      puVar6 = (ulonglong *)FUN_14018b280(0x20);
      puVar8 = (ulonglong *)0x0;
      puVar9 = puVar8;
      if (puVar6 != (ulonglong *)0x0) {
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[1] = 0;
        puVar9 = puVar6;
      }
      puVar6 = (ulonglong *)(param_1 + 0x1a18);
      if (puVar9[2] == 0) {
        puVar9[2] = (ulonglong)puVar6;
        puVar7 = puVar9 + 3;
        *puVar7 = *puVar6;
        *puVar6 = (ulonglong)puVar9;
        if (*puVar7 != 0) {
          *(ulonglong **)(*puVar7 + 0x10) = puVar7;
        }
      }
      if (*plVar1 == *(longlong *)(param_1 + 0x19f8)) {
        FUN_1400290d0(plVar1);
      }
      uVar5 = (**(code **)(param_1 + 0x1a08))(param_2);
      puVar6 = (ulonglong *)
               (*(longlong *)(param_1 + 0x1a00) + (uVar5 % *(ulonglong *)(param_1 + 0x19f8)) * 8);
      puVar7 = (ulonglong *)FUN_14018b280(0x20);
      if (puVar7 != (ulonglong *)0x0) {
        uVar3 = *puVar6;
        *puVar7 = uVar5;
        puVar7[1] = uVar3;
        uVar2 = *param_2;
        puVar7[3] = (ulonglong)puVar9;
        *(undefined4 *)(puVar7 + 2) = uVar2;
        puVar8 = puVar7;
      }
      *puVar6 = (ulonglong)puVar8;
      *plVar1 = *plVar1 + 1;
LAB_1407d0c1a:
      FUN_1403514f0(puVar9,param_2,&PTR_u_SkyCloudSet_140ad5fb8);
      return 0;
    }
    if ((uVar5 == *puVar9) &&
       (iVar4 = (**(code **)(param_1 + 0x1a10))(param_2,puVar9 + 2), iVar4 != 0)) {
      if (puVar9 + 3 != (ulonglong *)0x0) {
        puVar9 = (ulonglong *)puVar9[3];
        goto LAB_1407d0c1a;
      }
      goto LAB_1407d0b5c;
    }
    puVar9 = (ulonglong *)puVar9[1];
  } while( true );
}

