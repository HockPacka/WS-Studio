
void FUN_1404c1700(longlong *param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  
  if ((int)param_1[0x50] != 0) {
    FUN_1404c19c0();
    return;
  }
  plVar4 = (longlong *)(**(code **)(**(longlong **)(DAT_140c65898 + 0x7248) + 0x20))();
  lVar5 = FUN_140203520(*(undefined4 *)((longlong)param_1 + 0x6c));
  if (lVar5 == 0) {
    return;
  }
  uVar2 = *(ulonglong *)(lVar5 + 8);
  psVar8 = (short *)0x0;
  psVar7 = psVar8;
  if (uVar2 != 0) {
    if (DAT_140c3fe70 < uVar2) {
      psVar7 = (short *)0x0;
    }
    else {
      psVar7 = (short *)(DAT_140c3fe68 + uVar2);
    }
  }
  iVar3 = (**(code **)(*plVar4 + 0x28))(plVar4,psVar7,param_1 + 0x4c,0);
  if (-1 < iVar3) {
    if ((int)param_1[0x10] == 3) {
      uVar2 = *(ulonglong *)(lVar5 + 8);
      psVar7 = psVar8;
      if ((uVar2 != 0) && (uVar2 <= DAT_140c3fe70)) {
        psVar7 = (short *)(DAT_140c3fe68 + uVar2);
      }
      iVar3 = (**(code **)(*plVar4 + 0x28))(plVar4,psVar7,param_1 + 0x4d,0);
      if (iVar3 < 0) goto LAB_1404c1937;
    }
    lVar5 = FUN_140203da0((int)param_1[0xc]);
    if (lVar5 != 0) {
      uVar2 = *(ulonglong *)(lVar5 + 0x38);
      psVar7 = psVar8;
      if ((uVar2 != 0) && (uVar2 <= DAT_140c3fe70)) {
        psVar7 = (short *)(DAT_140c3fe68 + uVar2);
      }
      psVar6 = psVar8;
      if (*psVar7 != 0) {
        do {
          psVar6 = (short *)((longlong)psVar6 + 1);
        } while (psVar7[(longlong)psVar6] != 0);
        if (psVar6 != (short *)0x0) {
          psVar7 = psVar8;
          if ((uVar2 != 0) && (uVar2 <= DAT_140c3fe70)) {
            psVar7 = (short *)(uVar2 + DAT_140c3fe68);
          }
          iVar3 = (**(code **)(*plVar4 + 0x28))(plVar4,psVar7,param_1 + 0x4f,0);
          if (iVar3 < 0) goto LAB_1404c1937;
        }
      }
    }
    if (((int)param_1[0x26] == 0) || (iVar3 = FUN_1404c06c0(param_1), iVar3 != 0)) {
LAB_1404c18e7:
      FUN_1404c6b10(param_1);
      iVar3 = (**(code **)(*param_1 + 0x20))(param_1);
      if (iVar3 != 0) {
        return;
      }
      plVar4 = (longlong *)(param_1[0x25] + 0x90);
      if (param_1[2] != 0) {
        return;
      }
      param_1[2] = (longlong)plVar4;
      plVar1 = param_1 + 3;
      *plVar1 = *plVar4;
      *plVar4 = (longlong)param_1;
      if (*plVar1 == 0) {
        return;
      }
      *(longlong **)(*plVar1 + 0x10) = plVar1;
      return;
    }
    if ((DAT_140dc3190 & 1) == 0) {
      DAT_140dc3190 = DAT_140dc3190 | 1;
      DAT_140dc3198 = FUN_140203520(0xdd);
    }
    if (DAT_140dc3198 != 0) {
      uVar2 = *(ulonglong *)(DAT_140dc3198 + 8);
      if ((uVar2 != 0) && (uVar2 <= DAT_140c3fe70)) {
        psVar8 = (short *)(DAT_140c3fe68 + uVar2);
      }
      iVar3 = (**(code **)(*plVar4 + 0x28))(plVar4,psVar8,param_1 + 0x4e,0);
      if (-1 < iVar3) goto LAB_1404c18e7;
    }
  }
LAB_1404c1937:
  if ((longlong *)param_1[0x4c] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x4c] + 8))();
    param_1[0x4c] = 0;
  }
  if ((longlong *)param_1[0x4d] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x4d] + 8))();
    param_1[0x4d] = 0;
  }
  if ((longlong *)param_1[0x4e] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x4e] + 8))();
    param_1[0x4e] = 0;
  }
  if ((longlong *)param_1[0x4f] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[0x4f] + 8))();
    param_1[0x4f] = 0;
  }
  return;
}

