
undefined8 FUN_140497390(longlong *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  longlong lVar4;
  char *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  longlong lVar11;
  longlong *plVar12;
  uint *puVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined8 *puVar16;
  undefined4 **ppuVar17;
  void *_Dst;
  undefined4 *puVar18;
  char *pcVar19;
  char *pcVar20;
  uint uVar21;
  uint uVar23;
  longlong *plVar24;
  uint uVar25;
  bool bVar26;
  undefined8 local_res10;
  longlong *local_res18;
  undefined8 local_res20;
  undefined4 *local_98;
  undefined4 *local_90 [2];
  undefined1 local_80 [16];
  undefined4 *local_70;
  longlong *local_68;
  undefined4 *local_60;
  longlong *local_58;
  longlong *plVar22;
  
  plVar24 = (longlong *)0x0;
  local_res18 = (longlong *)0x0;
  uVar7 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c63e2c == 0) && (iVar8 = FUN_140226ca0(), -1 < iVar8)) {
      uVar7 = (**(code **)(*DAT_140c63be0 + 0x28))();
    }
  }
  else {
    uVar7 = (*DAT_140c63838)(&PTR_u_PublicEvent_140a6c3f8,DAT_140c63858);
  }
  plVar22 = plVar24;
  if (uVar7 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c63e2c == 0) && (iVar8 = FUN_140226ca0(), -1 < iVar8)) {
          puVar10 = (undefined4 *)(**(code **)(*DAT_140c63be0 + 0x20))(DAT_140c63be0,plVar22);
          goto LAB_14049745c;
        }
      }
      else {
        puVar10 = (undefined4 *)(*DAT_140c63848)(&PTR_u_PublicEvent_140a6c3f8,plVar22,DAT_140c63858)
        ;
LAB_14049745c:
        if (puVar10 != (undefined4 *)0x0) {
          uVar1 = puVar10[1];
          if (puVar10[6] == 0x10) {
            if (DAT_140c63840 == (code *)0x0) {
              if ((DAT_140c64698 == 0) && (iVar8 = FUN_14024aa60(), -1 < iVar8)) {
                lVar11 = (**(code **)(*DAT_140c63c08 + 0x18))(DAT_140c63c08,uVar1);
                goto LAB_14049750d;
              }
            }
            else {
              lVar11 = (*DAT_140c63840)(&PTR_u_World_140a6e180,uVar1,DAT_140c63858);
LAB_14049750d:
              if (((lVar11 != 0) && (*(uint *)(lVar11 + 0x14) < 0xc)) &&
                 ((0x94aU >> (*(uint *)(lVar11 + 0x14) & 0x1f) & 1) != 0)) {
                lVar11 = FUN_14020fd40(puVar10[9]);
                if (lVar11 == 0) goto LAB_140497566;
                bVar26 = (*(byte *)(lVar11 + 0xc) & 0x40) == 0;
                goto LAB_140497531;
              }
            }
          }
          else {
            if (DAT_140c63840 == (code *)0x0) {
              if ((DAT_140c64698 != 0) || (iVar8 = FUN_14024aa60(), iVar8 < 0)) goto LAB_140497566;
              lVar11 = (**(code **)(*DAT_140c63c08 + 0x18))(DAT_140c63c08,uVar1);
            }
            else {
              lVar11 = (*DAT_140c63840)(&PTR_u_World_140a6e180,uVar1,DAT_140c63858);
            }
            if (lVar11 == 0) goto LAB_140497566;
            iVar8 = (**(code **)(*param_1 + 0x10))(param_1,puVar10[1]);
            bVar26 = iVar8 == 0;
LAB_140497531:
            if (bVar26) goto LAB_140497566;
          }
          plVar12 = (longlong *)(**(code **)(*param_1 + 0x18))(param_1);
          (**(code **)(*plVar12 + 8))(plVar12,puVar10);
          local_70 = (undefined4 *)CONCAT44(local_70._4_4_,*puVar10);
          local_68 = plVar12;
          FUN_140055f80(param_1 + 1,&local_60,&local_70);
        }
      }
