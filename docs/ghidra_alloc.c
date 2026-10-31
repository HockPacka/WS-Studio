
==== FUN_1402ed080 @ 1402ed080 size 279 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1407e4830 FUN_1402edc50 memcpy FUN_14018b280

void FUN_1402ed080(uint *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *_Dst;
  
  if (*param_1 != 1) {
    uVar1 = SUB168(ZEXT816(0xb8) * ZEXT816(1),0);
    if (SUB168(ZEXT816(0xb8) * ZEXT816(1),8) != 0) {
      uVar1 = 0xffffffffffffffff;
    }
    lVar2 = uVar1 + 8;
    if (0xfffffffffffffff7 < uVar1) {
      lVar2 = -1;
    }
    puVar3 = (undefined4 *)FUN_14018b280(lVar2,2);
    if (puVar3 == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
    }
    else {
      _Dst = puVar3 + 2;
      *puVar3 = 1;
      *(undefined8 *)(puVar3 + 4) = 0;
      *(undefined8 *)(puVar3 + 6) = 0;
      *(undefined8 *)(puVar3 + 8) = 0;
      *(undefined8 *)(puVar3 + 10) = 0;
      *(undefined8 *)(puVar3 + 0xc) = 0;
      *(undefined8 *)(puVar3 + 0xe) = 0;
      *(undefined8 *)(puVar3 + 0x10) = 0;
      *(undefined8 *)(puVar3 + 0x12) = 0;
      *(undefined8 *)(puVar3 + 0x14) = 0;
      *(undefined8 *)(puVar3 + 0x16) = 0;
      *(undefined8 *)(puVar3 + 0x18) = 0;
      *(undefined8 *)(puVar3 + 0x1a) = 0;
      *(undefined8 *)(puVar3 + 0x1c) = 0;
      *(undefined8 *)(puVar3 + 0x1e) = 0;
      *(undefined8 *)(puVar3 + 0x20) = 0;
      *(undefined8 *)(puVar3 + 0x22) = 0;
      *(undefined8 *)(puVar3 + 0x24) = 0;
      *(undefined8 *)(puVar3 + 0x26) = 0;
      *(undefined8 *)(puVar3 + 0x28) = 0;
      *(undefined8 *)(puVar3 + 0x2a) = 0;
      *(undefined8 *)(puVar3 + 0x2c) = 0;
    }
    uVar1 = 1;
    if (*param_1 == 0) {
      uVar1 = (ulonglong)*param_1;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),uVar1 * 0xb8);
    FUN_1407e4830(*(undefined8 *)(param_1 + 2),0,uVar1 * 0xb8);
    if (*(longlong *)(param_1 + 2) != 0) {
      FUN_1402edc50();
    }
    *param_1 = 1;
    *(undefined4 **)(param_1 + 2) = _Dst;
  }
  return;
}



==== FUN_1402ed1a0 @ 1402ed1a0 size 307 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1407e4830 memcpy FUN_14018b280 FUN_1402edcb0

