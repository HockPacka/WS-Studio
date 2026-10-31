
void FUN_1404a5080(longlong param_1,undefined4 param_2,int param_3)

{
  short *psVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  wchar_t *pwVar5;
  undefined1 local_38 [8];
  longlong local_30;
  
  puVar2 = (undefined4 *)FUN_140225e00(param_2);
  if (puVar2 != (undefined4 *)0x0) {
    uVar4 = 0;
    if (*(int *)(param_1 + 0x68) != 0) {
      do {
        lVar3 = 0;
        do {
          psVar1 = &DAT_140b685ba + lVar3;
          lVar3 = lVar3 + 1;
        } while (*psVar1 != 0);
        FUN_14001c310(param_1 + 0x48,&DAT_140b685b8,&DAT_140b685b8 + lVar3 * 2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0x68));
    }
    pwVar5 = L"FAIL";
    if (param_3 != 0) {
      pwVar5 = L"PASS";
    }
    lVar3 = FUN_14018efa0(local_38,L"- PrereqType Id (%d): %s\n",*puVar2,pwVar5);
    FUN_14001c310(param_1 + 0x48,*(undefined8 *)(lVar3 + 8),*(undefined8 *)(lVar3 + 0x10));
    if (local_30 != 0) {
      FUN_14018b900(local_30,0);
    }
  }
  return;
}

