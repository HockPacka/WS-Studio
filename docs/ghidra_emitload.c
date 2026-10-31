
==== FUN_14030bcc0 @ 14030bcc0 size 1803 ====
CALLERS: FUN_14030c6a0
CALLEES: FUN_14030eb90 FUN_14030eb00 FUN_14030ebf0 FUN_14030ba20 FUN_14030ed20 FUN_1402ca3c0

undefined8 FUN_14030bcc0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar3;
  
  uVar1 = FUN_14030ba20(param_1,param_2,param_3 + 8);
  if ((((((((-1 < (int)uVar1) &&
           (uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x68), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
         ((uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1 &&
          (uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1)))) &&
        (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
       (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
         (uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1)) &&
        ((uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1 &&
         (((uVar1 = FUN_14030ebf0(param_1), -1 < (int)uVar1 &&
           (uVar1 = FUN_14030ebf0(param_1,param_2,param_3 + 0x140), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x158), -1 < (int)uVar1)))))))) &&
      ((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
       (uVar1 = FUN_14030ebf0(param_1), -1 < (int)uVar1)))) &&
     (((uVar1 = FUN_14030ed20(param_1,param_2,param_3 + 0x1a0), -1 < (int)uVar1 &&
       (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
         (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
        ((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
         (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
           (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)) &&
          (uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1)))))))) &&
      (((uVar1 = FUN_14030ed20(param_1), -1 < (int)uVar1 &&
        (uVar1 = FUN_1402ca3c0(param_1), -1 < (int)uVar1)) &&
       (uVar1 = FUN_14030eb00(param_1), -1 < (int)uVar1)))))) {
    uVar5 = 0;
    uVar4 = uVar5;
    do {
      uVar3 = uVar5;
      do {
        uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + ((uVar3 + uVar4 * 5) * 3 + 0x53) * 8);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      uVar2 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar2;
      uVar3 = uVar5;
    } while (uVar2 < 2);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0x388);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar4 + 0x2b) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x30) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0x500);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0x578);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0x5f8);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0x670);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_1402ca3c0(param_1,param_2,param_3 + (uVar4 + 0x4a) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x4f) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar4 = uVar5;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030ed20(param_1,param_2,param_3 + (uVar4 + 0x5a) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar4 + 1;
      uVar3 = uVar5;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    do {
      uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x5f) * 0x18);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 5);
    uVar1 = FUN_14030ed20(param_1);
    uVar4 = uVar5;
    if (-1 < (int)uVar1) {
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0x9a0);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0xa18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + (uVar4 + 0x71) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x76) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0xb90);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0xc08);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + uVar4 * 0x18 + 0xc88);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + uVar3 * 0x18 + 0xd00);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar4 = uVar5;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030ed20(param_1,param_2,param_3 + (uVar4 + 0x90) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar4 + 1;
        uVar3 = uVar5;
        uVar4 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      do {
        uVar1 = FUN_14030eb90(param_1,param_2,param_3 + (uVar3 + 0x95) * 0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < 5);
      uVar4 = *(longlong *)(param_3 + 0xec0) + param_2;
      if ((uVar4 < *param_1) ||
         (param_1[1] <
          *(longlong *)(param_3 + 0xec0) + (ulonglong)*(uint *)(param_3 + 0xeb8) * 2 + param_2)) {
        uVar1 = 0x80004005;
      }
      else {
        if (*(uint *)(param_3 + 0xeb8) != 0) {
          uVar5 = uVar4;
        }
        uVar1 = 0;
        *(ulonglong *)(param_3 + 0xec0) = uVar5;
      }
    }
  }
  return uVar1;
}



==== FUN_14030ed20 @ 14030ed20 size 93 ====
CALLERS: FUN_14030ca00 FUN_14030c3d0 FUN_14030cac0 FUN_14030c6a0 FUN_14030f4e0 FUN_14030bcc0 FUN_14030c7d0 FUN_14030b740 FUN_14030c930 FUN_14030f7c0
CALLEES:

undefined8 FUN_14030ed20(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 2 + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
    }
  }
  return 0x80004005;
}



==== FUN_14030eb90 @ 14030eb90 size 92 ====
CALLERS: FUN_14030c3d0 FUN_14030cac0 FUN_14030ee60 FUN_14030ac30 FUN_14030c6a0 FUN_14030bcc0 FUN_14030aba0
CALLEES:

undefined8 FUN_14030eb90(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
    }
  }
  return 0x80004005;
}



==== FUN_1402ca3c0 @ 1402ca3c0 size 93 ====
CALLERS: FUN_14030ca00 FUN_14030c3d0 FUN_14030cac0 FUN_1402c8f30 FUN_14030ac30 FUN_14030a9d0 FUN_14030bcc0 FUN_14030c7d0 FUN_14030aba0 FUN_14030c930
CALLEES:

undefined8 FUN_1402ca3c0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      *(ulonglong *)(param_3 + 2) = uVar3;
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
    }
  }
  return 0x80004005;
}



