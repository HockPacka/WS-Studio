
==== FUN_14031a280 @ 14031a280 size 831 ====
CALLERS: FUN_14031bca0
CALLEES: FUN_14018b280

void FUN_14031a280(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  
  if (*(longlong *)(param_1 + 0x598) == 0) {
    uVar3 = FUN_14018b280(0x600,0);
    lVar4 = 0;
    *(undefined8 *)(param_1 + 0x598) = uVar3;
    uVar1 = DAT_140b7b530;
    lVar5 = 0x20;
    do {
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x808),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x80c));
      *(undefined4 *)(lVar4 + 8 + *(longlong *)(param_1 + 0x598)) = uVar6;
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x810),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x814));
      *(undefined4 *)(lVar4 + 0x18 + *(longlong *)(param_1 + 0x598)) = uVar6;
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x818),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x81c));
      *(undefined4 *)(lVar4 + 0x28 + *(longlong *)(param_1 + 0x598)) = uVar6;
      if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x10) != 0) &&
         (iVar2 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                            (*(longlong **)(param_1 + 0x38),0,1), iVar2 != 0)) {
        *(uint *)(lVar4 + 8 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 8 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
        *(uint *)(lVar4 + 0x18 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 0x18 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
        *(uint *)(lVar4 + 0x28 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 0x28 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
      }
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x820),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x824));
      *(undefined4 *)(lVar4 + *(longlong *)(param_1 + 0x598)) = uVar6;
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x828),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x82c));
      *(undefined4 *)(lVar4 + 0x10 + *(longlong *)(param_1 + 0x598)) = uVar6;
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x830),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x834));
      *(undefined4 *)(lVar4 + 0x20 + *(longlong *)(param_1 + 0x598)) = uVar6;
      if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x20) != 0) &&
         (iVar2 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                            (*(longlong **)(param_1 + 0x38),0,1), iVar2 != 0)) {
        *(uint *)(lVar4 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
        *(uint *)(lVar4 + 0x10 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 0x10 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
        *(uint *)(lVar4 + 0x20 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 0x20 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
      }
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x838),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x83c));
      *(undefined4 *)(lVar4 + 4 + *(longlong *)(param_1 + 0x598)) = uVar6;
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x840),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x844));
      *(undefined4 *)(lVar4 + 0x14 + *(longlong *)(param_1 + 0x598)) = uVar6;
      uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                        (*(longlong **)(param_1 + 0x38),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x848),
                         *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + 0x84c));
      *(undefined4 *)(lVar4 + 0x24 + *(longlong *)(param_1 + 0x598)) = uVar6;
      if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x40) != 0) &&
         (iVar2 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                            (*(longlong **)(param_1 + 0x38),0,1), iVar2 != 0)) {
        *(uint *)(lVar4 + 4 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 4 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
        *(uint *)(lVar4 + 0x14 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 0x14 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
        *(uint *)(lVar4 + 0x24 + *(longlong *)(param_1 + 0x598)) =
             *(uint *)(lVar4 + 0x24 + *(longlong *)(param_1 + 0x598)) ^ uVar1;
      }
      lVar4 = lVar4 + 0x30;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return;
}



==== FUN_140310f70 @ 140310f70 size 4990 ====
CALLERS:
CALLEES: FUN_1402c8730 FUN_1400523e0 FUN_1402fa240 FUN_1403266d0 FUN_1402fa120 FUN_140312d80 FUN_14018db00 memcpy FUN_1402f6470

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



==== FUN_1403a25c0 @ 1403a25c0 size 15991 ====
CALLERS: FUN_1403e85d0
CALLEES: FUN_14057a190 FUN_14045e6d0 FUN_14018b900 __security_check_cookie FUN_1404dacf0 FUN_1405b3b80 FUN_1404dae70 FUN_1403a0c50 FUN_14079a4f0 FUN_14055a260 FUN_14079a810 FUN_1404daac0 FUN_14039e1a0 FUN_14047bf00 FUN_1401c9800 FUN_1404dab80 FUN_1408fc950 FUN_1408fd190 FUN_1408fe3d0 FUN_1403f4900 FUN_14057a2c0 FUN_1401fffc0 FUN_140200220 FUN_14047bf60 FUN_1405598d0 FUN_1403d90d0 FUN_14079a990 FUN_1404daf50 FUN_1404dad90 FUN_14079a780 FUN_1404daeb0 FUN_14047be40 FUN_1403a2550 FUN_1403a2460 FUN_14039e210 FUN_14039e0e0 FUN_1404dae30 FUN_1403b50c0 FUN_14047c060 FUN_14039e400 FUN_14045e680 FUN_1405ccde0 FUN_1403a0b80 FUN_1405b45e0 FUN_14045e630 FUN_1408fd8a4 FUN_1408fbfc0 FUN_14039e130 FUN_14018c320 FUN_140398360 FUN_140195d70 FUN_1408fc7f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1403a25c0(longlong param_1)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  undefined1 auVar6 [16];
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined1 auVar10 [12];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [4];
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  undefined8 *puVar20;
  float *pfVar21;
  undefined *puVar22;
  longlong lVar23;
  longlong *plVar24;
  undefined4 *puVar25;
  ulonglong uVar26;
  uint uVar27;
  undefined **ppuVar28;
  undefined1 auVar29 [4];
  undefined4 uVar30;
  undefined4 uVar31;
  int *piVar32;
  longlong lVar33;
  float *pfVar34;
  bool bVar35;
  bool bVar36;
  bool bVar37;
  ulonglong uVar38;
  uint uVar39;
  uint uVar40;
  bool bVar41;
  undefined1 uVar42;
  float fVar43;
  float extraout_XMM0_Da;
  float fVar44;
  float fVar45;
  float fVar46;
  undefined8 uVar47;
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar63;
  float fVar66;
  undefined1 in_XMM1 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar59 [16];
  undefined1 auVar61 [16];
  float fVar64;
  float fVar65;
  undefined1 auVar62 [16];
  float fVar67;
  float fVar76;
  undefined1 auVar68 [12];
  float fVar74;
  float fVar75;
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  float fVar77;
  float fVar78;
  undefined1 auVar79 [16];
  float fVar80;
  float fVar81;
  float fVar82;
  float fVar83;
  float fVar84;
  undefined1 auVar85 [16];
  undefined1 auStack_488 [32];
  float **local_468;
  undefined8 *local_460;
  float local_458;
  float local_454;
  uint local_450;
  uint local_44c;
  float local_448;
  undefined2 local_444;
  float local_440;
  int local_43c;
  uint local_438;
  float local_434;
  int local_430;
  int local_42c;
  float local_428;
  uint local_424;
  float local_420;
  float local_41c;
  float *local_418;
  float local_410;
  uint local_40c;
  uint local_408;
  undefined1 local_3f8 [8];
  undefined8 uStack_3f0;
  undefined8 local_3e8;
  undefined8 uStack_3e0;
  float local_3d8;
  int local_3d4;
  undefined1 local_3c8 [8];
  undefined8 uStack_3c0;
  undefined1 local_3b8 [16];
  float local_3a8;
  undefined4 uStack_3a4;
  undefined4 uStack_3a0;
  float local_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  undefined1 local_388 [32];
  float local_368;
  float local_348;
  float fStack_344;
  float fStack_340;
  float local_308;
  float fStack_304;
  float fStack_300;
  float local_2f8;
  undefined1 local_2a8 [32];
  float local_288;
  int local_26c;
  float local_218;
  float local_1e8;
  float local_1e4;
  undefined1 local_1c8 [64];
  int local_188;
  float local_184;
  undefined1 local_138 [4];
  undefined1 auStack_134 [4];
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  ulonglong uStack_110;
  float local_108;
  float fStack_104;
  ulonglong uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  undefined1 auVar58 [16];
  undefined1 auVar60 [16];
  
  local_e8 = DAT_140c0f7b0 ^ (ulonglong)auStack_488;
  lVar23 = *(longlong *)(param_1 + 0x6490);
  fVar43 = in_XMM1._0_4_;
  if (lVar23 == 0) {
    return 0;
  }
  if (lVar23 != *(longlong *)(param_1 + 0x6488)) {
    return 0;
  }
  if (*(int *)(lVar23 + 0xd50) == 0) {
    return 0;
  }
  if (*(int *)(lVar23 + 0xdf4) == 1) {
    return 0;
  }
  if (*(longlong *)(lVar23 + 0x16e8) == 0) {
    return 0;
  }
  lVar23 = *(longlong *)(lVar23 + 0xf00);
  local_3a8 = (float)lVar23;
  uStack_3a4 = (undefined4)((ulonglong)lVar23 >> 0x20);
  if ((lVar23 != 0) && (*(longlong *)(lVar23 + 0x16e8) == 0)) {
    return 0;
  }
  if ((*(longlong *)(param_1 + 0x71a8) != 0) &&
     (*(int *)(*(longlong *)(param_1 + 0x7198) + 0x50) == 0)) {
    return 0;
  }
  local_3d8 = fVar43;
  puVar20 = (undefined8 *)(**(code **)(**(longlong **)(param_1 + 0x6fc0) + 0x18))();
  pfVar21 = (float *)(**(code **)(**(longlong **)(param_1 + 0x6fc0) + 0x20))();
  if (lVar23 == 0) {
    puVar22 = &DAT_140c78390;
    local_418 = (float *)&DAT_140c78390;
  }
  else {
    local_418 = (float *)(lVar23 + 0x11b0);
    puVar22 = (undefined *)(lVar23 + 0x11f0);
  }
  local_3b8._0_8_ = puVar22;
  iVar15 = (**(code **)(**(longlong **)(param_1 + 0x6490) + 0x20))();
  if ((iVar15 == 0) || (iVar15 = FUN_14047c060(*(undefined8 *)(param_1 + 0x6490)), iVar15 != 0)) {
    _local_3c8 = *(undefined1 (*) [16])(DAT_140c65898 + 0x6ff0);
    local_3f8 = *(undefined1 (*) [8])(DAT_140c65898 + 0x7000);
    uStack_3f0 = *(undefined8 *)(DAT_140c65898 + 0x7008);
  }
  else {
    _local_3c8 = *(undefined1 (*) [16])(DAT_140c65898 + 0x7010);
    local_3f8 = *(undefined1 (*) [8])(DAT_140c65898 + 0x7020);
    uStack_3f0 = *(undefined8 *)(DAT_140c65898 + 0x7028);
  }
  uVar27 = 0;
  bVar41 = false;
  bVar36 = false;
  if ((*(int *)(*(longlong *)(param_1 + 0x6490) + 0x1620) != 0) &&
     ((lVar23 = FUN_1403d90d0(param_1), lVar23 == 0 || (*(int *)(lVar23 + 0x250) != 0)))) {
    lVar23 = *(longlong *)(param_1 + 0x6490);
    if (*(int *)(lVar23 + 0x1624) == 1) {
      *(undefined4 *)(lVar23 + 0x1620) = 0;
      FUN_140195d70(lVar23 + 0x1628);
    }
    lVar23 = *(longlong *)(param_1 + 0x6490);
    if (*(int *)(lVar23 + 0x1624) == 0) {
      *(undefined4 *)(lVar23 + 0x1620) = 0;
      FUN_140195d70(lVar23 + 0x1628);
    }
  }
  bVar9 = false;
  bVar7 = false;
  bVar8 = false;
  iVar15 = *(int *)(*(longlong *)(param_1 + 0x6490) + 0x1088);
  local_430 = 0;
  local_410 = 0.0;
  local_448 = 0.0;
  local_3e8 = (longlong *)((ulonglong)(uint)local_3e8._4_4_ << 0x20);
  local_43c = 0;
  local_40c = (uint)(iVar15 == 1);
  local_450 = 0;
  local_424 = 0;
  local_44c = 0;
  local_408 = (uint)(iVar15 == 3);
  bVar37 = false;
  bVar35 = false;
  local_454 = 0.0;
  uVar40 = 0;
  local_438 = 0;
  local_440 = 0.0;
  FUN_140398360(param_1);
  fVar46 = DAT_140b79ed0;
  uVar39 = uVar40;
  if (*(int *)(param_1 + 0x78d8) == 0) {
    if (*(int *)(param_1 + 0x78ec) != 0) {
      if ((DAT_140dc21e0 & 4) == 0) {
        DAT_140dc21e0 = DAT_140dc21e0 | 4;
        lVar23 = FUN_140200220(0x1e2);
        if (lVar23 == 0) {
          DAT_140dc21ec = 0x14d;
        }
        else {
          DAT_140dc21ec = *(int *)(lVar23 + 4);
        }
      }
      if ((DAT_140dc21e0 & 8) == 0) {
        DAT_140dc21e0 = DAT_140dc21e0 | 8;
        lVar23 = FUN_140200220(0x1e3);
        if (lVar23 == 0) {
          DAT_140dc21f0 = 400;
        }
        else {
          DAT_140dc21f0 = *(int *)(lVar23 + 4);
        }
      }
      iVar15 = DAT_140dc21ec + *(int *)(param_1 + 0x78f4);
      if (DAT_140c636a8 - iVar15 < 0) {
        iVar19 = *(int *)(param_1 + 0x78f8);
        if (iVar19 == 1) {
          bVar9 = true;
          local_3e8 = (longlong *)CONCAT44(local_3e8._4_4_,1);
          goto LAB_1403a2b22;
        }
        if (iVar19 == 2) {
          local_430 = 1;
          local_438 = 0x10000;
          bVar7 = false;
LAB_1403a2b28:
          bVar37 = true;
          uVar39 = local_438;
        }
        else {
          if (iVar19 == 3) {
            local_43c = 1;
LAB_1403a2b22:
            local_438 = 0x8000;
            bVar7 = bVar9;
            goto LAB_1403a2b28;
          }
          uVar39 = uVar27;
          bVar37 = false;
          bVar7 = false;
          if (iVar19 == 4) {
            local_450 = 1;
            bVar9 = false;
            goto LAB_1403a2b22;
          }
        }
        local_448 = (float)FUN_1408fbfc0(fVar46 - (float)(uint)(iVar15 - DAT_140c636a8) /
                                                  (float)(uint)(iVar15 - *(int *)(param_1 + 0x78f4))
                                        );
        local_448 = fVar46 - local_448;
      }
      else if (DAT_140c636a8 - (iVar15 + DAT_140dc21f0) < 0) {
        local_438 = 0x20000;
        uVar39 = 0x20000;
        bVar37 = bVar35;
        bVar7 = bVar8;
      }
      else {
        *(undefined4 *)(param_1 + 0x78ec) = 0;
        bVar37 = bVar35;
        bVar7 = bVar8;
      }
    }
  }
  else {
    if ((DAT_140dc21e0 & 1) == 0) {
      DAT_140dc21e0 = DAT_140dc21e0 | 1;
      lVar23 = FUN_140200220(0x10c);
      if (lVar23 == 0) {
        DAT_140dc21e4 = 0x10b;
      }
      else {
        DAT_140dc21e4 = *(int *)(lVar23 + 8);
      }
    }
    if ((DAT_140dc21e0 & 2) == 0) {
      DAT_140dc21e0 = DAT_140dc21e0 | 2;
      lVar23 = FUN_140200220(0x11b);
      if (lVar23 == 0) {
        DAT_140dc21e8 = 900;
      }
      else {
        DAT_140dc21e8 = *(int *)(lVar23 + 8);
      }
    }
    iVar15 = DAT_140dc21e4 + *(int *)(param_1 + 0x78e0);
    if (-1 < DAT_140c636a8 - iVar15) {
      if (DAT_140c636a8 - (iVar15 + DAT_140dc21e8) < 0) {
        local_438 = 0x4000;
        uVar39 = 0x4000;
        bVar37 = false;
        bVar7 = false;
      }
      else {
        *(undefined4 *)(param_1 + 0x78d8) = 0;
        uVar39 = uVar27;
        bVar37 = bVar35;
        bVar7 = bVar8;
        if (*(longlong *)(param_1 + 0x7040) != 0) {
          FUN_14057a2c0(param_1);
          uVar39 = uVar40;
          bVar37 = false;
          bVar7 = false;
        }
      }
      goto LAB_1403a29b3;
    }
    local_440 = 1.4013e-45;
    if (*(int *)(param_1 + 0x78e8) == 1) {
      bVar41 = true;
      local_3e8 = (longlong *)CONCAT44(local_3e8._4_4_,1);
LAB_1403a2953:
      bVar36 = true;
    }
    else if (*(int *)(param_1 + 0x78e8) == 2) {
      local_430 = 1;
      bVar41 = false;
      goto LAB_1403a2953;
    }
    if (*(int *)(param_1 + 0x78e4) == 3) {
      local_43c = 1;
LAB_1403a2971:
      bVar36 = true;
    }
    else if (*(int *)(param_1 + 0x78e4) == 4) {
      local_450 = 1;
      goto LAB_1403a2971;
    }
    local_410 = (float)FUN_1408fbfc0(fVar46 - (float)(uint)(iVar15 - DAT_140c636a8) /
                                              (float)(uint)(iVar15 - *(int *)(param_1 + 0x78e0)));
    local_410 = fVar46 - local_410;
    uVar39 = uVar27;
    bVar37 = bVar36;
    bVar7 = bVar41;
  }
LAB_1403a29b3:
  iVar15 = 0;
  if ((*(int *)(param_1 + 0x70a8) == 0) || (iVar19 = 1, *(int *)(param_1 + 0x70a4) == 0)) {
    iVar19 = iVar15;
  }
  lVar23 = *(longlong *)(param_1 + 0x6490);
  *(int *)(param_1 + 0x70a8) = iVar19;
  local_42c = iVar19;
  iVar16 = FUN_14045e630(lVar23);
  if ((iVar16 != 0) && (iVar19 == 0)) {
    iVar15 = 1;
  }
  local_3d4 = iVar15;
  iVar16 = FUN_14045e6d0(lVar23);
  if ((iVar16 == 0) || (iVar19 != 0)) {
    local_434 = 0.0;
  }
  else {
    local_434 = 1.4013e-45;
  }
  iVar19 = 1;
  if ((*(int *)(lVar23 + 0x250) == 0) &&
     (((iVar15 == 0 || (local_434 == 0.0)) &&
      (iVar15 = FUN_1405ccde0(*(undefined8 *)(param_1 + 0x7198)), iVar15 == 0)))) {
    local_420 = 1.4013e-45;
    if ((*(int *)(param_1 + 0x78d8) != 0) || (*(int *)(param_1 + 0x78ec) != 0)) goto LAB_1403a2f23;
    if (((DAT_140c89aa0 == 0) && (iVar15 = FUN_1404daac0(param_1), iVar15 == 0)) &&
       (*(int *)(param_1 + 0x70ac) == 0)) {
      uVar47 = 0;
    }
    else {
      uVar47 = 1;
    }
    iVar15 = FUN_1403a2460(uVar47);
    local_3e8 = (longlong *)CONCAT44(local_3e8._4_4_,iVar15);
    uVar17 = FUN_1404dab80(param_1);
    iVar18 = 0;
    iVar16 = FUN_1403a2460(uVar17);
    local_430 = iVar16;
    if (((*(int *)(param_1 + 0x70ac) == iVar18) && (iVar18 = FUN_1404daf50(param_1), iVar18 != 0))
       && ((iVar18 = FUN_1404daeb0(param_1), iVar18 != 0 &&
           (iVar18 = FUN_14055a260(param_1 + 0x7330), iVar18 == 0)))) {
      *(undefined4 *)(param_1 + 0x70ac) = 1;
    }
    if ((*(int *)(param_1 + 0x70ac) != 0) &&
       ((iVar18 = FUN_1404daf50(param_1), iVar18 == 0 ||
        (iVar18 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))(), iVar18 == 0)))) {
      *(undefined4 *)(param_1 + 0x70ac) = 0;
    }
    if (((iVar15 != 0) && (iVar16 != 0)) &&
       (*(float *)(param_1 + 0x78fc) == *(float *)(param_1 + 0x7900))) {
      iVar15 = 0;
      local_3e8 = (longlong *)((ulonglong)local_3e8 & 0xffffffff00000000);
      iVar16 = 0;
      local_430 = 0;
    }
    uVar17 = FUN_1404dacf0(param_1);
    local_43c = FUN_1403a2460(uVar17);
    uVar17 = FUN_1404dad90(param_1);
    pfVar34 = (float *)(param_1 + 0x7908);
    iVar18 = 0;
    local_450 = FUN_1403a2460(uVar17);
    if (((local_43c != iVar18) && (local_450 != 0)) && (*pfVar34 == *(float *)(param_1 + 0x7904))) {
      local_450 = 0;
      local_43c = 0;
    }
    local_458 = (float)FUN_1404dae30(param_1);
    local_454 = (float)FUN_1404dae70(param_1);
    if ((local_458 != 0.0) && (local_454 != 0.0)) {
      local_454 = 0.0;
      local_458 = 0.0;
    }
    iVar18 = FUN_14039e1a0(param_1);
    if (iVar18 == 0) {
      if ((((local_40c == 0) && (local_408 == 0)) && (local_42c == 0)) || (DAT_140c89a90 == 0)) {
        uVar47 = 0;
      }
      else {
        uVar47 = 1;
      }
      iVar18 = FUN_1403a2460(uVar47);
      local_424 = 1;
      if (iVar18 == 0) goto LAB_1403a2dbb;
    }
    else {
LAB_1403a2dbb:
      local_424 = 0;
    }
    iVar18 = FUN_14039e1a0();
    if (iVar18 == 0) {
      if (((local_40c != 0) || (local_408 != 0)) || (local_42c != 0)) {
        (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))();
      }
      iVar18 = FUN_1403a2460();
      if (iVar18 == 0) goto LAB_1403a2e1e;
      local_44c = 1;
    }
    else {
LAB_1403a2e1e:
      local_44c = 0;
    }
    if (((iVar15 != 0) || (iVar16 != 0)) ||
       ((local_43c != 0 ||
        (((local_450 != 0 || (local_424 != 0)) || (bVar41 = false, local_44c != 0)))))) {
      bVar41 = true;
    }
    iVar15 = FUN_1404daeb0(param_1);
    fVar75 = local_454;
    if (((iVar15 == 0) && (local_458 == 0.0)) && (local_454 == 0.0)) {
      bVar36 = false;
    }
    else {
      bVar36 = true;
    }
    if ((bVar41) && (local_3d4 == 0)) {
      bVar37 = true;
    }
    else {
      bVar37 = false;
    }
    if ((!bVar36) || (local_454 = 1.4013e-45, local_434 != 0.0)) {
      local_454 = 0.0;
    }
    if (*(int *)(param_1 + 0x70b4) != -1) {
      if (((bVar37) || (local_458 != 0.0)) || (fVar75 != 0.0)) {
        *(undefined4 *)(param_1 + 0x7220) = 0;
        FUN_1405598d0(param_1 + 0x70b0);
      }
      else if (*(int *)(param_1 + 0x70b8) != 0) {
        local_3e8 = (longlong *)CONCAT44(local_3e8._4_4_,1);
        bVar37 = true;
        *(undefined4 *)(param_1 + 0x78fc) = *(undefined4 *)(param_1 + 0x710c);
      }
    }
    fVar44 = *(float *)(param_1 + 0x7908);
    local_41c = *(float *)(param_1 + 0x790c);
    local_434 = *(float *)(param_1 + 0x7910);
    fVar84 = *(float *)(param_1 + 0x7900);
    fVar78 = *(float *)(param_1 + 0x78fc);
    fVar75 = *(float *)(param_1 + 0x7904);
  }
  else {
    local_420 = 0.0;
LAB_1403a2f23:
    local_458 = 1.0;
    if (((bVar7) || (local_430 != 0)) && ((local_43c != 0 || (local_450 != 0)))) {
      local_458 = (float)DAT_140b79e78;
    }
    *(undefined8 *)(param_1 + 0x78fc) = 0;
    *(undefined8 *)(param_1 + 0x7904) = 0;
    *(undefined8 *)(param_1 + 0x790c) = 0;
    *(undefined4 *)(param_1 + 0x70b4) = 0xffffffff;
    *(undefined8 *)(param_1 + 0x70b8) = 0;
    *(undefined4 *)(param_1 + 0x70f0) = 0;
    *(undefined4 *)(param_1 + 0x70c0) = 0;
    *(undefined4 *)(param_1 + 0x70f8) = 300;
    *(undefined8 *)(param_1 + 0x70fc) = 0xffffffffffffffff;
    local_128 = CONCAT44(local_458,local_458);
    uStack_120 = CONCAT44(local_458,local_458);
    local_118 = (undefined4 *)CONCAT44(local_458,local_458);
    *(undefined4 *)(param_1 + 0x7104) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x7130) = 0;
    if (*(longlong **)(param_1 + 0x7140) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x7140) + 0x98))();
    }
    fVar44 = uStack_120._4_4_;
    local_41c = (float)local_118;
    local_434 = local_118._4_4_;
    fVar84 = local_128._4_4_;
    fVar78 = (float)local_128;
    fVar75 = (float)uStack_120;
  }
  bVar41 = false;
  if (*(int *)(param_1 + 0x70b0) != 0) {
    if (*(int *)(param_1 + 0x7220) == 0) {
      if ((bVar37) && (iVar15 = FUN_1404daf50(param_1), iVar15 != 0)) {
        *(undefined4 *)(DAT_140c65898 + 0x7230) = 2;
      }
      else if (*(int *)(param_1 + 0x7220) != 0) goto LAB_1403a306d;
    }
    else {
LAB_1403a306d:
      if (!bVar37) {
        *(undefined4 *)(DAT_140c65898 + 0x7230) = 1;
      }
    }
  }
  fVar63 = DAT_140b7a230;
  lVar23 = *(longlong *)(param_1 + 0x6490);
  local_458 = 0.0;
  local_428 = *(float *)(lVar23 + 0x12c0);
  auVar79._4_12_ = in_XMM1._4_12_;
  if ((*(int *)(lVar23 + 0x1620) == 0) && (local_420 != 0.0)) {
    iVar15 = FUN_1404daeb0(param_1,0);
    if ((iVar15 == 0) &&
       ((((iVar15 = FUN_1404daf50(), iVar15 != 0 ||
          (iVar15 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                              (*(longlong **)(param_1 + 0x7588),0x29), iVar15 != 0)) ||
         (iVar15 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                             (*(longlong **)(param_1 + 0x7588),0x2a), iVar15 != 0)) ||
        ((iVar15 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                             (*(longlong **)(param_1 + 0x7588),0x2b), iVar15 != 0 ||
         (iVar15 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                             (*(longlong **)(param_1 + 0x7588),0x2c), iVar15 != 0)))))) {
      bVar41 = true;
    }
    if (((bVar37) && (*(int *)(param_1 + 0x7220) == 0)) && (!bVar41)) {
      lVar23 = *(longlong *)(param_1 + 0x71a0);
      *(undefined8 *)(lVar23 + 0x220) = *(undefined8 *)(lVar23 + 0x230);
      *(undefined8 *)(lVar23 + 0x228) = *(undefined8 *)(lVar23 + 0x238);
      fVar52 = *(float *)(lVar23 + 0x220);
      *(undefined8 *)(lVar23 + 0x220) = 0;
      *(float *)(lVar23 + 0x34) = *(float *)(lVar23 + 0x224) + *(float *)(lVar23 + 0x34);
      *(float *)(lVar23 + 0x38) = fVar52 + *(float *)(lVar23 + 0x38);
      *(undefined8 *)(lVar23 + 0x230) = *(undefined8 *)(lVar23 + 0x220);
      *(undefined8 *)(lVar23 + 0x238) = *(undefined8 *)(lVar23 + 0x228);
      lVar23 = *(longlong *)(param_1 + 0x71a0);
      *(float *)(lVar23 + 0x214) = *(float *)(lVar23 + 0x214) + *(float *)(lVar23 + 0x244);
      fVar52 = *(float *)(lVar23 + 0x240);
      *(undefined8 *)(lVar23 + 0x240) = 0;
      *(float *)(lVar23 + 0x210) = fVar52 + *(float *)(lVar23 + 0x210);
    }
    if (*(int *)(param_1 + 0x70b4) != -1) {
      lVar23 = *(longlong *)(param_1 + 0x71a0);
      fVar52 = *(float *)(param_1 + 0x70e0) - *(float *)(lVar23 + 0x34);
      local_138 = SUB84(*(undefined8 *)(lVar23 + 0x220),0);
      _local_138 = CONCAT44(*(float *)(lVar23 + 0x224) - fVar52,local_138);
      *(undefined8 *)(lVar23 + 0x220) = _local_138;
      *(undefined8 *)(lVar23 + 0x228) = *(undefined8 *)(lVar23 + 0x228);
      lVar23 = *(longlong *)(param_1 + 0x71a0);
      local_138 = SUB84(*(undefined8 *)(lVar23 + 0x230),0);
      _local_138 = CONCAT44(*(float *)(lVar23 + 0x234) - fVar52,local_138);
      uStack_130 = *(undefined8 *)(lVar23 + 0x238);
      *(undefined8 *)(lVar23 + 0x230) = _local_138;
      *(undefined8 *)(lVar23 + 0x238) = *(undefined8 *)(lVar23 + 0x238);
      lVar23 = *(longlong *)(param_1 + 0x71a0);
      local_138 = (undefined1  [4])*(undefined4 *)(lVar23 + 0x34);
      uVar17 = *(undefined4 *)(param_1 + 0x70e0);
      *(undefined4 *)(lVar23 + 0x38) = *(undefined4 *)(lVar23 + 0x38);
      *(undefined4 *)(lVar23 + 0x34) = uVar17;
      *(undefined4 *)(lVar23 + 0x3c) = *(undefined4 *)(lVar23 + 0x3c);
    }
    iVar15 = DAT_140c44710;
    if (*DAT_140c63750 < DAT_140c44710) {
      iVar15 = *DAT_140c63750;
    }
    if (((&DAT_140c44720)[iVar15] == '\0') || (*(int *)(param_1 + 0x722c) == 0)) {
LAB_1403a3368:
      if ((!bVar37) && (local_454 == 0.0)) goto LAB_1403a3374;
LAB_1403a3385:
      if ((*(int *)(param_1 + 31000) == 0) &&
         ((*(longlong *)(param_1 + 0x7198) == 0 ||
          (*(int *)(*(longlong *)(param_1 + 0x7198) + 0x50) == 0)))) {
        local_428 = *(float *)(*(longlong *)(param_1 + 0x71a0) + 0x34);
      }
    }
    else {
      if ((bVar37) || (local_454 != 0.0)) {
        iVar15 = FUN_1404daeb0(param_1,0);
        if ((iVar15 != 0) || (!bVar41)) {
          lVar23 = *(longlong *)(param_1 + 0x71a0);
          auVar79._0_4_ = fVar43 * fVar63 * DAT_140b7a00c;
          _local_138 = *(undefined1 (*) [16])(lVar23 + 0x220);
          fVar52 = (float)FUN_1408fc7f0(auVar79._0_8_);
          auStack_134 = (undefined1  [4])(*(float *)(lVar23 + 0x224) * fVar52);
          local_138 = (undefined1  [4])((float)local_138 * fVar52);
          *(undefined8 *)(lVar23 + 0x220) = _local_138;
          *(undefined8 *)(lVar23 + 0x228) = uStack_130;
        }
        goto LAB_1403a3368;
      }
LAB_1403a3374:
      if (*(float *)(*(longlong *)(param_1 + 0x71a0) + 0x214) != 0.0) goto LAB_1403a3385;
    }
    lVar23 = *(longlong *)(param_1 + 0x6490);
    if ((*(byte *)(lVar23 + 0x1070) & 0x80) == 0) goto LAB_1403a33f0;
    if (bVar37) {
      if (*(int *)(param_1 + 0x70b4) == -1) {
        local_458 = *(float *)(*(longlong *)(param_1 + 0x71a0) + 0x38);
      }
      else {
        local_458 = *(float *)(param_1 + 0x70e4);
      }
      goto LAB_1403a33f0;
    }
LAB_1403a353c:
    auVar29 = (undefined1  [4])(float)local_3e8;
  }
  else {
LAB_1403a33f0:
    if ((!bVar37) ||
       ((*(longlong *)(lVar23 + 0x388) == 0 &&
        (*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x388) == 0)))) goto LAB_1403a353c;
    _local_138 = ZEXT816(0);
    if ((float)local_3e8 != 0.0) {
      *(undefined4 *)(local_138 + (longlong)*(int *)(param_1 + 0x6378) * 4) = 1;
    }
    if (local_430 != 0) {
      *(undefined4 *)(local_138 + (longlong)*(int *)(param_1 + 0x637c) * 4) = 1;
    }
    if (local_43c != 0) {
      *(undefined4 *)(local_138 + (longlong)*(int *)(param_1 + 0x6380) * 4) = 1;
    }
    if (local_450 != 0) {
      *(undefined4 *)(local_138 + (longlong)*(int *)(param_1 + 0x6384) * 4) = 1;
    }
    local_430 = (int)auStack_134;
    local_43c = (int)(float)uStack_130;
    local_450 = (uint)uStack_130._4_4_;
    if ((((local_138 == (undefined1  [4])0x0) && (auStack_134 == (undefined1  [4])0x0)) &&
        ((float)uStack_130 == 0.0)) &&
       (((uStack_130._4_4_ == 0.0 && (local_424 == 0)) && (local_44c == 0)))) {
      bVar37 = false;
    }
    else {
      bVar37 = true;
    }
    *(undefined8 *)(param_1 + 0x78fc) = 0;
    *(undefined8 *)(param_1 + 0x7904) = 0;
    local_118 = (undefined4 *)0x3f8000003f800000;
    local_128 = 0x3f8000003f800000;
    uStack_120 = 0x3f8000003f800000;
    uStack_120._4_4_ = 1.0;
    uStack_120._0_4_ = 1.0;
    *(undefined8 *)(param_1 + 0x790c) = 0;
    local_128._4_4_ = 1.0;
    local_128._0_4_ = 1.0;
    local_434 = 1.0;
    local_41c = 1.0;
    fVar44 = uStack_120._4_4_;
    fVar84 = local_128._4_4_;
    auVar29 = local_138;
    fVar78 = (float)local_128;
    fVar75 = (float)uStack_120;
  }
  auVar85 = ZEXT416((uint)fVar75);
  if (((*(longlong *)(param_1 + 0x78) == 0) ||
      (local_3e8 = (longlong *)
                   FUN_1403d90d0(DAT_140c65898,*(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0xc0)
                                ), local_3e8 == (longlong *)0x0)) ||
     ((iVar15 = (**(code **)(*local_3e8 + 0x20))(local_3e8), iVar15 == 0 ||
      ((local_3e8[0x17] == 0 || (*(int *)(local_3e8[0x17] + 4) != 6)))))) {
    *(undefined4 *)(param_1 + 0x7914) = 0x3f000000;
    if (bVar37) goto LAB_1403a36a5;
LAB_1403a36bd:
    local_450 = 0;
    puVar20[10] = 0;
    puVar20[0xb] = 0;
    iVar15 = 0;
  }
  else {
    fVar84 = 0.0;
    local_41c = 0.0;
    local_434 = 0.0;
    bVar41 = local_430 != 0;
    if (bVar41) {
      local_430 = 0;
      local_41c = fVar46;
      *(float *)(param_1 + 0x7914) = *(float *)(param_1 + 0x7914) - fVar43 * DAT_140b79da4;
    }
    local_424 = (uint)bVar41;
    if (auVar29 != (undefined1  [4])0x0) {
      local_434 = fVar46;
      *(float *)(param_1 + 0x7914) = fVar43 * DAT_140b79dec + *(float *)(param_1 + 0x7914);
    }
    local_44c = (uint)(auVar29 != (undefined1  [4])0x0);
    fVar43 = *(float *)(param_1 + 0x7914);
    if (fVar46 <= *(float *)(param_1 + 0x7914)) {
      fVar43 = fVar46;
    }
    fVar78 = 0.0;
    if (0.0 <= fVar43) {
      fVar78 = fVar43;
    }
    *(float *)(param_1 + 0x7914) = fVar78;
    fVar43 = fVar78 * _DAT_140b79e24;
    if (fVar43 < local_434) {
      local_434 = fVar43;
    }
    fVar63 = DAT_140b7a230;
    auVar29 = (undefined1  [4])iVar19;
    if (fVar43 < local_41c) {
      local_41c = fVar43;
    }
LAB_1403a36a5:
    if (*(int *)(*(longlong *)(param_1 + 0x6490) + 0x1cc) != 0) {
      FUN_1403a2550(param_1);
      goto LAB_1403a36bd;
    }
    if ((*(int *)(param_1 + 31000) == 0) &&
       ((*(longlong *)(param_1 + 0x7198) == 0 ||
        (*(int *)(*(longlong *)(param_1 + 0x7198) + 0x50) == 0)))) {
      _local_138 = ZEXT816(0);
      auVar79 = _local_138;
      uStack_130._0_4_ = 0.0;
      fVar43 = (float)uStack_130;
      _local_138 = auVar79;
      if (auVar29 != (undefined1  [4])0x0) {
        fVar43 = 0.0 - fVar78;
        _local_138 = ZEXT416((uint)fVar43) << 0x40;
      }
      if (local_430 != 0) {
        auVar11._4_4_ = uStack_130._4_4_;
        auVar11._0_4_ = fVar43 + fVar84;
        auVar11._8_8_ = 0;
        _local_138 = auVar11 << 0x40;
      }
      fVar43 = 0.0;
      if (local_43c != 0) {
        fVar43 = 0.0 - fVar75;
        local_138 = (undefined1  [4])fVar43;
      }
      if (local_450 != 0) {
        local_138 = (undefined1  [4])(fVar43 + fVar44);
      }
      if (local_440 != 0.0) {
        if (local_430 == 0) {
          local_438 = uVar39 | 0x1000;
          uVar39 = local_438;
        }
        else {
          local_438 = uVar39 | 0x2000;
          uVar39 = local_438;
        }
      }
      plVar24 = *(longlong **)(*(longlong *)(param_1 + 0x6490) + 0x10c8);
      if ((((plVar24 == (longlong *)0x0) || (iVar15 = (**(code **)(*plVar24 + 8))(), iVar15 != 0x11)
           ) && (fVar43 = DAT_140b79e48, *(int *)(param_1 + 31000) == 0)) &&
         ((*(longlong *)(param_1 + 0x7198) == 0 ||
          (*(int *)(*(longlong *)(param_1 + 0x7198) + 0x50) == 0)))) {
        auVar29 = local_138;
        auVar14 = auStack_134;
        fVar75 = (float)uStack_130;
        fVar78 = (float)auStack_134 * (float)auStack_134;
        auVar56._4_4_ = fVar78;
        auVar56._0_4_ = fVar78;
        auVar56._8_4_ = fVar78;
        auVar56._12_4_ = fVar78;
        fVar44 = (float)local_138 * (float)local_138 + fVar78 +
                 (float)uStack_130 * (float)uStack_130;
        auVar2._4_4_ = fVar78;
        auVar2._0_4_ = fVar44;
        auVar2._8_4_ = (float)uStack_130 * (float)uStack_130;
        auVar2._12_4_ = uStack_130._4_4_ * uStack_130._4_4_;
        auVar79 = rsqrtss(auVar56,auVar2);
        fVar78 = auVar79._0_4_;
        fVar78 = (DAT_140b79fa0 - fVar44 * fVar78 * fVar78) * DAT_140b79e48 * fVar78;
        if (fVar78 <= 0.0) {
          fVar78 = 0.0;
        }
        fVar63 = fVar78 * (float)local_138;
        fVar52 = fVar78 * (float)auStack_134;
        fVar78 = fVar78 * (float)uStack_130;
        fVar44 = (float)FUN_1408fe3d0();
        fVar84 = (float)FUN_1408fc950();
        local_450 = (uint)(fVar43 < fVar44 * fVar63 + fVar52 * 0.0 + fVar84 * fVar78);
        fVar43 = (float)FUN_1408fe3d0();
        fVar78 = (float)FUN_1408fc950();
        fVar44 = (float)FUN_1408fe3d0();
        fVar84 = (float)FUN_1408fc950();
        fVar63 = (float)FUN_1408fe3d0();
        fVar52 = (float)FUN_1408fc950();
        local_138 = (undefined1  [4])(fVar43 * fVar63 * fVar84 + fVar78 * fVar52 * fVar44);
        auStack_134 = (undefined1  [4])(fVar78 * fVar63 * fVar84 - fVar43 * fVar52 * fVar44);
        auVar85 = ZEXT416((uint)DAT_140b79f58);
        uStack_130._0_4_ = fVar43 * fVar52 * fVar84 - fVar78 * fVar63 * fVar44;
        uStack_130._4_4_ = fVar43 * fVar63 * fVar44 + fVar78 * fVar52 * fVar84;
        fVar81 = (float)uStack_130 * DAT_140b79f58;
        fVar65 = (float)auStack_134 * DAT_140b79f58;
        fStack_104 = (float)local_138 * DAT_140b79f58 * uStack_130._4_4_;
        local_108 = fVar81 * (float)local_138 + fVar65 * uStack_130._4_4_;
        fVar84 = fVar81 * (float)local_138 - fVar65 * uStack_130._4_4_;
        fVar43 = (fVar46 - fVar65 * (float)auStack_134) - fVar81 * (float)uStack_130;
        uStack_120 = (ulonglong)(uint)fVar84;
        fVar63 = fVar81 * (float)auStack_134 + fStack_104;
        fStack_104 = fVar81 * (float)auStack_134 - fStack_104;
        fVar78 = fVar65 * (float)local_138 + fVar81 * uStack_130._4_4_;
        fVar52 = fVar65 * (float)local_138 - fVar81 * uStack_130._4_4_;
        uStack_110 = (ulonglong)(uint)fVar63;
        local_128 = CONCAT44(fVar78,fVar43);
        fVar44 = fVar46 - (float)local_138 * DAT_140b79f58 * (float)local_138;
        fVar65 = fVar44 - fVar65 * (float)auStack_134;
        fVar44 = fVar44 - fVar81 * (float)uStack_130;
        uStack_100 = (ulonglong)(uint)fVar65;
        local_118 = (undefined4 *)CONCAT44(fVar44,fVar52);
        local_f8 = _DAT_140b7ad00;
        uStack_f0 = _UNK_140b7ad08;
        *(float *)(puVar20 + 10) =
             (float)auVar14 * fVar52 + (float)auVar29 * fVar43 + fVar75 * local_108;
        *(float *)((longlong)puVar20 + 0x54) =
             (float)auVar14 * fVar44 + (float)auVar29 * fVar78 + fVar75 * fStack_104;
        *(float *)(puVar20 + 0xb) =
             (float)auVar14 * fVar63 + (float)auVar29 * fVar84 + fVar75 * fVar65;
        *(float *)((longlong)puVar20 + 0x5c) =
             (float)auVar14 * 0.0 + (float)auVar29 * 0.0 + fVar75 * 0.0;
      }
      else {
        auVar29 = local_138;
        auVar14 = auStack_134;
        fVar43 = (float)uStack_130;
        fVar75 = (float)auStack_134 * (float)auStack_134;
        auVar57._4_4_ = fVar75;
        auVar57._0_4_ = fVar75;
        auVar57._8_4_ = fVar75;
        auVar57._12_4_ = fVar75;
        fVar78 = (float)local_138 * (float)local_138 + fVar75 +
                 (float)uStack_130 * (float)uStack_130;
        auVar3._4_4_ = fVar75;
        auVar3._0_4_ = fVar78;
        auVar3._8_4_ = (float)uStack_130 * (float)uStack_130;
        auVar3._12_4_ = uStack_130._4_4_ * uStack_130._4_4_;
        auVar79 = rsqrtss(auVar57,auVar3);
        fVar75 = auVar79._0_4_;
        fVar75 = (DAT_140b79fa0 - fVar78 * fVar75 * fVar75) * DAT_140b79e48 * fVar75;
        if (fVar75 <= 0.0) {
          fVar75 = 0.0;
        }
        local_450 = (uint)(DAT_140b79e48 < fVar75 * (float)uStack_130);
        fVar75 = (float)FUN_1408fe3d0();
        fVar78 = (float)FUN_1408fc950();
        fVar44 = (float)FUN_1408fe3d0();
        fVar84 = (float)FUN_1408fc950();
        fVar63 = (float)FUN_1408fe3d0();
        fVar52 = (float)FUN_1408fc950();
        fVar81 = fVar52 * fVar44 * fVar78 + fVar63 * fVar84 * fVar75;
        local_138 = (undefined1  [4])fVar81;
        fVar65 = fVar52 * fVar84 * fVar75 - fVar63 * fVar44 * fVar78;
        fVar53 = fVar63 * fVar44 * fVar75 + fVar52 * fVar84 * fVar78;
        uStack_130._0_4_ = fVar65;
        uStack_130._4_4_ = fVar53;
        fVar82 = fVar63 * fVar84 * fVar78 - fVar52 * fVar44 * fVar75;
        auStack_134 = (undefined1  [4])fVar82;
        fVar84 = fVar82 * DAT_140b79f58;
        fStack_104 = fVar53 * fVar81 * DAT_140b79f58;
        fVar80 = fVar65 * DAT_140b79f58;
        fVar75 = (fVar46 - fVar82 * fVar84) - fVar65 * fVar80;
        fVar78 = fVar81 * fVar84 + fVar53 * fVar80;
        fVar67 = fVar81 * fVar84 - fVar53 * fVar80;
        fVar63 = fVar81 * fVar80 - fVar53 * fVar84;
        local_128 = CONCAT44(fVar78,fVar75);
        uStack_120 = (ulonglong)(uint)fVar63;
        fVar83 = fVar46 - fVar81 * fVar81 * DAT_140b79f58;
        local_108 = fVar81 * fVar80 + fVar53 * fVar84;
        fVar52 = fVar82 * fVar80 + fStack_104;
        fVar44 = fVar83 - fVar65 * fVar80;
        fStack_104 = fVar82 * fVar80 - fStack_104;
        local_118 = (undefined4 *)CONCAT44(fVar44,fVar67);
        uStack_110 = (ulonglong)(uint)fVar52;
        fVar83 = fVar83 - fVar82 * fVar84;
        local_f8 = _DAT_140b7ad00;
        uStack_f0 = _UNK_140b7ad08;
        uStack_100 = (ulonglong)(uint)fVar83;
        auVar85._0_4_ = fVar43 * local_108;
        auVar85._4_4_ = fVar43 * fStack_104;
        auVar85._8_4_ = fVar43 * fVar83;
        auVar85._12_4_ = fVar43 * 0.0;
        *(float *)(puVar20 + 10) = (float)auVar14 * fVar67 + (float)auVar29 * fVar75 + auVar85._0_4_
        ;
        *(float *)((longlong)puVar20 + 0x54) =
             (float)auVar14 * fVar44 + (float)auVar29 * fVar78 + auVar85._4_4_;
        *(float *)(puVar20 + 0xb) =
             (float)auVar14 * fVar52 + (float)auVar29 * fVar63 + auVar85._8_4_;
        *(float *)((longlong)puVar20 + 0x5c) =
             (float)auVar14 * 0.0 + (float)auVar29 * 0.0 + auVar85._12_4_;
      }
    }
    else {
      local_3e8 = (longlong *)0x0;
      if ((*(int *)(param_1 + 0x78d8) == 0) && (*(int *)(param_1 + 0x78ec) == 0)) {
        fVar43 = (fVar78 - fVar84) * (fVar78 - fVar84);
        auVar79 = sqrtps(ZEXT416((uint)fVar43),
                         ZEXT416((uint)((fVar44 - fVar75) * (fVar44 - fVar75) + fVar43)));
        fVar43 = 0.0 - auVar79._0_4_;
        uStack_3e0 = (ulonglong)(uint)fVar43;
        if (*(int *)(param_1 + 0x70b4) == -1) {
          if (fVar43 < DAT_140b7a1fc) {
            uVar47 = FUN_1408fd190();
            uVar17 = (undefined4)((ulonglong)uVar47 >> 0x20);
            uVar27 = FUN_1408fc7f0(local_3d8 * fVar63 * DAT_140b7a060);
            fVar75 = (((float)uVar47 - local_428) + DAT_140b79fac) * DAT_140b79dd4;
            auVar59._4_4_ = uVar17;
            auVar59._0_4_ = fVar75;
            iVar15 = (int)fVar75;
            fVar43 = fVar75;
            if ((iVar15 != -0x80000000) && ((float)iVar15 != fVar75)) {
              auVar59._8_4_ = uVar17;
              auVar59._12_4_ = uVar17;
              auVar58._8_8_ = auVar59._8_8_;
              auVar58._4_4_ = fVar75;
              auVar58._0_4_ = fVar75;
              uVar27 = movmskps(uVar27,auVar58);
              uVar27 = uVar27 & 1;
              fVar43 = (float)(int)(iVar15 - uVar27);
            }
            fVar75 = (((fVar75 - fVar43) * DAT_140b7a018 - DAT_140b79fac) *
                      (fVar46 - extraout_XMM0_Da) + local_428 + DAT_140b79fac) * DAT_140b79dd4;
            auVar61._4_4_ = uVar17;
            auVar61._0_4_ = fVar75;
            iVar15 = (int)fVar75;
            fVar43 = fVar75;
            if ((iVar15 != -0x80000000) && ((float)iVar15 != fVar75)) {
              auVar61._8_4_ = uVar17;
              auVar61._12_4_ = uVar17;
              auVar60._8_8_ = auVar61._8_8_;
              auVar60._4_4_ = fVar75;
              auVar60._0_4_ = fVar75;
              uVar27 = movmskps(uVar27,auVar60);
              fVar43 = (float)(int)(iVar15 - (uVar27 & 1));
            }
            local_428 = (fVar75 - fVar43) * DAT_140b7a018 - DAT_140b79fac;
          }
        }
        else {
          local_428 = *(float *)(param_1 + 0x70e0);
        }
      }
      else {
        uStack_3e0 = (ulonglong)DAT_140b7a23c;
      }
      if (local_440 != 0.0) {
        local_438 = uVar39 | 0x1000;
        uVar39 = local_438;
      }
      local_450 = 0;
      fVar43 = (float)FUN_1408fe3d0();
      fVar75 = (float)FUN_1408fc950();
      fVar78 = (float)FUN_1408fe3d0();
      fVar44 = (float)FUN_1408fc950();
      fVar84 = (float)FUN_1408fe3d0();
      fVar63 = (float)FUN_1408fc950();
      fVar65 = fVar63 * fVar78 * fVar75 + fVar84 * fVar44 * fVar43;
      fVar67 = fVar84 * fVar44 * fVar75 - fVar63 * fVar78 * fVar43;
      fVar52 = fVar63 * fVar44 * fVar43 - fVar84 * fVar78 * fVar75;
      fVar80 = fVar84 * fVar78 * fVar43 + fVar63 * fVar44 * fVar75;
      uStack_130._0_4_ = fVar52;
      auStack_134 = (undefined1  [4])fVar67;
      local_138 = (undefined1  [4])fVar65;
      uStack_130._4_4_ = fVar80;
      fVar83 = fVar52 * DAT_140b79f58;
      fVar82 = fVar67 * DAT_140b79f58;
      fStack_104 = fVar65 * DAT_140b79f58 * fVar80;
      fVar43 = (fVar46 - fVar82 * fVar67) - fVar83 * fVar52;
      fVar63 = fVar82 * fVar65 - fVar83 * fVar80;
      fVar75 = fVar82 * fVar65 + fVar83 * fVar80;
      fVar44 = fVar83 * fVar65 - fVar82 * fVar80;
      fVar78 = fVar46 - fVar65 * DAT_140b79f58 * fVar65;
      local_128 = CONCAT44(fVar75,fVar43);
      uStack_120 = (ulonglong)(uint)fVar44;
      fVar81 = fVar78 - fVar82 * fVar67;
      fVar78 = fVar78 - fVar83 * fVar52;
      fVar84 = fVar83 * fVar67 + fStack_104;
      uStack_100 = (ulonglong)(uint)fVar81;
      local_118 = (undefined4 *)CONCAT44(fVar78,fVar63);
      uStack_110 = (ulonglong)(uint)fVar84;
      local_108 = fVar83 * fVar65 + fVar82 * fVar80;
      fStack_104 = fVar83 * fVar67 - fStack_104;
      local_f8 = _DAT_140b7ad00;
      uStack_f0 = _UNK_140b7ad08;
      *(float *)(puVar20 + 10) =
           local_3e8._4_4_ * fVar63 + (float)local_3e8 * fVar43 + (float)uStack_3e0 * local_108;
      *(float *)((longlong)puVar20 + 0x54) =
           local_3e8._4_4_ * fVar78 + (float)local_3e8 * fVar75 + (float)uStack_3e0 * fStack_104;
      *(float *)(puVar20 + 0xb) =
           local_3e8._4_4_ * fVar84 + (float)local_3e8 * fVar44 + (float)uStack_3e0 * fVar81;
      *(float *)((longlong)puVar20 + 0x5c) =
           local_3e8._4_4_ * 0.0 + (float)local_3e8 * 0.0 + (float)uStack_3e0 * 0.0;
    }
    if (local_424 != 0) {
      *(float *)((longlong)puVar20 + 0x54) = local_41c + *(float *)((longlong)puVar20 + 0x54);
    }
    if (local_44c != 0) {
      *(float *)((longlong)puVar20 + 0x54) = *(float *)((longlong)puVar20 + 0x54) - local_434;
    }
    fVar43 = *(float *)(puVar20 + 10) * *(float *)(puVar20 + 10) +
             *(float *)((longlong)puVar20 + 0x54) * *(float *)((longlong)puVar20 + 0x54) +
             *(float *)(puVar20 + 0xb) * *(float *)(puVar20 + 0xb);
    if (fVar46 < fVar43) {
      auVar48._0_4_ = SQRT(fVar43);
      auVar48._4_4_ = auVar48._0_4_;
      auVar48._8_4_ = auVar48._0_4_;
      auVar48._12_4_ = auVar48._0_4_;
      auVar79 = divps(*(undefined1 (*) [16])(puVar20 + 10),auVar48);
      *(undefined1 (*) [16])(puVar20 + 10) = auVar79;
    }
    iVar15 = 0;
    if (fVar43 != 0.0) {
      iVar15 = iVar19;
    }
  }
  fVar43 = 0.0;
  fVar78 = 0.0;
  fVar75 = 0.0;
  *(int *)(param_1 + 0x7220) = iVar15;
  *(float *)(param_1 + 0x7224) = local_454;
  if (local_42c == 0) {
    local_440 = *(float *)(*(longlong *)(param_1 + 0x6490) + 0x1088);
  }
  else {
    local_440 = 4.2039e-45;
  }
  fVar44 = DAT_140dc21f4;
  if ((DAT_140dc21e0 & 0x10) == 0) {
    DAT_140dc21e0 = DAT_140dc21e0 | 0x10;
    if (DAT_140c63840 == (code *)0x0) {
      fVar44 = DAT_140b7a074;
      if ((DAT_140c638ac != 0) || (iVar19 = FUN_1401fffc0(), fVar44 = DAT_140b7a074, iVar19 < 0))
      goto LAB_1403a42a5;
      lVar23 = (**(code **)(*DAT_140c64c58 + 0x18))(DAT_140c64c58,0x10b);
    }
    else {
      lVar23 = (*DAT_140c63840)(&PTR_u_GameFormula_140a6a408,0x10b,DAT_140c63858);
    }
    fVar44 = DAT_140b7a074;
    if (lVar23 != 0) {
      fVar44 = *(float *)(lVar23 + 0x1c);
    }
  }
