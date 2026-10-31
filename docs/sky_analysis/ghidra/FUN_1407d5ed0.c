
void FUN_1407d5ed0(longlong *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5)

{
  longlong lVar1;
  
  lVar1 = (param_2 & 0xffffffff) * 0x30 + *(longlong *)(param_1[1] + 0x2f0);
  (**(code **)(*param_1 + 0x88))
            (param_1,*(undefined8 *)(lVar1 + 0x20),*(undefined4 *)(lVar1 + 0x18),param_3,param_4,
             param_5);
  return;
}

