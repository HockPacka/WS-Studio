
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1407c3b60(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  uint uVar7;
  float *pfVar8;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Da_00;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uStack_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  
  uVar2 = FUN_1402ec590(param_1,param_1 + 0xba8);
  if ((((((-1 < (int)uVar2) &&
         (uVar2 = FUN_1402ec590(extraout_XMM0_Da,param_1 + 0xbb0), -1 < (int)uVar2)) &&
        (uVar2 = FUN_1402ec590(extraout_XMM0_Da_00,param_1 + 3000), -1 < (int)uVar2)) &&
       (((uVar2 = (**(code **)(*DAT_140c65670 + 0x90))
                            (DAT_140c65670,L"Shaders\\SimpleVS.sho",param_1 + 0x1668),
         -1 < (int)uVar2 &&
         (uVar2 = (**(code **)(*DAT_140c65670 + 0x98))
                            (DAT_140c65670,L"Shaders\\SimplePS.sho",param_1 + 0x1670),
         -1 < (int)uVar2)) &&
        ((uVar2 = (**(code **)(*DAT_140c65670 + 0x90))
                            (DAT_140c65670,L"Shaders\\SkyVS.sho",param_1 + 0x1678), -1 < (int)uVar2
         && ((uVar2 = (**(code **)(*DAT_140c65670 + 0x98))
                                (DAT_140c65670,L"Shaders\\SkyPS.sho",param_1 + 0x1680),
             -1 < (int)uVar2 &&
             (uVar2 = (**(code **)(*DAT_140c65670 + 0x98))
                                (DAT_140c65670,L"Shaders\\CompositeEnvMapPS.sho",param_1 + 0x1688),
             -1 < (int)uVar2)))))))) &&
      (uVar2 = (**(code **)(*DAT_140c65670 + 0x98))
                         (DAT_140c65670,L"Shaders\\FilterEnvMapPS.sho",param_1 + 0x1690),
      -1 < (int)uVar2)) &&
     (((uVar2 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\DownsampleEnvMapPS.sho",param_1 + 0x1698),
       -1 < (int)uVar2 &&
       (uVar2 = (**(code **)(*DAT_140c65670 + 0x98))
                          (DAT_140c65670,L"Shaders\\CompositeCUBEMapPS.sho",param_1 + 0x16a0),
       -1 < (int)uVar2)) &&
      (uVar2 = (**(code **)(*DAT_140c65670 + 0x38))(DAT_140c65670,0x1c20,1,param_1 + 0x17a8),
      -1 < (int)uVar2)))) {
    uVar15 = param_1 + 0x17b0;
    uVar2 = (**(code **)(*DAT_140c65670 + 0x40))(DAT_140c65670,0x1500,0,1,uVar15);
    fVar11 = DAT_140c54ce8;
    if (-1 < (int)uVar2) {
      uVar4 = 0;
      fVar14 = DAT_140c54ce8 * 2.0;
      puVar5 = (undefined4 *)(param_1 + 0x16ac);
      uVar7 = uVar4;
      do {
        fVar12 = (float)uVar7 * fVar14 * 0.03125;
        uVar9 = FUN_1408fc950(fVar12);
        puVar5[-1] = uVar9;
        uVar9 = FUN_1408fe3d0(fVar12);
        uVar7 = uVar7 + 1;
        *puVar5 = uVar9;
        puVar5 = puVar5 + 2;
      } while (uVar7 < 0x20);
      iVar1 = DAT_140c54d00;
      if (*DAT_140c63750 < DAT_140c54d00) {
        iVar1 = *DAT_140c63750;
      }
      fVar13 = DAT_140c3b438 * 0.0055555557 * *(float *)(&DAT_140c54d10 + (longlong)iVar1 * 4);
      fVar14 = (float)FUN_1408fe3d0(0);
      fVar12 = (float)FUN_1408fc950(0);
      fVar10 = (float)FUN_1408fe3d0(fVar13);
      fVar13 = (float)FUN_1408fc950(fVar13);
      *(float *)(param_1 + 0x1838) = fVar14;
      *(undefined4 *)(param_1 + 0x182c) = 0;
      *(undefined4 *)(param_1 + 0x183c) = 0;
      *(undefined4 *)(param_1 + 0x184c) = 0;
      *(float *)(param_1 + 0x1820) = fVar12 * fVar13 - fVar14 * fVar14 * fVar10;
      *(float *)(param_1 + 0x1824) = fVar12 * fVar14 * fVar10 + fVar14 * fVar13;
      *(float *)(param_1 + 0x1830) = -(fVar14 * fVar12);
      *(float *)(param_1 + 0x1844) = fVar14 * fVar10 - fVar12 * fVar14 * fVar13;
      *(float *)(param_1 + 0x1834) = fVar12 * fVar12;
      *(float *)(param_1 + 0x1848) = fVar13 * fVar12;
      *(float *)(param_1 + 0x1828) = -(fVar10 * fVar12);
      *(float *)(param_1 + 0x1840) = fVar12 * fVar10 + fVar14 * fVar14 * fVar13;
      uVar2 = uRam0000000140c78448;
      *(undefined8 *)(param_1 + 0x1850) = _DAT_140c78440;
      *(undefined8 *)(param_1 + 0x1858) = uVar2;
      fVar14 = (float)FUN_140934e10(0x3dcccccd);
      fVar12 = (float)FUN_140934e10(0xbdcccccd);
      fVar12 = (float)FUN_1408fde98(fVar12 + fVar11,fVar11);
      lVar6 = 6;
      pfVar8 = (float *)(param_1 + 0x18bc);
      fVar11 = fVar14;
      do {
        fVar13 = (fVar12 - fVar14) * 0.16666667 + fVar11;
        fVar10 = (float)FUN_1408fc950(fVar11);
        fVar11 = (float)FUN_1408fe3d0(fVar11);
        pfVar8[1] = (fVar10 * 200.0) / fVar11;
        fVar11 = (float)FUN_1408fc950(fVar13);
        fVar10 = (float)FUN_1408fe3d0(fVar13);
        *pfVar8 = (fVar11 * 200.0) / fVar10;
        lVar6 = lVar6 + -1;
        pfVar8 = pfVar8 + 2;
        fVar11 = fVar13;
      } while (lVar6 != 0);
      lVar6 = (**(code **)(*DAT_140c65670 + 0x2c8))();
      uVar9 = 1;
      if (*(int *)(lVar6 + 0x54) != 0) {
        uVar9 = 4;
      }
      uVar15 = uVar15 & 0xffffffff00000000;
      uVar2 = (**(code **)(*DAT_140c65670 + 0x58))
                        (DAT_140c65670,0x10,1,1,uVar15,uVar9,1,0,0,param_1 + 0x17c0);
      if (-1 < (int)uVar2) {
        if (*(longlong **)(param_1 + 0x10) == (longlong *)0x0) {
          uVar9 = 0x40;
        }
        else {
          lVar6 = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x48))();
          uVar9 = *(undefined4 *)(lVar6 + 0x28);
        }
        uVar16 = param_1 + 0x19b0;
        uVar15 = uVar15 & 0xffffffff00000000;
        uVar2 = (**(code **)(*DAT_140c65670 + 0x58))
                          (DAT_140c65670,uVar9,uVar9,1,uVar15,5,1,0,0,uVar16);
        uVar9 = (undefined4)(uVar15 >> 0x20);
        if (-1 < (int)uVar2) {
          piVar3 = (int *)(**(code **)(*DAT_140c65670 + 0x2c8))();
          uVar2 = (**(code **)(*DAT_140c65670 + 0x68))
                            (DAT_140c65670,0x10,0x10,0x10,CONCAT44(uVar9,1),0,
                             (*piVar3 != 0) + '\x04',1,0,uVar16 & 0xffffffff00000000,
                             param_1 + 0x19b8);
          if ((-1 < (int)uVar2) &&
             (uVar2 = (**(code **)(**(longlong **)(param_1 + 0xba8) + 0x28))
                                (*(longlong **)(param_1 + 0xba8),
                                 L"Art\\Sky\\Glare\\Sky_Glare_StandardSunGlare_White.M3",
                                 param_1 + 0x1950,0), -1 < (int)uVar2)) {
            uStack_78 = 0x96;
            uStack_6c = 0;
            uStack_68 = 0;
            uStack_64 = 0;
            uStack_60 = 0;
            uStack_5c = 0;
            uStack_70 = 0x3f800000;
            (**(code **)(**(longlong **)(param_1 + 0x1950) + 0x248))
                      (*(longlong **)(param_1 + 0x1950),0,&uStack_78);
            (**(code **)(**(longlong **)(param_1 + 0x1950) + 0x48))
                      (*(longlong **)(param_1 + 0x1950),&DAT_140c78390);
            uVar2 = (**(code **)(*DAT_140c65670 + 0xc0))(DAT_140c65670,param_1 + 0x850);
            if (-1 < (int)uVar2) {
              uStack_68 = 0x407c4250;
              uStack_64 = 1;
              uStack_78 = uStack_78 & 0xffffffff00000000;
              uStack_70 = (undefined4)param_1;
              uStack_6c = (undefined4)((ulonglong)param_1 >> 0x20);
              uStack_60 = 0;
              uStack_5c = 0;
              (**(code **)(**(longlong **)(param_1 + 0x850) + 0x18))
                        (*(longlong **)(param_1 + 0x850),0,&uStack_78);
              puVar5 = (undefined4 *)(param_1 + 0x1a20);
              do {
                lVar6 = FUN_14024d360(uVar4);
                uVar4 = uVar4 + 1;
                *puVar5 = *(undefined4 *)(lVar6 + 0x24);
                puVar5 = puVar5 + 1;
              } while (uVar4 < 0xc);
              uVar9 = FUN_14018cdf0();
              *(undefined4 *)(param_1 + 0x528) = uVar9;
              uVar2 = 0;
            }
          }
        }
      }
    }
  }
  return uVar2;
}

