
void FUN_1403d4910(undefined8 param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  float *pfVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined8 *_Src;
  longlong *plVar11;
  undefined8 *puVar12;
  float *pfVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined8 *puVar16;
  ulonglong uVar17;
  longlong lVar18;
  longlong lVar19;
  uint uVar20;
  ulonglong uVar21;
  uint uVar22;
  float *pfVar23;
  ulonglong uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined8 *local_c8;
  undefined1 local_c0 [8];
  float *local_b8;
  float *local_b0;
  float *local_a8;
  undefined8 *local_a0;
  longlong local_98;
  longlong local_90;
  uint local_88 [2];
  undefined8 *local_80;
  undefined1 local_78 [56];
  
  uVar8 = DAT_140c65b70;
  lVar19 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x10);
  if (lVar19 != *(longlong *)(param_2 + 8)) {
    do {
      uVar1 = *(uint *)(lVar19 + 0x20);
      if ((*(longlong *)(lVar19 + 0x30) != 0) &&
         (_Src = (undefined8 *)FUN_1407a1080(uVar8,uVar1), local_a0 = _Src,
         _Src != (undefined8 *)0x0)) {
        lVar14 = *(longlong *)(param_3 + 8);
        lVar4 = lVar14;
        lVar18 = *(longlong *)(lVar14 + 8);
        while (lVar18 != 0) {
          if (*(uint *)(lVar18 + 0x20) < uVar1) {
            lVar18 = *(longlong *)(lVar18 + 0x18);
          }
          else {
            lVar4 = lVar18;
            lVar18 = *(longlong *)(lVar18 + 0x10);
          }
        }
        if ((lVar4 == lVar14) || (uVar1 < *(uint *)(lVar4 + 0x20))) {
          local_98 = lVar14;
          plVar11 = &local_98;
        }
        else {
          local_90 = lVar4;
          plVar11 = &local_90;
        }
        bVar6 = false;
        if (*plVar11 == lVar14) {
          local_c8 = (undefined8 *)FUN_14018b280(0xa8,0);
          if ((((uint)_Src | (uint)local_c8) & 0xf) == 0) {
            lVar14 = 1;
            puVar9 = local_c8;
            do {
              puVar16 = puVar9;
              puVar12 = _Src;
              uVar5 = puVar12[1];
              *puVar16 = *puVar12;
              puVar16[1] = uVar5;
              uVar5 = puVar12[3];
              puVar16[2] = puVar12[2];
              puVar16[3] = uVar5;
              uVar5 = puVar12[5];
              puVar16[4] = puVar12[4];
              puVar16[5] = uVar5;
              uVar5 = puVar12[7];
              puVar16[6] = puVar12[6];
              puVar16[7] = uVar5;
              uVar5 = puVar12[9];
              puVar16[8] = puVar12[8];
              puVar16[9] = uVar5;
              uVar5 = puVar12[0xb];
              puVar16[10] = puVar12[10];
              puVar16[0xb] = uVar5;
              uVar5 = puVar12[0xd];
              puVar16[0xc] = puVar12[0xc];
              puVar16[0xd] = uVar5;
              uVar5 = puVar12[0xf];
              puVar16[0xe] = puVar12[0xe];
              puVar16[0xf] = uVar5;
              lVar14 = lVar14 + -1;
              _Src = puVar12 + 0x10;
              puVar9 = puVar16 + 0x10;
            } while (lVar14 != 0);
            uVar5 = puVar12[0x11];
            bVar6 = true;
            puVar16[0x10] = puVar12[0x10];
            puVar16[0x11] = uVar5;
            uVar5 = puVar12[0x13];
            puVar16[0x12] = puVar12[0x12];
            puVar16[0x13] = uVar5;
            puVar16[0x14] = puVar12[0x14];
          }
          else {
            memcpy(local_c8,_Src,0xa8);
            bVar6 = true;
          }
        }
        else {
          local_c8 = *(undefined8 **)(*plVar11 + 0x28);
        }
        uVar20 = *(uint *)(**(longlong **)(lVar19 + 0x28) + 0xc);
        iVar2 = *(int *)((*(longlong **)(lVar19 + 0x28))[*(longlong *)(lVar19 + 0x30) + -1] + 0xc);
        if ((int)uVar20 <= iVar2) {
LAB_1403d4ae0:
          uVar17 = *(ulonglong *)(lVar19 + 0x30);
          uVar24 = 0;
          if (uVar17 != 0) {
            lVar14 = *(longlong *)(lVar19 + 0x28);
            uVar21 = uVar17;
            do {
              uVar15 = (uVar21 - uVar24 >> 1) + uVar24;
              lVar18 = *(longlong *)(lVar14 + uVar15 * 8);
              if (lVar18 == 0) {
                iVar10 = 0;
              }
              else {
                iVar10 = uVar20 - *(int *)(lVar18 + 0xc);
              }
              if (-1 < iVar10) {
                if (iVar10 < 1) {
                  uVar24 = uVar15;
                  if (uVar15 == 0) goto LAB_1403d4b6f;
                  lVar18 = lVar14 + uVar15 * 8;
                  goto LAB_1403d4b50;
                }
                uVar24 = uVar15 + 1;
                uVar15 = uVar21;
              }
              uVar21 = uVar15;
            } while (uVar24 < uVar15);
          }
          goto LAB_1403d4f69;
        }
LAB_1403d4f7e:
        if (bVar6) {
          local_88[0] = uVar1;
          local_80 = local_c8;
          FUN_140055f80(param_3,local_78,local_88);
        }
      }
      lVar14 = *(longlong *)(lVar19 + 0x18);
      if (lVar14 == 0) {
        lVar14 = *(longlong *)(lVar19 + 8);
        if (lVar19 == *(longlong *)(lVar14 + 0x18)) {
          do {
            lVar19 = lVar14;
            lVar14 = *(longlong *)(lVar19 + 8);
          } while (lVar19 == *(longlong *)(lVar14 + 0x18));
        }
        if (*(longlong *)(lVar19 + 0x18) != lVar14) {
          lVar19 = lVar14;
        }
      }
      else {
        for (lVar18 = *(longlong *)(lVar14 + 0x10); lVar19 = lVar14, lVar18 != 0;
            lVar18 = *(longlong *)(lVar18 + 0x10)) {
          lVar14 = lVar18;
        }
      }
    } while (lVar19 != *(longlong *)(param_2 + 8));
  }
  return;
  while (uVar24 = uVar21, uVar21 != 0) {
LAB_1403d4b50:
    plVar11 = (longlong *)(lVar18 + -8);
    lVar18 = lVar18 + -8;
    uVar21 = uVar24 - 1;
    if ((*plVar11 != 0) && (uVar20 != *(uint *)(*plVar11 + 0xc))) break;
  }
