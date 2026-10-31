
undefined4 * FUN_14055e180(longlong param_1)

{
  ulonglong *puVar1;
  longlong *plVar2;
  short sVar3;
  undefined4 uVar4;
  longlong lVar5;
  char *pcVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  char *pcVar17;
  void *pvVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  undefined4 *puVar22;
  void *pvVar23;
  ulonglong *puVar24;
  ulonglong uVar25;
  longlong lVar26;
  int *piVar27;
  ulonglong *puVar28;
  longlong lVar29;
  void *_Dst;
  void *pvVar30;
  ulonglong uVar31;
  ulonglong *puVar32;
  undefined8 uVar33;
  ulonglong *puVar34;
  float *pfVar35;
  undefined4 *puVar36;
  undefined4 *puVar37;
  uint *puVar38;
  undefined4 *puVar39;
  int *piVar40;
  char *pcVar41;
  char *pcVar42;
  ulonglong uVar43;
  ulonglong uVar44;
  int *piVar45;
  uint uVar46;
  undefined8 *puVar47;
  short *psVar48;
  undefined4 *puVar49;
  void *pvVar50;
  uint uVar51;
  short *psVar52;
  bool bVar53;
  longlong local_res8;
  ulonglong local_res10;
  int *local_res18;
  void *local_res20;
  ulonglong *local_1a8;
  void *local_1a0;
  void *local_198;
  undefined **local_190;
  undefined8 local_188;
  LPVOID local_180;
  void *local_178;
  ulonglong *local_170;
  ulonglong *local_168;
  void *local_160;
  ulonglong local_158;
  void *local_150;
  ulonglong local_148;
  ulonglong *local_140;
  longlong local_138;
  void *local_130;
  void *local_128;
  ulonglong *local_120;
  ulonglong local_118 [2];
  undefined **local_108;
  undefined8 local_100;
  LPVOID local_f8;
  undefined **local_e8 [3];
  longlong local_d0;
  longlong local_88;
  longlong local_78;
  int local_70;
  
  uVar25 = 0;
  local_1a0 = (void *)0x0;
  local_res8 = param_1;
  if (DAT_140c63838 == (code *)0x0) {
    iVar19 = 0;
    if (DAT_140c64c94 == 0) {
      iVar19 = FUN_14023d1a0();
      if (iVar19 < 0) {
        iVar19 = 0;
      }
      else {
        iVar19 = (**(code **)(*DAT_140c64fe8 + 0x28))();
      }
    }
  }
  else {
    iVar19 = (*DAT_140c63838)(&PTR_u_Spell4Visual_140a6d658);
  }
  local_res10 = CONCAT44(local_res10._4_4_,iVar19);
  uVar31 = uVar25;
  if (iVar19 != 0) {
    do {
      puVar22 = (undefined4 *)0x0;
      if (DAT_140c63848 == (code *)0x0) {
        if (DAT_140c64c94 == 0) {
          iVar19 = FUN_14023d1a0();
          if (iVar19 < 0) {
            puVar22 = (undefined4 *)0x0;
          }
          else {
            puVar22 = (undefined4 *)(**(code **)(*DAT_140c64fe8 + 0x20))();
          }
        }
      }
      else {
        puVar22 = (undefined4 *)(*DAT_140c63848)(&PTR_u_Spell4Visual_140a6d658,uVar25,DAT_140c63858)
        ;
      }
      if (((uint)puVar22[2] < 2) || (puVar22[1] != 0)) {
        if (puVar22[4] == 0) {
LAB_14055e32c:
          iVar19 = 0x4e;
          goto LAB_14055e331;
        }
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c64c04 != 0) || (iVar19 = FUN_140248ca0(), iVar19 < 0)) goto LAB_14055e32c;
          lVar26 = (**(code **)(*DAT_140c63b40 + 0x18))();
        }
        else {
          lVar26 = (*DAT_140c63840)(&PTR_u_VisualEffect_140a6dff8,puVar22[4],DAT_140c63858);
        }
        if (lVar26 == 0) goto LAB_14055e32c;
        pvVar23 = (void *)FUN_14018db00(local_1a0,uVar31 + 1,8);
        *(undefined4 **)((longlong)pvVar23 + uVar31 * 8) = puVar22;
        pvVar50 = local_1a0;
        if ((local_1a0 != pvVar23) &&
           (memcpy(pvVar23,local_1a0,uVar31 * 8), pvVar50 = pvVar23, local_1a0 != (void *)0x0)) {
          (**(code **)(*(longlong *)((longlong)local_1a0 + -0x10) + 8))((longlong)local_1a0 + -0x10)
          ;
        }
        local_1a0 = pvVar50;
        uVar31 = uVar31 + 1;
      }
      else {
        iVar19 = 0x50;
LAB_14055e331:
        plVar2 = (longlong *)(param_1 + 0x6b0);
        if (*plVar2 == *(longlong *)(param_1 + 0x6b8)) {
          FUN_1400290d0(plVar2);
        }
        local_res18 = (int *)(**(code **)(param_1 + 0x6c8))(puVar22);
        lVar26 = *(longlong *)(param_1 + 0x6c0);
        uVar43 = (ulonglong)local_res18 % *(ulonglong *)(param_1 + 0x6b8);
        puVar24 = (ulonglong *)FUN_14018b280(0x18);
        if (puVar24 == (ulonglong *)0x0) {
          puVar24 = (ulonglong *)0x0;
        }
        else {
          uVar44 = *(ulonglong *)(lVar26 + uVar43 * 8);
          *puVar24 = (ulonglong)local_res18;
          puVar24[1] = uVar44;
          *(undefined4 *)(puVar24 + 2) = *puVar22;
          *(int *)((longlong)puVar24 + 0x14) = iVar19;
        }
        *(ulonglong **)(lVar26 + uVar43 * 8) = puVar24;
        *plVar2 = *plVar2 + 1;
        if (iVar19 == 0x4e) {
          FUN_14018d540(&local_res20,&DAT_140b4f534,0x4e);
          pvVar50 = local_res20;
        }
        else {
          FUN_14018d540(&local_198,&DAT_140b4f534,iVar19);
          pvVar50 = local_198;
        }
        param_1 = local_res8;
        if (pvVar50 != (void *)0x0) {
          (**(code **)(*(longlong *)((longlong)pvVar50 + -0x10) + 8))((longlong)pvVar50 + -0x10);
          param_1 = local_res8;
        }
      }
      uVar51 = (int)uVar25 + 1;
      uVar25 = (ulonglong)uVar51;
    } while (uVar51 < (uint)local_res10);
  }
  uVar43 = 0;
  auVar7._8_8_ = 0;
  auVar7._0_8_ = uVar31;
  uVar25 = SUB168(ZEXT816(0xa0) * auVar7,0);
  if (SUB168(ZEXT816(0xa0) * auVar7,8) != 0) {
    uVar25 = 0xffffffffffffffff;
  }
  lVar26 = uVar25 + 0x10;
  if (0xffffffffffffffef < uVar25) {
    lVar26 = -1;
  }
  piVar27 = (int *)FUN_14018b280(lVar26,0);
  if (piVar27 == (int *)0x0) {
    piVar45 = (int *)0x0;
  }
  else {
    iVar19 = (int)uVar31;
    *piVar27 = iVar19;
    piVar45 = piVar27 + 4;
    while (iVar19 = iVar19 + -1, -1 < iVar19) {
      piVar40 = piVar27 + 0x28;
      piVar27[0x12] = 0;
      piVar27[0x13] = 0;
      piVar40[0] = 0;
      piVar40[1] = 0;
      piVar27 = piVar40;
    }
  }
  *(int **)(param_1 + 0x648) = piVar45;
  uVar25 = uVar43;
  if (uVar31 != 0) {
    do {
      puVar22 = *(undefined4 **)((longlong)local_1a0 + uVar43 * 8);
      local_res18 = (int *)(*(longlong *)(param_1 + 0x648) + uVar25);
      FUN_1405620a0(local_res18,local_res18,puVar22,puVar22[4],puVar22[5]);
      plVar2 = *(longlong **)(param_1 + 0x778);
      if (*plVar2 == plVar2[1]) {
        FUN_1400290d0(plVar2);
      }
      local_res10 = (*(code *)plVar2[3])(puVar22);
      lVar26 = plVar2[2];
      uVar44 = local_res10 % (ulonglong)plVar2[1];
      puVar24 = (ulonglong *)FUN_14018b280(0x20);
      if (puVar24 == (ulonglong *)0x0) {
        puVar24 = (ulonglong *)0x0;
      }
      else {
        puVar24[1] = *(ulonglong *)(lVar26 + uVar44 * 8);
        *puVar24 = local_res10;
        *(undefined4 *)(puVar24 + 2) = *puVar22;
        puVar24[3] = (ulonglong)local_res18;
      }
      *(ulonglong **)(lVar26 + uVar44 * 8) = puVar24;
      *plVar2 = *plVar2 + 1;
      uVar43 = uVar43 + 1;
      param_1 = local_res8;
      uVar25 = uVar25 + 0xa0;
    } while (uVar43 < uVar31);
  }
  puVar24 = (ulonglong *)0x0;
  iVar19 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    if (DAT_140c64d94 == 0) {
      iVar19 = FUN_140236320();
      if (iVar19 < 0) {
        iVar19 = 0;
      }
      else {
        iVar19 = (**(code **)(*DAT_140c653f0 + 0x28))();
      }
    }
  }
  else {
    iVar19 = (*DAT_140c63838)(&PTR_u_Spell4_140a6d0a8);
  }
  local_res10 = CONCAT44(local_res10._4_4_,iVar19);
  local_178 = (void *)0x0;
  local_1a8 = (ulonglong *)0x0;
  local_res20 = (void *)0x0;
  local_170 = (ulonglong *)0x0;
  local_160 = (void *)0x0;
  local_198 = (void *)0x0;
  local_168 = (ulonglong *)0x0;
  local_128 = (void *)0x0;
  local_140 = (ulonglong *)0x0;
  local_150 = (void *)0x0;
  local_158 = 0;
  local_130 = (void *)0x0;
  local_res18 = (int *)((ulonglong)local_res18 & 0xffffffff00000000);
  puVar28 = puVar24;
  if (iVar19 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        puVar28 = puVar24;
        if (DAT_140c64d94 == 0) {
          iVar19 = FUN_140236320();
          if (iVar19 < 0) {
            puVar28 = (ulonglong *)0x0;
          }
          else {
            puVar28 = (ulonglong *)(**(code **)(*DAT_140c653f0 + 0x20))();
          }
        }
      }
      else {
        puVar28 = (ulonglong *)(*DAT_140c63848)(&PTR_u_Spell4_140a6d0a8,puVar28,DAT_140c63858);
      }
      local_120 = puVar28;
      if (DAT_140c63840 == (code *)0x0) {
        if ((DAT_140c64510 == 0) && (iVar19 = FUN_140236ba0(), -1 < iVar19)) {
          lVar26 = (**(code **)(*DAT_140c654e0 + 0x18))();
          goto LAB_14055e68f;
        }
LAB_14055ef5b:
        iVar19 = 5;
LAB_14055ef60:
        plVar2 = *(longlong **)(param_1 + 0x570);
        if (*plVar2 == plVar2[1]) {
          FUN_1400290d0(plVar2);
        }
        uVar31 = (*(code *)plVar2[3])(puVar28);
        lVar26 = plVar2[2];
        uVar25 = plVar2[1];
        puVar32 = (ulonglong *)FUN_14018b280(0x18);
        puVar28 = puVar24;
        if (puVar32 != (ulonglong *)0x0) {
          uVar43 = *(ulonglong *)(lVar26 + (uVar31 % uVar25) * 8);
          *puVar32 = uVar31;
          puVar32[1] = uVar43;
          uVar43 = *local_120;
          *(int *)((longlong)puVar32 + 0x14) = iVar19;
          *(int *)(puVar32 + 2) = (int)uVar43;
          puVar28 = puVar32;
        }
        *(ulonglong **)(lVar26 + (uVar31 % uVar25) * 8) = puVar28;
        *plVar2 = *plVar2 + 1;
        FUN_14018d540(&local_138,&DAT_140b4f534,iVar19);
        if (local_138 != 0) {
          (**(code **)(*(longlong *)(local_138 + -0x10) + 8))(local_138 + -0x10);
        }
      }
      else {
        lVar26 = (*DAT_140c63840)(&PTR_u_Spell4Base_140a6d118,(int)puVar28[2],DAT_140c63858);
LAB_14055e68f:
        if (lVar26 == 0) goto LAB_14055ef5b;
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c63fe0 == 0) && (iVar19 = FUN_14023bc60(), -1 < iVar19)) {
            lVar29 = (**(code **)(*DAT_140c64ce8 + 0x18))();
            goto LAB_14055e6e7;
          }
