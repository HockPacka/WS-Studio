
void FUN_1402e4ec0(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  int *piVar13;
  undefined8 local_res8;
  longlong *local_res10;
  ulonglong local_res18;
  longlong *local_res20;
  undefined **local_2e8;
  wchar_t *local_2e0;
  LPVOID local_2d8;
  ulonglong local_2d0;
  undefined **local_2c8;
  wchar_t *local_2c0;
  LPVOID local_2b8;
  longlong local_2b0;
  undefined **local_2a8;
  undefined8 local_2a0;
  LPVOID local_298;
  undefined **local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  int iStack_278;
  undefined4 uStack_274;
  undefined8 local_270;
  ulonglong local_268;
  undefined8 local_260;
  longlong local_258;
  ulonglong local_250 [3];
  undefined **local_238;
  undefined8 local_230;
  LPVOID local_228;
  undefined **local_218;
  wchar_t *local_210;
  LPVOID local_208;
  longlong local_200;
  undefined **local_1f8;
  wchar_t *local_1f0;
  LPVOID local_1e8;
  ulonglong local_1e0;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 local_1c8;
  undefined4 uStack_1c4;
  int iStack_1c0;
  undefined4 uStack_1bc;
  longlong local_1b8 [38];
  longlong *local_88;
  ulonglong local_80;
  longlong local_78;
  ulonglong local_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 local_58;
  
  plVar5 = local_1b8;
  lVar10 = 0x26;
  do {
    puVar1 = *(undefined8 **)((param_1 - (longlong)local_1b8) + 0x98 + (longlong)plVar5);
    *plVar5 = (longlong)puVar1;
    if (puVar1 != (undefined8 *)0x0) {
      (**(code **)*puVar1)();
    }
    plVar5 = plVar5 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  local_res20 = *(longlong **)(param_1 + 0x1c8);
  uVar9 = 0;
  local_88 = local_res20;
  local_268 = *(ulonglong *)(param_1 + 0x1d0);
  local_80 = local_268;
  local_250[1] = *(longlong *)(param_1 + 0x1d8);
  local_78 = *(longlong *)(param_1 + 0x1d8);
  local_250[0] = *(ulonglong *)(param_1 + 0x1f0);
  local_70 = *(ulonglong *)(param_1 + 0x1f0);
  local_258 = *(longlong *)(param_1 + 0x1f8);
  local_68 = local_258;
  local_270 = *(undefined8 *)(param_1 + 0x1e0);
  local_60 = local_270;
  local_260 = *(undefined8 *)(param_1 + 0x1e8);
  local_58 = local_260;
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1d8) = 0;
  *(undefined8 *)(param_1 + 0x1f0) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0;
  plVar5 = *(longlong **)
            (*(longlong *)(param_1 + 0x10) + 0xcb8 + (ulonglong)*(uint *)(param_1 + 0x30) * 8);
  if (plVar5 != (longlong *)0x0) {
    local_res10 = (longlong *)0x0;
    if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) + 0x628) == 0) {
      (**(code **)*plVar5)(plVar5);
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 8))();
      }
    }
    else {
      iVar2 = (*(code *)((undefined8 *)*plVar5)[6])(plVar5,&local_res10);
      plVar5 = local_res10;
      if (iVar2 < 0) {
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 8))();
        }
        goto LAB_1402e5368;
      }
    }
    local_res10 = plVar5;
    puVar4 = (uint *)(**(code **)(*local_res10 + 0x18))(local_res10);
    uVar8 = (**(code **)(*local_res10 + 0x10))();
    if (uVar8 < 4) {
LAB_1402e5344:
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 8))();
      }
      iVar2 = -0x7fffbffb;
      goto LAB_1402e5368;
    }
    uVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    uVar8 = uVar8 - 4;
    plVar5 = (longlong *)(param_1 + 0x98);
    piVar13 = &DAT_140c4135c;
    local_res8 = CONCAT44(local_res8._4_4_,uVar3);
    do {
      if ((uVar3 >> ((uint)uVar9 & 0x1f) & 1) != 0) {
        local_res18 = (ulonglong)((piVar13[2] - *piVar13) * piVar13[4]);
        if (uVar8 < local_res18) goto LAB_1402e5344;
        if (piVar13[-4] != 0) {
          if ((longlong *)*plVar5 != (longlong *)0x0) {
            (**(code **)(*(longlong *)*plVar5 + 8))();
            *plVar5 = 0;
          }
          iVar2 = FUN_1402ddc50(uVar9,puVar4,local_res10,param_1 + (uVar9 + 0x13) * 8);
          if (iVar2 < 0) goto LAB_1402e51b4;
        }
        puVar4 = (uint *)((longlong)puVar4 + local_res18);
        uVar8 = uVar8 - local_res18;
        uVar3 = (uint)local_res8;
      }
      uVar11 = (uint)uVar9 + 1;
      uVar9 = (ulonglong)uVar11;
      plVar5 = plVar5 + 1;
      piVar13 = piVar13 + 0xe;
    } while (uVar11 < 0x20);
    for (; uVar8 != 0; uVar8 = (uVar8 - 8) - uVar9) {
      if (uVar8 < 8) goto LAB_1402e5344;
      uVar9 = (ulonglong)puVar4[1];
      uVar3 = *puVar4;
      puVar4 = puVar4 + 2;
      if (uVar8 - 8 < uVar9) goto LAB_1402e5344;
      if (uVar3 == 0x50524f50) {
        if (*(longlong *)(param_1 + 0x1c8) == 0) {
          iVar2 = FUN_1402e3010(puVar4,uVar9,local_res10,(longlong *)(param_1 + 0x1c8));
          if (-1 < iVar2) goto LAB_1402e523a;
        }
        else {
          iVar2 = -0x7fffbffb;
        }
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 8))();
        }
        goto LAB_1402e5368;
      }
      if (uVar3 == 0x57417447) {
        iVar2 = FUN_1402e5720(param_1,uVar9,puVar4,local_res10);
      }
      else if (uVar3 == 0x63757244) {
        iVar2 = FUN_1402e59b0(param_1,uVar9,puVar4,local_res10);
      }
      else {
        if (uVar3 != 0x77627350) goto LAB_1402e523a;
        iVar2 = FUN_1402e5860(param_1,uVar9,puVar4,local_res10);
      }
      if (iVar2 < 0) goto LAB_1402e51b4;