==== FUN_14030ebf0 @ 14030ebf0 size 134 ====
CALLERS: FUN_14030ca00 FUN_14030c3d0 FUN_14030ad40 FUN_14030bcc0
CALLEES:

undefined8 FUN_14030ebf0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      *(ulonglong *)(param_3 + 2) = uVar3;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 6 + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
      return 0x80004005;
    }
  }
  return 0x80004005;
}



==== FUN_14030eb00 @ 14030eb00 size 134 ====
CALLERS: FUN_14030ad40 FUN_14030aed0 FUN_14030a9d0 FUN_14030bcc0
CALLEES:

undefined8 FUN_14030eb00(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      *(ulonglong *)(param_3 + 2) = uVar3;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 0xc + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
      return 0x80004005;
    }
  }
  return 0x80004005;
}



==== FUN_14030ba20 @ 14030ba20 size 658 ====
CALLERS: FUN_14030bcc0
CALLEES: FUN_14030b7c0 FUN_14030b3e0 FUN_14030b5c0 FUN_14030b4a0 FUN_14030ef10 FUN_14030b740

undefined8 FUN_14030ba20(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint *puVar4;
  
  if (*(longlong *)(param_3 + 0x18) == -1) {
    *(undefined8 *)(param_3 + 0x18) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x18) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 1) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x18) = uVar3;
  }
  uVar2 = FUN_14030ef10(param_1,param_2,param_3 + 0x20);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (*(longlong *)(param_3 + 0x28) == -1) {
    *(undefined8 *)(param_3 + 0x28) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x28) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 0x10) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x28) = uVar3;
    puVar4 = (uint *)(param_1[2] + uVar3);
    uVar1 = *(longlong *)(puVar4 + 2) + uVar3 + 0x10;
    if (uVar1 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < *(longlong *)(puVar4 + 2) + (ulonglong)*puVar4 * 0xc + uVar3 + 0x10) {
      return 0x80004005;
    }
    uVar3 = 0;
    if (*puVar4 != 0) {
      uVar3 = uVar1;
    }
    *(ulonglong *)(puVar4 + 2) = uVar3;
  }
  if (*(longlong *)(param_3 + 0x30) == -1) {
    *(undefined8 *)(param_3 + 0x30) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x30) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 0x30) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x30) = uVar3;
    uVar2 = FUN_14030b3e0(param_1,uVar3 + 0x30,param_1[2] + uVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (*(longlong *)(param_3 + 0x38) == -1) {
    *(undefined8 *)(param_3 + 0x38) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x38) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 0x48) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x38) = uVar3;
    uVar2 = FUN_14030b4a0(param_1,uVar3 + 0x50,param_1[2] + uVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (*(longlong *)(param_3 + 0x40) == -1) {
    *(undefined8 *)(param_3 + 0x40) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x40) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 0x60) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x40) = uVar3;
    uVar2 = FUN_14030b5c0(param_1,uVar3 + 0x60,param_1[2] + uVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (*(longlong *)(param_3 + 0x48) == -1) {
    *(undefined8 *)(param_3 + 0x48) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x48) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 0x30) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x48) = uVar3;
    uVar2 = FUN_14030b3e0(param_1,uVar3 + 0x30,param_1[2] + uVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (*(longlong *)(param_3 + 0x50) == -1) {
    *(undefined8 *)(param_3 + 0x50) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x50) + param_2;
    if (uVar3 < *param_1) {
      return 0x80004005;
    }
    if (param_1[1] < uVar3 + 0x40) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x50) = uVar3;
    uVar2 = FUN_14030b740(param_1,uVar3 + 0x40,param_1[2] + uVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  if (*(longlong *)(param_3 + 0x58) == -1) {
    *(undefined8 *)(param_3 + 0x58) = 0;
  }
  else {
    uVar3 = *(longlong *)(param_3 + 0x58) + param_2;
    if ((uVar3 < *param_1) || (param_1[1] < uVar3 + 0x90)) {
      return 0x80004005;
    }
    *(ulonglong *)(param_3 + 0x58) = uVar3;
    uVar2 = FUN_14030b7c0(param_1,uVar3 + 0x90,param_1[2] + uVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  return 0;
}



==== FUN_14030c3d0 @ 14030c3d0 size 713 ====
CALLERS: FUN_14030c6a0
CALLEES: FUN_14030eb90 FUN_14030ebf0 FUN_14030ed20 FUN_1402ca3c0

undefined8 FUN_14030c3d0(ulonglong *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = *(longlong *)(param_3 + 0x10) + param_2;
  if ((uVar6 < *param_1) ||
     (param_1[1] < *(longlong *)(param_3 + 0x10) + (ulonglong)*(uint *)(param_3 + 8) * 0xc + param_2
     )) {
    return 0x80004005;
  }
  uVar3 = 0;
  if (*(uint *)(param_3 + 8) != 0) {
    uVar3 = uVar6;
  }
  *(ulonglong *)(param_3 + 0x10) = uVar3;
  uVar2 = FUN_14030ebf0(param_1,param_2,param_3 + 0x30);
  if (-1 < (int)uVar2) {
    uVar6 = 0;
    do {
      uVar3 = 0;
      do {
        uVar2 = FUN_1402ca3c0(param_1,param_2,param_3 + ((uVar3 + uVar6 * 5) * 3 + 10) * 8);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        uVar5 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar5;
      } while (uVar5 < 5);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 2);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + uVar6 * 0x18 + 0x140);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + uVar6 * 0x18 + 0x1c0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar6 = 0;
    do {
      uVar2 = FUN_14030eb90(param_1,param_2,param_3 + (uVar6 * 3 + 0x47) * 8);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < 5);
    uVar5 = 0;
    puVar4 = (ulonglong *)(param_3 + 0x2c8);
    do {
      uVar6 = puVar4[-1] + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      uVar1 = (uint)puVar4[-2];
      if (param_1[1] < puVar4[-1] + (ulonglong)uVar1 * 4 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      puVar4[-1] = uVar3;
      uVar6 = *puVar4 + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *puVar4 + (ulonglong)uVar1 * 2 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      uVar5 = uVar5 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 3;
    } while (uVar5 < 5);
    uVar5 = 0;
    puVar4 = (ulonglong *)(param_3 + 0x340);
    do {
      uVar6 = puVar4[-1] + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      uVar1 = (uint)puVar4[-2];
      if (param_1[1] < puVar4[-1] + (ulonglong)uVar1 * 4 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      puVar4[-1] = uVar3;
      uVar6 = *puVar4 + param_2;
      if (uVar6 < *param_1) {
        return 0x80004005;
      }
      if (param_1[1] < *puVar4 + (ulonglong)uVar1 + param_2) {
        return 0x80004005;
      }
      uVar3 = 0;
      if (uVar1 != 0) {
        uVar3 = uVar6;
      }
      uVar5 = uVar5 + 1;
      *puVar4 = uVar3;
      puVar4 = puVar4 + 3;
    } while (uVar5 < 5);
    uVar2 = FUN_14030ed20(param_1,param_2,param_3 + 0x418);
    if ((((-1 < (int)uVar2) && (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)) &&
        (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)) &&
       ((uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2 &&
        (uVar2 = FUN_14030ed20(param_1), -1 < (int)uVar2)))) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



==== FUN_14030ebf0 @ 14030ebf0 size 134 ====
CALLERS: FUN_14030ca00 FUN_14030c3d0 FUN_14030ad40 FUN_14030bcc0
CALLEES:

undefined8 FUN_14030ebf0(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar1) {
    uVar2 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar2 * 4 + param_2 <= param_1[1]) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar1;
      }
      uVar1 = *(longlong *)(param_3 + 4) + param_2;
      *(ulonglong *)(param_3 + 2) = uVar3;
      if ((*param_1 <= uVar1) &&
         (*(longlong *)(param_3 + 4) + (ulonglong)uVar2 * 6 + param_2 <= param_1[1])) {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar1;
        }
        *(ulonglong *)(param_3 + 4) = uVar3;
        return 0;
      }
      return 0x80004005;
    }
  }
  return 0x80004005;
}



