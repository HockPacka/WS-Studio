
==== FUN_140331990 @ 140331990 size 2060 ====
CALLERS: FUN_1403321a0
CALLEES: FUN_14018b900 FUN_140336d60 FUN_1400a71c0 FUN_1403370c0 FUN_14018ee90 FUN_140334a70 FUN_140335f10 FUN_140333790 FUN_140334d90 FUN_1403374e0 FUN_140335ec0 FUN_1401a3130 FUN_1401a2e50

undefined8 FUN_140331990(longlong *param_1,longlong param_2,longlong param_3)

{
  ulonglong *puVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined8 local_res18;
  ulonglong local_res20;
  undefined8 in_stack_ffffffffffffff48;
  undefined4 uVar12;
  undefined8 uVar11;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar14;
  undefined8 uVar13;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar15;
  undefined8 in_stack_ffffffffffffff60;
  undefined4 uVar16;
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar17;
  undefined8 local_88;
  ulonglong local_80;
  undefined1 local_78 [8];
  longlong local_70;
  undefined1 local_58 [8];
  longlong local_50;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  local_res18 = CONCAT44(local_res18._4_4_,*(int *)(param_3 + 8));
  if (*(longlong *)(param_3 + 0x10) == 0) {
LAB_140331a31:
    iVar3 = FUN_140336d60(param_3,&local_res20,0x20);
    if (iVar3 < 0) {
      return 0xc;
    }
    uVar10 = (uint)local_res20;
  }
  else {
    puVar1 = *(ulonglong **)(param_3 + 0x18);
    lVar6 = *(longlong *)(param_3 + 0x20);
    if ((ulonglong)
        ((*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x20) * 8 + (longlong)puVar1 * -8) - lVar6)
        < 0x40) goto LAB_140331a31;
    uVar10 = (uint)(*puVar1 >> ((byte)lVar6 & 0x3f));
    if (0x40 < (lVar6 + 0x27U & 0xfffffffffffffff8)) {
      uVar10 = uVar10 | (uint)(byte)puVar1[1] << (0x40 - (byte)lVar6 & 0x3f);
    }
    *(ulonglong *)(param_3 + 0x20) = (ulonglong)((uint)lVar6 & 7);
    lVar6 = (lVar6 + 0x20U >> 3) + (longlong)puVar1;
    *(longlong *)(param_3 + 0x18) = lVar6;
    *(int *)(param_3 + 8) = ((int)lVar6 - (int)puVar1) + *(int *)(param_3 + 8);
  }
  if (*(longlong *)(param_3 + 0x10) == 0) {
LAB_140331ac3:
    iVar3 = FUN_140336d60(param_3,&local_res20,0x10);
    uVar7 = local_res20;
  }
  else {
    lVar6 = *(longlong *)(param_3 + 0x18);
    if ((ulonglong)
        ((*(longlong *)(*(longlong *)(param_3 + 0x10) + 0x20) * 8 + lVar6 * -8) -
        *(longlong *)(param_3 + 0x20)) < 0x40) goto LAB_140331ac3;
    uVar7 = FUN_1400a71c0(param_3 + 0x18,(longlong *)(param_3 + 0x20),0x10);
    *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + (*(int *)(param_3 + 0x18) - (int)lVar6);
    iVar3 = 0;
  }
  if (iVar3 < 0) {
    return 0xc;
  }
  if (*(int *)(param_2 + 0x20) == 1) {
    uVar7 = (ulonglong)((uint)uVar7 | 0x10000);
  }
  iVar3 = (int)uVar7;
  lVar6 = (**(code **)(*param_1 + 0x130))(param_1,uVar7 & 0xffffffff);
  if (lVar6 == 0) {
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_58,"Message Id #%d");
      puVar8 = local_58;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_58,*(undefined4 *)(param_2 + 0x318));
    }
    uVar9 = *(undefined8 *)(puVar8 + 8);
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_78,"Message Id #%d",uVar7 & 0xffffffff);
      puVar8 = local_78;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_78,uVar7 & 0xffffffff);
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar11 = *(undefined8 *)(puVar8 + 8);
    if (*(char *)(lVar6 + 200) == '\0') {
      FUN_140334d90();
    }
    local_res20 = 0x141debc30;
    FUN_1401a2e50(0xb,0,&local_res20,lVar6 + 200,CONCAT44(uVar12,*(undefined4 *)(param_2 + 0x10)),
                  uVar11,CONCAT44(uVar15,uVar10),CONCAT44(uVar16,*(undefined4 *)(param_2 + 0x318)),
                  uVar9);
    lVar6 = local_50;
    if (local_70 != 0) {
      FUN_14018b900(local_70,0);
      lVar6 = local_50;
    }
  }
  else {
    uVar4 = FUN_140335ec0(uVar7 & 0xffffffff);
    local_res20 = CONCAT44(local_res20._4_4_,uVar4);
    local_80 = (ulonglong)((float)uVar4 * DAT_140b79f58);
    if (uVar10 <= uVar4) {
      if ((uint)(longlong)((float)uVar4 * DAT_140b79eb0) < uVar10) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        lVar2 = *(longlong *)(param_2 + 0x18);
        local_88 = *(undefined8 *)(puVar8 + 8);
        uVar9 = local_88;
        if (*(char *)(lVar2 + 200) == '\0') {
          FUN_140334d90();
          uVar9 = local_88;
        }
        local_88 = 0x141debcc0;
        uVar13 = CONCAT44(uVar14,(undefined4)local_res20);
        uVar11 = CONCAT44(uVar12,uVar10);
        FUN_1401a2e50(0xb,1,&local_88,lVar2 + 200,uVar11,uVar13,uVar9);
        uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar15 = (undefined4)((ulonglong)uVar9 >> 0x20);
        uVar12 = (undefined4)((ulonglong)uVar11 >> 0x20);
        if (local_50 != 0) {
          FUN_14018b900(local_50,0);
        }
      }
      *(int *)(param_2 + 0x318) = iVar3;
      FUN_140334a70(lVar6 + 0x50,uVar10,2);
      param_1[0xc] = param_1[10];
      param_1[8] = local_80 & 0xffffffff;
      puVar8 = (undefined1 *)FUN_1403374e0(param_1 + 8,*(undefined8 *)(lVar6 + 8));
      if (puVar8 == (undefined1 *)0x0) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        local_res20 = 0x141debfb0;
        FUN_1401a3130(0xb,0,&local_res20,uVar7 & 0xffffffff,*(undefined8 *)(puVar8 + 8),
                      *(undefined8 *)(lVar6 + 8));
        if (local_50 != 0) {
          FUN_14018b900(local_50,0);
        }
        iVar3 = *(int *)(param_3 + 8);
        if (*(longlong *)(param_3 + 0x20) != 0) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = iVar3 - (int)local_res18;
        if ((uVar4 != 0) && (uVar4 < uVar10)) {
          FUN_1403370c0(param_3,uVar10 - uVar4);
        }
        return 4;
      }
      if (*(code **)(lVar6 + 0x20) == (code *)0x0) {
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        local_res20 = 0x141debf40;
        FUN_1401a3130(0xb,0,&local_res20,uVar7 & 0xffffffff,*(undefined8 *)(puVar8 + 8));
        if (local_50 != 0) {
          FUN_14018b900(local_50,0);
        }
        iVar3 = *(int *)(param_3 + 8);
        if (*(longlong *)(param_3 + 0x20) != 0) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = iVar3 - (int)local_res18;
        if ((uVar4 != 0) && (uVar4 < uVar10)) {
          FUN_1403370c0(param_3,uVar10 - uVar4);
        }
        return 0xb;
      }
      iVar5 = (**(code **)(lVar6 + 0x20))(param_3,param_1 + 8,puVar8);
      if (iVar5 < 0) {
        iVar3 = *(int *)(param_3 + 8);
        if (*(longlong *)(param_3 + 0x20) != 0) {
          iVar3 = iVar3 + 1;
        }
        uVar4 = iVar3 - (int)local_res18;
        if ((uVar4 != 0) && (uVar4 < uVar10)) {
          FUN_1403370c0(param_3,uVar10 - uVar4);
        }
        if (DAT_140c65828 == 0) {
          FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
          puVar8 = local_58;
        }
        else {
          puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
        }
        lVar6 = *(longlong *)(param_2 + 0x18);
        uVar9 = *(undefined8 *)(puVar8 + 8);
        if (*(char *)(lVar6 + 200) == '\0') {
          FUN_140334d90();
        }
        local_res18 = 0x141dec040;
        FUN_1401a2e50(0xb,0,&local_res18,lVar6 + 200,uVar9,CONCAT44(uVar14,uVar4),
                      CONCAT44(uVar15,uVar10));
        if (local_50 == 0) {
          return 8;
        }
        FUN_14018b900(local_50,0);
        return 8;
      }
      if (iVar3 == 0) {
        local_res18 = CONCAT71(local_res18._1_7_,*puVar8);
        (**(code **)(*param_1 + 0xf0))(param_1,*(undefined4 *)(param_2 + 0x10),1,&local_res18);
      }
      else if (iVar3 == 1) {
        FUN_140333790(param_1,*(undefined4 *)(param_2 + 0x10),puVar8);
      }
      else if (iVar3 != 2) {
        lVar6 = *(longlong *)param_1[0xf];
        if (*(int *)(param_2 + 0x20) == 0) {
          iVar3 = (**(code **)(lVar6 + 0x10))();
          if (iVar3 < 0) {
            if (DAT_140c65828 == 0) {
              FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
              puVar8 = local_58;
            }
            else {
              puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
            }
            lVar6 = *(longlong *)(param_2 + 0x18);
            uVar9 = *(undefined8 *)(puVar8 + 8);
            if (*(char *)(lVar6 + 200) == '\0') {
              FUN_140334d90();
            }
            local_res18 = 0x141dec018;
            FUN_1401a2e50(0xb,0,&local_res18,lVar6 + 200,uVar9);
LAB_14033212d:
            if (local_50 != 0) {
              FUN_14018b900(local_50,0);
            }
            return 0xe;
          }
        }
        else {
          iVar3 = (**(code **)(lVar6 + 0x18))
                            ((longlong *)param_1[0xf],param_1,*(undefined4 *)(param_2 + 0x10),
                             *(int *)(param_2 + 0x20),CONCAT44(uVar12,iVar3),puVar8);
          if (iVar3 < 0) {
            if (DAT_140c65828 == 0) {
              FUN_14018ee90(local_78,"Message Id #%d",uVar7 & 0xffffffff);
              puVar8 = local_78;
            }
            else {
              puVar8 = (undefined1 *)FUN_140335f10(local_78,uVar7 & 0xffffffff);
            }
            lVar6 = *(longlong *)(param_2 + 0x18);
            uVar9 = *(undefined8 *)(puVar8 + 8);
            if (*(char *)(lVar6 + 200) == '\0') {
              FUN_140334d90();
            }
            local_res18 = 0x141dec0d8;
            FUN_1401a2e50(0xb,0,&local_res18,lVar6 + 200,uVar9);
            local_50 = local_70;
            goto LAB_14033212d;
          }
        }
      }
      return 0;
    }
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_78,"Message Id #%d");
      puVar8 = local_78;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_78,*(undefined4 *)(param_2 + 0x318));
    }
    uVar9 = *(undefined8 *)(puVar8 + 8);
    if (DAT_140c65828 == 0) {
      FUN_14018ee90(local_58,"Message Id #%d",uVar7 & 0xffffffff);
      puVar8 = local_58;
    }
    else {
      puVar8 = (undefined1 *)FUN_140335f10(local_58,uVar7 & 0xffffffff);
    }
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar11 = *(undefined8 *)(puVar8 + 8);
    if (*(char *)(lVar6 + 200) == '\0') {
      FUN_140334d90();
    }
    local_88 = 0x141debd30;
    FUN_1401a2e50(0xb,0,&local_88,lVar6 + 200,CONCAT44(uVar12,*(undefined4 *)(param_2 + 0x10)),
                  CONCAT44(uVar14,uVar10),CONCAT44(uVar15,(undefined4)local_res20),uVar11,
                  CONCAT44(uVar17,*(undefined4 *)(param_2 + 0x318)),uVar9);
    lVar6 = local_70;
    if (local_50 != 0) {
      FUN_14018b900(local_50,0);
      lVar6 = local_70;
    }
  }
  if (lVar6 != 0) {
    FUN_14018b900(lVar6,0);
  }
  iVar3 = *(int *)(param_3 + 8);
  if (*(longlong *)(param_3 + 0x20) != 0) {
    iVar3 = iVar3 + 1;
  }
  uVar4 = iVar3 - (int)local_res18;
  if ((uVar4 != 0) && (uVar4 < uVar10)) {
    FUN_1403370c0(param_3,uVar10 - uVar4);
    return 8;
  }
  return 8;
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



