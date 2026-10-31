
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1403ce4a0(byte param_1,longlong param_2)

{
  uint *puVar1;
  short sVar2;
  double *pdVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  longlong lVar11;
  short *psVar12;
  undefined1 *puVar13;
  undefined1 **ppuVar14;
  undefined8 *puVar15;
  longlong lVar16;
  undefined8 uVar17;
  int *piVar18;
  ulonglong uVar19;
  ushort *puVar20;
  undefined1 *puVar21;
  undefined8 *puVar22;
  longlong lVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  uint uVar27;
  uint uVar28;
  longlong lVar29;
  undefined1 *puVar30;
  bool bVar31;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  undefined8 extraout_XMM0_Qa_04;
  undefined1 *puVar32;
  float fVar33;
  undefined1 auStack_398 [32];
  undefined8 local_378;
  uint local_370;
  int *local_368;
  undefined1 *local_360;
  longlong local_358;
  undefined1 local_350 [8];
  undefined1 *local_348;
  undefined8 local_340;
  undefined1 *local_330;
  undefined8 local_328;
  undefined1 *local_320;
  undefined **local_318;
  undefined4 local_310;
  longlong local_308;
  undefined4 local_300;
  undefined1 local_2f8 [8];
  undefined1 *local_2f0;
  undefined8 local_2e8;
  undefined1 local_2d8 [8];
  undefined1 *local_2d0;
  undefined8 local_2c8;
  undefined **local_2b8;
  undefined4 local_2b0;
  longlong local_2a8;
  undefined4 local_2a0;
  undefined **local_298;
  int local_290;
  undefined1 *local_288;
  undefined4 local_280;
  undefined **local_278;
  undefined1 local_270 [8];
  undefined2 *local_268;
  undefined2 *local_260;
  undefined2 *local_1b8;
  undefined2 *puStack_1b0;
  undefined2 *local_1a8;
  undefined1 local_198 [8];
  undefined1 local_190 [8];
  undefined2 *local_188;
  undefined2 *local_180;
  longlong local_d8;
  uint local_b8;
  uint uStack_b4;
  undefined8 uStack_b0;
  uint local_a8 [6];
  undefined8 uStack_90;
  uint local_88;
  undefined4 uStack_84;
  short *psStack_80;
  short *local_78;
  undefined4 local_68 [6];
  ulonglong local_50;
  
  lVar16 = DAT_140c65898;
  local_50 = DAT_140c0f7b0 ^ (ulonglong)auStack_398;
  local_358 = param_2;
  local_2f0 = (undefined1 *)FUN_14018b280(0x70);
  uVar27 = 0;
  local_2e8 = 0;
  *local_2f0 = 0;
  *(undefined8 *)(local_2f0 + 8) = 0;
  *(undefined1 **)(local_2f0 + 0x10) = local_2f0;
  *(undefined1 **)(local_2f0 + 0x18) = local_2f0;
  local_348 = (undefined1 *)FUN_14018b280(0x58);
  local_340 = 0;
  *local_348 = 0;
  *(undefined8 *)(local_348 + 8) = 0;
  *(undefined1 **)(local_348 + 0x10) = local_348;
  *(undefined1 **)(local_348 + 0x18) = local_348;
  local_2d0 = (undefined1 *)FUN_14018b280(0x30);
  local_2c8 = 0;
  *local_2d0 = 0;
  *(undefined8 *)(local_2d0 + 8) = 0;
  *(undefined1 **)(local_2d0 + 0x10) = local_2d0;
  *(undefined1 **)(local_2d0 + 0x18) = local_2d0;
  uVar28 = uVar27;
  while( true ) {
    if (DAT_140c63838 == (code *)0x0) {
      uVar5 = 0;
      if ((DAT_140c655f8 == 0) && (iVar6 = FUN_1401fd100(), -1 < iVar6)) {
        uVar5 = (**(code **)(*DAT_140c63fb8 + 0x28))();
      }
    }
    else {
      uVar5 = (*DAT_140c63838)(&PTR_u_EldanAugmentationCategory_140a6a1a0,DAT_140c63858);
    }
    if (uVar28 == uVar5) break;
    if (DAT_140c63848 == (code *)0x0) {
      if ((DAT_140c655f8 == 0) && (iVar6 = FUN_1401fd100(), -1 < iVar6)) {
        puVar10 = (uint *)(**(code **)(*DAT_140c63fb8 + 0x20))();
        goto LAB_1403ce628;
      }
    }
    else {
      puVar10 = (uint *)(*DAT_140c63848)(&PTR_u_EldanAugmentationCategory_140a6a1a0);
LAB_1403ce628:
      if (puVar10 != (uint *)0x0) {
        puVar30 = local_2d0;
        if (*(undefined1 **)(local_2d0 + 8) != (undefined1 *)0x0) {
          puVar32 = *(undefined1 **)(local_2d0 + 8);
          do {
            if (*(uint *)(puVar32 + 0x20) < *puVar10) {
              puVar13 = *(undefined1 **)(puVar32 + 0x18);
            }
            else {
              puVar13 = *(undefined1 **)(puVar32 + 0x10);
              puVar30 = puVar32;
            }
            puVar32 = puVar13;
          } while (puVar13 != (undefined1 *)0x0);
        }
        if ((puVar30 == local_2d0) || (*puVar10 < *(uint *)(puVar30 + 0x20))) {
          local_330 = (undefined1 *)CONCAT44(local_330._4_4_,*puVar10);
          local_328 = 0;
          local_360 = puVar30;
          FUN_140055c60(local_2d8,&local_378,&local_360,&local_330);
          puVar30 = local_378;
        }
        *(uint **)(puVar30 + 0x28) = puVar10;
        local_a8[1] = 0;
        local_a8[2] = 0;
        local_a8[3] = 0;
        local_a8[4] = 0;
        local_a8[5] = 0;
        local_b8 = *puVar10;
        uStack_b4 = puVar10[7];
        uStack_90 = 0;
        lVar11 = -(longlong)puVar10;
        puVar10 = puVar10 + 3;
        lVar23 = 2;
        do {
          puVar1 = puVar10 + 1;
          *(uint *)((longlong)&uStack_b4 + lVar11 + (longlong)puVar1) = puVar10[-2];
          *(uint *)((longlong)&uStack_b0 + lVar11 + 4 + (longlong)puVar1) = *puVar10;
          *(uint *)((longlong)local_a8 + lVar11 + 4 + (longlong)puVar1) = puVar10[2];
          lVar23 = lVar23 + -1;
          puVar10 = puVar1;
        } while (lVar23 != 0);
        uStack_b0 = 0;
        puVar10 = (uint *)FUN_1403d2880(local_350);
        *puVar10 = local_b8;
        puVar10[1] = uStack_b4;
        puVar10[2] = (uint)uStack_b0;
        puVar10[3] = uStack_b0._4_4_;
        puVar10[4] = 0;
        puVar10[5] = local_a8[1];
        puVar10[6] = local_a8[2];
        puVar10[7] = local_a8[3];
        puVar10[8] = local_a8[4];
        puVar10[9] = local_a8[5];
        puVar10[10] = (uint)uStack_90;
        puVar10[0xb] = uStack_90._4_4_;
      }
    }
    uVar28 = uVar28 + 1;
  }
  if (*(longlong *)(lVar16 + 0x78) == 0) {
    uVar28 = 0x17;
  }
  else {
    uVar28 = *(uint *)(*(longlong *)(lVar16 + 0x78) + 0xdc);
  }
  local_370 = uVar28;
  if ((DAT_140dc2338 & 1) != 0) goto LAB_1403ce86a;
  DAT_140dc2338 = DAT_140dc2338 | 1;
  if (DAT_140c63840 == (code *)0x0) {
    if ((DAT_140c638ac == 0) && (iVar6 = FUN_1401fffc0(), -1 < iVar6)) {
      lVar23 = (**(code **)(*DAT_140c64c58 + 0x18))(DAT_140c64c58,0x3ae);
      goto LAB_1403ce845;
    }
  }
  else {
    lVar23 = (*DAT_140c63840)(&PTR_u_GameFormula_140a6a408,0x3ae,DAT_140c63858);
LAB_1403ce845:
    if (lVar23 != 0) {
      _DAT_140dc233c = *(float *)(lVar23 + 0x1c);
      goto LAB_1403ce86a;
    }
  }
  _DAT_140dc233c = 0.5;
LAB_1403ce86a:
  uVar25 = 0;
  local_368 = (int *)CONCAT44(local_368._4_4_,uVar27);
  uVar5 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    uVar7 = uVar5;
    if ((DAT_140c65444 == 0) && (iVar6 = FUN_1401fd540(), -1 < iVar6)) {
      uVar7 = (**(code **)(*DAT_140c653a0 + 0x28))();
    }
  }
  else {
    uVar7 = (*DAT_140c63838)(&PTR_u_EldanAugmentation_140a6a1d8,DAT_140c63858);
  }
  if (uVar27 == uVar7) {
    puVar30 = *(undefined1 **)(local_348 + 0x10);
    while (puVar30 != local_348) {
      puVar10 = (uint *)(puVar30 + 0x48);
      uVar19 = uVar25;
      uVar26 = 3;
      do {
        uVar27 = (uint)uVar26;
        uVar9 = 0;
        if (uVar27 == 0) break;
        uVar28 = puVar10[-4];
        uVar24 = uVar26;
        if (uVar28 != 0) {
          puVar32 = *(undefined1 **)(local_348 + 8);
          puVar13 = local_348;
          if (*(undefined1 **)(local_348 + 8) == (undefined1 *)0x0) {
LAB_1403cef21:
            local_320 = local_348;
            ppuVar14 = &local_320;
          }
          else {
            do {
              if (*(uint *)(puVar32 + 0x20) < uVar28) {
                puVar21 = *(undefined1 **)(puVar32 + 0x18);
              }
              else {
                puVar21 = *(undefined1 **)(puVar32 + 0x10);
                puVar13 = puVar32;
              }
              puVar32 = puVar21;
            } while (puVar21 != (undefined1 *)0x0);
            if ((puVar13 == local_348) || (uVar28 < *(uint *)(puVar13 + 0x20))) goto LAB_1403cef21;
            local_330 = puVar13;
            ppuVar14 = &local_330;
          }
          puVar32 = *ppuVar14;
          uVar24 = uVar25;
          if (puVar32 != local_348) {
            if ((uint)(longlong)*(float *)(puVar32 + 0x30) < *puVar10) {
              if ((puVar10[-2] <= (uint)(longlong)*(float *)(puVar32 + 0x2c)) &&
                 (uVar24 = uVar26, 1 < uVar27)) {
                uVar24 = 1;
              }
            }
            else {
              uVar24 = uVar26;
              if (2 < uVar27) {
                uVar24 = 2;
              }
            }
          }
        }
        uVar9 = (undefined4)uVar24;
        uVar27 = (int)uVar19 + 1;
        uVar19 = (ulonglong)uVar27;
        puVar10 = puVar10 + 1;
        uVar26 = uVar24;
      } while (uVar27 < 2);
      *(undefined4 *)(puVar30 + 0x50) = uVar9;
      puVar32 = *(undefined1 **)(puVar30 + 0x18);
      if (puVar32 == (undefined1 *)0x0) {
        puVar32 = *(undefined1 **)(puVar30 + 8);
        if (puVar30 == *(undefined1 **)(puVar32 + 0x18)) {
          do {
            puVar30 = puVar32;
            puVar32 = *(undefined1 **)(puVar30 + 8);
          } while (puVar30 == *(undefined1 **)(puVar32 + 0x18));
        }
        if (*(undefined1 **)(puVar30 + 0x18) != puVar32) {
          puVar30 = puVar32;
        }
      }
      else {
        for (puVar13 = *(undefined1 **)(puVar32 + 0x10); puVar30 = puVar32,
            puVar13 != (undefined1 *)0x0; puVar13 = *(undefined1 **)(puVar13 + 0x10)) {
          puVar32 = puVar13;
        }
      }
    }
    puVar30 = *(undefined1 **)(local_2f0 + 0x10);
    if (puVar30 != local_2f0) {
      do {
        if ((*(int *)(puVar30 + 0x2c) == 1) &&
           (lVar16 = FUN_1403d2880(local_350,puVar30 + 0x50),
           *(uint *)(puVar30 + 0x54) <= *(uint *)(lVar16 + 0x2c))) {
          *(undefined4 *)(puVar30 + 0x2c) = 2;
        }
        puVar32 = *(undefined1 **)(puVar30 + 0x18);
        if (puVar32 == (undefined1 *)0x0) {
          puVar32 = *(undefined1 **)(puVar30 + 8);
          if (puVar30 == *(undefined1 **)(puVar32 + 0x18)) {
            do {
              puVar30 = puVar32;
              puVar32 = *(undefined1 **)(puVar30 + 8);
            } while (puVar30 == *(undefined1 **)(puVar32 + 0x18));
          }
          if (*(undefined1 **)(puVar30 + 0x18) != puVar32) {
            puVar30 = puVar32;
          }
        }
        else {
          for (puVar13 = *(undefined1 **)(puVar32 + 0x10); puVar30 = puVar32,
              puVar13 != (undefined1 *)0x0; puVar13 = *(undefined1 **)(puVar13 + 0x10)) {
            puVar32 = puVar13;
          }
        }
      } while (puVar30 != local_2f0);
    }
    lVar23 = local_358;
    local_68[3] = 1;
    lVar16 = *(longlong *)(local_358 + 0x10);
    local_68[0] = 4;
    local_68[1] = 2;
    local_68[2] = 6;
    local_68[4] = 5;
    local_68[5] = 3;
    local_2b8 = &PTR_FUN_140b569f0;
    local_2a0 = 1;
    local_2a8 = lVar16;
    if (*(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x70) <=
        *(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x78)) {
      FUN_14005e2c0(lVar16);
    }
    puVar15 = *(undefined8 **)(lVar16 + 0x10);
    uVar17 = FUN_14005c1b0(lVar16,0,0);
    *(undefined4 *)(puVar15 + 1) = 5;
    *puVar15 = uVar17;
    *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
    local_2b0 = FUN_1400578c0(lVar16);
    local_370 = 0;
    do {
      puVar30 = *(undefined1 **)(lVar23 + 0x10);
      local_298 = &PTR_FUN_140b569f0;
      local_280 = 1;
      local_330 = puVar30;
      local_288 = puVar30;
      if (*(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x70) <=
          *(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x78)) {
        FUN_14005e2c0(puVar30);
      }
      puVar15 = *(undefined8 **)(puVar30 + 0x10);
      uVar17 = FUN_14005c1b0(puVar30,0,0);
      *(undefined4 *)(puVar15 + 1) = 5;
      *puVar15 = uVar17;
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      iVar8 = FUN_1400578c0(puVar30);
      local_290 = iVar8;
      piVar18 = (int *)FUN_1403d2880(local_350,local_68 + uVar25);
      lVar16 = *(longlong *)(*(longlong *)(puVar30 + 0x20) + 0xa0);
      iVar6 = *piVar18;
      if (iVar8 - 1U < *(uint *)(lVar16 + 0x38)) {
        puVar15 = (undefined8 *)((longlong)(iVar8 + -1) * 0x10 + *(longlong *)(lVar16 + 0x18));
      }
      else {
        puVar32 = (undefined1 *)(double)iVar8;
        if ((double)puVar32 == 0.0) {
          puVar15 = *(undefined8 **)(lVar16 + 0x20);
        }
        else {
          local_378._4_4_ = (int)((ulonglong)puVar32 >> 0x20);
          local_378._0_4_ = (int)puVar32;
          puVar15 = (undefined8 *)
                    (*(longlong *)(lVar16 + 0x20) +
                    ((longlong)(ulonglong)(uint)(local_378._4_4_ + (int)local_378) %
                    (longlong)((1L << (*(byte *)(lVar16 + 0xb) & 0x3f)) - 1U | 1)) * 0x28);
        }
        do {
          local_378 = puVar32;
          if ((*(int *)(puVar15 + 3) == 3) && ((double)puVar32 == (double)puVar15[2]))
          goto LAB_1403cf201;
          puVar15 = (undefined8 *)puVar15[4];
        } while (puVar15 != (undefined8 *)0x0);
        puVar15 = (undefined8 *)&DAT_140a12138;
      }
LAB_1403cf201:
      puVar22 = *(undefined8 **)(puVar30 + 0x10);
      *puVar22 = *puVar15;
      *(undefined4 *)(puVar22 + 1) = *(undefined4 *)(puVar15 + 1);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      local_368 = piVar18;
      lVar16 = FUN_14018f0e0(&local_b8,&DAT_140af66d8);
      lVar16 = *(longlong *)(lVar16 + 8);
      if (lVar16 == 0) {
        *(undefined4 *)(*(longlong *)(puVar30 + 0x10) + 8) = 0;
        *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      }
      else {
        lVar23 = -1;
        do {
          lVar23 = lVar23 + 1;
        } while (*(char *)(lVar16 + lVar23) != '\0');
        if (*(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x70) <=
            *(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x78)) {
          FUN_14005e2c0(puVar30);
        }
        puVar15 = *(undefined8 **)(puVar30 + 0x10);
        uVar17 = FUN_140062650(puVar30,lVar16,lVar23);
        *(undefined4 *)(puVar15 + 1) = 4;
        *puVar15 = uVar17;
        *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
        piVar18 = local_368;
      }
      if (uStack_b0 != 0) {
        FUN_14018b900(uStack_b0,0);
      }
      pdVar3 = *(double **)(puVar30 + 0x10);
      *(undefined4 *)(pdVar3 + 1) = 3;
      *pdVar3 = (double)iVar6;
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      uVar17 = FUN_1400580e0(puVar30,0xfffffffd);
      uVar17 = FUN_14005ea50(puVar30,uVar17,*(longlong *)(puVar30 + 0x10) + -0x20,
                             *(longlong *)(puVar30 + 0x10) + -0x10);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + -0x30;
      uVar17 = FUN_14034bdd0(uVar17,piVar18[1]);
      lVar16 = *(longlong *)(*(longlong *)(puVar30 + 0x20) + 0xa0);
      if (iVar8 - 1U < *(uint *)(lVar16 + 0x38)) {
        puVar15 = (undefined8 *)((longlong)(iVar8 + -1) * 0x10 + *(longlong *)(lVar16 + 0x18));
      }
      else {
        puVar32 = (undefined1 *)(double)iVar8;
        if ((double)puVar32 == 0.0) {
          puVar15 = *(undefined8 **)(lVar16 + 0x20);
        }
        else {
          local_378._4_4_ = (int)((ulonglong)puVar32 >> 0x20);
          local_378._0_4_ = (int)puVar32;
          puVar15 = (undefined8 *)
                    (*(longlong *)(lVar16 + 0x20) +
                    ((longlong)(ulonglong)(uint)(local_378._4_4_ + (int)local_378) %
                    (longlong)((1L << (*(byte *)(lVar16 + 0xb) & 0x3f)) - 1U | 1)) * 0x28);
        }
        do {
          local_378 = puVar32;
          if ((*(int *)(puVar15 + 3) == 3) && ((double)puVar32 == (double)puVar15[2]))
          goto LAB_1403cf38d;
          puVar15 = (undefined8 *)puVar15[4];
        } while (puVar15 != (undefined8 *)0x0);
        puVar15 = (undefined8 *)&DAT_140a12138;
      }
LAB_1403cf38d:
      puVar22 = *(undefined8 **)(puVar30 + 0x10);
      *puVar22 = *puVar15;
      *(undefined4 *)(puVar22 + 1) = *(undefined4 *)(puVar15 + 1);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      FUN_1400f0870(puVar30,puVar15,L"strName",uVar17);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + -0x10;
      fVar33 = (float)piVar18[4];
      lVar16 = *(longlong *)(*(longlong *)(puVar30 + 0x20) + 0xa0);
      puVar15 = *(undefined8 **)(puVar30 + 0x10);
      if (iVar8 - 1U < *(uint *)(lVar16 + 0x38)) {
        puVar22 = (undefined8 *)((longlong)(iVar8 + -1) * 0x10 + *(longlong *)(lVar16 + 0x18));
      }
      else {
        puVar32 = (undefined1 *)(double)iVar8;
        if ((double)puVar32 == 0.0) {
          puVar22 = *(undefined8 **)(lVar16 + 0x20);
        }
        else {
          local_378._4_4_ = (int)((ulonglong)puVar32 >> 0x20);
          local_378._0_4_ = (int)puVar32;
          puVar22 = (undefined8 *)
                    (*(longlong *)(lVar16 + 0x20) +
                    ((longlong)(ulonglong)(uint)(local_378._4_4_ + (int)local_378) %
                    (longlong)((1L << (*(byte *)(lVar16 + 0xb) & 0x3f)) - 1U | 1)) * 0x28);
        }
        do {
          local_378 = puVar32;
          if ((*(int *)(puVar22 + 3) == 3) && ((double)puVar32 == (double)puVar22[2]))
          goto LAB_1403cf44d;
          puVar22 = (undefined8 *)puVar22[4];
        } while (puVar22 != (undefined8 *)0x0);
        puVar22 = (undefined8 *)&DAT_140a12138;
      }
LAB_1403cf44d:
      *puVar15 = *puVar22;
      *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      lVar16 = FUN_14018f0e0(&local_b8,L"fPowerInCategory");
      lVar16 = *(longlong *)(lVar16 + 8);
      if (lVar16 == 0) {
        *(undefined4 *)(*(longlong *)(puVar30 + 0x10) + 8) = 0;
      }
      else {
        lVar23 = -1;
        do {
          lVar23 = lVar23 + 1;
        } while (*(char *)(lVar16 + lVar23) != '\0');
        if (*(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x70) <=
            *(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x78)) {
          FUN_14005e2c0(puVar30);
        }
        puVar15 = *(undefined8 **)(puVar30 + 0x10);
        uVar17 = FUN_140062650(puVar30,lVar16,lVar23);
        *(undefined4 *)(puVar15 + 1) = 4;
        *puVar15 = uVar17;
        piVar18 = local_368;
      }
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      if (uStack_b0 != 0) {
        FUN_14018b900(uStack_b0,0);
      }
      pdVar3 = *(double **)(puVar30 + 0x10);
      *(undefined4 *)(pdVar3 + 1) = 3;
      *pdVar3 = (double)fVar33;
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      uVar17 = FUN_1400580e0(puVar30,0xfffffffd);
      FUN_14005ea50(puVar30,uVar17,*(longlong *)(puVar30 + 0x10) + -0x20,
                    *(longlong *)(puVar30 + 0x10) + -0x10);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + -0x30;
      lVar16 = *(longlong *)(*(longlong *)(puVar30 + 0x20) + 0xa0);
      iVar6 = piVar18[0xb];
      puVar15 = *(undefined8 **)(puVar30 + 0x10);
      if (iVar8 - 1U < *(uint *)(lVar16 + 0x38)) {
        puVar22 = (undefined8 *)((longlong)(iVar8 + -1) * 0x10 + *(longlong *)(lVar16 + 0x18));
      }
      else {
        puVar32 = (undefined1 *)(double)iVar8;
        if ((double)puVar32 == 0.0) {
          puVar22 = *(undefined8 **)(lVar16 + 0x20);
        }
        else {
          local_378._4_4_ = (int)((ulonglong)puVar32 >> 0x20);
          local_378._0_4_ = (int)puVar32;
          puVar22 = (undefined8 *)
                    (*(longlong *)(lVar16 + 0x20) +
                    ((longlong)(ulonglong)(uint)(local_378._4_4_ + (int)local_378) %
                    (longlong)((1L << (*(byte *)(lVar16 + 0xb) & 0x3f)) - 1U | 1)) * 0x28);
        }
        do {
          local_378 = puVar32;
          if ((*(int *)(puVar22 + 3) == 3) && ((double)puVar32 == (double)puVar22[2]))
          goto LAB_1403cf5c4;
          puVar22 = (undefined8 *)puVar22[4];
        } while (puVar22 != (undefined8 *)0x0);
        puVar22 = (undefined8 *)&DAT_140a12138;
      }
LAB_1403cf5c4:
      *puVar15 = *puVar22;
      *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      lVar16 = FUN_14018f0e0(&local_b8,L"nHighestTierUnlocked");
      lVar16 = *(longlong *)(lVar16 + 8);
      if (lVar16 == 0) {
        *(undefined4 *)(*(longlong *)(puVar30 + 0x10) + 8) = 0;
      }
      else {
        lVar23 = -1;
        do {
          lVar23 = lVar23 + 1;
        } while (*(char *)(lVar16 + lVar23) != '\0');
        if (*(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x70) <=
            *(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x78)) {
          FUN_14005e2c0(puVar30);
        }
        puVar15 = *(undefined8 **)(puVar30 + 0x10);
        uVar17 = FUN_140062650(puVar30,lVar16,lVar23);
        *(undefined4 *)(puVar15 + 1) = 4;
        *puVar15 = uVar17;
        piVar18 = local_368;
      }
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      if (uStack_b0 != 0) {
        FUN_14018b900(uStack_b0,0);
      }
      pdVar3 = *(double **)(puVar30 + 0x10);
      *(undefined4 *)(pdVar3 + 1) = 3;
      *pdVar3 = (double)(iVar6 + 1);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      uVar17 = FUN_1400580e0(puVar30,0xfffffffd);
      FUN_14005ea50(puVar30,uVar17,*(longlong *)(puVar30 + 0x10) + -0x20,
                    *(longlong *)(puVar30 + 0x10) + -0x10);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + -0x30;
      lVar16 = *(longlong *)(*(longlong *)(puVar30 + 0x20) + 0xa0);
      puVar15 = *(undefined8 **)(puVar30 + 0x10);
      uVar27 = (piVar18[6] != 0) + 1;
      if (iVar8 - 1U < *(uint *)(lVar16 + 0x38)) {
        puVar22 = (undefined8 *)((longlong)(iVar8 + -1) * 0x10 + *(longlong *)(lVar16 + 0x18));
      }
      else {
        puVar32 = (undefined1 *)(double)iVar8;
        if ((double)puVar32 == 0.0) {
          puVar22 = *(undefined8 **)(lVar16 + 0x20);
        }
        else {
          local_378._4_4_ = (int)((ulonglong)puVar32 >> 0x20);
          local_378._0_4_ = (int)puVar32;
          puVar22 = (undefined8 *)
                    (*(longlong *)(lVar16 + 0x20) +
                    ((longlong)(ulonglong)(uint)(local_378._4_4_ + (int)local_378) %
                    (longlong)((1L << (*(byte *)(lVar16 + 0xb) & 0x3f)) - 1U | 1)) * 0x28);
        }
        do {
          local_378 = puVar32;
          if ((*(int *)(puVar22 + 3) == 3) && ((double)puVar32 == (double)puVar22[2]))
          goto LAB_1403cf740;
          puVar22 = (undefined8 *)puVar22[4];
        } while (puVar22 != (undefined8 *)0x0);
        puVar22 = (undefined8 *)&DAT_140a12138;
      }
LAB_1403cf740:
      *puVar15 = *puVar22;
      *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      lVar16 = FUN_14018f0e0(&local_b8,L"nCategoriesToUnlock");
      lVar16 = *(longlong *)(lVar16 + 8);
      if (lVar16 == 0) {
        *(undefined4 *)(*(longlong *)(puVar30 + 0x10) + 8) = 0;
      }
      else {
        lVar23 = -1;
        do {
          lVar23 = lVar23 + 1;
        } while (*(char *)(lVar16 + lVar23) != '\0');
        if (*(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x70) <=
            *(ulonglong *)(*(longlong *)(puVar30 + 0x20) + 0x78)) {
          FUN_14005e2c0(puVar30);
        }
        puVar15 = *(undefined8 **)(puVar30 + 0x10);
        uVar17 = FUN_140062650(puVar30,lVar16,lVar23);
        *(undefined4 *)(puVar15 + 1) = 4;
        *puVar15 = uVar17;
      }
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      if (uStack_b0 != 0) {
        FUN_14018b900(uStack_b0,0);
      }
      pdVar3 = *(double **)(puVar30 + 0x10);
      *(undefined4 *)(pdVar3 + 1) = 3;
      *pdVar3 = (double)uVar27;
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + 0x10;
      uVar17 = FUN_1400580e0(puVar30,0xfffffffd);
      FUN_14005ea50(puVar30,uVar17,*(longlong *)(puVar30 + 0x10) + -0x20,
                    *(longlong *)(puVar30 + 0x10) + -0x10);
      lVar23 = local_358;
      *(longlong *)(puVar30 + 0x10) = *(longlong *)(puVar30 + 0x10) + -0x30;
      lVar16 = *(longlong *)(local_358 + 0x10);
      local_300 = 1;
      local_318 = &PTR_FUN_140b569f0;
      local_308 = lVar16;
      if (*(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x70) <=
          *(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x78)) {
        FUN_14005e2c0(lVar16);
      }
      puVar15 = *(undefined8 **)(lVar16 + 0x10);
      uVar17 = FUN_14005c1b0(lVar16,0,0);
      *(undefined4 *)(puVar15 + 1) = 5;
      *puVar15 = uVar17;
      *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
      local_310 = FUN_1400578c0(lVar16);
      if (uVar27 != 0) {
        puVar30 = (undefined1 *)(ulonglong)uVar27;
        piVar18 = local_368 + 7;
        do {
          lVar16 = *(longlong *)(lVar23 + 0x10);
          local_360 = puVar30;
          if (*(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x70) <=
              *(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x78)) {
            FUN_14005e2c0(lVar16);
          }
          puVar15 = *(undefined8 **)(lVar16 + 0x10);
          uVar17 = FUN_14005c1b0(lVar16,0,0);
          *(undefined4 *)(puVar15 + 1) = 5;
          *puVar15 = uVar17;
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
          iVar8 = FUN_1400578c0(lVar16);
          iVar6 = piVar18[-2];
          lVar11 = *(longlong *)(*(longlong *)(lVar16 + 0x20) + 0xa0);
          local_368 = (int *)CONCAT44(local_368._4_4_,iVar6);
          if (iVar8 - 1U < *(uint *)(lVar11 + 0x38)) {
            puVar15 = (undefined8 *)((longlong)(iVar8 + -1) * 0x10 + *(longlong *)(lVar11 + 0x18));
          }
          else {
            puVar32 = (undefined1 *)(double)iVar8;
            if ((double)puVar32 == 0.0) {
              puVar15 = *(undefined8 **)(lVar11 + 0x20);
            }
            else {
              local_378._4_4_ = (int)((ulonglong)puVar32 >> 0x20);
              local_378._0_4_ = (int)puVar32;
              puVar15 = (undefined8 *)
                        (*(longlong *)(lVar11 + 0x20) +
                        ((longlong)(ulonglong)(uint)(local_378._4_4_ + (int)local_378) %
                        (longlong)((1L << (*(byte *)(lVar11 + 0xb) & 0x3f)) - 1U | 1)) * 0x28);
            }
            do {
              local_378 = puVar32;
              if ((*(int *)(puVar15 + 3) == 3) && ((double)puVar32 == (double)puVar15[2]))
              goto LAB_1403cf97d;
              puVar15 = (undefined8 *)puVar15[4];
            } while (puVar15 != (undefined8 *)0x0);
            puVar15 = (undefined8 *)&DAT_140a12138;
          }
LAB_1403cf97d:
          puVar22 = *(undefined8 **)(lVar16 + 0x10);
          *puVar22 = *puVar15;
          *(undefined4 *)(puVar22 + 1) = *(undefined4 *)(puVar15 + 1);
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
          lVar11 = FUN_14018f0e0(&local_b8,L"nUnlockCategoryId");
          lVar11 = *(longlong *)(lVar11 + 8);
          if (lVar11 == 0) {
            *(undefined4 *)(*(longlong *)(lVar16 + 0x10) + 8) = 0;
          }
          else {
            lVar29 = -1;
            do {
              lVar29 = lVar29 + 1;
            } while (*(char *)(lVar11 + lVar29) != '\0');
            if (*(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x70) <=
                *(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x78)) {
              FUN_14005e2c0(lVar16);
            }
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            uVar17 = FUN_140062650(lVar16,lVar11,lVar29);
            *(undefined4 *)(puVar15 + 1) = 4;
            *puVar15 = uVar17;
            puVar30 = local_360;
            iVar6 = (uint)local_368;
          }
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
          if (uStack_b0 != 0) {
            FUN_14018b900(uStack_b0,0);
          }
          pdVar3 = *(double **)(lVar16 + 0x10);
          *(undefined4 *)(pdVar3 + 1) = 3;
          *pdVar3 = (double)iVar6;
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
          uVar17 = FUN_1400580e0(lVar16,0xfffffffd);
          FUN_14005ea50(lVar16,uVar17,*(longlong *)(lVar16 + 0x10) + -0x20,
                        *(longlong *)(lVar16 + 0x10) + -0x10);
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x30;
          puVar15 = *(undefined8 **)(lVar16 + 0x10);
          puVar22 = (undefined8 *)
                    FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),iVar8);
          *puVar15 = *puVar22;
          *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
          FUN_1400f06f0(lVar16);
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
          puVar15 = *(undefined8 **)(lVar16 + 0x10);
          uVar25 = (ulonglong)(uint)piVar18[2];
          puVar22 = (undefined8 *)
                    FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),iVar8);
          uVar17 = *puVar22;
          *puVar15 = uVar17;
          *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
          FUN_1400f06f0(lVar16,uVar17,L"nTier3Amount",uVar25 & 0xffffffff);
          *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
          FUN_1400fb1d0(&local_318);
          FUN_1400579e0(lVar16);
          piVar18 = piVar18 + 1;
          puVar30 = puVar30 + -1;
        } while (puVar30 != (undefined1 *)0x0);
        local_360 = (undefined1 *)0x0;
        puVar30 = local_330;
        lVar16 = local_308;
        lVar23 = local_358;
      }
      FUN_1400fb2a0(&local_298,L"tUnlockedCategories",local_310);
      FUN_1400fb1d0(&local_2b8);
      if (lVar16 != 0) {
        FUN_1400579e0(lVar16);
      }
      FUN_1400579e0(puVar30);
      local_370 = local_370 + 1;
      uVar25 = (ulonglong)local_370;
      if (5 < local_370) {
        FUN_1400fb2a0(lVar23,L"tCategories",local_2b0);
        lVar16 = *(longlong *)(lVar23 + 0x10);
        local_318 = &PTR_FUN_140b569f0;
        local_300 = 1;
        local_308 = lVar16;
        if (*(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x70) <=
            *(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x78)) {
          FUN_14005e2c0(lVar16);
        }
        puVar15 = *(undefined8 **)(lVar16 + 0x10);
        uVar17 = FUN_14005c1b0(lVar16,0,0);
        *(undefined4 *)(puVar15 + 1) = 5;
        *puVar15 = uVar17;
        *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
        local_310 = FUN_1400578c0(lVar16);
        puVar30 = *(undefined1 **)(local_2f0 + 0x10);
        if (puVar30 != local_2f0) {
          do {
            lVar16 = *(longlong *)(lVar23 + 0x10);
            if (*(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x70) <=
                *(ulonglong *)(*(longlong *)(lVar16 + 0x20) + 0x78)) {
              FUN_14005e2c0(lVar16);
            }
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            uVar17 = FUN_14005c1b0(lVar16,0,0);
            *(undefined4 *)(puVar15 + 1) = 5;
            *puVar15 = uVar17;
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            uVar9 = FUN_1400578c0(lVar16);
            uVar25 = (ulonglong)*(uint *)(puVar30 + 0x28);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16,puVar15,&DAT_140af65a8,uVar25 & 0xffffffff);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f0630(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f0630(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f0630(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0));
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f06f0(lVar16);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            FUN_1400b6f30(&local_278);
            local_278 = &PTR_FUN_140b69230;
            local_1a8 = (undefined2 *)0x0;
            local_1b8 = (undefined2 *)0x0;
            puStack_1b0 = (undefined2 *)0x0;
            local_1b8 = (undefined2 *)FUN_14018b280(0x10);
            local_1a8 = local_1b8 + 8;
            if (local_1b8 != (undefined2 *)0x0) {
              *local_1b8 = 0;
            }
            psVar12 = *(short **)(puVar30 + 0x60);
            puStack_1b0 = local_1b8;
            if (psVar12 == (short *)0x0) {
              if (local_268 != local_260) {
                *local_268 = 0;
                local_260 = local_268;
              }
            }
            else {
              sVar2 = *psVar12;
              lVar11 = 0;
              while (sVar2 != 0) {
                lVar11 = lVar11 + 1;
                sVar2 = psVar12[lVar11];
              }
              FUN_14001c480(local_270,psVar12,psVar12 + lVar11);
            }
            lVar11 = FUN_1400b7660(&local_278);
            uVar17 = *(undefined8 *)(lVar11 + 8);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f0870(lVar16,puVar15,L"strTitle",uVar17);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            FUN_1404dde90(local_198);
            psVar12 = *(short **)(puVar30 + 0x68);
            if (psVar12 == (short *)0x0) {
              if (local_188 != local_180) {
                *local_188 = 0;
                local_180 = local_188;
              }
            }
            else {
              sVar2 = *psVar12;
              lVar11 = 0;
              while (sVar2 != 0) {
                lVar11 = lVar11 + 1;
                sVar2 = psVar12[lVar11];
              }
              FUN_14001c480(local_190,psVar12,psVar12 + lVar11);
            }
            lVar11 = FUN_1400b7660(local_198);
            uVar17 = *(undefined8 *)(lVar11 + 8);
            puVar22 = (undefined8 *)
                      FUN_14005c3c0(*(undefined8 *)(*(longlong *)(lVar16 + 0x20) + 0xa0),uVar9);
            puVar15 = *(undefined8 **)(lVar16 + 0x10);
            *puVar15 = *puVar22;
            *(undefined4 *)(puVar15 + 1) = *(undefined4 *)(puVar22 + 1);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + 0x10;
            FUN_1400f0870(lVar16,puVar15,L"strDescription",uVar17);
            *(longlong *)(lVar16 + 0x10) = *(longlong *)(lVar16 + 0x10) + -0x10;
            FUN_1400fb1d0(&local_318);
            if (local_d8 != 0) {
              FUN_14018b900();
            }
            FUN_1400b7390(local_198);
            if (local_1b8 != (undefined2 *)0x0) {
              FUN_14018b900();
            }
            FUN_1400b7390(&local_278);
            FUN_1400579e0(lVar16);
            puVar32 = *(undefined1 **)(puVar30 + 0x18);
            if (puVar32 == (undefined1 *)0x0) {
              puVar32 = *(undefined1 **)(puVar30 + 8);
              if (puVar30 == *(undefined1 **)(puVar32 + 0x18)) {
                do {
                  puVar30 = puVar32;
                  puVar32 = *(undefined1 **)(puVar30 + 8);
                } while (puVar30 == *(undefined1 **)(puVar32 + 0x18));
              }
              if (*(undefined1 **)(puVar30 + 0x18) != puVar32) {
                puVar30 = puVar32;
              }
            }
            else {
              for (puVar13 = *(undefined1 **)(puVar32 + 0x10); puVar30 = puVar32,
                  puVar13 != (undefined1 *)0x0; puVar13 = *(undefined1 **)(puVar13 + 0x10)) {
                puVar32 = puVar13;
              }
            }
            lVar16 = local_308;
          } while (puVar30 != local_2f0);
        }
        FUN_1400fb2a0(lVar23,L"tAugments",local_310);
        if (lVar16 != 0) {
          FUN_1400579e0(lVar16);
        }
        if (local_2a8 != 0) {
          FUN_1400579e0();
        }
        FUN_140008410(local_2d8);
        FUN_14018b900(local_2d0,0);
        FUN_140008410(local_350);
        FUN_14018b900(local_348,0);
        FUN_140008410(local_2f8);
        FUN_14018b900(local_2f0,0);
        return 1;
      }
    } while( true );
  }
  if (DAT_140c63848 != (code *)0x0) {
    puVar10 = (uint *)(*DAT_140c63848)(&PTR_u_EldanAugmentation_140a6a1d8);
    uVar17 = extraout_XMM0_Qa;
LAB_1403ce906:
    if ((puVar10 == (uint *)0x0) || (puVar10[3] != uVar28)) goto LAB_1403cee83;
    uVar27 = *puVar10;
    if ((param_1 < 4) && (*(ulonglong *)(lVar16 + 0x6eb8) != 0)) {
      uVar19 = uVar25;
      do {
        if (*(ushort *)(*(longlong *)(lVar16 + 0x6eb0) + uVar19 * 2) == uVar27) {
          uVar19 = *(ulonglong *)(lVar16 + 0x6e78 + (ulonglong)param_1 * 0x10);
          if (uVar19 == 0) goto LAB_1403cea60;
          puVar20 = *(ushort **)(lVar16 + ((ulonglong)param_1 + 0x6e7) * 0x10);
          uVar26 = uVar25;
          goto LAB_1403cea41;
        }
        uVar19 = (ulonglong)((int)uVar19 + 1);
      } while (uVar19 < *(ulonglong *)(lVar16 + 0x6eb8));
    }
LAB_1403ce958:
    uStack_b0._0_4_ = 0;
    goto LAB_1403ce95f;
  }
  if ((DAT_140c65444 == 0) && (iVar6 = FUN_1401fd540(), -1 < iVar6)) {
    puVar10 = (uint *)(**(code **)(*DAT_140c653a0 + 0x20))();
    uVar17 = extraout_XMM0_Qa_00;
    goto LAB_1403ce906;
  }
  goto LAB_1403cee83;
  while( true ) {
    uVar26 = uVar26 + 1;
    puVar20 = puVar20 + 1;
    if (uVar19 <= uVar26) break;
LAB_1403cea41:
    if (*puVar20 == uVar27) goto LAB_1403ce958;
  }
