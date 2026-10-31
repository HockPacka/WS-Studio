
void FUN_1407c15c0(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  LPVOID pvVar4;
  undefined **ppuVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined8 uVar9;
  int iVar10;
  uint uVar11;
  longlong *plVar12;
  undefined8 extraout_XMM0_Qa;
  undefined8 local_res10;
  undefined **local_98;
  undefined8 local_90;
  LPVOID local_88;
  undefined **local_78;
  longlong local_70;
  LPVOID local_68;
  undefined **local_58;
  wchar_t *local_50;
  LPVOID local_48;
  undefined8 local_40;
  undefined **local_38;
  wchar_t *local_30;
  LPVOID local_28;
  undefined8 local_20;
  
  plVar12 = (longlong *)0x0;
  plVar7 = plVar12;
  if (((DAT_140c63758 != 0) &&
      (pvVar4 = TlsGetValue(*(DWORD *)(DAT_140c63758 + 4)), pvVar4 != (LPVOID)0x0)) &&
     (*(longlong *)((longlong)pvVar4 + 8) != 0)) {
    plVar7 = *(longlong **)(*(longlong *)((longlong)pvVar4 + 8) + 0x60);
  }
  iVar3 = (**(code **)(*plVar7 + 0x28))(plVar7,0);
  if (iVar3 < 0) {
    local_90 = 0;
    local_98 = &PTR_LAB_140b5e648;
    local_88 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_98);
    local_78 = local_98;
    local_70 = local_90;
    local_68 = local_88;
    uVar9 = **(undefined8 **)(param_1 + 0x10);
    local_58 = &PTR_LAB_140b5e648;
    local_50 = L"TableName";
    local_48 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_58);
    local_res10 = 0x141e4e530;
  }
  else {
    ppuVar5 = (undefined **)(**(code **)(**(longlong **)(param_1 + 0x20) + 0x20))();
    lVar6 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0x10))();
    if (*(int *)ppuVar5 == 0x4454424c) {
      local_70 = lVar6 + (longlong)ppuVar5;
      local_68 = (LPVOID)0x0;
      local_78 = ppuVar5;
      iVar3 = FUN_1407c1f00(&local_78,ppuVar5 + 0xc,ppuVar5);
      if (-1 < iVar3) {
        lVar6 = *(longlong *)(param_1 + 0x10);
        iVar3 = FUN_1407c19f0(extraout_XMM0_Qa,lVar6,ppuVar5 + 1);
        if (-1 < iVar3) {
          plVar7 = plVar12;
          if (*(int *)(lVar6 + 0xc) != 0) {
            do {
              iVar3 = (int)plVar7;
              lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
              lVar6 = (longlong)plVar7 * 0x28;
              sVar1 = *(short *)(lVar2 + 8 + lVar6);
              if (sVar1 == 0x82) {
                plVar7 = plVar12;
                if (*(int *)(ppuVar5 + 6) != 0) {
                  do {
                    iVar10 = (int)plVar7;
                    uVar11 = iVar10 + 1;
                    plVar7 = (longlong *)(ulonglong)uVar11;
                    plVar8 = (longlong *)
                             (ppuVar5[8] +
                             (ulonglong)(uint)(*(int *)(*(longlong *)(param_1 + 0x10) + 8) * iVar10)
                             + (ulonglong)
                               *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) + 0xc +
                                        lVar6));
                    *plVar8 = (longlong)(ppuVar5[8] + *plVar8);
                  } while (uVar11 < *(uint *)(ppuVar5 + 6));
                }
              }
              else if (((sVar1 == 0x80) && ((*(byte *)(lVar2 + 0x18 + lVar6) & 0x10) == 0)) &&
                      (plVar8 = plVar12, *(int *)(ppuVar5 + 6) != 0)) {
                do {
                  iVar10 = (int)plVar8;
                  plVar8 = (longlong *)
                           (ppuVar5[8] +
                           (ulonglong)(uint)(*(int *)(*(longlong *)(param_1 + 0x10) + 8) * iVar10) +
                           (ulonglong)
                           *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10) + 0xc +
                                    lVar6));
                  if (*plVar8 != 0) {
                    FUN_1401e8450(plVar8,ppuVar5[8] + *plVar8,(int)plVar8[1]);
                  }
                  iVar3 = (int)plVar7;
                  plVar8 = (longlong *)(ulonglong)(iVar10 + 1U);
                } while (iVar10 + 1U < *(uint *)(ppuVar5 + 6));
              }
              plVar7 = (longlong *)(ulonglong)(iVar3 + 1U);
            } while (iVar3 + 1U < *(uint *)(*(longlong *)(param_1 + 0x10) + 0xc));
          }
          *(undefined ***)(param_1 + 0x28) = ppuVar5;
          FUN_1400035b0(0xc,3,0,**(undefined8 **)(param_1 + 0x10));
          return;
        }
        local_90 = 0;
        local_98 = &PTR_LAB_140b5e648;
        local_88 = TlsGetValue(DAT_140c63720);
        TlsSetValue(DAT_140c63720,&local_98);
        local_78 = local_98;
        local_70 = local_90;
        local_68 = local_88;
        uVar9 = **(undefined8 **)(param_1 + 0x10);
        local_58 = &PTR_LAB_140b5e648;
        local_50 = L"TableName";
        local_48 = TlsGetValue(DAT_140c63720);
        TlsSetValue(DAT_140c63720,&local_58);
        local_res10 = 0x141e4e5c0;
        goto LAB_1407c1959;
      }
    }
    local_90 = 0;
    local_98 = &PTR_LAB_140b5e648;
    local_88 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_98);
    local_78 = local_98;
    local_70 = local_90;
    local_68 = local_88;
    uVar9 = **(undefined8 **)(param_1 + 0x10);
    local_58 = &PTR_LAB_140b5e648;
    local_50 = L"TableName";
    local_48 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_58);
    local_res10 = 0x141e4e560;
  }
LAB_1407c1959:
  local_58 = &PTR_LAB_140b5e638;
  local_38 = &PTR_LAB_140b5e638;
  local_30 = local_50;
  local_28 = local_48;
  local_40 = uVar9;
  local_20 = uVar9;
  iVar3 = FUN_140197770(0xc,&local_res10,&local_38,&local_78);
  local_58 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_48);
  local_98 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_88);
  if (iVar3 != 0) {
    DebugBreak();
  }
  return;
}

