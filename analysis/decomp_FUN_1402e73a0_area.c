
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1402e73a0(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  ushort *puVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  ushort *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  longlong *local_res18;
  longlong *local_res20;
  
  if (*(longlong **)(param_1 + 0x38) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x38) + 8))();
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  if (((*(longlong *)(param_1 + 0x108) != 0) &&
      (lVar5 = *(longlong *)(param_1 + 0x20), *(float *)(lVar5 + 0x60) != 0.0)) &&
     ((*(byte *)(lVar5 + 0x38) & 1) != 0)) {
    lVar5 = (**(code **)(**(longlong **)(lVar5 + 0x18) + 0x18))();
    lVar6 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0x20))();
    iVar10 = *(int *)(lVar6 + 0x14) - *(int *)(lVar5 + 0x14);
    iVar3 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x40))(*(longlong **)(param_1 + 0x18),0);
    if (((iVar3 == 0) ||
        (iVar3 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                           (*(longlong **)(param_1 + 0x28),0), iVar3 == 0)) || (iVar10 != 0)) {
      lVar5 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x20))();
      local_res20 = (longlong *)0x0;
      (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
                (*(longlong **)(param_1 + 0x28),0,&local_res20,1);
      puVar7 = (ushort *)(**(code **)(*local_res20 + 0x20))();
      local_res18 = (longlong *)0x0;
      (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
                (*(longlong **)(param_1 + 0x18),0,&local_res18,1);
      lVar6 = (**(code **)(*local_res18 + 0x20))();
      FUN_1402ddac0(0,param_1 + 0x38);
      lVar8 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x20))();
      uVar14 = DAT_140c41360 - _DAT_140c41358;
      if (0 < DAT_140c41364 - DAT_140c4135c) {
        uVar12 = (ulonglong)(uint)(DAT_140c41364 - DAT_140c4135c);
        do {
          if (0 < (int)uVar14) {
            uVar15 = 0;
            uVar13 = (ulonglong)uVar14;
            puVar11 = puVar7;
            do {
              uVar1 = *(ushort *)((lVar6 - (longlong)puVar7) + (longlong)puVar11);
              uVar2 = *puVar11;
              iVar3 = (uVar2 & 0x7fff) + iVar10;
              if (0x7fff < iVar3) {
                iVar3 = 0x7fff;
              }
              iVar4 = 0;
              if (0 < iVar3) {
                iVar4 = iVar3;
              }
              lVar9 = uVar15 * 4;
              fVar18 = (float)(uVar1 & 0x7fff);
              puVar11 = puVar11 + 1;
              uVar15 = (ulonglong)((int)uVar15 + 4);
              fVar17 = (float)(uVar1 >> 0xf);
              fVar16 = (float)*(byte *)(lVar5 + lVar9) * 0.003921569 *
                       *(float *)(*(longlong *)(param_1 + 0x20) + 0x60);
              *(ushort *)((lVar8 - (longlong)puVar7) + -2 + (longlong)puVar11) =
                   (short)(longlong)(fVar16 * ((float)(uVar2 >> 0xf) - fVar17) + fVar17 + 0.5) <<
                   0xf | (ushort)(longlong)(fVar16 * ((float)iVar4 - fVar18) + fVar18 + 0.5);
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
          lVar9 = (longlong)DAT_140c4136c;
          puVar7 = (ushort *)((longlong)puVar7 + lVar9);
          lVar6 = lVar6 + lVar9;
          lVar8 = lVar8 + lVar9;
          lVar5 = lVar5 + (ulonglong)(uint)(DAT_140c4191c * 4);
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
      }
      if (local_res18 != (longlong *)0x0) {
        (**(code **)(*local_res18 + 8))();
      }
      if (local_res20 != (longlong *)0x0) {
        (**(code **)(*local_res20 + 8))();
      }
    }
  }
  return;
}