LAB_140497566:
      uVar23 = (int)plVar22 + 1;
      plVar22 = (longlong *)(ulonglong)uVar23;
    } while (uVar23 < uVar7);
  }
  uVar7 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    uVar23 = uVar7;
    if ((DAT_140c638c4 == 0) && (iVar8 = FUN_1402281e0(), -1 < iVar8)) {
      uVar23 = (**(code **)(*DAT_140c64890 + 0x28))();
    }
  }
  else {
    uVar23 = (*DAT_140c63838)(&PTR_u_PublicEventObjective_140a6c510,DAT_140c63858);
  }
  plVar22 = plVar24;
  if (uVar23 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c638c4 == 0) && (iVar8 = FUN_1402281e0(), -1 < iVar8)) {
          puVar13 = (uint *)(**(code **)(*DAT_140c64890 + 0x20))(DAT_140c64890,plVar22);
          goto LAB_14049761b;
        }
      }
      else {
        puVar13 = (uint *)(*DAT_140c63848)(&PTR_u_PublicEventObjective_140a6c510,plVar22,
                                           DAT_140c63858);
LAB_14049761b:
        if (puVar13 != (uint *)0x0) {
          puVar10 = (undefined4 *)param_1[2];
          puVar18 = puVar10;
          puVar3 = *(undefined4 **)(puVar10 + 2);
          while (puVar3 != (undefined4 *)0x0) {
            if ((uint)puVar3[8] < puVar13[1]) {
              puVar3 = *(undefined4 **)(puVar3 + 6);
            }
            else {
              puVar18 = puVar3;
              puVar3 = *(undefined4 **)(puVar3 + 4);
            }
          }
          if ((puVar18 == puVar10) || (puVar13[1] < (uint)puVar18[8])) {
            local_res20 = puVar10;
            puVar16 = &local_res20;
          }
          else {
            local_res10 = puVar18;
            puVar16 = &local_res10;
          }
          if ((((undefined4 *)*puVar16 != puVar10) &&
              (plVar12 = *(longlong **)((undefined4 *)*puVar16 + 10), plVar12 != (longlong *)0x0))
             && ((iVar8 = (**(code **)(*plVar12 + 0x28))(plVar12), iVar8 != 0x10 ||
                 ((puVar13[0x10] != 0 || (puVar13[10] == 5)))))) {
            if (puVar13[10] == 0x21) {
              uVar25 = puVar13[0xc];
              if (DAT_140c63840 == (code *)0x0) {
                if ((DAT_140c647d0 != 0) || (iVar8 = FUN_140225760(), iVar8 < 0))
                goto LAB_1404978ff;
                lVar11 = (**(code **)(*DAT_140c64208 + 0x18))(DAT_140c64208,uVar25);
              }
              else {
                lVar11 = (*DAT_140c63840)(&PTR_u_Prerequisite_140a6c2e0,uVar25,DAT_140c63858);
              }
              if (lVar11 == 0) goto LAB_1404978ff;
            }
            plVar14 = (longlong *)(**(code **)(*param_1 + 0x20))(param_1);
            (**(code **)(*plVar14 + 8))(plVar14,plVar12,puVar13);
            puVar10 = (undefined4 *)plVar12[3];
            uVar25 = *(uint *)plVar14[1];
            puVar18 = puVar10;
            puVar3 = *(undefined4 **)(puVar10 + 2);
            while (puVar3 != (undefined4 *)0x0) {
              if ((uint)puVar3[8] < uVar25) {
                puVar3 = *(undefined4 **)(puVar3 + 6);
              }
              else {
                puVar18 = puVar3;
                puVar3 = *(undefined4 **)(puVar3 + 4);
              }
            }
            if ((puVar18 == puVar10) || (uVar25 < (uint)puVar18[8])) {
              local_60 = (undefined4 *)CONCAT44(local_60._4_4_,uVar25);
              local_58 = (longlong *)0x0;
              local_98 = puVar18;
              FUN_140055c60(plVar12 + 2,local_90,&local_98,&local_60);
              puVar18 = local_90[0];
            }
            *(longlong **)(puVar18 + 10) = plVar14;
            (**(code **)(*param_1 + 0x28))(param_1,plVar14);
            pcVar2 = (char *)param_1[6];
            uVar25 = *puVar13;
            local_70 = (undefined4 *)CONCAT44(local_70._4_4_,uVar25);
            bVar26 = true;
            pcVar5 = pcVar2;
            pcVar20 = *(char **)(pcVar2 + 8);
            while (pcVar20 != (char *)0x0) {
              bVar26 = uVar25 < *(uint *)(pcVar20 + 0x20);
              pcVar5 = pcVar20;
              if (bVar26) {
                pcVar20 = *(char **)(pcVar20 + 0x10);
              }
              else {
                pcVar20 = *(char **)(pcVar20 + 0x18);
              }
            }
            pcVar20 = pcVar5;
            local_68 = plVar14;
            if (bVar26) {
              if (pcVar5 == *(char **)(pcVar2 + 0x10)) {
                FUN_140055e80(param_1 + 5,local_80,0,pcVar5,&local_70);
                goto LAB_1404978ff;
              }
              if ((*pcVar5 == '\0') && (*(char **)(*(longlong *)(pcVar5 + 8) + 8) == pcVar5)) {
                pcVar20 = *(char **)(pcVar5 + 0x18);
              }
              else {
                pcVar20 = *(char **)(pcVar5 + 0x10);
                if (pcVar20 == (char *)0x0) {
                  pcVar20 = *(char **)(pcVar5 + 8);
                  pcVar19 = pcVar20;
                  if (pcVar5 == *(char **)(pcVar20 + 0x10)) {
                    do {
                      pcVar20 = *(char **)(pcVar19 + 8);
                      bVar26 = pcVar19 == *(char **)(pcVar20 + 0x10);
                      pcVar19 = pcVar20;
                    } while (bVar26);
                  }
                }
                else {
                  for (pcVar19 = *(char **)(pcVar20 + 0x18); pcVar19 != (char *)0x0;
                      pcVar19 = *(char **)(pcVar19 + 0x18)) {
                    pcVar20 = pcVar19;
                  }
                }
              }
            }
            if (*(uint *)(pcVar20 + 0x20) < uVar25) {
              if ((pcVar5 == pcVar2) || (uVar25 < *(uint *)(pcVar5 + 0x20))) {
                lVar11 = FUN_14018b280(0x30);
                if ((undefined8 *)(lVar11 + 0x20) != (undefined8 *)0x0) {
                  *(undefined8 *)(lVar11 + 0x20) = local_70;
                  *(longlong **)(lVar11 + 0x28) = plVar14;
                }
                *(longlong *)(pcVar5 + 0x10) = lVar11;
                pcVar2 = (char *)param_1[6];
                if (pcVar5 == pcVar2) {
                  *(longlong *)(pcVar2 + 8) = lVar11;
                  *(longlong *)(param_1[6] + 0x18) = lVar11;
                }
                else if (pcVar5 == *(char **)(pcVar2 + 0x10)) {
                  *(longlong *)(pcVar2 + 0x10) = lVar11;
                }
              }
              else {
                lVar11 = FUN_14018b280(0x30);
                if ((undefined8 *)(lVar11 + 0x20) != (undefined8 *)0x0) {
                  *(undefined8 *)(lVar11 + 0x20) = local_70;
                  *(longlong **)(lVar11 + 0x28) = plVar14;
                }
                *(longlong *)(pcVar5 + 0x18) = lVar11;
                if (pcVar5 == *(char **)(param_1[6] + 0x18)) {
                  *(longlong *)(param_1[6] + 0x18) = lVar11;
                }
              }
              *(char **)(lVar11 + 8) = pcVar5;
              *(undefined8 *)(lVar11 + 0x10) = 0;
              *(undefined8 *)(lVar11 + 0x18) = 0;
              FUN_1400081c0(lVar11,param_1[6] + 8);
              param_1[7] = param_1[7] + 1;
            }
          }
        }
      }