LAB_1403d4b6f:
  uVar15 = uVar15 + 1;
  if (uVar15 < uVar17) {
    plVar11 = (longlong *)(lVar14 + uVar15 * 8);
    do {
      if ((*plVar11 != 0) && (uVar20 != *(uint *)(*plVar11 + 0xc))) break;
      uVar15 = uVar15 + 1;
      plVar11 = plVar11 + 1;
    } while (uVar15 < uVar17);
  }
  if (uVar24 != uVar15) {
    uVar22 = *(uint *)(*(longlong *)(lVar14 + uVar24 * 8) + 0x10);
    uVar3 = *(uint *)(*(longlong *)(lVar14 + -8 + uVar15 * 8) + 0x10);
    fVar25 = (float)FUN_1407a1c30(uVar20);
    fVar27 = fVar25;
    if ((uVar20 < 0x12) && ((0x30fdcU >> (uVar20 & 0x1f) & 1) != 0)) {
      if (uVar22 <= uVar3) {
LAB_1403d4bf0:
        uVar17 = *(ulonglong *)(lVar19 + 0x30);
        uVar24 = 0;
        if (uVar17 != 0) {
          lVar14 = *(longlong *)(lVar19 + 0x28);
          uVar21 = uVar17;
          do {
            uVar15 = (uVar21 - uVar24 >> 1) + uVar24;
            lVar18 = *(longlong *)(lVar14 + uVar15 * 8);
            if (lVar18 == 0) {
              iVar10 = 0;
            }
            else {
              iVar10 = uVar20 - *(int *)(lVar18 + 0xc);
              if ((iVar10 == 0) && (uVar22 != 0xffffffff)) {
                iVar10 = uVar22 - *(int *)(lVar18 + 0x10);
              }
            }
            if (-1 < iVar10) {
              if (iVar10 < 1) {
                uVar24 = uVar15;
                if (uVar15 == 0) goto LAB_1403d4c9b;
                lVar18 = lVar14 + uVar15 * 8;
                goto LAB_1403d4c70;
              }
              uVar24 = uVar15 + 1;
              uVar15 = uVar21;
            }
            uVar21 = uVar15;
          } while (uVar24 < uVar15);
        }
        goto LAB_1403d4de1;
      }
    }
    else if (((uVar20 & 0xfffffffa) == 0) && (uVar20 != 4)) {
      if (uVar22 <= uVar3) {
        uVar24 = *(ulonglong *)(lVar19 + 0x30);
LAB_1403d4e20:
        uVar17 = 0;
        if (uVar24 != 0) {
          lVar14 = *(longlong *)(lVar19 + 0x28);
          uVar21 = uVar24;
          do {
            uVar15 = (uVar21 - uVar17 >> 1) + uVar17;
            lVar18 = *(longlong *)(lVar14 + uVar15 * 8);
            if (lVar18 == 0) {
              iVar10 = 0;
            }
            else {
              iVar10 = uVar20 - *(int *)(lVar18 + 0xc);
              if ((iVar10 == 0) && (uVar22 != 0xffffffff)) {
                iVar10 = uVar22 - *(int *)(lVar18 + 0x10);
              }
            }
            if (-1 < iVar10) {
              if (iVar10 < 1) {
                uVar17 = uVar15;
                if (uVar15 == 0) goto LAB_1403d4ecb;
                lVar18 = lVar14 + uVar15 * 8;
                goto LAB_1403d4ea0;
              }
              uVar17 = uVar15 + 1;
              uVar15 = uVar21;
            }
            uVar21 = uVar15;
          } while (uVar17 < uVar15);
        }
        goto LAB_1403d4f30;
      }
    }
    else {
      lVar14 = *(longlong *)(*(longlong *)(lVar19 + 0x28) + uVar24 * 8);
      fVar27 = (float)FUN_1403d6f20(lVar14,*(undefined4 *)(lVar14 + 0x14),fVar25,fVar25);
    }
LAB_1403d4f5f:
    FUN_1407a2620(uVar20,fVar27,local_c8);
  }
