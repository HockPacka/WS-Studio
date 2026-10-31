/* WildStar64.exe build 16042, Ghidra MCP force_decompile.
Mesh +0x38 draw-list filter, before FUN_14030e7b0 -> FUN_1403258c0. */

void FUN_1402f9f10(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  ushort uVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong local_res20;
  
  if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x40);
    uVar8 = 0;
    auVar4 = ZEXT816(4) * ZEXT416(*(uint *)(lVar3 + 0x80));
    uVar6 = auVar4._0_8_;
    if (auVar4._8_8_ != 0) {
      uVar6 = 0xffffffffffffffff;
    }
    lVar7 = FUN_14018b280(uVar6,0);
    uVar11 = 0;
    if (*(int *)(lVar3 + 0x80) != 0) {
      do {
        lVar9 = uVar11 * 0x70 + *(longlong *)(lVar3 + 0x88);
        if ((*(byte *)(lVar9 + 0x38) & 10) != 10) {
          if ((uint)*(ushort *)(lVar9 + 0x1e) < *(uint *)(*(longlong *)(param_1 + 0x40) + 0x200)) {
            uVar2 = *(ushort *)
                     (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x208) +
                     (ulonglong)*(ushort *)(lVar9 + 0x1e) * 4);
            uVar12 = (ulonglong)(uVar2 >> 3);
            if (((ulonglong)param_3[1] <= uVar12) ||
               ((*(byte *)(*param_3 + uVar12) & '\x01' << ((byte)uVar2 & 7)) == 0))
            goto LAB_1402fa00c;
          }
          if ((*(ushort *)(lVar9 + 0x22) == 0) ||
             (*(uint *)(param_2 + (ulonglong)*(ushort *)(lVar9 + 0x22) * 4) <=
              (uint)*(ushort *)(lVar9 + 0x26))) {
            *(int *)(lVar7 + uVar8 * 4) = (int)uVar11;
            uVar8 = (ulonglong)((int)uVar8 + 1);
          }
        }
LAB_1402fa00c:
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
      } while (uVar10 < *(uint *)(lVar3 + 0x80));
    }
    iVar5 = FUN_14030e7b0(*(undefined8 *)(param_1 + 0x38),uVar8,lVar7,&local_res20);
    if (-1 < iVar5) {
      LOCK();
      plVar1 = *(longlong **)(param_1 + 0x470);
      *(longlong *)(param_1 + 0x470) = local_res20;
      UNLOCK();
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 8))();
      }
    }
    FUN_14018b900(lVar7,0);
    LOCK();
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 8;
    UNLOCK();
    if ((*(uint *)(param_1 + 0x34) & 0xe) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xfffffff1;
      UNLOCK();
      for (lVar3 = *(longlong *)(param_1 + 0x4c0);
          (lVar3 != 0 && ((*(uint *)(lVar3 + 0x34) & 0x20) != 0));
          lVar3 = *(longlong *)(lVar3 + 0x4c0)) {
        LOCK();
        *(uint *)(lVar3 + 0x34) = *(uint *)(lVar3 + 0x34) & 0xffffffdf;
        UNLOCK();
      }
    }
    for (lVar3 = *(longlong *)(param_1 + 0x4d0); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x4e0)) {
      if (*(int *)(lVar3 + 0x4b0) == 0) {
        FUN_1402f9f10(lVar3,param_2,param_3);
      }
    }
  }
  return;
}

