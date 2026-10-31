
undefined8 FUN_1402dd650(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  
  *(int *)(param_1 + 0xc) = param_2;
  lVar5 = (longlong)param_2;
  lVar6 = lVar5 * 0x38;
  iVar1 = *(int *)(&DAT_140c41368 + lVar6);
  iVar2 = *(int *)(&DAT_140c41358 + lVar6);
  iVar3 = (&DAT_140c4135c)[lVar5 * 0xe];
  iVar4 = (&DAT_140c4136c)[lVar5 * 0xe];
  lVar5 = FUN_14018b280((longlong)
                        ((iVar1 * ((&DAT_140c41360)[lVar5 * 0xe] - *(int *)(&DAT_140c41358 + lVar6))
                         - (&DAT_140c4136c)[lVar5 * 0xe]) +
                        ((&DAT_140c41364)[lVar5 * 0xe] - (&DAT_140c4135c)[lVar5 * 0xe]) *
                        (&DAT_140c4136c)[lVar5 * 0xe]),1);
  *(longlong *)(param_1 + 0x18) = lVar5;
  if (lVar5 == 0) {
    return 0x8007000e;
  }
  *(longlong *)(param_1 + 0x10) = lVar5 - (iVar1 * iVar2 + iVar3 * iVar4);
  return 0;
}