LAB_1403d4f69:
  uVar20 = uVar20 + 1;
  if (iVar2 < (int)uVar20) goto LAB_1403d4f7e;
  goto LAB_1403d4ae0;
  while (uVar17 = uVar21, uVar21 != 0) {
LAB_1403d4ea0:
    lVar4 = *(longlong *)(lVar18 + -8);
    lVar18 = lVar18 + -8;
    uVar21 = uVar17 - 1;
    if ((lVar4 != 0) &&
       ((uVar20 != *(uint *)(lVar4 + 0xc) ||
        ((uVar22 != 0xffffffff && (uVar22 != *(uint *)(lVar4 + 0x10))))))) break;
  }
LAB_1403d4ecb:
  uVar15 = uVar15 + 1;
  if (uVar15 < uVar24) {
    plVar11 = (longlong *)(lVar14 + uVar15 * 8);
    do {
      lVar18 = *plVar11;
      if ((lVar18 != 0) &&
         ((uVar20 != *(uint *)(lVar18 + 0xc) ||
          ((uVar22 != 0xffffffff && (uVar22 != *(uint *)(lVar18 + 0x10))))))) break;
      uVar15 = uVar15 + 1;
      plVar11 = plVar11 + 1;
    } while (uVar15 < uVar24);
  }
  if (uVar17 < uVar15) {
    plVar11 = (longlong *)(lVar14 + uVar17 * 8);
    lVar14 = uVar15 - uVar17;
    do {
      fVar27 = (float)FUN_1403d6f20(*plVar11,*(undefined4 *)(*plVar11 + 0x14),fVar25,fVar27);
      plVar11 = plVar11 + 1;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
  }
LAB_1403d4f30:
  uVar22 = uVar22 + 1;
  if (uVar3 < uVar22) goto LAB_1403d4f5f;
  goto LAB_1403d4e20;
  while (uVar24 = uVar21, uVar21 != 0) {
LAB_1403d4c70:
    lVar4 = *(longlong *)(lVar18 + -8);
    lVar18 = lVar18 + -8;
    uVar21 = uVar24 - 1;
    if ((lVar4 != 0) &&
       ((uVar20 != *(uint *)(lVar4 + 0xc) ||
        ((uVar22 != 0xffffffff && (uVar22 != *(uint *)(lVar4 + 0x10))))))) break;
  }
LAB_1403d4c9b:
  uVar15 = uVar15 + 1;
  if (uVar15 < uVar17) {
    plVar11 = (longlong *)(lVar14 + uVar15 * 8);
    do {
      lVar14 = *plVar11;
      if ((lVar14 != 0) &&
         ((uVar20 != *(uint *)(lVar14 + 0xc) ||
          ((uVar22 != 0xffffffff && (uVar22 != *(uint *)(lVar14 + 0x10))))))) break;
      uVar15 = uVar15 + 1;
      plVar11 = plVar11 + 1;
    } while (uVar15 < uVar17);
  }
  if (uVar24 != uVar15) {
    local_b8 = (float *)0x0;
    local_b0 = (float *)0x0;
    local_a8 = (float *)0x0;
    lVar14 = uVar15 - uVar24;
    if (lVar14 != 0) {
      pfVar13 = (float *)FUN_14018b280(lVar14 * 4);
      memcpy(pfVar13,(void *)0x0,0);
      local_a8 = pfVar13 + lVar14;
      local_b0 = pfVar13;
    }
    pfVar13 = local_b0;
    pfVar7 = local_b0;
    pfVar23 = local_a8;
    for (; lVar14 = 0, local_b8 = pfVar13, local_b0 = pfVar7, uVar24 < uVar15; uVar24 = uVar24 + 1)
    {
      lVar14 = *(longlong *)(*(longlong *)(lVar19 + 0x28) + uVar24 * 8);
      if (*(int *)(lVar14 + 0x14) == 2) break;
      fVar26 = (float)FUN_1403d6f20(lVar14,*(int *)(lVar14 + 0x14),fVar25,fVar27);
      if (pfVar7 == pfVar23) {
        FUN_1401e4420(local_c0);
        pfVar23 = local_a8;
      }
      else {
        if (pfVar7 != (float *)0x0) {
          *pfVar7 = fVar26;
        }
        local_b0 = pfVar7 + 1;
      }
      pfVar13 = local_b8;
      pfVar7 = local_b0;
    }
    fVar26 = 0.0;
    for (pfVar23 = pfVar13; pfVar23 != pfVar7; pfVar23 = pfVar23 + 1) {
      fVar26 = fVar26 + *pfVar23;
    }
    if (lVar14 != 0) {
      fVar26 = (float)FUN_1403d6f20(lVar14,*(undefined4 *)(lVar14 + 0x14),fVar25,fVar26);
    }
    fVar27 = fVar27 + fVar26;
    if (pfVar13 != (float *)0x0) {
      FUN_14018b900(pfVar13);
    }
  }
LAB_1403d4de1:
  uVar22 = uVar22 + 1;
  if (uVar3 < uVar22) goto LAB_1403d4f5f;
  goto LAB_1403d4bf0;
}