==== FUN_140332f60 @ 140332f60 size 608 ====
CALLERS: FUN_140333430
CALLEES: FUN_1401c5100 FUN_1401c4fb0 FUN_140332ae0 FUN_14018cdf0 FUN_1401a2e50 QueryPerformanceCounter FUN_140337f20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140332f60(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  LARGE_INTEGER local_res8;
  
  if (DAT_140c796cc == 0) {
    if ((uint)(DAT_140c636a8 - _DAT_140c785b0) < 0x7531) {
      FUN_1401c4fb0(0);
    }
    else {
      DAT_140c796cc = 1;
    }
  }
  QueryPerformanceCounter(&local_res8);
  lVar7 = local_res8.QuadPart - _DAT_140c87988;
  QueryPerformanceCounter(&local_res8);
  FUN_14018cdf0();
  lVar3 = param_1[0x1e];
  do {
    do {
      lVar5 = lVar3;
      if (lVar5 == 0) {
        QueryPerformanceCounter(&local_res8);
        if (DAT_140c796cc == 0) {
          if (30000 < (uint)(DAT_140c636a8 - _DAT_140c785b0)) {
            DAT_140c796cc = 1;
            return;
          }
          FUN_1401c5100(L"H Network_Outgoing",0,(local_res8.QuadPart - lVar7) - _DAT_140c87988,1);
        }
        return;
      }
      plVar1 = (longlong *)(lVar5 + 0x310);
      lVar3 = *plVar1;
      FUN_140332ae0();
      if ((0 < *(int *)(lVar5 + 0x31c)) &&
         (uVar6 = (**(code **)(*param_1 + 0xb0))(param_1,*(undefined4 *)(lVar5 + 0x10)),
         *(uint *)(lVar5 + 0x31c) < uVar6)) {
        local_res8.QuadPart = 0x141debf00;
        FUN_1401a2e50(0xb,0,&local_res8,*(undefined4 *)(lVar5 + 0x10));
        (**(code **)(*param_1 + 0x80))(param_1,*(undefined4 *)(lVar5 + 0x10));
      }
      if (*(longlong **)(lVar5 + 0x308) != (longlong *)0x0) {
        **(longlong **)(lVar5 + 0x308) = *plVar1;
      }
      if (*plVar1 != 0) {
        *(undefined8 *)(*plVar1 + 0x308) = *(undefined8 *)(lVar5 + 0x308);
      }
      *(undefined8 *)(lVar5 + 0x308) = 0;
      *plVar1 = 0;
    } while (**(longlong **)(lVar5 + 0x80) == 0);
    do {
      lVar4 = **(longlong **)(lVar5 + 0x80);
      if ((*(longlong *)(lVar4 + 0x10) == *(longlong *)(lVar4 + 0x20)) &&
         (*(longlong *)(lVar4 + 0x38) == 0)) break;
      param_1[0x1f] = param_1[0x1f] + (*(longlong *)(lVar4 + 0x20) - *(longlong *)(lVar4 + 0x10));
      FUN_140337f20(*(longlong *)(lVar5 + 0x18) + 0x180);
    } while (**(longlong **)(lVar5 + 0x80) != 0);
    iVar2 = *(int *)(lVar5 + 8);
    local_res8 = (LARGE_INTEGER)((LARGE_INTEGER *)(lVar5 + 0x18))->QuadPart;
    if ((undefined8 *)local_res8.QuadPart != (undefined8 *)0x0) {
      (*(code *)**(undefined8 **)local_res8)();
    }
    (**(code **)(*(longlong *)param_1[6] + 0x28))((longlong *)param_1[6],&local_res8,iVar2 == 2);
    plVar1 = *(longlong **)(lVar5 + 0x80);
    if (plVar1 == (longlong *)0x0) {
      *(undefined8 *)(lVar5 + 0x70) = 0;
    }
    else if (*plVar1 == 0) {
      *(undefined8 *)(lVar5 + 0x68) = 0;
    }
    else {
      *(longlong *)(lVar5 + 0x68) = plVar1[1];
    }
  } while( true );
}



==== FUN_140333fc0 @ 140333fc0 size 156 ====
CALLERS: FUN_140332580
CALLEES: FUN_1403355e0 FUN_1403315a0

void FUN_140333fc0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  iVar3 = FUN_1403355e0(param_2 + 0x60,param_3,param_4,local_res10,0);
  if (iVar3 != 1) {
    if (iVar3 != 0) {
      FUN_1403315a0(param_1,*(undefined4 *)(param_2 + 0x10),0xc);
      return;
    }
    if (*(longlong *)(param_2 + 0x308) == 0) {
      plVar1 = (longlong *)(param_1 + 0xf0);
      plVar2 = (longlong *)(param_2 + 0x310);
      *(longlong **)(param_2 + 0x308) = plVar1;
      *plVar2 = *plVar1;
      *plVar1 = param_2;
      if (*plVar2 != 0) {
        *(longlong **)(*plVar2 + 0x308) = plVar2;
      }
    }
  }
  return;
}



==== FUN_14034d010 @ 14034d010 size 3085 ====
CALLERS: FUN_1403721f0 FUN_140350850 FUN_14034cb80
CALLEES: FUN_1400083b0 FUN_14018b900 FUN_1401a4a00 FUN_1401981b0

