
void FUN_1403d40e0(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x10);
  if (lVar4 != *(longlong *)(param_1 + 8)) {
    do {
      puVar1 = *(undefined8 **)(lVar4 + 0x28);
      if (puVar1 != (undefined8 *)0x0) {
        (**(code **)*puVar1)(puVar1,1);
      }
      lVar3 = *(longlong *)(lVar4 + 0x18);
      if (lVar3 == 0) {
        lVar3 = *(longlong *)(lVar4 + 8);
        if (lVar4 == *(longlong *)(lVar3 + 0x18)) {
          do {
            lVar4 = lVar3;
            lVar3 = *(longlong *)(lVar4 + 8);
          } while (lVar4 == *(longlong *)(lVar3 + 0x18));
        }
        if (*(longlong *)(lVar4 + 0x18) != lVar3) {
          lVar4 = lVar3;
        }
      }
      else {
        for (lVar2 = *(longlong *)(lVar3 + 0x10); lVar4 = lVar3, lVar2 != 0;
            lVar2 = *(longlong *)(lVar2 + 0x10)) {
          lVar3 = lVar2;
        }
      }
    } while (lVar4 != *(longlong *)(param_1 + 8));
  }
  FUN_140008410(param_1);
  return;
}

