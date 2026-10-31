
int FUN_1403d3520(undefined8 param_1,int param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  uVar1 = DAT_140c65b70;
  if (param_2 == 0) {
    return 0;
  }
  lVar4 = FUN_1403acd90(DAT_140c65b70);
  iVar3 = 0;
  if (lVar4 != 0) {
    iVar2 = *(int *)(*(longlong *)(lVar4 + 0x70) + 0x18);
    iVar3 = param_2;
    if (((((iVar2 - 2U & 0xfffffffa) == 0) && (iVar2 != 3)) &&
        (*(int *)(*(longlong *)(lVar4 + 0x70) + 0x184) == 0)) &&
       (uVar5 = 0, *(int *)(lVar4 + 0x28) != 0)) {
      lVar6 = 0;
      do {
        if (((*(int *)(*(longlong *)(lVar4 + 0x30) + 0x10 + lVar6) == 0x1a) &&
            (*(int *)(*(longlong *)(lVar4 + 0x30) + 0x74 + lVar6) != 0)) &&
           (iVar2 = (**(code **)(*DAT_140c659a0 + 0x18))(), iVar2 != 0)) {
          iVar3 = *(int *)(uVar5 * 0xa8 + 0x40 + *(longlong *)(lVar4 + 0x30));
          lVar4 = FUN_1403acd90(uVar1,iVar3,param_3);
          if (lVar4 != 0) {
            return iVar3;
          }
          return param_2;
        }
        uVar5 = uVar5 + 1;
        lVar6 = lVar6 + 0xa8;
      } while (uVar5 < *(uint *)(lVar4 + 0x28));
    }
  }
  return iVar3;
}

