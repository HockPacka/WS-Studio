
longlong * FUN_140298f20(longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
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
  byte bVar14;
  uint uVar15;
  uint uVar16;
  longlong *plVar17;
  longlong *local_res10;
  longlong *local_res18;
  ulonglong local_res20;
  undefined4 local_68;
  undefined4 local_64;
  longlong local_60;
  code *local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  plVar17 = (longlong *)0x0;
  plVar8 = plVar17;
  if (((DAT_140c63758 != 0) &&
      (pvVar5 = TlsGetValue(*(DWORD *)(DAT_140c63758 + 4)), pvVar5 != (LPVOID)0x0)) &&
     (*(longlong *)((longlong)pvVar5 + 8) != 0)) {
    plVar8 = *(longlong **)(*(longlong *)((longlong)pvVar5 + 8) + 0x60);
  }
  iVar4 = (**(code **)(*plVar8 + 0x28))();
  if (iVar4 < 0) {
    if ((*(longlong **)(param_1 + 0x60) == (longlong *)0x0) ||
       (lVar6 = (**(code **)(**(longlong **)(param_1 + 0x60) + 0x10))(), lVar6 == 0)) {
      puVar7 = &DAT_1409e40fc;
    }
    else {
      puVar7 = (undefined *)(**(code **)(**(longlong **)(param_1 + 0x60) + 0x10))();
    }
    local_res18 = (longlong *)0x141de4358;
    FUN_1401a3130(0xe,2,&local_res18,iVar4,puVar7,iVar4 == -0x7ff8fff2);
    plVar8 = (longlong *)FUN_14029b080(param_1,iVar4);
    return plVar8;
  }
  piVar9 = (int *)(**(code **)(**(longlong **)(param_1 + 0x68) + 0x20))();
  if ((((*piVar9 != 0x474658) || (piVar9[1] != 3)) ||
      ((*(int *)(param_1 + 0x40) == 2 && ((piVar9[2] != piVar9[3] || (piVar9[5] != 6)))))) ||
     (iVar4 = piVar9[6], iVar4 == 0)) {
LAB_1402994a0:
    plVar8 = (longlong *)FUN_14029b080(param_1,0x80004005);
    return plVar8;
  }
  uVar1 = piVar9[2];
  uVar16 = iVar4 - 1;
  bVar14 = (byte)uVar16;
  if ((((uVar1 >> (bVar14 & 0x1f) == 0) && ((uint)piVar9[3] >> (bVar14 & 0x1f) == 0)) &&
      ((uint)piVar9[4] >> (bVar14 & 0x1f) == 0)) || (iVar2 = piVar9[7], 0x1a < iVar2))
  goto LAB_1402994a0;
  lVar6 = (longlong)iVar2 * 0x2c;
  if (1 < (uint)(&DAT_140ae5200)[(longlong)iVar2 * 0xb]) {
    uVar10 = (ulonglong)uVar1 / (ulonglong)(uint)(&DAT_140ae5200)[(longlong)iVar2 * 0xb];
    if ((int)uVar10 == 0) {
      bVar14 = 0xff;
    }
    else {
      bVar14 = 0;
      if ((short)uVar10 == 0) {
        bVar14 = 0x10;
        uVar10 = uVar10 >> 0x10;
      }
      if ((char)uVar10 == '\0') {
        bVar14 = bVar14 + 8;
        uVar10 = uVar10 >> 8;
      }
      if ((uVar10 & 0xf) == 0) {
        bVar14 = bVar14 + 4;
        uVar10 = uVar10 >> 4;
      }
      if ((uVar10 & 3) == 0) {
        bVar14 = bVar14 + 2;
        uVar10 = uVar10 >> 2;
      }
      if ((uVar10 & 1) == 0) {
        bVar14 = bVar14 + 1;
      }
    }
    if (bVar14 < uVar16) {
      uVar16 = (uint)bVar14;
    }
  }
  if (1 < *(uint *)(&DAT_140ae520c + lVar6)) {
    uVar10 = (ulonglong)(uint)piVar9[3] / (ulonglong)*(uint *)(&DAT_140ae520c + lVar6);
    if ((int)uVar10 == 0) {
      uVar15 = 0xff;
    }
    else {
      uVar15 = 0;
      if ((short)uVar10 == 0) {
        uVar15 = 0x10;
        uVar10 = uVar10 >> 0x10;
      }
      if ((char)uVar10 == '\0') {
        uVar15 = (uint)(byte)((char)uVar15 + 8);
        uVar10 = uVar10 >> 8;
      }
      if ((uVar10 & 0xf) == 0) {
        uVar15 = (uint)(byte)((char)uVar15 + 4);
        uVar10 = uVar10 >> 4;
      }
      if ((uVar10 & 3) == 0) {
        uVar15 = (uint)(byte)((char)uVar15 + 2);
        uVar10 = uVar10 >> 2;
      }
      if ((uVar10 & 1) == 0) {
        uVar15 = (uint)(byte)((char)uVar15 + 1);
      }
    }
    if (uVar15 < uVar16) {
      uVar16 = uVar15;
    }
  }
  if (1 < *(uint *)(&DAT_140ae5218 + lVar6)) {
    uVar10 = (ulonglong)(uint)piVar9[4] / (ulonglong)*(uint *)(&DAT_140ae5218 + lVar6);
    if ((int)uVar10 == 0) {
      bVar14 = 0xff;
    }
    else {
      bVar14 = 0;
      if ((short)uVar10 == 0) {
        bVar14 = 0x10;
        uVar10 = uVar10 >> 0x10;
      }
      if ((char)uVar10 == '\0') {
        bVar14 = bVar14 + 8;
        uVar10 = uVar10 >> 8;
      }
      if ((uVar10 & 0xf) == 0) {
        bVar14 = bVar14 + 4;
        uVar10 = uVar10 >> 4;
      }
      if ((uVar10 & 3) == 0) {
        bVar14 = bVar14 + 2;
        uVar10 = uVar10 >> 2;
      }
      if ((uVar10 & 1) == 0) {
        bVar14 = bVar14 + 1;
      }
    }
    if (bVar14 < uVar16) {
      uVar16 = (uint)bVar14;
    }
  }
  uVar15 = *(uint *)(param_1 + 0x44);
  if (uVar16 < *(uint *)(param_1 + 0x44)) {
    uVar15 = uVar16;
  }
  bVar14 = (byte)uVar15;
  piVar9[2] = (uint)(uVar1 >> (bVar14 & 0x1f) == 0) + (uVar1 >> (bVar14 & 0x1f));
  piVar9[3] = (uint)((uint)piVar9[3] >> (bVar14 & 0x1f) == 0) + ((uint)piVar9[3] >> (bVar14 & 0x1f))
  ;
  uVar16 = (uint)piVar9[4] >> (bVar14 & 0x1f);
  piVar9[6] = iVar4 - uVar15;
  piVar9[4] = (uVar16 == 0) + uVar16;
  *(int *)(param_1 + 0x54) = piVar9[8];
  *(int *)(param_1 + 0x58) = piVar9[0x1a];
  uVar10 = FUN_14029bdc0(piVar9);
  local_res20 = uVar10;
  uVar11 = (**(code **)(**(longlong **)(param_1 + 0x60) + 0x18))();
  if (uVar11 < uVar10) {
    plVar8 = (longlong *)FUN_14029b080(param_1,0x80004005);
    return plVar8;
  }
  local_res18 = (longlong *)0x0;
  iVar4 = FUN_1401c5690(uVar10,&local_res18,8);
  plVar8 = local_res18;
  if (iVar4 < 0) {
    local_res18 = (longlong *)0x141de41e8;
    FUN_1401a3130(0xe,2,&local_res18,iVar4,uVar10);
    uVar16 = FUN_14029b080(param_1,iVar4);
    plVar17 = (longlong *)(ulonglong)uVar16;
    goto LAB_140299485;
  }
  puVar12 = (undefined8 *)(**(code **)(*local_res18 + 0x20))(local_res18);
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
  if (*(longlong **)(param_1 + 0x68) != plVar8) {
    (**(code **)*plVar8)(plVar8);
    if (*(longlong **)(param_1 + 0x68) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x68) + 8))();
    }
    *(longlong **)(param_1 + 0x68) = plVar8;
  }
  uVar10 = local_res20;
  plVar3 = *(longlong **)(param_1 + 0x60);
  local_res10 = (longlong *)0x0;
  lVar6 = *plVar3;
  lVar13 = (**(code **)(**(longlong **)(param_1 + 0x68) + 0x20))();
  iVar4 = (**(code **)(lVar6 + 0x50))(plVar3,lVar13 + 0x70,uVar10 - 0x70,&local_res10,0);
  if (iVar4 < 0) {
    local_res18 = (longlong *)0x141de43e8;
LAB_140299386:
    FUN_1401a3130(0xe,2,&local_res18,iVar4);
LAB_14029946b:
    uVar16 = FUN_14029b080(param_1,iVar4);
    plVar17 = (longlong *)(ulonglong)uVar16;
  }
  else {
    if (*(longlong **)(param_1 + 0x60) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x60) + 8))();
      *(undefined8 *)(param_1 + 0x60) = 0;
    }
    if (piVar9[8] == 0) {
      local_58 = FUN_1402994c0;
      local_68 = 10;
      local_64 = 2;
      local_50 = 0;
      local_48 = 1;
      local_60 = param_1;
      iVar4 = FUN_14019dca0(&local_68,0,local_res10,param_1 + 0x98);
      if (iVar4 < 0) {
        local_res18 = (longlong *)0x141de4348;
        goto LAB_140299386;
      }
    }
    else {
      if (piVar9[8] != 1) {
        iVar4 = -0x7fffbffb;
        goto LAB_14029946b;
      }
      local_58 = FUN_140299eb0;
      local_68 = 0xc;
      local_64 = 2;
      local_50 = 0;
      local_48 = 1;
      local_60 = param_1;
      iVar4 = FUN_14019dca0(&local_68,0,local_res10,param_1 + 0x88);
      if (iVar4 < 0) {
        local_res18 = (longlong *)0x141de41d8;
        goto LAB_140299386;
      }
    }
  }
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 8))();
  }
LAB_140299485:
  if (plVar8 != (longlong *)0x0) {
    (**(code **)(*plVar8 + 8))(plVar8);
  }
  return plVar17;
}

