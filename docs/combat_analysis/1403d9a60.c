
undefined8
FUN_1403d9a60(longlong param_1,longlong *param_2,undefined4 param_3,uint param_4,float param_5)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 local_38 [2];
  longlong *local_30;
  code *local_28;
  undefined8 local_20;
  
  uVar4 = 0;
  uVar6 = (ulonglong)param_4;
  if ((*(longlong *)(param_1 + 0x78) != 0) &&
     ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
    uVar5 = uVar6;
    if (param_5 != 0.0) {
      uVar5 = (ulonglong)(uint)(int)(param_5 + 0.5);
    }
    FUN_140429cb0(*(undefined8 *)(param_1 + 0x7340),param_3,uVar5);
  }
  switch(param_3) {
  case 1:
    *(float *)(param_2 + 0x43) = param_5;
    if (((*(longlong **)(param_1 + 0x6d90) != (longlong *)0x0) &&
        (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(**(longlong **)(param_1 + 0x6d90) + 0xb0))();
    }
    break;
  case 2:
    *(float *)((longlong)param_2 + 0x21c) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,0);
    }
    break;
  case 3:
    *(float *)(param_2 + 0x44) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,1);
    }
    break;
  case 4:
    *(float *)((longlong)param_2 + 0x224) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,2);
    }
    break;
  case 5:
    *(float *)(param_2 + 0x45) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,3);
    }
    break;
  case 6:
    *(float *)((longlong)param_2 + 0x22c) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,4);
    }
    break;
  case 7:
    *(float *)(param_2 + 0x46) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,5);
    }
    break;
  case 8:
    *(float *)((longlong)param_2 + 0x234) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,6);
    }
    break;
  case 9:
    *(float *)(param_2 + 0x47) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,7);
    }
    break;
  case 10:
    uVar2 = *(uint *)(param_2 + 7);
    (**(code **)(*param_2 + 0x30))(param_2,uVar6,0);
    if ((*(longlong *)(DAT_140c65898 + 0x78) != 0) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(DAT_140c65898 + 0x78) + 8))) {
      if (uVar2 < param_4) {
        local_38[0] = 0;
        local_28 = FUN_14045edd0;
        local_20 = 0;
        local_30 = param_2;
        uVar7 = FUN_140195960(param_2 + 0x4c,2000,local_38,4);
        for (uVar5 = (ulonglong)(uVar2 + 1); uVar5 < uVar6; uVar5 = uVar5 + 1) {
          uVar7 = FUN_14043b4a0(uVar7,uVar5 & 0xffffffff);
        }
      }
      else if (param_4 < uVar2) {
        lVar3 = FUN_14024dfc0(uVar6);
        uVar2 = uVar4;
        if (lVar3 != 0) {
          uVar2 = *(uint *)(lVar3 + 0x10);
          uVar4 = *(uint *)(lVar3 + 0xc);
        }
        FUN_1400ea3e0(*(undefined8 *)(param_1 + 0x7340),"PlayerLevelChange",&DAT_1409ecb84,uVar6,
                      uVar2,uVar4);
      }
    }
    break;
  case 0xb:
    (**(code **)(*param_2 + 0x38))(param_2,uVar6);
    break;
  case 0xf:
    FUN_140470650(param_2,uVar6,0);
    break;
  case 0x11:
    if (param_2[0x27] != uVar6) {
      FUN_14045ad90(param_2,uVar6);
    }
    break;
  case 0x13:
    (**(code **)(*param_2 + 0x68))(param_2,param_5);
    break;
  case 0x14:
    (**(code **)(*param_2 + 0x80))(param_2,uVar6,(int)param_2[1],0);
    if ((*(longlong *)(param_1 + 0x78) != 0) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      FUN_1400ea3e0(*(undefined8 *)(param_1 + 0x7340),"RefreshHealthShieldBar",&DAT_1409d08be);
    }
    break;
  case 0x15:
    if (((int)*(float *)((longlong)param_2 + 0x724) != -1) &&
       (uVar2 = (int)*(float *)((longlong)param_2 + 0xc94) +
                (int)*(float *)((longlong)param_2 + 0x724), uVar2 != 0xffffffff)) {
      if ((-1 < (int)param_4) && (uVar4 = param_4, (int)uVar2 < (int)param_4)) {
        uVar4 = uVar2;
      }
      *(uint *)(param_2 + 0x96) = uVar4;
    }
    break;
  case 0x16:
    (**(code **)(*param_2 + 0x98))(param_2,uVar6,(int)param_2[1]);
    break;
  case 0x17:
    *(float *)((longlong)param_2 + 0x23c) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,8);
    }
    break;
  case 0x18:
    *(float *)(param_2 + 0x48) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,9);
    }
    break;
  case 0x19:
    *(float *)((longlong)param_2 + 0x244) = param_5;
    plVar1 = *(longlong **)(param_1 + 0x6d90);
    if (((plVar1 != (longlong *)0x0) && (*(longlong *)(param_1 + 0x78) != 0)) &&
       ((int)param_2[1] == *(int *)(*(longlong *)(param_1 + 0x78) + 8))) {
      (**(code **)(*plVar1 + 0xa8))(plVar1,10);
    }
    break;
  case 0x1a:
    *(uint *)(param_2 + 10) = param_4;
  }
  return 0;
}

