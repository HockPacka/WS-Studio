
==== FUN_1402dbc00 @ 1402dbc00 size 1583 ====
CALLERS: FUN_1402dc4c0
CALLEES: FID_conflict:swscanf FUN_1401a4f40 FUN_1401a5ae0 FUN_1401a72e0 FUN_1401a76a0 FUN_14018e820 FUN_1407dfe80 FUN_1401a6c20 FUN_1401a7c70 FUN_1401a6b80

short * FUN_1402dbc00(longlong param_1)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  longlong *plVar5;
  longlong lVar6;
  short *psVar7;
  longlong lVar8;
  undefined8 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  short *psVar13;
  short *psVar14;
  double dVar15;
  undefined4 local_res8 [2];
  undefined1 local_298 [48];
  undefined8 *local_268;
  short *psVar12;
  
  FUN_1401a72e0(local_298);
  iVar3 = FUN_1401a7c70(local_298,*(undefined8 *)(param_1 + 0x640));
  if (iVar3 < 0) {
    psVar14 = (short *)0x80004005;
  }
  else {
    psVar14 = (short *)0x0;
    for (puVar1 = local_268; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[9]) {
      plVar5 = (longlong *)(**(code **)*puVar1)(puVar1);
      if (plVar5 != (longlong *)0x0) {
        lVar6 = (**(code **)(*plVar5 + 0x30))(plVar5);
        psVar7 = psVar14;
        if (lVar6 == 0) {
          psVar7 = (short *)FUN_1401a4f40(plVar5 + 3);
        }
        psVar13 = &DAT_140af0cc8;
        if (psVar7 != &DAT_140af0cc8) {
          psVar12 = psVar14;
          if (*psVar7 != 0) {
            do {
              uVar11 = (uint)psVar12;
              if (((*psVar13 == 0) || (*psVar7 != *psVar13)) || (0x7ffffffe < (int)uVar11)) break;
              psVar7 = psVar7 + 1;
              psVar13 = psVar13 + 1;
              uVar11 = uVar11 + 1;
              psVar12 = (short *)(ulonglong)uVar11;
            } while (*psVar7 != 0);
            if (uVar11 == 0x7fffffff) goto LAB_1402dbcfe;
          }
          if ((*psVar7 != 0) || (*psVar13 != 0)) goto LAB_1402dbcec;
        }
LAB_1402dbcfe:
        if (plVar5 != (longlong *)0x0) {
          lVar6 = FUN_1401a5ae0(plVar5,L"OceanWaterTypeId");
          if ((lVar6 != 0) && (lVar8 = FUN_1401a6c20(lVar6), lVar8 != 0)) {
            uVar9 = FUN_1401a6c20(lVar6);
            uVar4 = FUN_14018e820(uVar9);
            *(undefined4 *)(param_1 + 0x648) = uVar4;
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"ShoreWaveLayerId");
          if (lVar6 != 0) {
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0928);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined4 *)(param_1 + 0x64c) = local_res8[0];
              }
            }
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0c08);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined4 *)(param_1 + 0x650) = local_res8[0];
              }
            }
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0c10);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined4 *)(param_1 + 0x654) = local_res8[0];
              }
            }
            lVar6 = FUN_1401a6b80(lVar6,&DAT_140af0c18);
            if (lVar6 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar6 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined4 *)(param_1 + 0x658) = local_res8[0];
              }
            }
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"ShoreAngleScale");
          if ((lVar6 != 0) && (lVar8 = FUN_1401a6c20(lVar6), lVar8 != 0)) {
            uVar9 = FUN_1401a6c20(lVar6);
            dVar15 = (double)FUN_1407dfe80(uVar9,0);
            *(float *)(param_1 + 0x65c) = (float)dVar15;
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"MaxShoreWaveDepth");
          if ((lVar6 != 0) && (lVar8 = FUN_1401a6c20(lVar6), lVar8 != 0)) {
            uVar9 = FUN_1401a6c20(lVar6);
            dVar15 = (double)FUN_1407dfe80(uVar9,0);
            *(float *)(param_1 + 0x660) = (float)dVar15;
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"OceanShoreWaveLayer");
          if ((lVar6 != 0) && (lVar8 = FUN_1401a6c20(lVar6), lVar8 != 0)) {
            uVar9 = FUN_1401a6c20(lVar6);
            uVar4 = FUN_14018e820(uVar9);
            *(undefined4 *)(param_1 + 0x664) = uVar4;
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"TerrainPresetId");
          if (lVar6 != 0) {
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0e00);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x668) = (undefined1)local_res8[0];
              }
            }
            lVar6 = FUN_1401a6b80(lVar6,&DAT_140af0e08);
            if (lVar6 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar6 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x669) = (undefined1)local_res8[0];
              }
            }
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"ClutterPresetId");
          if (lVar6 != 0) {
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0e30);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x66a) = (undefined1)local_res8[0];
              }
            }
            lVar6 = FUN_1401a6b80(lVar6,&DAT_140af0e38);
            if (lVar6 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar6 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x66b) = (undefined1)local_res8[0];
              }
            }
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"LandWaterPresetId");
          if (lVar6 != 0) {
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0e68);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x66c) = (undefined1)local_res8[0];
              }
            }
            lVar6 = FUN_1401a6b80(lVar6,&DAT_140af0e70);
            if (lVar6 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar6 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x66d) = (undefined1)local_res8[0];
              }
            }
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"OceanWaterPresetId");
          if (lVar6 != 0) {
            lVar8 = FUN_1401a6b80(lVar6,&DAT_140af0d48);
            if (lVar8 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar8 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x66e) = (undefined1)local_res8[0];
              }
            }
            lVar6 = FUN_1401a6b80(lVar6,&DAT_140af0d50);
            if (lVar6 != 0) {
              pwVar10 = (wchar_t *)FUN_1401a4f40(lVar6 + 0x20);
              iVar3 = FID_conflict_swscanf(pwVar10,L"%d",local_res8);
              if (iVar3 == 1) {
                *(undefined1 *)(param_1 + 0x66f) = (undefined1)local_res8[0];
              }
            }
          }
          lVar6 = FUN_1401a5ae0(plVar5,L"IceLayerPresetId");
          if ((lVar6 != 0) && (lVar8 = FUN_1401a6c20(lVar6), lVar8 != 0)) {
            uVar9 = FUN_1401a6c20(lVar6);
            uVar2 = FUN_14018e820(uVar9);
            *(undefined1 *)(param_1 + 0x670) = uVar2;
          }
        }
        break;
      }
LAB_1402dbcec:
    }
  }
  FUN_1401a76a0(local_298);
  return psVar14;
}


