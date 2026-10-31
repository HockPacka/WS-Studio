
void FUN_1405a6880(longlong param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar12;
  int *piVar13;
  ulonglong uVar14;
  longlong local_res8;
  longlong local_res10;
  code *local_58;
  ulonglong uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iVar11;
  
  FUN_1405a7700(param_1 + 0x6d48);
  FUN_140019490(param_1 + 0x6d48);
  uVar14 = 0;
  uVar10 = 0;
  uVar8 = uVar14;
  if (*(longlong *)(param_1 + 0xa98) != 0) {
    do {
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0xa90) + uVar8 * 8);
      if ((lVar4 != 0) && (lVar4 = FUN_1405a4b80(lVar4,1), lVar4 != 0)) {
        local_58 = FUN_1405a5c90;
        uStack_3c = (undefined4)(uStack_50 >> 0x20);
        uStack_50 = uStack_50 & 0xffffffff00000000;
        local_48 = 0x405a5c90;
        uStack_44 = 1;
        uStack_40 = 0;
        FUN_1405a5fe0(param_1,lVar4,&local_48);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(ulonglong *)(param_1 + 0xa98));
  }
  uStack_50 = 0;
  local_58 = (code *)0x0;
  FUN_1403d6710(param_1 + 0xa0,&local_58);
  FUN_1403d6710(param_1 + 0xb8,&local_58);
  FUN_1403d6710(param_1 + 0x118,&local_58);
  FUN_1403d6710(param_1 + 0x130,&local_58);
  uVar8 = uStack_50;
  pcVar2 = local_58;
  uVar9 = uVar14;
  if (uStack_50 != 0) {
    do {
      lVar4 = *(longlong *)(*(longlong *)(pcVar2 + uVar9 * 8) + 0x50);
      if (lVar4 == 0) {
        lVar4 = *(longlong *)(*(longlong *)(pcVar2 + uVar9 * 8) + 0x40) + 0x9c;
      }
      uVar1 = *(uint *)(lVar4 + 0x80);
      if (uVar1 != 0) {
        if ((*(longlong *)(DAT_140c65898 + 0x78) == 0) || (DAT_140c65898 == 0)) {
LAB_1405a6a34:
          lVar4 = FUN_1407a0fd0(DAT_140c65b70);
          if (lVar4 == 0) goto LAB_1405a6a6a;
        }
        else {
          lVar4 = *(longlong *)(DAT_140c65898 + 0x7d18);
          lVar6 = lVar4;
          lVar12 = *(longlong *)(lVar4 + 8);
          while (lVar12 != 0) {
            if (*(uint *)(lVar12 + 0x20) < uVar1) {
              lVar12 = *(longlong *)(lVar12 + 0x18);
            }
            else {
              lVar6 = lVar12;
              lVar12 = *(longlong *)(lVar12 + 0x10);
            }
          }
          if ((lVar6 == lVar4) || (uVar1 < *(uint *)(lVar6 + 0x20))) {
            local_res10 = lVar4;
            plVar5 = &local_res10;
          }
          else {
            local_res8 = lVar6;
            plVar5 = &local_res8;
          }
          if ((*plVar5 == lVar4) || (lVar4 = *(longlong *)(*plVar5 + 0x28), lVar4 == 0))
          goto LAB_1405a6a34;
        }
        local_58 = FUN_1405a5c90;
        uStack_3c = (undefined4)(uStack_50 >> 0x20);
        uStack_50 = uStack_50 & 0xffffffff00000000;
        local_48 = 0x405a5c90;
        uStack_44 = 1;
        uStack_40 = 0;
        FUN_1405a5fe0(param_1,lVar4,&local_48);
      }
LAB_1405a6a6a:
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar8);
  }
  lVar4 = 0x28;
  iVar11 = -0x1c;
  uVar8 = uVar14;
  do {
    if ((SBORROW4(uVar10,0x1c) != iVar11 < 0) && (*(longlong *)(lVar4 + DAT_140c65a08) != 0)) {
      piVar13 = (int *)(*(longlong *)(lVar4 + DAT_140c65a08) + 0x2c);
      lVar12 = 3;
      do {
        iVar11 = *piVar13;
        if (iVar11 != 0) {
          if (DAT_140c63840 == (code *)0x0) {
            if ((DAT_140c64c04 != 0) || (iVar3 = FUN_140248ca0(), iVar3 < 0)) goto LAB_1405a6b20;
            lVar6 = (**(code **)(*DAT_140c63b40 + 0x18))(DAT_140c63b40,iVar11);
          }
          else {
            lVar6 = (*DAT_140c63840)(&PTR_u_VisualEffect_140a6dff8,iVar11,DAT_140c63858);
          }
          if (lVar6 != 0) {
            uVar9 = *(ulonglong *)(lVar6 + 0x18);
            uVar7 = uVar14;
            if ((uVar9 != 0) && (uVar9 <= DAT_140c3fe70)) {
              uVar7 = DAT_140c3fe68 + uVar9;
            }
            FUN_1405a5c90(param_1,uVar7);
          }
        }
LAB_1405a6b20:
        piVar13 = piVar13 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
    }
    iVar11 = (int)uVar8;
    uVar10 = iVar11 + 1;
    uVar8 = (ulonglong)uVar10;
    lVar4 = lVar4 + 8;
    iVar11 = iVar11 + -0x1b;
    if (0x1b < uVar10) {
      FUN_1405a5c90(param_1,L"Art\\FX\\Test\\SLee\\overkill_death.m3");
      FUN_1405a5c90(param_1,L"Art\\FX\\Model\\Props\\Explosion_Smoke\\Explosion_Smoke.m3");
      if (pcVar2 != (code *)0x0) {
        (**(code **)(*(longlong *)(pcVar2 + -0x10) + 8))(pcVar2 + -0x10);
      }
      return;
    }
  } while( true );
}