LAB_14055ef54:
          iVar19 = 0x38;
          goto LAB_14055ef60;
        }
        lVar29 = (*DAT_140c63840)(&PTR_u_Spell4TargetMechanics_140a6d540,
                                  *(undefined4 *)(lVar26 + 0xc),DAT_140c63858);
LAB_14055e6e7:
        if (lVar29 == 0) goto LAB_14055ef54;
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c64e68 == 0) && (iVar19 = FUN_14023b820(), -1 < iVar19)) {
            lVar29 = (**(code **)(*DAT_140c64b98 + 0x18))();
            goto LAB_14055e73d;
          }
LAB_14055ef4d:
          iVar19 = 0x39;
          goto LAB_14055ef60;
        }
        lVar29 = (*DAT_140c63840)(&PTR_u_Spell4TargetAngle_140a6d508,*(undefined4 *)(lVar26 + 0x10),
                                  DAT_140c63858);
LAB_14055e73d:
        if (lVar29 == 0) goto LAB_14055ef4d;
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c64680 == 0) && (iVar19 = FUN_14023cd60(), -1 < iVar19)) {
            lVar29 = (**(code **)(*DAT_140c64558 + 0x18))();
            goto LAB_14055e793;
          }
LAB_14055ef46:
          iVar19 = 0x3a;
          goto LAB_14055ef60;
        }
        lVar29 = (*DAT_140c63840)(&PTR_u_Spell4ValidTargets_140a6d620,*(undefined4 *)(lVar26 + 0x18)
                                  ,DAT_140c63858);
LAB_14055e793:
        if (lVar29 == 0) goto LAB_14055ef46;
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c64520 == 0) && (iVar19 = FUN_1402391e0(), -1 < iVar19)) {
            lVar29 = (**(code **)(*DAT_140c651c8 + 0x18))();
            goto LAB_14055e7e9;
          }
LAB_14055ef3f:
          iVar19 = 0x3c;
          goto LAB_14055ef60;
        }
        lVar29 = (*DAT_140c63840)(&PTR_u_Spell4HitResults_140a6d310,*(undefined4 *)(lVar26 + 8),
                                  DAT_140c63858);
LAB_14055e7e9:
        if (lVar29 == 0) goto LAB_14055ef3f;
        if (*(int *)(lVar26 + 0x14) != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c64628 == 0) && (iVar19 = FUN_140239a60(), -1 < iVar19)) {
              lVar29 = (**(code **)(*DAT_140c64d98 + 0x18))();
              goto LAB_14055e83b;
            }
          }
          else {
            lVar29 = (*DAT_140c63840)(&PTR_u_Spell4Prerequisites_140a6d380,*(int *)(lVar26 + 0x14),
                                      DAT_140c63858);
LAB_14055e83b:
            if (lVar29 != 0) goto LAB_14055e84a;
          }
          iVar19 = 0x3b;
          goto LAB_14055ef60;
        }
LAB_14055e84a:
        if (*(int *)((longlong)puVar28 + 0x114) != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c64cc8 == 0) && (iVar19 = FUN_140236760(), -1 < iVar19)) {
              lVar29 = (**(code **)(*DAT_140c63e80 + 0x18))();
              goto LAB_14055e896;
            }
          }
          else {
            lVar29 = (*DAT_140c63840)(&PTR_u_Spell4AoeTargetConstraints_140a6d0e0,
                                      *(int *)((longlong)puVar28 + 0x114),DAT_140c63858);
LAB_14055e896:
            if (lVar29 != 0) goto LAB_14055e8a5;
          }
          iVar19 = 0x3d;
          goto LAB_14055ef60;
        }
LAB_14055e8a5:
        piVar27 = (int *)((longlong)puVar28 + 300);
        puVar32 = puVar24;
        do {
          if (*piVar27 == 0) break;
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c65494 == 0) && (iVar19 = FUN_14023da20(), -1 < iVar19)) {
              lVar29 = (**(code **)(*DAT_140c64d48 + 0x18))();
              goto LAB_14055e8f7;
            }
LAB_14055e931:
            iVar19 = 0x43;
            goto LAB_14055ef60;
          }
          lVar29 = (*DAT_140c63840)(&PTR_u_SpellCoolDown_140a6d6c8,*piVar27,DAT_140c63858);
LAB_14055e8f7:
          if (lVar29 == 0) goto LAB_14055e931;
          puVar32 = (ulonglong *)((longlong)puVar32 + 1);
          piVar27 = piVar27 + 1;
        } while (puVar32 < (ulonglong *)0x3);
        if (*(int *)(lVar26 + 0x1c) != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c63cd0 != 0) || (iVar19 = FUN_1402408e0(), iVar19 < 0)) goto LAB_14055e97a;
            lVar29 = (**(code **)(*DAT_140c63908 + 0x18))();
          }
          else {
            lVar29 = (*DAT_140c63840)(&PTR_u_TargetGroup_140a6d930,*(int *)(lVar26 + 0x1c),
                                      DAT_140c63858);
          }
          if (lVar29 != 0) {
            piVar27 = (int *)(lVar29 + 0xc);
            puVar32 = puVar24;
            do {
              if (*piVar27 != 0) goto LAB_14055e984;
              puVar32 = (ulonglong *)((longlong)puVar32 + 1);
              piVar27 = piVar27 + 1;
            } while (puVar32 < (ulonglong *)0x7);
          }
LAB_14055e97a:
          iVar19 = 0x37;
          goto LAB_14055ef60;
        }
LAB_14055e984:
        if (*(int *)(lVar26 + 0x34) != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c63cd0 != 0) || (iVar19 = FUN_1402408e0(), iVar19 < 0)) goto LAB_14055e97a;
            lVar29 = (**(code **)(*DAT_140c63908 + 0x18))();
          }
          else {
            lVar29 = (*DAT_140c63840)(&PTR_u_TargetGroup_140a6d930,*(int *)(lVar26 + 0x34),
                                      DAT_140c63858);
          }
          if (lVar29 != 0) {
            piVar27 = (int *)(lVar29 + 0xc);
            puVar32 = puVar24;
            do {
              if (*piVar27 != 0) goto LAB_14055e9fc;
              puVar32 = (ulonglong *)((longlong)puVar32 + 1);
              piVar27 = piVar27 + 1;
            } while (puVar32 < (ulonglong *)0x7);
            iVar19 = 0x37;
            goto LAB_14055ef60;
          }
          goto LAB_14055e97a;
        }
LAB_14055e9fc:
        if ((int)puVar28[0x2d] != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c64980 == 0) && (iVar19 = FUN_14023afa0(), -1 < iVar19)) {
              lVar29 = (**(code **)(*DAT_140c642f0 + 0x18))();
              goto LAB_14055ea48;
            }
          }
          else {
            lVar29 = (*DAT_140c63840)(&PTR_u_Spell4StackGroup_140a6d498,(int)puVar28[0x2d],
                                      DAT_140c63858);
LAB_14055ea48:
            if (lVar29 != 0) goto LAB_14055ea57;
          }
          iVar19 = 0x56;
          goto LAB_14055ef60;
        }
