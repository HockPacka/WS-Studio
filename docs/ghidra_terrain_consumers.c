
==== FUN_14034ea90 @ 14034ea90 size 6507 ====
CALLERS: FUN_14034dc80
CALLEES: FUN_1408fe3d0 FUN_1401c95b0 FUN_1401c96d0 FUN_140366cd0 FUN_1408fc950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14034ea90(ulonglong param_1)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  float *pfVar6;
  ushort uVar7;
  undefined4 *puVar8;
  int *piVar9;
  short *psVar10;
  undefined8 *puVar11;
  ushort uVar12;
  float fVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  ulonglong uVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  ushort uVar21;
  float fVar22;
  short *psVar23;
  int *piVar24;
  float *pfVar25;
  uint uVar26;
  uint uVar27;
  ulonglong uVar28;
  ushort *puVar29;
  short sVar30;
  longlong lVar31;
  uint uVar32;
  uint uVar33;
  int *piVar34;
  ulonglong uVar35;
  float fVar36;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  float fVar40;
  undefined8 local_res8;
  undefined4 local_res10;
  undefined2 uStackX_14;
  undefined2 uStackX_16;
  float local_res18;
  float fStackX_1c;
  float local_res20;
  float fStackX_24;
  float local_1a8;
  short local_1a4;
  short local_1a0;
  short local_19c;
  short local_198;
  short local_194;
  short local_190;
  short local_18c;
  short local_188;
  short local_184;
  short local_180;
  short local_17c;
  short local_178;
  short local_174;
  short local_170;
  short local_16c;
  short local_168;
  short local_164;
  short local_160;
  float local_15c;
  short local_158;
  float local_154;
  short local_150;
  short local_14c;
  short local_148;
  short local_144;
  short local_140;
  short local_13c;
  short local_138;
  short local_134;
  short local_130;
  short local_12c;
  short local_128;
  float local_124;
  short local_120;
  short local_11c;
  short local_118;
  short local_114;
  short local_110;
  float local_10c;
  short local_108;
  short local_104;
  short local_100;
  short local_fc;
  short local_f8;
  longlong local_e8;
  undefined8 uStack_e0;
  longlong local_d8;
  
  local_res8 = param_1;
  if (((*(byte *)(param_1 + 0x10) & 0x10) != 0) &&
     (puVar8 = (undefined4 *)
               (**(code **)(**(longlong **)(param_1 + 0xd8) + 0x38))
                         (*(longlong **)(param_1 + 0xd8),0,0,2), auVar39 = _DAT_140b7a620,
     puVar8 != (undefined4 *)0x0)) {
    uVar1 = DAT_140b7a620._8_4_;
    *puVar8 = (int)DAT_140b7a620;
    puVar8[1] = auVar39._4_4_;
    puVar8[2] = uVar1;
    local_e8 = 0;
    uStack_e0 = 0;
    FUN_1401c95b0(&local_res10,&local_e8);
    uVar5 = DAT_140c43e4c;
    puVar8[3] = local_res10;
    uVar1 = _DAT_140b7a3e0;
    puVar8[4] = 0;
    puVar8[5] = uVar1;
    uStack_e0 = _UNK_140b7a4b8;
    local_e8 = _DAT_140b7a4b0;
    puVar8[6] = uVar5;
    FUN_1401c95b0(&local_res10,&local_e8);
    puVar8[7] = local_res10;
    uVar1 = _DAT_140b7a3e0;
    puVar8[8] = uVar5;
    puVar8[9] = uVar1;
    uStack_e0 = _UNK_140b7a338;
    local_e8 = _DAT_140b7a330;
    puVar8[10] = 0;
    FUN_1401c95b0(&local_res10,&local_e8);
    puVar8[0xb] = local_res10;
    uVar1 = _DAT_140b7a3e0;
    puVar8[0xc] = uVar5;
    puVar8[0xd] = uVar1;
    uStack_e0 = _UNK_140b7a4c8;
    local_e8 = _DAT_140b7a4c0;
    puVar8[0xe] = uVar5;
    FUN_1401c95b0(&local_res10,&local_e8);
    puVar8[0xf] = local_res10;
    (**(code **)(**(longlong **)(param_1 + 0xd8) + 0x40))();
  }
  uVar26 = 0;
  if (((*(byte *)(param_1 + 0x10) & 4) != 0) &&
     (piVar9 = (int *)(**(code **)(**(longlong **)(param_1 + 0x78) + 0x38))
                                (*(longlong **)(param_1 + 0x78),0,0,2), fVar13 = DAT_140c43e84,
     uVar1 = DAT_140c43e4c, fVar22 = DAT_140b7a1b4, piVar24 = piVar9, uVar27 = uVar26,
     piVar9 != (int *)0x0)) {
    do {
      uVar33 = uVar26;
      do {
        piVar34 = piVar24;
        uVar32 = uVar33 + 1;
        auVar38._4_4_ = (float)uVar27 * fVar13;
        auVar38._0_4_ = (float)uVar33 * fVar13;
        auVar38._8_8_ = 0;
        auVar39._4_4_ = uVar1;
        auVar39._0_4_ = uVar1;
        auVar39._8_4_ = uVar1;
        auVar39._12_4_ = uVar1;
        auVar39 = divps(auVar38,auVar39);
        lVar14 = (longlong)(auVar39._0_4_ * fVar22);
        lVar31 = (longlong)(auVar39._4_4_ * fVar22);
        *piVar34 = (uint)(byte)((ulonglong)lVar31 >> 8) * 0x1000000 +
                   ((uint)lVar14 & 0xff) * 0x10000 + (uint)(byte)((ulonglong)lVar14 >> 8) * 0x100 +
                   ((uint)lVar31 & 0xff);
        piVar24 = piVar34 + 1;
        uVar33 = uVar32;
      } while (uVar32 < 0x11);
      uVar27 = uVar27 + 1;
      piVar24 = piVar34 + 0x11;
    } while (uVar27 < 0x11);
    fVar40 = fVar13 * DAT_140b79e48;
    uVar27 = uVar26;
    do {
      piVar24 = piVar9 + 0x11;
      uVar33 = uVar26;
      do {
        uVar32 = uVar33 + 1;
        piVar9 = piVar24 + 1;
        auVar37._0_4_ = fVar40 + (float)uVar33 * fVar13;
        auVar37._4_4_ = fVar40 + (float)uVar27 * fVar13;
        auVar37._8_4_ = fVar40 + 0.0;
        auVar37._12_4_ = fVar40 + 0.0;
        auVar2._4_4_ = uVar1;
        auVar2._0_4_ = uVar1;
        auVar2._8_4_ = uVar1;
        auVar2._12_4_ = uVar1;
        auVar39 = divps(auVar37,auVar2);
        lVar14 = (longlong)(auVar39._0_4_ * fVar22);
        lVar31 = (longlong)(auVar39._4_4_ * fVar22);
        *piVar24 = (uint)(byte)((ulonglong)lVar31 >> 8) * 0x1000000 +
                   ((uint)lVar14 & 0xff) * 0x10000 + (uint)(ushort)((ushort)lVar14 >> 8) * 0x100 +
                   ((uint)lVar31 & 0xff);
        piVar24 = piVar9;
        uVar33 = uVar32;
      } while (uVar32 < 0x10);
      uVar27 = uVar27 + 1;
    } while (uVar27 < 0x10);
    (**(code **)(**(longlong **)(param_1 + 0x78) + 0x40))();
  }
  if ((((*(byte *)(param_1 + 0x10) & 1) != 0) && ((*(byte *)(param_1 + 0x14) & 8) != 0)) &&
     (psVar10 = (short *)(**(code **)(**(longlong **)(param_1 + 0xf0) + 0x38))
                                   (*(longlong **)(param_1 + 0xf0),0,0,2), uVar27 = uVar26,
     psVar10 != (short *)0x0)) {
    do {
      psVar23 = psVar10;
      uVar33 = uVar26;
      do {
        sVar30 = (short)uVar27 * 0x21 + (short)uVar33;
        uVar33 = uVar33 + 1;
        psVar10 = psVar23 + 0xc;
        psVar23[1] = sVar30;
        psVar23[5] = sVar30;
        sVar18 = sVar30 + 0x11;
        psVar23[4] = sVar30 + 1;
        psVar23[0xb] = sVar30 + 1;
        *psVar23 = sVar18;
        psVar23[3] = sVar18;
        psVar23[6] = sVar18;
        psVar23[9] = sVar18;
        psVar23[2] = sVar30 + 0x21;
        psVar23[7] = sVar30 + 0x21;
        psVar23[8] = sVar30 + 0x22;
        psVar23[10] = sVar30 + 0x22;
        psVar23 = psVar10;
      } while (uVar33 < 0x10);
      uVar27 = uVar27 + 1;
    } while (uVar27 < 0x10);
    (**(code **)(**(longlong **)(param_1 + 0xf0) + 0x40))();
  }
  if (((byte)*(undefined4 *)(param_1 + 0x10) & 9) == 9) {
    puVar11 = (undefined8 *)
              (**(code **)(**(longlong **)(param_1 + 0x118) + 0x38))
                        (*(longlong **)(param_1 + 0x118),0,0,2);
    if (puVar11 != (undefined8 *)0x0) {
      lVar14 = 0x21;
      *puVar11 = DAT_140c67480;
      do {
        puVar3 = puVar11;
        puVar3[1] = DAT_140c67480;
        fVar22 = DAT_140c43ec0;
        local_res10 = DAT_140c43ebc;
        lVar14 = lVar14 + -1;
        puVar11 = puVar3 + 1;
      } while (lVar14 != 0);
      plVar16 = puVar3 + 3;
      local_res20 = DAT_140c43ebc;
      puVar3[2] = (ulonglong)(uint)DAT_140c43ebc;
      uVar27 = uVar26;
      do {
        fStackX_1c = (float)uVar27 * fVar22;
        *plVar16 = (ulonglong)(uint)fStackX_1c << 0x20;
        plVar16 = plVar16 + 1;
        uVar33 = uVar26;
        do {
          plVar15 = plVar16;
          uVar32 = uVar33 + 1;
          local_res18 = (float)uVar33 * fVar22;
          *plVar15 = CONCAT44(fStackX_1c,local_res18);
          plVar16 = plVar15 + 1;
          uVar33 = uVar32;
        } while (uVar32 < 0x21);
        uVar27 = uVar27 + 1;
        plVar15[1] = CONCAT44(fStackX_1c,local_res10);
        plVar16 = plVar15 + 2;
      } while (uVar27 < 0x21);
      uStackX_14 = SUB42(local_res10,0);
      uStackX_16 = (undefined2)((uint)local_res10 >> 0x10);
      *plVar16 = (ulonglong)(uint)local_res10 << 0x20;
      plVar16 = plVar15 + 3;
      uVar27 = uVar26;
      do {
        uVar33 = uVar27 + 1;
        plVar15 = plVar16 + 1;
        *plVar16 = CONCAT26(uStackX_16,CONCAT24(uStackX_14,(float)uVar27 * fVar22));
        plVar16 = plVar15;
        uVar27 = uVar33;
      } while (uVar33 < 0x21);
      *plVar15 = CONCAT26(uStackX_16,CONCAT24(uStackX_14,local_res10));
      fStackX_24 = fStackX_1c;
      (**(code **)(**(longlong **)(param_1 + 0x118) + 0x40))();
    }
    local_d8 = 0;
    do {
      plVar16 = *(longlong **)(local_res8 + 0x120 + local_d8 * 8);
      psVar10 = (short *)(**(code **)(*plVar16 + 0x38))(plVar16,0,0,2);
      if (psVar10 != (short *)0x0) {
        sVar30 = 2;
        lVar14 = 0x20;
        do {
          if (uVar26 == 0) {
            local_184 = sVar30 + -1;
            local_13c = 0;
          }
          else if (uVar26 == 1) {
            local_184 = 0x22;
            local_13c = sVar30 + -1;
          }
          else if (uVar26 == 2) {
            local_184 = 0;
            local_13c = 0x23 - sVar30;
          }
          else if (uVar26 == 3) {
            local_13c = 0x22;
            local_184 = 0x23 - sVar30;
          }
          if (uVar26 == 0) {
            local_19c = 0;
            local_11c = sVar30;
          }
          else if (uVar26 == 1) {
            local_19c = sVar30;
            local_11c = 0x22;
          }
          else if (uVar26 == 2) {
            local_19c = 0x22 - sVar30;
            local_11c = 0;
          }
          else if (uVar26 == 3) {
            local_19c = 0x22;
            local_11c = 0x22 - sVar30;
          }
          sVar18 = local_19c * 0x23 + local_11c;
          if (uVar26 == 0) {
            local_144 = sVar30 + -1;
            local_194 = 1;
          }
          else if (uVar26 == 1) {
            local_194 = sVar30 + -1;
            local_144 = 0x21;
          }
          else if (uVar26 == 2) {
            local_194 = 0x23 - sVar30;
            local_144 = 1;
          }
          else if (uVar26 == 3) {
            local_144 = 0x23 - sVar30;
            local_194 = 0x21;
          }
          sVar19 = local_194 * 0x23 + local_144;
          if (uVar26 == 0) {
            local_104 = 1;
            local_18c = sVar30;
          }
          else if (uVar26 == 1) {
            local_18c = 0x21;
            local_104 = sVar30;
          }
          else if (uVar26 == 2) {
            local_18c = 1;
            local_104 = 0x22 - sVar30;
          }
          else if (uVar26 == 3) {
            local_18c = 0x22 - sVar30;
            local_104 = 0x21;
          }
          *psVar10 = local_13c * 0x23 + local_184;
          psVar10[1] = sVar19;
          psVar10[2] = sVar18;
          psVar10[3] = sVar18;
          psVar10[4] = sVar19;
          psVar10[5] = local_104 * 0x23 + local_18c;
          psVar10 = psVar10 + 6;
          sVar30 = sVar30 + 1;
          lVar14 = lVar14 + -1;
        } while (lVar14 != 0);
        sVar30 = 2;
        lVar14 = 0x20;
        do {
          if (uVar26 == 0) {
            local_12c = sVar30 + -1;
            local_164 = 0;
          }
          else if (uVar26 == 1) {
            local_12c = 0;
            local_164 = 0x23 - sVar30;
          }
          else if (uVar26 == 2) {
            local_12c = 0x22;
            local_164 = sVar30 + -1;
          }
          else if (uVar26 == 3) {
            local_12c = 0x23 - sVar30;
            local_164 = 0x22;
          }
          if (uVar26 == 0) {
            local_17c = sVar30 + -1;
            local_114 = 1;
          }
          else if (uVar26 == 1) {
            local_114 = 0x23 - sVar30;
            local_17c = 1;
          }
          else if (uVar26 == 2) {
            local_114 = sVar30 + -1;
            local_17c = 0x21;
          }
          else if (uVar26 == 3) {
            local_17c = 0x23 - sVar30;
            local_114 = 0x21;
          }
          sVar18 = local_17c * 0x23 + local_114;
          if (uVar26 == 0) {
            local_134 = 0;
            local_174 = sVar30;
          }
          else if (uVar26 == 1) {
            local_134 = 0x22 - sVar30;
            local_174 = 0;
          }
          else if (uVar26 == 2) {
            local_134 = sVar30;
            local_174 = 0x22;
          }
          else if (uVar26 == 3) {
            local_134 = 0x22;
            local_174 = 0x22 - sVar30;
          }
          sVar19 = local_174 * 0x23 + local_134;
          if (uVar26 == 0) {
            local_16c = 1;
            local_f8 = sVar30;
          }
          else if (uVar26 == 1) {
            local_16c = 0x22 - sVar30;
            local_f8 = 1;
          }
          else if (uVar26 == 2) {
            local_16c = sVar30;
            local_f8 = 0x21;
          }
          else if (uVar26 == 3) {
            local_16c = 0x21;
            local_f8 = 0x22 - sVar30;
          }
          *psVar10 = local_12c * 0x23 + local_164;
          psVar10[1] = sVar19;
          psVar10[2] = sVar18;
          psVar10[3] = sVar18;
          psVar10[4] = sVar19;
          psVar10[5] = local_f8 * 0x23 + local_16c;
          psVar10 = psVar10 + 6;
          sVar30 = sVar30 + 1;
          lVar14 = lVar14 + -1;
        } while (lVar14 != 0);
        fVar22 = 2.8026e-45;
        local_e8 = 0x20;
        do {
          fVar13 = 2.8026e-45;
          lVar14 = 0x20;
          do {
            if (uVar26 == 0) {
              local_res10 = (float)((int)fVar13 - 1);
              local_res18 = (float)((int)fVar22 - 1);
            }
            else if (uVar26 == 1) {
              local_res18 = (float)((int)fVar13 - 1);
              local_res10 = (float)(0x23 - (int)fVar22);
            }
            else if (uVar26 == 2) {
              local_res10 = (float)((int)fVar22 - 1);
              local_res18 = (float)(0x23 - (int)fVar13);
            }
            else if (uVar26 == 3) {
              local_res10 = (float)(0x23 - (int)fVar13);
              local_res18 = (float)(0x23 - (int)fVar22);
            }
            if (uVar26 == 0) {
              local_1a8 = (float)((int)fVar22 - 1);
              local_res20 = fVar13;
            }
            else if (uVar26 == 1) {
              local_1a8 = fVar13;
              local_res20 = (float)(0x23 - (int)fVar22);
            }
            else if (uVar26 == 2) {
              local_1a8 = (float)(0x22 - (int)fVar13);
              local_res20 = (float)((int)fVar22 - 1);
            }
            else if (uVar26 == 3) {
              local_1a8 = (float)(0x23 - (int)fVar22);
              local_res20 = (float)(0x22 - (int)fVar13);
            }
            sVar30 = SUB42(local_1a8,0) * 0x23 + SUB42(local_res20,0);
            if (uVar26 == 0) {
              local_154 = (float)((int)fVar13 - 1);
              local_10c = fVar22;
            }
            else if (uVar26 == 1) {
              local_154 = (float)(0x22 - (int)fVar22);
              local_10c = (float)((int)fVar13 - 1);
            }
            else if (uVar26 == 2) {
              local_154 = fVar22;
              local_10c = (float)(0x23 - (int)fVar13);
            }
            else if (uVar26 == 3) {
              local_154 = (float)(0x23 - (int)fVar13);
              local_10c = (float)(0x22 - (int)fVar22);
            }
            sVar18 = SUB42(local_10c,0) * 0x23 + SUB42(local_154,0);
            fVar40 = fVar22;
            fVar36 = fVar13;
            if (uVar26 != 0) {
              if (uVar26 == 1) {
                fVar40 = fVar13;
                fVar36 = (float)(0x22 - (int)fVar22);
              }
              else if (uVar26 == 2) {
                fVar40 = (float)(0x22 - (int)fVar13);
                fVar36 = fVar22;
              }
              else {
                fVar40 = local_15c;
                fVar36 = local_124;
                if (uVar26 == 3) {
                  fVar40 = (float)(0x22 - (int)fVar22);
                  fVar36 = (float)(0x22 - (int)fVar13);
                }
              }
            }
            local_124 = fVar36;
            local_15c = fVar40;
            *psVar10 = SUB42(local_res18,0) * 0x23 + SUB42(local_res10,0);
            psVar10[1] = sVar18;
            psVar10[2] = sVar30;
            psVar10[3] = sVar30;
            psVar10[4] = sVar18;
            psVar10[5] = SUB42(local_15c,0) * 0x23 + local_124._0_2_;
            psVar10 = psVar10 + 6;
            fVar13 = (float)((int)fVar13 + 1);
            lVar14 = lVar14 + -1;
          } while (lVar14 != 0);
          fVar22 = (float)((int)fVar22 + 1);
          local_e8 = local_e8 + -1;
        } while (local_e8 != 0);
        sVar30 = 2;
        lVar14 = 0x20;
        do {
          sVar18 = 1;
          if (uVar26 == 0) {
            local_180 = 0x21;
            local_188 = sVar30 + -1;
          }
          else if (uVar26 == 1) {
            local_188 = 0x21;
            local_180 = 0x23 - sVar30;
          }
          else if (uVar26 == 2) {
            local_180 = sVar30 + -1;
            local_188 = sVar18;
          }
          else if (uVar26 == 3) {
            local_180 = 1;
            local_188 = 0x23 - sVar30;
          }
          if (uVar26 == 0) {
            local_14c = sVar30 + -1;
            local_fc = 0x22;
          }
          else if (uVar26 == 1) {
            local_fc = 0x23 - sVar30;
            local_14c = 0x22;
          }
          else if (uVar26 == 2) {
            local_fc = sVar30 + -1;
            local_14c = 0;
          }
          else if (uVar26 == 3) {
            local_14c = 0x23 - sVar30;
            local_fc = 0;
          }
          sVar19 = local_14c * 0x23 + local_fc;
          if (uVar26 == 0) {
            local_1a4 = 0x21;
            local_1a0 = sVar30;
          }
          else if (uVar26 == 1) {
            local_1a4 = 0x22 - sVar30;
            local_1a0 = 0x21;
          }
          else if (uVar26 == 2) {
            local_1a4 = sVar30;
            local_1a0 = 1;
          }
          else if (uVar26 == 3) {
            local_1a4 = 1;
            local_1a0 = 0x22 - sVar30;
          }
          sVar20 = local_1a0 * 0x23 + local_1a4;
          if (uVar26 == 0) {
            local_190 = 0x22;
            local_198 = sVar30;
          }
          else if (uVar26 == 1) {
            local_190 = 0x22 - sVar30;
            local_198 = 0x22;
          }
          else if (uVar26 == 2) {
            local_190 = sVar30;
            local_198 = 0;
          }
          else if (uVar26 == 3) {
            local_190 = 0;
            local_198 = 0x22 - sVar30;
          }
          *psVar10 = local_188 * 0x23 + local_180;
          psVar10[1] = sVar20;
          psVar10[2] = sVar19;
          psVar10[3] = sVar19;
          psVar10[4] = sVar20;
          psVar10[5] = local_198 * 0x23 + local_190;
          psVar10 = psVar10 + 6;
          sVar30 = sVar30 + 1;
          lVar14 = lVar14 + -1;
        } while (lVar14 != 0);
        sVar30 = 2;
        lVar14 = 0x20;
        do {
          psVar23 = psVar10;
          if (uVar26 == 0) {
            local_140 = sVar30 + -1;
            local_148 = 0x21;
          }
          else if (uVar26 == 1) {
            local_148 = sVar30 + -1;
            local_140 = sVar18;
          }
          else if (uVar26 == 2) {
            local_148 = 0x23 - sVar30;
            local_140 = 0x21;
          }
          else if (uVar26 == 3) {
            local_148 = sVar18;
            local_140 = 0x23 - sVar30;
          }
          if (uVar26 == 0) {
            local_170 = 0x21;
            local_178 = sVar30;
          }
          else if (uVar26 == 1) {
            local_178 = 1;
            local_170 = sVar30;
          }
          else if (uVar26 == 2) {
            local_178 = 0x21;
            local_170 = 0x22 - sVar30;
          }
          else if (uVar26 == 3) {
            local_178 = 0x22 - sVar30;
            local_170 = 1;
          }
          sVar19 = local_170 * 0x23 + local_178;
          if (uVar26 == 0) {
            local_168 = sVar30 + -1;
            local_160 = 0x22;
          }
          else if (uVar26 == 1) {
            local_160 = sVar30 + -1;
            local_168 = 0;
          }
          else if (uVar26 == 2) {
            local_160 = 0x23 - sVar30;
            local_168 = 0x22;
          }
          else if (uVar26 == 3) {
            local_168 = 0x23 - sVar30;
            local_160 = 0;
          }
          sVar20 = local_160 * 0x23 + local_168;
          if (uVar26 == 0) {
            local_158 = 0x22;
            local_150 = sVar30;
          }
          else if (uVar26 == 1) {
            local_158 = sVar30;
            local_150 = 0;
          }
          else if (uVar26 == 2) {
            local_158 = 0x22 - sVar30;
            local_150 = 0x22;
          }
          else if (uVar26 == 3) {
            local_158 = 0;
            local_150 = 0x22 - sVar30;
          }
          *psVar23 = local_148 * 0x23 + local_140;
          psVar23[1] = sVar20;
          psVar23[2] = sVar19;
          psVar23[3] = sVar19;
          psVar23[4] = sVar20;
          psVar23[5] = local_158 * 0x23 + local_150;
          sVar30 = sVar30 + 1;
          lVar14 = lVar14 + -1;
          psVar10 = psVar23 + 6;
        } while (lVar14 != 0);
        if (uVar26 == 0) {
          local_138 = 0;
          local_130 = 0;
        }
        else if (uVar26 == 1) {
          local_138 = 0x22;
          local_130 = 0;
        }
        else if (uVar26 == 2) {
          local_138 = 0;
          local_130 = 0x22;
        }
        else if (uVar26 == 3) {
          local_138 = 0x22;
          local_130 = 0x22;
        }
        if (uVar26 == 0) {
          local_128 = 0x22;
          local_120 = 0;
        }
        else if (uVar26 == 1) {
          local_128 = 0x22;
          local_120 = 0x22;
        }
        else if (uVar26 == 2) {
          local_128 = 0;
          local_120 = 0;
        }
        else if (uVar26 == 3) {
          local_128 = 0;
          local_120 = 0x22;
        }
        sVar30 = local_120 * 0x23 + local_128;
        if (uVar26 == 0) {
          local_118 = 0;
          local_110 = 0x22;
        }
        else if (uVar26 == 1) {
          local_118 = 0;
          local_110 = 0;
        }
        else if (uVar26 == 2) {
          local_118 = 0x22;
          local_110 = 0x22;
        }
        else if (uVar26 == 3) {
          local_118 = 0x22;
          local_110 = 0;
        }
        sVar18 = local_110 * 0x23 + local_118;
        if (uVar26 == 0) {
          local_100 = 0x22;
          local_108 = 0x22;
        }
        else if (uVar26 == 1) {
          local_100 = 0;
          local_108 = 0x22;
        }
        else if (uVar26 == 2) {
          local_100 = 0x22;
          local_108 = 0;
        }
        else if (uVar26 == 3) {
          local_100 = 0;
          local_108 = 0;
        }
        psVar23[7] = sVar18;
        psVar23[10] = sVar18;
        psVar23[6] = local_130 * 0x23 + local_138;
        psVar23[0xb] = local_108 * 0x23 + local_100;
        psVar23[8] = sVar30;
        psVar23[9] = sVar30;
        (**(code **)(**(longlong **)(local_res8 + 0x120 + local_d8 * 8) + 0x40))();
      }
      uVar26 = uVar26 + 1;
      local_d8 = local_d8 + 1;
      param_1 = local_res8;
    } while (uVar26 < 4);
  }
  uVar35 = 0;
  puVar11 = (undefined8 *)
            (**(code **)(**(longlong **)(param_1 + 0x158) + 0x38))
                      (*(longlong **)(param_1 + 0x158),0,0,2);
  uVar4 = _UNK_140b65798;
  if (puVar11 != (undefined8 *)0x0) {
    *puVar11 = _DAT_140b65790;
    puVar11[1] = uVar4;
    uVar4 = _UNK_140b657a8;
    puVar11[2] = _DAT_140b657a0;
    puVar11[3] = uVar4;
    uVar4 = _UNK_140b657b8;
    puVar11[4] = _DAT_140b657b0;
    puVar11[5] = uVar4;
    uVar4 = _UNK_140b657c8;
    puVar11[6] = _DAT_140b657c0;
    puVar11[7] = uVar4;
    puVar11[8] = DAT_140b657d0;
    (**(code **)(**(longlong **)(param_1 + 0x158) + 0x40))();
  }
  puVar11 = (undefined8 *)
            (**(code **)(**(longlong **)(param_1 + 0x160) + 0x38))
                      (*(longlong **)(param_1 + 0x160),0,0,2);
  if (puVar11 != (undefined8 *)0x0) {
    *puVar11 = DAT_140b65760;
    puVar11[1] = DAT_140b65768;
    puVar11[2] = DAT_140b65770;
    puVar11[3] = DAT_140b65778;
    puVar11[4] = DAT_140b65780;
    puVar11[5] = DAT_140b65788;
    (**(code **)(**(longlong **)(param_1 + 0x160) + 0x40))();
  }
  puVar8 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x168) + 0x48))
                     (*(longlong **)(param_1 + 0x168),0,&local_res8,2);
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = 0;
    (**(code **)(**(longlong **)(param_1 + 0x168) + 0x50))(*(longlong **)(param_1 + 0x168),0);
  }
  puVar8 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x170) + 0x48))
                     (*(longlong **)(param_1 + 0x170),0,&local_res8,2);
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = 0x7f7f7f7f;
    (**(code **)(**(longlong **)(param_1 + 0x170) + 0x50))(*(longlong **)(param_1 + 0x170),0);
  }
  puVar8 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x178) + 0x48))
                     (*(longlong **)(param_1 + 0x178),0,&local_res8,2);
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = 0xffffffff;
    (**(code **)(**(longlong **)(param_1 + 0x178) + 0x50))(*(longlong **)(param_1 + 0x178),0);
  }
  puVar8 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x1a0) + 0x38))
                     (*(longlong **)(param_1 + 0x1a0),0,0,2);
  uVar1 = DAT_140b7a12c;
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = 0;
    puVar8[1] = uVar1;
    puVar8[2] = 0;
    FUN_1401c96d0(&local_res8);
    FUN_1401c96d0((longlong)&local_res8 + 2);
    FUN_1401c96d0((longlong)&local_res8 + 4);
    puVar8[3] = (float)local_res8;
    *(undefined2 *)(puVar8 + 4) = local_res8._4_2_;
    FUN_1401c96d0(&local_res8);
    FUN_1401c96d0((longlong)&local_res8 + 2);
    fVar13 = DAT_140b7a294;
    puVar8[5] = (float)local_res8;
    fVar22 = DAT_140b79fa0;
    pfVar6 = (float *)(puVar8 + 6);
    uVar28 = uVar35;
    do {
      pfVar25 = pfVar6;
      fVar40 = (float)FUN_1408fc950();
      fVar36 = (float)FUN_1408fe3d0();
      *pfVar25 = fVar40 * fVar22;
      pfVar25[1] = fVar13;
      pfVar25[2] = fVar36 * fVar22;
      FUN_1401c96d0(&local_res10);
      FUN_1401c96d0((longlong)&local_res10 + 2);
      FUN_1401c96d0(&uStackX_14);
      pfVar25[3] = local_res10;
      *(undefined2 *)(pfVar25 + 4) = uStackX_14;
      FUN_1401c96d0(&local_res8);
      FUN_1401c96d0((longlong)&local_res8 + 2);
      uVar26 = (int)uVar28 + 1;
      uVar28 = (ulonglong)uVar26;
      pfVar25[5] = (float)local_res8;
      fVar40 = DAT_140b7a2c8;
      pfVar6 = pfVar25 + 6;
    } while (uVar26 < 0x20);
    pfVar25[6] = 0.0;
    pfVar25[7] = fVar40;
    pfVar25[8] = 0.0;
    FUN_1401c96d0(&local_res8);
    FUN_1401c96d0((longlong)&local_res8 + 2);
    FUN_1401c96d0((longlong)&local_res8 + 4);
    pfVar25[9] = (float)local_res8;
    *(undefined2 *)(pfVar25 + 10) = local_res8._4_2_;
    FUN_1401c96d0(&local_res8);
    FUN_1401c96d0((longlong)&local_res8 + 2);
    pfVar25[0xb] = (float)local_res8;
    (**(code **)(**(longlong **)(param_1 + 0x1a0) + 0x40))();
  }
  psVar10 = (short *)(**(code **)(**(longlong **)(param_1 + 0x1b0) + 0x38))
                               (*(longlong **)(param_1 + 0x1b0),0,0,2);
  if (psVar10 != (short *)0x0) {
    uVar27 = 1;
    uVar26 = 1;
    do {
      uVar21 = (ushort)uVar26;
      psVar10[2] = uVar21;
      uVar26 = uVar26 + 1;
      *psVar10 = 0;
      psVar23 = psVar10 + 3;
      psVar10[1] = (uVar21 & 0x1f) + 1;
      psVar10 = psVar23;
    } while (uVar26 < 0x21);
    do {
      uVar21 = (ushort)uVar27;
      psVar23[2] = uVar21;
      uVar27 = uVar27 + 1;
      psVar23[1] = 0x21;
      *psVar23 = (uVar21 & 0x1f) + 1;
      psVar23 = psVar23 + 3;
    } while (uVar27 < 0x21);
    (**(code **)(**(longlong **)(param_1 + 0x1b0) + 0x40))();
  }
  if (((*(uint *)(param_1 + 0x10) & 0x4800) != 0) &&
     (lVar14 = (**(code **)(**(longlong **)(param_1 + 0x1c8) + 0x38))
                         (*(longlong **)(param_1 + 0x1c8),0,0,2), lVar14 != 0)) {
    uVar21 = 2;
    puVar29 = (ushort *)(lVar14 + 4);
    do {
      uVar12 = uVar21 - 1;
      *puVar29 = uVar21;
      puVar29[-1] = uVar21 - 2;
      uVar7 = uVar21 + 1;
      puVar29[1] = uVar21;
      uVar21 = uVar21 + 4;
      puVar29[-2] = uVar12;
      puVar29[3] = uVar12;
      puVar29[2] = uVar7;
      puVar29 = puVar29 + 6;
    } while (uVar21 < 0xfa2);
    (**(code **)(**(longlong **)(param_1 + 0x1c8) + 0x40))();
  }
  if (((*(uint *)(param_1 + 0x14) & 0x1800000) != 0) &&
     (lVar14 = (**(code **)(**(longlong **)(param_1 + 0x1f0) + 0x48))
                         (*(longlong **)(param_1 + 0x1f0),0,&local_res8,2), lVar14 != 0)) {
    lVar31 = (**(code **)(**(longlong **)(param_1 + 0x1f0) + 0x18))();
    uVar28 = uVar35;
    if (*(int *)(lVar31 + 8) != 0) {
      do {
        uVar17 = uVar35;
        if (*(int *)(lVar31 + 4) != 0) {
          do {
            uVar26 = (uint)uVar17 & 0x18;
            if ((uVar17 & 0x18) == 0) {
              *(undefined4 *)(lVar14 + uVar17 * 4) = 0xff0000;
            }
            else if (uVar26 == 8) {
              *(undefined4 *)(lVar14 + uVar17 * 4) = 0xff00;
            }
            else if (uVar26 == 0x10) {
              *(undefined4 *)(lVar14 + uVar17 * 4) = 0xff;
            }
            else if (uVar26 == 0x18) {
              *(undefined4 *)(lVar14 + uVar17 * 4) = 0xff000000;
            }
            uVar26 = (uint)uVar17 + 1;
            uVar17 = (ulonglong)uVar26;
          } while (uVar26 < *(uint *)(lVar31 + 4));
        }
        uVar26 = (int)uVar28 + 1;
        uVar28 = (ulonglong)uVar26;
        lVar14 = lVar14 + (local_res8 & 0xffffffff);
      } while (uVar26 < *(uint *)(lVar31 + 8));
    }
    (**(code **)(**(longlong **)(param_1 + 0x1f0) + 0x50))(*(longlong **)(param_1 + 0x1f0),0);
  }
  if (((*(uint *)(param_1 + 0x14) & 0x100000) != 0) &&
     (psVar10 = (short *)(**(code **)(**(longlong **)(param_1 + 0x1f8) + 0x38))
                                   (*(longlong **)(param_1 + 0x1f8),0,0,2), uVar28 = uVar35,
     psVar10 != (short *)0x0)) {
    do {
      psVar23 = psVar10;
      uVar17 = uVar35;
      do {
        sVar30 = (short)uVar28 * 0x21 + (short)uVar17;
        uVar26 = (int)uVar17 + 1;
        uVar17 = (ulonglong)uVar26;
        psVar10 = psVar23 + 0xc;
        psVar23[1] = sVar30;
        psVar23[5] = sVar30;
        sVar18 = sVar30 + 0x11;
        psVar23[4] = sVar30 + 1;
        psVar23[0xb] = sVar30 + 1;
        *psVar23 = sVar18;
        psVar23[3] = sVar18;
        psVar23[6] = sVar18;
        psVar23[9] = sVar18;
        psVar23[2] = sVar30 + 0x21;
        psVar23[7] = sVar30 + 0x21;
        psVar23[8] = sVar30 + 0x22;
        psVar23[10] = sVar30 + 0x22;
        psVar23 = psVar10;
      } while (uVar26 < 0x10);
      uVar26 = (int)uVar28 + 1;
      uVar28 = (ulonglong)uVar26;
    } while (uVar26 < 0x10);
    (**(code **)(**(longlong **)(param_1 + 0x1f8) + 0x40))();
  }
  plVar16 = (longlong *)(param_1 + 0x2b0);
  lVar14 = 0xb;
  do {
    if ((longlong *)*plVar16 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar16 + 8))();
      *plVar16 = 0;
    }
    plVar16 = plVar16 + 1;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  for (lVar14 = *(longlong *)(param_1 + 0x230); lVar14 != 0; lVar14 = *(longlong *)(lVar14 + 0x78))
  {
    FUN_140366cd0(lVar14);
  }
  return;
}



