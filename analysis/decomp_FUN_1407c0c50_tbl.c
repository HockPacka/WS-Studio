
int * FUN_1407c0c50(longlong param_1,longlong *param_2)

{
  BOOL BVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int *piVar7;
  longlong lVar8;
  undefined8 extraout_XMM0_Qa;
  undefined8 local_res10;
  undefined **local_98;
  undefined8 local_90;
  LPVOID local_88;
  undefined **local_78;
  undefined8 local_70;
  LPVOID local_68;
  undefined **local_58;
  wchar_t *local_50;
  LPVOID local_48;
  longlong local_40;
  undefined **local_38;
  wchar_t *local_30;
  LPVOID local_28;
  longlong local_20;
  
  if (param_2 == (longlong *)0x0) {
    return (int *)0x0;
  }
  lVar8 = *param_2;
  lVar3 = FUN_1407c0af0(param_1,lVar8);
  if (lVar3 == -1) {
    uVar6 = 0;
    if (*(ulonglong *)(param_1 + 0x68) != 0) {
      plVar4 = *(longlong **)(param_1 + 0x60);
      uVar5 = uVar6;
      do {
        if (*plVar4 == lVar8) {
          return (int *)0x0;
        }
        uVar5 = uVar5 + 1;
        plVar4 = plVar4 + 1;
      } while (uVar5 < *(ulonglong *)(param_1 + 0x68));
    }
    FUN_140033260(param_1 + 0x60,param_2);
    local_res10 = 0x141e73d80;
    FUN_1401a3130(0xc,0,&local_res10);
    local_res10 = 0x141e73dc0;
    FUN_1401a3130(0xc,0,&local_res10,*param_2);
    BVar1 = IsDebuggerPresent();
    if ((BVar1 != 0) && (*(longlong *)(param_1 + 0x68) != 0)) {
      do {
        FUN_140059390(L"DbFileTable_%s_PrepShared();",
                      *(undefined8 *)(*(longlong *)(param_1 + 0x60) + uVar6 * 8));
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ulonglong *)(param_1 + 0x68));
    }
  }
  else {
    piVar7 = (int *)(*(longlong *)(lVar3 * 0x108 + 0x100 + *(longlong *)(param_1 + 0x58)) +
                    *(longlong *)(param_1 + 0x50));
    if (*piVar7 == 0x4454424c) {
      iVar2 = FUN_1407c0a20(extraout_XMM0_Qa,param_2,piVar7 + 2,piVar7);
      if (-1 < iVar2) {
        return piVar7;
      }
      local_98 = &PTR_LAB_140b5e648;
      local_90 = 0;
      local_88 = TlsGetValue(DAT_140c63720);
      TlsSetValue(DAT_140c63720,&local_98);
      lVar8 = *param_2;
      local_78 = local_98;
      local_70 = local_90;
      local_58 = &PTR_LAB_140b5e648;
      local_68 = local_88;
      local_50 = L"TableName";
      local_48 = TlsGetValue(DAT_140c63720);
      TlsSetValue(DAT_140c63720,&local_58);
      local_res10 = 0x141e73d20;
    }
    else {
      local_98 = &PTR_LAB_140b5e648;
      local_90 = 0;
      local_88 = TlsGetValue(DAT_140c63720);
      TlsSetValue(DAT_140c63720,&local_98);
      lVar8 = *param_2;
      local_78 = local_98;
      local_70 = local_90;
      local_58 = &PTR_LAB_140b5e648;
      local_68 = local_88;
      local_50 = L"TableName";
      local_48 = TlsGetValue(DAT_140c63720);
      TlsSetValue(DAT_140c63720,&local_58);
      local_res10 = 0x141e73cf0;
    }
    local_58 = &PTR_LAB_140b5e638;
    local_30 = local_50;
    local_38 = &PTR_LAB_140b5e638;
    local_28 = local_48;
    local_40 = lVar8;
    local_20 = lVar8;
    iVar2 = FUN_140197770(0xc,&local_res10,&local_38,&local_78);
    local_58 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_48);
    local_98 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_88);
    if (iVar2 != 0) {
      DebugBreak();
    }
  }
  return (int *)0x0;
}

