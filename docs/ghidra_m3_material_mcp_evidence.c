/* WildStar64.exe build 16042, Ghidra MCP force_decompile FUN_1403283c0.
   piVar68 points to on-disk material +8: [1]=flags, [3]=blend mode.
   Excerpts, not a standalone compilation unit. */

/* Original decompiler output lines 193..201 */

  lVar42 = plVar48[8];
  local_418 = *(undefined4 **)(local_3b8 + 0x40);
  local_3a0 = *(float *)(local_3b8 + 0x50);
  local_360 = *(float **)(local_3b8 + 0x38);
  piVar68 = (int *)(*(longlong *)(lVar42 + 0x1f8) + 8 +
                   (ulonglong)*(ushort *)((longlong)local_418 + 0x16) * 0x30);
  lVar56 = (ulonglong)*(ushort *)((longlong)local_418 + 0x16) * 0x60 + plVar48[0x8a];
  local_398 = (longlong *)0x0;
  local_388 = 0;

/* Original decompiler output lines 247..261 */

  }
  uVar69 = piVar68[1];
  if (((uVar69 & 4) == 0) &&
     (uVar54 = *(uint *)(*(longlong *)(lVar42 + 0x10) + 0x570), (uVar54 & 0xc0) == 0)) {
    if ((uVar54 >> 8 & 1) == 0) {
      local_2e0 = 1;
    }
    else {
      local_2e0 = 2;
    }
  }
  else {
    local_2e0 = 0;
  }
  uVar50 = 4;

/* Original decompiler output lines 288..289 */

  local_3ec = piVar68[3];
  local_440 = 0xf;

/* Original decompiler output lines 313..406 */

  if ((local_380 == (longlong *)0x0) || (*(short *)(*local_380 + 6) != 2)) {
    switch(local_3ec) {
    case 3:
      goto switchD_1403287a0_caseD_3;
    case 4:
      local_458 = 0;
      local_448 = 0;
      local_44c = 4;
      local_454 = 1;
      local_450 = 1;
      local_444 = 7;
      break;
    case 5:
      goto switchD_1403287a0_caseD_5;
    case 6:
      local_450 = 1;
      local_44c = 8;
      local_454 = 2;
      local_458 = 0;
      local_448 = 0;
      local_444 = 7;
      break;
    default:
      local_44c = 4;
      local_454 = 5;
      goto LAB_14032882f;
    case 8:
      goto switchD_1403287a0_caseD_8;
    case 9:
      goto switchD_1403287a0_caseD_9;
    case 10:
      local_44c = 1;
      local_454 = 3;
      local_458 = 0;
      local_450 = 1;
      local_448 = 0;
      local_444 = 7;
    }
    goto LAB_140328979;
  }
  switch(*(undefined2 *)(*local_380 + 0x16)) {
  case 3:
switchD_1403287a0_caseD_3:
    local_454 = 1;
    goto LAB_14032882b;
  case 4:
    local_454 = 1;
    local_44c = 4;
    goto LAB_14032882f;
  case 5:
switchD_1403287a0_caseD_5:
    local_450 = 1;
    local_44c = 8;
    local_454 = 0;
    local_444 = 7;
    local_448 = 0;
    local_458 = 0;
    break;
  case 6:
    local_44c = 8;
    local_454 = 2;
    goto LAB_14032882f;
  default:
    local_450 = 1;
    local_458 = 0;
    local_448 = 0;
    local_44c = 4;
    local_454 = 5;
    local_444 = 7;
    break;
  case 8:
switchD_1403287a0_caseD_8:
    uVar50 = 3;
  case 9:
switchD_1403287a0_caseD_9:
    local_44c = 1;
    local_454 = 1;
    local_444 = 7;
    local_450 = 1;
    local_448 = 0;
    local_458 = uVar50;
    break;
  case 10:
    local_454 = 3;
LAB_14032882b:
    local_44c = 1;
LAB_14032882f:
    local_450 = 1;
    local_444 = 7;
    local_458 = 0;
    local_448 = 0;
  }
LAB_140328979:
  iVar37 = local_3ec;

