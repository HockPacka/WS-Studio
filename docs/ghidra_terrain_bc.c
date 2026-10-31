
==== FUN_140268060 @ 140268060 size 190 ====
CALLERS: FUN_1402e8680
CALLEES: FUN_1402672a0

void FUN_140268060(undefined4 *param_1,uint *param_2)

{
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  
  FUN_1402672a0(param_1,param_2 + 2,0);
  fVar1 = DAT_140b79d94;
  uVar5 = *param_2;
  lVar4 = 8;
  lVar6 = 8;
  puVar3 = param_1;
  do {
    uVar2 = uVar5 & 0xf;
    uVar5 = uVar5 >> 4;
    *puVar3 = *puVar3;
    puVar3[1] = puVar3[1];
    puVar3[2] = puVar3[2];
    puVar3[3] = (float)uVar2 * fVar1;
    lVar6 = lVar6 + -1;
    puVar3 = puVar3 + 4;
  } while (lVar6 != 0);
  uVar5 = param_2[1];
  puVar3 = param_1 + 0x20;
  do {
    uVar2 = uVar5 & 0xf;
    uVar5 = uVar5 >> 4;
    *puVar3 = *puVar3;
    puVar3[1] = puVar3[1];
    puVar3[2] = puVar3[2];
    puVar3[3] = (float)uVar2 * fVar1;
    lVar4 = lVar4 + -1;
    puVar3 = puVar3 + 4;
  } while (lVar4 != 0);
  return;
}