void FUN_1402ed1a0(uint *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *_Dst;
  
  if (*param_1 != 1) {
    uVar1 = SUB168(ZEXT816(0x160) * ZEXT816(1),0);
    if (SUB168(ZEXT816(0x160) * ZEXT816(1),8) != 0) {
      uVar1 = 0xffffffffffffffff;
    }
    lVar2 = uVar1 + 0x10;
    if (0xffffffffffffffef < uVar1) {
      lVar2 = -1;
    }
    puVar3 = (undefined4 *)FUN_14018b280(lVar2,2);
    if (puVar3 == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
    }
    else {
      _Dst = puVar3 + 4;
      *puVar3 = 1;
      *(undefined8 *)(puVar3 + 8) = 0;
      *(undefined8 *)(puVar3 + 10) = 0;
      *(undefined8 *)(puVar3 + 0xc) = 0;
      *(undefined8 *)(puVar3 + 0xe) = 0;
      *(undefined8 *)(puVar3 + 0x10) = 0;
      *(undefined8 *)(puVar3 + 0x12) = 0;
      *(undefined8 *)(puVar3 + 0x14) = 0;
      *(undefined8 *)(puVar3 + 0x16) = 0;
      *(undefined8 *)(puVar3 + 0x18) = 0;
      *(undefined8 *)(puVar3 + 0x1a) = 0;
      *(undefined8 *)(puVar3 + 0x1c) = 0;
      *(undefined8 *)(puVar3 + 0x1e) = 0;
      *(undefined8 *)(puVar3 + 0x20) = 0;
      *(undefined8 *)(puVar3 + 0x22) = 0;
      *(undefined8 *)(puVar3 + 0x24) = 0;
      *(undefined8 *)(puVar3 + 0x26) = 0;
      *(undefined8 *)(puVar3 + 0x28) = 0;
      *(undefined8 *)(puVar3 + 0x2a) = 0;
      *(undefined8 *)(puVar3 + 0x2c) = 0;
      *(undefined8 *)(puVar3 + 0x2e) = 0;
      *(undefined8 *)(puVar3 + 0x30) = 0;
      *(undefined8 *)(puVar3 + 0x32) = 0;
      *(undefined8 *)(puVar3 + 0x34) = 0;
      *(undefined8 *)(puVar3 + 0x36) = 0;
    }
    uVar1 = 1;
    if (*param_1 == 0) {
      uVar1 = (ulonglong)*param_1;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),uVar1 * 0x160);
    FUN_1407e4830(*(undefined8 *)(param_1 + 2),0,uVar1 * 0x160);
    if (*(longlong *)(param_1 + 2) != 0) {
      FUN_1402edcb0();
    }
    *param_1 = 1;
    *(undefined4 **)(param_1 + 2) = _Dst;
  }
  return;
}



==== FUN_1402ed3e0 @ 1402ed3e0 size 273 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1407e4830 memcpy FUN_14018b280 FUN_1402edda0

void FUN_1402ed3e0(uint *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *_Dst;
  
  if (*param_1 != 1) {
    uVar1 = SUB168(ZEXT816(200) * ZEXT816(1),0);
    if (SUB168(ZEXT816(200) * ZEXT816(1),8) != 0) {
      uVar1 = 0xffffffffffffffff;
    }
    lVar2 = uVar1 + 8;
    if (0xfffffffffffffff7 < uVar1) {
      lVar2 = -1;
    }
    puVar3 = (undefined4 *)FUN_14018b280(lVar2,2);
    if (puVar3 == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
    }
    else {
      _Dst = puVar3 + 2;
      *puVar3 = 1;
      *(undefined8 *)(puVar3 + 4) = 0;
      *(undefined8 *)(puVar3 + 6) = 0;
      *(undefined8 *)(puVar3 + 0x10) = 0;
      *(undefined8 *)(puVar3 + 0x12) = 0;
      *(undefined8 *)(puVar3 + 0x14) = 0;
      *(undefined8 *)(puVar3 + 0x16) = 0;
      *(undefined8 *)(puVar3 + 0x18) = 0;
      *(undefined8 *)(puVar3 + 0x1a) = 0;
      *(undefined8 *)(puVar3 + 0x1e) = 0;
      *(undefined8 *)(puVar3 + 0x20) = 0;
      *(undefined8 *)(puVar3 + 0x22) = 0;
      *(undefined8 *)(puVar3 + 0x24) = 0;
      *(undefined8 *)(puVar3 + 0x28) = 0;
      *(undefined8 *)(puVar3 + 0x2a) = 0;
      *(undefined8 *)(puVar3 + 0x2c) = 0;
      *(undefined8 *)(puVar3 + 0x2e) = 0;
      *(undefined8 *)(puVar3 + 0x30) = 0;
      *(undefined8 *)(puVar3 + 0x32) = 0;
    }
    uVar1 = 1;
    if (*param_1 == 0) {
      uVar1 = (ulonglong)*param_1;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),uVar1 * 200);
    FUN_1407e4830(*(undefined8 *)(param_1 + 2),0,uVar1 * 200);
    if (*(longlong *)(param_1 + 2) != 0) {
      FUN_1402edda0();
    }
    *param_1 = 1;
    *(undefined4 **)(param_1 + 2) = _Dst;
  }
  return;
}