LAB_14055ea57:
        pvVar23 = local_res20;
        pvVar50 = (void *)((longlong)local_res20 + 1);
        _Dst = (void *)FUN_14018db00(local_178,pvVar50,8);
        pvVar30 = local_178;
        *(ulonglong **)((longlong)_Dst + (longlong)pvVar23 * 8) = puVar28;
        pvVar18 = local_178;
        if ((local_178 != _Dst) &&
           (memcpy(_Dst,local_178,(longlong)pvVar23 * 8), pvVar18 = _Dst, pvVar30 != (void *)0x0)) {
          (**(code **)(*(longlong *)((longlong)pvVar30 + -0x10) + 8))((longlong)pvVar30 + -0x10);
        }
        local_178 = pvVar18;
        puVar32 = (ulonglong *)((longlong)local_1a8 + 1);
        local_res20 = pvVar50;
        pvVar30 = (void *)FUN_14018db00(local_160,puVar32,8);
        pvVar50 = local_160;
        *(ulonglong **)((longlong)pvVar30 + (longlong)local_1a8 * 8) = puVar28;
        pvVar23 = local_160;
        if ((local_160 != pvVar30) &&
           (memcpy(pvVar30,local_160,(longlong)local_1a8 * 8), pvVar23 = pvVar30,
           pvVar50 != (void *)0x0)) {
          (**(code **)(*(longlong *)((longlong)pvVar50 + -0x10) + 8))((longlong)pvVar50 + -0x10);
        }
        local_160 = pvVar23;
        puVar1 = local_140;
        pvVar50 = local_150;
        puVar34 = local_140;
        if ((*(int *)(lVar26 + 0x50) - 1U & 0xfffffffd) == 0) {
          puVar34 = (ulonglong *)((longlong)local_140 + 1);
          pvVar30 = (void *)FUN_14018db00(local_150,puVar34,8);
          pvVar23 = local_150;
          *(ulonglong **)((longlong)pvVar30 + (longlong)puVar1 * 8) = puVar28;
          pvVar50 = local_150;
          if ((local_150 != pvVar30) &&
             (memcpy(pvVar30,local_150,(longlong)puVar1 * 8), pvVar50 = pvVar30,
             pvVar23 != (void *)0x0)) {
            (**(code **)(*(longlong *)((longlong)pvVar23 + -0x10) + 8))((longlong)pvVar23 + -0x10);
          }
        }
        local_140 = puVar34;
        local_150 = pvVar50;
        pvVar50 = local_130;
        uVar31 = local_158;
        uVar25 = local_158;
        pvVar23 = local_130;
        if (*(int *)(lVar26 + 0x50) == 8) {
          uVar25 = local_158 + 1;
          pvVar30 = (void *)FUN_14018db00(local_130,uVar25,8);
          *(ulonglong **)((longlong)pvVar30 + uVar31 * 8) = puVar28;
          pvVar23 = local_130;
          if ((pvVar50 != pvVar30) &&
             (memcpy(pvVar30,pvVar50,uVar31 * 8), pvVar23 = pvVar30, pvVar50 != (void *)0x0)) {
            (**(code **)(*(longlong *)((longlong)pvVar50 + -0x10) + 8))((longlong)pvVar50 + -0x10);
          }
        }
        local_130 = pvVar23;
        local_158 = uVar25;
        puVar34 = local_170;
        pvVar50 = local_198;
        if (((*(int *)((longlong)puVar28 + 0x34) != 0) || ((int)puVar28[7] != 0)) ||
           (pvVar23 = local_198, puVar1 = local_170, *(int *)((longlong)puVar28 + 0x4c) != 0)) {
          puVar1 = (ulonglong *)((longlong)local_170 + 1);
          pvVar30 = (void *)FUN_14018db00(local_198,puVar1,8);
          *(ulonglong **)((longlong)pvVar30 + (longlong)puVar34 * 8) = puVar28;
          pvVar23 = local_198;
          if ((pvVar50 != pvVar30) &&
             (memcpy(pvVar30,pvVar50,(longlong)puVar34 * 8), pvVar23 = pvVar30,
             pvVar50 != (void *)0x0)) {
            (**(code **)(*(longlong *)((longlong)pvVar50 + -0x10) + 8))((longlong)pvVar50 + -0x10);
          }
        }
        local_170 = puVar1;
        local_198 = pvVar23;
        pvVar50 = local_128;
        puVar1 = local_168;
        puVar34 = local_168;
        pvVar23 = local_128;
        if (*(int *)((longlong)puVar28 + 0x114) != 0) {
          puVar34 = (ulonglong *)((longlong)local_168 + 1);
          pvVar30 = (void *)FUN_14018db00(local_128,puVar34,8);
          *(ulonglong **)((longlong)pvVar30 + (longlong)puVar1 * 8) = puVar28;
          pvVar23 = local_128;
          if ((pvVar50 != pvVar30) &&
             (memcpy(pvVar30,pvVar50,(longlong)puVar1 * 8), pvVar23 = pvVar30,
             pvVar50 != (void *)0x0)) {
            (**(code **)(*(longlong *)((longlong)pvVar50 + -0x10) + 8))((longlong)pvVar50 + -0x10);
          }
        }
        local_128 = pvVar23;
        local_168 = puVar34;
        local_1a8 = puVar32;
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c63fa4 == 0) && (iVar19 = FUN_140238da0(), -1 < iVar19)) {
            puVar38 = (uint *)(**(code **)(*DAT_140c63c48 + 0x18))();
            goto LAB_14055ece9;
          }
        }
        else {
          puVar38 = (uint *)(*DAT_140c63840)(&PTR_u_Spell4GroupList_140a6d2d8,(int)puVar28[0x27],
                                             DAT_140c63858);
LAB_14055ece9:
          if (puVar38 != (uint *)0x0) {
            lVar26 = 0x20;
            do {
              puVar38 = puVar38 + 1;
              uVar51 = *puVar38;
              if (uVar51 == 0) goto LAB_14055ef09;
              uVar25 = *(ulonglong *)(param_1 + 0x720);
              uVar43 = uVar25;
              uVar31 = *(ulonglong *)(uVar25 + 8);
              while (uVar31 != 0) {
                if (*(uint *)(uVar31 + 0x20) < uVar51) {
                  uVar31 = *(ulonglong *)(uVar31 + 0x18);
                }
                else {
                  uVar43 = uVar31;
                  uVar31 = *(ulonglong *)(uVar31 + 0x10);
                }
              }
              if ((uVar43 == uVar25) || (uVar51 < *(uint *)(uVar43 + 0x20))) {
                local_148 = uVar25;
                puVar32 = &local_148;
              }
              else {
                local_118[0] = uVar43;
                puVar32 = local_118;
              }
              if (*puVar32 == uVar25) {
                puVar34 = (ulonglong *)FUN_14018b280(0x20);
                puVar32 = puVar24;
                if (puVar34 != (ulonglong *)0x0) {
                  puVar34[1] = 0;
                  puVar34[2] = 0;
                  puVar34[3] = 0;
                  puVar32 = puVar34;
                }
                pcVar6 = *(char **)(param_1 + 0x720);
                uVar51 = *puVar38;
                bVar53 = true;
                local_190 = (undefined **)CONCAT44(local_190._4_4_,uVar51);
                pcVar17 = pcVar6;
                pcVar42 = *(char **)(pcVar6 + 8);
                while (pcVar42 != (char *)0x0) {
                  bVar53 = uVar51 < *(uint *)(pcVar42 + 0x20);
                  pcVar17 = pcVar42;
                  if (bVar53) {
                    pcVar42 = *(char **)(pcVar42 + 0x10);
                  }
                  else {
                    pcVar42 = *(char **)(pcVar42 + 0x18);
                  }
                }
                pcVar42 = pcVar17;
                if (bVar53) {
                  if (pcVar17 != *(char **)(pcVar6 + 0x10)) {
                    if ((*pcVar17 == '\0') &&
                       (*(char **)(*(longlong *)(pcVar17 + 8) + 8) == pcVar17)) {
                      pcVar42 = *(char **)(pcVar17 + 0x18);
                    }
                    else {
                      pcVar42 = *(char **)(pcVar17 + 0x10);
                      if (pcVar42 == (char *)0x0) {
                        pcVar42 = *(char **)(pcVar17 + 8);
                        pcVar41 = pcVar42;
                        if (pcVar17 == *(char **)(pcVar42 + 0x10)) {
                          do {
                            pcVar42 = *(char **)(pcVar41 + 8);
                            bVar53 = pcVar41 == *(char **)(pcVar42 + 0x10);
                            pcVar41 = pcVar42;
                          } while (bVar53);
                        }
                      }
                      else {
                        for (pcVar41 = *(char **)(pcVar42 + 0x18); pcVar41 != (char *)0x0;
                            pcVar41 = *(char **)(pcVar41 + 0x18)) {
                          pcVar42 = pcVar41;
                        }
                      }
                    }
                    goto LAB_14055ee1d;
                  }
LAB_14055ee27:
                  if ((pcVar17 == pcVar6) || (uVar51 < *(uint *)(pcVar17 + 0x20))) {
                    lVar29 = FUN_14018b280(0x30);
                    if ((undefined8 *)(lVar29 + 0x20) != (undefined8 *)0x0) {
                      *(undefined8 *)(lVar29 + 0x20) = local_190;
                      *(ulonglong **)(lVar29 + 0x28) = puVar32;
                    }
                    *(longlong *)(pcVar17 + 0x10) = lVar29;
                    pcVar6 = *(char **)(param_1 + 0x720);
                    if (pcVar17 == pcVar6) {
                      *(longlong *)(pcVar6 + 8) = lVar29;
                      *(longlong *)(*(longlong *)(param_1 + 0x720) + 0x18) = lVar29;
                    }
                    else if (pcVar17 == *(char **)(pcVar6 + 0x10)) {
                      *(longlong *)(pcVar6 + 0x10) = lVar29;
                    }
                  }
                  else {
                    lVar29 = FUN_14018b280(0x30);
                    if ((undefined8 *)(lVar29 + 0x20) != (undefined8 *)0x0) {
                      *(undefined8 *)(lVar29 + 0x20) = local_190;
                      *(ulonglong **)(lVar29 + 0x28) = puVar32;
                    }
                    *(longlong *)(pcVar17 + 0x18) = lVar29;
                    if (pcVar17 == *(char **)(*(longlong *)(param_1 + 0x720) + 0x18)) {
                      *(longlong *)(*(longlong *)(param_1 + 0x720) + 0x18) = lVar29;
                    }
                  }
                  *(char **)(lVar29 + 8) = pcVar17;
                  *(undefined8 *)(lVar29 + 0x10) = 0;
                  *(undefined8 *)(lVar29 + 0x18) = 0;
                  FUN_1400081c0(lVar29,*(longlong *)(param_1 + 0x720) + 8);
                  *(longlong *)(param_1 + 0x728) = *(longlong *)(param_1 + 0x728) + 1;
                }
                else {
LAB_14055ee1d:
                  if (*(uint *)(pcVar42 + 0x20) < uVar51) goto LAB_14055ee27;
                }
                piVar27 = (int *)puVar32[2];
                if (piVar27 == (int *)puVar32[3]) {
LAB_14055ef01:
                  FUN_14017b140(puVar32,piVar27,puVar28);
                }
                else {
                  if (piVar27 != (int *)0x0) {
                    *piVar27 = (int)*puVar28;
                  }
                  puVar32[2] = puVar32[2] + 4;
                }
              }
              else {
                puVar32 = *(ulonglong **)(*puVar32 + 0x28);
                piVar27 = (int *)puVar32[2];
                if (piVar27[-1] != (int)*puVar28) {
                  if (piVar27 == (int *)puVar32[3]) goto LAB_14055ef01;
                  if (piVar27 != (int *)0x0) {
                    *piVar27 = (int)*puVar28;
                  }
                  puVar32[2] = puVar32[2] + 4;
                }
              }
LAB_14055ef09:
              lVar26 = lVar26 + -1;
            } while (lVar26 != 0);
          }
        }
      }
      uVar51 = (int)local_res18 + 1;
      puVar28 = (ulonglong *)(ulonglong)uVar51;
      local_res18 = (int *)CONCAT44(local_res18._4_4_,uVar51);
    } while (uVar51 < (uint)local_res10);
  }
  uVar25 = local_158;
  puVar32 = local_168;
  puVar28 = local_170;
  auVar8._8_8_ = 0;
  auVar8._0_8_ = local_res20;
  uVar31 = SUB168(ZEXT816(0x80) * auVar8,0);
  if (SUB168(ZEXT816(0x80) * auVar8,8) != 0) {
    uVar31 = 0xffffffffffffffff;
  }
  lVar26 = uVar31 + 8;
  if (0xfffffffffffffff7 < uVar31) {
    lVar26 = -1;
  }
  piVar27 = (int *)FUN_14018b280(lVar26,0);
  if (piVar27 == (int *)0x0) {
    piVar45 = (int *)0x0;
  }
  else {
    piVar45 = piVar27 + 2;
    *piVar27 = (int)local_res20;
    iVar19 = (int)local_res20 + -1;
    if (-1 < iVar19) {
      piVar27 = piVar27 + 0x1c;
      piVar40 = piVar45;
      do {
        iVar19 = iVar19 + -1;
        piVar27[-0x12] = 0;
        piVar27[-0x11] = 0;
        piVar27[-0x14] = 0;
        piVar27[-0x13] = 0;
        piVar27[0] = 0;
        piVar27[1] = 0;
        piVar27[-2] = 0;
        piVar27[-1] = 0;
        *(undefined ***)piVar40 = &PTR_FUN_140b667e0;
        piVar27[2] = 0;
        piVar27[3] = 0;
        piVar27[4] = 0;
        piVar40 = piVar40 + 0x20;
        piVar27 = piVar27 + 0x20;
      } while (-1 < iVar19);
    }
  }
  *(int **)(param_1 + 0x10) = piVar45;
  auVar9._8_8_ = 0;
  auVar9._0_8_ = local_res20;
  uVar33 = SUB168(ZEXT816(0x1b0) * auVar9,0);
  if (SUB168(ZEXT816(0x1b0) * auVar9,8) != 0) {
    uVar33 = 0xffffffffffffffff;
  }
  uVar33 = FUN_14018b280(uVar33,0);
  *(undefined8 *)(param_1 + 0x7d8) = uVar33;
  auVar10._8_8_ = 0;
  auVar10._0_8_ = local_1a8;
  uVar33 = SUB168(ZEXT816(0x10) * auVar10,0);
  if (SUB168(ZEXT816(0x10) * auVar10,8) != 0) {
    uVar33 = 0xffffffffffffffff;
  }
  uVar33 = FUN_14018b280(uVar33,0);
  *(undefined8 *)(param_1 + 0x20) = uVar33;
  auVar11._8_8_ = 0;
  auVar11._0_8_ = puVar28;
  uVar33 = SUB168(ZEXT816(0x24) * auVar11,0);
  if (SUB168(ZEXT816(0x24) * auVar11,8) != 0) {
    uVar33 = 0xffffffffffffffff;
  }
  uVar33 = FUN_14018b280(uVar33,0);
  *(undefined8 *)(param_1 + 0x28) = uVar33;
  auVar12._8_8_ = 0;
  auVar12._0_8_ = puVar32;
  uVar33 = SUB168(ZEXT816(0x28) * auVar12,0);
  if (SUB168(ZEXT816(0x28) * auVar12,8) != 0) {
    uVar33 = 0xffffffffffffffff;
  }
  uVar33 = FUN_14018b280(uVar33,0);
  *(undefined8 *)(param_1 + 0x30) = uVar33;
  auVar13._8_8_ = 0;
  auVar13._0_8_ = local_140;
  uVar33 = SUB168(ZEXT816(0x10) * auVar13,0);
  if (SUB168(ZEXT816(0x10) * auVar13,8) != 0) {
    uVar33 = 0xffffffffffffffff;
  }
  uVar33 = FUN_14018b280(uVar33,0);
  *(undefined8 *)(param_1 + 0x38) = uVar33;
  auVar14._8_8_ = 0;
  auVar14._0_8_ = uVar25;
  uVar31 = SUB168(ZEXT816(0x20) * auVar14,0);
  if (SUB168(ZEXT816(0x20) * auVar14,8) != 0) {
    uVar31 = 0xffffffffffffffff;
  }
  lVar26 = uVar31 + 8;
  if (0xfffffffffffffff7 < uVar31) {
    lVar26 = -1;
  }
  piVar27 = (int *)FUN_14018b280(lVar26,0);
  if (piVar27 == (int *)0x0) {
    piVar45 = (int *)0x0;
  }
  else {
    iVar19 = (int)uVar25;
    piVar45 = piVar27 + 2;
    *piVar27 = iVar19;
    piVar27 = piVar45;
    while (iVar19 = iVar19 + -1, -1 < iVar19) {
      piVar27[2] = 0;
      piVar27[3] = 0;
      piVar27[0] = 0;
      piVar27[1] = 0;
      piVar27[6] = 0;
      piVar27[7] = 0;
      piVar27[4] = 0;
      piVar27[5] = 0;
      piVar27 = piVar27 + 8;
    }
  }
  *(int **)(param_1 + 0x40) = piVar45;
  if (local_1a8 != (ulonglong *)0x0) {
    local_res10 = 0;
    puVar32 = puVar24;
    do {
      piVar27 = *(int **)((longlong)local_160 + (longlong)puVar32 * 8);
      iVar19 = *piVar27;
      piVar45 = (int *)(*(longlong *)(local_res8 + 0x20) + local_res10);
      piVar45[0] = 0;
      piVar45[1] = 0;
      piVar45[2] = 0;
      piVar45[3] = 0;
      local_res18 = piVar27;
      if (DAT_140c63840 == (code *)0x0) {
        puVar28 = puVar24;
        if ((DAT_140c64d94 == 0) && (iVar20 = FUN_140236320(), -1 < iVar20)) {
          puVar28 = (ulonglong *)(**(code **)(*DAT_140c653f0 + 0x18))(DAT_140c653f0,iVar19);
        }
      }
      else {
        puVar28 = (ulonglong *)(*DAT_140c63840)(&PTR_u_Spell4_140a6d0a8,iVar19,DAT_140c63858);
      }
      if ((piVar45 != (int *)0x0) && (puVar28 != (ulonglong *)0x0)) {
        *piVar45 = *(int *)((longlong)puVar28 + 0x24);
        bVar53 = *(int *)((longlong)puVar28 + 300) != 0;
        if (bVar53) {
          piVar45[1] = *(int *)((longlong)puVar28 + 300);
        }
        uVar25 = (ulonglong)bVar53;
        if ((int)puVar28[0x26] != 0) {
          uVar25 = (ulonglong)(bVar53 + 1);
          piVar45[(ulonglong)bVar53 + 1] = (int)puVar28[0x26];
        }
        uVar31 = uVar25;
        if (*(int *)((longlong)puVar28 + 0x134) != 0) {
          uVar31 = (ulonglong)((int)uVar25 + 1);
          piVar45[uVar25 + 1] = *(int *)((longlong)puVar28 + 0x134);
        }
        if ((uint)uVar31 < 3) {
          piVar40 = piVar45 + uVar31 + 1;
          for (uVar25 = (ulonglong)(3 - (uint)uVar31); uVar25 != 0; uVar25 = uVar25 - 1) {
            *piVar40 = 0;
            piVar40 = piVar40 + 1;
          }
        }
      }
      plVar2 = *(longlong **)(local_res8 + 0x548);
      if (*plVar2 == plVar2[1]) {
        FUN_1400290d0(plVar2);
      }
      uVar31 = (*(code *)plVar2[3])(piVar27);
      lVar26 = plVar2[2];
      uVar25 = plVar2[1];
      puVar34 = (ulonglong *)FUN_14018b280(0x20);
      puVar28 = puVar24;
      if (puVar34 != (ulonglong *)0x0) {
        uVar43 = *(ulonglong *)(lVar26 + (uVar31 % uVar25) * 8);
        *puVar34 = uVar31;
        puVar34[1] = uVar43;
        iVar19 = *local_res18;
        puVar34[3] = (ulonglong)piVar45;
        *(int *)(puVar34 + 2) = iVar19;
        puVar28 = puVar34;
      }
      *(ulonglong **)(lVar26 + (uVar31 % uVar25) * 8) = puVar28;
      *plVar2 = *plVar2 + 1;
      local_res10 = local_res10 + 0x10;
      puVar32 = (ulonglong *)((longlong)puVar32 + 1);
      puVar28 = local_170;
    } while (puVar32 < local_1a8);
  }
  if (puVar28 != (ulonglong *)0x0) {
    local_res10 = 0;
    puVar28 = puVar24;
    do {
      piVar27 = *(int **)((longlong)local_198 + (longlong)puVar28 * 8);
      iVar19 = *piVar27;
      piVar45 = (int *)(*(longlong *)(local_res8 + 0x28) + local_res10);
      piVar45[0] = 0;
      piVar45[1] = 0;
      piVar45[2] = 0;
      piVar45[3] = 0;
      piVar45[4] = 0;
      piVar45[5] = 0;
      piVar45[6] = 0;
      piVar45[7] = 0;
      piVar45[8] = 0;
      if (DAT_140c63840 == (code *)0x0) {
        puVar32 = puVar24;
        if ((DAT_140c64d94 == 0) && (iVar20 = FUN_140236320(), -1 < iVar20)) {
          puVar32 = (ulonglong *)(**(code **)(*DAT_140c653f0 + 0x18))(DAT_140c653f0,iVar19);
        }
      }
      else {
        puVar32 = (ulonglong *)(*DAT_140c63840)(&PTR_u_Spell4_140a6d0a8,iVar19,DAT_140c63858);
      }
      if ((piVar45 != (int *)0x0) && (puVar32 != (ulonglong *)0x0)) {
        *piVar45 = *(int *)((longlong)puVar32 + 0x34);
        piVar45[2] = *(int *)((longlong)puVar32 + 0x44);
        piVar45[4] = *(int *)((longlong)puVar32 + 0x3c);
        piVar45[1] = (int)puVar32[7];
        piVar45[3] = (int)puVar32[9];
        piVar45[5] = (int)puVar32[8];
        piVar45[6] = *(int *)((longlong)puVar32 + 0x4c);
        piVar45[7] = *(int *)((longlong)puVar32 + 0x54);
        piVar45[8] = (int)puVar32[10];
      }
      plVar2 = *(longlong **)(local_res8 + 0x550);
      if (*plVar2 == plVar2[1]) {
        FUN_1400290d0(plVar2);
      }
      local_res18 = (int *)(*(code *)plVar2[3])(piVar27);
      lVar26 = plVar2[2];
      uVar25 = (ulonglong)local_res18 % (ulonglong)plVar2[1];
      puVar34 = (ulonglong *)FUN_14018b280(0x20);
      puVar32 = puVar24;
      if (puVar34 != (ulonglong *)0x0) {
        uVar31 = *(ulonglong *)(lVar26 + uVar25 * 8);
        *puVar34 = (ulonglong)local_res18;
        puVar34[1] = uVar31;
        *(int *)(puVar34 + 2) = *piVar27;
        puVar34[3] = (ulonglong)piVar45;
        puVar32 = puVar34;
      }
      *(ulonglong **)(lVar26 + uVar25 * 8) = puVar32;
      *plVar2 = *plVar2 + 1;
      local_res10 = local_res10 + 0x24;
      puVar28 = (ulonglong *)((longlong)puVar28 + 1);
    } while (puVar28 < local_170);
  }
  if (local_168 != (ulonglong *)0x0) {
    local_res10 = 0;
    puVar28 = puVar24;
    do {
      uVar25 = local_res10;
      piVar27 = *(int **)((longlong)local_128 + (longlong)puVar28 * 8);
      iVar19 = piVar27[4];
      if (DAT_140c63840 == (code *)0x0) {
        puVar32 = puVar24;
        if (DAT_140c64510 == 0) {
          iVar20 = FUN_140236ba0();
          if (iVar20 < 0) {
            puVar32 = (ulonglong *)0x0;
          }
          else {
            puVar32 = (ulonglong *)(**(code **)(*DAT_140c654e0 + 0x18))(DAT_140c654e0,iVar19);
          }
        }
      }
      else {
        puVar32 = (ulonglong *)(*DAT_140c63840)(&PTR_u_Spell4Base_140a6d118,iVar19,DAT_140c63858);
      }
      lVar26 = local_res8;
      uVar25 = *(longlong *)(local_res8 + 0x30) + uVar25;
      FUN_1405698c0(puVar32,uVar25,(int)*puVar32,piVar27[0x45],(int)puVar32[3]);
      plVar2 = *(longlong **)(lVar26 + 0x558);
      if (*plVar2 == plVar2[1]) {
        FUN_1400290d0(plVar2);
      }
      local_res18 = (int *)(*(code *)plVar2[3])(piVar27);
      lVar26 = plVar2[2];
      uVar31 = (ulonglong)local_res18 % (ulonglong)plVar2[1];
      puVar34 = (ulonglong *)FUN_14018b280(0x20);
      puVar32 = puVar24;
      if (puVar34 != (ulonglong *)0x0) {
        uVar43 = *(ulonglong *)(lVar26 + uVar31 * 8);
        *puVar34 = (ulonglong)local_res18;
        puVar34[1] = uVar43;
        *(int *)(puVar34 + 2) = *piVar27;
        puVar34[3] = uVar25;
        puVar32 = puVar34;
      }
      *(ulonglong **)(lVar26 + uVar31 * 8) = puVar32;
      *plVar2 = *plVar2 + 1;
      local_res10 = local_res10 + 0x28;
      puVar28 = (ulonglong *)((longlong)puVar28 + 1);
    } while (puVar28 < local_168);
  }
  if (local_140 != (ulonglong *)0x0) {
    local_res10 = 0;
    do {
      lVar26 = 0;
      puVar22 = *(undefined4 **)((longlong)local_150 + (longlong)puVar24 * 8);
      uVar4 = *puVar22;
      puVar47 = (undefined8 *)(*(longlong *)(local_res8 + 0x38) + local_res10);
      if (DAT_140c63840 == (code *)0x0) {
        if ((DAT_140c64d94 == 0) && (iVar19 = FUN_140236320(), -1 < iVar19)) {
          lVar26 = (**(code **)(*DAT_140c653f0 + 0x18))(DAT_140c653f0,uVar4);
        }
      }
      else {
        lVar26 = (*DAT_140c63840)(&PTR_u_Spell4_140a6d0a8,uVar4,DAT_140c63858);
      }
      if ((puVar47 != (undefined8 *)0x0) && (lVar26 != 0)) {
        *puVar47 = 0;
        puVar47[1] = 0;
        *(undefined4 *)((longlong)puVar47 + 4) = *(undefined4 *)(lVar26 + 0x74);
        *(undefined4 *)puVar47 = *(undefined4 *)(lVar26 + 0x70);
        *(undefined4 *)(puVar47 + 1) = *(undefined4 *)(lVar26 + 0x78);
        *(undefined4 *)((longlong)puVar47 + 0xc) = *(undefined4 *)(lVar26 + 0xd4);
      }
      plVar2 = *(longlong **)(local_res8 + 0x560);
      if (*plVar2 == plVar2[1]) {
        FUN_1400290d0(plVar2);
      }
      uVar31 = (*(code *)plVar2[3])(puVar22);
      lVar26 = plVar2[2];
      uVar25 = plVar2[1];
      puVar28 = (ulonglong *)FUN_14018b280(0x20);
      if (puVar28 == (ulonglong *)0x0) {
        puVar28 = (ulonglong *)0x0;
      }
      else {
        uVar43 = *(ulonglong *)(lVar26 + (uVar31 % uVar25) * 8);
        *puVar28 = uVar31;
        puVar28[1] = uVar43;
        uVar4 = *puVar22;
        puVar28[3] = (ulonglong)puVar47;
        *(undefined4 *)(puVar28 + 2) = uVar4;
      }
      *(ulonglong **)(lVar26 + (uVar31 % uVar25) * 8) = puVar28;
      *plVar2 = *plVar2 + 1;
      local_res10 = local_res10 + 0x10;
      puVar24 = (ulonglong *)((longlong)puVar24 + 1);
    } while (puVar24 < local_140);
  }
  uVar31 = 0;
  uVar25 = uVar31;
  if (local_158 != 0) {
    do {
      puVar22 = *(undefined4 **)((longlong)local_130 + uVar31 * 8);
      puVar47 = (undefined8 *)(*(longlong *)(local_res8 + 0x40) + uVar25);
      *puVar47 = 0;
      puVar47[1] = 0;
      puVar47[2] = 0;
      puVar47[3] = 0;
      plVar2 = *(longlong **)(local_res8 + 0x568);
      if (*plVar2 == plVar2[1]) {
        FUN_1400290d0(plVar2);
      }
      local_res10 = (*(code *)plVar2[3])(puVar22);
      lVar26 = plVar2[2];
      uVar43 = local_res10 % (ulonglong)plVar2[1];
      puVar24 = (ulonglong *)FUN_14018b280(0x20);
      if (puVar24 == (ulonglong *)0x0) {
        puVar24 = (ulonglong *)0x0;
      }
      else {
        uVar44 = *(ulonglong *)(lVar26 + uVar43 * 8);
        *puVar24 = local_res10;
        puVar24[1] = uVar44;
        uVar4 = *puVar22;
        puVar24[3] = (ulonglong)puVar47;
        *(undefined4 *)(puVar24 + 2) = uVar4;
      }
      uVar31 = uVar31 + 1;
      *(ulonglong **)(lVar26 + uVar43 * 8) = puVar24;
      *plVar2 = *plVar2 + 1;
      uVar25 = uVar25 + 0x20;
    } while (uVar31 < local_158);
  }
  uVar51 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    iVar19 = 0;
    if ((DAT_140c64c2c == 0) && (iVar20 = FUN_14023e6e0(), -1 < iVar20)) {
      iVar19 = (**(code **)(*DAT_140c64af8 + 0x28))();
    }
  }
  else {
    iVar19 = (*DAT_140c63838)(&PTR_u_SpellPhase_140a6d770,DAT_140c63858);
  }
  local_res10 = CONCAT44(local_res10._4_4_,iVar19);
  if (iVar19 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c64c2c == 0) && (iVar19 = FUN_14023e6e0(), -1 < iVar19)) {
          lVar26 = (**(code **)(*DAT_140c64af8 + 0x20))();
          goto LAB_14055f86e;
        }
      }
      else {
        lVar26 = (*DAT_140c63848)(&PTR_u_SpellPhase_140a6d770,uVar51,DAT_140c63858);
LAB_14055f86e:
        if (lVar26 != 0) {
          lVar29 = *(longlong *)(local_res8 + 0x568);
          uVar25 = (**(code **)(lVar29 + 0x18))(lVar26 + 0x10);
          for (puVar24 = *(ulonglong **)
                          (*(longlong *)(lVar29 + 0x10) + (uVar25 % *(ulonglong *)(lVar29 + 8)) * 8)
              ; puVar24 != (ulonglong *)0x0; puVar24 = (ulonglong *)puVar24[1]) {
            if ((uVar25 == *puVar24) &&
               (iVar19 = (**(code **)(lVar29 + 0x20))(lVar26 + 0x10,puVar24 + 2), iVar19 != 0)) {
              if (puVar24 + 3 != (ulonglong *)0x0) {
                uVar25 = puVar24[3];
                if ((*(uint *)(lVar26 + 0xc) < 0x20) &&
                   ((*(uint *)(lVar26 + 0xc) == 0 || (*(int *)(lVar26 + 4) != 0)))) {
                  FUN_140003460(uVar25,lVar26 + 4);
                  FUN_140003460(uVar25 + 0x10,lVar26 + 8);
                }
              }
              break;
            }
          }
        }
      }
      uVar51 = uVar51 + 1;
    } while (uVar51 < (uint)local_res10);
  }
  pvVar50 = local_res20;
  auVar15._8_8_ = 0;
  auVar15._0_8_ = local_res20;
  uVar25 = SUB168(ZEXT816(0x70) * auVar15,0);
  if (SUB168(ZEXT816(0x70) * auVar15,8) != 0) {
    uVar25 = 0xffffffffffffffff;
  }
  lVar26 = uVar25 + 8;
  if (0xfffffffffffffff7 < uVar25) {
    lVar26 = -1;
  }
  piVar27 = (int *)FUN_14018b280(lVar26,0);
  if (piVar27 == (int *)0x0) {
    piVar45 = (int *)0x0;
  }
  else {
    iVar19 = (int)pvVar50;
    piVar45 = piVar27 + 2;
    *piVar27 = iVar19;
    piVar27 = piVar45;
    while (iVar19 = iVar19 + -1, -1 < iVar19) {
      piVar27[0] = 0;
      piVar27[1] = 0;
      piVar27[2] = 0;
      piVar27[3] = 0;
      FUN_1407e4830(piVar27 + 4,0,0x60);
      piVar27 = piVar27 + 0x1c;
    }
  }
  local_res18 = (void *)0x0;
  *(int **)(local_res8 + 0x18) = piVar45;
  if (pvVar50 != (void *)0x0) {
    do {
      piVar27 = local_res18;
      lVar26 = local_res8;
      lVar29 = 0;
      puVar22 = *(undefined4 **)((longlong)local_178 + (longlong)local_res18 * 8);
      uVar4 = puVar22[4];
      if (DAT_140c63840 == (code *)0x0) {
        if ((DAT_140c64510 == 0) && (iVar19 = FUN_140236ba0(), -1 < iVar19)) {
          lVar29 = (**(code **)(*DAT_140c654e0 + 0x18))(DAT_140c654e0,uVar4);
        }
      }
      else {
        lVar29 = (*DAT_140c63840)(&PTR_u_Spell4Base_140a6d118,uVar4,DAT_140c63858);
      }
      uVar25 = (longlong)piVar27 * 0x80 + *(longlong *)(lVar26 + 0x10);
      lVar5 = *(longlong *)(lVar26 + 0x7d8);
      if (*(int *)(uVar25 + 0x78) != 0) {
        FUN_14018b900(*(undefined8 *)(uVar25 + 0x70),0);
      }
      *(longlong *)(uVar25 + 0x70) = (longlong)piVar27 * 0x1b0 + lVar5;
      psVar48 = (short *)0x0;
      *(undefined4 *)(uVar25 + 0x78) = 0;
      FUN_1405697b0(local_e8,uVar25);
      uVar33 = FUN_140569480(lVar26,local_e8,*puVar22);
      FUN_140568540(uVar33,local_e8,*puVar22);
      *(undefined8 *)(local_78 + 0x10) = 0;
      local_e8[0] = &PTR_FUN_140b6c708;
      FUN_140569630(local_e8);
      if (local_70 != 0) {
        FUN_14018b900(local_78);
      }
      if (local_88 != 0) {
        (**(code **)(*(longlong *)(local_88 + -0x10) + 8))(local_88 + -0x10);
      }
      if (local_d0 != 0) {
        (**(code **)(*(longlong *)(local_d0 + -0x10) + 8))(local_d0 + -0x10);
      }
      iVar19 = FUN_140568260(uVar25);
      if (iVar19 == 0) {
        lVar26 = (longlong)piVar27 * 0x70 + *(longlong *)(lVar26 + 0x18);
        *(longlong *)(uVar25 + 8) = lVar26;
        *(undefined4 *)(lVar26 + 0x10) = *(undefined4 *)(lVar29 + 4);
        uVar31 = *(ulonglong *)(lVar29 + 0x48);
        psVar52 = psVar48;
        if ((uVar31 != 0) && (uVar31 <= DAT_140c3fe70)) {
          psVar52 = (short *)(DAT_140c3fe68 + uVar31);
        }
        puVar24 = *(ulonglong **)(uVar25 + 8);
        local_res10 = *puVar24;
        if (psVar52 == (short *)0x0) {
          *puVar24 = 0;
        }
        else {
          sVar3 = *psVar52;
          while (sVar3 != 0) {
            psVar48 = (short *)((longlong)psVar48 + 1);
            sVar3 = psVar52[(longlong)psVar48];
          }
          puVar47 = (undefined8 *)FUN_14018b280((longlong)psVar48 * 2 + 0x12,0);
          if (puVar47 != (undefined8 *)0x0) {
            puVar47[1] = psVar48;
            *puVar47 = &PTR_LAB_140b55060;
          }
          puVar47 = puVar47 + 2;
          memcpy(puVar47,psVar52,(longlong)psVar48 * 2);
          *(undefined2 *)((longlong)psVar48 * 2 + (longlong)puVar47) = 0;
          *puVar24 = (ulonglong)puVar47;
        }
        psVar48 = (short *)0x0;
        if (local_res10 != 0) {
          (**(code **)(*(longlong *)(local_res10 - 0x10) + 8))(local_res10 - 0x10);
        }
        uVar31 = *(ulonglong *)(lVar29 + 0x48);
        psVar52 = psVar48;
        if ((uVar31 != 0) && (uVar31 <= DAT_140c3fe70)) {
          psVar52 = (short *)(DAT_140c3fe68 + uVar31);
        }
        lVar26 = *(longlong *)(uVar25 + 8);
        local_res10 = *(ulonglong *)(lVar26 + 8);
        if (psVar52 == (short *)0x0) {
          *(undefined8 *)(lVar26 + 8) = 0;
        }
        else {
          sVar3 = *psVar52;
          while (sVar3 != 0) {
            psVar48 = (short *)((longlong)psVar48 + 1);
            sVar3 = psVar52[(longlong)psVar48];
          }
          puVar47 = (undefined8 *)FUN_14018b280((longlong)psVar48 * 2 + 0x12,0);
          if (puVar47 != (undefined8 *)0x0) {
            puVar47[1] = psVar48;
            *puVar47 = &PTR_LAB_140b55060;
          }
          puVar47 = puVar47 + 2;
          memcpy(puVar47,psVar52,(longlong)psVar48 * 2);
          *(undefined2 *)((longlong)psVar48 * 2 + (longlong)puVar47) = 0;
          *(undefined8 **)(lVar26 + 8) = puVar47;
        }
        uVar31 = 0;
        if (local_res10 != 0) {
          (**(code **)(*(longlong *)(local_res10 - 0x10) + 8))(local_res10 - 0x10);
        }
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x14) = *(undefined4 *)(lVar29 + 0x6c);
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x18) = *(undefined4 *)(lVar29 + 0x70);
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x20) = puVar22[0x1f];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x24) = puVar22[0x3e];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x28) = puVar22[0x3f];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x2c) = puVar22[0x40];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x30) = *(undefined4 *)(lVar29 + 0x78);
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x34) = puVar22[0x41];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x38) = *(undefined4 *)(lVar29 + 0x84);
        pfVar35 = (float *)(lVar29 + 0x88);
        do {
          if (*pfVar35 != 0.0) {
            uVar33 = FUN_14018b280(0x28);
            *(undefined8 *)(*(longlong *)(uVar25 + 8) + 0x40) = uVar33;
            **(undefined4 **)(*(longlong *)(uVar25 + 8) + 0x40) = *(undefined4 *)(lVar29 + 0x88);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 4) =
                 *(undefined4 *)(lVar29 + 0x8c);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 8) =
                 *(undefined4 *)(lVar29 + 0x90);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0xc) =
                 *(undefined4 *)(lVar29 + 0x94);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0x10) =
                 *(undefined4 *)(lVar29 + 0x98);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0x14) =
                 *(undefined4 *)(lVar29 + 0x9c);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0x18) =
                 *(undefined4 *)(lVar29 + 0xa0);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0x1c) =
                 *(undefined4 *)(lVar29 + 0xa4);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0x20) =
                 *(undefined4 *)(lVar29 + 0xa8);
            *(undefined4 *)(*(longlong *)(*(longlong *)(uVar25 + 8) + 0x40) + 0x24) =
                 *(undefined4 *)(lVar29 + 0xac);
            break;
          }
          uVar31 = uVar31 + 1;
          pfVar35 = pfVar35 + 1;
        } while (uVar31 < 10);
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x48) = puVar22[0x44];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x4c) = puVar22[0x42];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x50) = puVar22[0x43];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x6c) = *(undefined4 *)(lVar29 + 0x80);
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x54) = puVar22[0x29];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x5c) = puVar22[0x2b];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 100) = puVar22[0x2d];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x58) = puVar22[0x2a];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x60) = puVar22[0x2c];
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x68) = puVar22[0x2e];
        if (puVar22[5] != 0) {
          lVar26 = *(longlong *)(local_res8 + 0x618);
          uVar31 = (**(code **)(lVar26 + 0x18))(puVar22 + 4);
          for (puVar24 = *(ulonglong **)
                          (*(longlong *)(lVar26 + 0x10) + (uVar31 % *(ulonglong *)(lVar26 + 8)) * 8)
              ; puVar24 != (ulonglong *)0x0; puVar24 = (ulonglong *)puVar24[1]) {
            if ((uVar31 == *puVar24) &&
               (iVar19 = (**(code **)(lVar26 + 0x20))(puVar22 + 4), iVar19 != 0)) {
              if (puVar24 + 3 != (ulonglong *)0x0) {
                puVar24 = (ulonglong *)puVar24[3];
                goto LAB_14055ffad;
              }
              break;
            }
          }
          puVar32 = (ulonglong *)FUN_14018b280(0x10);
          puVar28 = (ulonglong *)0x0;
          puVar24 = puVar28;
          if (puVar32 != (ulonglong *)0x0) {
            puVar32[1] = 0;
            *puVar32 = 0;
            puVar24 = puVar32;
          }
          plVar2 = *(longlong **)(local_res8 + 0x618);
          if (*plVar2 == plVar2[1]) {
            FUN_1400290d0(plVar2);
          }
          local_148 = (*(code *)plVar2[3])(puVar22 + 4);
          uVar31 = local_148 % (ulonglong)plVar2[1];
          local_res10 = plVar2[2];
          puVar32 = (ulonglong *)FUN_14018b280(0x20);
          if (puVar32 != (ulonglong *)0x0) {
            uVar43 = *(ulonglong *)(local_res10 + uVar31 * 8);
            *puVar32 = local_148;
            puVar32[1] = uVar43;
            *(undefined4 *)(puVar32 + 2) = puVar22[4];
            puVar32[3] = (ulonglong)puVar24;
            puVar28 = puVar32;
          }
          *(ulonglong **)(local_res10 + uVar31 * 8) = puVar28;
          *plVar2 = *plVar2 + 1;
LAB_14055ffad:
          uVar51 = puVar22[5];
          uVar31 = (ulonglong)uVar51;
          if (puVar24[1] < uVar31) {
            if (puVar24[1] <= uVar31) {
              pvVar50 = (void *)FUN_14018db00(*puVar24,uVar31,4);
              uVar43 = puVar24[1];
              if (uVar43 < uVar31) {
                puVar49 = (undefined4 *)((longlong)pvVar50 + uVar43 * 4);
                for (lVar26 = uVar51 - uVar43; lVar26 != 0; lVar26 = lVar26 + -1) {
                  *puVar49 = 0;
                  puVar49 = puVar49 + 1;
                }
              }
              if ((void *)*puVar24 != pvVar50) {
                memcpy(pvVar50,(void *)*puVar24,puVar24[1] << 2);
                uVar43 = *puVar24;
                if (uVar43 != 0) {
                  (**(code **)(*(longlong *)(uVar43 - 0x10) + 8))(uVar43 - 0x10);
                }
                *puVar24 = (ulonglong)pvVar50;
              }
            }
            puVar24[1] = uVar31;
          }
          *(undefined4 *)(*puVar24 + (ulonglong)(puVar22[5] - 1) * 4) = *puVar22;
        }
        lVar26 = local_res8;
        uVar43 = 0;
        piVar27 = (int *)(*(longlong *)(uVar25 + 0x70) + 0x198);
        uVar31 = uVar43;
        do {
          if (*piVar27 == 10) {
            FUN_140003460(local_res8 + 0x7e0,lVar29);
            break;
          }
          uVar31 = uVar31 + 1;
          piVar27 = piVar27 + 1;
        } while (uVar31 < 5);
        piVar27 = (int *)(*(longlong *)(uVar25 + 0x70) + 0x198);
        do {
          if (*piVar27 == 5) {
            FUN_140003460(lVar26 + 0x7f0,lVar29);
            break;
          }
          uVar43 = uVar43 + 1;
          piVar27 = piVar27 + 1;
        } while (uVar43 < 5);
        *(undefined4 *)(*(longlong *)(uVar25 + 8) + 0x1c) = puVar22[0x21];
        FUN_140562560(lVar26,uVar25,puVar22[0x21]);
        plVar2 = *(longlong **)(lVar26 + 0x540);
        if (*plVar2 == plVar2[1]) {
          FUN_1400290d0(plVar2);
        }
        uVar43 = (*(code *)plVar2[3])(puVar22);
        lVar26 = plVar2[2];
        uVar31 = plVar2[1];
        puVar24 = (ulonglong *)FUN_14018b280(0x20);
        if (puVar24 == (ulonglong *)0x0) {
          puVar24 = (ulonglong *)0x0;
        }
        else {
          uVar44 = *(ulonglong *)(lVar26 + (uVar43 % uVar31) * 8);
          *puVar24 = uVar43;
          puVar24[1] = uVar44;
          uVar4 = *puVar22;
          puVar24[3] = uVar25;
          *(undefined4 *)(puVar24 + 2) = uVar4;
        }
        *(ulonglong **)(lVar26 + (uVar43 % uVar31) * 8) = puVar24;
        *plVar2 = *plVar2 + 1;
      }
      else {
        plVar2 = *(longlong **)(lVar26 + 0x570);
        if (*plVar2 == plVar2[1]) {
          FUN_1400290d0(plVar2);
        }
        uVar31 = (*(code *)plVar2[3])(puVar22);
        lVar26 = plVar2[2];
        uVar25 = plVar2[1];
        puVar24 = (ulonglong *)FUN_14018b280(0x18);
        if (puVar24 == (ulonglong *)0x0) {
          puVar24 = (ulonglong *)0x0;
        }
        else {
          uVar43 = *(ulonglong *)(lVar26 + (uVar31 % uVar25) * 8);
          *puVar24 = uVar31;
          puVar24[1] = uVar43;
          uVar4 = *puVar22;
          *(int *)((longlong)puVar24 + 0x14) = iVar19;
          *(undefined4 *)(puVar24 + 2) = uVar4;
        }
        *(ulonglong **)(lVar26 + (uVar31 % uVar25) * 8) = puVar24;
        *plVar2 = *plVar2 + 1;
        FUN_14018d540(&local_138,&DAT_140b4f534,iVar19);
        if (local_138 != 0) {
          (**(code **)(*(longlong *)(local_138 + -0x10) + 8))(local_138 + -0x10);
        }
      }
      local_res18 = (int *)((longlong)local_res18 + 1);
    } while (local_res18 < local_res20);
  }
  lVar26 = local_res8;
  puVar22 = (undefined4 *)0x0;
  local_1a8 = (ulonglong *)0x0;
  local_res18 = (undefined4 *)0x0;
  uVar51 = 0;
  uVar21 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c644e4 == 0) && (iVar19 = FUN_140238520(), uVar51 = uVar21, -1 < iVar19)) {
      uVar51 = (**(code **)(*DAT_140c63ba0 + 0x28))();
    }
  }
  else {
    uVar51 = (*DAT_140c63838)(&PTR_u_Spell4Effects_140a6d268,DAT_140c63858);
  }
  local_res8 = CONCAT44(local_res8._4_4_,uVar51);
  local_res10 = local_res10 & 0xffffffff00000000;
  puVar24 = (ulonglong *)puVar22;
  puVar49 = puVar22;
  piVar27 = puVar22;
  if (uVar51 != 0) {
LAB_1405601d0:
    if (DAT_140c63848 == (code *)0x0) {
      puVar36 = puVar22;
      if (DAT_140c644e4 == 0) {
        iVar19 = FUN_140238520();
        if (iVar19 < 0) {
          puVar36 = (undefined4 *)0x0;
        }
        else {
          puVar36 = (undefined4 *)(**(code **)(*DAT_140c63ba0 + 0x20))(DAT_140c63ba0,puVar49);
        }
      }
    }
    else {
      puVar36 = (undefined4 *)(*DAT_140c63848)(&PTR_u_Spell4Effects_140a6d268,puVar49,DAT_140c63858)
      ;
    }
    iVar19 = FUN_140567af0(lVar26);
    if (iVar19 == 0) {
      lVar29 = *(longlong *)(lVar26 + 0x540);
      uVar25 = (**(code **)(lVar29 + 0x18))(puVar36 + 1);
      for (puVar24 = *(ulonglong **)
                      (*(longlong *)(lVar29 + 0x10) + (uVar25 % *(ulonglong *)(lVar29 + 8)) * 8);
          piVar27 = local_res18, puVar24 != (ulonglong *)0x0; puVar24 = (ulonglong *)puVar24[1]) {
        if ((uVar25 == *puVar24) &&
           (iVar19 = (**(code **)(lVar29 + 0x20))(puVar36 + 1,puVar24 + 2), piVar45 = local_res18,
           iVar19 != 0)) {
          piVar27 = local_res18;
          if (puVar24 + 3 == (ulonglong *)0x0) break;
          piVar27 = (int *)(puVar24[3] + 0x28);
          *piVar27 = *piVar27 + 1;
          puVar49 = (undefined4 *)((longlong)local_1a8 + 1);
          puVar37 = (undefined4 *)FUN_14018db00(local_res18,puVar49,8);
          *(undefined4 **)(puVar37 + (longlong)local_1a8 * 2) = puVar36;
          piVar27 = piVar45;
          piVar40 = local_res18;
          if ((piVar45 != puVar37) &&
             (memcpy(puVar37,piVar45,(longlong)local_1a8 * 8), piVar27 = puVar37, piVar40 = puVar37,
             piVar45 != (undefined4 *)0x0)) {
            (**(code **)(*(longlong *)(piVar45 + -4) + 8))(piVar45 + -4);
          }
          local_res18 = piVar40;
          uVar4 = puVar36[0x1a];
          local_1a8 = (ulonglong *)puVar49;
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c6461c != 0) || (iVar19 = FUN_140238960(), iVar19 < 0)) break;
            puVar38 = (uint *)(**(code **)(*DAT_140c63f40 + 0x18))(DAT_140c63f40,uVar4);
          }
          else {
            puVar38 = (uint *)(*DAT_140c63840)(&PTR_u_Spell4EffectGroupList_140a6d2a0,uVar4,
                                               DAT_140c63858);
          }
          puVar49 = puVar22;
          if (puVar38 != (uint *)0x0) goto LAB_140560383;
          break;
        }
      }
    }
    else {
      FUN_14018d540(&local_138,&DAT_140b4f534,iVar19);
      if (local_138 != 0) {
        (**(code **)(*(longlong *)(local_138 + -0x10) + 8))(local_138 + -0x10);
      }
    }
    goto LAB_1405605a3;
  }
