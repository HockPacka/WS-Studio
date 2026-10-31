
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1403c7ac0(longlong param_1,int *param_2)

{
  longlong lVar1;
  undefined2 *puVar2;
  short sVar3;
  size_t sVar4;
  undefined1 *puVar5;
  void *pvVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined1 *puVar11;
  int *piVar12;
  short *psVar13;
  undefined8 *puVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  int iVar18;
  uint uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 extraout_XMM0_Da_01;
  undefined4 uVar22;
  undefined8 local_res10;
  undefined1 *local_res18;
  undefined1 *local_res20;
  ulonglong in_stack_fffffffffffffd98;
  ulonglong in_stack_fffffffffffffda0;
  undefined **local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  void *local_210;
  undefined **local_208;
  undefined1 local_200 [8];
  undefined2 *local_1f8;
  undefined2 *local_1f0;
  undefined2 *local_148;
  undefined2 *puStack_140;
  undefined2 *local_138;
  undefined **local_128;
  undefined1 local_120 [8];
  undefined2 *local_118;
  undefined2 *local_110;
  undefined2 *local_68;
  undefined2 *puStack_60;
  undefined2 *local_58;
  
  if (5 < *param_2 - 0x17U) {
    return;
  }
  puVar14 = (undefined8 *)0x0;
  uVar21 = in_stack_fffffffffffffd98 & 0xffffffff00000000;
  FUN_140437a10(DAT_140c658d8,0x84,0,0,uVar21,in_stack_fffffffffffffda0 & 0xffffffff00000000,1);
  uVar19 = DAT_140dc2290;
  if ((DAT_140dc2290 & 1) == 0) {
    uVar19 = DAT_140dc2290 | 1;
    iVar18 = 3;
    puVar9 = &DAT_140dc22a8;
    DAT_140dc2290 = uVar19;
    do {
      iVar18 = iVar18 + -1;
      puVar9[-1] = 0;
      *puVar9 = 0;
      puVar9 = puVar9 + 2;
    } while (-1 < iVar18);
  }
  if ((uVar19 & 2) == 0) {
    DAT_140dc2290 = uVar19 | 2;
    DAT_140dc22e8 = (undefined1 *)FUN_14018b280(0x28);
    _DAT_140dc22f0 = 0;
    *DAT_140dc22e8 = 0;
    *(undefined8 *)(DAT_140dc22e8 + 8) = 0;
    *(undefined1 **)(DAT_140dc22e8 + 0x10) = DAT_140dc22e8;
    *(undefined1 **)(DAT_140dc22e8 + 0x18) = DAT_140dc22e8;
    atexit(FUN_14094fcd0);
  }
  puVar9 = puVar14;
  if (DAT_140c8a6a0 == 0) {
    do {
      if (DAT_140c63838 == (code *)0x0) {
        if ((DAT_140c64b6c != 0) || (iVar18 = FUN_1401f4900(), iVar18 < 0)) goto LAB_1403c7c8b;
        uVar19 = (**(code **)(*DAT_140c64a90 + 0x28))();
      }
      else {
        uVar19 = (*DAT_140c63838)(&PTR_u_CombatReward_140a69aa0,DAT_140c63858);
      }
      if (uVar19 <= (uint)puVar9) goto LAB_1403c7c8b;
      lVar10 = FUN_1401f4bc0(puVar9);
      if ((lVar10 != 0) && (*(int *)(lVar10 + 4) - 4U < 4)) {
        DAT_140c8a6a0 = 1;
        *(undefined4 *)(&DAT_140dc22a0 + (ulonglong)(*(int *)(lVar10 + 4) - 4) * 2) =
             *(undefined4 *)(lVar10 + 8);
        *(undefined4 *)((longlong)&DAT_140dc22a0 + (ulonglong)(*(int *)(lVar10 + 4) - 4) * 0x10 + 4)
             = *(undefined4 *)(lVar10 + 0xc);
        *(undefined4 *)(&DAT_140dc22a8 + (ulonglong)(*(int *)(lVar10 + 4) - 4) * 2) =
             *(undefined4 *)(lVar10 + 0x10);
        *(undefined4 *)((longlong)&DAT_140dc22a8 + (ulonglong)(*(int *)(lVar10 + 4) - 4) * 0x10 + 4)
             = *(undefined4 *)(lVar10 + 0x14);
      }
      puVar9 = (undefined8 *)(ulonglong)((uint)puVar9 + 1);
    } while( true );
  }
LAB_1403c7df4:
  lVar10 = FUN_1401f4b60(param_2[4]);
  uVar22 = (undefined4)(uVar21 >> 0x20);
  if (lVar10 == 0) {
    return;
  }
  iVar18 = *param_2;
  local_res18 = (undefined1 *)0x0;
  if (iVar18 == 0x17) {
LAB_1403c8493:
    uStack_220 = (void *)CONCAT44(0x14,*(undefined4 *)(*(longlong *)(param_1 + 0x78) + 8));
    local_228 = &PTR_FUN_140b6f700;
    iVar8 = -1;
    if (param_2[2] != -1) {
      iVar8 = param_2[2];
    }
    local_218 = (undefined2 *)CONCAT44(iVar8,iVar18);
    iVar18 = FUN_14060af20(&local_228);
    if (((iVar18 != 0) &&
        (lVar10 = FUN_1403d90d0(DAT_140c65898,(ulonglong)uStack_220 & 0xffffffff), lVar10 != 0)) &&
       (lVar10 = FUN_14047dca0(lVar10), lVar10 != 0)) {
      FUN_14060afe0(&local_228,(ulonglong)uStack_220 & 0xffffffff);
    }
    puVar9 = (undefined8 *)FUN_14018b280(0x18);
    if (puVar9 != (undefined8 *)0x0) {
      *puVar9 = *(undefined8 *)param_2;
      puVar9[1] = *(undefined8 *)(param_2 + 2);
      puVar9[2] = *(undefined8 *)(param_2 + 4);
      puVar14 = puVar9;
    }
    puVar9 = (undefined8 *)FUN_14018b280(0x38);
    if (puVar9 == (undefined8 *)0x0) {
      puVar9 = (undefined8 *)0x0;
      uVar22 = extraout_XMM0_Da_00;
    }
    else {
      *puVar9 = 0;
      puVar9[2] = 0;
      *(undefined4 *)(puVar9 + 3) = 0;
      *(undefined4 *)(puVar9 + 5) = 0;
      puVar9[4] = FUN_1403c76d0;
      puVar9[6] = puVar14;
      lVar10 = FUN_140225140(3);
      uVar22 = extraout_XMM0_Da_01;
      if (lVar10 != 0) {
        puVar9[2] = lVar10;
      }
    }
    FUN_1404cfa80(uVar22,puVar9);
  }
  else {
    if (iVar18 == 0x18) {
      local_res10 = CONCAT44(local_res10._4_4_,0x18);
      piVar12 = (int *)FUN_1403d2710(extraout_XMM0_Da,&local_res10);
      local_res18 = *(undefined1 **)(lVar10 + 0x10);
      iVar8 = *(int *)(&DAT_140dc22a0 + ((longlong)*piVar12 + -4) * 2);
      iVar18 = DAT_140dc22d4;
LAB_1403c7ee6:
      plVar17 = (longlong *)0x0;
      if (iVar8 != 0) {
        FUN_1400b6f30(&local_208);
        local_208 = &PTR_FUN_140b69230;
        local_138 = (undefined2 *)0x0;
        local_148 = (undefined2 *)0x0;
        puStack_140 = (undefined2 *)0x0;
        local_148 = (undefined2 *)FUN_14018b280(0x10);
        local_138 = local_148 + 8;
        if (local_148 != (undefined2 *)0x0) {
          *local_148 = 0;
        }
        puStack_140 = local_148;
        psVar13 = (short *)FUN_14034bdd0(local_138,iVar8);
        if (psVar13 == (short *)0x0) {
          if (local_1f8 != local_1f0) {
            *local_1f8 = 0;
            local_1f0 = local_1f8;
          }
        }
        else {
          sVar3 = *psVar13;
          plVar15 = plVar17;
          while (sVar3 != 0) {
            plVar15 = (longlong *)((longlong)plVar15 + 1);
            sVar3 = psVar13[(longlong)plVar15];
          }
          FUN_14001c480(local_200,psVar13,psVar13 + (longlong)plVar15);
        }
        puVar14 = (undefined8 *)
                  FUN_14034c700(&local_res10,&DAT_140aeb814,*(undefined8 *)(param_2 + 2));
        psVar13 = (short *)*puVar14;
        sVar3 = *psVar13;
        plVar15 = plVar17;
        while (sVar3 != 0) {
          plVar15 = (longlong *)((longlong)plVar15 + 1);
          sVar3 = psVar13[(longlong)plVar15];
        }
        lVar10 = (longlong)plVar15 * 2 >> 1;
        uVar21 = lVar10 + 1;
        plVar15 = plVar17;
        if (uVar21 < 0x7fffffffffffffff) {
          plVar15 = (longlong *)FUN_14018b280(uVar21 * 2,0);
        }
        sVar4 = lVar10 * 2;
        memcpy(plVar15,psVar13,sVar4);
        puVar2 = (undefined2 *)((longlong)plVar15 + sVar4);
        if (puVar2 != (undefined2 *)0x0) {
          *puVar2 = 0;
        }
        if (local_res10 != 0) {
          (**(code **)(*(longlong *)(local_res10 + -0x10) + 8))(local_res10 + -0x10);
        }
        lVar10 = FUN_14018b280(0x60);
        plVar16 = plVar17;
        if (lVar10 != 0) {
          plVar16 = (longlong *)FUN_1404ddb40(lVar10,plVar15);
        }
        uStack_220 = (void *)0x0;
        local_218 = (void *)0x0;
        local_210 = (void *)0x0;
        do {
          lVar10 = (longlong)plVar17 + 1;
          plVar17 = (longlong *)((longlong)plVar17 + 1);
        } while (L"combatbuff"[lVar10] != L'\0');
        lVar10 = (longlong)plVar17 * 2 >> 1;
        uVar21 = lVar10 + 1;
        if (uVar21 < 0x7fffffffffffffff) {
          lVar1 = uVar21 * 2;
          local_218 = (undefined2 *)FUN_14018b280(lVar1,0);
          local_210 = (void *)((longlong)local_218 + lVar1);
        }
        pvVar6 = local_218;
        sVar4 = lVar10 * 2;
        uStack_220 = local_218;
        memcpy(local_218,L"combatbuff",sVar4);
        local_218 = (undefined2 *)((longlong)pvVar6 + sVar4);
        if (local_218 != (undefined2 *)0x0) {
          *local_218 = 0;
        }
        FUN_1400b7480(&local_208,plVar16);
        (**(code **)(*plVar16 + 0x48))(plVar16,&local_228);
        if (uStack_220 != (void *)0x0) {
          FUN_14018b900(uStack_220,0);
        }
        lVar10 = FUN_1400b7660(&local_208);
        FUN_1400ea3e0(*(undefined8 *)(param_1 + 0x7340),"CombatMomentum",&DAT_1409eb6ec,*param_2,
                      CONCAT44(uVar22,param_2[2]),*(undefined8 *)(lVar10 + 8));
        if (plVar15 != (longlong *)0x0) {
          FUN_14018b900(plVar15,0);
        }
        if (local_148 != (undefined2 *)0x0) {
          FUN_14018b900(local_148,0);
        }
        FUN_1400b7390(&local_208);
      }
      if (iVar18 != 0) {
        FUN_1400b6f30(&local_128);
        local_128 = &PTR_FUN_140b69230;
        local_58 = (undefined2 *)0x0;
        local_68 = (undefined2 *)0x0;
        puStack_60 = (undefined2 *)0x0;
        local_68 = (undefined2 *)FUN_14018b280(0x10);
        local_58 = local_68 + 8;
        if (local_68 != (undefined2 *)0x0) {
          *local_68 = 0;
        }
        puStack_60 = local_68;
        psVar13 = (short *)FUN_14034bdd0(local_58,iVar18);
        plVar17 = (longlong *)0x0;
        if (psVar13 == (short *)0x0) {
          if (local_118 != local_110) {
            *local_118 = 0;
            local_110 = local_118;
          }
        }
        else {
          sVar3 = *psVar13;
          plVar15 = plVar17;
          while (sVar3 != 0) {
            plVar15 = (longlong *)((longlong)plVar15 + 1);
            sVar3 = psVar13[(longlong)plVar15];
          }
          FUN_14001c480(local_120,psVar13,psVar13 + (longlong)plVar15);
        }
        puVar14 = (undefined8 *)
                  FUN_14034c700(&local_res10,&DAT_140aebef4,*(undefined8 *)(param_2 + 2));
        psVar13 = (short *)*puVar14;
        sVar3 = *psVar13;
        plVar15 = plVar17;
        while (sVar3 != 0) {
          plVar15 = (longlong *)((longlong)plVar15 + 1);
          sVar3 = psVar13[(longlong)plVar15];
        }
        lVar10 = (longlong)plVar15 * 2 >> 1;
        uVar21 = lVar10 + 1;
        plVar15 = plVar17;
        if (uVar21 < 0x7fffffffffffffff) {
          plVar15 = (longlong *)FUN_14018b280(uVar21 * 2,0);
        }
        sVar4 = lVar10 * 2;
        memcpy(plVar15,psVar13,sVar4);
        puVar2 = (undefined2 *)((longlong)plVar15 + sVar4);
        if (puVar2 != (undefined2 *)0x0) {
          *puVar2 = 0;
        }
        if (local_res10 != 0) {
          (**(code **)(*(longlong *)(local_res10 + -0x10) + 8))(local_res10 + -0x10);
        }
        lVar10 = FUN_14018b280(0x60);
        plVar16 = plVar17;
        if (lVar10 != 0) {
          plVar16 = (longlong *)FUN_1404ddb40(lVar10,plVar15);
        }
        uStack_220 = (void *)0x0;
        local_218 = (void *)0x0;
        local_210 = (void *)0x0;
        do {
          lVar10 = (longlong)plVar17 + 1;
          plVar17 = (longlong *)((longlong)plVar17 + 1);
        } while (L"combatbuff"[lVar10] != L'\0');
        lVar10 = (longlong)plVar17 * 2 >> 1;
        uVar21 = lVar10 + 1;
        if (uVar21 < 0x7fffffffffffffff) {
          lVar1 = uVar21 * 2;
          local_218 = (undefined2 *)FUN_14018b280(lVar1,0);
          local_210 = (void *)((longlong)local_218 + lVar1);
        }
        pvVar6 = local_218;
        sVar4 = lVar10 * 2;
        uStack_220 = local_218;
        memcpy(local_218,L"combatbuff",sVar4);
        local_218 = (undefined2 *)((longlong)pvVar6 + sVar4);
        if (local_218 != (undefined2 *)0x0) {
          *local_218 = 0;
        }
        FUN_1400b7480(&local_128,plVar16);
        (**(code **)(*plVar16 + 0x48))(plVar16,&local_228);
        if (uStack_220 != (void *)0x0) {
          FUN_14018b900(uStack_220,0);
        }
        lVar10 = FUN_1400b7660(&local_128);
        FUN_1400ea3e0(*(undefined8 *)(param_1 + 0x7340),"CombatLogString",&DAT_1409eb6d4,
                      *(undefined8 *)(lVar10 + 8));
        if (plVar15 != (longlong *)0x0) {
          FUN_14018b900(plVar15,0);
        }
        if (local_68 != (undefined2 *)0x0) {
          FUN_14018b900(local_68,0);
        }
        FUN_1400b7390(&local_128);
      }
    }
    else {
      if (iVar18 == 0x19) goto LAB_1403c8493;
      if (iVar18 - 0x1aU < 3) {
        piVar12 = (int *)FUN_1403d2710(extraout_XMM0_Da,param_2);
        iVar8 = *(int *)(&DAT_140dc22a0 + ((longlong)*piVar12 + -4) * 2);
        piVar12 = (int *)FUN_1403d2710(((longlong)*piVar12 + -4) * 2,param_2);
        lVar10 = ((longlong)*piVar12 + -4) * 2;
        uVar20 = 0;
        iVar18 = *(int *)((longlong)&DAT_140dc22a0 + ((longlong)*piVar12 + -4) * 0x10 + 4);
        do {
          piVar12 = (int *)FUN_1403d2710(lVar10,param_2);
          uVar22 = (undefined4)(uVar21 >> 0x20);
          lVar10 = (longlong)*piVar12;
          lVar1 = uVar20 + lVar10 * 4;
          uVar20 = uVar20 + 1;
          *(undefined4 *)((longlong)&local_res10 + uVar20 * 4 + 4) = (&DAT_140dc2268)[lVar1];
        } while (uVar20 < 2);
        goto LAB_1403c7ee6;
      }
    }
    uVar21 = 0;
    do {
      iVar18 = *(int *)((longlong)&local_res18 + uVar21 * 4);
      if (iVar18 != 0) {
        if (DAT_140c63840 == (code *)0x0) {
          if ((DAT_140c64c04 != 0) || (iVar8 = FUN_140248ca0(), iVar8 < 0)) goto LAB_1403c8481;
          lVar10 = (**(code **)(*DAT_140c63b40 + 0x18))(DAT_140c63b40,iVar18);
        }
        else {
          lVar10 = (*DAT_140c63840)(&PTR_u_VisualEffect_140a6dff8,iVar18,DAT_140c63858);
        }
        if (lVar10 != 0) {
          local_228 = (undefined **)0x0;
          uStack_220 = (void *)0x0;
          FUN_1405787d0(*(longlong *)(DAT_140c65898 + 0x6490),0,
                        *(undefined4 *)(*(longlong *)(DAT_140c65898 + 0x6490) + 8));
        }
      }
LAB_1403c8481:
      uVar21 = uVar21 + 1;
    } while (uVar21 < 2);
  }
  return;
LAB_1403c7c8b:
  puVar7 = *(undefined1 **)(DAT_140dc22e8 + 8);
  puVar11 = DAT_140dc22e8;
  while (puVar5 = puVar7, puVar5 != (undefined1 *)0x0) {
    if (*(int *)(puVar5 + 0x20) < 0x1a) {
      puVar7 = *(undefined1 **)(puVar5 + 0x18);
    }
    else {
      puVar7 = *(undefined1 **)(puVar5 + 0x10);
      puVar11 = puVar5;
    }
  }
  if ((puVar11 == DAT_140dc22e8) || (0x1a < *(int *)(puVar11 + 0x20))) {
    local_res10 = 0x1a;
    local_res18 = puVar11;
    FUN_1403d3e70(&DAT_140dc22e0,&local_res20,&local_res18,&local_res10);
    puVar11 = local_res20;
  }
  *(undefined4 *)(puVar11 + 0x24) = 4;
  puVar7 = *(undefined1 **)(DAT_140dc22e8 + 8);
  puVar11 = DAT_140dc22e8;
  while (puVar5 = puVar7, puVar5 != (undefined1 *)0x0) {
    if (*(int *)(puVar5 + 0x20) < 0x1b) {
      puVar7 = *(undefined1 **)(puVar5 + 0x18);
    }
    else {
      puVar7 = *(undefined1 **)(puVar5 + 0x10);
      puVar11 = puVar5;
    }
  }
  if ((puVar11 == DAT_140dc22e8) || (0x1b < *(int *)(puVar11 + 0x20))) {
    local_res10 = 0x1b;
    local_res18 = puVar11;
    FUN_1403d3e70(&DAT_140dc22e0,&local_res20,&local_res18,&local_res10);
    puVar11 = local_res20;
  }
  *(undefined4 *)(puVar11 + 0x24) = 5;
  puVar7 = *(undefined1 **)(DAT_140dc22e8 + 8);
  puVar11 = DAT_140dc22e8;
  while (puVar5 = puVar7, puVar5 != (undefined1 *)0x0) {
    if (*(int *)(puVar5 + 0x20) < 0x1c) {
      puVar7 = *(undefined1 **)(puVar5 + 0x18);
    }
    else {
      puVar7 = *(undefined1 **)(puVar5 + 0x10);
      puVar11 = puVar5;
    }
  }
  if ((puVar11 == DAT_140dc22e8) || (0x1c < *(int *)(puVar11 + 0x20))) {
    local_res10 = 0x1c;
    local_res18 = puVar11;
    FUN_1403d3e70(&DAT_140dc22e0,&local_res20,&local_res18,&local_res10);
    puVar11 = local_res20;
  }
  *(undefined4 *)(puVar11 + 0x24) = 6;
  goto LAB_1403c7df4;
}

