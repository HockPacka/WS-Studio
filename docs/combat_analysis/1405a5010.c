
undefined8 FUN_1405a5010(longlong param_1,int *param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  bool bVar8;
  
  plVar6 = (longlong *)0x0;
  plVar3 = *(longlong **)(DAT_140c65b70 + 0x7c8);
  plVar5 = plVar6;
  if (plVar3 != (longlong *)0x0) {
    do {
      plVar5 = plVar3;
      if ((int)plVar3[0xc] == *param_2) break;
      plVar3 = (longlong *)plVar3[8];
      plVar5 = plVar6;
    } while (plVar3 != (longlong *)0x0);
  }
  lVar4 = *(longlong *)(param_1 + 0x78);
  plVar3 = plVar6;
  if (param_2[1] != 0) {
    lVar7 = DAT_140c65b70;
    if (lVar4 != 0) {
      if (DAT_140c65898[0xf] == lVar4) {
        bVar8 = true;
      }
      else {
        bVar8 = DAT_140c65898[0xc92] == lVar4;
      }
      if (bVar8) {
        plVar3 = DAT_140c65898;
      }
      if ((plVar3 != (longlong *)0x0) &&
         (plVar3 = (longlong *)FUN_1405a5b90(plVar3), plVar3 != (longlong *)0x0))
      goto LAB_1405a50ba;
    }
    plVar3 = (longlong *)FUN_1407a0fd0(lVar7);
  }
LAB_1405a50ba:
  if (((((uint)param_2[2] < 0x14c) && (lVar4 = FUN_140237240(), lVar4 != 0)) &&
      (uVar1 = *(ulonglong *)(lVar4 + 8), uVar1 != 0)) &&
     (plVar6 = (longlong *)0x0, uVar1 <= DAT_140c3fe70)) {
    plVar6 = (longlong *)(DAT_140c3fe68 + uVar1);
  }
  FUN_1400035b0(0x18,3,0,param_2[1],*param_2,plVar6);
  if (plVar3 == (longlong *)0x0) {
    if (plVar5 == (longlong *)0x0) {
      return 0;
    }
    (**(code **)(*plVar5 + 8))(plVar5);
  }
  FUN_1403a12a0(param_1,param_2[2],plVar3,1);
  if (*(longlong *)(param_1 + 0x78) != 0) {
    iVar2 = DAT_140c45e40;
    if (*DAT_140c63750 < DAT_140c45e40) {
      iVar2 = *DAT_140c63750;
    }
    if (((&DAT_140c45e50)[iVar2] == '\0') || (param_2[2] != 0xd)) {
      FUN_14046aa00(*(longlong *)(param_1 + 0x78),0,0);
    }
  }
  if (DAT_140c65b70 != 0) {
    FUN_140561ad0(DAT_140c65b70,plVar5);
  }
  return 0;
}