LAB_1405605c6:
  auVar16._8_8_ = 0;
  auVar16._0_8_ = puVar24;
  uVar33 = SUB168(ZEXT816(0xa8) * auVar16,0);
  if (SUB168(ZEXT816(0xa8) * auVar16,8) != 0) {
    uVar33 = 0xffffffffffffffff;
  }
  lVar29 = FUN_14018b280(uVar33,0);
  *(longlong *)(lVar26 + 0x48) = lVar29;
  puVar49 = puVar22;
  for (pvVar50 = local_res20; pvVar50 != (void *)0x0; pvVar50 = (void *)((longlong)pvVar50 - 1)) {
    lVar5 = *(longlong *)(lVar26 + 0x10);
    uVar51 = *(uint *)((longlong)puVar49 + lVar5 + 0x28);
    if (uVar51 != 0) {
      *(longlong *)((longlong)puVar49 + lVar5 + 0x30) = lVar29;
      *(undefined4 *)((longlong)puVar49 + lVar5 + 0x28) = 0;
      lVar29 = lVar29 + (ulonglong)uVar51 * 0xa8;
    }
    puVar49 = puVar49 + 0x20;
  }
  puVar49 = puVar22;
  if (puVar24 != (ulonglong *)0x0) {
    do {
      puVar36 = *(undefined4 **)(piVar27 + (longlong)puVar49 * 2);
      iVar19 = FUN_1402dd480(*(undefined8 *)(lVar26 + 0x540),puVar36 + 1,&local_res8);
      if (iVar19 == 0) {
        local_188 = 0;
        local_190 = &PTR_LAB_140b5e648;
        local_180 = TlsGetValue(DAT_140c63720);
        TlsSetValue(DAT_140c63720,&local_190);
        local_108 = local_190;
        local_res8 = 0x141e19050;
        local_f8 = local_180;
        local_100 = local_188;
        iVar19 = FUN_1401971e0(&DAT_140c8af24,0x18,&local_res8,&local_108);
        local_190 = &PTR_LAB_140b5e648;
        TlsSetValue(DAT_140c63720,local_180);
        if (iVar19 != 0) {
          DebugBreak();
        }
        puVar22 = (undefined4 *)0x80004005;
        goto LAB_1405608d5;
      }
      local_res10 = (ulonglong)*(uint *)(local_res8 + 0x28) * 0xa8 +
                    *(longlong *)(local_res8 + 0x30);
      *(uint *)(local_res8 + 0x28) = *(uint *)(local_res8 + 0x28) + 1;
      FUN_140567950(local_res8,local_res10,*puVar36);
      FUN_1400b6080(*(undefined8 *)(lVar26 + 0x578),puVar36,&local_res10);
      puVar49 = (undefined4 *)((longlong)puVar49 + 1);
    } while (puVar49 < puVar24);
  }
  if (DAT_140c63838 == (code *)0x0) {
    uVar51 = uVar21;
    if ((DAT_140c654a0 == 0) && (iVar19 = FUN_14023c0a0(), -1 < iVar19)) {
      uVar51 = (**(code **)(*DAT_140c63a88 + 0x28))();
    }
  }
  else {
    uVar51 = (*DAT_140c63838)(&PTR_u_Spell4Telegraph_140a6d578,DAT_140c63858);
  }
  puVar49 = puVar22;
  if (uVar51 != 0) {
    do {
      lVar29 = FUN_14023c360(puVar49);
      if ((((lVar29 != 0) &&
           (local_res10 = FUN_140241c40(*(undefined4 *)(lVar29 + 8)), local_res10 != 0)) &&
          (*(int *)(lVar29 + 4) != 0)) &&
         (iVar19 = FUN_1402dd480(*(undefined8 *)(lVar26 + 0x540),lVar29 + 4,&local_res8),
         iVar19 != 0)) {
        FUN_140033260(local_res8 + 0x60,&local_res10);
      }
      uVar46 = (int)puVar49 + 1;
      puVar49 = (undefined4 *)(ulonglong)uVar46;
    } while (uVar46 < uVar51);
  }
  FUN_1405677d0();
  uVar51 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    uVar46 = uVar21;
    if ((DAT_140c63f20 == 0) && (iVar19 = FUN_140239620(), uVar46 = uVar51, -1 < iVar19)) {
      uVar46 = (**(code **)(*DAT_140c63b48 + 0x28))();
    }
  }
  else {
    uVar46 = (*DAT_140c63838)(&PTR_u_Spell4Modification_140a6d348,DAT_140c63858);
  }
  FUN_1405666e0(uVar46,lVar26 + 0x6d8);
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c6428c == 0) && (iVar19 = FUN_1402380e0(), uVar51 = uVar21, -1 < iVar19)) {
      uVar51 = (**(code **)(*DAT_140c65328 + 0x28))();
    }
  }
  else {
    uVar51 = (*DAT_140c63838)(&PTR_u_Spell4EffectModification_140a6d230,DAT_140c63858);
  }
  FUN_140566810(uVar51,lVar26 + 0x6f8);
  FUN_140560b20(lVar26);
  FUN_140560d90(lVar26);
  FUN_140560f80(lVar26);
  FUN_140561340(lVar26);
  FUN_140548db0();
