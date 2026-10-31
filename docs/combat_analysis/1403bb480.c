
void FUN_1403bb480(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  void *_Src;
  size_t _Size;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 *_Dst;
  ulonglong uVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 *puVar18;
  bool bVar19;
  undefined8 local_res8;
  longlong local_res10;
  longlong local_res18;
  longlong local_res20;
  longlong local_88;
  longlong local_80;
  undefined8 local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 *local_50;
  
  lVar6 = DAT_140c65898;
  local_70 = 0;
  local_68 = 0;
  local_60 = (undefined8 *)0x0;
  local_58 = 0;
  local_50 = (undefined8 *)0x0;
  local_80 = DAT_140c65898;
  local_78 = 0xc;
  uVar8 = SUB168(ZEXT816(4) * ZEXT816(0xc),0);
  if (SUB168(ZEXT816(4) * ZEXT816(0xc),8) != 0) {
    uVar8 = 0xffffffffffffffff;
  }
  local_70 = FUN_14018b280(uVar8);
  lVar16 = *(longlong *)(param_2 + 8);
  local_68 = CONCAT71(local_68._1_7_,*(undefined1 *)(lVar6 + 0x6dec));
  uVar14 = 0;
  lVar17 = local_70;
  if (*(longlong *)(param_2 + 0x10) - lVar16 >> 2 != 0) {
    do {
      uVar15 = (ulonglong)((int)uVar14 + 1);
      *(undefined4 *)(lVar17 + uVar14 * 4) = *(undefined4 *)(lVar16 + uVar14 * 4);
      lVar16 = *(longlong *)(param_2 + 8);
      uVar14 = uVar15;
      lVar17 = local_70;
    } while (uVar15 < (ulonglong)(*(longlong *)(param_2 + 0x10) - lVar16 >> 2));
  }
  lVar17 = *(longlong *)(lVar6 + 0x1468);
  lVar16 = 0;
  puVar18 = (undefined8 *)0x0;
  if (lVar17 != 0) {
    puVar9 = (undefined8 *)FUN_14018b280(lVar17 * 8 + 0x10,0);
    if (puVar9 != (undefined8 *)0x0) {
      *puVar9 = &PTR_LAB_140b55060;
      puVar9[1] = lVar17;
    }
    if (puVar9 + 2 != (undefined8 *)0x0) {
      puVar18 = puVar9 + 2;
    }
  }
  lVar17 = *(longlong *)(*(longlong *)(lVar6 + 0x1460) + 0x10);
  puVar9 = puVar18;
  lVar13 = lVar16;
  local_res8 = param_1;
  if (lVar17 != *(longlong *)(lVar6 + 0x1460)) {
    do {
      uVar2 = *(uint *)(lVar17 + 0x20);
      bVar1 = *(byte *)(lVar17 + 0x24);
      puVar18 = puVar9;
      lVar16 = lVar13;
      if (uVar2 != 0) {
        lVar11 = *(longlong *)(lVar6 + 0xaa8);
        lVar5 = lVar11;
        lVar4 = *(longlong *)(lVar11 + 8);
        while (lVar4 != 0) {
          if (*(uint *)(lVar4 + 0x20) < uVar2) {
            lVar4 = *(longlong *)(lVar4 + 0x18);
          }
          else {
            lVar5 = lVar4;
            lVar4 = *(longlong *)(lVar4 + 0x10);
          }
        }
        if ((lVar5 == lVar11) || (uVar2 < *(uint *)(lVar5 + 0x20))) {
          local_res18 = lVar11;
          plVar10 = &local_res18;
        }
        else {
          local_res10 = lVar5;
          plVar10 = &local_res10;
        }
        if (*plVar10 != lVar11) {
          plVar10 = *(longlong **)(*plVar10 + 0x28);
          if (((((ulonglong)*(byte *)(lVar6 + 0x6dec) < (ulonglong)plVar10[1]) &&
               (lVar11 = *(longlong *)(*plVar10 + (ulonglong)*(byte *)(lVar6 + 0x6dec) * 8),
               lVar11 != 0)) && (*(char *)(lVar11 + 8) != '\0')) && (bVar1 < 10)) {
            uVar3 = *(uint *)(lVar11 + 4);
            lVar11 = *(longlong *)(lVar6 + 0x78);
            if (uVar3 != 0) {
              if (lVar11 == 0) {
LAB_1403bb6da:
                lVar11 = FUN_1407a0fd0(DAT_140c65b70);
                if (lVar11 == 0) goto LAB_1403bb74a;
              }
              else {
                if (*(longlong *)(DAT_140c65898 + 0x78) == lVar11) {
                  bVar19 = true;
                }
                else {
                  bVar19 = *(longlong *)(DAT_140c65898 + 0x6490) == lVar11;
                }
                lVar11 = 0;
                if (bVar19) {
                  lVar11 = DAT_140c65898;
                }
                if (lVar11 == 0) goto LAB_1403bb6da;
                lVar11 = *(longlong *)(lVar11 + 0x7d18);
                lVar5 = lVar11;
                lVar4 = *(longlong *)(lVar11 + 8);
                while (lVar4 != 0) {
                  if (*(uint *)(lVar4 + 0x20) < uVar3) {
                    lVar4 = *(longlong *)(lVar4 + 0x18);
                  }
                  else {
                    lVar5 = lVar4;
                    lVar4 = *(longlong *)(lVar4 + 0x10);
                  }
                }
                if ((lVar5 == lVar11) || (uVar3 < *(uint *)(lVar5 + 0x20))) {
                  local_88 = lVar11;
                  plVar10 = &local_88;
                }
                else {
                  plVar10 = &local_res20;
                  local_res20 = lVar5;
                }
                if ((*plVar10 == lVar11) || (lVar11 = *(longlong *)(*plVar10 + 0x28), lVar11 == 0))
                goto LAB_1403bb6da;
              }
              iVar7 = FUN_1403d8c10(lVar11);
              if (iVar7 == 0) {
                lVar16 = lVar13 + 1;
                local_res8 = CONCAT44(CONCAT31(local_res8._5_3_,bVar1),uVar2);
                puVar12 = (undefined8 *)FUN_14018db00(puVar9,lVar16,8);
                puVar12[lVar13] = local_res8;
                if ((puVar9 != puVar12) &&
                   (memcpy(puVar12,puVar9,lVar13 * 8), puVar18 = puVar12,
                   puVar9 != (undefined8 *)0x0)) {
                  (**(code **)(puVar9[-2] + 8))(puVar9 + -2);
                }
              }
            }
          }
        }
      }
LAB_1403bb74a:
      lVar13 = *(longlong *)(lVar17 + 0x18);
      if (lVar13 == 0) {
        lVar13 = *(longlong *)(lVar17 + 8);
        if (lVar17 == *(longlong *)(lVar13 + 0x18)) {
          do {
            lVar17 = lVar13;
            lVar13 = *(longlong *)(lVar17 + 8);
          } while (lVar17 == *(longlong *)(lVar13 + 0x18));
        }
        if (*(longlong *)(lVar17 + 0x18) != lVar13) {
          lVar17 = lVar13;
        }
      }
      else {
        for (lVar11 = *(longlong *)(lVar13 + 0x10); lVar17 = lVar13, lVar11 != 0;
            lVar11 = *(longlong *)(lVar11 + 0x10)) {
          lVar13 = lVar11;
        }
      }
      puVar9 = puVar18;
      lVar13 = lVar16;
    } while (lVar17 != *(longlong *)(lVar6 + 0x1460));
  }
  local_68._0_2_ = CONCAT11((char)lVar16,(undefined1)local_68);
  lVar17 = (ulonglong)*(uint *)(lVar6 + 0x6dec) + 0x6e7;
  lVar16 = *(longlong *)(lVar6 + 8 + lVar17 * 0x10);
  local_60 = puVar18;
  if (lVar16 == 0) {
    puVar9 = (undefined8 *)0x0;
  }
  else {
    puVar9 = (undefined8 *)FUN_14018b280(lVar16 * 2 + 0x10,0);
    if (puVar9 == (undefined8 *)0x0) {
      puVar9 = (undefined8 *)&DAT_00000010;
    }
    else {
      *puVar9 = &PTR_LAB_140b55060;
      puVar9[1] = lVar16;
      puVar9 = puVar9 + 2;
    }
  }
  _Size = lVar16 * 2;
  memcpy(puVar9,*(void **)(lVar6 + lVar17 * 0x10),_Size);
  lVar17 = *(longlong *)(lVar6 + 0x6eb8);
  _Src = *(void **)(lVar6 + 0x6eb0);
  puVar12 = puVar9;
  if (lVar17 != 0) {
    lVar16 = lVar16 + lVar17;
    _Dst = (undefined8 *)FUN_14018db00(puVar9,lVar16,2);
    memcpy((undefined1 *)((longlong)_Dst + _Size),_Src,lVar17 * 2);
    if ((puVar9 != _Dst) && (memcpy(_Dst,puVar9,_Size), puVar12 = _Dst, puVar9 != (undefined8 *)0x0)
       ) {
      (**(code **)(puVar9[-2] + 8))(puVar9 + -2);
    }
  }
  local_58 = CONCAT71(local_58._1_7_,(char)lVar16);
  local_50 = puVar12;
  FUN_1403f4900(DAT_140c65898,0xb1,&local_78);
  *(undefined8 *)(local_80 + 0x6eb8) = 0;
  FUN_14018b900(local_70,0);
  if (puVar12 != (undefined8 *)0x0) {
    (**(code **)(puVar12[-2] + 8))(puVar12 + -2);
  }
  if (puVar18 != (undefined8 *)0x0) {
    (**(code **)(puVar18[-2] + 8))(puVar18 + -2);
  }
  return;
}

