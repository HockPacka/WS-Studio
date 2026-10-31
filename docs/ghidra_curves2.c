
==== FUN_140313c20 @ 140313c20 size 2694 ====
CALLERS: FUN_140314d80
CALLEES: FUN_1403180d0 FUN_1403181e0 FUN_140318430 FUN_140317ec0 FUN_140313b30 FUN_14018b280 FUN_1407e4830 FUN_140318300 FUN_140317fc0

void FUN_140313c20(longlong param_1)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  ulonglong uVar3;
  longlong lVar4;
  uint *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  
  if (*(char *)(param_1 + 400) == '\0') {
    FUN_140313b30();
    lVar4 = *(longlong *)(param_1 + 0x1a0);
    uVar8 = (uint)*(ushort *)(lVar4 + 0x6e8) +
            ((uint)*(ushort *)(lVar4 + 0xd78) + (uint)*(ushort *)(lVar4 + 0xc80) +
             (uint)*(ushort *)(lVar4 + 0xb88) + (uint)*(ushort *)(lVar4 + 0xa90) +
             (uint)*(ushort *)(lVar4 + 0x99c) + (uint)*(ushort *)(lVar4 + 0x86c) +
             (uint)*(ushort *)(lVar4 + 0x5f0) + (uint)*(ushort *)(lVar4 + 0x4f8) +
            (uint)*(ushort *)(lVar4 + 0x400)) * 2 + (uint)*(ushort *)(lVar4 + 0x294);
    uVar3 = SUB168(ZEXT816(0x10) * ZEXT416(uVar8),0);
    if (SUB168(ZEXT816(0x10) * ZEXT416(uVar8),8) != 0) {
      uVar3 = 0xffffffffffffffff;
    }
    lVar4 = uVar3 + 8;
    if (0xfffffffffffffff7 < uVar3) {
      lVar4 = -1;
    }
    puVar5 = (uint *)FUN_14018b280(lVar4,0);
    uVar3 = 0;
    if (puVar5 == (uint *)0x0) {
      puVar5 = (uint *)0x0;
    }
    else {
      *puVar5 = uVar8;
      puVar5 = puVar5 + 2;
      if (-1 < (int)(uVar8 - 1)) {
        FUN_1407e4830(puVar5,0,(ulonglong)uVar8 << 4);
      }
    }
    lVar4 = *(longlong *)(param_1 + 0x1a0);
    *(uint **)(param_1 + 0x498) = puVar5;
    *(uint **)(param_1 + 0x4a0) = puVar5;
    uVar1 = *(ushort *)(lVar4 + 0x4f8);
    *(uint **)(param_1 + 0x4a8) = puVar5 + (ulonglong)uVar1 * 4;
    uVar8 = (uint)uVar1 + (uint)*(ushort *)(lVar4 + 0x4f8);
    *(uint **)(param_1 + 0x4b0) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x5f0);
    *(uint **)(param_1 + 0x4b8) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x5f0);
    *(uint **)(param_1 + 0x4c8) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x294);
    *(uint **)(param_1 + 0x4d0) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x400);
    *(uint **)(param_1 + 0x4d8) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x400);
    *(uint **)(param_1 + 0x4e8) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x6e8);
    *(uint **)(param_1 + 0x4f0) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x86c);
    *(uint **)(param_1 + 0x4f8) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x86c);
    *(uint **)(param_1 + 0x500) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x99c);
    *(uint **)(param_1 + 0x508) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0x99c);
    *(uint **)(param_1 + 0x510) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0xa90);
    *(uint **)(param_1 + 0x518) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0xa90);
    *(uint **)(param_1 + 0x520) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0xb88);
    *(uint **)(param_1 + 0x528) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0xb88);
    *(uint **)(param_1 + 0x530) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0xc80);
    *(uint **)(param_1 + 0x538) = puVar5 + (ulonglong)uVar8 * 4;
    uVar8 = uVar8 + *(ushort *)(lVar4 + 0xc80);
    *(uint **)(param_1 + 0x540) = puVar5 + (ulonglong)uVar8 * 4;
    *(uint **)(param_1 + 0x548) = puVar5 + (ulonglong)(uVar8 + *(ushort *)(lVar4 + 0xd78)) * 4;
    uVar8 = (uint)*(ushort *)(lVar4 + 0x294) * 2;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = (longlong)(int)uVar8;
    uVar6 = SUB168(ZEXT816(0x20) * auVar2,0);
    if (SUB168(ZEXT816(0x20) * auVar2,8) != 0) {
      uVar6 = 0xffffffffffffffff;
    }
    lVar4 = uVar6 + 0x10;
    if (0xffffffffffffffef < uVar6) {
      lVar4 = -1;
    }
    puVar5 = (uint *)FUN_14018b280(lVar4,0);
    if (puVar5 == (uint *)0x0) {
      puVar5 = (uint *)0x0;
    }
    else {
      *puVar5 = uVar8;
      puVar5 = puVar5 + 4;
      if (-1 < (int)(uVar8 - 1)) {
        FUN_1407e4830(puVar5,0,(ulonglong)uVar8 << 5);
      }
    }
    *(uint **)(param_1 + 0x4c0) = puVar5;
    uVar6 = uVar3;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x4f8) != 0) {
      do {
        FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0x500 + uVar6 * 0x18,
                      *(longlong *)(param_1 + 0x4a0) + uVar6 * 0x10,param_1 + 0x180);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0x578 + uVar6 * 0x18,
                      *(longlong *)(param_1 + 0x4a8) + uVar6 * 0x10,param_1 + 0x180);
        uVar8 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar8;
      } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x4f8));
    }
    uVar6 = uVar3;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x5f0) != 0) {
      do {
        FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0x5f8 + uVar6 * 0x18,
                      *(longlong *)(param_1 + 0x4b0) + uVar6 * 0x10,param_1 + 0x180);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0x670 + uVar6 * 0x18,
                      *(longlong *)(param_1 + 0x4b8) + uVar6 * 0x10,param_1 + 0x180);
        uVar8 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar8;
      } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x5f0));
    }
    lVar4 = param_1 + 0x180;
    FUN_140317ec0(*(longlong *)(param_1 + 8) + 0x38,param_1 + 0x60,lVar4);
    FUN_1403180d0(*(longlong *)(param_1 + 0x1a0) + 0x188,param_1 + 0x2d0,lVar4);
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 2) != 0) {
      FUN_1403181e0(*(longlong *)(param_1 + 0x1a0) + 0x278,param_1 + 0x370,lVar4);
    }
    FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0x960,param_1 + 0x488,lVar4);
    uVar6 = uVar3;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x400) != 0) {
      do {
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x2b) * 0x18,
                      *(longlong *)(param_1 + 0x4d0) + uVar6 * 0x10,lVar4);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x30) * 0x18,
                      *(longlong *)(param_1 + 0x4d8) + uVar6 * 0x10,lVar4);
        uVar8 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar8;
      } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x400));
    }
    uVar6 = uVar3;
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x294) != 0) {
      do {
        lVar7 = uVar6 * 0x18;
        uVar9 = uVar3;
        do {
          FUN_140318300(*(longlong *)(param_1 + 0x1a0) + 0x298 + lVar7,
                        (ulonglong)
                        ((uint)*(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x294) * (int)uVar9 +
                        (int)uVar6) * 0x20 + *(longlong *)(param_1 + 0x4c0),lVar4);
          uVar8 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar8;
          lVar7 = lVar7 + 0x78;
        } while (uVar8 < 2);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0x388 + uVar6 * 0x18,
                      uVar6 * 0x10 + *(longlong *)(param_1 + 0x4c8),lVar4);
        uVar8 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar8;
      } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x294));
    }
    if ((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 8) != 0) {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x6e8);
      uVar6 = SUB168(ZEXT816(0x20) * ZEXT216(uVar1),0);
      if (SUB168(ZEXT816(0x20) * ZEXT216(uVar1),8) != 0) {
        uVar6 = 0xffffffffffffffff;
      }
      lVar7 = uVar6 + 0x10;
      if (0xffffffffffffffef < uVar6) {
        lVar7 = -1;
      }
      puVar5 = (uint *)FUN_14018b280(lVar7,0);
      if (puVar5 == (uint *)0x0) {
        puVar5 = (uint *)0x0;
      }
      else {
        *puVar5 = (uint)uVar1;
        puVar5 = puVar5 + 4;
        if (-1 < (int)(uVar1 - 1)) {
          FUN_1407e4830(puVar5,0,(ulonglong)(uint)uVar1 << 5);
        }
      }
      *(uint **)(param_1 + 0x4e0) = puVar5;
      uVar6 = uVar3;
      if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x6e8) != 0) {
        do {
          FUN_140318430(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x4a) * 0x18,
                        uVar6 * 0x20 + *(longlong *)(param_1 + 0x4e0),lVar4);
          FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x4f) * 0x18,
                        uVar6 * 0x10 + *(longlong *)(param_1 + 0x4e8),lVar4);
          uVar8 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar8;
        } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x6e8));
      }
    }
    if (((*(byte *)(*(longlong *)(param_1 + 0x1a0) + 0xec8) & 0x80) != 0) &&
       (uVar6 = uVar3, *(short *)(*(longlong *)(param_1 + 0x1a0) + 0x86c) != 0)) {
      do {
        FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x5a) * 0x18,
                      *(longlong *)(param_1 + 0x4f0) + uVar6 * 0x10,lVar4);
        FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x5f) * 0x18,
                      *(longlong *)(param_1 + 0x4f8) + uVar6 * 0x10,lVar4);
        uVar8 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar8;
      } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x86c));
    }
    if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x998) == 2) {
      uVar6 = uVar3;
      if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0x99c) != 0) {
        do {
          FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0x9a0 + uVar6 * 0x18,
                        *(longlong *)(param_1 + 0x500) + uVar6 * 0x10,lVar4);
          FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0xa18 + uVar6 * 0x18,
                        *(longlong *)(param_1 + 0x508) + uVar6 * 0x10,lVar4);
          uVar8 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar8;
        } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0x99c));
      }
      uVar6 = uVar3;
      if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0xa90) != 0) {
        do {
          FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x71) * 0x18,
                        *(longlong *)(param_1 + 0x510) + uVar6 * 0x10,lVar4);
          FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + (uVar6 + 0x76) * 0x18,
                        *(longlong *)(param_1 + 0x518) + uVar6 * 0x10,lVar4);
          uVar8 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar8;
        } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xa90));
      }
      uVar6 = uVar3;
      if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0xb88) != 0) {
        do {
          FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0xb90 + uVar6 * 0x18,
                        *(longlong *)(param_1 + 0x520) + uVar6 * 0x10,lVar4);
          FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0xc08 + uVar6 * 0x18,
                        *(longlong *)(param_1 + 0x528) + uVar6 * 0x10,lVar4);
          uVar8 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar8;
        } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xb88));
      }
      uVar6 = uVar3;
      if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0xc80) != 0) {
        do {
          FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + 0xc88 + uVar6 * 0x18,
                        *(longlong *)(param_1 + 0x530) + uVar6 * 0x10,lVar4);
          FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + 0xd00 + uVar6 * 0x18,
                        *(longlong *)(param_1 + 0x538) + uVar6 * 0x10,lVar4);
          uVar8 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar8;
        } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xc80));
      }
      if (*(short *)(*(longlong *)(param_1 + 0x1a0) + 0xd78) != 0) {
        do {
          FUN_140317ec0(*(longlong *)(param_1 + 0x1a0) + (uVar3 + 0x90) * 0x18,
                        *(longlong *)(param_1 + 0x540) + uVar3 * 0x10,lVar4);
          FUN_140317fc0(*(longlong *)(param_1 + 0x1a0) + (uVar3 + 0x95) * 0x18,
                        *(longlong *)(param_1 + 0x548) + uVar3 * 0x10,lVar4);
          uVar8 = (int)uVar3 + 1;
          uVar3 = (ulonglong)uVar8;
        } while (uVar8 < *(ushort *)(*(longlong *)(param_1 + 0x1a0) + 0xd78));
      }
    }
    *(undefined1 *)(param_1 + 400) = 1;
  }
  return;
}