LAB_1403a42a5:
  DAT_140dc21f4 = fVar44;
  if ((DAT_140dc21e0 & 0x20) == 0) {
    DAT_140dc21e0 = DAT_140dc21e0 | 0x20;
    if (DAT_140c63840 == (code *)0x0) {
      if ((DAT_140c638ac == 0) && (iVar19 = FUN_1401fffc0(), -1 < iVar19)) {
        lVar23 = (**(code **)(*DAT_140c64c58 + 0x18))(DAT_140c64c58,0x1e1);
        goto LAB_1403a42f7;
      }
    }
    else {
      lVar23 = (*DAT_140c63840)(&PTR_u_GameFormula_140a6a408,0x1e1,DAT_140c63858);
LAB_1403a42f7:
      if (lVar23 != 0) {
        DAT_140dc21f8 = *(float *)(lVar23 + 0x18);
        goto LAB_1403a4325;
      }
    }
    DAT_140dc21f8 = DAT_140b7a03c;
  }
LAB_1403a4325:
  if (*(int *)(param_1 + 0x78d8) == 0) {
    if (*(int *)(param_1 + 0x78ec) == 0) {
      if (local_450 == 0) {
        if (local_42c == 0) {
          iVar19 = DAT_140c44a80;
          if (*DAT_140c63750 < DAT_140c44a80) {
            iVar19 = *DAT_140c63750;
          }
          if (((&DAT_140c44a90)[iVar19] == '\0') ||
             (iVar19 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                                 (*(longlong **)(param_1 + 0x7588),9), iVar19 == 0)) {
            iVar19 = DAT_140c45de0;
            if (*DAT_140c63750 < DAT_140c45de0) {
              iVar19 = *DAT_140c63750;
            }
            if (*(int *)(&DAT_140c45df0 + (longlong)iVar19 * 4) != 0) {
              uVar42 = 4;
              goto LAB_1403a4437;
            }
          }
          uVar42 = 3;
        }
        else {
          uVar42 = 5;
        }
      }
      else if (local_42c == 0) {
        iVar19 = DAT_140c45de0;
        if (*DAT_140c63750 < DAT_140c45de0) {
          iVar19 = *DAT_140c63750;
        }
        uVar42 = *(int *)(&DAT_140c45df0 + (longlong)iVar19 * 4) == 0;
      }
      else {
        uVar42 = 0;
      }
LAB_1403a4437:
      fVar44 = (float)FUN_1405b45e0(*(undefined8 *)(param_1 + 0x6490),local_440,uVar42);
      fVar84 = *(float *)(puVar20 + 10) * fVar44;
      fVar63 = *(float *)((longlong)puVar20 + 0x54) * fVar44;
      fVar52 = *(float *)(puVar20 + 0xb) * fVar44;
      fVar44 = *(float *)((longlong)puVar20 + 0x5c) * fVar44;
      goto LAB_1403a4452;
    }
    fVar44 = DAT_140dc21f8 * local_448;
    *(float *)(puVar20 + 10) = fVar44 * *(float *)(puVar20 + 10);
    *(float *)((longlong)puVar20 + 0x54) = fVar44 * *(float *)((longlong)puVar20 + 0x54);
    *(float *)(puVar20 + 0xb) = fVar44 * *(float *)(puVar20 + 0xb);
    *(float *)((longlong)puVar20 + 0x5c) = fVar44 * *(float *)((longlong)puVar20 + 0x5c);
  }
  else {
    fVar44 = DAT_140dc21f4 * local_410;
    fVar84 = fVar44 * *(float *)(puVar20 + 10);
    fVar63 = fVar44 * *(float *)((longlong)puVar20 + 0x54);
    fVar52 = fVar44 * *(float *)(puVar20 + 0xb);
    fVar44 = fVar44 * *(float *)((longlong)puVar20 + 0x5c);
LAB_1403a4452:
    *(float *)(puVar20 + 10) = fVar84;
    *(float *)((longlong)puVar20 + 0x54) = fVar63;
    *(float *)(puVar20 + 0xb) = fVar52;
    *(float *)((longlong)puVar20 + 0x5c) = fVar44;
  }
  fVar44 = DAT_140b79eec;
  if ((DAT_140dc21e0 & 0x40) == 0) {
    DAT_140dc21e0 = DAT_140dc21e0 | 0x40;
    lVar23 = FUN_140200220(0x430);
    DAT_140dc21fc = fVar44;
    if (lVar23 != 0) {
      DAT_140dc21fc = *(float *)(lVar23 + 0x18);
    }
  }
  if (-1 < (char)DAT_140dc21e0) {
    DAT_140dc21e0 = DAT_140dc21e0 | 0x80;
    lVar23 = FUN_140200220(0x430);
    DAT_140dc2200 = fVar44;
    if (lVar23 != 0) {
      DAT_140dc2200 = *(float *)(lVar23 + 0x1c);
    }
  }
  if ((DAT_140dc21e0 & 0x100) == 0) {
    DAT_140dc21e0 = DAT_140dc21e0 | 0x100;
    local_410 = 0.0;
    iVar19 = 0;
    if ((int)DAT_140dc2200 < 0) {
      iVar19 = -0x80000000;
    }
    uVar27 = iVar19 - (int)DAT_140dc2200 >> 0x1f;
    DAT_140dc2204 = DAT_140dc2200;
    local_448 = DAT_140dc2200;
    if ((int)((iVar19 - (int)DAT_140dc2200 ^ uVar27) - uVar27) < 0x55) {
      DAT_140dc2204 = DAT_140dc21fc;
    }
  }
  plVar24 = *(longlong **)(param_1 + 0x6490);
  if (((((*(byte *)(plVar24 + 0x2ef) & 1) == 0) || (local_40c != 0)) || (local_408 != 0)) ||
     ((local_42c != 0 || (*(int *)((longlong)plVar24 + 0x2ac) != 0)))) {
    FUN_1403a0c50(param_1);
  }
  else {
    iVar19 = (**(code **)(*plVar24 + 0x20))(plVar24);
    fVar44 = DAT_140dc21fc;
    if (iVar19 != 0) {
      fVar44 = DAT_140dc2204;
    }
    *(float *)(puVar20 + 10) = *(float *)(puVar20 + 10) * fVar44;
    *(float *)((longlong)puVar20 + 0x54) = *(float *)((longlong)puVar20 + 0x54) * fVar44;
    *(float *)(puVar20 + 0xb) = *(float *)(puVar20 + 0xb) * fVar44;
    *(float *)((longlong)puVar20 + 0x5c) = *(float *)((longlong)puVar20 + 0x5c) * fVar44;
    FUN_1403a0b80(param_1);
  }
  fVar84 = DAT_140b79e48;
  fVar44 = DAT_140b79df8;
  uVar27 = *(uint *)(plVar24 + 0x2ef);
  fVar63 = 0.0;
  if ((uVar27 & 2) != 0) {
    fVar63 = DAT_140b79df8;
  }
  if ((uVar27 & 4) != 0) {
    fVar63 = fVar63 + DAT_140b79e48;
  }
  fVar52 = fVar46;
  if ((char)uVar27 < '\0') {
    iVar19 = DAT_140c44810;
    if (*DAT_140c63750 < DAT_140c44810) {
      iVar19 = *DAT_140c63750;
    }
    fVar52 = *(float *)(&DAT_140c44820 + (longlong)iVar19 * 4);
  }
  lVar23 = *(longlong *)(param_1 + 0x6490);
  iVar19 = DAT_140c44ac0;
  if (*DAT_140c63750 < DAT_140c44ac0) {
    iVar19 = *DAT_140c63750;
  }
  _local_138 = ZEXT416((uint)fVar52);
  if (*(float *)(lVar23 + 0x934) <= fVar52) {
    _local_138 = ZEXT416((uint)*(float *)(lVar23 + 0x934));
  }
  fVar63 = *(float *)(&DAT_140c44ad0 + (longlong)iVar19 * 4) * DAT_140b79d68 *
           *(float *)(lVar23 + 0x9d4) * (fVar46 - fVar63);
  if (*(longlong *)(param_1 + 0x78) != lVar23) {
    fVar63 = fVar63 * *(float *)(*(longlong *)(param_1 + 0x78) + 0x9d4);
  }
  local_448 = fVar46 / fVar63;
  fVar63 = fVar63 * DAT_140b7a084;
  auVar79 = sqrtps(ZEXT416((uint)fVar52),ZEXT416((uint)local_448));
  fVar52 = auVar79._0_4_ * *(float *)(lVar23 + 0x9cc);
  auVar49._4_4_ = auVar79._4_4_;
  auVar49._0_4_ = fVar52;
  auVar49._8_4_ = auVar79._8_4_;
  auVar49._12_4_ = auVar79._12_4_;
  auVar50._4_12_ = auVar49._4_12_;
  auVar50._0_4_ = (fVar52 * DAT_140b7a028) / fVar63;
  auVar79 = sqrtps(auVar85,auVar50);
  fVar65 = auVar79._0_4_;
  local_458 = fVar65;
  local_454 = fVar52;
  if ((local_420 == 0.0) ||
     ((((*(uint *)(lVar23 + 0x1070) & 0x40) != 0 &&
       ((((*(uint *)(lVar23 + 0x1070) >> 0xb & 1) != 0 ||
         ((iVar19 = FUN_14039e0e0(param_1), iVar19 != 0 &&
          (iVar19 = FUN_14039e210(param_1), iVar19 == 0)))) ||
        (-1 < (DAT_140c636a8 - (int)(longlong)(fVar65 * _DAT_140b7a16c)) -
              *(int *)(param_1 + 0x70a0))))) ||
      ((uVar27 = *(uint *)(*(longlong *)(param_1 + 0x6490) + 0x1070), (uVar27 & 0x40) == 0 &&
       (((DAT_140c636a8 - (int)(longlong)(fVar65 * DAT_140b7a158)) - *(int *)(param_1 + 0x70a0) < 0
        || ((uVar27 & 0x20) != 0)))))))) {
    *(undefined4 *)(param_1 + 0x75d8) = 0;
  }
  if ((((*(int *)(param_1 + 0x75d8) == 0) || (local_40c != 0)) || (local_408 != 0)) ||
     (plVar24 = *(longlong **)(param_1 + 0x6490), *(int *)((longlong)plVar24 + 0x12dc) == 0)) {
LAB_1403a477d:
    local_44c = 0;
    uVar27 = 0;
  }
  else {
    uVar27 = 1;
    local_44c = 1;
    if (*(int *)((longlong)plVar24 + 0x1cc) != 0) {
      FUN_1403a2550(param_1);
      goto LAB_1403a477d;
    }
    iVar19 = (**(code **)(*plVar24 + 0x20))();
    if ((iVar19 != 0) &&
       (lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x6490) + 0xb8), lVar23 != 0)) {
      uVar27 = (uint)((*(uint *)(lVar23 + 0x60) & 0x100) == 0);
      local_44c = uVar27;
    }
  }
  fVar81 = local_3d8;
  puVar20[0xc] = 0;
  puVar20[0xd] = 0;
  if ((uVar27 != 0) && (DAT_140b79cc4 < fVar65)) {
    lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x6490) + 0xf00);
    fVar67 = fVar46;
    if (lVar23 != 0) {
      fVar67 = fVar46 / *(float *)(lVar23 + 0x12c4);
    }
    fVar53 = (fVar52 * DAT_140b79fe8) / fVar65;
    fVar83 = local_418[5];
    fVar80 = local_418[6];
    fVar82 = local_418[7];
    *(float *)(puVar20 + 0xc) = fVar53 * local_418[4] * fVar67;
    *(float *)((longlong)puVar20 + 100) = fVar53 * fVar83 * fVar67;
    *(float *)(puVar20 + 0xd) = fVar53 * fVar80 * fVar67;
    *(float *)((longlong)puVar20 + 0x6c) = fVar53 * fVar82 * fVar67;
  }
  lVar23 = *(longlong *)(param_1 + 0x6490);
  fVar67 = *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x570);
  fVar83 = *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x574);
  local_440 = fVar67;
  local_420 = fVar83;
  if (local_42c == 0) {
    *puVar20 = local_3c8;
    puVar20[1] = uStack_3c0;
    puVar20[2] = local_3f8;
    puVar20[3] = uStack_3f0;
    uVar47 = *(undefined8 *)(*(longlong *)(param_1 + 0x6490) + 0x11e8);
    puVar20[4] = *(undefined8 *)(*(longlong *)(param_1 + 0x6490) + 0x11e0);
    puVar20[5] = uVar47;
    lVar23 = *(longlong *)(param_1 + 0x6490);
    fVar84 = *(float *)(lVar23 + 0xff0);
    fVar81 = *(float *)(lVar23 + 0xff4);
    fVar80 = *(float *)(lVar23 + 0xff8);
    fVar82 = local_418[5];
    fVar53 = local_418[6];
    fVar55 = local_418[7];
    fVar77 = local_418[1];
    fVar54 = local_418[2];
    fVar64 = local_418[3];
    fVar66 = local_418[9];
    fVar4 = local_418[10];
    fVar74 = local_418[0xb];
    *(float *)(puVar20 + 8) = fVar81 * local_418[4] + fVar84 * *local_418 + fVar80 * local_418[8];
    *(float *)((longlong)puVar20 + 0x44) = fVar81 * fVar82 + fVar84 * fVar77 + fVar80 * fVar66;
    *(float *)(puVar20 + 9) = fVar81 * fVar53 + fVar84 * fVar54 + fVar80 * fVar4;
    *(float *)((longlong)puVar20 + 0x4c) = fVar81 * fVar55 + fVar84 * fVar64 + fVar80 * fVar74;
    *(uint *)(puVar20 + 0x10) = local_40c;
    *(uint *)((longlong)puVar20 + 0x84) = local_408;
    *(undefined4 *)(puVar20 + 0x12) = 0;
    if (((*(int *)(param_1 + 0x78d8) != 0) && (*(int *)(param_1 + 0x78dc) == 0)) ||
       ((*(int *)(param_1 + 0x78ec) != 0 && (*(int *)(param_1 + 0x78f0) == 0)))) {
      *(undefined4 *)(puVar20 + 8) = *(undefined4 *)(puVar20 + 10);
      *(undefined4 *)(puVar20 + 9) = *(undefined4 *)(puVar20 + 0xb);
    }
    if (((uVar27 != 0) && (*(int *)(puVar20 + 0x14) != 0)) &&
       ((iVar19 = FUN_14039e0e0(param_1), iVar19 == 0 ||
        (iVar19 = FUN_14039e210(param_1), iVar19 != 0)))) {
      puVar20[0xc] = 0;
      puVar20[0xd] = 0;
      *(undefined4 *)(puVar20 + 0x16) = 1;
      if (*(int *)((longlong)puVar20 + 0xa4) == 0) {
        fVar84 = *(float *)((longlong)puVar20 + 0x44);
        fVar44 = fVar84 * fVar44;
        if (fVar44 <= 0.0) {
          fVar44 = 0.0;
        }
        fVar44 = fVar44 + *(float *)((longlong)puVar20 + 0x74);
        if (fVar44 <= fVar84) {
          fVar44 = fVar84;
        }
        *(float *)((longlong)puVar20 + 0x44) = fVar44;
      }
      else {
        fVar84 = *(float *)((longlong)puVar20 + 0x44);
        fVar44 = fVar84 * fVar44;
        if (fVar84 <= fVar44) {
          fVar44 = fVar84;
        }
        fVar44 = fVar44 + *(float *)((longlong)puVar20 + 0x74);
        if (fVar44 <= fVar84) {
          fVar44 = fVar84;
        }
        *(float *)((longlong)puVar20 + 0x44) = fVar44;
      }
    }
    auVar6._12_4_ = 0;
    auVar6._0_12_ = local_3b8._4_12_;
    local_3b8 = auVar6 << 0x20;
    local_468 = (float **)0x0;
    local_3e8 = (longlong *)
                CONCAT44(*(float *)((longlong)puVar20 + 0x24) +
                         *(float *)(*(longlong *)(param_1 + 0x6490) + 0x12c4) *
                         *(float *)(*(longlong *)(param_1 + 0x6490) + 0x570),
                         *(float *)(puVar20 + 4) + 0.0);
    uStack_3e0 = CONCAT44(*(float *)((longlong)puVar20 + 0x2c) + 0.0,*(float *)(puVar20 + 5) + 0.0);
    (**(code **)(**(longlong **)(param_1 + 0x7248) + 0x1b8))
              (*(longlong **)(param_1 + 0x7248),&local_3e8,local_388);
    fVar84 = local_2f8;
    fVar44 = DAT_140b79fa0;
    iVar19 = *(int *)(*(longlong *)(param_1 + 0x6490) + 0x1088);
    fVar83 = *(float *)((longlong)puVar20 + 0x24) + fVar83;
    fVar81 = fVar78;
    if (iVar19 != 3) {
      fVar81 = (float)((uint)fVar63 ^ DAT_140b7b530);
    }
    fVar82 = 0.0;
    fVar80 = 0.0;
    if (iVar19 == 1) {
      if ((local_2f8 < fVar67 * DAT_140b79fa0 + *(float *)((longlong)puVar20 + 0x24)) &&
         (*(float *)((longlong)puVar20 + 0x54) <= 0.0 && *(float *)((longlong)puVar20 + 0x54) != 0.0
         )) {
        fVar53 = *(float *)(puVar20 + 10);
        fVar55 = *(float *)((longlong)puVar20 + 0x54);
        fVar77 = *(float *)(puVar20 + 0xb);
        fVar52 = *(float *)((longlong)puVar20 + 0x5c);
        fVar65 = fVar55 * fVar55;
        auVar69._4_4_ = fVar65;
        auVar69._0_4_ = fVar53 * fVar53;
        auVar69._8_4_ = fVar77 * fVar77;
        auVar69._12_4_ = fVar52 * fVar52;
        auVar51._4_4_ = fVar65;
        auVar51._0_4_ = fVar65;
        auVar51._8_4_ = fVar65;
        auVar51._12_4_ = fVar65;
        auVar70._4_12_ = auVar69._4_12_;
        auVar70._0_4_ = fVar53 * fVar53 + fVar65 + fVar77 * fVar77;
        _local_3c8 = ZEXT416((uint)DAT_140b79e48);
        auVar79 = rsqrtss(auVar51,auVar70);
        fVar54 = auVar79._0_4_;
        fVar54 = (DAT_140b79fa0 - auVar70._0_4_ * fVar54 * fVar54) * DAT_140b79e48 * fVar54;
        if (fVar54 <= 0.0) {
          fVar54 = fVar75;
        }
        local_3f8._4_4_ = fVar54 * fVar55;
        local_3f8._0_4_ = fVar54 * fVar53;
        uStack_3f0._0_4_ = fVar54 * fVar77;
        uStack_3f0._4_4_ = fVar54 * fVar52;
        uVar27 = FUN_1408fc950();
        auVar79 = _local_3f8;
        fVar67 = local_440;
        fVar52 = local_454;
        fVar65 = local_458;
        if ((float)(uVar27 ^ DAT_140b7b530) < fVar54 * fVar55) {
          local_3f8._4_4_ = 0;
          auVar85 = _local_3f8;
          uStack_3f0._0_4_ = auVar79._8_4_;
          uStack_3f0._4_4_ = auVar79._12_4_;
          auVar12._4_4_ = uStack_3f0._4_4_ * uStack_3f0._4_4_;
          auVar12._0_4_ = (float)uStack_3f0 * (float)uStack_3f0;
          auVar12._8_8_ = 0;
          auVar71._4_12_ = SUB1612(auVar12 << 0x40,4);
          auVar71._0_4_ =
               (float)local_3f8._0_4_ * (float)local_3f8._0_4_ + 0.0 +
               (float)uStack_3f0 * (float)uStack_3f0;
          fVar77 = SQRT(fVar53 * fVar53 + fVar55 * fVar55 + fVar77 * fVar77);
          auVar79 = rsqrtss(ZEXT816(0),auVar71);
          fVar55 = fVar77 * _DAT_140b79ec4;
          fVar77 = fVar77 * DAT_140b79da4;
          fVar53 = auVar79._0_4_;
          fVar53 = (fVar44 - auVar71._0_4_ * fVar53 * fVar53) * (float)local_3c8._0_4_ * fVar53;
          if (fVar53 <= 0.0) {
            fVar53 = fVar75;
          }
          *(float *)(puVar20 + 10) = fVar55 * fVar53 * (float)local_3f8._0_4_;
          *(float *)((longlong)puVar20 + 0x54) = fVar55 * fVar53 * 0.0;
          *(float *)(puVar20 + 0xb) = fVar55 * fVar53 * (float)uStack_3f0;
          *(float *)((longlong)puVar20 + 0x5c) = fVar55 * fVar53 * uStack_3f0._4_4_;
          *(float *)((longlong)puVar20 + 0x54) = fVar77;
          _local_3f8 = auVar85;
        }
      }
      fVar44 = DAT_140c44798;
      if (((*(int *)(param_1 + 0x75d8) == 0) && (0.0 < *(float *)((longlong)puVar20 + 0x54))) &&
         (fVar84 < fVar83 + *(float *)((longlong)puVar20 + 0x54))) {
        fVar53 = *(float *)(puVar20 + 10);
        fVar55 = *(float *)((longlong)puVar20 + 0x54);
        fVar77 = *(float *)(puVar20 + 0xb);
        fVar64 = fVar53 * fVar53 + fVar77 * fVar77;
        fVar54 = fVar84 - fVar83;
        if (fVar54 <= 0.0) {
          fVar54 = 0.0;
        }
        *(float *)((longlong)puVar20 + 0x54) = fVar54;
        if (fVar44 < fVar64) {
          fVar44 = SQRT(((fVar53 * fVar53 + fVar55 * fVar55 + fVar77 * fVar77) - fVar54 * fVar54) /
                        fVar64);
          *(float *)(puVar20 + 0xb) = fVar44 * *(float *)(puVar20 + 0xb);
          *(float *)(puVar20 + 10) = fVar44 * *(float *)(puVar20 + 10);
        }
      }
      fVar44 = DAT_140b79f58;
      if (((fVar84 < fVar67 * DAT_140b79f58 + *(float *)((longlong)puVar20 + 0x24)) &&
          (0.0 < *(float *)((longlong)puVar20 + 0x44) || *(float *)((longlong)puVar20 + 0x44) == 0.0
          )) && (local_44c = *(uint *)(param_1 + 0x75d8), local_44c != 0)) {
        _local_3f8 = ZEXT812(0);
        if (DAT_140b79cc4 < fVar65) {
          auVar10._4_8_ = 0;
          auVar10._0_4_ = (fVar52 * DAT_140b79fe8) / fVar65;
          _local_3f8 = auVar10 << 0x20;
        }
        uStack_3f0._4_4_ = 0.0;
        lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x6490) + 0xf00);
        fVar52 = fVar46;
        if (lVar23 != 0) {
          fVar52 = fVar46 / *(float *)(lVar23 + 0x12c4);
        }
        fVar74 = local_3f8._4_4_;
        fVar76 = local_3f8._8_4_;
        fVar65 = local_418[1];
        fVar67 = local_418[2];
        fVar53 = local_418[3];
        fVar55 = local_418[5];
        fVar77 = local_418[6];
        fVar54 = local_418[7];
        fVar64 = local_418[9];
        fVar66 = local_418[10];
        fVar4 = local_418[0xb];
        *(float *)(puVar20 + 8) =
             *(float *)(puVar20 + 8) +
             (fVar74 * local_418[4] + *local_418 * 0.0 + fVar76 * local_418[8]) * fVar52;
        *(float *)((longlong)puVar20 + 0x44) =
             *(float *)((longlong)puVar20 + 0x44) +
             (fVar74 * fVar55 + fVar65 * 0.0 + fVar76 * fVar64) * fVar52;
        *(float *)(puVar20 + 9) =
             *(float *)(puVar20 + 9) + (fVar74 * fVar77 + fVar67 * 0.0 + fVar76 * fVar66) * fVar52;
        *(float *)((longlong)puVar20 + 0x4c) =
             *(float *)((longlong)puVar20 + 0x4c) +
             (fVar74 * fVar54 + fVar53 * 0.0 + fVar76 * fVar4) * fVar52;
        puVar20[0x10] = 0;
        *(undefined4 *)(puVar20 + 0x11) = 1;
        *(undefined4 *)((longlong)puVar20 + 0x94) = 1;
        *(undefined4 *)(puVar20 + 0x14) = 1;
        *(undefined4 *)(puVar20 + 0x16) = 0;
        *(undefined4 *)(param_1 + 0x75d8) = 0;
      }
      if ((*(int *)(puVar20 + 0x14) == 0) ||
         (*(float *)((longlong)puVar20 + 0x44) <= 0.0 && *(float *)((longlong)puVar20 + 0x44) != 0.0
         )) {
        fVar52 = fVar46 - (local_348 * _DAT_140c77870 + fStack_344 * fRam0000000140c77874 +
                          fStack_340 * fRam0000000140c77878);
        if ((fVar52 < DAT_140b79da4) ||
           (local_308 * local_308 + fStack_304 * fStack_304 + fStack_300 * fStack_300 < fVar46)) {
          fVar44 = 0.0;
        }
        else {
          fVar52 = fVar52 * fVar44;
          if (fVar46 <= fVar52) {
            fVar52 = fVar46;
          }
          fVar44 = fVar75;
          if (0.0 <= fVar52) {
            fVar44 = fVar52;
          }
          fVar52 = fVar63 / (fVar44 * DAT_140b7a034);
          if (fVar52 < *(float *)((longlong)puVar20 + 0x54)) {
            *(float *)((longlong)puVar20 + 0x54) = fVar52;
          }
        }
        if ((fVar83 < fVar84) && (fVar84 - fVar46 < fVar83)) {
          fVar43 = *(float *)((longlong)puVar20 + 0x44);
          fVar78 = DAT_140b79e48;
          if (fVar43 < 0.0) {
            fVar78 = fVar43 * 0.0 * fVar43 + DAT_140b79e48;
          }
          if (DAT_140b79ff8 <= fVar78) {
            fVar78 = DAT_140b79ff8;
          }
          fVar65 = fVar46 - fVar44;
          fVar52 = 0.0;
          if (0.0 <= fVar78) {
            fVar52 = fVar78;
          }
          fVar78 = fVar84 - fVar83;
          if (fVar46 <= fVar84 - fVar83) {
            fVar78 = fVar46;
          }
          fVar43 = fVar75;
          if (0.0 <= fVar78) {
            fVar43 = fVar78;
          }
          local_3b8 = ZEXT416((uint)(fVar43 * DAT_140b7a01c));
          fVar75 = fVar65 * 0.0 * fVar52 * fVar43;
          fVar78 = fVar65 * (0.0 - fVar81) * fVar52 * fVar43;
          fVar43 = fVar65 * 0.0 * fVar52 * fVar43;
        }
        if (fVar83 <= fVar84) {
          auVar68 = ZEXT812(0);
        }
        else {
          fVar52 = (fVar83 - fVar84) / local_420;
          if (fVar46 <= fVar52) {
            fVar52 = fVar46;
          }
          fVar65 = 0.0;
          if (0.0 <= fVar52) {
            fVar65 = fVar52;
          }
          fVar65 = fVar65 * (fVar46 - fVar44);
          auVar68._0_4_ = fVar65 * 0.0;
          auVar68._4_4_ = fVar65 * fVar81;
          auVar68._8_4_ = fVar65 * 0.0;
        }
        fVar80 = fVar75 + fVar44 * 0.0 + auVar68._0_4_;
        fVar81 = fVar78 + fVar44 * fVar81 + auVar68._4_4_;
        fVar82 = fVar43 + fVar44 * 0.0 + auVar68._8_4_;
      }
    }
    if (*(int *)(puVar20 + 0x10) == 0) {
      fVar43 = 0.0;
      fVar75 = 0.0;
      fVar78 = 0.0;
      if ((*(int *)((longlong)puVar20 + 0x84) == 0) &&
         ((*(longlong *)(param_1 + 0x78) == 0 ||
          (iVar19 = FUN_14047bf00(), fVar84 = local_2f8, iVar19 == 0)))) {
        ppuVar28 = &PTR_PTR_140c44860;
      }
      else {
        ppuVar28 = &PTR_PTR_140c44920;
      }
      iVar19 = *(int *)(ppuVar28 + 2);
      if (*DAT_140c63750 < *(int *)(ppuVar28 + 2)) {
        iVar19 = *DAT_140c63750;
      }
      fVar44 = *(float *)((longlong)ppuVar28 + (longlong)iVar19 * 4 + 0x20);
      if ((((local_368 < fVar84) &&
           (*(float *)((longlong)puVar20 + 0x24) <= fVar84 &&
            fVar84 != *(float *)((longlong)puVar20 + 0x24))) &&
          ((*(longlong *)(param_1 + 0x78) == 0 ||
           (iVar19 = FUN_14047bf60(), fVar84 = local_2f8, iVar19 == 0)))) &&
         ((local_44c == 0 || (local_458 <= DAT_140b79cc4)))) {
        iVar19 = DAT_140c448d0;
        if (*DAT_140c63750 < DAT_140c448d0) {
          iVar19 = *DAT_140c63750;
        }
        fVar43 = (fVar84 - *(float *)((longlong)puVar20 + 0x24)) / local_420;
        if (fVar46 <= fVar43) {
          fVar43 = fVar46;
        }
        fVar52 = 0.0;
        if (0.0 <= fVar43) {
          fVar52 = fVar43;
        }
        fVar43 = (local_308 - 0.0) * fVar52 + 0.0;
        fVar75 = (fStack_304 - 0.0) * fVar52 + 0.0;
        fVar78 = (fStack_300 - 0.0) * fVar52 + 0.0;
        fVar44 = fVar44 + (*(float *)(&DAT_140c448e0 + (longlong)iVar19 * 4) - fVar44) * fVar52;
        fVar80 = (0.0 - fVar80) * fVar52 + fVar80;
        fVar81 = (0.0 - fVar81) * fVar52 + fVar81;
        fVar82 = (0.0 - fVar82) * fVar52 + fVar82;
      }
    }
    else {
      iVar19 = DAT_140c448d0;
      if (*DAT_140c63750 < DAT_140c448d0) {
        iVar19 = *DAT_140c63750;
      }
      fVar44 = *(float *)(&DAT_140c448e0 + (longlong)iVar19 * 4);
      fVar43 = local_308;
      fVar75 = fStack_304;
      fVar78 = fStack_300;
    }
    piVar32 = DAT_140c63750;
    iVar19 = DAT_140c44ca0;
    if (*DAT_140c63750 < DAT_140c44ca0) {
      iVar19 = *DAT_140c63750;
    }
    fVar52 = *(float *)(&DAT_140c44cb0 + (longlong)iVar19 * 4);
    fVar43 = fVar52 * fVar43;
    fVar75 = fVar52 * fVar75;
    fVar52 = fVar52 * fVar78;
    if ((float)(*(uint *)((longlong)puVar20 + 0x54) & DAT_140b7b500) < DAT_140b79df8) {
      *(undefined4 *)((longlong)puVar20 + 0x54) = 0;
    }
    lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x6490) + 0xf00);
    fVar78 = fVar46;
    if (lVar23 != 0) {
      fVar78 = fVar46 / *(float *)(lVar23 + 0x12c4);
    }
    fVar65 = local_418[5];
    fVar67 = local_418[6];
    fVar83 = local_418[7];
    fVar53 = local_418[1];
    fVar55 = local_418[2];
    fVar77 = local_418[3];
    fVar54 = local_418[9];
    fVar64 = local_418[10];
    fVar66 = local_418[0xb];
    *pfVar21 = (fVar75 * local_418[4] + fVar43 * *local_418 + fVar52 * local_418[8]) * fVar78;
    pfVar21[1] = (fVar75 * fVar65 + fVar43 * fVar53 + fVar52 * fVar54) * fVar78;
    pfVar21[2] = (fVar75 * fVar67 + fVar43 * fVar55 + fVar52 * fVar64) * fVar78;
    pfVar21[3] = (fVar75 * fVar83 + fVar43 * fVar77 + fVar52 * fVar66) * fVar78;
    lVar23 = *(longlong *)(*(longlong *)(param_1 + 0x6490) + 0xf00);
    fVar43 = fVar46;
    if (lVar23 != 0) {
      fVar43 = fVar46 / *(float *)(lVar23 + 0x12c4);
    }
    fVar75 = local_418[1];
    fVar78 = local_418[2];
    fVar52 = local_418[3];
    fVar65 = local_418[5];
    fVar67 = local_418[6];
    fVar83 = local_418[7];
    fVar53 = local_418[9];
    fVar55 = local_418[10];
    fVar77 = local_418[0xb];
    fVar54 = DAT_140c3b438 * DAT_140b79d28;
    pfVar21[4] = (fVar81 * local_418[4] + fVar80 * *local_418 + fVar82 * local_418[8]) * fVar43;
    pfVar21[5] = (fVar81 * fVar65 + fVar80 * fVar75 + fVar82 * fVar53) * fVar43;
    pfVar21[6] = (fVar81 * fVar67 + fVar80 * fVar78 + fVar82 * fVar55) * fVar43;
    pfVar21[7] = (fVar81 * fVar83 + fVar80 * fVar52 + fVar82 * fVar77) * fVar43;
    iVar19 = DAT_140c44750;
    if (*piVar32 < DAT_140c44750) {
      iVar19 = *piVar32;
    }
    fVar43 = (float)FUN_1408fd8a4(fVar54 * *(float *)(&DAT_140c44760 + (longlong)iVar19 * 4));
    fVar75 = fVar43 * (float)local_138 * local_448;
    pfVar21[0xc] = fVar75;
    fVar43 = (float)FUN_1408fd8a4();
    pfVar21[0xe] = fVar44 + (float)local_3b8._0_4_;
    fVar43 = fVar43 * (float)local_138 * local_448;
    if (fVar75 <= fVar43) {
      fVar43 = fVar75;
    }
    pfVar21[0xd] = fVar43;
    fVar43 = *(float *)(*(longlong *)(param_1 + 0x6490) + 0xb64);
    pfVar21[0x13] = fVar84;
    pfVar21[0xf] = (fVar44 + (float)local_3b8._0_4_) / fVar43;
    if ((*(longlong *)(param_1 + 0x78) != 0) &&
       (iVar19 = FUN_14047bf00(), piVar32 = DAT_140c63750, iVar19 != 0)) {
      fVar43 = pfVar21[0xf];
      fVar75 = *(float *)((longlong)puVar20 + 0x54);
      fVar78 = *(float *)(puVar20 + 0xb);
      fVar44 = *(float *)((longlong)puVar20 + 0x5c);
      pfVar21[4] = pfVar21[4] + *(float *)(puVar20 + 10) * fVar43;
      pfVar21[5] = pfVar21[5] + fVar75 * fVar43;
      pfVar21[6] = pfVar21[6] + fVar78 * fVar43;
      pfVar21[7] = pfVar21[7] + fVar44 * fVar43;
    }
    fVar43 = local_454;
    iVar19 = *piVar32;
    iVar16 = DAT_140c44990;
    if (iVar19 < DAT_140c44990) {
      iVar16 = iVar19;
    }
    fVar75 = *(float *)(&DAT_140c449a0 + (longlong)iVar16 * 4);
    iVar16 = DAT_140c44a20;
    if (iVar19 < DAT_140c44a20) {
      iVar16 = iVar19;
    }
    auVar79 = ZEXT416((uint)(local_454 * fVar75 * fVar63 * DAT_140b79f58));
    fVar78 = *(float *)(&DAT_140c44a30 + (longlong)iVar16 * 4);
    auVar79 = sqrtps(auVar79,auVar79);
    pfVar21[0x10] = auVar79._0_4_;
    auVar79 = sqrtps(auVar79,ZEXT416((uint)((local_454 * fVar75 + fVar78) * fVar63 * DAT_140b79f58))
                    );
    pfVar21[0x11] = auVar79._0_4_;
    lVar23 = *(longlong *)(param_1 + 0x6490);
    fVar78 = (float)FUN_1405b45e0(lVar23,*(undefined4 *)(lVar23 + 0x1088),
                                  *(undefined4 *)(lVar23 + 0x1320));
    fVar75 = pfVar21[0x10];
    if (fVar75 < fVar78) {
      pfVar21[0x10] = fVar78;
      pfVar21[0x11] = (fVar78 - fVar75) + pfVar21[0x11];
    }
    if (((*(int *)(param_1 + 0x78d8) != 0) &&
        (fVar75 = pfVar21[0x10], fVar78 = DAT_140dc21f4, fVar75 < DAT_140dc21f4)) ||
       ((*(int *)(param_1 + 0x78ec) != 0 &&
        (fVar75 = pfVar21[0x10], fVar78 = DAT_140dc21f8, fVar75 < DAT_140dc21f8)))) {
      pfVar21[0x10] = fVar78;
      pfVar21[0x11] = (fVar78 - fVar75) + pfVar21[0x11];
    }
    if ((*(longlong *)(param_1 + 0x78) == 0) || (iVar19 = FUN_14047bf60(), iVar19 == 0)) {
      fVar75 = 0.0;
    }
    else {
      fVar75 = 1.4013e-45;
    }
    pfVar21[0x14] = fVar75;
    pfVar21[0x16] = 0.0;
    lVar23 = *(longlong *)(param_1 + 0x6490);
    if (*(int *)(lVar23 + 0x80) == 0x17) {
      lVar23 = *(longlong *)(param_1 + 0x78);
      fVar75 = DAT_140dc2208;
      if ((DAT_140dc21e0 >> 9 & 1) == 0) {
        DAT_140dc21e0 = DAT_140dc21e0 | 0x200;
        lVar33 = FUN_140200220(0x23a);
        if (lVar33 == 0) {
          DAT_140dc2208 = DAT_140b7a060;
          fVar75 = DAT_140b7a060;
        }
        else {
          DAT_140dc2208 = *(float *)(lVar33 + 0x18);
          fVar75 = DAT_140dc2208;
        }
      }
LAB_1403a5611:
      if (lVar23 == 0) {
        puVar20[10] = 0;
        puVar20[0xb] = 0;
        *(undefined4 *)(puVar20 + 9) = 0;
        *(undefined4 *)(puVar20 + 8) = 0;
        if (0.0 < *(float *)((longlong)puVar20 + 0x44)) {
          *(undefined4 *)((longlong)puVar20 + 0x44) = 0;
        }
      }
      else {
        pfVar21[0x16] = 1.4013e-45;
        uVar47 = *(undefined8 *)(lVar23 + 0x11e8);
        *(undefined8 *)(pfVar21 + 8) = *(undefined8 *)(lVar23 + 0x11e0);
        *(undefined8 *)(pfVar21 + 10) = uVar47;
        pfVar21[0x12] = fVar75;
      }
    }
    else if (*(float *)(lVar23 + 0x508) != 0.0) {
      lVar23 = FUN_1403d90d0(param_1,*(undefined4 *)(lVar23 + 0x50c));
      fVar75 = *(float *)(*(longlong *)(param_1 + 0x6490) + 0x508);
      goto LAB_1403a5611;
    }
    uVar26 = 0;
    if (local_3d4 != 0) {
      *(undefined4 *)(puVar20 + 0xb) = 0;
      *(undefined4 *)(puVar20 + 10) = 0;
      *(undefined4 *)(puVar20 + 9) = 0;
      *(undefined4 *)(puVar20 + 8) = 0;
      *(undefined4 *)((longlong)puVar20 + 0x94) = 0;
      *(undefined4 *)(puVar20 + 0x14) = 0;
      *(undefined4 *)(puVar20 + 0x16) = 0;
    }
    iVar19 = FUN_14045e680(*(undefined8 *)(param_1 + 0x6490));
    lVar23 = DAT_140c65b70;
    fVar75 = DAT_140b79d3c;
    if ((iVar19 == 0) && (*(longlong *)(DAT_140c65b70 + 0x808) != 0)) {
      uVar38 = uVar26 & 0xffffffff;
      do {
        plVar24 = *(longlong **)(*(longlong *)(lVar23 + 0x800) + uVar26 * 8);
        iVar19 = (**(code **)(*plVar24 + 0x38))(plVar24);
        if (iVar19 == 0x8e) {
          if ((int)plVar24[0x2b] == 0) {
            uVar17 = *(undefined4 *)(plVar24[10] + 0x154);
          }
          else {
            uVar17 = 0;
            if ((int)plVar24[0x2b] == 1) {
              uVar17 = *(undefined4 *)(plVar24[10] + 0x158);
            }
          }
          lVar33 = FUN_1403d90d0(param_1,uVar17);
          if (lVar33 != 0) {
            fVar78 = *(float *)((longlong)plVar24 + 0x154);
            if ((int)plVar24[0x2a] == 0) {
              lVar1 = *(longlong *)(param_1 + 0x6490);
              local_3f8._0_4_ = *(float *)(lVar33 + 0x11e0) - *(float *)(lVar1 + 0x11e0);
              fVar44 = *(float *)(lVar33 + 0x11e8) - *(float *)(lVar1 + 0x11e8);
              fVar84 = *(float *)(lVar33 + 0x11ec) - *(float *)(lVar1 + 0x11ec);
              local_3f8._4_4_ = *(float *)(lVar33 + 0x11e4) - *(float *)(lVar1 + 0x11e4);
              uStack_3f0._0_4_ = fVar44;
              uStack_3f0._4_4_ = fVar84;
              local_3f8._4_4_ = 0;
              fVar63 = (float)local_3f8._0_4_ * (float)local_3f8._0_4_ + 0.0 + fVar44 * fVar44;
              if (fVar78 <= 0.0) {
                if (fVar78 < 0.0) {
                  if (fVar63 < DAT_140b79cc4) {
                    fVar44 = *(float *)(lVar1 + 0x1140);
                    fVar84 = *(float *)(lVar1 + 0x1144);
                    fVar63 = *(float *)(lVar1 + 0x1148);
                    fVar52 = *(float *)(lVar1 + 0x114c);
                    goto LAB_1403a5833;
                  }
                  auVar62._0_4_ = (float)local_3f8._0_4_ * (float)local_3f8._0_4_;
                  auVar62._4_4_ = 0;
                  auVar62._8_4_ = fVar44 * fVar44;
                  auVar62._12_4_ = fVar84 * fVar84;
                  goto LAB_1403a57f9;
                }
              }
              else if (fVar75 < fVar63) {
                auVar62._0_4_ = (float)local_3f8._0_4_ * (float)local_3f8._0_4_;
                auVar62._4_4_ = 0;
                auVar62._8_4_ = fVar44 * fVar44;
                auVar62._12_4_ = fVar84 * fVar84;
                if (fVar63 < fVar46) {
                  fVar52 = auVar62._0_4_ + 0.0 + auVar62._8_4_;
                  auVar13._4_4_ = fVar84 * fVar84;
                  auVar13._0_4_ = fVar44 * fVar44;
                  auVar13._8_8_ = 0;
                  auVar72._4_12_ = SUB1612(auVar13 << 0x40,4);
                  auVar72._0_4_ =
                       (float)local_3f8._0_4_ * (float)local_3f8._0_4_ + 0.0 + fVar44 * fVar44;
                  auVar79 = rsqrtss(auVar72,auVar72);
                  fVar63 = auVar79._0_4_;
                  fVar65 = *(float *)(puVar20 + 10) +
                           fVar63 * (float)local_3f8._0_4_ * fVar78 * fVar52;
                  fVar81 = *(float *)((longlong)puVar20 + 0x54) + fVar63 * 0.0 * fVar78 * fVar52;
                  fVar44 = *(float *)(puVar20 + 0xb) + fVar63 * fVar44 * fVar78 * fVar52;
                  fVar78 = *(float *)((longlong)puVar20 + 0x5c) + fVar63 * fVar84 * fVar78 * fVar52;
                  goto LAB_1403a5845;
                }
LAB_1403a57f9:
                auVar73._0_4_ = auVar62._0_4_ + 0.0 + auVar62._8_4_;
                auVar73._4_12_ = auVar62._4_12_;
                auVar79 = rsqrtss(auVar73,auVar73);
                fVar63 = auVar79._0_4_;
                fVar65 = *(float *)(puVar20 + 10) + fVar63 * (float)local_3f8._0_4_ * fVar78;
                fVar81 = *(float *)((longlong)puVar20 + 0x54) + fVar63 * 0.0 * fVar78;
                fVar44 = *(float *)(puVar20 + 0xb) + fVar63 * fVar44 * fVar78;
                fVar78 = *(float *)((longlong)puVar20 + 0x5c) + fVar63 * fVar84 * fVar78;
                goto LAB_1403a5845;
              }
            }
            else if ((int)plVar24[0x2a] == 1) {
              fVar44 = *(float *)(lVar33 + 0x1140);
              fVar84 = *(float *)(lVar33 + 0x1144);
              fVar63 = *(float *)(lVar33 + 0x1148);
              fVar52 = *(float *)(lVar33 + 0x114c);
LAB_1403a5833:
              fVar65 = *(float *)(puVar20 + 10) + fVar44 * fVar78;
              fVar81 = *(float *)((longlong)puVar20 + 0x54) + fVar84 * fVar78;
              fVar44 = *(float *)(puVar20 + 0xb) + fVar63 * fVar78;
              fVar78 = *(float *)((longlong)puVar20 + 0x5c) + fVar52 * fVar78;
LAB_1403a5845:
              *(float *)(puVar20 + 10) = fVar65;
              *(float *)((longlong)puVar20 + 0x54) = fVar81;
              *(float *)(puVar20 + 0xb) = fVar44;
              *(float *)((longlong)puVar20 + 0x5c) = fVar78;
            }
          }
        }
        uVar26 = (ulonglong)((int)uVar38 + 1);
        uVar38 = uVar26;
        uVar39 = local_438;
      } while (uVar26 < *(ulonglong *)(lVar23 + 0x808));
    }
    (**(code **)(**(longlong **)(param_1 + 0x6fc0) + 0x28))();
    fVar84 = DAT_140b79e48;
    fVar83 = local_420;
    fVar65 = local_458;
  }
  else {
    *(float *)(puVar20 + 10) = *(float *)(puVar20 + 0xc) + *(float *)(puVar20 + 10);
    *(float *)((longlong)puVar20 + 0x54) =
         *(float *)((longlong)puVar20 + 100) + *(float *)((longlong)puVar20 + 0x54);
    *(float *)(puVar20 + 0xb) = *(float *)(puVar20 + 0xd) + *(float *)(puVar20 + 0xb);
    *(float *)((longlong)puVar20 + 0x5c) =
         *(float *)((longlong)puVar20 + 0x6c) + *(float *)((longlong)puVar20 + 0x5c);
    lVar23 = *(longlong *)(param_1 + 0x6490);
    fVar43 = *(float *)(lVar23 + 0xff0);
    fVar75 = *(float *)(lVar23 + 0xff4);
    fVar78 = *(float *)(lVar23 + 0xff8);
    fVar44 = local_418[4];
    fVar63 = local_418[5];
    fVar52 = local_418[6];
    fVar67 = local_418[7];
    fVar80 = local_418[8];
    fVar82 = local_418[9];
    fVar53 = local_418[10];
    fVar55 = local_418[0xb];
    fVar77 = *local_418;
    fVar54 = local_418[1];
    fVar64 = local_418[2];
    fVar66 = local_418[3];
    fVar4 = *(float *)(puVar20 + 10);
    fVar74 = *(float *)((longlong)puVar20 + 0x54);
    fVar76 = *(float *)(puVar20 + 0xb);
    fVar5 = *(float *)((longlong)puVar20 + 0x5c);
    fVar45 = (float)FUN_1408fbfc0(local_418,local_3d8 * DAT_140b7a034);
    fVar44 = fVar45 * ((fVar75 * fVar44 + fVar43 * fVar77 + fVar78 * fVar80) - fVar4) +
             *(float *)(puVar20 + 10);
    fVar63 = fVar45 * ((fVar75 * fVar63 + fVar43 * fVar54 + fVar78 * fVar82) - fVar74) +
             *(float *)((longlong)puVar20 + 0x54);
    fVar52 = fVar45 * ((fVar75 * fVar52 + fVar43 * fVar64 + fVar78 * fVar53) - fVar76) +
             *(float *)(puVar20 + 0xb);
    *(float *)(puVar20 + 8) = fVar44;
    *(float *)((longlong)puVar20 + 0x44) = fVar63;
    *(float *)(puVar20 + 9) = fVar52;
    *(float *)((longlong)puVar20 + 0x4c) =
         fVar45 * ((fVar75 * fVar67 + fVar43 * fVar66 + fVar78 * fVar55) - fVar5) +
         *(float *)((longlong)puVar20 + 0x5c);
    lVar23 = *(longlong *)(param_1 + 0x6490);
    fVar54 = *(float *)(lVar23 + 0xf70) +
             (fVar63 * *(float *)(local_3b8._0_8_ + 0x10) + fVar44 * *(float *)local_3b8._0_8_ +
             fVar52 * *(float *)(local_3b8._0_8_ + 0x20)) * fVar81;
    fVar64 = *(float *)(lVar23 + 0xf74) +
             (fVar63 * *(float *)(local_3b8._0_8_ + 0x14) + fVar44 * *(float *)(local_3b8._0_8_ + 4)
             + fVar52 * *(float *)(local_3b8._0_8_ + 0x24)) * fVar81;
    fVar66 = *(float *)(lVar23 + 0xf78) +
             (fVar63 * *(float *)(local_3b8._0_8_ + 0x18) + fVar44 * *(float *)(local_3b8._0_8_ + 8)
             + fVar52 * *(float *)(local_3b8._0_8_ + 0x28)) * fVar81;
    fVar43 = local_418[5];
    fVar75 = local_418[6];
    fVar78 = local_418[7];
    fVar44 = local_418[1];
    fVar63 = local_418[2];
    fVar52 = local_418[3];
    fVar67 = local_418[9];
    fVar80 = local_418[10];
    fVar82 = local_418[0xb];
    fVar53 = local_418[0xd];
    fVar55 = local_418[0xe];
    fVar77 = local_418[0xf];
    *(float *)(puVar20 + 4) =
         fVar64 * local_418[4] + fVar54 * *local_418 + fVar66 * local_418[8] + local_418[0xc];
    *(float *)((longlong)puVar20 + 0x24) =
         fVar64 * fVar43 + fVar54 * fVar44 + fVar66 * fVar67 + fVar53;
    *(float *)(puVar20 + 5) = fVar64 * fVar75 + fVar54 * fVar63 + fVar66 * fVar80 + fVar55;
    *(float *)((longlong)puVar20 + 0x2c) =
         fVar64 * fVar78 + fVar54 * fVar52 + fVar66 * fVar82 + fVar77;
    if (*(int *)(param_1 + 0x70a4) != 2) {
      lVar23 = *(longlong *)(param_1 + 0x6490);
      plVar24 = (longlong *)(**(code **)(**(longlong **)(param_1 + 0x7248) + 0x10))();
      auStack_134 = (undefined1  [4])*(undefined4 *)(lVar23 + 0x11e8);
      local_138 = (undefined1  [4])*(undefined4 *)(lVar23 + 0x11e0);
      uStack_130._0_4_ = (float)*(undefined4 *)(lVar23 + 0x11e0);
      uStack_130._4_4_ = (float)*(undefined4 *)(lVar23 + 0x11e8);
      iVar19 = (**(code **)(*plVar24 + 0xe0))(plVar24,local_138,local_388,3);
      if (iVar19 == 0) {
        fStack_344 = DAT_140c7ad44;
        local_348 = 0.0;
      }
      plVar24 = (longlong *)(**(code **)(**(longlong **)(param_1 + 0x7248) + 0x10))();
      auStack_134 = (undefined1  [4])*(undefined4 *)(puVar20 + 5);
      local_138 = (undefined1  [4])*(undefined4 *)(puVar20 + 4);
      uStack_130._0_4_ = (float)*(undefined4 *)(puVar20 + 4);
      uStack_130._4_4_ = (float)*(undefined4 *)(puVar20 + 5);
      iVar19 = (**(code **)(*plVar24 + 0xe0))(plVar24,local_138,local_1c8,3);
      if (iVar19 == 0) {
        local_184 = DAT_140c7ad44;
        local_188 = 0;
      }
      if ((((fStack_344 < *(float *)(lVar23 + 0x11e4) || fStack_344 == *(float *)(lVar23 + 0x11e4))
           && (*(float *)((longlong)puVar20 + 0x24) <= local_184 &&
               local_184 != *(float *)((longlong)puVar20 + 0x24))) && (local_348 == 0.0)) &&
         (local_188 == 0)) {
        *(float *)((longlong)puVar20 + 0x24) = local_184;
      }
    }
    *puVar20 = local_3c8;
    puVar20[1] = uStack_3c0;
    puVar20[2] = local_3f8;
    puVar20[3] = uStack_3f0;
    puVar20[6] = 0;
    puVar20[7] = 0;
    puVar20[10] = puVar20[8];
    puVar20[0xb] = puVar20[9];
    puVar20[0xc] = 0;
    puVar20[0xd] = 0;
    puVar20[0xe] = 0;
    puVar20[0xf] = 0;
    *(undefined4 *)(puVar20 + 0x10) = 1;
    *(undefined4 *)((longlong)puVar20 + 0x84) = 1;
    *(undefined4 *)(puVar20 + 0x11) = 1;
    puVar20[0x12] = 0;
    puVar20[0x13] = 0;
    *(float *)((longlong)puVar20 + 0x8c) = fVar81 + *(float *)((longlong)puVar20 + 0x8c);
    puVar20[0x14] = 0;
    puVar20[0x15] = 0;
    *(undefined4 *)(puVar20 + 0x16) = 0;
    fVar43 = local_454;
  }
  iVar19 = DAT_140c636a8;
  uVar17 = 1;
  uVar27 = 0;
  local_448 = 0.0;
  if ((local_44c != 0) &&
     (fVar75 = *(float *)((longlong)puVar20 + 100) - 0.0,
     (*(float *)(puVar20 + 0xc) - 0.0) * (*(float *)(puVar20 + 0xc) - 0.0) + fVar75 * fVar75 +
     (*(float *)(puVar20 + 0xd) - 0.0) * (*(float *)(puVar20 + 0xd) - 0.0) < DAT_140c3c7a8)) {
    *(undefined4 *)(param_1 + 0x75d8) = 0;
    local_448 = 1.4013e-45;
    *(int *)(param_1 + 0x70a0) = iVar19;
  }
  *(undefined4 *)(param_1 + 0x78dc) = *(undefined4 *)(param_1 + 0x78d8);
  *(undefined4 *)(param_1 + 0x78f0) = *(undefined4 *)(param_1 + 0x78ec);
  local_468 = (float **)0x0;
  local_398 = *(float *)(puVar20 + 4) + 0.0;
  fStack_394 = *(float *)((longlong)puVar20 + 0x24) +
               *(float *)(*(longlong *)(param_1 + 0x6490) + 0x12c4) *
               *(float *)(*(longlong *)(param_1 + 0x6490) + 0x570);
  fStack_390 = *(float *)(puVar20 + 5) + 0.0;
  fStack_38c = *(float *)((longlong)puVar20 + 0x2c) + 0.0;
  iVar19 = (**(code **)(**(longlong **)(param_1 + 0x7248) + 0x1b8))
                     (*(longlong **)(param_1 + 0x7248),&local_398,local_2a8,0xa0041);
  if (iVar19 == 0) {
    return 0;
  }
  iVar19 = FUN_14039e130(param_1);
  if (iVar19 == 0) {
    if ((*(longlong *)(param_1 + 0x78) == 0) || (iVar19 = FUN_14047bf60(), iVar19 == 0)) {
      uVar27 = 0;
      if ((*(int *)(puVar20 + 0x14) == 0) ||
         ((-1 < (DAT_140c636a8 - (int)(longlong)(fVar65 * DAT_140b7a158)) -
                *(int *)(param_1 + 0x70a0) ||
          (*(float *)((longlong)puVar20 + 0x44) <= 0.0 &&
           *(float *)((longlong)puVar20 + 0x44) != 0.0)))) {
        if ((local_218 <= *(float *)((longlong)puVar20 + 0x24)) || (local_218 - local_288 <= fVar83)
           ) {
          if ((*(int *)(puVar20 + 0x14) == 0) ||
             (-1 < (DAT_140c636a8 - (int)(longlong)(fVar65 * DAT_140b7a158)) -
                   *(int *)(param_1 + 0x70a0))) {
            if ((iVar15 == 0) || (local_218 <= *(float *)((longlong)puVar20 + 0x24) + local_440)) {
              uVar27 = (uint)(local_42c != 0);
            }
            else {
              uVar27 = 1;
            }
          }
        }
        else {
          uVar27 = 1;
        }
      }
    }
  }
  else {
    uVar27 = 3;
  }
  if (((*(int *)(puVar20 + 0x10) != 0) && (uVar27 != 1)) ||
     ((*(int *)((longlong)puVar20 + 0x84) != 0 && (uVar27 != 3)))) {
    *(undefined4 *)(param_1 + 0x75d8) = 0;
  }
  if ((*(float *)(puVar20 + 8) * *(float *)(puVar20 + 8) +
       *(float *)((longlong)puVar20 + 0x44) * *(float *)((longlong)puVar20 + 0x44) +
       *(float *)(puVar20 + 9) * *(float *)(puVar20 + 9) < DAT_140c44798) && (iVar15 == 0)) {
    uVar39 = uVar39 | 1;
  }
  if ((DAT_140c44798 <
       *(float *)(puVar20 + 10) * *(float *)(puVar20 + 10) +
       *(float *)((longlong)puVar20 + 0x54) * *(float *)((longlong)puVar20 + 0x54) +
       *(float *)(puVar20 + 0xb) * *(float *)(puVar20 + 0xb)) && (iVar15 != 0)) {
    uVar39 = uVar39 | 2;
  }
  if ((uVar27 - 1 & 0xfffffffd) == 0) {
    uVar39 = uVar39 | 0x80;
  }
  if (uVar27 == 2) {
    uVar39 = uVar39 | 0x400;
  }
  if (*(float *)((longlong)puVar20 + 0x24) <= DAT_140c7ad44 &&
      DAT_140c7ad44 != *(float *)((longlong)puVar20 + 0x24)) {
    *(float *)((longlong)puVar20 + 0x24) = DAT_140c7ad44;
    *(undefined4 *)(puVar20 + 0x11) = 0;
    *(undefined4 *)((longlong)puVar20 + 0x94) = 0;
  }
  if (-1 < (char)uVar39) {
    if (*(int *)(puVar20 + 0x11) == 0) {
      uVar40 = uVar39;
      if (uVar27 != 3) {
        uVar40 = uVar39 | 0x100;
      }
    }
    else {
      uVar40 = uVar39 | 4;
      if (fVar84 < *(float *)((longlong)puVar20 + 0x8c) ||
          fVar84 == *(float *)((longlong)puVar20 + 0x8c)) {
        uVar40 = uVar39 | 0xc;
      }
    }
    uVar39 = uVar40;
    if ((*(int *)((longlong)puVar20 + 0x94) != 0) &&
       (uVar39 = uVar40 | 0x10,
       fVar84 < *(float *)(puVar20 + 0x13) || fVar84 == *(float *)(puVar20 + 0x13))) {
      uVar39 = uVar40 | 0x30;
    }
  }
  if (*(int *)(puVar20 + 0x14) != 0) {
    uVar39 = uVar39 | 0x40;
  }
  if (*(int *)(puVar20 + 0x16) != 0) {
    uVar39 = uVar39 | 0x800;
  }
  lVar23 = *(longlong *)(param_1 + 0x6490);
  if (*(int *)(lVar23 + 0x80) == 0x17) {
    if ((uVar39 & 4) != 0) {
      local_460 = &local_128;
      local_468 = &local_418;
      local_128 = 0x4041;
      local_418 = (float *)0x0;
      uStack_120 = CONCAT44(uStack_120._4_4_,1);
      local_118 = (undefined4 *)0x0;
      fVar43 = *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x570) +
               *(float *)((longlong)puVar20 + 0x24) + fVar46;
      uStack_110 = 0;
      local_108 = 0.0;
      uStack_100 = 0;
      if (fVar43 <= local_1e4) {
        local_1e4 = fVar43;
      }
      local_3b8._0_8_ = 0x3f80000000000000;
      local_3c8._4_4_ = local_1e4;
      local_3c8._0_4_ = *(undefined4 *)(puVar20 + 4);
      uStack_3c0._0_4_ = *(undefined4 *)(puVar20 + 5);
      uStack_3c0._4_4_ = 0;
      local_3f8._4_4_ = local_1e8;
      local_3f8._0_4_ = *(undefined4 *)(puVar20 + 4);
      uStack_3f0._0_4_ = (float)*(undefined4 *)(puVar20 + 5);
      uStack_3f0._4_4_ = 0.0;
      iVar15 = (**(code **)(**(longlong **)(param_1 + 0x7248) + 0x1a8))
                         (*(longlong **)(param_1 + 0x7248),local_3c8,local_3f8,local_3b8);
      if (iVar15 == 0) {
        uVar47 = *(undefined8 *)(*(longlong *)(param_1 + 0x6490) + 0x11e8);
        puVar20[4] = *(undefined8 *)(*(longlong *)(param_1 + 0x6490) + 0x11e0);
        puVar20[5] = uVar47;
        uVar39 = *(uint *)(*(longlong *)(param_1 + 0x6490) + 0x1070);
        puVar20[8] = 0;
        puVar20[9] = 0;
      }
      if (local_418 != (float *)0x0) {
        (**(code **)(*(longlong *)local_418 + 8))();
      }
    }
    goto LAB_1403a5c98;
  }
  if (((local_1e8 - fVar46) - *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x570) <=
       *(float *)((longlong)puVar20 + 0x24)) || (*(int *)(param_1 + 0x70a4) != 0))
  goto LAB_1403a5c98;
  local_460 = &local_128;
  local_468 = &local_418;
  local_128 = 0x4041;
  local_418 = (float *)0x0;
  uStack_120 = CONCAT44(uStack_120._4_4_,1);
  local_118 = (undefined4 *)0x0;
  uStack_110 = 0;
  local_108 = 0.0;
  uStack_100 = 0;
  local_3c8._4_4_ =
       *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x570) +
       *(float *)((longlong)puVar20 + 0x24) + fVar46;
  local_3c8._0_4_ = *(undefined4 *)(puVar20 + 4);
  uStack_3c0._0_4_ = *(undefined4 *)(puVar20 + 5);
  uStack_3c0._4_4_ = 0;
  local_3b8._0_8_ = 0x3f80000000000000;
  local_3f8._4_4_ = local_1e8;
  local_3f8._0_4_ = *(undefined4 *)(puVar20 + 4);
  uStack_3f0._0_4_ = (float)*(undefined4 *)(puVar20 + 5);
  uStack_3f0._4_4_ = 0.0;
  uVar31 = 1;
  uVar30 = 1;
  iVar15 = (**(code **)(**(longlong **)(param_1 + 0x7248) + 0x1a8))
                     (*(longlong **)(param_1 + 0x7248),local_3c8,local_3f8,local_3b8);
  if (iVar15 == 0) {
    fVar43 = *(float *)((longlong)puVar20 + 0x24);
    lVar23 = (**(code **)(**(longlong **)(param_1 + 0x7248) + 0x48))();
    if (fVar43 < local_1e8 - *(float *)(lVar23 + 8)) {
      uVar47 = *(undefined8 *)(*(longlong *)(param_1 + 0x6490) + 0x11e8);
      puVar20[4] = *(undefined8 *)(*(longlong *)(param_1 + 0x6490) + 0x11e0);
      puVar20[5] = uVar47;
      goto LAB_1403a5e60;
    }
  }
  else {
    fVar75 = (float)(**(code **)(*(longlong *)local_418 + 0x10))();
    *(float *)((longlong)puVar20 + 0x24) =
         ((float)local_3f8._4_4_ - (float)local_3c8._4_4_) * fVar75 + (float)local_3c8._4_4_ +
         fVar43;
    uVar30 = 0;
LAB_1403a5e60:
    *(undefined4 *)((longlong)puVar20 + 0x44) = 0;
    uVar31 = uVar30;
  }
  if (*(int *)(param_1 + 0x1b80) == 0) {
    lVar23 = *(longlong *)(param_1 + 0x6490);
    fVar43 = (local_1e8 - fVar46) - *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x570);
    if (*(float *)(lVar23 + 0x11e4) <= fVar43 && fVar43 != *(float *)(lVar23 + 0x11e4)) {
      uStack_130 = *(undefined8 *)(lVar23 + 0x11e8);
      lVar33 = *(longlong *)(param_1 + 0x71a0);
      local_138 = SUB84(*(undefined8 *)(lVar23 + 0x11e0),0);
      _local_138 = CONCAT44((local_1e8 - fVar46) -
                            *(float *)(lVar23 + 0x12c4) * *(float *)(lVar23 + 0x570),local_138);
      if (*(int *)(lVar33 + 0x54) == 0) {
        *(undefined8 *)(lVar33 + 0x40) = _local_138;
        *(undefined8 *)(lVar33 + 0x48) = uStack_130;
      }
      lVar23 = *(longlong *)(param_1 + 0x71a0);
      if (*(int *)(lVar23 + 0x54) == 0) {
        *(undefined8 *)(lVar23 + 0x260) = _local_138;
        *(undefined8 *)(lVar23 + 0x268) = uStack_130;
      }
    }
    if (*(longlong *)(param_1 + 0x7040) != 0) {
      FUN_14057a2c0(param_1);
    }
    lVar23 = *(longlong *)(param_1 + 0x71a0);
    auStack_134 = (undefined1  [4])*(undefined4 *)(lVar23 + 0x40);
    local_138 = (undefined1  [4])uVar31;
    uStack_130._0_4_ = (float)*(undefined4 *)(lVar23 + 0x44);
    uStack_130._4_4_ = (float)*(undefined4 *)(lVar23 + 0x48);
    FUN_1403f4900(param_1,0xfc,local_138);
    *(undefined4 *)(*(longlong *)(param_1 + 0x71a0) + 0x54) = uVar31;
    *(undefined4 *)(param_1 + 0x1b80) = 1;
  }
  if (local_418 != (float *)0x0) {
    (**(code **)(*(longlong *)local_418 + 8))();
  }