==== FUN_14030ed80 @ 14030ed80 size 223 ====
CALLERS: FUN_14030f3f0
CALLEES:

undefined8 FUN_14030ed80(ulonglong *param_1,longlong param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = *(longlong *)(param_3 + 2) + param_2;
  if (*param_1 <= uVar6) {
    uVar5 = *param_3;
    if (*(longlong *)(param_3 + 2) + (ulonglong)uVar5 * 0x20 + param_2 <= param_1[1]) {
      uVar1 = 0;
      if (uVar5 != 0) {
        uVar1 = uVar6;
      }
      uVar6 = 0;
      *(ulonglong *)(param_3 + 2) = uVar1;
      lVar4 = (ulonglong)uVar5 * 0x20 + uVar1;
      if (uVar5 != 0) {
        do {
          lVar3 = uVar6 * 0x20 + param_1[2] + *(longlong *)(param_3 + 2);
          uVar1 = *(longlong *)(lVar3 + 0x10) + lVar4;
          if (uVar1 < *param_1) {
            return 0x80004005;
          }
          uVar5 = *(uint *)(lVar3 + 8);
          if (param_1[1] < *(longlong *)(lVar3 + 0x10) + (ulonglong)uVar5 * 4 + lVar4) {
            return 0x80004005;
          }
          uVar2 = 0;
          if (uVar5 != 0) {
            uVar2 = uVar1;
          }
          *(ulonglong *)(lVar3 + 0x10) = uVar2;
          uVar1 = *(longlong *)(lVar3 + 0x18) + lVar4;
          if (uVar1 < *param_1) {
            return 0x80004005;
          }
          if (param_1[1] < *(longlong *)(lVar3 + 0x18) + (ulonglong)uVar5 * 2 + lVar4) {
            return 0x80004005;
          }
          uVar2 = 0;
          if (uVar5 != 0) {
            uVar2 = uVar1;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
          *(ulonglong *)(lVar3 + 0x18) = uVar2;
        } while (uVar5 < *param_3);
      }
      return 0;
    }
  }
  return 0x80004005;
}