void FUN_14034d010(undefined8 *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  plVar4 = param_1 + 0x56;
  *param_1 = &PTR_LAB_140b657d8;
  lVar7 = 0xb;
  plVar3 = plVar4;
  do {
    if ((longlong *)*plVar3 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar3 + 8))();
      *plVar3 = 0;
    }
    plVar3 = plVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  FUN_1401981b0();
  lVar7 = param_1[0x71];
  while (lVar7 != 0) {
    lVar7 = param_1[0x71];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x71];
  }
  lVar7 = param_1[0x77];
  while (lVar7 != 0) {
    lVar7 = param_1[0x77];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x77];
  }
  lVar7 = param_1[0x7d];
  while (lVar7 != 0) {
    lVar7 = param_1[0x7d];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x7d];
  }
  lVar7 = param_1[0x83];
  while (lVar7 != 0) {
    lVar7 = param_1[0x83];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x83];
  }
  lVar7 = param_1[0x89];
  while (lVar7 != 0) {
    lVar7 = param_1[0x89];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x89];
  }
  lVar7 = param_1[0x8f];
  while (lVar7 != 0) {
    lVar7 = param_1[0x8f];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x8f];
  }
  lVar7 = param_1[0x95];
  while (lVar7 != 0) {
    lVar7 = param_1[0x95];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x95];
  }
  lVar7 = param_1[0x9b];
  while (lVar7 != 0) {
    lVar7 = param_1[0x9b];
    if (lVar7 != 0) {
      FUN_14018b900(*(undefined8 *)(lVar7 + 8),0);
      if (*(undefined8 **)(lVar7 + 0x10) != (undefined8 *)0x0) {
        **(undefined8 **)(lVar7 + 0x10) = *(undefined8 *)(lVar7 + 0x18);
      }
      if (*(longlong *)(lVar7 + 0x18) != 0) {
        *(undefined8 *)(*(longlong *)(lVar7 + 0x18) + 0x10) = *(undefined8 *)(lVar7 + 0x10);
      }
      *(undefined8 *)(lVar7 + 0x10) = 0;
      *(undefined8 *)(lVar7 + 0x18) = 0;
      FUN_14018b900(lVar7,0);
    }
    lVar7 = param_1[0x9b];
  }
  DAT_140c65878 = 0;
  if (param_1[0x15e] != 0) {
    lVar7 = *(longlong *)(param_1[0x15d] + 8);
    while (lVar7 != 0) {
      FUN_1400083b0(param_1 + 0x15c,*(undefined8 *)(lVar7 + 0x18));
      lVar1 = *(longlong *)(lVar7 + 0x10);
      FUN_14018b900(lVar7,0);
      lVar7 = lVar1;
    }
    *(undefined8 *)(param_1[0x15d] + 0x10) = param_1[0x15d];
    *(undefined8 *)(param_1[0x15d] + 8) = 0;
    *(undefined8 *)(param_1[0x15d] + 0x18) = param_1[0x15d];
    param_1[0x15e] = 0;
  }
  iVar5 = 0xb;
  FUN_14018b900(param_1[0x15d],0);
  puVar2 = param_1 + 0x15c;
  do {
    iVar5 = iVar5 + -1;
    puVar2 = puVar2 + -0x10;
    *puVar2 = &PTR_FUN_140b657e8;
  } while (-1 < iVar5);
  if (param_1[0x9b] != 0) {
    FUN_1401a4a00(param_1 + 0x9b);
  }
  uVar9 = 0;
  uVar8 = 0;
  if (param_1[0x97] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x98] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x98] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x97]);
  }
  param_1[0x96] = 0;
  FUN_14018b900(param_1[0x98],0);
  param_1[0x98] = 0;
  if (param_1[0x95] != 0) {
    FUN_1401a4a00(param_1 + 0x95);
  }
  uVar8 = uVar9;
  if (param_1[0x91] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x92] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x92] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x91]);
  }
  param_1[0x90] = 0;
  FUN_14018b900(param_1[0x92],0);
  param_1[0x92] = 0;
  if (param_1[0x8f] != 0) {
    FUN_1401a4a00(param_1 + 0x8f);
  }
  uVar8 = uVar9;
  if (param_1[0x8b] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x8c] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x8c] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x8b]);
  }
  param_1[0x8a] = 0;
  FUN_14018b900(param_1[0x8c],0);
  param_1[0x8c] = 0;
  if (param_1[0x89] != 0) {
    FUN_1401a4a00(param_1 + 0x89);
  }
  uVar8 = uVar9;
  if (param_1[0x85] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x86] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x86] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x85]);
  }
  param_1[0x84] = 0;
  FUN_14018b900(param_1[0x86],0);
  param_1[0x86] = 0;
  if (param_1[0x83] != 0) {
    FUN_1401a4a00();
  }
  uVar8 = uVar9;
  if (param_1[0x7f] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x80] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x80] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x7f]);
  }
  param_1[0x7e] = 0;
  FUN_14018b900(param_1[0x80],0);
  param_1[0x80] = 0;
  if (param_1[0x7d] != 0) {
    FUN_1401a4a00();
  }
  uVar8 = uVar9;
  if (param_1[0x79] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x7a] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x7a] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x79]);
  }
  param_1[0x78] = 0;
  FUN_14018b900(param_1[0x7a],0);
  param_1[0x7a] = 0;
  if (param_1[0x77] != 0) {
    FUN_1401a4a00();
  }
  uVar8 = uVar9;
  if (param_1[0x73] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x74] + uVar8 * 8);
      lVar7 = *(longlong *)(param_1[0x74] + uVar8 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (ulonglong)param_1[0x73]);
  }
  param_1[0x72] = 0;
  FUN_14018b900(param_1[0x74],0);
  param_1[0x74] = 0;
  if (param_1[0x71] != 0) {
    FUN_1401a4a00();
  }
  if (param_1[0x6d] != 0) {
    do {
      plVar3 = (longlong *)(param_1[0x6e] + uVar9 * 8);
      lVar7 = *(longlong *)(param_1[0x6e] + uVar9 * 8);
      while (lVar7 != 0) {
        lVar7 = *plVar3;
        *plVar3 = *(longlong *)(lVar7 + 8);
        FUN_14018b900(lVar7,0);
        lVar7 = *plVar3;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < (ulonglong)param_1[0x6d]);
  }
  param_1[0x6c] = 0;
  FUN_14018b900(param_1[0x6e],0);
  plVar3 = param_1 + 0x6b;
  param_1[0x6e] = 0;
  if (*plVar3 != 0) {
    FUN_1401a4a00(plVar3);
  }
  iVar6 = 8;
  iVar5 = 8;
  do {
    plVar3 = plVar3 + -1;
    if (*plVar3 != 0) {
      FUN_1401a4a00(plVar3);
    }
    iVar5 = iVar5 + -1;
  } while (-1 < iVar5);
  FUN_1401981b0(param_1 + 0x61);
  if (param_1[0x61] != 0) {
    FUN_1401a4a00(param_1 + 0x61);
  }
  do {
    plVar4 = plVar4 + -1;
    if (*plVar4 != 0) {
      FUN_1401a4a00(plVar4);
    }
    iVar6 = iVar6 + -1;
  } while (-1 < iVar6);
  if (param_1[0x46] != 0) {
    FUN_1401a4a00();
  }
  if ((longlong *)param_1[0x45] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x45] + 8))();
  }
  if ((longlong *)param_1[0x44] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x44] + 8))();
  }
  if ((longlong *)param_1[0x43] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x43] + 8))();
  }
  if ((longlong *)param_1[0x42] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x42] + 8))();
  }
  if ((longlong *)param_1[0x41] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x41] + 8))();
  }
  if ((longlong *)param_1[0x40] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x40] + 8))();
  }
  if ((longlong *)param_1[0x3f] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x3f] + 8))();
  }
  if ((longlong *)param_1[0x3e] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x3e] + 8))();
  }
  if ((longlong *)param_1[0x3d] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x3d] + 8))();
  }
  if ((longlong *)param_1[0x3c] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x3c] + 8))();
  }
  if ((longlong *)param_1[0x3b] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x3b] + 8))();
  }
  if ((longlong *)param_1[0x3a] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x3a] + 8))();
  }
  if ((longlong *)param_1[0x39] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x39] + 8))();
  }
  if ((longlong *)param_1[0x38] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x38] + 8))();
  }
  if ((longlong *)param_1[0x36] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x36] + 8))();
  }
  if ((longlong *)param_1[0x34] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x34] + 8))();
  }
  if ((longlong *)param_1[0x33] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x33] + 8))();
  }
  if ((longlong *)param_1[0x32] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x32] + 8))();
  }
  if ((longlong *)param_1[0x31] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x31] + 8))();
  }
  if ((longlong *)param_1[0x30] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x30] + 8))();
  }
  if ((longlong *)param_1[0x2f] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x2f] + 8))();
  }
  if ((longlong *)param_1[0x2e] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x2e] + 8))();
  }
  if ((longlong *)param_1[0x2d] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x2d] + 8))();
  }
  if ((longlong *)param_1[0x2c] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x2c] + 8))();
  }
  if ((longlong *)param_1[0x2b] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x2b] + 8))();
  }
  if ((longlong *)param_1[0x2a] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x2a] + 8))();
  }
  if ((longlong *)param_1[0x29] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x29] + 8))();
  }
  plVar4 = param_1 + 0x28;
  if ((longlong *)*plVar4 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*plVar4 + 8))();
  }
  iVar5 = 3;
  do {
    plVar3 = plVar4 + -1;
    plVar4 = plVar4 + -1;
    if ((longlong *)*plVar3 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*plVar3 + 8))();
    }
    iVar5 = iVar5 + -1;
  } while (-1 < iVar5);
  if ((longlong *)param_1[0x23] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x23] + 8))();
  }
  if ((longlong *)param_1[0x22] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x22] + 8))();
  }
  if ((longlong *)param_1[0x21] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x21] + 8))();
  }
  if ((longlong *)param_1[0x20] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x20] + 8))();
  }
  if ((longlong *)param_1[0x1f] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1f] + 8))();
  }
  if ((longlong *)param_1[0x1e] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1e] + 8))();
  }
  if ((longlong *)param_1[0x1d] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1d] + 8))();
  }
  if ((longlong *)param_1[0x1c] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1c] + 8))();
  }
  if ((longlong *)param_1[0x1b] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1b] + 8))();
  }
  if ((longlong *)param_1[0x1a] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x1a] + 8))();
  }
  if ((longlong *)param_1[0x19] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x19] + 8))();
  }
  if ((longlong *)param_1[0x18] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x18] + 8))();
  }
  if ((longlong *)param_1[0x17] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x17] + 8))();
  }
  if ((longlong *)param_1[0x16] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x16] + 8))();
  }
  if ((longlong *)param_1[0x15] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x15] + 8))();
  }
  if ((longlong *)param_1[0x14] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x14] + 8))();
  }
  if ((longlong *)param_1[0x13] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x13] + 8))();
  }
  if ((longlong *)param_1[0x12] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x12] + 8))();
  }
  if ((longlong *)param_1[0x11] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x11] + 8))();
  }
  if ((longlong *)param_1[0x10] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x10] + 8))();
  }
  if ((longlong *)param_1[0xf] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xf] + 8))();
  }
  if ((longlong *)param_1[0xe] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xe] + 8))();
  }
  if ((longlong *)param_1[0xd] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xd] + 8))();
  }
  if ((longlong *)param_1[0xc] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xc] + 8))();
  }
  if ((longlong *)param_1[0xb] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0xb] + 8))();
  }
  if ((longlong *)param_1[10] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[10] + 8))();
  }
  if ((longlong *)param_1[9] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[9] + 8))();
  }
  return;
}