==== FUN_140312ff0 @ 140312ff0 size 241 ====
CALLERS: FUN_1402f39e0
CALLEES: FUN_14032d190

undefined8 * FUN_140312ff0(undefined8 *param_1)

{
  FUN_14032d190();
  *param_1 = &PTR_LAB_140b64260;
  param_1[0x8d] = 0;
  param_1[0x8c] = 0;
  param_1[0x8f] = 0;
  param_1[0x8e] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  return param_1;
}



==== FUN_140313b30 @ 140313b30 size 238 ====
CALLERS: FUN_1403133c0 FUN_140313c20
CALLEES: FUN_140313290 FUN_1403131d0

void FUN_140313b30(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x4c0) != 0) {
    FUN_140313290();
  }
  *(undefined8 *)(param_1 + 0x4c0) = 0;
  if (*(longlong *)(param_1 + 0x4e0) != 0) {
    FUN_140313290();
  }
  *(undefined8 *)(param_1 + 0x4e0) = 0;
  if (*(longlong *)(param_1 + 0x498) != 0) {
    FUN_1403131d0();
  }
  *(undefined8 *)(param_1 + 0x498) = 0;
  *(undefined8 *)(param_1 + 0x4a0) = 0;
  *(undefined8 *)(param_1 + 0x4a8) = 0;
  *(undefined8 *)(param_1 + 0x4b0) = 0;
  *(undefined8 *)(param_1 + 0x4b8) = 0;
  *(undefined8 *)(param_1 + 0x4c8) = 0;
  *(undefined8 *)(param_1 + 0x4d0) = 0;
  *(undefined8 *)(param_1 + 0x4d8) = 0;
  *(undefined8 *)(param_1 + 0x4e8) = 0;
  *(undefined8 *)(param_1 + 0x4f0) = 0;
  *(undefined8 *)(param_1 + 0x4f8) = 0;
  *(undefined8 *)(param_1 + 0x500) = 0;
  *(undefined8 *)(param_1 + 0x508) = 0;
  *(undefined8 *)(param_1 + 0x510) = 0;
  *(undefined8 *)(param_1 + 0x518) = 0;
  *(undefined8 *)(param_1 + 0x520) = 0;
  *(undefined8 *)(param_1 + 0x528) = 0;
  *(undefined8 *)(param_1 + 0x530) = 0;
  *(undefined8 *)(param_1 + 0x538) = 0;
  *(undefined8 *)(param_1 + 0x540) = 0;
  *(undefined8 *)(param_1 + 0x548) = 0;
  return;
}