==== FUN_140359a20 @ 140359a20 size 1092 ====
CALLERS: FUN_14036f190 FUN_14036e3a0
CALLEES: FUN_1402c8500 FUN_140390f20 FUN_140359840 __security_check_cookie FUN_1401b20f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140359a20(longlong param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined8 uVar27;
  int iVar28;
  undefined4 *puVar29;
  undefined8 uVar30;
  float *pfVar31;
  float *pfVar32;
  float *pfVar33;
  longlong lVar34;
  int iVar35;
  int iVar36;
  longlong lVar37;
  float fVar38;
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auStack_1a8 [32];
  longlong local_188;
  longlong local_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined1 local_158 [64];
  float local_118 [2];
  undefined8 uStack_110;
  undefined1 local_b8 [96];
  ulonglong local_58;
  
  local_58 = DAT_140c0f7b0 ^ (ulonglong)auStack_1a8;
  lVar37 = 6;
  lVar34 = 6;
  puVar29 = (undefined4 *)(param_1 + 0x6f0);
  do {
    puVar2 = (undefined4 *)((param_1 - (param_1 + 0x6f0)) + 0x690 + (longlong)puVar29);
    uVar5 = puVar2[1];
    uVar6 = puVar2[2];
    uVar7 = puVar2[3];
    *puVar29 = *puVar2;
    puVar29[1] = uVar5;
    puVar29[2] = uVar6;
    puVar29[3] = uVar7;
    lVar34 = lVar34 + -1;
    puVar29 = puVar29 + 4;
  } while (lVar34 != 0);
  if (DAT_140c657f0 != 0) {
    local_180 = param_1 + 0xdb0;
    local_188 = param_1 + 0x640;
    FUN_1402c8500(DAT_140c657f0,param_1 + 0x3c0,param_1 + 0x500,param_1 + 0x690);
  }
  iVar35 = 0;
  lVar34 = *(longlong *)(param_1 + 0x1558);
  while (lVar34 != 0) {
    lVar34 = *(longlong *)(param_1 + 0x1558);
    if (*(undefined8 **)(lVar34 + 0x140) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar34 + 0x140) = *(undefined8 *)(lVar34 + 0x148);
    }
    if (*(longlong *)(lVar34 + 0x148) != 0) {
      *(undefined8 *)(*(longlong *)(lVar34 + 0x148) + 0x140) = *(undefined8 *)(lVar34 + 0x140);
    }
    *(undefined8 *)(lVar34 + 0x140) = 0;
    *(undefined8 *)(lVar34 + 0x148) = 0;
    lVar34 = *(longlong *)(param_1 + 0x1558);
  }
  *(undefined8 *)(param_1 + 0x1538) = 0;
  if (*(int *)(param_1 + 0x648) == 0) {
    pfVar31 = (float *)(param_1 + 0x750);
    local_178 = *(undefined8 *)pfVar31;
    uStack_170 = *(undefined8 *)(param_1 + 0x758);
    local_168 = *(undefined8 *)(param_1 + 0x760);
    uStack_160 = *(undefined8 *)(param_1 + 0x768);
    iVar36 = (int)((_DAT_140b7ac50 + *(float *)(param_1 + 0x390) * DAT_140c43fb8) * _DAT_140b7b490);
    iVar28 = (int)((_UNK_140b7ac54 + *(float *)(param_1 + 0x398) * DAT_140c43fb8) * _UNK_140b7b494);
    if ((((*(int *)(param_1 + 0x88c) <= iVar36) && (iVar36 < *(int *)(param_1 + 0x894))) &&
        (*(int *)(param_1 + 0x890) <= iVar28)) && (iVar28 < *(int *)(param_1 + 0x898))) {
      iVar3 = *(int *)(param_1 + 0x89c);
      iVar28 = iVar28 % *(int *)(param_1 + 0x8a0);
      lVar34 = *(longlong *)
                (*(longlong *)(param_1 + 0x8e0) +
                (ulonglong)
                ((uint)(iVar36 % iVar3 < 0) * iVar3 +
                ((uint)(iVar28 < 0) * *(int *)(param_1 + 0x8a0) + iVar28) * iVar3 + iVar36 % iVar3)
                * 8);
      if (lVar34 != 0) {
        for (lVar34 = *(longlong *)(*(longlong *)(lVar34 + 0x18) + 0x28); lVar34 != 0;
            lVar34 = *(longlong *)(lVar34 + 0x18)) {
          plVar4 = *(longlong **)(lVar34 + 8);
          iVar28 = (**(code **)(*plVar4 + 0x18))(plVar4);
          if ((iVar28 == 0) &&
             (iVar28 = (**(code **)(*plVar4 + 0x20))(plVar4,param_1 + 0x390,0,0), iVar28 != 0)) {
            local_178 = CONCAT44(uRam0000000140c78504,_DAT_140c78500);
            uStack_170 = CONCAT44(uRam0000000140c7850c,uRam0000000140c78508);
            local_168 = CONCAT44(uRam0000000140c78514,_DAT_140c78510);
            uStack_160 = CONCAT44(uRam0000000140c7851c,uRam0000000140c78518);
            FUN_140390f20(plVar4,pfVar31,&local_178);
            *(longlong **)(param_1 + 0x1538) = plVar4;
            break;
          }
        }
      }
    }
    if ((*(uint *)(param_1 + 0x80) & 0x1000000) != 0) {
      *(undefined8 *)pfVar31 = local_178;
      *(undefined8 *)(param_1 + 0x758) = uStack_170;
      *(undefined4 *)(param_1 + 0x760) = (undefined4)local_168;
      *(undefined4 *)(param_1 + 0x764) = local_168._4_4_;
      *(undefined4 *)(param_1 + 0x768) = (undefined4)uStack_160;
      *(undefined4 *)(param_1 + 0x76c) = uStack_160._4_4_;
      if ((*(float *)(param_1 + 0x760) < *pfVar31 || *(float *)(param_1 + 0x760) == *pfVar31) ||
         (*(float *)(param_1 + 0x764) < *(float *)(param_1 + 0x754) ||
          *(float *)(param_1 + 0x764) == *(float *)(param_1 + 0x754))) {
        iVar35 = 1;
      }
      *(int *)(param_1 + 0x770) = iVar35;
      if (iVar35 == 0) {
        uVar30 = FUN_140359840(param_1,local_158,pfVar31);
        pfVar31 = (float *)FUN_1401b20f0(local_b8,uVar30);
        fVar8 = *(float *)(param_1 + 0x400);
        fVar9 = *(float *)(param_1 + 0x404);
        fVar10 = *(float *)(param_1 + 0x408);
        fVar11 = *(float *)(param_1 + 0x40c);
        fVar38 = *(float *)(param_1 + 0x410);
        fVar12 = *(float *)(param_1 + 0x414);
        fVar13 = *(float *)(param_1 + 0x418);
        fVar14 = *(float *)(param_1 + 0x41c);
        fVar15 = *(float *)(param_1 + 0x420);
        fVar16 = *(float *)(param_1 + 0x424);
        fVar17 = *(float *)(param_1 + 0x428);
        fVar18 = *(float *)(param_1 + 0x42c);
        fVar19 = *(float *)(param_1 + 0x430);
        fVar20 = *(float *)(param_1 + 0x434);
        fVar21 = *(float *)(param_1 + 0x438);
        fVar22 = *(float *)(param_1 + 0x43c);
        if (pfVar31 < pfVar31 + 0x18) {
          pfVar32 = pfVar31;
          do {
            fVar23 = *pfVar32;
            fVar24 = pfVar32[1];
            fVar25 = pfVar32[2];
            fVar26 = pfVar32[3];
            pfVar33 = pfVar32 + 4;
            pfVar32 = (float *)((longlong)pfVar32 + ((longlong)local_118 - (longlong)pfVar31));
            *pfVar32 = fVar24 * fVar38 + fVar23 * fVar8 + fVar25 * fVar15 + fVar26 * fVar19;
            pfVar32[1] = fVar24 * fVar12 + fVar23 * fVar9 + fVar25 * fVar16 + fVar26 * fVar20;
            pfVar32[2] = fVar24 * fVar13 + fVar23 * fVar10 + fVar25 * fVar17 + fVar26 * fVar21;
            pfVar32[3] = fVar24 * fVar14 + fVar23 * fVar11 + fVar25 * fVar18 + fVar26 * fVar22;
            pfVar32 = pfVar33;
          } while (pfVar33 < pfVar31 + 0x18);
        }
        lVar34 = 6;
        pfVar31 = local_118;
        do {
          fVar8 = *pfVar31;
          fVar9 = pfVar31[1];
          fVar10 = pfVar31[2];
          fVar11 = pfVar31[3];
          auVar40._4_4_ = fVar9 * fVar9;
          auVar40._0_4_ = fVar8 * fVar8;
          auVar40._8_4_ = fVar10 * fVar10;
          auVar40._12_4_ = fVar11 * fVar11;
          auVar39._4_12_ = auVar40._4_12_;
          auVar39._0_4_ = fVar8 * fVar8 + fVar9 * fVar9 + fVar10 * fVar10;
          auVar40 = rsqrtss(auVar39,auVar39);
          fVar38 = auVar40._0_4_;
          *pfVar31 = fVar38 * fVar8;
          pfVar31[1] = fVar38 * fVar9;
          pfVar31[2] = fVar38 * fVar10;
          pfVar31[3] = fVar38 * fVar11;
          lVar34 = lVar34 + -1;
          pfVar31 = pfVar31 + 4;
        } while (lVar34 != 0);
        pfVar31 = local_118;
        do {
          uVar30 = *(undefined8 *)pfVar31;
          uVar27 = *(undefined8 *)(pfVar31 + 2);
          pfVar31 = pfVar31 + 4;
          puVar1 = (undefined8 *)((param_1 - (longlong)local_118) + 0x680 + (longlong)pfVar31);
          *puVar1 = uVar30;
          puVar1[1] = uVar27;
          lVar37 = lVar37 + -1;
        } while (lVar37 != 0);
      }
    }
    *(undefined8 *)(param_1 + 0x1540) = *(undefined8 *)(param_1 + 0x1558);
  }
  else {
    *(undefined8 *)(param_1 + 0x1540) = *(undefined8 *)(param_1 + 0x1558);
  }
  return;
}