LAB_1403a5c98:
  lVar23 = 0;
  if (*(float *)((longlong)puVar20 + 0x24) <= local_218 &&
      local_218 != *(float *)((longlong)puVar20 + 0x24)) {
    uVar39 = uVar39 | 0x200;
  }
  lVar33 = CONCAT44(uStack_3a4,local_3a8);
  local_410 = (float)(uVar39 & 0x100);
  if ((uVar39 & 0x100) == 0) {
    if ((uVar39 & 0x40) == 0) {
      if ((uVar39 & 4) == 0) {
        if ((uVar39 & 0x80) != 0) {
          lVar33 = 0;
        }
      }
      else if (fVar84 < *(float *)((longlong)puVar20 + 0x8c)) {
        lVar33 = 0;
      }
    }
    else if (fVar65 + fVar84 < *(float *)(puVar20 + 0x15)) {
      lVar33 = 0;
    }
  }
  else {
    lVar33 = lVar23;
    if (((local_26c != 0) && (lVar23 = FUN_1403d90d0(param_1), lVar23 != 0)) &&
       (*(int *)(lVar23 + 0x80) == 0xb)) {
      lVar33 = lVar23;
    }
  }
  lVar23 = CONCAT44(uStack_3a4,local_3a8);
  uStack_120 = uStack_120 & 0xffffffff00000000;
  uVar40 = (uint)(lVar23 == lVar33);
  if ((lVar23 != 0) && (uVar40 == 0)) {
    fVar43 = *(float *)(lVar23 + 0x1124);
    fVar46 = *(float *)(lVar23 + 0x1128);
    fVar75 = *(float *)(lVar23 + 0x112c);
    *(float *)(puVar20 + 8) = *(float *)(lVar23 + 0x1120) + *(float *)(puVar20 + 8);
    *(float *)((longlong)puVar20 + 0x44) = fVar43 + *(float *)((longlong)puVar20 + 0x44);
    *(float *)(puVar20 + 9) = fVar46 + *(float *)(puVar20 + 9);
    *(float *)((longlong)puVar20 + 0x4c) = fVar75 + *(float *)((longlong)puVar20 + 0x4c);
  }
  if (lVar33 == 0) {
    _local_138 = *(undefined1 (*) [16])(puVar20 + 4);
    _local_3f8 = *(undefined1 (*) [16])(puVar20 + 8);
    uVar30 = 0;
    _local_3c8 = *(undefined1 (*) [16])(puVar20 + 10);
    fVar43 = local_428;
  }
  else {
    fVar43 = *(float *)(puVar20 + 4);
    fVar46 = *(float *)((longlong)puVar20 + 0x24);
    fVar75 = *(float *)(puVar20 + 5);
    fVar78 = *(float *)(puVar20 + 8);
    fVar44 = *(float *)((longlong)puVar20 + 0x44);
    fVar84 = *(float *)(puVar20 + 9);
    auStack_134 = (undefined1  [4])
                  (fVar46 * *(float *)(lVar33 + 0x1204) + fVar43 * *(float *)(lVar33 + 0x11f4) +
                   fVar75 * *(float *)(lVar33 + 0x1214) + *(float *)(lVar33 + 0x1224));
    local_138 = (undefined1  [4])
                (fVar46 * *(float *)(lVar33 + 0x1200) + fVar43 * *(float *)(lVar33 + 0x11f0) +
                 fVar75 * *(float *)(lVar33 + 0x1210) + *(float *)(lVar33 + 0x1220));
    uStack_130._0_4_ =
         fVar46 * *(float *)(lVar33 + 0x1208) + fVar43 * *(float *)(lVar33 + 0x11f8) +
         fVar75 * *(float *)(lVar33 + 0x1218) + *(float *)(lVar33 + 0x1228);
    uStack_130._4_4_ =
         fVar46 * *(float *)(lVar33 + 0x120c) + fVar43 * *(float *)(lVar33 + 0x11fc) +
         fVar75 * *(float *)(lVar33 + 0x121c) + *(float *)(lVar33 + 0x122c);
    fVar43 = *(float *)(puVar20 + 10);
    fVar46 = *(float *)((longlong)puVar20 + 0x54);
    fVar75 = *(float *)(puVar20 + 0xb);
    local_3f8._4_4_ =
         fVar44 * *(float *)(lVar33 + 0x1204) + fVar78 * *(float *)(lVar33 + 0x11f4) +
         fVar84 * *(float *)(lVar33 + 0x1214);
    local_3f8._0_4_ =
         fVar44 * *(float *)(lVar33 + 0x1200) + fVar78 * *(float *)(lVar33 + 0x11f0) +
         fVar84 * *(float *)(lVar33 + 0x1210);
    uStack_3f0._0_4_ =
         fVar44 * *(float *)(lVar33 + 0x1208) + fVar78 * *(float *)(lVar33 + 0x11f8) +
         fVar84 * *(float *)(lVar33 + 0x1218);
    uStack_3f0._4_4_ =
         fVar44 * *(float *)(lVar33 + 0x120c) + fVar78 * *(float *)(lVar33 + 0x11fc) +
         fVar84 * *(float *)(lVar33 + 0x121c);
    uVar30 = *(undefined4 *)(lVar33 + 8);
    local_3c8._4_4_ =
         fVar46 * *(float *)(lVar33 + 0x1204) + fVar43 * *(float *)(lVar33 + 0x11f4) +
         fVar75 * *(float *)(lVar33 + 0x1214);
    local_3c8._0_4_ =
         fVar46 * *(float *)(lVar33 + 0x1200) + fVar43 * *(float *)(lVar33 + 0x11f0) +
         fVar75 * *(float *)(lVar33 + 0x1210);
    uStack_3c0._0_4_ =
         fVar46 * *(float *)(lVar33 + 0x1208) + fVar43 * *(float *)(lVar33 + 0x11f8) +
         fVar75 * *(float *)(lVar33 + 0x1218);
    uStack_3c0._4_4_ =
         fVar46 * *(float *)(lVar33 + 0x120c) + fVar43 * *(float *)(lVar33 + 0x11fc) +
         fVar75 * *(float *)(lVar33 + 0x121c);
    fVar43 = local_428 - *(float *)(lVar33 + 0x12c0);
  }
  local_128._4_4_ = 1.12104e-44;
  puVar25 = (undefined4 *)FUN_14018c320(0,0x240,8);
  *puVar25 = 1;
  puVar25[2] = uVar30;
  if ((uVar40 == 0) || (local_448 != 0.0)) {
    uVar17 = 0;
  }
  puVar25[0x12] = 2;
  puVar25[0x14] = local_138;
  puVar25[0x15] = auStack_134;
  puVar25[0x16] = (float)uStack_130;
  puVar25[0x17] = uVar17;
  local_118 = puVar25;
  FUN_1401c9800(&local_448,local_3f8);
  puVar25[0x24] = 8;
  puVar25[0x26] = local_448;
  *(undefined2 *)(puVar25 + 0x27) = local_444;
  puVar25[0x28] = uVar40;
  FUN_1401c9800(&local_448,local_3c8);
  puVar25[0x36] = 0xb;
  puVar25[0x38] = local_448;
  *(undefined2 *)(puVar25 + 0x39) = local_444;
  puVar25[0x3a] = uVar40;
  local_128 = CONCAT44(local_128._4_4_,4);
  if (*(int *)(*(longlong *)(param_1 + 0x6490) + 0x1620) == 0) {
    uStack_3a4 = 0;
    uStack_3a0 = 0;
    local_3a8 = fVar43;
    FUN_14079a780(&local_128,&local_3a8,lVar23 == lVar33);
  }
  FUN_14079a810(&local_128,uVar39);
  FUN_14079a990(&local_128,uVar27);
  if ((DAT_140dc21e0 >> 10 & 1) == 0) {
    DAT_140dc21e0 = DAT_140dc21e0 | 0x400;
    DAT_140dc2210 = 0x141cccf9c;
  }
  *(uint *)(param_1 + 0x7de0) = *(uint *)(param_1 + 0x7de0) ^ *(uint *)(DAT_140dc2210 + -0x12fa640);
  fVar43 = *(float *)(*(longlong *)(param_1 + 0x6490) + 0xe88);
  fVar46 = (float)FUN_1403b50c0();
  iVar15 = DAT_140c636a8;
  local_468 = (float **)0x0;
  *(float *)(param_1 + 0x7de0) = fVar46 + fVar43 + *(float *)(param_1 + 0x7de0);
  *(uint *)(param_1 + 0x7de0) = *(uint *)(param_1 + 0x7de0) ^ *(uint *)(DAT_140dc2210 + -0x12fa640);
  FUN_1405b3b80(*(undefined8 *)(param_1 + 0x6490),&local_128,iVar15,0);
  FUN_14057a190(param_1,&local_128);
  if ((0.0 < *(float *)(puVar20 + 0x12)) &&
     (*(int *)(*(longlong *)(param_1 + 0x6490) + 0x80) != 0x17)) {
    if (*(longlong *)(param_1 + 0x7040) != 0) {
      FUN_14057a2c0(param_1);
    }
    local_448 = *(float *)(puVar20 + 0x12);
    FUN_1403f4900(param_1,0xfb,&local_448);
  }
  if (((*(longlong *)(param_1 + 0x78) != 0) && (iVar15 = FUN_14047bf00(), iVar15 != 0)) &&
     (local_410 != 0.0)) {
    FUN_14039e400(param_1);
  }
  if ((((*(longlong *)(param_1 + 0x78) != 0) &&
       (lVar23 = FUN_1403d90d0(DAT_140c65898,*(undefined4 *)(*(longlong *)(param_1 + 0x78) + 0xc0)),
       lVar23 != 0)) &&
      ((*(int *)(lVar23 + 0x80) == 7 &&
       ((*(longlong *)(param_1 + 0x78) == 0 || (iVar15 = FUN_14047be40(), iVar15 == 0)))))) &&
     (*(int *)((longlong)puVar20 + 0xb4) != 0)) {
    FUN_14039e400(param_1);
  }
  if ((*(int *)(param_1 + 0x78d8) != 0) && (*(longlong *)(param_1 + 0x7040) != 0)) {
    FUN_14057a2c0(param_1);
  }
  FUN_14079a4f0(&local_128);
  FUN_14018b900(local_118,0);
  return 0;
}



