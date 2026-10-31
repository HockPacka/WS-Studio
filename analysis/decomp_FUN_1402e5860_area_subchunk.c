
ulonglong FUN_1402e5860(longlong param_1,ulonglong param_2,uint *param_3,undefined8 param_4)

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
  
  if ((*(longlong *)(param_1 + 0x1f8) == 0) && (3 < param_2)) {
    uVar1 = *param_3;
    *(ulonglong *)(param_1 + 0x1f0) = CONCAT44(0,uVar1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = CONCAT44(0,uVar1);
    uVar4 = SUB168(ZEXT816(8) * auVar2,0);
    if (SUB168(ZEXT816(8) * auVar2,8) != 0) {
      uVar4 = 0xffffffffffffffff;
    }
    lVar5 = FUN_14018b280(uVar4,1);
    *(longlong *)(param_1 + 0x1f8) = lVar5;
    if (lVar5 == 0) {
      uVar3 = 0x8007000e;
    }
    else {
      FUN_1407e4830(lVar5,0,*(longlong *)(param_1 + 0x1f0) << 3);
      uVar3 = 0;
      param_2 = param_2 - 4;
      puVar9 = param_3 + 1;
      if (*(longlong *)(param_1 + 0x1f0) != 0) {
        do {
          if (param_2 < 0x50) {
            return 0x80004005;
          }
          puVar10 = puVar9 + 0x14;
          uVar6 = (ulonglong)puVar9[0x10];
          if (param_2 - 0x50 < uVar6 * 0x18) {
            return 0x80004005;
          }
          uVar7 = (ulonglong)puVar9[0x11];
          param_2 = (param_2 - 0x50) + uVar6 * -0x18;
          if (param_2 < uVar7 * 0x48) {
            return 0x80004005;
          }
          param_2 = param_2 + uVar7 * -0x48;
          uVar8 = FUN_1402de8d0(puVar9,puVar10,puVar10 + uVar6 * 6,param_4,
                                *(longlong *)(param_1 + 0x1f8) + uVar3 * 8);
          if ((int)uVar8 < 0) {
            return uVar8;
          }
          uVar3 = (ulonglong)((int)uVar3 + 1);
          puVar9 = puVar10 + uVar6 * 6 + uVar7 * 0x12;
        } while (uVar3 < *(ulonglong *)(param_1 + 0x1f0));
      }
      uVar3 = (ulonglong)(-(uint)(param_2 != 0) & 0x80004005);
    }
  }
  else {
    uVar3 = 0x80004005;
  }
  return uVar3;
}

