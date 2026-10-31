
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1402eb270(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  longlong lVar14;
  int *piVar15;
  int *piVar16;
  undefined1 *puVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined1 *puVar20;
  uint uVar21;
  uint uVar22;
  undefined1 *puVar23;
  int *piVar24;
  ulonglong uVar25;
  undefined2 *puVar26;
  int iVar27;
  ulonglong uVar28;
  short sVar29;
  ulonglong uVar30;
  uint local_res10 [2];
  undefined1 local_88 [16];
  undefined1 local_78 [8];
  undefined1 *local_70;
  ulonglong local_68;
  undefined4 local_58 [2];
  undefined4 *local_50;
  code *local_48;
  undefined8 local_40;
  
  uVar25 = 0;
  *param_1 = 0;
  local_res10[0] = param_2;
  uVar13 = (**(code **)(*DAT_140c65670 + 0x90))
                     (DAT_140c65670,L"Shaders\\ModelVS.sho",param_1 + 0x1fe);
  if ((((((((-1 < (int)uVar13) &&
           (uVar13 = (**(code **)(*DAT_140c65670 + 0x98))
                               (DAT_140c65670,L"Shaders\\ModelPS.sho",param_1 + 0x200),
           -1 < (int)uVar13)) &&
          (uVar13 = (**(code **)(*DAT_140c65670 + 0x90))
                              (DAT_140c65670,L"Shaders\\M3CloudVS.sho",param_1 + 0x202),
          -1 < (int)uVar13)) &&
         ((uVar13 = (**(code **)(*DAT_140c65670 + 0x98))
                              (DAT_140c65670,L"Shaders\\M3CloudPS.sho",param_1 + 0x204),
          -1 < (int)uVar13 &&
          (uVar13 = (**(code **)(*DAT_140c65670 + 0x90))
                              (DAT_140c65670,L"Shaders\\SimpleVS.sho",param_1 + 0x206),
          -1 < (int)uVar13)))) &&
        (uVar13 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\SimplePS.sho",param_1 + 0x208),
        -1 < (int)uVar13)) &&
       (((uVar13 = (**(code **)(*DAT_140c65670 + 0x98))
                             (DAT_140c65670,L"shaders\\ParticlePS.sho",param_1 + 0x20c),
         -1 < (int)uVar13 &&
         (uVar13 = (**(code **)(*DAT_140c65670 + 0x90))
                             (DAT_140c65670,L"Shaders\\ParticleGPUVS.sho",param_1 + 0x20a),
         -1 < (int)uVar13)) &&
        ((uVar13 = (**(code **)(*DAT_140c65670 + 0x90))
                             (DAT_140c65670,L"shaders\\RibbonVS.sho",param_1 + 0x20e),
         -1 < (int)uVar13 &&
         (((uVar13 = (**(code **)(*DAT_140c65670 + 0x98))
                               (DAT_140c65670,L"shaders\\RibbonPS.sho",param_1 + 0x210),
           -1 < (int)uVar13 &&
           (uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                               (DAT_140c65670,2,2,0,0,1,0,0x15,0,param_1 + 0x212), -1 < (int)uVar13)
           ) && (uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                                    (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x214),
                -1 < (int)uVar13)))))))) &&
      ((uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                           (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x216), -1 < (int)uVar13 &&
       (uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                           (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x218), -1 < (int)uVar13))))
     && ((uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                             (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x21a), -1 < (int)uVar13 &&
         (((uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                               (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x21c), -1 < (int)uVar13
           && (uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                                  (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x21e),
              -1 < (int)uVar13)) &&
          ((uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                               (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x220), -1 < (int)uVar13
           && (((uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                                    (DAT_140c65670,1,1,0,0,1,0,0x15,0,param_1 + 0x222),
                -1 < (int)uVar13 &&
                (uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                                    (DAT_140c65670,1,1,0,0x11,1,0,0x15,0,param_1 + 0x224),
                -1 < (int)uVar13)) &&
               (uVar13 = (**(code **)(*DAT_140c65670 + 0x58))
                                   (DAT_140c65670,0x100,0x100,1,0x13,1,0,0,0,param_1 + 0x226),
               -1 < (int)uVar13)))))))))) {
    lVar14 = (**(code **)(*DAT_140c65670 + 0x2c8))();
    uVar13 = (**(code **)(*DAT_140c65670 + 0x38))
                       (DAT_140c65670,*(int *)(lVar14 + 0x30) << 2,1,param_1 + 0x22a);
    if ((-1 < (int)uVar13) &&
       (uVar13 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x10,1,param_1 + 0x22e),
       -1 < (int)uVar13)) {
      FUN_1402ebf40(param_1);
      uVar13 = (**(code **)(*DAT_140c65670 + 0xc0))(DAT_140c65670,param_1 + 0x22c);
      if (-1 < (int)uVar13) {
        local_48 = FUN_1402ebf40;
        local_58[0] = 0;
        local_40 = 0;
        local_50 = param_1;
        (**(code **)(**(longlong **)(param_1 + 0x22c) + 0x18))
                  (*(longlong **)(param_1 + 0x22c),0,local_58);
        FUN_1407e4830(param_1 + 0x1c,0,0x630);
        param_1[0x1c] = 0x4d4f444c;
        param_1[0x1d] = 100;
        FUN_1402ecf40(param_1 + 0x20);
        **(undefined2 **)(param_1 + 0x22) = 0x96;
        FUN_1402ed080(param_1 + 0x58);
        *(undefined2 *)(*(longlong *)(param_1 + 0x5a) + 2) = 0xffff;
        FUN_1402ed1a0(param_1 + 0x7c);
        puVar3 = *(undefined2 **)(param_1 + 0x7e);
        *puVar3 = 0xffff;
        puVar3[2] = 0xffff;
        uVar13 = uRam0000000140c78398;
        *(undefined8 *)(puVar3 + 0x68) = _DAT_140c78390;
        *(undefined8 *)(puVar3 + 0x6c) = uVar13;
        uVar13 = uRam0000000140c783a8;
        *(undefined8 *)(puVar3 + 0x70) = _DAT_140c783a0;
        *(undefined8 *)(puVar3 + 0x74) = uVar13;
        uVar13 = CONCAT44(uRam0000000140c783bc,uRam0000000140c783b8);
        *(ulonglong *)(puVar3 + 0x78) = CONCAT44(uRam0000000140c783b4,_DAT_140c783b0);
        *(undefined8 *)(puVar3 + 0x7c) = uVar13;
        uVar13 = CONCAT44(uRam0000000140c783cc,uRam0000000140c783c8);
        *(ulonglong *)(puVar3 + 0x80) = CONCAT44(uRam0000000140c783c4,_DAT_140c783c0);
        *(undefined8 *)(puVar3 + 0x84) = uVar13;
        uVar13 = uRam0000000140c78398;
        *(undefined8 *)(puVar3 + 0x88) = _DAT_140c78390;
        *(undefined8 *)(puVar3 + 0x8c) = uVar13;
        uVar13 = uRam0000000140c783a8;
        *(undefined8 *)(puVar3 + 0x90) = _DAT_140c783a0;
        *(undefined8 *)(puVar3 + 0x94) = uVar13;
        uVar9 = uRam0000000140c783bc;
        uVar8 = uRam0000000140c783b8;
        uVar7 = uRam0000000140c783b4;
        *(undefined4 *)(puVar3 + 0x98) = _DAT_140c783b0;
        *(undefined4 *)(puVar3 + 0x9a) = uVar7;
        *(undefined4 *)(puVar3 + 0x9c) = uVar8;
        *(undefined4 *)(puVar3 + 0x9e) = uVar9;
        uVar9 = uRam0000000140c783cc;
        uVar8 = uRam0000000140c783c8;
        uVar7 = uRam0000000140c783c4;
        *(undefined4 *)(puVar3 + 0xa0) = _DAT_140c783c0;
        *(undefined4 *)(puVar3 + 0xa2) = uVar7;
        *(undefined4 *)(puVar3 + 0xa4) = uVar8;
        *(undefined4 *)(puVar3 + 0xa6) = uVar9;
        FUN_1402ed680(param_1 + 0x140);
        if (param_1[0x144] != 0) {
          FUN_14018b900(*(undefined8 *)(param_1 + 0x146),0);
          param_1[0x144] = 0;
          *(undefined8 *)(param_1 + 0x146) = 0;
        }
        FUN_1402ed3e0(param_1 + 0xb0);
        param_1[0x1aa] = 0;
        param_1[0x1ab] = 0x3f800000;
        *(undefined8 *)(param_1 + 0x1ac) = 0x3f800000;
        *(undefined8 *)(param_1 + 0x1ae) = 0;
        *(undefined8 *)(param_1 + 0x1c2) = 1;
        param_1[0x1c4] = 0;
        iVar10 = FUN_14021a6f0();
        if (iVar10 == 0) {
          param_1[0x230] = 0;
        }
        else {
          iVar10 = FUN_14021a6f0();
          piVar15 = (int *)FUN_14021a7a0(iVar10 + -1);
          param_1[0x230] = *piVar15 + 1;
        }
        uVar11 = FUN_1402184f0();
        uVar30 = (ulonglong)uVar11;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = CONCAT44(0,uVar11);
        uVar13 = SUB168(ZEXT816(4) * auVar4,0);
        if (SUB168(ZEXT816(4) * auVar4,8) != 0) {
          uVar13 = 0xffffffffffffffff;
        }
        local_res10[0] = uVar11;
        piVar16 = (int *)FUN_14018b280(uVar13,8);
        uVar28 = uVar25;
        piVar15 = piVar16;
        if (uVar11 != 0) {
          do {
            *piVar15 = (int)uVar28;
            uVar21 = (int)uVar28 + 1;
            uVar28 = (ulonglong)uVar21;
            piVar15 = piVar15 + 1;
          } while (uVar21 < uVar11);
        }
        FUN_1401c3280(FUN_1402ec9d0,piVar16,CONCAT44(0,uVar11),0);
        iVar27 = -1;
        iVar10 = -1;
        piVar15 = piVar16;
        uVar28 = uVar30;
        if (uVar11 != 0) {
          do {
            lVar14 = FUN_1402185a0(*piVar15);
            if (iVar10 != *(int *)(lVar14 + 4)) {
              uVar25 = (ulonglong)((int)uVar25 + 1);
              iVar10 = *(int *)(lVar14 + 4);
            }
            uVar28 = uVar28 - 1;
            piVar15 = piVar15 + 1;
          } while (uVar28 != 0);
        }
        param_1[0x231] = (int)uVar25;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar25;
        uVar13 = SUB168(ZEXT816(0xc4) * auVar5,0);
        if (SUB168(ZEXT816(0xc4) * auVar5,8) != 0) {
          uVar13 = 0xffffffffffffffff;
        }
        uVar13 = FUN_14018b280(uVar13,0);
        *(undefined8 *)(param_1 + 0x232) = uVar13;
        FUN_1407e4830(uVar13,0xff,(ulonglong)(uint)param_1[0x231] * 0xc4);
        uVar11 = 0;
        puVar19 = (undefined4 *)0x0;
        puVar18 = puVar19;
        piVar15 = piVar16;
        if (local_res10[0] != 0) {
          do {
            lVar14 = FUN_1402185a0(*piVar15);
            iVar10 = *(int *)(lVar14 + 4);
            if (iVar27 != iVar10) {
              puVar18 = (undefined4 *)(ulonglong)((int)puVar18 + 1);
              iVar27 = iVar10;
            }
            piVar24 = (int *)((ulonglong)((int)puVar18 - 1) * 0xc4 + *(longlong *)(param_1 + 0x232))
            ;
            *piVar24 = iVar10;
            piVar24[1] = 0;
            piVar24[2] = 0;
            piVar24[(longlong)*(int *)(lVar14 + 8) + 2] = *(int *)(lVar14 + 0xc);
            uVar30 = uVar30 - 1;
            piVar15 = piVar15 + 1;
          } while (uVar30 != 0);
        }
        FUN_14018b900(piVar16,0);
        *(undefined8 *)(param_1 + 0x234) = 0;
        uVar12 = FUN_140216730();
        uVar21 = uVar11;
        if (uVar12 != 0) {
          do {
            lVar14 = FUN_1402167e0(uVar21);
            if ((uint)param_1[0x234] <= *(uint *)(lVar14 + 4)) {
              param_1[0x234] = *(uint *)(lVar14 + 4) + 1;
            }
            if ((uint)param_1[0x235] <= *(uint *)(lVar14 + 8)) {
              param_1[0x235] = *(uint *)(lVar14 + 8) + 1;
            }
            uVar21 = uVar21 + 1;
          } while (uVar21 < uVar12);
        }
        auVar4 = ZEXT816(4) * ZEXT416((uint)(param_1[0x235] * param_1[0x234]));
        uVar13 = auVar4._0_8_;
        if (auVar4._8_8_ != 0) {
          uVar13 = 0xffffffffffffffff;
        }
        uVar13 = FUN_14018b280(uVar13,0);
        *(undefined8 *)(param_1 + 0x236) = uVar13;
        puVar18 = puVar19;
        if (param_1[0x234] != 0) {
          do {
            uVar21 = 0;
            iVar10 = (int)puVar18;
            if (param_1[0x235] != 0) {
              do {
                uVar22 = param_1[0x235] * iVar10 + uVar21;
                uVar21 = uVar21 + 1;
                *(int *)(*(longlong *)(param_1 + 0x236) + (ulonglong)uVar22 * 4) = iVar10;
              } while (uVar21 < (uint)param_1[0x235]);
            }
            puVar18 = (undefined4 *)(ulonglong)(iVar10 + 1U);
          } while (iVar10 + 1U < (uint)param_1[0x234]);
        }
        puVar18 = puVar19;
        if (uVar12 != 0) {
          do {
            lVar14 = FUN_1402167e0(puVar18);
            uVar21 = (int)puVar18 + 1;
            puVar18 = (undefined4 *)(ulonglong)uVar21;
            *(undefined4 *)
             (*(longlong *)(param_1 + 0x236) +
             (ulonglong)(uint)(*(int *)(lVar14 + 4) * param_1[0x235] + *(int *)(lVar14 + 8)) * 4) =
                 *(undefined4 *)(lVar14 + 0xc);
          } while (uVar21 < uVar12);
        }
        local_70 = (undefined1 *)FUN_14018b280(0x28);
        local_68 = 0;
        *local_70 = 0;
        *(undefined8 *)(local_70 + 8) = 0;
        *(undefined1 **)(local_70 + 0x10) = local_70;
        *(undefined1 **)(local_70 + 0x18) = local_70;
        local_50 = (undefined4 *)FUN_14018b280(0x28);
        local_48 = (code *)0x0;
        *(undefined1 *)local_50 = 0;
        *(undefined8 *)((longlong)local_50 + 8) = 0;
        *(undefined4 **)((longlong)local_50 + 0x10) = local_50;
        *(undefined4 **)((longlong)local_50 + 0x18) = local_50;
        if (param_1[0x230] != 0) {
          do {
            lVar14 = FUN_14021a740(uVar11);
            sVar29 = 1;
            while (lVar14 != 0) {
              uVar2 = *(ushort *)(lVar14 + 0x10);
              uVar21 = (uint)uVar2;
              local_res10[0] = uVar21 << 0x10 | uVar11;
              if ((uVar2 == 0) || (uVar2 == 0x96)) break;
              puVar20 = *(undefined1 **)((longlong)local_50 + 8);
              puVar23 = (undefined1 *)local_50;
              if (*(undefined1 **)((longlong)local_50 + 8) != (undefined1 *)0x0) {
                do {
                  if (*(uint *)(puVar20 + 0x20) < local_res10[0]) {
                    puVar17 = *(undefined1 **)(puVar20 + 0x18);
                  }
                  else {
                    puVar17 = *(undefined1 **)(puVar20 + 0x10);
                    puVar23 = puVar20;
                  }
                  puVar20 = puVar17;
                } while (puVar17 != (undefined1 *)0x0);
                if (((undefined4 *)puVar23 != local_50) &&
                   (*(uint *)(puVar23 + 0x20) <= local_res10[0])) break;
              }
              FUN_1400293c0(local_58,local_88,local_res10);
              puVar20 = *(undefined1 **)(local_70 + 8);
              puVar23 = local_70;
              if (*(undefined1 **)(local_70 + 8) == (undefined1 *)0x0) {
LAB_1402ebd04:
                lVar14 = FUN_14018b280(0x28);
                if ((uint *)(lVar14 + 0x20) != (uint *)0x0) {
                  *(uint *)(lVar14 + 0x20) = uVar21;
                  *(short *)(lVar14 + 0x24) = (short)uVar11;
                  *(short *)(lVar14 + 0x26) = sVar29;
                }
                *(longlong *)(puVar23 + 0x10) = lVar14;
                if (puVar23 == local_70) {
                  *(longlong *)(local_70 + 8) = lVar14;
                  *(longlong *)(local_70 + 0x18) = lVar14;
                }
                else if (puVar23 == *(undefined1 **)(local_70 + 0x10)) {
                  *(longlong *)(local_70 + 0x10) = lVar14;
                }
              }
              else {
                do {
                  puVar23 = puVar20;
                  if (uVar21 < *(uint *)(puVar23 + 0x20)) {
                    puVar20 = *(undefined1 **)(puVar23 + 0x10);
                  }
                  else {
                    puVar20 = *(undefined1 **)(puVar23 + 0x18);
                  }
                } while (puVar20 != (undefined1 *)0x0);
                if ((puVar23 == local_70) || (uVar21 < *(uint *)(puVar23 + 0x20)))
                goto LAB_1402ebd04;
                lVar14 = FUN_14018b280(0x28,0);
                if ((uint *)(lVar14 + 0x20) != (uint *)0x0) {
                  *(uint *)(lVar14 + 0x20) = uVar21;
                  *(short *)(lVar14 + 0x24) = (short)uVar11;
                  *(short *)(lVar14 + 0x26) = sVar29;
                }
                *(longlong *)(puVar23 + 0x18) = lVar14;
                if (puVar23 == *(undefined1 **)(local_70 + 0x18)) {
                  *(longlong *)(local_70 + 0x18) = lVar14;
                }
              }
              *(undefined1 **)(lVar14 + 8) = puVar23;
              *(undefined8 *)(lVar14 + 0x10) = 0;
              *(undefined8 *)(lVar14 + 0x18) = 0;
              FUN_1400081c0(lVar14,local_70 + 8);
              local_68 = local_68 + 1;
              lVar14 = FUN_14021a740(uVar21);
              sVar29 = sVar29 + 1;
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < (uint)param_1[0x230]);
        }
        uVar25 = local_68;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = local_68;
        uVar13 = SUB168(ZEXT816(4) * auVar6,0);
        if (SUB168(ZEXT816(4) * auVar6,8) != 0) {
          uVar13 = 0xffffffffffffffff;
        }
        puVar18 = (undefined4 *)FUN_14018b280(uVar13,0);
        if (puVar18 != (undefined4 *)0x0) {
          iVar10 = (int)uVar25;
          puVar1 = puVar18;
          while (iVar10 = iVar10 + -1, puVar19 = puVar18, -1 < iVar10) {
            *puVar1 = 0xff0000;
            puVar1 = puVar1 + 1;
          }
        }
        *(undefined4 **)(param_1 + 0x238) = puVar19;
        auVar4 = ZEXT816(8) * ZEXT416(param_1[0x230] + 1);
        uVar13 = auVar4._0_8_;
        if (auVar4._8_8_ != 0) {
          uVar13 = 0xffffffffffffffff;
        }
        uVar13 = FUN_14018b280(uVar13,0);
        *(undefined8 *)(param_1 + 0x23a) = uVar13;
        uVar25 = 0;
        puVar3 = *(undefined2 **)(param_1 + 0x238);
        puVar20 = *(undefined1 **)(local_70 + 0x10);
        while (puVar20 != local_70) {
          uVar30 = uVar25;
          if ((uint)uVar25 <= *(uint *)(puVar20 + 0x20)) {
            do {
              uVar11 = (int)uVar30 + 1;
              uVar25 = (ulonglong)uVar11;
              *(undefined2 **)(*(longlong *)(param_1 + 0x23a) + uVar30 * 8) = puVar3;
              uVar30 = uVar25;
            } while (uVar11 <= *(uint *)(puVar20 + 0x20));
          }
          puVar26 = puVar3 + 2;
          *puVar3 = *(undefined2 *)(puVar20 + 0x24);
          puVar3[1] = *(undefined2 *)(puVar20 + 0x26);
          puVar23 = *(undefined1 **)(puVar20 + 0x18);
          puVar3 = puVar26;
          if (puVar23 == (undefined1 *)0x0) {
            puVar23 = *(undefined1 **)(puVar20 + 8);
            if (puVar20 == *(undefined1 **)(puVar23 + 0x18)) {
              do {
                puVar20 = puVar23;
                puVar23 = *(undefined1 **)(puVar20 + 8);
              } while (puVar20 == *(undefined1 **)(puVar23 + 0x18));
            }
            if (*(undefined1 **)(puVar20 + 0x18) != puVar23) {
              puVar20 = puVar23;
            }
          }
          else {
            for (puVar17 = *(undefined1 **)(puVar23 + 0x10); puVar20 = puVar23,
                puVar17 != (undefined1 *)0x0; puVar17 = *(undefined1 **)(puVar17 + 0x10)) {
              puVar23 = puVar17;
            }
          }
        }
        if ((uint)uVar25 <= (uint)param_1[0x230]) {
          do {
            uVar11 = (int)uVar25 + 1;
            *(undefined2 **)(*(longlong *)(param_1 + 0x23a) + uVar25 * 8) = puVar3;
            uVar25 = (ulonglong)uVar11;
          } while (uVar11 <= (uint)param_1[0x230]);
        }
        FUN_140008410(local_58);
        FUN_14018b900(local_50,0);
        FUN_140008410(local_78);
        FUN_14018b900(local_70,0);
        param_1[1] = 0;
        uVar13 = 0;
      }
    }
  }
  return uVar13;
}