==== FUN_140359e70 @ 140359e70 size 731 ====
CALLERS: FUN_14036e3a0 FUN_14036f190
CALLEES: QueryPerformanceCounter FUN_140357df0 FUN_140371550 FUN_14037d060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140359e70(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  float fVar3;
  undefined1 auVar4 [16];
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  LARGE_INTEGER local_res10;
  int local_78 [2];
  longlong local_70;
  
  plVar1 = (longlong *)(param_1 + 0x920);
  lVar5 = *plVar1;
  while (lVar5 != 0) {
    if (*(undefined8 **)(lVar5 + 0x588) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar5 + 0x588) = *(undefined8 *)(lVar5 + 0x590);
    }
    if (*(longlong *)(lVar5 + 0x590) != 0) {
      *(undefined8 *)(*(longlong *)(lVar5 + 0x590) + 0x588) = *(undefined8 *)(lVar5 + 0x588);
    }
    *(undefined8 *)(lVar5 + 0x588) = 0;
    *(undefined8 *)(lVar5 + 0x590) = 0;
    lVar5 = *plVar1;
  }
  if (*(int *)(param_1 + 0x770) == 0) {
    FUN_140357df0(param_1,param_1 + 0x690);
    fVar3 = *(float *)(param_1 + 0x88);
    fVar19 = fVar3 + DAT_140b7a084;
    fVar18 = fVar3 * fVar3 * DAT_140b79df8;
    fVar14 = (_DAT_140b7ac50 + *(float *)(param_1 + 0x390) * DAT_140c43fb8) * _DAT_140b7b490;
    fVar16 = (_UNK_140b7ac54 + *(float *)(param_1 + 0x398) * DAT_140c43fb8) * _UNK_140b7b494;
    lVar5 = *(longlong *)(param_1 + 0x918);
    while (lVar6 = lVar5, lVar6 != 0) {
      lVar5 = *(longlong *)(lVar6 + 0x580);
      piVar9 = (int *)(**(code **)(**(longlong **)(lVar6 + 0x10) + 0x28))();
      auVar4 = *(undefined1 (*) [16])(param_1 + 0x360);
      auVar13 = minps(auVar4,*(undefined1 (*) [16])(piVar9 + 0xc));
      auVar13 = maxps(*(undefined1 (*) [16])(piVar9 + 8),auVar13);
      fVar15 = auVar13._0_4_ - auVar4._0_4_;
      fVar17 = auVar13._8_4_ - auVar4._8_4_;
      fVar15 = fVar17 * fVar17 + fVar15 * fVar15;
      if (fVar15 <= fVar19 * fVar19) {
        local_78[0] = -1;
        if (fVar18 < fVar15) {
          local_78[0] = 0;
        }
        if (0 < local_78[0]) {
          QueryPerformanceCounter(&local_res10);
          local_70 = local_res10.QuadPart - _DAT_140c87988;
        }
        if (((*(longlong *)(lVar6 + 0x5b8) == 0) ||
            (iVar7 = FUN_14037d060(lVar6,local_78,0), iVar7 != 0)) && (fVar15 <= fVar3 * fVar3)) {
          auVar4 = *(undefined1 (*) [16])(param_1 + 0x390);
          auVar13 = minps(auVar4,*(undefined1 (*) [16])(piVar9 + 0xc));
          auVar13 = maxps(*(undefined1 (*) [16])(piVar9 + 8),auVar13);
          fVar15 = auVar13._0_4_ - auVar4._0_4_;
          fVar17 = auVar13._8_4_ - auVar4._8_4_;
          *(float *)(lVar6 + 0x30) = fVar17 * fVar17 + fVar15 * fVar15;
          uVar8 = piVar9[1] - (int)fVar16;
          uVar12 = *piVar9 - (int)fVar14;
          uVar10 = (int)uVar8 >> 0x1f;
          uVar11 = (int)uVar12 >> 0x1f;
          *(uint *)(lVar6 + 0x34) = ((uVar8 ^ uVar10) - uVar10) + ((uVar12 ^ uVar11) - uVar11);
          if (*(longlong *)(lVar6 + 0x588) == 0) {
            *(longlong **)(lVar6 + 0x588) = plVar1;
            plVar2 = (longlong *)(lVar6 + 0x590);
            *plVar2 = *plVar1;
            *plVar1 = lVar6;
            if (*plVar2 != 0) {
              *(longlong **)(*plVar2 + 0x588) = plVar2;
            }
          }
        }
      }
    }
    FUN_140371550(plVar1);
  }
  return;
}



==== FUN_140319e40 @ 140319e40 size 151 ====
CALLERS: FUN_1402f39e0
CALLEES: FUN_1407e4830 FUN_14032d190

undefined8 * FUN_140319e40(undefined8 *param_1)

{
  FUN_14032d190();
  *param_1 = &PTR_LAB_140b64310;
  param_1[0x89] = 0;
  param_1[0x88] = 0;
  param_1[0x8a] = 0;
  FUN_1407e4830(param_1 + 0x8b,0,0x50);
  FUN_1407e4830(param_1 + 0x95,0,0x50);
  FUN_1407e4830(param_1 + 0x9f,0,0x50);
  FUN_1407e4830(param_1 + 0xa9,0,0x50);
  param_1[0xb3] = 0;
  param_1[0x87] = 0;
  return param_1;
}



==== FUN_140319f20 @ 140319f20 size 766 ====
CALLERS: FUN_140319ee0
CALLEES: FUN_14018b900 FUN_1401a4a00 FUN_14031cd00 FUN_14032d3f0

/* WARNING: Removing unreachable block (ram,0x00014031a15e) */
/* WARNING: Removing unreachable block (ram,0x00014031a09e) */
/* WARNING: Removing unreachable block (ram,0x00014031a0fe) */
/* WARNING: Removing unreachable block (ram,0x00014031a1be) */

void FUN_140319f20(undefined8 *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  
  plVar1 = param_1 + 0x8a;
  uVar4 = 0;
  *param_1 = &PTR_LAB_140b64310;
  lVar9 = *plVar1;
  while (lVar9 != 0) {
    lVar9 = *plVar1;
    plVar2 = *(longlong **)(lVar9 + 0x50);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x460))(plVar2,0,0);
      if (*(longlong **)(lVar9 + 0x50) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(lVar9 + 0x50) + 8))();
        *(undefined8 *)(lVar9 + 0x50) = 0;
      }
    }
    lVar9 = *plVar1;
    if (lVar9 != 0) {
      if (*(undefined8 **)(lVar9 + 0x70) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar9 + 0x70) = *(undefined8 *)(lVar9 + 0x78);
      }
      if (*(longlong *)(lVar9 + 0x78) != 0) {
        *(undefined8 *)(*(longlong *)(lVar9 + 0x78) + 0x70) = *(undefined8 *)(lVar9 + 0x70);
      }
      *(undefined8 *)(lVar9 + 0x70) = 0;
      *(undefined8 *)(lVar9 + 0x78) = 0;
      FUN_14018b900();
    }
    lVar9 = *plVar1;
  }
  if (param_1[0x89] != 0) {
    do {
      lVar9 = param_1[0x88] + uVar4 * 0x70;
      plVar2 = *(longlong **)(lVar9 + 0x50);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 8))();
        *(undefined8 *)(lVar9 + 0x50) = 0;
      }
      uVar4 = (ulonglong)((int)uVar4 + 1);
    } while (uVar4 < (ulonglong)param_1[0x89]);
  }
  FUN_14031cd00(param_1 + 0x88,0);
  FUN_14018b900(param_1[0xb3],0);
  if ((longlong *)param_1[0x87] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x87] + 8))();
    param_1[0x87] = 0;
  }
  iVar6 = 4;
  puVar5 = param_1 + 0xb4;
  iVar8 = 4;
  iVar7 = iVar8;
  do {
    puVar3 = (undefined8 *)puVar5[-2];
    puVar5 = puVar5 + -2;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = &PTR__purecall_140b66870;
      if ((undefined8 *)puVar3[1] != (undefined8 *)0x0) {
        *(undefined8 *)puVar3[1] = puVar3[2];
      }
      if (puVar3[2] != 0) {
        *(undefined8 *)(puVar3[2] + 8) = puVar3[1];
      }
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      FUN_14018b900(puVar3,0);
    }
    iVar7 = iVar7 + -1;
  } while (-1 < iVar7);
  puVar5 = param_1 + 0xaa;
  do {
    puVar3 = (undefined8 *)puVar5[-2];
    puVar5 = puVar5 + -2;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = &PTR__purecall_140b66870;
      if ((undefined8 *)puVar3[1] != (undefined8 *)0x0) {
        *(undefined8 *)puVar3[1] = puVar3[2];
      }
      if (puVar3[2] != 0) {
        *(undefined8 *)(puVar3[2] + 8) = puVar3[1];
      }
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      FUN_14018b900(puVar3,0);
    }
    iVar8 = iVar8 + -1;
  } while (-1 < iVar8);
  iVar7 = 4;
  puVar5 = param_1 + 0xa0;
  do {
    puVar3 = (undefined8 *)puVar5[-2];
    puVar5 = puVar5 + -2;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = &PTR__purecall_140b66870;
      if ((undefined8 *)puVar3[1] != (undefined8 *)0x0) {
        *(undefined8 *)puVar3[1] = puVar3[2];
      }
      if (puVar3[2] != 0) {
        *(undefined8 *)(puVar3[2] + 8) = puVar3[1];
      }
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      FUN_14018b900(puVar3,0);
    }
    iVar7 = iVar7 + -1;
  } while (-1 < iVar7);
  puVar5 = param_1 + 0x96;
  do {
    puVar3 = (undefined8 *)puVar5[-2];
    puVar5 = puVar5 + -2;
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = &PTR__purecall_140b66870;
      if ((undefined8 *)puVar3[1] != (undefined8 *)0x0) {
        *(undefined8 *)puVar3[1] = puVar3[2];
      }
      if (puVar3[2] != 0) {
        *(undefined8 *)(puVar3[2] + 8) = puVar3[1];
      }
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      FUN_14018b900(puVar3,0);
    }
    iVar6 = iVar6 + -1;
  } while (-1 < iVar6);
  if (*plVar1 != 0) {
    FUN_1401a4a00(plVar1);
  }
  lVar9 = param_1[0x88];
  if (lVar9 != 0) {
    (**(code **)(*(longlong *)(lVar9 + -0x10) + 8))(lVar9 + -0x10);
  }
  FUN_14032d3f0(param_1);
  return;
}



==== FUN_1403283c0 @ 1403283c0 size 10067 ====
CALLERS:
CALLEES: FUN_140262750 __security_check_cookie FUN_140262d50 FUN_1403282e0 FUN_1407e4830 FUN_1401afb10 FUN_140312840 memcmp

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_1403283c0(longlong param_1,int param_2,uint param_3,longlong *param_4,ulonglong param_5,
             longlong param_6)

