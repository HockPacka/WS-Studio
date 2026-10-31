
void FUN_1405a6580(longlong param_1)

{
  uint uVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined4 uVar6;
  int *piVar7;
  uint *puVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  bool bVar13;
  longlong local_res8;
  longlong local_res10;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  
  if (*(longlong *)(param_1 + 0x78) == 0) {
    uVar6 = 0x17;
  }
  else {
    uVar6 = *(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0xdc);
  }
  lVar3 = FUN_1401f31e0(uVar6);
  if (lVar3 == 0) {
    return;
  }
  lVar12 = 2;
  piVar7 = (int *)(lVar3 + 0x44);
  lVar10 = 0;
  bVar13 = true;
  lVar9 = 2;
  lVar11 = DAT_140c65898;
  do {
    lVar4 = *(longlong *)(param_1 + 0x78);
    if (*piVar7 != 0) {
      if (lVar4 == 0) {
LAB_1405a6633:
        lVar4 = FUN_1407a0fd0(DAT_140c65b70);
        lVar11 = DAT_140c65898;
        if (lVar4 == 0) goto LAB_1405a6677;
      }
      else {
        bVar2 = bVar13;
        if (*(longlong *)(lVar11 + 0x78) != lVar4) {
          bVar2 = *(longlong *)(lVar11 + 0x6490) == lVar4;
        }
        lVar4 = lVar10;
        if (bVar2) {
          lVar4 = lVar11;
        }
        if ((lVar4 == 0) || (lVar4 = FUN_1405a5b90(), lVar4 == 0)) goto LAB_1405a6633;
      }
      local_48 = 0x405a5c90;
      uStack_44 = 1;
      uStack_40 = 0;
      FUN_1405a5fe0(param_1,lVar4,&local_48);
      lVar11 = DAT_140c65898;
    }
LAB_1405a6677:
    piVar7 = piVar7 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  puVar8 = (uint *)(lVar3 + 0x4c);
  do {
    uVar1 = *puVar8;
    lVar9 = *(longlong *)(param_1 + 0x78);
    if (uVar1 != 0) {
      if (lVar9 == 0) {
LAB_1405a6734:
        lVar9 = FUN_1407a0fd0(DAT_140c65b70);
        lVar11 = DAT_140c65898;
        if (lVar9 == 0) goto LAB_1405a6778;
      }
      else {
        bVar2 = bVar13;
        if (*(longlong *)(lVar11 + 0x78) != lVar9) {
          bVar2 = *(longlong *)(lVar11 + 0x6490) == lVar9;
        }
        lVar9 = lVar10;
        if (bVar2) {
          lVar9 = lVar11;
        }
        if (lVar9 == 0) goto LAB_1405a6734;
        lVar11 = *(longlong *)(lVar9 + 0x7d18);
        lVar4 = lVar11;
        lVar9 = *(longlong *)(lVar11 + 8);
        while (lVar9 != 0) {
          if (*(uint *)(lVar9 + 0x20) < uVar1) {
            lVar9 = *(longlong *)(lVar9 + 0x18);
          }
          else {
            lVar4 = lVar9;
            lVar9 = *(longlong *)(lVar9 + 0x10);
          }
        }
        if ((lVar4 == lVar11) || (uVar1 < *(uint *)(lVar4 + 0x20))) {
          local_res10 = lVar11;
          plVar5 = &local_res10;
        }
        else {
          local_res8 = lVar4;
          plVar5 = &local_res8;
        }
        if ((*plVar5 == lVar11) || (lVar9 = *(longlong *)(*plVar5 + 0x28), lVar9 == 0))
        goto LAB_1405a6734;
      }
      local_48 = 0x405a5c90;
      uStack_44 = 1;
      uStack_40 = 0;
      FUN_1405a5fe0(param_1,lVar9,&local_48);
      lVar11 = DAT_140c65898;
    }
LAB_1405a6778:
    puVar8 = puVar8 + 1;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  uVar1 = *(uint *)(lVar3 + 0x54);
  lVar3 = *(longlong *)(param_1 + 0x78);
  if (uVar1 == 0) {
    return;
  }
  if (lVar3 != 0) {
    if (*(longlong *)(lVar11 + 0x78) != lVar3) {
      bVar13 = *(longlong *)(lVar11 + 0x6490) == lVar3;
    }
    if (bVar13) {
      lVar10 = lVar11;
    }
    if (lVar10 != 0) {
      lVar3 = *(longlong *)(lVar10 + 0x7d18);
      local_res8 = lVar3;
      lVar10 = *(longlong *)(lVar3 + 8);
      while (lVar10 != 0) {
        if (*(uint *)(lVar10 + 0x20) < uVar1) {
          lVar10 = *(longlong *)(lVar10 + 0x18);
        }
        else {
          local_res8 = lVar10;
          lVar10 = *(longlong *)(lVar10 + 0x10);
        }
      }
      if ((local_res8 == lVar3) || (uVar1 < *(uint *)(local_res8 + 0x20))) {
        local_res8 = lVar3;
      }
      if ((local_res8 != lVar3) && (lVar3 = *(longlong *)(local_res8 + 0x28), lVar3 != 0))
      goto LAB_1405a683b;
    }
  }
  lVar3 = FUN_1407a0fd0(DAT_140c65b70);
  if (lVar3 == 0) {
    return;
  }
LAB_1405a683b:
  local_48 = 0x405a5c90;
  uStack_44 = 1;
  uStack_40 = 0;
  FUN_1405a5fe0(param_1,lVar3,&local_48);
  return;
}

