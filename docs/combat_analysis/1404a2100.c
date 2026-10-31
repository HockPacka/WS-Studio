
uint FUN_1404a2100(longlong *param_1,longlong *param_2,int *param_3)

{
  short *psVar1;
  byte bVar2;
  int iVar3;
  ulonglong *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  wchar_t *pwVar14;
  longlong lVar15;
  uint uVar16;
  char *pcVar17;
  undefined2 *puVar18;
  bool bVar19;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 uVar20;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  double dVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  float fVar24;
  float fVar25;
  float fVar26;
  int local_res8 [2];
  undefined1 local_88 [8];
  longlong local_80;
  undefined1 local_68 [8];
  longlong local_60;
  undefined8 extraout_XMM0_Qb;
  
  uVar9 = 0;
  uVar16 = 0;
  *(int *)(param_1 + 8) = *param_3;
  uVar5 = *param_3 - 1;
  if (0x126 < uVar5) goto LAB_1404a4817;
  pcVar17 = switchD_14018df93::caseD_16.e_magic +
            (&switchD_1404a2154::switchdataD_1404a4848)[(int)uVar5];
  switch(*param_3) {
  case 1:
    lVar12 = *param_2;
    uVar9 = uVar16;
    if (lVar12 != 0) {
      iVar8 = *(int *)(lVar12 + 0x3c);
      if (iVar8 == 0) {
        iVar8 = *(int *)(lVar12 + 0x38);
      }
      uVar9 = FUN_1404a2090(&switchD_14018df93::caseD_16,param_3[1],iVar8,param_3[3]);
    }
    break;
  case 2:
    uVar9 = (**(code **)(*param_1 + 0x30))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 3:
    uVar9 = (**(code **)(*param_1 + 0x40))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 4:
    uVar9 = (**(code **)(*param_1 + 0x58))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 5:
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (*param_2 != 0) {
      plVar10 = *(longlong **)(*param_2 + 0x118);
      if (plVar10 == (longlong *)0x0) {
LAB_1404a272b:
        uVar9 = FUN_1404a2010();
      }
      else {
        uVar20 = (**(code **)(*plVar10 + 0x20))(plVar10,param_3[2]);
        uVar9 = FUN_1404a2010(uVar20,iVar8);
      }
    }
    break;
  case 6:
    uVar9 = (**(code **)(*param_1 + 0x418))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 7:
    uVar9 = (**(code **)(*param_1 + 0x428))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 8:
    uVar9 = (**(code **)(*param_1 + 0x118))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 9:
    uVar9 = (**(code **)(*param_1 + 0x420))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 10:
    uVar9 = (**(code **)(*param_1 + 0x50))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xb:
    local_res8[0] = param_3[2];
    lVar12 = param_1[7];
    lVar11 = param_1[6];
    if (*(int *)((longlong)param_1 + 0x6c) == 0) {
LAB_1404a4745:
      if (param_3[1] == 2) {
        iVar8 = FUN_1404a1ca0(param_1,param_2,local_res8[0]);
        uVar9 = (uint)(iVar8 == 0);
      }
      else {
        uVar9 = FUN_1404a1ca0(param_1,param_2,local_res8[0]);
      }
      *(int *)(param_1 + 6) = (int)lVar11;
      param_1[7] = lVar12;
      if (*(int *)((longlong)param_1 + 0x6c) != 0) {
        uVar5 = 0;
        if ((int)param_1[0xd] != 0) {
          do {
            lVar12 = 0;
            do {
              psVar1 = &DAT_140b685ba + lVar12;
              lVar12 = lVar12 + 1;
            } while (*psVar1 != 0);
            FUN_14001c310(param_1 + 9,&DAT_140b685b8,&DAT_140b685b8 + lVar12 * 2);
            uVar5 = uVar5 + 1;
          } while (uVar5 < *(uint *)(param_1 + 0xd));
        }
        pwVar14 = L"FAIL";
        if (uVar9 != 0) {
          pwVar14 = L"PASS";
        }
        lVar12 = FUN_14018efa0(local_68,L"  - NESTED RESULT: %s\n",pwVar14);
        FUN_14001c310(param_1 + 9,*(undefined8 *)(lVar12 + 8),*(undefined8 *)(lVar12 + 0x10));
        if (local_60 != 0) {
          FUN_14018b900(local_60,0);
        }
        *(int *)(param_1 + 0xd) = (int)param_1[0xd] + -1;
      }
    }
    else {
      lVar15 = param_1[1];
      uVar13 = (**(code **)(lVar15 + 0x18))(local_res8);
      for (puVar4 = *(ulonglong **)
                     (*(longlong *)(lVar15 + 0x10) + (uVar13 % *(ulonglong *)(lVar15 + 8)) * 8);
          puVar4 != (ulonglong *)0x0; puVar4 = (ulonglong *)puVar4[1]) {
        if ((uVar13 == *puVar4) &&
           (iVar8 = (**(code **)(lVar15 + 0x20))(local_res8,puVar4 + 2), iVar8 != 0)) {
          if (puVar4 + 3 != (ulonglong *)0x0) {
            bVar2 = *(byte *)(puVar4[3] + 4);
            uVar9 = 0;
            if ((int)param_1[0xd] != 0) {
              do {
                lVar15 = 0;
                do {
                  psVar1 = &DAT_140b685ba + lVar15;
                  lVar15 = lVar15 + 1;
                } while (*psVar1 != 0);
                FUN_14001c310(param_1 + 9,&DAT_140b685b8,&DAT_140b685b8 + lVar15 * 2);
                uVar9 = uVar9 + 1;
              } while (uVar9 < *(uint *)(param_1 + 0xd));
            }
            puVar18 = &DAT_140b7b704;
            if (param_3[1] == 2) {
              puVar18 = (undefined2 *)&DAT_140b685a0;
            }
            pwVar14 = L"  AND";
            if ((bVar2 & 1) != 0) {
              pwVar14 = L"  OR";
            }
            lVar15 = FUN_14018efa0(local_88,L"- %s Nested Prereq Id (%d)  %s\n",puVar18,
                                   local_res8[0],pwVar14);
            FUN_14001c310(param_1 + 9,*(undefined8 *)(lVar15 + 8),*(undefined8 *)(lVar15 + 0x10));
            if (local_80 != 0) {
              FUN_14018b900(local_80,0);
            }
            *(int *)(param_1 + 0xd) = (int)param_1[0xd] + 1;
            goto LAB_1404a4745;
          }
          break;
        }
      }
    }
    break;
  case 0xc:
    uVar9 = (**(code **)(*param_1 + 0x80))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xd:
    uVar9 = (**(code **)(*param_1 + 0x120))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xe:
    uVar9 = (**(code **)(*param_1 + 0x128))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xf:
    uVar9 = FUN_1404a4ec0(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[3]);
    break;
  case 0x10:
    uVar9 = (**(code **)(*param_1 + 0x278))
                      (param_1,*param_2,param_3[1],param_3[2],(float)param_3[3]);
    break;
  case 0x12:
    uVar9 = (**(code **)(*param_1 + 0x390))(param_1,param_3[1],param_3[3]);
    break;
  case 0x13:
    uVar9 = (**(code **)(*param_1 + 0x3d8))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x14:
    uVar9 = (**(code **)(*param_1 + 0x308))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x16:
    iVar8 = param_3[3];
    uVar20 = 0;
    goto LAB_1404a3a56;
  case 0x17:
    iVar8 = param_3[3];
    uVar20 = 1;
    goto LAB_1404a3a56;
  case 0x18:
    uVar9 = (**(code **)(*param_1 + 0x290))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x19:
    uVar9 = (**(code **)(*param_1 + 0x298))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x1a:
    uVar9 = (**(code **)(*param_1 + 0x2a0))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x1b:
    uVar9 = (**(code **)(*param_1 + 0x2a8))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x1c:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = *(uint *)(*param_2 + 0x2ac);
LAB_1404a22ec:
      uVar9 = uVar5;
      if ((param_3[1] != 1) && (uVar9 = uVar16, param_3[1] == 2)) {
        uVar9 = (uint)(uVar5 == 0);
      }
    }
    break;
  case 0x1d:
    uVar9 = (**(code **)(*param_1 + 0x388))(param_1,param_3[1],param_3[3]);
    break;
  case 0x1e:
    uVar9 = (**(code **)(*param_1 + 0x2f0))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x1f:
    uVar9 = (**(code **)(*param_1 + 0x368))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x21:
    iVar8 = param_3[3];
    uVar20 = 2;
    goto LAB_1404a3a56;
  case 0x22:
    iVar8 = param_3[3];
    uVar20 = 3;
    goto LAB_1404a3a56;
  case 0x23:
    iVar8 = param_3[3];
    uVar20 = 4;
    goto LAB_1404a3a56;
  case 0x24:
    iVar8 = param_3[3];
    uVar20 = 5;
LAB_1404a3a56:
    uVar9 = (**(code **)(*param_1 + 0x408))(param_1,*param_2,param_3[1],param_3[2],uVar20,iVar8);
    break;
  case 0x25:
    iVar8 = param_3[3];
    iVar3 = param_3[1];
    dVar21 = (double)(**(code **)(DAT_140c77890 + 0x30))(&DAT_140c77890);
    uVar9 = FUN_1404a2090(dVar21 * -100.0,iVar3,1 - (int)(dVar21 * -100.0),iVar8);
    break;
  case 0x26:
    uVar9 = (**(code **)(*param_1 + 0x350))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x27:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      bVar19 = *(int *)(*param_2 + 0x80) == 0x14;
LAB_1404a22e9:
      uVar5 = (uint)bVar19;
      goto LAB_1404a22ec;
    }
    break;
  case 0x28:
    uVar9 = FUN_1404a4d90(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[3]);
    break;
  case 0x29:
    uVar9 = (**(code **)(*param_1 + 0x2b0))
                      (param_1,*param_2,param_3[1],param_3[2],(float)param_3[3]);
    break;
  case 0x2a:
    uVar9 = (**(code **)(*param_1 + 0x310))(param_1,*param_2,param_3[1]);
    break;
  case 0x2b:
    uVar9 = (**(code **)(*param_1 + 0x3f8))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x2c:
    uVar9 = (**(code **)(*param_1 + 0x370))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x2e:
    uVar9 = (**(code **)(*param_1 + 0x2b8))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x2f:
    uVar9 = (**(code **)(*param_1 + 0x2f8))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x30:
    uVar9 = (**(code **)(*param_1 + 0x1e8))(param_1,*param_2,param_3[1]);
    break;
  case 0x31:
    uVar9 = (**(code **)(*param_1 + 0x398))(param_1,param_3[1],param_3[3],(int)param_2[6]);
    break;
  case 0x32:
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (*param_2 != 0) {
      if (param_2[1] != 0) {
        uVar5 = FUN_1404699f0(*param_2,*(undefined4 *)(param_2[1] + 8),param_3[3]);
        goto LAB_1404a2af0;
      }
LAB_1404a2acc:
      uVar9 = uVar16;
      if ((iVar8 != 1) && (iVar8 == 2)) {
        uVar9 = 1;
      }
    }
    break;
  case 0x33:
    uVar9 = (**(code **)(*param_1 + 0x138))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x34:
    uVar9 = (**(code **)(*param_1 + 0x478))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x35:
    uVar9 = (**(code **)(*param_1 + 0x480))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x36:
    uVar9 = (**(code **)(*param_1 + 0x488))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x37:
    lVar12 = *param_2;
    goto joined_r0x0001404a24b7;
  case 0x38:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = 0;
      if (param_3[3] < 0x1c) {
        uVar5 = (uint)(*(longlong *)(*param_2 + 0x2d8 + (longlong)param_3[3] * 0x10) != 0);
      }
      goto LAB_1404a22ec;
    }
    break;
  case 0x3b:
    uVar9 = FUN_1404a4f60(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x3c:
    iVar8 = param_3[3];
    iVar3 = param_3[1];
    if (*param_2 == 0) {
      uVar9 = 0;
    }
    else if (param_2[1] == 0) {
      if (iVar3 == 1) goto LAB_1404a2d2f;
      if (iVar3 == 2) goto LAB_1404a3612;
      uVar9 = 0;
    }
    else {
      uVar6 = FUN_14046a110(*param_2,*(undefined4 *)(param_2[1] + 8),param_3[2]);
      uVar9 = FUN_1404a2090(extraout_XMM0_Qa_03,iVar3,uVar6,iVar8);
    }
    break;
  case 0x3d:
    uVar9 = (**(code **)(*param_1 + 0x4a0))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x3e:
    uVar9 = (**(code **)(*param_1 + 0x4a8))(param_1,*param_2,param_3[1],param_2[1],param_3[3]);
    break;
  case 0x3f:
    uVar9 = (**(code **)(*param_1 + 0x78))(param_1,*param_2,param_3[1]);
    break;
  case 0x40:
    lVar12 = *param_2;
joined_r0x0001404a24b7:
    uVar9 = uVar16;
    if (lVar12 != 0) {
      uVar9 = FUN_1404a2010(lVar12,param_3[1]);
    }
    break;
  case 0x41:
    uVar9 = (**(code **)(*param_1 + 0x358))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x42:
    uVar9 = (**(code **)(*param_1 + 0x360))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x43:
    uVar9 = (**(code **)(*param_1 + 0x490))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x44:
    uVar9 = (**(code **)(*param_1 + 0x400))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x45:
    uVar9 = (**(code **)(*param_1 + 0x440))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x46:
    uVar9 = (**(code **)(*param_1 + 0x448))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x47:
    uVar9 = FUN_1404a4e30(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x49:
    iVar8 = param_3[3];
    iVar3 = param_3[1];
    if (*param_2 == 0) {
      uVar9 = 0;
    }
    else {
      uVar20 = FUN_140466520(*param_2,param_3[2]);
      uVar9 = FUN_1404a2090(uVar20,iVar3,(longlong)(float)uVar20,iVar8);
    }
    break;
  case 0x4a:
    uVar9 = (**(code **)(*param_1 + 0x450))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x4c:
    uVar9 = (**(code **)(*param_1 + 0x300))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x4d:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar9 = 0;
      plVar10 = (longlong *)(*param_2 + 0x2d8);
      do {
        if (*plVar10 != 0) goto LAB_1404a257c;
        uVar9 = uVar9 + 1;
        plVar10 = plVar10 + 2;
      } while (uVar9 < 0x1c);
LAB_1404a2575:
      uVar5 = 0;
      goto LAB_1404a22ec;
    }
    break;
  case 0x4e:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      bVar19 = *(int *)(*param_2 + 0x1088) == param_3[3];
      goto LAB_1404a22e9;
    }
    break;
  case 0x4f:
    uVar9 = (**(code **)(*param_1 + 0xd8))(param_1,*param_2,param_3[1]);
    break;
  case 0x50:
    iVar8 = param_3[3];
    iVar3 = param_3[1];
    if ((longlong *)*param_2 == (longlong *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar6 = (**(code **)(*(longlong *)*param_2 + 0x40))();
      uVar9 = FUN_1404a2090(extraout_XMM0_Qa_00,iVar3,uVar6,iVar8);
    }
    break;
  case 0x51:
    uVar9 = (**(code **)(*param_1 + 0x150))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x52:
    uVar9 = (**(code **)(*param_1 + 0x48))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x53:
    uVar9 = (**(code **)(*param_1 + 0xe0))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x54:
    uVar9 = (**(code **)(*param_1 + 0xe8))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x55:
    uVar9 = (**(code **)(*param_1 + 0xf0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x56:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = *(uint *)(*param_2 + 0x1070) & 0x40;
      goto LAB_1404a22ec;
    }
    break;
  case 0x57:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = *(uint *)(*param_2 + 0x1070) & 2;
      goto LAB_1404a22ec;
    }
    break;
  case 0x58:
    uVar9 = (**(code **)(*param_1 + 0x158))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x59:
    uVar9 = (**(code **)(*param_1 + 0x160))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x5a:
    uVar9 = (**(code **)(*param_1 + 0x2c0))(param_1,*param_2,param_3[1]);
    break;
  case 0x5b:
    uVar9 = (**(code **)(*param_1 + 0x4b0))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x5c:
    uVar9 = (**(code **)(*param_1 + 0x168))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x5d:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      lVar12 = *(longlong *)(*param_2 + 0x15c8);
      if (lVar12 == 0) goto LAB_1404a2575;
      do {
        if (*(int *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar12 + 0x38) + 0x138) + 0x70) +
                    0xf8) == param_3[2]) goto LAB_1404a257c;
        lVar12 = *(longlong *)(lVar12 + 0x18);
      } while (lVar12 != 0);
      uVar5 = 0;
      goto LAB_1404a22ec;
    }
    break;
  case 0x5e:
    uVar9 = (**(code **)(*param_1 + 0x410))
                      (param_1,*param_2,param_3[1],param_3[2],param_3[3],param_2[1]);
    break;
  case 0x5f:
    lVar12 = *param_2;
    lVar11 = param_2[1];
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (lVar12 != 0) {
      if (lVar11 == 0) {
LAB_1404a219b:
        uVar9 = uVar16;
        if ((iVar8 != 1) && (iVar8 == 2)) {
          uVar9 = 1;
        }
      }
      else {
        fVar24 = *(float *)(lVar11 + 0x11e0) - *(float *)(lVar12 + 0x11e0);
        fVar25 = *(float *)(lVar11 + 0x11e4) - *(float *)(lVar12 + 0x11e4);
        fVar26 = *(float *)(lVar11 + 0x11e8) - *(float *)(lVar12 + 0x11e8);
        uVar9 = FUN_1404a2090(lVar12,iVar8,
                              (longlong)(fVar24 * fVar24 + fVar25 * fVar25 + fVar26 * fVar26),
                              param_3[3] * param_3[3]);
      }
    }
    break;
  case 0x60:
    uVar9 = (**(code **)(*param_1 + 0x1b0))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x61:
    uVar9 = (**(code **)(*param_1 + 0x1b8))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x62:
    uVar9 = (**(code **)(*param_1 + 0x1c0))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 99:
    uVar9 = (**(code **)(*param_1 + 0x1c8))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 100:
    uVar9 = (**(code **)(*param_1 + 0x1d0))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x65:
    uVar9 = (**(code **)(*param_1 + 0x1d8))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x66:
    uVar9 = FUN_1404a4fe0(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[2]);
    break;
  case 0x67:
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (*param_2 != 0) {
      if (param_2[1] == 0) goto LAB_1404a2acc;
      uVar5 = FUN_14046a190(*param_2,*(undefined4 *)(param_2[1] + 8),param_3[2]);
LAB_1404a2af0:
      uVar9 = uVar5;
      if ((iVar8 != 1) && (uVar9 = uVar16, iVar8 == 2)) {
        uVar9 = (uint)(uVar5 == 0);
      }
    }
    break;
  case 0x68:
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = FUN_14046a210(*param_2,param_3[2]);
      goto LAB_1404a2af0;
    }
    break;
  case 0x69:
    iVar8 = param_3[2];
    iVar3 = param_3[1];
    if (*param_2 == 0) {
LAB_1404a2d2f:
      uVar9 = 0;
    }
    else {
      for (plVar10 = *(longlong **)(*param_2 + 0x15d0); plVar10 != (longlong *)0x0;
          plVar10 = (longlong *)plVar10[6]) {
        iVar7 = (**(code **)(*plVar10 + 0x38))(plVar10);
        if (iVar7 == iVar8) {
          uVar5 = 1;
          goto LAB_1404a2d5a;
        }
      }
      uVar5 = 0;
LAB_1404a2d5a:
      uVar9 = uVar5;
      if ((iVar3 != 1) && (uVar9 = 0, iVar3 == 2)) {
        uVar9 = (uint)(uVar5 == 0);
      }
    }
    break;
  case 0x6a:
    uVar9 = (**(code **)(*param_1 + 0x318))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x6b:
    uVar9 = (**(code **)(*param_1 + 0x4b8))(param_1,*param_2,param_3[1],param_3[2],param_2[1]);
    break;
  case 0x6c:
    uVar9 = (**(code **)(*param_1 + 0x1e0))(param_1,*param_2,param_3[1],param_2[1],param_3[2]);
    break;
  case 0x6d:
    uVar9 = (**(code **)(*param_1 + 0x2c8))(param_1,param_3[1],param_3[2]);
    break;
  case 0x6e:
    uVar9 = (**(code **)(*param_1 + 0x4c0))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x6f:
    uVar9 = (**(code **)(*param_1 + 0x518))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x70:
    uVar9 = (**(code **)(*param_1 + 0x520))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x71:
    uVar9 = (**(code **)(*param_1 + 0x528))
                      (param_1,*param_2,param_3[1],param_3[2],(float)param_3[3]);
    break;
  case 0x72:
    lVar12 = *param_2;
    iVar8 = param_3[3];
    iVar3 = param_3[1];
    if (lVar12 == 0) {
      uVar9 = 0;
    }
    else {
      FUN_140466520(lVar12,param_3[2]);
      uVar20 = FUN_140466520(lVar12,iVar8);
      uVar9 = FUN_1404a2010(uVar20,iVar3);
    }
    break;
  case 0x73:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar9 = FUN_1404a2010(*param_2,param_3[1]);
    }
    break;
  case 0x74:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = (uint)(1 < *(int *)(*param_2 + 0x54));
      goto LAB_1404a22ec;
    }
    break;
  case 0x75:
    uVar9 = (**(code **)(*param_1 + 0x538))(param_1,param_3[1],param_3[2]);
    break;
  case 0x76:
    uVar9 = (**(code **)(*param_1 + 0x540))(param_1,param_3[1],param_3[3],param_3[2]);
    break;
  case 0x77:
    uVar9 = (**(code **)(*param_1 + 0x548))(param_1,*param_2,param_3[1],param_3[2],param_2[1]);
    break;
  case 0x78:
    uVar9 = (**(code **)(*param_1 + 0x550))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x79:
    uVar9 = (**(code **)(*param_1 + 0x558))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x7a:
    uVar9 = (**(code **)(*param_1 + 0x560))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x7b:
    uVar9 = (**(code **)(*param_1 + 0x568))(param_1,param_3[1],param_3[3],param_3[2]);
    break;
  case 0x7c:
    uVar9 = (**(code **)(*param_1 + 0x460))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x7d:
    uVar9 = (**(code **)(*param_1 + 0x458))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x7e:
    uVar9 = (**(code **)(*param_1 + 0x4c8))(param_1,param_3[1],param_3[2]);
    break;
  case 0x7f:
    uVar9 = (**(code **)(*param_1 + 0x4d0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x80:
    uVar9 = (**(code **)(*param_1 + 0x68))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x81:
    iVar8 = param_3[2];
    iVar3 = param_3[1];
    if (*param_2 == 0) {
      uVar9 = 0;
    }
    else {
      for (lVar12 = *(longlong *)(*param_2 + 0x15c8); lVar12 != 0;
          lVar12 = *(longlong *)(lVar12 + 0x18)) {
        lVar11 = *DAT_140c65b70;
        uVar6 = (**(code **)(**(longlong **)(lVar12 + 0x38) + 8))();
        iVar7 = (**(code **)(lVar11 + 0x38))(DAT_140c65b70,uVar6,iVar8);
        if (iVar7 != 0) {
          uVar5 = 1;
          goto LAB_1404a2bb2;
        }
      }
      uVar5 = 0;
LAB_1404a2bb2:
      uVar9 = uVar5;
      if ((iVar3 != 1) && (uVar9 = 0, iVar3 == 2)) {
        uVar9 = (uint)(uVar5 == 0);
      }
    }
    break;
  case 0x82:
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (*param_2 != 0) {
      if (param_2[1] == 0) goto LAB_1404a2acc;
      uVar5 = FUN_140469a70(*param_2,*(undefined4 *)(param_2[1] + 8),param_3[2]);
      goto LAB_1404a2af0;
    }
    break;
  case 0x83:
    lVar12 = *param_2;
    lVar11 = param_2[1];
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (lVar12 != 0) {
      if (lVar11 == 0) goto LAB_1404a219b;
      iVar3 = *(int *)(lVar11 + 0x3c);
      if (iVar3 == 0) {
        iVar3 = *(int *)(lVar11 + 0x38);
      }
      iVar7 = *(int *)(lVar12 + 0x3c);
      if (iVar7 == 0) {
        iVar7 = *(int *)(lVar12 + 0x38);
      }
      uVar9 = FUN_1404a2090(lVar12,iVar8,iVar7,iVar3);
    }
    break;
  case 0x85:
    uVar9 = (**(code **)(*param_1 + 0x5c8))(param_1,param_2[2],param_3[1],param_3[2]);
    break;
  case 0x86:
    uVar9 = (**(code **)(*param_1 + 0x5d0))(param_1,param_2[2],param_3[1],param_3[2]);
    break;
  case 0x87:
    uVar9 = (**(code **)(*param_1 + 0x5d8))(param_1,param_2[2],param_3[1],param_3[2]);
    break;
  case 0x88:
    uVar9 = (**(code **)(*param_1 + 0x5e0))(param_1,param_2[3],param_3[1],param_3[2]);
    break;
  case 0x89:
    uVar9 = (**(code **)(*param_1 + 0x5e8))(param_1,param_2[3],param_3[1],param_3[3]);
    break;
  case 0x8a:
    uVar9 = (**(code **)(*param_1 + 0x5f0))(param_1,param_2[2],param_2[3],param_3[1],param_3[2]);
    break;
  case 0x8b:
    uVar9 = (**(code **)(*param_1 + 0x5f8))(param_1,param_2[2],param_3[1],param_3[3]);
    break;
  case 0x8c:
    uVar9 = (**(code **)(*param_1 + 0x600))(param_1,param_2[3],param_3[1],param_3[2],param_3[3]);
    break;
  case 0x8d:
    uVar9 = (**(code **)(*param_1 + 0x280))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x8e:
    uVar9 = (**(code **)(*param_1 + 0x170))(param_1,(int)param_2[4],param_3[1],param_3[3]);
    break;
  case 0x8f:
    uVar9 = (**(code **)(*param_1 + 0x3a0))(param_1,param_3[1],param_3[3]);
    break;
  case 0x91:
    uVar9 = uVar16;
    if (param_3[1] == 1) {
LAB_1404a3612:
      uVar9 = 1;
    }
    break;
  case 0x92:
    uVar9 = (**(code **)(*param_1 + 0x608))(param_1,param_2[2],param_3[1],param_3[2]);
    break;
  case 0x93:
    uVar9 = (**(code **)(*param_1 + 0x2d0))(param_1,param_3[1],param_3[2]);
    break;
  case 0x94:
    uVar9 = (**(code **)(*param_1 + 0x4e8))(param_1,param_3[1],param_3[3],param_3[2]);
    break;
  case 0x95:
    uVar9 = (**(code **)(*param_1 + 0x88))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x96:
    uVar9 = (**(code **)(*param_1 + 0x4f0))(param_1,param_3[1],pcVar17,param_3[2]);
    break;
  case 0x97:
    uVar9 = (**(code **)(*param_1 + 0x4f8))(param_1,param_3[1],pcVar17,param_3[2]);
    break;
  case 0x98:
    uVar9 = (**(code **)(*param_1 + 0x500))(param_1,param_3[1],pcVar17,param_3[2]);
    break;
  case 0x99:
    uVar9 = (**(code **)(*param_1 + 0x4d8))(param_1,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x9a:
    uVar9 = (**(code **)(*param_1 + 0x4e0))(param_1,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x9b:
    uVar9 = (**(code **)(*param_1 + 0x508))(param_1,*param_2,param_3[1],param_3[3],param_3[2]);
    break;
  case 0x9f:
    uVar9 = (**(code **)(*param_1 + 0x1e0))(param_1,param_2[1],param_3[1],*param_2,param_3[2]);
    break;
  case 0xa0:
    uVar9 = (**(code **)(*param_1 + 0x468))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0xa2:
    uVar9 = (**(code **)(*param_1 + 0x570))(param_1,param_3[1],pcVar17,param_3[2]);
    break;
  case 0xa3:
    uVar9 = (**(code **)(*param_1 + 0x578))(param_1,param_3[1],param_3[3],param_3[2]);
    break;
  case 0xa4:
    uVar9 = (**(code **)(*param_1 + 0x580))(param_1,param_3[1],pcVar17,param_3[2]);
    break;
  case 0xa6:
    uVar9 = (**(code **)(*param_1 + 0x588))(param_1,*param_2,param_3[1],*param_1,param_3[2]);
    break;
  case 0xa7:
    uVar9 = (**(code **)(*param_1 + 0x590))(param_1,param_3[1],param_3[2]);
    break;
  case 0xa8:
    uVar9 = (**(code **)(*param_1 + 0x5a0))(param_1,param_3[1],param_3[3],param_3[2]);
    break;
  case 0xa9:
    uVar9 = (**(code **)(*param_1 + 0x5a8))(param_1,param_3[1],param_3[3],param_3[2]);
    break;
  case 0xaa:
    uVar9 = (**(code **)(*param_1 + 0x90))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xab:
    uVar9 = (**(code **)(*param_1 + 0x510))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0xac:
    lVar12 = *param_2;
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (lVar12 != 0) {
      lVar11 = *(longlong *)(lVar12 + 0xd08);
      if (lVar11 == 0) {
        lVar12 = FUN_14022d500(*(undefined4 *)(lVar12 + 0xd8));
        if (lVar12 == 0) goto LAB_1404a272b;
        uVar9 = FUN_1404a2010();
      }
      else {
        auVar22._0_8_ = FUN_14047a940(lVar12);
        auVar22._8_8_ = extraout_XMM0_Qb;
        auVar23._4_12_ = auVar22._4_12_;
        auVar23._0_4_ = (float)auVar22._0_8_ * *(float *)(lVar11 + 0x8c);
        uVar9 = FUN_1404a2010(auVar23._0_8_,iVar8);
      }
    }
    break;
  case 0xad:
    uVar9 = (**(code **)(*param_1 + 0x610))(param_1,param_2[2],param_3[1],param_3[2]);
    break;
  case 0xae:
    uVar9 = (**(code **)(*param_1 + 0x618))(param_1,param_2[2],param_3[1],param_3[2]);
    break;
  case 0xaf:
    uVar9 = (**(code **)(*param_1 + 0x3e0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xb0:
    uVar9 = (**(code **)(*param_1 + 0x470))(param_1,*param_2,param_3[1],param_3[2],param_2[1]);
    break;
  case 0xb1:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar9 = FUN_1404a2090(&switchD_14018df93::caseD_16,param_3[1],*(undefined4 *)(*param_2 + 0x38)
                            ,param_3[3]);
    }
    break;
  case 0xb2:
    uVar9 = (**(code **)(*param_1 + 0x140))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xb3:
    uVar9 = (**(code **)(*param_1 + 0x378))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xb4:
    uVar9 = (**(code **)(*param_1 + 0x3b0))(param_1,param_3[1],param_3[3]);
    break;
  case 0xb6:
    uVar9 = (**(code **)(*param_1 + 0x620))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0xb7:
    uVar9 = (**(code **)(*param_1 + 0x328))(param_1,*param_2,param_3[1]);
    break;
  case 0xb8:
    uVar9 = (**(code **)(*param_1 + 0x330))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0xb9:
    uVar9 = (**(code **)(*param_1 + 0x338))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xba:
    uVar9 = (**(code **)(*param_1 + 0x628))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0xbb:
    uVar9 = (**(code **)(*param_1 + 0x648))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xbc:
    uVar9 = (**(code **)(*param_1 + 0x340))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xbd:
    uVar9 = (**(code **)(*param_1 + 0x2d8))(param_1,param_3[1],param_3[3]);
    break;
  case 0xbe:
    uVar9 = (**(code **)(*param_1 + 0x658))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xbf:
    lVar12 = *param_2;
    iVar8 = param_3[1];
    uVar9 = uVar16;
    if (lVar12 != 0) {
      lVar11 = FUN_140561c30(DAT_140c65b70,*(undefined4 *)(lVar12 + 0x1600));
      if ((lVar11 == 0) && (*(longlong *)(DAT_140c65898 + 0x78) == lVar12)) {
        lVar12 = FUN_14039df50();
        lVar11 = 0;
        if (lVar12 != 0) {
          lVar11 = FUN_1404695e0(lVar12);
        }
      }
      uVar9 = (uint)(lVar11 != 0);
      if ((iVar8 != 1) && (uVar9 = uVar16, iVar8 == 2)) {
        uVar9 = (uint)((lVar11 != 0) == 0);
      }
    }
    break;
  case 0xc0:
    uVar9 = (**(code **)(*param_1 + 0x630))(param_1,*param_2,param_3[1]);
    break;
  case 0xc1:
    uVar9 = (**(code **)(*param_1 + 0x2e0))(param_1,param_3[1]);
    break;
  case 0xc2:
    uVar9 = (**(code **)(*param_1 + 0xf8))(param_1,*param_2,param_3[1]);
    break;
  case 0xc3:
    uVar9 = (**(code **)(*param_1 + 0x100))(param_1,*param_2,param_3[1]);
    break;
  case 0xc4:
    uVar9 = (**(code **)(*param_1 + 0x38))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xc5:
    uVar9 = (**(code **)(*param_1 + 0x108))(param_1,*param_2,param_3[1]);
    break;
  case 0xc6:
    uVar9 = (**(code **)(*param_1 + 0x110))(param_1,*param_2,param_3[1]);
    break;
  case 199:
    uVar9 = (**(code **)(*param_1 + 0x5b0))(param_1,param_3[1],param_3[2],param_3[3]);
    break;
  case 200:
    uVar9 = (**(code **)(*param_1 + 0x5b8))(param_1,param_3[1],param_3[2],param_3[3]);
    break;
  case 0xc9:
    uVar9 = (**(code **)(*param_1 + 0x430))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0xcb:
    uVar9 = (**(code **)(*param_1 + 0x348))(param_1,*param_2,param_3[1]);
    break;
  case 0xcc:
    uVar9 = (**(code **)(*param_1 + 0x1f0))(param_1,*param_2,param_3[1]);
    break;
  case 0xcd:
    iVar8 = (param_3[3] + 0x1c) * 0x32;
    goto LAB_1404a3197;
  case 0xce:
    iVar8 = (param_3[3] + 0x1c) * 0x32;
    goto LAB_1404a31b5;
  case 0xcf:
    iVar8 = (param_3[3] + 0x1c) * 0x32;
    goto LAB_1404a31d3;
  case 0xd0:
    iVar8 = (param_3[3] + 0x1c) * 0x32;
    goto LAB_1404a31f1;
  case 0xd1:
    iVar8 = (param_3[3] + 0x1c) * 0x32;
    goto LAB_1404a320f;
  case 0xd2:
    uVar9 = (**(code **)(*param_1 + 0x230))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xd3:
    uVar9 = (**(code **)(*param_1 + 0x238))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xd4:
    uVar9 = (**(code **)(*param_1 + 0x240))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xd5:
    uVar9 = (**(code **)(*param_1 + 0x248))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xd6:
    uVar9 = (**(code **)(*param_1 + 0x188))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xd7:
    uVar9 = FUN_1404a4cf0(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[3]);
    break;
  case 0xd8:
    iVar8 = param_3[3];
    iVar3 = param_3[1];
    if ((longlong *)*param_2 == (longlong *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar6 = (**(code **)(*(longlong *)*param_2 + 0x70))();
      uVar9 = FUN_1404a2090(extraout_XMM0_Qa,iVar3,uVar6,iVar8);
    }
    break;
  case 0xd9:
    uVar9 = (**(code **)(*param_1 + 0x1f8))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xda:
    uVar9 = (**(code **)(*param_1 + 0x660))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xdb:
    uVar9 = (**(code **)(*param_1 + 0x668))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xdc:
    uVar9 = (**(code **)(*param_1 + 0x498))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0xdd:
    uVar9 = (**(code **)(*param_1 + 400))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xde:
    uVar9 = (**(code **)(*param_1 + 0x380))(param_1,*param_2,param_3[1]);
    break;
  case 0xdf:
    uVar9 = (**(code **)(*param_1 + 0x438))(param_1,*param_2,param_3[1],param_3[2],param_2[1]);
    break;
  case 0xe0:
    uVar9 = (**(code **)(*param_1 + 0x3b8))
                      (param_1,param_3[1],*(undefined4 *)((longlong)param_2 + 0x2c));
    break;
  case 0xe1:
    uVar9 = (**(code **)(*param_1 + 0x3c0))
                      (param_1,param_3[1],*(undefined4 *)((longlong)param_2 + 0x2c));
    break;
  case 0xe2:
    uVar9 = (**(code **)(*param_1 + 0x670))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xe3:
    uVar9 = (**(code **)(*param_1 + 0x198))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xe4:
    uVar9 = (**(code **)(*param_1 + 1000))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xe5:
    uVar9 = (**(code **)(*param_1 + 0x3f0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xe6:
    iVar8 = (param_3[3] + 0x1c) * 0x32;
    goto LAB_1404a322d;
  case 0xe7:
    uVar9 = (**(code **)(*param_1 + 0x1a0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xe8:
    uVar9 = (**(code **)(*param_1 + 0x288))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xe9:
    uVar9 = (**(code **)(*param_1 + 0x1a8))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xea:
    uVar9 = (**(code **)(*param_1 + 0x650))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0xeb:
    uVar9 = (**(code **)(*param_1 + 0x98))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xec:
    uVar9 = (**(code **)(*param_1 + 0xa0))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xed:
    uVar9 = (**(code **)(*param_1 + 0xa8))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xee:
    uVar9 = (**(code **)(*param_1 + 0xb0))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xef:
    uVar9 = (**(code **)(*param_1 + 0xb8))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xf0:
    uVar9 = (**(code **)(*param_1 + 0x2e8))(param_1,param_3[1],param_3[2]);
    break;
  case 0xf1:
    uVar9 = (**(code **)(*param_1 + 0x638))(param_1,*param_2,param_3[1]);
    break;
  case 0xf2:
    uVar9 = (**(code **)(*param_1 + 0x598))(param_1,param_3[1],param_3[2]);
    break;
  case 0xf3:
    uVar9 = (**(code **)(*param_1 + 0x70))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xf4:
    uVar9 = (**(code **)(*param_1 + 0xc0))(param_1,*param_2,param_3[1]);
    break;
  case 0xf5:
    uVar9 = (**(code **)(*param_1 + 0x698))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0xf6:
    uVar9 = (**(code **)(*param_1 + 0x130))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xf8:
    uVar9 = (**(code **)(*param_1 + 0x5c0))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0xfa:
    uVar9 = (**(code **)(*param_1 + 0x60))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0xfb:
    iVar8 = param_3[3];
LAB_1404a3197:
    uVar9 = (**(code **)(*param_1 + 0x200))(param_1,*param_2,param_3[1],iVar8);
    break;
  case 0xfc:
    iVar8 = param_3[3];
LAB_1404a31b5:
    uVar9 = (**(code **)(*param_1 + 0x208))(param_1,*param_2,param_3[1],iVar8);
    break;
  case 0xfd:
    iVar8 = param_3[3];
LAB_1404a31d3:
    uVar9 = (**(code **)(*param_1 + 0x210))(param_1,*param_2,param_3[1],iVar8);
    break;
  case 0xfe:
    iVar8 = param_3[3];
LAB_1404a31f1:
    uVar9 = (**(code **)(*param_1 + 0x218))(param_1,*param_2,param_3[1],iVar8);
    break;
  case 0xff:
    iVar8 = param_3[3];
LAB_1404a320f:
    uVar9 = (**(code **)(*param_1 + 0x220))(param_1,*param_2,param_3[1],iVar8);
    break;
  case 0x100:
    iVar8 = param_3[3];
LAB_1404a322d:
    uVar9 = (**(code **)(*param_1 + 0x228))(param_1,*param_2,param_3[1],iVar8);
    break;
  case 0x103:
    uVar9 = (**(code **)(*param_1 + 0x530))(param_1,param_3[1],param_3[2]);
    break;
  case 0x104:
    uVar9 = (**(code **)(*param_1 + 0x640))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x105:
    uVar9 = (**(code **)(*param_1 + 0x250))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x106:
    uVar9 = (**(code **)(*param_1 + 600))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x107:
    uVar9 = (**(code **)(*param_1 + 0x260))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x108:
    uVar9 = (**(code **)(*param_1 + 0x268))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x109:
    uVar9 = (**(code **)(*param_1 + 0x270))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x10a:
    uVar9 = (**(code **)(*param_1 + 200))(param_1,*param_2,param_3[1]);
    break;
  case 0x10b:
    uVar9 = (**(code **)(*param_1 + 800))(param_1,*param_2,param_3[1]);
    break;
  case 0x10c:
    uVar9 = (**(code **)(*param_1 + 0x3c8))(param_1,param_3[1],param_3[2]);
    break;
  case 0x10d:
    uVar9 = (**(code **)(*param_1 + 0xd0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x10e:
    uVar9 = (**(code **)(*param_1 + 0x680))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x10f:
    uVar9 = (**(code **)(*param_1 + 0x178))
                      (param_1,*(undefined4 *)((longlong)param_2 + 0x24),param_3[1]);
    break;
  case 0x110:
    uVar9 = (**(code **)(*param_1 + 0x180))(param_1,(int)param_2[5],param_3[1]);
    break;
  case 0x111:
    uVar9 = (**(code **)(*param_1 + 0x678))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x113:
    uVar9 = (**(code **)(*param_1 + 0x6a0))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x114:
    iVar8 = (**(code **)(*param_1 + 0x2a8))(param_1,*param_2,param_3[1],param_3[3]);
    uVar9 = uVar16;
    if ((iVar8 != 0) &&
       (iVar8 = (**(code **)(*param_1 + 0x2a8))(param_1,param_2[1],param_3[1],param_3[3]),
       iVar8 != 0)) {
      uVar9 = 1;
    }
    break;
  case 0x115:
    iVar8 = (**(code **)(*param_1 + 0x2f8))(param_1,*param_2,param_3[1],param_3[3]);
    uVar9 = uVar16;
    if ((iVar8 != 0) &&
       (iVar8 = (**(code **)(*param_1 + 0x2f8))(param_1,param_2[1],param_3[1],param_3[3]),
       iVar8 != 0)) {
      uVar9 = 1;
    }
    break;
  case 0x116:
    iVar8 = (**(code **)(*param_1 + 0x300))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    uVar9 = uVar16;
    if ((iVar8 != 0) &&
       (iVar8 = (**(code **)(*param_1 + 0x300))(param_1,param_2[1],param_3[1],param_3[2],param_3[3])
       , iVar8 != 0)) goto LAB_1404a3612;
    break;
  case 0x117:
    iVar8 = FUN_1404a4ec0(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[3]);
    uVar9 = uVar16;
    if ((iVar8 != 0) &&
       (iVar8 = FUN_1404a4ec0(extraout_XMM0_Qa_01,param_2[1],param_3[1],param_3[3]), iVar8 != 0)) {
      uVar9 = 1;
    }
    break;
  case 0x118:
    iVar8 = FUN_1404a4f60(&switchD_14018df93::caseD_16,*param_2,param_3[1],param_3[2],param_3[3]);
    uVar9 = uVar16;
    if ((iVar8 != 0) &&
       (iVar8 = FUN_1404a4f60(extraout_XMM0_Qa_02,param_2[1],param_3[1],param_3[2],param_3[3]),
       iVar8 != 0)) {
      uVar9 = 1;
    }
    break;
  case 0x119:
    uVar9 = uVar16;
    if (*param_2 != 0) {
      uVar5 = *(uint *)(*param_2 + 0x1070) & 4;
      goto LAB_1404a22ec;
    }
    break;
  case 0x11b:
    uVar9 = (**(code **)(*param_1 + 0x6a8))(param_1,*param_2,param_3[1],param_2[1]);
    break;
  case 0x11d:
    uVar9 = (**(code **)(*param_1 + 0x6b0))(param_1,*param_2,param_3[1],param_3[3],param_2[1]);
    break;
  case 0x11e:
    uVar9 = (**(code **)(*param_1 + 0x688))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x11f:
    uVar9 = (**(code **)(*param_1 + 0x690))(param_1,*param_2,param_3[1],param_3[3]);
    break;
  case 0x120:
    uVar9 = (**(code **)(*param_1 + 0x6b8))(param_1,*param_2,param_3[1],param_3[2]);
    break;
  case 0x121:
    uVar9 = (**(code **)(*param_1 + 0x3d0))(param_1,param_3[1]);
    break;
  case 0x122:
    uVar9 = (**(code **)(*param_1 + 0x3a8))(param_1,param_3[1],param_3[3]);
    break;
  case 0x123:
    uVar9 = (**(code **)(*param_1 + 0x6c0))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x124:
    uVar9 = (**(code **)(*param_1 + 0x6c8))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x125:
    uVar9 = (**(code **)(*param_1 + 0x148))(param_1,*param_2,param_3[1],param_3[2],param_3[3]);
    break;
  case 0x126:
    uVar9 = (**(code **)(*param_1 + 0x6d0))(param_1,*param_2,param_3[1]);
    break;
  case 0x127:
    if (((*param_2 != 0) && (param_3[1] != 1)) && (uVar9 = uVar16, param_3[1] == 2)) {
      uVar9 = 1;
    }
  }
LAB_1404a4817:
  if ((*(int *)((longlong)param_1 + 0x6c) != 0) && (*param_3 != 0xb)) {
    FUN_1404a5080(param_1,*param_3,uVar9);
  }
  return uVar9;
LAB_1404a257c:
  uVar5 = 1;
  goto LAB_1404a22ec;
}