==== FUN_1402ed680 @ 1402ed680 size 205 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1407e4830 memcpy FUN_1402ee080 FUN_14018b280

void FUN_1402ed680(uint *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 *_Dst;
  
  if (*param_1 != 1) {
    uVar1 = SUB168(ZEXT816(0x40) * ZEXT816(1),0);
    if (SUB168(ZEXT816(0x40) * ZEXT816(1),8) != 0) {
      uVar1 = 0xffffffffffffffff;
    }
    lVar2 = uVar1 + 8;
    if (0xfffffffffffffff7 < uVar1) {
      lVar2 = -1;
    }
    puVar3 = (undefined4 *)FUN_14018b280(lVar2,2);
    if (puVar3 == (undefined4 *)0x0) {
      _Dst = (undefined8 *)0x0;
    }
    else {
      _Dst = (undefined8 *)(puVar3 + 2);
      *puVar3 = 1;
      *_Dst = 0;
      *(undefined8 *)(puVar3 + 4) = 0;
      *(undefined8 *)(puVar3 + 6) = 0;
      *(undefined8 *)(puVar3 + 8) = 0;
      *(undefined8 *)(puVar3 + 10) = 0;
      *(undefined8 *)(puVar3 + 0xc) = 0;
      *(undefined8 *)(puVar3 + 0xe) = 0;
      *(undefined8 *)(puVar3 + 0x10) = 0;
    }
    uVar1 = 1;
    if (*param_1 == 0) {
      uVar1 = (ulonglong)*param_1;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),uVar1 << 6);
    FUN_1407e4830(*(undefined8 *)(param_1 + 2),0,uVar1 << 6);
    if (*(longlong *)(param_1 + 2) != 0) {
      FUN_1402ee080();
    }
    *param_1 = 1;
    *(undefined8 **)(param_1 + 2) = _Dst;
  }
  return;
}



==== FUN_1402ed1a0 @ 1402ed1a0 size 307 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1407e4830 memcpy FUN_14018b280 FUN_1402edcb0

void FUN_1402ed1a0(uint *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *_Dst;
  
  if (*param_1 != 1) {
    uVar1 = SUB168(ZEXT816(0x160) * ZEXT816(1),0);
    if (SUB168(ZEXT816(0x160) * ZEXT816(1),8) != 0) {
      uVar1 = 0xffffffffffffffff;
    }
    lVar2 = uVar1 + 0x10;
    if (0xffffffffffffffef < uVar1) {
      lVar2 = -1;
    }
    puVar3 = (undefined4 *)FUN_14018b280(lVar2,2);
    if (puVar3 == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
    }
    else {
      _Dst = puVar3 + 4;
      *puVar3 = 1;
      *(undefined8 *)(puVar3 + 8) = 0;
      *(undefined8 *)(puVar3 + 10) = 0;
      *(undefined8 *)(puVar3 + 0xc) = 0;
      *(undefined8 *)(puVar3 + 0xe) = 0;
      *(undefined8 *)(puVar3 + 0x10) = 0;
      *(undefined8 *)(puVar3 + 0x12) = 0;
      *(undefined8 *)(puVar3 + 0x14) = 0;
      *(undefined8 *)(puVar3 + 0x16) = 0;
      *(undefined8 *)(puVar3 + 0x18) = 0;
      *(undefined8 *)(puVar3 + 0x1a) = 0;
      *(undefined8 *)(puVar3 + 0x1c) = 0;
      *(undefined8 *)(puVar3 + 0x1e) = 0;
      *(undefined8 *)(puVar3 + 0x20) = 0;
      *(undefined8 *)(puVar3 + 0x22) = 0;
      *(undefined8 *)(puVar3 + 0x24) = 0;
      *(undefined8 *)(puVar3 + 0x26) = 0;
      *(undefined8 *)(puVar3 + 0x28) = 0;
      *(undefined8 *)(puVar3 + 0x2a) = 0;
      *(undefined8 *)(puVar3 + 0x2c) = 0;
      *(undefined8 *)(puVar3 + 0x2e) = 0;
      *(undefined8 *)(puVar3 + 0x30) = 0;
      *(undefined8 *)(puVar3 + 0x32) = 0;
      *(undefined8 *)(puVar3 + 0x34) = 0;
      *(undefined8 *)(puVar3 + 0x36) = 0;
    }
    uVar1 = 1;
    if (*param_1 == 0) {
      uVar1 = (ulonglong)*param_1;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),uVar1 * 0x160);
    FUN_1407e4830(*(undefined8 *)(param_1 + 2),0,uVar1 * 0x160);
    if (*(longlong *)(param_1 + 2) != 0) {
      FUN_1402edcb0();
    }
    *param_1 = 1;
    *(undefined4 **)(param_1 + 2) = _Dst;
  }
  return;
}



