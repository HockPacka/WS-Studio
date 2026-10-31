
void FUN_1403d4210(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  bool bVar5;
  longlong lVar6;
  float *pfVar7;
  undefined8 uVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  float *pfVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong lVar15;
  longlong lVar16;
  uint uVar17;
  ulonglong uVar18;
  uint uVar19;
  float *pfVar20;
  ulonglong uVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined8 *local_c8;
  undefined1 local_c0 [8];
  float *local_b8;
  float *local_b0;
  float *local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  uint local_88 [2];
  undefined8 *local_80;
  undefined1 local_78 [56];
  
  uVar8 = DAT_140c65b70;
  lVar16 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x10);
  if (lVar16 != *(longlong *)(param_2 + 8)) {
    do {
      uVar1 = *(uint *)(lVar16 + 0x20);
      if ((*(longlong *)(lVar16 + 0x30) != 0) &&
         (lVar10 = FUN_1407a0fd0(uVar8,uVar1), local_90 = lVar10, lVar10 != 0)) {
        lVar15 = *(longlong *)(param_3 + 8);
        lVar6 = lVar15;
        lVar4 = *(longlong *)(lVar15 + 8);
        while (lVar4 != 0) {
          if (*(uint *)(lVar4 + 0x20) < uVar1) {
            lVar4 = *(longlong *)(lVar4 + 0x18);
          }
          else {
            lVar6 = lVar4;
            lVar4 = *(longlong *)(lVar4 + 0x10);
          }
        }
        if ((lVar6 == lVar15) || (uVar1 < *(uint *)(lVar6 + 0x20))) {
          local_a0 = lVar15;
          plVar11 = &local_a0;
        }
        else {
          local_98 = lVar6;
          plVar11 = &local_98;
        }
        bVar5 = false;
        if (*plVar11 == lVar15) {
          local_c8 = (undefined8 *)FUN_14018b280(0x88,0);
          if (local_c8 == (undefined8 *)0x0) {
            local_c8 = (undefined8 *)0x0;
          }
          else {
            local_c8[4] = 0;
            local_c8[3] = 0;
            local_c8[0xd] = 0;
            local_c8[0xc] = 0;
            local_c8[0xe] = 0;
            *(undefined4 *)(local_c8 + 0xf) = 0;
            *local_c8 = &PTR_FUN_140b667d0;
            *(undefined4 *)(local_c8 + 0x10) = 0;
          }
          FUN_1403d8810(local_c8,lVar10);
          bVar5 = true;
        }
        else {
          local_c8 = *(undefined8 **)(*plVar11 + 0x28);
        }
        uVar17 = *(uint *)(**(longlong **)(lVar16 + 0x28) + 8);
        iVar2 = *(int *)((*(longlong **)(lVar16 + 0x28))[*(longlong *)(lVar16 + 0x30) + -1] + 8);
        if ((int)uVar17 <= iVar2) {
LAB_1403d43a0:
          uVar14 = *(ulonglong *)(lVar16 + 0x30);
          uVar21 = 0;
          if (uVar14 != 0) {
            lVar10 = *(longlong *)(lVar16 + 0x28);
            uVar18 = uVar14;
            do {
              uVar13 = (uVar18 - uVar21 >> 1) + uVar21;
              lVar15 = *(longlong *)(lVar10 + uVar13 * 8);
              if (lVar15 == 0) {
                iVar9 = 0;
              }
              else {
                iVar9 = uVar17 - *(int *)(lVar15 + 8);
              }
              if (-1 < iVar9) {
                if (iVar9 < 1) {
                  uVar21 = uVar13;
                  if (uVar13 == 0) goto LAB_1403d442f;
                  lVar15 = lVar10 + uVar13 * 8;
                  goto LAB_1403d4410;
                }
                uVar21 = uVar13 + 1;
                uVar13 = uVar18;
              }
              uVar18 = uVar13;
            } while (uVar21 < uVar13);
          }
          goto LAB_1403d481e;
        }
LAB_1403d4833:
        if (bVar5) {
          local_88[0] = uVar1;
          local_80 = local_c8;
          FUN_140055f80(param_3,local_78,local_88);
        }
      }
      lVar10 = *(longlong *)(lVar16 + 0x18);
      if (lVar10 == 0) {
        lVar10 = *(longlong *)(lVar16 + 8);
        if (lVar16 == *(longlong *)(lVar10 + 0x18)) {
          do {
            lVar16 = lVar10;
            lVar10 = *(longlong *)(lVar16 + 8);
          } while (lVar16 == *(longlong *)(lVar10 + 0x18));
        }
        if (*(longlong *)(lVar16 + 0x18) != lVar10) {
          lVar16 = lVar10;
        }
      }
      else {
        for (lVar15 = *(longlong *)(lVar10 + 0x10); lVar16 = lVar10, lVar15 != 0;
            lVar15 = *(longlong *)(lVar15 + 0x10)) {
          lVar10 = lVar15;
        }
      }
    } while (lVar16 != *(longlong *)(param_2 + 8));
  }
  return;
  while (uVar21 = uVar18, uVar18 != 0) {
LAB_1403d4410:
    plVar11 = (longlong *)(lVar15 + -8);
    lVar15 = lVar15 + -8;
    uVar18 = uVar21 - 1;
    if ((*plVar11 != 0) && (uVar17 != *(uint *)(*plVar11 + 8))) break;
  }
