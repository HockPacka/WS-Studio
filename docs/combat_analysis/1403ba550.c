
void FUN_1403ba550(longlong param_1,uint param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  longlong *plVar11;
  void *_Dst;
  longlong lVar12;
  int *piVar13;
  byte bVar14;
  uint *puVar15;
  ulonglong uVar16;
  int iVar17;
  byte bVar18;
  uint uVar19;
  uint *puVar20;
  bool bVar21;
  longlong local_res18;
  longlong local_res20;
  longlong local_70 [2];
  longlong local_60;
  uint *local_58;
  
  if (param_2 != 0) {
    lVar12 = *(longlong *)(param_1 + 0xaa8);
    local_res18 = lVar12;
    lVar2 = *(longlong *)(lVar12 + 8);
    while (lVar2 != 0) {
      if (*(uint *)(lVar2 + 0x20) < param_2) {
        lVar2 = *(longlong *)(lVar2 + 0x18);
      }
      else {
        local_res18 = lVar2;
        lVar2 = *(longlong *)(lVar2 + 0x10);
      }
    }
    if ((local_res18 == lVar12) || (param_2 < *(uint *)(local_res18 + 0x20))) {
      local_res18 = lVar12;
    }
    if (local_res18 == lVar12) {
      bVar4 = FUN_1407a1590();
      iVar5 = FUN_1407a1440();
      puVar20 = (uint *)0x0;
      uVar19 = 0;
      uVar7 = uVar19;
      if (iVar5 != 0) {
        uVar7 = FUN_1403baf90(param_1,iVar5);
      }
      uVar6 = FUN_1407a1440();
      local_70[0] = FUN_1403acd90(DAT_140c65b70,uVar6,*(undefined8 *)(param_1 + 0x78));
      if (local_70[0] != 0) {
        iVar5 = 4;
        piVar13 = (int *)(*(longlong *)(local_70[0] + 0x70) + 0x198);
        puVar15 = puVar20;
        do {
          if (*piVar13 == 6) {
            iVar5 = 1;
            break;
          }
          puVar15 = (uint *)((longlong)puVar15 + 1);
          piVar13 = piVar13 + 1;
        } while (puVar15 < (uint *)0x5);
        puVar9 = (uint *)FUN_14018b280(0x10);
        puVar15 = puVar20;
        if (puVar9 != (uint *)0x0) {
          puVar9[2] = 0;
          puVar9[3] = 0;
          puVar9[0] = 0;
          puVar9[1] = 0;
          puVar15 = puVar9;
        }
        local_60 = (longlong)(int)uVar7;
        bVar18 = 0;
        local_res20 = CONCAT44(local_res20._4_4_,iVar5);
        iVar17 = 0;
        if (iVar5 != 0) {
          do {
            lVar12 = local_60;
            puVar10 = (uint *)FUN_14018b280(0x28);
            puVar9 = puVar20;
            if (puVar10 != (uint *)0x0) {
              puVar10[0] = 0;
              puVar10[1] = 0;
              *(undefined2 *)(puVar10 + 2) = 0;
              puVar10[4] = 0;
              puVar10[5] = 0;
              puVar10[8] = 0;
              puVar10[9] = 0;
              puVar10[6] = 0;
              puVar10[7] = 0;
              puVar9 = puVar10;
            }
            *puVar9 = param_2;
            *(byte *)((longlong)puVar9 + 9) = bVar4;
            puVar9[1] = uVar6;
            FUN_140052360(puVar9 + 6,bVar4 + 1);
            if (lVar12 != 0) {
              *(undefined1 *)(puVar9 + 2) = 1;
            }
            iVar5 = FUN_1403b5000(local_70[0],3);
            if (iVar5 != 0) {
              uVar7 = uVar19;
              if (DAT_140c65970 != (longlong *)0x0) {
                uVar7 = (**(code **)(*DAT_140c65970 + 0x10))();
              }
              plVar11 = (longlong *)FUN_1407a1500(DAT_140c65b70,param_2);
              if ((plVar11 != (longlong *)0x0) && (iVar5 = (int)plVar11[1] + -1, -1 < iVar5)) {
                lVar12 = *plVar11;
                do {
                  uVar8 = FUN_140491e90();
                  if (uVar8 <= uVar7) {
                    uVar7 = *(uint *)(lVar12 + (longlong)iVar5 * 4);
                    *(char *)(puVar9 + 2) = (char)iVar5 + '\x01';
                    puVar9[1] = uVar7;
                    break;
                  }
                  iVar5 = iVar5 + -1;
                } while (-1 < iVar5);
              }
            }
            lVar2 = *(longlong *)(puVar15 + 2);
            lVar12 = lVar2 + 1;
            _Dst = (void *)FUN_14018db00(*(longlong *)puVar15,lVar12,8);
            *(uint **)((longlong)_Dst + lVar2 * 8) = puVar9;
            if (*(void **)puVar15 != _Dst) {
              memcpy(_Dst,*(void **)puVar15,*(longlong *)(puVar15 + 2) << 3);
              lVar2 = *(longlong *)puVar15;
              if (lVar2 != 0) {
                (**(code **)(*(longlong *)(lVar2 + -0x10) + 8))(lVar2 + -0x10);
              }
              *(void **)puVar15 = _Dst;
            }
            bVar18 = bVar18 + 1;
            *(longlong *)(puVar15 + 2) = lVar12;
            iVar17 = (int)local_res20;
          } while ((int)(uint)bVar18 < (int)local_res20);
        }
        local_60 = CONCAT44(local_60._4_4_,param_2);
        local_58 = puVar15;
        FUN_140055f80(param_1 + 0xaa0,local_70,&local_60);
        bVar18 = 1;
        if (bVar4 != 0) {
          do {
            uVar7 = FUN_1407a1440();
            lVar12 = *(longlong *)(param_1 + 0x78);
            if (uVar7 != 0) {
              if (lVar12 == 0) {
LAB_1403ba906:
                lVar12 = FUN_1407a0fd0(DAT_140c65b70);
                if (lVar12 == 0) goto LAB_1403ba95b;
              }
              else {
                if (*(longlong *)(DAT_140c65898 + 0x1e) == lVar12) {
                  bVar21 = true;
                }
                else {
                  bVar21 = *(longlong *)(DAT_140c65898 + 0x1924) == lVar12;
                }
                puVar9 = puVar20;
                if (bVar21) {
                  puVar9 = DAT_140c65898;
                }
                if (puVar9 == (uint *)0x0) goto LAB_1403ba906;
                lVar12 = *(longlong *)(puVar9 + 0x1f46);
                lVar3 = lVar12;
                lVar2 = *(longlong *)(lVar12 + 8);
                while (lVar2 != 0) {
                  if (*(uint *)(lVar2 + 0x20) < uVar7) {
                    lVar2 = *(longlong *)(lVar2 + 0x18);
                  }
                  else {
                    lVar3 = lVar2;
                    lVar2 = *(longlong *)(lVar2 + 0x10);
                  }
                }
                if ((lVar3 == lVar12) || (uVar7 < *(uint *)(lVar3 + 0x20))) {
                  local_60 = lVar12;
                  plVar11 = &local_60;
                }
                else {
                  plVar11 = &local_res20;
                  local_res20 = lVar3;
                }
                if ((*plVar11 == lVar12) || (lVar12 = *(longlong *)(*plVar11 + 0x28), lVar12 == 0))
                goto LAB_1403ba906;
              }
              uVar1 = *(undefined4 *)(*(longlong *)(lVar12 + 0x70) + 0x18c);
              if (0 < iVar17) {
                uVar16 = 0;
                do {
                  bVar14 = (char)uVar16 + 1;
                  *(undefined4 *)
                   ((ulonglong)bVar18 * 4 +
                   *(longlong *)(*(longlong *)(*(longlong *)puVar15 + uVar16 * 8) + 0x18)) = uVar1;
                  uVar16 = (ulonglong)bVar14;
                } while ((int)(uint)bVar14 < iVar17);
              }
            }
LAB_1403ba95b:
            bVar18 = bVar18 + 1;
          } while (bVar18 <= bVar4);
        }
        if (((((*(int *)(param_1 + 0x7180) == 0) &&
              (iVar5 = FUN_1403bad30(param_1,param_2,*(undefined1 *)(param_1 + 0x6dec)), iVar5 != 0)
              ) && (lVar12 = FUN_1407a16f0(), lVar12 != 0)) &&
            ((*(longlong *)(param_1 + 0x78) != 0 &&
             (piVar13 = (int *)FUN_1407a16f0(), piVar13 != (int *)0x0)))) &&
           (iVar5 = FUN_1405a76a0(param_1,param_2), iVar5 + *piVar13 != 0)) {
          piVar13 = (int *)FUN_1407a16f0();
          if (piVar13 != (int *)0x0) {
            lVar12 = *(longlong *)(param_1 + 0x6dc0);
            local_res18 = lVar12;
            lVar2 = *(longlong *)(lVar12 + 8);
            while (lVar2 != 0) {
              if (*(uint *)(lVar2 + 0x20) < param_2) {
                lVar2 = *(longlong *)(lVar2 + 0x18);
              }
              else {
                local_res18 = lVar2;
                lVar2 = *(longlong *)(lVar2 + 0x10);
              }
            }
            if ((local_res18 == lVar12) || (param_2 < *(uint *)(local_res18 + 0x20))) {
              local_res18 = lVar12;
            }
            if (local_res18 != lVar12) {
              uVar19 = *(uint *)(local_res18 + 0x24);
            }
            puVar20 = (uint *)(ulonglong)(uVar19 + *piVar13);
          }
          FUN_1405a6c90(param_1,param_2,puVar20);
        }
      }
    }
  }
  return;
}

