
undefined4 FUN_1407beb20(longlong *param_1,longlong param_2)

{
  undefined8 *puVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined8 local_48;
  longlong local_40;
  longlong *local_38;
  
  if (param_2 != 0) {
    local_48 = CONCAT44(local_48._4_4_,0xffffffff);
    iVar3 = (**(code **)(*param_1 + 0x40))(param_1,&local_48);
    if (iVar3 != 0) {
      puVar5 = (undefined4 *)FUN_14018b280(0x58);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *(undefined8 *)(puVar5 + 2) = 0;
        *(undefined8 *)(puVar5 + 4) = 0;
        *(undefined8 *)(puVar5 + 8) = 0;
        *(undefined8 *)(puVar5 + 10) = 0;
        *(undefined8 *)(puVar5 + 0xe) = 0;
        *(undefined8 *)(puVar5 + 0x10) = 0;
        *(undefined8 *)(puVar5 + 0x12) = 0;
        *(undefined8 *)(puVar5 + 0x14) = 0;
      }
      FUN_1407e4830(puVar5,0,0x58);
      *puVar5 = 0x4454424c;
      lVar6 = -1;
      do {
        lVar9 = lVar6 * 2;
        lVar6 = lVar6 + 1;
      } while (*(short *)(*(longlong *)param_1[3] + 2 + lVar9) != 0);
      FUN_1407bfff0(puVar5 + 2,(int)lVar6 + 1);
      memcpy(*(void **)(puVar5 + 4),*(void **)param_1[3],(ulonglong)(uint)puVar5[2] * 2);
      puVar5[6] = *(undefined4 *)(param_1[3] + 8);
      FUN_1407c0090(puVar5 + 8);
      uVar11 = 0;
      if (puVar5[8] != 0) {
        do {
          lVar6 = uVar11 * 0x28;
          lVar8 = -1;
          lVar9 = uVar11 * 0x18;
          do {
            lVar8 = lVar8 + 1;
          } while (*(short *)(*(longlong *)(*(longlong *)(param_1[3] + 0x10) + lVar6) + lVar8 * 2)
                   != 0);
          FUN_1407bfff0(*(longlong *)(puVar5 + 10) + lVar9,(int)lVar8 + 1);
          memcpy(*(void **)(*(longlong *)(puVar5 + 10) + 8 + lVar9),
                 *(void **)(*(longlong *)(param_1[3] + 0x10) + lVar6),
                 (ulonglong)*(uint *)(*(longlong *)(puVar5 + 10) + lVar9) * 2);
          uVar10 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar10;
          *(undefined2 *)(lVar9 + 0x10 + *(longlong *)(puVar5 + 10)) =
               *(undefined2 *)(*(longlong *)(param_1[3] + 0x10) + 8 + lVar6);
          *(undefined4 *)(lVar9 + 0x14 + *(longlong *)(puVar5 + 10)) =
               *(undefined4 *)(*(longlong *)(param_1[3] + 0x10) + 0x18 + lVar6);
        } while (uVar10 < (uint)puVar5[8]);
      }
      puVar5[0xc] = (int)param_1[9];
      FUN_1407c0180(puVar5 + 0xe,(int)param_1[6]);
      uVar11 = 0;
      if ((int)param_1[9] != 0) {
        do {
          uVar10 = *(uint *)(param_1[3] + 8);
          memcpy((void *)((ulonglong)(uVar10 * (int)uVar11) + *(longlong *)(puVar5 + 0x10)),
                 (void *)((ulonglong)(*(int *)(param_1[8] + uVar11 * 4) * uVar10) + param_1[7]),
                 (ulonglong)uVar10);
          uVar10 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar10;
        } while (uVar10 < *(uint *)(param_1 + 9));
      }
      uVar10 = *(int *)(param_1[3] + 8) * (int)param_1[9];
      memcpy((void *)(*(longlong *)(puVar5 + 0x10) + (ulonglong)uVar10),
             (void *)(param_1[7] + (ulonglong)uVar10),(ulonglong)((int)param_1[6] - uVar10));
      uVar11 = 0;
      if (puVar5[8] != 0) {
        do {
          sVar2 = *(short *)(*(longlong *)(puVar5 + 10) + 0x10 + uVar11 * 0x18);
          if (sVar2 == 0x82) {
            uVar10 = 0;
            if ((int)param_1[9] != 0) {
              do {
                plVar7 = (longlong *)
                         ((ulonglong)
                          (*(int *)(param_1[3] + 8) * uVar10 +
                          *(int *)(*(longlong *)(param_1[3] + 0x10) + 0xc + uVar11 * 0x28)) +
                         *(longlong *)(puVar5 + 0x10));
                uVar10 = uVar10 + 1;
                *plVar7 = *plVar7 - param_1[7];
              } while (uVar10 < *(uint *)(param_1 + 9));
            }
          }
          else if (((sVar2 == 0x80) &&
                   ((*(byte *)(*(longlong *)(puVar5 + 10) + uVar11 * 0x18 + 0x14) & 0x10) == 0)) &&
                  (uVar10 = 0, (int)param_1[9] != 0)) {
            do {
              plVar7 = (longlong *)
                       ((ulonglong)(*(int *)(param_1[3] + 8) * uVar10) +
                        (ulonglong)*(uint *)(*(longlong *)(param_1[3] + 0x10) + 0xc + uVar11 * 0x28)
                       + *(longlong *)(puVar5 + 0x10));
              if (plVar7 != (longlong *)0x0) {
                lVar6 = *plVar7;
                if (lVar6 == 0) {
                  lVar6 = 0;
                }
                else if (DAT_140c3fe70 < (ulonglong)*(uint *)(plVar7 + 1) + lVar6) {
                  lVar6 = 0;
                }
                else {
                  lVar6 = DAT_140c3fe68 + lVar6;
                }
                *plVar7 = lVar6 - param_1[7];
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(uint *)(param_1 + 9));
          }
          uVar10 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar10;
        } while (uVar10 < (uint)puVar5[8]);
      }
      if ((int)param_1[9] != 0) {
        FUN_1407c0210(puVar5 + 0x12,
                      *(int *)((ulonglong)
                               (uint)(*(int *)(param_1[8] + (ulonglong)((int)param_1[9] - 1) * 4) *
                                     *(int *)(param_1[3] + 8)) + param_1[7]) + 1);
        FUN_1407e4830(*(undefined8 *)(puVar5 + 0x14),0xff);
        uVar10 = 0;
        if ((int)param_1[9] != 0) {
          do {
            *(uint *)(*(longlong *)(puVar5 + 0x14) +
                     (ulonglong)
                     *(uint *)((ulonglong)(*(int *)(param_1[3] + 8) * uVar10) +
                              *(longlong *)(puVar5 + 0x10)) * 4) = uVar10;
            uVar10 = uVar10 + 1;
          } while (uVar10 < *(uint *)(param_1 + 9));
        }
      }
      local_38 = &local_40;
      local_48 = 0;
      local_40 = 0;
      uVar4 = FUN_1407c0310(&local_48,param_2,puVar5);
      lVar6 = local_40;
      while (lVar6 != 0) {
        local_40 = *(longlong *)(lVar6 + 0x28);
        FUN_14018b900(lVar6,0);
        lVar6 = local_40;
      }
      local_40 = lVar6;
      FUN_14018b900(*(undefined8 *)(puVar5 + 0x14),0);
      FUN_14018b900(*(undefined8 *)(puVar5 + 0x10),0);
      lVar6 = *(longlong *)(puVar5 + 10);
      if (lVar6 != 0) {
        iVar3 = *(int *)(lVar6 + -8) + -1;
        if (-1 < iVar3) {
          lVar9 = lVar6 + (longlong)*(int *)(lVar6 + -8) * 0x18 + 8;
          do {
            puVar1 = (undefined8 *)(lVar9 + -0x18);
            lVar9 = lVar9 + -0x18;
            FUN_14018b900(*puVar1,0);
            iVar3 = iVar3 + -1;
          } while (-1 < iVar3);
        }
        FUN_14018b900(lVar6 + -8,0);
      }
      FUN_14018b900(*(undefined8 *)(puVar5 + 4),0);
      FUN_14018b900(puVar5,0);
      return uVar4;
    }
  }
  return 0x80004005;
}