LAB_1403cea60:
  uStack_b0._0_4_ = 1;
LAB_1403ce95f:
  uStack_b0 = CONCAT44(puVar10[4],(uint)uStack_b0);
  local_a8[0] = puVar10[7];
  uVar28 = 1;
  if ((local_a8[0] != 0) && (uVar28 = uVar5, *(uint *)(lVar16 + 0x6df0) != 0)) {
    puVar20 = (ushort *)(lVar16 + 0x6df4);
    uVar19 = uVar25;
    do {
      uVar28 = 1;
      if (*puVar20 == uVar27) break;
      uVar7 = (int)uVar19 + 1;
      uVar19 = (ulonglong)uVar7;
      puVar20 = puVar20 + 1;
      uVar28 = uVar5;
    } while (uVar7 < *(uint *)(lVar16 + 0x6df0));
  }
  local_a8[4] = puVar10[1];
  local_a8[2] = puVar10[5];
  local_a8[5] = puVar10[2];
  uStack_90 = *(undefined8 *)(puVar10 + 8);
  local_88 = puVar10[6];
  if (local_a8[2] == 0) {
    local_a8[3] = 1;
  }
  else {
    if (param_1 < 4) {
      uVar19 = *(ulonglong *)(lVar16 + 0x6eb8);
      if (((uint)param_1 == *(uint *)(lVar16 + 0x6dec)) && (uVar19 != 0)) {
        uVar5 = 1;
      }
      uVar26 = *(ulonglong *)(lVar16 + 0x6e78 + (ulonglong)param_1 * 0x10);
      if (uVar26 != 0) {
        puVar20 = *(ushort **)(lVar16 + ((ulonglong)param_1 + 0x6e7) * 0x10);
        uVar24 = uVar25;
        do {
          if (*puVar20 == local_a8[2]) goto LAB_1403ceaec;
          uVar24 = uVar24 + 1;
          puVar20 = puVar20 + 1;
        } while (uVar24 < uVar26);
      }
      if ((uVar5 != 0) && (uVar19 != 0)) {
        puVar20 = *(ushort **)(lVar16 + 0x6eb0);
        do {
          if (*puVar20 == local_a8[2]) goto LAB_1403ceaec;
          uVar25 = uVar25 + 1;
          puVar20 = puVar20 + 1;
        } while (uVar25 < uVar19);
      }
    }
    local_a8[3] = 0;
  }