{
  undefined8 *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [15];
  undefined1 auVar5 [14];
  undefined1 auVar6 [15];
  undefined1 auVar7 [15];
  undefined1 auVar8 [15];
  undefined1 auVar9 [15];
  undefined1 auVar10 [15];
  undefined1 auVar11 [15];
  undefined1 auVar12 [15];
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined1 auVar27 [15];
  unkuint9 Var28;
  undefined1 auVar29 [15];
  undefined1 auVar30 [13];
  undefined1 auVar31 [14];
  undefined1 auVar32 [15];
  uint6 uVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  longlong *plVar38;
  undefined4 *puVar39;
  short *psVar40;
  longlong lVar41;
  undefined4 *puVar42;
  undefined8 *puVar43;
  undefined8 uVar44;
  float *pfVar45;
  float *pfVar46;
  longlong *plVar47;
  uint uVar48;
  undefined4 uVar49;
  uint uVar50;
  int *piVar51;
  ulonglong uVar52;
  uint uVar53;
  uint uVar54;
  longlong lVar55;
  int *piVar56;
  int *piVar57;
  longlong *plVar58;
  undefined8 *puVar59;
  byte bVar60;
  uint uVar61;
  uint uVar62;
  longlong lVar63;
  ushort *puVar64;
  ulonglong uVar65;
  longlong lVar66;
  int *piVar67;
  uint uVar68;
  ulonglong uVar69;
  float fVar70;
  float fVar71;
  undefined8 extraout_XMM0_Qa;
  float fVar73;
  float fVar74;
  undefined8 extraout_XMM0_Qb;
  undefined8 uVar75;
  ushort uVar76;
  float fVar77;
  undefined1 auVar78 [12];
  undefined1 uVar85;
  undefined1 uVar86;
  undefined1 uVar87;
  undefined1 auVar79 [16];
  undefined1 auVar82 [16];
  undefined4 uVar88;
  undefined4 uVar89;
  undefined4 uVar90;
  float fVar91;
  undefined1 auStack_498 [32];
  undefined8 local_478;
  undefined4 local_470;
  undefined4 local_468;
  int local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  uint local_440;
  float local_438;
  float fStack_434;
  int local_430;
  uint local_42c;
  longlong local_428;
  uint local_420;
  undefined4 *local_418;
  longlong local_410;
  int local_408;
  longlong *local_400;
  uint local_3f8;
  uint local_3f4;
  uint local_3f0;
  int local_3ec;
  undefined8 local_3e8;
  undefined8 uStack_3e0;
  undefined4 local_3d4;
  longlong local_3c8;
  int *local_3c0;
  longlong local_3b8;
  longlong local_3b0;
  uint local_3a8;
  int local_3a4;
  float local_3a0;
  longlong *local_398;
  longlong local_390;
  ulonglong local_388;
  longlong *local_380;
  int *local_378;
  float *local_370;
  longlong *local_368;
  float *local_360;
  ulonglong local_358;
  longlong local_350;
  longlong *local_338;
  undefined8 local_328;
  undefined4 *puStack_320;
  undefined8 local_318;
  undefined4 *puStack_310;
  undefined4 *local_308;
  undefined8 uStack_300;
  undefined4 local_2f8;
  undefined4 uStack_2f4;
  uint local_2e8;
  uint local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  undefined8 local_2c4;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined8 local_2b0;
  uint local_2a8;
  longlong local_2a0 [8];
  undefined8 local_260;
  undefined8 local_258;
  longlong local_250 [6];
  longlong local_220 [10];
  longlong local_1d0 [6];
  undefined4 local_1a0 [8];
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178 [6];
  longlong alStack_160 [8];
  undefined8 local_120;
  undefined8 local_118;
  longlong local_110 [7];
  undefined4 *local_d8;
  longlong local_d0;
  ulonglong local_88;
  undefined1 auVar72 [16];
  undefined1 auVar80 [16];
  undefined1 auVar83 [16];
  undefined1 auVar81 [16];
  undefined1 auVar84 [16];
  
  local_88 = DAT_140c0f7b0 ^ (ulonglong)auStack_498;
  lVar63 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
  local_3b8 = *param_4;
  plVar47 = *(longlong **)(local_3b8 + 0x30);
  plVar58 = *(longlong **)(local_3b8 + 0x48);
  local_358 = plVar47[7];
  lVar41 = plVar47[8];
  local_418 = *(undefined4 **)(local_3b8 + 0x40);
  local_3a0 = *(float *)(local_3b8 + 0x50);
  local_360 = *(float **)(local_3b8 + 0x38);
  piVar67 = (int *)(*(longlong *)(lVar41 + 0x1f8) + 8 +
                   (ulonglong)*(ushort *)((longlong)local_418 + 0x16) * 0x30);
  lVar55 = (ulonglong)*(ushort *)((longlong)local_418 + 0x16) * 0x60 + plVar47[0x8a];
  local_398 = (longlong *)0x0;
  local_388 = 0;
  local_410 = 0;
  local_3c0 = (int *)0x0;
  local_390 = 0;
  local_438 = 0.0;
  local_370 = (float *)0x0;
  local_368 = (longlong *)0x0;
  local_430 = param_2;
  local_428 = param_1;
  local_420 = param_3;
  local_400 = plVar47;
  local_3c8 = lVar63;
  local_3b0 = lVar55;
  local_380 = plVar58;
  local_378 = piVar67;
  local_350 = lVar41;
  local_338 = param_4;
  plVar38 = (longlong *)(**(code **)(*DAT_140c65688 + 0xe0))();
  local_3a4 = *(int *)(*plVar38 + (ulonglong)*(byte *)(lVar55 + 0x58) * 4);
  if ((plVar58 != (longlong *)0x0) && (*(short *)(*plVar58 + 6) == 3)) {
    uVar69 = (ulonglong)*(ushort *)(*plVar58 + 0xe);
    piVar67 = (int *)(*(longlong *)(lVar41 + 0x1f8) + 8 + uVar69 * 0x30);
    local_3b0 = uVar69 * 0x60 + plVar47[0x8a];
    local_378 = piVar67;
  }
  if (param_6 != 0) {
    local_398 = *(longlong **)(param_6 + 0x30);
    local_410 = *(longlong *)(param_6 + 0x40);
    local_388 = local_398[7];
    piVar56 = (int *)((ulonglong)*(ushort *)(local_410 + 0x16) * 0x30 +
                     *(longlong *)(local_398[8] + 0x1f8) + 8);
    if (*piVar67 == *piVar56) {
      local_438 = *(float *)(param_6 + 0x50);
      local_370 = *(float **)(param_6 + 0x38);
      local_390 = (ulonglong)*(ushort *)(local_410 + 0x16) * 0x60 + local_398[0x8a];
      local_368 = *(longlong **)(param_6 + 0x48);
      local_3c0 = piVar56;
    }
  }
  FUN_1407e4830(&local_2e8,0,0x208);
  uVar50 = local_2e4;
  uVar54 = local_2e8;
  local_2b8 = (**(code **)(*DAT_140c65688 + 0x110))();
  lVar41 = local_428;
  if (param_6 == 0) {
    FUN_140312840(*(undefined8 *)(local_428 + 0x10),local_430);
  }
  fVar73 = DAT_140b79ed0;
  uVar68 = piVar67[1];
  if (((uVar68 & 4) == 0) &&
     (uVar53 = *(uint *)(*(longlong *)(lVar41 + 0x10) + 0x570), (uVar53 & 0xc0) == 0)) {
    if ((uVar53 >> 8 & 1) == 0) {
      local_2e0 = 1;
    }
    else {
      local_2e0 = 2;
    }
  }
  else {
    local_2e0 = 0;
  }
  uVar49 = 4;
  local_44c = 1;
  uVar53 = *(uint *)(*(longlong *)(lVar41 + 0x10) + 0x570);
  local_454 = 0;
  local_458 = 0;
  local_444 = 1;
  local_450 = 0;
  local_448 = 0;
  uVar61 = uVar53 & 4;
  if (uVar61 == 0) {
    if (((uVar53 >> 9 & 1) != 0) && (local_430 == 1)) {
      local_44c = 4;
      local_454 = 5;
      local_458 = 0;
      local_444 = 4;
      local_450 = 5;
      local_448 = 0;
    }
  }
  else {
    local_44c = 1;
    local_454 = 1;
    local_444 = 1;
    local_450 = 1;
    local_458 = 3;
    local_448 = 3;
  }
  local_3ec = piVar67[3];
  local_440 = 0xf;
  if (local_3c0 == (int *)0x0) {
    local_408 = 0xf;
  }
  else {
    local_408 = local_3c0[3];
  }
  if (local_430 != 5) goto LAB_140328979;
  if (local_380 != (longlong *)0x0) {
    if (local_3ec == 0) {
      local_3ec = 3;
    }
    else if ((local_3ec == 1) || (lVar63 = local_3c8, *(short *)(*local_380 + 6) == 2)) {
      local_3ec = 4;
    }
  }
  if (local_368 != (longlong *)0x0) {
    if (local_408 == 0) {
      local_408 = 3;
    }
    else if ((local_408 == 1) || (*(short *)(*local_368 + 6) == 2)) {
      local_408 = 4;
    }
  }
  if ((local_380 == (longlong *)0x0) || (*(short *)(*local_380 + 6) != 2)) {
    switch(local_3ec) {
    case 3:
      goto switchD_1403287a0_caseD_3;
    case 4:
      local_458 = 0;
      local_448 = 0;
      local_44c = 4;
      local_454 = 1;
      local_450 = 1;
      local_444 = 7;
      break;
    case 5:
      goto switchD_1403287a0_caseD_5;
    case 6:
      local_450 = 1;
      local_44c = 8;
      local_454 = 2;
      local_458 = 0;
      local_448 = 0;
      local_444 = 7;
      break;
    default:
      local_44c = 4;
      local_454 = 5;
      goto LAB_14032882f;
    case 8:
      goto switchD_1403287a0_caseD_8;
    case 9:
      goto switchD_1403287a0_caseD_9;
    case 10:
      local_44c = 1;
      local_454 = 3;
      local_458 = 0;
      local_450 = 1;
      local_448 = 0;
      local_444 = 7;
    }
    goto LAB_140328979;
  }
  switch(*(undefined2 *)(*local_380 + 0x16)) {
  case 3:
switchD_1403287a0_caseD_3:
    local_454 = 1;
    goto LAB_14032882b;
  case 4:
    local_454 = 1;
    local_44c = 4;
    goto LAB_14032882f;
  case 5:
switchD_1403287a0_caseD_5:
    local_450 = 1;
    local_44c = 8;
    local_454 = 0;
    local_444 = 7;
    local_448 = 0;
    local_458 = 0;
    break;
  case 6:
    local_44c = 8;
    local_454 = 2;
    goto LAB_14032882f;
  default:
    local_450 = 1;
    local_458 = 0;
    local_448 = 0;
    local_44c = 4;
    local_454 = 5;
    local_444 = 7;
    break;
  case 8:
switchD_1403287a0_caseD_8:
    uVar49 = 3;
  case 9:
switchD_1403287a0_caseD_9:
    local_44c = 1;
    local_454 = 1;
    local_444 = 7;
    local_450 = 1;
    local_448 = 0;
    local_458 = uVar49;
    break;
  case 10:
    local_454 = 3;
LAB_14032882b:
    local_44c = 1;
LAB_14032882f:
    local_450 = 1;
    local_444 = 7;
    local_458 = 0;
    local_448 = 0;
  }
LAB_140328979:
  iVar36 = local_3ec;
  local_2cc = local_450;
  local_2c8 = local_448;
  if ((uVar53 & 8) == 0) {
    if (local_430 == 5) {
      local_440 = 0x8f;
      if ((uVar53 & 0x40) == 0) {
        local_440 = 7;
      }
      if (((uVar53 & 0x20) == 0) &&
         ((*(longlong **)(local_3b8 + 0x48) == (longlong *)0x0 ||
          (*(short *)(**(longlong **)(local_3b8 + 0x48) + 6) != 2)))) {
        local_42c = ~(uVar68 >> 1) & 1;
      }
      else {
        local_42c = 0;
      }
    }
    else {
      if (local_430 != 4) {
        if (uVar61 == 0) {
          if ((uVar53 & 0x20) == 0) {
            local_440 = 0xfff;
            if ((uVar53 >> 0xc & 1) != 0) {
              local_440 = 0x2fff;
            }
            if ((local_430 == 0) && ((*(byte *)(plVar47 + 0xe4) & 1) != 0)) {
              local_440 = local_440 | 0x2000;
            }
            if ((uVar68 >> 0x10 & 1) != 0) {
              local_440 = 0;
              local_2b8 = 0;
            }
          }
          else {
            local_440 = 0xff7;
          }
        }
        else {
          local_440 = 0xf;
        }
      }
      local_42c = 1;
    }
    local_2c4 = CONCAT44(local_42c,local_440);
  }
  else {
    local_42c = 0;
    local_440 = 0;
    local_2c4 = 0;
  }
  if (((uVar53 & 0x20) == 0) && ((uVar68 & 1) == 0)) {
    local_2bc = 3;
  }
  else {
    local_2bc = 7;
  }
  uVar68 = local_2e8 | 0x5f;
  uVar53 = local_2e4 | 0x5f;
  local_3f8 = uVar68;
  local_3f4 = uVar53;
  local_2e8 = uVar68;
  local_2e4 = uVar53;
  local_2dc = local_44c;
  local_2d8 = local_454;
  local_2d4 = local_458;
  local_2d0 = local_444;
  if (uVar61 == 0) {
    if ((local_410 == 0) || (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0))
    {
      if ((*(byte *)(local_418 + 0xe) & 1) == 0) {
        fVar74 = 0.0;
        uVar49 = 0;
      }
      else {
        uVar49 = 0xfffffff8;
        fVar74 = DAT_140b7a23c;
      }
      goto LAB_140328b88;
    }
  }
  else if (param_6 == 0) {
    uVar49 = 8;
    fVar74 = DAT_140b79ed0;
LAB_140328b88:
    (**(code **)(*DAT_140c65670 + 0x188))(DAT_140c65670,uVar49,fVar74);
  }
  if (local_398 == (longlong *)0x0) {
LAB_140328c08:
    bVar60 = 0;
    if (local_430 == 0) {
      iVar34 = (**(code **)(*plVar47 + 0x118))(plVar47);
      bVar60 = -(iVar34 != 0) & 0x40;
    }
    if ((local_398 == (longlong *)0x0) ||
       ((uint)(0.0 < *(float *)((longlong)local_398 + 0x694)) -
        (uint)(*(float *)((longlong)local_398 + 0x694) < 0.0) !=
        (uint)(0.0 < *(float *)((longlong)plVar47 + 0x694)) -
        (uint)(*(float *)((longlong)plVar47 + 0x694) < 0.0))) {
      bVar60 = bVar60 | (&DAT_140b62cb1)
                        [(ulonglong)(0.0 < *(float *)((longlong)plVar47 + 0x694)) -
                         (ulonglong)(*(float *)((longlong)plVar47 + 0x694) < 0.0)];
    }
    (**(code **)(*DAT_140c65688 + 0x108))(DAT_140c65688,bVar60,0x78);
  }
  else {
    iVar34 = (**(code **)(*local_398 + 0x118))();
    iVar35 = (**(code **)(*local_400 + 0x118))(local_400);
    plVar47 = local_400;
    if ((iVar34 != iVar35) ||
       ((uint)(0.0 < *(float *)((longlong)local_398 + 0x694)) -
        (uint)(*(float *)((longlong)local_398 + 0x694) < 0.0) !=
        (uint)(0.0 < *(float *)((longlong)local_400 + 0x694)) -
        (uint)(*(float *)((longlong)local_400 + 0x694) < 0.0))) goto LAB_140328c08;
  }
  piVar56 = local_3c0;
  if (*piVar67 != 0) {
    if (*piVar67 != 1) {
      local_3a8 = local_420;
      local_3f0 = local_420;
      goto LAB_14032a409;
    }
    if (local_3c0 == (int *)0x0) {
      local_478 = (undefined *)((ulonglong)local_478._4_4_ << 0x20);
      puVar39 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x80,0);
      if (puVar39 != (undefined4 *)0x0) {
        lVar41 = *(longlong *)(local_428 + 0x10);
        uVar49 = *(undefined4 *)(lVar41 + 0x594);
        uVar89 = *(undefined4 *)(lVar41 + 0x598);
        uVar88 = *(undefined4 *)(lVar41 + 0x59c);
        uVar90 = *(undefined4 *)(lVar41 + 0x5b0);
        uVar13 = *(undefined4 *)(lVar41 + 0x5b4);
        uVar14 = *(undefined4 *)(lVar41 + 0x5b8);
        uVar15 = *(undefined4 *)(lVar41 + 0x5bc);
        uVar16 = *(undefined4 *)(lVar41 + 0x5a8);
        uVar17 = *(undefined4 *)(lVar41 + 0x5ac);
        uVar18 = *(undefined4 *)(lVar41 + 0x5c8);
        uVar19 = *(undefined4 *)(lVar41 + 0x5cc);
        uVar20 = *(undefined4 *)(lVar41 + 0x5a0);
        uVar21 = *(undefined4 *)(lVar41 + 0x5a4);
        uVar22 = *(undefined4 *)(lVar41 + 0x5c0);
        uVar23 = *(undefined4 *)(lVar41 + 0x5c4);
        *puVar39 = *(undefined4 *)(lVar41 + 0x590);
        puVar39[1] = uVar20;
        puVar39[2] = uVar90;
        puVar39[3] = uVar22;
        puVar39[4] = uVar49;
        puVar39[5] = uVar21;
        puVar39[6] = uVar13;
        puVar39[7] = uVar23;
        puVar39[8] = uVar89;
        puVar39[9] = uVar16;
        puVar39[10] = uVar14;
        puVar39[0xb] = uVar18;
        puVar39[0xc] = uVar88;
        puVar39[0xd] = uVar17;
        puVar39[0xe] = uVar15;
        puVar39[0xf] = uVar19;
        FUN_140262750(*(longlong *)(local_428 + 0x10) + 0x230,puVar39 + 0x10,
                      *(longlong *)(local_428 + 0x10) + 0xf0);
        puVar39[0x1c] = *(undefined4 *)(*(longlong *)(local_428 + 0x10) + 0x510);
        (**(code **)(*DAT_140c65670 + 0x108))();
      }
    }
    piVar56 = local_3c0;
    local_3a8 = 1;
    local_3f0 = 10;
    if ((local_3c0 == (int *)0x0) || (*(int *)(local_3b8 + 0x54) != *(int *)(param_6 + 0x54))) {
      (**(code **)(*DAT_140c65670 + 0x140))
                (DAT_140c65670,*(undefined8 *)(lVar63 + 0x808),*(undefined4 *)(local_3b8 + 0x54));
    }
    lVar41 = local_428;
    if (piVar56 == (int *)0x0) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      lVar55 = (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xb0,0,0);
      lVar41 = local_428;
      if (lVar55 != 0) {
        FUN_140262d50(*(longlong *)(local_428 + 0x10) + 0x230);
        lVar66 = *(longlong *)(lVar41 + 0x10);
        uVar44 = *(undefined8 *)(lVar66 + 0x2e8);
        *(undefined8 *)(lVar55 + 0x70) = *(undefined8 *)(lVar66 + 0x2e0);
        *(undefined8 *)(lVar55 + 0x78) = uVar44;
        *(undefined4 *)(lVar55 + 0x80) = *(undefined4 *)(lVar66 + 0x2c0);
        *(undefined4 *)(lVar55 + 0x84) = *(undefined4 *)(lVar66 + 0x2c4);
        *(undefined4 *)(lVar55 + 0x88) = *(undefined4 *)(lVar66 + 0x2c8);
        *(undefined4 *)(lVar55 + 0x8c) = *(undefined4 *)(lVar66 + 0x4e4);
        *(undefined4 *)(lVar55 + 0x90) = *(undefined4 *)(lVar66 + 0x2d0);
        *(undefined4 *)(lVar55 + 0x94) = *(undefined4 *)(lVar66 + 0x2d4);
        *(undefined4 *)(lVar55 + 0x98) = *(undefined4 *)(lVar66 + 0x2d8);
        *(undefined4 *)(lVar55 + 0x9c) = *(undefined4 *)(lVar66 + 0x4e0);
        *(undefined8 *)(lVar55 + 0xa0) = *(undefined8 *)(*(longlong *)(lVar41 + 0x10) + 0x550);
        lVar66 = *(longlong *)(lVar41 + 0x10);
        local_3e8 = (undefined4 *)
                    CONCAT44(*(float *)(lVar66 + 0x554) * _UNK_140b7ac54,
                             *(float *)(lVar66 + 0x550) * _DAT_140b7ac50);
        uStack_3e0 = CONCAT44(*(float *)(lVar66 + 0x55c) * _UNK_140b7ac5c,
                              *(float *)(lVar66 + 0x558) * _UNK_140b7ac58);
        *(undefined4 **)(lVar55 + 0xa8) = local_3e8;
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
    if (iVar36 < 3) {
LAB_14032a046:
      local_2a0[4] = *(undefined8 *)(*(longlong *)(lVar41 + 0x10) + 0x578);
    }
    else if (iVar36 < 5) {
      local_2a0[4] = *(undefined8 *)(lVar63 + 0x878);
    }
    else if (iVar36 == 5) {
      local_2a0[4] = *(undefined8 *)(lVar63 + 0x880);
    }
    else {
      if (iVar36 != 6) goto LAB_14032a046;
      local_2a0[4] = *(undefined8 *)(lVar63 + 0x888);
    }
    uVar68 = 0;
    alStack_160[4] = 0;
    local_1a0[4] = 0;
    if ((piVar56 == (int *)0x0) || (iVar36 != local_408)) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,1,0xb);
      fVar73 = DAT_140b79e48;
      if (pfVar46 != (float *)0x0) {
        if (iVar36 < 3) {
LAB_14032a123:
          *pfVar46 = DAT_140c79700;
          pfVar46[1] = DAT_140c79704;
          pfVar46[2] = DAT_140c79708;
          pfVar46[3] = 1.0;
        }
        else if (iVar36 < 5) {
          *pfVar46 = DAT_140c79700;
          pfVar46[1] = DAT_140c79704;
          pfVar46[2] = DAT_140c79708;
          pfVar46[3] = 0.0;
        }
        else if (iVar36 == 5) {
          *pfVar46 = DAT_140c79710;
          pfVar46[1] = DAT_140c79714;
          pfVar46[2] = DAT_140c79718;
          pfVar46[3] = 0.0;
        }
        else {
          if (iVar36 != 6) goto LAB_14032a123;
          *pfVar46 = DAT_140b79e48;
          pfVar46[1] = fVar73;
          pfVar46[2] = fVar73;
          pfVar46[3] = 0.0;
        }
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
    pfVar46 = local_360;
    lVar63 = local_3c8;
    iVar36 = local_3ec;
    puVar64 = *(ushort **)(piVar67 + 8);
    local_2a0[5] = *(undefined8 *)(*(longlong *)(lVar41 + 0x10) + 0x580);
    uVar54 = uVar54 | 0x185f;
    uVar50 = uVar50 | 0x185f;
    local_1a0[5] = 0;
    alStack_160[5] = 0;
    uVar53 = *(uint *)(local_350 + 0x1c0);
    puVar39 = local_1a0;
    plVar47 = local_2a0;
    puVar42 = local_1a0 + 2;
    plVar58 = local_2a0 + 2;
    do {
      uVar61 = 0x80 << ((byte)uVar68 & 0x1f);
      if (*puVar64 < uVar53) {
        plVar47[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)*puVar64 * 0x18);
        *puVar39 = 0;
      }
      else {
        *plVar47 = *(longlong *)(local_3c8 + 0x860);
        *puVar39 = 0;
        plVar47[0x28] = 0;
      }
      uVar48 = 0x80 << ((byte)uVar68 + 2 & 0x1f);
      uVar54 = uVar54 | uVar61 | uVar48;
      uVar50 = uVar50 | uVar61 | uVar48;
      if (puVar64[1] < uVar53) {
        plVar58[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)puVar64[1] * 0x18);
        *puVar42 = 0;
      }
      else {
        *plVar58 = *(longlong *)(local_3c8 + 0x868);
        *puVar42 = 0;
        plVar58[0x28] = 0;
      }
      uVar68 = uVar68 + 1;
      puVar42 = puVar42 + 1;
      plVar58 = plVar58 + 1;
      puVar64 = puVar64 + 0x94;
      puVar39 = puVar39 + 1;
      plVar47 = plVar47 + 1;
    } while (uVar68 < 2);
    local_258 = *(undefined8 *)(local_3c8 + 0x898);
    local_17c = 0;
    local_118 = 0;
    if (((local_360 != local_370) || (local_3ec != local_408)) ||
       (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0)) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      local_2e8 = uVar54;
      local_2e4 = uVar50;
      pfVar45 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,2,0xc);
      if (pfVar45 != (float *)0x0) {
        if (iVar36 - 5U < 2) {
          *pfVar45 = DAT_140c79710;
          pfVar45[1] = DAT_140c79714;
          pfVar45[2] = DAT_140c79718;
        }
        else {
          *pfVar45 = *pfVar46;
          pfVar45[1] = pfVar46[1];
          pfVar45[2] = pfVar46[2];
        }
        pfVar45[3] = pfVar46[8];
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
    local_2b0 = *(undefined8 *)(lVar63 + 0x810);
    uVar68 = uVar54 | 0x10020;
    uVar53 = uVar50 | 0x10020;
    local_2a8 = *(uint *)(local_3b8 + 0x58);
    local_42c = local_2c4._4_4_;
    local_440 = (uint)local_2c4;
    local_448 = local_2c8;
    local_450 = local_2cc;
    local_444 = local_2d0;
    local_458 = local_2d4;
    local_454 = local_2d8;
    local_44c = local_2dc;
    local_2e8 = uVar68;
    local_2e4 = uVar53;
    goto LAB_14032a409;
  }
  if (local_3c0 == (int *)0x0) {
    local_478 = (undefined *)((ulonglong)local_478._4_4_ << 0x20);
    puVar39 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x40,0);
    if (puVar39 != (undefined4 *)0x0) {
      lVar41 = *(longlong *)(local_428 + 0x10);
      uVar49 = *(undefined4 *)(lVar41 + 0x594);
      uVar89 = *(undefined4 *)(lVar41 + 0x598);
      uVar88 = *(undefined4 *)(lVar41 + 0x59c);
      uVar90 = *(undefined4 *)(lVar41 + 0x5b0);
      uVar13 = *(undefined4 *)(lVar41 + 0x5b4);
      uVar14 = *(undefined4 *)(lVar41 + 0x5b8);
      uVar15 = *(undefined4 *)(lVar41 + 0x5bc);
      uVar16 = *(undefined4 *)(lVar41 + 0x5a8);
      uVar17 = *(undefined4 *)(lVar41 + 0x5ac);
      uVar18 = *(undefined4 *)(lVar41 + 0x5c8);
      uVar19 = *(undefined4 *)(lVar41 + 0x5cc);
      uVar20 = *(undefined4 *)(lVar41 + 0x5a0);
      uVar21 = *(undefined4 *)(lVar41 + 0x5a4);
      uVar22 = *(undefined4 *)(lVar41 + 0x5c0);
      uVar23 = *(undefined4 *)(lVar41 + 0x5c4);
      *puVar39 = *(undefined4 *)(lVar41 + 0x590);
      puVar39[1] = uVar20;
      puVar39[2] = uVar90;
      puVar39[3] = uVar22;
      puVar39[4] = uVar49;
      puVar39[5] = uVar21;
      puVar39[6] = uVar13;
      puVar39[7] = uVar23;
      puVar39[8] = uVar89;
      puVar39[9] = uVar16;
      puVar39[10] = uVar14;
      puVar39[0xb] = uVar18;
      puVar39[0xc] = uVar88;
      puVar39[0xd] = uVar17;
      puVar39[0xe] = uVar15;
      puVar39[0xf] = uVar19;
      (**(code **)(*DAT_140c65670 + 0x108))();
    }
  }
  if (piVar56 == (int *)0x0) {
LAB_140328e30:
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    puVar39 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x80,1);
    if (puVar39 != (undefined4 *)0x0) {
      uVar61 = 0;
      lVar63 = 0;
      puVar64 = (ushort *)(local_418 + 0xc);
      do {
        uVar48 = 3;
        if (uVar61 < (uint)piVar67[6]) {
          uVar48 = *(uint *)(*(longlong *)(piVar67 + 8) + 0x120 + lVar63);
        }
        lVar41 = (ulonglong)uVar48 * 0x40;
        puVar42 = (undefined4 *)(&DAT_140c79e10 + lVar41);
        if (*puVar64 == 0xffff) {
          uVar49 = *puVar42;
          uVar89 = *(undefined4 *)(lVar41 + 0x140c79e14);
          auVar81 = *(undefined1 (*) [16])(&DAT_140c79e30 + lVar41);
          auVar83._0_8_ = auVar81._0_8_;
          uVar88 = *(undefined4 *)(&DAT_140c79e20 + lVar41);
          uVar90 = *(undefined4 *)(lVar41 + 0x140c79e24);
          auVar83._8_4_ = auVar81._4_4_;
          auVar83._12_4_ = auVar81._12_4_;
          auVar82._8_8_ = auVar83._8_8_;
          auVar82._0_4_ = auVar81._0_4_;
          auVar82._4_4_ = *(undefined4 *)(&DAT_140c79e40 + lVar41);
          auVar81._0_12_ = auVar82._0_12_;
          auVar81._12_4_ = *(undefined4 *)(lVar41 + 0x140c79e44);
        }
        else {
          uStack_3e0 = (ulonglong)*puVar64 * 0x110 + 0xd0 + plVar47[0x6a];
          local_3e8 = puVar42;
          local_d8 = puVar42;
          local_d0 = uStack_3e0;
          FUN_1401afb10(&local_d8,&local_328);
          auVar80._8_4_ = (int)((ulonglong)local_308 >> 0x20);
          auVar80._0_8_ = local_308;
          auVar80._12_4_ = (int)((ulonglong)uStack_300 >> 0x20);
          auVar79._8_8_ = auVar80._8_8_;
          auVar79._0_4_ = SUB84(local_308,0);
          auVar79._4_4_ = local_2f8;
          auVar81._0_12_ = auVar79._0_12_;
          auVar81._12_4_ = uStack_2f4;
          uVar49 = (undefined4)local_328;
          uVar88 = (undefined4)local_318;
          uVar89 = local_328._4_4_;
          uVar90 = local_318._4_4_;
        }
        uVar61 = uVar61 + 1;
        puVar64 = puVar64 + 1;
        lVar63 = lVar63 + 0x128;
        *puVar39 = uVar49;
        puVar39[1] = uVar88;
        puVar39[2] = auVar81._0_4_;
        puVar39[3] = auVar81._4_4_;
        puVar39[4] = uVar89;
        puVar39[5] = uVar90;
        puVar39[6] = auVar81._8_4_;
        puVar39[7] = auVar81._12_4_;
        puVar39 = puVar39 + 8;
      } while (uVar61 < 4);
      (**(code **)(*DAT_140c65670 + 0x108))();
      piVar56 = local_3c0;
      lVar63 = local_3c8;
    }
  }
  else {
    if (piVar67 != piVar56) {
      uVar61 = piVar67[6];
      uVar48 = piVar56[6];
      uVar69 = (ulonglong)uVar48;
      uVar37 = uVar61;
      if (uVar48 < uVar61) {
        uVar37 = uVar48;
      }
      uVar62 = 0;
      if (uVar37 != 0) {
        piVar51 = (int *)(*(longlong *)(piVar67 + 8) + 0x120);
        piVar57 = (int *)(*(longlong *)(piVar56 + 8) + 0x120);
        do {
          if (*piVar51 != *piVar57) goto LAB_140328e30;
          uVar62 = uVar62 + 1;
          piVar57 = piVar57 + 0x4a;
          piVar51 = piVar51 + 0x4a;
        } while (uVar62 < uVar37);
      }
      if (uVar48 < uVar61) {
        piVar51 = (int *)(uVar69 * 0x128 + 0x120 + *(longlong *)(piVar67 + 8));
        do {
          if (*piVar51 != 3) goto LAB_140328e30;
          uVar48 = (int)uVar69 + 1;
          uVar69 = (ulonglong)uVar48;
          piVar51 = piVar51 + 0x4a;
        } while (uVar48 < uVar61);
      }
    }
    if (plVar47 == local_398) {
      iVar36 = memcmp(local_418 + 0xc,(void *)(local_410 + 0x30),8);
      if (iVar36 != 0) goto LAB_140328e30;
    }
    else {
      uVar61 = 0;
      if (piVar67[6] != 0) {
        psVar40 = (short *)(local_418 + 0xc);
        do {
          if (*psVar40 != -1) goto LAB_140328e30;
          uVar61 = uVar61 + 1;
          psVar40 = psVar40 + 1;
        } while (uVar61 < (uint)piVar67[6]);
      }
      uVar61 = 0;
      if (piVar56[6] != 0) {
        psVar40 = (short *)(local_410 + 0x30);
        do {
          if (*psVar40 != -1) goto LAB_140328e30;
          uVar61 = uVar61 + 1;
          psVar40 = psVar40 + 1;
        } while (uVar61 < (uint)piVar56[6]);
      }
    }
  }
  local_3a8 = 2;
  local_3f0 = 0xe;
  if ((piVar56 == (int *)0x0) || (*(int *)(local_3b8 + 0x54) != *(int *)(param_6 + 0x54))) {
    (**(code **)(*DAT_140c65670 + 0x140))
              (DAT_140c65670,*(undefined8 *)(lVar63 + 0x7f8),*(undefined4 *)(local_3b8 + 0x54));
  }
  lVar63 = local_428;
  if (piVar56 == (int *)0x0) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    lVar41 = (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xd0,0);
    lVar63 = local_428;
    if (lVar41 != 0) {
      lVar55 = lVar41;
      FUN_140262d50(*(longlong *)(local_428 + 0x10) + 0x230,lVar41);
      FUN_140262750(*(longlong *)(lVar63 + 0x10) + 0x230,lVar55 + 0x70,
                    *(longlong *)(lVar63 + 0x10) + 0xf0);
      *(undefined8 *)(lVar41 + 0xa0) = 0;
      local_3e8 = (undefined4 *)
                  CONCAT44(*(float *)(*(longlong *)(lVar63 + 0x10) + 0x544) - _UNK_140b7b244,
                           *(float *)(*(longlong *)(lVar63 + 0x10) + 0x540) - _DAT_140b7b240);
      *(undefined4 **)(lVar41 + 0xa8) = local_3e8;
      *(undefined8 *)(lVar41 + 0xb0) = *(undefined8 *)(*(longlong *)(lVar63 + 0x10) + 0x550);
      lVar55 = *(longlong *)(lVar63 + 0x10);
      local_3e8 = (undefined4 *)
                  CONCAT44(*(float *)(lVar55 + 0x554) * _UNK_140b7ac54,
                           *(float *)(lVar55 + 0x550) * _DAT_140b7ac50);
      uStack_3e0 = CONCAT44(*(float *)(lVar55 + 0x55c) * _UNK_140b7ac5c,
                            *(float *)(lVar55 + 0x558) * _UNK_140b7ac58);
      *(undefined4 **)(lVar41 + 0xb8) = local_3e8;
      fVar74 = *(float *)(*(longlong *)(lVar63 + 0x10) + 0x1b0);
      fVar70 = *(float *)(*(longlong *)(lVar63 + 0x10) + 0x1b4);
      auVar3._4_4_ = fVar74 - fVar70;
      auVar3._0_4_ = fVar74 * fVar70;
      auVar3._8_4_ = fVar70;
      auVar3._12_4_ = 0;
      *(undefined1 (*) [16])(lVar41 + 0xc0) = auVar3;
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
  }
  iVar36 = local_430;
  if ((*(uint *)(*(longlong *)(lVar63 + 0x10) + 0x570) & 0x224) == 0) {
    if ((local_430 == 1) || (local_430 == 4)) {
      puVar43 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xc0))();
      uVar68 = uVar54 | 0x2005f;
      uVar53 = uVar50 | 0x2005f;
      local_250[0] = *puVar43;
      local_178[0] = 0;
      local_110[0] = 0;
      local_3f8 = uVar68;
      local_3f4 = uVar53;
    }
    if (iVar36 == 5) {
      lVar63 = (**(code **)(*DAT_140c65688 + 200))();
      local_260 = *(undefined8 *)(lVar63 + 0x20);
      local_180 = 0;
      local_120 = 0;
      lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
      uVar68 = uVar68 | 0x28000;
      uVar53 = uVar53 | 0x28000;
      local_250[0] = *(undefined8 *)(lVar63 + 0x38);
      local_178[0] = 0;
      local_110[0] = 0;
    }
    else if (iVar36 != 4) goto LAB_140329241;
    uVar44 = (**(code **)(*DAT_140c65688 + 0xd8))();
    lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
    uVar68 = uVar68 | 0x40000;
    uVar53 = uVar53 | 0x40000;
    local_250[1] = *(undefined8 *)(lVar63 + 0x48);
    local_178[1] = 0;
    local_3f8 = uVar68;
    local_3f4 = uVar53;
    local_110[1] = uVar44;
  }
LAB_140329241:
  lVar63 = local_3b0;
  if ((local_3b0 != local_390) || (local_3a0 != local_438)) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    local_3e8 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x1e0,1);
    piVar56 = local_378;
    lVar41 = local_3b0;
    auVar72._8_8_ = extraout_XMM0_Qb;
    auVar72._0_8_ = extraout_XMM0_Qa;
    if (local_3e8 != (undefined4 *)0x0) {
      local_438 = (float)piVar67[6];
      if (4 < (uint)piVar67[6]) {
        local_438 = (float)4;
      }
      uVar69 = (ulonglong)(uint)local_438;
      if (local_438 != 0.0) {
        lVar63 = 0;
        lVar55 = 0;
        puVar39 = local_3e8 + 0x20;
        pfVar46 = (float *)(local_3e8 + 100);
        fVar74 = DAT_140b79d04;
        do {
          local_328 = puVar39 + -0x20;
          puStack_320 = puVar39 + -0x10;
          lVar66 = *(longlong *)(lVar41 + 8) + lVar63;
          puStack_310 = puVar39 + 0x10;
          local_308 = puVar39 + 0x20;
          local_318 = puVar39;
          FUN_1403282e0(auVar72._0_8_,&local_328,*(longlong *)(piVar56 + 8) + lVar55,lVar66);
          uVar44 = *(undefined8 *)(lVar66 + 200);
          lVar55 = lVar55 + 0x128;
          lVar63 = lVar63 + 0xe0;
          *(undefined8 *)(puVar39 + 0x30) = *(undefined8 *)(lVar66 + 0xc0);
          *(undefined8 *)(puVar39 + 0x32) = uVar44;
          fVar70 = *(float *)(lVar66 + 100);
          if (fVar70 <= 0.0) {
            fVar70 = 0.0;
          }
          pfVar46[-4] = fVar70;
          fVar70 = *(float *)(lVar66 + 0x78) + fVar74;
          auVar72 = ZEXT416((uint)fVar70);
          *pfVar46 = fVar70;
          pfVar46[4] = *(float *)(lVar66 + 0x8c);
          pfVar46[8] = *(float *)(lVar66 + 0xa0);
          uVar69 = uVar69 - 1;
          puVar39 = puVar39 + 4;
          pfVar46 = pfVar46 + 1;
        } while (uVar69 != 0);
        uVar69 = (ulonglong)(uint)local_438;
        lVar63 = local_3b0;
        piVar67 = local_378;
        uVar68 = local_3f8;
        uVar53 = local_3f4;
      }
      if ((uint)uVar69 < 4) {
        puVar43 = (undefined8 *)(local_3e8 + (uVar69 + 8) * 4);
        uVar52 = (ulonglong)(4 - (uint)uVar69);
        puVar39 = local_3e8 + uVar69 + 100;
        do {
          puVar43[-0x10] = 0;
          puVar43[-0xf] = 0;
          puVar43[-8] = 0;
          puVar43[-7] = 0;
          *puVar43 = 0;
          puVar43[1] = 0;
          puVar43[8] = 0;
          puVar43[9] = 0;
          puVar43[0x10] = 0;
          puVar43[0x11] = 0;
          puVar43[0x18] = 0;
          puVar43[0x19] = 0;
          puVar39[-4] = 0;
          *puVar39 = 0;
          puVar39[4] = 0;
          puVar39[8] = 0;
          puVar43 = puVar43 + 2;
          uVar52 = uVar52 - 1;
          puVar39 = puVar39 + 1;
        } while (uVar52 != 0);
      }
      piVar56 = DAT_140c63750;
      bVar60 = *(byte *)(lVar63 + 0x59);
      uVar54 = (uint)bVar60;
      if (((uint)bVar60 < *(uint *)(local_3c8 + 0x8d0)) &&
         ((uint)local_3a0 < (uint)*(float *)(local_3c8 + 0x8d4))) {
        uVar54 = *(uint *)(*(longlong *)(local_3c8 + 0x8d8) +
                          (ulonglong)
                          ((uint)bVar60 * (int)*(float *)(local_3c8 + 0x8d4) + (int)local_3a0) * 4);
      }
      bVar60 = *(byte *)(lVar63 + 0x58);
      uVar50 = (uint)bVar60;
      if (((uint)bVar60 < *(uint *)(local_3c8 + 0x8d0)) &&
         ((uint)local_3a0 < (uint)*(float *)(local_3c8 + 0x8d4))) {
        uVar50 = *(uint *)(*(longlong *)(local_3c8 + 0x8d8) +
                          (ulonglong)
                          ((int)*(float *)(local_3c8 + 0x8d4) * (uint)bVar60 + (int)local_3a0) * 4);
      }
      fVar74 = *(float *)(*(longlong *)(local_3b8 + 0x30) + 0x35c);
      local_438 = (float)uVar50;
      if (0.0 <= fVar74) {
        local_438 = fVar74;
      }
      fVar74 = *(float *)(*(longlong *)(local_3b8 + 0x30) + 0x360);
      fStack_434 = (float)uVar54;
      if (0.0 <= fVar74) {
        fStack_434 = fVar74;
      }
      *(ulonglong *)(local_3e8 + 0x70) = CONCAT44(fStack_434,local_438);
      uVar69 = DAT_140c67498;
      if ((piVar67[1] & 0x2000U) != 0) {
        iVar36 = *piVar56;
        iVar34 = DAT_140c422a0;
        if (iVar36 < DAT_140c422a0) {
          iVar34 = iVar36;
        }
        if ((&DAT_140c422b0)[iVar34] != '\0') {
          fStack_434 = 0.0;
          iVar34 = DAT_140c422e0;
          if (iVar36 < DAT_140c422e0) {
            iVar34 = iVar36;
          }
          local_438 = *(float *)(&DAT_140c422f0 + (longlong)iVar34 * 4);
          uVar69 = (ulonglong)(uint)local_438;
        }
      }
      *(ulonglong *)(local_3e8 + 0x74) = uVar69;
      if ((piVar67[1] & 0x4000U) == 0) {
LAB_1403295a9:
        *(ulonglong *)(local_3e8 + 0x76) = DAT_140c67498;
        uVar69 = DAT_140c67498;
      }
      else {
        iVar36 = *piVar56;
        iVar34 = DAT_140c42340;
        if (iVar36 < DAT_140c42340) {
          iVar34 = iVar36;
        }
        if ((&DAT_140c42350)[iVar34] == '\0') goto LAB_1403295a9;
        iVar34 = DAT_140c42380;
        if (iVar36 < DAT_140c42380) {
          iVar34 = iVar36;
        }
        fStack_434 = 0.0;
        *(ulonglong *)(local_3e8 + 0x76) =
             (ulonglong)*(uint *)(&DAT_140c42390 + (longlong)iVar34 * 4);
        iVar36 = DAT_140c423e0;
        if (*piVar56 < DAT_140c423e0) {
          iVar36 = *piVar56;
        }
        local_438 = *(float *)(&DAT_140c423f0 + (longlong)iVar36 * 4);
        uVar69 = (ulonglong)(uint)local_438;
      }
      *(ulonglong *)(local_3e8 + 0x72) = uVar69;
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
  }
  pfVar46 = local_360;
  iVar36 = local_3ec;
  puVar39 = local_418;
  fVar70 = DAT_140b79e48;
  fVar74 = DAT_140b79d20;
  if ((((local_3ec != local_408) || (local_360 != local_370)) || (lVar63 != local_390)) ||
     (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0)) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    pfVar45 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xb0,2);
    if (pfVar45 != (float *)0x0) {
      if (iVar36 < 3) {
LAB_1403296c2:
        *pfVar45 = DAT_140c79700;
        pfVar45[1] = DAT_140c79704;
        pfVar45[2] = DAT_140c79708;
        pfVar45[3] = 1.0;
      }
      else if (iVar36 < 5) {
        *pfVar45 = DAT_140c79700;
        pfVar45[1] = DAT_140c79704;
        pfVar45[2] = DAT_140c79708;
        pfVar45[3] = 0.0;
      }
      else if (iVar36 == 5) {
        *pfVar45 = DAT_140c79710;
        pfVar45[1] = DAT_140c79714;
        pfVar45[2] = DAT_140c79718;
        pfVar45[3] = 0.0;
      }
      else {
        if (iVar36 != 6) goto LAB_1403296c2;
        *pfVar45 = fVar70;
        pfVar45[1] = fVar70;
        pfVar45[2] = fVar70;
        pfVar45[3] = 0.0;
      }
      fVar77 = DAT_140b79ec8;
      if (iVar36 == 0) {
        if ((pfVar46[8] <= DAT_140b79ec8 && DAT_140b79ec8 != pfVar46[8]) ||
           ((fVar71 = fVar73, (*(byte *)(puVar39 + 0xe) & 1) != 0 &&
            ((*(byte *)(*(longlong *)(local_428 + 0x10) + 0x570) & 4) == 0)))) {
          fVar71 = 0.0;
        }
        pfVar45[4] = fVar71;
        fVar71 = fVar74;
        if (fVar77 < pfVar46[8] || fVar77 == pfVar46[8]) {
          fVar71 = 0.0;
        }
        pfVar45[5] = fVar71;
      }
      else if (iVar36 == 1) {
        pfVar45[4] = 1.0;
        pfVar45[5] = 0.5;
      }
      else {
        pfVar45[4] = 0.0;
        pfVar45[5] = 0.003921569;
      }
      pfVar45[6] = pfVar46[9];
      pfVar45[7] = pfVar46[10];
      pfVar45[8] = (float)((uint)~piVar67[1] >> 0xf & 1);
      pfVar45[9] = 0.0;
      pfVar45[10] = 0.0;
      pfVar45[0xb] = 0.0;
      if (iVar36 - 3U < 4) {
        uVar44 = 0;
        uVar75 = 0;
        pfVar45[0xc] = 0.0;
        pfVar45[0xd] = 0.0;
        pfVar45[0xe] = 0.0;
        pfVar45[0xf] = 0.0;
        pfVar45[0x10] = 0.0;
        pfVar45[0x11] = 0.0;
        pfVar45[0x12] = 0.0;
        pfVar45[0x13] = 0.0;
      }
      else {
        uVar44 = *(undefined8 *)(pfVar46 + 6);
        *(undefined8 *)(pfVar45 + 0xc) = *(undefined8 *)(pfVar46 + 4);
        *(undefined8 *)(pfVar45 + 0xe) = uVar44;
        uVar44 = *(undefined8 *)(lVar63 + 0x38);
        *(undefined8 *)(pfVar45 + 0x10) = *(undefined8 *)(lVar63 + 0x30);
        *(undefined8 *)(pfVar45 + 0x12) = uVar44;
        uVar44 = *(undefined8 *)(lVar63 + 0x40);
        uVar75 = *(undefined8 *)(lVar63 + 0x48);
      }
      *(undefined8 *)(pfVar45 + 0x14) = uVar44;
      *(undefined8 *)(pfVar45 + 0x16) = uVar75;
      if (iVar36 - 5U < 2) {
        uVar44 = CONCAT44(_UNK_140b7b244,_DAT_140b7b240);
        uVar75 = CONCAT44(_UNK_140b7b24c,DAT_140b7b248);
        *(undefined8 *)(pfVar45 + 0x18) = uVar44;
        *(undefined8 *)(pfVar45 + 0x1a) = uVar75;
        *(undefined8 *)(pfVar45 + 0x1c) = uVar44;
        *(undefined8 *)(pfVar45 + 0x1e) = uVar75;
      }
      else {
        fVar77 = *(float *)(lVar63 + 0x14);
        fVar71 = *(float *)(lVar63 + 0x18);
        fVar24 = *(float *)(lVar63 + 0x1c);
        fVar91 = pfVar46[1];
        fVar25 = pfVar46[2];
        fVar26 = pfVar46[3];
        pfVar45[0x18] = *(float *)(lVar63 + 0x10) * *pfVar46;
        pfVar45[0x19] = fVar77 * fVar91;
        pfVar45[0x1a] = fVar71 * fVar25;
        pfVar45[0x1b] = fVar24 * fVar26;
        fVar77 = *(float *)(lVar63 + 0x24);
        fVar71 = *(float *)(lVar63 + 0x28);
        fVar24 = *(float *)(lVar63 + 0x2c);
        fVar91 = pfVar46[1];
        fVar25 = pfVar46[2];
        fVar26 = pfVar46[3];
        pfVar45[0x1c] = *(float *)(lVar63 + 0x20) * *pfVar46;
        pfVar45[0x1d] = fVar77 * fVar91;
        pfVar45[0x1e] = fVar71 * fVar25;
        pfVar45[0x1f] = fVar24 * fVar26;
      }
      if (local_3a4 == 1) {
        auVar2._12_4_ = 0;
        auVar2._0_12_ = *(undefined1 (*) [12])(puVar39 + 0x18);
        *(undefined1 (*) [16])(pfVar45 + 0x20) = auVar2;
      }
      else {
        pfVar45[0x20] = 0.0;
        pfVar45[0x21] = 0.0;
        pfVar45[0x22] = 0.0;
        pfVar45[0x23] = 0.0;
      }
      fVar91 = fVar73 / (pfVar46[0x13] + DAT_140b79cc4);
      fVar77 = pfVar46[0x11];
      fVar71 = pfVar46[0x12];
      fVar24 = pfVar46[0x13];
      pfVar45[0x24] = pfVar46[0x10] * fVar91;
      pfVar45[0x25] = fVar77 * fVar91;
      pfVar45[0x26] = fVar71 * fVar91;
      pfVar45[0x27] = fVar24 * fVar73;
      *(undefined1 (*) [16])(pfVar45 + 0x28) = ZEXT416((uint)(pfVar46[0x14] + DAT_140b79cc4));
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
  }
  uVar54 = piVar67[6];
  uVar50 = 0;
  if (uVar54 != 0) {
    puVar39 = local_1a0;
    plVar47 = local_2a0;
    uVar61 = *(uint *)(local_350 + 0x1c0);
    puVar42 = local_1a0 + 4;
    puVar64 = *(ushort **)(local_378 + 8);
    plVar58 = local_2a0 + 4;
    do {
      uVar48 = 0x80 << ((byte)uVar50 & 0x1f);
      if (*puVar64 < uVar61) {
        plVar47[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)*puVar64 * 0x18);
        *puVar39 = 0;
      }
      else {
        *plVar47 = *(longlong *)(local_3c8 + 0x860);
        *puVar39 = 0;
        plVar47[0x28] = 0;
      }
      uVar37 = 0x80 << ((byte)uVar50 + 4 & 0x1f);
      uVar68 = uVar68 | uVar48 | uVar37;
      uVar53 = uVar53 | uVar48 | uVar37;
      if (puVar64[1] < uVar61) {
        plVar58[0x10] = *(longlong *)(local_400[0x84] + 0x10 + (ulonglong)puVar64[1] * 0x18);
        *puVar42 = 0;
      }
      else {
        *plVar58 = *(longlong *)(local_3c8 + 0x868);
        *puVar42 = 0;
        plVar58[0x28] = 0;
      }
      uVar50 = uVar50 + 1;
      puVar42 = puVar42 + 1;
      plVar58 = plVar58 + 1;
      puVar64 = puVar64 + 0x94;
      puVar39 = puVar39 + 1;
      plVar47 = plVar47 + 1;
    } while (uVar50 < uVar54);
    local_42c = local_2c4._4_4_;
    local_440 = (uint)local_2c4;
    local_448 = local_2c8;
    local_450 = local_2cc;
    local_444 = local_2d0;
    local_458 = local_2d4;
    local_454 = local_2d8;
    local_44c = local_2dc;
    local_2e8 = uVar68;
    local_2e4 = uVar53;
  }
  if (local_3a4 == 1) {
    lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
    local_258 = *(undefined8 *)(lVar63 + 0x50);
  }
  else {
    local_258 = *(undefined8 *)(local_3c8 + 0x898);
  }
  uVar50 = uVar68 | 0x10000;
  uVar54 = uVar53 | 0x10000;
  local_118 = 0;
  local_17c = 0;
  if (local_380 != (longlong *)0x0) {
    lVar63 = local_380[1];
    lVar41 = *local_380;
    local_178[2] = 0;
    if ((uint)*(ushort *)(lVar41 + 4) < *(uint *)(*(longlong *)(lVar63 + 0x40) + 0x1c0)) {
      local_1d0[2] = *(undefined8 *)
                      (*(longlong *)(lVar63 + 0x420) + 0x10 +
                      (ulonglong)*(ushort *)(lVar41 + 4) * 0x18);
    }
    else {
      local_250[2] = 0;
      local_110[2] = 0;
    }
    uVar76 = *(ushort *)(lVar41 + 10);
    lVar55 = *(longlong *)(lVar63 + 0x420);
    uVar50 = uVar68 | 0x190000;
    uVar54 = uVar53 | 0x190000;
    local_178[3] = 0;
    local_1d0[3] = *(undefined8 *)(lVar55 + 0x10 + (ulonglong)uVar76 * 0x18);
    if (local_380 != local_368) {
      local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
      pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x40,3);
      if (pfVar46 != (float *)0x0) {
        fVar77 = fVar73;
        if ((*(ushort *)(lVar41 + 0x12) & 2) == 0) {
          fVar77 = 0.0;
        }
        if ((*(ushort *)(lVar41 + 0x12) & 1) == 0) {
          fVar74 = 0.0;
        }
        *pfVar46 = *(float *)(local_380 + 4) * DAT_140b79f58;
        pfVar46[1] = fVar74;
        pfVar46[2] = fVar77;
        plVar47 = *(longlong **)(lVar55 + 0x10 + (ulonglong)uVar76 * 0x18);
        if ((plVar47 == (longlong *)0x0) ||
           (plVar47 = (longlong *)(**(code **)(*plVar47 + 0x38))(), plVar47 == (longlong *)0x0)) {
          pfVar46[3] = 0.0;
        }
        else {
          uVar76 = *(ushort *)((longlong)local_380 + 0x34);
          lVar55 = (**(code **)(*plVar47 + 0x18))(plVar47);
          pfVar46[3] = ((float)uVar76 + fVar70) / (float)*(uint *)(lVar55 + 8);
        }
        local_3e8 = (undefined4 *)
                    CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x5d),
                             (float)(int)*(char *)((longlong)local_380 + 0x5c));
        uStack_3e0 = CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x5f),
                              (float)(int)*(char *)((longlong)local_380 + 0x5e));
        *(undefined4 **)(pfVar46 + 4) = local_3e8;
        *(longlong *)(pfVar46 + 6) = uStack_3e0;
        local_3e8 = (undefined4 *)
                    CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x71),
                             (float)(int)(char)local_380[0xe]);
        uStack_3e0 = CONCAT44((float)(int)*(char *)((longlong)local_380 + 0x73),
                              (float)(int)*(char *)((longlong)local_380 + 0x72));
        *(undefined4 **)(pfVar46 + 8) = local_3e8;
        *(longlong *)(pfVar46 + 10) = uStack_3e0;
        if (*(short *)(lVar41 + 6) == 2) {
          uVar49 = (undefined4)local_380[9];
          auVar78._0_8_ = CONCAT44(uVar49,uVar49);
          auVar78._8_4_ = uVar49;
          auVar84._12_4_ = uVar49;
          auVar84._0_12_ = auVar78;
          uVar87 = (undefined1)((uint)uVar49 >> 0x18);
          auVar4[0xd] = 0;
          auVar4._0_13_ = auVar84._0_13_;
          auVar4[0xe] = uVar87;
          uVar86 = (undefined1)((uint)uVar49 >> 0x10);
          auVar6[0xc] = uVar86;
          auVar6._0_12_ = auVar78;
          auVar6._13_2_ = auVar4._13_2_;
          auVar7[0xb] = 0;
          auVar7._0_11_ = auVar78._0_11_;
          auVar7._12_3_ = auVar6._12_3_;
          uVar85 = (undefined1)((uint)uVar49 >> 8);
          auVar8[10] = uVar85;
          auVar8._0_10_ = auVar78._0_10_;
          auVar8._11_4_ = auVar7._11_4_;
          auVar9[9] = 0;
          auVar9._0_9_ = auVar78._0_9_;
          auVar9._10_5_ = auVar8._10_5_;
          auVar10[8] = (byte)uVar49;
          auVar10._0_8_ = auVar78._0_8_;
          auVar10._9_6_ = auVar9._9_6_;
          auVar27._7_8_ = 0;
          auVar27._0_7_ = auVar10._8_7_;
          Var28 = CONCAT81(SUB158(auVar27 << 0x40,7),uVar87);
          auVar32._9_6_ = 0;
          auVar32._0_9_ = Var28;
          auVar11[4] = uVar86;
          auVar11._0_4_ = uVar49;
          auVar11._5_10_ = SUB1510(auVar32 << 0x30,5);
          auVar29._11_4_ = 0;
          auVar29._0_11_ = auVar11._4_11_;
          auVar30._1_12_ = SUB1512(auVar29 << 0x20,3);
          auVar30[0] = uVar85;
          uVar76 = CONCAT11(0,(byte)uVar49);
          auVar12._2_13_ = auVar30;
          auVar12._0_2_ = uVar76;
          auVar5._10_2_ = 0;
          auVar5._0_10_ = auVar12._0_10_;
          auVar5._12_2_ = (short)Var28;
          uVar33 = CONCAT42(auVar5._10_4_,auVar11._4_2_);
          auVar31._6_8_ = 0;
          auVar31._0_6_ = uVar33;
          fVar73 = _UNK_140b7b274 *
                   (float)(int)CONCAT82(SUB148(auVar31 << 0x40,6),auVar30._0_2_) * _UNK_140b7ab74;
          fVar74 = _UNK_140b7b278 * (float)uVar76 * _UNK_140b7ab78;
          fVar70 = _UNK_140b7b27c * (float)(auVar5._10_4_ >> 0x10) * _UNK_140b7ab7c;
          pfVar46[0xc] = _DAT_140b7b270 * (float)(int)uVar33 * _DAT_140b7ab70;
          pfVar46[0xd] = fVar73;
          pfVar46[0xe] = fVar74;
          pfVar46[0xf] = fVar70;
        }
        else if (*(short *)(lVar41 + 6) == 3) {
          lVar63 = *(longlong *)
                    ((ulonglong)*(ushort *)(lVar41 + 0xe) * 0x60 + 8 + *(longlong *)(lVar63 + 0x450)
                    );
          fVar74 = *(float *)(lVar63 + 0xc4);
          fVar70 = *(float *)(lVar63 + 200);
          pfVar46[0xc] = *(float *)(lVar63 + 0xc0);
          pfVar46[0xd] = fVar74;
          pfVar46[0xe] = fVar70;
          pfVar46[0xf] = fVar73;
        }
        (**(code **)(*DAT_140c65670 + 0x118))();
      }
    }
  }
  if (local_3b0 != local_390) {
    local_478 = (undefined *)0x0;
    (**(code **)(*DAT_140c65670 + 0x160))();
  }
  local_2a8 = *(uint *)(local_3b8 + 0x58);
  if (local_430 == 5) {
    if (0.0 < *(float *)(*(longlong *)(local_428 + 0x10) + 0x524)) {
      if ((local_420 & 2) == 0) {
        local_2a8 = local_2a8 + 0xb400;
      }
      else {
        local_2a8 = local_2a8 + 0xc600;
      }
    }
    else if ((local_420 & 1) == 0) {
      local_2a8 = local_2a8 + 0xa200;
    }
    else {
      local_2a8 = local_2a8 + 0x9000;
    }
  }
  else if ((local_430 == 1) && ((*(uint *)(*(longlong *)(local_428 + 0x10) + 0x570) & 0x200) != 0))
  {
    local_2a8 = local_2a8 +
                (0xc - ((int)((ulonglong)local_2a8 / 0x1200) +
                       (int)(((ulonglong)local_2a8 / 0x1200) / 0xd) * -0xd)) * 0x1200;
  }
  if (*(longlong *)(local_3b0 + 0x50) != 0) {
    local_2a8 = local_2a8 + 1;
  }
  uVar68 = uVar50 | 0x20;
  uVar53 = uVar54 | 0x20;
  local_2b0 = *(undefined8 *)(local_3c8 + 0x800);
  lVar63 = local_3c8;
  local_2e8 = uVar68;
  local_2e4 = uVar53;