==== FUN_1402ed080 @ 1402ed080 size 279 ====
CALLERS: FUN_1402eb270
CALLEES: FUN_1407e4830 FUN_1402edc50 memcpy FUN_14018b280

void FUN_1402ed080(uint *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *_Dst;
  
  if (*param_1 != 1) {
    uVar1 = SUB168(ZEXT816(0xb8) * ZEXT816(1),0);
    if (SUB168(ZEXT816(0xb8) * ZEXT816(1),8) != 0) {
      uVar1 = 0xffffffffffffffff;
    }
    lVar2 = uVar1 + 8;
    if (0xfffffffffffffff7 < uVar1) {
      lVar2 = -1;
    }
    puVar3 = (undefined4 *)FUN_14018b280(lVar2,2);
    if (puVar3 == (undefined4 *)0x0) {
      _Dst = (undefined4 *)0x0;
    }
    else {
      _Dst = puVar3 + 2;
      *puVar3 = 1;
      *(undefined8 *)(puVar3 + 4) = 0;
      *(undefined8 *)(puVar3 + 6) = 0;
      *(undefined8 *)(puVar3 + 8) = 0;
      *(undefined8 *)(puVar3 + 10) = 0;
      *(undefined8 *)(puVar3 + 0xc) = 0;
      *(undefined8 *)(puVar3 + 0xe) = 0;
      *(undefined8 *)(puVar3 + 0x10) = 0;
      *(undefined8 *)(puVar3 + 0x12) = 0;
      *(undefined8 *)(puVar3 + 0x14) = 0;
      *(undefined8 *)(puVar3 + 0x16) = 0;
      *(undefined8 *)(puVar3 + 0x18) = 0;
      *(undefined8 *)(puVar3 + 0x1a) = 0;
      *(undefined8 *)(puVar3 + 0x1c) = 0;
      *(undefined8 *)(puVar3 + 0x1e) = 0;
      *(undefined8 *)(puVar3 + 0x20) = 0;
      *(undefined8 *)(puVar3 + 0x22) = 0;
      *(undefined8 *)(puVar3 + 0x24) = 0;
      *(undefined8 *)(puVar3 + 0x26) = 0;
      *(undefined8 *)(puVar3 + 0x28) = 0;
      *(undefined8 *)(puVar3 + 0x2a) = 0;
      *(undefined8 *)(puVar3 + 0x2c) = 0;
    }
    uVar1 = 1;
    if (*param_1 == 0) {
      uVar1 = (ulonglong)*param_1;
    }
    memcpy(_Dst,*(void **)(param_1 + 2),uVar1 * 0xb8);
    FUN_1407e4830(*(undefined8 *)(param_1 + 2),0,uVar1 * 0xb8);
    if (*(longlong *)(param_1 + 2) != 0) {
      FUN_1402edc50();
    }
    *param_1 = 1;
    *(undefined4 **)(param_1 + 2) = _Dst;
  }
  return;
}