LAB_1403ceb06:
  local_b8 = uVar27;
  local_a8[1] = uVar28;
  psVar12 = (short *)FUN_14034bdd0(uVar17,puVar10[10]);
  psStack_80 = psVar12;
  local_78 = (short *)FUN_14034bdd0(extraout_XMM0_Qa_01,puVar10[0xb]);
  uVar5 = puVar10[6];
  lVar23 = *(longlong *)(lVar16 + 0x78);
  if (uVar5 != 0) {
    if (lVar23 == 0) {
LAB_1403cebc8:
      lVar23 = FUN_1407a0fd0(DAT_140c65b70);
      uVar17 = extraout_XMM0_Qa_03;
      if (lVar23 == 0) goto LAB_1403cec26;
    }
    else {
      if (*(longlong *)(DAT_140c65898 + 0x78) == lVar23) {
        bVar31 = true;
      }
      else {
        bVar31 = *(longlong *)(DAT_140c65898 + 0x6490) == lVar23;
      }
      lVar23 = 0;
      if (bVar31) {
        lVar23 = DAT_140c65898;
      }
      if (lVar23 == 0) goto LAB_1403cebc8;
      puVar30 = *(undefined1 **)(lVar23 + 0x7d18);
      puVar13 = puVar30;
      puVar32 = *(undefined1 **)(puVar30 + 8);
      while (puVar32 != (undefined1 *)0x0) {
        if (*(uint *)(puVar32 + 0x20) < uVar5) {
          puVar32 = *(undefined1 **)(puVar32 + 0x18);
        }
        else {
          puVar13 = puVar32;
          puVar32 = *(undefined1 **)(puVar32 + 0x10);
        }
      }
      if ((puVar13 == puVar30) || (uVar5 < *(uint *)(puVar13 + 0x20))) {
        local_378 = puVar30;
        ppuVar14 = (undefined1 **)&local_378;
      }
      else {
        local_360 = puVar13;
        ppuVar14 = &local_360;
      }
      if ((*ppuVar14 == puVar30) ||
         (lVar23 = *(longlong *)(*ppuVar14 + 0x28), uVar17 = extraout_XMM0_Qa_02, lVar23 == 0))
      goto LAB_1403cebc8;
    }
    if (*(longlong *)(lVar23 + 8) != 0) {
      if ((psVar12 == (short *)0x0) || (*psVar12 == 0)) {
        psStack_80 = (short *)FUN_14034bdd0(uVar17,*(undefined4 *)(*(longlong *)(lVar23 + 8) + 0x10)
                                           );
        uVar17 = extraout_XMM0_Qa_04;
      }
      if ((local_78 == (short *)0x0) || (*local_78 == 0)) {
        local_78 = (short *)FUN_14034bdd0(uVar17,*(undefined4 *)(*(longlong *)(lVar23 + 8) + 0x20));
      }
    }
  }