==== FUN_14035ac20 @ 14035ac20 size 1210 ====
CALLERS:
CALLEES: FUN_14035bdf0 FUN_140390f20 FUN_140359840 __security_check_cookie FUN_1401b20f0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14035ac20(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  float fVar4;
  longlong *plVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  longlong lVar26;
  int iVar27;
  undefined8 uVar28;
  float *pfVar29;
  float *pfVar30;
  float *pfVar31;
  longlong lVar32;
  longlong lVar33;
  float fVar34;
  float fVar35;
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auStack_178 [32];
  undefined1 local_158 [64];
  float local_118 [24];
  undefined1 local_b8 [96];
  ulonglong local_58;
  
  local_58 = DAT_140c0f7b0 ^ (ulonglong)auStack_178;
  plVar1 = (longlong *)(param_1 + 0x1550);
  lVar33 = *plVar1;
  while (lVar33 != 0) {
    lVar33 = *plVar1;
    if (*(undefined8 **)(lVar33 + 0x130) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar33 + 0x130) = *(undefined8 *)(lVar33 + 0x138);
    }
    if (*(longlong *)(lVar33 + 0x138) != 0) {
      *(undefined8 *)(*(longlong *)(lVar33 + 0x138) + 0x130) = *(undefined8 *)(lVar33 + 0x130);
    }
    *(undefined8 *)(lVar33 + 0x130) = 0;
    *(undefined8 *)(lVar33 + 0x138) = 0;
    lVar33 = *plVar1;
  }
  for (lVar33 = *(longlong *)(param_1 + 0x920); lVar33 != 0; lVar33 = *(longlong *)(lVar33 + 0x590))
  {
    for (lVar32 = *(longlong *)(*(longlong *)(lVar33 + 0x18) + 0x28); lVar32 != 0;
        lVar32 = *(longlong *)(lVar32 + 0x18)) {
      plVar5 = *(longlong **)(lVar32 + 8);
      if ((plVar5[0x28] == 0) && (iVar27 = (**(code **)(*plVar5 + 0x18))(plVar5), iVar27 != 0)) {
        if (*(int *)(param_1 + 0x354) != 0) {
          fVar34 = *(float *)((longlong)plVar5 + 0x34) - *(float *)(param_1 + 0x394);
          if (fVar34 <= 0.0) {
            fVar4 = *(float *)(lVar33 + 0x518);
          }
          else {
            fVar4 = *(float *)(lVar33 + 0x514);
          }
          if (fVar34 * fVar4 < *(float *)(lVar33 + 0x510)) goto LAB_14035addb;
        }
        iVar27 = FUN_14035bdf0(param_1,plVar5 + 4);
        if (iVar27 != 0) {
          if (plVar5[0x26] == 0) {
            plVar5[0x26] = (longlong)plVar1;
            plVar2 = plVar5 + 0x27;
            *plVar2 = *plVar1;
            *plVar1 = (longlong)plVar5;
            if (*plVar2 != 0) {
              *(longlong **)(*plVar2 + 0x130) = plVar2;
            }
          }
          plVar2 = (longlong *)(param_1 + 0x1558);
          if (plVar5[0x28] == 0) {
            plVar5[0x28] = (longlong)plVar2;
            plVar3 = plVar5 + 0x29;
            *plVar3 = *plVar2;
            *plVar2 = (longlong)plVar5;
            if (*plVar3 != 0) {
              *(longlong **)(*plVar3 + 0x140) = plVar3;
            }
          }
          lVar26 = *(longlong *)(param_1 + 0x758);
          plVar5[0x16] = *(longlong *)(param_1 + 0x750);
          plVar5[0x17] = lVar26;
          uVar6 = *(undefined4 *)(param_1 + 0x764);
          uVar7 = *(undefined4 *)(param_1 + 0x768);
          uVar8 = *(undefined4 *)(param_1 + 0x76c);
          *(undefined4 *)(plVar5 + 0x18) = *(undefined4 *)(param_1 + 0x760);
          *(undefined4 *)((longlong)plVar5 + 0xc4) = uVar6;
          *(undefined4 *)(plVar5 + 0x19) = uVar7;
          *(undefined4 *)((longlong)plVar5 + 0xcc) = uVar8;
        }
      }
LAB_14035addb:
    }
  }
  lVar33 = *plVar1;
  plVar1 = (longlong *)(param_1 + 0x1558);
  *(longlong *)(param_1 + 0x1548) = *plVar1;
  for (; lVar33 != 0; lVar33 = *(longlong *)(lVar33 + 0x138)) {
    FUN_140390f20(lVar33,lVar33 + 0xb0,0);
  }
  if ((*(uint *)(param_1 + 0x80) & 0x1000000) == 0) {
    for (lVar33 = *(longlong *)(param_1 + 0x920); lVar33 != 0;
        lVar33 = *(longlong *)(lVar33 + 0x590)) {
      for (lVar32 = *(longlong *)(*(longlong *)(lVar33 + 0x18) + 0x28); lVar32 != 0;
          lVar32 = *(longlong *)(lVar32 + 0x18)) {
        plVar5 = *(longlong **)(lVar32 + 8);
        if ((plVar5[0x28] == 0) && (iVar27 = (**(code **)(*plVar5 + 0x18))(plVar5), iVar27 == 0)) {
          if (*(int *)(param_1 + 0x354) != 0) {
            fVar34 = *(float *)((longlong)plVar5 + 0x34) - *(float *)(param_1 + 0x394);
            if (fVar34 <= 0.0) {
              fVar4 = *(float *)(lVar33 + 0x518);
            }
            else {
              fVar4 = *(float *)(lVar33 + 0x514);
            }
            if (fVar34 * fVar4 < *(float *)(lVar33 + 0x510)) goto LAB_14035af2c;
          }
          iVar27 = FUN_14035bdf0(param_1,plVar5 + 4);
          if (iVar27 != 0) {
            if (plVar5[0x28] == 0) {
              plVar5[0x28] = (longlong)plVar1;
              plVar2 = plVar5 + 0x29;
              *plVar2 = *plVar1;
              *plVar1 = (longlong)plVar5;
              if (*plVar2 != 0) {
                *(longlong **)(*plVar2 + 0x140) = plVar2;
              }
            }
            lVar26 = *(longlong *)(param_1 + 0x758);
            plVar5[0x16] = *(longlong *)(param_1 + 0x750);
            plVar5[0x17] = lVar26;
            uVar6 = *(undefined4 *)(param_1 + 0x764);
            uVar7 = *(undefined4 *)(param_1 + 0x768);
            uVar8 = *(undefined4 *)(param_1 + 0x76c);
            *(undefined4 *)(plVar5 + 0x18) = *(undefined4 *)(param_1 + 0x760);
            *(undefined4 *)((longlong)plVar5 + 0xc4) = uVar6;
            *(undefined4 *)(plVar5 + 0x19) = uVar7;
            *(undefined4 *)((longlong)plVar5 + 0xcc) = uVar8;
          }
        }
LAB_14035af2c:
      }
    }
  }
  for (lVar33 = *plVar1; lVar33 != 0; lVar33 = *(longlong *)(lVar33 + 0x148)) {
    uVar28 = FUN_140359840(param_1,local_158,lVar33 + 0xb0);
    pfVar29 = (float *)FUN_1401b20f0(local_b8,uVar28);
    fVar34 = *(float *)(param_1 + 0x400);
    fVar4 = *(float *)(param_1 + 0x404);
    fVar9 = *(float *)(param_1 + 0x408);
    fVar10 = *(float *)(param_1 + 0x40c);
    fVar35 = *(float *)(param_1 + 0x410);
    fVar11 = *(float *)(param_1 + 0x414);
    fVar12 = *(float *)(param_1 + 0x418);
    fVar13 = *(float *)(param_1 + 0x41c);
    fVar14 = *(float *)(param_1 + 0x420);
    fVar15 = *(float *)(param_1 + 0x424);
    fVar16 = *(float *)(param_1 + 0x428);
    fVar17 = *(float *)(param_1 + 0x42c);
    fVar18 = *(float *)(param_1 + 0x430);
    fVar19 = *(float *)(param_1 + 0x434);
    fVar20 = *(float *)(param_1 + 0x438);
    fVar21 = *(float *)(param_1 + 0x43c);
    if (pfVar29 < pfVar29 + 0x18) {
      pfVar30 = pfVar29;
      do {
        fVar22 = *pfVar30;
        fVar23 = pfVar30[1];
        fVar24 = pfVar30[2];
        fVar25 = pfVar30[3];
        pfVar31 = pfVar30 + 4;
        pfVar30 = (float *)((longlong)pfVar30 + ((longlong)local_118 - (longlong)pfVar29));
        *pfVar30 = fVar23 * fVar35 + fVar22 * fVar34 + fVar24 * fVar14 + fVar25 * fVar18;
        pfVar30[1] = fVar23 * fVar11 + fVar22 * fVar4 + fVar24 * fVar15 + fVar25 * fVar19;
        pfVar30[2] = fVar23 * fVar12 + fVar22 * fVar9 + fVar24 * fVar16 + fVar25 * fVar20;
        pfVar30[3] = fVar23 * fVar13 + fVar22 * fVar10 + fVar24 * fVar17 + fVar25 * fVar21;
        pfVar30 = pfVar31;
      } while (pfVar31 < pfVar29 + 0x18);
    }
    lVar32 = 6;
    pfVar29 = local_118;
    do {
      fVar34 = *pfVar29;
      fVar4 = pfVar29[1];
      fVar9 = pfVar29[2];
      fVar10 = pfVar29[3];
      auVar37._4_4_ = fVar4 * fVar4;
      auVar37._0_4_ = fVar34 * fVar34;
      auVar37._8_4_ = fVar9 * fVar9;
      auVar37._12_4_ = fVar10 * fVar10;
      auVar36._4_12_ = auVar37._4_12_;
      auVar36._0_4_ = fVar34 * fVar34 + fVar4 * fVar4 + fVar9 * fVar9;
      auVar37 = rsqrtss(auVar36,auVar36);
      fVar35 = auVar37._0_4_;
      *pfVar29 = fVar35 * fVar34;
      pfVar29[1] = fVar35 * fVar4;
      pfVar29[2] = fVar35 * fVar9;
      pfVar29[3] = fVar35 * fVar10;
      lVar32 = lVar32 + -1;
      pfVar29 = pfVar29 + 4;
    } while (lVar32 != 0);
    pfVar29 = local_118;
    lVar32 = 6;
    do {
      fVar34 = *pfVar29;
      fVar4 = pfVar29[1];
      fVar9 = pfVar29[2];
      fVar10 = pfVar29[3];
      pfVar29 = pfVar29 + 4;
      pfVar30 = (float *)((lVar33 - (longlong)local_118) + 0xc0 + (longlong)pfVar29);
      *pfVar30 = fVar34;
      pfVar30[1] = fVar4;
      pfVar30[2] = fVar9;
      pfVar30[3] = fVar10;
      lVar32 = lVar32 + -1;
    } while (lVar32 != 0);
  }
  return;
}



==== FUN_14035b910 @ 14035b910 size 803 ====
CALLERS:
CALLEES: FUN_14035bdf0

void FUN_14035b910(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  float fVar4;
  int iVar5;
  ulonglong uVar6;
  float *pfVar7;
  float *pfVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  float fVar12;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  float fStack_40;
  float fStack_30;
  
  plVar1 = (longlong *)(param_1 + 0x1508);
  lVar11 = *plVar1;
  while (lVar11 != 0) {
    if (*(undefined8 **)(lVar11 + 0x1e8) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar11 + 0x1e8) = *(undefined8 *)(lVar11 + 0x1f0);
    }
    if (*(longlong *)(lVar11 + 0x1f0) != 0) {
      *(undefined8 *)(*(longlong *)(lVar11 + 0x1f0) + 0x1e8) = *(undefined8 *)(lVar11 + 0x1e8);
    }
    *(undefined8 *)(lVar11 + 0x1e8) = 0;
    *(undefined8 *)(lVar11 + 0x1f0) = 0;
    lVar11 = *plVar1;
  }
  lVar11 = *(longlong *)(param_1 + 0x920);
  do {
    if (lVar11 == 0) {
      plVar2 = *(longlong **)(param_1 + 0x1558);
      do {
        if (plVar2 == (longlong *)0x0) {
          return;
        }
        iVar5 = (**(code **)(*plVar2 + 0x18))(plVar2);
        if (iVar5 == 0) {
          for (lVar11 = plVar2[0x12]; lVar11 != 0; lVar11 = *(longlong *)(lVar11 + 0x18)) {
            lVar10 = *(longlong *)(lVar11 + 8);
            if (((*(longlong *)(lVar10 + 0x1e8) == 0) && (0.0 < *(float *)(lVar10 + 0x110))) &&
               (*(longlong *)(lVar10 + 0x1f8) == 0)) {
              pfVar8 = (float *)(plVar2 + 0x1a);
              uVar6 = 0;
              pfVar7 = pfVar8;
              do {
                if (*(float *)(lVar10 + 400) <
                    *(float *)(lVar10 + 0x180) * *pfVar7 + *(float *)(lVar10 + 0x184) * pfVar7[1] +
                    *(float *)(lVar10 + 0x188) * pfVar7[2] + pfVar7[3]) goto LAB_14035bbfc;
                uVar6 = uVar6 + 1;
                pfVar7 = pfVar7 + 4;
              } while (uVar6 < 6);
              uVar6 = 0;
              do {
                if (0.0 < (float)(~-(uint)(0.0 < *pfVar8) & *(uint *)(lVar10 + 0x170) |
                                 -(uint)(0.0 < *pfVar8) & *(uint *)(lVar10 + 0x160)) * *pfVar8 +
                          (float)(~-(uint)(0.0 < pfVar8[1]) & *(uint *)(lVar10 + 0x174) |
                                 -(uint)(0.0 < pfVar8[1]) & *(uint *)(lVar10 + 0x164)) * pfVar8[1] +
                          (float)(~-(uint)(0.0 < pfVar8[2]) & *(uint *)(lVar10 + 0x178) |
                                 -(uint)(0.0 < pfVar8[2]) & *(uint *)(lVar10 + 0x168)) * pfVar8[2] +
                          pfVar8[3]) goto LAB_14035bbfc;
                uVar6 = uVar6 + 1;
                pfVar8 = pfVar8 + 4;
              } while (uVar6 < 6);
              *(longlong **)(lVar10 + 0x1e8) = plVar1;
              plVar3 = (longlong *)(lVar10 + 0x1f0);
              *plVar3 = *plVar1;
              *plVar1 = lVar10;
              if (*plVar3 != 0) {
                *(longlong **)(*plVar3 + 0x1e8) = plVar3;
              }
            }
LAB_14035bbfc:
          }
        }
        plVar2 = (longlong *)plVar2[0x29];
      } while( true );
    }
    for (lVar10 = *(longlong *)(*(longlong *)(lVar11 + 0x18) + 0x50); lVar10 != 0;
        lVar10 = *(longlong *)(lVar10 + 0x18)) {
      lVar9 = *(longlong *)(lVar10 + 8);
      if (((*(longlong *)(lVar9 + 0x1e8) == 0) && (*(int *)(lVar9 + 0x1c0) != 0)) &&
         ((0.0 < *(float *)(lVar9 + 0x110) && (*(longlong *)(lVar9 + 0x1f8) == 0)))) {
        auVar14 = minps(*(undefined1 (*) [16])(lVar11 + 0xd0),*(undefined1 (*) [16])(lVar9 + 0x170))
        ;
        auVar13 = maxps(*(undefined1 (*) [16])(lVar11 + 0xc0),*(undefined1 (*) [16])(lVar9 + 0x160))
        ;
        if (auVar13._0_4_ < auVar14._0_4_) {
          fStack_40 = auVar13._8_4_;
          fStack_30 = auVar14._8_4_;
          if (fStack_40 < fStack_30) {
            if (*(int *)(param_1 + 0x354) != 0) {
              fVar12 = *(float *)(lVar9 + 0x174) - *(float *)(param_1 + 0x394);
              if (fVar12 <= 0.0) {
                fVar4 = *(float *)(lVar11 + 0x518);
              }
              else {
                fVar4 = *(float *)(lVar11 + 0x514);
              }
              if (fVar12 * fVar4 < *(float *)(lVar11 + 0x510)) goto LAB_14035ba99;
            }
            iVar5 = FUN_14035bdf0(param_1);
            if (iVar5 != 0) {
              *(longlong **)(lVar9 + 0x1e8) = plVar1;
              plVar2 = (longlong *)(lVar9 + 0x1f0);
              *plVar2 = *plVar1;
              *plVar1 = lVar9;
              if (*plVar2 != 0) {
                *(longlong **)(*plVar2 + 0x1e8) = plVar2;
              }
            }
          }
        }
      }
LAB_14035ba99:
    }
    lVar11 = *(longlong *)(lVar11 + 0x590);
  } while( true );
}