==== FUN_140381300 @ 140381300 size 1643 ====
CALLERS: FUN_14037d3e0
CALLEES: FUN_14003d880 FUN_14019dca0 FUN_140374820 FUN_140383760 GetCurrentThreadId FUN_14003d8f0 FUN_1407e4830 CloseHandle memcpy FUN_14019fb60 CreateEventW FUN_140374780 SetEvent

undefined8 FUN_140381300(longlong *param_1)

{
  float *pfVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  float fVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  DWORD DVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  HANDLE hObject;
  void *_Dst;
  void *_Dst_00;
  ulonglong uVar13;
  longlong *plVar14;
  longlong lVar15;
  uint uVar16;
  DWORD *pDVar18;
  uint uVar19;
  longlong lVar20;
  longlong lVar21;
  ulonglong uVar22;
  bool bVar23;
  longlong local_res8;
  undefined1 local_res10 [8];
  undefined4 local_a8 [4];
  longlong *local_98;
  code *local_90;
  undefined4 local_88 [4];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  longlong *local_60;
  code *local_58;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong uVar17;
  
  if (((*(uint *)(*param_1 + 0xe8) & 0x4000) == 0) || ((int)param_1[0x62] == 0)) {
    return 1;
  }
  uVar13 = 0;
  local_a8[0] = 0;
  uVar11 = (**(code **)(*(longlong *)param_1[2] + 0x30))((longlong *)param_1[2],local_a8);
  if ((int)uVar11 == 0) {
    return uVar11;
  }
  plVar14 = (longlong *)param_1[0x6c];
  if (plVar14 == (longlong *)0x0) {
    FUN_14003d8f0(local_res10,*param_1 + 0x9d0);
    lVar15 = *(longlong *)(*param_1 + 0x9f8);
    if (lVar15 == 0) {
      FUN_14003d880(local_res10);
      return 0;
    }
    param_1[0x6e] = lVar15;
    if (*(undefined8 **)(lVar15 + 0x520) != (undefined8 *)0x0) {
      **(undefined8 **)(lVar15 + 0x520) = *(undefined8 *)(lVar15 + 0x528);
    }
    if (*(longlong *)(lVar15 + 0x528) != 0) {
      *(undefined8 *)(*(longlong *)(lVar15 + 0x528) + 0x520) = *(undefined8 *)(lVar15 + 0x520);
    }
    *(undefined8 *)(lVar15 + 0x520) = 0;
    *(undefined8 *)(lVar15 + 0x528) = 0;
    FUN_14003d880(local_res10);
    if ((longlong *)param_1[0x5e] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[0x5e] + 8))();
      param_1[0x5e] = 0;
    }
    if ((longlong *)param_1[0x61] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[0x61] + 8))();
      param_1[0x61] = 0;
    }
    lVar15 = 0xc0;
    plVar14 = param_1 + 7;
    param_1[0x5c] = 0;
    param_1[0x5d] = 0;
    param_1[0x5f] = 0;
    param_1[0x60] = 0;
    lVar20 = 0x80;
    lVar21 = 4;
    *(undefined4 *)(param_1 + 0x6d) = *(undefined4 *)(*param_1 + 0x98);
    do {
      lVar5 = *plVar14;
      if (lVar5 == 0) {
        puVar12 = (undefined8 *)(lVar20 + param_1[0x6e]);
        *puVar12 = 0;
        puVar12[1] = 0;
        local_78 = 0;
        uStack_70 = 0;
        *(undefined4 *)(lVar15 + param_1[0x6e]) = 0x3a83126f;
      }
      else {
        uVar8 = *(undefined4 *)(lVar5 + 0x24);
        uVar6 = *(undefined4 *)(lVar5 + 0x28);
        uVar7 = *(undefined4 *)(lVar5 + 0x2c);
        puVar3 = (undefined4 *)(lVar20 + param_1[0x6e]);
        *puVar3 = *(undefined4 *)(lVar5 + 0x20);
        puVar3[1] = uVar8;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        *(undefined4 *)(lVar15 + param_1[0x6e]) = *(undefined4 *)(lVar5 + 0x6c);
      }
      lVar20 = lVar20 + 0x10;
      plVar14 = plVar14 + 1;
      lVar15 = lVar15 + 4;
      lVar21 = lVar21 + -1;
    } while (lVar21 != 0);
    plVar14 = param_1 + 0x40;
    local_res8 = 0x10;
    uVar22 = uVar13;
    do {
      if (*plVar14 == 0) {
        *(undefined1 *)(param_1[0x6e] + 0x110 + uVar22) = 0;
      }
      else {
        *(undefined1 *)(param_1[0x6e] + 0x110 + uVar22) = 1;
        *(undefined4 *)(param_1[0x6e] + 0x114 + uVar22) = *(undefined4 *)(*plVar14 + 0x28);
        uVar8 = FUN_140374780(*plVar14);
        *(undefined4 *)(param_1[0x6e] + 0x118 + uVar22) = uVar8;
        lVar15 = uVar22 + 0x120;
        uVar17 = uVar13;
        do {
          puVar12 = (undefined8 *)FUN_140374820(*plVar14,uVar17);
          lVar20 = param_1[0x6e];
          if (*(undefined8 **)(lVar15 + lVar20) != puVar12) {
            if (puVar12 != (undefined8 *)0x0) {
              (**(code **)*puVar12)(puVar12);
            }
            if (*(longlong **)(lVar15 + lVar20) != (longlong *)0x0) {
              (**(code **)(**(longlong **)(lVar15 + lVar20) + 8))();
            }
            *(undefined8 **)(lVar15 + lVar20) = puVar12;
          }
          uVar19 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar19;
          lVar15 = lVar15 + 8;
        } while (uVar19 < 6);
      }
      plVar14 = plVar14 + 1;
      uVar22 = uVar22 + 0x40;
      local_res8 = local_res8 + -1;
    } while (local_res8 != 0);
    *(undefined4 *)(param_1[0x6e] + 0x20) = 0;
    FUN_1407e4830(param_1[0x6e] + 0x24,0,0x40);
    uVar22 = 0x24;
    plVar14 = param_1 + 0x40;
    do {
      lVar15 = *plVar14;
      if (lVar15 != 0) {
        fVar4 = *(float *)(lVar15 + 0x28);
        pfVar1 = (float *)(param_1[0x6e] + 0x20);
        if (*pfVar1 <= fVar4 && fVar4 != *pfVar1) {
          *(float *)(param_1[0x6e] + 0x20) = fVar4;
        }
        uVar19 = FUN_140374780(lVar15);
        uVar17 = uVar13;
        if (uVar19 != 0) {
          do {
            lVar20 = FUN_140374820(lVar15,uVar17);
            uVar16 = (int)uVar17 + 1;
            uVar17 = (ulonglong)uVar16;
            *(float *)(param_1[0x6e] + uVar22) =
                 *(float *)(lVar20 + 0x28) + *(float *)(param_1[0x6e] + uVar22);
          } while (uVar16 < uVar19);
        }
      }
      uVar22 = uVar22 + 4;
      plVar14 = plVar14 + 1;
    } while (uVar22 < 100);
    local_90 = FUN_140381970;
    local_58 = FUN_140381970;
    local_68 = 0xc;
    local_64 = 2;
    local_50 = 0;
    local_48 = 1;
    local_98 = param_1;
    local_60 = param_1;
    iVar9 = FUN_14019dca0(&local_68,0,0,param_1 + 0x6c);
    if (-1 < iVar9) {
      return 0;
    }
    lVar15 = *param_1;
    pDVar18 = (DWORD *)(lVar15 + 0x9d0);
    DVar10 = GetCurrentThreadId();
    if (*pDVar18 == DVar10) {
      *(longlong *)(lVar15 + 0x9d8) = *(longlong *)(lVar15 + 0x9d8) + 1;
    }
    else {
      do {
        LOCK();
        bVar23 = *(longlong *)(lVar15 + 0x9d8) == 0;
        if (bVar23) {
          *(longlong *)(lVar15 + 0x9d8) = 1;
        }
        UNLOCK();
        if (bVar23) {
          *pDVar18 = DVar10;
          goto LAB_140381704;
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < 0x400);
      FUN_14019fb60(pDVar18);
    }
LAB_140381704:
    lVar20 = param_1[0x6e];
    plVar14 = (longlong *)(*param_1 + 0x9f8);
    if (*(longlong *)(lVar20 + 0x520) == 0) {
      *(longlong **)(lVar20 + 0x520) = plVar14;
      plVar2 = (longlong *)(lVar20 + 0x528);
      *plVar2 = *plVar14;
      *plVar14 = lVar20;
      if (*plVar2 != 0) {
        *(longlong **)(*plVar2 + 0x520) = plVar2;
      }
    }
    param_1[0x6e] = 0;
    if (1 < *(ulonglong *)(lVar15 + 0x9d8)) {
      *(longlong *)(lVar15 + 0x9d8) = *(longlong *)(lVar15 + 0x9d8) + -1;
      return 1;
    }
    *pDVar18 = 0;
    LOCK();
    *(undefined8 *)(lVar15 + 0x9d8) = 0;
    UNLOCK();
    if (*(longlong *)(lVar15 + 0x9e0) == 0) {
      return 1;
    }
    if (*(longlong *)(lVar15 + 0x9e8) == 0) {
      hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      LOCK();
      bVar23 = *(longlong *)(lVar15 + 0x9e8) == 0;
      if (bVar23) {
        *(longlong *)(lVar15 + 0x9e8) = (longlong)hObject;
      }
      UNLOCK();
      if (!bVar23) {
        CloseHandle(hObject);
      }
    }
    SetEvent(*(HANDLE *)(lVar15 + 0x9e8));
    return 1;
  }
  local_88[0] = 0;
  iVar9 = (**(code **)(*plVar14 + 0x20))(plVar14,local_88);
  if (iVar9 == 0) {
    return 0;
  }
  iVar9 = (**(code **)(*(longlong *)param_1[0x6c] + 0x28))((longlong *)param_1[0x6c],0);
  if (-1 < iVar9) {
    lVar15 = *(longlong *)(param_1[0x6e] + 0x18);
    if ((lVar15 != 0) && (*(longlong *)(param_1[0x6e] + 8) != 0)) {
      plVar14 = param_1 + 0x5e;
      iVar9 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,(int)lVar15 * 0x38,1,plVar14);
      if (-1 < iVar9) {
        plVar2 = param_1 + 0x61;
        iVar9 = (**(code **)(*DAT_140c65670 + 0x40))
                          (DAT_140c65670,(int)*(undefined8 *)(param_1[0x6e] + 8) * 2,0,1,plVar2);
        if ((-1 < iVar9) &&
           (_Dst = (void *)(**(code **)(*(longlong *)*plVar14 + 0x38))
                                     ((longlong *)*plVar14,0,
                                      (int)*(undefined8 *)(param_1[0x6e] + 0x18) * 0x38,2),
           _Dst != (void *)0x0)) {
          _Dst_00 = (void *)(**(code **)(*(longlong *)*plVar2 + 0x38))
                                      ((longlong *)*plVar2,0,
                                       (int)*(undefined8 *)(param_1[0x6e] + 8) * 2,2);
          if (_Dst_00 != (void *)0x0) {
            memcpy(_Dst,*(void **)(param_1[0x6e] + 0x10),*(longlong *)(param_1[0x6e] + 0x18) * 0x38)
            ;
            memcpy(_Dst_00,*(void **)param_1[0x6e],((undefined8 *)param_1[0x6e])[1] * 2);
            (**(code **)(*(longlong *)*plVar14 + 0x40))();
            (**(code **)(*(longlong *)*plVar2 + 0x40))();
            goto LAB_14038192f;
          }
          (**(code **)(*(longlong *)*plVar14 + 0x40))();
        }
      }
      if ((longlong *)*plVar14 != (longlong *)0x0) {
        (**(code **)(*(longlong *)*plVar14 + 8))();
        *plVar14 = 0;
      }
      if ((longlong *)param_1[0x61] != (longlong *)0x0) {
        (**(code **)(*(longlong *)param_1[0x61] + 8))();
        param_1[0x61] = 0;
      }
    }
  }