LAB_1402e523a:
      puVar4 = (uint *)((longlong)puVar4 + uVar9);
    }
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 8))();
    }
  }
  lVar10 = 0x26;
  uVar9 = 0;
  plVar5 = local_1b8;
  do {
    if ((longlong *)*plVar5 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar5 + 8))();
      *plVar5 = 0;
    }
    plVar5 = plVar5 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  if (local_88 != (longlong *)0x0) {
    (**(code **)(*local_88 + 8))();
  }
  lVar10 = local_78;
  uVar8 = local_80;
  uVar6 = uVar9;
  if (local_80 != 0) {
    do {
      plVar5 = *(longlong **)(lVar10 + uVar6 * 8);
      if (plVar5 != (longlong *)0x0) {
        (**(code **)(*plVar5 + 8))();
        *(undefined8 *)(lVar10 + uVar6 * 8) = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar8);
  }
  FUN_14018b900(lVar10,0);
  lVar10 = local_68;
  uVar8 = local_70;
  if (local_70 != 0) {
    do {
      plVar5 = *(longlong **)(lVar10 + uVar9 * 8);
      if (plVar5 != (longlong *)0x0) {
        (**(code **)(*plVar5 + 8))();
        *(undefined8 *)(lVar10 + uVar9 * 8) = 0;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar8);
  }
  FUN_14018b900(lVar10,0);
  return;
LAB_1402e51b4:
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 8))();
  }