==== FUN_14035c090 @ 14035c090 size 1466 ====
CALLERS: FUN_14036b4c0 FUN_14036b3d0
CALLEES: FUN_14037cc30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14035c090(longlong param_1,int *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  undefined1 auVar25 [16];
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined1 auVar32 [16];
  float fVar33;
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  float fVar36;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined4 local_158 [8];
  float local_138;
  float fStack_130;
  float local_128;
  float fStack_120;
  
  iVar3 = *param_2;
  if ((((*(int *)(param_1 + 0x8d0) <= iVar3) && (iVar3 < *(int *)(param_1 + 0x8d8))) &&
      (iVar10 = param_2[1], *(int *)(param_1 + 0x8d4) <= iVar10)) &&
     (iVar10 < *(int *)(param_1 + 0x8dc))) {
    iVar4 = *(int *)(param_1 + 0x89c);
    local_158[0] = 0xffffffff;
    iVar10 = iVar10 % *(int *)(param_1 + 0x8a0);
    lVar5 = *(longlong *)
             (*(longlong *)(param_1 + 0x8e0) +
             (ulonglong)
             ((uint)(iVar3 % iVar4 < 0) * iVar4 +
             ((uint)(iVar10 < 0) * *(int *)(param_1 + 0x8a0) + iVar10) * iVar4 + iVar3 % iVar4) * 8)
    ;
    if (*(longlong *)(lVar5 + 0x5a8) != 0) {
      FUN_14037cc30(lVar5,local_158);
    }
    fVar9 = DAT_140c7ac64;
    fVar8 = fRam0000000140c77878;
    fVar7 = fRam0000000140c77874;
    uVar6 = DAT_140b7b530;
    auVar32 = maxps(*(undefined1 (*) [16])(lVar5 + 0xd0),*(undefined1 (*) [16])(lVar5 + 0x3c0));
    fVar11 = 0.0 - _DAT_140c77870;
    fVar12 = 0.0 - fRam0000000140c77874;
    fVar13 = 0.0 - fRam0000000140c77878;
    fVar15 = DAT_140c7ac58 * fRam0000000140c77874 - DAT_140c7ac54 * fRam0000000140c77878;
    fVar18 = DAT_140c7ac50 * fRam0000000140c77878 - DAT_140c7ac58 * _DAT_140c77870;
    fVar21 = DAT_140c7ac54 * _DAT_140c77870 - DAT_140c7ac50 * fRam0000000140c77874;
    fVar24 = fRam0000000140c7ac5c * fRam0000000140c7787c -
             fRam0000000140c7ac5c * fRam0000000140c7787c;
    auVar25._4_4_ = fVar18 * fVar18;
    auVar25._0_4_ = fVar15 * fVar15;
    auVar25._8_4_ = fVar21 * fVar21;
    auVar25._12_4_ = fVar24 * fVar24;
    auVar39._4_12_ = auVar25._4_12_;
    auVar39._0_4_ = fVar15 * fVar15 + fVar18 * fVar18 + fVar21 * fVar21;
    auVar25 = rsqrtss(auVar39,auVar39);
    fVar26 = auVar25._0_4_;
    fVar15 = fVar26 * fVar15;
    fVar18 = fVar26 * fVar18;
    fVar21 = fVar26 * fVar21;
    fVar26 = fVar26 * fVar24;
    fVar30 = 0.0 - fVar15;
    fVar31 = 0.0 - fVar21;
    fVar16 = fVar21 * DAT_140c7ac54 - fVar18 * DAT_140c7ac58;
    fVar19 = fVar15 * DAT_140c7ac58 - fVar21 * DAT_140c7ac50;
    fVar22 = fVar18 * DAT_140c7ac50 - fVar15 * DAT_140c7ac54;
    fVar24 = fVar26 * fRam0000000140c7ac5c - fVar26 * fRam0000000140c7ac5c;
    auVar34._4_4_ = fVar19 * fVar19;
    auVar34._0_4_ = fVar16 * fVar16;
    auVar34._8_4_ = fVar22 * fVar22;
    auVar34._12_4_ = fVar24 * fVar24;
    auVar35._4_12_ = auVar34._4_12_;
    auVar35._0_4_ = fVar16 * fVar16 + fVar19 * fVar19 + fVar22 * fVar22;
    auVar25 = rsqrtss(auVar35,auVar35);
    fVar33 = auVar25._0_4_;
    fVar16 = fVar33 * fVar16;
    fVar22 = fVar33 * fVar22;
    fVar17 = fRam0000000140c77878 * fVar18 - fRam0000000140c77874 * fVar21;
    fVar20 = _DAT_140c77870 * fVar21 - fRam0000000140c77878 * fVar15;
    fVar23 = fRam0000000140c77874 * fVar15 - _DAT_140c77870 * fVar18;
    fVar24 = fRam0000000140c7787c * fVar26 - fRam0000000140c7787c * fVar26;
    auVar37._4_4_ = fVar20 * fVar20;
    auVar37._0_4_ = fVar17 * fVar17;
    auVar37._8_4_ = fVar23 * fVar23;
    auVar37._12_4_ = fVar24 * fVar24;
    auVar38._4_12_ = auVar37._4_12_;
    auVar25 = minps(*(undefined1 (*) [16])(lVar5 + 0xc0),*(undefined1 (*) [16])(lVar5 + 0x3b0));
    auVar38._0_4_ = fVar17 * fVar17 + fVar20 * fVar20 + fVar23 * fVar23;
    auVar39 = rsqrtss(auVar38,auVar38);
    fVar36 = auVar39._0_4_;
    fVar17 = fVar36 * fVar17;
    fVar23 = fVar36 * fVar23;
    fStack_130 = auVar25._8_4_;
    fStack_120 = auVar32._8_4_;
    fVar26 = auVar32._4_4_;
    fVar24 = fStack_120;
    if (fVar21 < 0.0) {
      fVar24 = fStack_130;
    }
    local_128 = auVar32._0_4_;
    local_138 = auVar25._0_4_;
    fVar27 = local_128;
    if (fVar15 < 0.0) {
      fVar27 = local_138;
    }
    fVar1 = fStack_120;
    if (fVar31 < 0.0) {
      fVar1 = fStack_130;
    }
    fVar28 = local_128;
    if (fVar30 < 0.0) {
      fVar28 = local_138;
    }
    fVar2 = fStack_120;
    if (fVar22 < 0.0) {
      fVar2 = fStack_130;
    }
    fVar29 = local_128;
    if (fVar16 < 0.0) {
      fVar29 = local_138;
    }
    if (0.0 <= fVar23) {
      fStack_130 = fStack_120;
    }
    if (0.0 <= fVar17) {
      local_138 = local_128;
    }
    fVar14 = (float)((uint)(_DAT_140c77870 * 0.0 + fVar26 * fRam0000000140c77874 +
                           fRam0000000140c77878 * 0.0) ^ DAT_140b7b530);
    *param_3 = _DAT_140c77870;
    param_3[1] = fVar7;
    param_3[2] = fVar8;
    param_3[3] = fVar14;
    param_3[4] = fVar11;
    param_3[5] = fVar12;
    param_3[6] = fVar13;
    param_3[7] = (float)((uint)(fVar11 * 0.0 + fVar9 * fVar12 + fVar13 * 0.0) ^ uVar6);
    param_3[0xc] = fVar15;
    param_3[0xd] = fVar18;
    param_3[0xe] = fVar21;
    param_3[0xf] = (float)((uint)(fVar27 * fVar15 + fVar26 * fVar18 + fVar24 * fVar21) ^ uVar6);
    param_3[8] = fVar30;
    param_3[9] = 0.0 - fVar18;
    param_3[10] = fVar31;
    param_3[0xb] = (float)((uint)(fVar28 * fVar30 + fVar26 * (0.0 - fVar18) + fVar1 * fVar31) ^
                          uVar6);
    param_3[0x14] = fVar16;
    param_3[0x15] = fVar33 * fVar19;
    param_3[0x16] = fVar22;
    param_3[0x17] =
         (float)((uint)(fVar29 * fVar16 + fVar26 * fVar33 * fVar19 + fVar2 * fVar22) ^ uVar6);
    param_3[0x10] = fVar17;
    param_3[0x11] = fVar36 * fVar20;
    param_3[0x12] = fVar23;
    param_3[0x13] =
         (float)((uint)(local_138 * fVar17 + fVar26 * fVar36 * fVar20 + fStack_130 * fVar23) ^ uVar6
                );
    return 0;
  }
  return 0x80004005;
}



