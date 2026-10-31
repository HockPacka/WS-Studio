
==== FUN_140300fd0 @ 140300fd0 size 19331 ====
CALLERS: FUN_14031bca0 FUN_140305b60 FUN_140300dd0
CALLEES: CloseHandle FUN_140307da0 FUN_1402f1a60 FUN_140307f60 FUN_1402f1f50 CreateEventW FUN_140308350 FUN_1402f96a0 FUN_140306cb0 FUN_140307c90 FUN_1403272b0 FUN_1402f13d0 FUN_1402f02e0 FUN_1401afc20 FUN_14003d880 FUN_140307720 __chkstk DebugBreak FUN_1403129a0 FUN_1403068b0 FUN_14003d8f0 FUN_1401971e0 FUN_1403073a0 FUN_140306730 FUN_1402f15d0 FUN_1402f0c90 GetCurrentThreadId FUN_140306300 FUN_1401a4a00 FUN_140307830 FUN_140307b80 __security_check_cookie TlsSetValue FUN_1401afb10 FUN_140306db0 FUN_1402f9480 FUN_14019fb60 FUN_140308160 FUN_1400035b0 SetEvent FUN_140306fc0 FUN_140306b90 FUN_1403069d0 FUN_140306eb0 FUN_140305b60 FUN_140307280 FUN_1408fccb0 FUN_1401b1ee0 FUN_14018b280 FUN_1402f1ef0 TlsGetValue

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140300fd0(longlong *param_1,ulonglong param_2,float *param_3,uint param_4)