LAB_14038192f:
  FUN_140383760(param_1);
  return 1;
}



==== FUN_14031bca0 @ 14031bca0 size 4183 ====
CALLERS: FUN_14031b080
CALLEES: __security_check_cookie FUN_140318840 FUN_1408fe3d0 FUN_140305c20 FUN_1408fc950 FUN_1401afb10 FUN_14031a280 FUN_140300fd0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14031bca0(longlong *param_1,float *param_2,int param_3,longlong param_4,longlong param_5)

{
  float fVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 auVar8 [16];
  float fVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  longlong lVar15;
  undefined8 uVar16;
  char cVar17;
  int iVar18;
  longlong lVar19;
  uint uVar20;
  longlong lVar21;
  uint uVar22;
  float fVar23;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined8 extraout_XMM0_Qb;
  float fVar26;
  float fVar27;
  undefined1 auVar28 [16];
  undefined1 unaff_XMM6 [16];
  undefined1 auVar29 [16];
  undefined1 auVar32 [12];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  undefined1 auStack_4d8 [32];
  uint local_4b8;
  undefined8 local_4a8;
  undefined8 uStack_4a0;
  float local_498;
  float local_494;
  float local_490;
  int local_48c;
  longlong local_488;
  undefined8 local_478;
  float fStack_470;
  float fStack_46c;
  float local_468;
  float local_464;
  float local_460;
  undefined4 local_45c;
  float local_458;
  float local_454;
  float local_450;
  undefined4 local_44c;
  float local_448;
  uint local_444;
  float local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  undefined4 uStack_42c;
  float local_428;
  float local_424;
  float local_420;
  undefined4 local_41c;
  float local_418;
  float local_414;
  float local_410;
  undefined4 local_40c;
  float local_408;
  uint local_404;
  float local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  undefined4 uStack_3f4;
  undefined4 uStack_3f0;
  undefined4 uStack_3ec;
  float local_3e8;
  float local_3e4;
  float local_3e0;
  undefined4 local_3dc;
  uint local_3d8;
  float local_3d4;
  float local_3d0;
  undefined4 local_3cc;
  float local_3c8;
  uint local_3c4;
  float local_3c0;
  undefined4 local_3bc;
  undefined4 local_3b8;
  undefined4 uStack_3b4;
  undefined4 uStack_3b0;
  undefined4 uStack_3ac;
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  undefined8 local_388;
  undefined8 uStack_380;
  float local_378;
  float fStack_374;
  float fStack_370;
  undefined4 uStack_36c;
  undefined1 local_368 [16];
  undefined1 local_358 [16];
  undefined1 local_348 [16];
  undefined8 local_338;
  undefined8 uStack_330;
  undefined1 *local_328;
  undefined1 *local_320;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2c8;
  float fStack_2c4;
  float fStack_2c0;
  float fStack_2bc;
  float local_2b8;
  float fStack_2b4;
  float fStack_2b0;
  float fStack_2ac;
  float local_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float fStack_29c;
  undefined4 local_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  float local_288;
  float local_284;
  float local_280;
  float local_278;
  float fStack_274;
  float fStack_270;
  float fStack_26c;
  float local_268;
  float fStack_264;
  float fStack_260;
  float fStack_25c;
  float local_258;
  float fStack_254;
  float fStack_250;
  float fStack_24c;
  undefined4 local_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  float local_238;
  float local_234;
  float local_230;
  float local_228;
  float fStack_224;
  float fStack_220;
  float fStack_21c;
  float local_218;
  float fStack_214;
  float fStack_210;
  float fStack_20c;
  float local_208;
  float fStack_204;
  float fStack_200;
  float fStack_1fc;
  undefined4 local_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  float *local_1e8;
  float *local_1e0;
  undefined1 local_1d8 [64];
  float *local_198;
  float *local_190;
  undefined1 local_188 [64];
  float *local_148;
  float *local_140;
  undefined1 local_138 [64];
  ulonglong local_f8;
  
  auVar32 = unaff_XMM6._4_12_;
  local_f8 = DAT_140c0f7b0 ^ (ulonglong)auStack_4d8;
  local_4a8._0_4_ = SUB84(param_1,0);
  local_4a8._4_4_ = (float)((ulonglong)param_1 >> 0x20);
  local_488 = param_5;
  fVar39 = (float)param_3 * DAT_140b79d04;
  fVar34 = (float)((int)param_2[0x17] - (int)param_2[0x16]);
  fVar35 = fVar34 * DAT_140b79d04;
  fVar34 = fVar34 / (float)(int)param_2[0x17];
  if ((fVar34 < *(float *)(param_1 + 0x44)) ||
     (*(float *)(param_1 + 0x46) <= fVar34 && fVar34 != *(float *)(param_1 + 0x46))) {
    cVar17 = '\0';
  }
  else {
    cVar17 = '\x01';
  }
  plVar6 = *(longlong **)(param_2 + 0x14);
  local_494 = fVar34;
  local_490 = fVar35;
  local_48c = param_3;
  local_478 = param_4;
  if (plVar6 != (longlong *)0x0) {
    if (*(char *)(param_2 + 0x1b) == '\0') {
      if (cVar17 != '\0') {
        uVar16 = 1;
LAB_14031bdab:
        (**(code **)(*plVar6 + 0x580))(plVar6,uVar16);
      }
    }
    else if (cVar17 == '\0') {
      uVar16 = 0;
      goto LAB_14031bdab;
    }
    *(char *)(param_2 + 0x1b) = cVar17;
  }
  local_4b8 = (uint)*(ushort *)(param_1[0x34] + 0x5f0);
  FUN_140318840(*(ushort *)(param_1[0x34] + 0x5f0),param_1 + 0xa9,param_1 + 0x9f);
  pfVar13 = (float *)(**(code **)(*param_1 + 0x90))(param_1);
  pfVar14 = (float *)(**(code **)(*param_1 + 0x68))(param_1);
  uVar10 = DAT_140b7b500;
  fVar9 = DAT_140b79ed0;
  fVar36 = pfVar13[1];
  fVar37 = pfVar13[2];
  fVar38 = pfVar13[3];
  fVar27 = pfVar14[1];
  fVar1 = pfVar14[2];
  fVar33 = pfVar14[3];
  param_2[4] = param_2[4] + (*pfVar13 + *pfVar14) * fVar39;
  param_2[5] = param_2[5] + (fVar36 + fVar27) * fVar39;
  param_2[6] = param_2[6] + (fVar37 + fVar1) * fVar39;
  param_2[7] = param_2[7] + (fVar38 + fVar33) * fVar39;
  if (*(ushort *)(param_1[1] + 0x68) != 0) {
    uVar22 = 0;
    lVar15 = *(longlong *)(param_1[5] + 0x40);
    uVar20 = 1;
    fVar35 = 0.0;
    fVar36 = 0.0;
    fVar37 = 0.0;
    fVar38 = 0.0;
    uVar4 = *(uint *)(lVar15 + 0x308);
    if (uVar4 != 0) {
      auVar31._4_4_ = local_4a8._4_4_;
      auVar31._0_4_ = (float)local_4a8;
      auVar31._8_4_ = (float)uStack_4a0;
      auVar31._12_4_ = uStack_4a0._4_4_;
      lVar21 = 0;
      lVar19 = 0;
      pfVar13 = (float *)(local_488 + 8);
      fVar34 = local_498;
      do {
        if ((*(ushort *)(param_1[1] + 0x68) & uVar20) != 0) {
          lVar7 = *(longlong *)(param_1[5] + 0x588);
          sVar2 = *(short *)(*(longlong *)(lVar15 + 0x310) + 2 + lVar19);
          fVar27 = *(float *)(lVar7 + 0x30 + lVar21);
          unaff_XMM6 = ZEXT416((uint)fVar27);
          fVar1 = *(float *)(lVar7 + 0x1c + lVar21);
          fVar33 = fVar27 - fVar1;
          if (sVar2 == 0) {
            pfVar14 = (float *)((ulonglong)uVar22 * 0x10 + local_478);
            auVar28._0_4_ = *pfVar14 - *param_2;
            auVar28._4_4_ = pfVar14[1] - param_2[1];
            auVar28._8_4_ = pfVar14[2] - param_2[2];
            auVar28._12_4_ = pfVar14[3] - param_2[3];
            fVar27 = SQRT(auVar28._0_4_ * auVar28._0_4_ + auVar28._4_4_ * auVar28._4_4_ +
                          auVar28._8_4_ * auVar28._8_4_);
            if (fVar33 == 0.0) {
              fVar34 = fVar9;
              if (fVar1 <= fVar27) {
                fVar34 = 0.0;
              }
            }
            else {
              fVar33 = (fVar27 - fVar1) / fVar33;
              if (fVar9 <= fVar33) {
                fVar33 = fVar9;
              }
              fVar34 = 0.0;
              if (0.0 <= fVar33) {
                fVar34 = fVar33;
              }
              fVar34 = fVar9 - fVar34;
            }
            auVar24._4_4_ = fVar27;
            auVar24._0_4_ = fVar27;
            auVar24._8_4_ = fVar27;
            auVar24._12_4_ = fVar27;
            auVar31 = divps(auVar28,auVar24);
          }
          else if (sVar2 == 1) {
            pfVar14 = (float *)(local_488 + (ulonglong)uVar22 * 0x10);
            fVar26 = *param_2 * *pfVar14 + param_2[1] * pfVar14[1] + param_2[2] * pfVar14[2] +
                     *(float *)(local_488 + 0xc + (ulonglong)uVar22 * 0x10);
            fVar23 = (float)((uint)fVar26 & uVar10);
            if (fVar33 == 0.0) {
              fVar34 = fVar9;
              if (fVar1 <= fVar23) {
                fVar34 = 0.0;
              }
            }
            else {
              fVar33 = (fVar27 - fVar23) / fVar33;
              unaff_XMM6 = ZEXT416((uint)fVar33);
              if (fVar9 <= fVar33) {
                fVar33 = fVar9;
              }
              fVar34 = 0.0;
              if (0.0 <= fVar33) {
                fVar34 = fVar33;
              }
            }
            if (0.0 <= fVar26) {
              auVar31._0_4_ = 0.0 - pfVar13[-2];
              auVar31._4_4_ = 0.0 - pfVar13[-1];
              auVar31._8_4_ = 0.0 - *pfVar13;
              auVar31._12_4_ = 0;
            }
            else {
              auVar31._4_4_ = pfVar13[-1];
              auVar31._0_4_ = pfVar13[-2];
              auVar31._8_4_ = *pfVar13;
              auVar31._12_4_ = 0;
            }
          }
          fVar27 = *(float *)(lVar7 + 8 + lVar21);
          fVar35 = fVar27 * auVar31._0_4_ * fVar34 * fVar39 + fVar35;
          fVar36 = fVar27 * auVar31._4_4_ * fVar34 * fVar39 + fVar36;
          fVar37 = fVar27 * auVar31._8_4_ * fVar34 * fVar39 + fVar37;
          fVar38 = fVar27 * auVar31._12_4_ * fVar34 * fVar39 + fVar38;
        }
        auVar32 = unaff_XMM6._4_12_;
        uVar20 = uVar20 << 1 | (uint)((int)uVar20 < 0);
        uVar22 = uVar22 + 1;
        lVar19 = lVar19 + 0x50;
        pfVar13 = pfVar13 + 4;
        lVar21 = lVar21 + 0x48;
      } while (uVar22 < uVar4);
      param_1 = (longlong *)CONCAT44(local_4a8._4_4_,(float)local_4a8);
      fVar34 = local_494;
    }
    param_2[4] = param_2[4] + fVar35;
    param_2[5] = param_2[5] + fVar36;
    param_2[6] = param_2[6] + fVar37;
    param_2[7] = param_2[7] + fVar38;
    param_3 = local_48c;
    fVar35 = local_490;
  }
  if ((0.0 < *(float *)(param_1[1] + 0x30)) &&
     ((iVar18 = *(int *)(param_1[1] + 8), iVar18 == 2 || (*(char *)param_1[0x34] == '\x02')))) {
    lVar15 = param_1[5];
    plVar6 = *(longlong **)(*(longlong *)(lVar15 + 0x10) + 0x1e8);
    if (plVar6 != (longlong *)0x0) {
      if (iVar18 == 2) {
        local_4a8._0_4_ = *param_2;
        local_4a8._4_4_ = param_2[1];
        uStack_4a0._0_4_ = param_2[2];
        uStack_4a0._4_4_ = param_2[3];
      }
      else {
        local_4a8._0_4_ = *(float *)(lVar15 + 0x80) + *param_2;
        local_4a8._4_4_ = *(float *)(lVar15 + 0x84) + param_2[1];
        uStack_4a0._0_4_ = *(float *)(lVar15 + 0x88) + param_2[2];
        uStack_4a0._4_4_ = *(float *)(lVar15 + 0x8c) + param_2[3];
      }
      (**(code **)(*plVar6 + 0x1c0))(plVar6,&local_4a8,&local_478,3);
      fVar36 = *(float *)(param_1[1] + 0x30);
      param_2[4] = param_2[4] + fVar36 * (float)local_478 * fVar39;
      param_2[5] = param_2[5] + fVar36 * local_478._4_4_ * fVar39;
      param_2[6] = param_2[6] + fVar36 * fStack_470 * fVar39;
      param_2[7] = param_2[7] + fVar36 * fStack_46c * fVar39;
    }
  }
  local_4a8._0_4_ = *param_2;
  local_4a8._4_4_ = param_2[1];
  uStack_4a0._0_4_ = param_2[2];
  uStack_4a0._4_4_ = param_2[3];
  fVar36 = local_498 * fVar39;
  *param_2 = fVar36 * param_2[4] + (float)local_4a8;
  param_2[1] = fVar36 * param_2[5] + local_4a8._4_4_;
  param_2[2] = fVar36 * param_2[6] + (float)uStack_4a0;
  param_2[3] = fVar36 * param_2[7] + uStack_4a0._4_4_;
  if ((*(int *)(param_1[1] + 0x6c) != 0) &&
     (fVar36 = (float)(**(code **)(*(longlong *)param_1[5] + 0x58))(), 0.0 < fVar36)) {
    lVar15 = param_1[1];
    fVar36 = *(float *)(lVar15 + 0x70);
    fVar38 = fVar9 - ((*(float *)(lVar15 + 0x78) - *(float *)(lVar15 + 0x74)) * fVar34 +
                     *(float *)(lVar15 + 0x74));
    fVar37 = (float)(**(code **)(*(longlong *)param_1[5] + 0x58))();
    auVar32 = (undefined1  [12])0x0;
    if (0.0 <= fVar9 - ((fVar39 * fVar36) / fVar37) * fVar38) {
      fVar36 = *(float *)(param_1[1] + 0x70);
      fVar37 = (float)(**(code **)(*(longlong *)param_1[5] + 0x58))();
      fVar39 = fVar9 - ((fVar39 * fVar36) / fVar37) * fVar38;
    }
    else {
      fVar39 = 0.0;
    }
    lVar15 = param_1[5];
    fVar36 = *(float *)(lVar15 + 0xb4);
    fVar37 = *(float *)(lVar15 + 0xb8);
    fVar38 = *(float *)(lVar15 + 0xbc);
    *param_2 = *param_2 + *(float *)(lVar15 + 0xb0) * fVar39;
    param_2[1] = param_2[1] + fVar36 * fVar39;
    param_2[2] = param_2[2] + fVar37 * fVar39;
    param_2[3] = param_2[3] + fVar38 * fVar39;
  }
  lVar15 = param_1[1];
  if (*(int *)(lVar15 + 0x7c) != 0) {
    fVar39 = *(float *)(param_1 + 0x24);
    fVar36 = *(float *)((longlong)param_1 + 0x124);
    fVar37 = *(float *)(param_1 + 0x25);
    fVar38 = *(float *)((longlong)param_1 + 300);
    if (0.0 < fVar39 * fVar39 + fVar36 * fVar36 + fVar37 * fVar37) {
      fVar34 = (*(float *)(lVar15 + 0x84) - *(float *)(lVar15 + 0x80)) * fVar34 +
               *(float *)(lVar15 + 0x80);
      if (fVar34 < 0.0) {
        fVar34 = 0.0;
      }
      if (*(int *)(lVar15 + 8) == 2) {
        fVar39 = fVar39 - *(float *)(param_1 + 0x18);
        fVar36 = fVar36 - *(float *)((longlong)param_1 + 0xc4);
        fVar37 = fVar37 - *(float *)(param_1 + 0x19);
        fVar38 = fVar38 - *(float *)((longlong)param_1 + 0xcc);
      }
      *param_2 = *param_2 + fVar39 * fVar34;
      param_2[1] = param_2[1] + fVar36 * fVar34;
      param_2[2] = param_2[2] + fVar37 * fVar34;
      param_2[3] = param_2[3] + fVar38 * fVar34;
    }
  }
  lVar15 = param_1[0x34];
  uVar4 = *(uint *)(lVar15 + 0x850);
  if (uVar4 != 0) {
    iVar18 = 0;
    if (((uVar4 & 1) != 0) &&
       ((*param_2 * (float)local_4a8 <= 0.0 ||
        (fVar34 = (float)((uint)(*param_2 - *(float *)(param_1 + 0x78)) & uVar10), iVar18 = 0,
        fVar34 < *(float *)(lVar15 + 0x854) || fVar34 == *(float *)(lVar15 + 0x854))))) {
      iVar18 = 1;
    }
    if (((uVar4 & 2) != 0) &&
       ((param_2[1] * local_4a8._4_4_ <= 0.0 ||
        (fVar34 = (float)((uint)(param_2[1] - *(float *)((longlong)param_1 + 0x3c4)) & uVar10),
        fVar34 < *(float *)(lVar15 + 0x854) || fVar34 == *(float *)(lVar15 + 0x854))))) {
      iVar18 = iVar18 + 1;
    }
    if (((uVar4 & 4) != 0) &&
       ((param_2[2] * (float)uStack_4a0 <= 0.0 ||
        (fVar34 = (float)((uint)(param_2[2] - *(float *)(param_1 + 0x79)) & uVar10),
        fVar34 < *(float *)(lVar15 + 0x854) || fVar34 == *(float *)(lVar15 + 0x854))))) {
      iVar18 = iVar18 + 1;
    }
    iVar12 = (**(code **)(*param_1 + 0x80))(param_1);
    if (iVar18 == iVar12) {
      param_2[0x16] = 0.0;
      return;
    }
  }
  if (*(longlong *)(param_2 + 0x14) == 0) goto LAB_14031cc8a;
  uVar3 = *(ushort *)((longlong)param_2 + 0x6e);
  if (param_1[0xb3] == 0) {
    FUN_14031a280(param_1);
  }
  lVar15 = param_1[0x34];
  fVar34 = fVar35 * DAT_140b79e48;
  local_4b8 = (uint)*(ushort *)(lVar15 + 0x4f8);
  pfVar13 = (float *)((ulonglong)(uVar3 & 0x1f) * 0x30 + param_1[0xb3]);
  local_4a8._0_4_ = *pfVar13 + (pfVar13[4] + pfVar13[8] * fVar34) * fVar35;
  local_4a8._4_4_ = pfVar13[1] + (pfVar13[5] + pfVar13[9] * fVar34) * fVar35;
  uStack_4a0._0_4_ = pfVar13[2] + (pfVar13[6] + pfVar13[10] * fVar34) * fVar35;
  uStack_4a0._4_4_ = pfVar13[3] + (pfVar13[7] + pfVar13[0xb] * fVar34) * fVar35;
  FUN_140318840(pfVar13,param_1 + 0x95,param_1 + 0x8b,&local_498);
  fVar35 = local_498 * param_2[0x18];
  local_368._12_4_ = 0;
  local_368._0_12_ = *(undefined1 (*) [12])(param_2 + 8);
  local_358._12_4_ = 0;
  local_358._0_12_ = *(undefined1 (*) [12])(param_2 + 0xc);
  local_348._12_4_ = 0;
  local_348._0_12_ = *(undefined1 (*) [12])(param_2 + 0x10);
  auVar25._0_12_ = ZEXT812(0);
  auVar25._12_4_ = fVar9;
  uStack_330 = auVar25._8_8_;
  local_338 = 0;
  sVar2 = *(short *)(lVar15 + 0x804);
  if (sVar2 == 0) {
    fVar34 = (float)FUN_1408fe3d0();
    fVar39 = (float)FUN_1408fc950();
    auVar32 = SUB1612(ZEXT816(0),4);
    fVar36 = (float)FUN_1408fe3d0();
    local_454 = (float)FUN_1408fc950();
    local_198 = &local_228;
    local_190 = &local_468;
    local_45c = 0;
    local_44c = 0;
    local_43c = 0;
    local_468 = fVar34 * fVar34 * fVar36 + local_454 * fVar39;
    local_464 = fVar36 * fVar39;
    local_460 = fVar39 * fVar34 * fVar36 - local_454 * fVar34;
    local_458 = fVar34 * fVar34 * local_454 - fVar36 * fVar39;
    local_450 = fVar39 * fVar34 * local_454 + fVar36 * fVar34;
    local_454 = local_454 * fVar39;
    local_444 = (uint)fVar34 ^ DAT_140b7b530;
    local_448 = fVar34 * fVar39;
    local_440 = fVar39 * fVar39;
    local_438 = _DAT_140c78440;
    uStack_434 = uRam0000000140c78444;
    uStack_430 = uRam0000000140c78448;
    uStack_42c = uRam0000000140c7844c;
    local_1f8 = _DAT_140c78440;
    uStack_1f4 = uRam0000000140c78444;
    uStack_1f0 = uRam0000000140c78448;
    uStack_1ec = uRam0000000140c7844c;
    local_228 = _DAT_140c78410 * fVar35;
    fStack_224 = fRam0000000140c78414 * fVar35;
    fStack_220 = fRam0000000140c78418 * fVar35;
    fStack_21c = fRam0000000140c7841c * fVar35;
    local_218 = _DAT_140c78420 * fVar35;
    fStack_214 = fRam0000000140c78424 * fVar35;
    fStack_210 = fRam0000000140c78428 * fVar35;
    fStack_20c = fRam0000000140c7842c * fVar35;
    local_208 = _DAT_140c78430 * fVar35;
    fStack_204 = fRam0000000140c78434 * fVar35;
    fStack_200 = fRam0000000140c78438 * fVar35;
    fStack_1fc = fRam0000000140c7843c * fVar35;
    local_238 = fVar35;
    local_234 = fVar35;
    local_230 = fVar35;
    local_4a8 = local_198;
    uStack_4a0 = local_190;
    FUN_1401afb10(&local_198,local_188);
    local_328 = local_188;
LAB_14031ca37:
    local_320 = local_368;
    local_4a8._0_4_ = SUB84(local_328,0);
    local_4a8._4_4_ = (float)((ulonglong)local_328 >> 0x20);
    uStack_4a0 = (float *)local_320;
    FUN_1401afb10(&local_328,&local_3a8);
  }
  else {
    if (sVar2 == 1) {
      fVar34 = (float)FUN_1408fe3d0();
      fVar39 = (float)FUN_1408fc950();
      fVar36 = (float)FUN_1408fe3d0();
      fVar37 = (float)FUN_1408fc950();
      auVar32 = SUB1612(ZEXT816(0),4);
      fVar38 = (float)FUN_1408fe3d0();
      local_414 = (float)FUN_1408fc950();
      local_41c = 0;
      local_40c = 0;
      local_3fc = 0;
      local_404 = (uint)fVar34 ^ DAT_140b7b530;
      local_428 = fVar36 * fVar34 * fVar38 + local_414 * fVar37;
      local_424 = fVar38 * fVar39;
      local_420 = fVar37 * fVar34 * fVar38 - local_414 * fVar36;
      local_418 = fVar36 * fVar34 * local_414 - fVar38 * fVar37;
      local_410 = fVar37 * fVar34 * local_414 + fVar38 * fVar36;
      local_414 = local_414 * fVar39;
      local_408 = fVar36 * fVar39;
      local_3f8 = _DAT_140c78440;
      uStack_3f4 = uRam0000000140c78444;
      uStack_3f0 = uRam0000000140c78448;
      uStack_3ec = uRam0000000140c7844c;
      local_298 = _DAT_140c78440;
      uStack_294 = uRam0000000140c78444;
      uStack_290 = uRam0000000140c78448;
      uStack_28c = uRam0000000140c7844c;
      local_400 = fVar37 * fVar39;
      local_2c8 = _DAT_140c78410 * fVar35;
      fStack_2c4 = fRam0000000140c78414 * fVar35;
      fStack_2c0 = fRam0000000140c78418 * fVar35;
      fStack_2bc = fRam0000000140c7841c * fVar35;
      local_2b8 = _DAT_140c78420 * fVar35;
      fStack_2b4 = fRam0000000140c78424 * fVar35;
      fStack_2b0 = fRam0000000140c78428 * fVar35;
      fStack_2ac = fRam0000000140c7842c * fVar35;
      local_2a8 = _DAT_140c78430 * fVar35;
      fStack_2a4 = fRam0000000140c78434 * fVar35;
      fStack_2a0 = fRam0000000140c78438 * fVar35;
      fStack_29c = fRam0000000140c7843c * fVar35;
      local_1e8 = &local_2c8;
      local_1e0 = &local_428;
      local_2d8 = fVar35;
      local_2d4 = fVar35;
      local_2d0 = fVar35;
      local_4a8 = local_1e8;
      uStack_4a0 = local_1e0;
      FUN_1401afb10(&local_1e8,local_1d8);
      local_328 = local_1d8;
      goto LAB_14031ca37;
    }
    if (sVar2 == 2) {
      fVar34 = (float)FUN_1408fe3d0();
      fVar39 = (float)FUN_1408fc950();
      fVar36 = (float)FUN_1408fe3d0();
      fVar37 = (float)FUN_1408fc950();
      fVar38 = (float)FUN_1408fe3d0();
      uVar16 = FUN_1408fc950();
      local_3dc = 0;
      local_3cc = 0;
      local_3bc = 0;
      fVar27 = (float)uVar16;
      auVar29._8_4_ = (int)extraout_XMM0_Qb;
      auVar29._0_8_ = uVar16;
      auVar29._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
      local_3e8 = fVar27 * fVar37;
      local_3e0 = fVar38 * fVar34 - fVar36 * fVar39 * fVar27;
      local_3b8 = _DAT_140c78440;
      uStack_3b4 = uRam0000000140c78444;
      uStack_3b0 = uRam0000000140c78448;
      uStack_3ac = uRam0000000140c7844c;
      local_3e4 = fVar36 * fVar34 * fVar27 + fVar38 * fVar39;
      local_3d8 = (uint)(fVar38 * fVar37) ^ DAT_140b7b530;
      auVar32 = auVar29._4_12_;
      local_3d4 = fVar27 * fVar39 - fVar36 * fVar34 * fVar38;
      local_3d0 = fVar36 * fVar39 * fVar38 + fVar27 * fVar34;
      local_3c0 = fVar37 * fVar39;
      local_3c4 = (uint)(fVar37 * fVar34) ^ DAT_140b7b530;
      local_278 = _DAT_140c78410 * fVar35;
      fStack_274 = fRam0000000140c78414 * fVar35;
      fStack_270 = fRam0000000140c78418 * fVar35;
      fStack_26c = fRam0000000140c7841c * fVar35;
      local_268 = _DAT_140c78420 * fVar35;
      fStack_264 = fRam0000000140c78424 * fVar35;
      fStack_260 = fRam0000000140c78428 * fVar35;
      fStack_25c = fRam0000000140c7842c * fVar35;
      local_258 = _DAT_140c78430 * fVar35;
      fStack_254 = fRam0000000140c78434 * fVar35;
      fStack_250 = fRam0000000140c78438 * fVar35;
      fStack_24c = fRam0000000140c7843c * fVar35;
      local_148 = &local_278;
      local_140 = &local_3e8;
      local_248 = _DAT_140c78440;
      uStack_244 = uRam0000000140c78444;
      uStack_240 = uRam0000000140c78448;
      uStack_23c = uRam0000000140c7844c;
      local_3c8 = fVar36;
      local_288 = fVar35;
      local_284 = fVar35;
      local_280 = fVar35;
      local_4a8 = local_148;
      uStack_4a0 = local_140;
      FUN_1401afb10(&local_148,local_138);
      local_328 = local_138;
      goto LAB_14031ca37;
    }
    local_3a8 = _DAT_140c78390;
    uStack_3a0 = uRam0000000140c78398;
    local_398 = _DAT_140c783a0;
    uStack_390 = uRam0000000140c783a8;
    local_388 = _DAT_140c783b0;
    uStack_380 = uRam0000000140c783b8;
    uStack_36c = (undefined4)((ulonglong)uRam0000000140c783c8 >> 0x20);
  }
  local_378 = *param_2;
  fStack_374 = param_2[1];
  _fStack_370 = CONCAT44(uStack_36c,param_2[2]);
  (**(code **)(**(longlong **)(param_2 + 0x14) + 0x48))(*(longlong **)(param_2 + 0x14),&local_3a8);
  lVar15 = param_1[5];
  plVar6 = *(longlong **)(param_2 + 0x14);
  local_4a8._4_4_ = *(float *)(lVar15 + 0x42c);
  local_4a8._0_4_ = *(float *)(lVar15 + 0x428);
  uStack_4a0._0_4_ = *(float *)(lVar15 + 0x430) * *(float *)((longlong)plVar6 + 0x94);
  (**(code **)(*plVar6 + 0xf0))(plVar6,&local_4a8);
  piVar11 = DAT_140c63750;
  iVar18 = *(int *)((ushort *)param_1[1] + 4);
  if (iVar18 == 0) {
    pfVar13 = (float *)((ulonglong)*(ushort *)param_1[1] * 0x40 + *(longlong *)(param_1[5] + 0x338))
    ;
  }
  else if (iVar18 == 1) {
    pfVar13 = (float *)(param_1[5] + 0x4f0);
  }
  else if (iVar18 == 2) {
    pfVar13 = (float *)(*(longlong *)(param_1[5] + 0x10) + 0xf0);
  }
  else {
    pfVar13 = (float *)CONCAT44(local_4a8._4_4_,(float)local_4a8);
  }
  param_2[0x1a] = 1.0;
  iVar18 = DAT_140c42500;
  if (*piVar11 < DAT_140c42500) {
    iVar18 = *piVar11;
  }
  if (((&DAT_140c42510)[iVar18] != '\0') &&
     (*(float *)(*(longlong *)(param_1[5] + 0x10) + 0x5bc) != 0.0)) {
    fVar35 = fStack_374 * pfVar13[4] + local_378 * *pfVar13 + fStack_370 * pfVar13[8] + pfVar13[0xc]
    ;
    fVar34 = fStack_374 * pfVar13[5] + local_378 * pfVar13[1] + fStack_370 * pfVar13[9] +
             pfVar13[0xd];
    fVar39 = fStack_374 * pfVar13[6] + local_378 * pfVar13[2] + fStack_370 * pfVar13[10] +
             pfVar13[0xe];
    fVar36 = fStack_374 * pfVar13[7] + local_378 * pfVar13[3] + fStack_370 * pfVar13[0xb] +
             pfVar13[0xf];
    fVar34 = fVar34 * fVar34;
    fVar39 = fVar39 * fVar39;
    fVar35 = fVar35 * fVar35 + fVar34 + fVar39;
    if (_DAT_140c42068 < fVar35) {
      auVar30._4_12_ = auVar32;
      auVar30._0_4_ = fVar35;
      auVar8._4_4_ = fVar34;
      auVar8._0_4_ = fVar35;
      auVar8._8_4_ = fVar39;
      auVar8._12_4_ = fVar36 * fVar36;
      auVar31 = rsqrtss(auVar30,auVar8);
      lVar15 = (**(code **)(**(longlong **)(param_2 + 0x14) + 0x488))();
      fVar34 = auVar31._0_4_;
      fVar35 = *(float *)(lVar15 + 0x30) * *(float *)((longlong)param_1 + 0x394) * DAT_140b79f58 *
               *(float *)(*(longlong *)(param_1[5] + 0x10) + 0x5a4) *
               (fVar35 * fVar34 * fVar34 - DAT_140b79fa0) * fVar34 * DAT_140b7a228;
      if (_DAT_140b79d74 < fVar35) {
        if (fVar35 <= DAT_140b79d80) {
          param_2[0x1a] = fVar35 * _DAT_140b7a0c4 - DAT_140b79fa0;
        }
      }
      else {
        param_2[0x1a] = 0.0;
      }
    }
  }
  (**(code **)(**(longlong **)(param_2 + 0x14) + 0x70))
            (*(longlong **)(param_2 + 0x14),param_2[0x1a]);
  if (param_2[0x1a] != 0.0) {
    uVar5 = *(undefined4 *)(*(longlong *)(param_1[5] + 0x10) + 0xec);
    if ((*(byte *)(*(longlong *)(param_2 + 0x14) + 0x30) & 1) != 0) {
      FUN_140300fd0(*(longlong *)(param_2 + 0x14),pfVar13,param_1[0x83],uVar5);
    }
    FUN_140305c20(*(undefined8 *)(param_2 + 0x14),uVar5);
  }
LAB_14031cc8a:
  param_2[0x16] = (float)((int)param_2[0x16] - param_3);
  return;
}