LAB_1403cec26:
  if (param_1 < 4) {
    uVar25 = *(ulonglong *)(lVar16 + 0x6eb8);
    if (((uint)param_1 == *(uint *)(lVar16 + 0x6dec)) && (uVar25 != 0)) {
      bVar31 = true;
    }
    else {
      bVar31 = false;
    }
    uVar26 = 0;
    uVar19 = *(ulonglong *)(lVar16 + 0x6e78 + (ulonglong)param_1 * 0x10);
    if (uVar19 != 0) {
      puVar20 = *(ushort **)(lVar16 + ((ulonglong)param_1 + 0x6e7) * 0x10);
      uVar24 = uVar26;
      do {
        if (*puVar20 == uVar27) goto LAB_1403cecde;
        uVar24 = uVar24 + 1;
        puVar20 = puVar20 + 1;
      } while (uVar24 < uVar19);
    }
    if ((bVar31) && (uVar25 != 0)) {
      puVar20 = *(ushort **)(lVar16 + 0x6eb0);
      do {
        if (*puVar20 == uVar27) goto LAB_1403cecde;
        uVar26 = uVar26 + 1;
        puVar20 = puVar20 + 1;
      } while (uVar26 < uVar25);
      uStack_b4 = (uint)(uVar28 != 0);
      goto LAB_1403cee35;
    }
  }
  uStack_b4 = (uint)(uVar28 != 0);