LAB_14032a409:
  uVar54 = local_2a8;
  uVar52 = local_358;
  uVar69 = local_388;
  local_410 = local_2b0;
  if ((local_358 != local_388) || (local_400[0x8f] != local_398[0x8f])) {
    (**(code **)(*DAT_140c65670 + 0x138))();
  }
  if (uVar52 != uVar69) {
    (**(code **)(*DAT_140c65670 + 0x130))
              (DAT_140c65670,*(undefined8 *)(uVar52 + 0xa0),*(undefined4 *)(uVar52 + 0xa8),0);
  }
  if (local_3c0 == (int *)0x0) {
    (**(code **)(*DAT_140c65670 + 0x130))
              (DAT_140c65670,*(undefined8 *)(lVar63 + 0x8a8),*(undefined4 *)(uVar52 + 0xa8),1);
  }
  lVar63 = (**(code **)(*DAT_140c65670 + 0x2c8))();
  iVar36 = *(int *)(lVar63 + 0x30) - local_3f0;
  local_438 = (float)((uint)*(ushort *)((longlong)local_418 + 0x12) * 2 + 1 +
                     (uint)*(ushort *)((longlong)local_418 + 0x12));
  local_358 = (ulonglong)(iVar36 - 1) / (ulonglong)(uint)local_438;
  local_388 = 0;
  if (param_5 != 0) {
    local_420 = iVar36 * 0x10;
    puVar39 = local_418;
    do {
      plVar47 = local_338;
      uVar69 = local_388;
      fVar73 = local_438;
      local_478 = (undefined *)CONCAT44(local_478._4_4_,local_420);
      uVar52 = param_5 - local_388;
      if (local_358 < param_5 - local_388) {
        uVar52 = local_358;
      }
      iVar36 = (int)uVar52;
      pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x100))
                                   (DAT_140c65670,(iVar36 * (int)local_438 + 1) * 0x10,local_3a8,
                                    local_3f0);
      if (pfVar46 != (float *)0x0) {
        pfVar45 = pfVar46 + 4;
        uVar65 = 0;
        fVar73 = (float)(uint)fVar73;
        *pfVar46 = fVar73;
        pfVar46[1] = fVar73;
        pfVar46[2] = fVar73;
        pfVar46[3] = fVar73;
        if (uVar52 != 0) {
          do {
            lVar63 = plVar47[uVar69 + uVar65];
            lVar41 = *(longlong *)(lVar63 + 0x38);
            fVar73 = *(float *)(lVar41 + 0x3c);
            fVar74 = *(float *)(lVar41 + 0x38);
            fVar70 = *(float *)(lVar41 + 0x2c);
            *pfVar45 = *(float *)(lVar41 + 0x20);
            pfVar45[1] = fVar70;
            pfVar45[2] = fVar74;
            pfVar45[3] = fVar73;
            puVar43 = (undefined8 *)
                      ((ulonglong)*(ushort *)(puVar39 + 4) * 0x30 +
                      *(longlong *)(*(longlong *)(lVar63 + 0x30) + 0x340));
            iVar34 = (uint)*(ushort *)((longlong)puVar39 + 0x12) +
                     (uint)*(ushort *)((longlong)puVar39 + 0x12) * 2;
            if (iVar34 != 0) {
              lVar63 = (longlong)iVar34;
              puVar59 = puVar43;
              do {
                uVar44 = *puVar59;
                uVar75 = puVar59[1];
                puVar59 = puVar59 + 2;
                puVar1 = (undefined8 *)(((longlong)pfVar45 - (longlong)puVar43) + (longlong)puVar59)
                ;
                *puVar1 = uVar44;
                puVar1[1] = uVar75;
                lVar63 = lVar63 + -1;
              } while (lVar63 != 0);
            }
            uVar65 = uVar65 + 1;
            pfVar45 = pfVar45 + (longlong)iVar34 * 4 + 4;
          } while (uVar65 < uVar52);
        }
        (**(code **)(*DAT_140c65670 + 0x108))();
      }
      lVar63 = local_410;
      if (((local_430 == 0) && ((*(byte *)(*(longlong *)(local_428 + 0x10) + 0x570) & 1) != 0)) &&
         (local_3a4 == 1)) {
        (**(code **)(*DAT_140c65670 + 0x1f8))();
        (**(code **)(*DAT_140c65670 + 0x200))();
        lVar63 = (**(code **)(*DAT_140c65688 + 0xc0))();
        uStack_3e0 = *(longlong *)(lVar63 + 0x50);
        local_3e8 = (undefined4 *)CONCAT44(local_3e8._4_4_,1);
        local_3d4 = 0;
        local_478 = &DAT_140c3fe88;
        (**(code **)(*DAT_140c65670 + 0x208))
                  (DAT_140c65670,&local_3e8,&DAT_140c3fe88,&DAT_140c3fe88);
        (**(code **)(*DAT_140c65670 + 0x210))(DAT_140c65670,&DAT_140c3fe88,0);
        (**(code **)(*DAT_140c65670 + 0x1c0))(DAT_140c65670,1);
        (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,0);
        (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,1,3);
        (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,2);
        (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,7);
        uVar50 = 0;
        puVar39 = local_1a0;
        plVar47 = local_220;
        do {
          if ((uVar68 & 0x80 << ((byte)uVar50 & 0x1f)) != 0) {
            if (*plVar47 == 0) {
              if (plVar47[-0x10] != 0) {
                local_478 = (undefined *)plVar47[0x18];
                (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,uVar50,plVar47[-0x10],*puVar39);
              }
            }
            else {
              (**(code **)(*DAT_140c65670 + 0x168))(DAT_140c65670,uVar50,*plVar47,*puVar39);
            }
          }
          uVar50 = uVar50 + 1;
          plVar47 = plVar47 + 1;
          puVar39 = puVar39 + 1;
        } while (uVar50 < 9);
        local_478 = (undefined *)0x0;
        (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,9,0);
        uVar50 = 10;
        puVar39 = local_178;
        plVar47 = local_1d0;
        do {
          if ((uVar68 & 0x80 << ((byte)uVar50 & 0x1f)) != 0) {
            if (*plVar47 == 0) {
              if (plVar47[-0x10] != 0) {
                local_478 = (undefined *)plVar47[0x18];
                (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,uVar50,plVar47[-0x10],*puVar39);
              }
            }
            else {
              (**(code **)(*DAT_140c65670 + 0x168))(DAT_140c65670,uVar50,*plVar47,*puVar39);
            }
          }
          lVar63 = local_410;
          uVar50 = uVar50 + 1;
          plVar47 = plVar47 + 1;
          puVar39 = puVar39 + 1;
        } while (uVar50 < 0x10);
        (**(code **)(*DAT_140c65670 + 0x178))
                  (DAT_140c65670,local_410,uVar54 + ((uVar54 / 0x1200) % 0xd) * -0x1200);
        puVar39 = local_418;
        local_470 = local_418[3];
        local_468 = 0;
        local_478 = (undefined *)CONCAT44(local_478._4_4_,local_418[1]);
        local_460 = iVar36;
        (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,*local_418,local_418[2]);
        (**(code **)(*DAT_140c65670 + 0x2a0))();
        (**(code **)(*DAT_140c65670 + 0x228))();
        (**(code **)(*DAT_140c65670 + 0x220))();
        uVar53 = uVar53 | 0x1003f;
        local_2e4 = uVar53;
      }
      if (uVar53 != 0) {
        if ((uVar53 & 1) != 0) {
          (**(code **)(*DAT_140c65670 + 0x1c0))(DAT_140c65670,local_440);
        }
        if ((uVar53 & 4) != 0) {
          (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,local_2e0);
        }
        if ((uVar53 & 8) != 0) {
          local_468 = local_448;
          local_470 = local_450;
          local_478 = (undefined *)CONCAT44(local_478._4_4_,local_444);
          (**(code **)(*DAT_140c65670 + 0x1c8))(DAT_140c65670,local_44c,local_454,local_458);
        }
        if ((uVar53 & 0x10) != 0) {
          (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,local_2bc);
        }
        if ((uVar53 & 2) != 0) {
          (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,local_42c);
        }
        if ((uVar53 & 0x40) != 0) {
          (**(code **)(*DAT_140c65670 + 0x1a0))(DAT_140c65670,local_2b8,0);
        }
        if ((uVar53 & 0x20) != 0) {
          (**(code **)(*DAT_140c65670 + 0x178))(DAT_140c65670,lVar63,uVar54);
        }
        if ((uVar53 & 0x7fff80) != 0) {
          uVar50 = 0;
          puVar39 = local_1a0;
          plVar47 = local_220;
          do {
            if ((uVar53 & 0x80 << ((byte)uVar50 & 0x1f)) != 0) {
              if (*plVar47 == 0) {
                if (plVar47[-0x10] != 0) {
                  local_478 = (undefined *)plVar47[0x18];
                  (**(code **)(*DAT_140c65670 + 0x160))
                            (DAT_140c65670,uVar50,plVar47[-0x10],*puVar39);
                }
              }
              else {
                (**(code **)(*DAT_140c65670 + 0x168))(DAT_140c65670,uVar50,*plVar47,*puVar39);
              }
            }
            uVar50 = uVar50 + 1;
            plVar47 = plVar47 + 1;
            puVar39 = puVar39 + 1;
          } while (uVar50 < 0x10);
        }
        uVar53 = 0;
        local_2e4 = 0;
        puVar39 = local_418;
      }
      local_470 = puVar39[3];
      local_468 = 0;
      local_478 = (undefined *)CONCAT44(local_478._4_4_,puVar39[1]);
      local_460 = iVar36;
      (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,*puVar39,puVar39[2]);
      local_388 = local_388 + uVar52;
    } while (local_388 < param_5);
  }
  return 0;
}



==== FUN_14032c620 @ 14032c620 size 917 ====
CALLERS:
CALLEES: __security_check_cookie FUN_1401afb10 FUN_140312840

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_14032c620(longlong param_1,undefined8 param_2,undefined4 param_3,longlong *param_4,
             undefined8 param_5,longlong param_6)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  ushort *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined *puVar9;
  longlong lVar10;
  undefined1 auStack_148 [32];
  longlong local_128;
  longlong local_120;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined1 local_d8 [64];
  longlong local_98;
  longlong local_90;
  ulonglong local_48;
  
  local_48 = DAT_140c0f7b0 ^ (ulonglong)auStack_148;
  lVar10 = *param_4;
  if (param_6 == 0) {
    FUN_140312840(*(undefined8 *)(param_1 + 0x10));
    uVar4 = 0;
    local_128 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))
              (DAT_140c65670,5,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x578),0);
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x570) & 0x224) == 0) {
      lVar3 = (**(code **)(*DAT_140c65688 + 0xc0))();
      local_128 = 0;
      (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,6,*(undefined8 *)(lVar3 + 0x38),0);
      lVar3 = (**(code **)(*DAT_140c65688 + 200))();
      local_128 = 0;
      (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,7,*(undefined8 *)(lVar3 + 0x18),0);
      lVar3 = (**(code **)(*DAT_140c65688 + 200))();
      local_128 = 0;
      (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,9,*(undefined8 *)(lVar3 + 0x20),0);
      uVar4 = (**(code **)(*DAT_140c65688 + 0xd8))();
      lVar3 = (**(code **)(*DAT_140c65688 + 0xc0))();
      uVar8 = *(undefined8 *)(lVar3 + 0x48);
    }
    else {
      local_128 = 0;
      (**(code **)(*DAT_140c65670 + 0x160))
                (DAT_140c65670,6,
                 *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) + 0x890));
      uVar8 = *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) + 0x890);
    }
    local_128 = uVar4;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0xb,uVar8);
    (**(code **)(*DAT_140c65670 + 0x188))(DAT_140c65670,0,0);
  }
  plVar2 = *(longlong **)(lVar10 + 0x40);
  lVar3 = *(longlong *)(lVar10 + 0x30);
  puVar5 = (ushort *)(**(code **)(*plVar2 + 0x20))(plVar2);
  iVar1 = *(int *)(puVar5 + 4);
  lVar6 = (ulonglong)*puVar5 * 0x40 + *(longlong *)(lVar3 + 0x338);
  local_f0 = param_3;
  if (iVar1 == 0) {
    lVar3 = *(longlong *)(param_1 + 0x10);
    local_e0 = lVar3 + 0x130;
    local_e8 = lVar6;
    local_98 = lVar6;
    local_90 = local_e0;
    FUN_1401afb10(&local_98,local_d8);
    local_f8 = *(undefined8 *)(lVar10 + 0x38);
    local_100 = *(undefined4 *)(lVar3 + 0x570);
    local_108 = lVar3 + 0x160;
    local_110 = lVar3 + 0x230;
    local_118 = lVar3 + 0x1b0;
    local_120 = lVar3 + 0x590;
    local_128 = lVar6;
    (**(code **)(*plVar2 + 0x38))(plVar2,lVar6,local_d8,lVar3 + 0xf0);
  }
  else {
    if (iVar1 == 1) {
      local_120 = *(longlong *)(param_1 + 0x10);
      local_f8 = *(undefined8 *)(lVar10 + 0x38);
      lVar7 = *plVar2;
      local_100 = *(undefined4 *)(local_120 + 0x570);
      local_128 = lVar3 + 0x4f0;
      lVar10 = local_120 + 0xf0;
      puVar9 = (undefined *)(lVar3 + 0x50);
    }
    else {
      if (iVar1 != 2) {
        return 0;
      }
      local_120 = *(longlong *)(param_1 + 0x10);
      local_f8 = *(undefined8 *)(lVar10 + 0x38);
      lVar7 = *plVar2;
      local_100 = *(undefined4 *)(local_120 + 0x570);
      lVar10 = local_120 + 0xf0;
      puVar9 = &DAT_140c78390;
      local_128 = lVar10;
    }
    local_108 = local_120 + 0x160;
    local_110 = local_120 + 0x230;
    local_118 = local_120 + 0x1b0;
    local_120 = local_120 + 0x590;
    (**(code **)(lVar7 + 0x38))(plVar2,lVar6,puVar9,lVar10);
  }
  return 0;
}



==== FUN_140389c40 @ 140389c40 size 494 ====
CALLERS: FUN_140382e90 FUN_140382f90 FUN_14037c2e0 FUN_1403830c0 FUN_140383610 FUN_140383410 FUN_140383310 FUN_140367870
CALLEES: FUN_1400b6120 GetCurrentThreadId CreateEventW SetEvent CloseHandle FUN_14019fb60

void FUN_140389c40(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  DWORD DVar4;
  HANDLE hObject;
  ulonglong uVar5;
  longlong *plVar6;
  bool bVar7;
  
  lVar2 = *param_1;
  DVar4 = GetCurrentThreadId();
  uVar5 = 0;
  if (*(DWORD *)(lVar2 + 0x50) == DVar4) {
    *(longlong *)(lVar2 + 0x58) = *(longlong *)(lVar2 + 0x58) + 1;
  }
  else {
    do {
      LOCK();
      bVar7 = *(longlong *)(lVar2 + 0x58) == 0;
      if (bVar7) {
        *(longlong *)(lVar2 + 0x58) = 1;
      }
      UNLOCK();
      if (bVar7) {
        *(DWORD *)(lVar2 + 0x50) = DVar4;
        goto LAB_140389c9f;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x400);
    FUN_14019fb60(lVar2 + 0x50,DVar4);
  }
LAB_140389c9f:
  lVar3 = param_1[0xae];
  while (lVar3 != 0) {
    if (*(longlong *)(*param_1 + 0x17d0) == lVar3) {
      *(undefined8 *)(*param_1 + 0x17d0) = *(undefined8 *)(lVar3 + 0x110);
    }
    lVar3 = param_1[0xae];
    if (*(undefined8 **)(lVar3 + 0x108) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar3 + 0x108) = *(undefined8 *)(lVar3 + 0x110);
    }
    if (*(longlong *)(lVar3 + 0x110) != 0) {
      *(undefined8 *)(*(longlong *)(lVar3 + 0x110) + 0x108) = *(undefined8 *)(lVar3 + 0x108);
    }
    *(undefined8 *)(lVar3 + 0x108) = 0;
    *(undefined8 *)(lVar3 + 0x110) = 0;
    lVar3 = param_1[0xae];
    plVar6 = (longlong *)(*param_1 + 0x17e8);
    if (*(longlong *)(lVar3 + 0x108) == 0) {
      *(longlong **)(lVar3 + 0x108) = plVar6;
      plVar1 = (longlong *)(lVar3 + 0x110);
      *plVar1 = *plVar6;
      *plVar6 = lVar3;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 0x108) = plVar1;
      }
    }
    FUN_1400b6120(*param_1 + 0x17f0,param_1[0xae]);
    lVar3 = param_1[0xae];
    if (*(undefined8 **)(lVar3 + 0x118) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar3 + 0x118) = *(undefined8 *)(lVar3 + 0x120);
    }
    if (*(longlong *)(lVar3 + 0x120) != 0) {
      *(undefined8 *)(*(longlong *)(lVar3 + 0x120) + 0x118) = *(undefined8 *)(lVar3 + 0x118);
    }
    *(undefined8 *)(lVar3 + 0x118) = 0;
    *(undefined8 *)(lVar3 + 0x120) = 0;
    lVar3 = param_1[0xae];
  }
  if (1 < *(ulonglong *)(lVar2 + 0x58)) {
    *(longlong *)(lVar2 + 0x58) = *(longlong *)(lVar2 + 0x58) + -1;
    return;
  }
  *(undefined4 *)(lVar2 + 0x50) = 0;
  LOCK();
  *(undefined8 *)(lVar2 + 0x58) = 0;
  UNLOCK();
  if (*(longlong *)(lVar2 + 0x60) != 0) {
    if (*(longlong *)(lVar2 + 0x68) == 0) {
      hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      LOCK();
      bVar7 = *(longlong *)(lVar2 + 0x68) == 0;
      if (bVar7) {
        *(longlong *)(lVar2 + 0x68) = (longlong)hObject;
      }
      UNLOCK();
      if (!bVar7) {
        CloseHandle(hObject);
      }
    }
    SetEvent(*(HANDLE *)(lVar2 + 0x68));
  }
  return;
}



==== FUN_14031ee60 @ 14031ee60 size 9467 ====
CALLERS:
CALLEES: memcpy FUN_14031ea00 FUN_1408fde98 FUN_140318540 FUN_14031e170 FUN_1401afb10 FUN_1401afc20 FUN_1408fccb0 FUN_14031e6b0 FUN_14031e520 FUN_1408fc950 FUN_14031def0 FUN_14032fe20 FUN_1401adf30 FUN_140318840 FUN_1408fe3d0 FUN_140318930 FUN_14031e5e0 FUN_14031ec20 __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14031ee60(longlong *param_1,longlong *param_2,undefined1 param_3 [8],float *param_4)

