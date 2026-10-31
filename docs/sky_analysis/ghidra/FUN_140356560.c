
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140356560(longlong *param_1,int param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  float *pfVar9;
  longlong lVar10;
  int *piVar11;
  longlong *plVar12;
  longlong lVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  longlong alStack_bc8 [313];
  undefined8 uStack_200;
  undefined1 auStack_1f8 [32];
  undefined4 *local_1d8;
  undefined4 local_1d0;
  longlong local_1c8;
  longlong *local_1c0;
  int local_1b8;
  undefined8 local_1a8 [4];
  undefined4 local_188;
  float local_184;
  float local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined1 local_168 [176];
  float afStack_b8 [8];
  int local_98 [4];
  float local_88 [4];
  ulonglong local_78;
  ulonglong uVar8;
  
  local_78 = DAT_140c0f7b0 ^ (ulonglong)auStack_1f8;
  if ((*(byte *)(param_1 + 0x1d) & 1) == 0) {
    uVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      uStack_200 = 0x1403565fd;
      fVar14 = (float)FUN_1403726d0(param_1 + 0x14c,2);
      fVar16 = 0.0;
    }
    else {
      if (((param_1[0x2a7] == 0) || (param_1[0x151] != 0)) || (param_1[0x152] != 0)) {
        uStack_200 = 0x14035669a;
        fVar14 = (float)FUN_1403726d0(param_1 + 0x14c,2);
        fVar16 = *(float *)((longlong)param_1 + 0xa7c);
        if (fVar16 == 0.0) {
          uStack_200 = 0x1403566ba;
          fVar16 = (float)(**(code **)(*(longlong *)param_1[0x140] + 0x100))();
        }
        fVar16 = fVar16 * *(float *)((longlong)param_1 + 0x37c) + *(float *)(param_1 + 0x77);
        if (fVar16 <= fVar14) {
          fVar14 = fVar16;
        }
        *(float *)(param_1 + 0x77) = fVar14;
      }
      else {
        fVar14 = *(float *)((longlong)param_1 + 0xa7c);
        if (fVar14 == 0.0) {
          uStack_200 = 0x140356645;
          fVar14 = (float)(**(code **)(*(longlong *)param_1[0x140] + 0x100))();
        }
        fVar16 = *(float *)(param_1 + 0x77) - fVar14 * *(float *)((longlong)param_1 + 0x37c);
        fVar14 = 0.0;
        if (0.0 <= fVar16) {
          fVar14 = fVar16;
        }
        *(float *)(param_1 + 0x77) = fVar14;
        if (0.0 < fVar14) {
          uStack_200 = 0x14035667e;
          FUN_1403726d0(param_1 + 0x14c,2);
        }
        fVar14 = *(float *)(param_1 + 0x77);
      }
      if ((param_1[0x2a7] != 0) || (0.0 < *(float *)((longlong)param_1 + 0x3b4))) {
        uStack_200 = 0x14035670f;
        fVar16 = (float)FUN_1403726d0(param_1 + 0x148,1);
      }
      else {
        fVar16 = 0.0;
      }
    }
    uVar8 = 0;
    local_1d8 = (undefined4 *)0x0;
    uStack_200 = 0x140356738;
    iVar2 = (**(code **)(*param_1 + 0x1b8))(param_1,param_1 + 0x6c,local_168,0x40018000);
    if (iVar2 == 0) {
      local_98[0] = 0;
      local_98[1] = 0;
      local_98[2] = 0;
      local_98[3] = 0;
    }
    puVar4 = local_1a8;
    piVar11 = local_98;
    do {
      if (*piVar11 == 0) {
LAB_140356777:
        *puVar4 = 0;
      }
      else {
        uStack_200 = 0x140356773;
        iVar2 = FUN_1403543e0(param_1,*piVar11,param_1[0x140],local_1a8 + uVar8);
        if (iVar2 < 0) goto LAB_140356777;
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
      piVar11 = piVar11 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar7 < 4);
    plVar12 = param_1 + 0x144;
    lVar10 = 4;
    lVar5 = 4;
    plVar6 = plVar12;
    do {
      if ((longlong *)*plVar6 != (longlong *)0x0) {
        uStack_200 = 0x1403567b2;
        (**(code **)(*(longlong *)*plVar6 + 8))();
        *plVar6 = 0;
      }
      *plVar6 = *(longlong *)(((longlong)alStack_bc8 - (longlong)param_1) + (longlong)plVar6);
      lVar5 = lVar5 + -1;
      plVar6 = plVar6 + 1;
    } while (lVar5 != 0);
    fVar15 = 0.0;
    lVar5 = 0;
    lVar13 = 4;
    local_88[0] = 0.0;
    local_88[1] = 0.0;
    local_88[2] = 0.0;
    local_88[3] = 0.0;
    plVar6 = plVar12;
    do {
      if (*plVar6 != 0) {
        local_1a8[0]._0_4_ = 0;
        plVar1 = *(longlong **)(*plVar6 + 0x28);
        if (plVar1 != (longlong *)0x0) {
          uStack_200 = 0x140356807;
          iVar2 = (**(code **)(*plVar1 + 0x10))(plVar1,local_1a8);
          if (iVar2 == 0) goto LAB_14035681b;
        }
        *(float *)((longlong)local_88 + lVar5) = *(float *)((longlong)afStack_b8 + lVar5);
        fVar15 = fVar15 + *(float *)((longlong)afStack_b8 + lVar5);
      }
LAB_14035681b:
      plVar6 = plVar6 + 1;
      lVar5 = lVar5 + 4;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
    if (fVar15 <= 1e-05) {
      plVar12 = *(longlong **)(param_1[0x142] + 0x28);
      if (plVar12 != (longlong *)0x0) {
        uStack_200 = 0x140356894;
        (**(code **)(*plVar12 + 0x70))(plVar12,0,0x3f800000);
      }
    }
    else {
      pfVar9 = local_88;
      do {
        if ((*plVar12 != 0) && (plVar6 = *(longlong **)(*plVar12 + 0x28), plVar6 != (longlong *)0x0)
           ) {
          uStack_200 = 0x140356865;
          (**(code **)(*plVar6 + 0x70))(plVar6,0,*pfVar9 / fVar15);
        }
        plVar12 = plVar12 + 1;
        pfVar9 = pfVar9 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
    }
    local_188 = 0x3f800000;
    if (param_2 == 0) {
      local_184 = 0.0;
    }
    else {
      local_184 = fVar16;
      if ((param_1[0x2a7] == 0) && (0.0 < *(float *)((longlong)param_1 + 0x3b4))) {
        fVar16 = *(float *)((longlong)param_1 + 0xa5c);
        if (fVar16 == 0.0) {
          uStack_200 = 0x1403568f1;
          fVar16 = (float)(**(code **)(*(longlong *)param_1[0x140] + 0x100))();
        }
        fVar16 = *(float *)((longlong)param_1 + 0x3b4) -
                 fVar16 * *(float *)((longlong)param_1 + 0x37c);
        local_184 = 0.0;
        if (0.0 <= fVar16) {
          local_184 = fVar16;
        }
      }
      if (local_184 < 0.0) {
        local_184 = 0.0;
      }
      *(float *)((longlong)param_1 + 0x3b4) = local_184;
    }
    local_178 = 0x3f800000;
    local_174 = 0x3f800000;
    if (param_1[0x149] == 0) {
      local_174 = 0;
    }
    local_170 = 0x3f800000;
    if (param_1[0x14d] == 0) {
      local_170 = 0;
    }
    local_1c0 = param_1 + 0x72;
    local_1c8 = (longlong)param_1 + 0x774;
    local_1b8 = 2 - (uint)(param_2 != 0);
    local_1d0 = (undefined4)param_1[0xc9];
    local_1d8 = &local_178;
    uStack_200 = 0x1403569ee;
    local_180 = fVar14;
    uVar3 = (**(code **)(*(longlong *)param_1[0x140] + 0x38))
                      ((longlong *)param_1[0x140],(int)param_1[0x6e],(int)param_1[0x70],&local_188);
    if (-1 < (int)uVar3) {
      uVar3 = 0;
      *(undefined4 *)(param_1 + 0x14c) = 0;
      *(undefined8 *)((longlong)param_1 + 0xa7c) = 0;
      *(undefined4 *)((longlong)param_1 + 0xa9c) = 0;
    }
  }
  return uVar3;
}