LAB_1405608d5:
  if (piVar27 != (undefined4 *)0x0) {
    (**(code **)(*(longlong *)(piVar27 + -4) + 8))(piVar27 + -4);
  }
  if (local_130 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_130 + -0x10) + 8))((longlong)local_130 + -0x10);
  }
  if (local_150 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_150 + -0x10) + 8))((longlong)local_150 + -0x10);
  }
  if (local_128 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_128 + -0x10) + 8))((longlong)local_128 + -0x10);
  }
  if (local_198 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_198 + -0x10) + 8))((longlong)local_198 + -0x10);
  }
  if (local_160 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_160 + -0x10) + 8))((longlong)local_160 + -0x10);
  }
  if (local_178 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_178 + -0x10) + 8))((longlong)local_178 + -0x10);
  }
  if (local_1a0 != (void *)0x0) {
    (**(code **)(*(longlong *)((longlong)local_1a0 + -0x10) + 8))((longlong)local_1a0 + -0x10);
  }
  return puVar22;
LAB_140560383:
  do {
    puVar38 = puVar38 + 1;
    uVar51 = *puVar38;
    piVar27 = local_res18;
    if (uVar51 == 0) break;
    uVar25 = *(ulonglong *)(lVar26 + 0x740);
    uVar43 = uVar25;
    uVar31 = *(ulonglong *)(uVar25 + 8);
    while (uVar31 != 0) {
      if (*(uint *)(uVar31 + 0x20) < uVar51) {
        uVar31 = *(ulonglong *)(uVar31 + 0x18);
      }
      else {
        uVar43 = uVar31;
        uVar31 = *(ulonglong *)(uVar31 + 0x10);
      }
    }
    if ((uVar43 == uVar25) || (uVar51 < *(uint *)(uVar43 + 0x20))) {
      local_118[0] = uVar25;
      puVar24 = local_118;
    }
    else {
      local_148 = uVar43;
      puVar24 = &local_148;
    }
    if (*puVar24 == uVar25) {
      puVar39 = (undefined4 *)FUN_14018b280(0x20);
      puVar37 = puVar22;
      if (puVar39 != (undefined4 *)0x0) {
        *(undefined8 *)(puVar39 + 2) = 0;
        *(undefined8 *)(puVar39 + 4) = 0;
        *(undefined8 *)(puVar39 + 6) = 0;
        puVar37 = puVar39;
      }
      pcVar6 = *(char **)(lVar26 + 0x740);
      uVar51 = *puVar38;
      bVar53 = true;
      local_190 = (undefined **)CONCAT44(local_190._4_4_,uVar51);
      pcVar17 = pcVar6;
      pcVar42 = *(char **)(pcVar6 + 8);
      while (pcVar42 != (char *)0x0) {
        bVar53 = uVar51 < *(uint *)(pcVar42 + 0x20);
        pcVar17 = pcVar42;
        if (bVar53) {
          pcVar42 = *(char **)(pcVar42 + 0x10);
        }
        else {
          pcVar42 = *(char **)(pcVar42 + 0x18);
        }
      }
      pcVar42 = pcVar17;
      if (bVar53) {
        if (pcVar17 != *(char **)(pcVar6 + 0x10)) {
          if ((*pcVar17 == '\0') && (*(char **)(*(longlong *)(pcVar17 + 8) + 8) == pcVar17)) {
            pcVar42 = *(char **)(pcVar17 + 0x18);
          }
          else {
            pcVar42 = *(char **)(pcVar17 + 0x10);
            if (pcVar42 == (char *)0x0) {
              pcVar42 = *(char **)(pcVar17 + 8);
              pcVar41 = pcVar42;
              if (pcVar17 == *(char **)(pcVar42 + 0x10)) {
                do {
                  pcVar42 = *(char **)(pcVar41 + 8);
                  bVar53 = pcVar41 == *(char **)(pcVar42 + 0x10);
                  pcVar41 = pcVar42;
                } while (bVar53);
              }
            }
            else {
              for (pcVar41 = *(char **)(pcVar42 + 0x18); pcVar41 != (char *)0x0;
                  pcVar41 = *(char **)(pcVar41 + 0x18)) {
                pcVar42 = pcVar41;
              }
            }
          }
          goto LAB_14056049d;
        }
      }
      else {
LAB_14056049d:
        if (uVar51 <= *(uint *)(pcVar42 + 0x20)) goto LAB_140560564;
      }
      if ((pcVar17 == pcVar6) || (uVar51 < *(uint *)(pcVar17 + 0x20))) {
        lVar29 = FUN_14018b280(0x30);
        if ((undefined8 *)(lVar29 + 0x20) != (undefined8 *)0x0) {
          *(undefined8 *)(lVar29 + 0x20) = local_190;
          *(undefined4 **)(lVar29 + 0x28) = puVar37;
        }
        *(longlong *)(pcVar17 + 0x10) = lVar29;
        pcVar6 = *(char **)(lVar26 + 0x740);
        if (pcVar17 == pcVar6) {
          *(longlong *)(pcVar6 + 8) = lVar29;
          *(longlong *)(*(longlong *)(lVar26 + 0x740) + 0x18) = lVar29;
        }
        else if (pcVar17 == *(char **)(pcVar6 + 0x10)) {
          *(longlong *)(pcVar6 + 0x10) = lVar29;
        }
      }
      else {
        lVar29 = FUN_14018b280(0x30);
        if ((undefined8 *)(lVar29 + 0x20) != (undefined8 *)0x0) {
          *(undefined8 *)(lVar29 + 0x20) = local_190;
          *(undefined4 **)(lVar29 + 0x28) = puVar37;
        }
        *(longlong *)(pcVar17 + 0x18) = lVar29;
        if (pcVar17 == *(char **)(*(longlong *)(lVar26 + 0x740) + 0x18)) {
          *(longlong *)(*(longlong *)(lVar26 + 0x740) + 0x18) = lVar29;
        }
      }
      *(char **)(lVar29 + 8) = pcVar17;
      *(undefined8 *)(lVar29 + 0x10) = 0;
      *(undefined8 *)(lVar29 + 0x18) = 0;
      FUN_1400081c0(lVar29,*(longlong *)(lVar26 + 0x740) + 8);
      *(longlong *)(lVar26 + 0x748) = *(longlong *)(lVar26 + 0x748) + 1;
    }
    else {
      puVar37 = *(undefined4 **)(*puVar24 + 0x28);
    }
LAB_140560564:
    puVar39 = *(undefined4 **)(puVar37 + 4);
    if (puVar39 == *(undefined4 **)(puVar37 + 6)) {
      FUN_14017b140(puVar37,puVar39,puVar36);
    }
    else {
      if (puVar39 != (undefined4 *)0x0) {
        *puVar39 = *puVar36;
      }
      *(longlong *)(puVar37 + 4) = *(longlong *)(puVar37 + 4) + 4;
    }
    uVar51 = (int)puVar49 + 1;
    puVar49 = (undefined4 *)(ulonglong)uVar51;
    piVar27 = local_res18;
  } while (uVar51 < 0x20);
LAB_1405605a3:
  uVar51 = (uint)local_res10 + 1;
  puVar49 = (undefined4 *)(ulonglong)uVar51;
  local_res10 = CONCAT44(local_res10._4_4_,uVar51);
  puVar24 = local_1a8;
  if ((uint)local_res8 <= uVar51) goto LAB_1405605c6;
  goto LAB_1405601d0;
}

