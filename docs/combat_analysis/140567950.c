
void FUN_140567950(undefined8 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  FUN_1407e4830(param_2,0,0xa8);
  puVar1 = (undefined4 *)FUN_140238780(param_3);
  if ((param_2 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
    lVar2 = FUN_14023e0c0(puVar1[3]);
    if ((lVar2 != 0) && ((*(byte *)(lVar2 + 4) & 1) != 0)) {
      *param_2 = *puVar1;
      param_2[1] = puVar1[1];
      param_2[3] = puVar1[2];
      param_2[4] = puVar1[3];
      param_2[5] = puVar1[4];
      param_2[6] = *(undefined4 *)(lVar2 + 4);
      param_2[8] = puVar1[5];
      param_2[9] = puVar1[6];
      param_2[7] = puVar1[0x28];
      param_2[10] = puVar1[0x13];
      param_2[0xb] = puVar1[0x14];
      param_2[0xc] = puVar1[0x15];
      param_2[0xd] = puVar1[0x16];
      param_2[0xe] = puVar1[7];
      param_2[0xf] = puVar1[8];
      param_2[0x10] = puVar1[9];
      param_2[0x11] = puVar1[10];
      param_2[0x12] = puVar1[0xb];
      param_2[0x13] = puVar1[0xc];
      param_2[0x14] = puVar1[0xd];
      param_2[0x15] = puVar1[0xe];
      param_2[0x16] = puVar1[0xf];
      param_2[0x17] = puVar1[0x10];
      param_2[0x18] = puVar1[0x11];
      param_2[0x19] = puVar1[0x12];
      param_2[0x1a] = puVar1[0x17];
      param_2[0x1b] = puVar1[0x18];
      param_2[0x1c] = puVar1[0x19];
      param_2[0x1d] = puVar1[0x1b];
      param_2[0x1e] = puVar1[0x1c];
      param_2[0x1f] = puVar1[0x1d];
      param_2[0x20] = puVar1[0x1e];
      param_2[0x21] = puVar1[0x1f];
      param_2[0x22] = puVar1[0x20];
      param_2[0x26] = puVar1[0x24];
      param_2[0x23] = puVar1[0x21];
      param_2[0x27] = puVar1[0x25];
      param_2[0x24] = puVar1[0x22];
      param_2[0x28] = puVar1[0x26];
      param_2[0x25] = puVar1[0x23];
      param_2[0x29] = puVar1[0x27];
    }
  }
  return;
}

