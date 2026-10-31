
==== FUN_1402e01d0 @ 1402e01d0 size 392 ====
CALLERS: FUN_1402e1060 FUN_1402e0140 FUN_1402e5e60
CALLEES: FUN_1402e4180 FUN_14018b280 FUN_1407e4830 FUN_1402e3e00 FUN_1402dd480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_1402e01d0(longlong param_1,ulonglong param_2,undefined8 *param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong *local_res18;
  
  if (param_3 == (undefined8 *)0x0) {
    return -0x7ff8ffa9;
  }
  if (*(ulonglong *)(param_1 + 0x1518) <= param_2) {
    return -0x7fffbffb;
  }
  iVar5 = FUN_1402dd480(*(longlong *)(param_1 + 0x10) + 0x6d0,
                        *(undefined8 *)(*(longlong *)(param_1 + 0x1510) + param_2 * 8),&local_res18)
  ;
  if (iVar5 == 0) {
    local_res18 = (longlong *)FUN_14018b280(0x300,1);
    lVar4 = _DAT_140b7b248;
    lVar3 = _DAT_140b7b240;
    if (local_res18 == (longlong *)0x0) {
      return -0x7ff8fff2;
    }
    lVar2 = *(longlong *)(param_1 + 0x10);
    *local_res18 = (longlong)&PTR_FUN_140b63310;
    local_res18[0x4c] = lVar3;
    local_res18[0x4d] = lVar4;
    *(undefined4 *)(local_res18 + 1) = 1;
    local_res18[2] = lVar2;
    LOCK();
    piVar1 = (int *)(lVar2 + 0xc);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    local_res18[3] = 0;
    local_res18[4] = 0;
    local_res18[0x55] = 0;
    local_res18[0x56] = 0;
    local_res18[0x57] = 0;
    local_res18[0x58] = 0;
    local_res18[0x59] = 0;
    local_res18[0x5a] = 0;
    *(undefined4 *)((longlong)local_res18 + 0x34) = 0;
    FUN_1407e4830((longlong)local_res18 + 0x4c,0,0x208);
    *(undefined4 *)(local_res18 + 0x4e) = 0x3f800000;
    local_res18[0x50] = lVar3;
    local_res18[0x51] = lVar4;
    iVar5 = FUN_1402e3e00(local_res18,*(undefined8 *)(*(longlong *)(param_1 + 0x1510) + param_2 * 8)
                          ,*(undefined8 *)(*(longlong *)(param_1 + 0x1520) + param_2 * 8));
    if (iVar5 < 0) {
      (**(code **)(*local_res18 + 8))(local_res18);
      return iVar5;
    }
  }
  else {
    (**(code **)*local_res18)(local_res18);
  }
  *param_3 = local_res18;
  return 0;
}



==== FUN_1402e0820 @ 1402e0820 size 896 ====
CALLERS:
CALLEES: FUN_1402e0580 FUN_1402e0680 DebugBreak FUN_1402df540 TlsGetValue TlsSetValue FUN_1401971e0 FUN_1402e0480

undefined8 FUN_1402e0820(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 local_res8;
  undefined **local_d8;
  wchar_t *local_d0;
  LPVOID local_c8;
  longlong local_c0;
  undefined **local_b8;
  undefined8 local_b0;
  LPVOID local_a8;
  undefined **local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  int iStack_88;
  undefined4 uStack_84;
  undefined **local_78;
  undefined8 local_70;
  LPVOID local_68;
  undefined **local_58;
  wchar_t *local_50;
  LPVOID local_48;
  longlong local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  if (*(longlong **)(param_1 + 0x4a0) == (longlong *)0x0) {
    return 1;
  }
  uVar3 = (**(code **)(**(longlong **)(param_1 + 0x4a0) + 0x20))();
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  iVar2 = (**(code **)(**(longlong **)(param_1 + 0x4a0) + 0x28))(*(longlong **)(param_1 + 0x4a0),0);
  if (iVar2 < 0) {
    local_b0 = 0;
    local_b8 = &PTR_LAB_140b5e648;
    local_a8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_b8);
    local_78 = local_b8;
    local_70 = local_b0;
    local_a0 = &PTR_LAB_140b5e648;
    uStack_98 = L"Result";
    local_68 = local_a8;
    local_90 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a0);
    local_a0 = &PTR_FUN_140b5e640;
    local_d8 = &PTR_LAB_140b5e648;
    local_d0 = L"FileName";
    local_38 = 0x40b5e640;
    uStack_34 = 1;
    uStack_30 = (undefined4)uStack_98;
    uStack_2c = uStack_98._4_4_;
    local_28 = (undefined4)local_90;
    uStack_24 = local_90._4_4_;
    uStack_1c = uStack_84;
    iStack_88 = iVar2;
    iStack_20 = iVar2;
    local_c8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_d8);
    puVar4 = &DAT_140c8a578;
    local_res8 = 0x141deb530;
  }
  else {
    iVar2 = FUN_1402df540(param_1);
    if (-1 < iVar2) goto LAB_1402e0b13;
    local_b0 = 0;
    local_b8 = &PTR_LAB_140b5e648;
    local_a8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_b8);
    local_78 = local_b8;
    local_70 = local_b0;
    local_a0 = &PTR_LAB_140b5e648;
    uStack_98 = L"Result";
    local_68 = local_a8;
    local_90 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_a0);
    local_a0 = &PTR_FUN_140b5e640;
    local_d8 = &PTR_LAB_140b5e648;
    local_d0 = L"FileName";
    local_38 = 0x40b5e640;
    uStack_34 = 1;
    uStack_30 = (undefined4)uStack_98;
    uStack_2c = uStack_98._4_4_;
    local_28 = (undefined4)local_90;
    uStack_24 = local_90._4_4_;
    uStack_1c = uStack_84;
    iStack_88 = iVar2;
    iStack_20 = iVar2;
    local_c8 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_d8);
    puVar4 = &DAT_140c8a57c;
    local_res8 = 0x141deb560;
  }
  local_c0 = param_1 + 0x268;
  local_d8 = &PTR_LAB_140b5e638;
  local_58 = &PTR_LAB_140b5e638;
  local_50 = local_d0;
  local_48 = local_c8;
  local_40 = local_c0;
  iVar2 = FUN_1401971e0(puVar4,0x24,&local_res8,&local_58,&local_38,&local_78);
  local_d8 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_c8);
  local_a0 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_90);
  local_b8 = &PTR_LAB_140b5e648;
  TlsSetValue(DAT_140c63720,local_a8);
  if (iVar2 != 0) {
    DebugBreak();
  }
LAB_1402e0b13:
  if (*(longlong **)(param_1 + 0x4b0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x4b0) + 8))();
    *(undefined8 *)(param_1 + 0x4b0) = 0;
  }
  if (*(longlong **)(param_1 + 0x4a0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x4a0) + 8))();
    *(undefined8 *)(param_1 + 0x4a0) = 0;
  }
  FUN_1402e0480(param_1);
  FUN_1402e0580(param_1);
  FUN_1402e0680(param_1);
  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x10) + 0x770);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x788));
  }
  return 1;
}



==== FUN_1402e0ba0 @ 1402e0ba0 size 517 ====
CALLERS:
CALLEES: FUN_1402df1c0 FUN_1401b5b50

undefined8 FUN_1402e0ba0(longlong *param_1)

{
  code *pcVar1;
  ulonglong *puVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int local_res8;
  int local_resc;
  longlong *local_res10;
  
  iVar4 = (**(code **)(*param_1 + 0x40))();
  if (iVar4 != 0) {
    return 0x80004005;
  }
  pcVar1 = *(code **)(param_1[2] + 0x748);
  if (pcVar1 == (code *)0x0) {
    iVar4 = FUN_1401b5b50(DAT_140c63788,param_1 + 0x4d,1,4,&local_res10);
    if (iVar4 < 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = (**(code **)(*local_res10 + 0x20))(local_res10);
      (**(code **)(*local_res10 + 8))(local_res10);
    }
  }
  else {
    lVar5 = (*pcVar1)(param_1,*(undefined8 *)(param_1[2] + 0x788));
  }
  if (param_1[0x95] == lVar5) {
    return 0;
  }
  uVar6 = FUN_1402df1c0(param_1);
  if (-1 < (int)uVar6) {
    if (*(longlong *)(param_1[2] + 0x7a0) != 0) {
      for (lVar5 = param_1[0x297]; lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x208)) {
        (**(code **)(param_1[2] + 0x7a0))(lVar5,*(undefined8 *)(param_1[2] + 0x7f0));
      }
    }
    local_resc = *(int *)((longlong)param_1 + 0x24) + -1;
    if (local_resc < *(int *)((longlong)param_1 + 0x24) + 2) {
      do {
        local_res8 = (int)param_1[4] + -1;
        if (local_res8 < (int)param_1[4] + 2) {
          do {
            lVar5 = param_1[2];
            uVar7 = (**(code **)(lVar5 + 0x698))(&local_res8);
            for (puVar2 = *(ulonglong **)
                           (*(longlong *)(lVar5 + 0x690) +
                           (uVar7 % *(ulonglong *)(lVar5 + 0x688)) * 8); puVar2 != (ulonglong *)0x0;
                puVar2 = (ulonglong *)puVar2[1]) {
              if ((uVar7 == *puVar2) &&
                 (iVar4 = (**(code **)(lVar5 + 0x6a0))(&local_res8), iVar4 != 0)) {
                if ((puVar2 + 3 != (ulonglong *)0x0) &&
                   (((plVar3 = (longlong *)puVar2[3], plVar3 != (longlong *)0x0 &&
                     (iVar4 = (**(code **)(*plVar3 + 0x40))(plVar3), iVar4 == 0)) &&
                    (uVar6 = (**(code **)(*plVar3 + 0x28))(plVar3), (int)uVar6 < 0)))) {
                  return uVar6;
                }
                break;
              }
            }
            local_res8 = local_res8 + 1;
          } while (local_res8 < (int)param_1[4] + 2);
        }
        local_resc = local_resc + 1;
      } while (local_resc < *(int *)((longlong)param_1 + 0x24) + 2);
    }
    uVar6 = 0;
  }
  return uVar6;
}



==== FUN_1402e5720 @ 1402e5720 size 317 ====
CALLERS: FUN_1402e4ec0
CALLEES: FUN_14018b280 FUN_1407e4830 FUN_1402de370

ulonglong FUN_1402e5720(longlong param_1,ulonglong param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 auVar2 [16];
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint *puVar10;
  
  if ((*(longlong *)(param_1 + 0x1d8) == 0) && (3 < param_2)) {
    uVar1 = *param_3;
    *(ulonglong *)(param_1 + 0x1d0) = CONCAT44(0,uVar1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = CONCAT44(0,uVar1);
    uVar4 = SUB168(ZEXT816(8) * auVar2,0);
    if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
      uVar4 = 0xffffffffffffffff;
    }
    lVar5 = FUN_14018b280(uVar4,1);
    *(longlong *)(param_1 + 0x1d8) = lVar5;
    if (lVar5 == 0) {
      uVar3 = 0x8007000e;
    }
    else {
      FUN_1407e4830(lVar5,0,*(longlong *)(param_1 + 0x1d0) << 3);
      uVar3 = 0;
      param_2 = param_2 - 4;
      puVar9 = param_3 + 1;
      if (*(longlong *)(param_1 + 0x1d0) != 0) {
        do {
          if (param_2 < 0x50) {
            return 0x80004005;
          }
          puVar10 = puVar9 + 0x14;
          uVar6 = (ulonglong)puVar9[0x10];
          if (param_2 - 0x50 < uVar6 * 4) {
            return 0x80004005;
          }
          param_2 = (param_2 - 0x50) + uVar6 * -4;
          uVar7 = (ulonglong)puVar9[0x11];
          if (param_2 < uVar7 * 0x48) {
            return 0x80004005;
          }
          param_2 = param_2 + uVar7 * -0x48;
          uVar8 = FUN_1402de370(puVar9,puVar10,puVar10 + uVar6,param_4,
                                *(longlong *)(param_1 + 0x1d8) + uVar3 * 8);
          if ((int)uVar8 < 0) {
            return uVar8;
          }
          uVar3 = uVar3 + 1;
          puVar9 = puVar10 + uVar6 + uVar7 * 0x12;
        } while (uVar3 < *(ulonglong *)(param_1 + 0x1d0));
      }
      uVar3 = (ulonglong)(-(uint)(param_2 != 0) & 0x80004005);
    }
  }
  else {
    uVar3 = 0x80004005;
  }
  return uVar3;
}



==== FUN_1402e59b0 @ 1402e59b0 size 286 ====
CALLERS: FUN_1402e4ec0
CALLEES: FUN_1402de460 FUN_14018b280 FUN_1407e4830

ulonglong FUN_1402e59b0(longlong param_1,ulonglong param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 auVar2 [16];
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint *puVar8;
  
  if ((*(longlong *)(param_1 + 0x1e8) == 0) && (3 < param_2)) {
    uVar1 = *param_3;
    *(ulonglong *)(param_1 + 0x1e0) = CONCAT44(0,uVar1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = CONCAT44(0,uVar1);
    uVar4 = SUB168(ZEXT816(8) * auVar2,0);
    if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
      uVar4 = 0xffffffffffffffff;
    }
    lVar5 = FUN_14018b280(uVar4,1);
    *(longlong *)(param_1 + 0x1e8) = lVar5;
    if (lVar5 == 0) {
      uVar3 = 0x8007000e;
    }
    else {
      FUN_1407e4830(lVar5,0,*(longlong *)(param_1 + 0x1e0) << 3);
      uVar3 = 0;
      param_2 = param_2 - 4;
      puVar8 = param_3 + 1;
      if (*(longlong *)(param_1 + 0x1e0) != 0) {
        do {
          if (param_2 < 4) {
            return 0x80004005;
          }
          uVar6 = (ulonglong)*puVar8;
          if (param_2 - 4 < uVar6 * 0xc) {
            return 0x80004005;
          }
          param_2 = (param_2 - 4) + uVar6 * -0xc;
          uVar7 = FUN_1402de460(puVar8,puVar8 + 1,param_4,*(longlong *)(param_1 + 0x1e8) + uVar3 * 8
                               );
          if ((int)uVar7 < 0) {
            return uVar7;
          }
          uVar3 = uVar3 + 1;
          puVar8 = puVar8 + 1 + uVar6 * 3;
        } while (uVar3 < *(ulonglong *)(param_1 + 0x1e0));
      }
      uVar3 = (ulonglong)(-(uint)(param_2 != 0) & 0x80004005);
    }
  }
  else {
    uVar3 = 0x80004005;
  }
  return uVar3;
}



==== FUN_1402e63a0 @ 1402e63a0 size 333 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_1407b0710

undefined8 FUN_1402e63a0(longlong *param_1,undefined8 *param_2)

{
  undefined1 auVar1 [16];
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 local_18 [4];
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x30))(param_1,local_18);
  plVar2 = (longlong *)FUN_14018b280(0x20);
  if (plVar2 == (longlong *)0x0) {
    return 0x8007000e;
  }
  uVar5 = 0;
  *plVar2 = (longlong)&PTR_FUN_140b787c0;
  *(undefined4 *)(plVar2 + 3) = 1;
  plVar2[1] = 0;
  plVar2[2] = 0;
  plVar2[1] = param_1[0x3a];
  uVar4 = uVar5;
  if (param_1[0x3a] != 0) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_1[0x3a];
    uVar3 = SUB168(ZEXT816(8) * auVar1,0);
    if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
      uVar3 = 0xffffffffffffffff;
    }
    uVar4 = FUN_14018b280(uVar3,1);
  }
  plVar2[2] = uVar4;
  if ((plVar2[1] == 0) || (uVar4 != 0)) {
    if (param_1[0x3a] != 0) {
      do {
        *(undefined8 *)(plVar2[2] + uVar5 * 8) = *(undefined8 *)(param_1[0x3b] + uVar5 * 8);
        (**(code **)**(undefined8 **)(param_1[0x3b] + uVar5 * 8))();
        uVar5 = (ulonglong)((int)uVar5 + 1);
      } while (uVar5 < (ulonglong)param_1[0x3a]);
    }
    *param_2 = plVar2;
    uVar3 = 0;
  }
  else {
    (**(code **)(*plVar2 + 0x20))(plVar2,1);
    uVar3 = 0x8007000e;
  }
  return uVar3;
}



==== FUN_1402e64f0 @ 1402e64f0 size 333 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_1407b0710

undefined8 FUN_1402e64f0(longlong *param_1,undefined8 *param_2)

{
  undefined1 auVar1 [16];
  longlong *plVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 local_18 [4];
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x30))(param_1,local_18);
  plVar2 = (longlong *)FUN_14018b280(0x20);
  if (plVar2 == (longlong *)0x0) {
    return 0x8007000e;
  }
  uVar5 = 0;
  *plVar2 = (longlong)&PTR_FUN_140b787c0;
  *(undefined4 *)(plVar2 + 3) = 1;
  plVar2[1] = 0;
  plVar2[2] = 0;
  plVar2[1] = param_1[0x3c];
  uVar4 = uVar5;
  if (param_1[0x3c] != 0) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_1[0x3c];
    uVar3 = SUB168(ZEXT816(8) * auVar1,0);
    if (SUB168(ZEXT816(8) * auVar1,8) != 0) {
      uVar3 = 0xffffffffffffffff;
    }
    uVar4 = FUN_14018b280(uVar3,1);
  }
  plVar2[2] = uVar4;
  if ((plVar2[1] == 0) || (uVar4 != 0)) {
    if (param_1[0x3c] != 0) {
      do {
        *(undefined8 *)(plVar2[2] + uVar5 * 8) = *(undefined8 *)(param_1[0x3d] + uVar5 * 8);
        (**(code **)**(undefined8 **)(param_1[0x3d] + uVar5 * 8))();
        uVar5 = (ulonglong)((int)uVar5 + 1);
      } while (uVar5 < (ulonglong)param_1[0x3c]);
    }
    *param_2 = plVar2;
    uVar3 = 0;
  }
  else {
    (**(code **)(*plVar2 + 0x20))(plVar2,1);
    uVar3 = 0x8007000e;
  }
  return uVar3;
}



==== FUN_1402ebf40 @ 1402ebf40 size 1471 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1401c96d0 FUN_14030fbf0 FUN_14030f870 FUN_140326380 FUN_14030fa00

/* WARNING: Removing unreachable block (ram,0x0001402ec224) */
/* WARNING: Removing unreachable block (ram,0x0001402ec22c) */
/* WARNING: Removing unreachable block (ram,0x0001402ec1f9) */
/* WARNING: Removing unreachable block (ram,0x0001402ec201) */
/* WARNING: Removing unreachable block (ram,0x0001402ec237) */

void FUN_1402ebf40(longlong param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  longlong lVar8;
  float *pfVar9;
  uint *puVar10;
  ulonglong uVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 extraout_XMM0_Da;
  uint local_res8 [2];
  undefined1 local_res10 [8];
  undefined4 local_res18;
  
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x848) + 0x48))
                     (*(longlong **)(param_1 + 0x848),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *(undefined4 *)((ulonglong)local_res8[0] + 4 + (longlong)puVar6) = 0xffff00ff;
    *puVar6 = 0xffff00ff;
    *(undefined4 *)((ulonglong)local_res8[0] + (longlong)puVar6) = 0xff00ff00;
    puVar6[1] = 0xff00ff00;
    (**(code **)(**(longlong **)(param_1 + 0x848) + 0x50))(*(longlong **)(param_1 + 0x848),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x850) + 0x48))
                     (*(longlong **)(param_1 + 0x850),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xff7f7fff;
    (**(code **)(**(longlong **)(param_1 + 0x850) + 0x50))(*(longlong **)(param_1 + 0x850),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x858) + 0x48))
                     (*(longlong **)(param_1 + 0x858),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xffffffff;
    (**(code **)(**(longlong **)(param_1 + 0x858) + 0x50))(*(longlong **)(param_1 + 0x858),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x860) + 0x48))
                     (*(longlong **)(param_1 + 0x860),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xffffffff;
    (**(code **)(**(longlong **)(param_1 + 0x860) + 0x50))(*(longlong **)(param_1 + 0x860),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x868) + 0x48))
                     (*(longlong **)(param_1 + 0x868),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xff7f7fff;
    (**(code **)(**(longlong **)(param_1 + 0x868) + 0x50))(*(longlong **)(param_1 + 0x868),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x870) + 0x48))
                     (*(longlong **)(param_1 + 0x870),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xffffffff;
    (**(code **)(**(longlong **)(param_1 + 0x870) + 0x50))(*(longlong **)(param_1 + 0x870),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x878) + 0x48))
                     (*(longlong **)(param_1 + 0x878),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xff000000;
    (**(code **)(**(longlong **)(param_1 + 0x878) + 0x50))(*(longlong **)(param_1 + 0x878),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x880) + 0x48))
                     (*(longlong **)(param_1 + 0x880),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xffffffff;
    (**(code **)(**(longlong **)(param_1 + 0x880) + 0x50))(*(longlong **)(param_1 + 0x880),0);
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x888) + 0x48))
                     (*(longlong **)(param_1 + 0x888),0,local_res8,2);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0xff7f7f7f;
    (**(code **)(**(longlong **)(param_1 + 0x888) + 0x50))(*(longlong **)(param_1 + 0x888),0);
  }
  puVar7 = (ushort *)
           (**(code **)(**(longlong **)(param_1 + 0x890) + 0x48))
                     (*(longlong **)(param_1 + 0x890),0,local_res10,2);
  uVar16 = 0;
  if (puVar7 != (ushort *)0x0) {
    uVar15 = DAT_140b7a1b0 & 0x7fffffff;
    if (uVar15 < 0x33800000) {
      uVar14 = 0;
    }
    else if (uVar15 < 0x387ff000) {
      uVar14 = (ushort)(((DAT_140b7a1b0 & 0x7fffff | 0x800000) >>
                        (0x71U - (char)(uVar15 >> 0x17) & 0x1f)) + 0x1000 >> 0xd);
    }
    else if (uVar15 < 0x47fff000) {
      uVar14 = (ushort)(uVar15 + 0xc8001000 >> 0xd);
    }
    else {
      uVar14 = 0x43ff;
    }
    local_res8[0] = 0;
    *puVar7 = uVar14 | (ushort)(DAT_140b7a1b0 >> 0x10) & 0x8000;
    puVar7[1] = 0;
    (**(code **)(**(longlong **)(param_1 + 0x890) + 0x50))(*(longlong **)(param_1 + 0x890),0);
  }
  lVar8 = (**(code **)(**(longlong **)(param_1 + 0x898) + 0x48))
                    (*(longlong **)(param_1 + 0x898),0,local_res8,2);
  if (lVar8 != 0) {
    uVar15 = 0;
    do {
      uVar17 = 0;
      puVar10 = (uint *)((ulonglong)(uVar15 * local_res8[0]) + lVar8);
      do {
        uVar3 = uVar17 & 0xffff | (uint)(ushort)((short)uVar15 << 8);
        uVar4 = uVar3 & 0xffff7fff;
        if ((uVar3 & 0x7c00) == 0) {
          if ((uVar3 & 0x3ff) != 0) {
            iVar5 = 0x71;
            for (uVar4 = (uVar3 & 0x3ff) << 0xd; uVar4 < 0x800000; uVar4 = uVar4 * 2) {
              iVar5 = iVar5 + -1;
            }
            uVar4 = iVar5 << 0x17 | uVar4 & 0x7fffff;
          }
        }
        else {
          uVar4 = (uVar4 + 0x1c000) * 0x2000;
        }
        uVar17 = uVar17 + 1;
        *puVar10 = (uVar3 & 0xffff8000) << 0x10 | uVar4;
        puVar10 = puVar10 + 1;
      } while (uVar17 < 0x100);
      uVar15 = uVar15 + 1;
    } while (uVar15 < 0x100);
    (**(code **)(**(longlong **)(param_1 + 0x898) + 0x50))(*(longlong **)(param_1 + 0x898),0);
  }
  pfVar9 = (float *)(**(code **)(**(longlong **)(param_1 + 0x8a8) + 0x38))
                              (*(longlong **)(param_1 + 0x8a8),0,0,2);
  if (pfVar9 != (float *)0x0) {
    puVar10 = (uint *)(**(code **)(**(longlong **)(param_1 + 0x8a8) + 0x18))();
    uVar15 = *puVar10;
    if (uVar15 >> 2 != 0) {
      do {
        uVar11 = (ulonglong)uVar16;
        uVar16 = uVar16 + 1;
        *pfVar9 = (float)uVar11;
        pfVar9 = pfVar9 + 1;
      } while (uVar16 < uVar15 >> 2);
    }
    (**(code **)(**(longlong **)(param_1 + 0x8a8) + 0x40))();
  }
  puVar6 = (undefined4 *)
           (**(code **)(**(longlong **)(param_1 + 0x8b8) + 0x38))
                     (*(longlong **)(param_1 + 0x8b8),0,0,2);
  if (puVar6 != (undefined4 *)0x0) {
    puVar12 = (undefined2 *)FUN_1401c96d0(local_res8,0);
    puVar13 = (undefined2 *)FUN_1401c96d0(local_res10);
    uVar2 = DAT_140b79ed0;
    local_res18 = CONCAT22(*puVar12,*puVar13);
    *puVar6 = local_res18;
    puVar12 = (undefined2 *)FUN_1401c96d0(local_res8,uVar2);
    puVar13 = (undefined2 *)FUN_1401c96d0(local_res10,0);
    local_res18 = CONCAT22(*puVar12,*puVar13);
    puVar6[1] = local_res18;
    puVar12 = (undefined2 *)FUN_1401c96d0(local_res8);
    puVar13 = (undefined2 *)FUN_1401c96d0(local_res10,extraout_XMM0_Da);
    local_res18 = CONCAT22(*puVar12,*puVar13);
    puVar6[2] = local_res18;
    puVar12 = (undefined2 *)FUN_1401c96d0(local_res8);
    puVar13 = (undefined2 *)FUN_1401c96d0(local_res10);
    local_res18 = CONCAT22(*puVar12,*puVar13);
    puVar6[3] = local_res18;
    (**(code **)(**(longlong **)(param_1 + 0x8b8) + 0x40))();
  }
  for (lVar8 = *(longlong *)(param_1 + 0x30); lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x88)) {
    if (*(longlong *)(lVar8 + 0xa0) != 0) {
      iVar5 = *(int *)(lVar8 + 0xa8);
      if (iVar5 == 7) {
        FUN_14030f870(lVar8);
      }
      else if (iVar5 == 8) {
        FUN_14030fa00(lVar8);
      }
      else if (iVar5 == 9) {
        FUN_14030fbf0(lVar8);
      }
    }
    for (lVar1 = *(longlong *)(lVar8 + 0x1d8); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x68)) {
      FUN_140326380(lVar1);
    }
  }
  return;
}



==== FUN_1402ec620 @ 1402ec620 size 477 ====
CALLERS: FUN_1403104b0
CALLEES: FUN_14019fb60 FUN_14018b280 FUN_14030d310 SetEvent FUN_14018b900 CloseHandle FUN_14030d6a0 FUN_14030d400 CreateEventW GetCurrentThreadId

int FUN_1402ec620(longlong param_1,short *param_2,ulonglong *param_3)

{
  DWORD *pDVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  DWORD *pDVar4;
  DWORD DVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  HANDLE hObject;
  ulonglong *puVar10;
  bool bVar11;
  short *local_res10 [2];
  DWORD *local_res20;
  
  if ((param_2 == (short *)0x0) || (*param_2 == 0)) {
    return -0x7ff8ffa9;
  }
  local_res10[0] = param_2;
  local_res20 = (DWORD *)(param_1 + 8);
  DVar5 = GetCurrentThreadId();
  puVar10 = (ulonglong *)(local_res20 + 2);
  uVar9 = 0;
  uVar7 = uVar9;
  if (*(DWORD *)(param_1 + 8) == DVar5) {
    *puVar10 = *puVar10 + 1;
  }
  else {
    do {
      LOCK();
      uVar2 = *puVar10;
      if (uVar2 == 0) {
        *puVar10 = 1;
      }
      UNLOCK();
      if (uVar2 == 0) {
        *local_res20 = DVar5;
        goto LAB_1402ec6be;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x400);
    FUN_14019fb60(local_res20);
  }
LAB_1402ec6be:
  uVar7 = (**(code **)(param_1 + 0x50))(local_res10);
  puVar3 = *(ulonglong **)
            (*(longlong *)(param_1 + 0x48) + (uVar7 % *(ulonglong *)(param_1 + 0x40)) * 8);
  do {
    if (puVar3 == (ulonglong *)0x0) {
LAB_1402ec6fe:
      lVar8 = FUN_14018b280(0x208,0);
      if (lVar8 != 0) {
        uVar9 = FUN_14030d310(lVar8);
      }
      iVar6 = FUN_14030d6a0(uVar9,param_1,local_res10[0]);
      if (iVar6 < 0) {
        if (uVar9 != 0) {
          FUN_14030d400(uVar9);
          FUN_14018b900(uVar9,0);
        }
      }
      else {
        *param_3 = uVar9;
LAB_1402ec76f:
        iVar6 = 0;
      }
      pDVar4 = local_res20;
      if (*puVar10 < 2) {
        *local_res20 = 0;
        LOCK();
        *puVar10 = 0;
        UNLOCK();
        if (*(longlong *)(local_res20 + 4) != 0) {
          if (*(longlong *)(local_res20 + 6) == 0) {
            hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
            pDVar1 = pDVar4 + 6;
            LOCK();
            bVar11 = *(longlong *)pDVar1 == 0;
            if (bVar11) {
              *(HANDLE *)pDVar1 = hObject;
            }
            UNLOCK();
            if (!bVar11) {
              CloseHandle(hObject);
            }
          }
          SetEvent(*(HANDLE *)(pDVar4 + 6));
        }
      }
      else {
        *puVar10 = *puVar10 - 1;
      }
      return iVar6;
    }
    if ((uVar7 == *puVar3) &&
       (iVar6 = (**(code **)(param_1 + 0x58))(local_res10,puVar3 + 2), iVar6 != 0)) {
      if (puVar3 + 3 != (ulonglong *)0x0) {
        if (param_3 != (ulonglong *)0x0) {
          *param_3 = puVar3[3];
        }
        (*(code *)**(undefined8 **)*param_3)();
        goto LAB_1402ec76f;
      }
      goto LAB_1402ec6fe;
    }
    puVar3 = (ulonglong *)puVar3[1];
  } while( true );
}



==== FUN_1402ee1b0 @ 1402ee1b0 size 180 ====
CALLERS: FUN_1402edc50
CALLEES: FUN_14018b900

void FUN_1402ee1b0(longlong param_1)

{
  FUN_14018b900(*(undefined8 *)(param_1 + 0xa0),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0xa8),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x88),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x90),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x70),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x78),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x58),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x60),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x40),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x48),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x28),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x30),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x10),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x18),0);
  return;
}



==== FUN_1402ee350 @ 1402ee350 size 152 ====
CALLERS: FUN_1402ed360
CALLEES: FUN_14018b900

void FUN_1402ee350(longlong param_1)

{
  FUN_14018b900(*(undefined8 *)(param_1 + 0x88),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x90),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x70),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x78),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x58),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x60),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x40),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x48),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x28),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x30),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x10),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x18),0);
  return;
}



==== FUN_1402eedd0 @ 1402eedd0 size 498 ====
CALLERS: FUN_1402edf20
CALLEES: FUN_14018b900

void FUN_1402eedd0(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_14018b900(*(undefined8 *)(param_1 + 0x488),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x490),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x470),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x478),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x458),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x460),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x440),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x448),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x420),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x428),0);
  iVar5 = 4;
  puVar2 = (undefined8 *)(param_1 + 0x3b8);
  iVar4 = 4;
  iVar3 = 4;
  do {
    puVar1 = puVar2 + -4;
    puVar2 = puVar2 + -3;
    FUN_14018b900(*puVar1,0);
    FUN_14018b900(*puVar2);
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  puVar2 = (undefined8 *)(param_1 + 0x340);
  do {
    puVar1 = puVar2 + -4;
    puVar2 = puVar2 + -3;
    FUN_14018b900(*puVar1,0);
    FUN_14018b900(*puVar2);
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  iVar4 = 4;
  iVar3 = 4;
  puVar2 = (undefined8 *)(param_1 + 0x2c0);
  do {
    puVar1 = puVar2 + -4;
    puVar2 = puVar2 + -3;
    FUN_14018b900(*puVar1,0);
    FUN_14018b900(*puVar2);
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  puVar2 = (undefined8 *)(param_1 + 0x248);
  do {
    puVar1 = puVar2 + -4;
    puVar2 = puVar2 + -3;
    FUN_14018b900(*puVar1,0);
    FUN_14018b900(*puVar2);
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  puVar2 = (undefined8 *)(param_1 + 0x1c8);
  do {
    puVar1 = puVar2 + -4;
    puVar2 = puVar2 + -3;
    FUN_14018b900(*puVar1,0);
    FUN_14018b900(*puVar2);
    iVar5 = iVar5 + -1;
  } while (-1 < iVar5);
  iVar3 = 9;
  puVar2 = (undefined8 *)(param_1 + 0x150);
  do {
    puVar1 = puVar2 + -4;
    puVar2 = puVar2 + -3;
    FUN_14018b900(*puVar1,0);
    FUN_14018b900(*puVar2);
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x38),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x40),0);
  FUN_14018b900(*(undefined8 *)(param_1 + 0x10),0);
  return;
}



==== FUN_1402efc30 @ 1402efc30 size 47 ====
CALLERS:
CALLEES:

void FUN_1402efc30(longlong param_1)

{
  (**(code **)(**(longlong **)(param_1 + 8) + 0x330))
            (*(longlong **)(param_1 + 8),*(undefined8 *)(param_1 + 0x20),
             *(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x30),
             *(undefined8 *)(param_1 + 0x38));
  return;
}



==== FUN_1402f00c0 @ 1402f00c0 size 99 ====
CALLERS:
CALLEES:

void FUN_1402f00c0(longlong param_1)

{
  if (*(int *)(param_1 + 0x24) == 1) {
    (**(code **)(**(longlong **)(param_1 + 8) + 0x1f0))
              (*(longlong **)(param_1 + 8),*(undefined4 *)(param_1 + 0x20),
               *(undefined8 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
    if (*(longlong **)(param_1 + 0x28) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(param_1 + 0x28) + 8))();
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
  }
  else if (*(int *)(param_1 + 0x24) == 2) {
                    /* WARNING: Could not recover jumptable at 0x0001402f00e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(longlong **)(param_1 + 8) + 0x1e8))
              (*(longlong **)(param_1 + 8),*(undefined4 *)(param_1 + 0x20),param_1 + 0x40);
    return;
  }
  return;
}



==== FUN_1402f1a60 @ 1402f1a60 size 95 ====
CALLERS: FUN_140300fd0
CALLEES:

void FUN_1402f1a60(longlong param_1,longlong param_2)

{
  uint uVar1;
  
  if (*(float *)(param_1 + 8) <= 0.0 && *(float *)(param_1 + 8) != 0.0) {
    if ((*(int *)(param_1 + 0x4c) != 0) &&
       (uVar1 = *(int *)(param_1 + 0x4c) - 1,
       *(uint *)(*(longlong *)(param_1 + 0x20) + 0xc) <=
       *(uint *)(*(longlong *)(param_2 + 0x298) + (ulonglong)uVar1 * 4))) {
      *(uint *)(param_1 + 0x4c) = uVar1;
      return;
    }
  }
  else {
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    if ((*(uint *)(param_1 + 0x4c) < *(uint *)(param_2 + 0x290)) &&
       (*(uint *)(*(longlong *)(param_2 + 0x298) + (ulonglong)*(uint *)(param_1 + 0x4c) * 4) <
        *(uint *)(*(longlong *)(param_1 + 0x20) + 0x10))) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x4c) = 0xffffffff;
  return;
}



==== FUN_1402f5550 @ 1402f5550 size 508 ====
CALLERS:
CALLEES: FUN_1402f9d70 FUN_1402f39e0

undefined8 FUN_1402f5550(longlong *param_1,undefined8 param_2,int param_3)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar9;
  
  uVar5 = *(uint *)(param_1 + 6);
  if (param_3 == 0) {
    if ((uVar5 & 0xfffffffb) == 0xb) {
      return 1;
    }
  }
  else if (uVar5 == 0xf) {
    return 1;
  }
  if ((uVar5 & 1) == 0) {
    uVar3 = (**(code **)(*param_1 + 0x578))(param_1);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) | 1;
    FUN_1402f39e0(param_1);
  }
  if ((*(byte *)(param_1 + 6) & 2) == 0) {
    if (((param_1[0x8b] != 0) && (*(int *)(param_1[8] + 0x2b8) != 0)) &&
       (uVar7 = 0, *(int *)(param_1[8] + 0x2b8) != 0)) {
      do {
        lVar8 = *(longlong *)(param_1[8] + 0x2c0) + uVar7 * 0x28;
        if (*(int *)(lVar8 + 0x18) != 0) {
          uVar6 = 0;
          plVar9 = (longlong *)(param_1[0x8d] + uVar7 * 0x28);
          if (*(int *)(lVar8 + 0x18) != 0) {
            do {
              plVar1 = (longlong *)*plVar9;
              if ((plVar1 != (longlong *)0x0) &&
                 (puVar4 = (ushort *)(uVar6 * 0x20 + *(longlong *)(lVar8 + 0x20)),
                 *(int *)(puVar4 + 4) != 0)) {
                (**(code **)(*plVar1 + 0x20))
                          (plVar1,plVar9[1] + uVar6 * 8,
                           *(undefined4 *)(param_1[0x8b] + (ulonglong)*puVar4 * 4),
                           *(undefined4 *)(param_1[0x8b] + (ulonglong)puVar4[1] * 4));
              }
              uVar5 = (int)uVar6 + 1;
              uVar6 = (ulonglong)uVar5;
            } while (uVar5 < *(uint *)(lVar8 + 0x18));
          }
        }
        uVar5 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar5;
      } while (uVar5 < *(uint *)(param_1[8] + 0x2b8));
    }
    *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) | 2;
  }
  if ((param_3 != 0) && ((*(byte *)(param_1 + 6) & 4) == 0)) {
    for (plVar9 = (longlong *)param_1[0x9a]; plVar9 != (longlong *)0x0;
        plVar9 = (longlong *)plVar9[0x9c]) {
      iVar2 = (**(code **)(*plVar9 + 0x10))(plVar9,param_2,param_3);
      if (iVar2 == 0) {
        return 0;
      }
    }
    *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) | 4;
  }
  if ((*(byte *)(param_1 + 6) & 8) == 0) {
    plVar9 = param_1 + 0x98;
    lVar8 = *plVar9;
    while ((lVar8 != 0 && ((int)param_1[0x96] == 0))) {
      param_1 = (longlong *)*plVar9;
      plVar9 = param_1 + 0x98;
      lVar8 = *plVar9;
    }
    FUN_1402f9d70(param_1);
  }
  return 1;
}



==== FUN_1402f5f80 @ 1402f5f80 size 41 ====
CALLERS:
CALLEES:

longlong FUN_1402f5f80(longlong *param_1)

{
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_18);
  return param_1[8];
}



==== FUN_1402f6c40 @ 1402f6c40 size 500 ====
CALLERS: FUN_1402f80c0 FUN_1402f6f70 FUN_1402f9480 FUN_1402f6fd0
CALLEES: __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_1402f6c40(longlong *param_1,int param_2,uint param_3)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  ulonglong uVar14;
  short *psVar15;
  short *psVar16;
  undefined1 auStack_e8 [32];
  undefined4 local_c8 [4];
  uint local_b8 [32];
  ulonglong local_38;
  
  local_38 = DAT_140c0f7b0 ^ (ulonglong)auStack_e8;
  local_c8[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_c8);
  uVar11 = 0;
  lVar6 = *(longlong *)(param_1[7] + 0xb8);
  uVar10 = 0;
  uVar9 = *(uint *)(lVar6 + 0x20);
  if (uVar9 != 0) {
    do {
      uVar7 = (uVar9 - uVar10 >> 1) + uVar10;
      uVar12 = (uint)*(ushort *)(*(longlong *)(lVar6 + 0x28) + (ulonglong)uVar7 * 2);
      if ((int)uVar12 <= param_2) {
        if (param_2 <= (int)uVar12) {
          uVar1 = *(ushort *)(*(longlong *)(lVar6 + 0x30) + (ulonglong)uVar7 * 2);
          goto LAB_1402f6cd9;
        }
        uVar10 = uVar7 + 1;
        uVar7 = uVar9;
      }
      uVar9 = uVar7;
    } while (uVar10 < uVar9);
  }
  uVar1 = *(ushort *)(lVar6 + 0x1c);
LAB_1402f6cd9:
  uVar12 = (uint)uVar1;
  uVar7 = 0;
  lVar6 = *(longlong *)(param_1[8] + 0x18);
  uVar9 = *(uint *)(param_1[8] + 0x10);
  psVar16 = (short *)((ulonglong)uVar12 * 0x70 + lVar6);
  sVar2 = *psVar16;
  psVar15 = psVar16;
  uVar10 = uVar12;
  if (uVar12 < uVar9) {
    do {
      if ((0x1f < uVar7) || (*psVar15 != sVar2)) break;
      uVar3 = *(uint *)(psVar15 + 0xc);
      uVar4 = *(uint *)(psVar15 + 0xe);
      if (uVar3 == uVar4) {
LAB_1402f6d48:
        uVar14 = (ulonglong)uVar7;
        uVar7 = uVar7 + 1;
        local_b8[uVar14] = uVar10;
      }
      else {
        uVar5 = *(uint *)(param_1[2] + 0x1f0);
        if (uVar3 < uVar4) {
          if ((uVar3 <= uVar5) && (uVar5 < uVar4)) goto LAB_1402f6d48;
        }
        else if ((uVar5 < uVar4) || (uVar3 <= uVar5)) goto LAB_1402f6d48;
      }
      uVar10 = uVar10 + 1;
      psVar15 = psVar15 + 0x38;
    } while (uVar10 < uVar9);
    if (uVar7 == 0) {
      if (uVar9 <= uVar12) {
        return local_b8[0];
      }
      do {
        if ((0x1f < uVar7) || (*psVar16 != sVar2)) break;
        uVar14 = (ulonglong)uVar7;
        psVar16 = psVar16 + 0x38;
        uVar7 = uVar7 + 1;
        local_b8[uVar14] = uVar12;
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar9);
    }
    if (1 < uVar7) {
      iVar8 = 0;
      if (uVar7 != 0) {
        puVar13 = local_b8;
        uVar14 = (ulonglong)uVar7;
        iVar8 = 0;
        do {
          uVar9 = *puVar13;
          puVar13 = puVar13 + 1;
          iVar8 = iVar8 + (uint)*(ushort *)((ulonglong)uVar9 * 0x70 + 8 + lVar6);
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      if (iVar8 == 0) {
        local_b8[0] = local_b8[(param_3 & 0xffff) * uVar7 >> 0x10];
      }
      else {
        uVar9 = iVar8 * (param_3 & 0xffff) >> 0x10;
        if (uVar7 != 0) {
          puVar13 = local_b8;
          do {
            uVar10 = (uint)*(ushort *)((ulonglong)*puVar13 * 0x70 + 8 + lVar6);
            if (uVar9 < uVar10) {
              return *puVar13;
            }
            uVar11 = uVar11 + 1;
            uVar9 = uVar9 - uVar10;
            puVar13 = puVar13 + 1;
          } while (uVar11 < uVar7);
        }
      }
    }
  }
  return local_b8[0];
}



==== FUN_1402f6e40 @ 1402f6e40 size 103 ====
CALLERS:
CALLEES: FUN_1402ea550

undefined8 FUN_1402f6e40(longlong *param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_18);
  lVar1 = *(longlong *)(param_1[7] + 0xb8);
  if (param_2 != 0x96) {
    uVar2 = FUN_1402ea550(lVar1,param_2);
    if (uVar2 == *(ushort *)(lVar1 + 0x1c)) {
      return 0;
    }
  }
  return 1;
}



==== FUN_1402f6eb0 @ 1402f6eb0 size 185 ====
CALLERS:
CALLEES:

undefined8 FUN_1402f6eb0(longlong *param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_18);
  uVar6 = 0;
  lVar2 = *(longlong *)(param_1[7] + 0xb8);
  uVar4 = *(uint *)(lVar2 + 0x20);
  if (uVar4 != 0) {
    do {
      uVar3 = (uVar4 - uVar6 >> 1) + uVar6;
      uVar5 = (uint)*(ushort *)(*(longlong *)(lVar2 + 0x28) + (ulonglong)uVar3 * 2);
      if ((int)uVar5 <= param_2) {
        if (param_2 <= (int)uVar5) {
          uVar1 = *(ushort *)(*(longlong *)(lVar2 + 0x30) + (ulonglong)uVar3 * 2);
          goto LAB_1402f6f19;
        }
        uVar6 = uVar3 + 1;
        uVar3 = uVar4;
      }
      uVar4 = uVar3;
    } while (uVar6 < uVar4);
  }
  uVar1 = *(ushort *)(lVar2 + 0x1c);
LAB_1402f6f19:
  uVar4 = uVar1 + 1;
  if ((uVar4 < *(uint *)(param_1[8] + 0x10)) &&
     (lVar2 = *(longlong *)(param_1[8] + 0x18),
     *(short *)((ulonglong)(uint)uVar1 * 0x70 + lVar2) ==
     *(short *)((ulonglong)uVar4 * 0x70 + lVar2))) {
    return 1;
  }
  return 0;
}



==== FUN_1402f6fd0 @ 1402f6fd0 size 247 ====
CALLERS:
CALLEES: FUN_1402f6c40

int FUN_1402f6fd0(longlong *param_1,undefined4 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  uint *puVar8;
  longlong lVar9;
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_18);
  uVar3 = FUN_1402f6c40(param_1,param_2);
  lVar2 = param_1[8];
  uVar7 = 0;
  uVar1 = *(uint *)(lVar2 + 0x290);
  lVar6 = (ulonglong)uVar3 * 0x70 + *(longlong *)(lVar2 + 0x18);
  uVar3 = uVar1;
  if (uVar1 != 0) {
    do {
      uVar4 = uVar3 + uVar7 >> 1;
      if (*(uint *)(*(longlong *)(lVar2 + 0x298) + (ulonglong)uVar4 * 4) < *(uint *)(lVar6 + 0xc)) {
        uVar7 = uVar4 + 1;
        uVar4 = uVar3;
      }
      uVar3 = uVar4;
    } while (uVar7 < uVar3);
  }
  if (uVar3 < uVar1) {
    lVar9 = (ulonglong)uVar3 * 2;
    puVar8 = (uint *)(*(longlong *)(lVar2 + 0x298) + (ulonglong)uVar3 * 4);
    do {
      if (*(uint *)(lVar6 + 0x10) <= *puVar8) {
        return -1;
      }
      uVar5 = (ulonglong)*(ushort *)(*(longlong *)(lVar2 + 0x2a0) + lVar9);
      if ((*(short *)(*(longlong *)(lVar2 + 0x288) + uVar5 * 8) == 0) &&
         (*(int *)(*(longlong *)(lVar2 + 0x288) + 4 + uVar5 * 8) == param_4)) {
        return *(int *)(*(longlong *)(lVar2 + 0x298) + (ulonglong)uVar3 * 4) - *(int *)(lVar6 + 0xc)
        ;
      }
      uVar3 = uVar3 + 1;
      puVar8 = puVar8 + 1;
      lVar9 = lVar9 + 2;
    } while (uVar3 < uVar1);
  }
  return -1;
}



==== FUN_1402f7850 @ 1402f7850 size 296 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_14018b900

void FUN_1402f7850(longlong *param_1,uint param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  iVar3 = (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
  if (iVar3 == 0) {
    puVar5 = (undefined8 *)FUN_14018b280(0x28,0);
    if (puVar5 != (undefined8 *)0x0) {
      *puVar5 = &PTR_FUN_140b64078;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[1] = param_1;
      param_1 = param_1 + 9;
      if (puVar5[2] == 0) {
        puVar5[2] = param_1;
        plVar1 = puVar5 + 3;
        *plVar1 = *param_1;
        *param_1 = (longlong)puVar5;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x10) = plVar1;
        }
      }
      *(uint *)(puVar5 + 4) = param_2;
      *puVar5 = &PTR_FUN_140b63fa8;
      return;
    }
  }
  else {
    if (param_2 == 0) {
      uVar4 = 0;
    }
    else if (param_2 < *(uint *)(param_1[8] + 400)) {
      uVar4 = (uint)*(ushort *)(*(longlong *)(param_1[8] + 0x198) + (longlong)(int)param_2 * 2);
    }
    else {
      uVar4 = 0xffffffff;
    }
    lVar2 = *(longlong *)(param_1[0x69] + 0x10 + (ulonglong)uVar4 * 0x160);
    if (lVar2 != 0) {
      if (*(longlong **)(lVar2 + 8) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(lVar2 + 8) + 8))();
      }
      FUN_14018b900(lVar2,0);
      *(undefined8 *)(param_1[0x69] + 0x10 + (ulonglong)uVar4 * 0x160) = 0;
      plVar1 = param_1 + 0x6b;
      *(int *)plVar1 = (int)*plVar1 + -1;
      if ((int)*plVar1 == 0) {
        *(int *)((longlong)param_1 + 0x134) = *(int *)((longlong)param_1 + 0x134) + -1;
      }
    }
  }
  return;
}



==== FUN_1402f7b20 @ 1402f7b20 size 339 ====
CALLERS:
CALLEES: FUN_14018b280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1402f7b20(longlong *param_1,uint param_2,float *param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 local_18 [4];
  
  puVar8 = (uint *)0x0;
  local_18[0] = 0;
  iVar4 = (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
  if (iVar4 == 0) {
    puVar5 = (undefined8 *)FUN_14018b280(0x40,0);
    if (puVar5 != (undefined8 *)0x0) {
      *puVar5 = &PTR_FUN_140b64078;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[1] = param_1;
      param_1 = param_1 + 9;
      if (puVar5[2] == 0) {
        puVar5[2] = param_1;
        plVar1 = puVar5 + 3;
        *plVar1 = *param_1;
        *param_1 = (longlong)puVar5;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x10) = plVar1;
        }
      }
      *(uint *)(puVar5 + 4) = param_2;
      *puVar5 = &PTR_FUN_140b63f98;
      uVar2 = *(undefined8 *)(param_3 + 2);
      puVar5[6] = *(undefined8 *)param_3;
      puVar5[7] = uVar2;
    }
  }
  else {
    uVar7 = 0;
    if (param_2 != 0) {
      if (param_2 < *(uint *)(param_1[8] + 400)) {
        uVar7 = (uint)*(ushort *)(*(longlong *)(param_1[8] + 0x198) + (longlong)(int)param_2 * 2);
      }
      else {
        uVar7 = 0xffffffff;
      }
    }
    if (uVar7 < *(uint *)(param_1[8] + 0x180)) {
      puVar6 = *(uint **)((ulonglong)uVar7 * 0x160 + 8 + param_1[0x69]);
      if (puVar6 == (uint *)0x0) {
        puVar6 = (uint *)FUN_14018b280(0x40);
        if (puVar6 != (uint *)0x0) {
          uVar2 = CONCAT44(_UNK_140b7b244,_DAT_140b7b240);
          uVar3 = CONCAT44(_UNK_140b7b24c,DAT_140b7b248);
          *puVar6 = 0;
          *(undefined8 *)(puVar6 + 4) = uVar2;
          *(undefined8 *)(puVar6 + 6) = uVar3;
          uVar2 = uRam0000000140c78458;
          *(undefined8 *)(puVar6 + 8) = _DAT_140c78450;
          *(undefined8 *)(puVar6 + 10) = uVar2;
          puVar6[0xc] = 0;
          puVar6[0xd] = 0;
          puVar6[0xe] = 0;
          puVar6[0xf] = 0;
          puVar8 = puVar6;
        }
        *(uint **)((ulonglong)uVar7 * 0x160 + 8 + param_1[0x69]) = puVar8;
        puVar6 = puVar8;
      }
      *puVar6 = *puVar6 | 1;
      fVar9 = param_3[1] + _UNK_140b7b244;
      fVar10 = param_3[2] + DAT_140b7b248;
      fVar11 = param_3[3] + _UNK_140b7b24c;
      puVar6[4] = (uint)(*param_3 + _DAT_140b7b240);
      puVar6[5] = (uint)fVar9;
      puVar6[6] = (uint)fVar10;
      puVar6[7] = (uint)fVar11;
    }
  }
  return;
}



==== FUN_1402f8810 @ 1402f8810 size 321 ====
CALLERS:
CALLEES:

void FUN_1402f8810(longlong *param_1,uint param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_28 [8];
  
  local_28[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x10))(param_1,local_28,0);
  uVar3 = DAT_140b79ed0;
  if ((((ulonglong)param_2 < (ulonglong)param_1[0x70]) &&
      (uVar1 = *(ulonglong *)(param_1[0x6f] + (ulonglong)param_2 * 8),
      uVar1 < (ulonglong)param_1[0x6e])) &&
     (puVar2 = *(undefined4 **)(*(longlong *)(param_1[0x6d] + uVar1 * 8) + 8),
     puVar2 != (undefined4 *)0x0)) {
    *param_3 = *puVar2;
    param_3[1] = puVar2[1];
    param_3[2] = puVar2[2];
    param_3[3] = puVar2[3];
    param_3[4] = puVar2[4];
    param_3[5] = puVar2[5];
    param_3[6] = puVar2[6];
    param_3[7] = puVar2[7];
    param_3[3] = (int)((float)(*(int *)(param_1[2] + 0xd0) - puVar2[0xc]) * (float)puVar2[2]) +
                 puVar2[3];
    return;
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = uVar3;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  return;
}



==== FUN_1402f8f70 @ 1402f8f70 size 296 ====
CALLERS:
CALLEES:

void FUN_1402f8f70(longlong *param_1,uint param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_28 [8];
  
  local_28[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x10))(param_1,local_28,0);
  uVar3 = DAT_140b79ed0;
  if ((((ulonglong)param_2 < (ulonglong)param_1[0x70]) &&
      (uVar1 = *(ulonglong *)(param_1[0x6f] + (ulonglong)param_2 * 8),
      uVar1 < (ulonglong)param_1[0x6e])) &&
     (puVar2 = *(undefined4 **)(*(longlong *)(param_1[0x6d] + uVar1 * 8) + 0x10),
     puVar2 != (undefined4 *)0x0)) {
    *param_3 = *puVar2;
    param_3[1] = puVar2[1];
    param_3[2] = puVar2[2];
    param_3[3] = puVar2[3];
    param_3[4] = puVar2[4];
    param_3[5] = puVar2[5];
    param_3[6] = puVar2[6];
    param_3[3] = (int)((float)(*(int *)(param_1[2] + 0xd0) - puVar2[0xd]) * (float)puVar2[2]) +
                 puVar2[3];
    return;
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = uVar3;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  return;
}



==== FUN_1402f9aa0 @ 1402f9aa0 size 226 ====
CALLERS:
CALLEES: FUN_14018b280

void FUN_1402f9aa0(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 local_18 [4];
  
  uVar6 = 0;
  local_18[0] = 0;
  iVar2 = (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
  if (iVar2 == 0) {
    puVar3 = (undefined8 *)FUN_14018b280(0x20,0);
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = &PTR_FUN_140b64078;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[1] = param_1;
      param_1 = param_1 + 9;
      if (puVar3[2] == 0) {
        puVar3[2] = param_1;
        plVar1 = puVar3 + 3;
        *plVar1 = *param_1;
        *param_1 = (longlong)puVar3;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x10) = plVar1;
        }
      }
      *puVar3 = &PTR_FUN_140b64048;
      return;
    }
  }
  else {
    lVar4 = param_1[8];
    if (*(int *)(lVar4 + 0x200) != 0) {
      do {
        if ((*(byte *)(*(longlong *)(lVar4 + 0x208) + 2 + uVar6 * 4) & 1) != 0) {
          (**(code **)(*param_1 + 0x2d8))
                    (param_1,*(undefined2 *)(*(longlong *)(lVar4 + 0x208) + uVar6 * 4),1);
        }
        lVar4 = param_1[8];
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < *(uint *)(lVar4 + 0x200));
    }
  }
  return;
}



==== FUN_1402f9d70 @ 1402f9d70 size 135 ====
CALLERS: FUN_1402f5550
CALLEES: FUN_1402f9e00 FUN_1402f9f10 FUN_1407e4830 __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1402f9d70(longlong param_1)

{
  undefined1 auStack_1d8 [32];
  undefined1 local_1b8 [416];
  ulonglong local_18;
  
  local_18 = DAT_140c0f7b0 ^ (ulonglong)auStack_1d8;
  if ((*(byte *)(param_1 + 0x30) & 8) == 0) {
    FUN_1407e4830(local_1b8,0,0x19c);
    FUN_1402f9e00(param_1,local_1b8,param_1 + 0x410);
    FUN_1402f9f10(param_1,local_1b8,param_1 + 0x410);
  }
  return;
}



==== FUN_1402faf90 @ 1402faf90 size 219 ====
CALLERS: FUN_1402f6600 FUN_1402f6670
CALLEES:

void FUN_1402faf90(longlong param_1,int param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
    lVar6 = *(longlong *)(param_1 + 0x40);
    uVar5 = 0;
    if (*(int *)(lVar6 + 0x2b8) != 0) {
      do {
        uVar4 = 0;
        lVar6 = *(longlong *)(lVar6 + 0x2c0) + uVar5 * 0x28;
        plVar1 = (longlong *)(*(longlong *)(param_1 + 0x468) + uVar5 * 0x28);
        if (*(int *)(lVar6 + 0x18) != 0) {
          do {
            plVar2 = *(longlong **)(plVar1[1] + uVar4 * 8);
            if ((plVar2 != (longlong *)0x0) && (*(char *)(plVar1[4] + uVar4 * 0x14) != '\0')) {
              *(undefined1 *)(plVar1[4] + uVar4 * 0x14) = 0;
              (**(code **)(*plVar2 + 0x48))();
            }
            uVar3 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar3;
          } while (uVar3 < *(uint *)(lVar6 + 0x18));
        }
        if (((longlong *)*plVar1 != (longlong *)0x0) && (param_2 == 0)) {
          (**(code **)(*(longlong *)*plVar1 + 0x30))();
        }
        lVar6 = *(longlong *)(param_1 + 0x40);
        uVar3 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar3;
      } while (uVar3 < *(uint *)(lVar6 + 0x2b8));
    }
  }
  return;
}



==== FUN_1402fb070 @ 1402fb070 size 115 ====
CALLERS:
CALLEES:

bool FUN_1402fb070(longlong *param_1,uint param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_18);
  lVar3 = 0;
  if (((param_2 != 0) && (lVar2 = param_1[8], param_2 < *(uint *)(lVar2 + 0x270))) &&
     (uVar1 = *(ushort *)(*(longlong *)(lVar2 + 0x278) + (longlong)(int)param_2 * 2),
     (uint)uVar1 < *(uint *)(lVar2 + 0x260))) {
    lVar3 = *(longlong *)(lVar2 + 0x268) + (ulonglong)uVar1 * 4;
  }
  return lVar3 != 0;
}



==== FUN_1402fb2a0 @ 1402fb2a0 size 103 ====
CALLERS:
CALLEES:

void FUN_1402fb2a0(longlong *param_1,undefined4 param_2,float *param_3)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float *pfVar17;
  undefined1 local_18 [16];
  
  lVar1 = param_1[2];
  pfVar17 = (float *)(**(code **)(*param_1 + 0x358))(param_1,local_18,param_2);
  fVar2 = *pfVar17;
  fVar3 = pfVar17[1];
  fVar4 = pfVar17[2];
  fVar5 = *(float *)(lVar1 + 0x144);
  fVar6 = *(float *)(lVar1 + 0x148);
  fVar7 = *(float *)(lVar1 + 0x14c);
  fVar8 = *(float *)(lVar1 + 0x134);
  fVar9 = *(float *)(lVar1 + 0x138);
  fVar10 = *(float *)(lVar1 + 0x13c);
  fVar11 = *(float *)(lVar1 + 0x154);
  fVar12 = *(float *)(lVar1 + 0x158);
  fVar13 = *(float *)(lVar1 + 0x15c);
  fVar14 = *(float *)(lVar1 + 0x164);
  fVar15 = *(float *)(lVar1 + 0x168);
  fVar16 = *(float *)(lVar1 + 0x16c);
  *param_3 = fVar3 * *(float *)(lVar1 + 0x140) + fVar2 * *(float *)(lVar1 + 0x130) +
             fVar4 * *(float *)(lVar1 + 0x150) + *(float *)(lVar1 + 0x160);
  param_3[1] = fVar3 * fVar5 + fVar2 * fVar8 + fVar4 * fVar11 + fVar14;
  param_3[2] = fVar3 * fVar6 + fVar2 * fVar9 + fVar4 * fVar12 + fVar15;
  param_3[3] = fVar3 * fVar7 + fVar2 * fVar10 + fVar4 * fVar13 + fVar16;
  return;
}



==== FUN_1402fb7e0 @ 1402fb7e0 size 557 ====
CALLERS:
CALLEES: FUN_1402f5df0 FUN_1402fb490

void FUN_1402fb7e0(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  ulonglong uVar6;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  
  iVar2 = (**(code **)(*param_1 + 0x3f0))();
  if (iVar2 == 0) {
    if ((longlong *)param_2[0x2b] != (longlong *)0x0) {
      *(longlong *)param_2[0x2b] = param_2[0x2c];
    }
    if (param_2[0x2c] != 0) {
      *(longlong *)(param_2[0x2c] + 0x158) = param_2[0x2b];
    }
    uVar6 = 0;
    param_2[0x2b] = 0;
    param_2[0x2c] = 0;
    if ((longlong *)param_2[0x2d] != (longlong *)0x0) {
      *(longlong *)param_2[0x2d] = param_2[0x2e];
    }
    if (param_2[0x2e] != 0) {
      *(longlong *)(param_2[0x2e] + 0x168) = param_2[0x2d];
    }
    param_2[0x2d] = 0;
    param_2[0x2e] = 0;
    (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x28]);
    local_18 = (undefined4)param_1[0x85];
    local_14 = *(undefined4 *)((longlong)param_1 + 0x42c);
    local_10 = *(float *)(param_1 + 0x86) * *(float *)((longlong)param_2 + 0x94);
    (**(code **)(*param_2 + 0xf0))(param_2,&local_18);
    *(undefined4 *)(param_2 + 0x96) = 0;
    param_2[0x97] = 0;
    param_2[0x98] = (longlong)param_1;
    param_2[0x99] = param_1[0x99];
    for (lVar3 = param_2[0x9a]; lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x4e0)) {
      lVar3 = FUN_1402fb490(lVar3,param_2[0x99]);
    }
    plVar4 = param_1 + 0x9a;
    if (param_2[0x9b] == 0) {
      param_2[0x9b] = (longlong)plVar4;
      plVar5 = param_2 + 0x9c;
      *plVar5 = *plVar4;
      *plVar4 = (longlong)param_2;
      if (*plVar5 != 0) {
        *(longlong **)(*plVar5 + 0x4d8) = plVar5;
      }
    }
    (**(code **)*param_2)(param_2);
    local_18 = 0;
    iVar2 = (**(code **)(*param_2 + 0x10))(param_2,&local_18,0);
    plVar4 = param_1;
    if ((iVar2 != 0) && (*(int *)(param_2[8] + 0x2f8) != 0)) {
      do {
        plVar5 = *(longlong **)(param_2[0xb2] + uVar6 * 8);
        (**(code **)(*plVar5 + 0x78))(plVar5,1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_2[8] + 0x2f8));
    }
    do {
      plVar5 = param_1;
      if ((*(uint *)(plVar4 + 6) & 4) == 0) break;
      *(uint *)(plVar4 + 6) = *(uint *)(plVar4 + 6) & 0xfffffffb;
      plVar1 = plVar4 + 0x98;
      plVar4 = (longlong *)*plVar1;
    } while ((longlong *)*plVar1 != (longlong *)0x0);
    do {
      if ((*(uint *)((longlong)plVar5 + 0x34) & 0x20) == 0) break;
      *(uint *)((longlong)plVar5 + 0x34) = *(uint *)((longlong)plVar5 + 0x34) & 0xffffffdf;
      plVar4 = plVar5 + 0x98;
      plVar5 = (longlong *)*plVar4;
    } while ((longlong *)*plVar4 != (longlong *)0x0);
    FUN_1402f5df0(param_1);
  }
  return;
}



==== FUN_1402fbb00 @ 1402fbb00 size 495 ====
CALLERS:
CALLEES: FUN_1402f5df0 FUN_1402fb490 FUN_1402f6470

void FUN_1402fbb00(longlong *param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 local_18 [4];
  
  if ((param_1[0x98] != 0) &&
     ((iVar5 = (**(code **)(*param_1 + 0x3f0))(), iVar5 == 0 ||
      (iVar5 = (**(code **)(*(longlong *)param_1[0x98] + 0x3f0))(), iVar5 == 0)))) {
    FUN_1402f5df0(param_1);
    uVar7 = 0;
    lVar6 = *(longlong *)(param_1[0x99] + 0x4c8);
    if (*(int *)(lVar6 + 0x720) != 0) {
      *(undefined4 *)(lVar6 + 0x720) = 0;
      for (lVar6 = *(longlong *)(lVar6 + 0x4d0); lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x4e0)) {
        lVar6 = FUN_1402f6470(lVar6,0);
      }
    }
    for (lVar6 = param_1[0x98]; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x4c0)) {
      lVar2 = *(longlong *)(lVar6 + 0x4d0);
      uVar4 = (uint)(*(int *)(lVar6 + 0x358) != 0);
      while (lVar2 != 0) {
        puVar1 = (uint *)(lVar2 + 0x134);
        lVar2 = *(longlong *)(lVar2 + 0x4e0);
        if (uVar4 <= *puVar1) {
          uVar4 = *puVar1;
        }
      }
      if (*(uint *)(lVar6 + 0x134) == uVar4) break;
      *(uint *)(lVar6 + 0x134) = uVar4;
    }
    lVar6 = param_1[0x9a];
    *(undefined4 *)(param_1 + 0x96) = 0;
    param_1[0x97] = 0;
    param_1[0x98] = 0;
    param_1[0x99] = (longlong)param_1;
    for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x4e0)) {
      lVar6 = FUN_1402fb490(lVar6,param_1[0x99]);
    }
    local_18[0] = 0;
    iVar5 = (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
    if ((iVar5 != 0) && (*(int *)(param_1[8] + 0x2f8) != 0)) {
      do {
        plVar3 = *(longlong **)(param_1[0xb2] + uVar7 * 8);
        (**(code **)(*plVar3 + 0x78))(plVar3,1);
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(param_1[8] + 0x2f8));
    }
    if ((longlong *)param_1[0x9b] != (longlong *)0x0) {
      *(longlong *)param_1[0x9b] = param_1[0x9c];
    }
    if (param_1[0x9c] != 0) {
      *(longlong *)(param_1[0x9c] + 0x4d8) = param_1[0x9b];
    }
    param_1[0x9b] = 0;
    param_1[0x9c] = 0;
    (**(code **)(*param_1 + 8))(param_1);
  }
  return;
}



==== FUN_1402fc550 @ 1402fc550 size 867 ====
CALLERS:
CALLEES: FUN_1401afc20 FUN_140300dd0 FUN_1401afb10 __security_check_cookie FUN_1408fc950 FUN_1408fe3d0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1402fc550(longlong *param_1,uint param_2,float param_3,undefined4 *param_4,longlong *param_5,
             longlong param_6,longlong param_7,float *param_8)

{
  float fVar1;
  ushort uVar2;
  float fVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 auStack_158 [32];
  longlong local_138;
  undefined1 *local_130;
  undefined1 local_128 [64];
  longlong local_e8;
  undefined1 *local_e0;
  ulonglong local_98;
  
  local_98 = DAT_140c0f7b0 ^ (ulonglong)auStack_158;
  if ((param_2 != 0) && ((int)param_2 < 0x3d)) {
    local_138 = CONCAT44(local_138._4_4_,0xffffffff);
    (**(code **)(*param_1 + 0x10))(param_1,&local_138,0);
    lVar5 = param_1[8];
    if (param_2 < *(uint *)(lVar5 + 0x338)) {
      uVar2 = *(ushort *)(*(longlong *)(lVar5 + 0x340) + (longlong)(int)param_2 * 2);
      if ((uint)uVar2 < *(uint *)(lVar5 + 0x328)) {
        uVar4 = FUN_140300dd0(param_1,0xc);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        lVar6 = (ulonglong)uVar2 * 0x20 + param_1[0x5c];
        lVar5 = (ulonglong)(uint)uVar2 * 0x38 + *(longlong *)(param_1[8] + 0x330);
        if (param_5 != (longlong *)0x0) {
          local_138 = *(longlong *)(lVar5 + 0x2c);
          *param_5 = local_138;
        }
        if (param_6 != 0) {
          local_e8 = (ulonglong)*(ushort *)(lVar5 + 2) * 0x40 + param_1[0x67];
          FUN_1401afc20(&local_e8,local_128);
          local_138 = param_1[2] + 0xf0;
          local_130 = local_128;
          local_e8 = local_138;
          local_e0 = local_130;
          FUN_1401afb10(&local_e8,param_6);
        }
        if (param_7 != 0) {
          local_138 = (ulonglong)*(ushort *)(lVar5 + 2) * 0x40 + param_1[0x67];
          local_130 = (undefined1 *)(param_1[2] + 0x130);
          local_e8 = local_138;
          local_e0 = local_130;
          FUN_1401afb10(&local_e8,param_7);
        }
        if (*(int *)(lVar5 + 4) == 0) {
          if (param_8 != (float *)0x0) {
            fVar8 = *(float *)(lVar6 + 8) * DAT_140b79e48;
            fVar1 = *(float *)(lVar5 + 0x2c);
            fVar9 = *(float *)(lVar5 + 0x30);
            fVar7 = (float)FUN_1408fc950(fVar8);
            fVar8 = (float)FUN_1408fe3d0(fVar8);
            param_8[1] = 0.0;
            param_8[2] = 0.0;
            param_8[3] = 0.0;
            param_8[4] = 0.0;
            param_8[6] = 0.0;
            param_8[7] = 0.0;
            param_8[8] = 0.0;
            param_8[9] = 0.0;
            param_8[0xb] = -1.0;
            param_8[0xc] = 0.0;
            param_8[0xd] = 0.0;
            fVar9 = fVar9 / (fVar1 - fVar9);
            param_8[5] = fVar7 / fVar8;
            param_8[0xf] = 0.0;
            param_8[10] = fVar9;
            *param_8 = (fVar7 / fVar8) / param_3;
            param_8[0xe] = fVar9 * fVar1;
          }
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = *(undefined4 *)(lVar6 + 8);
            return 0;
          }
        }
        else {
          if (param_8 != (float *)0x0) {
            fVar1 = *(float *)(lVar5 + 0x28);
            fVar9 = *(float *)(lVar5 + 0x2c);
            fVar7 = *(float *)(lVar5 + 0x30);
            param_8[1] = 0.0;
            param_8[2] = 0.0;
            param_8[3] = 0.0;
            param_8[4] = 0.0;
            param_8[6] = 0.0;
            param_8[7] = 0.0;
            param_8[8] = 0.0;
            param_8[9] = 0.0;
            param_8[0xb] = 0.0;
            fVar3 = DAT_140b79f58;
            param_8[0xc] = 0.0;
            param_8[0xd] = 0.0;
            param_8[0xf] = 1.0;
            fVar8 = DAT_140b79ed0;
            *param_8 = fVar3 / (fVar1 / param_3);
            param_8[5] = fVar3 / fVar1;
            fVar8 = fVar8 / (fVar9 - fVar7);
            param_8[10] = fVar8;
            param_8[0xe] = fVar8 * fVar9;
          }
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = 0;
          }
        }
        return 0;
      }
    }
  }
  return 0x80004005;
}



==== FUN_1402fc980 @ 1402fc980 size 58 ====
CALLERS:
CALLEES: FUN_140300dd0

undefined4 FUN_1402fc980(longlong *param_1)

{
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
  FUN_140300dd0(param_1,4);
  return (int)param_1[0x62];
}



==== FUN_1402fc9c0 @ 1402fc9c0 size 130 ====
CALLERS:
CALLEES:

void FUN_1402fc9c0(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((((*(int *)(param_1 + 0x5a0) == 0) &&
       (*(undefined4 *)(param_1 + 0x5a0) = 1, *(longlong *)(param_1 + 0x590) != 0)) &&
      (*(int *)(param_1 + 0x5a4) != 0)) &&
     (uVar3 = 0, *(int *)(*(longlong *)(param_1 + 0x40) + 0x2f8) != 0)) {
    do {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x590) + uVar3 * 8);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x40))(plVar1,0xffffffff);
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(*(longlong *)(param_1 + 0x40) + 0x2f8));
  }
  return;
}



==== FUN_1402fca50 @ 1402fca50 size 179 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_1403129a0 FUN_1403272b0 FUN_140306300

void FUN_1402fca50(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if ((int)param_1[0xb4] != 0) {
    lVar1 = param_1[2];
    *(undefined4 *)(param_1 + 0xb4) = 0;
    iVar2 = (**(code **)(*param_1 + 0x480))();
    iVar2 = *(int *)(lVar1 + 0xd0) + iVar2;
    *(int *)((longlong)param_1 + 0x3f4) = iVar2;
    if (iVar2 == *(int *)(lVar1 + 0xd0)) {
      puVar3 = (undefined8 *)FUN_14018b280(0x40);
      if (puVar3 == (undefined8 *)0x0) {
        puVar3 = (undefined8 *)0x0;
      }
      else {
        FUN_1403272b0(puVar3,*(undefined4 *)((longlong)param_1 + 0x3f4),param_1,1);
        *puVar3 = &PTR_FUN_140b644d8;
      }
      FUN_1403129a0(param_1[2],puVar3);
      *(undefined4 *)(param_1 + 0x7e) = 1;
      return;
    }
    FUN_140306300(param_1);
  }
  return;
}



==== FUN_1402fcb10 @ 1402fcb10 size 130 ====
CALLERS:
CALLEES:

void FUN_1402fcb10(longlong param_1,int param_2)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((((*(int *)(param_1 + 0x5a4) != param_2) &&
       (*(int *)(param_1 + 0x5a4) = param_2, *(longlong *)(param_1 + 0x590) != 0)) &&
      (*(int *)(param_1 + 0x5a0) != 0)) &&
     ((param_2 != 0 && (uVar3 = 0, *(int *)(*(longlong *)(param_1 + 0x40) + 0x2f8) != 0)))) {
    do {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x590) + uVar3 * 8);
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x40))(plVar1,0xffffffff);
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(*(longlong *)(param_1 + 0x40) + 0x2f8));
  }
  return;
}



==== FUN_1402fcc50 @ 1402fcc50 size 122 ====
CALLERS:
CALLEES:

ulonglong FUN_1402fcc50(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = 0;
  if (*(longlong *)(param_1 + 0x590) == 0) {
    return 0;
  }
  uVar4 = uVar3;
  if (*(int *)(*(longlong *)(param_1 + 0x40) + 0x2f8) != 0) {
    do {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x590) + uVar3 * 8);
      if ((plVar1 != (longlong *)0x0) &&
         (uVar2 = (**(code **)(*plVar1 + 0x70))(), (uint)uVar4 < uVar2)) {
        uVar4 = (ulonglong)uVar2;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(*(longlong *)(param_1 + 0x40) + 0x2f8));
  }
  return uVar4;
}



==== FUN_1402fd120 @ 1402fd120 size 110 ====
CALLERS: FUN_1402fd190 FUN_1402fd210 FUN_1402fd270 FUN_1402fd1b0 FUN_1402fd2d0
CALLEES:

uint FUN_1402fd120(longlong *param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
  lVar1 = param_1[8];
  if (*(uint *)(lVar1 + 0x550) <= param_2) {
    return 0xffffffff;
  }
  uVar2 = (uint)*(ushort *)(*(longlong *)(lVar1 + 0x558) + (longlong)(int)param_2 * 2);
  if (*(uint *)(lVar1 + 0x540) <= uVar2) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



==== FUN_140300c70 @ 140300c70 size 347 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_14030e3b0

undefined8 FUN_140300c70(longlong *param_1,undefined4 param_2)

{
  longlong *plVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined4 local_18 [4];
  ulonglong uVar9;
  
  uVar9 = 0;
  uVar8 = 0;
  local_18[0] = 0;
  iVar5 = (**(code **)(*param_1 + 0x10))(param_1,local_18,0);
  if (iVar5 == 0) {
    puVar7 = (undefined8 *)FUN_14018b280(0x28,0);
    if (puVar7 != (undefined8 *)0x0) {
      *puVar7 = &PTR_FUN_140b64078;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[1] = param_1;
      param_1 = param_1 + 9;
      if (puVar7[2] == 0) {
        puVar7[2] = param_1;
        plVar1 = puVar7 + 3;
        *plVar1 = *param_1;
        *param_1 = (longlong)puVar7;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x10) = plVar1;
        }
      }
      *(undefined4 *)(puVar7 + 4) = param_2;
      *puVar7 = &PTR_FUN_140b63fe8;
    }
    return 0;
  }
  lVar4 = param_1[8];
  uVar3 = *(uint *)(lVar4 + 0x4a0);
  if (uVar3 != 0) {
    uVar6 = FUN_14030e3b0(param_1[7],param_2);
    uVar2 = *(ushort *)((ulonglong)uVar6 * 0x70 + *(longlong *)(lVar4 + 0x18));
    if (uVar3 != 0) {
      do {
        uVar8 = (uint)uVar9;
        if (uVar2 <= *(ushort *)(*(longlong *)(lVar4 + 0x4a8) + uVar9 * 4)) break;
        uVar8 = uVar8 + 1;
        uVar9 = (ulonglong)uVar8;
      } while (uVar8 < uVar3);
    }
    if ((uVar8 < uVar3) &&
       (*(ushort *)(*(longlong *)(lVar4 + 0x4a8) + (ulonglong)uVar8 * 4) == uVar2)) {
      uVar8 = (uint)*(ushort *)(*(longlong *)(lVar4 + 0x4a8) + (ulonglong)uVar8 * 4 + 2);
      if (uVar8 != *(uint *)(param_1 + 0x27)) {
        *(uint *)(param_1 + 0x27) = uVar8;
        return 1;
      }
    }
    else if ((int)param_1[0x27] != 0) {
      *(undefined4 *)(param_1 + 0x27) = 0;
      return 1;
    }
  }
  return 0;
}



==== FUN_140305fc0 @ 140305fc0 size 829 ====
CALLERS: FUN_140310730
CALLEES: FUN_14018b280 FUN_140308800 FUN_14018b900 FUN_1403129a0 FUN_1403272b0 FUN_1403088b0

undefined8 FUN_140305fc0(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  ulonglong uVar9;
  int iVar10;
  
  iVar10 = *(int *)(*(longlong *)(param_1 + 0x10) + 0xd0) + 0x7fffffff;
  uVar9 = 0;
  iVar8 = iVar10;
  if (*(longlong *)(param_1 + 0x370) != 0) {
    do {
      puVar3 = *(undefined4 **)(*(longlong *)(param_1 + 0x368) + uVar9 * 8);
      puVar4 = *(undefined4 **)(puVar3 + 2);
      if (((puVar4 != (undefined4 *)0x0) && (puVar4[0xb] == 0)) &&
         ((*(byte *)(puVar4 + 5) & 0x10) == 0)) {
        iVar1 = puVar4[0xd];
        if (*(int *)(*(longlong *)(param_1 + 0x10) + 0xd0) - iVar1 < 0) {
          if (0 < iVar8 - iVar1) {
            iVar8 = iVar1;
          }
        }
        else {
          puVar6 = (undefined8 *)FUN_14018b280(0x68);
          if (puVar6 == (undefined8 *)0x0) {
            puVar6 = (undefined8 *)0x0;
          }
          else {
            uVar2 = *puVar3;
            FUN_1403272b0(puVar6,puVar4[0xd],param_1,0);
            *puVar6 = &PTR_FUN_140b644c8;
            *(undefined4 *)(puVar6 + 0xc) = 0;
            *(undefined4 *)(puVar6 + 8) = uVar2;
            *(undefined4 *)((longlong)puVar6 + 0x44) = *puVar4;
            *(undefined4 *)(puVar6 + 9) = puVar4[1];
            *(undefined4 *)((longlong)puVar6 + 0x4c) = puVar4[2];
            *(undefined4 *)(puVar6 + 10) = puVar4[3];
            *(undefined4 *)((longlong)puVar6 + 0x54) = puVar4[4];
            *(undefined4 *)(puVar6 + 0xb) = puVar4[5];
            *(undefined4 *)((longlong)puVar6 + 0x5c) = puVar4[6];
            uVar2 = puVar4[7];
            *(undefined4 *)((longlong)puVar6 + 100) = 0;
            *(undefined4 *)(puVar6 + 0xc) = uVar2;
          }
          FUN_1403129a0(*(undefined8 *)(param_1 + 0x10),puVar6);
          puVar4[0xb] = 1;
          plVar5 = *(longlong **)(puVar3 + 6);
          while (plVar5 != (longlong *)0x0) {
            if ((longlong *)plVar5[1] != (longlong *)0x0) {
              *(longlong *)plVar5[1] = plVar5[2];
            }
            if (plVar5[2] != 0) {
              *(longlong *)(plVar5[2] + 8) = plVar5[1];
            }
            plVar5[1] = 0;
            plVar5[2] = 0;
            if ((longlong *)*plVar5 != (longlong *)0x0) {
              (**(code **)(*(longlong *)*plVar5 + 8))();
            }
            FUN_14018b900(plVar5,0);
            plVar5 = *(longlong **)(puVar3 + 6);
          }
        }
      }
      puVar4 = *(undefined4 **)(puVar3 + 4);
      if (((puVar4 != (undefined4 *)0x0) && (puVar4[0xc] == 0)) &&
         ((*(byte *)(puVar4 + 5) & 0x10) == 0)) {
        iVar1 = puVar4[0xe];
        if (*(int *)(*(longlong *)(param_1 + 0x10) + 0xd0) - iVar1 < 0) {
          if (0 < iVar8 - iVar1) {
            iVar8 = iVar1;
          }
        }
        else {
          puVar6 = (undefined8 *)FUN_14018b280(0x68);
          if (puVar6 == (undefined8 *)0x0) {
            puVar6 = (undefined8 *)0x0;
          }
          else {
            uVar2 = *puVar3;
            FUN_1403272b0(puVar6,puVar4[0xe],param_1,0);
            *puVar6 = &PTR_FUN_140b644b8;
            *(undefined4 *)(puVar6 + 8) = uVar2;
            *(undefined4 *)((longlong)puVar6 + 0x44) = *puVar4;
            *(undefined4 *)(puVar6 + 9) = puVar4[1];
            *(undefined4 *)((longlong)puVar6 + 0x4c) = puVar4[2];
            *(undefined4 *)(puVar6 + 10) = puVar4[3];
            *(undefined4 *)((longlong)puVar6 + 0x54) = puVar4[4];
            *(undefined4 *)(puVar6 + 0xb) = puVar4[5];
            uVar2 = puVar4[6];
            *(undefined4 *)(puVar6 + 0xc) = 0;
            *(undefined4 *)((longlong)puVar6 + 0x5c) = uVar2;
          }
          FUN_1403129a0(*(undefined8 *)(param_1 + 0x10),puVar6);
          puVar4[0xc] = 1;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(ulonglong *)(param_1 + 0x370));
  }
  puVar6 = (undefined8 *)0x0;
  if ((*(int *)(param_1 + 0x5a0) == 0) && (*(int *)(param_1 + 0x3f0) == 0)) {
    iVar1 = *(int *)(param_1 + 0x3f4);
    if (*(int *)(*(longlong *)(param_1 + 0x10) + 0xd0) - iVar1 < 0) {
      if (iVar8 != iVar1 && -1 < iVar8 - iVar1) {
        iVar8 = iVar1;
      }
    }
    else {
      puVar7 = (undefined8 *)FUN_14018b280(0x40);
      if (puVar7 != (undefined8 *)0x0) {
        FUN_1403272b0(puVar7,*(undefined4 *)(param_1 + 0x3f4),param_1,1);
        *puVar7 = &PTR_FUN_140b644d8;
        puVar6 = puVar7;
      }
      FUN_1403129a0(*(undefined8 *)(param_1 + 0x10),puVar6);
      *(undefined4 *)(param_1 + 0x3f0) = 1;
    }
  }
  if (iVar8 - iVar10 < 0) {
    *(int *)(param_1 + 0x178) = iVar8;
    FUN_140308800(*(longlong *)(param_1 + 0x10) + 0x208);
    return 0;
  }
  if (*(longlong *)(param_1 + 0x180) != 0) {
    FUN_1403088b0();
  }
  return 0;
}



==== FUN_140306300 @ 140306300 size 305 ====
CALLERS: FUN_1402f80c0 FUN_140300fd0 FUN_1402fca50 FUN_1402f8960
CALLEES: FUN_14019fb60 FUN_140308800 SetEvent CloseHandle CreateEventW GetCurrentThreadId

void FUN_140306300(longlong param_1,int param_2)

{
  longlong lVar1;
  DWORD DVar2;
  HANDLE hObject;
  ulonglong uVar3;
  bool bVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (param_2 - *(int *)(lVar1 + 0xd0) < 0) {
    param_2 = *(int *)(lVar1 + 0xd0);
  }
  if ((*(longlong *)(param_1 + 0x180) == 0) || (param_2 - *(int *)(param_1 + 0x178) < 0)) {
    DVar2 = GetCurrentThreadId();
    uVar3 = 0;
    if (*(DWORD *)(lVar1 + 0x68) == DVar2) {
      *(longlong *)(lVar1 + 0x70) = *(longlong *)(lVar1 + 0x70) + 1;
    }
    else {
      do {
        LOCK();
        bVar4 = *(longlong *)(lVar1 + 0x70) == 0;
        if (bVar4) {
          *(longlong *)(lVar1 + 0x70) = 1;
        }
        UNLOCK();
        if (bVar4) {
          *(DWORD *)(lVar1 + 0x68) = DVar2;
          goto LAB_140306396;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x400);
      FUN_14019fb60(lVar1 + 0x68);
    }
LAB_140306396:
    *(int *)(param_1 + 0x178) = param_2;
    FUN_140308800(*(longlong *)(param_1 + 0x10) + 0x208,param_1 + 0x180);
    if (*(ulonglong *)(lVar1 + 0x70) < 2) {
      *(undefined4 *)(lVar1 + 0x68) = 0;
      LOCK();
      *(undefined8 *)(lVar1 + 0x70) = 0;
      UNLOCK();
      if (*(longlong *)(lVar1 + 0x78) != 0) {
        if (*(longlong *)(lVar1 + 0x80) == 0) {
          hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          LOCK();
          bVar4 = *(longlong *)(lVar1 + 0x80) == 0;
          if (bVar4) {
            *(longlong *)(lVar1 + 0x80) = (longlong)hObject;
          }
          UNLOCK();
          if (!bVar4) {
            CloseHandle(hObject);
          }
        }
        SetEvent(*(HANDLE *)(lVar1 + 0x80));
      }
    }
    else {
      *(longlong *)(lVar1 + 0x70) = *(longlong *)(lVar1 + 0x70) + -1;
    }
  }
  return;
}



==== FUN_140306480 @ 140306480 size 68 ====
CALLERS:
CALLEES:

undefined2 FUN_140306480(longlong *param_1,longlong param_2)

{
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x578))(param_1,local_18);
  return *(undefined2 *)(*(longlong *)(param_1[8] + 0x590) + param_2 * 0x20);
}



==== FUN_1403098c0 @ 1403098c0 size 694 ====
CALLERS: FUN_140307c90
CALLEES: FUN_1401b1980 FUN_1401c9940

void FUN_1403098c0(uint *param_1,uint param_2,float *param_3,undefined8 param_4,uint *param_5)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  float fVar9;
  undefined8 local_res20;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float local_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  
  uVar5 = *param_1;
  local_res20 = param_4;
  if (uVar5 == 0) {
    if ((DAT_140dc0de0 & 1) == 0) {
      DAT_140dc0de0 = DAT_140dc0de0 | 1;
    }
    FUN_1401c9940(&local_res20);
    puVar1 = &local_res20;
  }
  else {
    if (uVar5 != 1) {
      if (param_5 == (uint *)0x0) {
        param_5 = (uint *)&local_res20;
      }
      else {
        uVar4 = *param_5;
        uVar5 = *(uint *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar4 * 4);
        if (uVar5 <= param_2) {
          uVar3 = *(uint *)(*(longlong *)(param_1 + 2) + (ulonglong)(uVar4 + 1) * 4);
          if (param_2 < uVar3) {
            lVar7 = *(longlong *)(param_1 + 4);
            FUN_1401b1980(&local_38,lVar7 + (ulonglong)(uVar4 + 1) * 8);
            FUN_1401b1980(&local_48,lVar7 + (ulonglong)uVar4 * 8);
            fVar9 = (float)(param_2 - uVar5) / (float)(uVar3 - uVar5);
            *param_3 = fVar9 * (local_38 - local_48) + local_48;
            param_3[1] = fVar9 * (fStack_34 - fStack_44) + fStack_44;
            param_3[2] = fVar9 * (fStack_30 - fStack_40) + fStack_40;
            param_3[3] = fVar9 * (fStack_2c - fStack_3c) + fStack_3c;
            return;
          }
        }
        uVar3 = uVar4 + 1;
        uVar2 = (ulonglong)uVar3;
        *param_5 = uVar3;
        uVar5 = *param_1;
        if (((uVar3 < uVar5 - 1) &&
            (lVar7 = *(longlong *)(param_1 + 2), *(uint *)(lVar7 + uVar2 * 4) <= param_2)) &&
           (param_2 < *(uint *)(lVar7 + (ulonglong)(uVar4 + 2) * 4))) {
          lVar6 = *(longlong *)(param_1 + 4);
          FUN_1401b1980(&local_48,lVar6 + (ulonglong)(uVar4 + 2) * 8);
          FUN_1401b1980(&local_38,lVar6 + uVar2 * 8);
          fVar9 = (float)(param_2 - *(int *)(lVar7 + uVar2 * 4)) /
                  (float)(uint)(*(int *)(lVar7 + (ulonglong)(uVar4 + 2) * 4) -
                               *(int *)(lVar7 + uVar2 * 4));
          *param_3 = fVar9 * (local_48 - local_38) + local_38;
          param_3[1] = fVar9 * (fStack_44 - fStack_34) + fStack_34;
          param_3[2] = fVar9 * (fStack_40 - fStack_30) + fStack_30;
          param_3[3] = fVar9 * (fStack_3c - fStack_2c) + fStack_2c;
          return;
        }
      }
      uVar2 = 0;
      if (uVar5 != 0) {
        uVar4 = uVar5;
        do {
          uVar3 = (uVar4 - (int)uVar2 >> 1) + (int)uVar2;
          if (*(uint *)(*(longlong *)(param_1 + 2) + (ulonglong)uVar3 * 4) <= param_2) {
            uVar2 = (ulonglong)(uVar3 + 1);
            uVar3 = uVar4;
          }
          uVar4 = uVar3;
        } while ((uint)uVar2 < uVar4);
      }
      uVar4 = (uint)uVar2;
      uVar8 = (ulonglong)(uVar4 - 1);
      if (uVar4 == 0) {
        FUN_1401b1980(&local_38,*(undefined8 *)(param_1 + 4));
        *(ulonglong *)param_3 = CONCAT44(fStack_34,local_38);
        *(ulonglong *)(param_3 + 2) = CONCAT44(fStack_2c,fStack_30);
        *param_5 = 0;
      }
      else if (uVar5 == uVar4) {
        FUN_1401b1980(&local_38,*(longlong *)(param_1 + 4) + uVar8 * 8);
        *(ulonglong *)param_3 = CONCAT44(fStack_34,local_38);
        *(ulonglong *)(param_3 + 2) = CONCAT44(fStack_2c,fStack_30);
        *param_5 = *param_1 - 2;
      }
      else {
        lVar7 = *(longlong *)(param_1 + 4);
        FUN_1401b1980(&local_48,lVar7 + uVar2 * 8);
        FUN_1401b1980(&local_38,lVar7 + uVar8 * 8);
        lVar7 = *(longlong *)(param_1 + 2);
        fVar9 = (float)(param_2 - *(int *)(lVar7 + uVar8 * 4)) /
                (float)(uint)(*(int *)(lVar7 + uVar2 * 4) - *(int *)(lVar7 + uVar8 * 4));
        *param_3 = fVar9 * (local_48 - local_38) + local_38;
        param_3[1] = fVar9 * (fStack_44 - fStack_34) + fStack_34;
        param_3[2] = fVar9 * (fStack_40 - fStack_30) + fStack_30;
        param_3[3] = fVar9 * (fStack_3c - fStack_2c) + fStack_2c;
        *param_5 = uVar4 - 1;
      }
      return;
    }
    puVar1 = *(undefined8 **)(param_1 + 4);
  }
  FUN_1401b1980(&local_48,puVar1);
  *(ulonglong *)param_3 = CONCAT44(fStack_44,local_48);
  *(ulonglong *)(param_3 + 2) = CONCAT44(fStack_3c,fStack_40);
  return;
}



==== FUN_14030c3d0 @ 14030c3d0 size 713 ====
CALLERS: FUN_14030c6a0
CALLEES: FUN_14030ebf0 FUN_1402ca3c0 FUN_14030ed20 FUN_14030eb90

undefined8 FUN_14030c3d0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = *(longlong *)(param_3 + 0x10) + param_2;
  if ((uVar6 < *param_1) ||
     (param_1[1] < *(longlong *)(param_3 + 0x10) + (ulonglong)*(uint *)(param_3 + 8) * 0xc + param_2
     )) {
    return 0x80004005;
  }
  uVar3 = 0;
  if (*(uint *)(param_3 + 8) != 0) {
    uVar3 = uVar6;
  }
  *(ulonglong *)(param_3 + 0x10) = uVar3;
  uVar2 = FUN_14030ebf0(param_1,param_2,param_3 + 0x30);
  if (-1 < (int)uVar2) {
    uVar6 = 0;
    do {
      uVar3 = 0;
      do {
        uVar2 = FUN_1402ca3c0(param_1,param_2,param_3 + ((uVar3 + uVar6 * 5) * 3 + 10) * 8);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        uVar5 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar5;
      } while (uVar5 < 5);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 2);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + uVar6 * 0x18 + 0x140);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + uVar6 * 0x18 + 0x1c0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + (uVar6 * 3 + 0x47) * 8);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar5 = 0;
    puVar4 = (ulonglong *)(param_3 + 0x2c8);
    do {
      uVar6 = puVar4[-1] + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      uVar1 = (uint)puVar4[-2];
      if (param_1[1] < puVar4[-1] + (ulonglong)uVar1 * 4 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      puVar4[-1] = uVar3;
      uVar6 = *puVar4 + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *puVar4 + (ulonglong)uVar1 * 2 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      uVar5 = uVar5 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 3;
    } while (uVar5 < 5);
    uVar5 = 0;
    puVar4 = (ulonglong *)(param_3 + 0x340);
    do {
      uVar6 = puVar4[-1] + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      uVar1 = (uint)puVar4[-2];
      if (param_1[1] < puVar4[-1] + (ulonglong)uVar1 * 4 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      puVar4[-1] = uVar3;
      uVar6 = *puVar4 + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *puVar4 + (ulonglong)uVar1 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      uVar5 = uVar5 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 3;
    } while (uVar5 < 5);
    uVar2 = FUN_14030ed20(param_1,param_2,param_3 + 0x418);
    if ((((-1 < (int)uVar2) && (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)) &&
        (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)) &&
       ((uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2 &&
        (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)))) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



==== FUN_14030c6a0 @ 14030c6a0 size 294 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ed20 FUN_14030c3d0 FUN_14030eb90 FUN_14030bcc0

undefined8 FUN_14030c6a0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = param_2;
  uVar2 = FUN_14030ed20(param_1,param_2,param_3 + 0x38);
  if (-1 < (int)uVar2) {
    uVar2 = FUN_14030eb90(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (*(longlong *)(param_3 + 0x90) == -1) {
      *(undefined8 *)(param_3 + 0x90) = 0;
    }
    else {
      uVar1 = *(longlong *)(param_3 + 0x90) + lVar3;
      if (uVar1 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < uVar1 + 0xed0) {
        return 0x80004005;
      }
      *(ulonglong *)(param_3 + 0x90) = uVar1;
      uVar2 = FUN_14030bcc0(param_1,uVar1 + 0xed0,param_1[2] + uVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    if (*(longlong *)(param_3 + 0x98) == -1) {
      *(undefined8 *)(param_3 + 0x98) = 0;
    }
    else {
      uVar1 = *(longlong *)(param_3 + 0x98) + param_2;
      if ((uVar1 < *param_1) || (param_1[1] < uVar1 + 0x4a8)) {
        return 0x80004005;
      }
      *(ulonglong *)(param_3 + 0x98) = uVar1;
      uVar2 = FUN_14030c3d0(param_1,uVar1 + 0x4b0,param_1[2] + uVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



==== FUN_14030c7d0 @ 14030c7d0 size 351 ====
CALLERS: FUN_14030cac0
CALLEES: FUN_14030ed20 FUN_1402ca3c0

undefined8 FUN_14030c7d0(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x10);
  if (-1 < (int)uVar1) {
    uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x28);
    if (-1 < (int)uVar1) {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x40);
      if (-1 < (int)uVar1) {
        uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + 0x58);
        if (-1 < (int)uVar1) {
          uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + 0x70);
          if (-1 < (int)uVar1) {
            uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x88);
            if (-1 < (int)uVar1) {
              uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xa0);
              if (-1 < (int)uVar1) {
                uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xb8);
                if (-1 < (int)uVar1) {
                  uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xd0);
                  if (-1 < (int)uVar1) {
                    uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0xe8);
                    if (-1 < (int)uVar1) {
                      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x100);
                      if (-1 < (int)uVar1) {
                        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x118);
                        if (-1 < (int)uVar1) {
                          uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x130);
                          if (-1 < (int)uVar1) {
                            uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x148);
                            if (-1 < (int)uVar1) {
                              uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x160);
                              if (-1 < (int)uVar1) {
                                uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x178);
                                if (-1 < (int)uVar1) {
                                  uVar1 = 0;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar1;
}



==== FUN_14030e510 @ 14030e510 size 384 ====
CALLERS: FUN_14030dbb0 FUN_1403258c0 FUN_140326800
CALLEES:

int FUN_14030e510(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int local_res8;
  
  iVar6 = *(ushort *)(param_2 + 0x14) - 1;
  uVar9 = (uint)(*(short *)(param_2 + 0x30) != -1);
  uVar10 = (uint)(*(short *)(param_2 + 0x32) != -1);
  uVar5 = (uint)(*(short *)(param_2 + 0x34) != -1);
  uVar4 = (ulonglong)*(ushort *)(param_2 + 0x16);
  uVar8 = (uint)(*(short *)(param_2 + 0x36) != -1);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x1f8);
  uVar1 = *(uint *)(lVar3 + 0x20 + uVar4 * 0x30);
  if ((uVar1 != 0) && (*(int *)(*(longlong *)(lVar3 + 0x28 + uVar4 * 0x30) + 0x120) != 3)) {
    uVar9 = 1;
  }
  if ((1 < uVar1) && (*(int *)(*(longlong *)(lVar3 + 0x28 + uVar4 * 0x30) + 0x248) != 3)) {
    uVar10 = 1;
  }
  if ((2 < uVar1) && (*(int *)(*(longlong *)(lVar3 + 0x28 + uVar4 * 0x30) + 0x370) != 3)) {
    uVar5 = 1;
  }
  if ((3 < uVar1) && (*(int *)(*(longlong *)(lVar3 + 0x28 + uVar4 * 0x30) + 0x498) != 3)) {
    uVar8 = 1;
  }
  iVar2 = *(int *)(param_1 + 0xa8);
  iVar7 = 2;
  if (((iVar2 != 9) && (iVar7 = 1, iVar2 != 8)) && (iVar7 = local_res8, iVar2 == 7)) {
    iVar7 = 0;
  }
  if (*(int *)(lVar3 + 8 + uVar4 * 0x30) == 1) {
    iVar6 = iVar6 + iVar7 * 4;
  }
  else {
    iVar6 = uVar8 + (uVar5 + (uVar10 + (uVar9 + (((uint)(*(short *)(param_2 + 0x2c) == 2) +
                                                 ((uint)(*(short *)(param_2 + 0x2a) == 2) +
                                                 ((uint)(*(short *)(param_2 + 0x28) == 2) +
                                                 (iVar7 * 0x10 + iVar6) * 2) * 2) * 2) * 2 +
                                                (uint)(*(short *)(param_2 + 0x2e) == 2)) * 2) * 2) *
                             2) * 2;
  }
  return iVar6;
}



==== FUN_140312840 @ 140312840 size 350 ====
CALLERS: FUN_1403283c0 FUN_14032c620 FUN_14032abb0
CALLEES:

void FUN_140312840(longlong param_1,int param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  (**(code **)(*DAT_140c65670 + 0x128))();
  if ((*(uint *)(param_1 + 0x570) & 4) == 0) {
    if ((*(uint *)(param_1 + 0x570) >> 9 & 1) == 0) {
      (**(code **)(*DAT_140c65688 + 0x50))();
    }
    else {
      (**(code **)(*DAT_140c65670 + 0x120))();
      if (param_2 == 1) {
        (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,4,5,0);
      }
    }
  }
  else {
    (**(code **)(*DAT_140c65670 + 0x120))();
    (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,1,3);
  }
  uVar1 = *(uint *)(param_1 + 0x570);
  if ((uVar1 & 0x20) != 0) {
    if ((uVar1 & 8) == 0) {
      if ((uVar1 & 0x40) == 0) goto LAB_140312978;
      (**(code **)(*DAT_140c65670 + 0x1a0))(DAT_140c65670,1);
      (**(code **)(*DAT_140c65670 + 0x1a8))(DAT_140c65670,0,1);
      uVar2 = 2;
    }
    else {
      (**(code **)(*DAT_140c65670 + 0x1a0))(DAT_140c65670,1);
      (**(code **)(*DAT_140c65670 + 0x1a8))(DAT_140c65670,0,1);
      uVar2 = 0;
    }
    (**(code **)(*DAT_140c65670 + 0x1b0))(DAT_140c65670,0,0,uVar2,2);
  }
LAB_140312978:
  if ((*(byte *)(param_1 + 0x570) & 0x10) != 0) {
    (**(code **)(*DAT_140c65670 + 0x158))(DAT_140c65670,0);
  }
  return;
}



==== FUN_140313b30 @ 140313b30 size 238 ====
CALLERS: FUN_1403133c0 FUN_140313c20
CALLEES: FUN_1403131d0 FUN_140313290

void FUN_140313b30(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x4c0) != 0) {
    FUN_140313290();
  }
  *(undefined8 *)(param_1 + 0x4c0) = 0;
  if (*(longlong *)(param_1 + 0x4e0) != 0) {
    FUN_140313290();
  }
  *(undefined8 *)(param_1 + 0x4e0) = 0;
  if (*(longlong *)(param_1 + 0x498) != 0) {
    FUN_1403131d0();
  }
  *(undefined8 *)(param_1 + 0x498) = 0;
  *(undefined8 *)(param_1 + 0x4a0) = 0;
  *(undefined8 *)(param_1 + 0x4a8) = 0;
  *(undefined8 *)(param_1 + 0x4b0) = 0;
  *(undefined8 *)(param_1 + 0x4b8) = 0;
  *(undefined8 *)(param_1 + 0x4c8) = 0;
  *(undefined8 *)(param_1 + 0x4d0) = 0;
  *(undefined8 *)(param_1 + 0x4d8) = 0;
  *(undefined8 *)(param_1 + 0x4e8) = 0;
  *(undefined8 *)(param_1 + 0x4f0) = 0;
  *(undefined8 *)(param_1 + 0x4f8) = 0;
  *(undefined8 *)(param_1 + 0x500) = 0;
  *(undefined8 *)(param_1 + 0x508) = 0;
  *(undefined8 *)(param_1 + 0x510) = 0;
  *(undefined8 *)(param_1 + 0x518) = 0;
  *(undefined8 *)(param_1 + 0x520) = 0;
  *(undefined8 *)(param_1 + 0x528) = 0;
  *(undefined8 *)(param_1 + 0x530) = 0;
  *(undefined8 *)(param_1 + 0x538) = 0;
  *(undefined8 *)(param_1 + 0x540) = 0;
  *(undefined8 *)(param_1 + 0x548) = 0;
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



==== FUN_14031a8b0 @ 14031a8b0 size 479 ====
CALLERS: FUN_14031b080
CALLEES: FUN_140317ec0 FUN_1403180d0 FUN_1403181e0 FUN_140317fc0

void FUN_14031a8b0(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (*(char *)(param_1 + 400) == '\0') {
    uVar1 = 0;
    uVar3 = uVar1;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x4f8) != 0) {
      do {
        FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0x500 + uVar3 * 0x18,
                      param_1 + 0x458 + uVar3 * 0x10,param_1 + 0x180);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0x578 + uVar3 * 0x18,
                      param_1 + 0x4a8 + uVar3 * 0x10,param_1 + 0x180);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x4f8));
    }
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x5f0) != 0) {
      do {
        FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0x5f8 + uVar1 * 0x18,
                      param_1 + 0x4f8 + uVar1 * 0x10,param_1 + 0x180);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0x670 + uVar1 * 0x18,
                      param_1 + 0x548 + uVar1 * 0x10,param_1 + 0x180);
        uVar2 = (int)uVar1 + 1;
        uVar1 = (ulonglong)uVar2;
      } while (uVar2 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x5f0));
    }
    FUN_140317ec0(*(longlong *)(param_1 + 8) + 0x38,param_1 + 0x60,param_1 + 0x180);
    FUN_1403180d0(*(longlong *)(param_1 + 0x1a0) + 0x188,param_1 + 0x2d0,param_1 + 0x180);
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 2) != 0) {
      FUN_1403181e0(*(longlong *)(param_1 + 0x1a0) + 0x278,param_1 + 0x370,param_1 + 0x180);
    }
    *(undefined1 *)(param_1 + 400) = 1;
  }
  return;
}



==== FUN_14031ce90 @ 14031ce90 size 492 ====
CALLERS: FUN_1402f39e0
CALLEES: FUN_1407e4830 FUN_14032f450

undefined8 * FUN_14031ce90(undefined8 *param_1)

{
  FUN_14032f450();
  *param_1 = &PTR_LAB_140b643c0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  FUN_1407e4830(param_1 + 0x38,0,0x140);
  FUN_1407e4830(param_1 + 0x60,0,0x50);
  FUN_1407e4830(param_1 + 0x6a,0,0x50);
  FUN_1407e4830(param_1 + 0x74,0,0x50);
  FUN_1407e4830(param_1 + 0x7e,0,0x50);
  FUN_1407e4830(param_1 + 0x88,0,0x50);
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  *(undefined4 *)(param_1 + 0x9c) = 1;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  *(undefined4 *)(param_1 + 0xa6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x544) = 0;
  *(undefined4 *)((longlong)param_1 + 0x54c) = 0;
  *(undefined4 *)((longlong)param_1 + 0x53c) = *(undefined4 *)(param_1 + 0xa7);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0xa7);
  *(undefined4 *)((longlong)param_1 + 0x55c) = 0;
  param_1[0xad] = 0;
  param_1[0xac] = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb8] = 0;
  *(undefined4 *)(param_1 + 0xb9) = 0;
  param_1[0xbb] = 0;
  param_1[0xba] = 0;
  param_1[0xbd] = 0;
  param_1[0xbc] = 0;
  param_1[0xc5] = 0;
  param_1[0xc4] = 0;
  param_1[199] = 0;
  param_1[0xc6] = 0;
  param_1[0xc9] = 0;
  param_1[200] = 0;
  param_1[0xcb] = 0;
  param_1[0xca] = 0;
  param_1[0xcd] = 0;
  param_1[0xcc] = 0;
  param_1[0xd4] = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xa7) = 0;
  return param_1;
}



==== FUN_14031d490 @ 14031d490 size 2561 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_140052360 FUN_14031e170 FUN_14032f6f0 FUN_14032f8b0 FUN_14031e520 FUN_1402626b0

undefined8 FUN_14031d490(longlong param_1,undefined8 param_2,longlong param_3)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  undefined2 uVar6;
  char *pcVar7;
  longlong lVar8;
  undefined1 auVar9 [16];
  undefined4 uVar10;
  undefined4 uVar11;
  float fVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  uint uVar18;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  ulonglong uVar22;
  uint uVar23;
  longlong lVar24;
  longlong lVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  undefined8 in_stack_ffffffffffffff78;
  longlong *plVar30;
  longlong local_68 [10];
  
  *(undefined8 *)(param_1 + 0x4e8) = *(undefined8 *)(param_3 + 0x98);
  uVar15 = FUN_14032f6f0();
  if ((int)uVar15 < 0) {
    return uVar15;
  }
  uVar17 = 0;
  uVar20 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0xd0);
  *(undefined4 *)(param_1 + 0x544) = 0;
  *(undefined4 *)(param_1 + 0x580) = uVar20;
  *(undefined4 *)(param_1 + 0x538) = uVar20;
  iVar19 = *(int *)(*(longlong *)(param_1 + 8) + 0x1c);
  uVar20 = 4;
  uVar23 = 1;
  uVar22 = 1;
  if (iVar19 == 0) {
    *(undefined4 *)(param_1 + 0x54c) = 1;
    *(undefined8 *)(param_1 + 0x554) = 5;
  }
  else {
    if (iVar19 == 1) {
      *(undefined4 *)(param_1 + 0x54c) = 0;
      *(undefined8 *)(param_1 + 0x550) = 8;
      *(undefined4 *)(param_1 + 0x558) = 0;
      goto LAB_14031d571;
    }
    if (iVar19 != 2) {
      if (iVar19 == 3) {
        *(undefined4 *)(param_1 + 0x54c) = 0;
        *(undefined4 *)(param_1 + 0x550) = 8;
        *(undefined8 *)(param_1 + 0x554) = 2;
      }
      goto LAB_14031d571;
    }
    *(undefined4 *)(param_1 + 0x54c) = 0;
    *(undefined8 *)(param_1 + 0x554) = 1;
  }
  *(undefined4 *)(param_1 + 0x550) = 4;
LAB_14031d571:
  pcVar7 = *(char **)(param_1 + 0x4e8);
  bVar4 = pcVar7[4];
  if (bVar4 == 0) {
    *(undefined4 *)(param_1 + 0x55c) = 1;
  }
  else if (bVar4 < 3) {
    uVar21 = *(uint *)(pcVar7 + 8);
    *(uint *)(param_1 + 0x55c) = uVar21;
    if (uVar21 < 2) {
      return 0x80070057;
    }
  }
  else if (bVar4 == 4) {
    *(undefined4 *)(param_1 + 0x55c) = 4;
  }
  else {
    *(uint *)(param_1 + 0x55c) = (uint)*(ushort *)(pcVar7 + 0x24);
  }
  fVar12 = DAT_140b79ed0;
  fVar27 = DAT_140b7a1c8;
  if (*(int *)(param_1 + 0x55c) != 1) {
    fVar27 = DAT_140b79ed0 / (float)(*(int *)(param_1 + 0x55c) - 1);
  }
  *(float *)(param_1 + 0x600) = fVar27;
  if (*pcVar7 == '\0') {
    uVar21 = ((int)((int)((ulonglong)(*(ushort *)(pcVar7 + 2) + 999) /
                         (ulonglong)(longlong)(int)(uint)*(ushort *)(pcVar7 + 2)) *
                   (uint)*(ushort *)(pcVar7 + 0x26)) / 1000) * 2 + 0x20;
  }
  else {
    if ((*(ushort *)(pcVar7 + 2) & 1) == 0) {
      *(ushort *)(pcVar7 + 2) = *(ushort *)(pcVar7 + 2) + 1;
    }
    uVar18 = *(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2) + 1;
    uVar21 = 2;
    if (2 < uVar18) {
      uVar21 = uVar18;
    }
  }
  *(uint *)(param_1 + 0x520) = uVar21;
  iVar19 = (*(int *)(param_1 + 0x55c) + 7) * 0x10;
  *(int *)(param_1 + 0x524) = iVar19;
  uVar15 = FUN_14018b280(iVar19 * uVar21,0);
  *(undefined8 *)(param_1 + 0x518) = uVar15;
  *(undefined8 *)(param_1 + 0x52c) = 0;
  *(undefined4 *)(param_1 + 0x528) = 0;
  uVar15 = FUN_14018b280(iVar19,0);
  *(undefined8 *)(param_1 + 0x588) = uVar15;
  uVar15 = FUN_14018b280(iVar19,0);
  *(undefined8 *)(param_1 + 0x590) = uVar15;
  lVar25 = *(longlong *)(param_1 + 0x588);
  uVar15 = *(undefined8 *)(param_1 + 0x1c8);
  *(undefined8 *)(lVar25 + 0x20) = *(undefined8 *)(param_1 + 0x1c0);
  *(undefined8 *)(lVar25 + 0x28) = uVar15;
  lVar25 = *(longlong *)(param_1 + 0x588);
  uVar15 = *(undefined8 *)(param_1 + 0x268);
  *(undefined8 *)(lVar25 + 0x30) = *(undefined8 *)(param_1 + 0x260);
  *(undefined8 *)(lVar25 + 0x38) = uVar15;
  *(undefined4 *)(*(longlong *)(param_1 + 0x588) + 4) = *(undefined4 *)(param_1 + 0x350);
  *(undefined4 *)(*(longlong *)(param_1 + 0x588) + 8) = *(undefined4 *)(param_1 + 0x3f0);
  *(uint *)(*(longlong *)(param_1 + 0x588) + 0x18) =
       (uint)*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 0x26);
  *(undefined4 *)(*(longlong *)(param_1 + 0x588) + 0x14) = *(undefined4 *)(param_1 + 0x538);
  lVar25 = *(longlong *)(param_1 + 0x590);
  uVar15 = *(undefined8 *)(param_1 + 0x248);
  *(undefined8 *)(lVar25 + 0x20) = *(undefined8 *)(param_1 + 0x240);
  *(undefined8 *)(lVar25 + 0x28) = uVar15;
  lVar25 = *(longlong *)(param_1 + 0x590);
  uVar3 = *(undefined4 *)(param_1 + 0x2e4);
  uVar10 = *(undefined4 *)(param_1 + 0x2e8);
  uVar11 = *(undefined4 *)(param_1 + 0x2ec);
  *(undefined4 *)(lVar25 + 0x30) = *(undefined4 *)(param_1 + 0x2e0);
  *(undefined4 *)(lVar25 + 0x34) = uVar3;
  *(undefined4 *)(lVar25 + 0x38) = uVar10;
  *(undefined4 *)(lVar25 + 0x3c) = uVar11;
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 4) = *(undefined4 *)(param_1 + 0x390);
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 8) = *(undefined4 *)(param_1 + 0x430);
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 0x18) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x590) + 0x14) = *(undefined4 *)(param_1 + 0x538);
  if (*(uint *)(param_1 + 0x55c) < 2) {
    fVar27 = 0.0;
  }
  else {
    fVar27 = (float)(*(int *)(*(longlong *)(param_1 + 0x4e8) + 8) - 3) /
             (float)(*(uint *)(param_1 + 0x55c) - 1);
  }
  *(float *)(param_1 + 0x548) = fVar27;
  if (*(char *)(*(longlong *)(param_1 + 0x4e8) + 4) != '\x04') {
    uVar20 = *(undefined4 *)(*(longlong *)(param_1 + 0x4e8) + 8);
  }
  FUN_1402626b0(param_1 + 0x620,uVar20);
  FUN_1402626b0(param_1 + 0x630,uVar20);
  FUN_1402626b0(param_1 + 0x640,uVar20);
  FUN_1402626b0(param_1 + 0x650,uVar20);
  FUN_1402626b0(param_1 + 0x660,uVar20);
  uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  *(undefined8 *)(param_1 + 0x6a0) = 0;
  if (**(char **)(param_1 + 0x4e8) == '\x01') {
    uVar16 = uVar17;
    if (*(short *)(*(char **)(param_1 + 0x4e8) + 2) != 0) {
      do {
        uVar21 = (int)uVar16 + 1;
        local_68[0] = 0;
        local_68[1] = 0;
        FUN_14031e520(param_1,param_1 + 0x630,local_68,
                      (ulonglong)(*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 0x26) * uVar21) /
                      (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2));
        uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
        iVar19 = *(int *)(param_1 + 0x52c);
        if (iVar19 == 0) {
          iVar19 = *(int *)(param_1 + 0x520);
        }
        *(int *)((ulonglong)(uint)((iVar19 + -1) * *(int *)(param_1 + 0x524)) + 0x14 +
                *(longlong *)(param_1 + 0x518)) = (*(int *)(param_1 + 0x538) - (int)uVar16) + -1;
        uVar16 = (ulonglong)uVar21;
      } while (uVar21 < *(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2));
    }
    *(uint *)(*(longlong *)(param_1 + 0x590) + 0x14) =
         (*(int *)(param_1 + 0x538) - (uint)*(ushort *)(*(longlong *)(param_1 + 0x4e8) + 2)) + -1;
    FUN_1402626b0(param_1 + 0x5d0,*(undefined4 *)(param_1 + 0x55c));
    FUN_1402626b0(param_1 + 0x5e0,*(undefined4 *)(param_1 + 0x55c));
  }
  cVar5 = *(char *)(*(longlong *)(param_1 + 0x4e8) + 4);
  if (cVar5 == '\x01') {
    plVar30 = (longlong *)(param_1 + 0x560);
    FUN_140052360(plVar30,*(undefined4 *)(param_1 + 0x55c));
    fVar27 = 0.0;
    *(undefined4 *)*plVar30 = 0;
    if (1 < *(uint *)(param_1 + 0x55c)) {
      lVar25 = *plVar30;
      do {
        uVar16 = (ulonglong)uVar23;
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x4e8) + 0x10);
        uVar17 = (ulonglong)(uVar23 - 1);
        uVar23 = uVar23 + 1;
        fVar26 = *(float *)(lVar8 + uVar17 * 0xc) - *(float *)(lVar8 + uVar16 * 0xc);
        fVar28 = *(float *)(lVar8 + 4 + uVar17 * 0xc) - *(float *)(lVar8 + 4 + uVar16 * 0xc);
        fVar29 = *(float *)(lVar8 + 8 + uVar17 * 0xc) - *(float *)(lVar8 + 8 + uVar16 * 0xc);
        *(float *)(lVar25 + uVar16 * 4) = SQRT(fVar26 * fVar26 + fVar28 * fVar28 + fVar29 * fVar29);
        lVar25 = *plVar30;
        fVar27 = fVar27 + *(float *)(lVar25 + uVar16 * 4);
      } while (uVar23 < *(uint *)(param_1 + 0x55c));
      if (1 < *(uint *)(param_1 + 0x55c)) {
        do {
          if (fVar27 == 0.0) {
            fVar26 = 0.0;
          }
          else {
            fVar26 = *(float *)(*plVar30 + uVar22 * 4) / fVar27 +
                     *(float *)(*plVar30 + (ulonglong)((int)uVar22 - 1) * 4);
          }
          uVar23 = (int)uVar22 + 1;
          *(float *)(*plVar30 + uVar22 * 4) = fVar26;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 < *(uint *)(param_1 + 0x55c));
      }
    }
  }
  else if (cVar5 == '\x02') {
    plVar30 = (longlong *)(param_1 + 0x560);
    FUN_140052360(plVar30,*(undefined4 *)(param_1 + 0x55c));
    fVar27 = 0.0;
    *(undefined4 *)*plVar30 = 0;
    if (1 < *(uint *)(param_1 + 0x55c)) {
      lVar25 = *plVar30;
      uVar17 = uVar22;
      do {
        fVar26 = 0.0;
        if ((uVar17 & 1) != 0) {
          lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x4e8) + 0x10);
          uVar16 = (ulonglong)((int)uVar17 - 1);
          fVar26 = *(float *)(lVar8 + uVar16 * 0xc) - *(float *)(lVar8 + uVar17 * 0xc);
          fVar28 = *(float *)(lVar8 + 4 + uVar16 * 0xc) - *(float *)(lVar8 + 4 + uVar17 * 0xc);
          fVar29 = *(float *)(lVar8 + 8 + uVar16 * 0xc) - *(float *)(lVar8 + 8 + uVar17 * 0xc);
          fVar26 = SQRT(fVar26 * fVar26 + fVar28 * fVar28 + fVar29 * fVar29);
        }
        uVar23 = (int)uVar17 + 1;
        *(float *)(lVar25 + uVar17 * 4) = fVar26;
        lVar25 = *plVar30;
        fVar27 = fVar27 + *(float *)(lVar25 + uVar17 * 4);
        uVar17 = (ulonglong)uVar23;
      } while (uVar23 < *(uint *)(param_1 + 0x55c));
      if (1 < *(uint *)(param_1 + 0x55c)) {
        do {
          if (fVar27 == 0.0) {
            fVar26 = 0.0;
          }
          else {
            fVar26 = *(float *)(*plVar30 + uVar22 * 4) / fVar27 +
                     *(float *)(*plVar30 + (ulonglong)((int)uVar22 - 1) * 4);
          }
          uVar23 = (int)uVar22 + 1;
          *(float *)(*plVar30 + uVar22 * 4) = fVar26;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 < *(uint *)(param_1 + 0x55c));
      }
    }
  }
  else if (cVar5 == '\x03') {
    local_68[1] = 0;
    local_68[0] = 0;
    FUN_1402626b0(local_68,*(undefined4 *)(*(longlong *)(param_1 + 0x4e8) + 8));
    lVar25 = local_68[0];
    if (*(int *)(*(longlong *)(param_1 + 0x4e8) + 8) != 0) {
      do {
        uVar23 = (int)uVar17 + 1;
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x4e8) + 0x10);
        auVar9._4_4_ = *(undefined4 *)(lVar8 + 4 + uVar17 * 0xc);
        auVar9._0_4_ = *(undefined4 *)(lVar8 + uVar17 * 0xc);
        auVar9._8_4_ = *(undefined4 *)(lVar8 + 8 + uVar17 * 0xc);
        auVar9._12_4_ = 0;
        *(undefined1 (*) [16])(local_68[0] + uVar17 * 0x10) = auVar9;
        uVar17 = (ulonglong)uVar23;
      } while (uVar23 < *(uint *)(*(longlong *)(param_1 + 0x4e8) + 8));
    }
    iVar19 = *(int *)(param_1 + 0x52c);
    uVar6 = *(undefined2 *)(*(longlong *)(param_1 + 0x4e8) + 0x26);
    local_68[2] = 0;
    local_68[3] = 0;
    iVar13 = iVar19;
    if (iVar19 == 0) {
      iVar13 = *(int *)(param_1 + 0x520);
    }
    iVar14 = iVar19 + 1;
    *(int *)(param_1 + 0x52c) = iVar14;
    if (iVar14 == *(int *)(param_1 + 0x520)) {
      iVar14 = 0;
    }
    *(int *)(param_1 + 0x52c) = iVar14;
    if (*(int *)(param_1 + 0x530) == *(int *)(param_1 + 0x520)) {
      *(undefined4 *)(param_1 + 0x528) = *(undefined4 *)(param_1 + 0x52c);
    }
    else {
      *(int *)(param_1 + 0x530) = *(int *)(param_1 + 0x530) + 1;
    }
    plVar30 = local_68 + 2;
    FUN_14031e170(param_1,(ulonglong)(uint)(*(int *)(param_1 + 0x524) * iVar19) +
                          *(longlong *)(param_1 + 0x518),
                  (ulonglong)(uint)((iVar13 + -1) * *(int *)(param_1 + 0x524)) +
                  *(longlong *)(param_1 + 0x518),local_68,plVar30,uVar6,1);
    uVar20 = (undefined4)((ulonglong)plVar30 >> 0x20);
    plVar30 = (longlong *)(param_1 + 0x560);
    FUN_140052360(plVar30,*(undefined4 *)(param_1 + 0x55c));
    fVar27 = 0.0;
    *(undefined4 *)*plVar30 = 0;
    lVar8 = *(longlong *)(param_1 + 0x518);
    if (1 < *(uint *)(param_1 + 0x55c)) {
      lVar24 = *plVar30;
      uVar17 = uVar22;
      do {
        uVar23 = (int)uVar17 + 1;
        pfVar1 = (float *)(lVar8 + ((ulonglong)((int)uVar17 - 1) + 7) * 0x10);
        pfVar2 = (float *)(lVar8 + (uVar17 + 7) * 0x10);
        *(float *)(lVar24 + uVar17 * 4) =
             SQRT((*pfVar1 - *pfVar2) * (*pfVar1 - *pfVar2) +
                  (pfVar1[1] - pfVar2[1]) * (pfVar1[1] - pfVar2[1]) +
                  (pfVar1[2] - pfVar2[2]) * (pfVar1[2] - pfVar2[2]));
        lVar24 = *plVar30;
        fVar27 = fVar27 + *(float *)(lVar24 + uVar17 * 4);
        uVar17 = (ulonglong)uVar23;
      } while (uVar23 < *(uint *)(param_1 + 0x55c));
      if (1 < *(uint *)(param_1 + 0x55c)) {
        do {
          if (fVar27 == 0.0) {
            fVar26 = 0.0;
          }
          else {
            fVar26 = *(float *)(*plVar30 + uVar22 * 4) / fVar27 +
                     *(float *)(*plVar30 + (ulonglong)((int)uVar22 - 1) * 4);
          }
          uVar23 = (int)uVar22 + 1;
          *(float *)(*plVar30 + uVar22 * 4) = fVar26;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 < *(uint *)(param_1 + 0x55c));
      }
    }
    *(undefined8 *)(param_1 + 0x52c) = 0;
    *(undefined4 *)(param_1 + 0x528) = 0;
    if (lVar25 != 0) {
      (**(code **)(*(longlong *)(lVar25 + -0x10) + 8))(lVar25 + -0x10);
    }
  }
  uVar23 = *(uint *)(*(longlong *)(param_1 + 0x4e8) + 0x28);
  uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x4e8) + 0x3c8);
  FUN_14032f8b0(uVar3,param_1 + 0x4f0,uVar23 & 0x80,uVar23 & 0x100,CONCAT44(uVar20,uVar3));
  lVar25 = *(longlong *)(param_1 + 0x4e8);
  uVar20 = 0x18;
  if (*(short *)(lVar25 + 0x404) != 0) {
    uVar20 = 0x24;
  }
  *(undefined4 *)(param_1 + 0x598) = uVar20;
  uVar20 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x40))
                     (*(longlong **)(param_1 + 0x38),*(undefined4 *)(lVar25 + 0x3e0),
                      *(undefined4 *)(lVar25 + 0x3e4));
  fVar26 = DAT_140b7a1c0;
  *(undefined4 *)(param_1 + 0x57c) = uVar20;
  fVar27 = *(float *)(*(longlong *)(param_1 + 0x4e8) + 0x3b4);
  fVar28 = fVar26;
  if (fVar27 != 0.0) {
    fVar28 = fVar12 / fVar27;
  }
  *(float *)(param_1 + 0x5f8) = fVar28;
  fVar27 = *(float *)(*(longlong *)(param_1 + 0x4e8) + 0x3b8);
  if (fVar27 != 0.0) {
    fVar26 = fVar12 / fVar27;
  }
  *(float *)(param_1 + 0x5fc) = fVar26;
  return 0;
}



==== FUN_14031e170 @ 14031e170 size 932 ====
CALLERS: FUN_14031d490 FUN_14031ee60 FUN_14031e520
CALLEES:

void FUN_14031e170(longlong param_1,longlong param_2,longlong param_3,longlong *param_4,
                  float *param_5,undefined4 param_6,int param_7)

{
  longlong lVar1;
  undefined8 *puVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  byte bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined8 uVar17;
  float fVar18;
  uint uVar19;
  int iVar20;
  longlong lVar21;
  undefined8 *puVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar30;
  float fVar31;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  
  fVar16 = DAT_140b79f88;
  fVar31 = DAT_140b79f58;
  fVar30 = DAT_140b79f20;
  fVar27 = DAT_140b79ed0;
  fVar18 = DAT_140b79e48;
  uVar23 = 0;
  bVar8 = *(byte *)(*(longlong *)(param_1 + 0x4e8) + 4);
  if (bVar8 == 0) {
    uVar17 = ((undefined8 *)*param_4)[1];
    *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)*param_4;
    *(undefined8 *)(param_2 + 0x78) = uVar17;
    goto LAB_14031e3ce;
  }
  if (2 < bVar8) {
    if (bVar8 == 3) {
      if (*(int *)(param_1 + 0x55c) != 0) {
        do {
          fVar38 = (float)uVar23 * *(float *)(param_1 + 0x548);
          iVar20 = (int)fVar38;
          fVar26 = fVar38;
          if ((iVar20 != -0x80000000) && ((float)iVar20 != fVar38)) {
            auVar28._4_4_ = fVar38;
            auVar28._0_4_ = fVar38;
            auVar28._8_8_ = 0;
            uVar19 = movmskps((int)uVar23,auVar28);
            fVar26 = (float)(int)(iVar20 - (uVar19 & 1));
          }
          fVar38 = fVar38 - fVar26;
          uVar24 = (ulonglong)(fVar26 + fVar18);
          if ((fVar38 == 0.0) && (*(int *)(*(longlong *)(param_1 + 0x4e8) + 8) - 3U <= (uint)uVar24)
             ) {
            uVar24 = (ulonglong)((uint)uVar24 - 1);
            fVar38 = fVar27;
          }
          lVar1 = *param_4;
          iVar20 = (int)uVar24;
          fVar35 = fVar38 * fVar38;
          fVar32 = fVar35 * fVar38 * fVar30;
          fVar34 = fVar35 * fVar38 * fVar18;
          fVar37 = fVar34 - fVar35 * fVar18;
          fVar25 = (fVar35 * fVar31 - fVar32) + fVar38 * fVar18;
          pfVar3 = (float *)(lVar1 + (uVar24 & 0xffffffff) * 0x10);
          fVar26 = pfVar3[1];
          fVar33 = pfVar3[2];
          fVar9 = pfVar3[3];
          uVar19 = (int)uVar23 + 1;
          pfVar4 = (float *)(lVar1 + (ulonglong)(iVar20 + 3) * 0x10);
          fVar10 = pfVar4[1];
          fVar11 = pfVar4[2];
          fVar12 = pfVar4[3];
          pfVar5 = (float *)(lVar1 + (ulonglong)(iVar20 + 2) * 0x10);
          fVar13 = pfVar5[1];
          fVar14 = pfVar5[2];
          fVar15 = pfVar5[3];
          fVar36 = (fVar35 - fVar34) - fVar38 * fVar18;
          fVar35 = (fVar32 - fVar35 * fVar16) + fVar27;
          pfVar6 = (float *)(lVar1 + (ulonglong)(iVar20 + 1) * 0x10);
          fVar38 = pfVar6[1];
          fVar32 = pfVar6[2];
          fVar34 = pfVar6[3];
          pfVar7 = (float *)(param_2 + (uVar23 + 7) * 0x10);
          *pfVar7 = fVar37 * *pfVar4 + *pfVar5 * fVar25 + fVar35 * *pfVar6 + *pfVar3 * fVar36;
          pfVar7[1] = fVar37 * fVar10 + fVar13 * fVar25 + fVar35 * fVar38 + fVar26 * fVar36;
          pfVar7[2] = fVar37 * fVar11 + fVar14 * fVar25 + fVar35 * fVar32 + fVar33 * fVar36;
          pfVar7[3] = fVar37 * fVar12 + fVar15 * fVar25 + fVar35 * fVar34 + fVar9 * fVar36;
          uVar23 = (ulonglong)uVar19;
        } while (uVar19 < *(uint *)(param_1 + 0x55c));
      }
      goto LAB_14031e3ce;
    }
    if (bVar8 != 4) goto LAB_14031e3ce;
  }
  if (param_4[1] != 0) {
    do {
      lVar1 = uVar23 + 7;
      lVar21 = uVar23 * 0x10;
      uVar23 = (ulonglong)((int)uVar23 + 1);
      puVar22 = (undefined8 *)(lVar21 + *param_4);
      uVar17 = puVar22[1];
      puVar2 = (undefined8 *)(param_2 + lVar1 * 0x10);
      *puVar2 = *puVar22;
      puVar2[1] = uVar17;
    } while (uVar23 < (ulonglong)param_4[1]);
  }
LAB_14031e3ce:
  auVar29._0_12_ = ZEXT812(0);
  auVar29._12_4_ = 0;
  *(undefined4 *)(param_2 + 0x18) = param_6;
  *(undefined4 *)(param_2 + 0x14) =
       *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0xd0);
  uVar17 = *(undefined8 *)(param_5 + 2);
  *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)param_5;
  *(undefined8 *)(param_2 + 0x58) = uVar17;
  *(undefined1 (*) [16])(param_2 + 0x40) = auVar29;
  if (param_7 != 0) {
    *(undefined1 (*) [16])(param_2 + 0x30) = auVar29;
    *(undefined1 (*) [16])(param_2 + 0x20) = auVar29;
    *(undefined8 *)(param_2 + 4) = 0;
  }
  uVar19 = DAT_140b7b500;
  fVar18 = DAT_140b79cc4;
  if ((1 < *(uint *)(param_1 + 0x530)) && (param_3 != 0)) {
    fVar27 = *(float *)(param_3 + 0x70) - *(float *)(param_2 + 0x70);
    fVar30 = *(float *)(param_3 + 0x74) - *(float *)(param_2 + 0x74);
    fVar31 = *(float *)(param_3 + 0x78) - *(float *)(param_2 + 0x78);
    fVar33 = SQRT(fVar27 * fVar27 + fVar30 * fVar30 + fVar31 * fVar31);
    *(float *)(param_2 + 0x10) = fVar33;
    *(float *)(param_2 + 0xc) =
         fVar33 * *(float *)(*(longlong *)(param_1 + 0x4e8) + 0x3b4) + *(float *)(param_3 + 0xc);
    fVar27 = param_5[1];
    fVar30 = param_5[2];
    fVar31 = param_5[3];
    fVar16 = *(float *)(param_3 + 0x54);
    fVar38 = *(float *)(param_3 + 0x58);
    fVar26 = *(float *)(param_3 + 0x5c);
    *(float *)(param_2 + 0x60) = *param_5 - *(float *)(param_3 + 0x50);
    *(float *)(param_2 + 100) = fVar27 - fVar16;
    *(float *)(param_2 + 0x68) = fVar30 - fVar38;
    *(float *)(param_2 + 0x6c) = fVar31 - fVar26;
    if ((float)(*(uint *)(param_2 + 0x60) & uVar19) < fVar18) {
      *(undefined4 *)(param_2 + 0x60) = 0;
    }
    if ((float)(*(uint *)(param_2 + 100) & uVar19) < fVar18) {
      *(undefined4 *)(param_2 + 100) = 0;
    }
    if ((float)(*(uint *)(param_2 + 0x68) & uVar19) < fVar18) {
      *(undefined4 *)(param_2 + 0x68) = 0;
    }
    *(float *)(param_1 + 0x570) = fVar33 + *(float *)(param_1 + 0x570);
    return;
  }
  *(undefined8 *)(param_2 + 0xc) = 0;
  *(undefined1 (*) [16])(param_2 + 0x60) = auVar29;
  return;
}



==== FUN_14031e520 @ 14031e520 size 191 ====
CALLERS: FUN_14031d490 FUN_14031ee60
CALLEES: FUN_14031e170

void FUN_14031e520(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x52c);
  iVar2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x520);
  }
  iVar3 = iVar1 + 1;
  *(int *)(param_1 + 0x52c) = iVar3;
  if (iVar3 == *(int *)(param_1 + 0x520)) {
    iVar3 = 0;
  }
  *(int *)(param_1 + 0x52c) = iVar3;
  if (*(int *)(param_1 + 0x530) == *(int *)(param_1 + 0x520)) {
    *(undefined4 *)(param_1 + 0x528) = *(undefined4 *)(param_1 + 0x52c);
  }
  else {
    *(int *)(param_1 + 0x530) = *(int *)(param_1 + 0x530) + 1;
  }
  FUN_14031e170(param_1,(ulonglong)(uint)(*(int *)(param_1 + 0x524) * iVar1) +
                        *(longlong *)(param_1 + 0x518),
                (ulonglong)(uint)((iVar2 + -1) * *(int *)(param_1 + 0x524)) +
                *(longlong *)(param_1 + 0x518),param_2,param_3,param_4,1);
  return;
}



==== FUN_140323d50 @ 140323d50 size 6099 ====
CALLERS:
CALLEES: FUN_1401afc20 FUN_1408fe170 FUN_140323590 FUN_1403220c0 FUN_140322ce0 FUN_140262750 FUN_1408fc7f0 FUN_140262d50 FUN_140321360 FUN_1401c3280 FUN_1401afb10 __security_check_cookie FUN_140052360 FUN_140262900

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140323d50(longlong *param_1,float *param_2,undefined8 *param_3,undefined8 param_4,
                  float *param_5,undefined8 param_6,float *param_7,longlong param_8,
                  undefined8 param_9,uint param_10,longlong param_11,uint param_12)

{
  ushort uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  short sVar6;
  short sVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  undefined4 *puVar15;
  byte bVar16;
  short sVar17;
  short sVar18;
  uint uVar19;
  ulonglong uVar20;
  short *psVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  uint uVar24;
  int iVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  uint uVar28;
  float *pfVar29;
  uint uVar30;
  longlong lVar31;
  bool bVar32;
  float fVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  float fVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  undefined1 auStack_918 [32];
  ulonglong local_8f8;
  undefined1 *local_8f0;
  float **local_8e8;
  undefined4 local_8e0;
  float local_8d8;
  float **local_8d0;
  float *local_8c8;
  undefined1 *puStack_8c0;
  uint local_8b8;
  int local_8b4;
  ulonglong local_8b0;
  undefined4 uStack_8a8;
  undefined4 uStack_8a4;
  undefined1 local_898 [8];
  undefined8 uStack_890;
  longlong local_888;
  undefined8 local_880;
  longlong local_878;
  float *local_870;
  undefined1 local_868 [16];
  float *local_858;
  undefined8 uStack_850;
  undefined8 local_848;
  float local_840;
  undefined4 local_83c;
  float *local_838;
  longlong local_828;
  float *local_820;
  float *local_818;
  undefined8 uStack_810;
  float local_808;
  undefined4 local_804;
  undefined8 local_7f8;
  undefined8 uStack_7f0;
  undefined8 local_7e8;
  undefined8 uStack_7e0;
  undefined8 local_7d8;
  undefined8 uStack_7d0;
  undefined8 local_7c8;
  undefined8 uStack_7c0;
  float *local_7b8;
  undefined8 uStack_7b0;
  undefined8 local_7a8;
  undefined8 uStack_7a0;
  float local_798;
  float fStack_794;
  float fStack_790;
  float fStack_78c;
  float local_788;
  float fStack_784;
  float fStack_780;
  float fStack_77c;
  undefined8 local_778;
  undefined8 uStack_770;
  undefined8 local_768;
  undefined8 uStack_760;
  float *local_758;
  undefined8 uStack_750;
  float local_748;
  float fStack_744;
  float fStack_740;
  float fStack_73c;
  float local_738;
  float fStack_734;
  float fStack_730;
  float fStack_72c;
  float local_728;
  float fStack_724;
  float fStack_720;
  float fStack_71c;
  float local_718;
  float local_714;
  float local_710;
  undefined4 local_708;
  undefined4 uStack_704;
  undefined4 uStack_700;
  undefined4 uStack_6fc;
  undefined4 local_6f8;
  undefined4 uStack_6f4;
  undefined4 uStack_6f0;
  undefined4 uStack_6ec;
  undefined4 local_6e8;
  undefined4 uStack_6e4;
  undefined4 uStack_6e0;
  undefined4 uStack_6dc;
  undefined4 local_6d8;
  undefined4 uStack_6d4;
  undefined4 uStack_6d0;
  undefined4 uStack_6cc;
  undefined8 local_6c8;
  undefined8 uStack_6c0;
  undefined4 local_6b8;
  undefined4 uStack_6b4;
  undefined4 uStack_6b0;
  undefined4 uStack_6ac;
  undefined8 local_6a8;
  undefined8 uStack_6a0;
  float local_698;
  float fStack_694;
  float fStack_690;
  float fStack_68c;
  undefined8 local_688;
  undefined8 uStack_680;
  undefined8 local_678;
  undefined8 uStack_670;
  undefined8 local_668;
  undefined8 uStack_660;
  undefined8 local_658;
  undefined8 uStack_650;
  float local_648;
  float fStack_644;
  float fStack_640;
  float fStack_63c;
  float local_638;
  float fStack_634;
  float fStack_630;
  float fStack_62c;
  float local_628;
  float fStack_624;
  float fStack_620;
  float fStack_61c;
  float local_618;
  float fStack_614;
  float fStack_610;
  float fStack_60c;
  float local_608;
  float fStack_604;
  float fStack_600;
  undefined4 uStack_5fc;
  float local_5f8;
  float fStack_5f4;
  float fStack_5f0;
  float fStack_5ec;
  float local_5e8;
  float fStack_5e4;
  float fStack_5e0;
  float fStack_5dc;
  float local_5d8;
  float fStack_5d4;
  float fStack_5d0;
  float fStack_5cc;
  float local_5c8;
  float fStack_5c4;
  float fStack_5c0;
  float fStack_5bc;
  float local_5b8;
  float fStack_5b4;
  float fStack_5b0;
  float fStack_5ac;
  float local_5a8 [13];
  float local_574;
  float local_568 [13];
  float local_534;
  undefined1 local_528 [64];
  undefined1 local_4e8 [64];
  undefined1 local_4a8 [64];
  float *local_468;
  undefined8 local_460;
  float *local_418;
  undefined8 local_410;
  float *local_3c8;
  undefined1 *local_3c0;
  float *local_378;
  undefined1 *local_370;
  undefined8 *local_328;
  undefined8 local_320;
  undefined8 local_2d8 [10];
  undefined8 *local_288 [10];
  undefined8 *local_238 [10];
  undefined8 local_1e8 [10];
  undefined1 local_198 [32];
  float local_178;
  ulonglong local_b8;
  undefined8 extraout_XMM0_Qb;
  
  local_b8 = DAT_140c0f7b0 ^ (ulonglong)auStack_918;
  local_838 = param_7;
  local_888 = param_8;
  if (*(uint *)(param_1 + 0xa6) < 2) {
    return;
  }
  if (*(short *)(param_11 + 0x34) == 0) {
    return;
  }
  if ((*(float *)(param_11 + 0x20) == 0.0) && (*(float *)(param_11 + 0x24) == 0.0)) {
    return;
  }
  local_880 = param_4;
  if (*(char *)param_1[0x9d] == '\x01') {
    if ((int)param_1[10] == 0) {
      return;
    }
    iVar12 = (**(code **)(*param_1 + 0x48))();
    if (iVar12 == 0) {
      return;
    }
  }
  local_6c8 = *param_3;
  uStack_6c0 = param_3[1];
  local_6b8 = *(undefined4 *)(param_3 + 2);
  uStack_6b4 = *(undefined4 *)((longlong)param_3 + 0x14);
  uStack_6b0 = *(undefined4 *)(param_3 + 3);
  uStack_6ac = *(undefined4 *)((longlong)param_3 + 0x1c);
  uVar23 = 0;
  fVar41 = *(float *)(param_3 + 6);
  fVar42 = *(float *)((longlong)param_3 + 0x34);
  fVar45 = *(float *)(param_3 + 7);
  fVar44 = *(float *)((longlong)param_3 + 0x3c);
  local_6a8 = param_3[4];
  uStack_6a0 = param_3[5];
  local_698 = fVar41;
  fStack_694 = fVar42;
  fStack_690 = fVar45;
  fStack_68c = fVar44;
  if ((*(int *)(param_1[1] + 0x28) == 0) || (*(int *)(param_1[1] + 8) == 2)) {
    local_688 = *(undefined8 *)param_2;
    uStack_680 = *(undefined8 *)(param_2 + 2);
    local_678 = *(undefined8 *)(param_2 + 4);
    uStack_670 = *(undefined8 *)(param_2 + 6);
    local_668 = *(undefined8 *)(param_2 + 8);
    uStack_660 = *(undefined8 *)(param_2 + 10);
    local_658 = *(undefined8 *)(param_2 + 0xc);
    uStack_650 = *(undefined8 *)(param_2 + 0xe);
    local_7f8 = *(undefined8 *)param_5;
    uStack_7f0 = *(undefined8 *)(param_5 + 2);
    local_7e8 = *(undefined8 *)(param_5 + 4);
    uStack_7e0 = *(undefined8 *)(param_5 + 6);
    local_7d8 = *(undefined8 *)(param_5 + 8);
    uStack_7d0 = *(undefined8 *)(param_5 + 10);
    local_7c8 = *(undefined8 *)(param_5 + 0xc);
    uStack_7c0 = *(undefined8 *)(param_5 + 0xe);
  }
  else {
    local_2d8[0] = param_4;
    FUN_1401afc20(local_2d8,local_528);
    puStack_8c0 = local_528;
    local_8c8 = param_2;
    local_3c8 = param_2;
    local_3c0 = puStack_8c0;
    FUN_1401afb10(&local_3c8,local_5a8);
    local_1e8[0] = param_4;
    FUN_1401afc20(local_1e8,local_4e8);
    puStack_8c0 = local_4e8;
    local_8c8 = param_5;
    local_378 = param_5;
    local_370 = puStack_8c0;
    FUN_1401afb10(&local_378,local_568);
    plVar2 = *(longlong **)(*(longlong *)(param_1[5] + 0x10) + 0x1e8);
    local_574 = 0.0;
    if (plVar2 != (longlong *)0x0) {
      local_8f8 = 0;
      local_628 = _DAT_140c77870;
      fStack_624 = fRam0000000140c77874;
      fStack_620 = fRam0000000140c77878;
      fStack_61c = fRam0000000140c7787c;
      local_798 = fVar41 + _DAT_140c77870;
      fStack_794 = fVar42 + fRam0000000140c77874;
      fStack_790 = fVar45 + fRam0000000140c77878;
      fStack_78c = fVar44 + fRam0000000140c7787c;
      iVar12 = (**(code **)(*plVar2 + 0x1b8))(plVar2,&local_798,local_198,1);
      if (iVar12 != 0) {
        local_574 = local_178;
      }
    }
    local_8c8 = local_5a8;
    puStack_8c0 = (undefined1 *)param_4;
    fStack_694 = local_574;
    local_534 = local_574;
    local_418 = local_8c8;
    local_410 = param_4;
    FUN_1401afb10(&local_418,&local_688);
    local_8c8 = local_568;
    puStack_8c0 = (undefined1 *)param_4;
    local_468 = local_8c8;
    local_460 = param_4;
    FUN_1401afb10(&local_468,&local_7f8);
  }
  local_288[0] = &local_7f8;
  FUN_1401afc20(local_288,local_4a8);
  FUN_140052360(&DAT_140c79de8,(int)param_1[0xa4] + 1);
  FUN_140052360(&DAT_140c79df8,(int)param_1[0xa4] + 1);
  local_238[0] = &local_7f8;
  fVar45 = SQRT(*param_2 * *param_2 + param_2[1] * param_2[1] + param_2[2] * param_2[2]);
  FUN_1401afc20(local_238,&local_748);
  auVar5._4_4_ = local_714;
  auVar5._0_4_ = local_718;
  auVar5._8_4_ = local_710;
  local_898._4_4_ = local_714;
  local_898._0_4_ = local_718;
  uStack_890._0_4_ = local_710;
  local_608 = _DAT_140b7a8c0;
  fStack_604 = _UNK_140b7a8c4;
  fStack_600 = _UNK_140b7a8c8;
  uStack_5fc = _UNK_140b7a8cc;
  uStack_890._4_4_ = 0.0;
  local_5c8 = _UNK_140b7a8c4 * local_738 + _DAT_140b7a8c0 * local_748 + _UNK_140b7a8c8 * local_728;
  fStack_5c4 = _UNK_140b7a8c4 * fStack_734 + _DAT_140b7a8c0 * fStack_744 +
               _UNK_140b7a8c8 * fStack_724;
  fStack_5c0 = _UNK_140b7a8c4 * fStack_730 + _DAT_140b7a8c0 * fStack_740 +
               _UNK_140b7a8c8 * fStack_720;
  fStack_5bc = _UNK_140b7a8c4 * fStack_72c + _DAT_140b7a8c0 * fStack_73c +
               _UNK_140b7a8c8 * fStack_71c;
  fVar41 = fStack_5c4 * fStack_5c4;
  auVar36._4_4_ = fVar41;
  auVar36._0_4_ = fVar41;
  auVar36._8_4_ = fVar41;
  auVar36._12_4_ = fVar41;
  fVar42 = local_5c8 * local_5c8 + fVar41 + fStack_5c0 * fStack_5c0;
  auVar37._4_4_ = fVar41;
  auVar37._0_4_ = fVar42;
  auVar37._8_4_ = fStack_5c0 * fStack_5c0;
  auVar37._12_4_ = fStack_5bc * fStack_5bc;
  auVar37 = rsqrtss(auVar36,auVar37);
  fStack_5dc = auVar37._0_4_;
  fStack_5dc = (DAT_140b79fa0 - fVar42 * fStack_5dc * fStack_5dc) * DAT_140b79e48 * fStack_5dc;
  if (fStack_5dc <= 0.0) {
    fStack_5dc = 0.0;
  }
  fVar41 = fStack_5dc * local_5c8;
  fVar42 = fStack_5dc * fStack_5c4;
  fVar44 = fStack_5dc * fStack_5c0;
  fStack_5dc = fStack_5dc * fStack_5bc;
  uVar20 = uVar23;
  if ((int)param_1[0xa6] != -1) {
    do {
      *(int *)(DAT_140c79de8 + uVar20 * 4) = (int)uVar20;
      uVar19 = (int)uVar20 + 1;
      uVar20 = (ulonglong)uVar19;
    } while (uVar19 < (int)param_1[0xa6] + 1U);
  }
  local_7a8 = _DAT_140b7a700;
  uStack_7a0 = _UNK_140b7a708;
  local_5e8 = fVar41;
  fStack_5e4 = fVar42;
  fStack_5e0 = fVar44;
  FUN_140262900(param_8,&local_8c8,&local_7a8);
  fVar9 = DAT_140b79ed0;
  fVar8 = DAT_140b79ce0;
  plVar2 = param_1 + 0xa3;
  lVar31 = *plVar2;
  iVar12 = *(int *)(param_1[0xb2] + 0x18);
  uVar19 = *(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5];
  iVar13 = *(int *)((ulonglong)uVar19 + 0x18 + lVar31);
  fVar43 = DAT_140b79ed0;
  if (iVar13 != iVar12) {
    uVar1 = *(ushort *)(param_1[0x9d] + 0x26);
    fVar43 = (float)(int)((uint)uVar1 - iVar13) * (DAT_140b79ed0 / (float)uVar1);
    fVar33 = (DAT_140b79ed0 - fVar43) /
             ((float)(int)((uint)uVar1 - iVar12) * (DAT_140b79ed0 / (float)uVar1) - fVar43);
    if (DAT_140b79ed0 <= fVar33) {
      fVar33 = DAT_140b79ed0;
    }
    fVar43 = 0.0;
    if (0.0 <= fVar33) {
      fVar43 = fVar33;
    }
  }
  fVar40 = (*(float *)(param_1[0xb2] + 0xc) - *(float *)((ulonglong)uVar19 + 0xc + lVar31)) * fVar43
           + *(float *)((ulonglong)uVar19 + 0xc + lVar31);
  *(float *)(param_1 + 0xa2) = fVar40;
  fVar33 = *(float *)(param_1[0xb1] + 0xc) - fVar40;
  if (fVar8 < fVar33) {
LAB_140324327:
    fVar33 = fVar9 / fVar33;
  }
  else {
    iVar12 = *(int *)((longlong)param_1 + 0x52c);
    if (iVar12 == 0) {
      iVar12 = (int)param_1[0xa4];
    }
    fVar33 = *(float *)((ulonglong)(uint)((iVar12 + -1) * *(int *)((longlong)param_1 + 0x524)) + 0xc
                       + *plVar2) - fVar40;
    if (fVar8 < fVar33) goto LAB_140324327;
    fVar33 = 0.0;
  }
  lVar31 = param_1[0x9d];
  *(float *)((longlong)param_1 + 0x514) = fVar33;
  if (*(char *)(lVar31 + 4) == '\0') {
    iVar12 = (int)param_1[0xa6] + 2;
    local_8b4 = iVar12 * 3;
    local_8b8 = 3;
    if (*(short *)(lVar31 + 0x404) == 0) {
      uVar22 = 10;
      iVar12 = iVar12 * 0x48;
    }
    else {
      uVar22 = 0xb;
      iVar12 = iVar12 * 0x6c;
    }
    local_878 = (**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,iVar12,uVar22);
    if (local_878 == 0) {
      return;
    }
    local_870 = (float *)0x0;
    auVar5._12_4_ = 0;
    local_848 = (float *)0x0;
    local_858 = local_8c8;
    uStack_850 = puStack_8c0;
    if ((*(short *)(param_1[1] + 0x18) == 0) ||
       (local_83c = 1, *(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_83c = 0;
    }
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb2];
      local_638 = pfVar29[0x14] - local_718;
      fStack_634 = pfVar29[0x15] - local_714;
      fStack_630 = pfVar29[0x16] - local_710;
      fStack_62c = pfVar29[0x17] - 0.0;
      *pfVar29 = local_638 * fVar41 + fStack_634 * fVar42 + fStack_630 * fVar44;
      *DAT_140c79df8 = *(undefined4 *)param_1[0xb2];
    }
    if ((*(short *)(param_1[1] + 0x18) == 0) || (*(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_8d0 = &local_7b8;
      local_7b8 = _DAT_140b7b240;
      uStack_7b0 = _DAT_140b7b248;
      uVar19 = (int)param_1[0xa5] * *(int *)((longlong)param_1 + 0x524);
    }
    else {
      local_8d0 = &local_8c8;
      uVar19 = *(int *)((longlong)param_1 + 0x524) * (int)param_1[0xa5];
    }
    local_8e8 = (float **)&local_848;
    local_8f0 = local_898;
    local_8f8 = CONCAT44(local_8f8._4_4_,fVar43);
    local_8d8 = fVar45;
    local_868 = auVar5;
    local_840 = fVar45;
    FUN_140321360(param_1,&local_878,(ulonglong)uVar19 + *plVar2);
    fVar8 = DAT_140b7a204;
    uVar35 = local_898._0_4_;
    uVar10 = local_898._4_4_;
    fVar33 = (float)uStack_890;
    fVar40 = uStack_890._4_4_;
    iVar12 = (int)param_1[0xa5];
    fVar45 = (float)((int)(longlong)
                          ((float)(*(int *)(param_1[0xb2] + 0x18) -
                                  *(int *)((ulonglong)
                                           (uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) +
                                           0x18 + *plVar2)) * fVar43) +
                    *(int *)((ulonglong)(uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) + 0x18
                            + *plVar2));
    uVar20 = (ulonglong)(uint)fVar45;
    uVar19 = 3;
    local_8b0 = uVar20;
    if ((int)param_1[0xa6] != 0) {
      do {
        pfVar29 = (float *)((ulonglong)(uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) +
                           *plVar2);
        if (*(int *)((longlong)param_1 + 0x54c) != 0) {
          local_618 = pfVar29[0x14] - (float)uVar35;
          fStack_614 = pfVar29[0x15] - (float)uVar10;
          fStack_610 = pfVar29[0x16] - fVar33;
          fStack_60c = pfVar29[0x17] - fVar40;
          fVar45 = local_618 * fVar41 + fStack_614 * fVar42 + fStack_610 * fVar44;
          *pfVar29 = fVar45;
          DAT_140c79df8[(int)uVar23 + 1] = fVar45;
        }
        local_870 = pfVar29;
        if (*(char *)param_1[0x9d] == '\0') {
          iVar13 = *DAT_140c63750;
          fVar45 = (float)FUN_1408fe170();
          iVar25 = DAT_140c42240;
          if (iVar13 < DAT_140c42240) {
            iVar25 = iVar13;
          }
          uVar34 = FUN_1408fc7f0(&PTR_PTR_140c42230,
                                 fVar45 * *(float *)(&DAT_140c42250 + (longlong)iVar25 * 4) *
                                 (float)(uint)((int)pfVar29[6] - (int)uVar20) * fVar8);
          local_848 = (float *)CONCAT44(uVar34,(undefined4)local_848);
        }
        FUN_1403220c0(param_1,&local_878);
        fVar45 = pfVar29[6];
        uVar20 = (ulonglong)(uint)fVar45;
        iVar12 = iVar12 + 1;
        if (iVar12 == (int)param_1[0xa4]) {
          iVar12 = 0;
        }
        uVar28 = (int)uVar23 + 1;
        uVar23 = (ulonglong)uVar28;
        uVar19 = local_8b8;
      } while (uVar28 < *(uint *)(param_1 + 0xa6));
    }
    local_8b0 = uVar20;
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb1];
      local_5f8 = pfVar29[0x14] - (float)uVar35;
      fStack_5f4 = pfVar29[0x15] - (float)uVar10;
      fStack_5f0 = pfVar29[0x16] - fVar33;
      fStack_5ec = pfVar29[0x17] - fVar40;
      *pfVar29 = local_5f8 * fVar41 + fStack_5f4 * fVar42 + fStack_5f0 * fVar44;
      DAT_140c79df8[(int)param_1[0xa6] + 1] = *(undefined4 *)param_1[0xb1];
    }
    if (*(char *)param_1[0x9d] == '\0') {
      iVar12 = *DAT_140c63750;
      auVar38._0_8_ = FUN_1408fe170();
      auVar38._8_8_ = extraout_XMM0_Qb;
      iVar13 = DAT_140c42240;
      if (iVar12 < DAT_140c42240) {
        iVar13 = iVar12;
      }
      auVar39._4_12_ = auVar38._4_12_;
      auVar39._0_4_ =
           (float)auVar38._0_8_ * *(float *)(&DAT_140c42250 + (longlong)iVar13 * 4) *
           (float)(uint)(*(int *)(param_1[0xb1] + 0x18) - (int)fVar45) * fVar8;
      uVar35 = FUN_1408fc7f0(auVar39._0_8_);
      local_848 = (float *)CONCAT44(uVar35,(undefined4)local_848);
    }
    local_870 = (float *)param_1[0xb1];
    FUN_1403220c0(param_1,&local_878);
    (**(code **)(*DAT_140c65670 + 0xe8))();
  }
  else {
    uVar19 = *(uint *)((longlong)param_1 + 0x55c);
    local_8b4 = ((int)param_1[0xa6] + 2) * uVar19;
    if (*(short *)(lVar31 + 0x404) == 0) {
      uVar22 = 10;
      iVar12 = local_8b4 * 0x18;
    }
    else {
      uVar22 = 0xb;
      iVar12 = local_8b4 * 0x24;
    }
    local_828 = (**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,iVar12,uVar22);
    if (local_828 == 0) {
      return;
    }
    local_820 = (float *)0x0;
    local_818 = local_8c8;
    uStack_810 = puStack_8c0;
    if ((*(short *)(param_1[1] + 0x18) == 0) ||
       (local_804 = 1, *(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_804 = 0;
    }
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb2];
      local_5d8 = pfVar29[0x14] - local_718;
      fStack_5d4 = pfVar29[0x15] - local_714;
      fStack_5d0 = pfVar29[0x16] - local_710;
      fStack_5cc = pfVar29[0x17] - 0.0;
      *pfVar29 = local_5d8 * fVar41 + fStack_5d4 * fVar42 + fStack_5d0 * fVar44;
      *DAT_140c79df8 = *(undefined4 *)param_1[0xb2];
    }
    if ((*(short *)(param_1[1] + 0x18) == 0) || (*(short *)(param_1[0x9d] + 0x404) == 1)) {
      local_8e8 = &local_758;
      local_758 = _DAT_140b7b240;
      uStack_750 = _DAT_140b7b248;
    }
    else {
      local_8e8 = &local_8c8;
    }
    local_8f0 = (undefined1 *)CONCAT44(local_8f0._4_4_,fVar45);
    local_8f8 = CONCAT44(local_8f8._4_4_,fVar43);
    local_808 = fVar45;
    FUN_140322ce0(param_1,&local_828,
                  (ulonglong)(uint)((int)param_1[0xa5] * *(int *)((longlong)param_1 + 0x524)) +
                  *plVar2);
    iVar12 = (int)param_1[0xa5];
    if ((int)param_1[0xa6] != 0) {
      do {
        local_820 = (float *)((ulonglong)(uint)(iVar12 * *(int *)((longlong)param_1 + 0x524)) +
                             *plVar2);
        if (*(int *)((longlong)param_1 + 0x54c) != 0) {
          local_648 = local_820[0x14] - local_718;
          fStack_644 = local_820[0x15] - local_714;
          fStack_640 = local_820[0x16] - local_710;
          fStack_63c = local_820[0x17] - 0.0;
          fVar45 = local_648 * fVar41 + fStack_644 * fVar42 + fStack_640 * fVar44;
          *local_820 = fVar45;
          DAT_140c79df8[(int)uVar23 + 1] = fVar45;
        }
        FUN_140323590(param_1,&local_828);
        iVar12 = iVar12 + 1;
        if (iVar12 == (int)param_1[0xa4]) {
          iVar12 = 0;
        }
        uVar28 = (int)uVar23 + 1;
        uVar23 = (ulonglong)uVar28;
      } while (uVar28 < *(uint *)(param_1 + 0xa6));
    }
    if (*(int *)((longlong)param_1 + 0x54c) != 0) {
      pfVar29 = (float *)param_1[0xb1];
      local_5b8 = pfVar29[0x14] - local_718;
      fStack_5b4 = pfVar29[0x15] - local_714;
      fStack_5b0 = pfVar29[0x16] - local_710;
      fStack_5ac = pfVar29[0x17] - 0.0;
      *pfVar29 = local_5b8 * fVar41 + fStack_5b4 * fVar42 + fStack_5b0 * fVar44;
      *DAT_140c79df8 = *(undefined4 *)param_1[0xb1];
    }
    local_820 = (float *)param_1[0xb1];
    FUN_140323590(param_1,&local_828);
    (**(code **)(*DAT_140c65670 + 0xe8))();
  }
  uVar23 = 0;
  if (*(int *)((longlong)param_1 + 0x54c) != 0) {
    FUN_1401c3280(&LAB_14031ce60,DAT_140c79de8,(int)param_1[0xa6] + 1);
  }
  sVar7 = (short)uVar19;
  if (*(char *)(param_1[0x9d] + 4) == '\x02') {
    iVar12 = (uVar19 - 2) * ((int)param_1[0xa6] + 1);
    local_8b8 = iVar12 * 6;
    psVar14 = (short *)(**(code **)(*DAT_140c65670 + 0xf0))(DAT_140c65670,iVar12 * 0xc);
    if (psVar14 == (short *)0x0) {
      return;
    }
    uVar28 = *(uint *)(param_1 + 0xa5);
    if ((int)param_1[0xa6] != -1) {
      uVar19 = uVar19 >> 1;
      uVar20 = uVar23;
      do {
        lVar31 = 2;
        uVar27 = uVar23;
        do {
          psVar21 = psVar14;
          uVar26 = uVar23;
          if (uVar19 != 1) {
            do {
              sVar11 = (short)uVar27;
              sVar6 = (short)uVar26;
              sVar17 = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4);
              if (((int)uVar26 + (int)uVar20 & 1U) == 1 - (uVar28 & 1)) {
                *psVar21 = sVar17 * sVar7 + sVar11 + sVar6;
                psVar21[1] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 +
                             sVar11 + sVar6;
                psVar21[2] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + 1 + sVar11
                             + sVar6;
                psVar21[3] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + 1 + sVar11
                             + sVar6;
                psVar21[4] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 +
                             sVar11 + sVar6;
                sVar17 = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1;
              }
              else {
                *psVar21 = (sVar17 + 1) * sVar7 + sVar11 + sVar6;
                psVar21[1] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + sVar11 +
                             sVar6;
                psVar21[2] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 + 1 +
                             sVar11 + sVar6;
                psVar21[3] = ((short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) + 1) * sVar7 + 1 +
                             sVar11 + sVar6;
                psVar21[4] = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4) * sVar7 + sVar11 +
                             sVar6;
                sVar17 = (short)*(undefined4 *)(DAT_140c79de8 + uVar20 * 4);
              }
              uVar24 = (int)uVar26 + 1;
              psVar14 = psVar21 + 6;
              psVar21[5] = sVar6 + 1 + sVar17 * sVar7 + sVar11;
              psVar21 = psVar14;
              uVar26 = (ulonglong)uVar24;
            } while (uVar24 < uVar19 - 1);
          }
          uVar27 = (ulonglong)((int)uVar27 + uVar19);
          lVar31 = lVar31 + -1;
        } while (lVar31 != 0);
        uVar24 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar24;
      } while (uVar24 < (int)param_1[0xa6] + 1U);
    }
    (**(code **)(*DAT_140c65670 + 0xf8))();
  }
  else {
    uVar28 = uVar19 - 1;
    iVar12 = ((int)param_1[0xa6] + 1) * uVar28;
    local_8b8 = iVar12 * 6;
    psVar14 = (short *)(**(code **)(*DAT_140c65670 + 0xf0))(DAT_140c65670,iVar12 * 0xc,0);
    if (psVar14 == (short *)0x0) {
      return;
    }
    uVar24 = *(uint *)(param_1 + 0xa5);
    uVar30 = 0;
    if ((int)param_1[0xa6] != -1) {
      do {
        iVar12 = *(int *)(DAT_140c79de8 + (ulonglong)uVar30 * 4) * uVar19;
        if (uVar28 != 0) {
          iVar13 = uVar19 + 1;
          sVar6 = (short)iVar13;
          iVar25 = iVar13 + iVar12;
          uVar23 = (ulonglong)uVar28;
          do {
            sVar17 = (short)iVar25;
            if ((((uVar30 - iVar13) - iVar12) + iVar25 & 1) == 1 - (uVar24 & 1)) {
              sVar18 = sVar17 + (sVar7 - sVar6);
              *psVar14 = sVar17 + -sVar6;
              psVar14[1] = sVar18;
              sVar11 = sVar17 + (1 - sVar6);
              psVar14[2] = sVar11;
              psVar14[3] = sVar11;
              psVar14[4] = sVar18;
              psVar14[5] = sVar17;
            }
            else {
              *psVar14 = sVar17 + (sVar7 - sVar6);
              sVar11 = sVar17 + -sVar6;
              psVar14[1] = sVar11;
              psVar14[2] = sVar17;
              psVar14[3] = sVar17;
              psVar14[4] = sVar11;
              psVar14[5] = sVar17 + (1 - sVar6);
            }
            psVar14 = psVar14 + 6;
            iVar25 = iVar25 + 1;
            uVar23 = uVar23 - 1;
          } while (uVar23 != 0);
        }
        uVar30 = uVar30 + 1;
      } while (uVar30 < (int)param_1[0xa6] + 1U);
    }
    (**(code **)(*DAT_140c65670 + 0xf8))();
  }
  if ((*(byte *)(param_1[0x9d] + 0x28) & 1) == 0) {
    fVar41 = *(float *)((longlong)param_1 + 0x574);
    if (fVar41 <= fVar9) {
      if (DAT_140b7a23c <= fVar41) goto LAB_140324d33;
      fVar41 = fVar41 + fVar9;
    }
    else {
      fVar41 = fVar41 - fVar9;
    }
    *(float *)((longlong)param_1 + 0x574) = fVar41;
  }
  else {
    fVar41 = *(float *)((longlong)param_1 + 0x574);
    fVar42 = *(float *)(param_1[0xb1] + 0xc) - *(float *)(param_1 + 0xa2);
    if (fVar41 <= fVar42) {
      if (fVar41 < fVar42 * DAT_140b7a23c) {
        *(float *)((longlong)param_1 + 0x574) = fVar41 + fVar42;
      }
    }
    else {
      *(float *)((longlong)param_1 + 0x574) = fVar41 - fVar42;
    }
  }
LAB_140324d33:
  uVar1 = *(ushort *)(param_1[0x9d] + 0x3c4);
  if ((uint)uVar1 < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,0,
               *(undefined8 *)(*(longlong *)(param_1[5] + 0x420) + 0x10 + (ulonglong)uVar1 * 0x18));
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,0);
  }
  if ((uint)*(ushort *)(param_1[0x9d] + 0x3dc) < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)
     ) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,1,
               *(undefined8 *)
                (*(longlong *)(param_1[5] + 0x420) + 0x10 +
                (ulonglong)*(ushort *)(param_1[0x9d] + 0x3dc) * 0x18));
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,1,0);
  }
  if ((uint)*(ushort *)(param_1[0x9d] + 0x3de) < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)
     ) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,2,
               *(undefined8 *)
                (*(longlong *)(param_1[5] + 0x420) + 0x10 +
                (ulonglong)*(ushort *)(param_1[0x9d] + 0x3de) * 0x18),0);
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,2,0,0);
  }
  if ((uint)*(ushort *)(param_1[0x9d] + 0x406) < *(uint *)(*(longlong *)(param_1[5] + 0x40) + 0x1c0)
     ) {
    (**(code **)(*DAT_140c65670 + 0x168))
              (DAT_140c65670,4,
               *(undefined8 *)
                (*(longlong *)(param_1[5] + 0x420) + 0x10 +
                (ulonglong)*(ushort *)(param_1[0x9d] + 0x406) * 0x18));
  }
  else {
    local_8f8 = 0;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,4);
  }
  (**(code **)(*DAT_140c65670 + 0x1d0))
            (DAT_140c65670,(int)param_1[0xaa],*(undefined4 *)((longlong)param_1 + 0x554),
             (int)param_1[0xab]);
  (**(code **)(*DAT_140c65670 + 0x198))(DAT_140c65670,*(undefined4 *)(param_1[1] + 0x24));
  uVar22 = 7;
  if (*(int *)(param_1[1] + 0x20) != 0) {
    uVar22 = 1;
  }
  (**(code **)(*DAT_140c65670 + 400))(DAT_140c65670,uVar22);
  (**(code **)(*DAT_140c65670 + 0x150))(DAT_140c65670,0);
  (**(code **)(*DAT_140c65670 + 0x140))
            (DAT_140c65670,
             *(undefined8 *)(*(longlong *)(*(longlong *)(param_1[5] + 0x10) + 0x10) + 0x838),
             (*(uint *)(param_1[0x9d] + 0x28) & 1) +
             ((uint)(*(short *)(param_1[1] + 0x18) == 2) +
             (uint)*(ushort *)(param_1[0x9d] + 0x404) * 2) * 2);
  local_8f8 = local_8f8 & 0xffffffff00000000;
  puVar15 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x100,0);
  lVar31 = local_888;
  if (puVar15 != (undefined4 *)0x0) {
    local_328 = &local_7f8;
    uStack_890 = param_6;
    local_898 = (undefined1  [8])local_328;
    local_320 = param_6;
    FUN_1401afb10(&local_328,&local_708);
    lVar31 = local_888;
    *puVar15 = local_708;
    puVar15[1] = local_6f8;
    puVar15[2] = local_6e8;
    puVar15[3] = local_6d8;
    puVar15[4] = uStack_704;
    puVar15[5] = uStack_6f4;
    puVar15[6] = uStack_6e4;
    puVar15[7] = uStack_6d4;
    puVar15[8] = uStack_700;
    puVar15[9] = uStack_6f0;
    puVar15[10] = uStack_6e0;
    puVar15[0xb] = uStack_6d0;
    puVar15[0xc] = uStack_6fc;
    puVar15[0xd] = uStack_6ec;
    puVar15[0xe] = uStack_6dc;
    puVar15[0xf] = uStack_6cc;
    puVar15[0x10] = (undefined4)local_7f8;
    puVar15[0x11] = (undefined4)local_7e8;
    puVar15[0x12] = (undefined4)local_7d8;
    puVar15[0x13] = (undefined4)local_7c8;
    puVar15[0x14] = local_7f8._4_4_;
    puVar15[0x15] = local_7e8._4_4_;
    puVar15[0x16] = local_7d8._4_4_;
    puVar15[0x17] = local_7c8._4_4_;
    puVar15[0x18] = (undefined4)uStack_7f0;
    puVar15[0x19] = (undefined4)uStack_7e0;
    puVar15[0x1a] = (undefined4)uStack_7d0;
    puVar15[0x1b] = (undefined4)uStack_7c0;
    puVar15[0x1c] = uStack_7f0._4_4_;
    puVar15[0x1d] = uStack_7e0._4_4_;
    puVar15[0x1e] = uStack_7d0._4_4_;
    puVar15[0x1f] = uStack_7c0._4_4_;
    puVar15[0x20] = (int)param_1[0xa2];
    puVar15[0x21] = *(undefined4 *)((longlong)param_1 + 0x514);
    lVar3 = param_1[0x9f];
    *(longlong *)(puVar15 + 0x24) = param_1[0x9e];
    *(longlong *)(puVar15 + 0x26) = lVar3;
    lVar3 = param_1[0xa1];
    *(longlong *)(puVar15 + 0x28) = param_1[0xa0];
    *(longlong *)(puVar15 + 0x2a) = lVar3;
    lVar3 = param_1[0x9d];
    if (((*(uint *)(lVar3 + 0x28) & 5) == 0) || ((*(uint *)(lVar3 + 0x28) >> 9 & 1) == 0)) {
      local_8b0 = 0;
      uStack_8a8 = 0x3f800000;
      uStack_8a4 = 0x3f800000;
      *(undefined8 *)(puVar15 + 0x2c) = 0;
      *(undefined8 *)(puVar15 + 0x2e) = 0x3f8000003f800000;
    }
    else {
      fVar41 = *(float *)(lVar3 + 0x3ec);
      fVar42 = *(float *)(lVar3 + 0x3f0);
      uVar19 = *(uint *)((longlong)param_1 + 0x57c);
      bVar16 = (byte)*(undefined4 *)(lVar3 + 0x3f4);
      puVar15[0x2c] = (float)((1 << (bVar16 & 0x1f)) - 1U & uVar19) * fVar41;
      puVar15[0x2d] = (float)(uVar19 >> (bVar16 & 0x1f)) * fVar42;
      puVar15[0x2e] = fVar41;
      puVar15[0x2f] = fVar42;
    }
    uVar22 = *(undefined8 *)(local_888 + 0xb8);
    *(undefined8 *)(puVar15 + 0x30) = *(undefined8 *)(local_888 + 0xb0);
    *(undefined8 *)(puVar15 + 0x32) = uVar22;
    FUN_140262750(local_888,puVar15 + 0x34,local_880);
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  bVar32 = (param_10 & 0x224) != 0;
  lVar3 = param_1[1];
  if ((*(int *)(lVar3 + 0x14) == 0) ||
     (iVar12 = 1, (**(byte **)(*(longlong *)(param_1[5] + 0x10) + 0x10) & 1) != 0)) {
    iVar12 = 0;
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,
             *(undefined8 *)(*(longlong *)(*(longlong *)(param_1[5] + 0x10) + 0x10) + 0x840),
             *(int *)(lVar3 + 0x1c) +
             (iVar12 + ((~param_12 & 1) +
                       ((uint)(0.0 < *(float *)(lVar31 + 0x2f4)) +
                       (uint)(*(int *)(lVar3 + 0x20) != 0) * 2 +
                       ((uint)*(ushort *)(param_1[0x9d] + 0x3cc) * 2 +
                       ((uint)*(ushort *)(lVar3 + 0x18) +
                       ((uint)bVar32 + (uint)*(ushort *)(param_1[0x9d] + 0x404) + (uint)bVar32 * 2)
                       * 3) * 10) * 2) * 2) * 2) * 4);
  local_8f8 = local_8f8 & 0xffffffff00000000;
  puVar15 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x130,0,0);
  if (puVar15 != (undefined4 *)0x0) {
    *puVar15 = *(undefined4 *)(param_1[0x9d] + 0x3d0);
    fVar41 = *(float *)(param_1[0x9d] + 0x3d4) - *(float *)(param_1[0x9d] + 0x3d0);
    if (fVar41 == 0.0) {
      fVar41 = 0.0;
    }
    else {
      fVar41 = fVar9 / fVar41;
    }
    puVar15[1] = fVar41;
    puVar15[2] = *(undefined4 *)(param_1[0x9d] + 0x400);
    *(undefined8 *)(puVar15 + 4) = *(undefined8 *)(*(longlong *)(param_1[5] + 0x10) + 0x550);
    lVar3 = *(longlong *)(param_1[5] + 0x10);
    local_788 = *(float *)(lVar3 + 0x550) * _DAT_140b7ac50;
    fStack_784 = *(float *)(lVar3 + 0x554) * _UNK_140b7ac54;
    fStack_780 = *(float *)(lVar3 + 0x558) * _UNK_140b7ac58;
    fStack_77c = *(float *)(lVar3 + 0x55c) * _UNK_140b7ac5c;
    *(ulonglong *)(puVar15 + 6) = CONCAT44(fStack_784,local_788);
    fVar41 = local_838[1];
    auVar4._4_4_ = *local_838 - fVar41;
    auVar4._0_4_ = *local_838 * fVar41;
    auVar4._8_4_ = fVar41;
    auVar4._12_4_ = 0;
    *(undefined1 (*) [16])(puVar15 + 8) = auVar4;
    lVar3 = param_1[5];
    if (*(float *)(lVar3 + 0x10c) == 0.0) {
      pfVar29 = (float *)&local_778;
      local_778 = _DAT_140b7a740;
      uStack_770 = _UNK_140b7a748;
    }
    else {
      pfVar29 = (float *)&local_768;
      local_768 = *(undefined8 *)(lVar3 + 0x100);
      uStack_760 = *(undefined8 *)(lVar3 + 0x108);
    }
    fVar41 = *(float *)(param_1 + 0xc);
    fVar42 = pfVar29[1];
    fVar45 = pfVar29[2];
    fVar44 = pfVar29[3];
    puVar15[0x48] = *pfVar29 * fVar41;
    puVar15[0x49] = fVar42 * fVar41;
    puVar15[0x4a] = fVar45 * fVar41;
    puVar15[0x4b] = fVar44 * fVar41;
    FUN_140262d50(lVar31,puVar15 + 0xc);
    uVar22 = *(undefined8 *)(lVar31 + 0xb8);
    *(undefined8 *)(puVar15 + 0x28) = *(undefined8 *)(lVar31 + 0xb0);
    *(undefined8 *)(puVar15 + 0x2a) = uVar22;
    puVar15[0x2c] = *(undefined4 *)(lVar31 + 0x90);
    puVar15[0x2d] = *(undefined4 *)(lVar31 + 0x94);
    puVar15[0x2e] = *(undefined4 *)(lVar31 + 0x98);
    puVar15[0x2f] = *(undefined4 *)(lVar31 + 0x2b4);
    puVar15[0x30] = *(undefined4 *)(lVar31 + 0xa0);
    puVar15[0x31] = *(undefined4 *)(lVar31 + 0xa4);
    puVar15[0x32] = *(undefined4 *)(lVar31 + 0xa8);
    puVar15[0x33] = *(undefined4 *)(lVar31 + 0x2b0);
    FUN_140262750();
    uVar22 = *(undefined8 *)(*(longlong *)(param_1[5] + 0x10) + 0x568);
    *(undefined8 *)(puVar15 + 0x40) = *(undefined8 *)(*(longlong *)(param_1[5] + 0x10) + 0x560);
    *(undefined8 *)(puVar15 + 0x42) = uVar22;
    puVar15[0x44] = *(undefined4 *)(param_11 + 0x2c);
    fVar41 = DAT_140b7a1cc;
    if (DAT_140b79cc4 < (float)((uint)*(float *)(param_1[1] + 0x88) & DAT_140b7b500)) {
      fVar41 = fVar9 / *(float *)(param_1[1] + 0x88);
    }
    puVar15[0x45] = fVar41;
    puVar15[0x46] = *(undefined4 *)(param_1[0x9d] + 0x3d8);
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  local_8e0 = 1;
  local_8e8 = (float **)((ulonglong)local_8e8 & 0xffffffff00000000);
  local_8f0 = (undefined1 *)CONCAT44(local_8f0._4_4_,local_8b4);
  local_8f8 = local_8f8 & 0xffffffff00000000;
  (**(code **)(*DAT_140c65670 + 0x290))(DAT_140c65670,3,0,local_8b8);
  return;
}



==== FUN_1403258c0 @ 1403258c0 size 2747 ====
CALLERS: FUN_14030e7b0
CALLEES: FUN_1407e4830 FUN_1400290d0 FUN_1401c3280 FUN_14018b900 memcpy __security_check_cookie FUN_14018b280 FUN_14030e690 FUN_14030e510

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1403258c0(ulonglong param_1,longlong param_2,uint param_3,void *param_4)

{
  undefined1 auVar1 [16];
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  void *pvVar6;
  short *psVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  ulonglong *puVar10;
  longlong lVar11;
  ushort *puVar12;
  longlong lVar13;
  uint uVar14;
  undefined4 *puVar15;
  longlong *plVar16;
  ushort uVar17;
  uint uVar18;
  undefined4 *puVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  undefined4 *puVar22;
  longlong lVar23;
  ulonglong uVar24;
  short sVar25;
  undefined4 *puVar26;
  ushort uVar27;
  ushort uVar28;
  ushort uVar29;
  undefined1 auStack_88 [8];
  ushort auStack_80 [4];
  short asStack_78 [8];
  uint local_68;
  longlong local_60;
  undefined4 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = DAT_140c0f7b0 ^ (ulonglong)auStack_88;
  *(longlong *)(param_1 + 8) = param_2;
  lVar23 = *(longlong *)(param_2 + 0x40);
  lVar13 = *(longlong *)(param_2 + 0x38);
  *(uint *)(param_1 + 0x14) = param_3;
  uVar5 = SUB168(ZEXT816(4) * ZEXT416(param_3),0);
  if (SUB168(ZEXT816(4) * ZEXT416(param_3),8) != 0) {
    uVar5 = 0xffffffffffffffff;
  }
  local_60 = lVar23;
  pvVar6 = (void *)FUN_14018b280(uVar5,0);
  *(void **)(param_1 + 0x18) = pvVar6;
  memcpy(pvVar6,param_4,(ulonglong)*(uint *)(param_1 + 0x14) << 2);
  auVar1 = ZEXT816(4) * ZEXT416(*(uint *)(param_1 + 0x14));
  uVar5 = auVar1._0_8_;
  if (auVar1._8_8_ != 0) {
    uVar5 = 0xffffffffffffffff;
  }
  pvVar6 = (void *)FUN_14018b280(uVar5,0);
  *(void **)(param_1 + 0x20) = pvVar6;
  memcpy(pvVar6,param_4,(ulonglong)*(uint *)(param_1 + 0x14) << 2);
  FUN_1401c3280(FUN_1403264c0,*(undefined8 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x14),
                *(undefined8 *)(lVar23 + 0x88));
  uVar18 = *(uint *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x30) = 0;
  if (uVar18 != 0) {
    lVar11 = *(longlong *)(param_1 + 0x20);
    local_68 = 0;
    uVar24 = 0;
    do {
      local_58 = *(undefined4 **)(lVar23 + 0x88);
      uVar14 = (int)uVar24 + 1;
      uVar21 = (ulonglong)uVar14;
      puVar22 = local_58 + (ulonglong)*(uint *)(lVar11 + uVar24 * 4) * 0x1c;
      uVar5 = *(undefined8 *)(puVar22 + 10);
      local_50 = uVar5;
      uVar5 = local_50;
      local_48 = *(undefined8 *)(puVar22 + 0xc);
      if (uVar14 < uVar18) {
        sVar25 = *(short *)(puVar22 + 4);
        local_50._6_2_ = (ushort)((ulonglong)uVar5 >> 0x30);
        local_50._4_2_ = (ushort)((ulonglong)uVar5 >> 0x20);
        local_50._2_2_ = (ushort)((ulonglong)uVar5 >> 0x10);
        local_50._0_2_ = (ushort)uVar5;
        puVar15 = local_58;
        uVar17 = local_50._6_2_;
        uVar28 = local_50._4_2_;
        uVar27 = (ushort)local_50;
        uVar29 = local_50._2_2_;
        local_50 = uVar5;
        do {
          puVar15 = puVar15 + (ulonglong)*(uint *)(lVar11 + uVar21 * 4) * 0x1c;
          if (((((sVar25 != *(short *)(puVar15 + 4)) ||
                (*(short *)((longlong)puVar22 + 0x12) != *(short *)((longlong)puVar15 + 0x12))) ||
               (*(short *)((longlong)puVar22 + 0x16) != *(short *)((longlong)puVar15 + 0x16))) ||
              ((*(ushort *)(puVar22 + 6) != *(ushort *)(puVar15 + 6) ||
               (*(short *)(puVar22 + 7) != *(short *)(puVar15 + 7))))) ||
             ((*(short *)((longlong)puVar22 + 0x1a) != *(short *)((longlong)puVar15 + 0x1a) ||
              (*(char *)(puVar22 + 0xe) != *(char *)(puVar15 + 0xe))))) break;
          uVar18 = 0;
          psVar7 = (short *)(puVar15 + 0xc);
          do {
            if (((psVar7[-4] &
                 *(ushort *)((longlong)auStack_80 + -(longlong)puVar15 + (longlong)psVar7)) == 0) ||
               (*(short *)((longlong)asStack_78 + -(longlong)puVar15 + (longlong)psVar7) != *psVar7)
               ) {
              if (uVar18 < 4) goto LAB_140325b1e;
              break;
            }
            uVar18 = uVar18 + 1;
            psVar7 = psVar7 + 1;
          } while (uVar18 < 4);
          if ((puVar22 != puVar15) &&
             ((*(byte *)((ulonglong)*(ushort *)(puVar22 + 6) * 0xb8 + *(longlong *)(lVar13 + 0xf8))
              & 1) != 0)) {
LAB_140325b1e:
            uVar18 = *(uint *)(param_1 + 0x14);
            break;
          }
          uVar27 = uVar27 & *(ushort *)(puVar15 + 10);
          uVar29 = uVar29 & *(ushort *)((longlong)puVar15 + 0x2a);
          uVar28 = uVar28 & *(ushort *)(puVar15 + 0xb);
          uVar17 = uVar17 & *(ushort *)((longlong)puVar15 + 0x2e);
          uVar18 = *(uint *)(param_1 + 0x14);
          lVar11 = *(longlong *)(param_1 + 0x20);
          sVar25 = *(short *)(puVar22 + 4);
          uVar14 = (int)uVar21 + 1;
          uVar21 = (ulonglong)uVar14;
          local_50 = CONCAT26(uVar17,CONCAT24(uVar28,CONCAT22(uVar29,uVar27)));
          puVar15 = local_58;
        } while (uVar14 < uVar18);
        lVar11 = *(longlong *)(param_1 + 0x20);
        lVar23 = local_60;
      }
      local_68 = local_68 + 1;
      *(uint *)(param_1 + 0x30) = local_68;
      uVar24 = uVar21;
    } while ((uint)uVar21 < uVar18);
  }
  auVar1 = ZEXT816(0x70) * ZEXT416(*(uint *)(param_1 + 0x30));
  uVar5 = auVar1._0_8_;
  if (auVar1._8_8_ != 0) {
    uVar5 = 0xffffffffffffffff;
  }
  uVar5 = FUN_14018b280(uVar5,0);
  *(undefined8 *)(param_1 + 0x40) = uVar5;
  auVar1 = ZEXT816(8) * ZEXT416(*(uint *)(param_1 + 0x30));
  uVar5 = auVar1._0_8_;
  if (auVar1._8_8_ != 0) {
    uVar5 = 0xffffffffffffffff;
  }
  uVar5 = FUN_14018b280(uVar5,0);
  uVar21 = 0;
  *(undefined8 *)(param_1 + 0x48) = uVar5;
  local_68 = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  uVar24 = uVar21;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      lVar11 = uVar21 * 4;
      puVar15 = (undefined4 *)(uVar24 * 0x70 + *(longlong *)(param_1 + 0x40));
      puVar22 = (undefined4 *)(*(longlong *)(param_1 + 0x48) + uVar24 * 8);
      uVar14 = (int)uVar21 + 1;
      uVar21 = (ulonglong)uVar14;
      puVar26 = (undefined4 *)
                ((ulonglong)*(uint *)(*(longlong *)(param_1 + 0x20) + lVar11) * 0x70 +
                *(longlong *)(lVar23 + 0x88));
      *puVar15 = *puVar26;
      puVar15[1] = puVar26[1];
      puVar15[2] = puVar26[2];
      puVar15[3] = puVar26[3];
      *(undefined2 *)(puVar15 + 4) = *(undefined2 *)(puVar26 + 4);
      *(undefined2 *)((longlong)puVar15 + 0x12) = *(undefined2 *)((longlong)puVar26 + 0x12);
      *(undefined2 *)(puVar15 + 5) = *(undefined2 *)(puVar26 + 5);
      *(undefined2 *)((longlong)puVar15 + 0x16) = *(undefined2 *)((longlong)puVar26 + 0x16);
      *(undefined2 *)(puVar15 + 6) = *(undefined2 *)(puVar26 + 6);
      *(undefined2 *)((longlong)puVar15 + 0x1a) = *(undefined2 *)((longlong)puVar26 + 0x1a);
      *(undefined2 *)(puVar15 + 7) = *(undefined2 *)(puVar26 + 7);
      *(undefined2 *)((longlong)puVar15 + 0x1e) = *(undefined2 *)((longlong)puVar26 + 0x1e);
      *(undefined2 *)(puVar15 + 8) = *(undefined2 *)(puVar26 + 8);
      *(undefined2 *)((longlong)puVar15 + 0x22) = *(undefined2 *)((longlong)puVar26 + 0x22);
      *(undefined2 *)(puVar15 + 9) = *(undefined2 *)(puVar26 + 9);
      *(undefined2 *)((longlong)puVar15 + 0x26) = *(undefined2 *)((longlong)puVar26 + 0x26);
      *(undefined8 *)(puVar15 + 10) = *(undefined8 *)(puVar26 + 10);
      *(undefined8 *)(puVar15 + 0xc) = *(undefined8 *)(puVar26 + 0xc);
      *(undefined1 *)(puVar15 + 0xe) = *(undefined1 *)(puVar26 + 0xe);
      *(undefined1 *)((longlong)puVar15 + 0x39) = *(undefined1 *)((longlong)puVar26 + 0x39);
      *(undefined1 *)((longlong)puVar15 + 0x3a) = *(undefined1 *)((longlong)puVar26 + 0x3a);
      uVar5 = *(undefined8 *)(puVar26 + 0x12);
      *(undefined8 *)(puVar15 + 0x10) = *(undefined8 *)(puVar26 + 0x10);
      *(undefined8 *)(puVar15 + 0x12) = uVar5;
      uVar4 = puVar26[0x15];
      uVar2 = puVar26[0x16];
      uVar3 = puVar26[0x17];
      puVar15[0x14] = puVar26[0x14];
      puVar15[0x15] = uVar4;
      puVar15[0x16] = uVar2;
      puVar15[0x17] = uVar3;
      puVar15[0x18] = puVar26[0x18];
      puVar15[0x19] = puVar26[0x19];
      puVar15[0x1a] = puVar26[0x1a];
      uVar4 = *(undefined4 *)(param_1 + 0x2c);
      *(undefined2 *)((longlong)puVar15 + 0x1e) = 0xffff;
      *(undefined4 *)((longlong)puVar15 + 0x22) = 0;
      *(undefined2 *)((longlong)puVar15 + 0x26) = 0;
      *puVar15 = uVar4;
      uVar18 = (uint)uVar24;
      if (uVar14 < *(uint *)(param_1 + 0x14)) {
        while ((((puVar19 = (undefined4 *)
                            ((ulonglong)*(uint *)(*(longlong *)(param_1 + 0x20) + uVar21 * 4) * 0x70
                            + *(longlong *)(local_60 + 0x88)), lVar23 = local_60, uVar18 = local_68,
                 *(short *)(puVar26 + 4) == *(short *)(puVar19 + 4) &&
                 (*(short *)((longlong)puVar26 + 0x12) == *(short *)((longlong)puVar19 + 0x12))) &&
                (*(short *)((longlong)puVar26 + 0x16) == *(short *)((longlong)puVar19 + 0x16))) &&
               (((*(ushort *)(puVar26 + 6) == *(ushort *)(puVar19 + 6) &&
                 (*(short *)(puVar26 + 7) == *(short *)(puVar19 + 7))) &&
                ((*(short *)((longlong)puVar26 + 0x1a) == *(short *)((longlong)puVar19 + 0x1a) &&
                 (*(char *)(puVar26 + 0xe) == *(char *)(puVar19 + 0xe)))))))) {
          uVar14 = 0;
          puVar12 = (ushort *)(puVar15 + 10);
          do {
            if (((*puVar12 &
                 *(ushort *)(((longlong)puVar19 - (longlong)puVar15) + (longlong)puVar12)) == 0) ||
               (puVar12[4] !=
                *(ushort *)(((longlong)puVar19 - (longlong)puVar15) + 8 + (longlong)puVar12))) {
              if (uVar14 < 4) goto LAB_140325e3d;
              break;
            }
            uVar14 = uVar14 + 1;
            puVar12 = puVar12 + 1;
          } while (uVar14 < 4);
          if ((puVar26 != puVar19) &&
             ((*(byte *)((ulonglong)*(ushort *)(puVar26 + 6) * 0xb8 + *(longlong *)(lVar13 + 0xf8))
              & 1) != 0)) break;
          puVar15[2] = puVar15[2] + puVar19[2];
          if ((uint)puVar19[1] < (uint)puVar15[1]) {
            puVar15[3] = puVar15[3] + (puVar15[1] - puVar19[1]);
            puVar15[1] = puVar19[1];
          }
          if ((uint)(puVar15[1] + puVar15[3]) < (uint)(puVar19[3] + puVar19[1])) {
            puVar15[3] = (puVar19[3] - puVar15[1]) + puVar19[1];
          }
          if (*(ushort *)(puVar15 + 5) < *(ushort *)(puVar19 + 5)) {
            *(ushort *)(puVar15 + 5) = *(ushort *)(puVar19 + 5);
          }
          uVar14 = (int)uVar21 + 1;
          uVar21 = (ulonglong)uVar14;
          *(ushort *)(puVar15 + 10) = *(ushort *)(puVar15 + 10) & *(ushort *)(puVar19 + 10);
          *(ushort *)((longlong)puVar15 + 0x2a) =
               *(ushort *)((longlong)puVar15 + 0x2a) & *(ushort *)((longlong)puVar19 + 0x2a);
          *(ushort *)(puVar15 + 0xb) = *(ushort *)(puVar15 + 0xb) & *(ushort *)(puVar19 + 0xb);
          *(ushort *)((longlong)puVar15 + 0x2e) =
               *(ushort *)((longlong)puVar15 + 0x2e) & *(ushort *)((longlong)puVar19 + 0x2e);
          if (*(uint *)(param_1 + 0x14) <= uVar14) break;
        }
      }
LAB_140325e3d:
      local_58 = puVar22;
      uVar4 = FUN_14030e510(*(undefined8 *)(param_1 + 8),puVar15);
      *puVar22 = uVar4;
      uVar4 = FUN_14030e690(*(undefined8 *)(param_1 + 8),puVar15);
      local_68 = uVar18 + 1;
      uVar24 = (ulonglong)local_68;
      puVar22[1] = uVar4;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + puVar15[2];
    } while ((uint)uVar21 < *(uint *)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(lVar23 + 0x18);
  if (*(uint *)(lVar13 + 0x1c0) != 0) {
    auVar1 = ZEXT816(4) * ZEXT416(*(uint *)(lVar13 + 0x1c0));
    uVar5 = auVar1._0_8_;
    if (auVar1._8_8_ != 0) {
      uVar5 = 0xffffffffffffffff;
    }
    uVar5 = FUN_14018b280(uVar5,0);
    *(undefined8 *)(param_1 + 0x50) = uVar5;
    FUN_1407e4830(uVar5,0,(ulonglong)*(uint *)(lVar13 + 0x1c0) << 2);
    uVar21 = 0;
    uVar24 = uVar21;
    if (*(int *)(param_1 + 0x30) != 0) {
      do {
        lVar23 = (ulonglong)*(ushort *)(uVar24 * 0x70 + 0x16 + *(longlong *)(param_1 + 0x40)) * 0x30
                 + *(longlong *)(lVar13 + 0x1f8);
        uVar20 = uVar21;
        if (*(int *)(lVar23 + 0x20) != 0) {
          do {
            puVar12 = (ushort *)(uVar20 * 0x128 + *(longlong *)(lVar23 + 0x28));
            uVar18 = (uint)*puVar12;
            if (uVar18 < *(uint *)(lVar13 + 0x1c0)) {
              *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar18 * 4) = 1;
            }
            uVar18 = (uint)puVar12[1];
            if (uVar18 < *(uint *)(lVar13 + 0x1c0)) {
              *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar18 * 4) = 1;
            }
            uVar18 = (int)uVar20 + 1;
            uVar20 = (ulonglong)uVar18;
          } while (uVar18 < *(uint *)(lVar23 + 0x20));
        }
        uVar18 = (int)uVar24 + 1;
        uVar24 = (ulonglong)uVar18;
      } while (uVar18 < *(uint *)(param_1 + 0x30));
    }
    uVar24 = uVar21;
    if (*(int *)(lVar13 + 0x318) != 0) {
      do {
        lVar23 = uVar24 * 400 + *(longlong *)(lVar13 + 800);
        uVar18 = (uint)*(ushort *)(lVar23 + 6);
        if (uVar18 < *(uint *)(lVar13 + 0x1c0)) {
          *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar18 * 4) = 1;
        }
        uVar18 = (uint)*(ushort *)(lVar23 + 8);
        if (uVar18 < *(uint *)(lVar13 + 0x1c0)) {
          *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar18 * 4) = 1;
        }
        uVar18 = (int)uVar24 + 1;
        uVar24 = (ulonglong)uVar18;
      } while (uVar18 < *(uint *)(lVar13 + 0x318));
    }
    uVar24 = uVar21;
    if (*(int *)(lVar13 + 0x560) != 0) {
      do {
        lVar23 = uVar24 * 0xa0 + *(longlong *)(lVar13 + 0x568);
        if ((uint)*(ushort *)(lVar23 + 10) < *(uint *)(lVar13 + 0x1c0)) {
          *(undefined4 *)
           (*(longlong *)(param_1 + 0x50) + (ulonglong)(uint)*(ushort *)(lVar23 + 10) * 4) = 1;
        }
        if ((uint)*(ushort *)(lVar23 + 4) < *(uint *)(lVar13 + 0x1c0)) {
          *(undefined4 *)
           (*(longlong *)(param_1 + 0x50) + (ulonglong)(uint)*(ushort *)(lVar23 + 4) * 4) = 1;
        }
        if ((*(ushort *)(lVar23 + 0xe) != 0xffff) &&
           (lVar23 = (ulonglong)*(ushort *)(lVar23 + 0xe) * 0x30 + *(longlong *)(lVar13 + 0x1f8),
           uVar20 = uVar21, *(int *)(lVar23 + 0x20) != 0)) {
          do {
            puVar12 = (ushort *)(uVar20 * 0x128 + *(longlong *)(lVar23 + 0x28));
            uVar18 = (uint)*puVar12;
            if (uVar18 < *(uint *)(lVar13 + 0x1c0)) {
              *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar18 * 4) = 1;
            }
            uVar18 = (uint)puVar12[1];
            if (uVar18 < *(uint *)(lVar13 + 0x1c0)) {
              *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar18 * 4) = 1;
            }
            uVar18 = (int)uVar20 + 1;
            uVar20 = (ulonglong)uVar18;
          } while (uVar18 < *(uint *)(lVar23 + 0x20));
        }
        uVar18 = (int)uVar24 + 1;
        uVar24 = (ulonglong)uVar18;
      } while (uVar18 < *(uint *)(lVar13 + 0x560));
    }
    uVar24 = uVar21;
    if (*(int *)(lVar13 + 0x2f8) != 0) {
      do {
        lVar23 = *(longlong *)(lVar13 + 0x300) + uVar21;
        if (*(int *)(lVar23 + 4) == 0) {
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x90) + 0x978);
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x90) + 0x994);
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x90) + 0x996);
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x90) + 0x99a);
LAB_1403261bd:
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
        }
        else if (*(int *)(lVar23 + 4) == 1) {
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x98) + 0x3c4);
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x98) + 0x3dc);
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x98) + 0x3de);
          if ((uint)uVar17 < *(uint *)(lVar13 + 0x1c0)) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x50) + (ulonglong)uVar17 * 4) = 1;
          }
          uVar17 = *(ushort *)(*(longlong *)(lVar23 + 0x98) + 0x406);
          goto LAB_1403261bd;
        }
        uVar24 = uVar24 + 1;
        uVar21 = uVar21 + 0xa0;
      } while (uVar24 < *(uint *)(lVar13 + 0x2f8));
    }
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  uVar18 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x38) + 0x180);
  uVar24 = CONCAT44(0,uVar18);
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar24;
  uVar5 = SUB168(ZEXT816(4) * auVar1,0);
  if (SUB168(ZEXT816(4) * auVar1,8) != 0) {
    uVar5 = 0xffffffffffffffff;
  }
  lVar23 = FUN_14018b280(uVar5);
  FUN_1407e4830(lVar23,0,uVar24 * 4);
  puVar9 = (ulonglong *)0x0;
  if (*(uint *)(param_1 + 0x30) != 0) {
    uVar24 = (ulonglong)*(uint *)(param_1 + 0x30);
    puVar10 = puVar9;
    do {
      uVar17 = *(ushort *)((longlong)puVar10 + *(longlong *)(param_1 + 0x40) + 0x10);
      uVar14 = (uint)*(ushort *)((longlong)puVar10 + *(longlong *)(param_1 + 0x40) + 0x12) +
               (uint)uVar17;
      if (uVar17 < uVar14) {
        lVar13 = (ulonglong)(uint)uVar17 * 2;
        uVar21 = (ulonglong)(uVar14 - uVar17);
        do {
          uVar17 = *(ushort *)
                    (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x38) + 0x1b8) +
                    lVar13);
          if ((uVar17 < uVar18) && (*(int *)(lVar23 + (ulonglong)uVar17 * 4) == 0)) {
            *(undefined4 *)(lVar23 + (ulonglong)uVar17 * 4) = 1;
            *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
          }
          lVar13 = lVar13 + 2;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
      puVar10 = puVar10 + 0xe;
      uVar24 = uVar24 - 1;
    } while (uVar24 != 0);
  }
  FUN_14018b900(lVar23);
  puVar10 = (ulonglong *)(*(longlong *)(param_1 + 8) + 0x1d8);
  if (*(longlong *)(param_1 + 0x60) == 0) {
    *(ulonglong **)(param_1 + 0x60) = puVar10;
    puVar8 = (ulonglong *)(param_1 + 0x68);
    *puVar8 = *puVar10;
    *puVar10 = param_1;
    if (*puVar8 != 0) {
      *(ulonglong **)(*puVar8 + 0x60) = puVar8;
    }
  }
  lVar23 = *(longlong *)(param_1 + 8);
  local_50 = CONCAT44(local_50._4_4_,*(undefined4 *)(param_1 + 0x14));
  local_48 = *(ulonglong *)(param_1 + 0x18);
  plVar16 = (longlong *)(lVar23 + 0x1e0);
  if (*plVar16 == *(longlong *)(lVar23 + 0x1e8)) {
    FUN_1400290d0(plVar16);
  }
  uVar24 = (**(code **)(lVar23 + 0x1f8))(&local_50);
  puVar10 = (ulonglong *)
            (*(longlong *)(lVar23 + 0x1f0) + (uVar24 % *(ulonglong *)(lVar23 + 0x1e8)) * 8);
  puVar8 = (ulonglong *)FUN_14018b280(0x28);
  if (puVar8 != (ulonglong *)0x0) {
    uVar21 = *puVar10;
    *puVar8 = uVar24;
    puVar8[1] = uVar21;
    puVar8[2] = local_50;
    puVar8[4] = param_1;
    puVar8[3] = local_48;
    puVar9 = puVar8;
  }
  *puVar10 = (ulonglong)puVar9;
  *plVar16 = *plVar16 + 1;
  return 0;
}



==== FUN_140327210 @ 140327210 size 160 ====
CALLERS: FUN_140373540 FUN_14030dbb0
CALLEES:

void FUN_140327210(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar1 = 1;
  lVar4 = 0;
  puVar2 = (uint *)(param_1 + 0xb0);
  lVar3 = 0xb;
  do {
    if ((uVar1 & *(ushort *)(param_2 + 6)) != 0) {
      *puVar2 = (uint)*(byte *)(lVar4 + 8 + param_2);
      *(ulonglong *)(param_1 + lVar4 * 8) =
           (ulonglong)*(byte *)(lVar4 + 0x13 + param_2) + *(longlong *)(param_2 + 0x28);
      *(ulonglong *)(param_1 + 0x58 + lVar4 * 8) = (ulonglong)*(byte *)(param_2 + 4);
    }
    uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    lVar4 = lVar4 + 1;
    puVar2 = puVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if ((*(ushort *)(param_2 + 6) & 0x300) == 0x100) {
    *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0xd0);
    *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(param_1 + 0x98);
  }
  return;
}



==== FUN_14032c3a0 @ 14032c3a0 size 294 ====
CALLERS:
CALLEES:

ulonglong FUN_14032c3a0(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort *puVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
  uVar3 = *(ulonglong *)(param_4 + 0x30);
  uVar4 = *(ulonglong *)(param_3 + 0x30);
  uVar2 = *(uint *)(param_3 + 0x40);
  lVar5 = *(longlong *)(uVar3 + 0x40);
  lVar6 = *(longlong *)(uVar4 + 0x40);
  lVar9 = (ulonglong)*(uint *)(param_4 + 0x40) * 400 + *(longlong *)(lVar5 + 800);
  lVar7 = *(longlong *)(lVar6 + 800);
  uVar12 = 0;
  puVar11 = (ushort *)(lVar9 + 6);
  do {
    uVar1 = *(ushort *)((((ulonglong)uVar2 * 400 + lVar7) - lVar9) + (longlong)puVar11);
    uVar13 = 0xffffffffffffffff;
    if (((uint)uVar1 < *(uint *)(lVar6 + 0x1c0)) &&
       (plVar8 = *(longlong **)(*(longlong *)(uVar4 + 0x420) + 0x10 + (ulonglong)uVar1 * 0x18),
       plVar8 != (longlong *)0x0)) {
      uVar13 = (**(code **)(*plVar8 + 0x40))();
    }
    uVar10 = 0xffffffffffffffff;
    if (((uint)*puVar11 < *(uint *)(lVar5 + 0x1c0)) &&
       (plVar8 = *(longlong **)(*(longlong *)(uVar3 + 0x420) + 0x10 + (ulonglong)*puVar11 * 0x18),
       plVar8 != (longlong *)0x0)) {
      uVar10 = (**(code **)(*plVar8 + 0x40))();
    }
    if (uVar13 < uVar10) {
      return 0xffffffff;
    }
    if (uVar10 < uVar13) {
      return 1;
    }
    uVar12 = uVar12 + 1;
    puVar11 = puVar11 + 1;
  } while (uVar12 < 2);
  if (*(ulonglong *)(uVar3 + 0x38) <= *(ulonglong *)(uVar4 + 0x38)) {
    if (*(ulonglong *)(uVar4 + 0x38) != *(ulonglong *)(uVar3 + 0x38)) {
      return 1;
    }
    if (uVar3 <= uVar4) {
      if (uVar4 != uVar3) {
        return 1;
      }
      if (*(uint *)(param_4 + 0x40) <= *(uint *)(param_3 + 0x40)) {
        return (ulonglong)(*(uint *)(param_4 + 0x40) < *(uint *)(param_3 + 0x40));
      }
    }
  }
  return 0xffffffff;
}



==== FUN_14032c4d0 @ 14032c4d0 size 85 ====
CALLERS:
CALLEES:

undefined8 FUN_14032c4d0(void)

{
  longlong *plVar1;
  int iVar2;
  longlong *in_R9;
  undefined1 local_b8 [184];
  
  plVar1 = *(longlong **)(*in_R9 + 0x30);
  iVar2 = (**(code **)(*plVar1 + 0x418))(plVar1,*(undefined4 *)(*in_R9 + 0x40),local_b8);
  if (-1 < iVar2) {
    (**(code **)(*DAT_140c65688 + 0x78))(DAT_140c65688,local_b8,0,0,0,0,0);
  }
  return 0;
}



==== FUN_14032ca60 @ 14032ca60 size 1838 ====
CALLERS: FUN_14032da00
CALLEES: FUN_1408fccb0 FUN_1408fe3d0 FUN_1408fc950 __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_14032ca60(longlong param_1,float *param_2,float *param_3,undefined4 param_4,
                     undefined4 param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
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
  float fVar27;
  float fVar28;
  undefined1 auStack_1f8 [32];
  undefined4 local_1d8;
  undefined1 local_1c8 [16];
  float local_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  undefined4 local_1a8;
  float local_198;
  float fStack_194;
  float fStack_190;
  undefined4 uStack_18c;
  float local_188;
  float fStack_184;
  float fStack_180;
  undefined4 uStack_17c;
  float local_178;
  float fStack_174;
  float fStack_170;
  undefined4 uStack_16c;
  undefined4 local_128;
  ulonglong local_d8;
  undefined8 extraout_XMM0_Qb;
  undefined8 extraout_XMM0_Qb_00;
  undefined8 extraout_XMM0_Qb_01;
  
  fVar18 = _UNK_140b7a338;
  fVar20 = _UNK_140b7a334;
  fVar8 = _DAT_140b7a330;
  fVar4 = DAT_140b79fa0;
  fVar24 = DAT_140b79ed0;
  fVar25 = DAT_140b79e48;
  local_d8 = DAT_140c0f7b0 ^ (ulonglong)auStack_1f8;
  fVar26 = *param_3;
  fVar27 = param_3[1];
  fVar28 = param_3[2];
  fVar5 = param_3[3];
  local_1c8 = ZEXT416((uint)DAT_140b79e48);
  fVar16 = fVar27 * fVar27;
  auVar9._4_4_ = fVar16;
  auVar9._0_4_ = fVar16;
  auVar9._8_4_ = fVar16;
  auVar9._12_4_ = fVar16;
  fVar17 = fVar26 * fVar26 + fVar16 + fVar28 * fVar28;
  auVar10._4_4_ = fVar16;
  auVar10._0_4_ = fVar17;
  auVar10._8_4_ = fVar28 * fVar28;
  auVar10._12_4_ = fVar5 * fVar5;
  auVar10 = rsqrtss(auVar9,auVar10);
  fVar16 = auVar10._0_4_;
  fVar16 = (DAT_140b79fa0 - fVar17 * fVar16 * fVar16) * DAT_140b79e48 * fVar16;
  if (fVar16 <= 0.0) {
    fVar16 = 0.0;
  }
  fVar26 = fVar16 * fVar26;
  fVar27 = fVar16 * fVar27;
  fVar28 = fVar16 * fVar28;
  fVar16 = fVar16 * fVar5;
  local_1d8 = param_4;
  if ((fVar26 != 0.0) ||
     (fVar5 = _DAT_140b7a330, fVar17 = _UNK_140b7a334, fVar19 = _UNK_140b7a338,
     fVar21 = _UNK_140b7a33c, fVar28 != 0.0)) {
    auVar11._4_4_ = fVar27 * _UNK_140b7a4b4;
    auVar11._0_4_ = fVar26 * _DAT_140b7a4b0;
    auVar11._8_4_ = fVar28 * _UNK_140b7a4b8;
    auVar11._12_4_ = fVar16 * _UNK_140b7a4bc;
    fVar21 = fVar28 * _UNK_140b7a4b4 - fVar27 * _UNK_140b7a4b8;
    fVar22 = fVar26 * _UNK_140b7a4b8 - fVar28 * _DAT_140b7a4b0;
    fVar23 = fVar27 * _DAT_140b7a4b0 - fVar26 * _UNK_140b7a4b4;
    fVar17 = fVar16 * _UNK_140b7a4bc - fVar16 * _UNK_140b7a4bc;
    auVar12._4_12_ = auVar11._4_12_;
    auVar12._0_4_ = fVar26 * _DAT_140b7a4b0 + fVar27 * _UNK_140b7a4b4 + fVar28 * _UNK_140b7a4b8;
    local_1a8 = FUN_1408fccb0(auVar12._0_8_);
    local_188 = (float)local_1a8;
    fVar5 = (float)FUN_1408fe3d0();
    auVar13._0_8_ = FUN_1408fc950();
    auVar13._8_8_ = extraout_XMM0_Qb;
    uStack_18c = 0;
    fStack_170 = (float)auVar13._0_8_;
    fVar24 = fVar24 - fStack_170;
    fVar19 = fVar21 * fVar21 + fVar22 * fVar22 + fVar23 * fVar23;
    auVar1._4_4_ = fVar22 * fVar22;
    auVar1._0_4_ = fVar19;
    auVar1._8_4_ = fVar23 * fVar23;
    auVar1._12_4_ = fVar17 * fVar17;
    auVar10 = rsqrtss(auVar13,auVar1);
    fVar17 = auVar10._0_4_;
    fVar17 = (fVar4 - fVar19 * fVar17 * fVar17) * fVar25 * fVar17;
    if (fVar17 <= 0.0) {
      fVar17 = 0.0;
    }
    fVar21 = fVar17 * fVar21;
    fVar22 = fVar17 * fVar22;
    fVar17 = fVar17 * fVar23;
    local_198 = fVar21 * fVar21 * fVar24 + fStack_170;
    local_188 = fVar22 * fVar21 * fVar24;
    fStack_194 = fVar17 * fVar5 + local_188;
    local_188 = local_188 - fVar17 * fVar5;
    local_178 = fVar17 * fVar21 * fVar24;
    fStack_174 = fVar17 * fVar22 * fVar24;
    fStack_190 = local_178 - fVar22 * fVar5;
    local_178 = fVar22 * fVar5 + local_178;
    uStack_17c = 0;
    uStack_16c = 0;
    fStack_180 = fVar21 * fVar5 + fStack_174;
    fStack_174 = fStack_174 - fVar21 * fVar5;
    fStack_184 = fVar22 * fVar22 * fVar24 + fStack_170;
    fStack_170 = fVar17 * fVar17 * fVar24 + fStack_170;
    fVar5 = fVar8 * local_198 + fVar20 * local_188 + fVar18 * local_178 + _DAT_140b7ad00;
    fVar17 = fVar8 * fStack_194 + fVar20 * fStack_184 + fVar18 * fStack_174 + _UNK_140b7ad04;
    fVar19 = fVar8 * fStack_190 + fVar20 * fStack_180 + fVar18 * fStack_170 + _UNK_140b7ad08;
    fVar21 = fVar8 * 0.0 + fVar20 * 0.0 + fVar18 * 0.0 + _UNK_140b7ad0c;
    local_1b8 = _DAT_140b7a700 * local_198 + _UNK_140b7a704 * local_188 + _UNK_140b7a708 * local_178
                + _DAT_140b7ad00;
    fStack_1b4 = _DAT_140b7a700 * fStack_194 + _UNK_140b7a704 * fStack_184 +
                 _UNK_140b7a708 * fStack_174 + _UNK_140b7ad04;
    fStack_1b0 = _DAT_140b7a700 * fStack_190 + _UNK_140b7a704 * fStack_180 +
                 _UNK_140b7a708 * fStack_170 + _UNK_140b7ad08;
    fStack_1ac = _DAT_140b7a700 * 0.0 + _UNK_140b7a704 * 0.0 + _UNK_140b7a708 * 0.0 + _UNK_140b7ad0c
    ;
  }
  fVar25 = DAT_140b79ed0;
  uVar6 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                    (*(longlong **)(param_1 + 0x38),local_1d8,param_5);
  uVar7 = (**(code **)(**(longlong **)(param_1 + 0x38) + 0x38))
                    (*(longlong **)(param_1 + 0x38),0,DAT_140c42128 * DAT_140b79f58);
  local_1a8 = uVar6;
  local_188 = (float)uVar6;
  fVar8 = (float)FUN_1408fe3d0();
  auVar14._0_8_ = FUN_1408fc950();
  auVar14._8_8_ = extraout_XMM0_Qb_00;
  uStack_18c = 0;
  fStack_170 = (float)auVar14._0_8_;
  fVar25 = fVar25 - fStack_170;
  fVar20 = fVar5 * fVar5 + fVar17 * fVar17 + fVar19 * fVar19;
  auVar2._4_4_ = fVar17 * fVar17;
  auVar2._0_4_ = fVar20;
  auVar2._8_4_ = fVar19 * fVar19;
  auVar2._12_4_ = fVar21 * fVar21;
  auVar10 = rsqrtss(auVar14,auVar2);
  fVar24 = auVar10._0_4_;
  fVar24 = (fVar4 - fVar20 * fVar24 * fVar24) * (float)local_1c8._0_4_ * fVar24;
  if (fVar24 <= 0.0) {
    fVar24 = 0.0;
  }
  fVar5 = fVar24 * fVar5;
  fVar17 = fVar24 * fVar17;
  fVar24 = fVar24 * fVar19;
  local_198 = fVar5 * fVar5 * fVar25 + fStack_170;
  local_188 = fVar17 * fVar5 * fVar25;
  fStack_194 = fVar24 * fVar8 + local_188;
  local_188 = local_188 - fVar24 * fVar8;
  local_178 = fVar24 * fVar5 * fVar25;
  fStack_174 = fVar24 * fVar17 * fVar25;
  fStack_190 = local_178 - fVar17 * fVar8;
  fStack_180 = fVar5 * fVar8 + fStack_174;
  fStack_184 = fVar17 * fVar17 * fVar25 + fStack_170;
  local_178 = fVar17 * fVar8 + local_178;
  uStack_17c = 0;
  uStack_16c = 0;
  fStack_174 = fStack_174 - fVar5 * fVar8;
  fStack_170 = fVar24 * fVar24 * fVar25 + fStack_170;
  fVar5 = fVar27 * fStack_184 + fVar26 * fStack_194 + fVar28 * fStack_174 + _UNK_140b7ad04;
  fVar25 = fVar27 * fStack_180 + fVar26 * fStack_190 + fVar28 * fStack_170 + _UNK_140b7ad08;
  fVar24 = fVar27 * 0.0 + fVar26 * 0.0 + fVar28 * 0.0 + _UNK_140b7ad0c;
  *param_2 = fVar27 * local_188 + fVar26 * local_198 + fVar28 * local_178 + _DAT_140b7ad00;
  param_2[1] = fVar5;
  param_2[2] = fVar25;
  param_2[3] = fVar24;
  local_1a8 = uVar7;
  local_128 = uVar7;
  fVar25 = (float)FUN_1408fe3d0();
  auVar15._0_8_ = FUN_1408fc950();
  auVar15._8_8_ = extraout_XMM0_Qb_01;
  fVar24 = (float)auVar15._0_8_;
  fVar20 = DAT_140b79ed0 - fVar24;
  fVar8 = fVar26 * fVar26 + fVar27 * fVar27 + fVar28 * fVar28;
  auVar3._4_4_ = fVar27 * fVar27;
  auVar3._0_4_ = fVar8;
  auVar3._8_4_ = fVar28 * fVar28;
  auVar3._12_4_ = fVar16 * fVar16;
  auVar10 = rsqrtss(auVar15,auVar3);
  fVar5 = auVar10._0_4_;
  fVar5 = (fVar4 - fVar8 * fVar5 * fVar5) * (float)local_1c8._0_4_ * fVar5;
  if (fVar5 <= 0.0) {
    fVar5 = 0.0;
  }
  fVar26 = fVar5 * fVar26;
  fVar27 = fVar5 * fVar27;
  fVar5 = fVar5 * fVar28;
  fVar19 = fVar27 * fVar26 * fVar20;
  fVar21 = fVar5 * fVar26 * fVar20;
  fVar16 = fVar5 * fVar27 * fVar20;
  fVar28 = *param_2;
  fVar4 = param_2[1];
  fVar8 = param_2[2];
  fVar18 = fVar4 * (fVar27 * fVar27 * fVar20 + fVar24) + fVar28 * (fVar5 * fVar25 + fVar19) +
           fVar8 * (fVar16 - fVar26 * fVar25) + _UNK_140b7ad04;
  fVar16 = fVar4 * (fVar26 * fVar25 + fVar16) + fVar28 * (fVar21 - fVar27 * fVar25) +
           fVar8 * (fVar5 * fVar5 * fVar20 + fVar24) + _UNK_140b7ad08;
  fVar17 = fVar4 * 0.0 + fVar28 * 0.0 + fVar8 * 0.0 + _UNK_140b7ad0c;
  *param_2 = fVar4 * (fVar19 - fVar5 * fVar25) + fVar28 * (fVar26 * fVar26 * fVar20 + fVar24) +
             fVar8 * (fVar27 * fVar25 + fVar21) + _DAT_140b7ad00;
  param_2[1] = fVar18;
  param_2[2] = fVar16;
  param_2[3] = fVar17;
  fVar26 = SQRT(*param_3 * *param_3 + param_3[1] * param_3[1] + param_3[2] * param_3[2]);
  *param_2 = *param_2 * fVar26;
  param_2[1] = param_2[1] * fVar26;
  param_2[2] = param_2[2] * fVar26;
  param_2[3] = param_2[3] * fVar26;
  return param_2;
}



==== FUN_14032d650 @ 14032d650 size 83 ====
CALLERS: FUN_1403146b0 FUN_14031ab20
CALLEES: FUN_1403131d0

void FUN_14032d650(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x1a8) != 0) {
    FUN_1403131d0();
  }
  *(undefined8 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1b0) = 0;
  *(undefined8 *)(param_1 + 0x1b8) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1d8) = 0;
  return;
}



==== FUN_140330740 @ 140330740 size 181 ====
CALLERS: FUN_140330700
CALLEES: FUN_14018b900

void FUN_140330740(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_140b64668;
  if ((undefined8 *)param_1[0x61] != (undefined8 *)0x0) {
    *(undefined8 *)param_1[0x61] = param_1[0x62];
  }
  if (param_1[0x62] != 0) {
    *(undefined8 *)(param_1[0x62] + 0x308) = param_1[0x61];
  }
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[0xc] = &PTR_FUN_140b64640;
  if (param_1[0x10] != 0) {
    FUN_14018b900(param_1[0x10],0);
    param_1[0x10] = 0;
  }
  param_1[5] = &PTR_FUN_140b64918;
  if (param_1[0xb] != 0) {
    FUN_14018b900(param_1[0xb],0);
    param_1[0xb] = 0;
  }
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[3] + 8))();
  }
  return;
}



==== FUN_140331050 @ 140331050 size 325 ====
CALLERS:
CALLEES: FUN_1403303e0 FUN_14018b280 FUN_14032ff20 FUN_1400edd00

undefined4 FUN_140331050(longlong param_1,ulonglong *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *local_res8;
  undefined8 *local_res10;
  undefined8 *local_28;
  undefined4 local_20;
  
  puVar1 = (undefined8 *)*param_2;
  local_res8 = puVar1;
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1);
  }
  iVar4 = (**(code **)(**(longlong **)(param_1 + 0x30) + 0x10))
                    (*(longlong **)(param_1 + 0x30),&local_res8);
  if (iVar4 < 0) {
    if ((longlong *)*param_2 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*param_2 + 8))();
    }
    return 0xffffffff;
  }
  lVar6 = FUN_14018b280(800,0);
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  else {
    local_res8 = (undefined8 *)*param_2;
    if (local_res8 != (undefined8 *)0x0) {
      (**(code **)*local_res8)();
    }
    lVar6 = FUN_1403303e0(lVar6,&local_res8,param_3);
  }
  uVar5 = FUN_14032ff20(param_1 + 0xa8,lVar6);
  *(undefined4 *)(lVar6 + 0x10) = uVar5;
  puVar2 = *(undefined8 **)(param_1 + 0xd8);
  puVar7 = puVar2;
  puVar3 = (undefined8 *)puVar2[1];
  while (puVar3 != (undefined8 *)0x0) {
    if ((undefined8 *)puVar3[4] < puVar1) {
      puVar3 = (undefined8 *)puVar3[3];
    }
    else {
      puVar7 = puVar3;
      puVar3 = (undefined8 *)puVar3[2];
    }
  }
  if ((puVar7 == puVar2) || (puVar1 < (undefined8 *)puVar7[4])) {
    local_20 = 0;
    local_res8 = puVar7;
    local_28 = puVar1;
    FUN_1400edd00(param_1 + 0xd0,&local_res10,&local_res8,&local_28);
    puVar7 = local_res10;
  }
  *(undefined4 *)(puVar7 + 5) = *(undefined4 *)(lVar6 + 0x10);
  uVar5 = *(undefined4 *)(lVar6 + 0x10);
  if ((longlong *)*param_2 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_2 + 8))();
  }
  return uVar5;
}



==== FUN_1403323a0 @ 1403323a0 size 472 ====
CALLERS: FUN_1403331c0
CALLEES: FUN_14019fb60 FUN_140332ae0 FUN_140334d90 FUN_140336b00 QueryPerformanceCounter CloseHandle FUN_140338040 FUN_140337f20 GetCurrentThreadId SetEvent CreateEventW FUN_1403321a0 FUN_1401a2e50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1403323a0(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  ushort uVar3;
  DWORD DVar4;
  longlong lVar5;
  longlong *plVar6;
  HANDLE hObject;
  ulonglong uVar7;
  DWORD *pDVar8;
  bool bVar9;
  LARGE_INTEGER local_res8;
  undefined8 local_res18 [2];
  
  uVar3 = (**(code **)(*param_1 + 0x40))();
  if (((ulonglong)param_1[0x16] <= (ulonglong)uVar3) ||
     (lVar1 = *(longlong *)(param_1[0x15] + (ulonglong)uVar3 * 8), lVar1 == 0)) {
    lVar1 = *param_2;
    if (*(char *)(lVar1 + 200) == '\0') {
      FUN_140334d90();
    }
    local_res18[0] = 0x141dec0f8;
    FUN_1401a2e50(0xb,0,local_res18,lVar1 + 200);
    return;
  }
  lVar2 = *param_2;
  pDVar8 = (DWORD *)(lVar2 + 0x120);
  DVar4 = GetCurrentThreadId();
  uVar7 = 0;
  if (*pDVar8 == DVar4) {
    *(longlong *)(lVar2 + 0x128) = *(longlong *)(lVar2 + 0x128) + 1;
  }
  else {
    do {
      LOCK();
      bVar9 = *(longlong *)(lVar2 + 0x128) == 0;
      if (bVar9) {
        *(longlong *)(lVar2 + 0x128) = 1;
      }
      UNLOCK();
      if (bVar9) {
        *pDVar8 = DVar4;
        goto LAB_140332434;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x400);
    FUN_14019fb60(pDVar8);
  }
LAB_140332434:
  if (*(longlong *)(*param_2 + 0x198) != 0) {
    QueryPerformanceCounter(&local_res8);
    *(LONGLONG *)(lVar1 + 0x300) = local_res8.QuadPart - _DAT_140c87988;
    lVar5 = FUN_140338040(*param_2 + 0x198);
    param_1[0x20] = param_1[0x20] + lVar5;
  }
  plVar6 = (longlong *)(*param_2 + 0x198);
  lVar5 = *plVar6;
  while (lVar5 != 0) {
    if (((*(longlong *)(lVar1 + 0x50) != 0) && (*(longlong *)(lVar1 + 0x58) != 0)) &&
       (FUN_140337f20(*(longlong *)(lVar1 + 0x58),*plVar6), *(longlong *)(lVar1 + 0x38) == 0)) {
      FUN_140336b00(lVar1 + 0x28);
    }
    plVar6 = (longlong *)(*param_2 + 0x198);
    lVar5 = *plVar6;
  }
  if (*(ulonglong *)(lVar2 + 0x128) < 2) {
    *pDVar8 = 0;
    LOCK();
    *(undefined8 *)(lVar2 + 0x128) = 0;
    UNLOCK();
    if (*(longlong *)(lVar2 + 0x130) != 0) {
      if (*(longlong *)(lVar2 + 0x138) == 0) {
        hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        LOCK();
        bVar9 = *(longlong *)(lVar2 + 0x138) == 0;
        if (bVar9) {
          *(longlong *)(lVar2 + 0x138) = (longlong)hObject;
        }
        UNLOCK();
        if (!bVar9) {
          CloseHandle(hObject);
        }
      }
      SetEvent(*(HANDLE *)(lVar2 + 0x138));
    }
  }
  else {
    *(longlong *)(lVar2 + 0x128) = *(longlong *)(lVar2 + 0x128) + -1;
  }
  FUN_140332ae0();
  FUN_1403321a0(param_1,*(undefined4 *)(lVar1 + 0x10));
  return;
}



==== FUN_140332870 @ 140332870 size 166 ====
CALLERS:
CALLEES: FUN_1403365e0

undefined8 FUN_140332870(longlong param_1,ushort param_2,uint *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  
  if (((ulonglong)param_2 < *(ulonglong *)(param_1 + 0xb0)) &&
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0xa8) + (ulonglong)param_2 * 8), lVar3 != 0)) {
    iVar4 = FUN_1403365e0(lVar3 + 0x60,param_3,(ulonglong)*param_3 + (longlong)param_3);
    if (iVar4 != 0) {
      return 4;
    }
    if (*(longlong *)(lVar3 + 0x308) == 0) {
      plVar1 = (longlong *)(param_1 + 0xf0);
      plVar2 = (longlong *)(lVar3 + 0x310);
      *(longlong **)(lVar3 + 0x308) = plVar1;
      *plVar2 = *plVar1;
      *plVar1 = lVar3;
      if (*plVar2 != 0) {
        *(longlong **)(*plVar2 + 0x308) = plVar2;
      }
    }
    return 0;
  }
  return 2;
}



==== FUN_140332ae0 @ 140332ae0 size 247 ====
CALLERS: FUN_140332c10 FUN_140332cf0 FUN_140332f60 FUN_1403323a0
CALLEES: QueryPerformanceCounter

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140332ae0(LARGE_INTEGER param_1,longlong param_2)

{
  longlong lVar1;
  LARGE_INTEGER local_res8 [4];
  
  local_res8[0] = param_1;
  QueryPerformanceCounter(local_res8);
  lVar1 = local_res8[0].QuadPart - _DAT_140c87988;
  if ((ulonglong)*(uint *)(param_2 + 0x1a4) <=
      (ulonglong)((lVar1 - *(longlong *)(param_2 + 0x1a8)) * 1000) / DAT_140c636b8) {
    *(longlong *)(param_2 + 0x1a8) = lVar1;
    *(undefined8 *)(param_2 + 0x1b8 + (ulonglong)*(uint *)(param_2 + 0x2f0) * 0x10) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x1c0);
    *(longlong *)(param_2 + ((ulonglong)*(uint *)(param_2 + 0x2f0) + 0x1b) * 0x10) = lVar1;
    *(undefined8 *)(param_2 + 600 + (ulonglong)*(uint *)(param_2 + 0x2f4) * 0x10) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x1b0);
    *(longlong *)(param_2 + ((ulonglong)*(uint *)(param_2 + 0x2f4) + 0x25) * 0x10) = lVar1;
    *(uint *)(param_2 + 0x2f0) = (*(int *)(param_2 + 0x2f0) + 1U) % 10;
    *(uint *)(param_2 + 0x2f4) = (*(int *)(param_2 + 0x2f4) + 1U) % 10;
  }
  return;
}



==== FUN_1403336d0 @ 1403336d0 size 95 ====
CALLERS:
CALLEES: QueryPerformanceCounter

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1403336d0(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  LARGE_INTEGER local_res8 [4];
  
  if (((param_2 & 0xffff) < *(ulonglong *)(param_1 + 0xb0)) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xa8) + (param_2 & 0xffff) * 8), lVar1 != 0)) {
    QueryPerformanceCounter(local_res8);
    return (ulonglong)
           (((local_res8[0].QuadPart - *(longlong *)(lVar1 + 0x300)) - _DAT_140c87988) * 1000) /
           DAT_140c636b8;
  }
  return 0;
}



==== FUN_14033ae10 @ 14033ae10 size 63 ====
CALLERS: FUN_14033c090 FUN_14033bde0
CALLEES: FUN_14033e900

undefined8 * FUN_14033ae10(undefined8 *param_1)

{
  FUN_14033e900();
  *param_1 = &PTR_FUN_140b64a88;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  return param_1;
}



==== FUN_14033bde0 @ 14033bde0 size 420 ====
CALLERS:
CALLEES: bind FUN_14033ae10 CreateIoCompletionPort __security_check_cookie WSAGetLastError FUN_14033b860 FUN_14018b280 FUN_14033bb50 listen FUN_14033b950

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * FUN_14033bde0(longlong param_1,longlong *param_2,undefined4 *param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *CompletionKey;
  HANDLE pvVar4;
  undefined1 auStack_68 [32];
  HANDLE local_48;
  sockaddr local_40;
  ulonglong local_30;
  
  local_30 = DAT_140c0f7b0 ^ (ulonglong)auStack_68;
  plVar2 = (longlong *)FUN_14033bb50(param_1,&local_48);
  if (-1 < (int)plVar2) {
    local_40._0_4_ = *param_3;
    local_40.sa_data._2_4_ = param_3[1];
    local_40.sa_data._6_4_ = param_3[2];
    local_40.sa_data._10_4_ = param_3[3];
    iVar1 = bind((SOCKET)local_48,&local_40,0x10);
    if (iVar1 == 0) {
      lVar3 = FUN_14018b280(0x218,0);
      plVar2 = (longlong *)0x0;
      CompletionKey = plVar2;
      if (lVar3 != 0) {
        CompletionKey = (longlong *)FUN_14033ae10(lVar3,local_48);
      }
      *(undefined4 *)((longlong)CompletionKey + 0x11c) = 2;
      iVar1 = listen((SOCKET)local_48,0x7fffffff);
      if (iVar1 == -1) {
        *(undefined4 *)(CompletionKey + 0x23) = 5;
        iVar1 = WSAGetLastError();
        FUN_14033b860(L"CNetworkDriverIOCompletion::ListenSocket listen",iVar1,0);
        plVar2 = (longlong *)0x80004005;
      }
      else {
        FUN_14033b950(L"listen",CompletionKey + 2,L"established");
        *(undefined4 *)(CompletionKey + 0x23) = 4;
        pvVar4 = CreateIoCompletionPort
                           (local_48,*(HANDLE *)(param_1 + 0x90),(ULONG_PTR)CompletionKey,0);
        if (pvVar4 == (HANDLE)0x0) {
          iVar1 = WSAGetLastError();
          FUN_14033b860(L"CNetworkDriverIOCompletion::ListenSocket CreateIoCompletionPort",iVar1,0);
          plVar2 = (longlong *)0x80004005;
        }
        else if ((longlong *)*param_2 != CompletionKey) {
          (**(code **)*CompletionKey)(CompletionKey);
          if ((longlong *)*param_2 != (longlong *)0x0) {
            (**(code **)(*(longlong *)*param_2 + 8))();
          }
          *param_2 = (longlong)CompletionKey;
        }
      }
      (**(code **)(*CompletionKey + 8))(CompletionKey);
    }
    else {
      iVar1 = WSAGetLastError();
      FUN_14033b860(L"CNetworkDriverIOCompletion::ListenSocket bind",iVar1,0);
      plVar2 = (longlong *)0x80004005;
    }
  }
  return plVar2;
}



==== FUN_14033f1d0 @ 14033f1d0 size 694 ====
CALLERS:
CALLEES: FUN_14033f5e0 FUN_14018e2c0 FUN_14018b900 memcpy FUN_14033f0a0 FUN_14018b280 FUN_14033f4e0 FUN_14018f570

ulonglong FUN_14033f1d0(undefined8 param_1)

{
  short *psVar1;
  undefined8 uVar2;
  longlong lVar3;
  size_t _Size;
  longlong lVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined1 local_58 [8];
  void *local_50;
  undefined2 *local_48;
  void *local_40;
  undefined1 local_38 [8];
  longlong local_30;
  longlong local_28;
  
  uVar10 = 0;
  local_50 = (void *)0x0;
  local_40 = (void *)0x0;
  uVar8 = uVar10;
  do {
    psVar1 = &DAT_140ae9776 + uVar8;
    uVar8 = uVar8 + 1;
  } while (*psVar1 != 0);
  lVar11 = (longlong)(uVar8 * 2) >> 1;
  uVar8 = lVar11 + 1;
  if (uVar8 < 0x7fffffffffffffff) {
    lVar3 = uVar8 * 2;
    local_50 = (void *)FUN_14018b280(lVar3,0);
    local_40 = (void *)((longlong)local_50 + lVar3);
  }
  pvVar5 = local_50;
  _Size = lVar11 * 2;
  memcpy(local_50,&DAT_140ae9774,_Size);
  local_48 = (undefined2 *)((longlong)pvVar5 + _Size);
  if (local_48 != (undefined2 *)0x0) {
    *local_48 = 0;
  }
  FUN_14018f570(local_38,param_1,local_58,0x22,0x5c);
  if (pvVar5 != (void *)0x0) {
    FUN_14018b900(pvVar5,0);
  }
  lVar3 = DAT_140c63748;
  lVar11 = local_30;
  if ((local_28 - local_30 & 0xffffffffffffffe0U) == 0) {
    puVar9 = *(undefined8 **)(DAT_140c63748 + 0x38);
    if (puVar9 != *(undefined8 **)(DAT_140c63748 + 0x40)) {
      do {
        (*(code *)puVar9[1])(*puVar9,L"usage: sound <cmd>");
        puVar9 = puVar9 + 2;
      } while (puVar9 != *(undefined8 **)(lVar3 + 0x40));
    }
    lVar3 = DAT_140c63748;
    puVar9 = *(undefined8 **)(DAT_140c63748 + 0x38);
    if (puVar9 != *(undefined8 **)(DAT_140c63748 + 0x40)) {
      do {
        (*(code *)puVar9[1])(*puVar9,L"       cmd = reset");
        puVar9 = puVar9 + 2;
      } while (puVar9 != *(undefined8 **)(lVar3 + 0x40));
    }
    lVar3 = DAT_140c63748;
    puVar9 = *(undefined8 **)(DAT_140c63748 + 0x38);
    if (puVar9 != *(undefined8 **)(DAT_140c63748 + 0x40)) {
      do {
        (*(code *)puVar9[1])(*puVar9,L"       cmd = on");
        puVar9 = puVar9 + 2;
      } while (puVar9 != *(undefined8 **)(lVar3 + 0x40));
    }
    lVar3 = DAT_140c63748;
    puVar9 = *(undefined8 **)(DAT_140c63748 + 0x38);
    if (puVar9 != *(undefined8 **)(DAT_140c63748 + 0x40)) {
      do {
        (*(code *)puVar9[1])(*puVar9,L"       cmd = off");
        puVar9 = puVar9 + 2;
      } while (puVar9 != *(undefined8 **)(lVar3 + 0x40));
    }
  }
  else {
    uVar2 = *(undefined8 *)(local_30 + 8);
    iVar6 = FUN_14018e2c0(uVar2,&DAT_140aea5f4);
    if (iVar6 == 0) {
      uVar7 = FUN_14033f4e0();
      uVar10 = (ulonglong)uVar7;
      goto joined_r0x00014033f382;
    }
    iVar6 = FUN_14018e2c0(uVar2,&DAT_140af4180);
    lVar4 = DAT_140c65850;
    lVar3 = DAT_140c63748;
    if (iVar6 == 0) {
      if (*(char *)(DAT_140c65850 + 0x48) == '\0') {
        puVar9 = *(undefined8 **)(DAT_140c63748 + 0x38);
        if (puVar9 != *(undefined8 **)(DAT_140c63748 + 0x40)) {
          do {
            (*(code *)puVar9[1])(*puVar9,L"sound is already off.");
            puVar9 = puVar9 + 2;
          } while (puVar9 != *(undefined8 **)(lVar3 + 0x40));
        }
        uVar10 = 0x80004005;
      }
      else {
        FUN_14033f0a0(DAT_140c65850,*(undefined8 *)(DAT_140c65850 + 0x68));
        (**(code **)(**(longlong **)(lVar4 + 0x60) + 0x198))();
        *(undefined1 *)(lVar4 + 0x48) = 0;
      }
      goto joined_r0x00014033f382;
    }
    iVar6 = FUN_14018e2c0(uVar2,L"reset");
    if (iVar6 == 0) {
      uVar7 = FUN_14033f5e0();
      uVar10 = (ulonglong)uVar7;
      goto joined_r0x00014033f382;
    }
  }
  uVar10 = 0x80070057;
joined_r0x00014033f382:
  for (; lVar11 != local_28; lVar11 = lVar11 + 0x20) {
    if (*(longlong *)(lVar11 + 8) != 0) {
      FUN_14018b900(*(longlong *)(lVar11 + 8),0);
    }
  }
  if (local_30 != 0) {
    FUN_14018b900(local_30,0);
  }
  return uVar10;
}



==== FUN_14033f940 @ 14033f940 size 300 ====
CALLERS: FUN_14033ef30 FUN_14033efa0
CALLEES: FUN_140347a10 FUN_14033fde0 FUN_14018b900 FUN_140198f50

undefined8 FUN_14033f940(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x70);
  while (lVar1 != 0) {
    (*(code *)**(undefined8 **)(param_1 + 0x70))(2,(*(undefined8 **)(param_1 + 0x70))[1]);
    lVar1 = *(longlong *)(param_1 + 0x70);
    if (lVar1 != 0) {
      if (*(undefined8 **)(lVar1 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar1 + 0x10) = *(undefined8 *)(lVar1 + 0x18);
      }
      if (*(longlong *)(lVar1 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar1 + 0x18) + 0x10) = *(undefined8 *)(lVar1 + 0x10);
      }
      *(undefined8 *)(lVar1 + 0x10) = 0;
      *(undefined8 *)(lVar1 + 0x18) = 0;
      FUN_14018b900(lVar1,0);
    }
    lVar1 = *(longlong *)(param_1 + 0x70);
  }
  if (param_2 == (longlong *)0x0) {
    param_2 = (longlong *)(param_1 + 0x50);
  }
  if (*param_2 == **(longlong **)(param_1 + 0x58)) {
    FUN_140198f50(**(longlong **)(param_1 + 0x58),L"sound");
    *param_2 = 0;
    DAT_140c65858 = *(undefined8 *)(param_1 + 0x68);
    if (*(char *)(param_1 + 0x48) != '\0') {
      (**(code **)(**(longlong **)(param_1 + 0x60) + 0x198))();
    }
    (**(code **)(**(longlong **)(param_1 + 0x68) + 0x198))();
    FUN_140347a10();
    FUN_14033fde0();
    plVar2 = *(longlong **)(param_1 + 0x60);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0xa8))(plVar2,1);
    }
    plVar2 = *(longlong **)(param_1 + 0x68);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0xa8))(plVar2,1);
    }
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 *)(param_1 + 0x58) = 0;
    return 0;
  }
  return 0x80070057;
}



==== FUN_14033fe60 @ 14033fe60 size 208 ====
CALLERS:
CALLEES: FUN_140343ad0 FUN_140343d30 FUN_140343e40 FUN_14018b280

int FUN_14033fe60(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if ((param_3 != 0) && (param_2 != (undefined8 *)0x0)) {
    puVar2 = (undefined8 *)FUN_140343e40(param_3);
    if (puVar2 != (undefined8 *)0x0) {
      (**(code **)*puVar2)(puVar2);
      *param_2 = puVar2;
      return 0;
    }
    lVar3 = FUN_14018b280(0x278,0);
    if (lVar3 == 0) {
      plVar4 = (longlong *)0x0;
    }
    else {
      plVar4 = (longlong *)FUN_140343ad0(lVar3);
    }
    iVar1 = FUN_140343d30(plVar4,param_3);
    if (iVar1 < 0) {
      if (plVar4 != (longlong *)0x0) {
        (**(code **)(*plVar4 + 0x38))(plVar4,1);
        return iVar1;
      }
    }
    else {
      *param_2 = plVar4;
    }
    return iVar1;
  }
  return -0x7ff8ffa9;
}



==== FUN_140343bb0 @ 140343bb0 size 150 ====
CALLERS: FUN_140343b70
CALLEES: FUN_140349d80 FUN_1400035b0

void FUN_140343bb0(undefined8 *param_1)

{
  *param_1 = &PTR_LAB_140b64f30;
  if (-1 < *(int *)(param_1 + 0x44)) {
    FUN_1400035b0(0x13,4,0,param_1 + 1);
    (**(code **)(*DAT_140c65858 + 0x150))(DAT_140c65858,*(undefined4 *)(param_1 + 0x42));
  }
  if ((undefined8 *)param_1[0x4d] != (undefined8 *)0x0) {
    *(undefined8 *)param_1[0x4d] = param_1[0x4e];
  }
  if (param_1[0x4e] != 0) {
    *(undefined8 *)(param_1[0x4e] + 0x268) = param_1[0x4d];
  }
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  FUN_140349d80(param_1 + 0x43);
  return;
}



==== FUN_140343c50 @ 140343c50 size 38 ====
CALLERS:
CALLEES: FUN_14034a1a0

void FUN_140343c50(undefined4 param_1,longlong *param_2)

{
  FUN_14034a1a0(param_2 + 0x43,param_1);
                    /* WARNING: Could not recover jumptable at 0x000140343c72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 8))(param_2);
  return;
}



==== FUN_140343cd0 @ 140343cd0 size 87 ====
CALLERS:
CALLEES: FUN_14034a2b0

void FUN_140343cd0(undefined8 *param_1)

{
  if (*(int *)(param_1 + 0x44) != -0x7ffffff6) {
    FUN_14034a2b0(param_1 + 0x43);
    (**(code **)*param_1)(param_1);
                    /* WARNING: Could not recover jumptable at 0x000140343d1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_140c65858 + 0x148))(DAT_140c65858,param_1 + 0x42,param_1 + 1,param_1 + 0x4b);
    return;
  }
  return;
}



==== FUN_140347380 @ 140347380 size 323 ====
CALLERS:
CALLEES: FUN_14019fb60 GetCurrentThreadId SetEvent CreateEventW CloseHandle

ulonglong FUN_140347380(longlong param_1,undefined4 *param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  DWORD DVar2;
  uint uVar3;
  HANDLE hObject;
  ulonglong uVar4;
  ulonglong uVar5;
  bool bVar6;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80070057;
  }
  DVar2 = GetCurrentThreadId();
  uVar5 = 0;
  uVar4 = uVar5;
  if (DAT_140c7aa70 == DVar2) {
    DAT_140c7aa78 = DAT_140c7aa78 + 1;
    DVar2 = DAT_140c7aa70;
  }
  else {
    do {
      LOCK();
      bVar6 = DAT_140c7aa78 == 0;
      if (bVar6) {
        DAT_140c7aa78 = 1;
      }
      UNLOCK();
      if (bVar6) goto LAB_14034740f;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x400);
    FUN_14019fb60(&DAT_140c7aa70,DVar2);
    DVar2 = DAT_140c7aa70;
  }
LAB_14034740f:
  DAT_140c7aa70 = DVar2;
  if (*(int *)(param_1 + 0x10) == 0) {
    *param_2 = 0;
  }
  else {
    uVar3 = (**(code **)(*DAT_140c65858 + 0xf8))
                      (DAT_140c65858,*(int *)(param_1 + 0x10),param_2,param_3);
    uVar5 = (ulonglong)uVar3;
  }
  if (DAT_140c7aa78 < 2) {
    DAT_140c7aa70 = 0;
    LOCK();
    DAT_140c7aa78 = 0;
    UNLOCK();
    if (DAT_140c7aa80 != 0) {
      if (DAT_140c7aa88 == (HANDLE)0x0) {
        hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        LOCK();
        bVar6 = DAT_140c7aa88 != (HANDLE)0x0;
        pvVar1 = hObject;
        if (bVar6) {
          pvVar1 = DAT_140c7aa88;
        }
        DAT_140c7aa88 = pvVar1;
        UNLOCK();
        if (bVar6) {
          CloseHandle(hObject);
        }
      }
      SetEvent(DAT_140c7aa88);
    }
    return uVar5;
  }
  DAT_140c7aa78 = DAT_140c7aa78 - 1;
  return uVar5;
}



==== FUN_140347e90 @ 140347e90 size 212 ====
CALLERS: FUN_140347e50
CALLEES:

void FUN_140347e90(undefined8 *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = param_1[3];
  uVar3 = 0;
  *param_1 = &PTR_FUN_140b65240;
  uVar5 = uVar3;
  for (; lVar4 != 0; lVar4 = lVar4 + -1) {
    lVar1 = param_1[2];
    plVar2 = *(longlong **)(lVar1 + 0x210 + uVar5);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 8))();
      *(undefined8 *)(lVar1 + 0x210 + uVar5) = 0;
    }
    uVar5 = uVar5 + 0x218;
  }
  uVar5 = uVar3;
  if (param_1[3] != 0) {
    do {
      plVar2 = *(longlong **)(uVar5 + 0x210 + param_1[2]);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 8))();
      }
      uVar3 = uVar3 + 1;
      uVar5 = uVar5 + 0x218;
    } while (uVar3 < (ulonglong)param_1[3]);
  }
  lVar4 = param_1[2];
  if (lVar4 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000140347f5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(longlong *)(lVar4 + -0x10) + 8))(lVar4 + -0x10);
    return;
  }
  return;
}



==== FUN_14034ad40 @ 14034ad40 size 745 ====
CALLERS:
CALLEES: FUN_14034b380 FUN_1400035b0 __security_check_cookie FUN_1401b5b50

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_14034ad40(longlong param_1,undefined8 param_2,int param_3,undefined8 *param_4,char *param_5,
             undefined8 *param_6)

{
  ulonglong *puVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined8 uVar5;
  char cVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 auStack_2e8 [32];
  longlong **local_2c8;
  longlong local_2c0;
  longlong local_2b8;
  undefined4 local_2a8 [2];
  undefined8 local_2a0;
  longlong *local_298;
  undefined4 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 local_270;
  undefined4 *local_268;
  undefined1 local_258 [528];
  ulonglong local_48;
  
  local_48 = DAT_140c0f7b0 ^ (ulonglong)auStack_2e8;
  cVar4 = '\0';
  if (*param_5 == '\0') {
    *param_6 = 0;
    *(undefined4 *)(param_6 + 1) = 0;
    *(undefined4 *)(param_6 + 4) = *(undefined4 *)(param_1 + 0x10);
    param_6[2] = 0;
    *(undefined4 *)((longlong)param_6 + 0xc) = 0;
    uVar8 = 1;
  }
  else {
    local_290 = *(undefined4 *)((longlong)StackBase + -4);
    uVar8 = 1;
    local_268 = (undefined4 *)((longlong)StackBase + -4);
    local_270 = CONCAT44(0xffffffff,(undefined4)local_270);
    *local_268 = 1;
    *param_6 = 0;
    if (param_4 == (undefined8 *)0x0) {
      param_4 = &local_288;
      local_288 = 0;
      local_280 = 0;
      local_278 = 0;
      local_270 = 0;
    }
    local_2c8 = (longlong **)local_2a8;
    local_298 = (longlong *)0x0;
    local_2a8[0] = 0x104;
    local_2a0 = param_2;
    iVar3 = FUN_14034b380(param_1,param_2,param_4,local_258);
    if (-1 < iVar3) {
      uVar7 = 3;
      do {
        if (param_3 == 0) {
          uVar5 = 1;
          cVar6 = (*(char *)(param_4 + 3) != '\0') + '\x03';
LAB_14034ae7d:
          local_2c8 = &local_298;
          iVar3 = FUN_1401b5b50(DAT_140c63788,local_258,uVar5,cVar6);
          if (iVar3 < 0) goto LAB_14034ae9f;
LAB_14034affa:
          *(undefined4 *)((longlong)param_6 + 0xc) = 8;
          param_6[2] = local_298;
          uVar7 = (**(code **)(*local_298 + 0x18))();
          *(undefined4 *)(param_6 + 1) = 0;
          *param_6 = uVar7;
          uVar2 = *(undefined4 *)(param_1 + 0x10);
          param_6[3] = 0;
          *(undefined4 *)(param_6 + 4) = uVar2;
          goto LAB_14034af4e;
        }
        if (param_3 == 1) {
          uVar5 = 2;
          cVar6 = '\x02';
          goto LAB_14034ae7d;
        }
        if (param_3 == 2) {
          uVar5 = 2;
          cVar6 = cVar4;
          goto LAB_14034ae7d;
        }
        if (param_3 == 3) {
          uVar5 = 3;
          cVar6 = '\x02';
          goto LAB_14034ae7d;
        }
        local_298 = (longlong *)0x0;
LAB_14034ae9f:
        if (*(char *)(param_4 + 3) == '\0') {
          if (param_3 == 0) {
            uVar7 = 1;
            cVar4 = (*(char *)(param_4 + 3) != '\0') + '\x03';
LAB_14034afc1:
            local_2c8 = &local_298;
            iVar3 = FUN_1401b5b50(DAT_140c63788,local_2a0,uVar7,cVar4);
            if (-1 < iVar3) goto LAB_14034affa;
          }
          else {
            if (param_3 == 1) {
              uVar7 = 2;
              cVar4 = '\x02';
              goto LAB_14034afc1;
            }
            if (param_3 == 2) {
              uVar7 = 2;
              goto LAB_14034afc1;
            }
            if (param_3 == 3) {
              cVar4 = '\x02';
              goto LAB_14034afc1;
            }
          }
          FUN_1400035b0(0x13,0,0,local_2a0);
          goto LAB_14034af48;
        }
        local_288 = *param_4;
        local_280 = param_4[1];
        local_278 = param_4[2];
        puVar1 = param_4 + 3;
        param_4 = &local_288;
        local_2c8 = (longlong **)local_2a8;
        local_270 = *puVar1 & 0xffffffffffffff00;
        local_2a8[0] = 0x104;
        iVar3 = FUN_14034b380(param_1,local_2a0,&local_288,local_258);
      } while (-1 < iVar3);
    }
    FUN_1400035b0(0x13,0,0,local_2a0);
    local_2b8 = param_1 + 0x638;
    local_2c0 = param_1 + 0x42c;
    local_2c8 = (longlong **)(param_1 + 0x220);
    FUN_1400035b0(0x13);
LAB_14034af48:
    uVar8 = 2;
LAB_14034af4e:
    *local_268 = local_290;
  }
  return uVar8;
}



==== FUN_14034c240 @ 14034c240 size 961 ====
CALLERS: FUN_14011f4f0 FUN_14034c610
CALLEES: GetNumberFormatW GetLocaleInfoW GetLastError memcpy __security_check_cookie FUN_14018b280 FUN_14018e820

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NUMBERFMTW * FUN_14034c240(LPCWSTR param_1,LPWSTR param_2,ulonglong param_3,byte *param_4)

{
  WCHAR *pWVar1;
  WCHAR WVar2;
  uint uVar3;
  UINT UVar4;
  int iVar5;
  DWORD DVar6;
  NUMBERFMTW *pNVar7;
  NUMBERFMTW *pNVar8;
  NUMBERFMTW *pNVar9;
  NUMBERFMTW *pNVar10;
  NUMBERFMTW *pNVar11;
  WCHAR *pWVar12;
  NUMBERFMTW *pNVar13;
  undefined1 auStackY_138 [32];
  NUMBERFMTW local_108;
  LPWSTR local_e0;
  WCHAR local_d8 [64];
  ulonglong local_58;
  
  local_58 = DAT_140c0f7b0 ^ (ulonglong)auStackY_138;
  pNVar13 = (NUMBERFMTW *)0x0;
  pNVar11 = (NUMBERFMTW *)0x0;
  local_108.NumDigits = 0;
  local_108.LeadingZero = 0;
  local_108.Grouping = 0;
  local_108._12_4_ = 0;
  local_108.lpDecimalSep = (LPWSTR)0x0;
  local_108.lpThousandSep = (LPWSTR)0x0;
  local_108.NegativeOrder = 0;
  local_108._36_4_ = 0;
  pNVar10 = (NUMBERFMTW *)0x0;
  pNVar9 = pNVar13;
  pNVar7 = pNVar13;
  local_e0 = param_2;
  if (param_4 == (byte *)0x0) {
LAB_14034c545:
    iVar5 = (int)param_3;
    if (0x7fffffff < param_3) {
      iVar5 = 0x7fffffff;
    }
    if ((param_4 == (byte *)0x0) || (pNVar10 = &local_108, *(int *)param_4 == 0)) {
      pNVar10 = pNVar13;
    }
    iVar5 = GetNumberFormatW(*(LCID *)(DAT_140c7aac0 + 0xc),0,param_1,pNVar10,local_e0,iVar5);
    pNVar10 = pNVar9;
    pNVar11 = pNVar7;
    if (iVar5 != 0) goto LAB_14034c59e;
  }
  else {
    if (((*param_4 & 1) != 0) && (*(int *)(param_4 + 4) == 0)) {
      local_108._12_4_ = 0;
      local_108.Grouping = 0;
LAB_14034c33d:
      if ((*param_4 & 2) == 0) {
        iVar5 = GetLocaleInfoW(*(LCID *)(DAT_140c7aac0 + 0xc),0x11,local_d8,0x40);
        if (iVar5 == 0) goto LAB_14034c586;
        uVar3 = FUN_14018e820(local_d8);
      }
      else {
        uVar3 = (uint)param_4[8];
      }
      local_108.NumDigits = uVar3;
      if ((*param_4 & 4) == 0) {
        iVar5 = GetLocaleInfoW(*(LCID *)(DAT_140c7aac0 + 0xc),0x12,local_d8,0x40);
        if (iVar5 == 0) goto LAB_14034c586;
        uVar3 = FUN_14018e820(local_d8);
      }
      else {
        uVar3 = (uint)(*(int *)(param_4 + 0xc) != 0);
      }
      local_108.LeadingZero = uVar3;
      if ((*param_4 & 8) == 0) {
        iVar5 = GetLocaleInfoW(*(LCID *)(DAT_140c7aac0 + 0xc),0xe,local_d8,0x40);
        pNVar11 = pNVar13;
        WVar2 = local_d8[0];
        if (iVar5 == 0) goto LAB_14034c586;
        while (WVar2 != L'\0') {
          pNVar11 = (NUMBERFMTW *)((longlong)&pNVar11->NumDigits + 1);
          WVar2 = local_d8[(longlong)pNVar11];
        }
        pNVar10 = (NUMBERFMTW *)FUN_14018b280((longlong)pNVar11 * 2 + 0x12,0);
        if (pNVar10 != (NUMBERFMTW *)0x0) {
          *(NUMBERFMTW **)&pNVar10->Grouping = pNVar11;
          *(undefined ***)pNVar10 = &PTR_LAB_140b55060;
          pNVar7 = pNVar10;
        }
        pNVar7 = (NUMBERFMTW *)&pNVar7->lpDecimalSep;
        memcpy(pNVar7,local_d8,(longlong)pNVar11 * 2);
        *(undefined2 *)((longlong)pNVar7 + (longlong)pNVar11 * 2) = 0;
        local_108.lpDecimalSep = (LPWSTR)pNVar7;
      }
      else {
        local_108.lpDecimalSep = (LPWSTR)*(LPWSTR **)(param_4 + 0x10);
      }
      pNVar11 = pNVar7;
      if ((*param_4 & 0x10) == 0) {
        iVar5 = GetLocaleInfoW(*(LCID *)(DAT_140c7aac0 + 0xc),0xf,local_d8,0x40);
        pNVar10 = pNVar13;
        if (iVar5 == 0) goto LAB_14034c586;
        while (local_d8[0] != L'\0') {
          pNVar10 = (NUMBERFMTW *)((longlong)&pNVar10->NumDigits + 1);
          local_d8[0] = local_d8[(longlong)pNVar10];
        }
        pNVar8 = (NUMBERFMTW *)FUN_14018b280((longlong)pNVar10 * 2 + 0x12,0);
        if (pNVar8 != (NUMBERFMTW *)0x0) {
          *(NUMBERFMTW **)&pNVar8->Grouping = pNVar10;
          *(undefined ***)pNVar8 = &PTR_LAB_140b55060;
          pNVar9 = pNVar8;
        }
        pNVar9 = (NUMBERFMTW *)&pNVar9->lpDecimalSep;
        memcpy(pNVar9,local_d8,(longlong)pNVar10 * 2);
        *(undefined2 *)((longlong)pNVar9 + (longlong)pNVar10 * 2) = 0;
        local_108.lpThousandSep = (LPWSTR)pNVar9;
      }
      else {
        local_108.lpThousandSep = (LPWSTR)*(LPWSTR **)(param_4 + 0x18);
      }
      if ((*param_4 & 0x20) == 0) {
        iVar5 = GetLocaleInfoW(*(LCID *)(DAT_140c7aac0 + 0xc),0x1010,local_d8,0x40);
        pNVar10 = pNVar9;
        if (iVar5 == 0) goto LAB_14034c586;
        UVar4 = FUN_14018e820(local_d8);
      }
      else {
        UVar4 = *(UINT *)(param_4 + 0x20);
      }
      local_108.NegativeOrder = UVar4;
      goto LAB_14034c545;
    }
    iVar5 = GetLocaleInfoW(*(LCID *)(DAT_140c7aac0 + 0xc),0x10,local_d8,0x40);
    if (iVar5 != 0) {
      pWVar12 = local_d8;
      WVar2 = local_d8[0];
      UVar4 = local_108.Grouping;
      while (WVar2 != L'\0') {
        if ((ushort)(WVar2 + L'ￏ') < 9) {
          UVar4 = (uint)(ushort)WVar2 + (UVar4 * 5 + -0x18) * 2;
          local_108.Grouping = UVar4;
        }
        if ((WVar2 == L'0') && (pWVar12[1] != L'\0')) {
          UVar4 = UVar4 * 10;
          local_108.Grouping = UVar4;
        }
        pWVar1 = pWVar12 + 1;
        pWVar12 = pWVar12 + 1;
        WVar2 = *pWVar1;
      }
      goto LAB_14034c33d;
    }
  }
LAB_14034c586:
  DVar6 = GetLastError();
  pNVar13 = (NUMBERFMTW *)(ulonglong)DVar6;
  if (0 < (int)DVar6) {
    pNVar13 = (NUMBERFMTW *)(ulonglong)(DVar6 & 0xffff | 0x80070000);
  }
LAB_14034c59e:
  if (pNVar10 != (NUMBERFMTW *)0x0) {
    (**(code **)(pNVar10[-1].lpThousandSep + 4))(&pNVar10[-1].lpThousandSep);
  }
  if (pNVar11 != (NUMBERFMTW *)0x0) {
    (**(code **)(pNVar11[-1].lpThousandSep + 4))(&pNVar11[-1].lpThousandSep);
  }
  return pNVar13;
}



==== FUN_140350990 @ 140350990 size 139 ====
CALLERS: FUN_1403722d0
CALLEES: FUN_1403508e0 FUN_14018b280 FUN_140371f80

int FUN_140350990(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *local_res8;
  
  lVar1 = param_1 + (longlong)(int)param_2 * 8;
  local_res8 = (longlong *)0x0;
  if (*(longlong *)(lVar1 + 0x310) == 0) {
    iVar2 = FUN_1403508e0(param_1,param_2,&local_res8);
    plVar5 = local_res8;
    if (iVar2 < 0) goto LAB_1403509f6;
  }
  plVar5 = local_res8;
  lVar3 = FUN_14018b280(0x40);
  uVar4 = 0;
  if (lVar3 != 0) {
    uVar4 = FUN_140371f80(lVar3,*(undefined8 *)(lVar1 + 0x310));
  }
  *param_3 = uVar4;
  iVar2 = 0;
LAB_1403509f6:
  if (plVar5 != (longlong *)0x0) {
    (**(code **)(*plVar5 + 8))(plVar5);
  }
  return iVar2;
}



==== FUN_140350a20 @ 140350a20 size 367 ====
CALLERS: FUN_14037f250 FUN_14038a680 FUN_1403829c0 FUN_14037e410 FUN_14037eab0 FUN_14037f370 FUN_14037ebe0 FUN_140382c20 FUN_14037ef80 FUN_140382af0 FUN_14037ee40 FUN_14037ed10 FUN_140350a20
CALLEES: FUN_1403722d0 FUN_14018b900 FUN_14018b280 FUN_1403721f0 FUN_140350a20

ulonglong FUN_140350a20(longlong param_1,undefined8 param_2,int param_3,longlong *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  
  if (param_4 == (longlong *)0x0) {
    return 0x80070057;
  }
  if (param_3 == 0) {
    iVar2 = *(int *)(param_1 + 0x238 + (longlong)(int)param_2 * 4);
    lVar1 = param_1 + (longlong)iVar2 * 8;
    lVar3 = *(longlong *)(lVar1 + 0x268);
    if (lVar3 == 0) {
      puVar6 = (undefined8 *)FUN_14018b280(0x68);
      if (puVar6 != (undefined8 *)0x0) {
        *puVar6 = &PTR_FUN_140b65a50;
        puVar6[7] = 0;
        puVar6[8] = 0;
        puVar6[9] = 0;
        puVar6[10] = 0;
        puVar6[5] = 0;
        *(undefined4 *)(puVar6 + 6) = 0;
        puVar6[0xb] = 0;
        puVar6[0xc] = 0;
        *(undefined4 *)(puVar6 + 1) = 1;
        puVar6[2] = param_1;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        puVar6[4] = 0;
      }
      uVar4 = FUN_1403722d0(puVar6,iVar2);
      if ((int)uVar4 < 0) {
        if (puVar6 == (undefined8 *)0x0) {
          return (ulonglong)uVar4;
        }
        FUN_1403721f0(puVar6);
        FUN_14018b900(puVar6,0);
        return (ulonglong)uVar4;
      }
      *param_4 = (longlong)puVar6;
    }
    else {
      *param_4 = lVar3;
      (**(code **)**(undefined8 **)(lVar1 + 0x268))();
    }
    uVar5 = 0;
  }
  else {
    lVar1 = param_1 + (longlong)(int)param_2 * 8;
    if (*(longlong *)(lVar1 + 0x2b0) != 0) {
      *param_4 = *(longlong *)(lVar1 + 0x2b0);
      (**(code **)**(undefined8 **)(lVar1 + 0x2b0))();
      return 1;
    }
    uVar5 = FUN_140350a20(param_1,param_2,0,lVar1 + 0x2b0);
    if (-1 < (int)uVar5) {
      *param_4 = *(longlong *)(lVar1 + 0x2b0);
      (**(code **)**(undefined8 **)(lVar1 + 0x2b0))();
      return 0;
    }
  }
  return uVar5;
}



==== FUN_1403535e0 @ 1403535e0 size 311 ====
CALLERS: FUN_1403522c0
CALLEES: FUN_140003810

void FUN_1403535e0(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  
  if ((longlong *)param_1[0xa4] != (longlong *)0x0) {
    *(longlong *)param_1[0xa4] = param_1[0xa5];
  }
  if (param_1[0xa5] != 0) {
    *(longlong *)(param_1[0xa5] + 0x520) = param_1[0xa4];
  }
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  if ((longlong *)param_1[0xa2] != (longlong *)0x0) {
    *(longlong *)param_1[0xa2] = param_1[0xa3];
  }
  if (param_1[0xa3] != 0) {
    *(longlong *)(param_1[0xa3] + 0x510) = param_1[0xa2];
  }
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  iVar2 = 0xf;
  plVar3 = param_1 + 0xa4;
  do {
    plVar3 = plVar3 + -8;
    FUN_140003810(plVar3,8,6,&LAB_14036f920);
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  plVar3 = param_1 + 0x22;
  iVar2 = 3;
  do {
    lVar1 = plVar3[-2];
    plVar3 = plVar3 + -2;
    if (lVar1 != 0) {
      (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  lVar1 = param_1[0xd];
  if (lVar1 != 0) {
    (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
  }
  lVar1 = param_1[2];
  if (lVar1 != 0) {
    (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
  }
  return;
}



==== FUN_140354e10 @ 140354e10 size 311 ====
CALLERS: FUN_140354c20 FUN_140353720
CALLEES: __security_check_cookie

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140354e10(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar7 = DAT_140c657f0;
  uVar1 = *(undefined4 *)(param_1 + 0x8c);
  uVar2 = *(undefined4 *)(param_1 + 0x94);
  uVar4 = *(undefined4 *)(&DAT_140b65808 + (longlong)*(int *)(param_1 + 0x9c) * 4);
  uVar5 = *(undefined4 *)(&DAT_140b62ce8 + (longlong)*(int *)(param_1 + 0x90) * 4);
  uVar3 = *(undefined4 *)(&DAT_140b65818 + (longlong)*(int *)(param_1 + 0x98) * 4);
  if (DAT_140c657f0 != 0) {
    if (((*(longlong *)(DAT_140c657f0 + 0x538) != *(longlong *)(param_1 + 0x88)) ||
        (*(longlong *)(DAT_140c657f0 + 0x540) != CONCAT44(uVar5,uVar4))) ||
       (*(longlong *)(DAT_140c657f0 + 0x548) != CONCAT44(uVar3,uVar2))) {
      lVar6 = *(longlong *)(DAT_140c657f0 + 0x28);
      *(undefined4 *)(DAT_140c657f0 + 0x538) = *(undefined4 *)(param_1 + 0x88);
      *(undefined4 *)(lVar7 + 0x53c) = uVar1;
      *(undefined4 *)(lVar7 + 0x540) = uVar4;
      *(undefined4 *)(lVar7 + 0x544) = uVar5;
      *(undefined4 *)(lVar7 + 0x548) = uVar2;
      *(undefined4 *)(lVar7 + 0x54c) = uVar3;
      for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x200)) {
      }
    }
    return 0;
  }
  return 0x80004005;
}



==== FUN_140355d50 @ 140355d50 size 1036 ====
CALLERS: FUN_140354c20 FUN_140355bf0
CALLEES: FUN_1401b24c0 __security_check_cookie FUN_140383760

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140355d50(longlong param_1,int *param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong *plVar7;
  int iVar8;
  longlong lVar9;
  int iVar10;
  longlong *plVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  int local_d0;
  int local_cc;
  int *local_c8;
  int *local_c0;
  int local_b8 [32];
  ulonglong local_38;
  
  local_38 = DAT_140c0f7b0 ^ (ulonglong)auStack_f8;
  local_c0 = (int *)(param_1 + 0x9c0);
  local_d0 = *(int *)(param_1 + 0x9c8);
  if (*(int *)(param_1 + 0x894) < *(int *)(param_1 + 0x9c8)) {
    local_d0 = *(int *)(param_1 + 0x894);
  }
  local_cc = *(int *)(param_1 + 0x9cc);
  if (*(int *)(param_1 + 0x898) < *(int *)(param_1 + 0x9cc)) {
    local_cc = *(int *)(param_1 + 0x898);
  }
  iVar13 = *local_c0;
  if (*local_c0 < *(int *)(param_1 + 0x88c)) {
    iVar13 = *(int *)(param_1 + 0x88c);
  }
  iVar3 = *(int *)(param_1 + 0x9c4);
  if (*(int *)(param_1 + 0x9c4) < *(int *)(param_1 + 0x890)) {
    iVar3 = *(int *)(param_1 + 0x890);
  }
  local_c8 = param_2;
  if ((iVar13 < local_d0) && (iVar3 < local_cc)) {
    local_d8 = (int *)CONCAT44(iVar3,iVar13);
    lVar9 = FUN_1401b24c0(&local_d8,param_2,local_b8);
    piVar12 = local_b8 + lVar9 * 4;
    if (local_b8 < piVar12) {
      piVar14 = local_b8 + 3;
      local_d8 = piVar12;
      do {
        iVar13 = piVar14[-2];
        iVar3 = *piVar14;
        if (iVar13 < iVar3) {
          iVar4 = piVar14[-3];
          iVar5 = piVar14[-1];
          iVar8 = iVar4;
          piVar12 = local_d8;
          do {
            for (; local_d8 = piVar12, iVar8 < iVar5; iVar8 = iVar8 + 1) {
              iVar6 = *(int *)(param_1 + 0x89c);
              iVar10 = iVar13 % *(int *)(param_1 + 0x8a0);
              plVar7 = *(longlong **)
                        (*(longlong *)(param_1 + 0x8e0) +
                        (ulonglong)
                        ((uint)(iVar8 % iVar6 < 0) * iVar6 +
                        ((uint)(iVar10 < 0) * *(int *)(param_1 + 0x8a0) + iVar10) * iVar6 +
                        iVar8 % iVar6) * 8);
              if ((plVar7 != (longlong *)0x0) && ((int)plVar7[0x62] != 0)) {
                *(undefined4 *)(plVar7 + 0x62) = 0;
                FUN_140383760(plVar7);
                *(uint *)((longlong)plVar7 + 0x2c) = *(uint *)((longlong)plVar7 + 0x2c) & 0xfffffff5
                ;
                if (plVar7[0xb9] == 0) {
                  plVar2 = plVar7 + 0xba;
                  plVar11 = (longlong *)(*plVar7 + 0x908);
                  plVar7[0xb9] = (longlong)plVar11;
                  *plVar2 = *plVar11;
                  *plVar11 = (longlong)plVar7;
                  if (*plVar2 != 0) {
                    *(longlong **)(*plVar2 + 0x5c8) = plVar2;
                  }
                  *(int *)(*plVar7 + 0x87c) = *(int *)(*plVar7 + 0x87c) + 1;
                }
              }
              piVar12 = local_d8;
            }
            iVar13 = iVar13 + 1;
            iVar8 = iVar4;
          } while (iVar13 < iVar3);
        }
        piVar1 = piVar14 + 1;
        param_2 = local_c8;
        piVar14 = piVar14 + 4;
      } while (piVar1 < piVar12);
    }
  }
  local_d0 = param_2[2];
  if (*(int *)(param_1 + 0x894) < param_2[2]) {
    local_d0 = *(int *)(param_1 + 0x894);
  }
  local_cc = param_2[3];
  if (*(int *)(param_1 + 0x898) < param_2[3]) {
    local_cc = *(int *)(param_1 + 0x898);
  }
  iVar13 = *param_2;
  if (*param_2 < *(int *)(param_1 + 0x88c)) {
    iVar13 = *(int *)(param_1 + 0x88c);
  }
  iVar3 = param_2[1];
  if (param_2[1] < *(int *)(param_1 + 0x890)) {
    iVar3 = *(int *)(param_1 + 0x890);
  }
  if ((iVar13 < local_d0) && (iVar3 < local_cc)) {
    local_d8 = (int *)CONCAT44(iVar3,iVar13);
    lVar9 = FUN_1401b24c0(&local_d8,param_1 + 0x9c0,local_b8);
    piVar12 = local_b8 + lVar9 * 4;
    if (local_b8 < piVar12) {
      piVar14 = local_b8 + 3;
      local_d8 = piVar12;
      do {
        iVar13 = piVar14[-2];
        iVar3 = *piVar14;
        if (iVar13 < iVar3) {
          iVar4 = piVar14[-3];
          iVar5 = piVar14[-1];
          iVar8 = iVar4;
          piVar12 = local_d8;
          do {
            for (; local_d8 = piVar12, iVar8 < iVar5; iVar8 = iVar8 + 1) {
              iVar6 = *(int *)(param_1 + 0x89c);
              iVar10 = iVar13 % *(int *)(param_1 + 0x8a0);
              plVar7 = *(longlong **)
                        (*(longlong *)(param_1 + 0x8e0) +
                        (ulonglong)
                        ((uint)(iVar8 % iVar6 < 0) * iVar6 +
                        ((uint)(iVar10 < 0) * *(int *)(param_1 + 0x8a0) + iVar10) * iVar6 +
                        iVar8 % iVar6) * 8);
              if ((plVar7 != (longlong *)0x0) && ((int)plVar7[0x62] == 0)) {
                *(undefined4 *)(plVar7 + 0x62) = 1;
                FUN_140383760(plVar7);
                *(uint *)((longlong)plVar7 + 0x2c) = *(uint *)((longlong)plVar7 + 0x2c) & 0xfffffff5
                ;
                if (plVar7[0xb9] == 0) {
                  plVar2 = plVar7 + 0xba;
                  plVar11 = (longlong *)(*plVar7 + 0x908);
                  plVar7[0xb9] = (longlong)plVar11;
                  *plVar2 = *plVar11;
                  *plVar11 = (longlong)plVar7;
                  if (*plVar2 != 0) {
                    *(longlong **)(*plVar2 + 0x5c8) = plVar2;
                  }
                  *(int *)(*plVar7 + 0x87c) = *(int *)(*plVar7 + 0x87c) + 1;
                }
              }
              piVar12 = local_d8;
            }
            iVar13 = iVar13 + 1;
            iVar8 = iVar4;
          } while (iVar13 < iVar3);
        }
        piVar1 = piVar14 + 1;
        param_2 = local_c8;
        piVar14 = piVar14 + 4;
      } while (piVar1 < piVar12);
    }
  }
  *local_c0 = *param_2;
  local_c0[1] = param_2[1];
  local_c0[2] = param_2[2];
  local_c0[3] = param_2[3];
  return 0;
}



==== FUN_140356160 @ 140356160 size 452 ====
CALLERS: FUN_14036dd50
CALLEES: FUN_1403786a0 FUN_14038e9a0 FUN_140378110 FUN_14037aa70 FUN_14038c060 FUN_14038bdb0 FUN_14038dc80

undefined8 FUN_140356160(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x13b0);
  while (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 0x4a0) != 0) {
      FUN_140378110(lVar1);
      FUN_1403786a0(lVar1);
      if (*(undefined8 **)(lVar1 + 0x4a0) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar1 + 0x4a0) = *(undefined8 *)(lVar1 + 0x4a8);
      }
      if (*(longlong *)(lVar1 + 0x4a8) != 0) {
        *(undefined8 *)(*(longlong *)(lVar1 + 0x4a8) + 0x4a0) = *(undefined8 *)(lVar1 + 0x4a0);
      }
      *(undefined8 *)(lVar1 + 0x4a0) = 0;
      *(undefined8 *)(lVar1 + 0x4a8) = 0;
    }
    lVar1 = *(longlong *)(param_1 + 0x13b0);
  }
  lVar1 = *(longlong *)(param_1 + 0x1490);
  while (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 0x410) != 0) {
      FUN_14038bdb0(lVar1);
      FUN_14038c060(lVar1);
      if (*(undefined8 **)(lVar1 + 0x410) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar1 + 0x410) = *(undefined8 *)(lVar1 + 0x418);
      }
      if (*(longlong *)(lVar1 + 0x418) != 0) {
        *(undefined8 *)(*(longlong *)(lVar1 + 0x418) + 0x410) = *(undefined8 *)(lVar1 + 0x410);
      }
      *(undefined8 *)(lVar1 + 0x410) = 0;
      *(undefined8 *)(lVar1 + 0x418) = 0;
    }
    lVar1 = *(longlong *)(param_1 + 0x1490);
  }
  lVar1 = *(longlong *)(param_1 + 0x14e8);
  while (lVar1 != 0) {
    FUN_14038dc80(lVar1);
    lVar1 = *(longlong *)(param_1 + 0x14e8);
  }
  lVar1 = *(longlong *)(param_1 + 0x1500);
  while (lVar1 != 0) {
    FUN_14038e9a0(lVar1);
    lVar1 = *(longlong *)(param_1 + 0x1500);
  }
  plVar2 = *(longlong **)(param_1 + 0x1568);
  while (plVar2 != (longlong *)0x0) {
    (**(code **)*plVar2)(plVar2);
    FUN_14037aa70(plVar2);
    *(undefined4 *)((longlong)plVar2 + 0xc) = 0;
    if (*(float *)(plVar2 + 10) < *(float *)((longlong)plVar2 + 0x44) ||
        *(float *)(plVar2 + 10) == *(float *)((longlong)plVar2 + 0x44)) {
      *(undefined4 *)((longlong)plVar2 + 0xc) = 1;
    }
    if (*(float *)((longlong)plVar2 + 0x34) <= *(float *)((longlong)plVar2 + 0x54)) {
      *(uint *)((longlong)plVar2 + 0xc) = *(uint *)((longlong)plVar2 + 0xc) | 2;
    }
    if ((longlong *)plVar2[0xd] != (longlong *)0x0) {
      *(longlong *)plVar2[0xd] = plVar2[0xe];
    }
    if (plVar2[0xe] != 0) {
      *(longlong *)(plVar2[0xe] + 0x68) = plVar2[0xd];
    }
    plVar2[0xd] = 0;
    plVar2[0xe] = 0;
    (**(code **)(*plVar2 + 8))(plVar2);
    plVar2 = *(longlong **)(param_1 + 0x1568);
  }
  return 0;
}



==== FUN_14035a150 @ 14035a150 size 2756 ====
CALLERS: FUN_1403617a0
CALLEES: FUN_1408fd190 FUN_14035bf90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14035a150(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  longlong lVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  int *piVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  float fVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  int local_res18;
  int local_res1c;
  int local_res20;
  int local_res24;
  float local_198;
  float local_194;
  float *local_190;
  undefined8 local_188;
  int local_180;
  int local_17c;
  longlong local_178;
  float local_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float local_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float local_148;
  float local_144;
  float *local_140;
  undefined8 local_138;
  float local_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  float local_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float local_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  
  *(undefined4 *)(param_1 + 0x354) = 0;
  fVar5 = DAT_140b79fac;
  fVar4 = DAT_140b79ed0;
  if (((*(uint *)(param_1 + 0x80) & 0x1000000) != 0) && (*(float *)(param_1 + 0x52c) != 0.0)) {
    iVar16 = (int)((_DAT_140b7ac50 + *(float *)(param_1 + 0x390) * DAT_140c43fb8) * _DAT_140b7b490);
    iVar6 = (int)((_UNK_140b7ac54 + *(float *)(param_1 + 0x398) * DAT_140c43fb8) * _UNK_140b7b494);
    if ((*(int *)(param_1 + 0x88c) <= iVar16) &&
       (((iVar16 < *(int *)(param_1 + 0x894) && (*(int *)(param_1 + 0x890) <= iVar6)) &&
        (iVar6 < *(int *)(param_1 + 0x898))))) {
      iVar11 = *(int *)(param_1 + 0x89c);
      iVar8 = iVar6 % *(int *)(param_1 + 0x8a0);
      lVar2 = *(longlong *)
               (*(longlong *)(param_1 + 0x8e0) +
               (ulonglong)
               ((uint)(iVar16 % iVar11 < 0) * iVar11 +
               ((uint)(iVar8 < 0) * *(int *)(param_1 + 0x8a0) + iVar8) * iVar11 + iVar16 % iVar11) *
               8);
      if ((lVar2 != 0) &&
         (fVar24 = *(float *)(lVar2 + 0xc4),
         *(float *)(param_1 + 0x394) <= fVar24 && fVar24 != *(float *)(param_1 + 0x394))) {
        return;
      }
    }
    lVar2 = *(longlong *)(param_1 + 0x920);
    local_190 = &local_148;
    local_148 = DAT_140c440d8;
    local_198 = (float)((uint)DAT_140c440d8 ^ DAT_140b7b530);
    local_188 = 0;
    local_140 = &local_198;
    local_138 = 0;
    local_194 = local_198;
    local_144 = local_198;
    for (; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x590)) {
      lVar17 = 0;
      local_168 = *(float *)(lVar2 + 0x140) - *(float *)(param_1 + 0x390);
      fStack_164 = *(float *)(lVar2 + 0x144) - *(float *)(param_1 + 0x394);
      fVar25 = *(float *)(lVar2 + 0x148) - *(float *)(param_1 + 0x398);
      fStack_15c = *(float *)(lVar2 + 0x14c) - *(float *)(param_1 + 0x39c);
      fVar23 = *(float *)(lVar2 + 0x150) - *(float *)(param_1 + 0x390);
      fStack_154 = *(float *)(lVar2 + 0x154) - *(float *)(param_1 + 0x394);
      fVar24 = *(float *)(lVar2 + 0x158) - *(float *)(param_1 + 0x398);
      fStack_14c = *(float *)(lVar2 + 0x15c) - *(float *)(param_1 + 0x39c);
      auVar22._4_4_ = fStack_164;
      auVar22._0_4_ = local_168;
      auVar22._8_4_ = fVar25;
      auVar22._12_4_ = fStack_15c;
      fStack_160 = fVar25;
      local_158 = fVar23;
      fStack_150 = fVar24;
      local_118 = 0;
      uStack_110 = 0;
      auVar21._4_4_ = fStack_154;
      auVar21._0_4_ = fVar23;
      auVar21._8_4_ = fVar24;
      auVar21._12_4_ = fStack_14c;
      auVar21 = minps(ZEXT816(0),auVar21);
      local_108 = (local_168 + fVar23) * _DAT_140b7ac50;
      fStack_100 = (fVar25 + fVar24) * _UNK_140b7ac58;
      auVar21 = maxps(auVar22,auVar21);
      fStack_104 = (fStack_164 + fStack_154) * _UNK_140b7ac54;
      fStack_fc = (fStack_15c + fStack_14c) * _UNK_140b7ac5c;
      fVar26 = fVar4 / SQRT(auVar21._8_4_ * auVar21._8_4_ + auVar21._0_4_ * auVar21._0_4_);
      *(float *)(lVar2 + 0x514) = fVar26;
      fVar20 = fVar24;
      if (fStack_100 < 0.0) {
        fVar20 = fVar25;
      }
      if (local_108 < 0.0) {
        fVar23 = local_168;
      }
      fVar23 = fVar4 / SQRT(fVar20 * fVar20 + fVar23 * fVar23);
      *(float *)(lVar2 + 0x518) = fVar23;
      if (0.0 <= fStack_164) {
        *(float *)(lVar2 + 0x510) = fVar23 * fStack_164;
      }
      else {
        *(float *)(lVar2 + 0x510) = fVar26 * fStack_164;
      }
      iVar11 = *(int *)(lVar2 + 0xc);
      iVar8 = *(int *)(lVar2 + 8);
      if (iVar11 < iVar6) {
        if (iVar8 < iVar16) {
          fVar23 = (float)FUN_1408fd190(fVar24);
          fVar24 = fVar25;
LAB_14035a4cf:
          fVar20 = (float)FUN_1408fd190(fVar24);
          iVar11 = iVar11 + 1;
          if (((*(int *)(param_1 + 0x88c) <= iVar8) && (iVar8 < *(int *)(param_1 + 0x894))) &&
             ((*(int *)(param_1 + 0x890) <= iVar11 && (iVar11 < *(int *)(param_1 + 0x898))))) {
            iVar1 = *(int *)(param_1 + 0x89c);
            iVar11 = iVar11 % *(int *)(param_1 + 0x8a0);
            lVar7 = *(longlong *)
                     (*(longlong *)(param_1 + 0x8e0) +
                     (ulonglong)
                     ((uint)(iVar8 % iVar1 < 0) * iVar1 +
                     ((uint)(iVar11 < 0) * *(int *)(param_1 + 0x8a0) + iVar11) * iVar1 +
                     iVar8 % iVar1) * 8);
            goto LAB_14035a93b;
          }
        }
        else {
          if (iVar8 == iVar16) {
            fVar23 = (float)FUN_1408fd190(fVar24);
            goto LAB_14035a4cf;
          }
          fVar23 = (float)FUN_1408fd190(fVar25);
          fVar20 = (float)FUN_1408fd190(fVar24);
          iVar8 = iVar8 + -1;
          if ((((*(int *)(param_1 + 0x88c) <= iVar8) && (iVar8 < *(int *)(param_1 + 0x894))) &&
              (*(int *)(param_1 + 0x890) <= iVar11)) && (iVar11 < *(int *)(param_1 + 0x898))) {
            iVar1 = *(int *)(param_1 + 0x89c);
            iVar11 = iVar11 % *(int *)(param_1 + 0x8a0);
            lVar7 = *(longlong *)
                     (*(longlong *)(param_1 + 0x8e0) +
                     (ulonglong)
                     ((uint)(iVar8 % iVar1 < 0) * iVar1 +
                     ((uint)(iVar11 < 0) * *(int *)(param_1 + 0x8a0) + iVar11) * iVar1 +
                     iVar8 % iVar1) * 8);
            goto LAB_14035a93b;
          }
        }
LAB_14035a62c:
        pfVar13 = &local_198;
      }
      else {
        if (iVar11 == iVar6) {
          if (iVar8 < iVar16) {
            fVar23 = (float)FUN_1408fd190(fVar24);
            goto LAB_14035a846;
          }
          fVar23 = DAT_140b7a278;
          fVar20 = fVar5;
          if (iVar8 == iVar16) goto LAB_14035a62c;
          fVar23 = (float)FUN_1408fd190(fVar25);
          fVar20 = (float)FUN_1408fd190(fVar24);
          local_res18 = iVar8 + -1;
          piVar12 = &local_res18;
          local_res1c = iVar11;
LAB_14035a930:
          lVar7 = FUN_14035bf90(param_1,piVar12);
        }
        else {
          if (iVar16 <= iVar8) {
            if (iVar8 == iVar16) {
              fVar23 = (float)FUN_1408fd190(fVar25);
              fVar20 = (float)FUN_1408fd190(fVar25);
              local_res24 = iVar11 + -1;
              piVar12 = &local_res20;
              local_res20 = iVar8;
            }
            else {
              fVar23 = (float)FUN_1408fd190(fVar25);
              fVar20 = (float)FUN_1408fd190(fVar24);
              local_17c = iVar11 + -1;
              piVar12 = &local_180;
              local_180 = iVar8;
            }
            goto LAB_14035a930;
          }
          fVar23 = (float)FUN_1408fd190(fVar24);
LAB_14035a846:
          fVar20 = (float)FUN_1408fd190(fVar25);
          iVar8 = iVar8 + 1;
          if (((iVar8 < *(int *)(param_1 + 0x88c)) || (*(int *)(param_1 + 0x894) <= iVar8)) ||
             ((iVar11 < *(int *)(param_1 + 0x890) || (*(int *)(param_1 + 0x898) <= iVar11))))
          goto LAB_14035a62c;
          iVar1 = *(int *)(param_1 + 0x89c);
          iVar11 = iVar11 % *(int *)(param_1 + 0x8a0);
          lVar7 = *(longlong *)
                   (*(longlong *)(param_1 + 0x8e0) +
                   (ulonglong)
                   ((uint)(iVar8 % iVar1 < 0) * iVar1 +
                   ((uint)(iVar11 < 0) * *(int *)(param_1 + 0x8a0) + iVar11) * iVar1 + iVar8 % iVar1
                   ) * 8);
        }
LAB_14035a93b:
        if (((lVar7 == 0) || (*(longlong *)(lVar7 + 0x588) == 0)) ||
           ((pfVar13 = (float *)(lVar7 + 0x520), fVar23 < *pfVar13 || fVar23 == *pfVar13 ||
            (*(float *)(lVar2 + 0x30) < *(float *)(lVar7 + 0x30) ||
             *(float *)(lVar2 + 0x30) == *(float *)(lVar7 + 0x30))))) goto LAB_14035a62c;
        for (pfVar14 = *(float **)(lVar7 + 0x530); pfVar14 != (float *)0x0;
            pfVar14 = *(float **)(pfVar14 + 4)) {
          pfVar13 = pfVar14;
        }
      }
      if (**(float **)(pfVar13 + 2) <= fVar23 && fVar23 != **(float **)(pfVar13 + 2)) {
        do {
          pfVar13 = *(float **)(pfVar13 + 2);
        } while (**(float **)(pfVar13 + 2) <= fVar23 && fVar23 != **(float **)(pfVar13 + 2));
      }
      pfVar14 = (float *)(lVar2 + 0x520);
      *pfVar14 = fVar23;
      pfVar9 = &local_198;
      if (fVar23 <= fVar20) {
        pfVar9 = pfVar14;
      }
      *(float *)(lVar2 + 0x524) = pfVar13[1];
      uVar3 = *(undefined8 *)(pfVar13 + 2);
      *(undefined8 *)(lVar2 + 0x530) = 0;
      *(undefined8 *)(lVar2 + 0x528) = uVar3;
      fVar23 = DAT_140c440d8;
      *(float **)(pfVar13 + 2) = pfVar14;
      fVar24 = **(float **)(pfVar9 + 2);
      while (fVar24 <= fVar20) {
        pfVar9 = *(float **)(pfVar9 + 2);
        fVar24 = **(float **)(pfVar9 + 2);
      }
      lVar7 = *(longlong *)(pfVar9 + 2);
      pfVar10 = (float *)(lVar2 + 0x538);
      local_178 = lVar7;
      *pfVar10 = fVar20;
      *(float *)(lVar2 + 0x53c) = pfVar9[1];
      uVar3 = *(undefined8 *)(pfVar9 + 2);
      *(undefined8 *)(lVar2 + 0x548) = 0;
      *(undefined8 *)(lVar2 + 0x540) = uVar3;
      *(float **)(pfVar9 + 2) = pfVar10;
      for (pfVar9 = pfVar14; pfVar9 != pfVar10; pfVar9 = *(float **)(pfVar9 + 2)) {
        fVar24 = *(float *)(lVar2 + 0x510);
        if (*(float *)(lVar2 + 0x510) <= pfVar9[1]) {
          fVar24 = pfVar9[1];
        }
        pfVar9[1] = fVar24;
        if (fVar24 <= fVar23) {
          fVar23 = fVar24;
        }
      }
      *(float *)(lVar2 + 0x510) = fVar23;
      if (*(longlong *)(lVar2 + 0x568) != 0) {
        lVar18 = (*(longlong *)(lVar2 + 0x568) - 1U >> 1) + 1;
        lVar19 = lVar17;
        do {
          pfVar9 = (float *)(lVar17 + *(longlong *)(lVar2 + 0x560));
          pfVar10 = (float *)(lVar17 + 0x10 + *(longlong *)(lVar2 + 0x560));
          local_128 = *pfVar9 - *(float *)(param_1 + 0x390);
          fStack_124 = pfVar9[1] - *(float *)(param_1 + 0x394);
          fStack_120 = pfVar9[2] - *(float *)(param_1 + 0x398);
          fStack_11c = pfVar9[3] - *(float *)(param_1 + 0x39c);
          local_f8 = *pfVar10 - *(float *)(param_1 + 0x390);
          fStack_f4 = pfVar10[1] - *(float *)(param_1 + 0x394);
          fStack_f0 = pfVar10[2] - *(float *)(param_1 + 0x398);
          fStack_ec = pfVar10[3] - *(float *)(param_1 + 0x39c);
          fVar24 = fStack_124;
          if (fStack_f4 <= fStack_124) {
            fVar24 = fStack_f4;
          }
          if (0.0 <= fVar24) {
            fVar23 = local_128 * local_128 + fStack_120 * fStack_120;
            fVar20 = fStack_f0 * fStack_f0 + local_f8 * local_f8;
            if (fVar23 <= fVar20) {
              fVar23 = fVar20;
            }
          }
          else {
            fVar20 = local_f8 - local_128;
            fVar25 = fStack_f0 - fStack_120;
            fVar23 = (float)((uint)((fVar25 * fStack_120 + fVar20 * local_128) /
                                   (fVar20 * fVar20 + fVar25 * fVar25)) ^ DAT_140b7b530);
            if (fVar4 <= fVar23) {
              fVar23 = fVar4;
            }
            fVar26 = 0.0;
            if (0.0 <= fVar23) {
              fVar26 = fVar23;
            }
            fVar23 = fVar26 * fVar20 + local_128;
            fVar20 = fVar26 * fVar25 + fStack_120;
            fVar23 = fVar23 * fVar23 + fVar20 * fVar20;
          }
          fVar25 = (float)FUN_1408fd190(fStack_120);
          fVar20 = (float)FUN_1408fd190(fStack_f0);
          if (((fVar25 < fVar20) && (fVar5 < fVar20 - fVar25)) ||
             ((fVar26 = fVar25, fVar20 < fVar25 && (fVar25 - fVar20 < fVar5)))) {
            fVar26 = fVar20;
            fVar20 = fVar25;
          }
          pfVar9 = &local_198;
          if (*pfVar14 <= fVar26) {
            pfVar9 = pfVar14;
          }
          pfVar10 = pfVar9 + 2;
          if (**(float **)pfVar10 <= fVar26 && fVar26 != **(float **)pfVar10) {
            do {
              pfVar9 = *(float **)pfVar10;
              pfVar10 = pfVar9 + 2;
            } while (**(float **)(pfVar9 + 2) <= fVar26 && fVar26 != **(float **)(pfVar9 + 2));
          }
          pfVar10 = (float *)(*(longlong *)(lVar2 + 0x550) + lVar19);
          *pfVar10 = fVar26;
          pfVar10[1] = pfVar9[1];
          uVar3 = *(undefined8 *)(pfVar9 + 2);
          pfVar10[4] = 0.0;
          pfVar10[5] = 0.0;
          *(undefined8 *)(pfVar10 + 2) = uVar3;
          *(float **)(pfVar9 + 2) = pfVar10;
          pfVar9 = &local_198;
          if (*pfVar14 <= fVar20) {
            pfVar9 = pfVar14;
          }
          pfVar15 = pfVar9 + 2;
          fVar25 = **(float **)pfVar15;
          while (fVar25 <= fVar20) {
            pfVar9 = *(float **)pfVar15;
            pfVar15 = pfVar9 + 2;
            fVar25 = **(float **)(pfVar9 + 2);
          }
          pfVar15 = (float *)(*(longlong *)(lVar2 + 0x550) + 0x18 + lVar19);
          *pfVar15 = fVar20;
          pfVar15[1] = pfVar9[1];
          uVar3 = *(undefined8 *)(pfVar9 + 2);
          pfVar15[4] = 0.0;
          pfVar15[5] = 0.0;
          *(undefined8 *)(pfVar15 + 2) = uVar3;
          *(float **)(pfVar9 + 2) = pfVar15;
          for (; pfVar10 != pfVar15; pfVar10 = *(float **)(pfVar10 + 2)) {
            fVar20 = fVar24 / SQRT(fVar23);
            if (fVar24 / SQRT(fVar23) <= pfVar10[1]) {
              fVar20 = pfVar10[1];
            }
            pfVar10[1] = fVar20;
          }
          lVar17 = lVar17 + 0x20;
          lVar19 = lVar19 + 0x30;
          lVar18 = lVar18 + -1;
          lVar7 = local_178;
        } while (lVar18 != 0);
      }
      lVar17 = *(longlong *)(pfVar13 + 2);
      while (lVar17 != lVar7) {
        pfVar14 = *(float **)(pfVar13 + 2);
        if (pfVar14 == &local_148) {
          pfVar14 = &local_198;
        }
        else if ((pfVar14[1] == pfVar13[1]) || (*pfVar14 == *pfVar13)) {
          *(float **)(pfVar14 + 4) = pfVar13;
          pfVar13[1] = *(float *)(*(longlong *)(pfVar13 + 2) + 4);
          *(undefined8 *)(pfVar13 + 2) = *(undefined8 *)(*(longlong *)(pfVar13 + 2) + 8);
          pfVar14 = pfVar13;
        }
        pfVar13 = pfVar14;
        lVar17 = *(longlong *)(pfVar14 + 2);
      }
    }
    *(undefined4 *)(param_1 + 0x354) = 1;
  }
  return;
}



==== FUN_14035bc40 @ 14035bc40 size 426 ====
CALLERS:
CALLEES: FUN_140371430

void FUN_14035bc40(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  
  plVar1 = (longlong *)(param_1 + 0x1528);
  lVar3 = *plVar1;
  while (lVar3 != 0) {
    if (*(undefined8 **)(lVar3 + 0x40) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar3 + 0x40) = *(undefined8 *)(lVar3 + 0x48);
    }
    if (*(longlong *)(lVar3 + 0x48) != 0) {
      *(undefined8 *)(*(longlong *)(lVar3 + 0x48) + 0x40) = *(undefined8 *)(lVar3 + 0x40);
    }
    *(undefined8 *)(lVar3 + 0x40) = 0;
    *(undefined8 *)(lVar3 + 0x48) = 0;
    lVar3 = *plVar1;
  }
  plVar2 = (longlong *)(param_1 + 0x1530);
  lVar3 = *plVar2;
  while (lVar3 != 0) {
    if (*(undefined8 **)(lVar3 + 0x40) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar3 + 0x40) = *(undefined8 *)(lVar3 + 0x48);
    }
    if (*(longlong *)(lVar3 + 0x48) != 0) {
      *(undefined8 *)(*(longlong *)(lVar3 + 0x48) + 0x40) = *(undefined8 *)(lVar3 + 0x40);
    }
    *(undefined8 *)(lVar3 + 0x40) = 0;
    *(undefined8 *)(lVar3 + 0x48) = 0;
    lVar3 = *plVar2;
  }
  lVar3 = *(longlong *)(param_1 + 0x1520);
  do {
    if (lVar3 == 0) {
      FUN_140371430(plVar1,0x40,&LAB_140390460);
      for (lVar3 = *(longlong *)(param_1 + 0x1558); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x148)
          ) {
        FUN_140371430(lVar3 + 0x98,0x20,&LAB_140390480);
      }
      return;
    }
    for (plVar4 = *(longlong **)(lVar3 + 0xe0); plVar4 != (longlong *)0x0;
        plVar4 = (longlong *)plVar4[7]) {
      if (*plVar4 == 0) {
        if ((*(int *)(param_1 + 0x770) == 0) && (plVar4[8] == 0)) {
          plVar4[8] = (longlong)plVar1;
          plVar4[9] = *plVar1;
          *plVar1 = (longlong)plVar4;
LAB_14035bd3a:
          lVar5 = plVar4[9];
          if (lVar5 != 0) {
            *(longlong **)(lVar5 + 0x40) = plVar4 + 9;
          }
        }
      }
      else if ((*(longlong *)(*plVar4 + 0x140) != 0) && (plVar4[8] == 0)) {
        plVar4[8] = (longlong)plVar2;
        plVar4[9] = *plVar2;
        *plVar2 = (longlong)plVar4;
        goto LAB_14035bd3a;
      }
    }
    if (*(undefined8 **)(lVar3 + 0xf8) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar3 + 0xf8) = *(undefined8 *)(lVar3 + 0x100);
    }
    if (*(longlong *)(lVar3 + 0x100) != 0) {
      *(undefined8 *)(*(longlong *)(lVar3 + 0x100) + 0xf8) = *(undefined8 *)(lVar3 + 0xf8);
    }
    *(undefined8 *)(lVar3 + 0xf8) = 0;
    *(undefined8 *)(lVar3 + 0x100) = 0;
    lVar3 = *(longlong *)(param_1 + 0x1520);
  } while( true );
}



==== FUN_14035ed70 @ 14035ed70 size 430 ====
CALLERS: FUN_14035ef20
CALLEES:

void FUN_14035ed70(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined *puVar12;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_44;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined4 local_24;
  
  local_58 = CONCAT44(local_58._4_4_,1);
  local_38[0] = 1;
  uVar9 = 0;
  local_44 = 0;
  local_24 = 0;
  puVar12 = &DAT_140c3fe88;
  uStack_50 = param_3;
  local_30 = param_2;
  (**(code **)(*DAT_140c65670 + 0x208))
            (DAT_140c65670,local_38,&local_58,&DAT_140c3fe88,&DAT_140c3fe88);
  (**(code **)(*DAT_140c65670 + 0x278))(DAT_140c65670,1);
  puVar8 = (undefined8 *)
           (**(code **)(*DAT_140c65670 + 0x110))
                     (DAT_140c65670,0x90,0,0,(ulonglong)puVar12 & 0xffffffff00000000);
  if (puVar8 != (undefined8 *)0x0) {
    local_58 = 0;
    uStack_50 = 0;
    puVar11 = &local_58;
    puVar10 = puVar8;
    do {
      lVar2 = *param_4;
      if (lVar2 != 0) {
        uVar1 = *(undefined4 *)(lVar2 + 0x4c);
        uVar7 = *(undefined8 *)(lVar2 + 0x88);
        *puVar10 = *(undefined8 *)(lVar2 + 0x80);
        puVar10[1] = uVar7;
        uVar3 = *(undefined4 *)(lVar2 + 0x90);
        uVar4 = *(undefined4 *)(lVar2 + 0x94);
        uVar5 = *(undefined4 *)(lVar2 + 0x98);
        uVar6 = *(undefined4 *)(lVar2 + 0x9c);
        *(undefined4 *)puVar11 = uVar1;
        *(undefined4 *)(puVar10 + 2) = uVar3;
        *(undefined4 *)((longlong)puVar10 + 0x14) = uVar4;
        *(undefined4 *)(puVar10 + 3) = uVar5;
        *(undefined4 *)((longlong)puVar10 + 0x1c) = uVar6;
        (**(code **)(*DAT_140c65670 + 0x160))
                  (DAT_140c65670,uVar9,*(undefined8 *)(*param_4 + 0x50),0,0);
        (**(code **)(*DAT_140c65670 + 0x160))
                  (DAT_140c65670,uVar9 + 4,*(undefined8 *)(*param_4 + 0x58),0,0);
      }
      uVar9 = uVar9 + 1;
      puVar10 = puVar10 + 4;
      puVar11 = (undefined8 *)((longlong)puVar11 + 4);
      param_4 = param_4 + 1;
    } while (uVar9 < 4);
    *(undefined4 *)(puVar8 + 0x10) = (undefined4)local_58;
    *(undefined4 *)((longlong)puVar8 + 0x84) = local_58._4_4_;
    *(undefined4 *)(puVar8 + 0x11) = (undefined4)uStack_50;
    *(undefined4 *)((longlong)puVar8 + 0x8c) = uStack_50._4_4_;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  (**(code **)(*DAT_140c65670 + 0x298))(DAT_140c65670,0xffffffff,DAT_140b79ed0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x00014035ef17. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_140c65670 + 0x2a0))();
  return;
}



==== FUN_14035f590 @ 14035f590 size 268 ====
CALLERS: FUN_14035ff70
CALLEES:

undefined8 FUN_14035f590(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  iVar1 = (**(code **)(*DAT_140c65688 + 0x38))(DAT_140c65688,7);
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*DAT_140c65688 + 0x38))(DAT_140c65688,6), iVar1 != 0)) {
    return 0;
  }
  lVar2 = (**(code **)(*DAT_140c65688 + 0xc0))();
  puVar3 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xd0))();
  (**(code **)(*DAT_140c65688 + 0x50))();
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,*puVar3,0,0);
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x58),3);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,1,5);
  (**(code **)(*DAT_140c65670 + 0x298))
            (DAT_140c65670,0xffffffff,0,lVar2 + 0x58,lVar2 + 0x60,lVar2 + 0x60);
  return 0;
}



==== FUN_14035f6a0 @ 14035f6a0 size 415 ====
CALLERS: FUN_14035ff70
CALLEES: FUN_1408fc950

undefined8 FUN_14035f6a0(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  float fVar8;
  ulonglong uVar9;
  
  (**(code **)(*DAT_140c65688 + 0x48))();
  (**(code **)(*DAT_140c65688 + 0x50))();
  (**(code **)(*DAT_140c65670 + 0x1c0))(DAT_140c65670,0x77);
  (**(code **)(*DAT_140c65670 + 0x1d0))(DAT_140c65670,4,5);
  lVar4 = (**(code **)(*DAT_140c65688 + 0xc0))();
  uVar9 = 0;
  (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,0,*(undefined8 *)(lVar4 + 0x28),0,0);
  puVar5 = (undefined8 *)
           (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x30,0,0,uVar9 & 0xffffffff00000000);
  if (puVar5 != (undefined8 *)0x0) {
    uVar7 = *(undefined4 *)(param_1 + 0x3d4);
    uVar1 = *(undefined4 *)(param_1 + 0x3d8);
    uVar2 = *(undefined4 *)(param_1 + 0x3dc);
    *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(param_1 + 0x3d0);
    *(undefined4 *)((longlong)puVar5 + 0x14) = uVar7;
    *(undefined4 *)(puVar5 + 3) = uVar1;
    *(undefined4 *)((longlong)puVar5 + 0x1c) = uVar2;
    puVar6 = (undefined8 *)(**(code **)(*DAT_140c65688 + 0xe8))();
    fVar8 = DAT_140c3b438 * DAT_140b79d28;
    uVar3 = puVar6[1];
    *puVar5 = *puVar6;
    puVar5[1] = uVar3;
    uVar7 = FUN_1408fc950(fVar8 * *(float *)(param_1 + 0x280));
    *(undefined4 *)(puVar5 + 4) = uVar7;
    uVar7 = FUN_1408fc950(fVar8 * *(float *)(param_1 + 0x284));
    *(undefined4 *)((longlong)puVar5 + 0x24) = uVar7;
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x100),0);
  (**(code **)(*DAT_140c65670 + 0x298))(DAT_140c65670,0xffffffff,0,lVar4 + 0x58,lVar4 + 0x60,0);
  (**(code **)(*DAT_140c65670 + 0x2a0))();
  return 0;
}



==== FUN_140361170 @ 140361170 size 638 ====
CALLERS: FUN_140361040
CALLEES: FUN_140361a10 FUN_1402c89c0 __security_check_cookie FUN_1407c20b0 FUN_1407c1fe0 FUN_1407c2170 FUN_140364cc0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_140361170(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 local_a8 [64];
  longlong local_68;
  ulonglong local_18;
  
  local_18 = DAT_140c0f7b0 ^ (ulonglong)auStack_f8;
  FUN_1407c1fe0(local_a8);
  (**(code **)(*DAT_140c65670 + 0x120))();
  if ((*(byte *)(param_1 + 0x80) & 2) == 0) {
    (**(code **)(*DAT_140c65670 + 0x278))(DAT_140c65670,1);
    uVar3 = 6;
    local_b8 = 0;
  }
  else {
    uVar3 = 7;
    local_b8 = DAT_140c440d8;
  }
  local_d8 = 0;
  uStack_b4 = local_b8;
  uStack_b0 = local_b8;
  uStack_ac = local_b8;
  (**(code **)(*DAT_140c65670 + 0x270))(DAT_140c65670,uVar3,&local_b8,DAT_140b79ed0);
  local_b8 = 0xffffffff;
  (**(code **)(**(longlong **)(param_1 + 0x1820) + 0x20))
            (*(longlong **)(param_1 + 0x1820),&local_b8);
  if (((*(byte *)(param_1 + 0x80) & 4) == 0) || (iVar2 = FUN_140361a10(param_1), -1 < iVar2)) {
    local_b8 = 0xffffffff;
    (**(code **)(**(longlong **)(param_1 + 0x1858) + 0x20))
              (*(longlong **)(param_1 + 0x1858),&local_b8);
    uVar4 = 4;
    if (((*(uint *)(param_1 + 0x80) >> 0xc & 1) == 0) ||
       ((DAT_140c657f0 == 0 || (iVar2 = FUN_1402c89c0(DAT_140c657f0,local_a8), -1 < iVar2)))) {
      if ((*(uint *)(param_1 + 0x80) & 0x800) != 0) {
        local_d8 = 1;
        if ((*(uint *)(param_1 + 0x84) & 0x4000) != 0) {
          local_d8 = 3;
        }
        iVar2 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x50))
                          (*(longlong **)(param_1 + 0x28),param_1 + 0x480,param_1 + 0x4c0,
                           param_1 + 0x640);
        if (iVar2 < 0) goto LAB_1403613b4;
        if (((*(uint *)(param_1 + 0x84) & 0x400) != 0) ||
           ((*(uint *)(param_1 + 0x80) & 0x4000000) != 0)) {
          uVar4 = 0x104;
        }
        lVar1 = **(longlong **)(param_1 + 0x28);
        local_c8 = (**(code **)(**(longlong **)(param_1 + 0x120) + 0xf0))();
        local_c0 = 0;
        local_d0 = 0;
        local_d8 = uVar4;
        iVar2 = (**(code **)(lVar1 + 0x78))
                          (*(undefined8 *)(param_1 + 0x28),local_a8,param_1 + 0x540,param_1 + 0xdb0)
        ;
        if (iVar2 < 0) goto LAB_1403613b4;
      }
      if (((local_68 == 0) || (iVar2 = FUN_1407c2170(local_a8,0,0xffffffff), -1 < iVar2)) &&
         (((*(byte *)(param_1 + 0x80) & 2) != 0 || (iVar2 = FUN_140364cc0(param_1), -1 < iVar2)))) {
        iVar2 = 0;
      }
    }
  }
LAB_1403613b4:
  FUN_1407c20b0(local_a8);
  return iVar2;
}



==== FUN_140364cc0 @ 140364cc0 size 464 ====
CALLERS: FUN_140361170
CALLEES:

undefined8 FUN_140364cc0(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  int local_res8 [8];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(int *)(param_1 + 0x10d0) != 0) {
    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x10c8) + 0x28))
                      (*(longlong **)(param_1 + 0x10c8),local_res8,0);
    if (iVar1 != 0) {
      return 0;
    }
    uVar3 = DAT_140b79ed0;
    if (local_res8[0] == 0) {
      uVar3 = 0;
    }
    *(undefined4 *)(param_1 + 0x10c4) = uVar3;
    *(undefined4 *)(param_1 + 0x10d0) = 0;
  }
  (**(code **)(*DAT_140c65670 + 0x120))();
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x58),0);
  (**(code **)(*DAT_140c65670 + 0x140))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x50),1);
  puVar2 = (undefined8 *)(**(code **)(*DAT_140c65670 + 0xe0))(DAT_140c65670,0x10,1);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined4 *)puVar2 = *(undefined4 *)(param_1 + 0x390);
    *(undefined4 *)((longlong)puVar2 + 4) = *(undefined4 *)(param_1 + 0x394);
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(param_1 + 0x398);
    (**(code **)(*DAT_140c65670 + 0xe8))();
    uStack_44 = *(undefined4 *)(param_1 + 0x5d0);
    uStack_34 = *(undefined4 *)(param_1 + 0x5d4);
    uStack_24 = *(undefined4 *)(param_1 + 0x5d8);
    uStack_14 = *(undefined4 *)(param_1 + 0x5dc);
    local_48 = *(undefined4 *)(param_1 + 0x5c0);
    local_38 = *(undefined4 *)(param_1 + 0x5c4);
    local_28 = *(undefined4 *)(param_1 + 0x5c8);
    local_18 = *(undefined4 *)(param_1 + 0x5cc);
    uStack_40 = *(undefined4 *)(param_1 + 0x5e0);
    uStack_30 = *(undefined4 *)(param_1 + 0x5e4);
    uStack_20 = *(undefined4 *)(param_1 + 0x5e8);
    uStack_10 = *(undefined4 *)(param_1 + 0x5ec);
    uStack_3c = *(undefined4 *)(param_1 + 0x5f0);
    uStack_2c = *(undefined4 *)(param_1 + 0x5f4);
    uStack_1c = *(undefined4 *)(param_1 + 0x5f8);
    uStack_c = *(undefined4 *)(param_1 + 0x5fc);
    (**(code **)(*DAT_140c65670 + 0x148))(DAT_140c65670,0x40,&local_48,0,0,0);
    (**(code **)(**(longlong **)(param_1 + 0x10c8) + 0x18))();
    (**(code **)(*DAT_140c65670 + 0x288))(DAT_140c65670,0,0,1,1);
    (**(code **)(**(longlong **)(param_1 + 0x10c8) + 0x20))();
    *(undefined4 *)(param_1 + 0x10d0) = 1;
  }
  return 0;
}



==== FUN_140367440 @ 140367440 size 377 ====
CALLERS: FUN_1403746b0
CALLEES: FUN_140383760

undefined8 FUN_140367440(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x9c4);
  if (iVar8 < *(int *)(param_1 + 0x9cc)) {
    do {
      iVar7 = *(int *)(param_1 + 0x9c0);
      if (iVar7 < *(int *)(param_1 + 0x9c8)) {
        do {
          iVar1 = *(int *)(param_1 + 0x89c);
          iVar4 = iVar8 % *(int *)(param_1 + 0x8a0);
          plVar2 = *(longlong **)
                    (*(longlong *)(param_1 + 0x8e0) +
                    (ulonglong)
                    ((uint)(iVar7 % iVar1 < 0) * iVar1 +
                    ((uint)(iVar4 < 0) * *(int *)(param_1 + 0x8a0) + iVar4) * iVar1 + iVar7 % iVar1)
                    * 8);
          if (plVar2 != (longlong *)0x0) {
            uVar5 = 0;
            plVar3 = plVar2 + 0x40;
            do {
              if (*plVar3 == param_2) break;
              if (plVar3[1] == param_2) {
                uVar5 = uVar5 + 1;
                break;
              }
              if (plVar3[2] == param_2) {
                uVar5 = uVar5 + 2;
                break;
              }
              if (plVar3[3] == param_2) {
                uVar5 = uVar5 + 3;
                break;
              }
              uVar5 = uVar5 + 4;
              plVar3 = plVar3 + 4;
            } while (uVar5 < 0x10);
            if ((uVar5 != 0x10) && ((int)plVar2[0x62] != 0)) {
              FUN_140383760(plVar2);
              *(uint *)((longlong)plVar2 + 0x2c) = *(uint *)((longlong)plVar2 + 0x2c) & 0xfffffff5;
              if (plVar2[0xb9] == 0) {
                plVar3 = plVar2 + 0xba;
                plVar6 = (longlong *)(*plVar2 + 0x908);
                plVar2[0xb9] = (longlong)plVar6;
                *plVar3 = *plVar6;
                *plVar6 = (longlong)plVar2;
                if (*plVar3 != 0) {
                  *(longlong **)(*plVar3 + 0x5c8) = plVar3;
                }
                *(int *)(*plVar2 + 0x87c) = *(int *)(*plVar2 + 0x87c) + 1;
              }
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(param_1 + 0x9c8));
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x9cc));
  }
  return 0;
}



==== FUN_1403682c0 @ 1403682c0 size 1140 ====
CALLERS:
CALLEES: FUN_14038a510 QueryPerformanceCounter FUN_14037d3e0 FUN_14037d060 FUN_140370b30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1403682c0(longlong *param_1,uint *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  ulonglong uVar11;
  longlong lVar12;
  LARGE_INTEGER local_res8;
  LARGE_INTEGER local_res10;
  
  QueryPerformanceCounter(&local_res8);
  uVar8 = *param_2;
  lVar12 = local_res8.QuadPart - _DAT_140c87988;
  if (((int)uVar8 < 0) || (uVar8 != 0)) {
    lVar12 = *(longlong *)(param_2 + 2);
  }
  else {
    uVar8 = 5;
  }
  uVar5 = (**(code **)(*param_1 + 0x90))(param_1);
  if ((int)uVar5 == 0) {
    return uVar5;
  }
  uVar5 = 1;
  if ((int)param_1[0x120] == 0) {
    FUN_140370b30(param_1 + 0x11f,0x5b8,&LAB_140354f50,(longlong)param_1 + 0x884);
    *(undefined4 *)(param_1 + 0x120) = 1;
  }
  uVar11 = 0;
  lVar3 = param_1[0x11f];
  do {
    do {
      if (lVar3 == 0) {
        if ((int)param_1[0x122] == 0) {
          FUN_140370b30(param_1 + 0x121,0x5c8,&LAB_140354f50,(longlong)param_1 + 0x884);
          *(undefined4 *)(param_1 + 0x122) = 1;
        }
        lVar3 = param_1[0x121];
        while (lVar3 != 0) {
          lVar1 = *(longlong *)(lVar3 + 0x5d0);
          iVar4 = FUN_14037d3e0(lVar3);
          if (iVar4 == 0) {
            uVar5 = uVar11;
          }
          if (uVar8 == 0) {
            return 0;
          }
          lVar3 = lVar1;
          if (-1 < (int)uVar8) {
            QueryPerformanceCounter(&local_res10);
            uVar6 = (local_res10.QuadPart - lVar12) - _DAT_140c87988;
            if ((uVar8 * DAT_140c636b0 <= uVar6) ||
               ((int)((uVar8 * DAT_140c636b0 - uVar6) / DAT_140c636b0) == -1)) {
              return 0;
            }
          }
        }
        if ((int)param_1[0x136] == 0) {
          FUN_140370b30(param_1 + 0x135,0x90,&LAB_140354f50,param_1 + 300);
          *(undefined4 *)(param_1 + 0x136) = 1;
        }
        lVar3 = param_1[0x135];
        do {
          do {
            if (lVar3 == 0) {
              if (((param_1[0x142] != 0) &&
                  (plVar10 = *(longlong **)(param_1[0x142] + 0x28), plVar10 != (longlong *)0x0)) &&
                 (iVar4 = (**(code **)(*plVar10 + 0x10))(), iVar4 == 0)) {
                uVar5 = uVar11;
              }
              if (uVar8 == 0) {
                return 0;
              }
              if (-1 < (int)uVar8) {
                QueryPerformanceCounter(&local_res8);
                uVar6 = (local_res8.QuadPart - lVar12) - _DAT_140c87988;
                if (uVar8 * DAT_140c636b0 <= uVar6) {
                  return 0;
                }
                if ((int)((uVar8 * DAT_140c636b0 - uVar6) / DAT_140c636b0) == -1) {
                  return 0;
                }
              }
              plVar10 = param_1 + 0x144;
              uVar6 = uVar11;
              do {
                if (((*plVar10 != 0) &&
                    (plVar2 = *(longlong **)(*plVar10 + 0x28), plVar2 != (longlong *)0x0)) &&
                   (iVar4 = (**(code **)(*plVar2 + 0x10))(), iVar4 == 0)) {
                  uVar5 = uVar11;
                }
                if (-1 < (int)uVar8) {
                  QueryPerformanceCounter(&local_res10);
                  uVar7 = (local_res10.QuadPart - lVar12) - _DAT_140c87988;
                  if (uVar8 * DAT_140c636b0 <= uVar7) {
                    return 0;
                  }
                  if ((int)((uVar8 * DAT_140c636b0 - uVar7) / DAT_140c636b0) == -1) {
                    return 0;
                  }
                }
                uVar9 = (int)uVar6 + 1;
                uVar6 = (ulonglong)uVar9;
                plVar10 = plVar10 + 1;
                if (3 < uVar9) {
                  plVar10 = (longlong *)param_1[0x29b];
                  do {
                    do {
                      if (plVar10 == (longlong *)0x0) {
                        plVar10 = (longlong *)param_1[0x2a2];
                        do {
                          do {
                            if (plVar10 == (longlong *)0x0) {
                              return uVar5;
                            }
                            plVar2 = (longlong *)plVar10[0x40];
                            iVar4 = (**(code **)(*plVar10 + 0x38))();
                            if (iVar4 == 0) {
                              uVar5 = uVar11;
                            }
                            plVar10 = plVar2;
                          } while ((int)uVar8 < 0);
                          QueryPerformanceCounter(&local_res10);
                          uVar6 = (local_res10.QuadPart - lVar12) - _DAT_140c87988;
                        } while ((uVar6 < uVar8 * DAT_140c636b0) &&
                                ((int)((uVar8 * DAT_140c636b0 - uVar6) / DAT_140c636b0) != -1));
                        return 0;
                      }
                      plVar2 = (longlong *)plVar10[0x95];
                      iVar4 = (**(code **)(*plVar10 + 0x28))();
                      if (iVar4 == 0) {
                        uVar5 = uVar11;
                      }
                      plVar10 = plVar2;
                    } while ((int)uVar8 < 0);
                    QueryPerformanceCounter(&local_res10);
                    uVar6 = (local_res10.QuadPart - lVar12) - _DAT_140c87988;
                    if (uVar8 * DAT_140c636b0 <= uVar6) {
                      return 0;
                    }
                  } while ((int)((uVar8 * DAT_140c636b0 - uVar6) / DAT_140c636b0) != -1);
                  return 0;
                }
              } while( true );
            }
            lVar1 = *(longlong *)(lVar3 + 0x98);
            if ((*(longlong *)(lVar3 + 0x90) != 0) && (iVar4 = FUN_14038a510(), iVar4 == 0)) {
              uVar5 = uVar11;
            }
            if (uVar8 == 0) {
              return 0;
            }
            lVar3 = lVar1;
          } while ((int)uVar8 < 0);
          QueryPerformanceCounter(&local_res10);
          uVar6 = (local_res10.QuadPart - lVar12) - _DAT_140c87988;
          if (uVar8 * DAT_140c636b0 <= uVar6) {
            return 0;
          }
        } while ((int)((uVar8 * DAT_140c636b0 - uVar6) / DAT_140c636b0) != -1);
        return 0;
      }
      lVar1 = *(longlong *)(lVar3 + 0x5c0);
      if ((*(longlong *)(lVar3 + 0x5b8) != 0) &&
         (iVar4 = FUN_14037d060(lVar3,param_2,1), iVar4 == 0)) {
        uVar5 = uVar11;
      }
      if (uVar8 == 0) {
        return 0;
      }
      lVar3 = lVar1;
    } while ((int)uVar8 < 0);
    QueryPerformanceCounter(&local_res10);
    uVar6 = (local_res10.QuadPart - lVar12) - _DAT_140c87988;
    if (uVar8 * DAT_140c636b0 <= uVar6) {
      return 0;
    }
  } while ((int)((uVar8 * DAT_140c636b0 - uVar6) / DAT_140c636b0) != -1);
  return 0;
}



==== FUN_140369d90 @ 140369d90 size 410 ====
CALLERS:
CALLEES: FUN_14018b280

undefined8 FUN_140369d90(longlong param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined1 auVar2 [16];
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  if (param_3 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)FUN_14018b280(0x20);
    if (puVar3 == (undefined8 *)0x0) {
      puVar3 = (undefined8 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_140b787c0;
      *(undefined4 *)(puVar3 + 3) = 1;
      puVar3[1] = 0;
      puVar3[2] = 0;
    }
    if ((param_2 & 1) != 0) {
      puVar3[1] = puVar3[1] + *(longlong *)(param_1 + 0x1478);
    }
    if ((param_2 & 2) != 0) {
      puVar3[1] = puVar3[1] + *(longlong *)(param_1 + 0x13a0);
    }
    if ((param_2 & 4) != 0) {
      puVar3[1] = puVar3[1] + *(longlong *)(param_1 + 0x10d8);
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = puVar3[1];
    uVar4 = SUB168(ZEXT816(8) * auVar2,0);
    if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
      uVar4 = 0xffffffffffffffff;
    }
    puVar5 = (undefined8 *)FUN_14018b280(uVar4,0);
    puVar3[2] = puVar5;
    if ((param_2 & 1) != 0) {
      for (puVar1 = *(undefined8 **)(param_1 + 0x1480); puVar1 != (undefined8 *)0x0;
          puVar1 = (undefined8 *)puVar1[0x7f]) {
        *puVar5 = puVar1;
        puVar5 = puVar5 + 1;
        (**(code **)*puVar1)(puVar1);
      }
    }
    if ((param_2 & 2) != 0) {
      for (puVar1 = *(undefined8 **)(param_1 + 0x13a8); puVar1 != (undefined8 *)0x0;
          puVar1 = (undefined8 *)puVar1[0x93]) {
        if (puVar1 == (undefined8 *)puVar1[4]) {
          *puVar5 = puVar1;
          puVar5 = puVar5 + 1;
          (**(code **)*puVar1)(puVar1);
        }
        else {
          puVar3[1] = puVar3[1] + -1;
        }
      }
    }
    if ((param_2 & 4) != 0) {
      for (puVar1 = *(undefined8 **)(param_1 + 0x10e0); puVar1 != (undefined8 *)0x0;
          puVar1 = (undefined8 *)puVar1[0x1b]) {
        *puVar5 = puVar1;
        puVar5 = puVar5 + 1;
        (**(code **)*puVar1)(puVar1);
      }
    }
    *param_3 = puVar3;
    return 0;
  }
  return 0x80070057;
}



==== FUN_14036b7c0 @ 14036b7c0 size 269 ====
CALLERS:
CALLEES: FUN_14018b280

undefined8 FUN_14036b7c0(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  puVar6 = (undefined8 *)0x0;
  puVar7 = puVar6;
  for (lVar1 = *(longlong *)(param_1 + 0x920); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x590)) {
    puVar7 = (undefined8 *)((longlong)puVar7 + 1);
  }
  puVar3 = (undefined8 *)FUN_14018b280(0x20);
  puVar8 = puVar6;
  if (puVar3 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar3 + 1) = 1;
    puVar3[2] = 0;
    *puVar3 = &PTR_FUN_140b65ff8;
    puVar3[3] = 0;
    puVar8 = puVar3;
  }
  puVar8[2] = puVar7;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = puVar7;
  uVar4 = SUB168(ZEXT816(8) * auVar2,0);
  if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
    uVar4 = 0xffffffffffffffff;
  }
  uVar4 = FUN_14018b280(uVar4,0);
  puVar8[3] = uVar4;
  for (lVar1 = *(longlong *)(param_1 + 0x920); lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x590)) {
    puVar5 = (undefined4 *)(puVar8[3] + (longlong)puVar6);
    puVar6 = puVar6 + 1;
    *puVar5 = *(undefined4 *)(lVar1 + 8);
    puVar5[1] = *(undefined4 *)(lVar1 + 0xc);
  }
  *param_2 = puVar8;
  return 0;
}



==== FUN_14036b8d0 @ 14036b8d0 size 1483 ====
CALLERS:
CALLEES: FUN_14018b280 FUN_14037cc30 FUN_140378ff0 FUN_140388e70 FUN_1403577d0 FUN_140393740 FUN_140389a30

undefined8
FUN_14036b8d0(longlong param_1,undefined1 (*param_2) [16],uint param_3,undefined8 *param_4,
             longlong *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 (*pauVar5) [16];
  longlong lVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined4 local_68 [4];
  undefined1 local_58 [8];
  float fStack_50;
  undefined1 local_48 [8];
  float fStack_40;
  
  if (param_4 == (undefined8 *)0x0) {
    return 0x80070057;
  }
  puVar4 = (undefined8 *)FUN_14018b280(0x38);
  puVar9 = (undefined8 *)0x0;
  puVar8 = puVar9;
  if (puVar4 != (undefined8 *)0x0) {
    puVar4[1] = 1;
    *(undefined4 *)(puVar4 + 2) = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    *puVar4 = &PTR_LAB_140b5fe88;
    puVar4[6] = 0;
    puVar8 = puVar4;
  }
  if (((param_3 & 0xf800) != 0) && (lVar6 = *(longlong *)(param_1 + 0x1488), lVar6 != 0)) {
    plVar7 = (longlong *)(param_1 + 0x14b0);
    do {
      if (*(longlong *)(lVar6 + 0x450) == 0) {
        *(longlong **)(lVar6 + 0x450) = plVar7;
        plVar1 = (longlong *)(lVar6 + 0x458);
        *plVar1 = *plVar7;
        *plVar7 = lVar6;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x450) = plVar1;
        }
      }
      lVar6 = *(longlong *)(lVar6 + 0x408);
    } while (lVar6 != 0);
  }
  FUN_1403577d0(param_1);
  lVar6 = *(longlong *)(param_1 + 0x918);
  if (lVar6 != 0) {
    do {
      local_68[0] = 0xffffffff;
      if (*(longlong *)(lVar6 + 0x5a8) != 0) {
        FUN_14037cc30(lVar6);
      }
      if ((param_3 & 3) != 0) {
        FUN_140388e70(lVar6,param_2,param_3,puVar8);
      }
      if ((param_3 & 0xf800) != 0) {
        for (lVar2 = *(longlong *)(*(longlong *)(lVar6 + 0x18) + 0x40); lVar2 != 0;
            lVar2 = *(longlong *)(lVar2 + 0x18)) {
          lVar3 = *(longlong *)(lVar2 + 8);
          if (*(longlong *)(lVar3 + 0x450) == 0) {
            plVar7 = (longlong *)(param_1 + 0x14b0);
            plVar1 = (longlong *)(lVar3 + 0x458);
            *(longlong **)(lVar3 + 0x450) = plVar7;
            *plVar1 = *plVar7;
            *plVar7 = lVar3;
            if (*plVar1 != 0) {
              *(longlong **)(*plVar1 + 0x450) = plVar1;
            }
          }
        }
      }
      if ((param_3 & 0x7f8) != 0) {
        for (lVar2 = *(longlong *)(*(longlong *)(lVar6 + 0x18) + 0x30); lVar2 != 0;
            lVar2 = *(longlong *)(lVar2 + 0x18)) {
          lVar3 = *(longlong *)(lVar2 + 8);
          if (*(longlong *)(lVar3 + 0x4d0) == 0) {
            plVar7 = (longlong *)(param_1 + 0x13c0);
            plVar1 = (longlong *)(lVar3 + 0x4d8);
            *(longlong **)(lVar3 + 0x4d0) = plVar7;
            *plVar1 = *plVar7;
            *plVar7 = lVar3;
            if (*plVar1 != 0) {
              *(longlong **)(*plVar1 + 0x4d0) = plVar1;
            }
          }
        }
      }
      if ((param_3 & 4) != 0) {
        puVar4 = puVar9;
        if (*(longlong *)(lVar6 + 0x408) != 0) {
          do {
            lVar2 = *(longlong *)(*(longlong *)(lVar6 + 0x410) + (longlong)puVar4 * 8);
            if ((lVar2 != 0) &&
               (plVar7 = (longlong *)(param_1 + 0x10e8), *(longlong *)(lVar2 + 0xe0) == 0)) {
              *(longlong **)(lVar2 + 0xe0) = plVar7;
              plVar1 = (longlong *)(lVar2 + 0xe8);
              *plVar1 = *plVar7;
              *plVar7 = lVar2;
              if (*plVar1 != 0) {
                *(longlong **)(*plVar1 + 0xe0) = plVar1;
              }
            }
            puVar4 = (undefined8 *)((longlong)puVar4 + 1);
          } while (puVar4 < *(undefined8 **)(lVar6 + 0x408));
        }
        FUN_140389a30(lVar6,param_2,param_3,puVar8);
      }
      lVar6 = *(longlong *)(lVar6 + 0x580);
    } while (lVar6 != 0);
  }
  plVar7 = *(longlong **)(param_1 + 0x14b0);
  while (plVar7 != (longlong *)0x0) {
    if (plVar7 != param_5) {
      pauVar5 = (undefined1 (*) [16])(**(code **)(*plVar7 + 0x50))();
      _local_48 = minps(param_2[1],pauVar5[1]);
      _local_58 = maxps(*param_2,*pauVar5);
      if (local_58._0_4_ <= local_48._0_4_) {
        if ((float)local_58._4_4_ <= (float)local_48._4_4_) {
          if ((fStack_50 <= fStack_40) &&
             (plVar7 = *(longlong **)(param_1 + 0x14b0), plVar7[4] != 0)) {
            if ((param_3 >> 0xb & 1) == 0) {
              puVar4 = puVar9;
              if (((param_3 >> 0xf & 1) != 0) &&
                 (puVar4 = (undefined8 *)0x0, *(int *)((longlong)plVar7 + 0xe4) != 0)) {
                puVar4 = (undefined8 *)0x1;
              }
            }
            else {
              puVar4 = (undefined8 *)0x1;
            }
            if ((((param_3 >> 0xc & 1) != 0) && ((int)plVar7[0x1c] != 0)) ||
               ((param_3 >> 0xd & 1) != 0)) {
              puVar4 = (undefined8 *)(ulonglong)((uint)puVar4 | 2);
            }
            if (((param_3 >> 0xe & 1) != 0) && (*(int *)((longlong)plVar7 + 0xe4) != 0)) {
              puVar4 = (undefined8 *)(ulonglong)((uint)puVar4 | 4);
            }
            if ((int)puVar4 != 0) {
              local_68[0] = 0xffffffff;
              (**(code **)(*plVar7 + 0x20))(plVar7,local_68);
              (**(code **)(*(longlong *)plVar7[4] + 0x528))
                        ((longlong *)plVar7[4],param_2,puVar4,puVar8);
            }
          }
        }
      }
    }
    lVar6 = *(longlong *)(param_1 + 0x14b0);
    if (*(undefined8 **)(lVar6 + 0x450) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar6 + 0x450) = *(undefined8 *)(lVar6 + 0x458);
    }
    if (*(longlong *)(lVar6 + 0x458) != 0) {
      *(undefined8 *)(*(longlong *)(lVar6 + 0x458) + 0x450) = *(undefined8 *)(lVar6 + 0x450);
    }
    *(undefined8 *)(lVar6 + 0x450) = 0;
    *(undefined8 *)(lVar6 + 0x458) = 0;
    plVar7 = *(longlong **)(param_1 + 0x14b0);
  }
  plVar7 = *(longlong **)(param_1 + 0x13c0);
  if (plVar7 != (longlong *)0x0) {
    do {
      if (plVar7 != param_5) {
        pauVar5 = (undefined1 (*) [16])
                  (**(code **)(*plVar7 + 0x50))(plVar7,2 - (uint)((param_3 & 0x38) != 0));
        _local_48 = minps(param_2[1],pauVar5[1]);
        _local_58 = maxps(*param_2,*pauVar5);
        if (local_58._0_4_ <= local_48._0_4_) {
          if ((float)local_58._4_4_ <= (float)local_48._4_4_) {
            if (fStack_50 <= fStack_40) {
              FUN_140378ff0(*(undefined8 *)(param_1 + 0x13c0),param_2,param_3,puVar8);
            }
          }
        }
      }
      lVar6 = *(longlong *)(param_1 + 0x13c0);
      if (*(undefined8 **)(lVar6 + 0x4d0) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar6 + 0x4d0) = *(undefined8 *)(lVar6 + 0x4d8);
      }
      if (*(longlong *)(lVar6 + 0x4d8) != 0) {
        *(undefined8 *)(*(longlong *)(lVar6 + 0x4d8) + 0x4d0) = *(undefined8 *)(lVar6 + 0x4d0);
      }
      *(undefined8 *)(lVar6 + 0x4d0) = 0;
      *(undefined8 *)(lVar6 + 0x4d8) = 0;
      plVar7 = *(longlong **)(param_1 + 0x13c0);
    } while (plVar7 != (longlong *)0x0);
  }
  plVar7 = *(longlong **)(param_1 + 0x10e8);
  while (plVar7 != (longlong *)0x0) {
    if (plVar7 != param_5) {
      pauVar5 = (undefined1 (*) [16])(**(code **)(*plVar7 + 0x50))(plVar7,0);
      _local_48 = minps(param_2[1],pauVar5[1]);
      _local_58 = maxps(*param_2,*pauVar5);
      if (local_58._0_4_ <= local_48._0_4_) {
        if ((float)local_58._4_4_ <= (float)local_48._4_4_) {
          if (fStack_50 <= fStack_40) {
            FUN_140393740(*(undefined8 *)(param_1 + 0x10e8),param_2,param_3,puVar8);
          }
        }
      }
    }
    lVar6 = *(longlong *)(param_1 + 0x10e8);
    if (*(undefined8 **)(lVar6 + 0xe0) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar6 + 0xe0) = *(undefined8 *)(lVar6 + 0xe8);
    }
    if (*(longlong *)(lVar6 + 0xe8) != 0) {
      *(undefined8 *)(*(longlong *)(lVar6 + 0xe8) + 0xe0) = *(undefined8 *)(lVar6 + 0xe0);
    }
    *(undefined8 *)(lVar6 + 0xe0) = 0;
    *(undefined8 *)(lVar6 + 0xe8) = 0;
    plVar7 = *(longlong **)(param_1 + 0x10e8);
  }
  *param_4 = puVar8;
  return 0;
}



==== FUN_140371f80 @ 140371f80 size 339 ====
CALLERS: FUN_140350990
CALLEES: FUN_140052360

undefined8 * FUN_140371f80(undefined8 *param_1,undefined8 *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  longlong *plVar10;
  
  *param_1 = &PTR_FUN_140b55048;
  *(undefined4 *)(param_1 + 1) = 1;
  *param_1 = &PTR_FUN_140b65a20;
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if ((undefined8 *)param_1[2] != param_2) {
    if (param_2 != (undefined8 *)0x0) {
      (**(code **)*param_2)(param_2);
    }
    if ((longlong *)param_1[2] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[2] + 8))();
    }
    param_1[2] = param_2;
  }
  lVar9 = param_2[10];
  uVar7 = *(uint *)(param_2[9] + -4 + lVar9 * 4);
  FUN_140052360(param_2 + 9);
  if (lVar9 == 1) {
    if ((undefined8 *)param_2[0xb] != (undefined8 *)0x0) {
      *(undefined8 *)param_2[0xb] = param_2[0xc];
    }
    if (param_2[0xc] != 0) {
      *(undefined8 *)(param_2[0xc] + 0x58) = param_2[0xb];
    }
    param_2[0xb] = 0;
    param_2[0xc] = 0;
  }
  *(uint *)(param_1 + 3) = uVar7;
  uVar2 = *(undefined4 *)(param_2 + 7);
  uVar8 = *(uint *)((longlong)param_2 + 0x34);
  fVar3 = *(float *)((longlong)param_2 + 0x3c);
  fVar4 = *(float *)((longlong)param_2 + 0x3c);
  fVar5 = *(float *)(param_2 + 8);
  fVar6 = *(float *)(param_2 + 8);
  *(undefined4 *)(param_1 + 4) = uVar2;
  *(undefined4 *)((longlong)param_1 + 0x24) = uVar2;
  *(float *)(param_1 + 5) = (float)(int)(uVar7 % uVar8) * fVar4 + fVar6;
  *(float *)((longlong)param_1 + 0x2c) = (float)(int)(uVar7 / uVar8) * fVar3 + fVar5;
  plVar10 = (longlong *)(*(longlong *)(param_1[2] + 0x10) + 0x358);
  if (param_1[6] == 0) {
    param_1[6] = plVar10;
    plVar1 = param_1 + 7;
    *plVar1 = *plVar10;
    *plVar10 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x30) = plVar1;
    }
  }
  return param_1;
}



==== FUN_1403763a0 @ 1403763a0 size 1003 ====
CALLERS: FUN_1403698f0
CALLEES: FUN_14018b280 FUN_1403793c0 FUN_140001ba0 FUN_140395ea0 FUN_140376f30 FUN_1401b6bf0 FUN_14021a740 FUN_140395080 FUN_140394fa0 FUN_140394620 FUN_1400290d0

ulonglong FUN_1403763a0(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  longlong *plVar6;
  undefined4 *puVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  longlong *plVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong *puVar13;
  ulonglong uVar14;
  undefined4 extraout_XMM0_Da;
  ulonglong local_res8;
  undefined4 uVar15;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined4 local_50;
  longlong *local_48;
  code *local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  param_1[3] = (longlong)param_2;
  (**(code **)*param_2)(param_2);
  plVar6 = (longlong *)(**(code **)(*(longlong *)param_1[3] + 0x20))();
  puVar13 = (ulonglong *)0x0;
  uVar15 = 0;
  if (plVar6 != (longlong *)0x0) {
    puVar7 = (undefined4 *)(**(code **)(*plVar6 + 0x20))(plVar6);
    uVar15 = *puVar7;
  }
  uVar4 = (**(code **)(*(longlong *)param_1[3] + 0xd8))();
  local_res8 = (ulonglong)uVar4;
  param_1[0xb] = local_res8;
  param_1[0xc] = CONCAT44(uStack_5c,uVar15);
  iVar5 = (**(code **)(*(longlong *)param_1[3] + 0x28))();
  puVar9 = puVar13;
  if (iVar5 == 0) {
    puVar8 = (ulonglong *)FUN_14018b280(0x40);
    if (puVar8 != (ulonglong *)0x0) {
      puVar8[2] = 0;
      *(undefined4 *)((longlong)puVar8 + 0x1c) = 0;
      *puVar8 = (ulonglong)&PTR_FUN_140b660c0;
      puVar8[4] = 0;
      puVar8[5] = 0;
      puVar8[6] = 0;
      puVar8[7] = 0;
      puVar9 = puVar8;
    }
    uVar4 = FUN_140394620(puVar9);
LAB_140376548:
    uVar12 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      param_1[6] = (longlong)puVar9;
      goto LAB_140376566;
    }
    if (puVar9 == (ulonglong *)0x0) goto LAB_140376566;
  }
  else {
    if (iVar5 == 1) {
LAB_1403764b0:
      puVar9 = (ulonglong *)FUN_14018b280(0x50);
      if (puVar9 == (ulonglong *)0x0) {
        uVar4 = FUN_140395080(0);
        puVar9 = puVar13;
      }
      else {
        puVar9[2] = 0;
        puVar9[3] = 0;
        puVar9[4] = 0;
        *puVar9 = (ulonglong)&PTR_FUN_140b66190;
        puVar9[5] = 0;
        puVar9[6] = 0;
        *(undefined8 *)((longlong)puVar9 + 0x3c) = 0;
        *(undefined4 *)(puVar9 + 7) = 0;
        puVar9[9] = 0;
        uVar4 = FUN_140395080(puVar9);
      }
      goto LAB_140376548;
    }
    if (iVar5 != 2) {
      if (iVar5 != 3) {
        return 0x80070057;
      }
      goto LAB_1403764b0;
    }
    puVar8 = (ulonglong *)FUN_14018b280(0x30);
    if (puVar8 != (ulonglong *)0x0) {
      puVar8[3] = 0;
      puVar8[4] = 0;
      *puVar8 = (ulonglong)&PTR_FUN_140b66260;
      puVar8[5] = 0;
      puVar9 = puVar8;
    }
    puVar9[2] = (ulonglong)param_1;
    if ((*(uint *)(param_1[2] + 0xec) & 0x100) == 0) {
LAB_1403764a4:
      uVar12 = 0;
      param_1[6] = (longlong)puVar9;
      goto LAB_140376566;
    }
    plVar6 = *(longlong **)(param_1[2] + 0x28);
    uVar4 = (**(code **)(*plVar6 + 0x28))(plVar6,L"Art\\Dev\\Sound_Emitter_Sphere.m3",puVar9 + 5,2);
    uVar12 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) goto LAB_1403764a4;
  }
  (**(code **)*puVar9)(puVar9);
LAB_140376566:
  if ((longlong *)param_1[6] != (longlong *)0x0) {
    plVar6 = (longlong *)(**(code **)(*(longlong *)param_1[6] + 0x38))();
    if (plVar6 != (longlong *)0x0) {
      plVar10 = (longlong *)(**(code **)(*(longlong *)param_1[3] + 0x20))();
      plVar1 = (longlong *)param_1[3];
      local_res8 = local_res8 & 0xffffffff00000000;
      if (plVar10 == (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x188))(plVar1,5,0,&local_res8);
        if (((int)local_res8 == 0) || (lVar11 = FUN_14021a740(), lVar11 == 0)) {
          local_res8 = CONCAT44(local_res8._4_4_,*(undefined4 *)((longlong)param_1 + 0x16c));
        }
        (**(code **)(*plVar6 + 0x288))(plVar6,&LAB_140379300,param_1);
        uVar15 = 0x20;
        iVar5 = 0;
      }
      else {
        (**(code **)(*plVar1 + 0x188))(plVar1,5,1);
        if (((int)local_res8 == 0) || (lVar11 = FUN_14021a740(), lVar11 == 0)) {
          local_res8 = CONCAT44(local_res8._4_4_,0x452);
        }
        (**(code **)(*plVar6 + 0x288))(plVar6,&LAB_140379300,param_1);
        lVar11 = (**(code **)(*plVar10 + 0x20))(plVar10);
        uVar15 = 0;
        iVar5 = *(int *)(param_1[2] + 0x370) - *(int *)(lVar11 + 0x1c);
      }
      FUN_1403793c0(param_1,plVar6,local_res8 & 0xffffffff,iVar5,uVar15);
      uVar4 = (**(code **)(*(longlong *)param_1[3] + 200))();
      if ((uVar4 >> 0xb & 1) == 0) {
        (**(code **)(*plVar6 + 0x2e8))(plVar6);
      }
      else {
        (**(code **)(*plVar6 + 0x2e0))();
      }
      (**(code **)(*param_1 + 0x130))(param_1);
    }
    uVar12 = FUN_140376f30(param_1);
    if (-1 < (int)uVar12) {
      local_res8 = param_1[3];
      lVar11 = param_1[2];
      plVar6 = (longlong *)(lVar11 + 0x13e8);
      if (*plVar6 == *(longlong *)(lVar11 + 0x13f0)) {
        FUN_1400290d0(plVar6);
      }
      uVar12 = (**(code **)(lVar11 + 0x1400))(&local_res8);
      lVar2 = *(longlong *)(lVar11 + 0x13f8);
      uVar14 = uVar12 % *(ulonglong *)(lVar11 + 0x13f0);
      puVar9 = (ulonglong *)FUN_14018b280(0x20);
      if (puVar9 != (ulonglong *)0x0) {
        uVar3 = *(ulonglong *)(lVar2 + uVar14 * 8);
        *puVar9 = uVar12;
        puVar9[1] = uVar3;
        puVar9[3] = (ulonglong)param_1;
        puVar9[2] = local_res8;
        puVar13 = puVar9;
      }
      *(ulonglong **)(lVar2 + uVar14 * 8) = puVar13;
      *plVar6 = *plVar6 + 1;
      *(undefined4 *)(param_1 + 9) = 1;
      if (*(int *)((longlong)param_1 + 0x54) == 0) {
        local_58 = (**(code **)(*param_2 + 0x30))(param_2);
        local_50 = 0;
        local_38 = 0;
        local_30 = 1;
        local_40 = FUN_140377140;
        local_48 = param_1;
        FUN_1401b6bf0(extraout_XMM0_Da,&local_58,param_1 + 7);
      }
      uVar12 = 0;
    }
  }
  return uVar12;
}



==== FUN_140376c10 @ 140376c10 size 335 ====
CALLERS: FUN_140368a40
CALLEES: FUN_14018b280 FUN_1403772e0

undefined8
FUN_140376c10(longlong param_1,undefined8 param_2,undefined8 *param_3,longlong *param_4,
             longlong param_5)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  longlong *plVar5;
  undefined4 uStack_c;
  
  if (*param_4 != 0) {
    if (param_5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(param_5 + 0x60);
    }
    *(longlong *)(param_1 + 0x58) = *param_4;
    *(ulonglong *)(param_1 + 0x60) = CONCAT44(uStack_c,uVar4);
  }
  puVar2 = (undefined8 *)FUN_14018b280(0x40);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar2[2] = 0;
    *(undefined4 *)((longlong)puVar2 + 0x1c) = 0;
    *puVar2 = &PTR_FUN_140b660c0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  if (param_3 == (undefined8 *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    puVar2[1] = param_1;
    puVar2[2] = param_3;
    (**(code **)*param_3)(param_3);
    *(uint *)(puVar2 + 3) = *(uint *)(puVar2 + 3) & 0xfffffffe;
    *(undefined8 **)(param_1 + 0x30) = puVar2;
    FUN_1403772e0(param_1,param_2);
    plVar5 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x13d8);
    if (*(longlong *)(param_1 + 0x510) == 0) {
      *(longlong **)(param_1 + 0x510) = plVar5;
      plVar1 = (longlong *)(param_1 + 0x518);
      *plVar1 = *plVar5;
      *plVar5 = param_1;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 0x510) = plVar1;
      }
    }
    if (param_5 != 0) {
      *(longlong *)(param_1 + 0x28) = param_5;
      plVar5 = (longlong *)(param_5 + 0x40);
      if (*(longlong *)(param_1 + 0x4b0) == 0) {
        *(longlong **)(param_1 + 0x4b0) = plVar5;
        plVar1 = (longlong *)(param_1 + 0x4b8);
        *plVar1 = *plVar5;
        *plVar5 = param_1;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x4b0) = plVar1;
        }
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



==== FUN_140376d60 @ 140376d60 size 452 ====
CALLERS: FUN_140368b00
CALLEES: FUN_14018b280 FUN_14013d820 FUN_1403793c0 FUN_1403772e0

undefined8
FUN_140376d60(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4,
             longlong param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 uStack_c;
  
  if (*param_4 != 0) {
    if (param_5 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(param_5 + 0x60);
    }
    param_1[0xb] = *param_4;
    param_1[0xc] = CONCAT44(uStack_c,uVar3);
  }
  plVar2 = (longlong *)FUN_14018b280(0x40);
  if (plVar2 == (longlong *)0x0) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2[2] = 0;
    *(undefined4 *)((longlong)plVar2 + 0x1c) = 0;
    *plVar2 = (longlong)&PTR_FUN_140b660c0;
    plVar2[4] = 0;
    plVar2[5] = 0;
    plVar2[6] = 0;
    plVar2[7] = 0;
  }
  plVar2[1] = (longlong)param_1;
  uVar4 = 2;
  if ((*(uint *)(param_1[2] + 0x80) & 0x8000000) == 0) {
    uVar4 = 0x12;
  }
  uVar4 = (**(code **)(**(longlong **)(param_1[2] + 0x28) + 0x28))
                    (*(longlong **)(param_1[2] + 0x28),param_3,plVar2 + 2,uVar4);
  if (-1 < (int)uVar4) {
    *(uint *)(plVar2 + 3) = *(uint *)(plVar2 + 3) & 0xfffffffe;
    param_1[6] = (longlong)plVar2;
    plVar2 = (longlong *)(**(code **)(*plVar2 + 0x38))(plVar2);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x288))(plVar2,&LAB_140379300,param_1);
      FUN_1403793c0(param_1,plVar2,*(undefined4 *)((longlong)param_1 + 0x16c),0,0x20);
      (**(code **)(*param_1 + 0x130))(param_1,*(undefined4 *)((longlong)param_1 + 0x16c));
    }
    FUN_1403772e0(param_1,param_2);
    plVar2 = (longlong *)(param_1[2] + 0x13d8);
    if (param_1[0xa2] == 0) {
      param_1[0xa2] = (longlong)plVar2;
      plVar1 = param_1 + 0xa3;
      *plVar1 = *plVar2;
      *plVar2 = (longlong)param_1;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 0x510) = plVar1;
      }
    }
    if (param_5 != 0) {
      param_1[5] = param_5;
      plVar2 = (longlong *)(param_5 + 0x40);
      if (param_1[0x96] == 0) {
        param_1[0x96] = (longlong)plVar2;
        plVar1 = param_1 + 0x97;
        *plVar1 = *plVar2;
        *plVar2 = (longlong)param_1;
        if (*plVar1 != 0) {
          *(longlong **)(*plVar1 + 0x4b0) = plVar1;
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



==== FUN_140377f70 @ 140377f70 size 102 ====
CALLERS: FUN_140379b70 FUN_1403780a0 FUN_140379b20
CALLEES: FUN_1403786a0 FUN_140378110

void FUN_140377f70(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x4a0) != 0) {
    FUN_140378110();
    FUN_1403786a0(param_1);
    if (*(undefined8 **)(param_1 + 0x4a0) != (undefined8 *)0x0) {
      **(undefined8 **)(param_1 + 0x4a0) = *(undefined8 *)(param_1 + 0x4a8);
    }
    if (*(longlong *)(param_1 + 0x4a8) != 0) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x4a8) + 0x4a0) = *(undefined8 *)(param_1 + 0x4a0);
    }
    *(undefined8 *)(param_1 + 0x4a0) = 0;
    *(undefined8 *)(param_1 + 0x4a8) = 0;
  }
  return;
}



==== FUN_1403786a0 @ 1403786a0 size 497 ====
CALLERS: FUN_14037cc30 FUN_140377fe0 FUN_140377f70 FUN_140356160
CALLEES: FUN_14018b280 FUN_14038fb20 FUN_14038fbf0 FUN_14018b900 FUN_1403589f0 FUN_140358b00 FUN_140359110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1403786a0(longlong param_1)

{
  float *pfVar1;
  longlong *plVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  float *pfVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar11;
  float fVar12;
  float fVar13;
  float local_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  
  if (*(int *)(param_1 + 0x458) == 0) {
    lVar7 = *(longlong *)(param_1 + 0x460);
    while (lVar7 != 0) {
      lVar7 = *(longlong *)(param_1 + 0x460);
      if (lVar7 != 0) {
        FUN_14038fbf0(lVar7);
        FUN_14018b900(lVar7,0);
      }
      lVar7 = *(longlong *)(param_1 + 0x460);
    }
    if (((*(longlong *)(param_1 + 0x18) != 0) &&
        (*(int *)(*(longlong *)(param_1 + 0x20) + 0x41c) == 0)) ||
       (iVar4 = (**(code **)(**(longlong **)(param_1 + 0x30) + 8))(), iVar4 == 1)) {
      *(undefined4 *)(param_1 + 0x418) = 1;
      return;
    }
    pfVar8 = (float *)(param_1 + 0x1f0);
    pfVar1 = (float *)(param_1 + 0x1b0);
    if (((*(float *)(param_1 + 0x200) < *pfVar8 || *(float *)(param_1 + 0x200) == *pfVar8) ||
        (*(float *)(param_1 + 0x204) < *(float *)(param_1 + 500) ||
         *(float *)(param_1 + 0x204) == *(float *)(param_1 + 500))) ||
       (*(float *)(param_1 + 0x208) < *(float *)(param_1 + 0x1f8) ||
        *(float *)(param_1 + 0x208) == *(float *)(param_1 + 0x1f8))) {
      if (((*(float *)(param_1 + 0x1c0) < *pfVar1 || *(float *)(param_1 + 0x1c0) == *pfVar1) ||
          (*(float *)(param_1 + 0x1c4) < *(float *)(param_1 + 0x1b4) ||
           *(float *)(param_1 + 0x1c4) == *(float *)(param_1 + 0x1b4))) ||
         (*(float *)(param_1 + 0x1c8) < *(float *)(param_1 + 0x1b8) ||
          *(float *)(param_1 + 0x1c8) == *(float *)(param_1 + 0x1b8))) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      pfVar8 = (float *)(param_1 + 0x170);
      if (!bVar3) {
        pfVar8 = pfVar1;
      }
    }
    if (*(longlong *)(param_1 + 0x18) == 0) {
      uVar6 = FUN_140358b00(*(undefined8 *)(param_1 + 0x10),pfVar8,param_1 + 0xb0);
    }
    else {
      fVar11 = (pfVar8[4] + *pfVar8) * _DAT_140b7ac50;
      fVar12 = (pfVar8[5] + pfVar8[1]) * _UNK_140b7ac54;
      fVar13 = (pfVar8[6] + pfVar8[2]) * _UNK_140b7ac58;
      local_38 = fVar12 * *(float *)(param_1 + 0xc0) + fVar11 * *(float *)(param_1 + 0xb0) +
                 fVar13 * *(float *)(param_1 + 0xd0) + *(float *)(param_1 + 0xe0);
      fStack_34 = fVar12 * *(float *)(param_1 + 0xc4) + fVar11 * *(float *)(param_1 + 0xb4) +
                  fVar13 * *(float *)(param_1 + 0xd4) + *(float *)(param_1 + 0xe4);
      fStack_30 = fVar12 * *(float *)(param_1 + 200) + fVar11 * *(float *)(param_1 + 0xb8) +
                  fVar13 * *(float *)(param_1 + 0xd8) + *(float *)(param_1 + 0xe8);
      fStack_2c = fVar12 * *(float *)(param_1 + 0xcc) + fVar11 * *(float *)(param_1 + 0xbc) +
                  fVar13 * *(float *)(param_1 + 0xdc) + *(float *)(param_1 + 0xec);
      uVar6 = FUN_1403589f0(*(undefined8 *)(param_1 + 0x10),&local_38);
    }
    auVar10 = maxps(*(undefined1 (*) [16])(param_1 + 0x280),*(undefined1 (*) [16])(param_1 + 0x2c0))
    ;
    auVar9 = minps(*(undefined1 (*) [16])(param_1 + 0x270),*(undefined1 (*) [16])(param_1 + 0x2b0));
    local_18 = maxps(auVar10,*(undefined1 (*) [16])(param_1 + 0x300));
    local_28 = minps(auVar9,*(undefined1 (*) [16])(param_1 + 0x2f0));
    uVar5 = FUN_140359110(*(undefined8 *)(param_1 + 0x10),uVar6,local_28);
    *(undefined4 *)(param_1 + 0x418) = uVar5;
    for (plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x10) + 0x1550); plVar2 != (longlong *)0x0;
        plVar2 = (longlong *)plVar2[0x27]) {
      iVar4 = (**(code **)(*plVar2 + 0x18))(plVar2);
      if ((iVar4 == 0) && (lVar7 = FUN_14018b280(0x30,0), lVar7 != 0)) {
        FUN_14038fb20(lVar7,plVar2,param_1);
      }
    }
  }
  return;
}



==== FUN_140378ff0 @ 140378ff0 size 172 ====
CALLERS: FUN_14036b8d0 FUN_140379840
CALLEES: FUN_140379200

void FUN_140378ff0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  plVar2 = (longlong *)(**(code **)(**(longlong **)(param_1 + 0x30) + 0x38))();
  plVar3 = (longlong *)(**(code **)(**(longlong **)(param_1 + 0x30) + 0x40))();
  if (plVar2 == (longlong *)0x0) {
    if (plVar3 != (longlong *)0x0) {
      iVar1 = FUN_140379200(param_1,param_3);
      if (iVar1 != 0) {
        (**(code **)(*plVar3 + 0x1a8))(plVar3,param_2,iVar1,param_4);
      }
    }
  }
  else {
    iVar1 = FUN_140379200(param_1,param_3);
    if (iVar1 != 0) {
      (**(code **)(*plVar2 + 0x528))(plVar2,param_2,iVar1,param_4);
    }
  }
  return;
}



==== FUN_1403791a0 @ 1403791a0 size 95 ====
CALLERS: FUN_1403675c0 FUN_140369aa0
CALLEES: FUN_140379330

void FUN_1403791a0(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = (longlong *)(**(code **)(**(longlong **)(param_1 + 0x30) + 0x38))();
  if (plVar1 != (longlong *)0x0) {
    lVar2 = (**(code **)(*plVar1 + 0x290))(plVar1,0);
    if (lVar2 == 0) {
      (**(code **)(*plVar1 + 0x288))(plVar1,&LAB_140379300,param_1);
      FUN_140379330(param_1,0);
    }
  }
  return;
}



==== FUN_1403794d0 @ 1403794d0 size 288 ====
CALLERS:
CALLEES: FUN_140377580 FUN_140377640 FUN_140367870 FUN_1403788a0

undefined8 FUN_1403794d0(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)((longlong)param_1 + 0x4c) != 0) {
    return 1;
  }
  uVar3 = (**(code **)(*(longlong *)param_1[6] + 0x28))();
  if ((int)uVar3 != 0) {
    plVar1 = (longlong *)param_1[8];
    while( true ) {
      if (plVar1 == (longlong *)0x0) {
        FUN_140377580(param_1);
        FUN_140377640(param_1);
        *(undefined4 *)((longlong)param_1 + 0x4c) = 1;
        FUN_1403788a0(param_1);
        if (param_1[0xa2] != 0) {
          iVar2 = (**(code **)(*param_1 + 0x120))(param_1);
          if (iVar2 != 0) {
            FUN_140367870(param_1[2],param_1 + 0x5e);
          }
          if ((longlong *)param_1[0xa2] != (longlong *)0x0) {
            *(longlong *)param_1[0xa2] = param_1[0xa3];
          }
          if (param_1[0xa3] != 0) {
            *(longlong *)(param_1[0xa3] + 0x510) = param_1[0xa2];
          }
          param_1[0xa2] = 0;
          param_1[0xa3] = 0;
        }
        return 1;
      }
      iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_2);
      if (iVar2 == 0) break;
      plVar1 = (longlong *)plVar1[0x97];
    }
    return 0;
  }
  return uVar3;
}



==== FUN_14037a300 @ 14037a300 size 86 ====
CALLERS:
CALLEES: FUN_140367870

void FUN_14037a300(longlong param_1,undefined4 param_2)

{
  int iVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(**(code **)(**(longlong **)(param_1 + 0x30) + 0x38))();
  if (plVar2 != (longlong *)0x0) {
    iVar1 = (**(code **)(*plVar2 + 0x538))(plVar2,param_2);
    if ((iVar1 != 0) && (*(longlong *)(param_1 + 0x510) == 0)) {
      FUN_140367870(*(undefined8 *)(param_1 + 0x10),param_1 + 0x2f0);
    }
  }
  return;
}



==== FUN_14037c090 @ 14037c090 size 592 ====
CALLERS: FUN_140355440
CALLEES: FUN_1407e4830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_14037c090(longlong *param_1,longlong param_2)

{
  undefined8 uVar1;
  
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  *(undefined4 *)(param_1 + 0x37) = 0x544e5645;
  *(undefined4 *)((longlong)param_1 + 0x1fc) = 0;
  param_1[0xab] = 0;
  param_1[0xaa] = 0;
  param_1[0xad] = 0;
  param_1[0xac] = 0;
  param_1[0xae] = 0;
  param_1[0xaf] = 0;
  param_1[0xb0] = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  param_1[0xb5] = 0;
  param_1[0xb6] = 0;
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  param_1[0xb9] = 0;
  param_1[0xba] = 0;
  *param_1 = param_2;
  *(int *)(param_2 + 0x870) = *(int *)(param_2 + 0x870) + 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  param_1[0x16] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x5e] = 0;
  param_1[0x61] = 0;
  param_1[0x6c] = 0;
  param_1[0x6e] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_1407e4830(param_1 + 0x40,0,0x80);
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0x70] = 0;
  param_1[0x6f] = 0;
  param_1[0x7a] = 0;
  param_1[0x7c] = 0;
  param_1[0x7e] = 0;
  uVar1 = _DAT_140c79888;
  param_1[0x82] = 0;
  *(undefined8 *)((longlong)param_1 + 0x3fc) = uVar1;
  param_1[0x81] = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  return param_1;
}



==== FUN_14037d3e0 @ 14037d3e0 size 349 ====
CALLERS: FUN_1403621e0 FUN_1403682c0
CALLEES: FUN_140381300 FUN_14037d060 FUN_140381180

undefined8 FUN_14037d3e0(longlong *param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong *plVar5;
  
  if (param_1[0xb9] == 0) {
    return 1;
  }
  if ((*(byte *)((longlong)param_1 + 0x2c) & 1) == 0) {
    if ((param_1[0xb7] != 0) && (uVar3 = FUN_14037d060(param_1,param_2,1), (int)uVar3 == 0)) {
      return uVar3;
    }
    *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) | 1;
  }
  if ((*(byte *)((longlong)param_1 + 0x2c) & 2) == 0) {
    FUN_140381180(param_1);
    *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) & 0xfffffffb | 2;
  }
  if ((*(byte *)((longlong)param_1 + 0x2c) & 4) == 0) {
    if ((*(uint *)(*param_1 + 0xe8) & 0x4000) != 0) {
      uVar4 = 0;
      plVar5 = param_1 + 0x54;
      do {
        plVar1 = (longlong *)plVar5[-4];
        if ((plVar1 != (longlong *)0x0) &&
           (iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_2), iVar2 == 0)) {
          return 0;
        }
        plVar1 = (longlong *)*plVar5;
        if ((plVar1 != (longlong *)0x0) &&
           (iVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_2), iVar2 == 0)) {
          return 0;
        }
        uVar4 = uVar4 + 1;
        plVar5 = plVar5 + 1;
      } while (uVar4 < 4);
    }
    *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) | 4;
  }
  if ((*(byte *)((longlong)param_1 + 0x2c) & 8) == 0) {
    iVar2 = FUN_140381300(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) | 8;
  }
  if ((longlong *)param_1[0xb9] != (longlong *)0x0) {
    *(longlong *)param_1[0xb9] = param_1[0xba];
  }
  if (param_1[0xba] != 0) {
    *(longlong *)(param_1[0xba] + 0x5c8) = param_1[0xb9];
  }
  param_1[0xb9] = 0;
  param_1[0xba] = 0;
  *(int *)(*param_1 + 0x87c) = *(int *)(*param_1 + 0x87c) + -1;
  return 1;
}



==== FUN_14037d540 @ 14037d540 size 584 ====
CALLERS: FUN_1403563c0 FUN_14037ea00 FUN_140381180
CALLEES: FUN_140195960

void FUN_14037d540(longlong *param_1)

{
  undefined1 (*pauVar1) [16];
  longlong *plVar2;
  longlong lVar3;
  float *pfVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 auVar7 [16];
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 local_48 [2];
  longlong *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  
  lVar5 = *param_1;
  fVar8 = DAT_140b79ed0;
  if (*(int *)(lVar5 + 0x648) == 0) {
    lVar3 = (**(code **)(*(longlong *)param_1[2] + 0x28))();
    pauVar1 = (undefined1 (*) [16])(lVar5 + 0x390);
    lVar5 = *param_1;
    auVar7 = minps(*pauVar1,*(undefined1 (*) [16])(lVar3 + 0x30));
    auVar7 = maxps(*(undefined1 (*) [16])(lVar3 + 0x20),auVar7);
    fVar8 = auVar7._0_4_ - *(float *)(lVar5 + 0x390);
    fVar9 = auVar7._4_4_ - *(float *)(lVar5 + 0x394);
    fVar10 = auVar7._8_4_ - *(float *)(lVar5 + 0x398);
    fVar8 = SQRT(fVar8 * fVar8 + fVar9 * fVar9 + fVar10 * fVar10);
  }
  pfVar4 = (float *)(param_1 + 0x5a);
  lVar3 = 4;
  fVar9 = fVar8 * *(float *)(lVar5 + 0x77c);
  plVar6 = param_1 + 0xb;
  do {
    lVar5 = plVar6[-4];
    if (lVar5 != 0) {
      plVar2 = (longlong *)*plVar6;
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x30))
                  (plVar2,*(undefined4 *)(*param_1 + 0x774),*(undefined4 *)(*param_1 + 0x778),
                   *(float *)((longlong)param_1 + (longlong)*(int *)(lVar5 + 0x70) * 4 + 0x1a8) *
                   *(float *)(lVar5 + 0x68) * fVar9);
      }
      plVar2 = (longlong *)plVar6[4];
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x30))
                  (plVar2,*(undefined4 *)(*param_1 + 0x774),*(undefined4 *)(*param_1 + 0x778),
                   *(float *)((longlong)param_1 + (longlong)*(int *)(lVar5 + 0x70) * 4 + 0x1a8) *
                   *(float *)(lVar5 + 0x68) * fVar9);
      }
      plVar2 = (longlong *)plVar6[0x45];
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x30))
                  (plVar2,*(undefined4 *)(*param_1 + 0x774),*(undefined4 *)(*param_1 + 0x778),
                   fVar9 * *pfVar4);
      }
      plVar2 = (longlong *)plVar6[0x49];
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x30))
                  (plVar2,*(undefined4 *)(*param_1 + 0x774),*(undefined4 *)(*param_1 + 0x778),
                   fVar9 * *pfVar4);
      }
    }
    plVar6 = plVar6 + 1;
    pfVar4 = pfVar4 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if ((longlong *)param_1[0xb3] != (longlong *)0x0) {
    *(longlong *)param_1[0xb3] = param_1[0xb4];
  }
  if (param_1[0xb4] != 0) {
    *(longlong *)(param_1[0xb4] + 0x598) = param_1[0xb3];
  }
  fVar8 = fVar8 * DAT_140b7a120;
  param_1[0xb3] = 0;
  param_1[0xb4] = 0;
  local_48[0] = 0;
  local_30 = 0;
  fVar8 = fVar8 * DAT_140b79d68;
  if (fVar8 <= DAT_140b7a120) {
    fVar8 = DAT_140b7a120;
  }
  local_38 = &LAB_140383720;
  if (DAT_140b7a190 <= fVar8) {
    fVar8 = DAT_140b7a190;
  }
  local_40 = param_1;
  FUN_140195960(param_1 + 0x37,(longlong)fVar8,local_48,4);
  return;
}



==== FUN_14037d790 @ 14037d790 size 2877 ====
CALLERS: FUN_14037cb70
CALLEES: FUN_14018b280

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14037d790(longlong param_1)

{
  ushort uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  float *pfVar9;
  ushort *puVar10;
  float *pfVar11;
  undefined4 *puVar12;
  longlong lVar13;
  undefined4 *puVar14;
  float *pfVar15;
  longlong lVar16;
  float *pfVar17;
  undefined4 *puVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar29;
  undefined1 auVar25 [12];
  undefined1 auVar26 [12];
  float fVar30;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float local_res8;
  float fStackX_c;
  longlong *local_res10;
  float local_res18;
  float fStackX_1c;
  
  (**(code **)(**(longlong **)(param_1 + 0x10) + 0x48))
            (*(longlong **)(param_1 + 0x10),0,&local_res10,1);
  lVar6 = (**(code **)(*local_res10 + 0x10))();
  lVar7 = (**(code **)(*local_res10 + 0x18))();
  fVar21 = DAT_140c41b9c;
  fVar19 = DAT_140c41b94;
  pfVar15 = (float *)&DAT_140dc16b0;
  lVar16 = 0x13;
  lVar7 = (lVar7 - *(int *)(lVar6 + 0x28)) - (longlong)*(int *)(lVar6 + 0x2c);
  do {
    lVar13 = 2;
    pfVar9 = pfVar15 + -0xe;
    puVar10 = (ushort *)(lVar7 + 4);
    do {
      pfVar9[-2] = (float)(puVar10[-2] & 0x7fff) * fVar21 - fVar19;
      pfVar9[-1] = (float)(puVar10[-1] & 0x7fff) * fVar21 - fVar19;
      *pfVar9 = (float)(*puVar10 & 0x7fff) * fVar21 - fVar19;
      pfVar9[1] = (float)(puVar10[1] & 0x7fff) * fVar21 - fVar19;
      pfVar9[2] = (float)(puVar10[2] & 0x7fff) * fVar21 - fVar19;
      pfVar9[3] = (float)(puVar10[3] & 0x7fff) * fVar21 - fVar19;
      pfVar9[4] = (float)(puVar10[4] & 0x7fff) * fVar21 - fVar19;
      pfVar9[5] = (float)(puVar10[5] & 0x7fff) * fVar21 - fVar19;
      lVar13 = lVar13 + -1;
      pfVar9 = pfVar9 + 8;
      puVar10 = puVar10 + 8;
    } while (lVar13 != 0);
    puVar10 = (ushort *)(lVar7 + 0x20);
    lVar13 = 3;
    pfVar9 = pfVar15;
    do {
      uVar1 = *puVar10;
      puVar10 = puVar10 + 1;
      *pfVar9 = (float)(uVar1 & 0x7fff) * fVar21 - fVar19;
      fVar5 = DAT_140b79ed0;
      fVar4 = DAT_140b79e48;
      lVar13 = lVar13 + -1;
      pfVar9 = pfVar9 + 1;
    } while (lVar13 != 0);
    pfVar15 = pfVar15 + 0x13;
    lVar7 = lVar7 + *(int *)(lVar6 + 0x2c);
    lVar16 = lVar16 + -1;
  } while (lVar16 != 0);
  puVar12 = &DAT_140dc1c20;
  lVar6 = 0x12;
  puVar14 = &DAT_140dc1c20;
  puVar18 = &DAT_140dc1670;
  do {
    lVar16 = (longlong)(puVar18 + 0x13) - (longlong)puVar18;
    lVar13 = (longlong)puVar14 - (longlong)puVar18;
    lVar7 = 2;
    pfVar15 = (float *)(puVar18 + 1);
    pfVar9 = (float *)(puVar18 + 1);
    do {
      fVar19 = pfVar15[-1] - *(float *)(lVar16 + (longlong)pfVar9);
      fVar21 = *pfVar9 - *(float *)((longlong)pfVar15 + lVar16 + -4);
      fVar32 = fVar5 / (fVar19 * fVar19 + fVar5);
      fVar22 = fVar5 / (fVar21 * fVar21 + fVar5);
      fVar19 = *pfVar15;
      fVar21 = *(float *)(lVar16 + 4 + (longlong)pfVar9);
      fVar20 = fVar19 - *(float *)(lVar16 + 4 + (longlong)pfVar9);
      *(float *)((longlong)pfVar15 + lVar13 + -4) =
           ((*pfVar9 + *(float *)((longlong)pfVar15 + lVar16 + -4)) * fVar22 +
           (pfVar15[-1] + *(float *)(lVar16 + (longlong)pfVar9)) * fVar32) *
           (fVar4 / (fVar22 + fVar32));
      fVar22 = pfVar9[1] - *(float *)(lVar16 + (longlong)pfVar15);
      fVar33 = fVar5 / (fVar20 * fVar20 + fVar5);
      fVar23 = fVar5 / (fVar22 * fVar22 + fVar5);
      fVar20 = pfVar15[1];
      fVar22 = *(float *)(lVar16 + 8 + (longlong)pfVar9);
      fVar32 = fVar20 - *(float *)(lVar16 + 8 + (longlong)pfVar9);
      *(float *)(lVar13 + (longlong)pfVar15) =
           ((pfVar9[1] + *(float *)(lVar16 + (longlong)pfVar15)) * fVar23 +
           (fVar19 + fVar21) * fVar33) * (fVar4 / (fVar23 + fVar33));
      fVar19 = pfVar9[2] - *(float *)(lVar16 + 4 + (longlong)pfVar15);
      fVar23 = fVar5 / (fVar32 * fVar32 + fVar5);
      fVar32 = fVar5 / (fVar19 * fVar19 + fVar5);
      fVar19 = pfVar15[2];
      fVar21 = fVar19 - *(float *)(lVar16 + 0xc + (longlong)pfVar9);
      *(float *)(lVar13 + 4 + (longlong)pfVar15) =
           ((pfVar9[2] + *(float *)(lVar16 + 4 + (longlong)pfVar15)) * fVar32 +
           (fVar20 + fVar22) * fVar23) * (fVar4 / (fVar32 + fVar23));
      fVar23 = fVar5 / (fVar21 * fVar21 + fVar5);
      fVar21 = pfVar9[3] - *(float *)(lVar16 + 8 + (longlong)pfVar15);
      fVar32 = fVar5 / (fVar21 * fVar21 + fVar5);
      fVar21 = pfVar15[3];
      fVar20 = *(float *)(lVar16 + 0x10 + (longlong)pfVar9);
      fVar22 = fVar21 - *(float *)(lVar16 + 0x10 + (longlong)pfVar9);
      *(float *)(lVar13 + 8 + (longlong)pfVar15) =
           ((pfVar9[3] + *(float *)(lVar16 + 8 + (longlong)pfVar15)) * fVar32 +
           (fVar19 + *(float *)(lVar16 + 0xc + (longlong)pfVar9)) * fVar23) *
           (fVar4 / (fVar32 + fVar23));
      fVar19 = pfVar9[4] - *(float *)(lVar16 + 0xc + (longlong)pfVar15);
      fVar33 = fVar5 / (fVar22 * fVar22 + fVar5);
      fVar23 = fVar5 / (fVar19 * fVar19 + fVar5);
      fVar19 = pfVar15[4];
      fVar22 = *(float *)(lVar16 + 0x14 + (longlong)pfVar9);
      fVar32 = fVar19 - *(float *)(lVar16 + 0x14 + (longlong)pfVar9);
      *(float *)(lVar13 + 0xc + (longlong)pfVar15) =
           ((pfVar9[4] + *(float *)(lVar16 + 0xc + (longlong)pfVar15)) * fVar23 +
           (fVar21 + fVar20) * fVar33) * (fVar4 / (fVar23 + fVar33));
      fVar21 = pfVar9[5] - *(float *)(lVar16 + 0x10 + (longlong)pfVar15);
      fVar33 = fVar5 / (fVar32 * fVar32 + fVar5);
      fVar23 = fVar5 / (fVar21 * fVar21 + fVar5);
      fVar21 = pfVar15[5];
      fVar20 = *(float *)(lVar16 + 0x18 + (longlong)pfVar9);
      fVar32 = fVar21 - *(float *)(lVar16 + 0x18 + (longlong)pfVar9);
      *(float *)((longlong)pfVar15 + lVar13 + 0x10) =
           ((pfVar9[5] + *(float *)(lVar16 + 0x10 + (longlong)pfVar15)) * fVar23 +
           (fVar19 + fVar22) * fVar33) * (fVar4 / (fVar23 + fVar33));
      fVar19 = pfVar9[6] - *(float *)(lVar16 + 0x14 + (longlong)pfVar15);
      fVar33 = fVar5 / (fVar32 * fVar32 + fVar5);
      fVar23 = fVar5 / (fVar19 * fVar19 + fVar5);
      fVar19 = pfVar15[6];
      pfVar11 = pfVar15 + 9;
      pfVar17 = pfVar9 + 9;
      fVar22 = *(float *)(lVar16 + -8 + (longlong)pfVar17);
      fVar32 = fVar19 - *(float *)(lVar16 + -8 + (longlong)pfVar17);
      *(float *)((longlong)pfVar15 + lVar13 + 0x14) =
           ((pfVar9[6] + *(float *)(lVar16 + 0x14 + (longlong)pfVar15)) * fVar23 +
           (fVar21 + fVar20) * fVar33) * (fVar4 / (fVar23 + fVar33));
      fVar21 = pfVar9[7] - *(float *)(lVar16 + -0xc + (longlong)pfVar11);
      fVar33 = fVar5 / (fVar32 * fVar32 + fVar5);
      fVar23 = fVar5 / (fVar21 * fVar21 + fVar5);
      fVar21 = pfVar15[7];
      fVar20 = *(float *)(lVar16 + -4 + (longlong)pfVar17);
      fVar32 = fVar21 - *(float *)(lVar16 + -4 + (longlong)pfVar17);
      *(float *)((longlong)pfVar15 + lVar13 + 0x18) =
           ((pfVar9[7] + *(float *)(lVar16 + -0xc + (longlong)pfVar11)) * fVar23 +
           (fVar19 + fVar22) * fVar33) * (fVar4 / (fVar23 + fVar33));
      fVar19 = pfVar9[8] - *(float *)(lVar16 + -8 + (longlong)pfVar11);
      fVar22 = fVar5 / (fVar32 * fVar32 + fVar5);
      fVar19 = fVar5 / (fVar19 * fVar19 + fVar5);
      *(float *)((longlong)pfVar15 + lVar13 + 0x1c) =
           ((pfVar9[8] + *(float *)(lVar16 + -8 + (longlong)pfVar11)) * fVar19 +
           (fVar21 + fVar20) * fVar22) * (fVar4 / (fVar19 + fVar22));
      lVar7 = lVar7 + -1;
      pfVar15 = pfVar11;
      pfVar9 = pfVar17;
    } while (lVar7 != 0);
    puVar14 = puVar14 + 0x12;
    lVar6 = lVar6 + -1;
    puVar18 = puVar18 + 0x13;
  } while (lVar6 != 0);
  if (*(longlong *)(param_1 + 0x98) == 0) {
    uVar8 = FUN_14018b280(0x2210,0);
    *(undefined8 *)(param_1 + 0x98) = uVar8;
  }
  fVar21 = DAT_140c44574;
  fVar19 = DAT_140b7a228;
  pfVar15 = *(float **)(param_1 + 0x98);
  puVar18 = &DAT_140dc16c0;
  lVar6 = 0x11;
  local_res8 = DAT_140c79888;
  fStackX_c = DAT_140c7988c;
  do {
    lVar7 = 0x11;
    pfVar9 = (float *)(puVar12 + 0x12);
    do {
      pfVar11 = pfVar15;
      fVar20 = pfVar9[1];
      pfVar15 = pfVar9 + 1;
      fVar22 = *(float *)((longlong)puVar18 + (-0x4c - (longlong)puVar12) + (longlong)pfVar15);
      if (fVar22 <= local_res8) {
        local_res8 = fVar22;
      }
      fVar22 = *(float *)((longlong)puVar18 + (-0x4c - (longlong)puVar12) + (longlong)pfVar15);
      if (fStackX_c <= fVar22) {
        fStackX_c = fVar22;
      }
      fVar22 = pfVar9[-0x11];
      fVar32 = *pfVar9;
      fVar23 = pfVar9[-0x12];
      pfVar11[1] = fVar21;
      fVar32 = ((fVar20 + fVar22) - (fVar32 + fVar23)) * fVar19;
      *pfVar11 = fVar32;
      fVar20 = ((*pfVar15 + *pfVar9) - (pfVar9[-0x11] + pfVar9[-0x12])) * fVar19;
      pfVar11[2] = fVar20;
      pfVar11[3] = *(float *)((longlong)puVar18 + (-0x4c - (longlong)puVar12) + (longlong)pfVar15);
      auVar25._4_4_ = fVar21 * fVar21;
      auVar25._0_4_ = fVar32 * fVar32;
      auVar25._8_4_ = fVar20 * fVar20;
      auVar27._0_4_ = fVar32 * fVar32 + fVar21 * fVar21 + fVar20 * fVar20;
      auVar27._4_8_ = auVar25._4_8_;
      auVar27._12_4_ = 0;
      auVar27 = rsqrtss(auVar27,auVar27);
      fVar22 = auVar27._0_4_;
      *pfVar11 = fVar22 * fVar32;
      pfVar11[1] = fVar22 * fVar21;
      pfVar11[2] = fVar22 * fVar20;
      lVar7 = lVar7 + -1;
      pfVar9 = pfVar15;
      pfVar15 = pfVar11 + 4;
    } while (lVar7 != 0);
    pfVar15 = pfVar11 + 0x44;
    puVar18 = puVar18 + 0x13;
    puVar12 = puVar12 + 0x12;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  pfVar15 = *(float **)(param_1 + 0x98);
  lVar6 = 0x10;
  do {
    lVar7 = 0x10;
    pfVar9 = pfVar15 + 0x8b;
    pfVar11 = pfVar15 + 0x44;
    do {
      pfVar15 = pfVar11 + 4;
      fVar33 = fVar5 / ((pfVar9[-0x84] - pfVar9[-4]) * (pfVar9[-0x84] - pfVar9[-4]) + fVar5);
      fVar19 = pfVar9[-0x86];
      fVar21 = pfVar9[-0x85];
      fVar20 = pfVar9[-0x84];
      fVar34 = fVar5 / ((pfVar9[-0x88] - *pfVar9) * (pfVar9[-0x88] - *pfVar9) + fVar5);
      fVar22 = pfVar9[-6];
      fVar32 = pfVar9[-5];
      fVar23 = pfVar9[-4];
      fVar31 = fVar4 / (fVar33 + fVar34);
      fVar34 = fVar31 * fVar34;
      fVar31 = fVar31 * fVar33;
      fVar33 = pfVar9[-0x8a];
      fVar24 = pfVar9[-0x89];
      fVar29 = pfVar9[-0x88];
      fVar30 = pfVar9[-2];
      fVar2 = pfVar9[-1];
      fVar3 = *pfVar9;
      *pfVar11 = fVar31 * (pfVar9[-0x87] + pfVar9[-7]) + fVar34 * (pfVar9[-0x8b] + pfVar9[-3]);
      pfVar11[1] = fVar31 * (fVar19 + fVar22) + fVar34 * (fVar33 + fVar30);
      pfVar11[2] = fVar31 * (fVar21 + fVar32) + fVar34 * (fVar24 + fVar2);
      pfVar11[3] = fVar31 * (fVar20 + fVar23) + fVar34 * (fVar29 + fVar3);
      fVar19 = pfVar9[-0x45];
      fVar21 = pfVar9[-0x46];
      fVar20 = *pfVar11;
      auVar26._4_4_ = fVar21 * fVar21;
      auVar26._0_4_ = fVar20 * fVar20;
      auVar26._8_4_ = fVar19 * fVar19;
      auVar28._0_4_ = fVar20 * fVar20 + fVar21 * fVar21 + fVar19 * fVar19;
      auVar28._4_8_ = auVar26._4_8_;
      auVar28._12_4_ = 0;
      auVar27 = rsqrtss(auVar28,auVar28);
      fVar22 = auVar27._0_4_;
      *pfVar11 = fVar22 * fVar20;
      pfVar11[1] = fVar22 * fVar21;
      pfVar11[2] = fVar22 * fVar19;
      lVar7 = lVar7 + -1;
      pfVar9 = pfVar9 + 4;
      pfVar11 = pfVar15;
    } while (lVar7 != 0);
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  local_res18 = local_res8;
  fStackX_1c = fStackX_c;
  (**(code **)(*local_res10 + 8))();
  lVar6 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x28))();
  fVar20 = _UNK_140b7ac5c;
  fVar5 = _UNK_140b7ac58;
  fVar21 = _UNK_140b7ac54;
  fVar19 = _DAT_140b7ac50;
  uVar8 = *(undefined8 *)(lVar6 + 0x28);
  *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(lVar6 + 0x20);
  *(undefined8 *)(param_1 + 200) = uVar8;
  uVar8 = *(undefined8 *)(lVar6 + 0x38);
  *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(lVar6 + 0x30);
  *(undefined8 *)(param_1 + 0xd8) = uVar8;
  *(float *)(param_1 + 0xd4) = fStackX_c;
  *(float *)(param_1 + 0xc4) = local_res8;
  fVar22 = *(float *)(param_1 + 0xd0) - *(float *)(param_1 + 0xc0);
  fVar32 = *(float *)(param_1 + 0xd4) - *(float *)(param_1 + 0xc4);
  fVar23 = *(float *)(param_1 + 0xd8) - *(float *)(param_1 + 200);
  *(float *)(param_1 + 0xe0) = (*(float *)(param_1 + 0xc0) + *(float *)(param_1 + 0xd0)) * fVar19;
  *(float *)(param_1 + 0xe4) = (*(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xd4)) * fVar21;
  *(float *)(param_1 + 0xe8) = (*(float *)(param_1 + 200) + *(float *)(param_1 + 0xd8)) * fVar5;
  *(float *)(param_1 + 0xec) = (*(float *)(param_1 + 0xcc) + *(float *)(param_1 + 0xdc)) * fVar20;
  *(float *)(param_1 + 0xf0) = SQRT(fVar22 * fVar22 + fVar32 * fVar32 + fVar23 * fVar23) * fVar4;
  *(undefined8 *)(param_1 + 0x100) = *(undefined8 *)(param_1 + 0xc0);
  *(undefined8 *)(param_1 + 0x108) = *(undefined8 *)(param_1 + 200);
  *(undefined8 *)(param_1 + 0x110) = *(undefined8 *)(param_1 + 0xd0);
  *(undefined8 *)(param_1 + 0x118) = *(undefined8 *)(param_1 + 0xd8);
  fVar22 = *(float *)(param_1 + 0xc4);
  if (*(float *)(param_1 + 0x3fc) <= *(float *)(param_1 + 0xc4)) {
    fVar22 = *(float *)(param_1 + 0x3fc);
  }
  fVar32 = *(float *)(param_1 + 0xd4);
  if (*(float *)(param_1 + 0xd4) <= *(float *)(param_1 + 0x400)) {
    fVar32 = *(float *)(param_1 + 0x400);
  }
  *(float *)(param_1 + 0x104) = fVar22;
  *(float *)(param_1 + 0x114) = fVar32;
  fVar22 = *(float *)(param_1 + 0x110) - *(float *)(param_1 + 0x100);
  fVar32 = *(float *)(param_1 + 0x114) - *(float *)(param_1 + 0x104);
  fVar23 = *(float *)(param_1 + 0x118) - *(float *)(param_1 + 0x108);
  *(float *)(param_1 + 0x120) = (*(float *)(param_1 + 0x100) + *(float *)(param_1 + 0x110)) * fVar19
  ;
  *(float *)(param_1 + 0x124) = (*(float *)(param_1 + 0x104) + *(float *)(param_1 + 0x114)) * fVar21
  ;
  *(float *)(param_1 + 0x128) = (*(float *)(param_1 + 0x108) + *(float *)(param_1 + 0x118)) * fVar5;
  *(float *)(param_1 + 300) = (*(float *)(param_1 + 0x10c) + *(float *)(param_1 + 0x11c)) * fVar20;
  *(float *)(param_1 + 0x130) = SQRT(fVar22 * fVar22 + fVar32 * fVar32 + fVar23 * fVar23) * fVar4;
  *(undefined8 *)(param_1 + 800) = *(undefined8 *)(param_1 + 0xc0);
  *(undefined8 *)(param_1 + 0x328) = *(undefined8 *)(param_1 + 200);
  *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(param_1 + 0xd0);
  *(undefined8 *)(param_1 + 0x338) = *(undefined8 *)(param_1 + 0xd8);
  fVar22 = *(float *)(param_1 + 0x324) - _UNK_140b7b244;
  fVar32 = *(float *)(param_1 + 0x328) - DAT_140b7b248;
  fVar23 = *(float *)(param_1 + 0x32c) - _UNK_140b7b24c;
  *(float *)(param_1 + 800) = *(float *)(param_1 + 800) - _DAT_140b7b240;
  *(float *)(param_1 + 0x324) = fVar22;
  *(float *)(param_1 + 0x328) = fVar32;
  *(float *)(param_1 + 0x32c) = fVar23;
  fVar22 = *(float *)(param_1 + 0x330) + _DAT_140b7b240;
  fVar32 = *(float *)(param_1 + 0x334) + _UNK_140b7b244;
  fVar23 = *(float *)(param_1 + 0x338) + DAT_140b7b248;
  fVar33 = *(float *)(param_1 + 0x33c) + _UNK_140b7b24c;
  *(float *)(param_1 + 0x330) = fVar22;
  *(float *)(param_1 + 0x334) = fVar32;
  *(float *)(param_1 + 0x338) = fVar23;
  *(float *)(param_1 + 0x33c) = fVar33;
  fVar24 = fVar22 - *(float *)(param_1 + 800);
  fVar29 = fVar32 - *(float *)(param_1 + 0x324);
  fVar30 = fVar23 - *(float *)(param_1 + 0x328);
  *(float *)(param_1 + 0x340) = (fVar22 + *(float *)(param_1 + 800)) * fVar19;
  *(float *)(param_1 + 0x344) = (fVar32 + *(float *)(param_1 + 0x324)) * fVar21;
  *(float *)(param_1 + 0x348) = (fVar23 + *(float *)(param_1 + 0x328)) * fVar5;
  *(float *)(param_1 + 0x34c) = (fVar33 + *(float *)(param_1 + 0x32c)) * fVar20;
  *(float *)(param_1 + 0x350) = SQRT(fVar24 * fVar24 + fVar29 * fVar29 + fVar30 * fVar30) * fVar4;
  return;
}



==== FUN_14037ee40 @ 14037ee40 size 314 ====
CALLERS: FUN_14037d060
CALLEES: FUN_140350a20 FUN_140371d10

void FUN_14037ee40(longlong *param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *local_res8;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((longlong *)param_1[0x33] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x33] + 8))();
    param_1[0x33] = 0;
  }
  if ((((byte)*(undefined4 *)(*param_1 + 0xe8) & 5) == 5) &&
     ((*(uint *)(*param_1 + 0xec) & 0x1000) != 0)) {
    uVar2 = (**(code **)(*(longlong *)param_1[2] + 0x40))((longlong *)param_1[2],0xe);
    iVar3 = FUN_140350a20(*(undefined8 *)(*param_1 + 0x10),6,uVar2,param_1 + 0x33);
    if ((-1 < iVar3) && (iVar3 != 1)) {
      local_res8 = (longlong *)0x0;
      (**(code **)(*(longlong *)param_1[2] + 0x48))((longlong *)param_1[2],0xe,&local_res8);
      lVar1 = *(longlong *)(param_1[0x33] + 0x20);
      uVar4 = (**(code **)(*local_res8 + 0x18))();
      local_18 = 0x44;
      local_14 = 0x44;
      local_10 = 1;
      local_c = 0xd;
      lVar5 = (**(code **)(*local_res8 + 0x10))();
      local_28 = *(int *)(lVar5 + 0x2c);
      local_24 = local_28 * 0x11;
      local_20 = local_24;
      FUN_140371d10(*(undefined8 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x18),uVar4,&local_18,
                    &local_28);
      if (local_res8 != (longlong *)0x0) {
        (**(code **)(*local_res8 + 8))();
      }
    }
  }
  return;
}



==== FUN_14037f4a0 @ 14037f4a0 size 407 ====
CALLERS: FUN_14037cc30
CALLEES: FUN_14018b280 FUN_14018b900 FUN_140377fe0 FUN_1407e4830

void FUN_14037f4a0(undefined8 *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong *local_res8;
  longlong local_res10;
  
  iVar4 = (**(code **)(*(longlong *)param_1[2] + 0x90))((longlong *)param_1[2],&local_res8);
  if (-1 < iVar4) {
    uVar5 = (**(code **)(*local_res8 + 0x10))();
    uVar10 = 0;
    uVar7 = uVar10;
    if (uVar5 != 0) {
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar5;
      uVar6 = SUB168(ZEXT816(8) * auVar3,0);
      if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
        uVar6 = 0xffffffffffffffff;
      }
      uVar7 = FUN_14018b280(uVar6,0);
    }
    FUN_1407e4830(uVar7,0,uVar5 * 8);
    uVar9 = uVar10;
    uVar11 = uVar10;
    if (uVar5 != 0) {
      do {
        plVar8 = (longlong *)(**(code **)(*local_res8 + 0x18))(local_res8,uVar11);
        iVar4 = (**(code **)(*plVar8 + 0x28))(plVar8);
        if (iVar4 != 4) {
          lVar2 = *(longlong *)*param_1;
          uVar6 = (**(code **)(*local_res8 + 0x18))(local_res8,uVar11);
          iVar4 = (**(code **)(lVar2 + 0x130))(*param_1,uVar6,&local_res10);
          if (-1 < iVar4) {
            uVar9 = uVar9 + 1;
            *(longlong *)((uVar7 - 8) + uVar9 * 8) = local_res10;
            iVar4 = *(int *)(local_res10 + 0x41c);
            *(int *)(local_res10 + 0x41c) = iVar4 + 1;
            if (iVar4 == 0) {
              FUN_140377fe0();
            }
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar5);
    }
    if (param_1[0x6f] != 0) {
      do {
        plVar8 = *(longlong **)(param_1[0x70] + uVar10 * 8);
        piVar1 = (int *)((longlong)plVar8 + 0x41c);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          FUN_140377fe0(plVar8);
        }
        (**(code **)(*plVar8 + 8))(plVar8);
        uVar10 = uVar10 + 1;
      } while (uVar10 < (ulonglong)param_1[0x6f]);
    }
    FUN_14018b900(param_1[0x70],0);
    param_1[0x70] = uVar7;
    param_1[0x6f] = uVar9;
    (**(code **)(*local_res8 + 8))();
  }
  return;
}



==== FUN_140381180 @ 140381180 size 376 ====
CALLERS: FUN_14037d3e0 FUN_140355330
CALLEES: FUN_14037d540 FUN_1403748e0 FUN_140374bf0

void FUN_140381180(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  float *pfVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  float fVar9;
  float fVar10;
  longlong local_res8;
  longlong local_res10;
  
  if ((*(uint *)(*param_1 + 0xe8) & 0x4000) != 0) {
    plVar7 = param_1 + 0x54;
    pfVar5 = (float *)(param_1 + 0x5a);
    plVar8 = param_1 + 0x40;
    lVar6 = 4;
    do {
      lVar3 = 0;
      *pfVar5 = DAT_140c44570;
      pfVar5[-4] = 0.0;
      if ((int)param_1[0x62] != 0) {
        lVar4 = 4;
        plVar2 = plVar8;
        do {
          lVar1 = *plVar2;
          if (lVar1 != 0) {
            pfVar5[-4] = (float)((uint)pfVar5[-4] | *(uint *)(lVar1 + 0x24));
            fVar9 = (float)FUN_140374bf0();
            fVar10 = *pfVar5;
            if (fVar9 <= *pfVar5) {
              fVar10 = fVar9;
            }
            *pfVar5 = fVar10;
            lVar3 = lVar1;
          }
          plVar2 = plVar2 + 1;
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
      }
      local_res8 = 0;
      local_res10 = 0;
      if (lVar3 != 0) {
        FUN_1403748e0(lVar3,&local_res8,&local_res10);
      }
      lVar4 = local_res10;
      lVar3 = local_res8;
      if ((longlong *)plVar7[-4] != (longlong *)0x0) {
        (**(code **)(*(longlong *)plVar7[-4] + 8))();
        plVar7[-4] = 0;
      }
      plVar7[-4] = lVar3;
      if ((longlong *)*plVar7 != (longlong *)0x0) {
        (**(code **)(*(longlong *)*plVar7 + 8))();
        *plVar7 = 0;
      }
      *plVar7 = lVar4;
      plVar7 = plVar7 + 1;
      pfVar5 = pfVar5 + 1;
      plVar8 = plVar8 + 4;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    FUN_14037d540(param_1);
  }
  return;
}



==== FUN_140382c20 @ 140382c20 size 299 ====
CALLERS: FUN_14037d060
CALLEES: FUN_140350a20 FUN_140371d10

void FUN_140382c20(longlong *param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *local_res8;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((longlong *)param_1[0x93] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x93] + 8))();
    param_1[0x93] = 0;
  }
  if (((byte)*(undefined4 *)(*param_1 + 0xe8) & 0x11) == 0x11) {
    uVar2 = (**(code **)(*(longlong *)param_1[2] + 0x40))((longlong *)param_1[2],0x1f);
    iVar3 = FUN_140350a20(*(undefined8 *)(*param_1 + 0x10),7,uVar2,param_1 + 0x93);
    if ((-1 < iVar3) && (iVar3 != 1)) {
      local_res8 = (longlong *)0x0;
      (**(code **)(*(longlong *)param_1[2] + 0x48))((longlong *)param_1[2],0x1f,&local_res8);
      lVar1 = *(longlong *)(param_1[0x93] + 0x20);
      uVar4 = (**(code **)(*local_res8 + 0x18))();
      local_18 = 0x44;
      local_14 = 0x44;
      local_10 = 1;
      local_c = 0xd;
      lVar5 = (**(code **)(*local_res8 + 0x10))();
      local_28 = *(int *)(lVar5 + 0x2c);
      local_24 = local_28 * 0x11;
      local_20 = local_24;
      FUN_140371d10(*(undefined8 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x18),uVar4,&local_18,
                    &local_28);
      if (local_res8 != (longlong *)0x0) {
        (**(code **)(*local_res8 + 8))();
      }
    }
  }
  return;
}



==== FUN_140382d50 @ 140382d50 size 316 ====
CALLERS: FUN_140366cd0
CALLEES: FUN_140383760 FUN_140393020

void FUN_140382d50(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffe9600;
  FUN_140383760();
  *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) & 0xfffffff6;
  uVar3 = 0;
  if (param_1[0xb5] == 0) {
    plVar1 = param_1 + 0xb6;
    plVar2 = (longlong *)(*param_1 + 0x8e8);
    param_1[0xb5] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5a8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x8f0) = 0;
    *(int *)(*param_1 + 0x874) = *(int *)(*param_1 + 0x874) + 1;
  }
  if (param_1[0xb7] == 0) {
    plVar1 = param_1 + 0xb8;
    plVar2 = (longlong *)(*param_1 + 0x8f8);
    param_1[0xb7] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5b8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x900) = 0;
    *(int *)(*param_1 + 0x878) = *(int *)(*param_1 + 0x878) + 1;
  }
  if (param_1[0xb9] == 0) {
    plVar1 = param_1 + 0xba;
    plVar2 = (longlong *)(*param_1 + 0x908);
    param_1[0xb9] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5c8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x910) = 0;
    *(int *)(*param_1 + 0x87c) = *(int *)(*param_1 + 0x87c) + 1;
  }
  if (param_1[0x81] != 0) {
    do {
      if (*(longlong *)(param_1[0x82] + uVar3 * 8) != 0) {
        FUN_140393020();
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (ulonglong)param_1[0x81]);
  }
  return;
}



==== FUN_140382e90 @ 140382e90 size 251 ====
CALLERS: FUN_14038f540 FUN_140367130 FUN_14038f600
CALLEES: FUN_140389c40

void FUN_140382e90(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  *(uint *)((longlong)param_1 + 0x24) = *(uint *)((longlong)param_1 + 0x24) & 0xffffffcf;
  *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffffe;
  *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) & 0xfffffffe;
  if (param_1[0xb5] == 0) {
    plVar1 = param_1 + 0xb6;
    plVar2 = (longlong *)(*param_1 + 0x8e8);
    param_1[0xb5] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5a8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x8f0) = 0;
    *(int *)(*param_1 + 0x874) = *(int *)(*param_1 + 0x874) + 1;
  }
  if (param_1[0xb7] == 0) {
    plVar1 = param_1 + 0xb8;
    plVar2 = (longlong *)(*param_1 + 0x8f8);
    param_1[0xb7] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5b8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x900) = 0;
    *(int *)(*param_1 + 0x878) = *(int *)(*param_1 + 0x878) + 1;
  }
  if (param_1[0xb9] == 0) {
    plVar1 = param_1 + 0xba;
    plVar2 = (longlong *)(*param_1 + 0x908);
    param_1[0xb9] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5c8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x910) = 0;
    *(int *)(*param_1 + 0x87c) = *(int *)(*param_1 + 0x87c) + 1;
  }
  FUN_140389c40(param_1);
  return;
}



==== FUN_140382f90 @ 140382f90 size 295 ====
CALLERS: FUN_140367070
CALLEES: FUN_140389c40

void FUN_140382f90(longlong *param_1,undefined8 *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  (**(code **)*param_2)(param_2);
  (**(code **)(*(longlong *)param_1[2] + 8))();
  param_1[2] = (longlong)param_2;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_1[0xb5] == 0) {
    plVar1 = param_1 + 0xb6;
    plVar2 = (longlong *)(*param_1 + 0x8e8);
    param_1[0xb5] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5a8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x8f0) = 0;
    *(int *)(*param_1 + 0x874) = *(int *)(*param_1 + 0x874) + 1;
  }
  if (param_1[0xb7] == 0) {
    plVar1 = param_1 + 0xb8;
    plVar2 = (longlong *)(*param_1 + 0x8f8);
    param_1[0xb7] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5b8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x900) = 0;
    *(int *)(*param_1 + 0x878) = *(int *)(*param_1 + 0x878) + 1;
  }
  if (param_1[0xb9] == 0) {
    plVar1 = param_1 + 0xba;
    plVar2 = (longlong *)(*param_1 + 0x908);
    param_1[0xb9] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5c8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x910) = 0;
    *(int *)(*param_1 + 0x87c) = *(int *)(*param_1 + 0x87c) + 1;
  }
  FUN_140389c40(param_1);
  return;
}



==== FUN_1403830c0 @ 1403830c0 size 449 ====
CALLERS: FUN_1403670b0
CALLEES: FUN_140383760 FUN_140389c40

void FUN_1403830c0(longlong *param_1,undefined4 param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  switch(param_2) {
  case 0:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd;
    break;
  case 1:
    *(uint *)((longlong)param_1 + 0x24) = *(uint *)((longlong)param_1 + 0x24) & 0xfffffbff;
    break;
  case 0xd:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xffffffef;
    break;
  case 0xe:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xffffffdf;
    break;
  case 0x10:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xffffffbf;
    break;
  case 0x11:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffffb;
    break;
  case 0x12:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffff7;
    break;
  case 0x13:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xffffdfff;
    break;
  case 0x14:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xffffbfff;
    break;
  case 0x15:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffb;
    break;
  case 0x16:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffff7;
    break;
  case 0x1a:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xffffff7f;
    break;
  case 0x1b:
    FUN_140383760(param_1);
    *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) & 0xfffffff7;
    break;
  case 0x1c:
    *(uint *)((longlong)param_1 + 0x24) = *(uint *)((longlong)param_1 + 0x24) & 0xfffffdff;
    break;
  case 0x1f:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffeffff;
    break;
  case 0x22:
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffeff;
  }
  if ((int)param_1[4] != 0xf) {
    *(uint *)((longlong)param_1 + 0x24) = *(uint *)((longlong)param_1 + 0x24) & 0xfffffffe;
  }
  if (*(int *)((longlong)param_1 + 0x24) != 0x3fff) {
    if (param_1[0xb5] == 0) {
      plVar1 = param_1 + 0xb6;
      plVar2 = (longlong *)(*param_1 + 0x8e8);
      param_1[0xb5] = (longlong)plVar2;
      *plVar1 = *plVar2;
      *plVar2 = (longlong)param_1;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 0x5a8) = plVar1;
      }
      *(undefined4 *)(*param_1 + 0x8f0) = 0;
      *(int *)(*param_1 + 0x874) = *(int *)(*param_1 + 0x874) + 1;
    }
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) & 0xfffffffe;
  }
  if ((int)param_1[5] != 0x1ffff) {
    if (param_1[0xb7] == 0) {
      plVar1 = param_1 + 0xb8;
      plVar2 = (longlong *)(*param_1 + 0x8f8);
      param_1[0xb7] = (longlong)plVar2;
      *plVar1 = *plVar2;
      *plVar2 = (longlong)param_1;
      if (*plVar1 != 0) {
        *(longlong **)(*plVar1 + 0x5b8) = plVar1;
      }
      *(undefined4 *)(*param_1 + 0x900) = 0;
      *(int *)(*param_1 + 0x878) = *(int *)(*param_1 + 0x878) + 1;
    }
    *(uint *)((longlong)param_1 + 0x2c) = *(uint *)((longlong)param_1 + 0x2c) & 0xfffffffe;
  }
  if ((*(int *)((longlong)param_1 + 0x2c) != 0xf) && (param_1[0xb9] == 0)) {
    plVar1 = param_1 + 0xba;
    plVar2 = (longlong *)(*param_1 + 0x908);
    param_1[0xb9] = (longlong)plVar2;
    *plVar1 = *plVar2;
    *plVar2 = (longlong)param_1;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x5c8) = plVar1;
    }
    *(undefined4 *)(*param_1 + 0x910) = 0;
    *(int *)(*param_1 + 0x87c) = *(int *)(*param_1 + 0x87c) + 1;
  }
  FUN_140389c40(param_1);
  return;
}



==== FUN_140384320 @ 140384320 size 345 ====
CALLERS: FUN_1403617a0
CALLEES: FUN_140384480

undefined8 FUN_140384320(longlong *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  ulonglong in_stack_ffffffffffffffd8;
  ulonglong uVar7;
  
  uVar7 = in_stack_ffffffffffffffd8 & 0xffffffff00000000;
  puVar6 = (undefined4 *)(**(code **)(*DAT_140c65670 + 0x100))(DAT_140c65670,0x10,1,9,uVar7);
  if (puVar6 != (undefined4 *)0x0) {
    lVar1 = param_1[0x18];
    lVar5 = param_1[0x19];
    *puVar6 = (int)lVar1;
    puVar6[1] = (int)lVar5;
    puVar6[2] = (int)lVar1;
    puVar6[3] = (int)lVar5;
    (**(code **)(*DAT_140c65670 + 0x108))();
  }
  puVar6 = (undefined4 *)
           (**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0x10,0,0,uVar7 & 0xffffffff00000000);
  if (puVar6 != (undefined4 *)0x0) {
    (**(code **)(*DAT_140c65670 + 0x160))
              (DAT_140c65670,0,
               *(undefined8 *)(*(longlong *)(*(longlong *)(param_1[0x34] + 0x20) + 0x10) + 0x20),0,0
              );
    lVar1 = *(longlong *)(param_1[0x34] + 0x20);
    uVar2 = *(undefined4 *)(lVar1 + 0x24);
    uVar3 = *(undefined4 *)(lVar1 + 0x28);
    uVar4 = *(undefined4 *)(lVar1 + 0x2c);
    *puVar6 = *(undefined4 *)(lVar1 + 0x20);
    puVar6[1] = uVar2;
    puVar6[2] = uVar3;
    puVar6[3] = uVar4;
    (**(code **)(*DAT_140c65670 + 0x160))(DAT_140c65670,1,*(undefined8 *)(*param_1 + 800),0,0);
    (**(code **)(*DAT_140c65670 + 0x118))();
  }
  (**(code **)(*DAT_140c65670 + 0x178))
            (DAT_140c65670,*(undefined8 *)(*(longlong *)(*param_1 + 0x10) + 0x80),1);
  FUN_140384480(param_1,param_2,param_3,param_4);
  return 0;
}



==== FUN_14038b6d0 @ 14038b6d0 size 1645 ====
CALLERS: FUN_14038c650 FUN_14038d560
CALLEES: FUN_140367870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14038b6d0(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar12;
  float fVar14;
  float fVar15;
  float fVar17;
  int iVar18;
  int iVar19;
  undefined1 auVar20 [12];
  undefined1 auVar21 [12];
  uint uVar22;
  float *pfVar23;
  float *pfVar24;
  int iVar25;
  int iVar26;
  undefined1 (*pauVar27) [16];
  longlong *plVar28;
  longlong lVar29;
  float fVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined8 local_d8;
  ulonglong uStack_d0;
  undefined8 local_c8;
  ulonglong uStack_c0;
  float local_b8;
  float fStack_b0;
  float local_a8;
  float fStack_a0;
  float fVar6;
  float fVar11;
  float fVar13;
  float fVar16;
  
  lVar29 = 4;
  pfVar23 = (float *)(param_1 + 0x214);
  pauVar27 = (undefined1 (*) [16])(param_1 + 0x100);
  auVar42 = _DAT_140c798c0;
  auVar43 = _DAT_140c798d0;
  do {
    auVar21 = *(undefined1 (*) [12])(param_1 + 0x60);
    auVar20 = *(undefined1 (*) [12])(param_1 + 0x60);
    auVar36._0_4_ = *(float *)(param_1 + 0x30);
    fVar41 = pfVar23[-5];
    fVar3 = pfVar23[-1];
    local_d8._0_4_ = auVar20._0_4_;
    local_c8._0_4_ = auVar21._0_4_;
    auVar34._0_4_ = fVar3;
    auVar35._0_4_ = fVar41;
    if (0.0 < auVar36._0_4_) {
      auVar34._0_4_ = fVar41;
      auVar35._0_4_ = fVar3;
    }
    auVar33._0_4_ = *(float *)(param_1 + 0x40);
    fVar40 = pfVar23[-4];
    fVar4 = *pfVar23;
    fVar5 = fVar40;
    fVar6 = fVar4;
    if (0.0 < auVar33._0_4_) {
      fVar5 = fVar4;
      fVar6 = fVar40;
    }
    fVar39 = pfVar23[-3];
    fVar7 = pfVar23[1];
    fVar8 = *(float *)(param_1 + 0x50);
    fVar9 = fVar39;
    fVar38 = fVar7;
    if (0.0 < fVar8) {
      fVar9 = fVar7;
      fVar38 = fVar39;
    }
    local_d8._4_4_ = auVar20._4_4_;
    fVar30 = *(float *)(param_1 + 0x34);
    fVar11 = fVar41;
    fVar37 = fVar3;
    if (0.0 < fVar30) {
      fVar11 = fVar3;
      fVar37 = fVar41;
    }
    fVar10 = *(float *)(param_1 + 0x44);
    local_c8._4_4_ = auVar21._4_4_;
    fVar12 = fVar40;
    fVar13 = fVar4;
    if (0.0 < fVar10) {
      fVar12 = fVar4;
      fVar13 = fVar40;
    }
    fVar14 = *(float *)(param_1 + 0x54);
    fVar15 = fVar7;
    fVar16 = fVar39;
    if (0.0 < fVar14) {
      fVar15 = fVar39;
      fVar16 = fVar7;
    }
    fVar17 = *(float *)(param_1 + 0x38);
    fVar41 = fVar41 * fVar17;
    uStack_d0._0_4_ = auVar20._8_4_;
    uStack_c0._0_4_ = auVar21._8_4_;
    local_c8 = CONCAT44(local_c8._4_4_ + fVar11 * fVar30 + fVar12 * fVar10 + fVar16 * fVar14,
                        (float)local_c8 + auVar36._0_4_ * auVar35._0_4_ + fVar5 * auVar33._0_4_ +
                        fVar9 * fVar8);
    local_d8 = CONCAT44(local_d8._4_4_ + fVar37 * fVar30 + fVar13 * fVar10 + fVar15 * fVar14,
                        (float)local_d8 + auVar36._0_4_ * auVar34._0_4_ + fVar6 * auVar33._0_4_ +
                        fVar38 * fVar8);
    auVar36._0_4_ = fVar3 * fVar17;
    if (0.0 < fVar17) {
      auVar36._0_4_ = fVar41;
      fVar41 = fVar3 * fVar17;
    }
    fVar3 = *(float *)(param_1 + 0x48);
    fVar40 = fVar40 * fVar3;
    auVar34._0_4_ = fVar4 * fVar3;
    if (0.0 < fVar3) {
      auVar34._0_4_ = fVar40;
      fVar40 = fVar4 * fVar3;
    }
    fVar3 = *(float *)(param_1 + 0x58);
    fVar39 = fVar39 * fVar3;
    auVar35._0_4_ = fVar7 * fVar3;
    if (0.0 < fVar3) {
      auVar35._0_4_ = fVar39;
      fVar39 = fVar7 * fVar3;
    }
    uStack_c0 = (ulonglong)(uint)((float)uStack_c0 + fVar41 + fVar40 + fVar39);
    uStack_d0 = (ulonglong)(uint)((float)uStack_d0 + auVar36._0_4_ + auVar34._0_4_ + auVar35._0_4_);
    pfVar24 = pfVar23 + 0x10;
    *(undefined8 *)*pauVar27 = local_d8;
    *(ulonglong *)(*pauVar27 + 8) = uStack_d0;
    *(undefined8 *)pauVar27[1] = local_c8;
    *(ulonglong *)(pauVar27[1] + 8) = uStack_c0;
    auVar36._0_4_ = *(float *)(param_1 + 0x50);
    fVar41 = *(float *)(param_1 + 0x54);
    fVar3 = *(float *)(param_1 + 0x58);
    auVar34._0_4_ = *(float *)(param_1 + 0x5c);
    auVar35._0_4_ = *(float *)(param_1 + 0x40);
    auVar33._0_4_ = *(float *)(param_1 + 0x44);
    fVar40 = *(float *)(param_1 + 0x48);
    fVar4 = *(float *)(param_1 + 0x30);
    fVar5 = *(float *)(param_1 + 0x34);
    fVar6 = *(float *)(param_1 + 0x38);
    fVar39 = *(float *)(param_1 + 0x3c);
    fVar37 = auVar36._0_4_ * auVar36._0_4_ + fVar41 * fVar41 + fVar3 * fVar3;
    fVar30 = auVar35._0_4_ * auVar35._0_4_ + auVar33._0_4_ * auVar33._0_4_ + fVar40 * fVar40;
    fVar7 = pfVar23[3];
    fVar8 = pfVar23[4];
    fVar9 = pfVar23[5];
    fVar38 = fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6;
    if (fVar38 <= fVar30) {
      fVar38 = fVar30;
    }
    if (fVar38 <= fVar37) {
      fVar38 = fVar37;
    }
    auVar31._0_4_ = fVar8 * auVar35._0_4_;
    auVar31._4_4_ = fVar8 * auVar33._0_4_;
    auVar31._8_4_ = fVar8 * fVar40;
    auVar31._12_4_ = fVar8 * *(float *)(param_1 + 0x4c);
    auVar32 = sqrtps(auVar31,ZEXT416((uint)fVar38));
    auVar35._0_4_ = *(float *)(param_1 + 100);
    auVar33._0_4_ = *(float *)(param_1 + 0x68);
    fVar40 = *(float *)(param_1 + 0x6c);
    pfVar23[-0x3d] =
         fVar7 * fVar4 + auVar31._0_4_ + fVar9 * auVar36._0_4_ + *(float *)(param_1 + 0x60);
    pfVar23[-0x3c] = fVar7 * fVar5 + auVar31._4_4_ + fVar9 * fVar41 + auVar35._0_4_;
    pfVar23[-0x3b] = fVar7 * fVar6 + auVar31._8_4_ + fVar9 * fVar3 + auVar33._0_4_;
    pfVar23[-0x3a] = fVar7 * fVar39 + auVar31._12_4_ + fVar9 * auVar34._0_4_ + fVar40;
    pfVar23[-0x39] = auVar32._0_4_ * pfVar23[7];
    fVar41 = DAT_140c43fb8;
    auVar36._0_4_ = DAT_140b7a178;
    auVar43 = maxps(auVar43,pauVar27[1]);
    auVar42 = minps(auVar42,*pauVar27);
    lVar29 = lVar29 + -1;
    pfVar23 = pfVar24;
    pauVar27 = pauVar27 + 4;
  } while (lVar29 != 0);
  fVar3 = *(float *)(param_1 + 0x50);
  auVar34._0_4_ = *(float *)(param_1 + 0x54);
  auVar35._0_4_ = *(float *)(param_1 + 0x58);
  auVar33._0_4_ = *(float *)(param_1 + 0x40);
  fVar40 = *(float *)(param_1 + 0x44);
  fVar4 = *(float *)(param_1 + 0x48);
  fVar5 = *(float *)(param_1 + 0x30);
  fVar6 = *(float *)(param_1 + 0x34);
  fVar39 = *(float *)(param_1 + 0x38);
  fVar37 = fVar3 * fVar3 + auVar34._0_4_ * auVar34._0_4_ + auVar35._0_4_ * auVar35._0_4_;
  fVar30 = auVar33._0_4_ * auVar33._0_4_ + fVar40 * fVar40 + fVar4 * fVar4;
  fVar7 = *(float *)(param_1 + 800);
  fVar8 = *(float *)(param_1 + 0x324);
  fVar9 = *(float *)(param_1 + 0x328);
  fVar38 = fVar5 * fVar5 + fVar6 * fVar6 + fVar39 * fVar39;
  if (fVar38 <= fVar30) {
    fVar38 = fVar30;
  }
  if (fVar38 <= fVar37) {
    fVar38 = fVar37;
  }
  auVar32._0_4_ = fVar8 * auVar33._0_4_;
  auVar32._4_4_ = fVar8 * fVar40;
  auVar32._8_4_ = fVar8 * fVar4;
  auVar32._12_4_ = fVar8 * *(float *)(param_1 + 0x4c);
  local_b8 = auVar42._0_4_;
  auVar33 = sqrtps(auVar32,ZEXT416((uint)fVar38));
  local_b8 = local_b8 * DAT_140c43fb8;
  *(float *)(param_1 + 0x300) =
       fVar7 * fVar5 + auVar32._0_4_ + fVar9 * fVar3 + *(float *)(param_1 + 0x60);
  *(float *)(param_1 + 0x304) =
       fVar7 * fVar6 + auVar32._4_4_ + fVar9 * auVar34._0_4_ + *(float *)(param_1 + 100);
  *(float *)(param_1 + 0x308) =
       fVar7 * fVar39 + auVar32._8_4_ + fVar9 * auVar35._0_4_ + *(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x30c) =
       fVar7 * *(float *)(param_1 + 0x3c) + auVar32._12_4_ + fVar9 * *(float *)(param_1 + 0x5c) +
       *(float *)(param_1 + 0x6c);
  fVar3 = DAT_140b79e48;
  local_b8 = local_b8 + DAT_140b79e48;
  *(float *)(param_1 + 0x310) = auVar33._0_4_ * *(float *)(param_1 + 0x330);
  auVar34._0_4_ = local_b8 * auVar36._0_4_;
  iVar25 = (int)auVar34._0_4_;
  if ((iVar25 != -0x80000000) && ((float)iVar25 != auVar34._0_4_)) {
    auVar34._4_4_ = auVar34._0_4_;
    auVar34._8_8_ = 0;
    uVar22 = movmskps((int)pfVar24,auVar34);
    pfVar24 = (float *)(ulonglong)(uVar22 & 1);
    auVar34._0_4_ = (float)(int)(iVar25 - (uVar22 & 1));
  }
  uVar22 = (uint)pfVar24;
  fStack_b0 = auVar42._8_4_;
  auVar35._0_4_ = (fStack_b0 * fVar41 + fVar3) * auVar36._0_4_;
  iVar25 = (int)auVar35._0_4_;
  if ((iVar25 != -0x80000000) && ((float)iVar25 != auVar35._0_4_)) {
    auVar35._4_4_ = auVar35._0_4_;
    auVar35._8_8_ = 0;
    uVar22 = movmskps(uVar22,auVar35);
    uVar22 = uVar22 & 1;
    auVar35._0_4_ = (float)(int)(iVar25 - uVar22);
  }
  local_a8 = auVar43._0_4_;
  auVar33._0_4_ = (local_a8 * fVar41 + fVar3) * auVar36._0_4_;
  iVar25 = (int)auVar33._0_4_;
  if ((iVar25 != -0x80000000) && ((float)iVar25 != auVar33._0_4_)) {
    auVar33._4_4_ = auVar33._0_4_;
    auVar33._8_8_ = 0;
    uVar22 = movmskps(uVar22,auVar33);
    uVar22 = uVar22 & 1;
    auVar33._0_4_ = (float)(int)(iVar25 - uVar22);
  }
  fStack_a0 = auVar43._8_4_;
  iVar25 = (int)auVar33._0_4_ + 1;
  auVar36._0_4_ = (fStack_a0 * fVar41 + fVar3) * auVar36._0_4_;
  iVar26 = (int)auVar36._0_4_;
  if ((iVar26 != -0x80000000) && ((float)iVar26 != auVar36._0_4_)) {
    auVar36._4_4_ = auVar36._0_4_;
    auVar36._8_8_ = 0;
    uVar22 = movmskps(uVar22,auVar36);
    auVar36._0_4_ = (float)(int)(iVar26 - (uVar22 & 1));
  }
  piVar1 = (int *)(param_1 + 0x340);
  *piVar1 = (int)auVar34._0_4_;
  *(int *)(param_1 + 0x344) = (int)auVar35._0_4_;
  *(int *)(param_1 + 0x348) = iVar25;
  iVar26 = (int)auVar36._0_4_ + 1;
  *(int *)(param_1 + 0x34c) = iVar26;
  if (DAT_140c445a0 < iVar25) {
    iVar25 = DAT_140c445a0;
  }
  if (DAT_140c445a4 < iVar26) {
    iVar26 = DAT_140c445a4;
  }
  iVar18 = *piVar1;
  if (*piVar1 < DAT_140c44598) {
    iVar18 = DAT_140c44598;
  }
  iVar19 = *(int *)(param_1 + 0x344);
  if (*(int *)(param_1 + 0x344) < DAT_140c4459c) {
    iVar19 = DAT_140c4459c;
  }
  if ((iVar18 < iVar25) && (iVar19 < iVar26)) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = iVar18;
      *(int *)(param_1 + 0x344) = iVar19;
      *(int *)(param_1 + 0x348) = iVar25;
      *(int *)(param_1 + 0x34c) = iVar26;
    }
  }
  else {
    *piVar1 = DAT_140c784c0;
    *(undefined4 *)(param_1 + 0x344) = DAT_140c784c4;
    *(undefined4 *)(param_1 + 0x348) = DAT_140c784c8;
    *(undefined4 *)(param_1 + 0x34c) = DAT_140c784cc;
  }
  if (*(int *)(param_1 + 0xe4) != 0) {
    FUN_140367870(*(undefined8 *)(param_1 + 0x10),param_1 + 0x180);
  }
  if (*(longlong *)(param_1 + 0x410) == 0) {
    plVar2 = (longlong *)(param_1 + 0x418);
    plVar28 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x1490);
    *(longlong **)(param_1 + 0x410) = plVar28;
    *plVar2 = *plVar28;
    *plVar28 = param_1;
    if (*plVar2 != 0) {
      *(longlong **)(*plVar2 + 0x410) = plVar2;
    }
  }
  return;
}



==== FUN_14038bdb0 @ 14038bdb0 size 684 ====
CALLERS: FUN_14038bd40 FUN_140356160
CALLEES: FUN_1403762e0 FUN_14018b280 FUN_14035bec0

void FUN_14038bdb0(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint *puVar6;
  int iVar7;
  longlong *plVar8;
  uint *puVar9;
  ulonglong uVar10;
  longlong *plVar11;
  int local_res8;
  int local_resc;
  longlong *local_res10;
  
  if ((*(longlong *)(param_1 + 0x39c) != *(longlong *)(param_1 + 0x340)) ||
     (*(longlong *)(param_1 + 0x3a4) != *(longlong *)(param_1 + 0x348))) {
    if (*(longlong *)(param_1 + 0x3b0) != 0) {
      FUN_1403762e0();
    }
    uVar10 = 0;
    *(undefined8 *)(param_1 + 0x3b0) = 0;
    *(undefined4 *)(param_1 + 0x39c) = *(undefined4 *)(param_1 + 0x340);
    *(undefined4 *)(param_1 + 0x3a0) = *(undefined4 *)(param_1 + 0x344);
    *(undefined4 *)(param_1 + 0x3a4) = *(undefined4 *)(param_1 + 0x348);
    *(undefined4 *)(param_1 + 0x3a8) = *(undefined4 *)(param_1 + 0x34c);
    if (*(undefined8 **)(param_1 + 0x400) != (undefined8 *)0x0) {
      **(undefined8 **)(param_1 + 0x400) = *(undefined8 *)(param_1 + 0x408);
    }
    plVar2 = (longlong *)(param_1 + 0x408);
    if (*plVar2 != 0) {
      *(undefined8 *)(*plVar2 + 0x400) = *(undefined8 *)(param_1 + 0x400);
    }
    *(undefined8 *)(param_1 + 0x400) = 0;
    *plVar2 = 0;
    if (*(int *)(param_1 + 0x39c) < *(int *)(param_1 + 0x3a4)) {
      if (*(int *)(param_1 + 0x3a0) < *(int *)(param_1 + 0x3a8)) {
        uVar3 = (*(int *)(param_1 + 0x3a4) - *(int *)(param_1 + 0x39c)) *
                (*(int *)(param_1 + 0x3a8) - *(int *)(param_1 + 0x3a0));
        if (uVar3 < 0x100) {
          uVar4 = SUB168(ZEXT816(0x20) * ZEXT416(uVar3),0);
          if (SUB168(ZEXT816(0x20) * ZEXT416(uVar3),8) != 0) {
            uVar4 = 0xffffffffffffffff;
          }
          lVar5 = uVar4 + 8;
          if (0xfffffffffffffff7 < uVar4) {
            lVar5 = -1;
          }
          puVar6 = (uint *)FUN_14018b280(lVar5,0);
          if (puVar6 == (uint *)0x0) {
            puVar9 = (uint *)0x0;
          }
          else {
            iVar7 = uVar3 - 1;
            *puVar6 = uVar3;
            puVar9 = puVar6 + 2;
            if (-1 < iVar7) {
              puVar6 = puVar6 + 6;
              do {
                iVar7 = iVar7 + -1;
                puVar6[0] = 0;
                puVar6[1] = 0;
                puVar6[2] = 0;
                puVar6[3] = 0;
                puVar6[-4] = 0;
                puVar6[-3] = 0;
                puVar6 = puVar6 + 8;
              } while (-1 < iVar7);
            }
          }
          *(uint **)(param_1 + 0x3b0) = puVar9;
          local_resc = *(int *)(param_1 + 0x3a0);
          if (local_resc < *(int *)(param_1 + 0x3a8)) {
            do {
              local_res8 = *(int *)(param_1 + 0x39c);
              uVar4 = uVar10;
              if (local_res8 < *(int *)(param_1 + 0x3a4)) {
                do {
                  local_res10 = (longlong *)0x0;
                  if ((((DAT_140c44530 <= local_res8) && (local_res8 < DAT_140c44538)) &&
                      (DAT_140c44534 <= local_resc)) && (local_resc < DAT_140c4453c)) {
                    FUN_14035bec0(*(undefined8 *)(param_1 + 0x10),&local_res8,&local_res10);
                  }
                  plVar2 = local_res10;
                  uVar10 = (ulonglong)((int)uVar4 + 1);
                  plVar11 = (longlong *)(uVar4 * 0x20 + *(longlong *)(param_1 + 0x3b0));
                  *plVar11 = (longlong)local_res10;
                  plVar11[1] = param_1;
                  (**(code **)*local_res10)(local_res10);
                  plVar8 = (longlong *)(*plVar11 + 0x40);
                  if (plVar11[2] == 0) {
                    plVar11[2] = (longlong)plVar8;
                    plVar1 = plVar11 + 3;
                    *plVar1 = *plVar8;
                    *plVar8 = (longlong)plVar11;
                    if (*plVar1 != 0) {
                      *(longlong **)(*plVar1 + 0x10) = plVar1;
                    }
                  }
                  (**(code **)(*plVar2 + 8))(plVar2);
                  local_res8 = local_res8 + 1;
                  uVar4 = uVar10;
                } while (local_res8 < *(int *)(param_1 + 0x3a4));
              }
              local_resc = local_resc + 1;
            } while (local_resc < *(int *)(param_1 + 0x3a8));
          }
        }
        else {
          plVar8 = (longlong *)(*(longlong *)(param_1 + 0x10) + 0x1488);
          *(longlong **)(param_1 + 0x400) = plVar8;
          *plVar2 = *plVar8;
          *plVar8 = param_1;
          if (*plVar2 != 0) {
            *(longlong **)(*plVar2 + 0x400) = plVar2;
            return;
          }
        }
      }
    }
  }
  return;
}



==== FUN_14038c490 @ 14038c490 size 114 ====
CALLERS: FUN_14038ce10
CALLEES: FUN_14038c430

void FUN_14038c490(longlong *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  longlong *plVar2;
  
  if ((param_1[4] != 0) && (plVar2 = param_1, iVar1 = FUN_14038c430(param_1,param_3), iVar1 != 0)) {
    (**(code **)(*plVar2 + 0x20))();
    (**(code **)(*(longlong *)param_1[4] + 0x528))((longlong *)param_1[4],param_2,iVar1,param_4);
  }
  return;
}



==== FUN_14038c7a0 @ 14038c7a0 size 41 ====
CALLERS:
CALLEES:

longlong * FUN_14038c7a0(longlong *param_1)

{
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x20))(param_1,local_18);
  return param_1 + 0x68;
}



==== FUN_14038c850 @ 14038c850 size 176 ====
CALLERS:
CALLEES:

longlong * FUN_14038c850(longlong *param_1,longlong *param_2,int param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 local_18 [4];
  
  local_18[0] = 0xffffffff;
  (**(code **)(*param_1 + 0x20))(param_1,local_18);
  if (param_3 == 0) {
    plVar1 = (longlong *)param_1[4];
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x498))(plVar1,param_2);
      return param_2;
    }
  }
  else if ((param_3 == 1) && (plVar1 = (longlong *)param_1[4], plVar1 != (longlong *)0x0)) {
    (**(code **)(*plVar1 + 0x4b0))(plVar1,param_2);
    return param_2;
  }
  lVar2 = (param_1 + ((longlong)param_3 + 8) * 8)[1];
  *param_2 = param_1[((longlong)param_3 + 8) * 8];
  param_2[1] = lVar2;
  lVar2 = (param_1 + ((longlong)param_3 + 8) * 8 + 2)[1];
  param_2[2] = param_1[((longlong)param_3 + 8) * 8 + 2];
  param_2[3] = lVar2;
  return param_2;
}



==== FUN_14038d9a0 @ 14038d9a0 size 84 ====
CALLERS:
CALLEES: FUN_140367870

void FUN_14038d9a0(longlong *param_1)

{
  int iVar1;
  
  if ((longlong *)param_1[4] != (longlong *)0x0) {
    iVar1 = (**(code **)(*(longlong *)param_1[4] + 0x538))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x120))(param_1);
      if ((iVar1 != 0) && (param_1[0x92] == 0)) {
        FUN_140367870(param_1[2],param_1 + 0x30);
        return;
      }
    }
  }
  return;
}



==== FUN_14038ff70 @ 14038ff70 size 233 ====
CALLERS: FUN_14038dc80 FUN_14038db00 FUN_1403904c0
CALLEES:

void FUN_14038ff70(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  
  if (*(undefined8 **)(param_1 + 0x10) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x18);
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x10) = *(undefined8 *)(param_1 + 0x10);
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0x20) = *(undefined8 *)(param_1 + 0x28);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x20) = *(undefined8 *)(param_1 + 0x20);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (*(longlong *)(lVar2 + 0x378) == 0) {
    plVar1 = (longlong *)(lVar2 + 0x380);
    plVar3 = (longlong *)(*(longlong *)(lVar2 + 0x10) + 0x14e8);
    *(longlong **)(lVar2 + 0x378) = plVar3;
    *plVar1 = *plVar3;
    *plVar3 = lVar2;
    if (*plVar1 != 0) {
      *(longlong **)(*plVar1 + 0x378) = plVar1;
    }
  }
  if (*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0x20) = *(undefined8 *)(param_1 + 0x28);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x20) = *(undefined8 *)(param_1 + 0x20);
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (*(undefined8 **)(param_1 + 0x10) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x18);
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x10) = *(undefined8 *)(param_1 + 0x10);
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  return;
}


