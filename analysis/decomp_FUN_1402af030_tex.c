
longlong * FUN_1402af030(longlong param_1)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  LPVOID pvVar5;
  longlong lVar6;
  undefined *puVar7;
  longlong *plVar8;
  int *piVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  longlong lVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  longlong *plVar18;
  longlong *local_res10;
  longlong *local_res18 [2];
  undefined8 in_stack_ffffffffffffff80;
  undefined4 uVar19;
  longlong local_78;
  code *local_70;
  undefined4 local_68;
  undefined4 local_64;
  longlong local_60;
  code *local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  plVar18 = (longlong *)0x0;
  plVar8 = plVar18;
  if (((DAT_140c63758 != 0) &&
      (pvVar5 = TlsGetValue(*(DWORD *)(DAT_140c63758 + 4)), pvVar5 != (LPVOID)0x0)) &&
     (*(longlong *)((longlong)pvVar5 + 8) != 0)) {
    plVar8 = *(longlong **)(*(longlong *)((longlong)pvVar5 + 8) + 0x60);
  }
  iVar4 = (**(code **)(*plVar8 + 0x28))();
  if (iVar4 < 0) {
    if ((*(longlong **)(param_1 + 0x158) == (longlong *)0x0) ||
       (lVar6 = (**(code **)(**(longlong **)(param_1 + 0x158) + 0x10))(), lVar6 == 0)) {
      puVar7 = &DAT_1409e4254;
    }
    else {
      puVar7 = (undefined *)(**(code **)(**(longlong **)(param_1 + 0x158) + 0x10))();
    }
    local_res18[0] = (longlong *)0x141de7160;
    FUN_1401a3130(0xe,2,local_res18,iVar4,puVar7,CONCAT44(uVar19,(uint)(iVar4 == -0x7ff8fff2)));
    plVar8 = (longlong *)FUN_1402b1940(param_1,iVar4);
    return plVar8;
  }
  piVar9 = (int *)(**(code **)(**(longlong **)(param_1 + 0x160) + 0x20))();
  if ((((*piVar9 != 0x474658) || (piVar9[1] != 3)) ||
      ((*(int *)(param_1 + 0x48) == 2 && ((piVar9[2] != piVar9[3] || (piVar9[5] != 6)))))) ||
     (iVar4 = piVar9[6], iVar4 == 0)) {
LAB_1402af64e:
    plVar8 = (longlong *)FUN_1402b1940(param_1,0x80004005);
    return plVar8;
  }
  uVar1 = piVar9[2];
  uVar17 = iVar4 - 1;
  bVar15 = (byte)uVar17;
  if ((((uVar1 >> (bVar15 & 0x1f) == 0) && ((uint)piVar9[3] >> (bVar15 & 0x1f) == 0)) &&
      ((uint)piVar9[4] >> (bVar15 & 0x1f) == 0)) ||
     ((1 < (uint)piVar9[8] || (uVar16 = piVar9[7], 0x1a < uVar16)))) goto LAB_1402af64e;
  lVar6 = (longlong)(int)uVar16 * 0x2c;
  if (1 < (uint)(&DAT_140ae5200)[(longlong)(int)uVar16 * 0xb]) {
    uVar10 = (ulonglong)uVar1 / (ulonglong)(uint)(&DAT_140ae5200)[(longlong)(int)uVar16 * 0xb];
    if ((int)uVar10 == 0) {
      bVar15 = 0xff;
    }
    else {
      bVar15 = 0;
      if ((short)uVar10 == 0) {
        bVar15 = 0x10;
        uVar10 = uVar10 >> 0x10;
      }
      if ((char)uVar10 == '\0') {
        bVar15 = bVar15 + 8;
        uVar10 = uVar10 >> 8;
      }
      if ((uVar10 & 0xf) == 0) {
        bVar15 = bVar15 + 4;
        uVar10 = uVar10 >> 4;
      }
      if ((uVar10 & 3) == 0) {
        bVar15 = bVar15 + 2;
        uVar10 = uVar10 >> 2;
      }
      if ((uVar10 & 1) == 0) {
        bVar15 = bVar15 + 1;
      }
    }
    if (bVar15 < uVar17) {
      uVar17 = (uint)bVar15;
    }
  }
  if (1 < *(uint *)(&DAT_140ae520c + lVar6)) {
    uVar10 = (ulonglong)(uint)piVar9[3] / (ulonglong)*(uint *)(&DAT_140ae520c + lVar6);
    if ((int)uVar10 == 0) {
      uVar16 = 0xff;
    }
    else {
      uVar16 = 0;
      if ((short)uVar10 == 0) {
        uVar16 = 0x10;
        uVar10 = uVar10 >> 0x10;
      }
      if ((char)uVar10 == '\0') {
        uVar16 = (uint)(byte)((char)uVar16 + 8);
        uVar10 = uVar10 >> 8;
      }
      if ((uVar10 & 0xf) == 0) {
        uVar16 = (uint)(byte)((char)uVar16 + 4);
        uVar10 = uVar10 >> 4;
      }
      if ((uVar10 & 3) == 0) {
        uVar16 = (uint)(byte)((char)uVar16 + 2);
        uVar10 = uVar10 >> 2;
      }
      if ((uVar10 & 1) == 0) {
        uVar16 = (uint)(byte)((char)uVar16 + 1);
      }
    }
    if (uVar16 < uVar17) {
      uVar17 = uVar16;
    }
  }
  if (1 < *(uint *)(&DAT_140ae5218 + lVar6)) {
    uVar10 = (ulonglong)(uint)piVar9[4] / (ulonglong)*(uint *)(&DAT_140ae5218 + lVar6);
    if ((int)uVar10 == 0) {
      bVar15 = 0xff;
    }
    else {
      bVar15 = 0;
      if ((short)uVar10 == 0) {
        bVar15 = 0x10;
        uVar10 = uVar10 >> 0x10;
      }
      if ((char)uVar10 == '\0') {
        bVar15 = bVar15 + 8;
        uVar10 = uVar10 >> 8;
      }
      if ((uVar10 & 0xf) == 0) {
        bVar15 = bVar15 + 4;
        uVar10 = uVar10 >> 4;
      }
      if ((uVar10 & 3) == 0) {
        bVar15 = bVar15 + 2;
        uVar10 = uVar10 >> 2;
      }
      if ((uVar10 & 1) == 0) {
        bVar15 = bVar15 + 1;
      }
    }
    if (bVar15 < uVar17) {
      uVar17 = (uint)bVar15;
    }
  }
  uVar16 = *(uint *)(param_1 + 0x4c);
  if (uVar17 < *(uint *)(param_1 + 0x4c)) {
    uVar16 = uVar17;
  }
  bVar15 = (byte)uVar16;
  piVar9[2] = (uint)(uVar1 >> (bVar15 & 0x1f) == 0) + (uVar1 >> (bVar15 & 0x1f));
  piVar9[3] = (uint)((uint)piVar9[3] >> (bVar15 & 0x1f) == 0) + ((uint)piVar9[3] >> (bVar15 & 0x1f))
  ;
  uVar17 = (uint)piVar9[4] >> (bVar15 & 0x1f);
  piVar9[6] = iVar4 - uVar16;
  piVar9[4] = (uVar17 == 0) + uVar17;
  *(int *)(param_1 + 0x60) = piVar9[8];
  *(int *)(param_1 + 100) = piVar9[0x1a];
  uVar10 = FUN_14029bdc0(piVar9);
  uVar11 = (**(code **)(**(longlong **)(param_1 + 0x158) + 0x18))();
  if (uVar11 < uVar10) {
    plVar8 = (longlong *)FUN_1402b1940(param_1,0x80004005);
    return plVar8;
  }
  local_res18[0] = (longlong *)0x0;
  iVar4 = FUN_1401c5690(uVar10,local_res18,8);
  plVar8 = local_res18[0];
  if (iVar4 < 0) {
    if ((*(longlong **)(param_1 + 0x158) == (longlong *)0x0) ||
       (lVar6 = (**(code **)(**(longlong **)(param_1 + 0x158) + 0x10))(), lVar6 == 0)) {
      puVar7 = &DAT_1409e41fc;
    }
    else {
      puVar7 = (undefined *)(**(code **)(**(longlong **)(param_1 + 0x158) + 0x10))();
    }
    local_res18[0] = (longlong *)0x141de7140;
    FUN_1401a3130(0xe,2,local_res18,iVar4,uVar10,puVar7);
    uVar17 = FUN_1402b1940(param_1,iVar4);
    plVar18 = (longlong *)(ulonglong)uVar17;
    goto LAB_1402af630;
  }
  puVar12 = (undefined8 *)(**(code **)(*local_res18[0] + 0x20))(local_res18[0]);
  *puVar12 = *(undefined8 *)piVar9;
  puVar12[1] = *(undefined8 *)(piVar9 + 2);
  puVar12[2] = *(undefined8 *)(piVar9 + 4);
  puVar12[3] = *(undefined8 *)(piVar9 + 6);
  puVar12[4] = *(undefined8 *)(piVar9 + 8);
  puVar12[5] = *(undefined8 *)(piVar9 + 10);
  puVar12[6] = *(undefined8 *)(piVar9 + 0xc);
  puVar12[7] = *(undefined8 *)(piVar9 + 0xe);
  puVar12[8] = *(undefined8 *)(piVar9 + 0x10);
  puVar12[9] = *(undefined8 *)(piVar9 + 0x12);
  puVar12[10] = *(undefined8 *)(piVar9 + 0x14);
  puVar12[0xb] = *(undefined8 *)(piVar9 + 0x16);
  puVar12[0xc] = *(undefined8 *)(piVar9 + 0x18);
  puVar12[0xd] = *(undefined8 *)(piVar9 + 0x1a);
  if (*(longlong **)(param_1 + 0x160) != plVar8) {
    (**(code **)*plVar8)(plVar8);
    if (*(longlong **)(param_1 + 0x160) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x160) + 8))();
    }
    *(longlong **)(param_1 + 0x160) = plVar8;
  }
  plVar2 = *(longlong **)(param_1 + 0x158);
  local_res10 = (longlong *)0x0;
  lVar3 = *plVar2;
  lVar13 = (**(code **)(*plVar8 + 0x10))(plVar8);
  lVar14 = (**(code **)(*plVar8 + 0x20))(plVar8);
  lVar6 = 0;
  iVar4 = (**(code **)(lVar3 + 0x50))(plVar2,lVar14 + 0x70,lVar13 + -0x70,&local_res10,0);
  plVar2 = *(longlong **)(param_1 + 0x158);
  if (iVar4 < 0) {
    if ((plVar2 == (longlong *)0x0) || (lVar6 = (**(code **)(*plVar2 + 0x10))(), lVar6 == 0)) {
      puVar7 = &DAT_1409e41bc;
    }
    else {
      puVar7 = (undefined *)(**(code **)(**(longlong **)(param_1 + 0x158) + 0x10))();
    }
    local_res18[0] = (longlong *)0x141de7128;
    FUN_1401a3130(0xe,2,local_res18,iVar4,puVar7);
LAB_1402af616:
    uVar17 = FUN_1402b1940(param_1,iVar4);
    plVar18 = (longlong *)(ulonglong)uVar17;
  }
  else {
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 8))();
      *(undefined8 *)(param_1 + 0x158) = 0;
    }
    if (piVar9[8] == 0) {
      local_70 = FUN_1402af660;
      lVar6 = param_1 + 400;
      local_78 = param_1;
      iVar4 = FUN_140279d70(*(undefined8 *)(param_1 + 0x38),&local_78);
      if (iVar4 < 0) {
        local_res18[0] = (longlong *)0x141de7118;
LAB_1402af5a3:
        FUN_1401a3130(0xe,2,local_res18,iVar4,lVar6);
        goto LAB_1402af616;
      }
    }
    else {
      if (piVar9[8] != 1) {
        iVar4 = -0x7fffbffb;
        goto LAB_1402af616;
      }
      local_58 = FUN_1402affc0;
      local_68 = 0xc;
      local_64 = 2;
      local_50 = 0;
      local_48 = 1;
      local_60 = param_1;
      iVar4 = FUN_14019dca0(&local_68,0,local_res10,param_1 + 0x180);
      if (iVar4 < 0) {
        local_res18[0] = (longlong *)0x141de7108;
        goto LAB_1402af5a3;
      }
    }
  }
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 8))();
  }
LAB_1402af630:
  if (plVar8 == (longlong *)0x0) {
    return plVar18;
  }
  (**(code **)(*plVar8 + 8))(plVar8);
  return plVar18;
}

