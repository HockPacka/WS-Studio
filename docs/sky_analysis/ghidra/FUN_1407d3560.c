
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1407d3560(longlong *param_1,uint param_2)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  longlong lVar12;
  int *piVar13;
  int *piVar14;
  uint uVar15;
  ulonglong uVar16;
  longlong lVar17;
  longlong *plVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  float fVar23;
  float fVar24;
  int local_res8 [2];
  float local_res18;
  float fStackX_1c;
  float local_res20;
  undefined1 local_res24 [4];
  undefined4 local_68 [12];
  
  uVar21 = 0;
  local_68[0] = 0;
  iVar10 = (**(code **)(*param_1 + 0x10))(param_1,local_68);
  if (iVar10 != 0) {
    *(undefined4 *)((longlong)param_1 + 0x5c) = 0;
    fVar23 = *(float *)(param_1[3] + 0xb98) * *(float *)(param_1 + 0xb);
    *(float *)((longlong)param_1 + 0x5c) = fVar23;
    fVar24 = 1.0 - *(float *)(param_1[3] + 0xb98);
    fVar23 = *(float *)(param_1[3] + 0xb94) * *(float *)((longlong)param_1 + 0x54) * fVar24 + fVar23
    ;
    *(float *)((longlong)param_1 + 0x5c) = fVar23;
    *(float *)((longlong)param_1 + 0x5c) =
         (1.0 - *(float *)(param_1[3] + 0xb94)) * fVar24 *
         *(float *)(param_1[3] + 0xb90) * *(float *)(param_1 + 10) + fVar23;
    uVar16 = uVar21;
    if (*(int *)(param_1[1] + 0x2e8) != 0) {
      do {
        lVar17 = uVar16 * 0x20 + param_1[0x23];
        iVar10 = (**(code **)(*param_1 + 0x80))(param_1,uVar16,local_res8,&local_res18,&local_res20)
        ;
        if (iVar10 == 2) {
          lVar12 = *(longlong *)(*(longlong *)(param_1[1] + 0x2f0) + 0x28 + uVar16 * 0x30);
          fVar23 = *(float *)((longlong)local_res8[0] * 0x20 + lVar12);
          *(float *)(lVar17 + 8) =
               (*(float *)((longlong)(int)local_res18 * 0x20 + lVar12) - fVar23) * local_res20 +
               fVar23;
          lVar12 = *(longlong *)(*(longlong *)(param_1[1] + 0x2f0) + 0x28 + uVar16 * 0x30);
          fVar23 = *(float *)((longlong)local_res8[0] * 0x20 + 4 + lVar12);
          *(float *)(lVar17 + 0xc) =
               (*(float *)((longlong)(int)local_res18 * 0x20 + 4 + lVar12) - fVar23) * local_res20 +
               fVar23;
          lVar12 = *(longlong *)(*(longlong *)(param_1[1] + 0x2f0) + 0x28 + uVar16 * 0x30);
          pfVar1 = (float *)((longlong)local_res8[0] * 0x20 + 0x10 + lVar12);
          fVar23 = pfVar1[1];
          fVar24 = pfVar1[2];
          fVar4 = pfVar1[3];
          pfVar2 = (float *)((longlong)(int)local_res18 * 0x20 + 0x10 + lVar12);
          fVar5 = pfVar2[1];
          fVar6 = pfVar2[2];
          fVar7 = pfVar2[3];
          *(float *)(lVar17 + 0x10) = (*pfVar2 - *pfVar1) * local_res20 + *pfVar1;
          *(float *)(lVar17 + 0x14) = (fVar5 - fVar23) * local_res20 + fVar23;
          *(float *)(lVar17 + 0x18) = (fVar6 - fVar24) * local_res20 + fVar24;
          *(float *)(lVar17 + 0x1c) = (fVar7 - fVar4) * local_res20 + fVar4;
        }
        else if (iVar10 == 1) {
          *(undefined4 *)(lVar17 + 8) =
               *(undefined4 *)
                ((longlong)local_res8[0] * 0x20 +
                *(longlong *)(*(longlong *)(param_1[1] + 0x2f0) + 0x28 + uVar16 * 0x30));
          *(undefined4 *)(lVar17 + 0xc) =
               *(undefined4 *)
                (*(longlong *)(*(longlong *)(param_1[1] + 0x2f0) + 0x28 + uVar16 * 0x30) + 4 +
                (longlong)local_res8[0] * 0x20);
          puVar3 = (undefined4 *)
                   (*(longlong *)(*(longlong *)(param_1[1] + 0x2f0) + 0x28 + uVar16 * 0x30) + 0x10 +
                   (longlong)local_res8[0] * 0x20);
          uVar11 = puVar3[1];
          uVar8 = puVar3[2];
          uVar9 = puVar3[3];
          *(undefined4 *)(lVar17 + 0x10) = *puVar3;
          *(undefined4 *)(lVar17 + 0x14) = uVar11;
          *(undefined4 *)(lVar17 + 0x18) = uVar8;
          *(undefined4 *)(lVar17 + 0x1c) = uVar9;
        }
        uVar15 = (int)uVar16 + 1;
        uVar16 = (ulonglong)uVar15;
      } while (uVar15 < *(uint *)(param_1[1] + 0x2e8));
    }
    (**(code **)(*param_1 + 0x1c8))(param_1,param_1 + 0x196,param_1[1] + 0x28,param_1 + 0x3e);
    (**(code **)(*param_1 + 0x1c8))(param_1,param_1 + 0x1ba,param_1[1] + 0x158,param_1 + 0xba);
    (**(code **)(*param_1 + 0x1c8))(param_1,param_1 + 0x1a8,param_1[1] + 0xc0,param_1 + 0x7c);
    (**(code **)(*param_1 + 0x1c8))(param_1,param_1 + 0x1cc,param_1[1] + 0x1f0,param_1 + 0xf8);
    uVar9 = uRam0000000140c777dc;
    uVar8 = uRam0000000140c777d8;
    uVar11 = uRam0000000140c777d4;
    piVar13 = (int *)(param_1[1] + 0x288);
    if (*piVar13 == 0) {
      *(undefined4 *)(param_1 + 0x136) = _DAT_140c777d0;
      *(undefined4 *)((longlong)param_1 + 0x9b4) = uVar11;
      *(undefined4 *)(param_1 + 0x137) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0x9bc) = uVar9;
    }
    else if (*piVar13 != 0) {
      FUN_1407d8350(piVar13,*(undefined4 *)(param_1[3] + 0x520));
    }
    piVar13 = (int *)(param_1[1] + 0x2a0);
    if (*piVar13 == 0) {
      param_1[0x13a] = 0;
      uVar9 = uRam0000000140c777dc;
      uVar8 = uRam0000000140c777d8;
      uVar11 = uRam0000000140c777d4;
      *(undefined4 *)(param_1 + 0x13c) = _DAT_140c777d0;
      *(undefined4 *)((longlong)param_1 + 0x9e4) = uVar11;
      *(undefined4 *)(param_1 + 0x13d) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0x9ec) = uVar9;
    }
    else if (*piVar13 != 0) {
      FUN_1407d8590(piVar13,*(undefined4 *)(param_1[3] + 0x520));
    }
    uVar9 = uRam0000000140c777dc;
    uVar8 = uRam0000000140c777d8;
    uVar11 = uRam0000000140c777d4;
    piVar13 = (int *)(param_1[1] + 0x2b8);
    if (*piVar13 == 0) {
      *(undefined4 *)(param_1 + 0x140) = _DAT_140c777d0;
      *(undefined4 *)((longlong)param_1 + 0xa04) = uVar11;
      *(undefined4 *)(param_1 + 0x141) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0xa0c) = uVar9;
    }
    else if (*piVar13 != 0) {
      FUN_1407d88c0(piVar13,*(undefined4 *)(param_1[3] + 0x520));
    }
    piVar13 = DAT_140c63750;
    piVar14 = (int *)(param_1[1] + 0x2d0);
    if (*piVar14 == 0) {
      iVar10 = DAT_140c55f70;
      if (*DAT_140c63750 < DAT_140c55f70) {
        iVar10 = *DAT_140c63750;
      }
      *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(&DAT_140c55f80 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55fd0;
      if (*piVar13 < DAT_140c55fd0) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa24) =
           *(undefined4 *)(&DAT_140c55fe0 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c56030;
      if (*piVar13 < DAT_140c56030) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 0x146) = *(undefined4 *)(&DAT_140c56040 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c56090;
      if (*piVar13 < DAT_140c56090) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa34) =
           *(undefined4 *)(&DAT_140c560a0 + (longlong)iVar10 * 4);
    }
    else if (*piVar14 != 0) {
      FUN_1407d8b00(piVar14,*(undefined4 *)(param_1[3] + 0x520),param_1 + 0x144,param_1 + 0x147);
    }
    uVar9 = uRam0000000140c777dc;
    uVar8 = uRam0000000140c777d8;
    uVar11 = uRam0000000140c777d4;
    piVar14 = (int *)(param_1[1] + 0x360);
    if (*piVar14 == 0) {
      *(undefined4 *)(param_1 + 0x156) = _DAT_140c777d0;
      *(undefined4 *)((longlong)param_1 + 0xab4) = uVar11;
      *(undefined4 *)(param_1 + 0x157) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0xabc) = uVar9;
    }
    else if (*piVar14 != 0) {
      FUN_1407d88c0(piVar14,*(undefined4 *)(param_1[3] + 0x520));
    }
    piVar14 = (int *)(param_1[1] + 0x398);
    if (*piVar14 == 0) {
      *(undefined4 *)(param_1 + 0x15a) = 0;
    }
    else if (*piVar14 != 0) {
      FUN_140309410(piVar14,*(undefined4 *)(param_1[3] + 0x520));
    }
    uVar9 = uRam0000000140c777dc;
    uVar8 = uRam0000000140c777d8;
    uVar11 = uRam0000000140c777d4;
    piVar14 = (int *)(param_1[1] + 0x3b0);
    if (*piVar14 == 0) {
      *(undefined4 *)(param_1 + 0x15c) = _DAT_140c777d0;
      *(undefined4 *)((longlong)param_1 + 0xae4) = uVar11;
      *(undefined4 *)(param_1 + 0x15d) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0xaec) = uVar9;
    }
    else if (*piVar14 != 0) {
      FUN_1407d88c0(piVar14,*(undefined4 *)(param_1[3] + 0x520));
    }
    uVar9 = uRam0000000140c777fc;
    uVar8 = uRam0000000140c777f8;
    uVar11 = uRam0000000140c777f4;
    piVar14 = (int *)(param_1[1] + 0x3c8);
    if (*piVar14 == 0) {
      *(undefined4 *)(param_1 + 0x192) = _DAT_140c777f0;
      *(undefined4 *)((longlong)param_1 + 0xc94) = uVar11;
      *(undefined4 *)(param_1 + 0x193) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0xc9c) = uVar9;
    }
    else if (*piVar14 != 0) {
      FUN_1407d88c0(piVar14,*(undefined4 *)(param_1[3] + 0x520));
    }
    plVar18 = param_1 + 0x160;
    uVar16 = uVar21;
    do {
      uVar9 = uRam0000000140c777dc;
      uVar8 = uRam0000000140c777d8;
      uVar11 = uRam0000000140c777d4;
      piVar14 = (int *)(param_1[1] + 0x3e0 + uVar16);
      if (*piVar14 == 0) {
        *(undefined4 *)plVar18 = _DAT_140c777d0;
        *(undefined4 *)((longlong)plVar18 + 4) = uVar11;
        *(undefined4 *)(plVar18 + 1) = uVar8;
        *(undefined4 *)((longlong)plVar18 + 0xc) = uVar9;
        plVar18[2] = 0x3f8000003f800000;
        plVar18[3] = 0x3f8000003f800000;
      }
      else {
        FUN_1407d13d0(*(undefined4 *)(param_1[3] + 0x520),piVar14,plVar18);
      }
      uVar16 = uVar16 + 0x18;
      plVar18 = plVar18 + 6;
    } while (uVar16 < 0xc0);
    piVar14 = (int *)(param_1[1] + 0x2f8);
    if (*piVar14 == 0) {
      iVar10 = DAT_140c55c10;
      if (*piVar13 < DAT_140c55c10) {
        iVar10 = *piVar13;
      }
      lVar17 = (longlong)iVar10 * 0x10;
      uVar11 = *(undefined4 *)(lVar17 + 0x140c55c24);
      uVar8 = *(undefined4 *)(lVar17 + 0x140c55c28);
      uVar9 = *(undefined4 *)(lVar17 + 0x140c55c2c);
      *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(&DAT_140c55c20 + lVar17);
      *(undefined4 *)((longlong)param_1 + 0xa44) = uVar11;
      *(undefined4 *)(param_1 + 0x149) = uVar8;
      *(undefined4 *)((longlong)param_1 + 0xa4c) = uVar9;
      iVar10 = DAT_140c55cd0;
      if (*piVar13 < DAT_140c55cd0) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 0x14b) = *(undefined4 *)(&DAT_140c55ce0 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55d30;
      if (*piVar13 < DAT_140c55d30) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa5c) =
           *(undefined4 *)(&DAT_140c55d40 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55d90;
      if (*piVar13 < DAT_140c55d90) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(&DAT_140c55da0 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c40110;
      if (*piVar13 < DAT_140c40110) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa64) =
           *(undefined4 *)(&DAT_140c40120 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c40170;
      if (*piVar13 < DAT_140c40170) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa7c) =
           *(undefined4 *)(&DAT_140c40180 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c401d0;
      if (*piVar13 < DAT_140c401d0) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(&DAT_140c401e0 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c40230;
      if (*piVar13 < DAT_140c40230) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa84) =
           *(undefined4 *)(&DAT_140c40240 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55df0;
      if (*piVar13 < DAT_140c55df0) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 0x151) = *(undefined4 *)(&DAT_140c55e00 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55e50;
      if (*piVar13 < DAT_140c55e50) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa8c) =
           *(undefined4 *)(&DAT_140c55e60 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55eb0;
      if (*piVar13 < DAT_140c55eb0) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 0x152) = *(undefined4 *)(&DAT_140c55ec0 + (longlong)iVar10 * 4);
      iVar10 = DAT_140c55f10;
      if (*piVar13 < DAT_140c55f10) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)((longlong)param_1 + 0xa94) =
           *(undefined4 *)(&DAT_140c55f20 + (longlong)iVar10 * 4);
    }
    else if (*piVar14 != 0) {
      FUN_1407d8f40(piVar14,*(undefined4 *)(param_1[3] + 0x520));
    }
    if (*(int *)(param_1[1] + 0xa8) != 0) {
      FUN_1407d9700((int *)(param_1[1] + 0xa8),*(undefined4 *)(param_1[3] + 0x520));
    }
    if (*(int *)(param_1[1] + 0x140) != 0) {
      FUN_1407d9700((int *)(param_1[1] + 0x140),*(undefined4 *)(param_1[3] + 0x520));
    }
    if (*(int *)(param_1[1] + 0x1d8) != 0) {
      FUN_1407d9700((int *)(param_1[1] + 0x1d8),*(undefined4 *)(param_1[3] + 0x520));
    }
    if (*(int *)(param_1[1] + 0x270) != 0) {
      FUN_1407d9700((int *)(param_1[1] + 0x270),*(undefined4 *)(param_1[3] + 0x520));
    }
    piVar14 = (int *)(param_1[1] + 0x328);
    if (*piVar14 == 0) {
      iVar10 = DAT_140c560f0;
      if (*piVar13 < DAT_140c560f0) {
        iVar10 = *piVar13;
      }
      *(undefined4 *)(param_1 + 400) = *(undefined4 *)(&DAT_140c56100 + (longlong)iVar10 * 4);
    }
    else if (*piVar14 != 0) {
      FUN_140309410(piVar14,*(undefined4 *)(param_1[3] + 0x520));
    }
    uVar11 = (**(code **)(*param_1 + 0x88))
                       (param_1,*(undefined8 *)(param_1[1] + 0x318),
                        *(undefined4 *)(param_1[1] + 0x310),param_1 + 0x27,(longlong)param_1 + 0x13c
                        ,param_1 + 0x28);
    *(undefined4 *)((longlong)param_1 + 0x144) = uVar11;
    if ((((param_2 & 1) != 0) && (*(longlong *)(param_1[3] + 0x10) != 0)) &&
       (0.0 < *(float *)((longlong)param_1 + 0x5c))) {
      iVar10 = DAT_140c55bd0;
      if (*DAT_140c63750 < DAT_140c55bd0) {
        iVar10 = *DAT_140c63750;
      }
      if (((&DAT_140c55be0)[iVar10] != '\0') &&
         (uVar16 = uVar21, uVar20 = uVar21, uVar22 = uVar21, param_1[0x3c] != 0)) {
        do {
          _local_res18 = 0x3f800000;
          uVar15 = (**(code **)(*param_1 + 0x88))
                             (param_1,*(undefined8 *)
                                       (*(longlong *)(param_1[1] + 0x4a8) + 8 + uVar22),
                              *(undefined4 *)(*(longlong *)(param_1[1] + 0x4a8) + uVar22),
                              &local_res20,local_res24,&fStackX_1c);
          if (uVar15 != 0) {
            _local_res18 = CONCAT44(fStackX_1c,1.0 - fStackX_1c);
            uVar19 = uVar21;
            do {
              lVar12 = (longlong)*(int *)(local_res24 + uVar19 * 4 + -4);
              lVar17 = *(longlong *)(uVar16 + param_1[0x3b]);
              if ((-1 < *(int *)(param_1[3] + 0x528) - *(int *)(lVar17 + 8 + lVar12 * 0xc)) &&
                 (0.0 < (&local_res18)[uVar19])) {
                plVar18 = *(longlong **)(param_1[3] + 0x10);
                iVar10 = (**(code **)(*plVar18 + 0x100))
                                   (plVar18,*(undefined4 *)(lVar17 + 4 + lVar12 * 0xc),
                                    *(undefined4 *)(lVar17 + lVar12 * 0xc),
                                    (&local_res18)[uVar19] * *(float *)((longlong)param_1 + 0x5c),
                                    local_res8);
                if (iVar10 < 0) {
                  iVar10 = *(int *)(param_1[3] + 0x528) + 0x7fffffff;
                }
                else {
                  iVar10 = local_res8[0] + *(int *)(param_1[3] + 0x528);
                }
                *(int *)(*(longlong *)(uVar16 + param_1[0x3b]) + 8 +
                        (longlong)*(int *)(local_res24 + uVar19 * 4 + -4) * 0xc) = iVar10;
              }
              uVar19 = uVar19 + 1;
            } while (uVar19 < uVar15);
          }
          uVar20 = uVar20 + 1;
          uVar16 = uVar16 + 0x10;
          uVar22 = uVar22 + 0x18;
        } while (uVar20 < (ulonglong)param_1[0x3c]);
      }
    }
  }
  return;
}