LAB_1404978ff:
      uVar25 = (int)plVar22 + 1;
      plVar22 = (longlong *)(ulonglong)uVar25;
    } while (uVar25 < uVar23);
  }
  if (DAT_140c63838 == (code *)0x0) {
    uVar23 = uVar7;
    if ((DAT_140c64bd8 == 0) && (iVar8 = FUN_1402292e0(), -1 < iVar8)) {
      uVar23 = (**(code **)(*DAT_140c63888 + 0x28))();
    }
  }
  else {
    uVar23 = (*DAT_140c63838)(&PTR_u_PublicEventTeam_140a6c5f0,DAT_140c63858);
  }
  plVar22 = plVar24;
  if (uVar23 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c64bd8 == 0) && (iVar8 = FUN_1402292e0(), -1 < iVar8)) {
          puVar13 = (uint *)(**(code **)(*DAT_140c63888 + 0x20))(DAT_140c63888,plVar22);
          goto LAB_1404979aa;
        }
      }
      else {
        puVar13 = (uint *)(*DAT_140c63848)(&PTR_u_PublicEventTeam_140a6c5f0,plVar22,DAT_140c63858);
LAB_1404979aa:
        if (puVar13 != (uint *)0x0) {
          pcVar2 = (char *)param_1[10];
          uVar25 = *puVar13;
          bVar26 = true;
          local_70 = (undefined4 *)CONCAT44(local_70._4_4_,uVar25);
          pcVar5 = pcVar2;
          pcVar20 = *(char **)(pcVar2 + 8);
          while (pcVar20 != (char *)0x0) {
            bVar26 = uVar25 < *(uint *)(pcVar20 + 0x20);
            pcVar5 = pcVar20;
            if (bVar26) {
              pcVar20 = *(char **)(pcVar20 + 0x10);
            }
            else {
              pcVar20 = *(char **)(pcVar20 + 0x18);
            }
          }
          pcVar20 = pcVar5;
          if (bVar26) {
            if (pcVar5 != *(char **)(pcVar2 + 0x10)) {
              if ((*pcVar5 == '\0') && (*(char **)(*(longlong *)(pcVar5 + 8) + 8) == pcVar5)) {
                pcVar20 = *(char **)(pcVar5 + 0x18);
              }
              else {
                pcVar20 = *(char **)(pcVar5 + 0x10);
                if (pcVar20 == (char *)0x0) {
                  pcVar20 = *(char **)(pcVar5 + 8);
                  pcVar19 = pcVar20;
                  if (pcVar5 == *(char **)(pcVar20 + 0x10)) {
                    do {
                      pcVar20 = *(char **)(pcVar19 + 8);
                      bVar26 = pcVar19 == *(char **)(pcVar20 + 0x10);
                      pcVar19 = pcVar20;
                    } while (bVar26);
                  }
                }
                else {
                  for (pcVar19 = *(char **)(pcVar20 + 0x18); pcVar19 != (char *)0x0;
                      pcVar19 = *(char **)(pcVar19 + 0x18)) {
                    pcVar20 = pcVar19;
                  }
                }
              }
              goto LAB_140497a4d;
            }
          }
          else {
LAB_140497a4d:
            if (uVar25 <= *(uint *)(pcVar20 + 0x20)) goto LAB_140497afd;
          }
          if ((pcVar5 == pcVar2) || (uVar25 < *(uint *)(pcVar5 + 0x20))) {
            lVar11 = FUN_14018b280(0x30);
            if ((undefined8 *)(lVar11 + 0x20) != (undefined8 *)0x0) {
              *(undefined8 *)(lVar11 + 0x20) = local_70;
              *(uint **)(lVar11 + 0x28) = puVar13;
            }
            *(longlong *)(pcVar5 + 0x10) = lVar11;
            pcVar2 = (char *)param_1[10];
            if (pcVar5 == pcVar2) {
              *(longlong *)(pcVar2 + 8) = lVar11;
              *(longlong *)(param_1[10] + 0x18) = lVar11;
            }
            else if (pcVar5 == *(char **)(pcVar2 + 0x10)) {
              *(longlong *)(pcVar2 + 0x10) = lVar11;
            }
          }
          else {
            lVar11 = FUN_14018b280(0x30);
            if ((undefined8 *)(lVar11 + 0x20) != (undefined8 *)0x0) {
              *(undefined8 *)(lVar11 + 0x20) = local_70;
              *(uint **)(lVar11 + 0x28) = puVar13;
            }
            *(longlong *)(pcVar5 + 0x18) = lVar11;
            if (pcVar5 == *(char **)(param_1[10] + 0x18)) {
              *(longlong *)(param_1[10] + 0x18) = lVar11;
            }
          }
          *(char **)(lVar11 + 8) = pcVar5;
          *(undefined8 *)(lVar11 + 0x10) = 0;
          *(undefined8 *)(lVar11 + 0x18) = 0;
          FUN_1400081c0(lVar11,param_1[10] + 8);
          param_1[0xb] = param_1[0xb] + 1;
        }
      }
