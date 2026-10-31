
==== FUN_14004fe00 @ 14004fe00 size 3732 ====
CALLERS: FUN_140051530
CALLEES: FUN_1402338a0 memcpy FUN_14018db00 FUN_14018b280 FUN_1400518a0 __security_check_cookie FUN_1407e4830 FUN_140001e60

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

void FUN_14004fe00(longlong param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined4 *puVar8;
  undefined8 *_Dst;
  void *pvVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  longlong *plVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  longlong lVar20;
  undefined1 auStack_1f8 [32];
  uint local_1d8;
  longlong local_1d0;
  longlong local_1c8;
  ulonglong local_1c0;
  ulonglong local_1b8 [4];
  ulonglong local_198 [18];
  ulonglong local_108 [24];
  ulonglong local_48;
  
  local_48 = DAT_140c0f7b0 ^ (ulonglong)auStack_1f8;
  iVar5 = DAT_140c3b950;
  if (*DAT_140c63750 < DAT_140c3b950) {
    iVar5 = *DAT_140c63750;
  }
  uVar2 = *(undefined4 *)(&DAT_140c3b960 + (longlong)iVar5 * 4);
  local_1d0 = param_1;
  if (DAT_140c63628 != 0) {
    uVar4 = FUN_1400518a0(DAT_140c63628,0x62,2);
    (**(code **)(*DAT_140c65848 + 0x38))(DAT_140c65848,uVar4,uVar2);
  }
  iVar5 = DAT_140c3b570;
  if (*DAT_140c63750 < DAT_140c3b570) {
    iVar5 = *DAT_140c63750;
  }
  uVar2 = *(undefined4 *)(&DAT_140c3b580 + (longlong)iVar5 * 4);
  if (DAT_140c63628 != 0) {
    uVar4 = FUN_1400518a0(DAT_140c63628,99,2);
    (**(code **)(*DAT_140c65848 + 0x38))(DAT_140c65848,uVar4,uVar2);
  }
  iVar5 = DAT_140c3b600;
  if (*DAT_140c63750 < DAT_140c3b600) {
    iVar5 = *DAT_140c63750;
  }
  uVar2 = *(undefined4 *)(&DAT_140c3b610 + (longlong)iVar5 * 4);
  if (DAT_140c63628 != 0) {
    uVar4 = FUN_1400518a0(DAT_140c63628,100,2);
    (**(code **)(*DAT_140c65848 + 0x38))(DAT_140c65848,uVar4,uVar2);
  }
  iVar5 = DAT_140c3b660;
  if (*DAT_140c63750 < DAT_140c3b660) {
    iVar5 = *DAT_140c63750;
  }
  uVar2 = *(undefined4 *)(&DAT_140c3b670 + (longlong)iVar5 * 4);
  if (DAT_140c63628 != 0) {
    uVar4 = FUN_1400518a0(DAT_140c63628,0x65,2);
    (**(code **)(*DAT_140c65848 + 0x38))(DAT_140c65848,uVar4,uVar2);
  }
  iVar5 = DAT_140c3b6f0;
  if (*DAT_140c63750 < DAT_140c3b6f0) {
    iVar5 = *DAT_140c63750;
  }
  uVar2 = *(undefined4 *)(&DAT_140c3b700 + (longlong)iVar5 * 4);
  if (DAT_140c63628 != 0) {
    uVar4 = FUN_1400518a0(DAT_140c63628,0x66,2);
    (**(code **)(*DAT_140c65848 + 0x38))(DAT_140c65848,uVar4,uVar2);
  }
  iVar5 = DAT_140c3b750;
  if (*DAT_140c63750 < DAT_140c3b750) {
    iVar5 = *DAT_140c63750;
  }
  uVar2 = *(undefined4 *)(&DAT_140c3b760 + (longlong)iVar5 * 4);
  if (DAT_140c63628 != 0) {
    uVar4 = FUN_1400518a0(DAT_140c63628,0x67,2);
    (**(code **)(*DAT_140c65848 + 0x38))(DAT_140c65848,uVar4,uVar2);
  }
  lVar12 = param_1 + 0x2d0;
  uVar14 = 3;
  do {
    (**(code **)(*DAT_140c65848 + 0x28))(DAT_140c65848,lVar12,0);
    lVar12 = lVar12 + 8;
    uVar14 = uVar14 - 1;
  } while (uVar14 != 0);
  uVar19 = 0;
  local_1b8[0] = 0;
  local_1b8[1] = uVar14;
  local_1b8[2] = uVar14;
  local_108[0] = uVar14;
  FUN_1407e4830(local_108 + 1,0,0xb0);
  local_198[0] = uVar14;
  FUN_1407e4830(local_198 + 1,0,0x80);
  uVar11 = 0;
  local_1c0 = uVar14;
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c64ca4 == 0) && (iVar5 = FUN_1402338a0(), -1 < iVar5)) {
      local_1d8 = (**(code **)(*DAT_140c63d88 + 0x28))();
      goto LAB_1400500f5;
    }
  }
  else {
    local_1d8 = (*DAT_140c63838)(&PTR_u_SoundEvent_140a6ce78,DAT_140c63858);
LAB_1400500f5:
    uVar15 = local_108[4];
    uVar16 = local_108[7];
    uVar17 = local_108[5];
    uVar18 = local_198[0xd];
    uVar10 = local_1d8;
    if (local_1d8 != 0) {
      do {
        if (DAT_140c63848 == (code *)0x0) {
          if (DAT_140c64ca4 == 0) {
            iVar5 = FUN_1402338a0();
            if (iVar5 < 0) {
              lVar12 = 0;
              uVar10 = local_1d8;
            }
            else {
              lVar12 = (**(code **)(*DAT_140c63d88 + 0x20))(DAT_140c63d88,uVar11);
              uVar10 = local_1d8;
            }
          }
          else {
            lVar12 = 0;
          }
        }
        else {
          lVar12 = (*DAT_140c63848)(&PTR_u_SoundEvent_140a6ce78,uVar11,DAT_140c63858);
          uVar10 = local_1d8;
        }
        uVar3 = *(uint *)(lVar12 + 0x38);
        if ((uVar3 >> 0x10 & 1) == 0) {
          if ((uVar3 & 2) != 0) {
            uVar19 = uVar19 + 1;
          }
          if ((uVar3 & 4) != 0) {
            uVar14 = uVar14 + 1;
          }
          if ((uVar3 & 8) != 0) {
            local_108[1] = local_108[1] + 1;
          }
          if ((uVar3 & 0x10) != 0) {
            local_108[3] = local_108[3] + 1;
          }
          if ((uVar3 & 0x20) != 0) {
            uVar16 = uVar16 + 1;
          }
          if ((uVar3 & 0x40) != 0) {
            uVar17 = uVar17 + 1;
          }
          if ((char)uVar3 < '\0') {
            local_108[2] = local_108[2] + 1;
          }
          if ((uVar3 >> 8 & 1) != 0) {
            uVar15 = uVar15 + 1;
          }
          if ((uVar3 >> 9 & 1) != 0) {
            local_198[1] = local_198[1] + 1;
          }
          if ((uVar3 >> 10 & 1) != 0) {
            local_198[3] = local_198[3] + 1;
          }
          if ((uVar3 >> 0xb & 1) != 0) {
            local_198[4] = local_198[4] + 1;
          }
          if ((uVar3 >> 0xc & 1) != 0) {
            local_198[0x10] = local_198[0x10] + 1;
          }
          if ((uVar3 >> 0xd & 1) != 0) {
            local_198[5] = local_198[5] + 1;
          }
          if ((uVar3 >> 0xe & 1) != 0) {
            local_198[0xc] = local_198[0xc] + 1;
          }
          if ((uVar3 >> 0xf & 1) != 0) {
            uVar18 = uVar18 + 1;
          }
        }
        else {
          local_1c0 = local_1c0 + 1;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar10);
      local_108[4] = uVar15;
      local_1b8[1] = uVar14;
      local_198[0xd] = uVar18;
      local_1b8[0] = uVar19;
      local_108[7] = uVar16;
      local_108[5] = uVar17;
      param_1 = local_1d0;
    }
  }
  plVar13 = (longlong *)(param_1 + 0x300);
  uVar14 = 0;
  do {
    uVar19 = local_1b8[uVar14];
    if (uVar19 < (ulonglong)plVar13[1]) {
      plVar13[1] = uVar19;
    }
    puVar6 = (undefined8 *)*plVar13;
    if (uVar19 == 0) {
      puVar6 = (undefined8 *)0x0;
    }
    else {
      lVar12 = uVar19 * 8 + 0x10;
      if ((puVar6 == (undefined8 *)0x0) ||
         (iVar5 = (**(code **)puVar6[-2])(puVar6 + -2,lVar12), iVar5 == 0)) {
        puVar6 = (undefined8 *)FUN_14018b280(lVar12,0);
        if (puVar6 != (undefined8 *)0x0) {
          *puVar6 = &PTR_LAB_140b55060;
          puVar6[1] = uVar19;
        }
        puVar6 = puVar6 + 2;
      }
      else {
        puVar6[-1] = uVar19;
      }
    }
    if ((undefined8 *)*plVar13 != puVar6) {
      memcpy(puVar6,(undefined8 *)*plVar13,plVar13[1] << 3);
      lVar12 = *plVar13;
      if (lVar12 != 0) {
        (**(code **)(*(longlong *)(lVar12 + -0x10) + 8))(lVar12 + -0x10);
      }
      *plVar13 = (longlong)puVar6;
    }
    uVar14 = uVar14 + 1;
    plVar13 = plVar13 + 2;
  } while (uVar14 < 3);
  uVar14 = 0;
  plVar13 = (longlong *)(local_1d0 + 0x330);
  do {
    uVar19 = local_108[uVar14];
    if (uVar19 < (ulonglong)plVar13[1]) {
      plVar13[1] = uVar19;
    }
    puVar6 = (undefined8 *)*plVar13;
    if (uVar19 == 0) {
      puVar6 = (undefined8 *)0x0;
    }
    else {
      lVar12 = uVar19 * 8 + 0x10;
      if ((puVar6 == (undefined8 *)0x0) ||
         (iVar5 = (**(code **)puVar6[-2])(puVar6 + -2,lVar12), iVar5 == 0)) {
        puVar6 = (undefined8 *)FUN_14018b280(lVar12,0);
        if (puVar6 != (undefined8 *)0x0) {
          *puVar6 = &PTR_LAB_140b55060;
          puVar6[1] = uVar19;
        }
        puVar6 = puVar6 + 2;
      }
      else {
        puVar6[-1] = uVar19;
      }
    }
    if ((undefined8 *)*plVar13 != puVar6) {
      memcpy(puVar6,(undefined8 *)*plVar13,plVar13[1] << 3);
      lVar12 = *plVar13;
      if (lVar12 != 0) {
        (**(code **)(*(longlong *)(lVar12 + -0x10) + 8))(lVar12 + -0x10);
      }
      *plVar13 = (longlong)puVar6;
    }
    uVar14 = uVar14 + 1;
    plVar13 = plVar13 + 2;
  } while (uVar14 < 0x17);
  uVar14 = 0;
  plVar13 = (longlong *)(local_1d0 + 0x4a0);
  do {
    uVar19 = local_198[uVar14];
    if (uVar19 < (ulonglong)plVar13[1]) {
      plVar13[1] = uVar19;
    }
    puVar6 = (undefined8 *)*plVar13;
    if (uVar19 == 0) {
      puVar6 = (undefined8 *)0x0;
    }
    else {
      lVar12 = uVar19 * 8 + 0x10;
      if ((puVar6 == (undefined8 *)0x0) ||
         (iVar5 = (**(code **)puVar6[-2])(puVar6 + -2,lVar12), iVar5 == 0)) {
        puVar6 = (undefined8 *)FUN_14018b280(lVar12,0);
        if (puVar6 != (undefined8 *)0x0) {
          *puVar6 = &PTR_LAB_140b55060;
          puVar6[1] = uVar19;
        }
        puVar6 = puVar6 + 2;
      }
      else {
        puVar6[-1] = uVar19;
      }
    }
    if ((undefined8 *)*plVar13 != puVar6) {
      memcpy(puVar6,(undefined8 *)*plVar13,plVar13[1] << 3);
      lVar12 = *plVar13;
      if (lVar12 != 0) {
        (**(code **)(*(longlong *)(lVar12 + -0x10) + 8))(lVar12 + -0x10);
      }
      *plVar13 = (longlong)puVar6;
    }
    uVar19 = local_1c0;
    lVar12 = local_1d0;
    uVar14 = uVar14 + 1;
    plVar13 = plVar13 + 2;
  } while (uVar14 < 0x11);
  lVar20 = 0;
  local_1c8 = 0;
  puVar6 = (undefined8 *)0x0;
  if (local_1c0 != 0) {
    puVar7 = (undefined8 *)FUN_14018b280(local_1c0 * 4 + 0x10,0);
    if (puVar7 != (undefined8 *)0x0) {
      puVar7[1] = uVar19;
      *puVar7 = &PTR_LAB_140b55060;
    }
    if (puVar7 + 2 != (undefined8 *)0x0) {
      puVar6 = puVar7 + 2;
    }
  }
  uVar11 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c64ca4 != 0) || (iVar5 = FUN_1402338a0(), iVar5 < 0)) goto LAB_140050c35;
    local_1d8 = (**(code **)(*DAT_140c63d88 + 0x28))();
  }
  else {
    local_1d8 = (*DAT_140c63838)(&PTR_u_SoundEvent_140a6ce78,DAT_140c63858);
  }
  puVar7 = puVar6;
  if (local_1d8 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if (DAT_140c64ca4 == 0) {
          iVar5 = FUN_1402338a0();
          if (iVar5 < 0) {
            puVar8 = (undefined4 *)0x0;
          }
          else {
            puVar8 = (undefined4 *)(**(code **)(*DAT_140c63d88 + 0x20))(DAT_140c63d88,uVar11);
          }
        }
        else {
          puVar8 = (undefined4 *)0x0;
        }
      }
      else {
        puVar8 = (undefined4 *)(*DAT_140c63848)(&PTR_u_SoundEvent_140a6ce78,uVar11,DAT_140c63858);
      }
      puVar6 = puVar7;
      if (((uint)puVar8[0xe] >> 0x10 & 1) == 0) {
        if ((puVar8[0xe] & 2) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x308);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x300),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x300) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x300),*(longlong *)(lVar12 + 0x308) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x300);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x300) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x308) = lVar20;
        }
        if ((*(byte *)(puVar8 + 0xe) & 4) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x318);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x310),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x310) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x310),*(longlong *)(lVar12 + 0x318) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x310);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x310) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x318) = lVar20;
        }
        if ((*(byte *)(puVar8 + 0xe) & 8) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x348);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x340),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x340) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x340),*(longlong *)(lVar12 + 0x348) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x340);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x340) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x348) = lVar20;
        }
        if ((*(byte *)(puVar8 + 0xe) & 0x10) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x368);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x360),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x360) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x360),*(longlong *)(lVar12 + 0x368) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x360);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x360) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x368) = lVar20;
        }
        if ((*(byte *)(puVar8 + 0xe) & 0x20) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x3a8);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x3a0),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x3a0) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x3a0),*(longlong *)(lVar12 + 0x3a8) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x3a0);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x3a0) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x3a8) = lVar20;
        }
        if ((*(byte *)(puVar8 + 0xe) & 0x40) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x388);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x380),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x380) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x380),*(longlong *)(lVar12 + 0x388) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x380);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x380) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x388) = lVar20;
        }
        if ((*(byte *)(puVar8 + 0xe) & 0x80) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x358);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x350),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x350) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x350),*(longlong *)(lVar12 + 0x358) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x350);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x350) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x358) = lVar20;
        }
        if ((puVar8[0xe] & 0x100) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x378);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x370),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x370) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x370),*(longlong *)(lVar12 + 0x378) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x370);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x370) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x378) = lVar20;
        }
        if ((puVar8[0xe] & 0x200) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x4b8);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x4b0),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x4b0) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x4b0),*(longlong *)(lVar12 + 0x4b8) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x4b0);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x4b0) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x4b8) = lVar20;
        }
        if ((puVar8[0xe] & 0x400) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x4d8);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x4d0),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x4d0) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x4d0),*(longlong *)(lVar12 + 0x4d8) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x4d0);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x4d0) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x4d8) = lVar20;
        }
        if ((puVar8[0xe] & 0x800) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x4e8);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x4e0),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x4e0) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x4e0),*(longlong *)(lVar12 + 0x4e8) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x4e0);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x4e0) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x4e8) = lVar20;
        }
        if ((puVar8[0xe] & 0x1000) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x5a8);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x5a0),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x5a0) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x5a0),*(longlong *)(lVar12 + 0x5a8) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x5a0);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x5a0) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x5a8) = lVar20;
        }
        if ((puVar8[0xe] & 0x2000) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x4f8);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x4f0),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x4f0) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x4f0),*(longlong *)(lVar12 + 0x4f8) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x4f0);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x4f0) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x4f8) = lVar20;
        }
        if ((puVar8[0xe] & 0x4000) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x568);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x560),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x560) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x560),*(longlong *)(lVar12 + 0x568) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x560);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x560) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x568) = lVar20;
        }
        lVar1 = local_1c8;
        if ((puVar8[0xe] & 0x8000) != 0) {
          lVar1 = *(longlong *)(lVar12 + 0x578);
          lVar20 = lVar1 + 1;
          pvVar9 = (void *)FUN_14018db00(*(undefined8 *)(lVar12 + 0x570),lVar20,8);
          *(undefined4 **)((longlong)pvVar9 + lVar1 * 8) = puVar8;
          if (*(void **)(lVar12 + 0x570) != pvVar9) {
            memcpy(pvVar9,*(void **)(lVar12 + 0x570),*(longlong *)(lVar12 + 0x578) << 3);
            lVar1 = *(longlong *)(lVar12 + 0x570);
            if (lVar1 != 0) {
              (**(code **)(*(longlong *)(lVar1 + -0x10) + 8))(lVar1 + -0x10);
            }
            *(void **)(lVar12 + 0x570) = pvVar9;
          }
          *(longlong *)(lVar12 + 0x578) = lVar20;
          lVar1 = local_1c8;
        }
      }
      else {
        lVar1 = lVar20 + 1;
        _Dst = (undefined8 *)FUN_14018db00(puVar7,lVar1,4);
        *(undefined4 *)((longlong)_Dst + lVar20 * 4) = *puVar8;
        if ((puVar7 != _Dst) &&
           (memcpy(_Dst,puVar7,lVar20 * 4), puVar6 = _Dst, puVar7 != (undefined8 *)0x0)) {
          (**(code **)(puVar7[-2] + 8))(puVar7 + -2);
        }
      }
      local_1c8 = lVar1;
      uVar11 = uVar11 + 1;
      puVar7 = puVar6;
      lVar20 = local_1c8;
    } while (uVar11 < local_1d8);
  }