==== FUN_14035ce90 @ 14035ce90 size 3399 ====
CALLERS: FUN_14035ff70
CALLEES: FUN_1408fe3d0 FUN_140354aa0 FUN_1408fccb0 __security_check_cookie FUN_1401af0b0 FUN_140262d50 FUN_1408fc950 FUN_1401afb10

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14035ce90(longlong *param_1)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  longlong lVar6;
  int *piVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong lVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined1 auStack_4d8 [32];
  ulonglong local_4b8;
  undefined4 local_4b0;
  undefined4 local_4a8;
  undefined4 local_4a0;
  undefined8 local_498;
  undefined8 uStack_490;
  undefined8 local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  longlong local_448 [6];
  undefined4 local_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 local_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined4 uStack_3fc;
  longlong local_3f8;
  longlong lStack_3f0;
  longlong local_3e8;
  longlong lStack_3e0;
  longlong local_3d8;
  longlong lStack_3d0;
  undefined4 local_3c8;
  undefined4 uStack_3c4;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 local_3b8;
  undefined4 uStack_3b4;
  undefined4 uStack_3b0;
  undefined4 uStack_3ac;
  undefined4 local_3a8;
  undefined4 uStack_3a4;
  undefined4 uStack_3a0;
  undefined4 uStack_39c;
  undefined4 local_398;
  undefined4 uStack_394;
  undefined4 uStack_390;
  undefined4 uStack_38c;
  undefined4 local_388;
  undefined4 uStack_384;
  undefined4 uStack_380;
  undefined4 uStack_37c;
  float local_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  float local_368;
  float fStack_364;
  float fStack_360;
  float fStack_35c;
  float local_358;
  float local_348;
  float fStack_344;
  float fStack_340;
  float fStack_33c;
  float local_338;
  float fStack_334;
  float fStack_330;
  float fStack_32c;
  float local_328;
  float local_318;
  float fStack_314;
  float fStack_310;
  float fStack_30c;
  float local_308;
  float fStack_304;
  float fStack_300;
  float fStack_2fc;
  float local_2f8;
  undefined8 local_2e8;
  undefined8 local_2e0;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  float local_288;
  float local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  float local_26c;
  float local_268;
  longlong *local_258;
  longlong *local_250;
  longlong local_248 [18];
  undefined1 local_1b8 [80];
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined4 local_120 [18];
  ulonglong local_d8;
  undefined8 extraout_XMM0_Qb;
  
  local_d8 = DAT_140c0f7b0 ^ (ulonglong)auStack_4d8;
  uVar9 = 0;
  local_4b8 = 0;
  (**(code **)(*param_1 + 0x1b8))(param_1,param_1 + 0x72,local_1b8,0xe00);
  local_358 = *(float *)(param_1 + 0x158);
  fVar15 = *(float *)(param_1 + 0x154);
  fStack_374 = *(float *)((longlong)param_1 + 0xaa4);
  fStack_370 = *(float *)(param_1 + 0x155);
  fStack_36c = *(float *)((longlong)param_1 + 0xaac);
  fVar27 = *(float *)(param_1 + 0x156);
  fStack_364 = *(float *)((longlong)param_1 + 0xab4);
  fStack_360 = *(float *)(param_1 + 0x157);
  fStack_35c = *(float *)((longlong)param_1 + 0xabc);
  fVar28 = *(float *)(param_1 + 0x15a);
  fStack_344 = *(float *)((longlong)param_1 + 0xad4);
  fStack_340 = *(float *)(param_1 + 0x15b);
  fStack_33c = *(float *)((longlong)param_1 + 0xadc);
  local_328 = *(float *)(param_1 + 0x15e);
  local_2f8 = *(float *)(param_1 + 0x164);
  fVar29 = *(float *)(param_1 + 0x15c);
  fStack_334 = *(float *)((longlong)param_1 + 0xae4);
  fStack_330 = *(float *)(param_1 + 0x15d);
  fStack_32c = *(float *)((longlong)param_1 + 0xaec);
  fVar19 = *(float *)(param_1 + 0x160);
  fStack_314 = *(float *)((longlong)param_1 + 0xb04);
  fStack_310 = *(float *)(param_1 + 0x161);
  fStack_30c = *(float *)((longlong)param_1 + 0xb0c);
  fVar20 = *(float *)(param_1 + 0x162);
  fStack_304 = *(float *)((longlong)param_1 + 0xb14);
  fStack_300 = *(float *)(param_1 + 0x163);
  fStack_2fc = *(float *)((longlong)param_1 + 0xb1c);
  local_498 = param_1 + 0x166;
  uStack_490 = param_1 + 0x16a;
  local_378 = fVar15;
  local_368 = fVar27;
  local_348 = fVar28;
  local_338 = fVar29;
  local_318 = fVar19;
  local_308 = fVar20;
  local_258 = local_498;
  local_250 = uStack_490;
  FUN_1401af0b0(&local_258,&local_2e8);
  fVar23 = DAT_140b79fa0;
  fVar3 = DAT_140b79ed0;
  fStack_374 = fStack_374 + local_2e8._4_4_;
  fStack_344 = fStack_344 + local_2b4;
  local_378 = fVar15 + (float)local_2e8;
  fStack_314 = fStack_314 + local_284;
  fStack_370 = fStack_370 + (float)local_2e0;
  local_348 = fVar28 + local_2b8;
  fStack_340 = fStack_340 + local_2b0;
  fStack_310 = fStack_310 + local_280;
  fStack_36c = fStack_36c + local_2e0._4_4_;
  local_318 = fVar19 + local_288;
  fStack_33c = fStack_33c + local_2ac;
  fStack_30c = fStack_30c + local_27c;
  local_368 = fVar27 + local_2d8;
  local_338 = fVar29 + local_2a8;
  local_308 = fVar20 + local_278;
  fVar15 = *(float *)(param_1 + 0x16a);
  fVar27 = *(float *)((longlong)param_1 + 0xb54);
  fVar28 = *(float *)(param_1 + 0x16b);
  fVar29 = *(float *)((longlong)param_1 + 0xb5c);
  fStack_364 = fStack_364 + local_2d4;
  fStack_334 = fStack_334 + local_2a4;
  fStack_304 = fStack_304 + local_274;
  fStack_360 = fStack_360 + local_2d0;
  fStack_330 = fStack_330 + local_2a0;
  fStack_300 = fStack_300 + local_270;
  fStack_35c = fStack_35c + local_2cc;
  fStack_32c = fStack_32c + local_29c;
  fStack_2fc = fStack_2fc + local_26c;
  local_358 = local_358 + local_2c8;
  local_328 = local_328 + local_298;
  local_2f8 = local_2f8 + local_268;
  local_418 = (int)param_1[0x166];
  uStack_414 = *(undefined4 *)((longlong)param_1 + 0xb34);
  uStack_410 = (int)param_1[0x167];
  uStack_40c = *(undefined4 *)((longlong)param_1 + 0xd54);
  local_408 = (int)param_1[0x168];
  uStack_404 = *(undefined4 *)((longlong)param_1 + 0xb44);
  uStack_400 = (int)param_1[0x169];
  local_488 = _DAT_140c78390;
  uStack_480 = uRam0000000140c78398;
  uStack_3fc = (int)param_1[0x1aa];
  local_468 = _DAT_140c783b0;
  uStack_460 = uRam0000000140c783b8;
  local_478 = _DAT_140c783a0;
  uStack_470 = uRam0000000140c783a8;
  local_458 = CONCAT44(uRam0000000140c783c4,_DAT_140c783c0);
  uStack_450 = CONCAT44(uRam0000000140c783cc,uRam0000000140c783c8);
  if ((fVar15 != 0.0) || (fVar28 != 0.0)) {
    fVar21 = _UNK_140b7a4b8 * fVar27 - _UNK_140b7a4b4 * fVar28;
    fVar24 = _DAT_140b7a4b0 * fVar28 - _UNK_140b7a4b8 * fVar15;
    fVar25 = _UNK_140b7a4b4 * fVar15 - _DAT_140b7a4b0 * fVar27;
    fVar26 = _UNK_140b7a4bc * fVar29 - _UNK_140b7a4bc * fVar29;
    fVar19 = fVar24 * fVar24;
    auVar16._4_4_ = fVar19;
    auVar16._0_4_ = fVar19;
    auVar16._8_4_ = fVar19;
    auVar16._12_4_ = fVar19;
    fVar20 = fVar21 * fVar21 + fVar19 + fVar25 * fVar25;
    auVar17._4_4_ = fVar19;
    auVar17._0_4_ = fVar20;
    auVar17._8_4_ = fVar25 * fVar25;
    auVar17._12_4_ = fVar26 * fVar26;
    auVar17 = rsqrtss(auVar16,auVar17);
    fVar19 = auVar17._0_4_;
    fVar19 = (DAT_140b79fa0 - fVar20 * fVar19 * fVar19) * DAT_140b79e48 * fVar19;
    if (fVar19 <= 0.0) {
      fVar19 = 0.0;
    }
    fVar21 = fVar19 * fVar21;
    fVar24 = fVar19 * fVar24;
    fVar25 = fVar19 * fVar25;
    uVar13 = FUN_1408fccb0();
    local_2d8 = (float)(uVar13 ^ DAT_140b7b530);
    fVar20 = (float)FUN_1408fe3d0();
    auVar18._0_8_ = FUN_1408fc950();
    auVar18._8_8_ = extraout_XMM0_Qb;
    fVar14 = (float)auVar18._0_8_;
    fVar30 = fVar3 - fVar14;
    fVar22 = fVar21 * fVar21 + fVar24 * fVar24 + fVar25 * fVar25;
    auVar1._4_4_ = fVar24 * fVar24;
    auVar1._0_4_ = fVar22;
    auVar1._8_4_ = fVar25 * fVar25;
    auVar1._12_4_ = fVar19 * fVar26 * fVar19 * fVar26;
    auVar17 = rsqrtss(auVar18,auVar1);
    fVar19 = auVar17._0_4_;
    fVar19 = (fVar23 - fVar22 * fVar19 * fVar19) * DAT_140b79e48 * fVar19;
    if (fVar19 <= 0.0) {
      fVar19 = 0.0;
    }
    fVar21 = fVar19 * fVar21;
    fVar24 = fVar19 * fVar24;
    fVar19 = fVar19 * fVar25;
    fVar23 = fVar24 * fVar21 * fVar30;
    fVar26 = fVar19 * fVar24 * fVar30;
    fVar25 = fVar19 * fVar21 * fVar30;
    local_488 = CONCAT44(fVar19 * fVar20 + fVar23,fVar21 * fVar21 * fVar30 + fVar14);
    local_478 = CONCAT44(fVar24 * fVar24 * fVar30 + fVar14,fVar23 - fVar19 * fVar20);
    uStack_460 = (ulonglong)(uint)(fVar19 * fVar19 * fVar30 + fVar14);
    uStack_480 = (ulonglong)(uint)(fVar25 - fVar24 * fVar20);
    uStack_470 = (ulonglong)(uint)(fVar26 + fVar21 * fVar20);
    local_468 = CONCAT44(fVar26 - fVar21 * fVar20,fVar25 + fVar24 * fVar20);
    local_458 = _DAT_140b7ad00;
    uStack_450 = _UNK_140b7ad08;
  }
  puVar5 = local_120;
  local_448[0] = 0;
  local_448[1] = 0;
  local_448[2] = 0;
  local_448[3] = 0;
  uVar10 = uVar9;
  do {
    iVar4 = FUN_140354aa0(param_1,*puVar5,local_448 + uVar10);
    if (iVar4 < 0) {
      plVar11 = local_448;
      lVar6 = 4;
      do {
        if ((longlong *)*plVar11 != (longlong *)0x0) {
          (**(code **)(*(longlong *)*plVar11 + 8))();
          *plVar11 = 0;
        }
        plVar11 = plVar11 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      return 0;
    }
    uVar13 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar13;
    puVar5 = puVar5 + 1;
  } while (uVar13 < 4);
  local_4b8 = local_4b8 & 0xffffffff00000000;
  puVar5 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0xc0,0,0);
  if (puVar5 != (undefined4 *)0x0) {
    local_3f8 = param_1[0x78];
    lStack_3f0 = param_1[0x79];
    local_3e8 = param_1[0x7a];
    lStack_3e0 = param_1[0x7b];
    local_498 = &local_488;
    uStack_490 = &local_3f8;
    local_3d8 = param_1[0x7c];
    lStack_3d0 = param_1[0x7d];
    uStack_3bc = (undefined4)((ulonglong)param_1[0x7f] >> 0x20);
    uStack_3c4 = 0;
    uStack_3c0 = 0;
    local_3c8 = 0;
    local_258 = local_498;
    local_250 = uStack_490;
    FUN_1401afb10(&local_258,local_248);
    local_498 = local_248;
    uStack_490 = param_1 + 0xa0;
    local_2e8 = local_498;
    local_2e0 = uStack_490;
    FUN_1401afb10(&local_2e8,&local_3b8);
    *puVar5 = local_3b8;
    puVar5[1] = local_3a8;
    puVar5[2] = local_398;
    puVar5[3] = local_388;
    puVar5[4] = uStack_3b4;
    puVar5[5] = uStack_3a4;
    puVar5[6] = uStack_394;
    puVar5[7] = uStack_384;
    puVar5[8] = uStack_3b0;
    puVar5[9] = uStack_3a0;
    puVar5[10] = uStack_390;
    puVar5[0xb] = uStack_380;
    puVar5[0xc] = uStack_3ac;
    puVar5[0xd] = uStack_39c;
    puVar5[0xe] = uStack_38c;
    puVar5[0xf] = uStack_37c;
    puVar5[0x10] = (undefined4)local_488;
    puVar5[0x11] = (undefined4)local_478;
    puVar5[0x12] = (undefined4)local_468;
    puVar5[0x13] = (undefined4)local_458;
    puVar5[0x14] = local_488._4_4_;
    puVar5[0x15] = local_478._4_4_;
    puVar5[0x16] = local_468._4_4_;
    puVar5[0x17] = local_458._4_4_;
    puVar5[0x18] = (undefined4)uStack_480;
    puVar5[0x19] = (undefined4)uStack_470;
    puVar5[0x1a] = (undefined4)uStack_460;
    puVar5[0x1b] = (undefined4)uStack_450;
    puVar5[0x1c] = uStack_480._4_4_;
    puVar5[0x1d] = uStack_470._4_4_;
    puVar5[0x1e] = uStack_460._4_4_;
    puVar5[0x1f] = uStack_450._4_4_;
    *(undefined8 *)(puVar5 + 0x20) = 0;
    *(undefined8 *)(puVar5 + 0x22) = 0;
    lVar6 = param_1[0x73];
    *(longlong *)(puVar5 + 0x24) = param_1[0x72];
    *(longlong *)(puVar5 + 0x26) = lVar6;
    *(undefined8 *)(puVar5 + 0x28) = local_158;
    *(undefined8 *)(puVar5 + 0x2a) = uStack_150;
    *(undefined8 *)(puVar5 + 0x2c) = local_148;
    *(undefined8 *)(puVar5 + 0x2e) = uStack_140;
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  local_4b8 = local_4b8 & 0xffffffff00000000;
  lVar6 = (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,400,0,0);
  if (lVar6 != 0) {
    lVar12 = lVar6;
    FUN_140262d50(&local_378);
    piVar7 = DAT_140c63750;
    *(float *)(lVar12 + 0x70) = fVar15;
    *(float *)(lVar12 + 0x74) = fVar27;
    *(float *)(lVar12 + 0x78) = fVar28;
    *(float *)(lVar12 + 0x7c) = fVar29;
    *(ulonglong *)(lVar12 + 0x80) = CONCAT44(uStack_414,local_418);
    *(ulonglong *)(lVar12 + 0x88) = CONCAT44(uStack_40c,uStack_410);
    *(ulonglong *)(lVar12 + 0x90) = CONCAT44(uStack_404,local_408);
    *(ulonglong *)(lVar12 + 0x98) = CONCAT44(uStack_3fc,uStack_400);
    *(undefined4 *)(lVar12 + 0xa0) = 0x3f800000;
    iVar4 = DAT_140c43f70;
    if (*piVar7 < DAT_140c43f70) {
      iVar4 = *piVar7;
    }
    *(undefined4 *)(lVar12 + 0xa4) = *(undefined4 *)(&DAT_140c43f80 + (longlong)iVar4 * 4);
    iVar4 = DAT_140c43fd0;
    if (*piVar7 < DAT_140c43fd0) {
      iVar4 = *piVar7;
    }
    *(undefined4 *)(lVar12 + 0xa8) = *(undefined4 *)(&DAT_140c43fe0 + (longlong)iVar4 * 4);
    iVar4 = DAT_140c44030;
    if (*piVar7 < DAT_140c44030) {
      iVar4 = *piVar7;
    }
    fVar15 = (float)FUN_1408fc950(*(float *)(&DAT_140c44040 + (longlong)iVar4 * 4) * DAT_140b79fac);
    *(float *)(lVar6 + 0xac) = fVar15;
    *(float *)(lVar6 + 0xb0) = fVar3 / (fVar3 - fVar15);
    iVar4 = DAT_140c44090;
    if (*piVar7 < DAT_140c44090) {
      iVar4 = *piVar7;
    }
    *(undefined4 *)(lVar6 + 0xb4) = *(undefined4 *)(&DAT_140c440a0 + (longlong)iVar4 * 4);
    iVar4 = DAT_140c440f0;
    if (*piVar7 < DAT_140c440f0) {
      iVar4 = *piVar7;
    }
    *(undefined4 *)(lVar6 + 0xb8) = *(undefined4 *)(&DAT_140c44100 + (longlong)iVar4 * 4);
    *(undefined4 *)(lVar6 + 0xbc) = *(undefined4 *)((longlong)param_1 + 0xd94);
    iVar4 = DAT_140c44150;
    if (*piVar7 < DAT_140c44150) {
      iVar4 = *piVar7;
    }
    *(float *)(lVar6 + 0xc0) = fVar3 / *(float *)(&DAT_140c44160 + (longlong)iVar4 * 4);
    fVar15 = (float)FUN_1408fc950();
    *(float *)(lVar6 + 0xc4) = fVar15;
    *(float *)(lVar6 + 200) = fVar3 / (fVar3 - fVar15);
    iVar4 = DAT_140c441b0;
    if (*piVar7 < DAT_140c441b0) {
      iVar4 = *piVar7;
    }
    *(undefined4 *)(lVar6 + 0xcc) = *(undefined4 *)(&DAT_140c441c0 + (longlong)iVar4 * 4);
    *(int *)(lVar6 + 0xd0) = (int)param_1[0x218];
    *(undefined4 *)(lVar6 + 0xd4) = 0;
    piVar7 = (int *)(**(code **)(*DAT_140c65670 + 0x230))();
    plVar11 = local_448;
    puVar8 = (undefined8 *)(lVar6 + 0x100);
    fVar15 = (fVar3 / (float)*piVar7) * _DAT_140b7ac50;
    fVar27 = (fVar3 / (float)piVar7[1]) * _UNK_140b7ac54;
    fVar28 = _UNK_140b7ac58 * 0.0;
    fVar29 = _UNK_140b7ac5c * 0.0;
    *(ulonglong *)(lVar6 + 0xe0) = CONCAT44(fVar3 / (float)piVar7[1],fVar3 / (float)*piVar7);
    local_498 = (longlong *)CONCAT44(fVar27,fVar15);
    uStack_490 = (longlong *)CONCAT44(fVar29,fVar28);
    *(longlong **)(lVar6 + 0xe8) = local_498;
    *(undefined8 *)(lVar6 + 0xf0) = local_168;
    *(undefined8 *)(lVar6 + 0xf8) = uStack_160;
    do {
      lVar12 = *plVar11;
      local_4b8 = 0;
      uVar2 = *(undefined8 *)(lVar12 + 0x88);
      *puVar8 = *(undefined8 *)(lVar12 + 0x80);
      puVar8[1] = uVar2;
      uVar2 = *(undefined8 *)(lVar12 + 0x98);
      puVar8[2] = *(undefined8 *)(lVar12 + 0x90);
      puVar8[3] = uVar2;
      (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,uVar9,*(undefined8 *)(lVar12 + 0x58),0);
      uVar13 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar13;
      puVar8 = puVar8 + 4;
      plVar11 = plVar11 + 1;
    } while (uVar13 < 4);
    puVar8 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xf8))();
    uVar2 = puVar8[1];
    *(undefined8 *)(lVar6 + 0x180) = *puVar8;
    *(undefined8 *)(lVar6 + 0x188) = uVar2;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  lVar6 = (**(code **)(*DAT_140c65688 + 0xc0))();
  lVar12 = 4;
  local_4b8 = 0;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,4,*(undefined8 *)(lVar6 + 0x38),0);
  uVar9 = (**(code **)(*DAT_140c65688 + 0xd8))();
  lVar6 = (**(code **)(*DAT_140c65688 + 0xc0))();
  local_4b8 = uVar9;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,5,*(undefined8 *)(lVar6 + 0x48),0);
  (**(code **)(*DAT_140c65688 + 0x50))();
  (**(code **)(*DAT_140c65670 + 0x140))(DAT_140c65670,*(undefined8 *)(param_1[2] + 400),0);
  (**(code **)(*DAT_140c65670 + 0x178))(DAT_140c65670,*(undefined8 *)(param_1[2] + 0x198),1);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,0,2,0);
  (**(code **)(*DAT_140c65670 + 0x130))(DAT_140c65670,*(undefined8 *)(param_1[2] + 0x1a0),3,0);
  (**(code **)(*DAT_140c65670 + 0x138))(DAT_140c65670,*(undefined8 *)(param_1[2] + 0x1b0));
  local_4b0 = *(undefined4 *)(param_1[2] + 0x1a8);
  local_4a0 = 1;
  local_4a8 = 0;
  local_4b8 = local_4b8 & 0xffffffff00000000;
  (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,0,*(undefined4 *)(param_1[2] + 0x1b8));
  plVar11 = local_448;
  do {
    if ((longlong *)*plVar11 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar11 + 8))();
      *plVar11 = 0;
    }
    plVar11 = plVar11 + 1;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  return 0;
}