LAB_1403d442f:
  uVar13 = uVar13 + 1;
  if (uVar13 < uVar14) {
    plVar11 = (longlong *)(lVar10 + uVar13 * 8);
    do {
      if ((*plVar11 != 0) && (uVar17 != *(uint *)(*plVar11 + 8))) break;
      uVar13 = uVar13 + 1;
      plVar11 = plVar11 + 1;
    } while (uVar13 < uVar14);
  }
  if (uVar21 != uVar13) {
    uVar19 = *(uint *)(*(longlong *)(lVar10 + uVar21 * 8) + 0xc);
    uVar3 = *(uint *)(*(longlong *)(lVar10 + -8 + uVar13 * 8) + 0xc);
    fVar22 = (float)FUN_1407a18c0(uVar17);
    fVar24 = fVar22;
    if ((uVar17 < 0x16) && ((0x31bf6fU >> (uVar17 & 0x1f) & 1) != 0)) {
      if (uVar19 <= uVar3) {
LAB_1403d44b0:
        uVar14 = *(ulonglong *)(lVar16 + 0x30);
        uVar21 = 0;
        if (uVar14 != 0) {
          lVar10 = *(longlong *)(lVar16 + 0x28);
          uVar18 = uVar14;
          do {
            uVar13 = (uVar18 - uVar21 >> 1) + uVar21;
            lVar15 = *(longlong *)(lVar10 + uVar13 * 8);
            if (lVar15 == 0) {
              iVar9 = 0;
            }
            else {
              iVar9 = uVar17 - *(int *)(lVar15 + 8);
              if ((iVar9 == 0) && (uVar19 != 0xffffffff)) {
                iVar9 = uVar19 - *(int *)(lVar15 + 0xc);
              }
            }
            if (-1 < iVar9) {
              if (iVar9 < 1) {
                uVar21 = uVar13;
                if (uVar13 == 0) goto LAB_1403d455b;
                lVar15 = lVar10 + uVar13 * 8;
                goto LAB_1403d4530;
              }
              uVar21 = uVar13 + 1;
              uVar13 = uVar18;
            }
            uVar18 = uVar13;
          } while (uVar21 < uVar13);
        }
        goto LAB_1403d46a1;
      }
    }
    else if ((uVar17 == 0xe) || (uVar17 - 0x11 < 2)) {
      if (uVar19 <= uVar3) {
        uVar21 = *(ulonglong *)(lVar16 + 0x30);
LAB_1403d46f2:
        uVar14 = 0;
        if (uVar21 != 0) {
          lVar10 = *(longlong *)(lVar16 + 0x28);
          uVar18 = uVar21;
          do {
            uVar13 = (uVar18 - uVar14 >> 1) + uVar14;
            lVar15 = *(longlong *)(lVar10 + uVar13 * 8);
            if (lVar15 == 0) {
              iVar9 = 0;
            }
            else {
              iVar9 = uVar17 - *(int *)(lVar15 + 8);
              if ((iVar9 == 0) && (uVar19 != 0xffffffff)) {
                iVar9 = uVar19 - *(int *)(lVar15 + 0xc);
              }
            }
            if (-1 < iVar9) {
              if (iVar9 < 1) {
                uVar14 = uVar13;
                if (uVar13 == 0) goto LAB_1403d479b;
                lVar15 = lVar10 + uVar13 * 8;
                goto LAB_1403d4770;
              }
              uVar14 = uVar13 + 1;
              uVar13 = uVar18;
            }
            uVar18 = uVar13;
          } while (uVar14 < uVar13);
        }
        goto LAB_1403d4800;
      }
    }
    else {
      lVar10 = *(longlong *)(*(longlong *)(lVar16 + 0x28) + uVar21 * 8);
      fVar24 = (float)FUN_1403d6d70(lVar10,*(undefined4 *)(lVar10 + 0x10),fVar22,fVar22);
    }
LAB_1403d4814:
    FUN_1407a1eb0(uVar17,fVar24,local_c8);
  }