LAB_140050c35:
  (**(code **)(*DAT_140c65848 + 0x10))(DAT_140c65848,lVar12 + 0x2f8,puVar6,lVar20);
  if (puVar6 != (undefined8 *)0x0) {
    (**(code **)(puVar6[-2] + 8))(puVar6 + -2);
  }
  return;
}



==== FUN_14004fa30 @ 14004fa30 size 973 ====
CALLERS: FUN_140051530
CALLEES: FUN_140232be0 FUN_1402358c0 FUN_14018b280 DebugBreak FUN_1402347c0 FUN_1402336c0 FUN_1407e4830 FUN_1401971e0 FUN_14018db00 TlsGetValue FUN_1400290d0 TlsSetValue FUN_140235480

void FUN_14004fa30(longlong param_1)

{
  longlong *plVar1;
  ulonglong *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  undefined4 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong *puVar13;
  undefined4 uVar14;
  longlong lVar15;
  int iVar16;
  undefined4 uVar17;
  longlong local_res8;
  int local_res10;
  int local_res18;
  longlong local_res20;
  undefined **local_88;
  ulonglong local_80;
  LPVOID local_78;
  undefined **local_68;
  ulonglong local_60;
  LPVOID local_58;
  
  local_res8 = param_1;
  if (DAT_140c63838 == (code *)0x0) {
    if (DAT_140c641a4 == 0) {
      iVar16 = FUN_140232be0();
      if (iVar16 < 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (**(code **)(*DAT_140c63ea0 + 0x28))();
      }
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    uVar6 = (*DAT_140c63838)(&PTR_u_SoundContext_140a6cdd0,DAT_140c63858);
  }
  lVar9 = FUN_14018db00(0,uVar6,4);
  lVar11 = 0;
  if (lVar9 != 0) {
    lVar11 = lVar9;
  }
  local_res20 = lVar11;
  if (DAT_140c63838 == (code *)0x0) {
    if (DAT_140c641a4 == 0) {
      iVar16 = FUN_140232be0();
      if (iVar16 < 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = (**(code **)(*DAT_140c63ea0 + 0x28))();
      }
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = (*DAT_140c63838)(&PTR_u_SoundContext_140a6cdd0,DAT_140c63858);
  }
  pcVar5 = DAT_140c63838;
  FUN_1407e4830(lVar11,0,(ulonglong)uVar7 << 2);
  iVar16 = 0;
  if (pcVar5 == (code *)0x0) {
    if (DAT_140c641a4 == 0) {
      iVar8 = FUN_140232be0();
      if (iVar8 < 0) {
        local_res10 = 0;
      }
      else {
        local_res10 = (**(code **)(*DAT_140c63ea0 + 0x28))();
      }
    }
    else {
      local_res10 = 0;
    }
  }
  else {
    local_res10 = (*pcVar5)(&PTR_u_SoundContext_140a6cdd0,DAT_140c63858);
  }
  lVar15 = (longlong)local_res10;
  lVar9 = 0;
  if (0 < local_res10) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c641a4 == 0) && (iVar8 = FUN_140232be0(), -1 < iVar8)) {
          puVar10 = (undefined4 *)(**(code **)(*DAT_140c63ea0 + 0x20))();
          goto LAB_14004fbdb;
        }
      }
      else {
        puVar10 = (undefined4 *)(*DAT_140c63848)(&PTR_u_SoundContext_140a6cdd0,iVar16,DAT_140c63858)
        ;
LAB_14004fbdb:
        if (puVar10 != (undefined4 *)0x0) {
          local_res18 = puVar10[2];
          uVar14 = 0;
          uVar17 = 0;
          local_80 = local_80 & 0xffffffff00000000;
          if (local_res18 == 2) {
            lVar11 = FUN_1402347c0(puVar10[1]);
LAB_14004fc45:
            if (lVar11 != 0) {
              uVar14 = *(undefined4 *)(lVar11 + 4);
            }
          }
          else {
            if (local_res18 == 3) {
              lVar11 = FUN_140235480(puVar10[1]);
            }
            else {
              if (local_res18 != 4) {
                if (local_res18 == 5) {
                  lVar11 = FUN_1402336c0(puVar10[1]);
                  goto LAB_14004fc45;
                }
                uVar14 = puVar10[1];
                *(undefined4 *)(lVar11 + lVar9 * 4) = uVar14;
                goto LAB_14004fc4d;
              }
              lVar11 = FUN_1402358c0(puVar10[1]);
            }
            if (lVar11 != 0) {
              uVar14 = *(undefined4 *)(lVar11 + 8);
              uVar17 = *(undefined4 *)(lVar11 + 4);
            }
          }
LAB_14004fc4d:
          plVar1 = (longlong *)(param_1 + 0x280);
          if (*plVar1 == *(longlong *)(param_1 + 0x288)) {
            FUN_1400290d0(plVar1);
          }
          uVar12 = (**(code **)(param_1 + 0x298))(puVar10);
          puVar2 = (ulonglong *)
                   (*(longlong *)(param_1 + 0x290) + (uVar12 % *(ulonglong *)(param_1 + 0x288)) * 8)
          ;
          puVar13 = (ulonglong *)FUN_14018b280(0x20);
          if (puVar13 != (ulonglong *)0x0) {
            uVar4 = *puVar2;
            *puVar13 = uVar12;
            puVar13[1] = uVar4;
            uVar3 = *puVar10;
            *(undefined4 *)((longlong)puVar13 + 0x14) = uVar14;
            *(undefined4 *)(puVar13 + 2) = uVar3;
            *(undefined4 *)(puVar13 + 3) = uVar17;
            *(int *)((longlong)puVar13 + 0x1c) = local_res18;
          }
          *puVar2 = (ulonglong)puVar13;
          *plVar1 = *plVar1 + 1;
          lVar11 = local_res20;
          param_1 = local_res8;
        }
      }
      lVar9 = lVar9 + 1;
      iVar16 = iVar16 + 1;
    } while (lVar9 < lVar15);
  }
  if (local_res10 == 0) {
    local_80 = 0;
    local_88 = &PTR_LAB_140b5e648;
    local_78 = TlsGetValue(DAT_140c63720);
    TlsSetValue(DAT_140c63720,&local_88);
    local_68 = local_88;
    local_res8 = 0x141e50360;
    local_58 = local_78;
    local_60 = local_80;
    iVar16 = FUN_1401971e0(&DAT_140c8a030,0x13,&local_res8,&local_68);
    local_88 = &PTR_LAB_140b5e648;
    TlsSetValue(DAT_140c63720,local_78);
    if (iVar16 != 0) {
      DebugBreak();
    }
  }
  (**(code **)(*DAT_140c65848 + 0x10))(DAT_140c65848,param_1 + 0x2e8,lVar11,uVar6);
  if (lVar11 != 0) {
    (**(code **)(*(longlong *)(lVar11 + -0x10) + 8))(lVar11 + -0x10);
  }
  return;
}



