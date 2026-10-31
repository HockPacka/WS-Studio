
void FUN_1405a5fe0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  int iVar10;
  ulonglong uVar11;
  uint uVar12;
  bool bVar13;
  
  if (*(int *)(*(longlong *)(param_2 + 0x70) + 0x104) != 0) {
    if (*(longlong *)(param_2 + 8) != 0) {
      uVar9 = 0;
      do {
        uVar11 = 0;
        do {
          uVar12 = 0;
          do {
            bVar13 = *(int *)(*(longlong *)(param_2 + 0x70) + 0x18) == 8;
            uVar1 = *(uint *)(*(longlong *)(param_2 + 8) + 0x1c);
            lVar6 = *(longlong *)(DAT_140c65b70 + 0x658);
            lVar7 = *(longlong *)(lVar6 + 8);
            lVar4 = lVar7;
            lVar8 = lVar6;
            if (lVar7 != 0) {
              do {
                iVar3 = (int)uVar9;
                iVar10 = (int)uVar11;
                if (bVar13) {
                  if (*(int *)(lVar4 + 0x20) != 0) goto LAB_1405a6092;
LAB_1405a60bd:
                  lVar5 = *(longlong *)(lVar4 + 0x18);
                }
                else if (*(int *)(lVar4 + 0x20) == 0) {
LAB_1405a6092:
                  if ((*(uint *)(lVar4 + 0x24) <= uVar1) &&
                     ((uVar1 != *(uint *)(lVar4 + 0x24) ||
                      ((*(int *)(lVar4 + 0x28) <= iVar3 &&
                       ((*(int *)(lVar4 + 0x28) < iVar3 ||
                        ((*(int *)(lVar4 + 0x2c) <= iVar10 &&
                         ((*(int *)(lVar4 + 0x2c) < iVar10 || (*(uint *)(lVar4 + 0x30) <= uVar12))))
                        )))))))) goto LAB_1405a60bd;
                  lVar5 = *(longlong *)(lVar4 + 0x10);
                  lVar8 = lVar4;
                }
                else {
                  lVar5 = *(longlong *)(lVar4 + 0x10);
                  lVar8 = lVar4;
                }
                lVar4 = lVar5;
              } while (lVar5 != 0);
              while (lVar7 != 0) {
                if (*(int *)(lVar7 + 0x20) == 0) {
                  if (!bVar13) {
LAB_1405a60e2:
                    if ((uVar1 <= *(uint *)(lVar7 + 0x24)) &&
                       ((*(uint *)(lVar7 + 0x24) != uVar1 ||
                        ((iVar3 <= *(int *)(lVar7 + 0x28) &&
                         ((iVar3 < *(int *)(lVar7 + 0x28) ||
                          ((iVar10 <= *(int *)(lVar7 + 0x2c) &&
                           ((iVar10 < *(int *)(lVar7 + 0x2c) || (uVar12 <= *(uint *)(lVar7 + 0x30)))
                           )))))))))) goto LAB_1405a610a;
                  }
                  lVar7 = *(longlong *)(lVar7 + 0x18);
                }
                else {
                  if (bVar13) goto LAB_1405a60e2;
LAB_1405a610a:
                  lVar6 = lVar7;
                  lVar7 = *(longlong *)(lVar7 + 0x10);
                }
              }
            }
            while (lVar6 != lVar8) {
              if (*(int *)(*(longlong *)(lVar6 + 0x38) + 0x20) != 3) {
                (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,
                                    *(undefined8 *)(*(longlong *)(lVar6 + 0x38) + 0x58));
              }
              lVar7 = *(longlong *)(lVar6 + 0x18);
              if (lVar7 == 0) {
                lVar7 = *(longlong *)(lVar6 + 8);
                if (lVar6 == *(longlong *)(lVar7 + 0x18)) {
                  do {
                    lVar6 = lVar7;
                    lVar7 = *(longlong *)(lVar6 + 8);
                  } while (lVar6 == *(longlong *)(lVar7 + 0x18));
                }
                if (*(longlong *)(lVar6 + 0x18) != lVar7) {
                  lVar6 = lVar7;
                }
              }
              else {
                for (lVar4 = *(longlong *)(lVar7 + 0x10); lVar6 = lVar7, lVar4 != 0;
                    lVar4 = *(longlong *)(lVar4 + 0x10)) {
                  lVar7 = lVar4;
                }
              }
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < 0x20);
          uVar11 = uVar11 + 1;
        } while (uVar11 < 8);
        uVar9 = uVar9 + 1;
      } while (uVar9 < 8);
    }
    if (*(int *)(*(longlong *)(param_2 + 0x70) + 0x50) != 0) {
      uVar9 = 0x54;
      do {
        uVar2 = *(undefined4 *)(uVar9 + *(longlong *)(param_2 + 0x70));
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c64f14 != 0) || (iVar3 = FUN_140237420(), iVar3 < 0)) break;
          lVar6 = (**(code **)(*DAT_140c64a28 + 0x18))(DAT_140c64a28,uVar2);
        }
        else {
          lVar6 = (*DAT_140c63840)(&PTR_u_Spell4ClientMissile_140a6d188,uVar2,DAT_140c63858);
        }
        if (lVar6 == 0) break;
        uVar11 = *(ulonglong *)(lVar6 + 0x18);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x20);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x28);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x70);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x80);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x88);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x90);
        if (uVar11 == 0) {
          lVar6 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar6 = 0;
        }
        else {
          lVar6 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar6);
        uVar9 = uVar9 + 4;
      } while (uVar9 < 0x6c);
    }
    if (*(int *)(*(longlong *)(param_2 + 0x70) + 0x34) != 0) {
      uVar9 = 0x38;
      do {
        uVar2 = *(undefined4 *)(uVar9 + *(longlong *)(param_2 + 0x70));
        if (DAT_140c63840 == (code *)0x0) {
          if (DAT_140c64f14 != 0) {
            return;
          }
          iVar3 = FUN_140237420();
          if (iVar3 < 0) {
            return;
          }
          lVar6 = (**(code **)(*DAT_140c64a28 + 0x18))(DAT_140c64a28,uVar2);
        }
        else {
          lVar6 = (*DAT_140c63840)(&PTR_u_Spell4ClientMissile_140a6d188,uVar2,DAT_140c63858);
        }
        if (lVar6 == 0) {
          return;
        }
        uVar11 = *(ulonglong *)(lVar6 + 0x18);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x20);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x28);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x70);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x80);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x88);
        if (uVar11 == 0) {
          lVar7 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar7 = 0;
        }
        else {
          lVar7 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar7);
        uVar11 = *(ulonglong *)(lVar6 + 0x90);
        if (uVar11 == 0) {
          lVar6 = 0;
        }
        else if (DAT_140c3fe70 < uVar11) {
          lVar6 = 0;
        }
        else {
          lVar6 = DAT_140c3fe68 + uVar11;
        }
        (*(code *)*param_3)(*(int *)(param_3 + 1) + param_1,lVar6);
        uVar9 = uVar9 + 4;
      } while (uVar9 < 0x50);
    }
  }
  return;
}