==== FUN_14035dbe0 @ 14035dbe0 size 3444 ====
CALLERS: FUN_14035ff70
CALLEES: __security_check_cookie FUN_14035e960

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14035dbe0(longlong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined1 auStack_498 [32];
  undefined *local_478;
  undefined8 local_470;
  float local_468;
  float fStack_464;
  float fStack_460;
  float fStack_45c;
  undefined1 local_458 [8];
  float fStack_450;
  float fStack_44c;
  float local_448;
  float fStack_444;
  float fStack_440;
  float fStack_43c;
  float local_438;
  float fStack_434;
  float fStack_430;
  float fStack_42c;
  undefined8 local_428;
  undefined8 uStack_420;
  undefined8 local_418;
  undefined8 uStack_410;
  int local_408;
  int local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  float local_3f8;
  float fStack_3f4;
  float fStack_3f0;
  float fStack_3ec;
  float local_3e8;
  float fStack_3e4;
  undefined8 uStack_3e0;
  float local_3d8;
  float fStack_3d4;
  undefined8 uStack_3d0;
  float local_3c8;
  float fStack_3c4;
  undefined8 uStack_3c0;
  float local_3b8;
  float fStack_3b4;
  undefined8 uStack_3b0;
  float local_3a8;
  float fStack_3a4;
  undefined8 uStack_3a0;
  undefined4 local_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  float local_388;
  float fStack_384;
  undefined8 uStack_380;
  float local_378;
  float fStack_374;
  undefined8 uStack_370;
  float local_368;
  float fStack_364;
  undefined8 uStack_360;
  float local_358;
  float fStack_354;
  undefined8 uStack_350;
  float local_348;
  float fStack_344;
  undefined8 uStack_340;
  undefined8 local_338;
  float fStack_330;
  float fStack_32c;
  float local_328;
  float fStack_324;
  undefined8 uStack_320;
  float local_318;
  undefined4 uStack_314;
  float fStack_310;
  float fStack_30c;
  float local_308;
  float fStack_304;
  undefined8 uStack_300;
  undefined4 local_2f8 [2];
  undefined8 local_2f0;
  undefined4 local_2e4;
  undefined4 local_2e0 [2];
  undefined8 local_2d8;
  undefined4 local_2cc;
  undefined4 local_2c8 [2];
  undefined8 local_2c0;
  undefined4 local_2b4;
  undefined4 local_2b0 [2];
  undefined8 local_2a8;
  undefined4 local_29c;
  undefined4 local_298 [2];
  undefined8 local_290;
  undefined4 local_284;
  undefined4 local_280 [2];
  undefined8 local_278;
  undefined4 local_26c;
  undefined8 local_268;
  undefined8 uStack_260;
  int *local_258;
  undefined4 *local_250;
  float local_238;
  float fStack_234;
  float fStack_230;
  float fStack_22c;
  float local_228;
  float fStack_224;
  float fStack_220;
  float fStack_21c;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  float local_1f8;
  float fStack_1f4;
  float fStack_1f0;
  float fStack_1ec;
  float local_1e8;
  float fStack_1e4;
  float fStack_1e0;
  float fStack_1dc;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  float local_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float local_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  float local_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float local_188;
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  undefined8 local_178;
  undefined8 uStack_170;
  float local_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float local_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float local_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  undefined8 local_138;
  undefined8 uStack_130;
  float local_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined1 local_118 [16];
  float local_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  undefined1 local_f8 [16];
  float local_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float local_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  ulonglong local_b0;
  
  local_b0 = DAT_140c0f7b0 ^ (ulonglong)auStack_498;
  (**(code **)(*DAT_140c65670 + 0x1f8))();
  (**(code **)(*DAT_140c65670 + 0x200))();
  (**(code **)(*DAT_140c65670 + 0x120))();
  (**(code **)(*DAT_140c65670 + 0x128))();
  (**(code **)(*DAT_140c65670 + 0x210))(DAT_140c65670,&DAT_140c3fe88,1);
  iVar6 = (**(code **)(**(longlong **)(param_1 + 0x15a8) + 0x30))();
  fVar13 = DAT_140b79ed0;
  if (iVar6 == 0) {
    local_2d8 = *(undefined8 *)(param_1 + 0x1598);
    local_2e0[0] = 1;
    local_2c0 = *(undefined8 *)(param_1 + 0x15a0);
    local_2cc = 0;
    local_278 = *(undefined8 *)(param_1 + 0x15a8);
    local_2c8[0] = 1;
    local_2b4 = 0;
    local_280[0] = 1;
    local_26c = 0;
    local_478 = &DAT_140c3fe88;
    (**(code **)(*DAT_140c65670 + 0x208))(DAT_140c65670,local_280,local_2c8,local_2e0);
    local_268 = 0;
    uStack_260 = 0;
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    (**(code **)(*DAT_140c65670 + 0x270))(DAT_140c65670,1,&local_268);
    (**(code **)(*DAT_140c65670 + 0x2a0))();
  }
  local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
  puVar7 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,0);
  piVar5 = DAT_140c63750;
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0x3f800000;
    iVar6 = DAT_140c44440;
    if (*piVar5 < DAT_140c44440) {
      iVar6 = *piVar5;
    }
    puVar7[1] = *(float *)(&DAT_140c44450 + (longlong)iVar6 * 4) * DAT_140b7a23c;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  local_290 = *(undefined8 *)(param_1 + 0x1598);
  local_298[0] = 1;
  local_284 = 0;
  local_478 = &DAT_140c3fe88;
  (**(code **)(*DAT_140c65670 + 0x208))(DAT_140c65670,local_298,&DAT_140c3fe88,&DAT_140c3fe88);
  (**(code **)(*DAT_140c65670 + 0x278))(DAT_140c65670,3);
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,*(undefined8 *)(param_1 + 0x15a8),0);
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1e0),0);
  local_470 = 0;
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x298))(DAT_140c65670,0xffffffff);
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,0,0);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,1,0);
  fVar4 = _UNK_140b7ac5c;
  fVar3 = _UNK_140b7ac58;
  fVar2 = _UNK_140b7ac54;
  fVar1 = _DAT_140b7ac50;
  fVar10 = DAT_140b79f58;
  local_b8 = 0;
  local_b4 = 0x3f800000;
  fVar9 = *(float *)(param_1 + 0x1580);
  fVar14 = *(float *)(param_1 + 0x390) - fVar9 * DAT_140b79e48;
  fVar11 = *(float *)(param_1 + 0x398) - fVar9 * DAT_140b79e48;
  local_218 = CONCAT44(fVar11,fVar14);
  uStack_210 = 0;
  fVar17 = DAT_140c43fb8 * fVar14 + DAT_140b79e48;
  fVar15 = *(float *)(param_1 + 0x1590) * fVar17;
  fVar16 = DAT_140c43fb8 * fVar11 + DAT_140b79e48;
  fVar12 = fVar16 * *(float *)(param_1 + 0x1590);
  fVar17 = fVar17 * _DAT_140b7a1c4;
  local_258 = &local_408;
  local_250 = &local_400;
  local_400 = 1;
  fVar16 = fVar16 * _DAT_140b7a1c4;
  local_3fc = 1;
  local_148 = _DAT_140b7ac50;
  fStack_144 = _UNK_140b7ac54;
  fStack_140 = _UNK_140b7ac58;
  fStack_13c = _UNK_140b7ac5c;
  fStack_1dc = *(float *)(param_1 + 0x1594);
  local_228 = _DAT_140b7ac50;
  fStack_224 = _UNK_140b7ac54;
  fStack_220 = _UNK_140b7ac58;
  fStack_21c = _UNK_140b7ac5c;
  local_408 = (int)fVar15;
  local_1d8 = CONCAT44(fVar12,fVar15);
  uStack_1d0 = 0;
  local_158 = _DAT_140b7ac50;
  fStack_154 = _UNK_140b7ac54;
  fStack_150 = _UNK_140b7ac58;
  fStack_14c = _UNK_140b7ac5c;
  local_404 = (int)fVar12;
  local_1a8 = CONCAT44((float)(local_404 + 1),(float)(local_408 + 1));
  uStack_1a0 = 0;
  local_108 = (float)(local_408 + 1) * fStack_1dc;
  fStack_104 = (float)(local_404 + 1) * fStack_1dc;
  fStack_100 = fStack_1dc * 0.0;
  fStack_fc = fStack_1dc * 0.0;
  local_208 = CONCAT44((float)local_404,(float)local_408);
  uStack_200 = 0;
  local_1e8 = (float)local_408 * fStack_1dc;
  fStack_1e4 = (float)local_404 * fStack_1dc;
  fStack_1e0 = fStack_1dc * 0.0;
  fStack_1dc = fStack_1dc * 0.0;
  local_188 = local_108 - _DAT_140b7ac50;
  fStack_184 = fStack_104 - _UNK_140b7ac54;
  fStack_180 = fStack_100 - _UNK_140b7ac58;
  fStack_17c = fStack_fc - _UNK_140b7ac5c;
  local_1b8 = local_1e8 - _DAT_140b7ac50;
  fStack_1b4 = fStack_1e4 - _UNK_140b7ac54;
  fStack_1b0 = fStack_1e0 - _UNK_140b7ac58;
  fStack_1ac = fStack_1dc - _UNK_140b7ac5c;
  local_438 = local_188 * _DAT_140b7b4b0;
  fStack_434 = fStack_184 * _UNK_140b7b4b4;
  fStack_430 = fStack_180 * _UNK_140b7b4b8;
  fStack_42c = fStack_17c * _UNK_140b7b4bc;
  local_448 = local_1b8 * _DAT_140b7b4b0;
  fStack_444 = fStack_1b4 * _UNK_140b7b4b4;
  fStack_440 = fStack_1b0 * _UNK_140b7b4b8;
  fStack_43c = fStack_1ac * _UNK_140b7b4bc;
  local_178 = CONCAT44(fVar11 - fStack_444,fVar14 - local_448);
  uStack_170 = 0;
  local_138 = CONCAT44(fVar16,fVar17);
  uStack_130 = 0;
  local_118._0_4_ = (float)(int)fVar17;
  local_118._4_4_ = (float)(int)fVar16;
  local_118._8_8_ = 0;
  local_f8 = divps(local_118,_DAT_140b7b4d0);
  local_d8 = local_f8._0_4_ - _DAT_140b7ac50;
  fStack_d4 = local_f8._4_4_ - _UNK_140b7ac54;
  fStack_d0 = local_f8._8_4_ - _UNK_140b7ac58;
  fStack_cc = local_f8._12_4_ - _UNK_140b7ac5c;
  fVar15 = local_d8 * _DAT_140b7b4b0;
  fVar16 = fStack_d4 * _UNK_140b7b4b4;
  fStack_1c0 = fStack_d0 * _UNK_140b7b4b8;
  fStack_1bc = fStack_cc * _UNK_140b7b4bc;
  fVar11 = (float)((longlong)((fVar15 - local_448) * DAT_140b79f58) & 0xffffffff);
  fVar12 = (float)((longlong)((fVar16 - fStack_444) * DAT_140b79f58) & 0xffffffff);
  fVar14 = (float)*(uint *)(param_1 + 0x1588);
  local_3f8 = fVar11;
  fStack_3f4 = fVar12;
  local_3e8 = fVar14;
  fStack_3e4 = fVar14;
  local_1c8 = fVar15;
  fStack_1c4 = fVar16;
  local_198 = local_448;
  fStack_194 = fStack_444;
  fStack_190 = fStack_440;
  fStack_18c = fStack_43c;
  local_128 = local_438;
  fStack_124 = fStack_434;
  fStack_120 = fStack_430;
  fStack_11c = fStack_42c;
  if (fVar11 < fVar14) {
    if (fVar12 < fVar14) {
      local_3c8 = fVar9 + local_448;
      local_c8 = (undefined4)(longlong)fVar11;
      local_428 = CONCAT44(fVar16,fVar15);
      uStack_420 = uStack_3d0;
      local_c4 = (undefined4)(longlong)fVar12;
      fStack_3c4 = fVar9 + fStack_444;
      local_418 = CONCAT44(fStack_3c4,local_3c8);
      uStack_410 = uStack_3c0;
      local_c0 = (undefined4)(longlong)(fVar14 - fVar11);
      local_bc = (undefined4)(longlong)(fVar14 - fVar12);
      local_3d8 = fVar15;
      fStack_3d4 = fVar16;
      (**(code **)(*DAT_140c65670 + 0x250))(DAT_140c65670,&local_c8);
      local_468 = fVar11 - fVar1;
      fStack_464 = fVar12 - fVar2;
      fStack_460 = fStack_3f0 - fVar3;
      fStack_45c = fStack_3ec - fVar4;
      local_238 = fVar1;
      fStack_234 = fVar2;
      fStack_230 = fVar3;
      fStack_22c = fVar4;
      local_458._4_4_ = fVar14 - fVar2;
      local_458._0_4_ = fVar14 - fVar1;
      fStack_450 = (float)uStack_3e0 - fVar3;
      fStack_44c = (float)((ulonglong)uStack_3e0 >> 0x20) - fVar4;
      FUN_14035e960(param_1,&local_428,&local_468,&local_448);
      (**(code **)(*DAT_140c65670 + 0x2a0))();
    }
  }
  local_398 = 0;
  fVar9 = (float)((longlong)((fVar16 - fStack_444) * fVar10) & 0xffffffff);
  fVar12 = (float)*(uint *)(param_1 + 0x1588);
  fVar11 = (float)((longlong)((fVar15 - local_448) * fVar10) & 0xffffffff);
  fStack_394 = fVar9;
  local_388 = fVar11;
  fStack_384 = fVar12;
  if (0.0 < fVar11) {
    if (fVar9 < fVar12) {
      fStack_344 = *(float *)(param_1 + 0x1580);
      local_348 = fVar15 + fStack_344;
      local_358 = local_448 + fStack_344;
      local_c8 = 0;
      fStack_344 = fStack_444 + fStack_344;
      local_c4 = (undefined4)(longlong)fVar9;
      local_428 = CONCAT44(fVar16,local_358);
      uStack_420 = uStack_350;
      local_418 = CONCAT44(fStack_344,local_348);
      uStack_410 = uStack_340;
      local_c0 = (undefined4)(longlong)(fVar11 - 0.0);
      local_bc = (undefined4)(longlong)(fVar12 - fVar9);
      fStack_354 = fVar16;
      (**(code **)(*DAT_140c65670 + 0x250))(DAT_140c65670,&local_c8);
      local_468 = 0.0 - fVar1;
      fStack_464 = fVar9 - fVar2;
      fStack_460 = fStack_390 - fVar3;
      fStack_45c = fStack_38c - fVar4;
      local_168 = fVar1;
      fStack_164 = fVar2;
      fStack_160 = fVar3;
      fStack_15c = fVar4;
      local_458._4_4_ = fVar12 - fVar2;
      local_458._0_4_ = fVar11 - fVar1;
      fStack_450 = (float)uStack_380 - fVar3;
      fStack_44c = (float)((ulonglong)uStack_380 >> 0x20) - fVar4;
      FUN_14035e960(param_1,&local_428,&local_468,&local_448);
      (**(code **)(*DAT_140c65670 + 0x2a0))();
    }
  }
  uStack_314 = 0;
  fVar9 = (float)((longlong)((fVar15 - local_448) * fVar10) & 0xffffffff);
  fVar11 = (float)*(uint *)(param_1 + 0x1588);
  fVar12 = (float)((longlong)((fVar16 - fStack_444) * fVar10) & 0xffffffff);
  local_318 = fVar9;
  local_308 = fVar11;
  fStack_304 = fVar12;
  if (fVar9 < fVar11) {
    if (0.0 < fVar12) {
      local_3a8 = *(float *)(param_1 + 0x1580);
      fStack_3a4 = fVar16 + local_3a8;
      fStack_3b4 = fStack_444 + local_3a8;
      local_c8 = (undefined4)(longlong)fVar9;
      local_c4 = 0;
      local_3a8 = local_448 + local_3a8;
      local_428 = CONCAT44(fStack_3b4,fVar15);
      uStack_420 = uStack_3b0;
      local_418 = CONCAT44(fStack_3a4,local_3a8);
      uStack_410 = uStack_3a0;
      local_c0 = (undefined4)(longlong)(fVar11 - fVar9);
      local_bc = (undefined4)(longlong)(fVar12 - 0.0);
      local_3b8 = fVar15;
      (**(code **)(*DAT_140c65670 + 0x250))(DAT_140c65670,&local_c8);
      local_468 = fVar9 - fVar1;
      fStack_464 = 0.0 - fVar2;
      fStack_460 = fStack_310 - fVar3;
      fStack_45c = fStack_30c - fVar4;
      local_1f8 = fVar1;
      fStack_1f4 = fVar2;
      fStack_1f0 = fVar3;
      fStack_1ec = fVar4;
      local_458._4_4_ = fVar12 - fVar2;
      local_458._0_4_ = fVar11 - fVar1;
      fStack_450 = (float)uStack_300 - fVar3;
      fStack_44c = (float)((ulonglong)uStack_300 >> 0x20) - fVar4;
      FUN_14035e960(param_1,&local_428,&local_468,&local_448);
      (**(code **)(*DAT_140c65670 + 0x2a0))();
    }
  }
  local_338 = 0;
  local_468 = 0.0;
  fStack_464 = 0.0;
  fStack_460 = fStack_330;
  fStack_45c = fStack_32c;
  fVar9 = (float)((longlong)((fVar15 - local_448) * fVar10) & 0xffffffff);
  fVar10 = (float)((longlong)((fVar16 - fStack_444) * fVar10) & 0xffffffff);
  local_458._4_4_ = fVar10;
  local_458._0_4_ = fVar9;
  unique0x1000186d = uStack_320;
  local_328 = fVar9;
  fStack_324 = fVar10;
  if (0.0 < fVar9) {
    if (0.0 < fVar10) {
      fStack_364 = *(float *)(param_1 + 0x1580);
      local_378 = local_448 + fStack_364;
      fStack_374 = fStack_444 + fStack_364;
      local_368 = fVar15 + fStack_364;
      local_c8 = 0;
      fStack_364 = fVar16 + fStack_364;
      local_c4 = 0;
      local_428 = CONCAT44(fStack_374,local_378);
      uStack_420 = uStack_370;
      local_418 = CONCAT44(fStack_364,local_368);
      uStack_410 = uStack_360;
      local_c0 = (undefined4)(longlong)(fVar9 - 0.0);
      local_bc = (undefined4)(longlong)(fVar10 - 0.0);
      (**(code **)(*DAT_140c65670 + 0x250))(DAT_140c65670,&local_c8);
      local_468 = 0.0 - fVar1;
      fStack_464 = 0.0 - fVar2;
      fStack_460 = fStack_330 - fVar3;
      fStack_45c = fStack_32c - fVar4;
      local_e8 = fVar1;
      fStack_e4 = fVar2;
      fStack_e0 = fVar3;
      fStack_dc = fVar4;
      local_458._4_4_ = fVar10 - fVar2;
      local_458._0_4_ = fVar9 - fVar1;
      fStack_450 = (float)uStack_320 - fVar3;
      fStack_44c = (float)((ulonglong)uStack_320 >> 0x20) - fVar4;
      FUN_14035e960(param_1,&local_428,&local_468,&local_448);
      (**(code **)(*DAT_140c65670 + 0x2a0))();
    }
  }
  local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
  pfVar8 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,0);
  fVar9 = DAT_140b79d80;
  if (pfVar8 != (float *)0x0) {
    iVar6 = DAT_140c444a0;
    if (*DAT_140c63750 < DAT_140c444a0) {
      iVar6 = *DAT_140c63750;
    }
    *pfVar8 = fVar13 - *(float *)(&DAT_140c444b0 + (longlong)iVar6 * 4);
    fVar13 = *(float *)(param_1 + 0x37c);
    if (fVar9 <= *(float *)(param_1 + 0x37c)) {
      fVar13 = fVar9;
    }
    pfVar8[1] = fVar13;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  local_2a8 = *(undefined8 *)(param_1 + 0x15a0);
  local_2b0[0] = 1;
  local_29c = 0;
  local_478 = &DAT_140c3fe88;
  (**(code **)(*DAT_140c65670 + 0x208))(DAT_140c65670,local_2b0,&DAT_140c3fe88,&DAT_140c3fe88);
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,*(undefined8 *)(param_1 + 0x1598),0);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,4);
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1e0),0);
  local_470 = 0;
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x298))(DAT_140c65670,0xffffffff);
  (**(code **)(*DAT_140c65670 + 0x2a0))();
  local_2f0 = *(undefined8 *)(param_1 + 0x15a8);
  local_2f8[0] = 1;
  local_2e4 = 0;
  local_478 = &DAT_140c3fe88;
  (**(code **)(*DAT_140c65670 + 0x208))(DAT_140c65670,local_2f8,&DAT_140c3fe88,&DAT_140c3fe88);
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,*(undefined8 *)(param_1 + 0x15a0),0);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,4);
  local_470 = 0;
  local_478 = (undefined *)0x0;
  (**(code **)(*DAT_140c65670 + 0x298))(DAT_140c65670,0xffffffff);
  (**(code **)(*DAT_140c65670 + 0x2a0))();
  (**(code **)(*DAT_140c65670 + 0x228))();
  (**(code **)(*DAT_140c65670 + 0x220))();
  return 0;
}



==== FUN_140361ce0 @ 140361ce0 size 1271 ====
CALLERS: FUN_14035ff70
CALLEES: FUN_1401afb10 __security_check_cookie FUN_14035bdf0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140361ce0(longlong param_1)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined8 *puVar21;
  undefined1 auVar22 [16];
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined1 auStack_178 [32];
  undefined4 local_158;
  undefined4 local_150;
  undefined4 local_148;
  undefined4 local_140;
  longlong local_138;
  float *local_130;
  float local_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float local_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float local_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  longlong local_a8;
  float *local_a0;
  ulonglong local_58;
  
  local_58 = DAT_140c0f7b0 ^ (ulonglong)auStack_178;
  (**(code **)(*DAT_140c65670 + 0x128))();
  (**(code **)(*DAT_140c65688 + 0x50))();
  local_158 = 2;
  (**(code **)(*DAT_140c65670 + 0x1b0))(DAT_140c65670,0,0,0);
  (**(code **)(*DAT_140c65670 + 0x158))(DAT_140c65670,0);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,1,0);
  (**(code **)(*DAT_140c65670 + 0x1c0))(DAT_140c65670,7);
  (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,0);
  (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,0);
  fVar25 = *(float *)(param_1 + 0x88) * DAT_140b79df8;
  fVar26 = fVar25 * DAT_140b79df8;
  fVar24 = fVar25 * fVar25;
  local_158 = 0;
  puVar20 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x80,0,0);
  if (puVar20 != (undefined4 *)0x0) {
    local_138 = param_1 + 0x3c0;
    local_130 = &local_128;
    local_128 = _DAT_140c78410 * _DAT_140b7acf0;
    fStack_124 = fRam0000000140c78414 * _DAT_140b7acf0;
    fStack_120 = fRam0000000140c78418 * _DAT_140b7acf0;
    fStack_11c = fRam0000000140c7841c * _DAT_140b7acf0;
    local_118 = _DAT_140c78420 * _UNK_140b7acf4;
    fStack_114 = fRam0000000140c78424 * _UNK_140b7acf4;
    fStack_110 = fRam0000000140c78428 * _UNK_140b7acf4;
    fStack_10c = fRam0000000140c7842c * _UNK_140b7acf4;
    local_108 = _DAT_140c78430 * DAT_140b7acf8;
    fStack_104 = fRam0000000140c78434 * DAT_140b7acf8;
    fStack_100 = fRam0000000140c78438 * DAT_140b7acf8;
    fStack_fc = fRam0000000140c7843c * DAT_140b7acf8;
    local_f8 = _DAT_140c78440;
    uStack_f0 = uRam0000000140c78448;
    local_a8 = local_138;
    local_a0 = local_130;
    FUN_1401afb10(&local_a8,&local_e8);
    *puVar20 = local_e8;
    puVar20[1] = local_d8;
    puVar20[2] = local_c8;
    puVar20[3] = local_b8;
    puVar20[4] = uStack_e4;
    puVar20[5] = uStack_d4;
    puVar20[6] = uStack_c4;
    puVar20[7] = uStack_b4;
    puVar20[8] = uStack_e0;
    puVar20[9] = uStack_d0;
    puVar20[10] = uStack_c0;
    puVar20[0xb] = uStack_b0;
    uVar3 = *(undefined4 *)(param_1 + 0x510);
    uVar4 = *(undefined4 *)(param_1 + 0x514);
    uVar5 = *(undefined4 *)(param_1 + 0x518);
    uVar6 = *(undefined4 *)(param_1 + 0x51c);
    uVar7 = *(undefined4 *)(param_1 + 0x504);
    uVar8 = *(undefined4 *)(param_1 + 0x508);
    uVar9 = *(undefined4 *)(param_1 + 0x50c);
    uVar10 = *(undefined4 *)(param_1 + 0x520);
    uVar11 = *(undefined4 *)(param_1 + 0x524);
    uVar12 = *(undefined4 *)(param_1 + 0x528);
    uVar13 = *(undefined4 *)(param_1 + 0x52c);
    uVar14 = *(undefined4 *)(param_1 + 0x530);
    uVar15 = *(undefined4 *)(param_1 + 0x534);
    uVar16 = *(undefined4 *)(param_1 + 0x538);
    uVar17 = *(undefined4 *)(param_1 + 0x53c);
    puVar20[0xc] = *(undefined4 *)(param_1 + 0x500);
    puVar20[0xd] = uVar3;
    puVar20[0xe] = uVar10;
    puVar20[0xf] = uVar14;
    puVar20[0x10] = uVar7;
    puVar20[0x11] = uVar4;
    puVar20[0x12] = uVar11;
    puVar20[0x13] = uVar15;
    puVar20[0x14] = uVar8;
    puVar20[0x15] = uVar5;
    puVar20[0x16] = uVar12;
    puVar20[0x17] = uVar16;
    puVar20[0x18] = uVar9;
    puVar20[0x19] = uVar6;
    puVar20[0x1a] = uVar13;
    puVar20[0x1b] = uVar17;
    fVar25 = DAT_140b79ed0 / (fVar25 - fVar26);
    puVar20[0x1c] = fVar25;
    puVar20[0x1d] = (uint)(fVar25 * fVar26) ^ DAT_140b7b530;
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  (**(code **)(*DAT_140c65670 + 0x140))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0xe0),0);
  local_158 = 0;
  puVar21 = (undefined8 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,0);
  uVar18 = _UNK_140b7a668;
  if (puVar21 != (undefined8 *)0x0) {
    *puVar21 = _DAT_140b7a660;
    puVar21[1] = uVar18;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0xe8),0);
  (**(code **)(*DAT_140c65670 + 0x138))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0xf0));
  (**(code **)(*DAT_140c65670 + 0x130))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x78),4);
  for (lVar2 = *(longlong *)(param_1 + 0x920);
      (lVar2 != 0 && (*(float *)(lVar2 + 0x30) <= fVar24 && fVar24 != *(float *)(lVar2 + 0x30)));
      lVar2 = *(longlong *)(lVar2 + 0x590)) {
    auVar1 = *(undefined1 (*) [16])(param_1 + 0x390);
    auVar22 = minps(auVar1,*(undefined1 (*) [16])(lVar2 + 0xd0));
    auVar22 = maxps(*(undefined1 (*) [16])(lVar2 + 0xc0),auVar22);
    fVar25 = auVar22._0_4_ - auVar1._0_4_;
    fVar26 = auVar22._4_4_ - auVar1._4_4_;
    fVar23 = auVar22._8_4_ - auVar1._8_4_;
    if ((fVar25 * fVar25 + fVar26 * fVar26 + fVar23 * fVar23 < fVar24) &&
       (iVar19 = FUN_14035bdf0(param_1,lVar2 + 0xc0), iVar19 != 0)) {
      local_158 = 0;
      puVar20 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x10,1,8);
      if (puVar20 != (undefined4 *)0x0) {
        uVar3 = *(undefined4 *)(lVar2 + 0xc0);
        uVar4 = *(undefined4 *)(lVar2 + 200);
        *puVar20 = uVar3;
        puVar20[1] = uVar4;
        puVar20[2] = uVar3;
        puVar20[3] = uVar4;
        (**(code **)(*DAT_140c65670 + 0x108))();
      }
      (**(code **)(*DAT_140c65670 + 0x130))
                (DAT_140c65670,*(undefined8 *)(*(longlong *)(lVar2 + 0xa0) + 0x20),4);
      local_140 = 1;
      local_148 = 0;
      local_150 = 0x221;
      local_158 = 0;
      (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,0,0xc00);
    }
  }
  return 0;
}



