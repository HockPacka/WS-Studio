
==== FUN_140310f70 @ 140310f70 size 4990 ====
CALLERS:
CALLEES: FUN_1403266d0 FUN_1402f6470 FUN_1402fa120 FUN_1402fa240 FUN_140312d80 FUN_1400523e0 memcpy FUN_1402c8730 FUN_14018db00

undefined8
FUN_140310f70(longlong param_1,longlong param_2,undefined8 *param_3,longlong param_4,uint param_5,
             int param_6,undefined8 *param_7,undefined8 *param_8)

{
  longlong *plVar1;
  float *pfVar2;
  longlong *plVar3;
  float fVar4;
  ushort uVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  byte bVar9;
  undefined8 uVar10;
  float fVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int *piVar16;
  void *_Dst;
  longlong *plVar17;
  longlong lVar18;
  longlong *plVar19;
  longlong lVar20;
  ushort *puVar21;
  undefined8 *puVar22;
  longlong lVar23;
  longlong lVar24;
  byte bVar25;
  longlong *plVar26;
  uint uVar27;
  longlong lVar28;
  ulonglong uVar29;
  longlong lVar30;
  longlong lVar31;
  ulonglong uVar32;
  uint uVar33;
  ulonglong uVar34;
  longlong lVar35;
  uint local_ac;
  uint local_a4;
  longlong local_a0;
  longlong *local_88;
  undefined4 local_68 [12];
  
  uVar10 = param_3[1];
  *(undefined8 *)(param_1 + 0x590) = *param_3;
  *(undefined8 *)(param_1 + 0x598) = uVar10;
  uVar10 = param_3[3];
  *(undefined8 *)(param_1 + 0x5a0) = param_3[2];
  *(undefined8 *)(param_1 + 0x5a8) = uVar10;
  uVar10 = param_3[5];
  *(undefined8 *)(param_1 + 0x5b0) = param_3[4];
  *(undefined8 *)(param_1 + 0x5b8) = uVar10;
  uVar10 = param_3[7];
  *(undefined8 *)(param_1 + 0x5c0) = param_3[6];
  *(undefined8 *)(param_1 + 0x5c8) = uVar10;
  if ((param_5 & 1) == 0) {
    if ((param_5 & 2) == 0) {
      if ((param_5 & 4) == 0) {
        param_5 = param_5 | 1;
      }
      else {
        param_5 = param_5 & 0xfffffffc;
      }
    }
    else {
      param_5 = param_5 & 0xfffffffa;
    }
  }
  else {
    param_5 = param_5 & 0xfffffff9;
  }
  FUN_1402c8730(param_1 + 0x230,param_4);
  puVar22 = (undefined8 *)0x0;
  uVar12 = param_5 & 4;
  *(uint *)(param_1 + 0x570) = param_5;
  if (uVar12 == 0) {
    puVar22 = *(undefined8 **)(param_4 + 0x300);
  }
  if (*(undefined8 **)(param_1 + 0x578) != puVar22) {
    if (puVar22 != (undefined8 *)0x0) {
      (**(code **)*puVar22)(puVar22);
    }
    if (*(longlong **)(param_1 + 0x578) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x578) + 8))();
    }
    *(undefined8 **)(param_1 + 0x578) = puVar22;
  }
  (**(code **)(*DAT_140c65688 + 0x100))
            (DAT_140c65688,*(undefined8 *)(param_1 + 0x578),param_1 + 0x560);
  if (*(undefined8 **)(param_1 + 0x580) != param_7) {
    if (param_7 != (undefined8 *)0x0) {
      (**(code **)*param_7)(param_7);
    }
    if (*(longlong **)(param_1 + 0x580) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x580) + 8))();
    }
    *(undefined8 **)(param_1 + 0x580) = param_7;
  }
  if (*(undefined8 **)(param_1 + 0x588) != param_8) {
    if (param_8 != (undefined8 *)0x0) {
      (**(code **)*param_8)(param_8);
    }
    if (*(longlong **)(param_1 + 0x588) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x588) + 8))();
    }
    *(undefined8 **)(param_1 + 0x588) = param_8;
  }
  piVar16 = (int *)(**(code **)(*DAT_140c65670 + 0x230))();
  fVar11 = DAT_140b79ed0;
  *(ulonglong *)(param_1 + 0x540) = CONCAT44((float)piVar16[1],(float)*piVar16);
  *(undefined8 *)(param_1 + 0x548) = 0;
  *(ulonglong *)(param_1 + 0x550) =
       CONCAT44(fVar11 / *(float *)(param_1 + 0x544),fVar11 / *(float *)(param_1 + 0x540));
  *(undefined8 *)(param_1 + 0x558) = 0;
  fVar11 = DAT_140b79ec8;
  lVar7 = *(longlong *)(param_1 + 200);
  do {
    if (lVar7 == 0) {
      return 0;
    }
    plVar8 = *(longlong **)(param_1 + 200);
    if ((longlong *)plVar8[0x2d] != (longlong *)0x0) {
      *(longlong *)plVar8[0x2d] = plVar8[0x2e];
    }
    if (plVar8[0x2e] != 0) {
      *(longlong *)(plVar8[0x2e] + 0x168) = plVar8[0x2d];
    }
    plVar8[0x2d] = 0;
    plVar8[0x2e] = 0;
    if (((*(uint *)(param_1 + 0x570) & 0x400) == 0) || ((*(byte *)(plVar8[8] + 8) & 1) != 0)) {
      plVar8[0x92] = 0;
      plVar8[0x95] = 0;
      iVar13 = (**(code **)(*plVar8 + 0x138))(plVar8);
      if ((iVar13 != 0) && (*(short *)((longlong)plVar8 + 0x1c4) != 0)) {
        local_68[0] = 0;
        iVar13 = (**(code **)(*plVar8 + 0x18))(plVar8,local_68,0);
        if ((iVar13 != 0) && (plVar8[0x8e] != 0)) {
          plVar26 = (longlong *)(param_1 + 0x1f8);
          lVar7 = *(longlong *)(plVar8[7] + 0x38);
          uVar27 = *(uint *)(plVar8[0x8e] + 0x30);
          FUN_1400523e0(plVar26);
          plVar17 = plVar8;
          do {
            for (plVar19 = (longlong *)plVar17[0xb9]; plVar19 != (longlong *)0x0;
                plVar19 = (longlong *)plVar19[3]) {
              if ((*(short *)(*plVar19 + 6) != 0) &&
                 ((*(short *)(*plVar19 + 0xc) != 3 || (plVar8 == plVar17)))) {
                lVar30 = *(longlong *)(param_1 + 0x200);
                lVar20 = lVar30 + 1;
                _Dst = (void *)FUN_14018db00(*plVar26,lVar20,8);
                *(longlong **)((longlong)_Dst + lVar30 * 8) = plVar19;
                if ((void *)*plVar26 != _Dst) {
                  memcpy(_Dst,(void *)*plVar26,*(longlong *)(param_1 + 0x200) << 3);
                  lVar30 = *plVar26;
                  if (lVar30 != 0) {
                    (**(code **)(*(longlong *)(lVar30 + -0x10) + 8))(lVar30 + -0x10);
                  }
                  *plVar26 = (longlong)_Dst;
                }
                *(longlong *)(param_1 + 0x200) = lVar20;
              }
            }
          } while (((*(byte *)(plVar17 + 5) & 1) == 0) &&
                  (plVar17 = (longlong *)plVar17[0x98], plVar17 != (longlong *)0x0));
          FUN_140312d80();
          local_ac = 0;
          uVar33 = 0xffffffff;
          plVar17 = plVar8;
          do {
            for (plVar19 = (longlong *)plVar17[0xbb]; plVar19 != (longlong *)0x0;
                plVar19 = (longlong *)plVar19[5]) {
              if (*(ushort *)(*plVar19 + 2) < uVar33) {
                local_ac = (uint)*(byte *)(plVar19 + 1);
                uVar33 = (uint)*(ushort *)(*plVar19 + 2);
              }
            }
          } while (((*(byte *)(plVar17 + 5) & 1) == 0) &&
                  (plVar17 = (longlong *)plVar17[0x98], plVar17 != (longlong *)0x0));
          local_a4 = 0;
          local_a0 = 0;
          if (uVar27 != 0) {
            do {
              uVar34 = 0;
              lVar20 = *(longlong *)(plVar8[0x8e] + 0x48);
              lVar30 = local_a0 * 0x70 + *(longlong *)(plVar8[0x8e] + 0x40);
              if ((uVar12 == 0) || ((param_5 & 0x800) != 0)) {
                bVar25 = *(byte *)(lVar30 + 0x38);
                bVar9 = bVar25 & 2;
              }
              else {
                bVar25 = *(byte *)(lVar30 + 0x38);
                bVar9 = bVar25 & 8;
              }
              if ((bVar9 == 0) &&
                 ((((bVar25 & 4) == 0 || ((*(byte *)(param_1 + 0xe8) & 2) == 0)) &&
                  (uVar5 = *(ushort *)(lVar30 + 0x16), (uint)uVar5 < *(uint *)(lVar7 + 0x1f0))))) {
                lVar23 = *(longlong *)(lVar7 + 0x1f8);
                lVar28 = (ulonglong)uVar5 * 0x30;
                lVar24 = plVar8[0x8a];
                lVar35 = (ulonglong)*(ushort *)(lVar30 + 0x18) * 0x60 + plVar8[0x3e];
                if ((*(short *)(lVar35 + 0x34) != 0) &&
                   ((fVar4 = *(float *)(lVar35 + 0x20), fVar4 != 0.0 ||
                    (*(float *)(lVar35 + 0x24) != 0.0)))) {
                  iVar13 = *(int *)(lVar23 + 8 + lVar28);
                  if ((iVar13 == 2) || ((*(byte *)(lVar35 + 0x36) & 1) != 0)) {
                    if (fVar4 != 0.0) {
                      lVar24 = FUN_1402fa120(plVar8);
                      plVar17 = (longlong *)(param_2 + 0x10);
                      *(longlong *)(lVar24 + 0x18) = param_1 + 0x600;
                      *(int *)(lVar24 + 0xc) = (int)plVar8[0x26];
                      lVar20 = plVar8[0xae];
                      *(longlong **)(lVar24 + 0x30) = plVar8;
                      *(longlong *)(lVar24 + 0x38) = lVar35;
                      *(longlong *)(lVar24 + 0x40) = lVar30;
                      *(int *)(lVar24 + 0x10) = (int)lVar20;
                      if (*(longlong *)(lVar24 + 0x20) == 0) {
                        plVar19 = (longlong *)(lVar24 + 0x28);
                        *(longlong **)(lVar24 + 0x20) = plVar17;
                        *plVar19 = *plVar17;
                        *plVar17 = lVar24;
                        if (*plVar19 != 0) {
                          *(longlong **)(*plVar19 + 0x20) = plVar19;
                        }
                      }
                      *(longlong *)(param_2 + 0x50) = *(longlong *)(param_2 + 0x50) + 1;
                      if (((*(uint *)(lVar23 + 0xc + lVar28) & 0x200) != 0) &&
                         (lVar20 = plVar8[0x99], *(int *)(lVar20 + 0x720) != 1)) {
                        *(undefined4 *)(lVar20 + 0x720) = 1;
                        for (lVar20 = *(longlong *)(lVar20 + 0x4d0); lVar20 != 0;
                            lVar20 = *(longlong *)(lVar20 + 0x4e0)) {
                          lVar20 = FUN_1402f6470(lVar20,1);
                        }
                      }
                    }
                  }
                  else if (iVar13 == 0) {
                    uVar32 = *(ulonglong *)(param_1 + 0x200);
                    iVar13 = *(int *)(&DAT_140b640c8 + (longlong)param_6 * 4) * 0x400 +
                             *(int *)(lVar20 + local_a0 * 8);
                    param_8._0_4_ =
                         *(int *)(&DAT_140b640c8 + (longlong)param_6 * 4) * 0x480 +
                         *(int *)(lVar20 + 4 + local_a0 * 8);
                    uVar29 = (ulonglong)(uint)param_8;
                    param_7._0_2_ = -1;
                    if (uVar32 != 0) {
                      plVar17 = (longlong *)*plVar26;
                      do {
                        plVar19 = (longlong *)*plVar17;
                        if ((*(short *)(*plVar19 + 0xc) == 3) &&
                           (*(short *)(lVar30 + 0x1c) ==
                            (short)(((longlong)plVar19 - plVar8[0xb8]) / 0x88))) {
                          param_7._0_2_ = *(short *)(*plVar19 + 0x14);
                          break;
                        }
                        uVar34 = uVar34 + 1;
                        plVar17 = plVar17 + 1;
                      } while (uVar34 < uVar32);
                    }
                    uVar34 = 0;
                    local_88 = (longlong *)0x0;
                    if (uVar32 != 0) {
                      puVar22 = (undefined8 *)*plVar26;
                      do {
                        lVar31 = *(longlong *)*puVar22;
                        if (*(short *)(lVar31 + 6) != 1) break;
                        if ((*(short *)(lVar31 + 0xc) != 3) ||
                           (*(short *)(lVar31 + 0x14) == (short)param_7)) {
                          param_8._0_4_ = (uint)param_8 + (uint)*(ushort *)(lVar31 + 6) * 0x20;
                          uVar29 = (ulonglong)(uint)param_8;
                          local_88 = (longlong *)*puVar22;
                          break;
                        }
                        uVar34 = uVar34 + 1;
                        puVar22 = puVar22 + 1;
                      } while (uVar34 < uVar32);
                    }
                    uVar33 = local_ac;
                    if ((uint)*(ushort *)(lVar30 + 0x1a) < *(uint *)(lVar7 + 0x570)) {
                      uVar33 = (uint)*(byte *)(plVar8[0xba] + 8 +
                                              (ulonglong)*(ushort *)(lVar30 + 0x1a) * 0x30);
                    }
                    uVar15 = (uint)uVar29;
                    if (fVar4 != 0.0) {
                      uVar15 = *(uint *)(param_1 + 0x570);
                      if ((((uVar15 & 0x20) == 0) && ((*(byte *)(lVar28 + 0xc + lVar23) & 2) == 0))
                         && (iVar14 = *(int *)(lVar28 + 0x14 + lVar23), -1 < iVar14)) {
                        if (iVar14 < 2) {
                          if (fVar11 <= fVar4) {
                            if ((bVar25 & 1) != 0) goto joined_r0x00014031167f;
LAB_140311681:
                            iVar14 = 0;
                            lVar31 = 0;
                            goto LAB_14031168e;
                          }
                        }
                        else if (iVar14 != 2) {
                          if (iVar14 != 7) goto LAB_140311687;
joined_r0x00014031167f:
                          if ((uVar15 & 4) != 0) goto LAB_140311681;
                        }
                        iVar14 = 1;
                        lVar31 = 1;
                      }
                      else {
LAB_140311687:
                        iVar14 = 5;
                        lVar31 = 5;
                      }
LAB_14031168e:
                      if ((uVar15 & 4) == 0) {
                        if (iVar14 == 0) {
                          if ((uVar15 & 1) == 0) {
LAB_140311730:
                            uVar29 = (ulonglong)((uint)param_8 + 0x5a00);
                          }
                          else if (*(int *)(lVar28 + 0x14 + lVar23) == 0) {
                            plVar17 = (longlong *)(**(code **)(*DAT_140c65688 + 0xe0))();
                            if (*(int *)(*plVar17 +
                                        (ulonglong)
                                        *(byte *)((ulonglong)uVar5 * 0x60 + lVar24 + 0x58) * 4) == 1
                               ) {
                              uVar29 = (ulonglong)((uint)param_8 + 0x3600);
                            }
                            else {
                              uVar29 = (ulonglong)((uint)param_8 + 0x2400);
                            }
                          }
                          else {
                            uVar29 = (ulonglong)((uint)param_8 + 0x4800);
                          }
                        }
                        else if (iVar14 == 1) {
                          if (*(int *)(lVar28 + 0x14 + lVar23) != 7) goto LAB_140311730;
                          uVar29 = (ulonglong)((uint)param_8 + 0x6c00);
                        }
                      }
                      else if (*(int *)(lVar28 + 0x14 + lVar23) == 1) {
                        uVar29 = (ulonglong)((uint)param_8 + 0x1200);
                      }
                      if ((*(uint *)(lVar28 + 0xc + lVar23) & 0x10002) != 0x10002) {
                        lVar18 = FUN_1402fa240(plVar8);
                        plVar17 = (longlong *)(param_2 + lVar31 * 8);
                        *(longlong *)(lVar18 + 0x18) = param_1 + 0x5d0;
                        *(int *)(lVar18 + 0xc) = (int)plVar8[0x26];
                        lVar24 = plVar8[0xae];
                        *(longlong **)(lVar18 + 0x30) = plVar8;
                        *(longlong *)(lVar18 + 0x38) = lVar35;
                        *(int *)(lVar18 + 0x10) = (int)lVar24;
                        *(longlong *)(lVar18 + 0x40) = lVar30;
                        *(int *)(lVar18 + 0x58) = (int)uVar29;
                        *(longlong **)(lVar18 + 0x48) = local_88;
                        *(uint *)(lVar18 + 0x50) = uVar33;
                        *(int *)(lVar18 + 0x54) = iVar13;
                        if (*(longlong *)(lVar18 + 0x20) == 0) {
                          *(longlong **)(lVar18 + 0x20) = plVar17;
                          plVar19 = (longlong *)(lVar18 + 0x28);
                          *plVar19 = *plVar17;
                          *plVar17 = lVar18;
                          if (*plVar19 != 0) {
                            *(longlong **)(*plVar19 + 0x20) = plVar19;
                          }
                        }
                        plVar17 = (longlong *)(param_2 + 0x40 + lVar31 * 8);
                        *plVar17 = *plVar17 + 1;
                      }
                      uVar34 = 0;
                      if (*(longlong *)(param_1 + 0x200) != 0) {
                        do {
                          plVar17 = *(longlong **)(*plVar26 + uVar34 * 8);
                          lVar24 = *plVar17;
                          if (*(short *)(lVar24 + 6) == 2) break;
                          if (((*(short *)(lVar24 + 0xc) != 3) ||
                              (*(short *)(lVar24 + 0x14) == (short)param_7)) &&
                             (*(short *)(lVar24 + 6) == 3)) {
                            lVar18 = FUN_1402fa240(plVar8);
                            plVar19 = (longlong *)(param_2 + lVar31 * 8);
                            *(longlong *)(lVar18 + 0x18) = param_1 + 0x5d0;
                            *(int *)(lVar18 + 0xc) = (int)plVar8[0x26];
                            lVar24 = plVar8[0xae];
                            *(longlong **)(lVar18 + 0x30) = plVar8;
                            *(int *)(lVar18 + 0x10) = (int)lVar24;
                            *(longlong *)(lVar18 + 0x38) = lVar35;
                            *(longlong *)(lVar18 + 0x40) = lVar30;
                            *(uint *)(lVar18 + 0x50) = uVar33;
                            *(int *)(lVar18 + 0x54) = iVar13;
                            *(longlong **)(lVar18 + 0x48) = plVar17;
                            *(uint *)(lVar18 + 0x58) =
                                 (3 - ((uint)(uVar29 >> 5) & 3)) * 0x20 + (int)uVar29;
                            if (*(longlong *)(lVar18 + 0x20) == 0) {
                              *(longlong **)(lVar18 + 0x20) = plVar19;
                              plVar17 = (longlong *)(lVar18 + 0x28);
                              *plVar17 = *plVar19;
                              *plVar19 = lVar18;
                              if (*plVar17 != 0) {
                                *(longlong **)(*plVar17 + 0x20) = plVar17;
                              }
                            }
                            plVar17 = (longlong *)(param_2 + 0x40 + lVar31 * 8);
                            *plVar17 = *plVar17 + 1;
                          }
                          uVar34 = uVar34 + 1;
                        } while (uVar34 < *(ulonglong *)(param_1 + 0x200));
                      }
                      lVar24 = *(longlong *)(param_1 + 0x200);
                      while (uVar15 = (uint)param_8, lVar24 != 0) {
                        lVar24 = lVar24 + -1;
                        plVar17 = *(longlong **)(*plVar26 + lVar24 * 8);
                        lVar31 = *plVar17;
                        if (*(short *)(lVar31 + 6) != 2) break;
                        if ((*(short *)(lVar31 + 0xc) != 3) ||
                           (*(short *)(lVar31 + 0x14) == (short)param_7)) {
                          if ((*(byte *)(lVar31 + 0x12) & 4) == 0) {
                            lVar18 = FUN_1402fa240(plVar8);
                            *(longlong *)(lVar18 + 0x18) = param_1 + 0x5d0;
                            *(int *)(lVar18 + 0xc) = (int)plVar8[0x26];
                            lVar31 = plVar8[0xae];
                            *(longlong **)(lVar18 + 0x30) = plVar8;
                            *(longlong *)(lVar18 + 0x38) = lVar35;
                            *(int *)(lVar18 + 0x10) = (int)lVar31;
                            *(longlong *)(lVar18 + 0x40) = lVar30;
                            *(longlong **)(lVar18 + 0x48) = plVar17;
                            *(undefined4 *)(lVar18 + 0x50) = 0;
                            *(undefined4 *)(lVar18 + 0x54) = *(undefined4 *)(lVar20 + local_a0 * 8);
                            plVar19 = (longlong *)(param_2 + 0x28);
                            *(uint *)(lVar18 + 0x58) =
                                 (uint)*(ushort *)(*plVar17 + 6) * 0x20 +
                                 *(int *)(lVar20 + 4 + local_a0 * 8);
                            if (*(longlong *)(lVar18 + 0x20) == 0) {
                              *(longlong **)(lVar18 + 0x20) = plVar19;
                              plVar17 = (longlong *)(lVar18 + 0x28);
                              *plVar17 = *plVar19;
                              *plVar19 = lVar18;
                              if (*plVar17 != 0) {
                                *(longlong **)(*plVar17 + 0x20) = plVar17;
                              }
                            }
                            *(longlong *)(param_2 + 0x68) = *(longlong *)(param_2 + 0x68) + 1;
                          }
                          else {
                            plVar19 = (longlong *)FUN_1403266d0(plVar8[0x8e],lVar31 + 0x1e);
                            uVar34 = 0;
                            if (plVar19[1] != 0) {
                              plVar3 = (longlong *)(param_2 + 0x28);
                              uVar32 = uVar34;
                              do {
                                lVar18 = FUN_1402fa240(plVar8);
                                *(longlong *)(lVar18 + 0x18) = param_1 + 0x5d0;
                                *(int *)(lVar18 + 0xc) = (int)plVar8[0x26];
                                lVar31 = plVar8[0xae];
                                *(longlong **)(lVar18 + 0x30) = plVar8;
                                *(int *)(lVar18 + 0x10) = (int)lVar31;
                                *(longlong *)(lVar18 + 0x38) = lVar35;
                                lVar31 = *plVar19;
                                *(longlong **)(lVar18 + 0x48) = plVar17;
                                *(undefined4 *)(lVar18 + 0x50) = 0;
                                *(ulonglong *)(lVar18 + 0x40) = lVar31 + uVar32;
                                *(undefined4 *)(lVar18 + 0x54) =
                                     *(undefined4 *)(plVar19[2] + uVar34 * 8);
                                *(uint *)(lVar18 + 0x58) =
                                     (uint)*(ushort *)(*plVar17 + 6) * 0x20 +
                                     *(int *)(plVar19[2] + 4 + uVar34 * 8);
                                if (*(longlong *)(lVar18 + 0x20) == 0) {
                                  *(longlong **)(lVar18 + 0x20) = plVar3;
                                  plVar1 = (longlong *)(lVar18 + 0x28);
                                  *plVar1 = *plVar3;
                                  *plVar3 = lVar18;
                                  if (*plVar1 != 0) {
                                    *(longlong **)(*plVar1 + 0x20) = plVar1;
                                  }
                                }
                                *(longlong *)(param_2 + 0x68) = *(longlong *)(param_2 + 0x68) + 1;
                                uVar34 = uVar34 + 1;
                                uVar32 = uVar32 + 0x70;
                              } while (uVar34 < (ulonglong)plVar19[1]);
                            }
                          }
                        }
                      }
                    }
                    if (((*(float *)(lVar35 + 0x24) != 0.0) &&
                        ((*(byte *)(param_1 + 0x570) & 4) == 0)) &&
                       ((uVar6 = *(uint *)(lVar28 + 0x14 + lVar23), uVar6 < 3 || (uVar6 == 7)))) {
                      lVar20 = FUN_1402fa240(plVar8);
                      plVar17 = (longlong *)(param_2 + 0x20);
                      *(longlong *)(lVar20 + 0x18) = param_1 + 0x5d0;
                      *(int *)(lVar20 + 0xc) = (int)plVar8[0x26];
                      *(int *)(lVar20 + 0x10) = (int)plVar8[0xae];
                      *(longlong **)(lVar20 + 0x30) = plVar8;
                      *(longlong *)(lVar20 + 0x38) = lVar35;
                      *(longlong *)(lVar20 + 0x40) = lVar30;
                      *(longlong **)(lVar20 + 0x48) = local_88;
                      *(uint *)(lVar20 + 0x58) = uVar15 + 0x7e00;
                      *(uint *)(lVar20 + 0x50) = uVar33;
                      *(int *)(lVar20 + 0x54) = iVar13;
                      if (*(longlong *)(lVar20 + 0x20) == 0) {
                        *(longlong **)(lVar20 + 0x20) = plVar17;
                        plVar19 = (longlong *)(lVar20 + 0x28);
                        *plVar19 = *plVar17;
                        *plVar17 = lVar20;
                        if (*plVar19 != 0) {
                          *(longlong **)(*plVar19 + 0x20) = plVar19;
                        }
                      }
                      *(longlong *)(param_2 + 0x60) = *(longlong *)(param_2 + 0x60) + 1;
                    }
                  }
                  else if (iVar13 == 1) {
                    lVar31 = FUN_1402fa240(plVar8);
                    uVar34 = 0;
                    *(longlong *)(lVar31 + 0x18) = param_1 + 0x5d0;
                    *(int *)(lVar31 + 0xc) = (int)plVar8[0x26];
                    lVar24 = plVar8[0xae];
                    *(longlong **)(lVar31 + 0x30) = plVar8;
                    *(int *)(lVar31 + 0x10) = (int)lVar24;
                    *(longlong *)(lVar31 + 0x38) = lVar35;
                    *(longlong *)(lVar31 + 0x40) = lVar30;
                    *(undefined8 *)(lVar31 + 0x48) = 0;
                    *(undefined4 *)(lVar31 + 0x50) = 0;
                    *(undefined4 *)(lVar31 + 0x54) = *(undefined4 *)(lVar20 + local_a0 * 8);
                    uVar33 = *(uint *)(lVar20 + 4 + local_a0 * 8);
                    *(uint *)(lVar31 + 0x58) = uVar33;
                    uVar15 = (byte)~**(byte **)(param_1 + 0x10) & 1;
                    if ((uVar33 & 1) != uVar15) {
                      *(uint *)(lVar31 + 0x58) = (uVar33 - (uVar33 & 1)) + uVar15;
                    }
                    if (((*(byte *)(lVar23 + 0xc + lVar28) & 2) == 0) &&
                       (iVar13 = *(int *)(lVar23 + 0x14 + lVar28), -1 < iVar13)) {
                      if (iVar13 < 2) {
                        if ((*(float *)(lVar35 + 0x20) <= fVar11 &&
                             fVar11 != *(float *)(lVar35 + 0x20)) ||
                           (((*(byte *)(lVar30 + 0x38) & 1) != 0 &&
                            ((*(byte *)(param_1 + 0x570) & 4) == 0)))) goto LAB_140311e86;
                      }
                      else if (iVar13 == 2) {
LAB_140311e86:
                        uVar34 = 1;
                      }
                      else {
                        if (iVar13 != 7) goto LAB_140311e8d;
                        uVar34 = (ulonglong)((byte)~*(byte *)(param_1 + 0x570) >> 2 & 1);
                      }
                    }
                    else {
LAB_140311e8d:
                      uVar34 = 5;
                    }
                    plVar17 = (longlong *)(param_2 + uVar34 * 8);
                    if (*(longlong *)(lVar31 + 0x20) == 0) {
                      *(longlong **)(lVar31 + 0x20) = plVar17;
                      plVar19 = (longlong *)(lVar31 + 0x28);
                      *plVar19 = *plVar17;
                      *plVar17 = lVar31;
                      if (*plVar19 != 0) {
                        *(longlong **)(*plVar19 + 0x20) = plVar19;
                      }
                    }
                    plVar17 = (longlong *)(param_2 + 0x40 + uVar34 * 8);
                    *plVar17 = *plVar17 + 1;
                  }
                }
              }
              local_a4 = local_a4 + 1;
              local_a0 = local_a0 + 1;
            } while (local_a4 < uVar27);
          }
          if (uVar12 == 0) {
            iVar13 = (**(code **)(*plVar8 + 0x3f0))(plVar8);
            if (iVar13 == 0) {
              for (piVar16 = (int *)plVar8[0xd4]; piVar16 != (int *)0x0;
                  piVar16 = *(int **)(piVar16 + 0x1e)) {
                if ((((*(code **)(piVar16 + 4) == (code *)0x0) ||
                     (iVar13 = (**(code **)(piVar16 + 4))(plVar8,piVar16[1]), iVar13 != 0)) &&
                    (*(longlong *)(piVar16 + 6) != 0)) &&
                   (*(short *)(*(longlong *)(piVar16 + 2) + 0x34) != 0)) {
                  iVar13 = *piVar16;
                  if ((iVar13 == 0) &&
                     (pfVar2 = (float *)(*(longlong *)(piVar16 + 2) + 0x20),
                     *pfVar2 <= fVar11 && fVar11 != *pfVar2)) {
                    iVar13 = 1;
                  }
                  *(longlong *)(piVar16 + 0x10) = param_1 + 0x5e8;
                  piVar16[0xd] = (int)plVar8[0x26];
                  lVar20 = plVar8[0xae];
                  *(longlong **)(piVar16 + 0x16) = plVar8;
                  piVar16[0xe] = (int)lVar20;
                  *(int **)(piVar16 + 0x1a) = piVar16;
                  *(undefined8 *)(piVar16 + 0x18) = *(undefined8 *)(piVar16 + 2);
                  plVar26 = (longlong *)(param_2 + (longlong)iVar13 * 8);
                  if (*(longlong *)(piVar16 + 0x12) == 0) {
                    *(longlong **)(piVar16 + 0x12) = plVar26;
                    plVar17 = (longlong *)(piVar16 + 0x14);
                    *plVar17 = *plVar26;
                    *plVar26 = (longlong)(piVar16 + 10);
                    if (*plVar17 != 0) {
                      *(longlong **)(*plVar17 + 0x20) = plVar17;
                    }
                  }
                  plVar26 = (longlong *)(param_2 + 0x40 + (longlong)iVar13 * 8);
                  *plVar26 = *plVar26 + 1;
                }
              }
            }
            if ((((int)plVar8[0xb4] != 0) && (*(int *)((longlong)plVar8 + 0x5a4) != 0)) &&
               ((iVar13 = (**(code **)(*plVar8 + 0x158))(plVar8), iVar13 != 0 &&
                (uVar34 = 0, *(int *)(lVar7 + 0x318) != 0)))) {
              do {
                lVar20 = (ulonglong)
                         *(ushort *)
                          ((ulonglong)*(ushort *)(uVar34 * 400 + 2 + *(longlong *)(lVar7 + 800)) *
                           0x160 + 6 + *(longlong *)(lVar7 + 0x188)) * 0x60 + plVar8[0x3e];
                if (*(short *)(lVar20 + 0x34) != 0) {
                  if ((*(longlong *)(param_1 + 0x1e8) == 0) ||
                     (plVar26 = *(longlong **)(uVar34 * 0x1b0 + 0x1a8 + plVar8[0xb7]),
                     plVar26 == (longlong *)0x0)) {
                    plVar26 = (longlong *)(param_2 + 0x18);
                    lVar23 = plVar8[0xb7] + 0x160 + uVar34 * 0x1b0;
                    *(longlong *)(lVar23 + 0x18) = param_1 + 0x618;
                    *(int *)(lVar23 + 0xc) = (int)plVar8[0x26];
                    lVar30 = plVar8[0xae];
                    *(longlong **)(lVar23 + 0x30) = plVar8;
                    *(longlong *)(lVar23 + 0x38) = lVar20;
                    *(int *)(lVar23 + 0x40) = (int)uVar34;
                    *(int *)(lVar23 + 0x10) = (int)lVar30;
                    if (*(longlong *)(lVar23 + 0x20) == 0) {
                      *(longlong **)(lVar23 + 0x20) = plVar26;
                      plVar17 = (longlong *)(lVar23 + 0x28);
                      *plVar17 = *plVar26;
                      *plVar26 = lVar23;
                      if (*plVar17 != 0) {
                        *(longlong **)(*plVar17 + 0x20) = plVar17;
                      }
                    }
                    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + 1;
                  }
                  else {
                    lVar20 = *plVar8;
                    (**(code **)(*plVar26 + 0x18))(plVar26);
                    iVar13 = (**(code **)(lVar20 + 0x418))(plVar8,uVar34);
                    if (-1 < iVar13) {
                      (**(code **)(*plVar26 + 0x20))(plVar26);
                    }
                  }
                }
                uVar27 = (int)uVar34 + 1;
                uVar34 = (ulonglong)uVar27;
              } while (uVar27 < *(uint *)(lVar7 + 0x318));
            }
            uVar34 = 0;
            if (*(int *)(plVar8[8] + 0x2f8) != 0) {
              do {
                plVar26 = *(longlong **)(plVar8[0xb2] + uVar34 * 8);
                if (plVar26 != (longlong *)0x0) {
                  puVar21 = (ushort *)(**(code **)(*plVar26 + 0x20))(plVar26);
                  if ((uint)puVar21[1] < *(uint *)(lVar7 + 0x200)) {
                    uVar5 = *(ushort *)(*(longlong *)(lVar7 + 0x208) + (ulonglong)puVar21[1] * 4);
                    if ((((*(ulonglong *)(plVar8[0x99] + 0x418) <= (ulonglong)(uVar5 >> 3)) ||
                         ((*(byte *)((ulonglong)(uVar5 >> 3) + *(longlong *)(plVar8[0x99] + 0x410))
                          & '\x01' << ((byte)uVar5 & 7)) == 0)) ||
                        ((ulonglong)plVar8[0x83] <= (ulonglong)(uVar5 >> 3))) ||
                       ((*(byte *)((ulonglong)(uVar5 >> 3) + plVar8[0x82]) &
                        '\x01' << ((byte)uVar5 & 7)) == 0)) goto LAB_140312210;
                  }
                  lVar20 = (ulonglong)
                           *(ushort *)
                            ((ulonglong)*puVar21 * 0x160 + 6 + *(longlong *)(lVar7 + 0x188)) * 0x60
                           + plVar8[0x3e];
                  if (*(short *)(lVar20 + 0x34) != 0) {
                    plVar26[0x29] = param_1 + 0x630;
                    *(int *)((longlong)plVar26 + 0x13c) = (int)plVar8[0x26];
                    lVar30 = plVar8[0xae];
                    plVar26[0x2c] = (longlong)plVar8;
                    plVar26[0x2d] = lVar20;
                    plVar26[0x2e] = (longlong)plVar26;
                    *(undefined4 *)(plVar26 + 0x27) = 0;
                    *(int *)(plVar26 + 0x28) = (int)lVar30;
                    lVar20 = (**(code **)(*plVar26 + 0x20))(plVar26);
                    if ((*(byte *)(lVar20 + 0x10) & 1) != 0) {
                      *(uint *)(plVar26 + 0x27) = *(uint *)(plVar26 + 0x27) | 1;
                    }
                    lVar20 = (**(code **)(*plVar26 + 0x20))(plVar26);
                    if ((*(byte *)(lVar20 + 0x10) & 2) != 0) {
                      *(uint *)(plVar26 + 0x27) = *(uint *)(plVar26 + 0x27) | 2;
                    }
                    plVar17 = (longlong *)(param_2 + 0x28);
                    if (plVar26[0x2a] == 0) {
                      plVar26[0x2a] = (longlong)plVar17;
                      plVar19 = plVar26 + 0x2b;
                      *plVar19 = *plVar17;
                      *plVar17 = (longlong)(plVar26 + 0x26);
                      if (*plVar19 != 0) {
                        *(longlong **)(*plVar19 + 0x20) = plVar19;
                      }
                    }
                    *(longlong *)(param_2 + 0x68) = *(longlong *)(param_2 + 0x68) + 1;
                    if ((*(int *)(puVar21 + 2) == 0) && (**(char **)(puVar21 + 0x48) == '\x01')) {
                      (**(code **)(*plVar26 + 0x58))(plVar26,(longlong *)(param_1 + 200));
                    }
                  }
                }
LAB_140312210:
                uVar27 = (int)uVar34 + 1;
                uVar34 = (ulonglong)uVar27;
              } while (uVar27 < *(uint *)(plVar8[8] + 0x2f8));
            }
          }
        }
      }
      plVar26 = (longlong *)(param_1 + 200);
      for (lVar7 = plVar8[0x9a]; lVar7 != 0; lVar7 = *(longlong *)(lVar7 + 0x4e0)) {
        if (((*(short *)(lVar7 + 0x1c4) != 0) &&
            ((*(int *)(lVar7 + 0x4b0) == 0 || (*(longlong *)(lVar7 + 0x4b8) != 0)))) &&
           (*(longlong *)(lVar7 + 0x168) == 0)) {
          *(longlong **)(lVar7 + 0x168) = plVar26;
          plVar8 = (longlong *)(lVar7 + 0x170);
          *plVar8 = *plVar26;
          *plVar26 = lVar7;
          if (*plVar8 != 0) {
            *(longlong **)(*plVar8 + 0x168) = plVar8;
          }
        }
      }
    }
    lVar7 = *(longlong *)(param_1 + 200);
  } while( true );
}