{
  float *pfVar1;
  float *pfVar2;
  char cVar3;
  short sVar4;
  ushort uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  bool bVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  float fVar16;
  undefined8 uVar17;
  float fVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  float *pfVar22;
  longlong lVar23;
  undefined8 *puVar24;
  uint uVar25;
  ulonglong uVar26;
  undefined4 *puVar27;
  float fVar28;
  longlong lVar29;
  undefined4 *puVar30;
  undefined4 *puVar31;
  uint uVar32;
  int iVar33;
  char *pcVar34;
  undefined4 *puVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  uint uVar39;
  float fVar40;
  float extraout_XMM0_Da;
  undefined8 extraout_XMM0_Qa;
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined8 extraout_XMM0_Qb;
  float fVar48;
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  float fVar59;
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  float fVar69;
  float fVar70;
  float fVar71;
  float fVar72;
  float fVar73;
  float fVar74;
  float fVar75;
  float fVar76;
  float fVar77;
  float fVar78;
  float fVar79;
  float fVar80;
  float fVar81;
  float fVar82;
  float fVar83;
  undefined1 auVar84 [16];
  float fVar85;
  float fVar86;
  undefined1 auStack_408 [32];
  undefined8 local_3e8;
  float local_3e0;
  undefined4 local_3d8;
  float local_3c8;
  undefined8 local_3b8;
  undefined8 uStack_3b0;
  undefined1 local_3a8 [8];
  undefined8 uStack_3a0;
  float local_398 [4];
  undefined8 local_388;
  float fStack_380;
  float fStack_37c;
  float local_378 [4];
  undefined4 local_368;
  undefined4 uStack_364;
  undefined4 uStack_360;
  undefined4 uStack_35c;
  undefined4 local_348;
  undefined4 uStack_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  undefined4 local_338;
  undefined4 uStack_334;
  undefined4 uStack_330;
  undefined4 uStack_32c;
  longlong local_328;
  float *local_320;
  undefined4 *local_2d8 [2];
  undefined4 local_2c8;
  float fStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined4 local_2b8;
  float fStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined4 local_2a8;
  float fStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 local_298;
  float fStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined1 local_288 [32];
  float local_268;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  float local_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float local_168 [4];
  float local_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float local_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float local_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float local_128 [4];
  float local_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float local_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float local_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  ulonglong local_e8;
  undefined1 auVar58 [16];
  
  local_e8 = DAT_140c0f7b0 ^ (ulonglong)auStack_408;
  local_1a8 = *param_2;
  uStack_1a0 = param_2[1];
  local_198 = param_2[2];
  uStack_190 = param_2[3];
  puVar35 = (undefined4 *)0x0;
  local_3a8 = param_3;
  local_188 = param_2[4];
  uStack_180 = param_2[5];
  local_178 = *(float *)(param_2 + 6);
  fStack_174 = *(float *)((longlong)param_2 + 0x34);
  fStack_170 = *(float *)(param_2 + 7);
  fStack_16c = *(float *)((longlong)param_2 + 0x3c);
  uVar25 = 0;
  fVar85 = fStack_174;
  if ((*(int *)(param_1[1] + 0x28) != 0) && (*(int *)(param_1[1] + 8) == 2)) {
    plVar6 = *(longlong **)(*(longlong *)(param_1[5] + 0x10) + 0x1e8);
    fVar85 = 0.0;
    if (plVar6 != (longlong *)0x0) {
      local_3e8 = (float *)0x0;
      local_3b8 = CONCAT44(fStack_174 + fRam0000000140c77874,local_178 + _DAT_140c77870);
      uStack_3b0 = (float *)CONCAT44(fStack_16c + fRam0000000140c7787c,
                                     fStack_170 + fRam0000000140c77878);
      iVar19 = (**(code **)(*plVar6 + 0x1b8))(plVar6,&local_3b8,local_288,1);
      if (iVar19 != 0) {
        fVar85 = local_268;
      }
    }
  }
  fStack_174 = fVar85;
  FUN_14031ec20(param_1);
  FUN_14032fe20(param_1,&local_1a8,param_3,param_4);
  lVar23 = param_1[0xa7];
  lVar29 = param_1[5];
  uVar39 = *(uint *)(*(longlong *)(lVar29 + 0x10) + 0xd0);
  *(int *)((longlong)param_1 + 0x53c) = (int)lVar23;
  iVar19 = *(int *)(*(longlong *)(lVar29 + 0x10) + 0xd0);
  *(int *)(param_1 + 0xa7) = iVar19;
  fVar85 = DAT_140b79d04;
  fVar28 = (float)(iVar19 - (int)lVar23);
  fVar82 = fVar28;
  if (((*(byte *)(param_1[0x9d] + 0x28) & 0x10) != 0) && (fVar82 = 1.4013e-43, (uint)fVar28 < 100))
  {
    fVar82 = fVar28;
  }
  fVar86 = (float)(uint)fVar82;
  fVar28 = fVar86 * DAT_140b79d04;
  local_3c8 = fVar82;
  if (((*(char *)(param_1[0x9d] + 4) == '\x04') && (*(longlong *)(lVar29 + 0x4c0) != 0)) &&
     (param_1[2] != *(longlong *)(lVar29 + 0x4c0))) {
    FUN_14031def0(param_1);
  }
  fVar36 = (float)(**(code **)(*(longlong *)param_1[5] + 0x58))();
  fVar18 = DAT_140b79ed0;
  *(float *)((longlong)param_1 + 0x5cc) = fVar36 / (fVar28 * *(float *)(param_1[0x9d] + 0x3a8));
  fVar36 = *(float *)(param_1 + 0x34);
  fVar37 = *(float *)((longlong)param_1 + 0x1a4);
  fVar38 = *(float *)(param_1 + 0x35);
  fVar83 = param_4[5];
  fVar69 = param_4[6];
  fVar71 = param_4[7];
  fVar72 = param_4[1];
  fVar74 = param_4[2];
  fVar76 = param_4[3];
  fVar78 = param_4[9];
  fVar79 = param_4[10];
  fVar80 = param_4[0xb];
  *(float *)(param_1 + 0xc2) = fVar37 * param_4[4] + fVar36 * *param_4 + fVar38 * param_4[8];
  *(float *)((longlong)param_1 + 0x614) = fVar37 * fVar83 + fVar36 * fVar72 + fVar38 * fVar78;
  *(float *)(param_1 + 0xc3) = fVar37 * fVar69 + fVar36 * fVar74 + fVar38 * fVar79;
  *(float *)((longlong)param_1 + 0x61c) = fVar37 * fVar71 + fVar36 * fVar76 + fVar38 * fVar80;
  lVar29 = param_1[0x9d];
  if (*(char *)(lVar29 + 0x430) != '\0') {
    fVar36 = DAT_140b7a1c8;
    if (*(float *)(param_1 + 0x94) != 0.0) {
      fVar36 = fVar18 / *(float *)(param_1 + 0x94);
    }
    *(float *)(param_1 + 0xbe) = fVar36;
  }
  fVar37 = DAT_140b7a23c;
  fVar36 = DAT_140b7a1c0;
  if (*(ushort *)(lVar29 + 0x26) != 0) {
    fVar36 = fVar18 / (float)*(ushort *)(lVar29 + 0x26);
  }
  *(float *)((longlong)param_1 + 0x5f4) = fVar36;
  *(float *)((longlong)param_1 + 0x574) =
       fVar28 * *(float *)(lVar29 + 0x3bc) + *(float *)((longlong)param_1 + 0x574);
  fVar36 = fVar28 * *(float *)(lVar29 + 0x3c0) + *(float *)(param_1 + 0xaf);
  *(float *)(param_1 + 0xaf) = fVar36;
  if (fVar36 <= fVar18) {
    if (fVar37 <= fVar36) goto LAB_14031f14d;
    fVar36 = fVar36 + fVar18;
  }
  else {
    fVar36 = fVar36 - fVar18;
  }
  *(float *)(param_1 + 0xaf) = fVar36;
LAB_14031f14d:
  if ((*(uint *)(lVar29 + 0x28) & 0x200) != 0) {
    iVar19 = (int)param_1[0xb0];
    if ((uint)(*(int *)(lVar29 + 1000) + iVar19) < uVar39) {
      iVar33 = *(int *)((longlong)param_1 + 0x57c);
      do {
        iVar33 = iVar33 + 1;
        *(int *)((longlong)param_1 + 0x57c) = iVar33;
        iVar19 = iVar19 + *(int *)(lVar29 + 1000);
        *(int *)(param_1 + 0xb0) = iVar19;
      } while ((uint)(*(int *)(lVar29 + 1000) + iVar19) < uVar39);
    }
    uVar39 = *(uint *)(lVar29 + 0x3fc);
    uVar32 = *(uint *)((longlong)param_1 + 0x57c);
    if (uVar39 <= uVar32) {
      if ((*(uint *)(lVar29 + 0x28) & 0x400) == 0) {
        uVar20 = uVar39 - 1;
        if (uVar32 < uVar39 - 1) {
          uVar20 = uVar32;
        }
        *(uint *)((longlong)param_1 + 0x57c) = uVar20;
      }
      else if (uVar39 == 0) {
        *(undefined4 *)((longlong)param_1 + 0x57c) = 0;
      }
      else {
        *(uint *)((longlong)param_1 + 0x57c) = uVar32 % uVar39;
      }
    }
  }
  fVar36 = DAT_140b79e48;
  if (*(short *)(lVar29 + 0x404) == 2) {
    *(float *)(param_1 + 0xb8) = fVar28 * *(float *)(lVar29 + 0x408) + *(float *)(param_1 + 0xb8);
    *(float *)((longlong)param_1 + 0x5c4) =
         fVar28 * *(float *)(lVar29 + 0x40c) + *(float *)((longlong)param_1 + 0x5c4);
    *(float *)(param_1 + 0xb9) = fVar28 * *(float *)(lVar29 + 0x410) + *(float *)(param_1 + 0xb9);
    fVar83 = (*(float *)(param_1[0xb2] + 0xc) + *(float *)(param_1[0xb1] + 0xc)) * fVar36;
    fVar37 = (float)FUN_1408fe3d0();
    fVar38 = (float)FUN_1408fc950();
    *(float *)((longlong)param_1 + 0x5a4) = fVar37;
    *(float *)(param_1 + 0xb4) = fVar38;
    uVar39 = (uint)fVar37 ^ DAT_140b7b530;
    *(float *)((longlong)param_1 + 0x5b4) = fVar38;
    *(float *)(param_1 + 0xb5) =
         (fVar83 - (fVar38 * fVar83 + fVar37 * fVar36)) + *(float *)(param_1 + 0xb8);
    *(uint *)(param_1 + 0xb6) = uVar39;
    *(float *)(param_1 + 0xb7) =
         (fVar37 * fVar83 - fVar38 * fVar36) + fVar36 + *(float *)((longlong)param_1 + 0x5c4);
    fVar37 = DAT_140b7a23c;
  }
  puVar31 = puVar35;
  if (*(int *)(*(longlong *)(param_1[5] + 0x40) + 0x308) != 0) {
    do {
      lVar29 = param_1[5];
      lVar23 = *(longlong *)(*(longlong *)(lVar29 + 0x40) + 0x310);
      sVar4 = *(short *)(lVar23 + 2 + (longlong)puVar31 * 0x50);
      if (sVar4 == 0) {
        pfVar22 = (float *)((ulonglong)*(ushort *)(lVar23 + (longlong)puVar31 * 0x50) * 0x40 + 0x30
                           + *(longlong *)(lVar29 + 0x338));
        fVar38 = *pfVar22;
        fVar83 = pfVar22[1];
        fVar69 = pfVar22[2];
        fVar71 = *(float *)((longlong)param_3 + 0x14);
        fVar72 = *(float *)((longlong)param_3 + 0x18);
        fVar74 = *(float *)((longlong)param_3 + 0x1c);
        fVar76 = *(float *)((longlong)param_3 + 4);
        fVar78 = *(float *)((longlong)param_3 + 8);
        fVar79 = *(float *)((longlong)param_3 + 0xc);
        fVar80 = *(float *)((longlong)param_3 + 0x24);
        fVar73 = *(float *)((longlong)param_3 + 0x28);
        fVar75 = *(float *)((longlong)param_3 + 0x2c);
        fVar40 = *(float *)((longlong)param_3 + 0x34);
        fVar48 = *(float *)((longlong)param_3 + 0x38);
        fVar59 = *(float *)((longlong)param_3 + 0x3c);
        local_168[(longlong)puVar31 * 4] =
             fVar83 * *(float *)((longlong)param_3 + 0x10) + fVar38 * *(float *)param_3 +
             fVar69 * *(float *)((longlong)param_3 + 0x20) + *(float *)((longlong)param_3 + 0x30);
        local_168[(longlong)puVar31 * 4 + 1] =
             fVar83 * fVar71 + fVar38 * fVar76 + fVar69 * fVar80 + fVar40;
        local_168[(longlong)puVar31 * 4 + 2] =
             fVar83 * fVar72 + fVar38 * fVar78 + fVar69 * fVar73 + fVar48;
        local_168[(longlong)puVar31 * 4 + 3] =
             fVar83 * fVar74 + fVar38 * fVar79 + fVar69 * fVar75 + fVar59;
      }
      else if (sVar4 == 1) {
        local_3b8 = (ulonglong)*(ushort *)(lVar23 + (longlong)puVar31 * 0x50) * 0x40 +
                    *(longlong *)(lVar29 + 0x338);
        puVar27 = puVar31;
        uStack_3b0 = (float *)param_3;
        local_328 = local_3b8;
        local_320 = (float *)param_3;
        FUN_1401afb10(&local_328,&local_368);
        local_2d8[0] = &local_368;
        FUN_1401afc20(local_2d8,&local_2c8);
        local_368 = local_2c8;
        uStack_364 = local_2b8;
        uStack_360 = local_2a8;
        uStack_35c = local_298;
        local_128[(longlong)puVar31 * 4] = fStack_2c4;
        local_128[(longlong)puVar31 * 4 + 1] = fStack_2b4;
        local_128[(longlong)puVar31 * 4 + 2] = fStack_2a4;
        local_128[(longlong)puVar31 * 4 + 3] = fStack_294;
        local_348 = uStack_2c0;
        uStack_344 = uStack_2b0;
        uStack_340 = uStack_2a0;
        uStack_33c = uStack_290;
        local_338 = uStack_2bc;
        uStack_334 = uStack_2ac;
        uStack_330 = uStack_29c;
        uStack_32c = uStack_28c;
        puVar31 = puVar27;
      }
      uVar39 = (int)puVar31 + 1;
      puVar31 = (undefined4 *)(ulonglong)uVar39;
    } while (uVar39 < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x308));
  }
  plVar6 = param_1 + 0x60;
  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
  FUN_140318930(param_1[0x9d],plVar6,param_1 + 0x38,param_1[0xb1] + 0x20);
  if ((*(byte *)(param_1[0x9d] + 0x28) & 0x20) != 0) {
    local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
    FUN_140318930();
  }
  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x1b8);
  FUN_140318840(*(ushort *)(param_1[0x9d] + 0x1b8),param_1 + 0x74,param_1 + 0x6a,param_1[0xb1] + 4);
  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x2b0);
  FUN_140318840(*(ushort *)(param_1[0x9d] + 0x2b0),param_1 + 0x88,param_1 + 0x7e,param_1[0xb1] + 8);
  FUN_14031e5e0(param_1,param_1[0xb1]);
  if (*(short *)(param_1[1] + 0x68) != 0) {
    local_3e8._0_4_ = fVar28;
    FUN_14031e6b0(param_1,param_1[0xb1],local_168,local_128);
  }
  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
  FUN_140318930(param_1[0x9d],plVar6,param_1 + 0x38,param_1[0xb2] + 0x20);
  if ((*(byte *)(param_1[0x9d] + 0x28) & 0x20) != 0) {
    local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
    FUN_140318930();
  }
  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x1b8);
  FUN_140318840(*(ushort *)(param_1[0x9d] + 0x1b8),param_1 + 0x74,param_1 + 0x6a,param_1[0xb2] + 4);
  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x2b0);
  FUN_140318840(*(ushort *)(param_1[0x9d] + 0x2b0),param_1 + 0x88,param_1 + 0x7e,param_1[0xb2] + 8);
  FUN_14031e5e0(param_1,param_1[0xb2]);
  if (*(short *)(param_1[1] + 0x68) != 0) {
    local_3e8._0_4_ = fVar28;
    FUN_14031e6b0(param_1,param_1[0xb2],local_168,local_128);
  }
  if ((int)param_1[0xa6] != 0) {
    pcVar34 = (char *)param_1[0x9d];
    if (*pcVar34 == '\0') {
      lVar29 = param_1[0xb1];
      fVar38 = *(float *)(lVar29 + 8);
      fVar83 = fVar38 * fVar36 + *(float *)(param_1 + 0x98);
      fVar69 = (*(float *)(lVar29 + 0x70) - *(float *)(lVar29 + 0x50)) * fVar38 +
               *(float *)(lVar29 + 0x50);
      fVar71 = (*(float *)(lVar29 + 0x74) - *(float *)(lVar29 + 0x54)) * fVar38 +
               *(float *)(lVar29 + 0x54);
      fVar72 = (*(float *)(lVar29 + 0x78) - *(float *)(lVar29 + 0x58)) * fVar38 +
               *(float *)(lVar29 + 0x58);
      fVar74 = (*(float *)(lVar29 + 0x7c) - *(float *)(lVar29 + 0x5c)) * fVar38 +
               *(float *)(lVar29 + 0x5c);
      lVar29 = param_1[0xb2];
      fVar38 = *(float *)(lVar29 + 8);
      fVar76 = fVar38 * (*(float *)(lVar29 + 0x70) - *(float *)(lVar29 + 0x50)) +
               *(float *)(lVar29 + 0x50);
      fVar78 = fVar38 * (*(float *)(lVar29 + 0x74) - *(float *)(lVar29 + 0x54)) +
               *(float *)(lVar29 + 0x54);
      fVar79 = fVar38 * (*(float *)(lVar29 + 0x78) - *(float *)(lVar29 + 0x58)) +
               *(float *)(lVar29 + 0x58);
      fVar80 = fVar38 * (*(float *)(lVar29 + 0x7c) - *(float *)(lVar29 + 0x5c)) +
               *(float *)(lVar29 + 0x5c);
      *(float *)(param_1 + 0x1a) = fVar69 - fVar83;
      *(float *)((longlong)param_1 + 0xd4) = fVar71 - fVar83;
      *(float *)(param_1 + 0x1b) = fVar72 - fVar83;
      *(float *)((longlong)param_1 + 0xdc) = fVar74 - fVar83;
      *(float *)(param_1 + 0x1c) = fVar83 + fVar69;
      *(float *)((longlong)param_1 + 0xe4) = fVar83 + fVar71;
      *(float *)(param_1 + 0x1d) = fVar83 + fVar72;
      *(float *)((longlong)param_1 + 0xec) = fVar83 + fVar74;
      fVar38 = *(float *)(param_1[0xb2] + 8) * fVar36 + *(float *)(param_1 + 0x98);
      auVar41._0_4_ = fVar38 + fVar76;
      auVar41._4_4_ = fVar38 + fVar78;
      auVar41._8_4_ = fVar38 + fVar79;
      auVar41._12_4_ = fVar38 + fVar80;
      auVar49 = maxps(*(undefined1 (*) [16])(param_1 + 0x1c),auVar41);
      auVar13._4_4_ = fVar78 - fVar38;
      auVar13._0_4_ = fVar76 - fVar38;
      auVar13._8_4_ = fVar79 - fVar38;
      auVar13._12_4_ = fVar80 - fVar38;
      auVar42 = minps(*(undefined1 (*) [16])(param_1 + 0x1a),auVar13);
      *(undefined1 (*) [16])(param_1 + 0x1a) = auVar42;
      *(undefined1 (*) [16])(param_1 + 0x1c) = auVar49;
      if ((*(byte *)(param_1[0x9d] + 0x28) & 0x40) == 0) {
        *(int *)(param_1[0xb1] + 0x18) = *(int *)(param_1[0xb1] + 0x18) - (int)fVar82;
        *(int *)(param_1[0xb2] + 0x18) = *(int *)(param_1[0xb2] + 0x18) - (int)fVar82;
      }
      else {
        *(int *)(param_1[0xb1] + 0x18) =
             *(int *)(param_1[0xb1] + 0x18) -
             (int)(longlong)
                  ((*(float *)(param_1[0x9d] + 0x3ac) * *(float *)((longlong)param_1 + 0x5cc) +
                   fVar18) * fVar86);
        *(int *)(param_1[0xb2] + 0x18) =
             *(int *)(param_1[0xb2] + 0x18) -
             (int)(longlong)
                  ((*(float *)(param_1[0x9d] + 0x3b0) * *(float *)((longlong)param_1 + 0x5cc) +
                   fVar18) * fVar86);
      }
      FUN_14031ea00(param_1,param_1[0xb1]);
      FUN_14031ea00(param_1,param_1[0xb2]);
      local_378[0] = *(float *)(param_1 + 0xa5);
      fVar82 = *(float *)((longlong)param_1 + 0x52c);
      if ((uint)local_378[0] < (uint)fVar82) {
        uVar39 = 1;
        local_398[0] = fVar82;
      }
      else {
        uVar39 = 2;
        local_378[1] = 0.0;
        local_398[0] = *(float *)(param_1 + 0xa4);
        local_398[1] = fVar82;
      }
      fVar82 = *(float *)((ulonglong)(uint)((int)local_378[0] * *(int *)((longlong)param_1 + 0x524))
                          + param_1[0xa3] + 0xc);
      if ((fVar82 <= fVar18) && (bVar9 = fVar82 < fVar37, fVar37 = 0.0, bVar9)) {
        fVar37 = fVar18;
      }
      *(float *)(param_1[0xb1] + 0xc) = fVar37 + *(float *)(param_1[0xb1] + 0xc);
      *(float *)(param_1[0xb2] + 0xc) = fVar37 + *(float *)(param_1[0xb2] + 0xc);
      if (uVar39 != 0) {
        local_3b8 = (ulonglong)uVar39;
        local_388 = 0;
        puVar31 = puVar35;
        puVar27 = puVar35;
        do {
          uVar39 = *(uint *)((longlong)local_378 + local_388);
          puVar30 = puVar31;
          uVar32 = uVar39;
          if (uVar39 < *(uint *)((longlong)local_398 + local_388)) {
            do {
              uVar32 = uVar32 + 1;
              puVar31 = (undefined4 *)
                        ((ulonglong)(*(int *)((longlong)param_1 + 0x524) * uVar39) + param_1[0xa3]);
              puVar31[3] = fVar37 + (float)puVar31[3];
              fVar82 = (float)(int)((uint)*(ushort *)(param_1[0x9d] + 0x26) - puVar31[6]) /
                       (float)*(ushort *)(param_1[0x9d] + 0x26);
              FUN_14031ea00(param_1,puVar31);
              if (fVar82 < fVar18) {
                FUN_14031e5e0(param_1,puVar31);
                if ((*(char *)(param_1[0x9d] + 4) == '\0') && (puVar30 != (undefined4 *)0x0)) {
                  fVar38 = (float)puVar31[0x15];
                  fVar83 = (float)puVar31[0x16];
                  fVar69 = (float)puVar31[0x17];
                  fVar71 = (float)puVar30[0x14];
                  fVar72 = (float)puVar30[0x15];
                  fVar74 = (float)puVar30[0x16];
                  fVar76 = (float)puVar30[0x17];
                  puVar31[0x18] = (float)puVar31[0x14] - fVar71;
                  puVar31[0x19] = fVar38 - fVar72;
                  puVar31[0x1a] = fVar83 - fVar74;
                  puVar31[0x1b] = fVar69 - fVar76;
                  if ((int)puVar27 == 1) {
                    puVar30[0x18] = (float)puVar31[0x14] - fVar71;
                    puVar30[0x19] = fVar38 - fVar72;
                    puVar30[0x1a] = fVar83 - fVar74;
                    puVar30[0x1b] = fVar69 - fVar76;
                  }
                }
                if (*(short *)(param_1[1] + 0x68) != 0) {
                  local_3e8._0_4_ = fVar28;
                  FUN_14031e6b0(param_1);
                }
                local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
                FUN_140318930(*(ushort *)(param_1[0x9d] + 0x48),param_1 + 0x60,param_1 + 0x38,
                              puVar31 + 8);
                if ((*(byte *)(param_1[0x9d] + 0x28) & 0x20) != 0) {
                  local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
                  FUN_140318930();
                }
                local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x1b8);
                FUN_140318840(*(ushort *)(param_1[0x9d] + 0x1b8),param_1 + 0x74,param_1 + 0x6a,
                              puVar31 + 1);
                local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x2b0);
                FUN_140318840(*(ushort *)(param_1[0x9d] + 0x2b0),param_1 + 0x88,param_1 + 0x7e,
                              puVar31 + 2);
                fVar38 = (float)puVar31[2];
                fVar83 = fVar38 * fVar36 + *(float *)(param_1 + 0x98);
                fVar69 = ((float)puVar31[0x1c] - (float)puVar31[0x14]) * fVar38 +
                         (float)puVar31[0x14];
                fVar71 = ((float)puVar31[0x1d] - (float)puVar31[0x15]) * fVar38 +
                         (float)puVar31[0x15];
                fVar72 = ((float)puVar31[0x1e] - (float)puVar31[0x16]) * fVar38 +
                         (float)puVar31[0x16];
                fVar38 = ((float)puVar31[0x1f] - (float)puVar31[0x17]) * fVar38 +
                         (float)puVar31[0x17];
                auVar50._0_4_ = fVar83 + fVar69;
                auVar50._4_4_ = fVar83 + fVar71;
                auVar50._8_4_ = fVar83 + fVar72;
                auVar50._12_4_ = fVar83 + fVar38;
                auVar10._4_4_ = fVar71 - fVar83;
                auVar10._0_4_ = fVar69 - fVar83;
                auVar10._8_4_ = fVar72 - fVar83;
                auVar10._12_4_ = fVar38 - fVar83;
                auVar42 = minps(*(undefined1 (*) [16])(param_1 + 0x1a),auVar10);
                auVar49 = maxps(*(undefined1 (*) [16])(param_1 + 0x1c),auVar50);
                *(undefined1 (*) [16])(param_1 + 0x1a) = auVar42;
                *(undefined1 (*) [16])(param_1 + 0x1c) = auVar49;
              }
              else {
                puVar30 = (undefined4 *)param_1[0xb2];
                *puVar30 = *puVar31;
                uVar17 = *(undefined8 *)(puVar31 + 10);
                *(undefined8 *)(puVar30 + 8) = *(undefined8 *)(puVar31 + 8);
                *(undefined8 *)(puVar30 + 10) = uVar17;
                uVar17 = *(undefined8 *)(puVar31 + 0xe);
                *(undefined8 *)(puVar30 + 0xc) = *(undefined8 *)(puVar31 + 0xc);
                *(undefined8 *)(puVar30 + 0xe) = uVar17;
                puVar30[1] = puVar31[1];
                puVar30[2] = puVar31[2];
                puVar30[6] = puVar31[6];
                puVar30[5] = puVar31[5];
                puVar30[3] = puVar31[3];
                puVar30[4] = puVar31[4];
                uVar17 = *(undefined8 *)(puVar31 + 0x12);
                *(undefined8 *)(puVar30 + 0x10) = *(undefined8 *)(puVar31 + 0x10);
                *(undefined8 *)(puVar30 + 0x12) = uVar17;
                uVar17 = *(undefined8 *)(puVar31 + 0x16);
                *(undefined8 *)(puVar30 + 0x14) = *(undefined8 *)(puVar31 + 0x14);
                *(undefined8 *)(puVar30 + 0x16) = uVar17;
                uVar17 = *(undefined8 *)(puVar31 + 0x1a);
                *(undefined8 *)(puVar30 + 0x18) = *(undefined8 *)(puVar31 + 0x18);
                *(undefined8 *)(puVar30 + 0x1a) = uVar17;
                memcpy(puVar30 + 0x1c,puVar31 + 0x1c,
                       (ulonglong)*(uint *)((longlong)param_1 + 0x55c) << 4);
                if ((int)param_1[0xa6] != 0) {
                  uVar20 = uVar32;
                  if (uVar32 == *(uint *)(param_1 + 0xa4)) {
                    uVar20 = uVar25;
                  }
                  *(uint *)(param_1 + 0xa5) = uVar20;
                  *(int *)(param_1 + 0xa6) = (int)param_1[0xa6] + -1;
                }
              }
              lVar29 = param_1[0x9d];
              fVar38 = local_3c8;
              if ((*(byte *)(lVar29 + 0x28) & 0x40) != 0) {
                fVar38 = (float)(longlong)
                                ((((*(float *)(lVar29 + 0x3b0) - *(float *)(lVar29 + 0x3ac)) *
                                   fVar82 + *(float *)(lVar29 + 0x3ac)) *
                                  *(float *)((longlong)param_1 + 0x5cc) + fVar18) * fVar86);
              }
              puVar31[6] = puVar31[6] - (int)fVar38;
              uVar39 = uVar39 + 1;
              puVar27 = (undefined4 *)(ulonglong)((int)puVar27 + 1);
              puVar30 = puVar31;
            } while (uVar39 < *(uint *)((longlong)local_398 + local_388));
          }
          local_3b8 = local_3b8 - 1;
          local_388 = local_388 + 4;
        } while (local_3b8 != 0);
        local_3b8 = 0;
        param_3 = local_3a8;
      }
    }
    else {
      lVar29 = *(longlong *)(param_1[5] + 0x338);
      local_3b8 = (ulonglong)*(ushort *)(pcVar34 + 0x49c) * 0x40 + lVar29;
      uStack_3b0 = (float *)param_3;
      local_328 = local_3b8;
      local_320 = (float *)param_3;
      FUN_1401afb10(&local_328,local_168);
      local_3b8 = (ulonglong)*(ushort *)(pcVar34 + 0x49e) * 0x40 + lVar29;
      uStack_3b0 = (float *)param_3;
      local_328 = local_3b8;
      local_320 = (float *)param_3;
      FUN_1401afb10(&local_328,local_128);
      fVar71 = local_138 - local_f8;
      fVar72 = fStack_134 - fStack_f4;
      fVar74 = fStack_130 - fStack_f0;
      fVar76 = fStack_12c - fStack_ec;
      *(float *)(param_1 + 0xae) = SQRT(fVar71 * fVar71 + fVar72 * fVar72 + fVar74 * fVar74);
      fVar85 = (float)local_3a8._0_4_;
      fVar82 = (float)local_3a8._4_4_;
      fVar28 = (float)uStack_3a0;
      fVar86 = uStack_3a0._4_4_;
      fVar37 = (float)local_3a8._0_4_;
      fVar38 = (float)local_3a8._4_4_;
      fVar83 = (float)uStack_3a0;
      fVar69 = uStack_3a0._4_4_;
      if ((byte)(pcVar34[4] - 1U) < 3) {
        fVar86 = *(float *)(pcVar34 + 0x20);
        fVar37 = *(float *)(pcVar34 + 0x1c);
        fVar38 = *(float *)(pcVar34 + 0x18);
        fVar69 = *(float *)(pcVar34 + 0x1c);
        fVar78 = *(float *)(pcVar34 + 0x20);
        fVar79 = *(float *)(pcVar34 + 0x18);
        fVar85 = fVar37 * local_158 + fVar38 * local_168[0] + fVar86 * local_148 + local_138;
        fVar82 = fVar37 * fStack_154 + fVar38 * local_168[1] + fVar86 * fStack_144 + fStack_134;
        fVar28 = fVar37 * fStack_150 + fVar38 * local_168[2] + fVar86 * fStack_140 + fStack_130;
        fVar86 = fVar37 * fStack_14c + fVar38 * local_168[3] + fVar86 * fStack_13c + fStack_12c;
        fVar37 = fVar69 * local_118 + fVar79 * local_128[0] + fVar78 * local_108 + local_f8;
        fVar38 = fVar69 * fStack_114 + fVar79 * local_128[1] + fVar78 * fStack_104 + fStack_f4;
        fVar83 = fVar69 * fStack_110 + fVar79 * local_128[2] + fVar78 * fStack_100 + fStack_f0;
        fVar69 = fVar69 * fStack_10c + fVar79 * local_128[3] + fVar78 * fStack_fc + fStack_ec;
        puVar31 = puVar35;
        if (*(int *)((longlong)param_1 + 0x55c) != 0) {
          do {
            lVar29 = *(longlong *)(param_1[0x9d] + 0x10);
            uVar39 = (int)puVar31 + 1;
            fVar36 = *(float *)(lVar29 + 8 + (longlong)puVar31 * 0xc);
            fVar78 = *(float *)(lVar29 + 4 + (longlong)puVar31 * 0xc);
            fVar79 = *(float *)(lVar29 + (longlong)puVar31 * 0xc);
            pfVar22 = (float *)(param_1[0xba] + (longlong)puVar31 * 0x10);
            *pfVar22 = fVar78 * local_158 + fVar79 * local_168[0] + fVar36 * local_148 + local_138;
            pfVar22[1] = fVar78 * fStack_154 + fVar79 * local_168[1] + fVar36 * fStack_144 +
                         fStack_134;
            pfVar22[2] = fVar78 * fStack_150 + fVar79 * local_168[2] + fVar36 * fStack_140 +
                         fStack_130;
            pfVar22[3] = fVar78 * fStack_14c + fVar79 * local_168[3] + fVar36 * fStack_13c +
                         fStack_12c;
            lVar29 = *(longlong *)(param_1[0x9d] + 0x10);
            fVar36 = *(float *)(lVar29 + 8 + (longlong)puVar31 * 0xc);
            fVar78 = *(float *)(lVar29 + 4 + (longlong)puVar31 * 0xc);
            fVar79 = *(float *)(lVar29 + (longlong)puVar31 * 0xc);
            pfVar22 = (float *)(param_1[0xbc] + (longlong)puVar31 * 0x10);
            *pfVar22 = fVar78 * local_118 + fVar79 * local_128[0] + fVar36 * local_108 + local_f8;
            pfVar22[1] = fVar78 * fStack_114 + fVar79 * local_128[1] + fVar36 * fStack_104 +
                         fStack_f4;
            pfVar22[2] = fVar78 * fStack_110 + fVar79 * local_128[2] + fVar36 * fStack_100 +
                         fStack_f0;
            pfVar22[3] = fVar78 * fStack_10c + fVar79 * local_128[3] + fVar36 * fStack_fc +
                         fStack_ec;
            puVar31 = (undefined4 *)(ulonglong)uVar39;
            fVar36 = DAT_140b79e48;
          } while (uVar39 < *(uint *)((longlong)param_1 + 0x55c));
        }
      }
      lVar29 = param_1[0x9d];
      fVar78 = SQRT(fVar71 * fVar71 + fVar72 * fVar72 + fVar74 * fVar74);
      if ((*(short *)(lVar29 + 0x4a0) != 1) ||
         (fVar79 = (float)local_3a8._0_4_, fVar80 = (float)local_3a8._4_4_,
         fStack_380 = (float)uStack_3a0, fStack_37c = uStack_3a0._4_4_,
         *(short *)(lVar29 + 0x4a2) != 1)) {
        fVar79 = fVar72 * fVar72;
        auVar49._4_4_ = fVar79;
        auVar49._0_4_ = fVar79;
        auVar49._8_4_ = fVar79;
        auVar49._12_4_ = fVar79;
        fVar80 = fVar71 * fVar71 + fVar79 + fVar74 * fVar74;
        auVar42._4_4_ = fVar79;
        auVar42._0_4_ = fVar80;
        auVar42._8_4_ = fVar74 * fVar74;
        auVar42._12_4_ = fVar76 * fVar76;
        auVar42 = rsqrtss(auVar49,auVar42);
        fVar73 = auVar42._0_4_;
        fVar73 = (DAT_140b79fa0 - fVar80 * fVar73 * fVar73) * fVar36 * fVar73;
        if (fVar73 <= 0.0) {
          fVar73 = 0.0;
        }
        fVar79 = fVar73 * fVar71;
        fVar80 = fVar73 * fVar72;
        fStack_380 = fVar73 * fVar74;
        fStack_37c = fVar73 * fVar76;
      }
      local_3b8._0_4_ = fVar79;
      local_3b8._4_4_ = fVar80;
      uStack_3b0._0_4_ = fStack_380;
      uStack_3b0._4_4_ = fStack_37c;
      if (*(short *)(lVar29 + 0x4a0) == 1) {
        fVar71 = fStack_144 * fStack_144;
        auVar51._4_4_ = fVar71;
        auVar51._0_4_ = fVar71;
        auVar51._8_4_ = fVar71;
        auVar51._12_4_ = fVar71;
        fVar72 = local_148 * local_148 + fVar71 + fStack_140 * fStack_140;
        auVar11._4_4_ = fVar71;
        auVar11._0_4_ = fVar72;
        auVar11._8_4_ = fStack_140 * fStack_140;
        auVar11._12_4_ = fStack_13c * fStack_13c;
        auVar42 = rsqrtss(auVar51,auVar11);
        fVar71 = auVar42._0_4_;
        fVar71 = (DAT_140b79fa0 - fVar72 * fVar71 * fVar71) * fVar36 * fVar71;
        if (fVar71 <= 0.0) {
          fVar71 = 0.0;
        }
        uStack_3b0._0_4_ = fVar71 * fStack_140;
        uStack_3b0._4_4_ = fVar71 * fStack_13c;
        local_3b8._0_4_ = fVar71 * local_148;
        local_3b8._4_4_ = fVar71 * fStack_144;
      }
      if (*(short *)(lVar29 + 0x4a2) == 1) {
        fVar71 = fStack_104 * fStack_104;
        auVar52._4_4_ = fVar71;
        auVar52._0_4_ = fVar71;
        auVar52._8_4_ = fVar71;
        auVar52._12_4_ = fVar71;
        fVar72 = local_108 * local_108 + fVar71 + fStack_100 * fStack_100;
        auVar12._4_4_ = fVar71;
        auVar12._0_4_ = fVar72;
        auVar12._8_4_ = fStack_100 * fStack_100;
        auVar12._12_4_ = fStack_fc * fStack_fc;
        auVar42 = rsqrtss(auVar52,auVar12);
        fVar71 = auVar42._0_4_;
        fVar71 = (DAT_140b79fa0 - fVar72 * fVar71 * fVar71) * fVar36 * fVar71;
        if (fVar71 <= 0.0) {
          fVar71 = 0.0;
        }
        fStack_380 = fVar71 * fStack_100;
        fStack_37c = fVar71 * fStack_fc;
        local_388 = CONCAT44(fVar71 * fStack_104,fVar71 * local_108);
      }
      else {
        local_388 = CONCAT44(fVar80,fVar79);
      }
      fVar71 = *(float *)(lVar29 + 0x498);
      lVar29 = param_1[0xb1];
      *(float *)(lVar29 + 0x50) = local_138;
      *(float *)(lVar29 + 0x54) = fStack_134;
      *(float *)(lVar29 + 0x58) = fStack_130;
      *(float *)(lVar29 + 0x5c) = fStack_12c;
      lVar29 = param_1[0xb2];
      *(float *)(lVar29 + 0x50) = local_f8;
      *(float *)(lVar29 + 0x54) = fStack_f4;
      *(float *)(lVar29 + 0x58) = fStack_f0;
      *(float *)(lVar29 + 0x5c) = fStack_ec;
      lVar29 = param_1[0xb1];
      local_378[0] = (0.0 - (float)local_3b8) * fVar71 * fVar78;
      local_378[1] = (0.0 - local_3b8._4_4_) * fVar71 * fVar78;
      local_378[2] = (0.0 - (float)uStack_3b0) * fVar71 * fVar78;
      local_378[3] = (0.0 - uStack_3b0._4_4_) * fVar71 * fVar78;
      local_3b8 = CONCAT44((0.0 - local_388._4_4_) * fVar71 * fVar78,
                           (0.0 - (float)local_388) * fVar71 * fVar78);
      uStack_3b0 = (float *)CONCAT44((0.0 - fStack_37c) * fVar71 * fVar78,
                                     (0.0 - fStack_380) * fVar71 * fVar78);
      fVar78 = *(float *)(lVar29 + 8) * fVar36 + *(float *)(param_1 + 0x98);
      fVar71 = *(float *)(lVar29 + 0x50);
      fVar72 = *(float *)(lVar29 + 0x54);
      fVar74 = *(float *)(lVar29 + 0x58);
      fVar76 = *(float *)(lVar29 + 0x5c);
      *(float *)(param_1 + 0x1a) = fVar71 - fVar78;
      *(float *)((longlong)param_1 + 0xd4) = fVar72 - fVar78;
      *(float *)(param_1 + 0x1b) = fVar74 - fVar78;
      *(float *)((longlong)param_1 + 0xdc) = fVar76 - fVar78;
      *(float *)(param_1 + 0x1c) = fVar78 + fVar71;
      *(float *)((longlong)param_1 + 0xe4) = fVar78 + fVar72;
      *(float *)(param_1 + 0x1d) = fVar78 + fVar74;
      *(float *)((longlong)param_1 + 0xec) = fVar78 + fVar76;
      lVar29 = param_1[0xb2];
      fVar71 = *(float *)(lVar29 + 8) * fVar36 + *(float *)(param_1 + 0x98);
      auVar43._0_4_ = fVar71 + *(float *)(lVar29 + 0x50);
      auVar43._4_4_ = fVar71 + *(float *)(lVar29 + 0x54);
      auVar43._8_4_ = fVar71 + *(float *)(lVar29 + 0x58);
      auVar43._12_4_ = fVar71 + *(float *)(lVar29 + 0x5c);
      auVar61._0_4_ = *(float *)(lVar29 + 0x50) - fVar71;
      auVar61._4_4_ = *(float *)(lVar29 + 0x54) - fVar71;
      auVar61._8_4_ = *(float *)(lVar29 + 0x58) - fVar71;
      auVar61._12_4_ = *(float *)(lVar29 + 0x5c) - fVar71;
      auVar49 = maxps(*(undefined1 (*) [16])(param_1 + 0x1c),auVar43);
      auVar42 = minps(*(undefined1 (*) [16])(param_1 + 0x1a),auVar61);
      *(undefined1 (*) [16])(param_1 + 0x1a) = auVar42;
      *(undefined1 (*) [16])(param_1 + 0x1c) = auVar49;
      uVar39 = *(uint *)(param_1 + 0xa5);
      lVar29 = (ulonglong)(*(int *)((longlong)param_1 + 0x524) * uVar39) + param_1[0xa3];
      fVar71 = local_f8 - *(float *)(lVar29 + 0x50);
      fVar72 = fStack_f4 - *(float *)(lVar29 + 0x54);
      fVar74 = fStack_f0 - *(float *)(lVar29 + 0x58);
      local_3c8 = DAT_140b7a23c / (float)((int)param_1[0xa6] - 1);
      fVar40 = (float)FUN_1408fde98(*(float *)(lVar29 + 0xc) -
                                    SQRT(fVar71 * fVar71 + fVar72 * fVar72 + fVar74 * fVar74) *
                                    *(float *)(param_1[0x9d] + 0x3b4));
      fVar73 = fStack_12c;
      fVar80 = fStack_130;
      fVar79 = fStack_134;
      fVar78 = local_138;
      fVar75 = fVar18;
      fVar71 = local_f8;
      fVar72 = fStack_f4;
      fVar74 = fStack_f0;
      fVar76 = fStack_ec;
      if (uVar39 < *(uint *)((longlong)param_1 + 0x52c)) {
        do {
          lVar29 = (ulonglong)(uVar39 * *(int *)((longlong)param_1 + 0x524)) + param_1[0xa3];
          local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
          FUN_140318930(*(undefined2 *)(param_1[0x9d] + 0x26),plVar6,param_1 + 0x38,lVar29 + 0x20);
          if ((*(byte *)(param_1[0x9d] + 0x28) & 0x20) != 0) {
            local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
            FUN_140318930();
          }
          local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x1b8);
          FUN_140318840(*(ushort *)(param_1[0x9d] + 0x1b8),param_1 + 0x74,param_1 + 0x6a,lVar29 + 4)
          ;
          local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x2b0);
          FUN_140318840(*(ushort *)(param_1[0x9d] + 0x2b0),param_1 + 0x88,param_1 + 0x7e,lVar29 + 8)
          ;
          fVar59 = fVar75 * fVar75;
          fVar70 = fVar75 * fVar59;
          fVar81 = fVar70 - fVar59;
          fVar77 = (fVar70 - fVar59 * DAT_140b79f58) + fVar75;
          fVar48 = fVar59 * DAT_140b79fa0 - fVar70 * DAT_140b79f58;
          fVar59 = (fVar70 * DAT_140b79f58 - fVar59 * DAT_140b79fa0) + fVar18;
          *(float *)(lVar29 + 0x50) =
               fVar81 * (float)local_3b8 +
               fVar77 * local_378[0] + fVar48 * local_f8 + fVar59 * fVar78;
          *(float *)(lVar29 + 0x54) =
               fVar81 * local_3b8._4_4_ +
               fVar77 * local_378[1] + fVar48 * fStack_f4 + fVar59 * fVar79;
          *(float *)(lVar29 + 0x58) =
               fVar81 * (float)uStack_3b0 +
               fVar77 * local_378[2] + fVar48 * fStack_f0 + fVar59 * fVar80;
          *(float *)(lVar29 + 0x5c) =
               fVar81 * uStack_3b0._4_4_ +
               fVar77 * local_378[3] + fVar48 * fStack_ec + fVar59 * fVar73;
          if (*(char *)(param_1[0x9d] + 4) == '\0') {
            *(float *)(lVar29 + 0x60) = *(float *)(lVar29 + 0x50) - fVar71;
            *(float *)(lVar29 + 100) = *(float *)(lVar29 + 0x54) - fVar72;
            *(float *)(lVar29 + 0x68) = *(float *)(lVar29 + 0x58) - fVar74;
            *(float *)(lVar29 + 0x6c) = *(float *)(lVar29 + 0x5c) - fVar76;
          }
          else if ((byte)(*(char *)(param_1[0x9d] + 4) - 1U) < 3) {
            puVar31 = puVar35;
            if (*(int *)((longlong)param_1 + 0x55c) != 0) {
              do {
                uVar32 = (int)puVar31 + 1;
                pfVar22 = (float *)(param_1[0xba] + (longlong)puVar31 * 0x10);
                fVar76 = pfVar22[1];
                fVar48 = pfVar22[2];
                fVar59 = pfVar22[3];
                pfVar1 = (float *)(param_1[0xbc] + (longlong)puVar31 * 0x10);
                fVar70 = pfVar1[1];
                fVar77 = pfVar1[2];
                fVar81 = pfVar1[3];
                fVar14 = *(float *)(lVar29 + 0x54);
                fVar15 = *(float *)(lVar29 + 0x58);
                fVar16 = *(float *)(lVar29 + 0x5c);
                pfVar2 = (float *)(lVar29 + ((longlong)puVar31 + 7) * 0x10);
                *pfVar2 = (*(float *)(lVar29 + 0x50) - ((fVar37 - fVar85) * fVar75 + fVar85)) +
                          (*pfVar1 - *pfVar22) * fVar75 + *pfVar22;
                pfVar2[1] = (fVar14 - ((fVar38 - fVar82) * fVar75 + fVar82)) +
                            (fVar70 - fVar76) * fVar75 + fVar76;
                pfVar2[2] = (fVar15 - ((fVar83 - fVar28) * fVar75 + fVar28)) +
                            (fVar77 - fVar48) * fVar75 + fVar48;
                pfVar2[3] = (fVar16 - ((fVar69 - fVar86) * fVar75 + fVar86)) +
                            (fVar81 - fVar59) * fVar75 + fVar59;
                puVar31 = (undefined4 *)(ulonglong)uVar32;
              } while (uVar32 < *(uint *)((longlong)param_1 + 0x55c));
            }
          }
          fVar71 = fVar71 - *(float *)(lVar29 + 0x50);
          fVar72 = fVar72 - *(float *)(lVar29 + 0x54);
          fVar74 = fVar74 - *(float *)(lVar29 + 0x58);
          uVar39 = uVar39 + 1;
          fVar40 = SQRT(fVar71 * fVar71 + fVar72 * fVar72 + fVar74 * fVar74) *
                   *(float *)(param_1[0x9d] + 0x3b4) + fVar40;
          *(float *)(lVar29 + 0xc) = fVar40;
          fVar48 = *(float *)(lVar29 + 8) * fVar36 + *(float *)(param_1 + 0x98);
          fVar71 = *(float *)(lVar29 + 0x50);
          fVar72 = *(float *)(lVar29 + 0x54);
          fVar74 = *(float *)(lVar29 + 0x58);
          fVar76 = *(float *)(lVar29 + 0x5c);
          auVar62._0_4_ = fVar71 - fVar48;
          auVar62._4_4_ = fVar72 - fVar48;
          auVar62._8_4_ = fVar74 - fVar48;
          auVar62._12_4_ = fVar76 - fVar48;
          auVar44._0_4_ = fVar48 + fVar71;
          auVar44._4_4_ = fVar48 + fVar72;
          auVar44._8_4_ = fVar48 + fVar74;
          auVar44._12_4_ = fVar48 + fVar76;
          auVar49 = maxps(*(undefined1 (*) [16])(param_1 + 0x1c),auVar44);
          auVar42 = minps(*(undefined1 (*) [16])(param_1 + 0x1a),auVar62);
          *(undefined1 (*) [16])(param_1 + 0x1a) = auVar42;
          *(undefined1 (*) [16])(param_1 + 0x1c) = auVar49;
          fVar75 = fVar75 + local_3c8;
        } while (uVar39 < *(uint *)((longlong)param_1 + 0x52c));
      }
      auVar84._0_12_ = ZEXT812(0);
      auVar84._12_4_ = 0;
      iVar19 = *(int *)((longlong)param_1 + 0x52c);
      lVar29 = (ulonglong)(uint)(*(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5]) +
               param_1[0xa3];
      if (iVar19 == 0) {
        iVar19 = (int)param_1[0xa4];
      }
      lVar23 = (ulonglong)(uint)((iVar19 + -1) * *(int *)((longlong)param_1 + 0x524)) +
               param_1[0xa3];
      *(undefined4 *)(param_1[0xb1] + 0xc) = *(undefined4 *)(lVar23 + 0xc);
      *(undefined4 *)(param_1[0xb2] + 0xc) = *(undefined4 *)(lVar29 + 0xc);
      cVar3 = *(char *)(param_1[0x9d] + 4);
      if (cVar3 == '\0') {
        if ((*(uint *)(param_1[0x9d] + 0x28) & 0x8000) == 0) {
          pfVar22 = (float *)((ulonglong)
                              (uint)(((int)param_1[0xa5] + 1) * *(int *)((longlong)param_1 + 0x524))
                              + 0x50 + param_1[0xa3]);
          fVar85 = pfVar22[1];
          fVar82 = pfVar22[2];
          fVar28 = pfVar22[3];
          *(float *)(lVar29 + 0x60) = *pfVar22 - *(float *)(lVar29 + 0x50);
          *(float *)(lVar29 + 100) = fVar85 - *(float *)(lVar29 + 0x54);
          *(float *)(lVar29 + 0x68) = fVar82 - *(float *)(lVar29 + 0x58);
          *(float *)(lVar29 + 0x6c) = fVar28 - *(float *)(lVar29 + 0x5c);
        }
        else {
          *(undefined1 (*) [16])(lVar23 + 0x60) = auVar84;
        }
        fVar85 = DAT_140b79d04;
        *(undefined1 (*) [16])(param_1[0xb1] + 0x60) = auVar84;
        *(undefined1 (*) [16])(param_1[0xb2] + 0x60) = auVar84;
      }
      else {
        fVar85 = DAT_140b79d04;
        if (((byte)(cVar3 - 1U) < 3) &&
           (puVar31 = puVar35, *(int *)((longlong)param_1 + 0x55c) != 0)) {
          do {
            uVar39 = (int)puVar31 + 1;
            puVar7 = (undefined8 *)(param_1[0xba] + (longlong)puVar31 * 0x10);
            uVar17 = puVar7[1];
            puVar24 = (undefined8 *)(param_1[0xb1] + ((longlong)puVar31 + 7) * 0x10);
            *puVar24 = *puVar7;
            puVar24[1] = uVar17;
            puVar7 = (undefined8 *)(param_1[0xbc] + (longlong)puVar31 * 0x10);
            uVar17 = puVar7[1];
            puVar24 = (undefined8 *)(param_1[0xb2] + ((longlong)puVar31 + 7) * 0x10);
            *puVar24 = *puVar7;
            puVar24[1] = uVar17;
            puVar31 = (undefined4 *)(ulonglong)uVar39;
            fVar85 = DAT_140b79d04;
          } while (uVar39 < *(uint *)((longlong)param_1 + 0x55c));
        }
      }
    }
  }
  auVar42 = minps(*(undefined1 (*) [16])(param_1 + 0x1e),*(undefined1 (*) [16])(param_1 + 0x1a));
  auVar49 = maxps(*(undefined1 (*) [16])(param_1 + 0x20),*(undefined1 (*) [16])(param_1 + 0x1c));
  *(undefined1 (*) [16])(param_1 + 0x1e) = auVar42;
  *(undefined1 (*) [16])(param_1 + 0x20) = auVar49;
  if (*(char *)(param_1[0x9d] + 4) == '\x04') {
    if (*(longlong *)(param_1[5] + 0x4c0) == 0) {
      return;
    }
    puVar31 = puVar35;
    if (*(int *)((longlong)param_1 + 0x55c) != 0) {
      do {
        pfVar22 = (float *)(**(code **)(**(longlong **)(param_1[5] + 0x4c0) + 0x358))
                                     (*(longlong **)(param_1[5] + 0x4c0),local_3a8,
                                      (&DAT_140af1508)[(longlong)puVar31],0);
        uVar39 = (int)puVar31 + 1;
        fVar82 = *pfVar22;
        fVar28 = pfVar22[1];
        fVar86 = pfVar22[2];
        auVar60._0_4_ =
             fVar82 * *(float *)param_3 + fVar28 * *(float *)((longlong)param_3 + 0x10) +
             fVar86 * *(float *)((longlong)param_3 + 0x20) + *(float *)((longlong)param_3 + 0x30);
        auVar60._4_4_ =
             fVar82 * *(float *)((longlong)param_3 + 4) +
             fVar28 * *(float *)((longlong)param_3 + 0x14) +
             fVar86 * *(float *)((longlong)param_3 + 0x24) + *(float *)((longlong)param_3 + 0x34);
        auVar60._8_4_ =
             fVar82 * *(float *)((longlong)param_3 + 8) +
             fVar28 * *(float *)((longlong)param_3 + 0x18) +
             fVar86 * *(float *)((longlong)param_3 + 0x28) + *(float *)((longlong)param_3 + 0x38);
        auVar60._12_4_ =
             fVar82 * *(float *)((longlong)param_3 + 0xc) +
             fVar28 * *(float *)((longlong)param_3 + 0x1c) +
             fVar86 * *(float *)((longlong)param_3 + 0x2c) + *(float *)((longlong)param_3 + 0x3c);
        *(undefined1 (*) [16])((longlong)puVar31 * 0x10 + param_1[0xc6]) = auVar60;
        puVar31 = (undefined4 *)(ulonglong)uVar39;
      } while (uVar39 < *(uint *)((longlong)param_1 + 0x55c));
    }
    iVar19 = (**(code **)(**(longlong **)(param_1[5] + 0x4c0) + 0x350))
                       (*(longlong **)(param_1[5] + 0x4c0),0x1f);
    if (iVar19 == 0) {
      _local_3a8 = *(undefined1 (*) [16])param_1[0xc6];
    }
    else {
      pfVar22 = (float *)(**(code **)(**(longlong **)(param_1[5] + 0x4c0) + 0x358))
                                   (*(longlong **)(param_1[5] + 0x4c0),local_3a8,0x1f);
      fVar82 = *pfVar22;
      fVar28 = pfVar22[1];
      fVar86 = pfVar22[2];
      local_3a8._0_4_ =
           fVar28 * *(float *)((longlong)param_3 + 0x10) + fVar82 * *(float *)param_3 +
           fVar86 * *(float *)((longlong)param_3 + 0x20) + *(float *)((longlong)param_3 + 0x30);
      local_3a8._4_4_ =
           fVar28 * *(float *)((longlong)param_3 + 0x14) +
           fVar82 * *(float *)((longlong)param_3 + 4) +
           fVar86 * *(float *)((longlong)param_3 + 0x24) + *(float *)((longlong)param_3 + 0x34);
      uStack_3a0._0_4_ =
           fVar28 * *(float *)((longlong)param_3 + 0x18) +
           fVar82 * *(float *)((longlong)param_3 + 8) +
           fVar86 * *(float *)((longlong)param_3 + 0x28) + *(float *)((longlong)param_3 + 0x38);
      uStack_3a0._4_4_ =
           fVar28 * *(float *)((longlong)param_3 + 0x1c) +
           fVar82 * *(float *)((longlong)param_3 + 0xc) +
           fVar86 * *(float *)((longlong)param_3 + 0x2c) + *(float *)((longlong)param_3 + 0x3c);
    }
  }
  else {
    puVar31 = puVar35;
    if (*(int *)(param_1[0x9d] + 8) != 0) {
      do {
        lVar29 = *(longlong *)(param_1[0x9d] + 0x10);
        pfVar22 = (float *)((longlong)puVar31 * 0x10 + param_1[0xc6]);
        uVar39 = (int)puVar31 + 1;
        fVar82 = *(float *)(lVar29 + 8 + (longlong)puVar31 * 0xc);
        fVar28 = *(float *)(lVar29 + 4 + (longlong)puVar31 * 0xc);
        fVar86 = *(float *)(lVar29 + (longlong)puVar31 * 0xc);
        *pfVar22 = fVar28 * (float)local_198 + fVar86 * (float)local_1a8 + fVar82 * (float)local_188
                   + local_178;
        pfVar22[1] = fVar28 * local_198._4_4_ + fVar86 * local_1a8._4_4_ + fVar82 * local_188._4_4_
                     + fStack_174;
        pfVar22[2] = fVar28 * (float)uStack_190 + fVar86 * (float)uStack_1a0 +
                     fVar82 * (float)uStack_180 + fStack_170;
        pfVar22[3] = fVar28 * uStack_190._4_4_ + fVar86 * uStack_1a0._4_4_ +
                     fVar82 * uStack_180._4_4_ + fStack_16c;
        puVar31 = (undefined4 *)(ulonglong)uVar39;
      } while (uVar39 < *(uint *)(param_1[0x9d] + 8));
    }
    lVar29 = param_1[0x9d];
    fVar82 = *(float *)(lVar29 + 0x20);
    fVar28 = *(float *)(lVar29 + 0x1c);
    fVar86 = *(float *)(lVar29 + 0x18);
    local_3a8._0_4_ =
         fVar86 * (float)local_1a8 + fVar28 * (float)local_198 + fVar82 * (float)local_188 +
         local_178;
    local_3a8._4_4_ =
         fVar86 * local_1a8._4_4_ + fVar28 * local_198._4_4_ + fVar82 * local_188._4_4_ + fStack_174
    ;
    uStack_3a0._0_4_ =
         fVar86 * (float)uStack_1a0 + fVar28 * (float)uStack_190 + fVar82 * (float)uStack_180 +
         fStack_170;
    uStack_3a0._4_4_ =
         fVar86 * uStack_1a0._4_4_ + fVar28 * uStack_190._4_4_ + fVar82 * uStack_180._4_4_ +
         fStack_16c;
  }
  iVar19 = (**(code **)(*param_1 + 0x48))(param_1);
  if (iVar19 != 0) {
    if (*(char *)((longlong)param_1 + 0x191) == '\0') {
      FUN_140318540(param_1[1] + 0x50,param_1 + 10,param_1 + 0x31);
      *(undefined1 *)((longlong)param_1 + 0x191) = 1;
    }
    for (puVar7 = (undefined8 *)param_1[0x31]; puVar7 != (undefined8 *)0x0;
        puVar7 = (undefined8 *)puVar7[2]) {
      (**(code **)*puVar7)(puVar7,param_1[6]);
    }
    pcVar34 = (char *)param_1[0x9d];
    if ((*pcVar34 != '\0') ||
       (((pcVar34[4] == '\x04' &&
         (*(float *)((ulonglong)
                     *(ushort *)
                      ((ulonglong)*(ushort *)param_1[1] * 0x160 + 6 +
                      *(longlong *)(*(longlong *)(param_1[5] + 0x40) + 0x188)) * 0x60 + 0x30 +
                    *(longlong *)(param_1[5] + 0x1f0)) <= fVar36)) || ((int)param_1[10] == 0)))) {
      *(undefined4 *)((longlong)param_1 + 0x544) = 0;
    }
    else {
      iVar19 = *(int *)((longlong)param_1 + 0x52c);
      if (iVar19 == 0) {
        iVar19 = (int)param_1[0xa4];
      }
      local_3d8 = 0;
      local_3e0 = (float)(uint)*(ushort *)(pcVar34 + 0x26);
      local_3e8 = (float *)local_3a8;
      plVar6 = param_1 + 0xc6;
      FUN_14031e170(param_1,param_1[0xb1],
                    (ulonglong)(uint)(*(int *)((longlong)param_1 + 0x524) * (iVar19 + -1)) +
                    param_1[0xa3],plVar6);
      if (*(int *)((longlong)param_1 + 0x544) == 0) {
        local_3d8 = 0;
        local_3e8 = (float *)local_3a8;
        local_3e0 = (float)(uint)*(ushort *)(param_1[0x9d] + 0x26);
        FUN_14031e170(param_1,param_1[0xb2],0);
        *(undefined4 *)((longlong)param_1 + 0x6a4) = 0;
        *(uint *)(param_1 + 0xa8) = (int)param_1[0xa7] - (uint)*(ushort *)(param_1[0x9d] + 2);
      }
      lVar29 = param_1[0x9d];
      uVar5 = *(ushort *)(lVar29 + 2);
      if ((int)(uVar5 + 1) >> 1 <= (int)param_1[0xa7] - (int)param_1[0xa8]) {
        if (*(uint *)((longlong)param_1 + 0x6a4) < 3) {
          *(uint *)((longlong)param_1 + 0x6a4) = *(uint *)((longlong)param_1 + 0x6a4) + 1;
        }
        else {
          uVar39 = *(uint *)(param_1 + 0xd4);
          lVar23 = param_1[((ulonglong)((uVar39 + 1) % 3) + 100) * 2];
          lVar8 = *plVar6;
          fVar86 = *(float *)(lVar8 + 0x10) - *(float *)(lVar23 + 0x10);
          fVar37 = *(float *)(lVar8 + 0x14) - *(float *)(lVar23 + 0x14);
          fVar38 = *(float *)(lVar8 + 0x18) - *(float *)(lVar23 + 0x18);
          fVar83 = *(float *)(lVar8 + 0x1c) - *(float *)(lVar23 + 0x1c);
          fVar82 = fVar37 * fVar37;
          auVar63._4_4_ = fVar82;
          auVar63._0_4_ = fVar86 * fVar86;
          auVar63._8_4_ = fVar38 * fVar38;
          auVar63._12_4_ = fVar83 * fVar83;
          auVar45._4_4_ = fVar82;
          auVar45._0_4_ = fVar82;
          auVar45._8_4_ = fVar82;
          auVar45._12_4_ = fVar82;
          lVar8 = param_1[((ulonglong)(uVar39 % 3) + 100) * 2];
          auVar64._4_12_ = auVar63._4_12_;
          auVar64._0_4_ = fVar86 * fVar86 + fVar82 + fVar38 * fVar38;
          fVar69 = *(float *)(lVar23 + 0x10) - *(float *)(lVar8 + 0x10);
          fVar71 = *(float *)(lVar23 + 0x14) - *(float *)(lVar8 + 0x14);
          fVar72 = *(float *)(lVar23 + 0x18) - *(float *)(lVar8 + 0x18);
          fVar74 = *(float *)(lVar23 + 0x1c) - *(float *)(lVar8 + 0x1c);
          auVar42 = rsqrtss(auVar45,auVar64);
          fVar82 = auVar42._0_4_;
          uVar26 = (ulonglong)((uVar39 + 2) % 3);
          fVar28 = fVar71 * fVar71;
          auVar65._4_4_ = fVar28;
          auVar65._0_4_ = fVar69 * fVar69;
          lVar23 = param_1[(uVar26 + 100) * 2];
          auVar65._8_4_ = fVar72 * fVar72;
          auVar65._12_4_ = fVar74 * fVar74;
          fVar82 = (DAT_140b79fa0 - auVar64._0_4_ * fVar82 * fVar82) * fVar36 * fVar82;
          auVar46._4_4_ = fVar28;
          auVar46._0_4_ = fVar28;
          auVar46._8_4_ = fVar28;
          auVar46._12_4_ = fVar28;
          fVar76 = 0.0;
          if (fVar82 <= 0.0) {
            fVar82 = fVar76;
          }
          auVar66._4_12_ = auVar65._4_12_;
          auVar66._0_4_ = fVar69 * fVar69 + fVar28 + fVar72 * fVar72;
          auVar42 = rsqrtss(auVar46,auVar66);
          fVar86 = fVar82 * fVar86;
          fVar37 = fVar82 * fVar37;
          fVar38 = fVar82 * fVar38;
          fVar79 = *(float *)(lVar23 + 0x10) - *(float *)(lVar8 + 0x10);
          fVar80 = *(float *)(lVar23 + 0x14) - *(float *)(lVar8 + 0x14);
          fVar73 = *(float *)(lVar23 + 0x18) - *(float *)(lVar8 + 0x18);
          fVar75 = *(float *)(lVar23 + 0x1c) - *(float *)(lVar8 + 0x1c);
          fVar28 = auVar42._0_4_;
          fVar78 = fVar80 * fVar80;
          auVar67._4_4_ = fVar78;
          auVar67._0_4_ = fVar79 * fVar79;
          fVar28 = (DAT_140b79fa0 - auVar66._0_4_ * fVar28 * fVar28) * fVar36 * fVar28;
          if (fVar28 <= 0.0) {
            fVar28 = fVar76;
          }
          fVar69 = fVar28 * fVar69;
          fVar71 = fVar28 * fVar71;
          fVar72 = fVar28 * fVar72;
          auVar47._4_4_ = fVar78;
          auVar47._0_4_ = fVar78;
          auVar47._8_4_ = fVar78;
          auVar47._12_4_ = fVar78;
          auVar67._8_4_ = fVar73 * fVar73;
          auVar67._12_4_ = fVar75 * fVar75;
          auVar68._4_12_ = auVar67._4_12_;
          auVar68._0_4_ = fVar79 * fVar79 + fVar78 + fVar73 * fVar73;
          auVar42 = rsqrtss(auVar47,auVar68);
          fVar78 = auVar42._0_4_;
          fVar78 = (DAT_140b79fa0 - auVar68._0_4_ * fVar78 * fVar78) * fVar36 * fVar78;
          if (fVar78 <= 0.0) {
            fVar78 = fVar76;
          }
          fVar36 = fVar69 * fVar69 + fVar71 * fVar71 + fVar72 * fVar72;
          if ((fVar86 * fVar86 + fVar37 * fVar37 + fVar38 * fVar38 == 0.0) || (fVar36 == 0.0)) {
            fVar82 = 0.0;
          }
          else {
            fVar86 = (0.0 - fVar69) * fVar86;
            fVar37 = (0.0 - fVar71) * fVar37;
            auVar53._4_4_ = fVar37;
            auVar53._0_4_ = fVar86;
            fVar38 = (0.0 - fVar72) * fVar38;
            auVar53._8_4_ = fVar38;
            auVar53._12_4_ = (0.0 - fVar28 * fVar74) * fVar82 * fVar83;
            auVar54._4_12_ = auVar53._4_12_;
            auVar54._0_4_ = fVar86 + fVar37 + fVar38;
            lVar23 = FUN_1408fccb0(uVar26,auVar54._0_8_);
            fVar82 = extraout_XMM0_Da;
          }
          uVar21 = (undefined4)lVar23;
          if ((fVar36 == 0.0) ||
             (fVar78 * fVar79 * fVar78 * fVar79 + fVar78 * fVar80 * fVar78 * fVar80 +
              fVar78 * fVar73 * fVar78 * fVar73 == 0.0)) {
            auVar55._0_12_ = ZEXT812(0);
            auVar55._12_4_ = 0;
          }
          else {
            uVar21 = FUN_1408fccb0();
            auVar55._8_4_ = (int)extraout_XMM0_Qb;
            auVar55._0_8_ = extraout_XMM0_Qa;
            auVar55._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
          }
          if ((*(byte *)(lVar29 + 0x28) & 8) != 0) {
            auVar56._4_12_ = auVar55._4_12_;
            fVar28 = _DAT_140c79de4;
            if (*(char *)(lVar29 + 4) == '\x04') {
              fVar28 = _DAT_140b7a038;
            }
            auVar56._0_4_ = (auVar55._0_4_ + fVar82) * fVar28;
            iVar19 = (int)auVar56._0_4_;
            if ((iVar19 != -0x80000000) && ((float)iVar19 != auVar56._0_4_)) {
              auVar58._0_8_ = auVar56._0_8_;
              auVar58._8_4_ = auVar55._4_4_;
              auVar58._12_4_ = auVar55._4_4_;
              auVar57._8_8_ = auVar58._8_8_;
              auVar57._4_4_ = auVar56._0_4_;
              auVar57._0_4_ = auVar56._0_4_;
              uVar39 = movmskps(uVar21,auVar57);
              auVar56 = ZEXT416((uint)(float)(int)(iVar19 + (uVar39 & 1 ^ 1)));
            }
            uVar32 = (uint)(longlong)auVar56._0_4_;
            uVar39 = 10;
            if (uVar32 < 10) {
              uVar39 = uVar32;
            }
            if (-1 < (int)((uVar5 - 1) +
                          *(int *)((ulonglong)
                                   (uint)(*(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5])
                                   + 0x18 + param_1[0xa3])) / (int)(uint)uVar5) {
              uVar25 = (int)((uVar5 - 1) +
                            *(int *)((ulonglong)
                                     (uint)(*(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5]
                                           ) + 0x18 + param_1[0xa3])) / (int)(uint)uVar5;
            }
            uVar25 = (((int)param_1[0xa4] - uVar25) - (int)param_1[0xa6]) - 0x10;
            if (((int)uVar25 < (int)uVar39) && (uVar39 = uVar25, (int)uVar25 < 1)) {
              uVar39 = 1;
            }
            if (1 < uVar39) {
              if ((int)param_1[0xa6] != 0) {
                iVar19 = *(int *)((longlong)param_1 + 0x52c);
                *(int *)((longlong)param_1 + 0x52c) = iVar19 + -1;
                if (iVar19 == 0) {
                  *(int *)((longlong)param_1 + 0x52c) = (int)param_1[0xa4] + -1;
                }
                *(int *)(param_1 + 0xa6) = (int)param_1[0xa6] + -1;
              }
              uVar25 = *(uint *)(param_1 + 0xd4);
              local_178 = (float)local_3a8._0_4_;
              fStack_174 = (float)local_3a8._4_4_;
              fStack_170 = (float)uStack_3a0;
              fStack_16c = uStack_3a0._4_4_;
              pfVar22 = (float *)(param_1 + ((ulonglong)((uVar25 + 2) % 3) + 0x67) * 2);
              fVar82 = *pfVar22;
              fVar28 = pfVar22[1];
              local_1a8 = *(longlong *)pfVar22;
              fVar86 = pfVar22[2];
              uStack_1a0 = *(longlong *)(pfVar22 + 2);
              pfVar1 = (float *)(param_1 + ((ulonglong)((uVar25 + 1) % 3) + 0x67) * 2);
              local_198 = *(longlong *)pfVar1;
              fVar36 = pfVar1[2];
              uStack_190 = *(longlong *)(pfVar1 + 2);
              pfVar2 = (float *)(param_1 + ((ulonglong)(uVar25 % 3) + 0x67) * 2);
              local_188 = *(longlong *)pfVar2;
              fVar37 = pfVar2[2];
              uStack_180 = *(longlong *)(pfVar2 + 2);
              fVar38 = fVar82 - *pfVar2;
              fVar83 = fVar28 - pfVar2[1];
              fVar69 = fVar86 - fVar37;
              fVar71 = fVar38 * fVar38 + fVar83 * fVar83 + fVar69 * fVar69;
              fVar38 = *pfVar1 - (float)local_3a8._0_4_;
              fVar83 = pfVar1[1] - (float)local_3a8._4_4_;
              fVar69 = fVar36 - (float)uStack_3a0;
              fVar38 = fVar38 * fVar38 + fVar83 * fVar83 + fVar69 * fVar69;
              if (fVar38 <= fVar71) {
                fVar83 = local_3c8;
                if (fVar38 < fVar71) {
                  fVar83 = SQRT(fVar38 / fVar71);
                }
              }
              else {
                fVar83 = SQRT(fVar71 / fVar38);
              }
              iVar19 = *(int *)((longlong)param_1 + 0x52c);
              if (iVar19 == 0) {
                iVar19 = (int)param_1[0xa4];
              }
              fVar69 = *(float *)((ulonglong)
                                  (uint)((iVar19 + -1) * *(int *)((longlong)param_1 + 0x524)) + 0x18
                                 + param_1[0xa3]);
              puVar31 = puVar35;
              fVar72 = *pfVar1;
              fVar74 = pfVar1[1];
              fVar76 = pfVar1[3];
              fVar78 = *pfVar2;
              fVar79 = pfVar2[1];
              fVar80 = pfVar2[3];
              fVar73 = fVar18 / (float)uVar39;
              fVar75 = fVar82;
              fVar40 = fVar28;
              fVar48 = fVar86;
              fVar59 = pfVar22[3];
              local_3c8 = fVar69;
              if (uVar39 != 0) {
                while( true ) {
                  if (fVar38 <= fVar71) {
                    if (fVar38 < fVar71) {
                      local_1a8 = CONCAT44((fVar40 - fVar79) * fVar83 + fVar79,
                                           (fVar75 - fVar78) * fVar83 + fVar78);
                      uStack_1a0 = CONCAT44((fVar59 - fVar80) * fVar83 + fVar80,
                                            (fVar48 - fVar37) * fVar83 + fVar37);
                    }
                  }
                  else {
                    local_178 = (local_178 - fVar72) * fVar83 + fVar72;
                    fStack_174 = (fStack_174 - fVar74) * fVar83 + fVar74;
                    fStack_170 = (fStack_170 - fVar36) * fVar83 + fVar36;
                    fStack_16c = (fStack_16c - fVar76) * fVar83 + fVar76;
                  }
                  local_3e8 = &local_178;
                  local_3e0 = fVar73;
                  FUN_1401adf30(&local_3b8,&local_1a8,&local_198,&local_188);
                  fVar36 = (float)local_3b8;
                  fVar37 = local_3b8._4_4_;
                  fVar72 = (float)uStack_3b0;
                  if (fVar85 < ((float)local_3b8 - fVar82) * ((float)local_3b8 - fVar82) +
                               (local_3b8._4_4_ - fVar28) * (local_3b8._4_4_ - fVar28) +
                               ((float)uStack_3b0 - fVar86) * ((float)uStack_3b0 - fVar86)) {
                    puVar27 = puVar35;
                    if (*(int *)((longlong)param_1 + 0x55c) != 0) {
                      do {
                        uVar25 = *(uint *)(param_1 + 0xd4);
                        iVar19 = (int)puVar27;
                        lVar29 = (longlong)puVar27 * 2;
                        pfVar22 = (float *)(param_1[((ulonglong)((uVar25 + 2) % 3) + 100) * 2] +
                                           (longlong)puVar27 * 0x10);
                        local_168[0] = *pfVar22;
                        local_168[1] = pfVar22[1];
                        local_168[2] = pfVar22[2];
                        local_168[3] = pfVar22[3];
                        pfVar22 = (float *)(param_1[((ulonglong)((uVar25 + 1) % 3) + 100) * 2] +
                                           (longlong)puVar27 * 0x10);
                        local_158 = *pfVar22;
                        fStack_154 = pfVar22[1];
                        fStack_150 = pfVar22[2];
                        fStack_14c = pfVar22[3];
                        pfVar22 = (float *)(param_1[((ulonglong)(uVar25 % 3) + 100) * 2] +
                                           (longlong)puVar27 * 0x10);
                        local_148 = *pfVar22;
                        fStack_144 = pfVar22[1];
                        fStack_140 = pfVar22[2];
                        fStack_13c = pfVar22[3];
                        pfVar22 = (float *)(*plVar6 + (longlong)puVar27 * 0x10);
                        local_138 = *pfVar22;
                        fStack_134 = pfVar22[1];
                        fStack_130 = pfVar22[2];
                        fStack_12c = pfVar22[3];
                        if (fVar38 <= fVar71) {
                          if (fVar38 < fVar71) {
                            local_168[0] = (local_168[0] - local_148) * fVar83 + local_148;
                            local_168[1] = (local_168[1] - fStack_144) * fVar83 + fStack_144;
                            local_168[2] = (local_168[2] - fStack_140) * fVar83 + fStack_140;
                            local_168[3] = (local_168[3] - fStack_13c) * fVar83 + fStack_13c;
                          }
                        }
                        else {
                          local_138 = (local_138 - local_158) * fVar83 + local_158;
                          fStack_134 = (fStack_134 - fStack_154) * fVar83 + fStack_154;
                          fStack_130 = (fStack_130 - fStack_150) * fVar83 + fStack_150;
                          fStack_12c = (fStack_12c - fStack_14c) * fVar83 + fStack_14c;
                        }
                        local_3e8 = &local_138;
                        local_3e0 = fVar73;
                        puVar24 = (undefined8 *)
                                  FUN_1401adf30(&local_388,local_168,local_168 + 4,&local_148);
                        puVar27 = (undefined4 *)(ulonglong)(iVar19 + 1U);
                        uVar17 = puVar24[1];
                        puVar7 = (undefined8 *)(param_1[0xc4] + lVar29 * 8);
                        *puVar7 = *puVar24;
                        puVar7[1] = uVar17;
                      } while (iVar19 + 1U < *(uint *)((longlong)param_1 + 0x55c));
                    }
                    FUN_14031e520(param_1,param_1 + 0xc4,&local_3b8,
                                  (int)fVar69 +
                                  (((uint)*(ushort *)(param_1[0x9d] + 0x26) - (int)fVar69) *
                                  ((int)puVar31 + 1)) / uVar39);
                    iVar19 = *(int *)((longlong)param_1 + 0x52c);
                    if (iVar19 == 0) {
                      iVar19 = (int)param_1[0xa4];
                    }
                    lVar29 = (ulonglong)(uint)((iVar19 + -1) * *(int *)((longlong)param_1 + 0x524))
                             + param_1[0xa3];
                    local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
                    FUN_140318930(*(ushort *)(param_1[0x9d] + 0x48),param_1 + 0x60,param_1 + 0x38,
                                  lVar29 + 0x20);
                    if ((*(byte *)(param_1[0x9d] + 0x28) & 0x20) != 0) {
                      local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
                      FUN_140318930();
                    }
                    local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x1b8);
                    FUN_140318840(*(ushort *)(param_1[0x9d] + 0x1b8),param_1 + 0x74,param_1 + 0x6a,
                                  lVar29 + 4);
                    local_3e8 = (float *)CONCAT44(local_3e8._4_4_,
                                                  (uint)*(ushort *)(param_1[0x9d] + 0x2b0));
                    FUN_140318840(*(ushort *)(param_1[0x9d] + 0x2b0),param_1 + 0x88,param_1 + 0x7e,
                                  lVar29 + 8);
                    fVar82 = fVar36;
                    fVar28 = fVar37;
                    fVar86 = fVar72;
                    fVar69 = local_3c8;
                  }
                  uVar25 = (int)puVar31 + 1;
                  puVar31 = (undefined4 *)(ulonglong)uVar25;
                  fVar73 = fVar73 + fVar18 / (float)uVar39;
                  if (uVar39 <= uVar25) break;
                  fVar72 = (float)local_198;
                  fVar74 = local_198._4_4_;
                  fVar36 = (float)uStack_190;
                  fVar76 = uStack_190._4_4_;
                  fVar78 = (float)local_188;
                  fVar79 = local_188._4_4_;
                  fVar37 = (float)uStack_180;
                  fVar80 = uStack_180._4_4_;
                  fVar75 = (float)local_1a8;
                  fVar40 = local_1a8._4_4_;
                  fVar48 = (float)uStack_1a0;
                  fVar59 = uStack_1a0._4_4_;
                }
              }
            }
          }
        }
        if ((int)param_1[0xa6] == (int)param_1[0xa4]) {
          puVar31 = (undefined4 *)param_1[0xb2];
          puVar27 = (undefined4 *)
                    ((ulonglong)(uint)((int)param_1[0xa5] * *(int *)((longlong)param_1 + 0x524)) +
                    param_1[0xa3]);
          *puVar31 = *puVar27;
          uVar17 = *(undefined8 *)(puVar27 + 10);
          *(undefined8 *)(puVar31 + 8) = *(undefined8 *)(puVar27 + 8);
          *(undefined8 *)(puVar31 + 10) = uVar17;
          uVar17 = *(undefined8 *)(puVar27 + 0xe);
          *(undefined8 *)(puVar31 + 0xc) = *(undefined8 *)(puVar27 + 0xc);
          *(undefined8 *)(puVar31 + 0xe) = uVar17;
          puVar31[1] = puVar27[1];
          puVar31[2] = puVar27[2];
          puVar31[6] = puVar27[6];
          puVar31[5] = puVar27[5];
          puVar31[3] = puVar27[3];
          puVar31[4] = puVar27[4];
          uVar17 = *(undefined8 *)(puVar27 + 0x12);
          *(undefined8 *)(puVar31 + 0x10) = *(undefined8 *)(puVar27 + 0x10);
          *(undefined8 *)(puVar31 + 0x12) = uVar17;
          uVar17 = *(undefined8 *)(puVar27 + 0x16);
          *(undefined8 *)(puVar31 + 0x14) = *(undefined8 *)(puVar27 + 0x14);
          *(undefined8 *)(puVar31 + 0x16) = uVar17;
          uVar17 = *(undefined8 *)(puVar27 + 0x1a);
          *(undefined8 *)(puVar31 + 0x18) = *(undefined8 *)(puVar27 + 0x18);
          *(undefined8 *)(puVar31 + 0x1a) = uVar17;
          memcpy(puVar31 + 0x1c,puVar27 + 0x1c,(ulonglong)*(uint *)((longlong)param_1 + 0x55c) << 4)
          ;
        }
        FUN_14031e520(param_1,plVar6,local_3a8,*(undefined2 *)(param_1[0x9d] + 0x26));
        iVar19 = *(int *)((longlong)param_1 + 0x52c);
        if (iVar19 == 0) {
          iVar19 = (int)param_1[0xa4];
        }
        lVar29 = (ulonglong)(uint)((iVar19 + -1) * *(int *)((longlong)param_1 + 0x524)) +
                 param_1[0xa3];
        local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
        FUN_140318930(*(ushort *)(param_1[0x9d] + 0x48),param_1 + 0x60,param_1 + 0x38,lVar29 + 0x20)
        ;
        if ((*(byte *)(param_1[0x9d] + 0x28) & 0x20) != 0) {
          local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x48);
          FUN_140318930();
        }
        local_3e8._0_4_ = (float)(uint)*(ushort *)(param_1[0x9d] + 0x1b8);
        FUN_140318840(*(ushort *)(param_1[0x9d] + 0x1b8),param_1 + 0x74,param_1 + 0x6a,lVar29 + 4);
        local_3e8 = (float *)CONCAT44(local_3e8._4_4_,(uint)*(ushort *)(param_1[0x9d] + 0x2b0));
        FUN_140318840(*(ushort *)(param_1[0x9d] + 0x2b0),param_1 + 0x88,param_1 + 0x7e,lVar29 + 8);
        uVar5 = *(ushort *)(param_1[0x9d] + 2) >> 1;
        uVar25 = ((int)param_1[0xa7] - (uint)*(ushort *)(param_1[0x9d] + 2)) - (int)param_1[0xa8];
        if ((int)(uint)uVar5 < (int)uVar25) {
          uVar25 = (uint)uVar5;
        }
        lVar29 = param_1[0xd4];
        *(int *)(param_1 + 0xd4) = (int)lVar29 + -1;
        *(uint *)(param_1 + 0xa8) = (int)param_1[0xa7] - uVar25;
        if ((int)lVar29 == 0) {
          *(undefined4 *)(param_1 + 0xd4) = 2;
        }
        if (*(int *)((longlong)param_1 + 0x55c) != 0) {
          do {
            uVar25 = (int)puVar35 + 1;
            puVar7 = (undefined8 *)(*plVar6 + (longlong)puVar35 * 0x10);
            uVar17 = puVar7[1];
            puVar24 = (undefined8 *)
                      (param_1[((ulonglong)*(uint *)(param_1 + 0xd4) + 100) * 2] +
                      (longlong)puVar35 * 0x10);
            *puVar24 = *puVar7;
            puVar24[1] = uVar17;
            puVar35 = (undefined4 *)(ulonglong)uVar25;
          } while (uVar25 < *(uint *)((longlong)param_1 + 0x55c));
        }
        uVar25 = *(uint *)(param_1 + 0xd4);
        param_1[((ulonglong)uVar25 + 0x67) * 2] = (longlong)local_3a8;
        (param_1 + ((ulonglong)uVar25 + 0x67) * 2)[1] = uStack_3a0;
      }
      *(undefined4 *)((longlong)param_1 + 0x544) = 1;
    }
  }
  return;
}