==== FUN_1403621e0 @ 1403621e0 size 1388 ====
CALLERS: FUN_14035ff70
CALLEES: FUN_140384690 FUN_14035bdf0 FUN_14037d3e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1403621e0(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  ulonglong uVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  int iVar22;
  longlong lVar23;
  undefined4 *puVar24;
  ulonglong *puVar25;
  undefined8 uVar26;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  undefined8 local_res8;
  ulonglong local_68;
  undefined8 uStack_60;
  
  lVar23 = (**(code **)(**(longlong **)(param_1 + 0x18) + 0x40))();
  (**(code **)(*DAT_140c65670 + 0x128))();
  (**(code **)(*DAT_140c65688 + 0x50))();
  bVar21 = false;
  bVar20 = true;
  iVar22 = DAT_140c44400;
  if (*DAT_140c63750 < DAT_140c44400) {
    iVar22 = *DAT_140c63750;
  }
  if (((&DAT_140c44410)[iVar22] == '\0') ||
     (bVar19 = bVar20, (*(uint *)(param_1 + 0x80) & 0x8000000) == 0)) {
    bVar19 = false;
  }
  iVar22 = *(int *)(&DAT_140b657f8 + (longlong)*(int *)(param_1 + 0x90) * 4);
  uVar1 = *(uint *)(param_1 + 0x84);
  iVar2 = *(int *)(&DAT_140b657f8 + (longlong)*(int *)(param_1 + 0x90) * 4);
  puVar24 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x90,0,0,0);
  if (puVar24 != (undefined4 *)0x0) {
    uVar3 = *(undefined4 *)(param_1 + 0x3d0);
    uVar4 = *(undefined4 *)(param_1 + 0x3d4);
    uVar5 = *(undefined4 *)(param_1 + 0x3d8);
    uVar6 = *(undefined4 *)(param_1 + 0x3f0);
    uVar7 = *(undefined4 *)(param_1 + 0x3f4);
    uVar8 = *(undefined4 *)(param_1 + 0x3f8);
    uVar9 = *(undefined4 *)(param_1 + 0x3c4);
    uVar10 = *(undefined4 *)(param_1 + 0x3c8);
    uVar11 = *(undefined4 *)(param_1 + 0x3e0);
    uVar12 = *(undefined4 *)(param_1 + 0x3e4);
    uVar13 = *(undefined4 *)(param_1 + 1000);
    fVar32 = *(float *)(param_1 + 0x94);
    *puVar24 = *(undefined4 *)(param_1 + 0x3c0);
    puVar24[1] = uVar3;
    puVar24[2] = uVar11;
    puVar24[3] = uVar6;
    puVar24[4] = uVar9;
    puVar24[5] = uVar4;
    puVar24[6] = uVar12;
    puVar24[7] = uVar7;
    puVar24[8] = uVar10;
    puVar24[9] = uVar5;
    puVar24[10] = uVar13;
    puVar24[0xb] = uVar8;
    fVar29 = DAT_140b7a23c;
    fVar30 = DAT_140b79e48;
    uVar3 = *(undefined4 *)(param_1 + 0x510);
    uVar4 = *(undefined4 *)(param_1 + 0x514);
    uVar5 = *(undefined4 *)(param_1 + 0x518);
    uVar6 = *(undefined4 *)(param_1 + 0x51c);
    uVar7 = *(undefined4 *)(param_1 + 0x530);
    uVar8 = *(undefined4 *)(param_1 + 0x534);
    uVar9 = *(undefined4 *)(param_1 + 0x538);
    uVar10 = *(undefined4 *)(param_1 + 0x53c);
    uVar11 = *(undefined4 *)(param_1 + 0x504);
    uVar12 = *(undefined4 *)(param_1 + 0x508);
    uVar13 = *(undefined4 *)(param_1 + 0x50c);
    uVar14 = *(undefined4 *)(param_1 + 0x520);
    uVar15 = *(undefined4 *)(param_1 + 0x524);
    uVar16 = *(undefined4 *)(param_1 + 0x528);
    uVar17 = *(undefined4 *)(param_1 + 0x52c);
    puVar24[0xc] = *(undefined4 *)(param_1 + 0x500);
    puVar24[0xd] = uVar3;
    puVar24[0xe] = uVar14;
    puVar24[0xf] = uVar7;
    puVar24[0x10] = uVar11;
    puVar24[0x11] = uVar4;
    puVar24[0x12] = uVar15;
    puVar24[0x13] = uVar8;
    puVar24[0x14] = uVar12;
    puVar24[0x15] = uVar5;
    puVar24[0x16] = uVar16;
    puVar24[0x17] = uVar9;
    puVar24[0x18] = uVar13;
    puVar24[0x19] = uVar6;
    puVar24[0x1a] = uVar17;
    puVar24[0x1b] = uVar10;
    fVar29 = fVar29 / (fVar32 - fVar32 * DAT_140b79e84);
    local_res8 = (longlong *)CONCAT44((uint)(fVar29 * fVar32) ^ DAT_140b7b530,fVar29);
    *(longlong **)(puVar24 + 0x1c) = local_res8;
    puVar24[0x1e] = *(undefined4 *)(param_1 + 0x1584);
    fVar29 = *(float *)(param_1 + 0x1580) * fVar30;
    fVar32 = *(float *)(param_1 + 0x1594);
    auVar28._0_4_ =
         (fVar32 * (float)(int)((DAT_140c43fb8 * (*(float *)(param_1 + 0x390) - fVar29) + fVar30) *
                               *(float *)(param_1 + 0x1590)) - _DAT_140b7ac50) * _DAT_140b7b4b0;
    auVar28._4_4_ =
         (fVar32 * (float)(int)((DAT_140c43fb8 * (*(float *)(param_1 + 0x398) - fVar29) + fVar30) *
                               *(float *)(param_1 + 0x1590)) - _UNK_140b7ac54) * _UNK_140b7b4b4;
    auVar28._8_4_ = (fVar32 * 0.0 - _UNK_140b7ac58) * _UNK_140b7b4b8;
    auVar28._12_4_ = (fVar32 * 0.0 - _UNK_140b7ac5c) * _UNK_140b7b4bc;
    *(undefined1 (*) [16])(puVar24 + 0x20) = auVar28;
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  (**(code **)(*DAT_140c65670 + 0x140))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x140),
             (uint)bVar19 + iVar22 * 2);
  puVar25 = (ulonglong *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x40,0,0,0);
  if (puVar25 != (ulonglong *)0x0) {
    local_68 = CONCAT44((float)*(byte *)(lVar23 + 0x23),(float)*(byte *)(lVar23 + 0x22));
    uStack_60 = 0;
    *puVar25 = local_68;
    *(undefined4 *)(puVar25 + 1) = 0x3f000000;
    uVar18 = *(ulonglong *)(param_1 + 0x1e8);
    puVar25[2] = *(ulonglong *)(param_1 + 0x1e0);
    puVar25[3] = uVar18;
    uVar18 = *(ulonglong *)(param_1 + 0x1f8);
    puVar25[4] = *(ulonglong *)(param_1 + 0x1f0);
    puVar25[5] = uVar18;
    uVar18 = *(ulonglong *)(param_1 + 0x338);
    puVar25[6] = *(ulonglong *)(param_1 + 0x330);
    puVar25[7] = uVar18;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x148),
             (uint)((uVar1 & 0x1809023) != 0) + iVar2 * 2);
  if (bVar19) {
    local_res8 = *(longlong **)(param_1 + 0x15a8);
    if (local_res8 != (longlong *)0x0) {
      (**(code **)*local_res8)(local_res8);
    }
  }
  else {
    local_res8 = (longlong *)0x0;
    bVar21 = true;
    bVar20 = false;
  }
  (**(code **)(*DAT_140c65670 + 0x170))(DAT_140c65670,0,local_res8,0);
  if ((bVar21) && (local_res8 != (longlong *)0x0)) {
    (**(code **)(*local_res8 + 8))(local_res8);
  }
  if ((bVar20 != false) && (local_res8 != (longlong *)0x0)) {
    (**(code **)(*local_res8 + 8))(local_res8);
  }
  lVar23 = *(longlong *)(param_1 + 0x920);
  fVar32 = *(float *)(param_1 + 0x94) * *(float *)(param_1 + 0x94);
  do {
    if ((lVar23 == 0) || (fVar32 < *(float *)(lVar23 + 0x30) || fVar32 == *(float *)(lVar23 + 0x30))
       ) {
      return 0;
    }
    if (*(int *)(lVar23 + 0x310) != 0) {
      auVar28 = *(undefined1 (*) [16])(param_1 + 0x390);
      auVar27 = minps(auVar28,*(undefined1 (*) [16])(lVar23 + 0x330));
      auVar27 = maxps(*(undefined1 (*) [16])(lVar23 + 800),auVar27);
      fVar30 = auVar27._0_4_ - auVar28._0_4_;
      fVar29 = auVar27._4_4_ - auVar28._4_4_;
      fVar31 = auVar27._8_4_ - auVar28._8_4_;
      if (fVar30 * fVar30 + fVar29 * fVar29 + fVar31 * fVar31 < fVar32) {
        if (*(int *)(param_1 + 0x354) != 0) {
          fVar30 = *(float *)(lVar23 + 0x334) - *(float *)(param_1 + 0x394);
          if (fVar30 <= 0.0) {
            fVar29 = *(float *)(lVar23 + 0x518);
          }
          else {
            fVar29 = *(float *)(lVar23 + 0x514);
          }
          if (fVar30 * fVar29 < *(float *)(lVar23 + 0x510)) goto LAB_140362723;
        }
        iVar22 = FUN_14035bdf0(param_1);
        if (iVar22 != 0) {
          local_68 = local_68 & 0xffffffff00000000;
          iVar22 = FUN_14037d3e0(lVar23,&local_68);
          if ((iVar22 != 0) && (uVar26 = FUN_140384690(lVar23), (int)uVar26 < 0)) {
            return uVar26;
          }
        }
      }
    }
LAB_140362723:
    lVar23 = *(longlong *)(lVar23 + 0x590);
  } while( true );
}



==== FUN_140364970 @ 140364970 size 845 ====
CALLERS: FUN_14035ff70
CALLEES: FUN_1401afb10 FUN_1407e4830 __security_check_cookie FUN_1401afc20 FUN_14038c510

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140364970(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  longlong *plVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_2f8 [32];
  undefined1 *local_2d8;
  undefined8 *local_2d0;
  float local_2c8;
  float fStack_2c4;
  float fStack_2c0;
  float fStack_2bc;
  float local_2b8;
  float fStack_2b4;
  float fStack_2b0;
  float fStack_2ac;
  undefined1 local_298 [16];
  undefined1 local_288 [16];
  undefined8 local_278;
  undefined8 uStack_270;
  float local_268;
  float fStack_264;
  float fStack_260;
  undefined4 uStack_25c;
  float local_258;
  float fStack_254;
  float fStack_250;
  float fStack_24c;
  float local_248;
  float fStack_244;
  float fStack_240;
  float fStack_23c;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined4 local_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined1 local_1f8 [128];
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  float local_168;
  undefined8 local_164;
  float local_158;
  float local_154;
  undefined4 local_14c;
  undefined4 local_148;
  undefined8 local_138;
  undefined1 *local_128;
  undefined8 *local_120;
  undefined1 local_118 [32];
  undefined4 local_f8;
  undefined4 local_f0;
  undefined1 *local_d8 [10];
  ulonglong local_88;
  
  local_88 = DAT_140c0f7b0 ^ (ulonglong)auStack_2f8;
  FUN_1407e4830(&local_258,0,0x130);
  uVar4 = DAT_140b79ed0;
  fVar3 = DAT_140b79e48;
  fVar2 = DAT_140b79df8;
  plVar1 = *(longlong **)(param_1 + 0x14a8);
  local_164 = 0x3f800000;
  local_14c = 0x4a0;
  local_138 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x180);
  local_148 = param_3;
  local_178 = _DAT_140b7b240;
  uStack_174 = _UNK_140b7b244;
  uStack_170 = DAT_140b7b248;
  uStack_16c = _UNK_140b7b24c;
  for (; plVar1 != (longlong *)0x0; plVar1 = (longlong *)plVar1[0x89]) {
    iVar5 = (**(code **)(*plVar1 + 0x158))(plVar1);
    if (iVar5 != 0) {
      fVar8 = (float)FUN_14038c510(plVar1,*(undefined4 *)(param_1 + 0x370));
      fVar9 = (float)(**(code **)(*plVar1 + 0x90))();
      if (0.0 < fVar8 * fVar9) {
        lVar6 = (**(code **)(*(longlong *)plVar1[4] + 0x1a8))((longlong *)plVar1[4],0x96,0);
        local_2b8 = *(float *)(lVar6 + 0x40) - _DAT_140b7a6a0;
        fStack_2b4 = *(float *)(lVar6 + 0x44) - _UNK_140b7a6a4;
        fStack_2b0 = *(float *)(lVar6 + 0x48) - _UNK_140b7a6a8;
        fStack_2ac = *(float *)(lVar6 + 0x4c) - _UNK_140b7a6ac;
        local_248 = _DAT_140b7a6a0 + *(float *)(lVar6 + 0x50);
        fStack_244 = _UNK_140b7a6a4 + *(float *)(lVar6 + 0x54);
        fStack_240 = _UNK_140b7a6a8 + *(float *)(lVar6 + 0x58);
        fStack_23c = _UNK_140b7a6ac + *(float *)(lVar6 + 0x5c);
        local_2c8 = local_248 - local_2b8;
        fVar10 = fStack_244 - fStack_2b4;
        fStack_2c0 = fStack_240 - fStack_2b0;
        fStack_2bc = fStack_23c - fStack_2ac;
        fVar11 = fVar10 * fVar3;
        fStack_254 = fStack_2b4 - fVar11;
        fStack_244 = fStack_244 - fVar11;
        fStack_2c4 = fVar10;
        local_258 = local_2b8;
        fStack_250 = fStack_2b0;
        fStack_24c = fStack_2ac;
        puVar7 = (undefined8 *)(**(code **)(*plVar1 + 0x38))(plVar1);
        local_238 = *puVar7;
        uStack_230 = puVar7[1];
        local_228 = puVar7[2];
        uStack_220 = puVar7[3];
        local_218 = *(undefined4 *)(puVar7 + 4);
        uStack_214 = *(undefined4 *)((longlong)puVar7 + 0x24);
        uStack_210 = *(undefined4 *)(puVar7 + 5);
        uStack_20c = *(undefined4 *)((longlong)puVar7 + 0x2c);
        local_208 = *(undefined4 *)(puVar7 + 6);
        uStack_204 = *(undefined4 *)((longlong)puVar7 + 0x34);
        uStack_200 = *(undefined4 *)(puVar7 + 7);
        uStack_1fc = *(undefined4 *)((longlong)puVar7 + 0x3c);
        iVar5 = (**(code **)(*(longlong *)plVar1[4] + 0x1d0))((longlong *)plVar1[4],0x80);
        if (iVar5 != 0) {
          (**(code **)(*(longlong *)plVar1[4] + 0x1e0))((longlong *)plVar1[4],0x80);
          local_208 = local_f8;
          uStack_200 = local_f0;
        }
        local_2d8 = local_298;
        local_2d0 = &local_238;
        local_278 = _DAT_140c78420;
        uStack_270 = uRam0000000140c78428;
        local_298 = ZEXT416((uint)local_2c8);
        local_288 = ZEXT416((uint)fStack_2c0) << 0x40;
        local_268 = local_2b8;
        fStack_264 = fStack_2b4;
        fStack_260 = fStack_2b0;
        uStack_25c = uVar4;
        local_128 = local_2d8;
        local_120 = local_2d0;
        FUN_1401afb10(&local_128,local_118);
        local_d8[0] = local_118;
        FUN_1401afc20(local_d8,local_1f8);
        local_158 = fVar10 * fVar2;
        local_168 = fVar8 * fVar9;
        local_154 = fVar11;
        (**(code **)(*DAT_140c65688 + 0x68))(DAT_140c65688,&local_258);
      }
    }
  }
  return 0;
}



==== FUN_140364e90 @ 140364e90 size 4195 ====
CALLERS: FUN_14035ff70
CALLEES: FUN_140370a90 FUN_1401afb10 FUN_140370ae0 FUN_1407e4830 __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140364e90(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined1 auStack_198 [32];
  undefined4 local_178;
  undefined4 local_170;
  undefined4 local_168;
  undefined4 local_160;
  undefined8 local_158;
  longlong local_150;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  longlong local_a0;
  ulonglong local_58;
  
  local_58 = DAT_140c0f7b0 ^ (ulonglong)auStack_198;
  if ((((*(longlong *)(param_1 + 0x14b8) != 0) || (*(longlong *)(param_1 + 0x13c8) != 0)) ||
      (*(longlong *)(param_1 + 0x14c0) != 0)) || (*(longlong *)(param_1 + 0x13d0) != 0)) {
    (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,0);
    (**(code **)(*DAT_140c65670 + 0x188))(DAT_140c65670,0xfffffff8,DAT_140b7a23c);
    (**(code **)(*DAT_140c65670 + 0x138))
              (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x158));
    (**(code **)(*DAT_140c65670 + 0x178))
              (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x58),0);
    (**(code **)(*DAT_140c65670 + 0x140))
              (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x50),1);
    plVar1 = *(longlong **)(param_1 + 0x14b8);
    while (plVar1 != (longlong *)0x0) {
      iVar2 = (**(code **)(*plVar1 + 0x100))(plVar1);
      if (iVar2 != 0) {
        if (plVar1[0x7a] == 0) {
          *(undefined4 *)(plVar1 + 0x7c) = 0;
          uVar3 = (**(code **)(*DAT_140c65670 + 0xb0))(DAT_140c65670,plVar1 + 0x7a);
          if ((int)uVar3 < 0) {
            return uVar3;
          }
        }
        else if (((int)plVar1[0x7c] != 0) &&
                ((**(code **)(*plVar1 + 0x108))(plVar1,0,0), (int)plVar1[0x7c] != 0))
        goto LAB_140365303;
        puVar4 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0xe0))();
        if (puVar4 != (undefined4 *)0x0) {
          FUN_1407e4830(puVar4,0,0x80);
          (**(code **)(*plVar1 + 0x58))(plVar1,&local_148,0);
          *puVar4 = local_148;
          puVar4[1] = local_144;
          puVar4[2] = local_140;
          puVar4[4] = local_138;
          puVar4[5] = local_144;
          puVar4[6] = local_140;
          puVar4[8] = local_148;
          puVar4[9] = local_134;
          puVar4[10] = local_140;
          puVar4[0xc] = local_138;
          puVar4[0xd] = local_134;
          puVar4[0xe] = local_140;
          puVar4[0x10] = local_148;
          puVar4[0x11] = local_144;
          puVar4[0x12] = local_130;
          puVar4[0x14] = local_138;
          puVar4[0x15] = local_144;
          puVar4[0x16] = local_130;
          puVar4[0x18] = local_148;
          puVar4[0x19] = local_134;
          puVar4[0x1a] = local_130;
          puVar4[0x1c] = local_138;
          puVar4[0x1d] = local_134;
          puVar4[0x1e] = local_130;
          (**(code **)(*DAT_140c65670 + 0xe8))();
          local_158 = (**(code **)(*plVar1 + 0x38))(plVar1);
          local_150 = param_1 + 0x5c0;
          local_a8 = local_158;
          local_a0 = local_150;
          FUN_1401afb10(&local_a8,&local_128);
          local_170 = 0;
          local_178 = 0;
          local_e8 = local_128;
          uStack_e4 = local_118;
          uStack_e0 = local_108;
          uStack_dc = local_f8;
          local_d8 = uStack_124;
          uStack_d4 = uStack_114;
          uStack_d0 = uStack_104;
          uStack_cc = uStack_f4;
          local_c8 = uStack_120;
          uStack_c4 = uStack_110;
          uStack_c0 = uStack_100;
          uStack_bc = uStack_f0;
          local_b8 = uStack_11c;
          uStack_b4 = uStack_10c;
          uStack_b0 = uStack_fc;
          uStack_ac = uStack_ec;
          (**(code **)(*DAT_140c65670 + 0x148))(DAT_140c65670,0x40);
          (**(code **)(*(longlong *)plVar1[0x7a] + 0x18))();
          local_160 = 1;
          local_168 = 0;
          local_170 = 8;
          local_178 = 0;
          (**(code **)(*DAT_140c65670 + 0x290))();
          (**(code **)(*(longlong *)plVar1[0x7a] + 0x20))();
          *(undefined4 *)(plVar1 + 0x7c) = 1;
        }
      }