LAB_1402e5368:
  plVar5 = (longlong *)(param_1 + 0x1c8);
  lVar12 = 0x26;
  uVar9 = 0;
  local_2a8 = &PTR_LAB_140b5e648;
  local_2a0 = 0;
  local_298 = TlsGetValue(DAT_140c63720);
  TlsSetValue(DAT_140c63720,&local_2a8);
  local_238 = local_2a8;
  local_230 = local_2a0;
  local_290 = &PTR_LAB_140b5e648;
  uStack_288 = L"Result";
  local_228 = local_298;
  local_280 = TlsGetValue(DAT_140c63720);
  TlsSetValue(DAT_140c63720,&local_290);
  uVar3 = *(uint *)(param_1 + 0x30);
  local_2e8 = &PTR_LAB_140b5e648;
  local_290 = &PTR_FUN_140b5e640;
  local_1c8 = (undefined4)local_280;
  uStack_1c4 = local_280._4_4_;
  uStack_1bc = uStack_274;
  local_2e0 = L"RecordId";
  local_1d8 = 0x40b5e640;
  uStack_1d4 = 1;
  uStack_1d0 = (undefined4)uStack_288;
  uStack_1cc = uStack_288._4_4_;
  iStack_278 = iVar2;
  iStack_1c0 = iVar2;
  local_2d8 = TlsGetValue(DAT_140c63720);
  TlsSetValue(DAT_140c63720,&local_2e8);
  local_1f0 = local_2e0;
  local_2e8 = &PTR_LAB_140b5e630;
  local_1f8 = &PTR_LAB_140b5e630;
  local_1e8 = local_2d8;
  local_2d0 = (ulonglong)uVar3;
  local_1e0 = (ulonglong)uVar3;
  lVar10 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x18))();
  local_2c8 = &PTR_LAB_140b5e648;
  local_2c0 = L"FileName";
  local_2b8 = TlsGetValue(DAT_140c63720);
  TlsSetValue(DAT_140c63720,&local_2c8);
  local_210 = local_2c0;
  local_2c8 = &PTR_LAB_140b5e638;
  local_res8 = 0x141deb590;
  local_218 = &PTR_LAB_140b5e638;
  local_208 = local_2b8;
  local_2b0 = lVar10 + 0x248;
  local_200 = lVar10 + 0x248;
  iVar2 = FUN_1401971e0(&DAT_140c8a580,0x24,&local_res8,&local_218,&local_1f8,&local_1d8,
                        local_250 + 3);
  local_2c8 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_2b8);
  local_2e8 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_2d8);
  local_290 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_280);
  local_2a8 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_298);
  if (iVar2 != 0) {
    DebugBreak();
  }
  plVar7 = (longlong *)(param_1 + 0x98);
  do {
    if ((longlong *)*plVar7 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar7 + 8))();
      *plVar7 = 0;
    }
    *plVar7 = *(longlong *)(((longlong)local_250 - param_1) + (longlong)plVar7);
    lVar12 = lVar12 + -1;
    plVar7 = plVar7 + 1;
  } while (lVar12 != 0);
  if ((longlong *)*plVar5 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*plVar5 + 8))();
    *plVar5 = 0;
  }
  *plVar5 = (longlong)local_res20;
  uVar8 = uVar9;
  if (*(longlong *)(param_1 + 0x1d0) != 0) {
    do {
      lVar10 = *(longlong *)(param_1 + 0x1d8);
      plVar5 = *(longlong **)(lVar10 + uVar8 * 8);
      if (plVar5 != (longlong *)0x0) {
        (**(code **)(*plVar5 + 8))();
        *(undefined8 *)(lVar10 + uVar8 * 8) = 0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(ulonglong *)(param_1 + 0x1d0));
  }
  FUN_14018b900(*(undefined8 *)(param_1 + 0x1d8),0);
  *(ulonglong *)(param_1 + 0x1d0) = local_268;
  *(ulonglong *)(param_1 + 0x1d8) = local_250[1];
  uVar8 = uVar9;
  if (*(longlong *)(param_1 + 0x1f0) != 0) {
    do {
      lVar10 = *(longlong *)(param_1 + 0x1f8);
      plVar5 = *(longlong **)(lVar10 + uVar8 * 8);
      if (plVar5 != (longlong *)0x0) {
        (**(code **)(*plVar5 + 8))();
        *(undefined8 *)(lVar10 + uVar8 * 8) = 0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(ulonglong *)(param_1 + 0x1f0));
  }
  FUN_14018b900(*(undefined8 *)(param_1 + 0x1f8),0);
  *(ulonglong *)(param_1 + 0x1f0) = local_250[0];
  *(longlong *)(param_1 + 0x1f8) = local_258;
  if (*(longlong *)(param_1 + 0x1e0) != 0) {
    do {
      lVar10 = *(longlong *)(param_1 + 0x1e8);
      plVar5 = *(longlong **)(lVar10 + uVar9 * 8);
      if (plVar5 != (longlong *)0x0) {
        (**(code **)(*plVar5 + 8))();
        *(undefined8 *)(lVar10 + uVar9 * 8) = 0;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(ulonglong *)(param_1 + 0x1e0));
  }
  FUN_14018b900(*(undefined8 *)(param_1 + 0x1e8),0);
  *(undefined8 *)(param_1 + 0x1e0) = local_270;
  *(undefined8 *)(param_1 + 0x1e8) = local_260;
  return;
}