LAB_1403d481e:
  uVar17 = uVar17 + 1;
  if (iVar2 < (int)uVar17) goto LAB_1403d4833;
  goto LAB_1403d43a0;
  while (uVar14 = uVar18, uVar18 != 0) {
LAB_1403d4770:
    lVar4 = *(longlong *)(lVar15 + -8);
    lVar15 = lVar15 + -8;
    uVar18 = uVar14 - 1;
    if ((lVar4 != 0) &&
       ((uVar17 != *(uint *)(lVar4 + 8) ||
        ((uVar19 != 0xffffffff && (uVar19 != *(uint *)(lVar4 + 0xc))))))) break;
  }
LAB_1403d479b:
  uVar13 = uVar13 + 1;
  if (uVar13 < uVar21) {
    plVar11 = (longlong *)(lVar10 + uVar13 * 8);
    do {
      lVar15 = *plVar11;
      if ((lVar15 != 0) &&
         ((uVar17 != *(uint *)(lVar15 + 8) ||
          ((uVar19 != 0xffffffff && (uVar19 != *(uint *)(lVar15 + 0xc))))))) break;
      uVar13 = uVar13 + 1;
      plVar11 = plVar11 + 1;
    } while (uVar13 < uVar21);
  }
  if (uVar14 < uVar13) {
    plVar11 = (longlong *)(lVar10 + uVar14 * 8);
    lVar10 = uVar13 - uVar14;
    do {
      fVar24 = (float)FUN_1403d6d70(*plVar11,*(undefined4 *)(*plVar11 + 0x10),fVar22,fVar24);
      plVar11 = plVar11 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
LAB_1403d4800:
  uVar19 = uVar19 + 1;
  if (uVar3 < uVar19) goto LAB_1403d4814;
  goto LAB_1403d46f2;
  while (uVar21 = uVar18, uVar18 != 0) {
LAB_1403d4530:
    lVar4 = *(longlong *)(lVar15 + -8);
    lVar15 = lVar15 + -8;
    uVar18 = uVar21 - 1;
    if ((lVar4 != 0) &&
       ((uVar17 != *(uint *)(lVar4 + 8) ||
        ((uVar19 != 0xffffffff && (uVar19 != *(uint *)(lVar4 + 0xc))))))) break;
  }
LAB_1403d455b:
  uVar13 = uVar13 + 1;
  if (uVar13 < uVar14) {
    plVar11 = (longlong *)(lVar10 + uVar13 * 8);
    do {
      lVar10 = *plVar11;
      if ((lVar10 != 0) &&
         ((uVar17 != *(uint *)(lVar10 + 8) ||
          ((uVar19 != 0xffffffff && (uVar19 != *(uint *)(lVar10 + 0xc))))))) break;
      uVar13 = uVar13 + 1;
      plVar11 = plVar11 + 1;
    } while (uVar13 < uVar14);
  }
  if (uVar21 != uVar13) {
    local_b8 = (float *)0x0;
    local_b0 = (float *)0x0;
    local_a8 = (float *)0x0;
    lVar10 = uVar13 - uVar21;
    if (lVar10 != 0) {
      pfVar12 = (float *)FUN_14018b280(lVar10 * 4);
      memcpy(pfVar12,(void *)0x0,0);
      local_a8 = pfVar12 + lVar10;
      local_b0 = pfVar12;
    }
    pfVar12 = local_b0;
    pfVar7 = local_b0;
    pfVar20 = local_a8;
    for (; lVar10 = 0, local_b8 = pfVar12, local_b0 = pfVar7, uVar21 < uVar13; uVar21 = uVar21 + 1)
    {
      lVar10 = *(longlong *)(*(longlong *)(lVar16 + 0x28) + uVar21 * 8);
      if (*(int *)(lVar10 + 0x10) == 2) break;
      fVar23 = (float)FUN_1403d6d70(lVar10,*(int *)(lVar10 + 0x10),fVar22,fVar24);
      if (pfVar7 == pfVar20) {
        FUN_1401e4420(local_c0);
        pfVar20 = local_a8;
      }
      else {
        if (pfVar7 != (float *)0x0) {
          *pfVar7 = fVar23;
        }
        local_b0 = pfVar7 + 1;
      }
      pfVar12 = local_b8;
      pfVar7 = local_b0;
    }
    fVar23 = 0.0;
    for (pfVar20 = pfVar12; pfVar20 != pfVar7; pfVar20 = pfVar20 + 1) {
      fVar23 = fVar23 + *pfVar20;
    }
    if (lVar10 != 0) {
      fVar23 = (float)FUN_1403d6d70(lVar10,*(undefined4 *)(lVar10 + 0x10),fVar22,fVar23);
    }
    fVar24 = fVar24 + fVar23;
    if (pfVar12 != (float *)0x0) {
      FUN_14018b900(pfVar12);
    }
  }
LAB_1403d46a1:
  uVar19 = uVar19 + 1;
  if (uVar3 < uVar19) goto LAB_1403d4814;
  goto LAB_1403d44b0;
}

