
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1404a1ca0(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  ulonglong *puVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  undefined1 auStack_78 [32];
  undefined4 local_58 [2];
  int local_50 [4];
  ulonglong local_40;
  
  local_40 = DAT_140c0f7b0 ^ (ulonglong)auStack_78;
  lVar1 = *(longlong *)(param_1 + 8);
  local_58[0] = param_3;
  uVar4 = (**(code **)(lVar1 + 0x18))(local_58);
  puVar2 = *(ulonglong **)(*(longlong *)(lVar1 + 0x10) + (uVar4 % *(ulonglong *)(lVar1 + 8)) * 8);
  while( true ) {
    if (puVar2 == (ulonglong *)0x0) {
      return 0;
    }
    if ((uVar4 == *puVar2) && (iVar3 = (**(code **)(lVar1 + 0x20))(local_58,puVar2 + 2), iVar3 != 0)
       ) break;
    puVar2 = (ulonglong *)puVar2[1];
  }
  if (puVar2 + 3 == (ulonglong *)0x0) {
    return 0;
  }
  uVar4 = puVar2[3];
  *(undefined8 *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0x30) = local_58[0];
  bVar8 = (*(byte *)(uVar4 + 4) & 1) == 0;
  uVar6 = 0;
  do {
    if (*(longlong *)(uVar4 + 8 + uVar6 * 8) == 0) break;
    iVar3 = FUN_1404a2100(param_1,param_2);
    local_50[uVar6] = iVar3;
    uVar7 = (int)uVar6 + 1;
    uVar6 = (ulonglong)uVar7;
    if (*(int *)(param_1 + 0x6c) == 0) {
      if (bVar8) {
        if (iVar3 == 0) break;
      }
      else if (iVar3 != 0) break;
    }
  } while (uVar7 < 3);
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (bVar8) {
    iVar3 = 1;
    if ((int)uVar6 != 0) {
      piVar5 = local_50;
      do {
        if ((iVar3 == 0) || (*piVar5 == 0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = 1;
        }
        piVar5 = piVar5 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
  }
  else if ((int)uVar6 != 0) {
    piVar5 = local_50;
    do {
      if ((iVar3 != 0) || (*piVar5 != 0)) {
        iVar3 = 1;
      }
      piVar5 = piVar5 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return iVar3;
}