==== FUN_140051e80 @ 140051e80 size 522 ====
CALLERS: FUN_140013d00 FUN_140051530
CALLEES: FUN_140233b00 FUN_1400523e0 FUN_140051cc0 FUN_1400bb6b0 FUN_1400bbca0 FUN_1400ba9f0 FUN_14018cdf0

void FUN_140051e80(longlong param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  int *piVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  
  iVar5 = (**(code **)*DAT_140c65848)();
  if (iVar5 != 0) {
    FUN_1400ba9f0(param_1 + 0x10);
    FUN_1400bb6b0(param_1 + 0x10);
    FUN_1400bbca0(param_1 + 0x10);
  }
  piVar9 = DAT_140c63750;
  if ((*(int *)(param_1 + 0x5c0) != 0) &&
     (iVar5 = FUN_14018cdf0(), piVar9 = DAT_140c63750, 0 < iVar5 - *(int *)(param_1 + 0x5c0))) {
    uVar3 = *(ulonglong *)(param_1 + 0x5b8);
    uVar11 = 0;
    if (uVar3 != 0) {
      uVar10 = 1;
      uVar13 = uVar11;
      if (1 < uVar3) {
        do {
          lVar7 = FUN_140233b00(*(undefined4 *)(uVar13 + *(longlong *)(param_1 + 0x5b0)));
          lVar8 = FUN_140233b00(*(undefined4 *)(uVar10 * 8 + *(longlong *)(param_1 + 0x5b0)));
          if ((lVar8 != 0) && ((lVar7 == 0 || (*(uint *)(lVar7 + 0x3c) < *(uint *)(lVar8 + 0x3c)))))
          {
            uVar11 = uVar10;
            uVar13 = uVar10 * 8;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar3);
      }
      puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0x5b0) + uVar11 * 8);
      uVar2 = puVar1[1];
      if ((uVar2 < 3) &&
         (plVar4 = *(longlong **)(param_1 + 0x2d0 + (longlong)(int)uVar2 * 8),
         plVar4 != (longlong *)0x0)) {
        (**(code **)(*plVar4 + 0x10))(plVar4,*puVar1,0,0,0,0,0);
      }
      FUN_1400523e0(param_1 + 0x5b0);
    }
    piVar9 = DAT_140c63750;
    iVar6 = DAT_140c3b890;
    if (*DAT_140c63750 < DAT_140c3b890) {
      iVar6 = *DAT_140c63750;
    }
    if (*(int *)(&DAT_140c3b8a0 + (longlong)iVar6 * 4) < iVar5 - *(int *)(param_1 + 0x5c0)) {
      *(undefined4 *)(param_1 + 0x5c0) = 0;
    }
  }
  iVar5 = *piVar9;
  iVar6 = DAT_140c3b7f0;
  if (iVar5 < DAT_140c3b7f0) {
    iVar6 = iVar5;
  }
  if ((&DAT_140c3b800)[iVar6] == '\0') {
    iVar6 = DAT_140c3b7b0;
    if (iVar5 < DAT_140c3b7b0) {
      iVar6 = iVar5;
    }
    if (((&DAT_140c3b7c0)[iVar6] != '\0') || ((*(uint *)(DAT_140c635f0 + 0x40) & 0x2000) != 0)) {
      uVar12 = 0xaa;
      goto LAB_140052077;
    }
  }
  uVar12 = 0xa9;
LAB_140052077:
  FUN_140051cc0(param_1,7,uVar12);
  return;
}