/* Original decompiler output lines 413..469 */

        local_440 = 7;
      }
      if (((uVar54 & 0x20) == 0) &&
         ((*(longlong **)(local_3b8 + 0x48) == (longlong *)0x0 ||
          (*(short *)(**(longlong **)(local_3b8 + 0x48) + 6) != 2)))) {
        local_42c = ~(uVar69 >> 1) & 1;
      }
      else {
        local_42c = 0;
      }
    }
    else {
      if (local_430 != 4) {
        if (uVar62 == 0) {
          if ((uVar54 & 0x20) == 0) {
            local_440 = 0xfff;
            if ((uVar54 >> 0xc & 1) != 0) {
              local_440 = 0x2fff;
            }
            if ((local_430 == 0) && ((*(byte *)(plVar48 + 0xe4) & 1) != 0)) {
              local_440 = local_440 | 0x2000;
            }
            if ((uVar69 >> 0x10 & 1) != 0) {
              local_440 = 0;
              local_2b8 = 0;
            }
          }
          else {
            local_440 = 0xff7;
          }
        }
        else {
          local_440 = 0xf;
        }
      }
      local_42c = 1;
    }
    local_2c4 = CONCAT44(local_42c,local_440);
  }
  else {
    local_42c = 0;
    local_440 = 0;
    local_2c4 = 0;
  }
  if (((uVar54 & 0x20) == 0) && ((uVar69 & 1) == 0)) {
    local_2bc = 3;
  }
  else {
    local_2bc = 7;
  }
  uVar69 = local_2e8 | 0x5f;
  uVar54 = local_2e4 | 0x5f;
  local_3f8 = uVar69;
  local_3f4 = uVar54;
  local_2e8 = uVar69;
  local_2e4 = uVar54;
  local_2dc = local_44c;

/* Original decompiler output lines 1129..1193 */

  iVar37 = local_3ec;
  puVar40 = local_418;
  fVar86 = 0.003921569;
  if ((((local_3ec != local_408) || (local_360 != local_370)) || (lVar64 != local_390)) ||
     (((*(byte *)(local_410 + 0x38) ^ *(byte *)(local_418 + 0xe)) & 1) != 0)) {
    local_478 = (undefined *)((ulonglong)local_478 & 0xffffffff00000000);
    pfVar46 = (float *)(**(code **)(*DAT_140c65670 + 0x110))(DAT_140c65670,0xb0,2);
    if (pfVar46 != (float *)0x0) {
      if (iVar37 < 3) {
LAB_1403296c2:
        *pfVar46 = DAT_140c79700;
        pfVar46[1] = DAT_140c79704;
        pfVar46[2] = DAT_140c79708;
        pfVar46[3] = 1.0;
      }
      else if (iVar37 < 5) {
        *pfVar46 = DAT_140c79700;
        pfVar46[1] = DAT_140c79704;
        pfVar46[2] = DAT_140c79708;
        pfVar46[3] = 0.0;
      }
      else if (iVar37 == 5) {
        *pfVar46 = DAT_140c79710;
        pfVar46[1] = DAT_140c79714;
        pfVar46[2] = DAT_140c79718;
        pfVar46[3] = 0.0;
      }
      else {
        if (iVar37 != 6) goto LAB_1403296c2;
        *pfVar46 = 0.5;
        pfVar46[1] = 0.5;
        pfVar46[2] = 0.5;
        pfVar46[3] = 0.0;
      }
      if (iVar37 == 0) {
        if ((pfVar47[8] <= 0.99607843 && pfVar47[8] != 0.99607843) ||
           (((*(byte *)(puVar40 + 0xe) & 1) != 0 &&
            ((*(byte *)(*(longlong *)(local_428 + 0x10) + 0x570) & 4) == 0)))) {
          fVar71 = 0.0;
        }
        else {
          fVar71 = 1.0;
        }
        pfVar46[4] = fVar71;
        if (0.99607843 < pfVar47[8] || pfVar47[8] == 0.99607843) {
          fVar71 = 0.0;
        }
        else {
          fVar71 = 0.003921569;
        }
        pfVar46[5] = fVar71;
      }
      else if (iVar37 == 1) {
        pfVar46[4] = 1.0;
        pfVar46[5] = 0.5;
      }
      else {
        pfVar46[4] = 0.0;
        pfVar46[5] = 0.003921569;
      }
      pfVar46[6] = pfVar47[9];
      pfVar46[7] = pfVar47[10];
      pfVar46[8] = (float)((uint)~piVar68[1] >> 0xf & 1);
      pfVar46[9] = 0.0;
      pfVar46[10] = 0.0;