LAB_1403cee35:
  puVar15 = (undefined8 *)FUN_1403d2790(local_2f8);
  *puVar15 = CONCAT44(uStack_b4,local_b8);
  puVar15[1] = uStack_b0;
  puVar15[2] = CONCAT44(local_a8[1],local_a8[0]);
  puVar15[3] = CONCAT44(local_a8[3],local_a8[2]);
  puVar15[4] = CONCAT44(local_a8[5],local_a8[4]);
  puVar15[5] = uStack_90;
  puVar15[6] = CONCAT44(uStack_84,local_88);
  puVar15[7] = psStack_80;
  puVar15[8] = local_78;
  uVar27 = (uint)local_368;
LAB_1403cee83:
  uVar27 = uVar27 + 1;
  uVar28 = local_370;
  goto LAB_1403ce86a;
LAB_1403ceaec:
  local_a8[3] = 1;
  goto LAB_1403ceb06;
LAB_1403cecde:
  uStack_b4 = 3;
  puVar30 = *(undefined1 **)(local_2d0 + 8);
  puVar32 = local_2d0;
  if (puVar30 == (undefined1 *)0x0) {
LAB_1403ced2d:
    local_330 = local_2d0;
    ppuVar14 = &local_330;
  }
  else {
    do {
      if (*(uint *)(puVar30 + 0x20) < puVar10[8]) {
        puVar13 = *(undefined1 **)(puVar30 + 0x18);
      }
      else {
        puVar13 = *(undefined1 **)(puVar30 + 0x10);
        puVar32 = puVar30;
      }
      puVar30 = puVar13;
    } while (puVar13 != (undefined1 *)0x0);
    if ((puVar32 == local_2d0) || (puVar10[8] < *(uint *)(puVar32 + 0x20))) goto LAB_1403ced2d;
    local_320 = puVar32;
    ppuVar14 = &local_320;
  }
  if (*ppuVar14 != local_2d0) {
    lVar23 = *(longlong *)(*ppuVar14 + 0x28);
    uVar27 = puVar10[9];
    fVar33 = (float)puVar10[4];
    piVar18 = (int *)(lVar23 + 8);
    lVar23 = lVar23 + 4;
    if (*piVar18 == 0) {
      lVar11 = FUN_1403d2880(local_350,lVar23);
      uVar27 = 0;
      fVar4 = fVar33;
    }
    else {
      lVar11 = FUN_1403d2880(local_350,lVar23);
      *(float *)(lVar11 + 0x10) = fVar33 * _DAT_140dc233c + *(float *)(lVar11 + 0x10);
      lVar11 = FUN_1403d2880(local_350,piVar18);
      fVar4 = fVar33 * _DAT_140dc233c;
    }
    uVar28 = 1;
    if (1 < (int)uVar27) {
      uVar28 = uVar27;
    }
    *(float *)(lVar11 + 0x10) = fVar4 + *(float *)(lVar11 + 0x10);
    for (; uVar28 < 3; uVar28 = uVar28 + 1) {
      if (*piVar18 == 0) {
        lVar11 = FUN_1403d2880(local_350,lVar23);
        *(float *)(lVar11 + 8 + (ulonglong)(uVar28 - 1) * 4) =
             fVar33 + *(float *)(lVar11 + 8 + (ulonglong)(uVar28 - 1) * 4);
      }
      else {
        uVar25 = (ulonglong)(uVar28 - 1);
        lVar11 = FUN_1403d2880(local_350,lVar23);
        *(float *)(lVar11 + 8 + uVar25 * 4) =
             fVar33 * _DAT_140dc233c + *(float *)(lVar11 + 8 + uVar25 * 4);
        lVar11 = FUN_1403d2880(local_350,piVar18);
        *(float *)(lVar11 + 8 + uVar25 * 4) =
             fVar33 * _DAT_140dc233c + *(float *)(lVar11 + 8 + uVar25 * 4);
      }
    }
  }
  goto LAB_1403cee35;
}

