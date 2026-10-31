
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1407d24d0(longlong param_1)

{
  undefined4 *puVar1;
  float fVar2;
  longlong *plVar3;
  short *psVar4;
  void *_Src;
  int iVar5;
  undefined8 uVar6;
  int *piVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  float fVar15;
  undefined1 auStack_9b8 [32];
  undefined4 *local_998;
  undefined ***local_990;
  undefined4 local_988;
  longlong local_980;
  undefined **local_978;
  undefined8 uStack_970;
  undefined8 local_968;
  undefined8 uStack_960;
  ulonglong local_958;
  undefined **local_950;
  undefined8 local_948;
  LPVOID local_940;
  undefined **local_938;
  longlong local_930;
  LPVOID local_928;
  undefined **local_918;
  wchar_t *local_910;
  LPVOID local_908;
  undefined8 local_900;
  void *local_8f8;
  undefined **local_8e8;
  wchar_t *local_8e0;
  LPVOID local_8d8;
  undefined8 local_8d0;
  undefined4 local_8c8;
  undefined4 uStack_8c4;
  undefined4 uStack_8c0;
  undefined4 uStack_8bc;
  undefined4 local_8b8;
  undefined4 uStack_8b4;
  int iStack_8b0;
  undefined4 uStack_8ac;
  undefined8 local_8a8;
  undefined8 uStack_8a0;
  undefined8 local_898;
  undefined8 uStack_890;
  undefined8 local_888;
  undefined8 uStack_880;
  undefined8 local_878;
  undefined8 uStack_870;
  undefined8 local_868;
  undefined8 uStack_860;
  undefined8 local_858;
  undefined8 uStack_850;
  undefined4 local_848;
  undefined4 uStack_844;
  undefined4 uStack_840;
  undefined4 uStack_83c;
  undefined1 local_838 [2048];
  ulonglong local_38;
  
  local_38 = DAT_140c0f7b0 ^ (ulonglong)auStack_9b8;
  iVar5 = (**(code **)(**(longlong **)(param_1 + 0xd8) + 0x28))(*(longlong **)(param_1 + 0xd8),0);
  if (iVar5 < 0) {
    FUN_1401b3450(local_838,0x400,iVar5);
    local_950 = &PTR_LAB_140b5e648;
    local_948 = 0;
    local_940 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_950);
    local_958 = 0x141e4f268;
    local_990 = &local_938;
    local_938 = local_950;
    local_930 = local_948;
    local_998 = *(undefined4 **)(param_1 + 0x90);
    local_928 = local_940;
    iVar5 = FUN_1401971e0(&DAT_140c8b180,0x1b,&local_958,local_838);
  }
  else {
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0xe0) + 0x20))();
    *(undefined8 *)(param_1 + 8) = uVar6;
    local_930 = (**(code **)(**(longlong **)(param_1 + 0xe0) + 0x10))();
    local_938 = *(undefined ***)(param_1 + 8);
    local_930 = local_930 + (longlong)local_938;
    uVar12 = 0;
    local_928 = (LPVOID)0x0;
    iVar5 = FUN_1407d1000(&local_938,local_938 + 0x98);
    if (-1 < iVar5) {
      FUN_1407d7dc0(param_1 + 0x1f0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x30));
      FUN_1407d7ea0(param_1 + 0x200,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x40));
      FUN_1407d7fa0(param_1 + 0x210,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x50));
      FUN_1407d80b0(param_1 + 0x220,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x60));
      FUN_1407d81c0(param_1 + 0x230,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x70));
      FUN_1407d82d0(param_1 + 0x240,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x80));
      uVar14 = uVar12;
      if (*(int *)(*(longlong *)(param_1 + 8) + 0x80) != 0) {
        do {
          uStack_83c = 0;
          FUN_1407e4830(&local_8a8,0,0x6c);
          lVar10 = *(longlong *)(param_1 + 0x240);
          lVar8 = uVar14 * 0x70;
          uVar9 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar9;
          *(undefined8 *)(lVar8 + lVar10) = local_8a8;
          ((undefined8 *)(lVar8 + lVar10))[1] = uStack_8a0;
          puVar11 = (undefined8 *)(lVar8 + 0x10 + lVar10);
          *puVar11 = local_898;
          puVar11[1] = uStack_890;
          puVar11 = (undefined8 *)(lVar8 + 0x20 + lVar10);
          *puVar11 = local_888;
          puVar11[1] = uStack_880;
          puVar11 = (undefined8 *)(lVar8 + 0x30 + lVar10);
          *puVar11 = local_878;
          puVar11[1] = uStack_870;
          puVar11 = (undefined8 *)(lVar8 + 0x40 + lVar10);
          *puVar11 = local_868;
          puVar11[1] = uStack_860;
          puVar11 = (undefined8 *)(lVar8 + 0x50 + lVar10);
          *puVar11 = local_858;
          puVar11[1] = uStack_850;
          puVar1 = (undefined4 *)(lVar8 + 0x60 + lVar10);
          *puVar1 = local_848;
          puVar1[1] = uStack_844;
          puVar1[2] = uStack_840;
          puVar1[3] = uStack_83c;
        } while (uVar9 < *(uint *)(*(longlong *)(param_1 + 8) + 0x80));
      }
      FUN_1407d7dc0(param_1 + 0x3e0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 200));
      FUN_1407d7ea0(param_1 + 0x3f0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0xd8));
      FUN_1407d7fa0(param_1 + 0x400,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0xe8));
      FUN_1407d80b0(param_1 + 0x410,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0xf8));
      FUN_1407d81c0(param_1 + 0x420,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x108));
      FUN_1407d7dc0(param_1 + 0x5d0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x160));
      FUN_1407d7ea0(param_1 + 0x5e0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x170));
      FUN_1407d7fa0(param_1 + 0x5f0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x180));
      FUN_1407d80b0(param_1 + 0x600,*(undefined4 *)(*(longlong *)(param_1 + 8) + 400));
      FUN_1407d81c0(param_1 + 0x610,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x1a0));
      FUN_1407d7dc0(param_1 + 0x7c0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x1f8));
      FUN_1407d7ea0(param_1 + 2000,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x208));
      FUN_1407d7fa0(param_1 + 0x7e0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x218));
      FUN_1407d80b0(param_1 + 0x7f0,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x228));
      FUN_1407d81c0(param_1 + 0x800,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x238));
      iVar5 = *(int *)(*(longlong *)(param_1 + 8) + 0x2e8);
      if ((iVar5 != 0) &&
         (FUN_1407d7ba0(param_1 + 0x118,iVar5), uVar14 = uVar12,
         *(int *)(*(longlong *)(param_1 + 8) + 0x2e8) != 0)) {
        do {
          plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x18) + 0xba8);
          iVar5 = (**(code **)(*plVar3 + 0x28))
                            (plVar3,*(undefined8 *)
                                     (*(longlong *)(*(longlong *)(param_1 + 8) + 0x2f0) + 0x10 +
                                     uVar14 * 0x30),&local_958,0);
          lVar10 = uVar14 * 0x20;
          if (iVar5 < 0) {
            *(undefined8 *)(lVar10 + *(longlong *)(param_1 + 0x118)) = 0;
          }
          else {
            *(ulonglong *)(lVar10 + *(longlong *)(param_1 + 0x118)) = local_958;
          }
          local_978 = (undefined **)0x96;
          uStack_970 = (wchar_t *)0x3f800000;
          plVar3 = *(longlong **)(lVar10 + *(longlong *)(param_1 + 0x118));
          local_968 = (LPVOID)0x0;
          uStack_960 = 0;
          (**(code **)(*plVar3 + 0x248))(plVar3,0,&local_978);
          plVar3 = *(longlong **)(lVar10 + *(longlong *)(param_1 + 0x118));
          (**(code **)(*plVar3 + 0xd0))
                    (plVar3,*(undefined2 *)
                             (*(longlong *)(*(longlong *)(param_1 + 8) + 0x2f0) + uVar14 * 0x30));
          uVar9 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar9;
        } while (uVar9 < *(uint *)(*(longlong *)(param_1 + 8) + 0x2e8));
      }
      uVar9 = *(uint *)(*(longlong *)(param_1 + 8) + 0x340);
      if (4 < uVar9) {
        uVar9 = 4;
      }
      uVar14 = (ulonglong)uVar9;
      if (uVar9 != 0) {
        puVar11 = (undefined8 *)(param_1 + 0x148);
        uVar13 = uVar12;
        do {
          lVar10 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x348);
          psVar4 = *(short **)(lVar10 + 8 + uVar13);
          if (((psVar4 == (short *)0x0) || (*psVar4 == 0)) ||
             (plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x18) + 3000),
             iVar5 = (**(code **)(*plVar3 + 0x28))
                               (plVar3,*(undefined8 *)(lVar10 + 8 + uVar13),puVar11,0), iVar5 < 0))
          {
            *puVar11 = 0;
          }
          else {
            local_978 = (undefined **)0x96;
            uStack_970 = (wchar_t *)0x3f800000;
            local_968 = (LPVOID)0x0;
            uStack_960 = 0;
            (**(code **)(*(longlong *)*puVar11 + 0x248))((longlong *)*puVar11,0,&local_978);
          }
          puVar11 = puVar11 + 1;
          uVar13 = uVar13 + 0x10;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      psVar4 = *(short **)(*(longlong *)(param_1 + 8) + 0x358);
      if ((psVar4 != (short *)0x0) && (*psVar4 != 0)) {
        fVar15 = (float)*(uint *)(*(longlong *)(param_1 + 0x18) + 0xb9c);
        local_980 = param_1 + 0x170;
        local_988 = 0;
        local_990 = (undefined ***)((ulonglong)local_990 & 0xffffffff00000000);
        local_998 = (undefined4 *)((ulonglong)local_998 & 0xffffffff00000000);
        fVar2 = *(float *)(*(longlong *)(param_1 + 0x18) + 0xba0);
        if (fVar15 <= fVar2) {
          fVar15 = fVar2;
        }
        *(int *)(param_1 + 0x168) = (int)(longlong)fVar15;
        (**(code **)(*DAT_140c65670 + 0x70))
                  (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x358),
                   (longlong)fVar15 & 0xffffffff,0);
      }
      psVar4 = *(short **)(*(longlong *)(param_1 + 8) + 0x380);
      if (((psVar4 == (short *)0x0) || (*psVar4 == 0)) ||
         (plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x18) + 0xba8),
         iVar5 = (**(code **)(*plVar3 + 0x28))(plVar3,psVar4,param_1 + 0x1a8,0), iVar5 < 0)) {
        *(undefined8 *)(param_1 + 0x1a8) = 0;
      }
      else {
        local_978 = (undefined **)0x96;
        uStack_970 = (wchar_t *)0x3f800000;
        local_968 = (LPVOID)0x0;
        uStack_960 = 0;
        (**(code **)(**(longlong **)(param_1 + 0x1a8) + 0x248))
                  (*(longlong **)(param_1 + 0x1a8),0,&local_978);
      }
      psVar4 = *(short **)(*(longlong *)(param_1 + 8) + 0x390);
      if (((psVar4 == (short *)0x0) || (*psVar4 == 0)) ||
         (plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x18) + 0xba8),
         iVar5 = (**(code **)(*plVar3 + 0x28))(plVar3,psVar4,param_1 + 0x1b0,0), iVar5 < 0)) {
        *(undefined8 *)(param_1 + 0x1b0) = 0;
      }
      else {
        local_978 = (undefined **)0x96;
        uStack_970 = (wchar_t *)0x3f800000;
        local_968 = (LPVOID)0x0;
        uStack_960 = 0;
        (**(code **)(**(longlong **)(param_1 + 0x1b0) + 0x248))
                  (*(longlong **)(param_1 + 0x1b0),0,&local_978);
      }
      FUN_1407d7c90(param_1 + 0x1d8,*(undefined4 *)(*(longlong *)(param_1 + 8) + 0x4a0));
      uVar14 = uVar12;
      if (*(int *)(*(longlong *)(param_1 + 8) + 0x4a0) != 0) {
        do {
          lVar10 = *(longlong *)(param_1 + 0x1d8);
          uVar9 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x4a8) + uVar14 * 0x18);
          local_958 = (ulonglong)uVar9;
          if (*(ulonglong *)(lVar10 + 8 + uVar14 * 0x10) <= local_958) {
            local_8f8 = (void *)FUN_14018db00(*(undefined8 *)(lVar10 + uVar14 * 0x10),uVar9,0xc);
            _Src = *(void **)(lVar10 + uVar14 * 0x10);
            if (_Src != local_8f8) {
              memcpy(local_8f8,_Src,*(longlong *)(lVar10 + 8 + uVar14 * 0x10) * 0xc);
              lVar8 = *(longlong *)(lVar10 + uVar14 * 0x10);
              if (lVar8 != 0) {
                (**(code **)(*(longlong *)(lVar8 + -0x10) + 8))(lVar8 + -0x10);
              }
              *(void **)(lVar10 + uVar14 * 0x10) = local_8f8;
            }
          }
          *(ulonglong *)(lVar10 + 8 + uVar14 * 0x10) = local_958;
          uVar13 = uVar12;
          if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x4a8) + uVar14 * 0x18) != 0) {
            do {
              uVar9 = (int)uVar13 + 1;
              *(undefined8 *)
               (*(longlong *)(*(longlong *)(param_1 + 0x1d8) + uVar14 * 0x10) + uVar13 * 0xc) =
                   *(undefined8 *)
                    (*(longlong *)
                      (*(longlong *)(*(longlong *)(param_1 + 8) + 0x4a8) + 0x10 + uVar14 * 0x18) +
                    uVar13 * 8);
              *(undefined4 *)
               (*(longlong *)(*(longlong *)(param_1 + 0x1d8) + uVar14 * 0x10) + 8 + uVar13 * 0xc) =
                   *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x528);
              uVar13 = (ulonglong)uVar9;
            } while (uVar9 < *(uint *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x4a8) +
                                      uVar14 * 0x18));
          }
          uVar9 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar9;
        } while (uVar9 < *(uint *)(*(longlong *)(param_1 + 8) + 0x4a0));
      }
      psVar4 = *(short **)(*(longlong *)(param_1 + 8) + 0x4b8);
      if ((psVar4 != (short *)0x0) && (*psVar4 != 0)) {
        piVar7 = (int *)(**(code **)(*DAT_140c65670 + 0x2c8))();
        local_980 = param_1 + 0x1e8;
        local_988 = 0;
        local_990 = (undefined ***)((ulonglong)local_990 & 0xffffffff00000000);
        local_998 = (undefined4 *)CONCAT44(local_998._4_4_,1);
        (**(code **)(*DAT_140c65670 + 0x60))
                  (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x4b8),0,*piVar7 != 0)
        ;
      }
      return 1;
    }
    local_948 = 0;
    local_950 = &PTR_LAB_140b5e648;
    local_940 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_950);
    local_938 = local_950;
    local_930 = local_948;
    local_978 = &PTR_LAB_140b5e648;
    uStack_970 = L"Result";
    local_928 = local_940;
    local_968 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_978);
    uStack_960 = CONCAT44(uStack_960._4_4_,iVar5);
    uVar6 = *(undefined8 *)(param_1 + 0x90);
    local_918 = &PTR_LAB_140b5e648;
    local_8b8 = (undefined4)local_968;
    uStack_8b4 = local_968._4_4_;
    uStack_8ac = uStack_960._4_4_;
    local_978 = &PTR_FUN_140b5e640;
    local_910 = L"FileName";
    local_8c8 = 0x40b5e640;
    uStack_8c4 = 1;
    uStack_8c0 = (undefined4)uStack_970;
    uStack_8bc = uStack_970._4_4_;
    iStack_8b0 = iVar5;
    local_908 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_918);
    local_8e0 = local_910;
    local_918 = &PTR_LAB_140b5e638;
    local_8e8 = &PTR_LAB_140b5e638;
    local_958 = 0x141e4f328;
    local_990 = &local_938;
    local_8d8 = local_908;
    local_998 = &local_8c8;
    local_900 = uVar6;
    local_8d0 = uVar6;
    iVar5 = FUN_1401971e0(&DAT_140c8b17c,0x1b,&local_958,&local_8e8);
    local_918 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_908);
    local_978 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_968);
  }
  local_950 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_940);
  if (iVar5 != 0) {
    DebugBreak();
  }
  if (*(longlong **)(param_1 + 0xe0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xe0) + 8))();
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  *(undefined8 *)(param_1 + 8) = 0;
  return 0;
}