LAB_140497afd:
      uVar25 = (int)plVar22 + 1;
      plVar22 = (longlong *)(ulonglong)uVar25;
    } while (uVar25 < uVar23);
  }
  lVar11 = *(longlong *)(param_1[2] + 0x10);
  if (lVar11 != param_1[2]) {
    do {
      (**(code **)(**(longlong **)(lVar11 + 0x28) + 0x30))();
      lVar15 = *(longlong *)(lVar11 + 0x18);
      if (lVar15 == 0) {
        lVar15 = *(longlong *)(lVar11 + 8);
        if (lVar11 == *(longlong *)(lVar15 + 0x18)) {
          do {
            lVar11 = lVar15;
            lVar15 = *(longlong *)(lVar11 + 8);
          } while (lVar11 == *(longlong *)(lVar15 + 0x18));
        }
        if (*(longlong *)(lVar11 + 0x18) != lVar15) {
          lVar11 = lVar15;
        }
      }
      else {
        for (lVar4 = *(longlong *)(lVar15 + 0x10); lVar11 = lVar15, lVar4 != 0;
            lVar4 = *(longlong *)(lVar4 + 0x10)) {
          lVar15 = lVar4;
        }
      }
    } while (lVar11 != param_1[2]);
  }
  uVar23 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    uVar25 = uVar7;
    if ((DAT_140c63a84 == 0) && (iVar8 = FUN_1402270e0(), uVar25 = uVar23, -1 < iVar8)) {
      uVar25 = (**(code **)(*DAT_140c64738 + 0x28))();
    }
  }
  else {
    uVar25 = (*DAT_140c63838)(&PTR_u_PublicEventCustomStat_140a6c430,DAT_140c63858);
  }
  plVar22 = plVar24;
  if (uVar25 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        plVar12 = plVar24;
        if (DAT_140c63a84 == 0) {
          iVar8 = FUN_1402270e0();
          if (iVar8 < 0) {
            plVar12 = (longlong *)0x0;
          }
          else {
            plVar12 = (longlong *)(**(code **)(*DAT_140c64738 + 0x20))(DAT_140c64738,plVar22);
          }
        }
      }
      else {
        plVar12 = (longlong *)
                  (*DAT_140c63848)(&PTR_u_PublicEventCustomStat_140a6c430,plVar22,DAT_140c63858);
      }
      uVar21 = *(uint *)((longlong)plVar12 + 0xc);
      if (uVar21 < 6) {
        if ((int)plVar12[1] == 0) {
          local_res20 = (undefined4 *)CONCAT44(uVar21,*(undefined4 *)((longlong)plVar12 + 4));
          local_70 = local_res20;
          local_68 = plVar12;
          FUN_1403ae510(param_1 + 0xd,local_90,&local_70);
        }
        else {
          local_res10 = (undefined4 *)CONCAT44(uVar21,(int)plVar12[1]);
          local_60 = local_res10;
          local_58 = plVar12;
          FUN_1404990f0(param_1 + 0x11,local_80,&local_60);
        }
      }
      uVar21 = (int)plVar22 + 1;
      plVar22 = (longlong *)(ulonglong)uVar21;
    } while (uVar21 < uVar25);
  }
  if (DAT_140c63838 == (code *)0x0) {
    uVar25 = uVar23;
    if ((DAT_140c64efc == 0) && (iVar8 = FUN_140229720(), -1 < iVar8)) {
      uVar25 = (**(code **)(*DAT_140c64da0 + 0x28))();
    }
  }
  else {
    uVar25 = (*DAT_140c63838)(&PTR_u_PublicEventUnitPropertyModifier_140a6c628,DAT_140c63858);
  }
  plVar22 = plVar24;
  if (uVar25 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c64efc == 0) && (iVar8 = FUN_140229720(), -1 < iVar8)) {
          puVar10 = (undefined4 *)(**(code **)(*DAT_140c64da0 + 0x20))(DAT_140c64da0,plVar22);
          goto LAB_140497d29;
        }
      }
      else {
        puVar10 = (undefined4 *)
                  (*DAT_140c63848)(&PTR_u_PublicEventUnitPropertyModifier_140a6c628,plVar22,
                                   DAT_140c63858);
LAB_140497d29:
        if (puVar10 != (undefined4 *)0x0) {
          switch(puVar10[2]) {
          case 7:
          case 0x23:
          case 0x24:
          case 100:
          case 0x72:
          case 0x81:
          case 0x82:
          case 0x83:
          case 0x89:
          case 0xa2:
          case 0xa6:
          case 0xa7:
          case 0xb5:
          case 0xbf:
            puVar3 = (undefined4 *)param_1[2];
            puVar6 = puVar3;
            puVar18 = *(undefined4 **)(puVar3 + 2);
            while (puVar18 != (undefined4 *)0x0) {
              if ((uint)puVar18[8] < (uint)puVar10[1]) {
                puVar18 = *(undefined4 **)(puVar18 + 6);
              }
              else {
                puVar6 = puVar18;
                puVar18 = *(undefined4 **)(puVar18 + 4);
              }
            }
            if ((puVar6 == puVar3) || ((uint)puVar10[1] < (uint)puVar6[8])) {
              local_res20 = puVar3;
              puVar16 = &local_res20;
            }
            else {
              local_res10 = puVar6;
              puVar16 = &local_res10;
            }
            if (((undefined4 *)*puVar16 != puVar3) &&
               (lVar11 = *(longlong *)((undefined4 *)*puVar16 + 10), lVar11 != 0)) {
              puVar16 = *(undefined8 **)(lVar11 + 0x40);
              local_90[0] = puVar10;
              if (puVar16 == *(undefined8 **)(lVar11 + 0x48)) {
                FUN_1400b9430(lVar11 + 0x30,puVar16,local_90);
              }
              else {
                if (puVar16 != (undefined8 *)0x0) {
                  *puVar16 = puVar10;
                }
                *(longlong *)(lVar11 + 0x40) = *(longlong *)(lVar11 + 0x40) + 8;
              }
            }
            break;
          default:
            local_90[0] = (undefined4 *)0x141e03570;
            FUN_1401a2e50(0x40,0,local_90,puVar10[1],*puVar10,puVar10[2]);
          }
        }
      }
      uVar21 = (int)plVar22 + 1;
      plVar22 = (longlong *)(ulonglong)uVar21;
    } while (uVar21 < uVar25);
  }
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c63d4c == 0) && (iVar8 = FUN_140229b60(), uVar23 = uVar7, -1 < iVar8)) {
      uVar23 = (**(code **)(*DAT_140c649a8 + 0x28))();
    }
  }
  else {
    uVar23 = (*DAT_140c63838)(&PTR_u_PublicEventRewardModifier_140a6c660,DAT_140c63858);
  }
  plVar22 = plVar24;
  if (uVar23 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c63d4c == 0) && (iVar8 = FUN_140229b60(), -1 < iVar8)) {
          puVar10 = (undefined4 *)(**(code **)(*DAT_140c649a8 + 0x20))(DAT_140c649a8,plVar22);
          goto LAB_140497ead;
        }
      }
      else {
        puVar10 = (undefined4 *)
                  (*DAT_140c63848)(&PTR_u_PublicEventRewardModifier_140a6c660,plVar22,DAT_140c63858)
        ;
LAB_140497ead:
        if (puVar10 != (undefined4 *)0x0) {
          puVar3 = (undefined4 *)param_1[2];
          puVar6 = puVar3;
          puVar18 = *(undefined4 **)(puVar3 + 2);
          while (puVar18 != (undefined4 *)0x0) {
            if ((uint)puVar18[8] < (uint)puVar10[1]) {
              puVar18 = *(undefined4 **)(puVar18 + 6);
            }
            else {
              puVar6 = puVar18;
              puVar18 = *(undefined4 **)(puVar18 + 4);
            }
          }
          if ((puVar6 == puVar3) || ((uint)puVar10[1] < (uint)puVar6[8])) {
            local_res20 = puVar3;
            puVar16 = &local_res20;
          }
          else {
            local_res10 = puVar6;
            puVar16 = &local_res10;
          }
          if (((undefined4 *)*puVar16 != puVar3) &&
             (lVar11 = *(longlong *)((undefined4 *)*puVar16 + 10), lVar11 != 0)) {
            puVar16 = *(undefined8 **)(lVar11 + 0x60);
            local_90[0] = puVar10;
            if (puVar16 == *(undefined8 **)(lVar11 + 0x68)) {
              FUN_1400b9430(lVar11 + 0x50,puVar16,local_90);
            }
            else {
              if (puVar16 != (undefined8 *)0x0) {
                *puVar16 = puVar10;
              }
              *(longlong *)(lVar11 + 0x60) = *(longlong *)(lVar11 + 0x60) + 8;
            }
          }
        }
      }
      uVar7 = (int)plVar22 + 1;
      plVar22 = (longlong *)(ulonglong)uVar7;
    } while (uVar7 < uVar23);
  }
  if (DAT_140c63838 == (code *)0x0) {
    if (DAT_140c63c54 == 0) {
      iVar8 = FUN_1402426a0();
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else {
        iVar8 = (**(code **)(*DAT_140c653c0 + 0x28))();
      }
    }
    else {
      iVar8 = 0;
    }
  }
  else {
    iVar8 = (*DAT_140c63838)(&PTR_u_TrackingSlot_140a6dab8,DAT_140c63858);
  }
  local_res10 = (undefined4 *)CONCAT44(local_res10._4_4_,iVar8);
  if (iVar8 != 0) {
    do {
      iVar8 = (int)plVar24;
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c63c54 == 0) && (iVar9 = FUN_1402426a0(), -1 < iVar9)) {
          puVar10 = (undefined4 *)(**(code **)(*DAT_140c653c0 + 0x20))(DAT_140c653c0,plVar24);
          goto LAB_140497feb;
        }
      }
      else {
        puVar10 = (undefined4 *)
                  (*DAT_140c63848)(&PTR_u_TrackingSlot_140a6dab8,plVar24,DAT_140c63858);
LAB_140497feb:
        if (puVar10 != (undefined4 *)0x0) {
          uVar7 = puVar10[4];
          if (uVar7 != 0) {
            puVar3 = (undefined4 *)param_1[6];
            puVar6 = puVar3;
            puVar18 = *(undefined4 **)(puVar3 + 2);
            while (puVar18 != (undefined4 *)0x0) {
              if ((uint)puVar18[8] < uVar7) {
                puVar18 = *(undefined4 **)(puVar18 + 6);
              }
              else {
                puVar6 = puVar18;
                puVar18 = *(undefined4 **)(puVar18 + 4);
              }
            }
            if ((puVar6 == puVar3) || (uVar7 < (uint)puVar6[8])) {
              local_90[0] = puVar3;
              ppuVar17 = local_90;
            }
            else {
              local_res20 = puVar6;
              ppuVar17 = (undefined4 **)&local_res20;
            }
            if (*ppuVar17 != puVar3) {
              lVar15 = *(longlong *)(*ppuVar17 + 10);
              uVar1 = *puVar10;
              lVar4 = *(longlong *)(lVar15 + 0x20);
              lVar11 = lVar4 + 1;
              _Dst = (void *)FUN_14018db00(*(undefined8 *)(lVar15 + 0x18),lVar11,4);
              *(undefined4 *)((longlong)_Dst + lVar4 * 4) = uVar1;
              if (*(void **)(lVar15 + 0x18) != _Dst) {
                memcpy(_Dst,*(void **)(lVar15 + 0x18),*(longlong *)(lVar15 + 0x20) << 2);
                lVar4 = *(longlong *)(lVar15 + 0x18);
                if (lVar4 != 0) {
                  (**(code **)(*(longlong *)(lVar4 + -0x10) + 8))(lVar4 + -0x10);
                }
                *(void **)(lVar15 + 0x18) = _Dst;
              }
              *(longlong *)(lVar15 + 0x20) = lVar11;
              FUN_1400bd4a0(param_1 + 0x15,puVar10,puVar10 + 4);
            }
          }
          iVar8 = (int)local_res18;
        }
      }
      plVar24 = (longlong *)(ulonglong)(iVar8 + 1U);
      local_res18 = plVar24;
    } while (iVar8 + 1U < (uint)local_res10);
  }
  return 0;
}