LAB_140365303:
      if ((longlong *)plVar1[0x8c] != (longlong *)0x0) {
        *(longlong *)plVar1[0x8c] = plVar1[0x8d];
      }
      if (plVar1[0x8d] != 0) {
        *(longlong *)(plVar1[0x8d] + 0x460) = plVar1[0x8c];
      }
      plVar1[0x8d] = 0;
      plVar1[0x8c] = 0;
      plVar1 = *(longlong **)(param_1 + 0x14b8);
    }
    plVar1 = *(longlong **)(param_1 + 0x14c0);
    while (plVar1 != (longlong *)0x0) {
      iVar2 = (**(code **)(*plVar1 + 0x100))(plVar1);
      if (iVar2 != 0) {
        if (plVar1[0x7b] == 0) {
          *(undefined4 *)((longlong)plVar1 + 0x3e4) = 0;
          uVar3 = (**(code **)(*DAT_140c65670 + 0xb0))(DAT_140c65670,plVar1 + 0x7b);
          if ((int)uVar3 < 0) {
            return uVar3;
          }
        }
        else if ((*(int *)((longlong)plVar1 + 0x3e4) != 0) &&
                ((**(code **)(*plVar1 + 0x108))(plVar1,0,1), *(int *)((longlong)plVar1 + 0x3e4) != 0
                )) goto LAB_1403656b7;
        puVar4 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,0x80,1);
        if (puVar4 != (undefined4 *)0x0) {
          FUN_1407e4830(puVar4,0,0x80);
          (**(code **)(*plVar1 + 0x58))(plVar1,&local_148,1);
          *puVar4 = local_148;
          puVar4[1] = local_144;
          puVar4[2] = local_140;
          puVar4[4] = local_138;
          puVar4[5] = local_144;
          puVar4[6] = local_140;
          puVar4[8] = local_148;
          puVar4[9] = local_134;
          puVar4[10] = local_140;
          puVar4[0xc] = local_138;
          puVar4[0xd] = local_134;
          puVar4[0xe] = local_140;
          puVar4[0x10] = local_148;
          puVar4[0x11] = local_144;
          puVar4[0x12] = local_130;
          puVar4[0x14] = local_138;
          puVar4[0x15] = local_144;
          puVar4[0x16] = local_130;
          puVar4[0x18] = local_148;
          puVar4[0x19] = local_134;
          puVar4[0x1a] = local_130;
          puVar4[0x1c] = local_138;
          puVar4[0x1d] = local_134;
          puVar4[0x1e] = local_130;
          (**(code **)(*DAT_140c65670 + 0xe8))();
          local_158 = (**(code **)(*plVar1 + 0x38))(plVar1);
          local_150 = param_1 + 0x5c0;
          local_a8 = local_158;
          local_a0 = local_150;
          FUN_1401afb10(&local_a8,&local_e8);
          local_170 = 0;
          local_178 = 0;
          local_128 = local_e8;
          uStack_124 = local_d8;
          uStack_120 = local_c8;
          uStack_11c = local_b8;
          local_118 = uStack_e4;
          uStack_114 = uStack_d4;
          uStack_110 = uStack_c4;
          uStack_10c = uStack_b4;
          local_108 = uStack_e0;
          uStack_104 = uStack_d0;
          uStack_100 = uStack_c0;
          uStack_fc = uStack_b0;
          local_f8 = uStack_dc;
          uStack_f4 = uStack_cc;
          uStack_f0 = uStack_bc;
          uStack_ec = uStack_ac;
          (**(code **)(*DAT_140c65670 + 0x148))(DAT_140c65670,0x40,&local_128);
          (**(code **)(*(longlong *)plVar1[0x7b] + 0x18))();
          local_160 = 1;
          local_168 = 0;
          local_170 = 8;
          local_178 = 0;
          (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,0);
          (**(code **)(*(longlong *)plVar1[0x7b] + 0x20))();
          *(undefined4 *)((longlong)plVar1 + 0x3e4) = 1;
        }
      }
LAB_1403656b7:
      if ((longlong *)plVar1[0x8e] != (longlong *)0x0) {
        *(longlong *)plVar1[0x8e] = plVar1[0x8f];
      }
      if (plVar1[0x8f] != 0) {
        *(longlong *)(plVar1[0x8f] + 0x470) = plVar1[0x8e];
      }
      plVar1[0x8f] = 0;
      plVar1[0x8e] = 0;
      plVar1 = *(longlong **)(param_1 + 0x14c0);
    }
    plVar1 = *(longlong **)(param_1 + 0x13c8);
    while (plVar1 != (longlong *)0x0) {
      iVar2 = (**(code **)(*plVar1 + 0x100))(plVar1);
      if (iVar2 == 0) {
LAB_140365a4a:
        if ((longlong *)plVar1[0x9c] != (longlong *)0x0) {
          *(longlong *)plVar1[0x9c] = plVar1[0x9d];
        }
        if (plVar1[0x9d] != 0) {
          *(longlong *)(plVar1[0x9d] + 0x4e0) = plVar1[0x9c];
        }
        plVar1[0x9c] = 0;
        plVar1[0x9d] = 0;
      }
      else {
        if (plVar1[0x8e] == 0) {
          *(undefined4 *)(plVar1 + 0x90) = 0;
          uVar3 = (**(code **)(*DAT_140c65670 + 0xb0))(DAT_140c65670,plVar1 + 0x8e);
          if ((int)uVar3 < 0) {
            return uVar3;
          }
LAB_140365767:
          puVar4 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0xe0))();
          if (puVar4 != (undefined4 *)0x0) {
            FUN_1407e4830(puVar4,0,0x80);
            (**(code **)(*plVar1 + 0x58))(plVar1,&local_148,0);
            *puVar4 = local_148;
            puVar4[1] = local_144;
            puVar4[2] = local_140;
            puVar4[4] = local_138;
            puVar4[5] = local_144;
            puVar4[6] = local_140;
            puVar4[8] = local_148;
            puVar4[9] = local_134;
            puVar4[10] = local_140;
            puVar4[0xc] = local_138;
            puVar4[0xd] = local_134;
            puVar4[0xe] = local_140;
            puVar4[0x10] = local_148;
            puVar4[0x11] = local_144;
            puVar4[0x12] = local_130;
            puVar4[0x14] = local_138;
            puVar4[0x15] = local_144;
            puVar4[0x16] = local_130;
            puVar4[0x18] = local_148;
            puVar4[0x19] = local_134;
            puVar4[0x1a] = local_130;
            puVar4[0x1c] = local_138;
            puVar4[0x1d] = local_134;
            puVar4[0x1e] = local_130;
            (**(code **)(*DAT_140c65670 + 0xe8))();
            local_158 = (**(code **)(*plVar1 + 0x38))(plVar1);
            local_150 = param_1 + 0x5c0;
            local_a8 = local_158;
            local_a0 = local_150;
            FUN_1401afb10(&local_a8,&local_e8);
            local_170 = 0;
            local_178 = 0;
            local_128 = local_e8;
            uStack_124 = local_d8;
            uStack_120 = local_c8;
            uStack_11c = local_b8;
            local_118 = uStack_e4;
            uStack_114 = uStack_d4;
            uStack_110 = uStack_c4;
            uStack_10c = uStack_b4;
            local_108 = uStack_e0;
            uStack_104 = uStack_d0;
            uStack_100 = uStack_c0;
            uStack_fc = uStack_b0;
            local_f8 = uStack_dc;
            uStack_f4 = uStack_cc;
            uStack_f0 = uStack_bc;
            uStack_ec = uStack_ac;
            (**(code **)(*DAT_140c65670 + 0x148))(DAT_140c65670,0x40);
            (**(code **)(*(longlong *)plVar1[0x8e] + 0x18))();
            local_160 = 1;
            local_168 = 0;
            local_170 = 8;
            local_178 = 0;
            (**(code **)(*DAT_140c65670 + 0x290))();
            (**(code **)(*(longlong *)plVar1[0x8e] + 0x20))();
            *(undefined4 *)(plVar1 + 0x90) = 1;
          }
          goto LAB_140365a4a;
        }
        if (((int)plVar1[0x90] == 0) ||
           ((**(code **)(*plVar1 + 0x108))(plVar1,0,0), (int)plVar1[0x90] == 0)) goto LAB_140365767;
        FUN_140370ae0(plVar1);
      }
      plVar1 = *(longlong **)(param_1 + 0x13c8);
    }
    plVar1 = *(longlong **)(param_1 + 0x13d0);
    while (plVar1 != (longlong *)0x0) {
      iVar2 = (**(code **)(*plVar1 + 0x100))(plVar1);
      if (iVar2 == 0) {
LAB_140365ddd:
        if ((longlong *)plVar1[0x9e] != (longlong *)0x0) {
          *(longlong *)plVar1[0x9e] = plVar1[0x9f];
        }
        if (plVar1[0x9f] != 0) {
          *(longlong *)(plVar1[0x9f] + 0x4f0) = plVar1[0x9e];
        }
        plVar1[0x9e] = 0;
        plVar1[0x9f] = 0;
      }
      else {
        if (plVar1[0x8f] == 0) {
          *(undefined4 *)((longlong)plVar1 + 0x484) = 0;
          uVar3 = (**(code **)(*DAT_140c65670 + 0xb0))(DAT_140c65670,plVar1 + 0x8f);
          if ((int)uVar3 < 0) {
            return uVar3;
          }
LAB_140365af7:
          puVar4 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,0x80,1);
          if (puVar4 != (undefined4 *)0x0) {
            FUN_1407e4830(puVar4,0,0x80);
            (**(code **)(*plVar1 + 0x58))(plVar1,&local_148,1);
            *puVar4 = local_148;
            puVar4[1] = local_144;
            puVar4[2] = local_140;
            puVar4[4] = local_138;
            puVar4[5] = local_144;
            puVar4[6] = local_140;
            puVar4[8] = local_148;
            puVar4[9] = local_134;
            puVar4[10] = local_140;
            puVar4[0xc] = local_138;
            puVar4[0xd] = local_134;
            puVar4[0xe] = local_140;
            puVar4[0x10] = local_148;
            puVar4[0x11] = local_144;
            puVar4[0x12] = local_130;
            puVar4[0x14] = local_138;
            puVar4[0x15] = local_144;
            puVar4[0x16] = local_130;
            puVar4[0x18] = local_148;
            puVar4[0x19] = local_134;
            puVar4[0x1a] = local_130;
            puVar4[0x1c] = local_138;
            puVar4[0x1d] = local_134;
            puVar4[0x1e] = local_130;
            (**(code **)(*DAT_140c65670 + 0xe8))();
            local_158 = (**(code **)(*plVar1 + 0x38))(plVar1);
            local_150 = param_1 + 0x5c0;
            local_a8 = local_158;
            local_a0 = local_150;
            FUN_1401afb10(&local_a8,&local_e8);
            local_170 = 0;
            local_178 = 0;
            local_128 = local_e8;
            uStack_124 = local_d8;
            uStack_120 = local_c8;
            uStack_11c = local_b8;
            local_118 = uStack_e4;
            uStack_114 = uStack_d4;
            uStack_110 = uStack_c4;
            uStack_10c = uStack_b4;
            local_108 = uStack_e0;
            uStack_104 = uStack_d0;
            uStack_100 = uStack_c0;
            uStack_fc = uStack_b0;
            local_f8 = uStack_dc;
            uStack_f4 = uStack_cc;
            uStack_f0 = uStack_bc;
            uStack_ec = uStack_ac;
            (**(code **)(*DAT_140c65670 + 0x148))(DAT_140c65670,0x40,&local_128);
            (**(code **)(*(longlong *)plVar1[0x8f] + 0x18))();
            local_160 = 1;
            local_168 = 0;
            local_170 = 8;
            local_178 = 0;
            (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,0);
            (**(code **)(*(longlong *)plVar1[0x8f] + 0x20))();
            *(undefined4 *)((longlong)plVar1 + 0x484) = 1;
          }
          goto LAB_140365ddd;
        }
        if ((*(int *)((longlong)plVar1 + 0x484) == 0) ||
           ((**(code **)(*plVar1 + 0x108))(plVar1,0,1), *(int *)((longlong)plVar1 + 0x484) == 0))
        goto LAB_140365af7;
        FUN_140370a90(plVar1);
      }
      plVar1 = *(longlong **)(param_1 + 0x13d0);
    }
  }
  return 0;
}



==== FUN_140366270 @ 140366270 size 1050 ====
CALLERS: FUN_14035ff70
CALLEES:

undefined8 FUN_140366270(longlong param_1)

{
  char cVar1;
  int iVar2;
  float fVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  float fVar9;
  float fVar10;
  undefined8 in_stack_ffffffffffffffa8;
  uint uVar13;
  undefined *puVar11;
  ulonglong uVar12;
  undefined4 uVar14;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_34;
  
  uVar13 = (uint)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  local_48 = CONCAT44(local_48._4_4_,0xffffffff);
  (**(code **)(**(longlong **)(param_1 + 0x1840) + 0x20))
            (*(longlong **)(param_1 + 0x1840),&local_48);
  fVar3 = DAT_140b79ed0;
  if (*(longlong *)(param_1 + 0x14f0) != 0) {
    local_48 = 0;
    uStack_40 = 0;
    (**(code **)(*DAT_140c65670 + 0x270))
              (DAT_140c65670,1,&local_48,DAT_140b79ed0,(ulonglong)uVar13 << 0x20);
    for (lVar4 = *(longlong *)(param_1 + 0x14f0); lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x390))
    {
      (**(code **)(*DAT_140c65688 + 0x60))(DAT_140c65688,lVar4 + 0x20);
    }
    (**(code **)(*DAT_140c65670 + 0x2a0))();
    lVar4 = (**(code **)(*DAT_140c65688 + 0xc0))();
    puVar5 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xd0))();
    local_48 = CONCAT44(local_48._4_4_,1);
    uStack_40 = *puVar5;
    local_34 = 0;
    puVar11 = &DAT_140c3fe88;
    (**(code **)(*DAT_140c65670 + 0x208))
              (DAT_140c65670,&local_48,&DAT_140c3fe88,&DAT_140c3fe88,&DAT_140c3fe88);
    local_48 = 0;
    uStack_40 = 0;
    (**(code **)(*DAT_140c65670 + 0x270))
              (DAT_140c65670,1,&local_48,fVar3,(ulonglong)puVar11 & 0xffffffff00000000);
    uVar6 = (**(code **)(*DAT_140c65688 + 0xd8))();
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,*(undefined8 *)(lVar4 + 0x48),0,uVar6);
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,1,*(undefined8 *)(lVar4 + 0x28),0,0);
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,2,puVar5[1],0,0);
    uVar12 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))
              (DAT_140c65670,3,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x200),0,0);
    uVar12 = uVar12 & 0xffffffff00000000;
    puVar5 = (undefined8 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xe0,0,0,uVar12);
    uVar14 = (undefined4)(uVar12 >> 0x20);
    if (puVar5 != (undefined8 *)0x0) {
      lVar7 = (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x10) + 0x200) + 0x18))();
      fVar9 = fVar3 / (float)*(uint *)(lVar7 + 8);
      fVar10 = fVar9 * DAT_140b79f20;
      fVar9 = fVar9 * DAT_140b79e48;
      *puVar5 = CONCAT44(fVar3 / (float)*(int *)(lVar4 + 0x5c),fVar3 / (float)*(int *)(lVar4 + 0x58)
                        );
      puVar5[1] = 0;
      uVar6 = *(undefined8 *)(param_1 + 0x148);
      puVar5[2] = *(undefined8 *)(param_1 + 0x140);
      puVar5[3] = uVar6;
      *(float *)(puVar5 + 4) = fVar9;
      *(float *)((longlong)puVar5 + 0x24) = fVar10;
      *(float *)(puVar5 + 5) = fVar3;
      *(float *)((longlong)puVar5 + 0x2c) = fVar3;
      uVar6 = *(undefined8 *)(param_1 + 0x168);
      puVar5[10] = *(undefined8 *)(param_1 + 0x160);
      puVar5[0xb] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x178);
      puVar5[0xc] = *(undefined8 *)(param_1 + 0x170);
      puVar5[0xd] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x188);
      puVar5[0xe] = *(undefined8 *)(param_1 + 0x180);
      puVar5[0xf] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x198);
      puVar5[0x10] = *(undefined8 *)(param_1 + 400);
      puVar5[0x11] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x1a8);
      puVar5[0x12] = *(undefined8 *)(param_1 + 0x1a0);
      puVar5[0x13] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x1b8);
      puVar5[0x14] = *(undefined8 *)(param_1 + 0x1b0);
      puVar5[0x15] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x1c8);
      puVar5[0x16] = *(undefined8 *)(param_1 + 0x1c0);
      puVar5[0x17] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x1d8);
      puVar5[0x18] = *(undefined8 *)(param_1 + 0x1d0);
      puVar5[0x19] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x158);
      puVar5[6] = *(undefined8 *)(param_1 + 0x150);
      puVar5[7] = uVar6;
      uVar6 = *(undefined8 *)(param_1 + 0x3d8);
      puVar5[8] = *(undefined8 *)(param_1 + 0x3d0);
      puVar5[9] = uVar6;
      puVar8 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xf8))();
      uVar6 = puVar8[1];
      puVar5[0x1a] = *puVar8;
      puVar5[0x1b] = uVar6;
      (**(code **)(*DAT_140c65670 + 0x118))();
    }
    (**(code **)(*DAT_140c65670 + 0x178))
              (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x208),0);
    iVar2 = DAT_140c40550;
    if (*DAT_140c63750 < DAT_140c40550) {
      iVar2 = *DAT_140c63750;
    }
    cVar1 = (&DAT_140c40560)[iVar2];
    if (cVar1 == '\0') {
      (**(code **)(*DAT_140c65670 + 0x1a8))(DAT_140c65670,0x80,0x80,0x80);
    }
    else {
      (**(code **)(*DAT_140c65670 + 0x1a8))(DAT_140c65670,0x80,0x80,0);
    }
    (**(code **)(*DAT_140c65670 + 0x1b0))(DAT_140c65670,0,0,cVar1 == '\0',CONCAT44(uVar14,2));
    (**(code **)(*DAT_140c65670 + 0x298))
              (DAT_140c65670,0xffffffff,0,lVar4 + 0x58,lVar4 + 0x60,lVar4 + 0x60);
  }
  return 0;
}



==== FUN_14036ea20 @ 14036ea20 size 621 ====
CALLERS: FUN_14036e3a0
CALLEES:

undefined8 * FUN_14036ea20(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  puVar4 = param_2 + 8;
  uVar2 = param_2[3];
  param_1[2] = param_2[2];
  param_1[3] = uVar2;
  uVar2 = param_2[5];
  param_1[4] = param_2[4];
  param_1[5] = uVar2;
  uVar2 = param_2[7];
  param_1[6] = param_2[6];
  param_1[7] = uVar2;
  lVar5 = 8;
  do {
    uVar2 = *puVar4;
    uVar3 = puVar4[1];
    puVar4 = puVar4 + 2;
    puVar1 = (undefined8 *)((longlong)param_1 + (-0x10 - (longlong)param_2) + (longlong)puVar4);
    *puVar1 = uVar2;
    puVar1[1] = uVar3;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar2 = param_2[0x19];
  param_1[0x18] = param_2[0x18];
  param_1[0x19] = uVar2;
  uVar2 = param_2[0x1b];
  param_1[0x1a] = param_2[0x1a];
  param_1[0x1b] = uVar2;
  uVar2 = param_2[0x1d];
  param_1[0x1c] = param_2[0x1c];
  param_1[0x1d] = uVar2;
  uVar2 = param_2[0x1f];
  param_1[0x1e] = param_2[0x1e];
  param_1[0x1f] = uVar2;
  uVar2 = param_2[0x21];
  param_1[0x20] = param_2[0x20];
  param_1[0x21] = uVar2;
  uVar2 = param_2[0x23];
  param_1[0x22] = param_2[0x22];
  param_1[0x23] = uVar2;
  param_1[0x24] = param_2[0x24];
  *(undefined4 *)(param_1 + 0x25) = *(undefined4 *)(param_2 + 0x25);
  uVar2 = param_2[0x27];
  param_1[0x26] = param_2[0x26];
  param_1[0x27] = uVar2;
  uVar2 = param_2[0x29];
  param_1[0x28] = param_2[0x28];
  param_1[0x29] = uVar2;
  uVar2 = param_2[0x2b];
  param_1[0x2a] = param_2[0x2a];
  param_1[0x2b] = uVar2;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)((longlong)param_1 + 0x164) = *(undefined4 *)((longlong)param_2 + 0x164);
  param_1[0x2e] = param_2[0x2e];
  param_1[0x2d] = param_2[0x2d];
  param_1[0x30] = param_2[0x30];
  param_1[0x2f] = param_2[0x2f];
  param_1[0x32] = param_2[0x32];
  param_1[0x31] = param_2[0x31];
  param_1[0x34] = param_2[0x34];
  param_1[0x33] = param_2[0x33];
  param_1[0x36] = param_2[0x36];
  param_1[0x35] = param_2[0x35];
  param_1[0x38] = param_2[0x38];
  param_1[0x37] = param_2[0x37];
  param_1[0x3a] = param_2[0x3a];
  param_1[0x39] = param_2[0x39];
  param_1[0x3c] = param_2[0x3c];
  param_1[0x3b] = param_2[0x3b];
  param_1[0x3e] = param_2[0x3e];
  param_1[0x3d] = param_2[0x3d];
  *(undefined4 *)(param_1 + 0x3f) = *(undefined4 *)(param_2 + 0x3f);
  *(undefined4 *)((longlong)param_1 + 0x1fc) = *(undefined4 *)((longlong)param_2 + 0x1fc);
  param_1[0x40] = param_2[0x40];
  *(undefined4 *)(param_1 + 0x41) = *(undefined4 *)(param_2 + 0x41);
  *(undefined4 *)((longlong)param_1 + 0x20c) = *(undefined4 *)((longlong)param_2 + 0x20c);
  uVar2 = param_2[0x43];
  param_1[0x42] = param_2[0x42];
  param_1[0x43] = uVar2;
  param_1[0x44] = param_2[0x44];
  return param_1;
}


