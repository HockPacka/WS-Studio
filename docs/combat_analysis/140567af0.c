
undefined4 FUN_140567af0(undefined8 param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  float fVar7;
  longlong lVar8;
  longlong lVar9;
  float *pfVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  
  lVar8 = FUN_140238780(param_2);
  lVar9 = FUN_14023e0c0(*(undefined4 *)(lVar8 + 0xc));
  if ((lVar9 == 0) || (uVar11 = *(uint *)(lVar9 + 4), (uVar11 & 1) == 0)) {
    return 0x67;
  }
  if (*(int *)(lVar8 + 8) == 0) {
    return 7;
  }
  if (3600000 < *(uint *)(lVar8 + 0x14)) {
    return 8;
  }
  uVar3 = *(uint *)(lVar8 + 0x1c);
  if (0x240c8400 < uVar3) {
    return 0xb;
  }
  uVar4 = *(uint *)(lVar8 + 0x18);
  if ((uVar4 != 0) && ((uVar11 & 4) == 0)) {
    return 0x69;
  }
  uVar13 = *(uint *)(lVar8 + 0x20) & 2;
  if (uVar13 == 0) {
    if (((uVar3 != 0) && ((uVar11 & 8) == 0)) && (uVar4 == 0)) {
      return 0x6a;
    }
    if (uVar3 < uVar4) {
      return 9;
    }
  }
  else {
    if ((uVar11 & 0x10) == 0) {
      return 0x6b;
    }
    if (uVar3 != 0) {
      return 0xb;
    }
  }
  if ((((*(uint *)(lVar8 + 0x14) != 0) || ((uVar3 != 0 && (*(int *)(lVar8 + 0xc) != 4)))) ||
      (uVar13 != 0)) &&
     ((lVar9 = FUN_1407a0fd0(param_1,*(undefined4 *)(lVar8 + 4)), lVar9 != 0 &&
      (*(int *)(*(longlong *)(lVar9 + 0x70) + 0x120) == 0)))) {
    return 0xc;
  }
  if ((*(int *)(lVar8 + 0x18) - 1U < 0xf9) && (*(int *)(lVar8 + 0x1c) != 0)) {
    return 9;
  }
  if (((*(int *)(lVar8 + 0x54) != 0) && (0x1f < *(uint *)(lVar8 + 0x4c))) ||
     ((*(int *)(lVar8 + 0x58) != 0 && (0x1f < *(uint *)(lVar8 + 0x50))))) {
    return 10;
  }
  switch(*(undefined4 *)(lVar8 + 0xc)) {
  case 1:
    if (0x1d < *(int *)(lVar8 + 0x24) - 1U) {
      return 0x11;
    }
    if (*(int *)(lVar8 + 0x28) <= *(int *)(lVar8 + 0x2c)) {
      if (*(int *)(lVar8 + 0x30) <= *(int *)(lVar8 + 0x34)) {
        uVar12 = 0;
        pfVar10 = (float *)(lVar8 + 0x90);
        bVar6 = false;
        while ((pfVar10[-4] == 0.0 || (*pfVar10 == 0.0))) {
          uVar12 = uVar12 + 1;
          pfVar10 = pfVar10 + 1;
          if (3 < uVar12) {
LAB_140567d82:
            if (*(int *)(lVar8 + 0x28) != 0) {
              return 0;
            }
            if (*(int *)(lVar8 + 0x2c) != 0) {
              return 0;
            }
            if (*(int *)(lVar8 + 0x30) != 0) {
              return 0;
            }
            if (*(int *)(lVar8 + 0x34) != 0) {
              return 0;
            }
            uVar11 = *(uint *)(lVar8 + 0x38);
            if ((int)uVar11 < 0) {
              uVar11 = 0x80000000 - uVar11;
            }
            if (0x54 < (int)((uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f))) {
              return 0;
            }
            if (bVar6) {
              return 0;
            }
            return 0x13;
          }
        }
        bVar6 = true;
        goto LAB_140567d82;
      }
    }
    return 0x12;
  case 2:
    if (*(int *)(lVar8 + 0x30) == 0) {
      return 0x10;
    }
    break;
  case 3:
    iVar5 = *(int *)(lVar8 + 0x24);
    fVar1 = *(float *)(lVar8 + 0x28);
    fVar2 = *(float *)(lVar8 + 0x2c);
    if (0xf < iVar5) {
      return 0x16;
    }
    if ((2 < iVar5 - 8U) && (iVar5 != 0xf)) {
      fVar7 = fVar1;
      if ((int)fVar1 < 0) {
        fVar7 = (float)(-0x80000000 - (int)fVar1);
      }
      if ((int)(((uint)fVar7 ^ (int)fVar7 >> 0x1f) - ((int)fVar7 >> 0x1f)) < 0x55) {
        fVar7 = fVar2;
        if ((int)fVar2 < 0) {
          fVar7 = (float)(-0x80000000 - (int)fVar2);
        }
        if ((int)(((uint)fVar7 ^ (int)fVar7 >> 0x1f) - ((int)fVar7 >> 0x1f)) < 0x55) {
          return 0x17;
        }
      }
    }
    if (fVar2 < fVar1) {
      return 0x18;
    }
    break;
  case 4:
    if (0x1b < *(uint *)(lVar8 + 0x24)) {
      return 0x24;
    }
    break;
  case 5:
  case 8:
  case 0xc:
  case 0x21:
  case 0x8a:
    if (2 < *(int *)(lVar8 + 0x10) - 1U) {
      return 0x15;
    }
    break;
  case 7:
    lVar8 = FUN_1407a0fd0(param_1,*(undefined4 *)(lVar8 + 4));
    if ((((lVar8 != 0) && (*(uint **)(lVar8 + 0x38) != (uint *)0x0)) &&
        (**(uint **)(lVar8 + 0x38) < 1000)) &&
       ((iVar5 = *(int *)(*(longlong *)(lVar8 + 0x70) + 0x7c), iVar5 - 2U < 4 || (iVar5 - 7U < 2))))
    {
      return 0x51;
    }
    break;
  case 0xb:
    if (((*(byte *)(lVar8 + 0x20) & 2) == 0) && (*(uint *)(lVar8 + 0x1c) < 200)) {
      return 0xd;
    }
    lVar9 = FUN_1402479c0(*(undefined4 *)(lVar8 + 0x24));
    if ((lVar9 == 0) || ((*(byte *)(lVar9 + 0x24) & 4) == 0)) {
      return 0xe;
    }
    goto LAB_140567cb7;
  case 0xe:
    if (0x10a < *(uint *)(lVar8 + 0x24)) {
      return 0x1f;
    }
    if (*(int *)(lVar8 + 0x28) == *(int *)(lVar8 + 4)) {
      return 0x21;
    }
    if (*(float *)(lVar8 + 0x2c) <= 0.0) {
      return 0x1d;
    }
    if (1.0 < *(float *)(lVar8 + 0x2c)) {
      return 0x1e;
    }
    if (1000 < *(uint *)(lVar8 + 0x38)) {
      return 0x22;
    }
    break;
  case 0xf:
    if (0x17 < *(uint *)(lVar8 + 0x24)) {
      return 0x23;
    }
    break;
  case 0x12:
    if (*(float *)(lVar8 + 0x24) <= 0.0) {
      return 0x54;
    }
    if ((((*(int *)(lVar8 + 0x28) < 1) || (*(int *)(lVar8 + 0x2c) < 1)) &&
        ((*(byte *)(lVar8 + 0x20) & 2) == 0)) && (*(int *)(lVar8 + 0x1c) == *(int *)(lVar8 + 0x14)))
    {
      return 0x55;
    }
    break;
  case 0x14:
    if (3 < *(byte *)(lVar8 + 0x24)) {
      return 0x65;
    }
    break;
  case 0x18:
    if (1000 < *(int *)(lVar8 + 0x28) + 1U) {
      return 0x5c;
    }
    if ((*(float *)(lVar8 + 0x30) < 0.0) || (1.0 < *(float *)(lVar8 + 0x30))) {
      return 0x5d;
    }
    break;
  case 0x1d:
    if (*(int *)(lVar8 + 0x34) == 0) {
      return 0x66;
    }
    break;
  case 0x1e:
    if (0x1d < *(int *)(lVar8 + 0x24) - 1U) {
      return 0x14;
    }
    break;
  case 0x26:
  case 0x2b:
  case 0x2c:
    if (*(int *)(lVar8 + 0x24) == 0) {
      return 0x10;
    }
    break;
  case 0x2d:
    if (*(int *)(lVar8 + 0x24) == 0) {
      return 0x10;
    }
    if (1 < *(uint *)(lVar8 + 0x28)) {
      return 0x10;
    }
    break;
  case 0x32:
    if (((*(byte *)(lVar8 + 0x20) & 2) == 0) && (*(uint *)(lVar8 + 0x1c) < 200)) {
      return 0xd;
    }
    lVar8 = FUN_14022f2c0(*(undefined4 *)(lVar8 + 0x24));
    if (lVar8 == 0) {
      return 0xe;
    }
    break;
  case 0x34:
    if (0x3e6 < *(int *)(lVar8 + 0x24) - 1U) {
      return 0x5b;
    }
    break;
  case 0x97:
    if (((*(byte *)(lVar8 + 0x20) & 2) == 0) && (*(uint *)(lVar8 + 0x1c) < 200)) {
      return 0xd;
    }
LAB_140567cb7:
    if (*(int *)(lVar8 + 0x28) == 0) {
      return 0xf;
    }
  }
  return 0;
}