{
  float *pfVar1;
  undefined8 *puVar2;
  DWORD *pDVar3;
  char *pcVar4;
  float fVar5;
  float fVar6;
  float fVar8;
  float fVar10;
  float fVar12;
  char cVar14;
  char cVar15;
  ushort uVar16;
  short sVar17;
  undefined4 uVar18;
  undefined8 uVar19;
  byte *pbVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined2 uVar25;
  DWORD DVar26;
  int iVar27;
  ulonglong uVar28;
  undefined8 *puVar29;
  longlong lVar30;
  undefined4 *puVar31;
  HANDLE hObject;
  float *pfVar32;
  longlong *plVar33;
  ulonglong uVar34;
  uint uVar35;
  uint uVar36;
  int *piVar37;
  longlong *plVar38;
  uint uVar39;
  undefined *puVar40;
  ulonglong uVar41;
  ulonglong uVar42;
  longlong lVar43;
  longlong lVar44;
  longlong *plVar45;
  uint uVar46;
  float *pfVar47;
  undefined1 (*pauVar48) [16];
  uint uVar49;
  uint uVar50;
  undefined1 auVar51 [8];
  undefined8 *puVar52;
  undefined1 auVar53 [8];
  uint uVar54;
  float *pfVar55;
  ushort *puVar56;
  longlong lVar57;
  undefined1 *puVar58;
  byte bVar59;
  bool bVar60;
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  float fVar79;
  float fVar80;
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  float fVar81;
  float fVar82;
  float fVar110;
  float fVar111;
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar93 [16];
  undefined1 auVar94 [16];
  undefined1 auVar95 [16];
  undefined1 auVar96 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  undefined1 auVar99 [16];
  undefined1 auVar100 [16];
  undefined1 auVar101 [16];
  undefined1 auVar102 [16];
  undefined1 auVar103 [16];
  undefined1 auVar104 [16];
  undefined1 auVar105 [16];
  undefined1 auVar106 [16];
  undefined1 auVar107 [16];
  float fVar112;
  undefined1 auVar108 [16];
  undefined1 auVar109 [16];
  float fVar113;
  undefined1 auVar114 [16];
  undefined1 auVar115 [16];
  undefined1 auVar116 [16];
  undefined1 auVar117 [16];
  undefined1 auVar118 [16];
  undefined1 auVar119 [16];
  undefined1 auVar120 [16];
  undefined1 auVar121 [16];
  undefined1 auVar122 [16];
  undefined1 auVar123 [16];
  undefined1 auVar124 [16];
  float fVar125;
  float fVar130;
  undefined1 auVar126 [16];
  undefined1 auVar127 [16];
  undefined1 auVar128 [16];
  undefined1 auVar129 [16];
  undefined1 auVar133 [12];
  float fVar131;
  float fVar132;
  undefined1 auVar134 [16];
  undefined1 auVar135 [16];
  float fVar136;
  undefined1 auStack_13d8 [32];
  undefined ***local_13b8;
  longlong *local_13b0;
  undefined8 local_13a8;
  uint local_1398;
  uint local_1394;
  uint local_1390;
  longlong local_1388;
  longlong *local_1380;
  longlong *local_1378;
  undefined1 *local_1370;
  undefined1 local_1368 [8];
  ulonglong uStack_1360;
  undefined8 *local_1358;
  undefined1 local_1348 [8];
  float fStack_1340;
  undefined4 uStack_133c;
  ulonglong local_1338;
  longlong local_1330;
  float *local_1328;
  longlong *local_1320;
  longlong *local_1318 [2];
  undefined8 local_1308;
  undefined8 uStack_1300;
  undefined8 local_12f8;
  undefined8 uStack_12f0;
  longlong *local_12e8 [2];
  undefined1 local_12d8 [16];
  uint local_12c8;
  undefined1 local_12c0 [8];
  float *local_12b8;
  undefined8 local_12a8;
  undefined8 uStack_12a0;
  undefined8 local_1298;
  float fStack_1290;
  float fStack_128c;
  undefined **local_1288;
  wchar_t *local_1280;
  LPVOID local_1278;
  undefined8 local_1270;
  undefined1 *local_1268;
  longlong *plStack_1260;
  undefined **local_1258;
  undefined8 local_1250;
  LPVOID local_1248;
  undefined8 local_1238;
  undefined8 uStack_1230;
  longlong local_1228;
  float fStack_1220;
  float fStack_121c;
  float local_1218;
  float fStack_1214;
  float fStack_1210;
  float fStack_120c;
  float local_1208;
  float fStack_1204;
  float fStack_1200;
  float fStack_11fc;
  float local_11f8;
  float fStack_11f4;
  float fStack_11f0;
  float fStack_11ec;
  undefined8 local_11e8;
  undefined8 uStack_11e0;
  undefined8 local_11d8 [2];
  float local_11c8;
  float local_11c4;
  float local_11c0;
  undefined1 local_11b8 [8];
  float fStack_11b0;
  float local_11a8;
  float local_11a4;
  float local_11a0;
  float local_1198;
  float local_1194;
  float local_1190;
  float local_1188;
  float local_1184;
  float local_1180;
  undefined1 local_1178 [12];
  float fStack_116c;
  undefined1 local_1168 [16];
  undefined1 local_1158 [16];
  undefined **local_1148;
  undefined8 local_1140;
  LPVOID local_1138;
  undefined **local_1128;
  wchar_t *local_1120;
  LPVOID local_1118;
  undefined8 local_1110;
  undefined1 *local_1108;
  longlong *plStack_1100;
  undefined1 local_10f8 [16];
  float local_10e8;
  float fStack_10e4;
  float fStack_10e0;
  float fStack_10dc;
  undefined1 local_10d8 [16];
  float local_10c8;
  float fStack_10c4;
  float fStack_10c0;
  float fStack_10bc;
  undefined8 local_10b8;
  ulonglong uStack_10b0;
  undefined1 local_10a8 [16];
  undefined8 local_1098;
  undefined8 uStack_1090;
  undefined8 local_1088;
  undefined8 uStack_1080;
  undefined1 local_1078 [16];
  undefined8 local_1068;
  undefined8 uStack_1060;
  float local_1058;
  float fStack_1054;
  float fStack_1050;
  float fStack_104c;
  undefined1 local_1048 [16];
  float local_1038;
  float fStack_1034;
  float fStack_1030;
  float fStack_102c;
  float local_1028;
  float fStack_1024;
  float fStack_1020;
  float fStack_101c;
  undefined1 local_1018 [16];
  undefined1 local_1008 [16];
  undefined1 local_ff8 [16];
  float local_fe8;
  float fStack_fe4;
  float fStack_fe0;
  float fStack_fdc;
  float local_fd8;
  float fStack_fd4;
  float fStack_fd0;
  float fStack_fcc;
  float local_fc8;
  float fStack_fc4;
  float fStack_fc0;
  float fStack_fbc;
  float local_fb8;
  float fStack_fb4;
  float fStack_fb0;
  float fStack_fac;
  undefined1 *local_fa8;
  longlong *plStack_fa0;
  undefined1 local_f98 [16];
  undefined1 local_f88 [16];
  float local_f78;
  float fStack_f74;
  float fStack_f70;
  float fStack_f6c;
  undefined1 local_f68 [16];
  float local_f58;
  float fStack_f54;
  float fStack_f50;
  float fStack_f4c;
  float local_f48;
  float fStack_f44;
  float fStack_f40;
  float fStack_f3c;
  undefined1 local_f38 [16];
  undefined1 local_f28 [16];
  undefined1 local_f18 [16];
  float local_f08;
  float fStack_f04;
  float fStack_f00;
  float fStack_efc;
  float local_ef8;
  float fStack_ef4;
  float fStack_ef0;
  float fStack_eec;
  float local_ee8;
  float fStack_ee4;
  float fStack_ee0;
  float fStack_edc;
  undefined1 local_ed8 [16];
  float local_ec8;
  float fStack_ec4;
  float fStack_ec0;
  float fStack_ebc;
  undefined1 local_eb8 [16];
  float local_ea8;
  float fStack_ea4;
  float fStack_ea0;
  float fStack_e9c;
  float local_e98;
  float fStack_e94;
  float fStack_e90;
  float fStack_e8c;
  float local_e88;
  float fStack_e84;
  float fStack_e80;
  float fStack_e7c;
  float local_e78;
  float fStack_e74;
  float fStack_e70;
  float fStack_e6c;
  undefined1 local_e68 [16];
  float local_e58;
  float fStack_e54;
  float fStack_e50;
  float fStack_e4c;
  float local_e48;
  float fStack_e44;
  float fStack_e40;
  float fStack_e3c;
  undefined1 local_e38 [16];
  undefined1 local_e28 [16];
  float local_e18;
  float fStack_e14;
  float fStack_e10;
  float fStack_e0c;
  float local_e08;
  float fStack_e04;
  float fStack_e00;
  float fStack_dfc;
  float local_df8;
  float fStack_df4;
  float fStack_df0;
  float fStack_dec;
  float local_de8;
  float fStack_de4;
  float fStack_de0;
  float fStack_ddc;
  undefined1 local_dd8 [16];
  undefined1 local_dc8 [16];
  float local_db8;
  float fStack_db4;
  float fStack_db0;
  float fStack_dac;
  float local_da8;
  float fStack_da4;
  float fStack_da0;
  float fStack_d9c;
  float local_d98;
  float fStack_d94;
  float fStack_d90;
  float fStack_d8c;
  float local_d88;
  float fStack_d84;
  float fStack_d80;
  float fStack_d7c;
  float local_d78;
  float fStack_d74;
  float fStack_d70;
  float fStack_d6c;
  float local_d68;
  float fStack_d64;
  float fStack_d60;
  float fStack_d5c;
  float local_d58;
  float fStack_d54;
  float fStack_d50;
  float fStack_d4c;
  float local_d48;
  float fStack_d44;
  float fStack_d40;
  float fStack_d3c;
  float local_d38;
  float fStack_d34;
  float fStack_d30;
  float fStack_d2c;
  float local_d28;
  float fStack_d24;
  float fStack_d20;
  float fStack_d1c;
  float local_d18;
  float fStack_d14;
  float fStack_d10;
  float fStack_d0c;
  float local_d08;
  float fStack_d04;
  float fStack_d00;
  float fStack_cfc;
  undefined1 local_cf8 [16];
  float local_ce8;
  float fStack_ce4;
  float fStack_ce0;
  float fStack_cdc;
  undefined1 local_cd8 [16];
  float local_cc8;
  float fStack_cc4;
  float fStack_cc0;
  float fStack_cbc;
  undefined1 local_cb8 [16];
  float local_ca8;
  float fStack_ca4;
  float fStack_ca0;
  float fStack_c9c;
  float local_c98;
  float fStack_c94;
  float fStack_c90;
  float fStack_c8c;
  float local_c88;
  float fStack_c84;
  float fStack_c80;
  float fStack_c7c;
  undefined8 local_c78;
  longlong lStack_c70;
  undefined1 local_c68 [16];
  float local_c58;
  float fStack_c54;
  float fStack_c50;
  float fStack_c4c;
  float local_c48;
  float fStack_c44;
  float fStack_c40;
  float fStack_c3c;
  undefined1 local_c38 [16];
  float local_c28;
  float fStack_c24;
  float fStack_c20;
  float fStack_c1c;
  undefined8 local_c18;
  undefined8 uStack_c10;
  undefined1 local_c08 [16];
  float local_bf8;
  float fStack_bf4;
  float fStack_bf0;
  float fStack_bec;
  float local_be8;
  float fStack_be4;
  float fStack_be0;
  float fStack_bdc;
  float local_bd8;
  float fStack_bd4;
  float fStack_bd0;
  float fStack_bcc;
  undefined1 local_bc8 [16];
  float local_bb8;
  float fStack_bb4;
  float fStack_bb0;
  float fStack_bac;
  float local_ba8;
  float fStack_ba4;
  float fStack_ba0;
  float fStack_b9c;
  float local_b98;
  float fStack_b94;
  float fStack_b90;
  float fStack_b8c;
  undefined1 local_b88 [16];
  undefined1 local_b78 [16];
  undefined1 local_b68 [16];
  undefined1 local_b58 [16];
  float local_b48;
  float fStack_b44;
  float fStack_b40;
  float fStack_b3c;
  undefined1 local_b38 [16];
  undefined1 local_b28 [16];
  undefined1 local_b18 [16];
  undefined1 local_b08 [16];
  undefined1 local_af8 [16];
  float local_ae8;
  float fStack_ae4;
  float fStack_ae0;
  float fStack_adc;
  undefined1 local_ad8 [16];
  float local_ac8;
  float fStack_ac4;
  float fStack_ac0;
  float fStack_abc;
  undefined1 local_ab8 [64];
  undefined1 local_a78 [32];
  float local_a58;
  float fStack_a54;
  float fStack_a50;
  float fStack_a4c;
  undefined8 local_a48;
  undefined8 uStack_a40;
  undefined1 local_a38 [64];
  undefined1 local_9f8 [64];
  undefined1 local_9b8 [64];
  undefined1 local_978 [64];
  undefined1 local_938 [64];
  undefined1 local_8f8 [64];
  longlong local_8b8;
  longlong local_8b0;
  undefined1 local_8a8 [64];
  longlong local_868;
  undefined8 *local_860;
  undefined1 local_858 [64];
  longlong *local_818;
  undefined1 *local_810;
  float local_808 [16];
  float *local_7c8;
  longlong *local_7c0;
  float *local_778;
  longlong *local_770;
  int *local_728;
  longlong local_720;
  undefined1 *local_6d8;
  longlong *local_6d0;
  undefined1 *local_688;
  longlong *local_680;
  longlong local_638;
  undefined1 *local_630;
  longlong *local_5e8;
  undefined1 *local_5e0;
  longlong *local_598;
  undefined1 *local_590;
  longlong *local_548;
  undefined1 *local_540;
  float *local_4f8;
  longlong *local_4f0;
  longlong *local_4a8;
  undefined1 *local_4a0;
  float *local_458;
  longlong *local_450;
  longlong *local_408;
  undefined1 *local_400;
  longlong *local_3b8;
  ulonglong local_3b0;
  undefined1 *local_368;
  longlong *local_360;
  longlong *local_318 [10];
  longlong local_2c8 [10];
  float *local_278 [10];
  undefined1 local_228 [2] [16];
  float local_208;
  float local_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  ulonglong local_f8;
  float fVar7;
  float fVar9;
  float fVar11;
  float fVar13;
  
  local_f8 = DAT_140c0f7b0 ^ (ulonglong)auStack_13d8;
  uVar34 = 0;
  if (*(int *)((longlong)param_1 + 0x574) != *(int *)(param_1[2] + 0xdc)) {
    *(int *)((longlong)param_1 + 0x574) = *(int *)(param_1[2] + 0xdc);
    *(undefined4 *)((longlong)param_1 + 0x57c) = *(undefined4 *)(param_1[2] + 0xd0);
    param_1[0xb0] = 0;
  }
  uVar54 = ~*(uint *)(param_1 + 0xb0) & param_4;
  if (uVar54 != 0) {
    local_1390 = uVar54;
    local_1380 = param_1;
    local_1338 = param_2;
    local_12c8 = param_4;
    if ((uVar54 & 1) != 0) {
      uVar42 = uVar34;
      if (param_1[0x6e] != 0) {
        do {
          lVar43 = *(longlong *)(param_1[0x6d] + uVar42 * 8);
          (**(code **)(*param_1 + 400))(param_1);
          uVar28 = FUN_1402f1f50(lVar43,*(undefined4 *)(param_1[2] + 0xd0));
          if ((int)uVar28 < 0) {
            return uVar28;
          }
          if (*(float *)((longlong)param_1 + 0xc4) != 0.0) {
            lVar44 = *(longlong *)(lVar43 + 8);
            if ((((lVar44 != 0) && (*(int *)(lVar44 + 0x2c) == 0)) &&
                ((*(uint *)(lVar44 + 0x14) & 0x10) == 0)) && ((*(uint *)(lVar44 + 0x14) & 4) != 0))
            {
              FUN_140306300(param_1,*(undefined4 *)(lVar44 + 0x34));
            }
            lVar43 = *(longlong *)(lVar43 + 0x10);
            if (((lVar43 != 0) && (*(int *)(lVar43 + 0x30) == 0)) &&
               (((*(uint *)(lVar43 + 0x14) & 0x10) == 0 && ((*(uint *)(lVar43 + 0x14) & 4) != 0))))
            {
              FUN_140306300(param_1,*(undefined4 *)(lVar43 + 0x38));
            }
          }
          uVar42 = uVar42 + 1;
        } while (uVar42 < (ulonglong)param_1[0x6e]);
      }
      uVar42 = uVar34;
      if ((int)param_1[0x71] != 0) {
        do {
          lVar43 = param_1[uVar42 + 0x72];
          if ((*(longlong *)(lVar43 + 8) != 0) &&
             (-1 < *(int *)(param_1[2] + 0xd0) - *(int *)(*(longlong *)(lVar43 + 8) + 0x34))) {
            FUN_1402f9480(param_1,lVar43);
          }
          if ((*(longlong *)(lVar43 + 0x10) != 0) &&
             (-1 < *(int *)(param_1[2] + 0xd0) - *(int *)(*(longlong *)(lVar43 + 0x10) + 0x38))) {
            FUN_1402f96a0(param_1,lVar43);
          }
          (**(code **)(*param_1 + 400))(param_1);
          uVar28 = FUN_1402f1f50(lVar43,*(undefined4 *)(param_1[2] + 0xd0));
          if ((int)uVar28 < 0) {
            return uVar28;
          }
          uVar46 = (int)uVar42 + 1;
          uVar42 = (ulonglong)uVar46;
        } while (uVar46 < *(uint *)(param_1 + 0x71));
      }
      uVar42 = uVar34;
      if (*(int *)(param_1[7] + 200) != 0) {
        do {
          lVar43 = uVar42 * 0x158 + param_1[0x65];
          uVar54 = FUN_1402f02e0(lVar43,param_1);
          if (((int)uVar54 < 0) || (uVar54 = FUN_1402f0c90(lVar43,param_1), (int)uVar54 < 0)) {
            local_1250 = 0;
            local_1258 = &PTR_LAB_140b5e648;
            local_1248 = TlsGetValue(DAT_140c63720);
            TlsSetValue(DAT_140c63720,&local_1258);
            local_1148 = local_1258;
            local_1140 = local_1250;
            local_1138 = local_1248;
            uVar19 = *(undefined8 *)(param_1[7] + 0x18);
            local_1288 = &PTR_LAB_140b5e648;
            local_1280 = L"FileName";
            local_1278 = TlsGetValue(DAT_140c63720);
            TlsSetValue(DAT_140c63720,&local_1288);
            local_1120 = local_1280;
            local_1288 = &PTR_LAB_140b5e638;
            local_1128 = &PTR_LAB_140b5e638;
            local_11d8[0] = 0x141deb930;
            local_13b8 = &local_1148;
            local_1118 = local_1278;
            local_1270 = uVar19;
            local_1110 = uVar19;
            iVar27 = FUN_1401971e0(&DAT_140c8a5f4,6,local_11d8,&local_1128);
            local_1288 = &PTR_LAB_140b5e648;
            TlsSetValue(DAT_140c63720,local_1278);
            local_1258 = &PTR_LAB_140b5e648;
            TlsSetValue(DAT_140c63720,local_1248);
            if (iVar27 != 0) {
              DebugBreak();
              return (ulonglong)uVar54;
            }
            return (ulonglong)uVar54;
          }
          uVar46 = (int)uVar42 + 1;
          uVar42 = (ulonglong)uVar46;
          uVar54 = local_1390;
        } while (uVar46 < *(uint *)(param_1[7] + 200));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
    }
    if ((uVar54 & 2) != 0) {
      local_de8 = *(float *)(param_1 + 0x1c) * *param_3;
      fStack_de4 = *(float *)((longlong)param_1 + 0xe4) * param_3[1];
      fStack_de0 = *(float *)(param_1 + 0x1d) * param_3[2];
      fStack_ddc = *(float *)((longlong)param_1 + 0xec) * param_3[3];
      *(float *)(param_1 + 0x32) = local_de8;
      *(float *)((longlong)param_1 + 0x194) = fStack_de4;
      *(float *)(param_1 + 0x33) = fStack_de0;
      *(float *)((longlong)param_1 + 0x19c) = fStack_ddc;
      local_d98 = param_3[4] + *(float *)(param_1 + 0x1e);
      fStack_d94 = param_3[5] + *(float *)((longlong)param_1 + 0xf4);
      fStack_d90 = param_3[6] + *(float *)(param_1 + 0x1f);
      fStack_d8c = param_3[7] + *(float *)((longlong)param_1 + 0xfc);
      *(float *)(param_1 + 0x34) = local_d98;
      *(float *)((longlong)param_1 + 0x1a4) = fStack_d94;
      *(float *)(param_1 + 0x35) = fStack_d90;
      *(float *)((longlong)param_1 + 0x1ac) = fStack_d8c;
      *(float *)(param_1 + 0x36) = param_3[8] * *(float *)(param_1 + 0x19);
      *(float *)((longlong)param_1 + 0x1b4) =
           (*(float *)((longlong)param_1 + 0xcc) + param_3[9]) -
           *(float *)((longlong)param_1 + 0xcc) * param_3[9];
      *(float *)(param_1 + 0x37) = param_3[10] * *(float *)(param_1 + 0x1a);
      *(float *)((longlong)param_1 + 0x1bc) = param_3[0xb] * *(float *)((longlong)param_1 + 0xd4);
      *(float *)(param_1 + 0x38) = param_3[0xc];
      *(undefined2 *)((longlong)param_1 + 0x1c4) = *(undefined2 *)(param_3 + 0xd);
      lVar43 = *(longlong *)(param_3 + 0x12);
      param_1[0x3a] = *(longlong *)(param_3 + 0x10);
      param_1[0x3b] = lVar43;
      *(float *)(param_1 + 0x3c) = param_3[0x14];
      fVar131 = DAT_140b79ed0;
      lVar43 = param_1[8];
      local_1398 = *(uint *)(lVar43 + 0xf0);
      local_1394 = 0;
      if (local_1398 != 0) {
        do {
          lVar44 = param_1[0x3e];
          lVar57 = uVar34 * 0xb8 + *(longlong *)(lVar43 + 0xf8);
          puVar52 = (undefined8 *)(uVar34 * 0xc0 + param_1[0x3f]);
          uVar19 = *puVar52;
          pfVar47 = (float *)(uVar34 * 0x60 + lVar44);
          if ((param_1[0x98] == 0) || ((int)param_1[0x96] != 0)) {
LAB_140301650:
            pfVar32 = (float *)(param_1 + 0x32);
            if (*(ushort *)(lVar57 + 2) < local_1398) {
              pfVar32 = (float *)((ulonglong)*(ushort *)(lVar57 + 2) * 0x60 + lVar44);
            }
            if ((int)param_1[0x22] == 0) {
              if (*(int *)(lVar57 + 8) == 0) {
                fVar80 = *pfVar32;
                fVar82 = pfVar32[1];
                fVar110 = pfVar32[2];
                fVar111 = pfVar32[3];
              }
              else {
                FUN_1403068b0(lVar57 + 8,puVar52 + 2,uVar19);
                fVar80 = *(float *)(puVar52 + 2) * *pfVar32;
                fVar82 = *(float *)((longlong)puVar52 + 0x14) * pfVar32[1];
                fVar110 = *(float *)(puVar52 + 3) * pfVar32[2];
                fVar111 = *(float *)((longlong)puVar52 + 0x1c) * pfVar32[3];
                local_d78 = fVar80;
                fStack_d74 = fVar82;
                fStack_d70 = fVar110;
                fStack_d6c = fVar111;
              }
            }
            else {
              fVar80 = *(float *)(param_1 + 0x20);
              fVar82 = *(float *)((longlong)param_1 + 0x104);
              fVar110 = *(float *)(param_1 + 0x21);
              fVar111 = *(float *)((longlong)param_1 + 0x10c);
            }
            *pfVar47 = fVar80;
            pfVar47[1] = fVar82;
            pfVar47[2] = fVar110;
            pfVar47[3] = fVar111;
            if (*(int *)(lVar57 + 0x20) == 0) {
              fVar80 = pfVar32[4];
              fVar82 = pfVar32[5];
              fVar110 = pfVar32[6];
              fVar111 = pfVar32[7];
            }
            else {
              FUN_1403068b0((int *)(lVar57 + 0x20),puVar52 + 6,uVar19);
              fVar80 = pfVar32[4] + *(float *)(puVar52 + 6);
              fVar82 = pfVar32[5] + *(float *)((longlong)puVar52 + 0x34);
              fVar110 = pfVar32[6] + *(float *)(puVar52 + 7);
              fVar111 = pfVar32[7] + *(float *)((longlong)puVar52 + 0x3c);
              local_d58 = fVar80;
              fStack_d54 = fVar82;
              fStack_d50 = fVar110;
              fStack_d4c = fVar111;
            }
            pfVar47[4] = fVar80;
            pfVar47[5] = fVar82;
            pfVar47[6] = fVar110;
            pfVar47[7] = fVar111;
            if ((*(int *)(lVar57 + 0x38) == 0) || (pfVar32[8] == 0.0)) {
              pfVar47[8] = pfVar32[8];
            }
            else {
              FUN_140306730((int *)(lVar57 + 0x38),puVar52 + 10,uVar19);
              pfVar47[8] = pfVar32[8] * *(float *)(puVar52 + 10);
            }
            if (*(int *)(lVar57 + 0x50) == 0) {
              pfVar47[9] = pfVar32[9];
            }
            else {
              FUN_140306730(lVar57 + 0x50,(longlong)puVar52 + 100,uVar19);
              pfVar47[9] = (*(float *)((longlong)puVar52 + 100) + pfVar32[9]) -
                           *(float *)((longlong)puVar52 + 100) * pfVar32[9];
            }
            pfVar47[10] = pfVar32[10];
            pfVar47[0xb] = pfVar32[0xb];
            if ((*(int *)(lVar57 + 0x68) == 0) ||
               (fVar131 < pfVar32[0xc] || fVar131 == pfVar32[0xc])) {
              pfVar47[0xc] = pfVar32[0xc];
            }
            else {
              FUN_140306730((int *)(lVar57 + 0x68),puVar52 + 0xf,uVar19);
              pfVar47[0xc] = (*(float *)(puVar52 + 0xf) + pfVar32[0xc]) -
                             *(float *)(puVar52 + 0xf) * pfVar32[0xc];
            }
            if ((*(int *)(lVar57 + 0x80) == 0) || (*(short *)(pfVar32 + 0xd) == 0)) {
              uVar25 = *(undefined2 *)(pfVar32 + 0xd);
            }
            else {
              FUN_1403069d0((int *)(lVar57 + 0x80),(longlong)puVar52 + 0x8c,uVar19);
              if ((*(char *)((longlong)puVar52 + 0x8c) == '\0') || (*(short *)(pfVar32 + 0xd) == 0))
              {
                uVar25 = 0;
              }
              else {
                uVar25 = 1;
              }
            }
            *(undefined2 *)(pfVar47 + 0xd) = uVar25;
            if (*(int *)(lVar57 + 0x98) == 0) {
              fVar80 = pfVar32[0x10];
              fVar82 = pfVar32[0x11];
              fVar110 = pfVar32[0x12];
              fVar111 = pfVar32[0x13];
            }
            else {
              FUN_140306b90((int *)(lVar57 + 0x98),puVar52 + 0x14,uVar19);
              fVar80 = *(float *)((longlong)puVar52 + 0xac);
              uStack_11e0._0_4_ = (float)puVar52[0x15];
              local_11e8._0_4_ = (float)puVar52[0x14];
              local_11e8._4_4_ = (float)((ulonglong)puVar52[0x14] >> 0x20);
              pfVar47[0x10] = fVar80 * (float)local_11e8;
              pfVar47[0x11] = fVar80 * local_11e8._4_4_;
              pfVar47[0x12] = fVar80 * (float)uStack_11e0;
              pfVar47[0x13] = fVar80 * 1.0;
              local_11e8 = CONCAT44(fVar80 * local_11e8._4_4_,fVar80 * (float)local_11e8);
              uStack_11e0 = CONCAT44(fVar80 * 1.0,fVar80 * (float)uStack_11e0);
              fStack_d2c = fVar131 - pfVar47[0x13];
              local_d38 = fStack_d2c * pfVar32[0x10];
              fStack_d34 = fStack_d2c * pfVar32[0x11];
              fStack_d30 = fStack_d2c * pfVar32[0x12];
              fStack_d2c = fStack_d2c * pfVar32[0x13];
              fVar80 = pfVar47[0x10] + local_d38;
              fVar82 = pfVar47[0x11] + fStack_d34;
              fVar110 = pfVar47[0x12] + fStack_d30;
              fVar111 = pfVar47[0x13] + fStack_d2c;
              local_d18 = fVar80;
              fStack_d14 = fVar82;
              fStack_d10 = fVar110;
              fStack_d0c = fVar111;
            }
            pfVar47[0x10] = fVar80;
            pfVar47[0x11] = fVar82;
            pfVar47[0x12] = fVar110;
            pfVar47[0x13] = fVar111;
            pfVar55 = (float *)(lVar57 + 0xb0);
            if (*(float *)(lVar57 + 0xb0) < pfVar32[0x14]) {
              pfVar55 = pfVar32 + 0x14;
            }
            fVar80 = *pfVar55;
          }
          else {
            uVar49 = 0;
            uVar54 = *(uint *)((ulonglong)*(ushort *)(lVar57 + 4) * 0x160 + 8 +
                              *(longlong *)(lVar43 + 0x188));
            lVar43 = *(longlong *)(param_1[0x98] + 0x40);
            uVar46 = *(uint *)(lVar43 + 0x1a0);
            if (uVar46 != 0) {
              do {
                uVar35 = uVar46 + uVar49 >> 1;
                uVar34 = (ulonglong)
                         *(ushort *)(*(longlong *)(lVar43 + 0x1a8) + (ulonglong)uVar35 * 2);
                uVar39 = *(uint *)(uVar34 * 0x160 + 8 + *(longlong *)(lVar43 + 0x188));
                if (uVar39 <= uVar54) {
                  if (uVar54 <= uVar39) goto LAB_1403015ad;
                  uVar49 = uVar35 + 1;
                  uVar35 = uVar46;
                }
                uVar46 = uVar35;
              } while (uVar49 < uVar46);
            }
            uVar34 = 0xffffffff;
LAB_1403015ad:
            lVar43 = *(longlong *)(param_1[0x98] + 0x40);
            if (*(uint *)(lVar43 + 0x180) <= (uint)uVar34) {
              lVar44 = param_1[0x3e];
              goto LAB_140301650;
            }
            puVar52 = (undefined8 *)
                      ((ulonglong)*(ushort *)(uVar34 * 0x160 + 6 + *(longlong *)(lVar43 + 0x188)) *
                       0x60 + *(longlong *)(param_1[0x98] + 0x1f0));
            uVar19 = puVar52[1];
            *(undefined8 *)pfVar47 = *puVar52;
            *(undefined8 *)(pfVar47 + 2) = uVar19;
            uVar19 = puVar52[3];
            *(undefined8 *)(pfVar47 + 4) = puVar52[2];
            *(undefined8 *)(pfVar47 + 6) = uVar19;
            pfVar47[8] = *(float *)(puVar52 + 4);
            pfVar47[9] = *(float *)((longlong)puVar52 + 0x24);
            pfVar47[10] = *(float *)(puVar52 + 5);
            pfVar47[0xb] = *(float *)((longlong)puVar52 + 0x2c);
            pfVar47[0xc] = *(float *)(puVar52 + 6);
            *(undefined2 *)(pfVar47 + 0xd) = *(undefined2 *)((longlong)puVar52 + 0x34);
            *(undefined2 *)((longlong)pfVar47 + 0x36) = *(undefined2 *)((longlong)puVar52 + 0x36);
            pfVar47[0xe] = *(float *)(puVar52 + 7);
            pfVar47[0xf] = *(float *)((longlong)puVar52 + 0x3c);
            uVar19 = puVar52[9];
            *(undefined8 *)(pfVar47 + 0x10) = puVar52[8];
            *(undefined8 *)(pfVar47 + 0x12) = uVar19;
            fVar80 = *(float *)(puVar52 + 10);
          }
          lVar43 = param_1[8];
          pfVar47[0x14] = fVar80;
          local_1398 = *(uint *)(lVar43 + 0xf0);
          local_1394 = local_1394 + 1;
          uVar34 = (ulonglong)local_1394;
          param_2 = local_1338;
          uVar54 = local_1390;
        } while (local_1394 < local_1398);
      }
      local_cf8._8_8_ = _DAT_140b7b248;
      local_cf8._0_8_ = _DAT_140b7b240;
      local_cd8 = ZEXT816(0);
      pauVar48 = (undefined1 (*) [16])(param_1 + 0x40);
      *pauVar48 = local_cf8;
      *(undefined1 (*) [16])(param_1 + 0x42) = local_cd8;
      param_1[0x44] = 0x3f800000;
      *(undefined1 (*) [16])(param_1 + 0x46) = local_cd8;
      *(undefined4 *)(param_1 + 0x48) = 0;
      if (param_1[0x98] != 0) {
        pauVar48 = (undefined1 (*) [16])(param_1[0x98] + 0x200);
      }
      local_cb8 = local_cd8;
      if (*(int *)(param_1[8] + 0x100) != 0) {
        FUN_1403068b0((int *)(param_1[8] + 0x100),param_1 + 0x4a,param_1[0x66]);
        local_b38._0_4_ = *(float *)*pauVar48 * *(float *)(param_1 + 0x4a);
        local_b38._4_4_ =
             *(float *)((longlong)*pauVar48 + 4) * *(float *)((longlong)param_1 + 0x254);
        local_b38._8_4_ = *(float *)((longlong)*pauVar48 + 8) * *(float *)(param_1 + 0x4b);
        local_b38._12_4_ =
             *(float *)((longlong)*pauVar48 + 0xc) * *(float *)((longlong)param_1 + 0x25c);
        *pauVar48 = local_b38;
      }
      if (*(int *)(param_1[8] + 0x118) != 0) {
        FUN_1403068b0((int *)(param_1[8] + 0x118),param_1 + 0x4e,param_1[0x66]);
        auVar75._0_4_ = *(float *)pauVar48[1] + *(float *)(param_1 + 0x4e);
        auVar75._4_4_ =
             *(float *)((longlong)pauVar48[1] + 4) + *(float *)((longlong)param_1 + 0x274);
        auVar75._8_4_ = *(float *)((longlong)pauVar48[1] + 8) + *(float *)(param_1 + 0x4f);
        auVar75._12_4_ =
             *(float *)((longlong)pauVar48[1] + 0xc) + *(float *)((longlong)param_1 + 0x27c);
        pauVar48[1] = auVar75;
      }
      if (*(int *)(param_1[8] + 0x130) != 0) {
        FUN_140306730((int *)(param_1[8] + 0x130),param_1 + 0x52,param_1[0x66]);
        *(float *)pauVar48[2] = *(float *)(param_1 + 0x52) * *(float *)pauVar48[2];
      }
      if (*(int *)(param_1[8] + 0x148) != 0) {
        FUN_140306730((int *)(param_1[8] + 0x148),(undefined4 *)((longlong)param_1 + 0x2a4),
                      param_1[0x66]);
        *(float *)((longlong)pauVar48[2] + 4) =
             (*(float *)((longlong)param_1 + 0x2a4) + *(float *)((longlong)pauVar48[2] + 4)) -
             *(float *)((longlong)param_1 + 0x2a4) * *(float *)((longlong)pauVar48[2] + 4);
      }
      if (*(int *)(param_1[8] + 0x160) != 0) {
        FUN_140306b90((int *)(param_1[8] + 0x160),param_1 + 0x58,param_1[0x66]);
        fVar131 = *(float *)((longlong)param_1 + 0x2cc);
        auVar75 = *(undefined1 (*) [16])(param_1 + 0x58);
        local_11b8._0_4_ = auVar75._0_4_;
        local_11b8._4_4_ = auVar75._4_4_;
        fStack_11b0 = auVar75._8_4_;
        local_11b8._0_4_ = fVar131 * (float)local_11b8._0_4_;
        local_11b8._4_4_ = fVar131 * (float)local_11b8._4_4_;
        fStack_11b0 = fVar131 * fStack_11b0;
        register0x0000124c = fVar131 * 1.0;
        pauVar48[3] = _local_11b8;
      }
      *(undefined4 *)pauVar48[4] = *(undefined4 *)(param_1[8] + 0x178);
    }
    if ((uVar54 & 4) != 0) {
      lVar43 = param_1[8];
      uVar34 = 0;
      if (*(int *)(lVar43 + 0x328) != 0) {
        do {
          puVar52 = (undefined8 *)(uVar34 * 0x20 + param_1[0x5c]);
          FUN_140306cb0(uVar34 * 0x38 + *(longlong *)(lVar43 + 0x330) + 0x10,puVar52 + 1,*puVar52);
          lVar43 = param_1[8];
          uVar46 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar46;
        } while (uVar46 < *(uint *)(lVar43 + 0x328));
      }
      if (param_1[0x5d] != 0) {
        FUN_140306db0(param_1[8] + 0x350,param_1 + 0x5e,param_1[0x5d]);
      }
      if (param_1[0x61] != 0) {
        FUN_140306db0(param_1[8] + 0x370,param_1 + 0x62,param_1[0x61]);
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 4;
    }
    uVar46 = DAT_140b7b500;
    fVar131 = DAT_140b79fa0;
    if ((uVar54 & 8) != 0) {
      local_1308 = param_1 + 10;
      plVar33 = param_1 + 0x9e;
      uStack_1300 = param_2;
      local_3b8 = local_1308;
      local_3b0 = param_2;
      FUN_1401afb10(&local_3b8);
      plVar45 = param_1 + 0xa6;
      local_318[0] = plVar33;
      FUN_1401afc20(local_318,plVar45);
      if (param_1[0x98] == 0) {
        fVar80 = *(float *)(param_1 + 0xa4) * *(float *)(param_1 + 0xa4);
        fVar82 = *(float *)((longlong)param_1 + 0x524) * *(float *)((longlong)param_1 + 0x524);
        auVar83._4_4_ = fVar82;
        auVar83._0_4_ = fVar80;
        fVar110 = *(float *)(param_1 + 0xa5) * *(float *)(param_1 + 0xa5);
        auVar83._8_4_ = fVar110;
        auVar83._12_4_ =
             *(float *)((longlong)param_1 + 0x52c) * *(float *)((longlong)param_1 + 0x52c);
        auVar85._4_12_ = auVar83._4_12_;
        auVar85._0_4_ = fVar80 + fVar82 + fVar110;
      }
      else {
        auVar85 = ZEXT416(*(uint *)(param_1[0x98] + 0x570));
      }
      lVar43 = param_1[8];
      *(int *)(param_1 + 0xae) = auVar85._0_4_;
      uVar34 = 0;
      local_1394 = *(uint *)(lVar43 + 0x180);
      local_1398 = 0;
      if (local_1394 != 0) {
        do {
          uVar54 = 0;
          auVar51 = *(undefined1 (*) [8])(lVar43 + 0x188);
          lVar43 = param_1[0x69];
          lVar44 = param_1[0x67];
          local_1348 = auVar51;
          pfVar47 = (float *)(uVar34 * 0x40 + lVar44);
          lVar57 = uVar34 * 0x160;
          piVar37 = *(int **)(lVar43 + 0x10 + lVar57);
          local_1388 = *(longlong *)(lVar43 + lVar57);
          puVar52 = (undefined8 *)(lVar43 + lVar57);
          local_1358 = puVar52;
          local_12b8 = pfVar47;
          local_1298 = lVar57;
          if (piVar37 == (int *)0x0) {
            puVar29 = puVar52;
            if (((param_1[0x98] == 0) || ((int)param_1[0x96] != 0)) ||
               (uVar49 = *(uint *)((longlong)auVar51 + 8 + lVar57), uVar49 == 0)) {
LAB_140301e56:
              auVar53 = (undefined1  [8])0x0;
              uVar16 = *(ushort *)((longlong)auVar51 + 4 + lVar57);
              uVar34 = uStack_1360;
              auVar23._8_8_ = 0;
              auVar23._0_8_ = uStack_1360;
              _local_1368 = auVar23 << 0x40;
              if ((uVar16 < local_1394) &&
                 ((~*(ushort *)((longlong)auVar51 + 2 + lVar57) & 0x70) != 0)) {
                lVar30 = (ulonglong)(uint)uVar16 * 0x160;
                auVar53 = (undefined1  [8])(lVar30 + lVar43);
                local_1368 = auVar53;
                _local_1368 = CONCAT88(uVar34,local_1368);
                if (*(int *)(lVar30 + 0x18 + lVar43) == 0) {
                  local_12a8 = lVar30 + 0xd0 + (longlong)auVar51;
                  uStack_12a0 = (ulonglong)uVar16 * 0x40 + lVar44;
                  local_8b8 = local_12a8;
                  local_8b0 = uStack_12a0;
                  FUN_1401afb10(&local_8b8,local_8a8);
                  local_1268 = local_8a8;
                  plStack_1260 = plVar45;
                  local_368 = local_1268;
                  local_360 = plVar45;
                  FUN_1401afb10(&local_368,(longlong)auVar53 + 0x120);
                  FUN_1402f15d0(auVar53);
                }
              }
              lVar43 = _DAT_140b7b248;
              piVar37 = (int *)(lVar57 + 0x10 + (longlong)auVar51);
              if (*piVar37 == 0) {
                if ((auVar53 == (undefined1  [8])0x0) ||
                   ((*(byte *)((longlong)auVar51 + 2 + lVar57) & 0x10) != 0)) {
                  local_c78 = _DAT_140b7b240;
                  lStack_c70 = _DAT_140b7b248;
                  puVar52[4] = _DAT_140b7b240;
                  puVar52[5] = lVar43;
                }
                else {
                  uVar19 = *(undefined8 *)((longlong)auVar53 + 0x28);
                  puVar52[4] = *(undefined8 *)((longlong)auVar53 + 0x20);
                  puVar52[5] = uVar19;
                }
              }
              else {
                FUN_140306eb0(piVar37,puVar52 + 4,local_1388);
                if ((auVar53 != (undefined1  [8])0x0) &&
                   ((*(byte *)((longlong)auVar51 + 2 + lVar57) & 0x10) == 0)) {
                  local_1028 = *(float *)((longlong)auVar53 + 0x20) * *(float *)(puVar52 + 4);
                  fStack_1024 = *(float *)((longlong)auVar53 + 0x24) *
                                *(float *)((longlong)puVar52 + 0x24);
                  fStack_1020 = *(float *)((longlong)auVar53 + 0x28) * *(float *)(puVar52 + 5);
                  fStack_101c = *(float *)((longlong)auVar53 + 0x2c) *
                                *(float *)((longlong)puVar52 + 0x2c);
                  *(float *)(puVar52 + 4) = local_1028;
                  *(float *)((longlong)puVar52 + 0x24) = fStack_1024;
                  *(float *)(puVar52 + 5) = fStack_1020;
                  *(float *)((longlong)puVar52 + 0x2c) = fStack_101c;
                }
                piVar37 = (int *)(lVar57 + 0x40 + (longlong)auVar51);
                if (*piVar37 != 0) {
                  FUN_140306eb0(piVar37,puVar52 + 0xc,local_1388);
                  fVar80 = DAT_140b79cc4;
                  if (DAT_140b79cc4 < (float)((uint)*(float *)(puVar52 + 0xc) & uVar46)) {
                    *(float *)(puVar52 + 4) = *(float *)(puVar52 + 4) / *(float *)(puVar52 + 0xc);
                  }
                  fVar82 = DAT_140b79cc4;
                  if (fVar80 < (float)((uint)*(float *)((longlong)puVar52 + 100) & uVar46)) {
                    *(float *)((longlong)puVar52 + 0x24) =
                         *(float *)((longlong)puVar52 + 0x24) / *(float *)((longlong)puVar52 + 100);
                    fVar80 = fVar82;
                  }
                  fVar82 = *(float *)(puVar52 + 0xd);
                  auVar85 = ZEXT416((uint)fVar82);
                  if (fVar80 < (float)((uint)fVar82 & uVar46)) {
                    *(float *)(puVar52 + 5) = *(float *)(puVar52 + 5) / fVar82;
                  }
                }
              }
              lVar43 = _DAT_140b7b248;
              uVar19 = _DAT_140b7b240;
              lVar44 = lVar57 + 0x28 + (longlong)auVar51;
              local_1330 = lVar44;
              if ((*(int *)((longlong)auVar51 + 0x28 + lVar57) != 0) &&
                 (local_1394 = *(uint *)(local_1388 + 0xb4), local_1394 != 0)) {
                auVar21._8_8_ = _DAT_140b7b248;
                auVar21._0_8_ = _DAT_140b7b240;
                fVar80 = (float)((ulonglong)_DAT_140b7b248 >> 0x20);
                uVar34 = (ulonglong)local_1394;
                piVar37 = (int *)(lVar57 + 0x58 + (longlong)auVar51);
                puVar31 = (undefined4 *)(local_1388 + 0x74 + uVar34 * 8);
                puVar58 = (undefined1 *)((longlong)puVar52 + (uVar34 + 0x20) * 4);
                do {
                  local_13b8 = (undefined ***)(puVar58 + -0x44);
                  uVar54 = (int)uVar34 - 1;
                  uVar34 = (ulonglong)uVar54;
                  FUN_140306fc0(lVar44,puVar31[-2],&local_1308);
                  if (*piVar37 != 0) {
                    local_13b8 = (undefined ***)(puVar58 + -4);
                    FUN_140306fc0(piVar37,puVar31[-2],&local_11c8);
                    if (DAT_140b79cc4 < (float)((uint)local_11c8 & uVar46)) {
                      local_1308 = (longlong *)
                                   CONCAT44(local_1308._4_4_,(float)local_1308 / local_11c8);
                    }
                    if (DAT_140b79cc4 < (float)((uint)local_11c4 & uVar46)) {
                      local_1308 = (longlong *)
                                   CONCAT44(local_1308._4_4_ / local_11c4,(float)local_1308);
                    }
                    auVar85 = ZEXT416((uint)local_11c0);
                    if (DAT_140b79cc4 < (float)((uint)local_11c0 & uVar46)) {
                      uStack_1300 = CONCAT44(uStack_1300._4_4_,(float)uStack_1300 / local_11c0);
                    }
                  }
                  fStack_fdc = (float)puVar31[-1];
                  local_c58 = (float)uVar19;
                  local_b98 = (float)local_1308 - local_c58;
                  fStack_c54 = (float)((ulonglong)uVar19 >> 0x20);
                  fStack_b94 = local_1308._4_4_ - fStack_c54;
                  fStack_b90 = (float)uStack_1300 - (float)lVar43;
                  fStack_b8c = uStack_1300._4_4_ - fVar80;
                  local_fe8 = fStack_fdc * local_b98;
                  fStack_fe4 = fStack_fdc * fStack_b94;
                  fStack_fe0 = fStack_fdc * fStack_b90;
                  fStack_fdc = fStack_fdc * fStack_b8c;
                  local_c58 = local_fe8 + local_c58;
                  fStack_c54 = fStack_fe4 + fStack_c54;
                  fStack_c50 = fStack_fe0 + (float)lVar43;
                  fStack_c4c = fStack_fdc + fVar80;
                  local_fc8 = *(float *)(puVar52 + 4) * local_c58;
                  fStack_fc4 = *(float *)((longlong)puVar52 + 0x24) * fStack_c54;
                  fStack_fc0 = *(float *)(puVar52 + 5) * fStack_c50;
                  fStack_fbc = *(float *)((longlong)puVar52 + 0x2c) * fStack_c4c;
                  *(float *)(puVar52 + 4) = local_fc8;
                  *(float *)((longlong)puVar52 + 0x24) = fStack_fc4;
                  *(float *)(puVar52 + 5) = fStack_fc0;
                  *(float *)((longlong)puVar52 + 0x2c) = fStack_fbc;
                  puVar31 = puVar31 + -2;
                  puVar58 = puVar58 + -4;
                  local_1008 = auVar21;
                } while (uVar54 != 0);
                param_1 = local_1380;
                pfVar47 = local_12b8;
                auVar51 = local_1348;
                auVar53 = local_1368;
                lVar57 = local_1298;
              }
              if (*(int *)((longlong)auVar51 + 0x70 + lVar57) == 0) {
                if ((auVar53 == (undefined1  [8])0x0) ||
                   ((*(byte *)((longlong)auVar51 + 2 + lVar57) & 0x20) != 0)) {
                  local_fa8 = _DAT_140c78450;
                  plStack_fa0 = plRam0000000140c78458;
                  puVar58 = _DAT_140c78450;
                  plVar33 = plRam0000000140c78458;
                }
                else {
                  puVar58 = *(undefined1 **)((longlong)auVar53 + 0xa0);
                  plVar33 = *(longlong **)((longlong)auVar53 + 0xa8);
                }
                puVar52[0x14] = puVar58;
                puVar52[0x15] = plVar33;
              }
              else {
                FUN_140307280((longlong)auVar51 + lVar57 + 0x70,puVar52 + 0x14,local_1388);
                if ((auVar53 != (undefined1  [8])0x0) &&
                   ((*(byte *)((longlong)auVar51 + 2 + lVar57) & 0x20) == 0)) {
                  fVar80 = *(float *)((longlong)puVar52 + 0xac);
                  fVar82 = *(float *)(puVar52 + 0x14);
                  fVar110 = *(float *)((longlong)auVar53 + 0xa0);
                  fVar111 = *(float *)((longlong)auVar53 + 0xac);
                  fVar112 = *(float *)(puVar52 + 0x15);
                  fVar79 = *(float *)((longlong)auVar53 + 0xa4);
                  fVar130 = *(float *)((longlong)puVar52 + 0xa4);
                  fVar132 = *(float *)((longlong)auVar53 + 0xa8);
                  fVar136 = (fVar110 * fVar80 + fVar82 * fVar111 + fVar112 * fVar79) -
                            fVar130 * fVar132;
                  fVar113 = (fVar130 * fVar111 - fVar112 * fVar110) + fVar79 * fVar80 +
                            fVar132 * fVar82;
                  fVar81 = ((fVar130 * fVar110 + fVar112 * fVar111) - fVar79 * fVar82) +
                           fVar132 * fVar80;
                  auVar114._4_4_ = fVar81;
                  auVar114._0_4_ = fVar136;
                  fVar80 = ((fVar80 * fVar111 - fVar110 * fVar82) - fVar130 * fVar79) -
                           fVar132 * fVar112;
                  auVar85._4_4_ = fVar80;
                  auVar85._0_4_ = fVar113;
                  auVar85._8_8_ = 0;
                  auVar114._8_4_ = fVar81;
                  auVar114._12_4_ = fVar80;
                  local_af8._8_8_ = auVar114._8_8_;
                  local_af8._4_4_ = fVar113;
                  local_af8._0_4_ = fVar136;
                  *(undefined1 (*) [16])(puVar52 + 0x14) = local_af8;
                }
              }
              lVar43 = lVar57 + 0x88 + (longlong)auVar51;
              local_1330 = lVar43;
              if ((*(int *)((longlong)auVar51 + 0x88 + lVar57) != 0) &&
                 (*(uint *)(local_1388 + 0xb4) != 0)) {
                uVar34 = (ulonglong)*(uint *)(local_1388 + 0xb4);
                auVar126 = ZEXT816(0);
                auVar134 = ZEXT816(0);
                pfVar32 = (float *)(local_1388 + 0x78 + uVar34 * 8);
                puVar58 = (undefined1 *)((longlong)puVar52 + (uVar34 + 0x30) * 4);
                local_1158 = auVar126;
                do {
                  pfVar47 = pfVar32 + -3;
                  pfVar32 = pfVar32 + -2;
                  puVar58 = puVar58 + -4;
                  uVar54 = (int)uVar34 - 1;
                  uVar34 = (ulonglong)uVar54;
                  local_13b8 = (undefined ***)puVar58;
                  FUN_1403073a0(lVar43,*pfVar47,local_1168);
                  lVar57 = local_1298;
                  pfVar47 = local_12b8;
                  param_1 = local_1380;
                  fVar80 = local_1168._12_4_;
                  fVar111 = auVar126._4_4_;
                  fVar112 = auVar126._8_4_;
                  fVar79 = auVar126._12_4_;
                  fVar82 = local_1168._4_4_;
                  fVar110 = local_1168._8_4_;
                  if (fVar111 * fVar82 + fVar79 * fVar80 +
                      auVar126._0_4_ * local_1168._0_4_ + fVar112 * fVar110 < 0.0) {
                    local_1168._0_4_ = 0.0 - local_1168._0_4_;
                    local_1168._4_4_ = 0.0 - fVar82;
                    local_1168._8_4_ = 0.0 - fVar110;
                    local_1168._12_4_ = 0.0 - fVar80;
                    local_c38 = local_1168;
                  }
                  fVar80 = *pfVar32;
                  auVar134._0_4_ = auVar134._0_4_ + *pfVar32;
                  auVar126._0_4_ = local_1168._0_4_ * fVar80 + auVar126._0_4_;
                  auVar126._4_4_ = local_1168._4_4_ * fVar80 + fVar111;
                  auVar126._8_4_ = local_1168._8_4_ * fVar80 + fVar112;
                  auVar126._12_4_ = local_1168._12_4_ * fVar80 + fVar79;
                } while (uVar54 != 0);
                auVar51 = local_1348;
                auVar85 = local_1168;
                local_1158 = auVar126;
                local_f88 = auVar126;
                if ((DAT_140b79cc4 < auVar134._0_4_) &&
                   (fVar80 = auVar126._4_4_ * auVar126._4_4_ + auVar126._12_4_ * auVar126._12_4_ +
                             auVar126._0_4_ * auVar126._0_4_ + auVar126._8_4_ * auVar126._8_4_,
                   _DAT_140c42008 < fVar80)) {
                  auVar61._0_4_ = SQRT(fVar80);
                  auVar61._4_4_ = auVar61._0_4_;
                  auVar61._8_4_ = auVar61._0_4_;
                  auVar61._12_4_ = auVar61._0_4_;
                  local_10d8 = divps(auVar126,auVar61);
                  local_1108 = _DAT_140c78450;
                  plStack_1100 = plRam0000000140c78458;
                  pauVar48 = (undefined1 (*) [16])FUN_1401b1ee0(local_b78,&local_1108,local_10d8);
                  fVar80 = *(float *)((longlong)puVar52 + 0xac);
                  fVar82 = *(float *)(puVar52 + 0x14);
                  fVar110 = *(float *)((longlong)puVar52 + 0xa4);
                  fVar111 = *(float *)(puVar52 + 0x15);
                  fVar112 = *(float *)*pauVar48;
                  fVar79 = *(float *)(*pauVar48 + 4);
                  fVar130 = *(float *)(*pauVar48 + 8);
                  fVar132 = *(float *)(*pauVar48 + 0xc);
                  local_1158 = *pauVar48;
                  fVar136 = (fVar112 * fVar80 + fVar132 * fVar82 + fVar110 * fVar130) -
                            fVar79 * fVar111;
                  fVar113 = (fVar79 * fVar80 - fVar130 * fVar82) + fVar132 * fVar110 +
                            fVar112 * fVar111;
                  fVar81 = ((fVar130 * fVar80 + fVar79 * fVar82) - fVar110 * fVar112) +
                           fVar132 * fVar111;
                  auVar84._4_4_ = fVar79;
                  auVar84._0_4_ = fVar113;
                  auVar115._4_4_ = fVar81;
                  auVar115._0_4_ = fVar136;
                  fVar80 = ((fVar132 * fVar80 - fVar112 * fVar82) - fVar110 * fVar79) -
                           fVar130 * fVar111;
                  auVar84._8_4_ = fVar79;
                  auVar84._12_4_ = fVar132;
                  auVar85._8_8_ = auVar84._8_8_;
                  auVar85._4_4_ = fVar80;
                  auVar85._0_4_ = fVar113;
                  auVar115._8_4_ = fVar81;
                  auVar115._12_4_ = fVar80;
                  local_f68._8_8_ = auVar115._8_8_;
                  local_f68._4_4_ = fVar113;
                  local_f68._0_4_ = fVar136;
                  *(undefined1 (*) [16])(puVar52 + 0x14) = local_f68;
                }
              }
              puVar2 = puVar52 + 0x1c;
              local_1368 = (undefined1  [8])puVar2;
              if (*(int *)((longlong)auVar51 + lVar57 + 0xa0) == 0) {
                local_c18 = 0;
                uStack_c10 = 0;
                *puVar2 = 0;
                puVar52[0x1d] = 0;
              }
              else {
                FUN_140307720((longlong)auVar51 + lVar57 + 0xa0,puVar2,local_1388);
              }
              lVar43 = lVar57 + 0xb8 + (longlong)auVar51;
              local_1330 = lVar43;
              if ((*(int *)((longlong)auVar51 + 0xb8 + lVar57) != 0) &&
                 (*(uint *)(local_1388 + 0xb4) != 0)) {
                uVar34 = (ulonglong)*(uint *)(local_1388 + 0xb4);
                pfVar47 = (float *)(local_1388 + 0x78 + uVar34 * 8);
                puVar58 = (undefined1 *)((longlong)puVar52 + (uVar34 + 0x40) * 4);
                auVar51 = local_1368;
                do {
                  pfVar32 = pfVar47 + -3;
                  pfVar47 = pfVar47 + -2;
                  puVar58 = puVar58 + -4;
                  local_13b8 = (undefined ***)puVar58;
                  FUN_140307830(lVar43,*pfVar32,&local_10e8);
                  fStack_f3c = *pfVar47;
                  local_f48 = local_10e8 * fStack_f3c;
                  fStack_f44 = fStack_10e4 * fStack_f3c;
                  fStack_f40 = fStack_10e0 * fStack_f3c;
                  fStack_f3c = fStack_10dc * fStack_f3c;
                  *(float *)auVar51 = *(float *)auVar51 + local_f48;
                  *(float *)((longlong)auVar51 + 4) = *(float *)((longlong)auVar51 + 4) + fStack_f44
                  ;
                  *(float *)((longlong)auVar51 + 8) = *(float *)((longlong)auVar51 + 8) + fStack_f40
                  ;
                  *(float *)((longlong)auVar51 + 0xc) =
                       *(float *)((longlong)auVar51 + 0xc) + fStack_f3c;
                  uVar54 = (int)uVar34 - 1;
                  uVar34 = (ulonglong)uVar54;
                } while (uVar54 != 0);
                param_1 = local_1380;
                pfVar47 = local_12b8;
                auVar51 = local_1348;
                puVar29 = local_1358;
                lVar57 = local_1298;
              }
              if ((auVar53 != (undefined1  [8])0x0) &&
                 ((*(byte *)((longlong)auVar51 + 2 + lVar57) & 0x40) == 0)) {
                fVar80 = *(float *)(puVar29 + 0x1c);
                fVar82 = *(float *)((longlong)puVar29 + 0xe4);
                fVar110 = *(float *)(puVar29 + 0x1d);
                auVar85._0_4_ =
                     fVar82 * *(float *)((longlong)auVar53 + 0x130) +
                     fVar80 * *(float *)((longlong)auVar53 + 0x120) +
                     fVar110 * *(float *)((longlong)auVar53 + 0x140) +
                     *(float *)((longlong)auVar53 + 0x150);
                auVar85._4_4_ =
                     fVar82 * *(float *)((longlong)auVar53 + 0x134) +
                     fVar80 * *(float *)((longlong)auVar53 + 0x124) +
                     fVar110 * *(float *)((longlong)auVar53 + 0x144) +
                     *(float *)((longlong)auVar53 + 0x154);
                auVar85._8_4_ =
                     fVar82 * *(float *)((longlong)auVar53 + 0x138) +
                     fVar80 * *(float *)((longlong)auVar53 + 0x128) +
                     fVar110 * *(float *)((longlong)auVar53 + 0x148) +
                     *(float *)((longlong)auVar53 + 0x158);
                auVar85._12_4_ =
                     fVar82 * *(float *)((longlong)auVar53 + 0x13c) +
                     fVar80 * *(float *)((longlong)auVar53 + 300) +
                     fVar110 * *(float *)((longlong)auVar53 + 0x14c) +
                     *(float *)((longlong)auVar53 + 0x15c);
                *(undefined1 (*) [16])(puVar29 + 0x1c) = auVar85;
              }
              FUN_1402f13d0(puVar29);
              pbVar20 = (byte *)puVar29[1];
              if (pbVar20 != (byte *)0x0) {
                if ((*pbVar20 & 4) != 0) {
                  fVar80 = *(float *)(pbVar20 + 0x30);
                  fVar82 = *(float *)(pbVar20 + 0x34);
                  fVar110 = *(float *)(pbVar20 + 0x38);
                  auVar85._0_4_ =
                       fVar82 * *(float *)(puVar29 + 0x26) + fVar80 * *(float *)(puVar29 + 0x24) +
                       fVar110 * *(float *)(puVar29 + 0x28) + *(float *)(puVar29 + 0x2a);
                  auVar85._4_4_ =
                       fVar82 * *(float *)((longlong)puVar29 + 0x134) +
                       fVar80 * *(float *)((longlong)puVar29 + 0x124) +
                       fVar110 * *(float *)((longlong)puVar29 + 0x144) +
                       *(float *)((longlong)puVar29 + 0x154);
                  auVar85._8_4_ =
                       fVar82 * *(float *)(puVar29 + 0x27) + fVar80 * *(float *)(puVar29 + 0x25) +
                       fVar110 * *(float *)(puVar29 + 0x29) + *(float *)(puVar29 + 0x2b);
                  auVar85._12_4_ =
                       fVar82 * *(float *)((longlong)puVar29 + 0x13c) +
                       fVar80 * *(float *)((longlong)puVar29 + 300) +
                       fVar110 * *(float *)((longlong)puVar29 + 0x14c) +
                       *(float *)((longlong)puVar29 + 0x15c);
                  *(undefined1 (*) [16])(puVar29 + 0x1c) = auVar85;
                  local_b18 = auVar85;
                }
                if ((*pbVar20 & 2) != 0) {
                  fVar80 = *(float *)(pbVar20 + 0x2c);
                  fVar82 = *(float *)(pbVar20 + 0x20);
                  fVar110 = *(float *)((longlong)puVar29 + 0xac);
                  fVar111 = *(float *)(puVar29 + 0x14);
                  fVar112 = *(float *)(pbVar20 + 0x28);
                  fVar79 = *(float *)((longlong)puVar29 + 0xa4);
                  fVar130 = *(float *)(pbVar20 + 0x24);
                  fVar132 = *(float *)(puVar29 + 0x15);
                  fVar136 = (fVar82 * fVar110 + fVar80 * fVar111 + fVar112 * fVar79) -
                            fVar130 * fVar132;
                  fVar113 = (fVar130 * fVar110 - fVar112 * fVar111) + fVar80 * fVar79 +
                            fVar82 * fVar132;
                  fVar81 = ((fVar112 * fVar110 + fVar130 * fVar111) - fVar82 * fVar79) +
                           fVar80 * fVar132;
                  auVar116._4_4_ = fVar81;
                  auVar116._0_4_ = fVar136;
                  fVar80 = ((fVar80 * fVar110 - fVar82 * fVar111) - fVar130 * fVar79) -
                           fVar112 * fVar132;
                  auVar85._4_4_ = fVar80;
                  auVar85._0_4_ = fVar113;
                  auVar85._8_8_ = 0;
                  auVar116._8_4_ = fVar81;
                  auVar116._12_4_ = fVar80;
                  local_f28._8_8_ = auVar116._8_8_;
                  local_f28._4_4_ = fVar113;
                  local_f28._0_4_ = fVar136;
                  *(undefined1 (*) [16])(puVar29 + 0x14) = local_f28;
                }
                if ((*pbVar20 & 1) != 0) {
                  local_bf8 = *(float *)(pbVar20 + 0x10) * *(float *)(puVar52 + 4);
                  fStack_bf4 = *(float *)(pbVar20 + 0x14) * *(float *)((longlong)puVar52 + 0x24);
                  fStack_bf0 = *(float *)(pbVar20 + 0x18) * *(float *)(puVar52 + 5);
                  fStack_bec = *(float *)(pbVar20 + 0x1c) * *(float *)((longlong)puVar52 + 0x2c);
                  *(float *)(puVar52 + 4) = local_bf8;
                  *(float *)((longlong)puVar52 + 0x24) = fStack_bf4;
                  *(float *)(puVar52 + 5) = fStack_bf0;
                  *(float *)((longlong)puVar52 + 0x2c) = fStack_bec;
                }
                FUN_1402f13d0(puVar29);
              }
              local_868 = lVar57 + 0x110 + (longlong)auVar51;
              local_860 = puVar29 + 0x24;
              local_12d8._8_8_ = local_860;
              local_12d8._0_8_ = local_868;
              FUN_1401afb10(&local_868,local_858);
              local_12f8 = local_858;
              uStack_12f0 = param_1 + 0x9e;
              local_688 = local_12f8;
              local_680 = uStack_12f0;
              FUN_1401afb10(&local_688,pfVar47);
              fVar80 = DAT_140b79e48;
              uVar16 = *(ushort *)((longlong)auVar51 + 2 + lVar57);
              if ((uVar16 & 0x428f) == 0) {
                if ((*(byte *)((ulonglong)*(ushort *)((longlong)auVar51 + 6 + lVar57) * 0x60 + 0x36
                              + param_1[0x3e]) & 2) != 0) {
                  *pfVar47 = SQRT(*pfVar47 * *pfVar47 + pfVar47[1] * pfVar47[1] +
                                  pfVar47[2] * pfVar47[2]);
                  pfVar47[1] = 0.0;
                  pfVar47[2] = 0.0;
                  fVar80 = pfVar47[4];
                  fVar82 = pfVar47[5];
                  pfVar47[4] = 0.0;
                  pfVar47[5] = 0.0;
                  pfVar47[6] = SQRT(fVar80 * fVar80 + fVar82 * fVar82 + pfVar47[6] * pfVar47[6]);
                  fVar80 = pfVar47[9] * pfVar47[9];
                  fVar82 = pfVar47[10] * pfVar47[10];
                  auVar85._0_4_ =
                       (float)((uint)SQRT(pfVar47[8] * pfVar47[8] + fVar80 + fVar82) ^ DAT_140b7b530
                              );
                  auVar85._4_4_ = (float)((uint)fVar80 ^ _UNK_140b7b534);
                  auVar85._8_4_ = (float)((uint)fVar82 ^ _UNK_140b7b538);
                  auVar85._12_4_ = (float)((uint)(pfVar47[0xb] * pfVar47[0xb]) ^ _UNK_140b7b53c);
                  pfVar47[8] = 0.0;
                  pfVar47[9] = auVar85._0_4_;
                  pfVar47[10] = 0.0;
                  *(undefined4 *)(puVar29 + 3) = 0;
                }
              }
              else {
                if ((uVar16 & 0x200) != 0) {
                  fVar110 = *pfVar47;
                  fVar111 = pfVar47[1];
                  fVar112 = pfVar47[2];
                  lVar43 = param_1[2];
                  fVar79 = *(float *)(lVar43 + 0x100);
                  fVar130 = *(float *)(lVar43 + 0x104);
                  fVar132 = *(float *)(lVar43 + 0x108);
                  fVar81 = *(float *)(lVar43 + 0x10c);
                  local_f08 = fVar132 * fVar111 - fVar130 * fVar112;
                  fStack_f04 = fVar79 * fVar112 - fVar132 * fVar110;
                  fStack_f00 = fVar130 * fVar110 - fVar79 * fVar111;
                  fStack_efc = fVar81 * pfVar47[3] - fVar81 * pfVar47[3];
                  fVar82 = fStack_f04 * fStack_f04;
                  auVar117._4_4_ = fVar82;
                  auVar117._0_4_ = local_f08 * local_f08;
                  auVar117._8_4_ = fStack_f00 * fStack_f00;
                  auVar117._12_4_ = fStack_efc * fStack_efc;
                  auVar76._4_4_ = fVar82;
                  auVar76._0_4_ = fVar82;
                  auVar76._8_4_ = fVar82;
                  auVar76._12_4_ = fVar82;
                  auVar118._4_12_ = auVar117._4_12_;
                  auVar118._0_4_ = local_f08 * local_f08 + fVar82 + fStack_f00 * fStack_f00;
                  auVar75 = rsqrtss(auVar76,auVar118);
                  fVar82 = auVar75._0_4_;
                  fVar82 = (fVar131 - auVar118._0_4_ * fVar82 * fVar82) * DAT_140b79e48 * fVar82;
                  if (fVar82 <= 0.0) {
                    fVar82 = 0.0;
                  }
                  local_b58._0_4_ = fVar82 * local_f08;
                  local_b58._4_4_ = fVar82 * fStack_f04;
                  local_b58._8_4_ = fVar82 * fStack_f00;
                  local_b58._12_4_ = fVar82 * fStack_efc;
                  local_ee8 = local_b58._8_4_ * fVar130 - local_b58._4_4_ * fVar132;
                  fStack_ee4 = local_b58._0_4_ * fVar132 - local_b58._8_4_ * fVar79;
                  fStack_ee0 = local_b58._4_4_ * fVar79 - local_b58._0_4_ * fVar130;
                  fStack_edc = local_b58._12_4_ * fVar81 - local_b58._12_4_ * fVar81;
                  fStack_bcc = SQRT(fVar110 * fVar110 + fVar111 * fVar111 + fVar112 * fVar112);
                  local_bd8 = local_ee8 * fStack_bcc;
                  fStack_bd4 = fStack_ee4 * fStack_bcc;
                  fStack_bd0 = fStack_ee0 * fStack_bcc;
                  fStack_bcc = fStack_edc * fStack_bcc;
                  *pfVar47 = local_bd8;
                  pfVar47[1] = fStack_bd4;
                  pfVar47[2] = fStack_bd0;
                  fStack_ebc = SQRT(pfVar47[4] * pfVar47[4] + pfVar47[5] * pfVar47[5] +
                                    pfVar47[6] * pfVar47[6]);
                  local_ec8 = *(float *)(lVar43 + 0x100) * fStack_ebc;
                  fStack_ec4 = *(float *)(lVar43 + 0x104) * fStack_ebc;
                  fStack_ec0 = *(float *)(lVar43 + 0x108) * fStack_ebc;
                  fStack_ebc = *(float *)(lVar43 + 0x10c) * fStack_ebc;
                  pfVar47[4] = local_ec8;
                  pfVar47[5] = fStack_ec4;
                  pfVar47[6] = fStack_ec0;
                  fVar82 = SQRT(pfVar47[8] * pfVar47[8] + pfVar47[9] * pfVar47[9] +
                                pfVar47[10] * pfVar47[10]);
                  local_ad8._0_4_ = fVar82 * local_b58._0_4_;
                  local_ad8._4_4_ = fVar82 * local_b58._4_4_;
                  local_ad8._8_4_ = fVar82 * local_b58._8_4_;
                  local_ad8._12_4_ = fVar82 * local_b58._12_4_;
                  pfVar47[8] = local_ad8._0_4_;
                  auVar85 = local_ad8 >> 0x40;
                  pfVar47[9] = local_ad8._4_4_;
                  pfVar47[10] = local_ad8._8_4_;
                }
                uVar16 = *(ushort *)((longlong)auVar51 + 2 + lVar57);
                if ((char)uVar16 < '\0') {
                  local_ea8 = pfVar47[0xc];
                  fStack_ea4 = pfVar47[0xd];
                  fStack_ea0 = pfVar47[0xe];
                  fVar82 = pfVar47[0xf];
                  auVar119._4_4_ = fStack_ea4 * fStack_ea4;
                  auVar119._0_4_ = local_ea8 * local_ea8;
                  auVar119._8_4_ = fStack_ea0 * fStack_ea0;
                  auVar119._12_4_ = fVar82 * fVar82;
                  auVar120._4_12_ = auVar119._4_12_;
                  auVar120._0_4_ =
                       local_ea8 * local_ea8 + fStack_ea4 * fStack_ea4 + fStack_ea0 * fStack_ea0;
                  auVar75 = rsqrtss(auVar85,auVar120);
                  fStack_e9c = auVar75._0_4_;
                  fStack_e9c = (fVar131 - auVar120._0_4_ * fStack_e9c * fStack_e9c) * fVar80 *
                               fStack_e9c;
                  local_e88 = _DAT_140c77870;
                  fStack_e84 = fRam0000000140c77874;
                  fStack_e80 = fRam0000000140c77878;
                  fStack_e7c = fRam0000000140c7787c;
                  if (fStack_e9c <= 0.0) {
                    fStack_e9c = 0.0;
                  }
                  local_ea8 = fStack_e9c * local_ea8;
                  fStack_ea4 = fStack_e9c * fStack_ea4;
                  fStack_ea0 = fStack_e9c * fStack_ea0;
                  fStack_e9c = fStack_e9c * fVar82;
                  local_bb8 = 0.0 - local_ea8;
                  fStack_bb4 = 0.0 - fStack_ea4;
                  fStack_bb0 = 0.0 - fStack_ea0;
                  fStack_bac = 0.0 - fStack_e9c;
                  local_c98 = fStack_bb0 * fRam0000000140c77874 - fStack_bb4 * fRam0000000140c77878;
                  fStack_c94 = local_bb8 * fRam0000000140c77878 - fStack_bb0 * _DAT_140c77870;
                  fStack_c90 = fStack_bb4 * _DAT_140c77870 - local_bb8 * fRam0000000140c77874;
                  fStack_c8c = fStack_bac * fRam0000000140c7787c - fStack_bac * fRam0000000140c7787c
                  ;
                  fVar82 = fStack_c94 * fStack_c94;
                  auVar86._4_4_ = fVar82;
                  auVar86._0_4_ = local_c98 * local_c98;
                  auVar86._8_4_ = fStack_c90 * fStack_c90;
                  auVar86._12_4_ = fStack_c8c * fStack_c8c;
                  auVar62._4_4_ = fVar82;
                  auVar62._0_4_ = fVar82;
                  auVar62._8_4_ = fVar82;
                  auVar62._12_4_ = fVar82;
                  auVar87._4_12_ = auVar86._4_12_;
                  auVar87._0_4_ = local_c98 * local_c98 + fVar82 + fStack_c90 * fStack_c90;
                  auVar75 = rsqrtss(auVar62,auVar87);
                  fVar82 = auVar75._0_4_;
                  fVar82 = (fVar131 - auVar87._0_4_ * fVar82 * fVar82) * fVar80 * fVar82;
                  if (fVar82 <= 0.0) {
                    fVar82 = 0.0;
                  }
                  local_e68._0_4_ = fVar82 * local_c98;
                  local_e68._4_4_ = fVar82 * fStack_c94;
                  local_e68._8_4_ = fVar82 * fStack_c90;
                  local_e68._12_4_ = fVar82 * fStack_c8c;
                  local_c88 = local_e68._8_4_ * fStack_bb4 - local_e68._4_4_ * fStack_bb0;
                  fStack_c84 = local_e68._0_4_ * fStack_bb0 - local_e68._8_4_ * local_bb8;
                  fStack_c80 = local_e68._4_4_ * local_bb8 - local_e68._0_4_ * fStack_bb4;
                  fStack_c7c = local_e68._12_4_ * fStack_bac - local_e68._12_4_ * fStack_bac;
                  fStack_e3c = SQRT(*pfVar47 * *pfVar47 + pfVar47[1] * pfVar47[1] +
                                    pfVar47[2] * pfVar47[2]);
                  local_e48 = fStack_e3c * local_e68._0_4_;
                  fStack_e44 = fStack_e3c * local_e68._4_4_;
                  fStack_e40 = fStack_e3c * local_e68._8_4_;
                  fStack_e3c = fStack_e3c * local_e68._12_4_;
                  *pfVar47 = local_e48;
                  pfVar47[1] = fStack_e44;
                  pfVar47[2] = fStack_e40;
                  fVar80 = SQRT(pfVar47[4] * pfVar47[4] + pfVar47[5] * pfVar47[5] +
                                pfVar47[6] * pfVar47[6]);
                  local_c68._0_4_ = local_c88 * fVar80;
                  local_c68._4_4_ = fStack_c84 * fVar80;
                  local_c68._8_4_ = fStack_c80 * fVar80;
                  local_c68._12_4_ = fStack_c7c * fVar80;
                  pfVar47[4] = local_c68._0_4_;
                  pfVar47[5] = local_c68._4_4_;
                  pfVar47[6] = local_c68._8_4_;
                  fVar80 = SQRT(pfVar47[8] * pfVar47[8] + pfVar47[9] * pfVar47[9] +
                                pfVar47[10] * pfVar47[10]);
                  auVar88._0_4_ = fVar80 * local_bb8;
                  auVar88._4_4_ = fVar80 * fStack_bb4;
                  auVar88._8_4_ = fVar80 * fStack_bb0;
                  auVar88._12_4_ = fVar80 * fStack_bac;
                  local_e28 = auVar88;
LAB_1403035bc:
                  pfVar47[8] = auVar88._0_4_;
                  auVar85 = auVar88 >> 0x40;
                  pfVar47[9] = auVar88._4_4_;
                  pfVar47[10] = auVar88._8_4_;
                }
                else {
                  if ((uVar16 & 1) != 0) {
                    local_c48 = pfVar47[0xc];
                    fStack_c44 = pfVar47[0xd];
                    fStack_c40 = pfVar47[0xe];
                    fVar82 = pfVar47[0xf];
                    auVar121._4_4_ = fStack_c44 * fStack_c44;
                    auVar121._0_4_ = local_c48 * local_c48;
                    auVar121._8_4_ = fStack_c40 * fStack_c40;
                    auVar121._12_4_ = fVar82 * fVar82;
                    auVar122._4_12_ = auVar121._4_12_;
                    auVar122._0_4_ =
                         local_c48 * local_c48 + fStack_c44 * fStack_c44 + fStack_c40 * fStack_c40;
                    auVar75 = rsqrtss(auVar85,auVar122);
                    fStack_c3c = auVar75._0_4_;
                    fStack_c3c = (fVar131 - auVar122._0_4_ * fStack_c3c * fStack_c3c) * fVar80 *
                                 fStack_c3c;
                    local_c28 = _DAT_140c77870;
                    fStack_c24 = fRam0000000140c77874;
                    fStack_c20 = fRam0000000140c77878;
                    fStack_c1c = fRam0000000140c7787c;
                    if (fStack_c3c <= 0.0) {
                      fStack_c3c = 0.0;
                    }
                    local_c48 = fStack_c3c * local_c48;
                    fStack_c44 = fStack_c3c * fStack_c44;
                    fStack_c40 = fStack_c3c * fStack_c40;
                    fStack_c3c = fStack_c3c * fVar82;
                    local_e08 = 0.0 - local_c48;
                    fStack_e04 = 0.0 - fStack_c44;
                    fStack_e00 = 0.0 - fStack_c40;
                    fStack_dfc = 0.0 - fStack_c3c;
                    local_1058 = fStack_e00 * fRam0000000140c77874 -
                                 fStack_e04 * fRam0000000140c77878;
                    fStack_1054 = local_e08 * fRam0000000140c77878 - fStack_e00 * _DAT_140c77870;
                    fStack_1050 = fStack_e04 * _DAT_140c77870 - local_e08 * fRam0000000140c77874;
                    fStack_104c = fStack_dfc * fRam0000000140c7787c -
                                  fStack_dfc * fRam0000000140c7787c;
                    fVar82 = fStack_1054 * fStack_1054;
                    auVar89._4_4_ = fVar82;
                    auVar89._0_4_ = local_1058 * local_1058;
                    auVar89._8_4_ = fStack_1050 * fStack_1050;
                    auVar89._12_4_ = fStack_104c * fStack_104c;
                    auVar63._4_4_ = fVar82;
                    auVar63._0_4_ = fVar82;
                    auVar63._8_4_ = fVar82;
                    auVar63._12_4_ = fVar82;
                    auVar90._4_12_ = auVar89._4_12_;
                    auVar90._0_4_ = local_1058 * local_1058 + fVar82 + fStack_1050 * fStack_1050;
                    auVar75 = rsqrtss(auVar63,auVar90);
                    fVar82 = auVar75._0_4_;
                    fVar82 = (fVar131 - auVar90._0_4_ * fVar82 * fVar82) * fVar80 * fVar82;
                    if (fVar82 <= 0.0) {
                      fVar82 = 0.0;
                    }
                    local_c08._0_4_ = fVar82 * local_1058;
                    local_c08._4_4_ = fVar82 * fStack_1054;
                    local_c08._8_4_ = fVar82 * fStack_1050;
                    local_c08._12_4_ = fVar82 * fStack_104c;
                    local_dc8._0_4_ = local_c08._8_4_ * fStack_e04 - local_c08._4_4_ * fStack_e00;
                    local_dc8._4_4_ = local_c08._0_4_ * fStack_e00 - local_c08._8_4_ * local_e08;
                    local_dc8._8_4_ = local_c08._4_4_ * local_e08 - local_c08._0_4_ * fStack_e04;
                    local_dc8._12_4_ = local_c08._12_4_ * fStack_dfc - local_c08._12_4_ * fStack_dfc
                    ;
                    fStack_bdc = SQRT(*pfVar47 * *pfVar47 + pfVar47[1] * pfVar47[1] +
                                      pfVar47[2] * pfVar47[2]);
                    local_be8 = fStack_bdc * local_c08._0_4_;
                    fStack_be4 = fStack_bdc * local_c08._4_4_;
                    fStack_be0 = fStack_bdc * local_c08._8_4_;
                    fStack_bdc = fStack_bdc * local_c08._12_4_;
                    *pfVar47 = local_be8;
                    pfVar47[1] = fStack_be4;
                    pfVar47[2] = fStack_be0;
                    fStack_d9c = SQRT(pfVar47[4] * pfVar47[4] + pfVar47[5] * pfVar47[5] +
                                      pfVar47[6] * pfVar47[6]);
                    local_da8 = fStack_d9c * local_e08;
                    fStack_da4 = fStack_d9c * fStack_e04;
                    fStack_da0 = fStack_d9c * fStack_e00;
                    fStack_d9c = fStack_d9c * fStack_dfc;
                    pfVar47[4] = local_da8;
                    pfVar47[5] = fStack_da4;
                    pfVar47[6] = fStack_da0;
                    fVar80 = (float)((uint)SQRT(pfVar47[8] * pfVar47[8] + pfVar47[9] * pfVar47[9] +
                                                pfVar47[10] * pfVar47[10]) ^ DAT_140b7b530);
                    auVar88._0_4_ = fVar80 * local_dc8._0_4_;
                    auVar88._4_4_ = fVar80 * local_dc8._4_4_;
                    auVar88._8_4_ = fVar80 * local_dc8._8_4_;
                    auVar88._12_4_ = fVar80 * local_dc8._12_4_;
                    local_bc8 = auVar88;
                    goto LAB_1403035bc;
                  }
                  if ((uVar16 & 2) != 0) {
                    fStack_d5c = SQRT(pfVar47[4] * pfVar47[4] + pfVar47[5] * pfVar47[5] +
                                      pfVar47[6] * pfVar47[6]);
                    local_d88 = pfVar47[0xe] * pfVar47[1] - pfVar47[0xd] * pfVar47[2];
                    fStack_d84 = pfVar47[0xc] * pfVar47[2] - pfVar47[0xe] * *pfVar47;
                    fStack_d80 = pfVar47[0xd] * *pfVar47 - pfVar47[0xc] * pfVar47[1];
                    fStack_d7c = pfVar47[0xf] * pfVar47[3] - pfVar47[0xf] * pfVar47[3];
                    fVar82 = fStack_d84 * fStack_d84;
                    auVar91._4_4_ = fVar82;
                    auVar91._0_4_ = local_d88 * local_d88;
                    fVar110 = fStack_d80 * fStack_d80;
                    auVar91._8_4_ = fVar110;
                    auVar91._12_4_ = fStack_d7c * fStack_d7c;
                    auVar92._4_12_ = auVar91._4_12_;
                    auVar92._0_4_ = local_d88 * local_d88 + fVar82 + fVar110;
                    auVar64._4_4_ = fVar82;
                    auVar64._0_4_ = auVar92._0_4_;
                    auVar64._8_4_ = fVar110;
                    auVar64._12_4_ = fStack_d7c * fStack_d7c;
                    auVar75 = rsqrtss(auVar64,auVar92);
                    fStack_b9c = auVar75._0_4_;
                    fStack_b9c = (fVar131 - auVar92._0_4_ * fStack_b9c * fStack_b9c) * fVar80 *
                                 fStack_b9c;
                    if (fStack_b9c <= 0.0) {
                      fStack_b9c = 0.0;
                    }
                    local_ba8 = fStack_b9c * local_d88;
                    fStack_ba4 = fStack_b9c * fStack_d84;
                    fStack_ba0 = fStack_b9c * fStack_d80;
                    fStack_b9c = fStack_b9c * fStack_d7c;
                    local_d68 = local_ba8 * fStack_d5c;
                    fStack_d64 = fStack_ba4 * fStack_d5c;
                    fStack_d60 = fStack_ba0 * fStack_d5c;
                    fStack_d5c = fStack_b9c * fStack_d5c;
                    pfVar47[4] = local_d68;
                    pfVar47[5] = fStack_d64;
                    pfVar47[6] = fStack_d60;
                    fVar111 = SQRT(pfVar47[8] * pfVar47[8] + pfVar47[9] * pfVar47[9] +
                                   pfVar47[10] * pfVar47[10]);
                    local_b88._0_4_ = pfVar47[6] * pfVar47[1] - pfVar47[5] * pfVar47[2];
                    local_b88._4_4_ = pfVar47[4] * pfVar47[2] - pfVar47[6] * *pfVar47;
                    local_b88._8_4_ = pfVar47[5] * *pfVar47 - pfVar47[4] * pfVar47[1];
                    local_b88._12_4_ = pfVar47[7] * pfVar47[3] - pfVar47[7] * pfVar47[3];
                    fVar82 = local_b88._4_4_ * local_b88._4_4_;
                    auVar93._4_4_ = fVar82;
                    auVar93._0_4_ = local_b88._0_4_ * local_b88._0_4_;
                    fVar110 = local_b88._8_4_ * local_b88._8_4_;
                    auVar93._8_4_ = fVar110;
                    auVar93._12_4_ = local_b88._12_4_ * local_b88._12_4_;
                    auVar94._4_12_ = auVar93._4_12_;
                    auVar94._0_4_ = local_b88._0_4_ * local_b88._0_4_ + fVar82 + fVar110;
                    auVar65._4_4_ = fVar82;
                    auVar65._0_4_ = auVar94._0_4_;
                    auVar65._8_4_ = fVar110;
                    auVar65._12_4_ = local_b88._12_4_ * local_b88._12_4_;
                    auVar75 = rsqrtss(auVar65,auVar94);
                    fStack_d3c = auVar75._0_4_;
                    auVar85._0_4_ = auVar94._0_4_ * fStack_d3c * fStack_d3c;
                    auVar85._4_12_ = auVar94._4_12_;
                    fStack_d3c = (fVar131 - auVar85._0_4_) * fVar80 * fStack_d3c;
                    if (fStack_d3c <= 0.0) {
                      fStack_d3c = 0.0;
                    }
                    local_d48 = fStack_d3c * local_b88._0_4_;
                    fStack_d44 = fStack_d3c * local_b88._4_4_;
                    fStack_d40 = fStack_d3c * local_b88._8_4_;
                    fStack_d3c = fStack_d3c * local_b88._12_4_;
                    auVar133._0_4_ = local_d48 * fVar111;
                    auVar133._4_4_ = fStack_d44 * fVar111;
                    auVar133._8_4_ = fStack_d40 * fVar111;
                    local_b68._12_4_ = fStack_d3c * fVar111;
                    local_b68._0_12_ = auVar133;
LAB_1403031ef:
                    pfVar47[8] = auVar133._0_4_;
                    pfVar47[9] = auVar133._4_4_;
                    pfVar47[10] = auVar133._8_4_;
                    *(undefined4 *)(puVar29 + 3) = 0;
                    goto LAB_1403036ac;
                  }
                  if ((uVar16 & 4) != 0) {
                    fStack_cfc = SQRT(*pfVar47 * *pfVar47 + pfVar47[1] * pfVar47[1] +
                                      pfVar47[2] * pfVar47[2]);
                    local_d28 = pfVar47[6] * pfVar47[0xd] - pfVar47[5] * pfVar47[0xe];
                    fStack_d24 = pfVar47[4] * pfVar47[0xe] - pfVar47[6] * pfVar47[0xc];
                    fStack_d20 = pfVar47[5] * pfVar47[0xc] - pfVar47[4] * pfVar47[0xd];
                    fStack_d1c = pfVar47[7] * pfVar47[0xf] - pfVar47[7] * pfVar47[0xf];
                    fVar82 = fStack_d24 * fStack_d24;
                    auVar95._4_4_ = fVar82;
                    auVar95._0_4_ = local_d28 * local_d28;
                    fVar110 = fStack_d20 * fStack_d20;
                    auVar95._8_4_ = fVar110;
                    auVar95._12_4_ = fStack_d1c * fStack_d1c;
                    auVar96._4_12_ = auVar95._4_12_;
                    auVar96._0_4_ = local_d28 * local_d28 + fVar82 + fVar110;
                    auVar66._4_4_ = fVar82;
                    auVar66._0_4_ = auVar96._0_4_;
                    auVar66._8_4_ = fVar110;
                    auVar66._12_4_ = fStack_d1c * fStack_d1c;
                    auVar75 = rsqrtss(auVar66,auVar96);
                    fStack_b3c = auVar75._0_4_;
                    fStack_b3c = (fVar131 - auVar96._0_4_ * fStack_b3c * fStack_b3c) * fVar80 *
                                 fStack_b3c;
                    if (fStack_b3c <= 0.0) {
                      fStack_b3c = 0.0;
                    }
                    local_b48 = fStack_b3c * local_d28;
                    fStack_b44 = fStack_b3c * fStack_d24;
                    fStack_b40 = fStack_b3c * fStack_d20;
                    fStack_b3c = fStack_b3c * fStack_d1c;
                    local_d08 = local_b48 * fStack_cfc;
                    fStack_d04 = fStack_b44 * fStack_cfc;
                    fStack_d00 = fStack_b40 * fStack_cfc;
                    fStack_cfc = fStack_b3c * fStack_cfc;
                    *pfVar47 = local_d08;
                    pfVar47[1] = fStack_d04;
                    pfVar47[2] = fStack_d00;
                    fVar111 = SQRT(pfVar47[8] * pfVar47[8] + pfVar47[9] * pfVar47[9] +
                                   pfVar47[10] * pfVar47[10]);
                    local_b28._0_4_ = pfVar47[6] * pfVar47[1] - pfVar47[5] * pfVar47[2];
                    local_b28._4_4_ = pfVar47[4] * pfVar47[2] - pfVar47[6] * *pfVar47;
                    local_b28._8_4_ = pfVar47[5] * *pfVar47 - pfVar47[4] * pfVar47[1];
                    local_b28._12_4_ = pfVar47[7] * pfVar47[3] - pfVar47[7] * pfVar47[3];
                    fVar82 = local_b28._4_4_ * local_b28._4_4_;
                    auVar97._4_4_ = fVar82;
                    auVar97._0_4_ = local_b28._0_4_ * local_b28._0_4_;
                    fVar110 = local_b28._8_4_ * local_b28._8_4_;
                    auVar97._8_4_ = fVar110;
                    auVar97._12_4_ = local_b28._12_4_ * local_b28._12_4_;
                    auVar98._4_12_ = auVar97._4_12_;
                    auVar98._0_4_ = local_b28._0_4_ * local_b28._0_4_ + fVar82 + fVar110;
                    auVar67._4_4_ = fVar82;
                    auVar67._0_4_ = auVar98._0_4_;
                    auVar67._8_4_ = fVar110;
                    auVar67._12_4_ = local_b28._12_4_ * local_b28._12_4_;
                    auVar75 = rsqrtss(auVar67,auVar98);
                    fStack_cdc = auVar75._0_4_;
                    auVar85._0_4_ = auVar98._0_4_ * fStack_cdc * fStack_cdc;
                    auVar85._4_12_ = auVar98._4_12_;
                    fStack_cdc = (fVar131 - auVar85._0_4_) * fVar80 * fStack_cdc;
                    if (fStack_cdc <= 0.0) {
                      fStack_cdc = 0.0;
                    }
                    local_ce8 = fStack_cdc * local_b28._0_4_;
                    fStack_ce4 = fStack_cdc * local_b28._4_4_;
                    fStack_ce0 = fStack_cdc * local_b28._8_4_;
                    fStack_cdc = fStack_cdc * local_b28._12_4_;
                    auVar133._0_4_ = local_ce8 * fVar111;
                    auVar133._4_4_ = fStack_ce4 * fVar111;
                    auVar133._8_4_ = fStack_ce0 * fVar111;
                    local_b08._12_4_ = fStack_cdc * fVar111;
                    local_b08._0_12_ = auVar133;
                    goto LAB_1403031ef;
                  }
                  if ((uVar16 & 8) != 0) {
                    local_cc8 = _DAT_140c77860;
                    fStack_cc4 = fRam0000000140c77864;
                    fStack_cc0 = fRam0000000140c77868;
                    fStack_cbc = fRam0000000140c7786c;
                    fStack_abc = SQRT(pfVar47[4] * pfVar47[4] + pfVar47[5] * pfVar47[5] +
                                      pfVar47[6] * pfVar47[6]);
                    local_ae8 = fRam0000000140c77868 * pfVar47[9] -
                                fRam0000000140c77864 * pfVar47[10];
                    fStack_ae4 = _DAT_140c77860 * pfVar47[10] - fRam0000000140c77868 * pfVar47[8];
                    fStack_ae0 = fRam0000000140c77864 * pfVar47[8] - _DAT_140c77860 * pfVar47[9];
                    fStack_adc = fRam0000000140c7786c * pfVar47[0xb] -
                                 fRam0000000140c7786c * pfVar47[0xb];
                    fVar82 = fStack_ae4 * fStack_ae4;
                    auVar99._4_4_ = fVar82;
                    auVar99._0_4_ = local_ae8 * local_ae8;
                    fVar110 = fStack_ae0 * fStack_ae0;
                    auVar99._8_4_ = fVar110;
                    auVar99._12_4_ = fStack_adc * fStack_adc;
                    auVar100._4_12_ = auVar99._4_12_;
                    auVar100._0_4_ = local_ae8 * local_ae8 + fVar82 + fVar110;
                    auVar68._4_4_ = fVar82;
                    auVar68._0_4_ = auVar100._0_4_;
                    auVar68._8_4_ = fVar110;
                    auVar68._12_4_ = fStack_adc * fStack_adc;
                    auVar75 = rsqrtss(auVar68,auVar100);
                    fStack_c9c = auVar75._0_4_;
                    fStack_c9c = (fVar131 - auVar100._0_4_ * fStack_c9c * fStack_c9c) * fVar80 *
                                 fStack_c9c;
                    if (fStack_c9c <= 0.0) {
                      fStack_c9c = 0.0;
                    }
                    local_ca8 = fStack_c9c * local_ae8;
                    fStack_ca4 = fStack_c9c * fStack_ae4;
                    fStack_ca0 = fStack_c9c * fStack_ae0;
                    fStack_c9c = fStack_c9c * fStack_adc;
                    local_ac8 = local_ca8 * fStack_abc;
                    fStack_ac4 = fStack_ca4 * fStack_abc;
                    fStack_ac0 = fStack_ca0 * fStack_abc;
                    fStack_abc = fStack_c9c * fStack_abc;
                    pfVar47[4] = local_ac8;
                    pfVar47[5] = fStack_ac4;
                    pfVar47[6] = fStack_ac0;
                    fVar111 = SQRT(*pfVar47 * *pfVar47 + pfVar47[1] * pfVar47[1] +
                                   pfVar47[2] * pfVar47[2]);
                    local_1048._0_4_ = pfVar47[10] * pfVar47[5] - pfVar47[9] * pfVar47[6];
                    local_1048._4_4_ = pfVar47[8] * pfVar47[6] - pfVar47[10] * pfVar47[4];
                    local_1048._8_4_ = pfVar47[9] * pfVar47[4] - pfVar47[8] * pfVar47[5];
                    local_1048._12_4_ = pfVar47[0xb] * pfVar47[7] - pfVar47[0xb] * pfVar47[7];
                    fVar82 = local_1048._4_4_ * local_1048._4_4_;
                    auVar101._4_4_ = fVar82;
                    auVar101._0_4_ = local_1048._0_4_ * local_1048._0_4_;
                    fVar110 = local_1048._8_4_ * local_1048._8_4_;
                    auVar101._8_4_ = fVar110;
                    auVar101._12_4_ = local_1048._12_4_ * local_1048._12_4_;
                    auVar102._4_12_ = auVar101._4_12_;
                    auVar102._0_4_ = local_1048._0_4_ * local_1048._0_4_ + fVar82 + fVar110;
                    auVar69._4_4_ = fVar82;
                    auVar69._0_4_ = auVar102._0_4_;
                    auVar69._8_4_ = fVar110;
                    auVar69._12_4_ = local_1048._12_4_ * local_1048._12_4_;
                    auVar75 = rsqrtss(auVar69,auVar102);
                    fStack_102c = auVar75._0_4_;
                    auVar85._0_4_ = auVar102._0_4_ * fStack_102c * fStack_102c;
                    auVar85._4_12_ = auVar102._4_12_;
                    fStack_102c = (fVar131 - auVar85._0_4_) * fVar80 * fStack_102c;
                    if (fStack_102c <= 0.0) {
                      fStack_102c = 0.0;
                    }
                    local_1038 = fStack_102c * local_1048._0_4_;
                    fStack_1034 = fStack_102c * local_1048._4_4_;
                    fStack_1030 = fStack_102c * local_1048._8_4_;
                    fStack_102c = fStack_102c * local_1048._12_4_;
                    local_1018._0_4_ = local_1038 * fVar111;
                    local_1018._4_4_ = fStack_1034 * fVar111;
                    local_1018._8_4_ = fStack_1030 * fVar111;
                    local_1018._12_4_ = fStack_102c * fVar111;
                    *pfVar47 = local_1018._0_4_;
                    pfVar47[1] = local_1018._4_4_;
                    pfVar47[2] = local_1018._8_4_;
                    *(undefined4 *)(puVar29 + 3) = 0;
                    goto LAB_1403036ac;
                  }
                  if ((uVar16 & 0x4000) != 0) {
                    fVar82 = *(float *)(local_1338 + 0x20);
                    fVar110 = *(float *)(local_1338 + 0x24);
                    fVar111 = *(float *)(local_1338 + 0x28);
                    fVar112 = *(float *)(local_1338 + 0x2c);
                    fVar79 = fVar110 * fVar110;
                    auVar103._4_4_ = fVar79;
                    auVar103._0_4_ = fVar82 * fVar82;
                    auVar103._8_4_ = fVar111 * fVar111;
                    auVar103._12_4_ = fVar112 * fVar112;
                    auVar70._4_4_ = fVar79;
                    auVar70._0_4_ = fVar79;
                    auVar70._8_4_ = fVar79;
                    auVar70._12_4_ = fVar79;
                    auVar104._4_12_ = auVar103._4_12_;
                    auVar104._0_4_ = fVar82 * fVar82 + fVar79 + fVar111 * fVar111;
                    auVar75 = rsqrtss(auVar70,auVar104);
                    fVar79 = auVar75._0_4_;
                    local_fd8 = _DAT_140c77870;
                    fStack_fd4 = fRam0000000140c77874;
                    fStack_fd0 = fRam0000000140c77878;
                    fStack_fcc = fRam0000000140c7787c;
                    fVar79 = (fVar131 - auVar104._0_4_ * fVar79 * fVar79) * fVar80 * fVar79;
                    if (fVar79 <= 0.0) {
                      fVar79 = 0.0;
                    }
                    local_ff8._0_4_ = fVar79 * fVar82;
                    local_ff8._4_4_ = fVar79 * fVar110;
                    local_ff8._8_4_ = fVar79 * fVar111;
                    local_ff8._12_4_ = fVar79 * fVar112;
                    local_fb8 = local_ff8._8_4_ * fRam0000000140c77874 -
                                local_ff8._4_4_ * fRam0000000140c77878;
                    fStack_fb4 = local_ff8._0_4_ * fRam0000000140c77878 -
                                 local_ff8._8_4_ * _DAT_140c77870;
                    fStack_fb0 = local_ff8._4_4_ * _DAT_140c77870 -
                                 local_ff8._0_4_ * fRam0000000140c77874;
                    fStack_fac = local_ff8._12_4_ * fRam0000000140c7787c -
                                 local_ff8._12_4_ * fRam0000000140c7787c;
                    fVar82 = fStack_fb4 * fStack_fb4;
                    auVar105._4_4_ = fVar82;
                    auVar105._0_4_ = local_fb8 * local_fb8;
                    auVar105._8_4_ = fStack_fb0 * fStack_fb0;
                    auVar105._12_4_ = fStack_fac * fStack_fac;
                    auVar71._4_4_ = fVar82;
                    auVar71._0_4_ = fVar82;
                    auVar71._8_4_ = fVar82;
                    auVar71._12_4_ = fVar82;
                    auVar106._4_12_ = auVar105._4_12_;
                    auVar106._0_4_ = local_fb8 * local_fb8 + fVar82 + fStack_fb0 * fStack_fb0;
                    auVar75 = rsqrtss(auVar71,auVar106);
                    fVar82 = auVar75._0_4_;
                    fVar82 = (fVar131 - auVar106._0_4_ * fVar82 * fVar82) * fVar80 * fVar82;
                    if (fVar82 <= 0.0) {
                      fVar82 = 0.0;
                    }
                    local_f98._0_4_ = fVar82 * local_fb8;
                    local_f98._4_4_ = fVar82 * fStack_fb4;
                    local_f98._8_4_ = fVar82 * fStack_fb0;
                    local_f98._12_4_ = fVar82 * fStack_fac;
                    local_f78 = local_f98._8_4_ * local_ff8._4_4_ -
                                local_f98._4_4_ * local_ff8._8_4_;
                    fStack_f74 = local_f98._0_4_ * local_ff8._8_4_ -
                                 local_f98._8_4_ * local_ff8._0_4_;
                    fStack_f70 = local_f98._4_4_ * local_ff8._0_4_ -
                                 local_f98._0_4_ * local_ff8._4_4_;
                    fStack_f6c = local_f98._12_4_ * local_ff8._12_4_ -
                                 local_f98._12_4_ * local_ff8._12_4_;
                    fStack_f4c = SQRT(*pfVar47 * *pfVar47 + pfVar47[1] * pfVar47[1] +
                                      pfVar47[2] * pfVar47[2]);
                    local_f58 = fStack_f4c * local_f98._0_4_;
                    fStack_f54 = fStack_f4c * local_f98._4_4_;
                    fStack_f50 = fStack_f4c * local_f98._8_4_;
                    fStack_f4c = fStack_f4c * local_f98._12_4_;
                    *pfVar47 = local_f58;
                    pfVar47[1] = fStack_f54;
                    pfVar47[2] = fStack_f50;
                    fVar80 = SQRT(pfVar47[4] * pfVar47[4] + pfVar47[5] * pfVar47[5] +
                                  pfVar47[6] * pfVar47[6]);
                    local_f38._0_4_ = local_f78 * fVar80;
                    local_f38._4_4_ = fStack_f74 * fVar80;
                    local_f38._8_4_ = fStack_f70 * fVar80;
                    local_f38._12_4_ = fStack_f6c * fVar80;
                    pfVar47[4] = local_f38._0_4_;
                    pfVar47[5] = local_f38._4_4_;
                    pfVar47[6] = local_f38._8_4_;
                    fVar80 = SQRT(pfVar47[8] * pfVar47[8] + pfVar47[9] * pfVar47[9] +
                                  pfVar47[10] * pfVar47[10]);
                    auVar88._0_4_ = fVar80 * local_ff8._0_4_;
                    auVar88._4_4_ = fVar80 * local_ff8._4_4_;
                    auVar88._8_4_ = fVar80 * local_ff8._8_4_;
                    auVar88._12_4_ = fVar80 * local_ff8._12_4_;
                    local_f18 = auVar88;
                    goto LAB_1403035bc;
                  }
                }
                *(undefined4 *)(puVar29 + 3) = 0;
              }
LAB_1403036ac:
              if ((*(ushort *)((longlong)auVar51 + 2 + lVar57) & 0x2100) != 0) {
                local_1320 = (longlong *)(param_1[2] + 0x130);
                local_1328 = pfVar47;
                local_7c8 = pfVar47;
                local_7c0 = local_1320;
                FUN_1401afb10(&local_7c8,&local_1228);
                pfVar32 = (float *)((longlong)auVar51 + 0x150 + lVar57);
                fVar80 = *pfVar32;
                fVar82 = pfVar32[1];
                fVar110 = pfVar32[2];
                auVar135._8_4_ = fStack_1220;
                auVar135._0_8_ = local_1228;
                auVar135._12_4_ = fStack_121c;
                auVar85._0_4_ =
                     fVar82 * local_1218 + fVar80 * (float)local_1228 + fVar110 * local_1208 +
                     local_11f8;
                auVar85._4_4_ =
                     fVar82 * fStack_1214 + fVar80 * (float)((ulonglong)local_1228 >> 0x20) +
                     fVar110 * fStack_1204 + fStack_11f4;
                auVar85._8_4_ =
                     fVar82 * fStack_1210 + fVar80 * fStack_1220 + fVar110 * fStack_1200 +
                     fStack_11f0;
                auVar85._12_4_ =
                     fVar82 * fStack_120c + fVar80 * fStack_121c + fVar110 * fStack_11fc +
                     fStack_11ec;
                local_10f8 = auVar85;
                if (*(longlong *)(param_1[2] + 0x1e8) == 0) {
                  local_ed8._4_4_ = fRam0000000140c77874;
                  local_ed8._0_4_ = _DAT_140c77870;
                  local_ed8._8_4_ = fRam0000000140c77878;
                  local_ed8._12_4_ = fRam0000000140c7787c;
                  local_208 = 0.0;
                  local_228[0] = local_ed8;
                }
                else {
                  bVar59 = (*(ushort *)((longlong)auVar51 + 2 + lVar57) & 0x100) != 0;
                  if ((*(ushort *)((longlong)auVar51 + 2 + lVar57) & 0x2000) != 0) {
                    bVar59 = bVar59 | 2;
                  }
                  local_ef8 = _DAT_140c77870;
                  fStack_ef4 = fRam0000000140c77874;
                  fStack_ef0 = fRam0000000140c77878;
                  fStack_eec = fRam0000000140c7787c;
                  local_13b8 = (undefined ***)0x0;
                  local_10c8 = _DAT_140c77870 + auVar85._0_4_;
                  fStack_10c4 = fRam0000000140c77874 + auVar85._4_4_;
                  fStack_10c0 = fRam0000000140c77878 + auVar85._8_4_;
                  fStack_10bc = fRam0000000140c7787c + auVar85._12_4_;
                  iVar27 = (**(code **)(**(longlong **)(param_1[2] + 0x1e8) + 0x1b8))
                                     (*(longlong **)(param_1[2] + 0x1e8),&local_10c8,local_228,
                                      bVar59);
                  if (iVar27 == 0) goto LAB_140303a25;
                  auVar135._8_4_ = fStack_1220;
                  auVar135._0_8_ = local_1228;
                  auVar135._12_4_ = fStack_121c;
                }
                if ((*(ushort *)((longlong)auVar51 + 2 + lVar57) & 0x100) != 0) {
                  fStack_11f4 = fStack_11f4 + (local_208 - (float)local_10f8._4_4_);
                }
                if ((*(ushort *)((longlong)auVar51 + 2 + lVar57) & 0x2000) != 0) {
                  fVar79 = auVar135._0_4_;
                  fVar130 = auVar135._4_4_;
                  fVar132 = auVar135._8_4_;
                  fVar82 = local_228[0]._0_4_;
                  fVar110 = local_228[0]._4_4_;
                  fVar111 = local_228[0]._8_4_;
                  fVar112 = local_228[0]._12_4_;
                  local_e98 = fVar111 * fVar130 - fVar110 * fVar132;
                  fStack_e94 = fVar82 * fVar132 - fVar111 * fVar79;
                  fStack_e90 = fVar110 * fVar79 - fVar82 * fVar130;
                  fStack_e8c = fVar112 * auVar135._12_4_ - fVar112 * auVar135._12_4_;
                  fVar80 = fStack_e94 * fStack_e94;
                  auVar123._4_4_ = fVar80;
                  auVar123._0_4_ = local_e98 * local_e98;
                  auVar123._8_4_ = fStack_e90 * fStack_e90;
                  auVar123._12_4_ = fStack_e8c * fStack_e8c;
                  auVar77._4_4_ = fVar80;
                  auVar77._0_4_ = fVar80;
                  auVar77._8_4_ = fVar80;
                  auVar77._12_4_ = fVar80;
                  auVar124._4_12_ = auVar123._4_12_;
                  auVar124._0_4_ = local_e98 * local_e98 + fVar80 + fStack_e90 * fStack_e90;
                  auVar75 = rsqrtss(auVar77,auVar124);
                  fStack_e6c = auVar75._0_4_;
                  fStack_e6c = (fVar131 - auVar124._0_4_ * fStack_e6c * fStack_e6c) * DAT_140b79e48
                               * fStack_e6c;
                  if (fStack_e6c <= 0.0) {
                    fStack_e6c = 0.0;
                  }
                  local_e78 = fStack_e6c * local_e98;
                  fStack_e74 = fStack_e6c * fStack_e94;
                  fStack_e70 = fStack_e6c * fStack_e90;
                  fStack_e6c = fStack_e6c * fStack_e8c;
                  local_e58 = fStack_e70 * fVar110 - fStack_e74 * fVar111;
                  fStack_e54 = local_e78 * fVar111 - fStack_e70 * fVar82;
                  fStack_e50 = fStack_e74 * fVar82 - local_e78 * fVar110;
                  fStack_e4c = fStack_e6c * fVar112 - fStack_e6c * fVar112;
                  fVar80 = SQRT(fVar79 * fVar79 + fVar130 * fVar130 + fVar132 * fVar132);
                  local_e38._0_8_ = CONCAT44(fStack_e54 * fVar80,local_e58 * fVar80);
                  local_e38._8_4_ = fStack_e50 * fVar80;
                  local_e38._12_4_ = fStack_e4c * fVar80;
                  auVar85 = local_e38 >> 0x40;
                  fStack_e0c = SQRT(local_1218 * local_1218 + fStack_1214 * fStack_1214 +
                                    fStack_1210 * fStack_1210);
                  local_1218 = fStack_e0c * fVar82;
                  fStack_1214 = fStack_e0c * fVar110;
                  fStack_1210 = fStack_e0c * fVar111;
                  fStack_e0c = fStack_e0c * fVar112;
                  fStack_dec = SQRT(local_1208 * local_1208 + fStack_1204 * fStack_1204 +
                                    fStack_1200 * fStack_1200);
                  local_1208 = fStack_dec * local_e78;
                  fStack_1204 = fStack_dec * fStack_e74;
                  fStack_1200 = fStack_dec * fStack_e70;
                  fStack_dec = fStack_dec * fStack_e6c;
                  local_1228 = local_e38._0_8_;
                  fStack_1220 = local_e38._8_4_;
                  local_eb8 = local_228[0];
                  local_e18 = local_1218;
                  fStack_e14 = fStack_1214;
                  fStack_e10 = fStack_1210;
                  local_df8 = local_1208;
                  fStack_df4 = fStack_1204;
                  fStack_df0 = fStack_1200;
                }
                local_1378 = &local_1228;
                local_1370 = (undefined1 *)(param_1[2] + 0xf0);
                local_5e8 = local_1378;
                local_5e0 = local_1370;
                FUN_1401afb10(&local_5e8,pfVar47);
                goto LAB_140303a21;
              }
            }
            else {
              lVar43 = *(longlong *)(param_1[0x98] + 0x40);
              uVar39 = *(uint *)(lVar43 + 0x1a0);
              if (uVar39 != 0) {
                do {
                  uVar36 = uVar39 + uVar54 >> 1;
                  uVar16 = *(ushort *)(*(longlong *)(lVar43 + 0x1a8) + (ulonglong)uVar36 * 2);
                  uVar50 = (uint)uVar16;
                  uVar35 = *(uint *)((ulonglong)uVar16 * 0x160 + 8 + *(longlong *)(lVar43 + 0x188));
                  if (uVar35 <= uVar49) {
                    if (uVar49 <= uVar35) goto LAB_140301df2;
                    uVar54 = uVar36 + 1;
                    uVar36 = uVar39;
                  }
                  uVar39 = uVar36;
                } while (uVar54 < uVar39);
              }
              uVar50 = 0xffffffff;
LAB_140301df2:
              if (*(uint *)(*(longlong *)(param_1[0x98] + 0x40) + 0x180) <= uVar50) {
                lVar43 = param_1[0x69];
                lVar44 = param_1[0x67];
                plVar45 = param_1 + 0xa6;
                goto LAB_140301e56;
              }
              puVar52 = (undefined8 *)
                        ((ulonglong)uVar50 * 0x40 + *(longlong *)(param_1[0x98] + 0x338));
              uVar19 = puVar52[1];
              *(undefined8 *)pfVar47 = *puVar52;
              *(undefined8 *)(pfVar47 + 2) = uVar19;
              uVar19 = puVar52[3];
              *(undefined8 *)(pfVar47 + 4) = puVar52[2];
              *(undefined8 *)(pfVar47 + 6) = uVar19;
              uVar19 = puVar52[5];
              *(undefined8 *)(pfVar47 + 8) = puVar52[4];
              *(undefined8 *)(pfVar47 + 10) = uVar19;
              *(undefined1 (*) [16])(pfVar47 + 0xc) = *(undefined1 (*) [16])(puVar52 + 6);
LAB_140303a21:
              *(undefined4 *)(puVar29 + 3) = 0;
            }
LAB_140303a25:
            plVar45 = param_1 + 0xa6;
          }
          else if (*piVar37 == 1) {
            uVar54 = piVar37[1];
            if ((((uVar54 != 0) &&
                 (lVar43 = *(longlong *)(*(longlong *)(piVar37 + 2) + 0x40),
                 uVar54 < *(uint *)(lVar43 + 0x270))) &&
                (uVar16 = *(ushort *)(*(longlong *)(lVar43 + 0x278) + (longlong)(int)uVar54 * 2),
                (uint)uVar16 < *(uint *)(lVar43 + 0x260))) &&
               (lVar43 = *(longlong *)(lVar43 + 0x268) + (ulonglong)uVar16 * 4, lVar43 != 0)) {
              puVar29 = (undefined8 *)
                        ((ulonglong)*(ushort *)(lVar43 + 2) * 0x40 +
                        *(longlong *)(*(longlong *)(piVar37 + 2) + 0x338));
              uVar19 = puVar29[1];
              *(undefined8 *)pfVar47 = *puVar29;
              *(undefined8 *)(pfVar47 + 2) = uVar19;
              uVar19 = puVar29[3];
              *(undefined8 *)(pfVar47 + 4) = puVar29[2];
              *(undefined8 *)(pfVar47 + 6) = uVar19;
              uVar19 = puVar29[5];
              *(undefined8 *)(pfVar47 + 8) = puVar29[4];
              *(undefined8 *)(pfVar47 + 10) = uVar19;
              *(undefined1 (*) [16])(pfVar47 + 0xc) = *(undefined1 (*) [16])(puVar29 + 6);
              goto LAB_140301d62;
            }
          }
          else if (*piVar37 == 2) {
            local_1238 = piVar37 + 4;
            uStack_1230 = param_1[2] + 0xf0;
            local_728 = local_1238;
            local_720 = uStack_1230;
            FUN_1401afb10(&local_728,pfVar47);
            *(undefined4 *)(puVar52 + 3) = 0;
          }
          else {
LAB_140301d62:
            *(undefined4 *)(puVar52 + 3) = 0;
          }
          lVar43 = param_1[8];
          local_1394 = *(uint *)(lVar43 + 0x180);
          local_1398 = local_1398 + 1;
          uVar34 = (ulonglong)local_1398;
          uVar54 = local_1390;
        } while (local_1398 < local_1394);
      }
      uVar42 = 0;
      uVar34 = uVar42;
      if (*(int *)(param_1[8] + 0x1b0) != 0) {
        do {
          uVar49 = (int)uVar34 + 1;
          puVar31 = (undefined4 *)
                    ((ulonglong)*(ushort *)(*(longlong *)(param_1[8] + 0x1b8) + uVar34 * 2) * 0x40 +
                    param_1[0x67]);
          pauVar48 = (undefined1 (*) [16])(uVar34 * 0x30 + param_1[0x68]);
          auVar75 = *(undefined1 (*) [16])(puVar31 + 8);
          auVar85 = *(undefined1 (*) [16])(puVar31 + 0xc);
          auVar72._4_4_ = puVar31[4];
          auVar72._0_4_ = *puVar31;
          auVar72._8_4_ = auVar75._0_4_;
          auVar72._12_4_ = auVar85._0_4_;
          auVar107._4_4_ = puVar31[5];
          auVar107._0_4_ = puVar31[1];
          auVar107._8_4_ = auVar75._4_4_;
          auVar107._12_4_ = auVar85._4_4_;
          auVar127._4_4_ = puVar31[6];
          auVar127._0_4_ = puVar31[2];
          auVar127._8_4_ = auVar75._8_4_;
          auVar127._12_4_ = auVar85._8_4_;
          *pauVar48 = auVar72;
          pauVar48[1] = auVar107;
          pauVar48[2] = auVar127;
          uVar34 = (ulonglong)uVar49;
        } while (uVar49 < *(uint *)(param_1[8] + 0x1b0));
      }
      if (param_1[0xe2] != 0) {
        pDVar3 = (DWORD *)(param_1 + 0xde);
        DVar26 = GetCurrentThreadId();
        if (*pDVar3 == DVar26) {
          param_1[0xdf] = param_1[0xdf] + 1;
        }
        else {
          do {
            LOCK();
            bVar60 = param_1[0xdf] == 0;
            if (bVar60) {
              param_1[0xdf] = 1;
            }
            UNLOCK();
            if (bVar60) {
              *pDVar3 = DVar26;
              goto LAB_140303b34;
            }
            uVar42 = uVar42 + 1;
          } while (uVar42 < 0x400);
          FUN_14019fb60(pDVar3);
        }
LAB_140303b34:
        if (param_1[0xe2] != 0) {
          (**(code **)(*(longlong *)param_1[0xe2] + 8))();
          param_1[0xe2] = 0;
        }
        if ((ulonglong)param_1[0xdf] < 2) {
          *pDVar3 = 0;
          LOCK();
          param_1[0xdf] = 0;
          UNLOCK();
          if (param_1[0xe0] != 0) {
            if (param_1[0xe1] == 0) {
              hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
              LOCK();
              bVar60 = param_1[0xe1] == 0;
              if (bVar60) {
                param_1[0xe1] = (longlong)hObject;
              }
              UNLOCK();
              if (!bVar60) {
                CloseHandle(hObject);
              }
            }
            SetEvent((HANDLE)param_1[0xe1]);
          }
        }
        else {
          param_1[0xdf] = param_1[0xdf] + -1;
        }
      }
      *(undefined4 *)(param_1 + 0xaf) = *(undefined4 *)((longlong)param_1 + 0x574);
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 8;
    }
    uVar34 = 0;
    if ((uVar54 & 0x10) != 0) {
      lVar43 = param_1[8];
      local_1398 = 0;
      if (*(int *)(lVar43 + 0x1f0) != 0) {
        do {
          lVar43 = *(longlong *)(lVar43 + 0x1f8);
          puVar52 = (undefined8 *)(uVar34 * 0x60 + param_1[0x8a]);
          uVar54 = 0;
          uVar19 = *puVar52;
          local_1358 = puVar52;
          if (*(int *)(lVar43 + 0x20 + uVar34 * 0x30) != 0) {
            do {
              lVar57 = (ulonglong)uVar54 * 0x128 + *(longlong *)(lVar43 + 0x28 + uVar34 * 0x30);
              lVar44 = (ulonglong)uVar54 * 0xe0 + puVar52[1];
              if (*(int *)(lVar57 + 0x18) != 0) {
                FUN_140306db0(lVar57 + 0x18,lVar44,uVar19);
              }
              if (*(int *)(lVar57 + 0x30) != 0) {
                FUN_140306db0(lVar57 + 0x30,lVar44 + 0x14,uVar19);
              }
              if (*(int *)(lVar57 + 0x48) != 0) {
                FUN_140306db0(lVar57 + 0x48,lVar44 + 0x28,uVar19);
              }
              if (*(int *)(lVar57 + 0x60) != 0) {
                FUN_140306db0(lVar57 + 0x60,lVar44 + 0x3c,uVar19);
              }
              if (*(int *)(lVar57 + 0x78) != 0) {
                FUN_140306db0(lVar57 + 0x78,lVar44 + 0x50,uVar19);
              }
              if (*(int *)(lVar57 + 0xa8) != 0) {
                FUN_140306db0((int *)(lVar57 + 0xa8),lVar44 + 100,uVar19);
              }
              if (*(int *)(lVar57 + 0xc0) != 0) {
                FUN_140306db0((int *)(lVar57 + 0xc0),lVar44 + 0x78,uVar19);
              }
              if (*(int *)(lVar57 + 0xd8) != 0) {
                FUN_140306db0((int *)(lVar57 + 0xd8),lVar44 + 0x8c,uVar19);
              }
              if (*(int *)(lVar57 + 0xf0) != 0) {
                FUN_140306db0((int *)(lVar57 + 0xf0),lVar44 + 0xa0,uVar19);
              }
              if (*(int *)(lVar57 + 0x108) != 0) {
                FUN_140307720((int *)(lVar57 + 0x108),lVar44 + 0xc0,uVar19);
              }
              uVar54 = uVar54 + 1;
              param_1 = local_1380;
            } while (uVar54 < *(uint *)(lVar43 + 0x20 + uVar34 * 0x30));
          }
          lVar43 = param_1[8];
          local_1398 = local_1398 + 1;
          uVar34 = (ulonglong)local_1398;
          uVar54 = local_1390;
        } while (local_1398 < *(uint *)(lVar43 + 0x1f0));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x10;
    }
    fVar80 = DAT_140b79f58;
    uVar34 = 0;
    if ((uVar54 & 0x20) != 0) {
      lVar43 = param_1[8];
      local_1398 = 0;
      if (*(int *)(lVar43 + 0x1e0) != 0) {
        local_1328 = local_808;
        local_1378 = (longlong *)&DAT_140dc0d60;
        local_1320 = (longlong *)&DAT_140dc0d60;
        local_1370 = local_8f8;
        do {
          plVar33 = plRam0000000140c78458;
          lVar44 = uVar34 * 0x98 + *(longlong *)(lVar43 + 0x1e8);
          plVar45 = (longlong *)(uVar34 * 0x110 + param_1[0x6a]);
          lVar43 = *plVar45;
          pfVar47 = (float *)(plVar45 + 10);
          local_1388 = lVar43;
          local_1330 = lVar44;
          if (*(int *)(lVar44 + 0x38) == 0) {
            *(undefined1 **)pfVar47 = _DAT_140c78450;
            plVar45[0xb] = (longlong)plVar33;
          }
          else {
            FUN_140307280(lVar44 + 0x38,pfVar47,lVar43);
          }
          lVar57 = lVar43;
          if ((*(int *)(lVar44 + 0x50) != 0) &&
             (uVar34 = (ulonglong)*(uint *)(lVar43 + 0xb4), lVar57 = local_1388,
             *(uint *)(lVar43 + 0xb4) != 0)) {
            auVar128 = ZEXT816(0);
            fVar131 = 0.0;
            puVar58 = (undefined1 *)((longlong)plVar45 + (uVar34 + 0x1c) * 4);
            pfVar32 = (float *)(local_1388 + 0x78 + uVar34 * 8);
            do {
              pfVar55 = pfVar32 + -3;
              pfVar32 = pfVar32 + -2;
              puVar58 = puVar58 + -4;
              uVar54 = (int)uVar34 - 1;
              uVar34 = (ulonglong)uVar54;
              local_13b8 = (undefined ***)puVar58;
              FUN_1403073a0(lVar44 + 0x50,*pfVar55,&local_12f8);
              param_1 = local_1380;
              fVar79 = auVar128._4_4_;
              fVar130 = auVar128._8_4_;
              fVar132 = auVar128._12_4_;
              fVar82 = (float)local_12f8;
              fVar110 = local_12f8._4_4_;
              fVar111 = (float)uStack_12f0;
              fVar112 = uStack_12f0._4_4_;
              if (fVar79 * local_12f8._4_4_ + fVar132 * uStack_12f0._4_4_ +
                  auVar128._0_4_ * (float)local_12f8 + fVar130 * (float)uStack_12f0 < 0.0) {
                fVar82 = 0.0 - (float)local_12f8;
                fVar110 = 0.0 - local_12f8._4_4_;
                fVar111 = 0.0 - (float)uStack_12f0;
                fVar112 = 0.0 - uStack_12f0._4_4_;
                local_12f8 = (undefined1 *)CONCAT44(fVar110,fVar82);
                uStack_12f0 = (longlong *)CONCAT44(fVar112,fVar111);
              }
              fVar81 = *pfVar32;
              fVar131 = fVar131 + *pfVar32;
              auVar128._0_4_ = fVar82 * fVar81 + auVar128._0_4_;
              auVar128._4_4_ = fVar110 * fVar81 + fVar79;
              auVar128._8_4_ = fVar111 * fVar81 + fVar130;
              auVar128._12_4_ = fVar112 * fVar81 + fVar132;
            } while (uVar54 != 0);
            lVar57 = local_1388;
            if ((DAT_140b79cc4 < fVar131) &&
               (fVar131 = auVar128._4_4_ * auVar128._4_4_ + auVar128._12_4_ * auVar128._12_4_ +
                          auVar128._0_4_ * auVar128._0_4_ + auVar128._8_4_ * auVar128._8_4_,
               _DAT_140c42008 < fVar131)) {
              auVar73._0_4_ = SQRT(fVar131);
              auVar73._4_4_ = auVar73._0_4_;
              auVar73._8_4_ = auVar73._0_4_;
              auVar73._12_4_ = auVar73._0_4_;
              local_12d8 = divps(auVar128,auVar73);
              local_1268 = _DAT_140c78450;
              plStack_1260 = plRam0000000140c78458;
              pfVar32 = (float *)FUN_1401b1ee0(local_dd8,&local_1268,local_12d8);
              fVar131 = *(float *)((longlong)plVar45 + 0x5c);
              fVar82 = *pfVar47;
              fVar110 = *(float *)((longlong)plVar45 + 0x54);
              fVar111 = *(float *)(plVar45 + 0xb);
              fVar112 = *pfVar32;
              fVar79 = pfVar32[1];
              fVar130 = pfVar32[2];
              fVar132 = pfVar32[3];
              *(longlong *)pfVar47 =
                   CONCAT44((fVar131 * fVar79 - fVar82 * fVar130) + fVar110 * fVar132 +
                            fVar111 * fVar112,
                            (fVar82 * fVar132 + fVar131 * fVar112 + fVar110 * fVar130) -
                            fVar111 * fVar79);
              *(float *)(plVar45 + 0xb) =
                   ((fVar82 * fVar79 + fVar131 * fVar130) - fVar110 * fVar112) + fVar111 * fVar132;
              *(float *)((longlong)plVar45 + 0x5c) =
                   ((fVar131 * fVar132 - fVar82 * fVar112) - fVar110 * fVar79) - fVar111 * fVar130;
              lVar57 = local_1388;
            }
          }
          fVar131 = DAT_140b79ed0;
          local_db8 = *pfVar47;
          fStack_db4 = *(float *)((longlong)plVar45 + 0x54);
          fStack_db0 = *(float *)(plVar45 + 0xb);
          fStack_dac = *(float *)((longlong)plVar45 + 0x5c);
          pfVar32 = (float *)(plVar45 + 0x1a);
          pfVar47 = (float *)(plVar45 + 2);
          fVar110 = local_db8 * fVar80 * fStack_dac;
          fVar82 = fStack_db0 * fVar80;
          fVar111 = fStack_db4 * fVar80;
          *pfVar32 = (DAT_140b79ed0 - fVar111 * fStack_db4) - fVar82 * fStack_db0;
          *(float *)((longlong)plVar45 + 0xd4) = fVar111 * local_db8 + fVar82 * fStack_dac;
          *(float *)(plVar45 + 0x1b) = fVar82 * local_db8 - fVar111 * fStack_dac;
          *(undefined4 *)((longlong)plVar45 + 0xdc) = 0;
          *(float *)(plVar45 + 0x1c) = fVar111 * local_db8 - fVar82 * fStack_dac;
          fVar131 = fVar131 - local_db8 * fVar80 * local_db8;
          *(float *)((longlong)plVar45 + 0xe4) = fVar131 - fVar82 * fStack_db0;
          *(float *)(plVar45 + 0x1d) = fVar82 * fStack_db4 + fVar110;
          *(undefined4 *)((longlong)plVar45 + 0xec) = 0;
          *(float *)(plVar45 + 0x1e) = fVar82 * local_db8 + fVar111 * fStack_dac;
          *(float *)((longlong)plVar45 + 0xf4) = fVar82 * fStack_db4 - fVar110;
          *(float *)(plVar45 + 0x1f) = fVar131 - fVar111 * fStack_db4;
          *(undefined8 *)((longlong)plVar45 + 0xfc) = 0;
          *(undefined8 *)((longlong)plVar45 + 0x104) = 0;
          *(undefined4 *)((longlong)plVar45 + 0x10c) = 0x3f800000;
          lVar43 = _DAT_140b7b248;
          local_148 = local_db8;
          fStack_144 = fStack_db4;
          fStack_140 = fStack_db0;
          fStack_13c = fStack_dac;
          if (*(int *)(lVar44 + 8) == 0) {
            *(undefined8 *)pfVar47 = _DAT_140b7b240;
            plVar45[3] = lVar43;
          }
          else {
            FUN_140306eb0((int *)(lVar44 + 8),pfVar47,lVar57);
          }
          lVar43 = _DAT_140b7b248;
          uVar19 = _DAT_140b7b240;
          lVar30 = lVar44;
          if ((*(int *)(lVar44 + 0x20) != 0) &&
             (uVar34 = (ulonglong)*(uint *)(lVar57 + 0xb4), *(uint *)(lVar57 + 0xb4) != 0)) {
            fVar131 = (float)((ulonglong)_DAT_140b7b248 >> 0x20);
            puVar58 = (undefined1 *)((longlong)plVar45 + (uVar34 + 0xc) * 4);
            pfVar55 = (float *)(lVar57 + uVar34 * 8 + 0x78);
            do {
              pfVar1 = pfVar55 + -3;
              pfVar55 = pfVar55 + -2;
              puVar58 = puVar58 + -4;
              local_13b8 = (undefined ***)puVar58;
              FUN_140306fc0(lVar44 + 0x20,*pfVar1,&local_12a8);
              fVar82 = *pfVar55;
              fVar110 = (float)uVar19;
              fVar111 = (float)((ulonglong)uVar19 >> 0x20);
              *pfVar47 = *pfVar47 * (((float)local_12a8 - fVar110) * fVar82 + fVar110);
              *(float *)((longlong)plVar45 + 0x14) =
                   *(float *)((longlong)plVar45 + 0x14) *
                   ((local_12a8._4_4_ - fVar111) * fVar82 + fVar111);
              *(float *)(plVar45 + 3) =
                   *(float *)(plVar45 + 3) *
                   (((float)uStack_12a0 - (float)lVar43) * fVar82 + (float)lVar43);
              *(float *)((longlong)plVar45 + 0x1c) =
                   *(float *)((longlong)plVar45 + 0x1c) *
                   ((uStack_12a0._4_4_ - fVar131) * fVar82 + fVar131);
              uVar54 = (int)uVar34 - 1;
              uVar34 = (ulonglong)uVar54;
              param_1 = local_1380;
              lVar30 = local_1330;
            } while (uVar54 != 0);
          }
          lVar43 = local_1388;
          fVar131 = *pfVar47;
          pfVar47 = (float *)(plVar45 + 0x12);
          *pfVar32 = *pfVar32 * fVar131;
          *(float *)((longlong)plVar45 + 0xd4) = *(float *)((longlong)plVar45 + 0xd4) * fVar131;
          *(float *)(plVar45 + 0x1b) = *(float *)(plVar45 + 0x1b) * fVar131;
          *(float *)((longlong)plVar45 + 0xdc) = *(float *)((longlong)plVar45 + 0xdc) * fVar131;
          fVar131 = *(float *)((longlong)plVar45 + 0x14);
          *(float *)(plVar45 + 0x1c) = *(float *)(plVar45 + 0x1c) * fVar131;
          *(float *)((longlong)plVar45 + 0xe4) = *(float *)((longlong)plVar45 + 0xe4) * fVar131;
          *(float *)(plVar45 + 0x1d) = *(float *)(plVar45 + 0x1d) * fVar131;
          *(float *)((longlong)plVar45 + 0xec) = *(float *)((longlong)plVar45 + 0xec) * fVar131;
          fVar131 = *(float *)(plVar45 + 3);
          auVar78._0_4_ = *(float *)(plVar45 + 0x1e) * fVar131;
          auVar78._4_4_ = *(float *)((longlong)plVar45 + 0xf4) * fVar131;
          auVar78._8_4_ = *(float *)(plVar45 + 0x1f) * fVar131;
          auVar78._12_4_ = *(float *)((longlong)plVar45 + 0xfc) * fVar131;
          *(undefined1 (*) [16])(plVar45 + 0x1e) = auVar78;
          if (*(int *)(lVar30 + 0x68) == 0) {
            pfVar47[0] = 0.0;
            pfVar47[1] = 0.0;
            plVar45[0x13] = 0;
          }
          else {
            FUN_140307720((int *)(lVar30 + 0x68),pfVar47,local_1388);
          }
          if ((*(int *)(lVar30 + 0x80) != 0) &&
             (uVar54 = *(uint *)(lVar43 + 0xb4), uVar34 = (ulonglong)uVar54, uVar54 != 0)) {
            puVar58 = (undefined1 *)((longlong)plVar45 + (uVar34 + 0x2c) * 4);
            pfVar55 = (float *)(lVar43 + uVar34 * 8 + 0x78);
            do {
              pfVar1 = pfVar55 + -3;
              pfVar55 = pfVar55 + -2;
              puVar58 = puVar58 + -4;
              local_13b8 = (undefined ***)puVar58;
              FUN_140307830(lVar30 + 0x80,*pfVar1,&local_1238);
              fVar131 = *pfVar55;
              *pfVar47 = *pfVar47 + (float)local_1238 * fVar131;
              *(float *)((longlong)plVar45 + 0x94) =
                   *(float *)((longlong)plVar45 + 0x94) + local_1238._4_4_ * fVar131;
              *(float *)(plVar45 + 0x13) = *(float *)(plVar45 + 0x13) + (float)uStack_1230 * fVar131
              ;
              *(float *)((longlong)plVar45 + 0x9c) =
                   *(float *)((longlong)plVar45 + 0x9c) + uStack_1230._4_4_ * fVar131;
              uVar54 = (int)uVar34 - 1;
              uVar34 = (ulonglong)uVar54;
              param_1 = local_1380;
            } while (uVar54 != 0);
          }
          *(float *)(plVar45 + 0x20) = *pfVar47;
          *(undefined4 *)((longlong)plVar45 + 0x104) = *(undefined4 *)((longlong)plVar45 + 0x94);
          *(int *)(plVar45 + 0x21) = (int)plVar45[0x13];
          if ((DAT_140dc0d50 & 1) == 0) {
            DAT_140dc0d50 = DAT_140dc0d50 | 1;
            _DAT_140dc0d60 = _DAT_140b7a330;
            uRam0000000140dc0d68 = _UNK_140b7a338;
            _DAT_140dc0d70 = _DAT_140b7a5d0;
            uRam0000000140dc0d78 = _UNK_140b7a5d8;
            _DAT_140dc0d80 = _DAT_140b7a700;
            uRam0000000140dc0d88 = _UNK_140b7a708;
            _DAT_140dc0d90 = _DAT_140b7aee0;
          }
          local_278[0] = pfVar32;
          FUN_1401afc20(local_278,local_8f8);
          local_818 = local_1378;
          local_810 = local_8f8;
          FUN_1401afb10(&local_818,local_808);
          local_458 = local_1328;
          local_450 = local_1320;
          FUN_1401afb10(&local_458,pfVar32);
          lVar43 = param_1[8];
          local_1398 = local_1398 + 1;
          uVar34 = (ulonglong)local_1398;
          uVar46 = DAT_140b7b500;
          fVar131 = DAT_140b79fa0;
          uVar54 = local_1390;
        } while (local_1398 < *(uint *)(lVar43 + 0x1e0));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x20;
    }
    uVar34 = 0;
    if ((uVar54 & 0x40) != 0) {
      lVar43 = param_1[8];
      uVar42 = uVar34;
      if (*(int *)(lVar43 + 0x318) != 0) {
        do {
          lVar44 = uVar42 * 400 + *(longlong *)(lVar43 + 800);
          lVar57 = (ulonglong)*(ushort *)(lVar44 + 2) * 0x160;
          if (*(short *)((ulonglong)*(ushort *)(*(longlong *)(lVar43 + 0x188) + 6 + lVar57) * 0x60 +
                         0x34 + param_1[0x3e]) != 0) {
            lVar43 = uVar42 * 0x1b0 + param_1[0xb7];
            uVar19 = *(undefined8 *)(lVar57 + param_1[0x69]);
            if (*(int *)(lVar44 + 0x10) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x10),lVar43,uVar19);
            }
            if (*(int *)(lVar44 + 0x28) != 0) {
              FUN_140306cb0(lVar44 + 0x28,lVar43 + 0x14,uVar19);
            }
            if (*(int *)(lVar44 + 0x40) != 0) {
              FUN_140306cb0(lVar44 + 0x40,lVar43 + 0x28,uVar19);
            }
            if (*(int *)(lVar44 + 0x58) != 0) {
              FUN_1403068b0(lVar44 + 0x58,lVar43 + 0x40,uVar19);
            }
            if (*(int *)(lVar44 + 0x70) != 0) {
              FUN_1403068b0(lVar44 + 0x70,lVar43 + 0x60,uVar19);
            }
            if (*(int *)(lVar44 + 0x88) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x88),lVar43 + 0x80,uVar19);
            }
            if (*(int *)(lVar44 + 0xa0) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0xa0),lVar43 + 0x94,uVar19);
            }
            if (*(int *)(lVar44 + 0xb8) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0xb8),lVar43 + 0xa8,uVar19);
            }
            if (*(int *)(lVar44 + 0xd0) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0xd0),lVar43 + 0xbc,uVar19);
            }
            if (*(int *)(lVar44 + 0xe8) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0xe8),lVar43 + 0xd0,uVar19);
            }
            if (*(int *)(lVar44 + 0x100) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x100),lVar43 + 0xe4,uVar19);
            }
            if (*(int *)(lVar44 + 0x118) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x118),lVar43 + 0xf8,uVar19);
            }
            if (*(int *)(lVar44 + 0x130) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x130),lVar43 + 0x10c,uVar19);
            }
            if (*(int *)(lVar44 + 0x148) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x148),lVar43 + 0x120,uVar19);
            }
            if (*(int *)(lVar44 + 0x160) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x160),lVar43 + 0x134,uVar19);
            }
            if (*(int *)(lVar44 + 0x178) != 0) {
              FUN_140306cb0((int *)(lVar44 + 0x178),lVar43 + 0x148,uVar19);
            }
          }
          lVar43 = param_1[8];
          uVar49 = (int)uVar42 + 1;
          uVar42 = (ulonglong)uVar49;
          uVar54 = local_1390;
        } while (uVar49 < *(uint *)(lVar43 + 0x318));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x40;
    }
    if ((char)uVar54 < '\0') {
      lVar43 = param_1[8];
      uVar42 = uVar34;
      if (*(int *)(lVar43 + 0x540) != 0) {
        do {
          lVar44 = uVar42 * 0x80 + param_1[0xd0];
          lVar43 = uVar42 * 0x68 + *(longlong *)(lVar43 + 0x548);
          uVar19 = *(undefined8 *)((ulonglong)*(ushort *)(lVar43 + 2) * 0x160 + param_1[0x69]);
          if (*(int *)(lVar43 + 8) != 0) {
            FUN_140306cb0(lVar43 + 8,lVar44,uVar19);
          }
          if (*(int *)(lVar43 + 0x20) != 0) {
            FUN_140307b80(lVar43 + 0x20,lVar44 + 0x20,uVar19);
          }
          if (*(int *)(lVar43 + 0x38) != 0) {
            FUN_140306eb0(lVar43 + 0x38,lVar44 + 0x40,uVar19);
          }
          if (*(int *)(lVar43 + 0x50) != 0) {
            FUN_140307c90(lVar43 + 0x50,lVar44 + 0x60,uVar19);
          }
          lVar43 = param_1[8];
          uVar49 = (int)uVar42 + 1;
          uVar42 = (ulonglong)uVar49;
          uVar54 = local_1390;
        } while (uVar49 < *(uint *)(lVar43 + 0x540));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x80;
    }
    if ((uVar54 & 0x100) != 0) {
      lVar43 = param_1[8];
      if ((*(int *)(lVar43 + 0x588) != 0) &&
         (uVar19 = *(undefined8 *)((ulonglong)*(ushort *)(lVar43 + 0x580) * 0x160 + param_1[0x69]),
         uVar42 = uVar34, *(int *)(lVar43 + 0x588) != 0)) {
        do {
          piVar37 = (int *)(uVar42 * 0x20 + 8 + *(longlong *)(lVar43 + 0x590));
          if (*piVar37 != 0) {
            FUN_140306cb0(piVar37,param_1[0xd1] + uVar42 * 0x14,uVar19);
          }
          lVar43 = param_1[8];
          uVar49 = (int)uVar42 + 1;
          uVar42 = (ulonglong)uVar49;
        } while (uVar49 < *(uint *)(lVar43 + 0x588));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x100;
    }
    if ((uVar54 & 0x200) != 0) {
      plVar33 = param_1 + 0xb9;
      lVar43 = *plVar33;
      while (lVar43 != 0) {
        if (*(undefined8 **)(lVar43 + 0x10) != (undefined8 *)0x0) {
          **(undefined8 **)(lVar43 + 0x10) = *(undefined8 *)(lVar43 + 0x18);
        }
        if (*(longlong *)(lVar43 + 0x18) != 0) {
          *(undefined8 *)(*(longlong *)(lVar43 + 0x18) + 0x10) = *(undefined8 *)(lVar43 + 0x10);
        }
        *(undefined8 *)(lVar43 + 0x10) = 0;
        *(undefined8 *)(lVar43 + 0x18) = 0;
        lVar43 = *plVar33;
      }
      lVar43 = param_1[8];
      if (*(int *)(lVar43 + 0x560) != 0) {
        do {
          lVar44 = uVar34 * 0x88 + param_1[0xb8];
          puVar56 = (ushort *)(uVar34 * 0xa0 + *(longlong *)(lVar43 + 0x568));
          if (*(undefined8 **)(lVar44 + 0x10) != (undefined8 *)0x0) {
            **(undefined8 **)(lVar44 + 0x10) = *(undefined8 *)(lVar44 + 0x18);
          }
          plVar45 = (longlong *)(lVar44 + 0x18);
          if (*(longlong *)(lVar44 + 0x18) != 0) {
            *(undefined8 *)(*(longlong *)(lVar44 + 0x18) + 0x10) = *(undefined8 *)(lVar44 + 0x10);
          }
          *(undefined8 *)(lVar44 + 0x10) = 0;
          *plVar45 = 0;
          if (*(short *)((ulonglong)
                         *(ushort *)
                          (*(longlong *)(param_1[8] + 0x188) + 6 + (ulonglong)*puVar56 * 0x160) *
                         0x60 + 0x34 + param_1[0x3e]) != 0) {
            uVar19 = *(undefined8 *)((ulonglong)*puVar56 * 0x160 + param_1[0x69]);
            if (*(int *)(puVar56 + 0x14) != 0) {
              FUN_140306cb0(puVar56 + 0x14,lVar44 + 0x20,uVar19);
            }
            if (*(float *)(lVar44 + 0x20) != 0.0) {
              *(longlong **)(lVar44 + 8) = param_1;
              if (*(int *)(puVar56 + 0x20) != 0) {
                FUN_140307da0(puVar56 + 0x20,lVar44 + 0x34,uVar19);
              }
              if (*(int *)(puVar56 + 0x2c) != 0) {
                FUN_140307f60(puVar56 + 0x2c,lVar44 + 0x48,uVar19);
              }
              if (*(int *)(puVar56 + 0x38) != 0) {
                FUN_140308160(puVar56 + 0x38,lVar44 + 0x5c,uVar19);
              }
              if (*(int *)(puVar56 + 0x44) != 0) {
                FUN_140308160(puVar56 + 0x44,lVar44 + 0x70,uVar19);
              }
              if (puVar56[6] == 0) {
                lVar43 = param_1[0x99];
LAB_140304914:
                plVar38 = (longlong *)(lVar43 + 0x5c8);
                if (*(longlong *)(lVar44 + 0x10) != 0) goto LAB_140304970;
                *(longlong **)(lVar44 + 0x10) = plVar38;
                *plVar45 = *plVar38;
                *plVar38 = lVar44;
              }
              else {
                if ((puVar56[6] == 1) && (param_1[0x98] != 0)) {
                  lVar43 = param_1[0x98];
                  goto LAB_140304914;
                }
                if (*(longlong *)(lVar44 + 0x10) != 0) goto LAB_140304970;
                *(longlong **)(lVar44 + 0x10) = plVar33;
                *plVar45 = *plVar33;
                *plVar33 = lVar44;
              }
              if (*plVar45 != 0) {
                *(longlong **)(*plVar45 + 0x10) = plVar45;
              }
            }
          }
LAB_140304970:
          lVar43 = param_1[8];
          uVar49 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar49;
          uVar54 = local_1390;
        } while (uVar49 < *(uint *)(lVar43 + 0x560));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x200;
    }
    uVar34 = 0;
    if ((uVar54 >> 10 & 1) != 0) {
      plVar33 = param_1 + 0xbb;
      lVar43 = *plVar33;
      while (lVar43 != 0) {
        if (*(undefined8 **)(lVar43 + 0x20) != (undefined8 *)0x0) {
          **(undefined8 **)(lVar43 + 0x20) = *(undefined8 *)(lVar43 + 0x28);
        }
        if (*(longlong *)(lVar43 + 0x28) != 0) {
          *(undefined8 *)(*(longlong *)(lVar43 + 0x28) + 0x20) = *(undefined8 *)(lVar43 + 0x20);
        }
        *(undefined8 *)(lVar43 + 0x20) = 0;
        *(undefined8 *)(lVar43 + 0x28) = 0;
        lVar43 = *plVar33;
      }
      lVar43 = param_1[8];
      uVar42 = uVar34;
      if (*(int *)(lVar43 + 0x570) != 0) {
        do {
          puVar56 = (ushort *)(uVar42 * 0x20 + *(longlong *)(lVar43 + 0x578));
          lVar43 = uVar42 * 0x30 + param_1[0xba];
          if (*(undefined8 **)(lVar43 + 0x20) != (undefined8 *)0x0) {
            **(undefined8 **)(lVar43 + 0x20) = *(undefined8 *)(lVar43 + 0x28);
          }
          plVar45 = (longlong *)(lVar43 + 0x28);
          if (*(longlong *)(lVar43 + 0x28) != 0) {
            *(undefined8 *)(*(longlong *)(lVar43 + 0x28) + 0x20) = *(undefined8 *)(lVar43 + 0x20);
          }
          *(undefined8 *)(lVar43 + 0x20) = 0;
          *plVar45 = 0;
          if (*(short *)((ulonglong)
                         *(ushort *)
                          (*(longlong *)(param_1[8] + 0x188) + 6 + (ulonglong)*puVar56 * 0x160) *
                         0x60 + 0x34 + param_1[0x3e]) != 0) {
            if (*(int *)(puVar56 + 4) != 0) {
              FUN_1403069d0(puVar56 + 4,lVar43 + 8,
                            *(undefined8 *)(param_1[0x69] + (ulonglong)*puVar56 * 0x160));
            }
            if (*(char *)(lVar43 + 8) != '\0') {
              uVar16 = puVar56[2];
              if (uVar16 == 0) {
                if (*(longlong *)(lVar43 + 0x20) != 0) goto LAB_140304b15;
                *(longlong **)(lVar43 + 0x20) = plVar33;
                *plVar45 = *plVar33;
                *plVar33 = lVar43;
              }
              else {
                if (uVar16 == 1) {
                  plVar38 = plVar33;
                  if (param_1[0x98] != 0) {
                    lVar44 = param_1[0x98];
                    goto LAB_140304ac0;
                  }
                }
                else {
                  if (uVar16 != 2) goto LAB_140304b15;
                  lVar44 = param_1[0x99];
LAB_140304ac0:
                  plVar38 = (longlong *)(lVar44 + 0x5d8);
                }
                if (*(longlong *)(lVar43 + 0x20) != 0) goto LAB_140304b15;
                *(longlong **)(lVar43 + 0x20) = plVar38;
                *plVar45 = *plVar38;
                *plVar38 = lVar43;
              }
              if (*plVar45 != 0) {
                *(longlong **)(*plVar45 + 0x20) = plVar45;
              }
            }
          }
LAB_140304b15:
          lVar43 = param_1[8];
          uVar49 = (int)uVar42 + 1;
          uVar42 = (ulonglong)uVar49;
          uVar54 = local_1390;
        } while (uVar49 < *(uint *)(lVar43 + 0x570));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x400;
    }
    if (((uVar54 >> 0xb & 1) != 0) && ((*(byte *)(param_1 + 6) & 2) != 0)) {
      if ((int)param_1[0x28] != 0) {
        lVar43 = param_1[8];
        local_1398 = 0;
        if (*(int *)(lVar43 + 0x2b8) != 0) {
          do {
            lVar44 = *(longlong *)(lVar43 + 0x2c0);
            lVar57 = param_1[0x8d];
            uVar16 = *(ushort *)(lVar44 + uVar34 * 0x28);
            if ((uint)uVar16 < *(uint *)(lVar43 + 0x180)) {
              local_1378 = (longlong *)((ulonglong)uVar16 * 0x40 + param_1[0x67]);
              local_1338 = *(ulonglong *)((ulonglong)uVar16 * 0x160 + param_1[0x69]);
              local_1370 = (undefined1 *)(param_1[2] + 0x130);
              local_548 = local_1378;
              local_540 = local_1370;
              FUN_1401afb10(&local_548,local_938);
              plVar33 = *(longlong **)(lVar57 + uVar34 * 0x28);
              (**(code **)(*plVar33 + 0x58))(plVar33,local_938);
              uVar42 = local_1338;
              uVar54 = 0;
              if (*(int *)(lVar44 + 8 + uVar34 * 0x28) != 0) {
                do {
                  puVar31 = (undefined4 *)
                            ((ulonglong)uVar54 * 0x20 + *(longlong *)(lVar44 + 0x10 + uVar34 * 0x28)
                            );
                  if (puVar31[2] != 0) {
                    FUN_140306cb0(puVar31 + 2,
                                  *(longlong *)(lVar57 + 0x18 + uVar34 * 0x28) +
                                  (ulonglong)uVar54 * 0x14,uVar42);
                    plVar33 = *(longlong **)(lVar57 + uVar34 * 0x28);
                    (**(code **)(*plVar33 + 0x50))(plVar33,*puVar31);
                  }
                  uVar54 = uVar54 + 1;
                  param_1 = local_1380;
                } while (uVar54 < *(uint *)(lVar44 + 8 + uVar34 * 0x28));
              }
              if (*(int *)(lVar44 + 0x18 + uVar34 * 0x28) != 0) {
                uVar42 = 0;
                do {
                  plVar33 = *(longlong **)(*(longlong *)(lVar57 + 8 + uVar34 * 0x28) + uVar42 * 8);
                  if ((plVar33 != (longlong *)0x0) &&
                     (piVar37 = (int *)(uVar42 * 0x20 + 8 +
                                       *(longlong *)(lVar44 + 0x20 + uVar34 * 0x28)), *piVar37 != 0)
                     ) {
                    lVar43 = *(longlong *)(lVar57 + 0x20 + uVar34 * 0x28);
                    cVar14 = *(char *)(lVar43 + uVar42 * 0x14);
                    pcVar4 = (char *)(lVar43 + uVar42 * 0x14);
                    FUN_1403069d0(piVar37,pcVar4,local_1338);
                    cVar15 = *pcVar4;
                    if (cVar14 != cVar15) {
                      if (cVar15 == '\0') {
                        (**(code **)(*plVar33 + 0x48))(plVar33);
                      }
                      else {
                        (**(code **)(*plVar33 + 0x40))();
                      }
                    }
                  }
                  uVar54 = (int)uVar42 + 1;
                  uVar42 = (ulonglong)uVar54;
                  param_1 = local_1380;
                } while (uVar54 < *(uint *)(lVar44 + 0x18 + uVar34 * 0x28));
              }
            }
            else {
              local_13a8 = *(undefined8 *)(param_1[7] + 0x18);
              local_13b0 = (longlong *)CONCAT44(local_13b0._4_4_,(int)uVar34);
              local_13b8 = (undefined ***)CONCAT44(local_13b8._4_4_,*(uint *)(lVar43 + 0x180));
              FUN_1400035b0(6,0,0);
            }
            lVar43 = param_1[8];
            local_1398 = local_1398 + 1;
            uVar34 = (ulonglong)local_1398;
            uVar54 = local_1390;
          } while (local_1398 < *(uint *)(lVar43 + 0x2b8));
        }
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x800;
    }
    auVar51 = (undefined1  [8])0x0;
    if ((uVar54 >> 0xc & 1) != 0) {
      lVar43 = param_1[8];
      uVar34 = (ulonglong)auVar51;
      if (*(int *)(lVar43 + 0x308) != 0) {
        do {
          lVar44 = param_1[0xb1];
          lVar43 = uVar34 * 0x50 + *(longlong *)(lVar43 + 0x310);
          if (*(int *)(lVar43 + 8) != 0) {
            FUN_140306cb0(lVar43 + 8,lVar44 + (uVar34 * 9 + 1) * 8,
                          *(undefined8 *)(lVar44 + uVar34 * 0x48));
          }
          if (*(int *)(lVar43 + 0x20) != 0) {
            FUN_140306cb0(lVar43 + 0x20,uVar34 * 0x48 + 0x1c + lVar44,
                          *(undefined8 *)(lVar44 + uVar34 * 0x48));
          }
          if (*(int *)(lVar43 + 0x38) != 0) {
            FUN_140306cb0(lVar43 + 0x38,lVar44 + (uVar34 * 9 + 6) * 8,
                          *(undefined8 *)(lVar44 + uVar34 * 0x48));
          }
          lVar43 = param_1[8];
          uVar49 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar49;
          uVar54 = local_1390;
        } while (uVar49 < *(uint *)(lVar43 + 0x308));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x1000;
    }
    if ((uVar54 >> 0xd & 1) != 0) {
      local_1378 = param_1 + 0x9e;
      local_1370 = (undefined1 *)(param_1[2] + 0x130);
      local_408 = local_1378;
      local_400 = local_1370;
      FUN_1401afb10(&local_408,&local_11a8);
      auVar22._12_4_ = fStack_116c;
      auVar22._0_12_ = local_1178;
      fVar80 = local_1178._0_4_;
      fVar82 = fVar80 - *(float *)(param_1 + 0x14);
      fVar111 = local_1178._4_4_;
      fVar110 = fVar111 - *(float *)((longlong)param_1 + 0xa4);
      fVar79 = local_1178._8_4_;
      fVar112 = fVar79 - *(float *)(param_1 + 0x15);
      *(float *)(param_1 + 0x16) = fVar82;
      *(float *)((longlong)param_1 + 0xb4) = fVar110;
      *(float *)(param_1 + 0x17) = fVar112;
      *(float *)((longlong)param_1 + 0xbc) = fStack_116c - *(float *)((longlong)param_1 + 0xac);
      fVar82 = SQRT(fVar82 * fVar82 + fVar110 * fVar110 + fVar112 * fVar112);
      *(float *)(param_1 + 0x18) = fVar82;
      *(undefined1 (*) [16])(param_1 + 0x14) = auVar22;
      *(int *)(param_1 + 0xb6) =
           *(int *)((longlong)param_1 + 0x57c) - *(int *)((longlong)param_1 + 0x5ac);
      *(undefined4 *)((longlong)param_1 + 0x5ac) = *(undefined4 *)(param_1[2] + 0xd0);
      if ((param_1[0xb3] != 0) && (DAT_140b79cc4 < fVar82)) {
        lVar43 = param_1[8];
        fVar82 = *(float *)(lVar43 + 0x390);
        fVar110 = *(float *)(lVar43 + 0x3a0);
        fVar130 = fVar110;
        fVar112 = fVar82;
        if (0.0 < local_11a8) {
          fVar130 = fVar82;
          fVar112 = fVar110;
        }
        fVar132 = *(float *)(lVar43 + 0x394);
        fVar81 = *(float *)(lVar43 + 0x3a4);
        fVar136 = fVar81;
        fVar113 = fVar132;
        if (0.0 < local_1198) {
          fVar136 = fVar132;
          fVar113 = fVar81;
        }
        fVar125 = *(float *)(lVar43 + 0x398);
        fVar5 = *(float *)(lVar43 + 0x3a8);
        fVar6 = fVar125;
        fVar7 = fVar5;
        if (0.0 < local_1188) {
          fVar6 = fVar5;
          fVar7 = fVar125;
        }
        fVar8 = fVar110;
        fVar9 = fVar82;
        if (0.0 < local_11a4) {
          fVar8 = fVar82;
          fVar9 = fVar110;
        }
        fVar10 = fVar81;
        fVar11 = fVar132;
        if (0.0 < local_1194) {
          fVar10 = fVar132;
          fVar11 = fVar81;
        }
        fVar12 = fVar5;
        fVar13 = fVar125;
        if (0.0 < local_1184) {
          fVar12 = fVar125;
          fVar13 = fVar5;
        }
        fVar82 = fVar82 * local_11a0;
        local_1348._4_4_ = fVar111 + fVar9 * local_11a4 + fVar11 * local_1194 + fVar13 * local_1184;
        local_1348._0_4_ = fVar80 + fVar112 * local_11a8 + fVar113 * local_1198 + fVar6 * local_1188
        ;
        local_1368._4_4_ = fVar111 + fVar8 * local_11a4 + fVar10 * local_1194 + fVar12 * local_1184;
        local_1368._0_4_ = fVar80 + fVar130 * local_11a8 + fVar136 * local_1198 + fVar7 * local_1188
        ;
        fVar80 = fVar110 * local_11a0;
        if (0.0 < local_11a0) {
          fVar80 = fVar82;
          fVar82 = fVar110 * local_11a0;
        }
        fVar132 = fVar132 * local_1190;
        fVar110 = fVar81 * local_1190;
        if (0.0 < local_1190) {
          fVar110 = fVar132;
          fVar132 = fVar81 * local_1190;
        }
        fVar125 = fVar125 * local_1180;
        uStack_1360._0_4_ = fVar5 * local_1180;
        if (0.0 < local_1180) {
          uStack_1360._0_4_ = fVar125;
          fVar125 = fVar5 * local_1180;
        }
        uStack_1360._0_4_ = fVar79 + fVar80 + fVar110 + (float)uStack_1360;
        fStack_1340 = fVar79 + fVar82 + fVar132 + fVar125;
        uStack_133c = 0;
        uStack_1360._4_4_ = 0;
        auVar75 = _local_1368;
        uStack_1360 = (ulonglong)(uint)(float)uStack_1360;
        local_10a8 = _local_1348;
        local_10b8 = local_1368;
        uStack_10b0 = uStack_1360;
        _local_1368 = auVar75;
        (**(code **)(*(longlong *)param_1[0xb3] + 0x18))((longlong *)param_1[0xb3],&local_10b8);
      }
      uVar34 = (ulonglong)auVar51;
      if (*(int *)(param_1[8] + 0x2f8) != 0) {
        do {
          if (*(longlong *)(param_1[0xb2] + uVar34 * 8) != 0) {
            puVar56 = (ushort *)(**(code **)(**(longlong **)(param_1[0xb2] + uVar34 * 8) + 0x20))();
            if ((uint)puVar56[1] < *(uint *)(param_1[8] + 0x200)) {
              uVar16 = *(ushort *)(*(longlong *)(param_1[8] + 0x208) + (ulonglong)puVar56[1] * 4);
              if ((((*(ulonglong *)(param_1[0x99] + 0x418) <= (ulonglong)(uVar16 >> 3)) ||
                   ((*(byte *)((ulonglong)(uVar16 >> 3) + *(longlong *)(param_1[0x99] + 0x410)) &
                    '\x01' << ((byte)uVar16 & 7)) == 0)) ||
                  ((ulonglong)param_1[0x83] <= (ulonglong)(uVar16 >> 3))) ||
                 ((*(byte *)((ulonglong)(uVar16 >> 3) + param_1[0x82]) &
                  '\x01' << ((byte)uVar16 & 7)) == 0)) goto LAB_1403053d5;
            }
            iVar27 = *(int *)(puVar56 + 4);
            if (iVar27 == 0) {
              local_2c8[0] = (ulonglong)*puVar56 * 0x40 + param_1[0x67];
              FUN_1401afc20(local_2c8,local_ab8);
              local_638 = param_1[2] + 0xf0;
              local_630 = local_ab8;
              local_12d8._8_8_ = local_630;
              local_12d8._0_8_ = local_638;
              FUN_1401afb10(&local_638,local_9b8);
              puVar40 = &DAT_140c78390;
            }
            else if (iVar27 == 1) {
              plVar33 = param_1 + 0xa6;
              local_1328 = (float *)(param_1[2] + 0xf0);
              local_1320 = plVar33;
              local_778 = local_1328;
              local_770 = plVar33;
              FUN_1401afb10(&local_778,local_a38);
              local_12f8 = (undefined1 *)((ulonglong)*puVar56 * 0x40 + param_1[0x67]);
              uStack_12f0 = plVar33;
              local_6d8 = local_12f8;
              local_6d0 = plVar33;
              FUN_1401afb10(&local_6d8,local_9f8);
              puVar40 = local_9f8;
            }
            else {
              if (iVar27 != 2) goto LAB_1403053d5;
              local_1378 = (longlong *)((ulonglong)*puVar56 * 0x40 + param_1[0x67]);
              local_1370 = (undefined1 *)(param_1[2] + 0x130);
              local_4a8 = local_1378;
              local_4a0 = local_1370;
              FUN_1401afb10(&local_4a8,local_978);
              puVar40 = local_978;
            }
            plVar33 = *(longlong **)(param_1[0xb2] + uVar34 * 8);
            (**(code **)(*plVar33 + 0x30))(plVar33,puVar40);
          }
LAB_1403053d5:
          uVar49 = (int)uVar34 + 1;
          uVar34 = (ulonglong)uVar49;
          uVar54 = local_1390;
        } while (uVar49 < *(uint *)(param_1[8] + 0x2f8));
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x2000;
    }
    if (((uVar54 & 0x4000) != 0) && ((*(byte *)(param_1 + 6) & 2) != 0)) {
      auVar24._8_8_ = 0;
      auVar24._0_8_ = uStack_1360;
      _local_1368 = auVar24 << 0x40;
      if (param_1[0x6e] != 0) {
        do {
          local_1380 = *(longlong **)(param_1[0x6d] + (longlong)auVar51 * 8);
          lVar43 = local_1380[1];
          if (((lVar43 != 0) && (*(int *)(lVar43 + 0x2c) == 0)) &&
             (DAT_140b79cc4 < (float)(*(uint *)(lVar43 + 8) & uVar46))) {
            lVar44 = param_1[8];
            uVar54 = *(uint *)(lVar43 + 0x4c);
            if (uVar54 < *(uint *)(lVar44 + 0x290)) {
              do {
                plVar33 = local_1380;
                lVar57 = param_1[2];
                uVar49 = (int)(longlong)
                              ((float)((*(int *)(*(longlong *)(lVar44 + 0x298) +
                                                (ulonglong)uVar54 * 4) -
                                       *(int *)(*(longlong *)(lVar43 + 0x20) + 0xc)) -
                                      *(int *)(lVar43 + 0xc)) / *(float *)(lVar43 + 8)) +
                         *(int *)(lVar43 + 0x30);
                local_1338 = (ulonglong)uVar49;
                if ((int)(*(int *)(lVar57 + 0xd0) - uVar49) < 0) break;
                lVar30 = *(longlong *)(lVar44 + 0x288);
                uVar42 = (ulonglong)
                         *(ushort *)(*(longlong *)(lVar44 + 0x2a0) + (ulonglong)uVar54 * 2);
                uVar54 = (uint)*(ushort *)(lVar30 + 2 + uVar42 * 8);
                uVar34 = (ulonglong)uVar54;
                plVar45 = *(longlong **)((ulonglong)uVar54 * 0x160 + param_1[0x69]);
                if ((*(int *)((longlong)plVar45 + 0x6c) ==
                     *(int *)(*plVar45 + 8 + (longlong)*(int *)(lVar43 + 0x10) * 4)) &&
                   ((int)plVar45[0xe] == *(int *)(lVar43 + 0x18))) {
                  sVar17 = *(short *)(lVar30 + uVar42 * 8);
                  if (sVar17 == 0) {
                    local_1320 = (longlong *)(lVar57 + 0x130);
                    local_1328 = (float *)(uVar34 * 0x40 + param_1[0x67]);
                    local_4f8 = local_1328;
                    local_4f0 = local_1320;
                    FUN_1401afb10(&local_4f8,&local_1098);
                    puVar52 = (undefined8 *)FUN_14018b280(0xa0,0);
                    if (puVar52 == (undefined8 *)0x0) {
LAB_140305a10:
                      puVar52 = (undefined8 *)0x0;
                    }
                    else {
                      uVar18 = *(undefined4 *)(lVar30 + 4 + uVar42 * 8);
                      lVar44 = *plVar33;
                      FUN_1403272b0(puVar52,local_1338 & 0xffffffff,param_1,0);
                      *puVar52 = &PTR_FUN_140b644a8;
                      *(int *)(puVar52 + 8) = (int)lVar44;
                      *(undefined4 *)((longlong)puVar52 + 0x44) = uVar18;
                      puVar52[10] = local_1098;
                      puVar52[0xb] = uStack_1090;
                      puVar52[0xc] = local_1088;
                      puVar52[0xd] = uStack_1080;
                      *(undefined1 (*) [16])(puVar52 + 0xe) = local_1078;
                      puVar52[0x10] = local_1068;
                      puVar52[0x11] = uStack_1060;
                      *(undefined4 *)(puVar52 + 0x12) = 0;
                    }
LAB_140305a18:
                    FUN_1403129a0(param_1[2],puVar52);
                  }
                  else if (sVar17 == 1) {
                    if (((int)param_1[0x28] != 0) &&
                       ((uint)*(ushort *)(lVar30 + 4 + uVar42 * 8) < *(uint *)(lVar44 + 0x2b8))) {
                      FUN_14003d8f0(local_12c0,lVar57 + 0x68);
                      uVar28 = (ulonglong)*(ushort *)(lVar30 + 4 + uVar42 * 8);
                      uVar41 = (ulonglong)*(ushort *)(lVar30 + 6 + uVar42 * 8);
                      local_1358 = (undefined8 *)param_1[0x8d];
                      if ((*(uint *)(param_1[0x8c] + uVar41 * 4) & 0x20000) == 0) {
                        local_13a8 = 0;
                        local_13b0 = (longlong *)0x0;
                        local_13b8 = (undefined ***)0x0;
                        (**(code **)(*(longlong *)local_1358[uVar28 * 5] + 0x10))
                                  ((longlong *)local_1358[uVar28 * 5],
                                   *(undefined4 *)(param_1[0x8b] + uVar41 * 4),0,0x300000);
                      }
                      else {
                        local_1318[0] = (longlong *)0x0;
                        plVar33 = (longlong *)FUN_14018b280(0x18,0);
                        if (plVar33 != (longlong *)0x0) {
                          *plVar33 = 0;
                          plVar33[1] = 0;
                          plVar33[2] = 0;
                          if (plVar33[1] == 0) {
                            plVar45 = plVar33 + 2;
                            plVar33[1] = (longlong)local_1318;
                            *plVar45 = (longlong)local_1318[0];
                            local_1318[0] = plVar33;
                            if (*plVar45 != 0) {
                              *(longlong **)(*plVar45 + 8) = plVar45;
                            }
                          }
                        }
                        local_12e8[0] = (longlong *)0x0;
                        local_13a8 = 0;
                        local_13b8 = (undefined ***)&LAB_1402f2150;
                        local_13b0 = plVar33;
                        iVar27 = (**(code **)(*(longlong *)local_1358[uVar28 * 5] + 0x10))
                                           ((longlong *)local_1358[uVar28 * 5],
                                            *(undefined4 *)
                                             (param_1[0x8b] +
                                             (ulonglong)*(ushort *)(lVar30 + 6 + uVar42 * 8) * 4),
                                            local_12e8,0x80300000);
                        plVar45 = local_12e8[0];
                        if (local_1318[0] != (longlong *)0x0) {
                          if (iVar27 < 0) {
                            if (plVar33 != (longlong *)0x0) {
                              FUN_1402f1ef0(plVar33);
                            }
                          }
                          else {
                            if ((longlong *)*plVar33 != local_12e8[0]) {
                              if (local_12e8[0] != (longlong *)0x0) {
                                (**(code **)*local_12e8[0])(local_12e8[0]);
                              }
                              if (*plVar33 != 0) {
                                (**(code **)(*(longlong *)*plVar33 + 8))();
                              }
                              *plVar33 = (longlong)plVar45;
                            }
                            if ((longlong *)plVar33[1] != (longlong *)0x0) {
                              *(longlong *)plVar33[1] = plVar33[2];
                            }
                            plVar45 = plVar33 + 2;
                            if (plVar33[2] != 0) {
                              *(longlong *)(plVar33[2] + 8) = plVar33[1];
                            }
                            plVar33[1] = 0;
                            plVar38 = local_1380 + 3;
                            *plVar45 = 0;
                            if (plVar33[1] == 0) {
                              plVar33[1] = (longlong)plVar38;
                              *plVar45 = *plVar38;
                              *plVar38 = (longlong)plVar33;
                              if (*plVar45 != 0) {
                                *(longlong **)(*plVar45 + 8) = plVar45;
                              }
                            }
                          }
                        }
                        if (local_12e8[0] != (longlong *)0x0) {
                          (**(code **)(*local_12e8[0] + 8))();
                          local_12e8[0] = (longlong *)0x0;
                        }
                        plVar33 = local_1380;
                        if (local_1318[0] != (longlong *)0x0) {
                          FUN_1401a4a00(local_1318);
                          plVar33 = local_1380;
                        }
                      }
                      FUN_14003d880(local_12c0);
                      if (param_1[0x7c] != 0) {
                        lVar44 = param_1[2];
                        pfVar47 = (float *)(uVar34 * 0x40 + 0x30 + param_1[0x67]);
                        fVar80 = *pfVar47;
                        fVar82 = pfVar47[1];
                        fVar110 = pfVar47[2];
                        auVar129._0_4_ =
                             fVar82 * *(float *)(lVar44 + 0x140) +
                             fVar80 * *(float *)(lVar44 + 0x130) +
                             fVar110 * *(float *)(lVar44 + 0x150) + *(float *)(lVar44 + 0x160);
                        auVar129._4_4_ =
                             fVar82 * *(float *)(lVar44 + 0x144) +
                             fVar80 * *(float *)(lVar44 + 0x134) +
                             fVar110 * *(float *)(lVar44 + 0x154) + *(float *)(lVar44 + 0x164);
                        auVar129._8_4_ =
                             fVar82 * *(float *)(lVar44 + 0x148) +
                             fVar80 * *(float *)(lVar44 + 0x138) +
                             fVar110 * *(float *)(lVar44 + 0x158) + *(float *)(lVar44 + 0x168);
                        auVar129._12_4_ =
                             fVar82 * *(float *)(lVar44 + 0x14c) +
                             fVar80 * *(float *)(lVar44 + 0x13c) +
                             fVar110 * *(float *)(lVar44 + 0x15c) + *(float *)(lVar44 + 0x16c);
                        puVar52 = (undefined8 *)FUN_14018b280(0x60);
                        if (puVar52 == (undefined8 *)0x0) goto LAB_140305a10;
                        lVar44 = *plVar33;
                        uVar18 = *(undefined4 *)
                                  (param_1[0x8b] +
                                  (ulonglong)*(ushort *)(lVar30 + 6 + uVar42 * 8) * 4);
                        FUN_1403272b0(puVar52,local_1338 & 0xffffffff,param_1,0);
                        *puVar52 = &PTR_FUN_140b64498;
                        *(int *)(puVar52 + 8) = (int)lVar44;
                        *(undefined4 *)((longlong)puVar52 + 0x44) = uVar18;
                        *(undefined1 (*) [16])(puVar52 + 10) = auVar129;
                        goto LAB_140305a18;
                      }
                    }
                  }
                  else if ((sVar17 == 2) && (*(longlong *)(lVar57 + 0x1e8) != 0)) {
                    local_1370 = (undefined1 *)(lVar57 + 0x130);
                    local_1378 = (longlong *)(uVar34 * 0x40 + param_1[0x67]);
                    local_598 = local_1378;
                    local_590 = local_1370;
                    FUN_1401afb10(&local_598,local_a78);
                    fVar80 = fStack_a54 * fStack_a54;
                    auVar108._4_4_ = fVar80;
                    auVar108._0_4_ = local_a58 * local_a58;
                    auVar108._8_4_ = fStack_a50 * fStack_a50;
                    auVar108._12_4_ = fStack_a4c * fStack_a4c;
                    auVar74._4_4_ = fVar80;
                    auVar74._0_4_ = fVar80;
                    auVar74._8_4_ = fVar80;
                    auVar74._12_4_ = fVar80;
                    auVar109._4_12_ = auVar108._4_12_;
                    auVar109._0_4_ = local_a58 * local_a58 + fVar80 + fStack_a50 * fStack_a50;
                    auVar75 = rsqrtss(auVar74,auVar109);
                    fVar80 = auVar75._0_4_;
                    fVar80 = (fVar131 - auVar109._0_4_ * fVar80 * fVar80) * DAT_140b79e48 * fVar80;
                    if (fVar80 <= 0.0) {
                      fVar80 = 0.0;
                    }
                    fVar82 = fVar80 * fStack_a50;
                    fStack_128c = fVar80 * fStack_a4c;
                    local_1298 = CONCAT44(fVar80 * fStack_a54,fVar80 * local_a58);
                    fStack_1290 = fVar82;
                    uVar54 = FUN_1408fccb0();
                    if (fVar82 < 0.0) {
                      uVar54 = uVar54 ^ DAT_140b7b530;
                    }
                    fVar80 = DAT_140b79ed0 - (float)(local_1298._4_4_ & uVar46);
                    if (DAT_140b79ed0 <= fVar80) {
                      fVar80 = DAT_140b79ed0;
                    }
                    fVar82 = 0.0;
                    if (0.0 <= fVar80) {
                      fVar82 = fVar80;
                    }
                    puVar52 = (undefined8 *)FUN_14018b280(0x70);
                    if (puVar52 != (undefined8 *)0x0) {
                      uVar18 = *(undefined4 *)(lVar30 + 4 + uVar42 * 8);
                      FUN_1403272b0(puVar52,uVar49,param_1,0);
                      *puVar52 = &PTR_FUN_140b644e8;
                      *(undefined4 *)(puVar52 + 8) = uVar18;
                      puVar52[10] = local_a48;
                      puVar52[0xb] = uStack_a40;
                      *(uint *)(puVar52 + 0xc) = uVar54;
                      *(float *)((longlong)puVar52 + 100) = fVar82;
                    }
                    goto LAB_140305a18;
                  }
                }
                FUN_1402f1a60(lVar43,param_1[8]);
                lVar44 = param_1[8];
                uVar54 = *(uint *)(lVar43 + 0x4c);
              } while (uVar54 < *(uint *)(lVar44 + 0x290));
              auVar51 = local_1368;
            }
          }
          auVar51 = (undefined1  [8])((longlong)auVar51 + 1);
          local_1368 = auVar51;
          uVar54 = local_1390;
        } while ((ulonglong)auVar51 < (ulonglong)param_1[0x6e]);
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x4000;
    }
    if ((uVar54 >> 0xf & 1) != 0) {
      FUN_140308350(param_1[8] + 0x5c0,param_1 + 0xd6,param_1[0x66]);
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 0x8000;
    }
    uVar46 = local_12c8;
    if (((uVar54 >> 0x10 & 1) != 0) && ((local_12c8 & ~*(uint *)((longlong)param_1 + 0x584)) != 0))
    {
      for (lVar43 = param_1[0x9a]; lVar43 != 0; lVar43 = *(longlong *)(lVar43 + 0x4e0)) {
        uVar34 = FUN_140305b60(param_1,lVar43,uVar46);
        if ((int)uVar34 < 0) {
          return uVar34;
        }
      }
      *(uint *)((longlong)param_1 + 0x584) =
           *(uint *)((longlong)param_1 + 0x584) | uVar46 & 0xfffffffd;
    }
  }
  return 0;
}


