BLOCK-ID-CANDIDATE 27 1400b41ad FUN_1400b4140
BLOCK-ID-CANDIDATE 27 1400e9acd FUN_1400e9a00
BLOCK-ID-CANDIDATE 27 140112f0d FUN_140112a60
BLOCK-ID-CANDIDATE 27 14016317f FUN_140162f00
BLOCK-ID-CANDIDATE 27 140271ed0 FUN_140271dd0
BLOCK-ID-CANDIDATE 27 140272039 FUN_140271f20
BLOCK-ID-CANDIDATE 27 1402721ab FUN_140271f20
BLOCK-ID-CANDIDATE 27 140273edc FUN_140273760
BLOCK-ID-CANDIDATE 27 1402e77da FUN_1402e76e0
BLOCK-ID-CANDIDATE 27 1402e7b8f FUN_1402e76e0
BLOCK-ID-CANDIDATE 27 1403c1bc5 FUN_1403c17d0
BLOCK-ID-CANDIDATE 27 140432f9b FUN_140432f20
BLOCK-ID-CANDIDATE 27 140474283 FUN_1404739b0
BLOCK-ID-CANDIDATE 27 1404daaf9 FUN_1404daac0
BLOCK-ID-CANDIDATE 27 1404dadbb FUN_1404dad90
BLOCK-ID-CANDIDATE 27 14050f432 FUN_14050f270
BLOCK-ID-CANDIDATE 27 14050f5a3 FUN_14050f270
BLOCK-ID-CANDIDATE 27 140513acd FUN_140513900
BLOCK-ID-CANDIDATE 27 1405514f7 FUN_1405512f0
BLOCK-ID-CANDIDATE 27 1406627d1 FUN_1406625d0
BLOCK-ID-CANDIDATE 27 140662dde FUN_1406625d0
BLOCK-ID-CANDIDATE 27 14066a608 FUN_14066a570
BLOCK-ID-CANDIDATE 27 14066ca1c FUN_14066c710
BLOCK-ID-CANDIDATE 27 14067a4c6 FUN_140679e50
BLOCK-ID-CANDIDATE 27 14067b048 FUN_140679e50
BLOCK-ID-CANDIDATE 27 140688434 FUN_140687d40
BLOCK-ID-CANDIDATE 27 1406a4839 FUN_1406a47d0
BLOCK-ID-CANDIDATE 27 1406a4958 FUN_1406a48d0
BLOCK-ID-CANDIDATE 27 1406f2837 FUN_1406f26c0
BLOCK-ID-CANDIDATE 27 14070acdf FUN_140709460
BLOCK-ID-CANDIDATE 27 14070b83f FUN_140709460
BLOCK-ID-CANDIDATE 27 14072fdb8 FUN_14072fae0
BLOCK-ID-CANDIDATE 27 14073025d FUN_14072fae0
BLOCK-ID-CANDIDATE 27 1407304de FUN_14072fae0
BLOCK-ID-CANDIDATE 27 14074c3b0 FUN_14074be90
BLOCK-ID-CANDIDATE 27 14074c697 FUN_14074be90
BLOCK-ID-CANDIDATE 27 14074c92c FUN_14074be90
BLOCK-ID-CANDIDATE 27 14074ff2c FUN_14074ff00
BLOCK-ID-CANDIDATE 27 140750796 FUN_140750220
BLOCK-ID-CANDIDATE 27 140750898 FUN_140750220
BLOCK-ID-CANDIDATE 27 140757d5a FUN_140757c50
BLOCK-ID-CANDIDATE 27 140761622 FUN_140761170
BLOCK-ID-CANDIDATE 27 1409201bc FUN_14091f420
BLOCK-ID-CANDIDATE 27 14092043f FUN_14091f420
BLOCK-ID-CANDIDATE 27 140924091 FUN_140923e20
BLOCK-ID-CANDIDATE 27 140930216 FUN_140930010

==== FUN_1400b4140 @ 1400b4140 ====

void FUN_1400b4140(longlong param_1,longlong *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_res8;
  
  pvVar2 = StackBase;
  uVar1 = *(undefined4 *)((longlong)StackBase + -4);
  *(undefined4 *)((longlong)StackBase + -4) = 1;
  if (*(longlong *)(param_1 + 0x110) == 0) goto LAB_1400b41ff;
  iVar3 = (**(code **)(*param_2 + 0x10))(param_2);
  if (iVar3 == 0) {
    uVar4 = 0x1e;
  }
  else if (iVar3 == 10) {
LAB_1400b41e6:
    uVar4 = 0x1c;
  }
  else {
    if (iVar3 != 0xbc2) {
      if (0xcfe < iVar3) {
        if (iVar3 < 0xd01) goto LAB_1400b41e6;
        if (iVar3 == 0xd01) {
          uVar4 = 0x1b;
          goto LAB_1400b41f2;
        }
      }
      FUN_1400b2700(param_1);
      local_res8 = 0x141d0e0c0;
      FUN_1401a3130(0x5f,0,&local_res8,iVar3);
      goto LAB_1400b41ff;
    }
    uVar4 = 0x1d;
  }
LAB_1400b41f2:
  FUN_1400b23b0(param_1,uVar4);
LAB_1400b41ff:
  *(undefined4 *)((longlong)pvVar2 + -4) = uVar1;
  return;
}



==== FUN_1400e9a00 @ 1400e9a00 ====

void FUN_1400e9a00(longlong param_1)

{
  size_t _Size;
  undefined8 uVar1;
  size_t sVar2;
  void *_Dst;
  undefined1 *_Src;
  
  if (*(longlong **)(param_1 + 0xd38) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xd38) + 0x168))();
    _Src = &DAT_140b7b700;
    if (*(undefined1 **)(param_1 + 0xd70) != (undefined1 *)0x0) {
      _Src = *(undefined1 **)(param_1 + 0xd70);
    }
    _Dst = (void *)0x0;
    _Size = 0xffffffffffffffff;
    do {
      sVar2 = _Size;
      _Size = sVar2 + 1;
    } while (_Src[sVar2 + 1] != '\0');
    if (sVar2 + 2 != -1) {
      _Dst = (void *)FUN_14018b280(sVar2 + 2,0);
    }
    memcpy(_Dst,_Src,_Size);
    if ((undefined1 *)(_Size + (longlong)_Dst) != (undefined1 *)0x0) {
      *(undefined1 *)(_Size + (longlong)_Dst) = 0;
    }
    uVar1 = *(undefined8 *)(param_1 + 0xda0);
    FUN_1400e1580(param_1 + 0xd28);
    FUN_1400eaa10(param_1,0x1b,&DAT_1409d3b4c,_Dst,uVar1);
    if (_Dst != (void *)0x0) {
      FUN_14018b900(_Dst,0);
    }
  }
  return;
}



==== FUN_140112a60 @ 140112a60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140112a60(longlong *param_1,ulonglong param_2,ulonglong param_3,undefined8 param_4,
                  char *param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  float *pfVar8;
  undefined8 uVar9;
  ushort uVar10;
  uint uVar11;
  ulonglong uVar12;
  float fVar13;
  float fVar14;
  undefined1 local_88 [16];
  undefined1 local_78 [96];
  
  pcVar5 = param_5;
  uVar11 = (uint)param_2;
  uVar12 = param_2 & 0xffffffff;
  if (*param_5 != '\0') {
    FUN_1400d1af0(param_1,param_2,param_3,param_4,param_5);
    return;
  }
  lVar1 = param_1[4];
  if ((lVar1 == 0) || (*(longlong **)(lVar1 + 0xb40) != param_1)) {
    uVar7 = (uint)((ulonglong)param_4 >> 0x10);
    if ((uVar11 == 0x102) &&
       ((((param_3 == 0xd && (((uVar7 & 0x1ff) - 0x1c & 0xfffffeff) == 0)) &&
         (*(longlong *)(lVar1 + 0xb40) == 0)) && ((*(byte *)(param_1 + 0x53) >> 2 & 1) != 0)))) {
      FUN_1400e8c50(lVar1,param_1);
      *pcVar5 = '\x01';
      return;
    }
    uVar7 = uVar7 & 0x1ff;
    if (uVar7 == 0x11c) {
      uVar7 = 0x1c;
    }
    if (((uVar11 == 0x102) && (uVar7 == 0x35)) &&
       ((*(longlong *)(lVar1 + 0xb40) == 0 && ((*(byte *)(param_1 + 0x53) >> 2 & 1) != 0)))) {
      FUN_1400e8c50(lVar1,param_1);
      FUN_14010f120(param_1,0x2f);
      goto switchD_140112c76_caseD_12;
    }
LAB_140113045:
    FUN_1400d1af0(param_1,uVar12,param_3,param_4,pcVar5);
  }
  else {
    param_5._0_4_ = 0;
    if (((0x1ff < uVar11) &&
        (cVar6 = FUN_1400e6570(lVar1,param_2,param_3,&param_5,local_88), fVar4 = _UNK_140b7a494,
        fVar3 = _DAT_140b7a490, cVar6 != '\0')) &&
       (((int)param_5 == 1 && ((*(uint *)(param_1 + 0x53) >> 10 & 1) != 0)))) {
      fVar13 = (float)**(int **)(lVar1 + 0xb10);
      fVar14 = (float)(*(int **)(lVar1 + 0xb10))[1];
      pfVar8 = (float *)FUN_1400c96c0(param_1,local_78);
      param_5._0_4_ = (int)(fVar3 + fVar14 * pfVar8[4] + fVar13 * *pfVar8 + pfVar8[0xc]);
      param_5._4_4_ = (int)(fVar4 + fVar14 * pfVar8[5] + fVar13 * pfVar8[1] + pfVar8[0xd]);
      cVar6 = FUN_140001d30(param_1,&param_5);
      if (((cVar6 == '\0') && (param_1[4] != 0)) && (*(longlong **)(param_1[4] + 0xb40) == param_1))
      {
        FUN_1400e8bf0();
      }
    }
    uVar2 = param_1[0x53];
    if ((((uVar2 >> 0xb & 1) != 0) &&
        ((uVar10 = *(ushort *)(DAT_140c63650 + 0xe0) & 0x3ff, uVar10 == 4 ||
         ((ushort)(uVar10 - 0x11) < 2)))) && (uVar11 - 0x10d < 3)) {
      FUN_140113f60(param_1);
      *pcVar5 = uVar11 - 0x10d < 2;
      return;
    }
    if (uVar11 != 0x100) {
      if (uVar11 == 0x101) {
        if (param_3 == 0x10) {
          *(undefined1 *)((longlong)param_1 + 0x431) = 0;
LAB_140112e8c:
          *pcVar5 = '\x01';
          return;
        }
        if (param_3 == 0x11) {
          *(undefined1 *)((longlong)param_1 + 0x432) = 0;
          *pcVar5 = '\x01';
          return;
        }
        if (param_3 != 0xc0) goto LAB_140112e8c;
        param_3 = 0xc0;
      }
      else if (uVar11 == 0x102) {
        if (param_3 == 8) {
          FUN_1401119a0(param_1);
          *pcVar5 = '\x01';
          return;
        }
        if (param_3 == 9) {
          if (((byte)uVar2 >> 4 & 1) != 0) {
            uVar9 = (**(code **)(*(longlong *)param_1[0x87] + 0x40))();
            FUN_1400d4070(param_1,0x29,param_1,&DAT_1409d5b0c,uVar9);
            *pcVar5 = '\x01';
            return;
          }
          uVar12 = 0x102;
          param_3 = 9;
        }
        else {
          if (param_3 == 0xd) {
            if ((uVar2 & 1) != 0) {
              FUN_14010f120(param_1,10);
              *pcVar5 = '\x01';
              return;
            }
            FUN_140111030(param_1);
            *pcVar5 = '\x01';
            return;
          }
          if (param_3 == 0x1b) {
            uVar12 = 0x102;
            param_3 = 0x1b;
          }
          else {
            if (param_3 != 0x60) {
              cVar6 = FUN_140112950(param_1,uVar2,param_3);
              if ((cVar6 == '\0') && (0x1f < (ushort)param_3)) {
                FUN_14010f120(param_1,param_3 & 0xffff);
                *pcVar5 = '\x01';
                return;
              }
              goto switchD_140112c76_caseD_12;
            }
            uVar12 = 0x102;
            param_3 = 0x60;
          }
        }
      }
      goto LAB_140113045;
    }
    switch(param_3) {
    case 0x10:
      *(undefined1 *)((longlong)param_1 + 0x431) = 1;
      *pcVar5 = '\x01';
      break;
    case 0x11:
      *(undefined1 *)((longlong)param_1 + 0x432) = 1;
      *pcVar5 = '\x01';
      break;
    case 0x1b:
      FUN_1400d4070(param_1,0x2a,param_1,&DAT_1409d04a3);
      if ((*(uint *)(param_1 + 0x53) >> 8 & 1) != 0) {
        (**(code **)(*param_1 + 0x50))(param_1,&DAT_1409d5af4);
      }
      if ((param_1[4] != 0) && (*(longlong **)(param_1[4] + 0xb40) == param_1)) {
        FUN_1400e8bf0();
        *pcVar5 = '\x01';
        return;
      }
    default:
switchD_140112c76_caseD_12:
      *pcVar5 = '\x01';
      break;
    case 0x23:
      FUN_140111890(param_1);
      *pcVar5 = '\x01';
      break;
    case 0x24:
      FUN_1401117d0(param_1);
      *pcVar5 = '\x01';
      break;
    case 0x25:
      lVar1 = *(longlong *)param_1[0x87];
      if (*(char *)((longlong)param_1 + 0x432) == '\0') {
        (**(code **)(lVar1 + 0xc0))((longlong *)param_1[0x87],param_1[0x80],&param_5);
        FUN_1401116a0(param_1,CONCAT44(param_5._4_4_,(int)param_5));
        *pcVar5 = '\x01';
      }
      else {
        (**(code **)(lVar1 + 0xd0))();
        FUN_1401116a0(param_1,CONCAT44(param_5._4_4_,(int)param_5));
        *pcVar5 = '\x01';
      }
      break;
    case 0x26:
      FUN_1401110b0(param_1);
      *pcVar5 = '\x01';
      break;
    case 0x27:
      lVar1 = *(longlong *)param_1[0x87];
      if (*(char *)((longlong)param_1 + 0x432) == '\0') {
        (**(code **)(lVar1 + 0xb8))((longlong *)param_1[0x87],param_1[0x80],&param_5);
        FUN_1401115f0(param_1,CONCAT44(param_5._4_4_,(int)param_5));
        *pcVar5 = '\x01';
      }
      else {
        (**(code **)(lVar1 + 200))();
        FUN_1401115f0(param_1,CONCAT44(param_5._4_4_,(int)param_5));
        *pcVar5 = '\x01';
      }
      break;
    case 0x28:
      FUN_1401113a0(param_1);
      *pcVar5 = '\x01';
      break;
    case 0x2d:
      if (*(char *)((longlong)param_1 + 0x431) == '\0') {
        *(bool *)(param_1 + 0x86) = (char)param_1[0x86] == '\0';
        *pcVar5 = '\x01';
      }
      else {
        FUN_140111d60(param_1);
        *pcVar5 = '\x01';
      }
      break;
    case 0x2e:
      if (*(char *)((longlong)param_1 + 0x431) == '\0') {
        FUN_140111b80(param_1);
        *pcVar5 = '\x01';
      }
      else {
        FUN_140111fd0();
        *pcVar5 = '\x01';
      }
      break;
    case 0xc0:
      uVar12 = 0x100;
      goto LAB_140113045;
    }
  }
  return;
}



==== FUN_140162f00 @ 140162f00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140162f00(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                  char *param_5)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  char *pcVar4;
  char cVar5;
  float *pfVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  undefined1 local_88 [16];
  undefined1 local_78 [96];
  
  pcVar4 = param_5;
  if (*param_5 != '\0') {
    FUN_1400d1af0(param_1,param_2,param_3,param_4,param_5);
    return;
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  if ((lVar1 == 0) || (*(longlong *)(lVar1 + 0xb40) != param_1)) goto LAB_14016305a;
  if ((0x1ff < (uint)param_2) &&
     ((cVar5 = FUN_1400e6570(lVar1,param_2,param_3,local_88,&param_5), fVar3 = _UNK_140b7a494,
      fVar2 = _DAT_140b7a490, cVar5 != '\0' && ((int)param_2 == 1)))) {
    fVar8 = (float)**(int **)(lVar1 + 0xb10);
    fVar9 = (float)(*(int **)(lVar1 + 0xb10))[1];
    pfVar6 = (float *)FUN_1400c96c0(param_1,local_78);
    param_5._0_4_ = (int)(fVar2 + fVar9 * pfVar6[4] + fVar8 * *pfVar6 + pfVar6[0xc]);
    param_5._4_4_ = (int)(fVar3 + fVar9 * pfVar6[5] + fVar8 * pfVar6[1] + pfVar6[0xd]);
    cVar5 = FUN_140001d30(param_1,&param_5);
    if ((cVar5 == '\0') &&
       ((*(longlong *)(param_1 + 0x20) != 0 &&
        (*(longlong *)(*(longlong *)(param_1 + 0x20) + 0xb40) == param_1)))) {
      FUN_1400e8bf0();
    }
    goto LAB_14016305a;
  }
  iVar7 = (int)param_2;
  if (iVar7 != 0x100) {
    if (iVar7 == 0x101) {
      if (param_3 != 0xc0) goto switchD_1401630bd_caseD_1c;
    }
    else if ((((iVar7 == 0x102) && (param_3 != 9)) && (param_3 != 0xd)) &&
            ((param_3 != 0x1b && (param_3 != 0x60)))) goto switchD_1401630bd_caseD_1c;
    goto LAB_14016305a;
  }
  switch(param_3) {
  case 0x1b:
    FUN_1400e8bf0(lVar1);
    *pcVar4 = '\x01';
    goto LAB_14016305a;
  default:
    goto switchD_1401630bd_caseD_1c;
  case 0x23:
    FUN_140162e10(param_1);
    *pcVar4 = '\x01';
    break;
  case 0x24:
    FUN_140162d20(param_1);
    *pcVar4 = '\x01';
    break;
  case 0x25:
    FUN_140162b40(param_1);
    *pcVar4 = '\x01';
    break;
  case 0x26:
    FUN_140162980(param_1);
    *pcVar4 = '\x01';
    break;
  case 0x27:
    FUN_140162c30(param_1);
    *pcVar4 = '\x01';
    break;
  case 0x28:
    FUN_140162a60(param_1);
    goto switchD_1401630bd_caseD_1c;
  case 0xc0:
LAB_14016305a:
    FUN_1400d1af0(param_1);
  }
  return;
switchD_1401630bd_caseD_1c:
  *pcVar4 = '\x01';
  return;
}



==== FUN_140271dd0 @ 140271dd0 ====

void FUN_140271dd0(longlong param_1,int param_2,int param_3,int param_4)

{
  longlong *plVar1;
  undefined4 uVar2;
  
  if (((param_2 == 1) && (param_3 == 0)) && (param_4 == 0)) {
    if (*(int *)(param_1 + 0x1eb0) == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1eb0) = 0;
    plVar1 = *(longlong **)(param_1 + 0x19d0);
    uVar2 = 0x1b;
  }
  else {
    if (*(int *)(param_1 + 0x1e90) != *(int *)(&DAT_140ae7cc8 + (longlong)param_2 * 4)) {
      *(int *)(param_1 + 0x1e90) = *(int *)(&DAT_140ae7cc8 + (longlong)param_2 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x13);
    }
    if (*(int *)(param_1 + 0x1e94) != *(int *)(&DAT_140ae7cc8 + (longlong)param_3 * 4)) {
      *(int *)(param_1 + 0x1e94) = *(int *)(&DAT_140ae7cc8 + (longlong)param_3 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x14);
    }
    if (*(int *)(param_1 + 0x20f0) != *(int *)(&DAT_140ae7cf0 + (longlong)param_4 * 4)) {
      *(int *)(param_1 + 0x20f0) = *(int *)(&DAT_140ae7cf0 + (longlong)param_4 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0xab);
    }
    if (*(int *)(param_1 + 0x1eb0) != 1) {
      *(undefined4 *)(param_1 + 0x1eb0) = 1;
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x1b,1);
    }
    if (*(int *)(param_1 + 0x217c) == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x217c) = 0;
    plVar1 = *(longlong **)(param_1 + 0x19d0);
    uVar2 = 0xce;
  }
  (**(code **)(*plVar1 + 0x1c8))(plVar1,uVar2,0);
  return;
}



==== FUN_140271f20 @ 140271f20 ====

void FUN_140271f20(longlong param_1,int param_2,undefined8 param_3,int param_4,int param_5,
                  int param_6,int param_7)

{
  longlong *plVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = (int)param_3;
  if (((param_5 == param_2) && (param_6 == iVar3)) && (param_7 == param_4)) {
    if (((param_2 == 1) && (iVar3 == 0)) && (param_4 == 0)) {
      if (*(int *)(param_1 + 0x1eb0) == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x1eb0) = 0;
      plVar1 = *(longlong **)(param_1 + 0x19d0);
      uVar2 = 0x1b;
      goto LAB_1402721e2;
    }
    if (*(int *)(param_1 + 0x1e90) != *(int *)(&DAT_140ae7cc8 + (longlong)param_2 * 4)) {
      *(int *)(param_1 + 0x1e90) = *(int *)(&DAT_140ae7cc8 + (longlong)param_2 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x13);
    }
    if (*(int *)(param_1 + 0x1e94) != *(int *)(&DAT_140ae7cc8 + (longlong)iVar3 * 4)) {
      *(int *)(param_1 + 0x1e94) = *(int *)(&DAT_140ae7cc8 + (longlong)iVar3 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x14);
    }
    if (*(int *)(param_1 + 0x20f0) != *(int *)(&DAT_140ae7cf0 + (longlong)param_4 * 4)) {
      *(int *)(param_1 + 0x20f0) = *(int *)(&DAT_140ae7cf0 + (longlong)param_4 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0xab);
    }
    if (*(int *)(param_1 + 0x1eb0) != 1) {
      *(undefined4 *)(param_1 + 0x1eb0) = 1;
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x1b,1);
    }
    if (*(int *)(param_1 + 0x217c) == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x217c) = 0;
    param_3 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1e90) != *(int *)(&DAT_140ae7cc8 + (longlong)param_2 * 4)) {
      *(int *)(param_1 + 0x1e90) = *(int *)(&DAT_140ae7cc8 + (longlong)param_2 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x13);
    }
    if (*(int *)(param_1 + 0x1e94) != *(int *)(&DAT_140ae7cc8 + (longlong)iVar3 * 4)) {
      *(int *)(param_1 + 0x1e94) = *(int *)(&DAT_140ae7cc8 + (longlong)iVar3 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x14);
    }
    if (*(int *)(param_1 + 0x20f0) != *(int *)(&DAT_140ae7cf0 + (longlong)param_4 * 4)) {
      *(int *)(param_1 + 0x20f0) = *(int *)(&DAT_140ae7cf0 + (longlong)param_4 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0xab);
    }
    if (*(int *)(param_1 + 0x2180) != *(int *)(&DAT_140ae7cc8 + (longlong)param_5 * 4)) {
      *(int *)(param_1 + 0x2180) = *(int *)(&DAT_140ae7cc8 + (longlong)param_5 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0xcf);
    }
    if (*(int *)(param_1 + 0x2184) != *(int *)(&DAT_140ae7cc8 + (longlong)param_6 * 4)) {
      *(int *)(param_1 + 0x2184) = *(int *)(&DAT_140ae7cc8 + (longlong)param_6 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0xd0);
    }
    if (*(int *)(param_1 + 0x2188) != *(int *)(&DAT_140ae7cf0 + (longlong)param_7 * 4)) {
      *(int *)(param_1 + 0x2188) = *(int *)(&DAT_140ae7cf0 + (longlong)param_7 * 4);
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0xd1);
    }
    if (*(int *)(param_1 + 0x1eb0) != 1) {
      *(undefined4 *)(param_1 + 0x1eb0) = 1;
      (**(code **)(**(longlong **)(param_1 + 0x19d0) + 0x1c8))
                (*(longlong **)(param_1 + 0x19d0),0x1b,1);
    }
    if (*(int *)(param_1 + 0x217c) == 1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x217c) = 1;
    param_3 = 1;
  }
  plVar1 = *(longlong **)(param_1 + 0x19d0);
  uVar2 = 0xce;
LAB_1402721e2:
  (**(code **)(*plVar1 + 0x1c8))(plVar1,uVar2,param_3);
  return;
}



==== FUN_140273760 @ 140273760 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140273760(longlong *param_1,ulonglong param_2,undefined1 (*param_3) [16],undefined4 param_4
                  ,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  char cVar10;
  undefined6 uVar14;
  undefined8 uVar15;
  unkbyte10 Var16;
  undefined1 auVar17 [12];
  undefined1 auVar18 [14];
  short sVar19;
  int in_EAX;
  int iVar20;
  longlong lVar21;
  longlong *plVar22;
  uint uVar23;
  longlong lVar24;
  longlong lVar25;
  uint *puVar26;
  bool bVar27;
  bool bVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  char cVar32;
  char cVar33;
  char cVar34;
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined4 uVar37;
  undefined8 in_stack_ffffffffffffff78;
  uint uVar38;
  undefined4 local_60 [10];
  char cVar11;
  char cVar12;
  char cVar13;
  
  uVar38 = (uint)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  bVar28 = false;
  lVar24 = 4;
  if ((param_2 & 1) != 0) {
    plVar22 = param_1 + 0x3af;
    puVar26 = (uint *)(param_1 + 0x3b5);
    lVar25 = 4;
    do {
      uVar23 = puVar26[-0x10];
      if (uVar23 == 0) {
        in_EAX = (int)param_1[0x1e];
        if (*plVar22 == 0) {
          if ((int)param_1[0x3be] != in_EAX) {
            bVar28 = true;
          }
        }
        else if (*(int *)(*plVar22 + 0x58) != in_EAX) {
          bVar28 = true;
        }
      }
      else if (uVar23 == 1) {
        lVar21 = *plVar22;
        if ((lVar21 != 0) && (*(int *)(lVar21 + 0x34) == 5)) {
          uVar23 = *puVar26;
          goto LAB_1402737ec;
        }
      }
      else if (((uVar23 == 2) && (lVar21 = *plVar22, lVar21 != 0)) && (*(int *)(lVar21 + 0x34) == 5)
              ) {
        uVar23 = *(int *)(lVar21 + 0x2c) * puVar26[-4] + *puVar26;
LAB_1402737ec:
        in_EAX = (int)param_1[0x1e];
        if (*(int *)(*(longlong *)(lVar21 + 0x98) + (ulonglong)uVar23 * 4) != in_EAX) {
          bVar28 = true;
        }
      }
      puVar26 = puVar26 + 1;
      plVar22 = plVar22 + 1;
      lVar25 = lVar25 + -1;
    } while (lVar25 != 0);
  }
  if ((param_1[0x3c4] == 0) || ((param_2 & 6) == 0)) goto LAB_1402738cb;
  iVar20 = *(int *)((longlong)param_1 + 0x1e04);
  if (iVar20 == 0) {
    in_EAX = (int)param_1[0x1e];
    if (param_1[0x3c1] == 0) {
      bVar27 = (int)param_1[0x3c6] == in_EAX;
    }
    else {
      bVar27 = *(int *)(param_1[0x3c1] + 0x68) == in_EAX;
    }
LAB_1402738c9:
    if (bVar27) goto LAB_1402738cb;
LAB_1402738d4:
    if ((param_2 & 1) != 0) {
      plVar22 = param_1 + 0x3af;
      puVar26 = (uint *)(param_1 + 0x3b5);
      do {
        uVar23 = puVar26[-0x10];
        if (uVar23 == 0) {
          in_EAX = (int)param_1[0x1e];
          if (*plVar22 == 0) {
            *(int *)(param_1 + 0x3be) = in_EAX;
          }
          else {
            *(int *)(*plVar22 + 0x58) = in_EAX;
          }
        }
        else if (uVar23 == 1) {
          lVar25 = *plVar22;
          if (lVar25 != 0) {
            uVar23 = *puVar26;
            goto LAB_140273920;
          }
        }
        else if ((uVar23 == 2) && (lVar25 = *plVar22, lVar25 != 0)) {
          uVar23 = *(int *)(lVar25 + 0x2c) * puVar26[-4] + *puVar26;
LAB_140273920:
          in_EAX = (int)param_1[0x1e];
          *(int *)(*(longlong *)(lVar25 + 0x98) + (ulonglong)uVar23 * 4) = in_EAX;
        }
        puVar26 = puVar26 + 1;
        plVar22 = plVar22 + 1;
        lVar24 = lVar24 + -1;
      } while (lVar24 != 0);
      *(undefined4 *)(param_1 + 0x3c0) = 0;
    }
    if ((param_1[0x3c4] != 0) && ((param_2 & 6) != 0)) {
      iVar20 = *(int *)((longlong)param_1 + 0x1e04);
      if (iVar20 == 0) {
        in_EAX = (int)param_1[0x1e];
        if (param_1[0x3c1] == 0) {
          *(int *)(param_1 + 0x3c6) = in_EAX;
          goto LAB_1402739f5;
        }
        *(int *)(param_1[0x3c1] + 0x68) = in_EAX;
        *(undefined4 *)(param_1 + 0x3c8) = 0;
      }
      else {
        if (iVar20 == 1) {
          lVar24 = param_1[0x3c1];
          if (lVar24 == 0) goto LAB_1402739f5;
          uVar23 = *(uint *)((longlong)param_1 + 0x1e14);
        }
        else {
          if ((iVar20 != 2) || (lVar24 = param_1[0x3c1], lVar24 == 0)) {
LAB_1402739f5:
            *(undefined4 *)(param_1 + 0x3c8) = 0;
            goto LAB_140273a25;
          }
          uVar23 = (int)param_1[0x3c2] * *(int *)(lVar24 + 0x2c) +
                   *(int *)((longlong)param_1 + 0x1e14);
        }
        in_EAX = (int)param_1[0x1e];
        *(int *)(*(longlong *)(lVar24 + 0x98) + (ulonglong)uVar23 * 4) = in_EAX;
        *(undefined4 *)(param_1 + 0x3c8) = 0;
      }
    }
  }
  else {
    if (iVar20 == 1) {
      lVar25 = param_1[0x3c1];
      if ((lVar25 != 0) && (*(int *)(lVar25 + 0x34) == 5)) {
        uVar23 = *(uint *)((longlong)param_1 + 0x1e14);
        goto LAB_140273880;
      }
    }
    else if (((iVar20 == 2) && (lVar25 = param_1[0x3c1], lVar25 != 0)) &&
            (*(int *)(lVar25 + 0x34) == 5)) {
      uVar23 = (int)param_1[0x3c2] * *(int *)(lVar25 + 0x2c) + *(int *)((longlong)param_1 + 0x1e14);
LAB_140273880:
      in_EAX = (int)param_1[0x1e];
      bVar27 = *(int *)(*(longlong *)(lVar25 + 0x98) + (ulonglong)uVar23 * 4) == in_EAX;
      goto LAB_1402738c9;
    }
LAB_1402738cb:
    if (bVar28) goto LAB_1402738d4;
    if ((int)param_1[0x517] != 0) {
      in_EAX = (**(code **)(*(longlong *)param_1[0x33a] + 0x178))
                         ((longlong *)param_1[0x33a],param_1 + 0x514);
      *(undefined4 *)(param_1 + 0x517) = 0;
    }
  }
LAB_140273a25:
  bVar28 = (param_2 & 1) != 0;
  uVar23 = (uint)bVar28;
  if (param_1[0x3c4] != 0) {
    if ((param_2 & 2) != 0) {
      uVar23 = bVar28 | 2;
    }
    if ((param_2 & 4) != 0) {
      in_EAX = (int)param_1[0x3c3];
      uVar23 = uVar23 | *(uint *)(&DAT_140ae7ba0 + (longlong)in_EAX * 4) & 4;
    }
  }
  if ((uVar23 & 1) == 0) {
    if ((uVar23 & 6) == 0) goto LAB_140273f5d;
    plVar22 = (longlong *)param_1[0x33a];
    lVar24 = *plVar22;
    uVar37 = 0;
  }
  else {
    plVar22 = (longlong *)param_1[0x33a];
    lVar24 = *plVar22;
    auVar35 = maxps(ZEXT816(0),*param_3);
    auVar36 = minps(auVar35,_DAT_140b7b240);
    auVar35._4_4_ = -(uint)(auVar36._4_4_ != *(float *)(*param_3 + 4));
    auVar35._0_4_ = -(uint)(auVar36._0_4_ != *(float *)*param_3);
    auVar35._8_4_ = -(uint)(auVar36._8_4_ != *(float *)(*param_3 + 8));
    auVar35._12_4_ = -(uint)(auVar36._12_4_ != *(float *)(*param_3 + 0xc));
    iVar20 = movmskps(in_EAX,auVar35);
    if (iVar20 != 0) {
      (**(code **)(lVar24 + 0x158))(plVar22,0,0,uVar23,(ulonglong)uVar38 << 0x20,param_4,param_5);
      if (param_1[0x36e] == 0) {
        iVar20 = (**(code **)(*param_1 + 0x98))(param_1,L"Shaders\\DefaultPS.sho",param_1 + 0x36e);
        if (iVar20 < 0) {
          return;
        }
        local_60[0] = 0xffffffff;
        (**(code **)(*(longlong *)param_1[0x36e] + 0x20))((longlong *)param_1[0x36e],local_60);
      }
      iVar20 = *(int *)((longlong)param_1 + 0x1e9c);
      iVar29 = *(int *)((longlong)param_1 + 0x213c);
      iVar30 = (int)param_1[0x428];
      iVar31 = *(int *)((longlong)param_1 + 0x2144);
      iVar1 = (int)param_1[0x3d6];
      lVar24 = param_1[0x4e7];
      iVar2 = *(int *)((longlong)param_1 + 0x1e64);
      iVar3 = (int)param_1[0x3cc];
      iVar4 = *(int *)((longlong)param_1 + 0x20e4);
      iVar5 = *(int *)((longlong)param_1 + 0x1f14);
      if (*(int *)((longlong)param_1 + 0x1e9c) != 1) {
        *(undefined4 *)((longlong)param_1 + 0x1e9c) = 1;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0x16,1);
      }
      if (*(int *)((longlong)param_1 + 0x1e64) != 3) {
        *(undefined4 *)((longlong)param_1 + 0x1e64) = 3;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],8,3);
      }
      if ((int)param_1[0x3cc] != 0) {
        *(undefined4 *)(param_1 + 0x3cc) = 0;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],7);
      }
      if (*(int *)((longlong)param_1 + 0x1f14) != 0) {
        *(undefined4 *)((longlong)param_1 + 0x1f14) = 0;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0x34);
      }
      if (*(int *)((longlong)param_1 + 0x20e4) != 0xf) {
        *(undefined4 *)((longlong)param_1 + 0x20e4) = 0xf;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xa8,0xf);
      }
      if (*(int *)((longlong)param_1 + 0x213c) != 0xf) {
        *(undefined4 *)((longlong)param_1 + 0x213c) = 0xf;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xbe,0xf);
      }
      if ((int)param_1[0x428] != 0xf) {
        *(undefined4 *)(param_1 + 0x428) = 0xf;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xbf,0xf);
      }
      if (*(int *)((longlong)param_1 + 0x2144) != 0xf) {
        *(undefined4 *)((longlong)param_1 + 0x2144) = 0xf;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xc0,0xf);
      }
      if ((int)param_1[0x3d6] != 0) {
        *(undefined4 *)(param_1 + 0x3d6) = 0;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0x1b);
      }
      (**(code **)(*param_1 + 0x178))(param_1,param_1[0x36e],0);
      (**(code **)(*(longlong *)param_1[0x33a] + 0x368))((longlong *)param_1[0x33a],0,param_3,1);
      (**(code **)(*param_1 + 0x298))(param_1,0xffffffff);
      if (*(int *)((longlong)param_1 + 0x1e9c) != iVar20) {
        *(int *)((longlong)param_1 + 0x1e9c) = iVar20;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0x16,iVar20);
      }
      if (*(int *)((longlong)param_1 + 0x1e64) != iVar2) {
        *(int *)((longlong)param_1 + 0x1e64) = iVar2;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],8,iVar2);
      }
      if ((int)param_1[0x3cc] != iVar3) {
        *(int *)(param_1 + 0x3cc) = iVar3;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],7,iVar3);
      }
      if (*(int *)((longlong)param_1 + 0x1f14) != iVar5) {
        *(int *)((longlong)param_1 + 0x1f14) = iVar5;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0x34,iVar5);
      }
      if (*(int *)((longlong)param_1 + 0x20e4) != iVar4) {
        *(int *)((longlong)param_1 + 0x20e4) = iVar4;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xa8,iVar4);
      }
      if (*(int *)((longlong)param_1 + 0x213c) != iVar29) {
        *(int *)((longlong)param_1 + 0x213c) = iVar29;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xbe,iVar29);
      }
      if ((int)param_1[0x428] != iVar30) {
        *(int *)(param_1 + 0x428) = iVar30;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xbf,iVar30);
      }
      if (*(int *)((longlong)param_1 + 0x2144) != iVar31) {
        *(int *)((longlong)param_1 + 0x2144) = iVar31;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0xc0,iVar31);
      }
      if ((int)param_1[0x3d6] != iVar1) {
        *(int *)(param_1 + 0x3d6) = iVar1;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x1c8))((longlong *)param_1[0x33a],0x1b,iVar1);
      }
      if (param_1[0x4e7] != lVar24) {
        param_1[0x4e7] = lVar24;
        (**(code **)(*(longlong *)param_1[0x33a] + 0x358))((longlong *)param_1[0x33a],lVar24);
      }
      (**(code **)(*(longlong *)param_1[0x33a] + 0x368))
                ((longlong *)param_1[0x33a],0,param_1[0x37f],1);
      goto LAB_140273f5d;
    }
    iVar20 = (int)(_DAT_140b7b470 * auVar36._0_4_ + _DAT_140b7ac50);
    iVar29 = (int)(_UNK_140b7b474 * auVar36._4_4_ + _UNK_140b7ac54);
    iVar30 = (int)(_UNK_140b7b478 * auVar36._8_4_ + _UNK_140b7ac58);
    iVar31 = (int)(_UNK_140b7b47c * auVar36._12_4_ + _UNK_140b7ac5c);
    cVar32 = (char)((uint)iVar29 >> 0x10);
    cVar33 = (char)((uint)iVar20 >> 0x10);
    cVar34 = (char)((uint)iVar31 >> 0x10);
    uVar14 = CONCAT15((char)((uint)iVar29 >> 8),CONCAT14((char)iVar29,iVar30));
    uVar15 = CONCAT17((char)((uint)iVar29 >> 0x18),CONCAT16(cVar32,uVar14));
    Var16 = CONCAT19((char)((uint)iVar20 >> 8),CONCAT18((char)iVar20,uVar15));
    auVar17[10] = cVar33;
    auVar17._0_10_ = Var16;
    auVar17[0xb] = (char)((uint)iVar20 >> 0x18);
    auVar18[0xc] = (char)iVar31;
    auVar18._0_12_ = auVar17;
    auVar18[0xd] = (char)((uint)iVar31 >> 8);
    auVar36[0xe] = cVar34;
    auVar36._0_14_ = auVar18;
    auVar36[0xf] = (char)((uint)iVar31 >> 0x18);
    sVar6 = (short)iVar30;
    cVar10 = (0 < sVar6) * (sVar6 < 0x100) * (char)iVar30 - (0xff < sVar6);
    sVar6 = (short)((uint)iVar30 >> 0x10);
    sVar7 = (short)((uint6)uVar14 >> 0x20);
    cVar11 = (0 < sVar7) * (sVar7 < 0x100) * (char)iVar29 - (0xff < sVar7);
    sVar7 = (short)((ulonglong)uVar15 >> 0x30);
    sVar8 = (short)((unkuint10)Var16 >> 0x40);
    cVar12 = (0 < sVar8) * (sVar8 < 0x100) * (char)iVar20 - (0xff < sVar8);
    sVar8 = auVar17._10_2_;
    sVar9 = auVar18._12_2_;
    cVar13 = (0 < sVar9) * (sVar9 < 0x100) * (char)iVar31 - (0xff < sVar9);
    sVar9 = auVar36._14_2_;
    sVar19 = CONCAT11((0 < sVar6) * (sVar6 < 0x100) * (char)((uint)iVar30 >> 0x10) - (0xff < sVar6),
                      cVar10);
    uVar37 = CONCAT13((0 < sVar7) * (sVar7 < 0x100) * cVar32 - (0xff < sVar7),
                      CONCAT12(cVar11,sVar19));
    uVar14 = CONCAT15((0 < sVar8) * (sVar8 < 0x100) * cVar33 - (0xff < sVar8),
                      CONCAT14(cVar12,uVar37));
    sVar6 = (short)((uint)uVar37 >> 0x10);
    sVar7 = (short)((uint6)uVar14 >> 0x20);
    sVar8 = (short)(CONCAT17((0 < sVar9) * (sVar9 < 0x100) * cVar34 - (0xff < sVar9),
                             CONCAT16(cVar13,uVar14)) >> 0x30);
    uVar37 = CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar13 - (0xff < sVar8),
                      CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar12 - (0xff < sVar7),
                               CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar11 - (0xff < sVar6),
                                        (0 < sVar19) * (sVar19 < 0x100) * cVar10 - (0xff < sVar19)))
                     );
  }
  (**(code **)(lVar24 + 0x158))(plVar22,0,0,uVar23,CONCAT44(uVar38,uVar37),param_4,param_5);
LAB_140273f5d:
  *(int *)((longlong)param_1 + 0x424) = *(int *)((longlong)param_1 + 0x424) + 1;
  return;
}



==== FUN_1402e76e0 @ 1402e76e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1402e76e0(longlong param_1)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float fVar11;
  float fVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  int *piVar18;
  int *piVar19;
  int *piVar20;
  ulonglong uVar21;
  longlong lVar22;
  ulonglong uVar23;
  uint uVar24;
  int *piVar25;
  undefined1 (*pauVar26) [16];
  float *pfVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  uint uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  longlong lVar34;
  longlong lVar35;
  longlong lVar36;
  float fVar37;
  longlong lVar38;
  byte bVar39;
  uint uVar40;
  longlong lVar41;
  longlong lVar42;
  longlong lVar43;
  longlong lVar44;
  undefined1 auVar45 [16];
  float fVar46;
  float fVar47;
  float fVar48;
  float fVar49;
  float fVar50;
  float fVar51;
  float fVar52;
  float fVar53;
  float fVar54;
  float fVar55;
  float fVar56;
  float fVar57;
  float fVar62;
  float fVar63;
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  float fVar64;
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  undefined1 auVar70 [16];
  undefined1 auVar72 [16];
  float fVar73;
  undefined1 auVar74 [16];
  uint uVar75;
  uint uVar76;
  uint uVar77;
  uint uVar78;
  uint uVar79;
  uint uVar80;
  float fVar81;
  float fVar82;
  float fVar83;
  float fVar84;
  undefined1 auStack_698 [32];
  undefined4 local_678;
  uint local_668;
  uint local_664;
  int local_660 [4];
  int local_650 [6];
  uint local_638 [4];
  longlong *local_628;
  longlong *local_620;
  longlong *local_618;
  longlong local_610;
  longlong *local_608;
  longlong *local_600;
  longlong *local_5f8;
  longlong local_5f0;
  longlong *local_5e8;
  longlong *local_5e0;
  longlong local_5d8;
  longlong local_5d0;
  longlong local_5c8;
  longlong local_5c0;
  undefined1 local_5b8 [16];
  longlong local_5a8;
  undefined1 local_598 [16];
  longlong local_588;
  longlong local_580;
  longlong local_578;
  longlong local_570;
  longlong local_568;
  longlong local_560;
  longlong local_558;
  undefined8 local_548;
  undefined8 uStack_540;
  longlong local_538;
  longlong local_530;
  longlong local_528;
  longlong local_520;
  byte local_518 [16];
  float local_508;
  byte bStack_504;
  undefined8 local_500;
  float local_4f8 [4];
  float local_4e8 [4];
  float local_4d8 [2];
  undefined8 uStack_4d0;
  float local_3d8 [64];
  float local_2d8 [2];
  undefined8 uStack_2d0;
  undefined8 local_1d8;
  float afStack_1d0 [62];
  ulonglong local_d8;
  undefined1 auVar69 [16];
  undefined1 auVar71 [16];
  
  local_d8 = DAT_140c0f7b0 ^ (ulonglong)auStack_698;
  local_580 = param_1;
  if (*(longlong **)(param_1 + 0x40) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x40) + 8))();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (*(longlong **)(param_1 + 0xc0) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0xc0) + 8))();
    *(undefined8 *)(param_1 + 0xc0) = 0;
  }
  if (*(longlong **)(param_1 + 200) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 200) + 8))();
    *(undefined8 *)(param_1 + 200) = 0;
  }
  if (*(longlong **)(param_1 + 0x110) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x110) + 8))();
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  if ((((*(longlong *)(param_1 + 0x108) != 0) &&
       (*(float *)(*(longlong *)(param_1 + 0x20) + 0x60) != 0.0)) &&
      ((*(byte *)(*(longlong *)(param_1 + 0x20) + 0x38) & 2) != 0)) &&
     ((iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                          (*(longlong **)(param_1 + 0x28),1), iVar13 == 0 &&
      ((iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                           (*(longlong **)(param_1 + 0x28),0x11), iVar13 == 0 ||
       (iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                           (*(longlong **)(param_1 + 0x28),0x1b), iVar13 == 0)))))) {
    local_628 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),1,&local_628);
    lVar17 = (**(code **)(*local_628 + 0x18))();
    local_620 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),1,&local_620);
    piVar18 = (int *)(**(code **)(*local_620 + 0x18))();
    FUN_1402ddac0(1,param_1 + 0x40);
    piVar19 = (int *)(**(code **)(**(longlong **)(param_1 + 0x40) + 0x18))();
    uVar33 = 0;
    *piVar19 = *piVar18;
    local_638[0] = 0;
    local_638[1] = 0;
    local_638[2] = 0;
    local_638[3] = 0;
    local_548 = 0;
    uStack_540 = 0;
    piVar19[1] = piVar18[1];
    piVar19[2] = piVar18[2];
    piVar19[3] = piVar18[3];
    local_650[3] = DAT_140c79784;
    local_660[3] = DAT_140c79784;
    local_650[1] = DAT_140c7977c;
    _local_508 = 0;
    local_500 = 0;
    local_518[0] = 0;
    local_518[1] = 0;
    local_518[2] = 0;
    local_518[3] = 0;
    local_518[4] = 0;
    local_518[5] = 0;
    local_518[6] = 0;
    local_518[7] = 0;
    local_518[8] = 0;
    local_518[9] = 0;
    local_518[10] = 0;
    local_518[0xb] = 0;
    local_518[0xc] = 0;
    local_518[0xd] = 0;
    local_518[0xe] = 0;
    local_518[0xf] = 0;
    local_660[1] = DAT_140c7977c;
    local_650[0] = DAT_140c79778;
    local_650[2] = DAT_140c79780;
    local_660[0] = DAT_140c79778;
    local_660[2] = DAT_140c79780;
    uVar32 = uVar33;
    uVar23 = uVar33;
    uVar21 = uVar33;
    do {
      iVar13 = (int)uVar21;
      fVar37 = (float)uVar23;
      if (*(int *)(((longlong)piVar18 - (longlong)local_650) +
                  (longlong)((longlong)local_650 + uVar32)) != 0) {
        *(int *)((longlong)local_650 + uVar32) = iVar13;
        *(undefined4 *)((longlong)local_638 + uVar32) = 0x3f800000;
        *(float *)((longlong)&local_508 + uVar32) = fVar37;
        pbVar2 = local_518 + uVar32;
        pbVar2[0] = 3;
        pbVar2[1] = 0;
        pbVar2[2] = 0;
        pbVar2[3] = 0;
      }
      iVar4 = *(int *)(uVar32 + lVar17);
      piVar20 = piVar19;
      uVar23 = uVar33;
      if (iVar4 != 0) {
        do {
          uVar21 = uVar33;
          piVar25 = piVar19;
          if (*piVar20 == iVar4) {
            local_660[uVar23] = iVar13;
            *(undefined4 *)((longlong)&local_548 + uVar23 * 4) = 0x3f800000;
            local_4e8[uVar23] = fVar37;
            local_4f8[uVar23] = 4.2039e-45;
            if ((uint)uVar23 < 4) goto LAB_1402e7a05;
            break;
          }
          uVar24 = (uint)uVar23 + 1;
          piVar20 = piVar20 + 1;
          uVar23 = (ulonglong)uVar24;
        } while (uVar24 < 4);
        do {
          if (*piVar25 == 0) {
            piVar19[uVar21] = iVar4;
            local_660[uVar21] = iVar13;
            *(undefined4 *)((longlong)&local_548 + uVar21 * 4) = 0x3f800000;
            local_4e8[uVar21] = fVar37;
            local_4f8[uVar21] = 4.2039e-45;
            break;
          }
          uVar24 = (int)uVar21 + 1;
          uVar21 = (ulonglong)uVar24;
          piVar25 = piVar25 + 1;
        } while (uVar24 < 4);
      }
LAB_1402e7a05:
      uVar23 = (ulonglong)((int)fVar37 + 2U);
      uVar21 = (ulonglong)(iVar13 + 1);
      uVar32 = uVar32 + 4;
    } while ((int)fVar37 + 2U < 8);
    local_538 = (**(code **)(**(longlong **)(param_1 + 0x108) + 0x18))();
    local_5e8 = (longlong *)0x0;
    local_608 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x11,&local_5e8);
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x12,&local_608);
    local_570 = (**(code **)(*local_5e8 + 0x18))();
    lVar22 = (**(code **)(*local_608 + 0x18))();
    local_5f8 = (longlong *)0x0;
    local_600 = (longlong *)0x0;
    local_5a8 = lVar22;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x11,&local_5f8);
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x12,&local_600);
    local_528 = (**(code **)(*local_5f8 + 0x18))();
    lVar17 = (**(code **)(*local_600 + 0x18))();
    local_5d8 = 0;
    local_5d0 = 0;
    local_5c8 = lVar17;
    iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                       (*(longlong **)(param_1 + 0x28),0x11);
    if (iVar13 == 0) {
      FUN_1402ddac0(0x11,param_1 + 0xc0);
      FUN_1402ddac0(0x12,param_1 + 200);
      local_5d8 = (**(code **)(**(longlong **)(param_1 + 0xc0) + 0x18))();
      local_5d0 = (**(code **)(**(longlong **)(param_1 + 200) + 0x18))();
    }
    local_618 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x48))
              (*(longlong **)(param_1 + 0x28),0x1b,&local_618);
    local_588 = (**(code **)(*local_618 + 0x18))();
    local_5e0 = (longlong *)0x0;
    (**(code **)(**(longlong **)(param_1 + 0x18) + 0x48))
              (*(longlong **)(param_1 + 0x18),0x1b,&local_5e0);
    local_560 = (**(code **)(*local_5e0 + 0x18))();
    local_610 = 0;
    iVar13 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x40))
                       (*(longlong **)(param_1 + 0x28),0x1b);
    if (iVar13 == 0) {
      FUN_1402ddac0(0x1b,param_1 + 0x110);
      local_610 = (**(code **)(**(longlong **)(param_1 + 0x110) + 0x18))();
    }
    fVar12 = DAT_140b79ed0;
    fVar11 = DAT_140b79e48;
    fVar37 = DAT_140b79d20;
    auVar7._4_4_ = local_638[1];
    auVar7._0_4_ = local_638[0];
    auVar7._8_4_ = local_638[2];
    auVar7._12_4_ = local_638[3];
    local_664 = 0;
    uVar24 = _DAT_140b608c0;
    uVar16 = _UNK_140b608c4;
    uVar75 = _UNK_140b608c8;
    uVar76 = _UNK_140b608cc;
    fVar73 = _DAT_140c58780;
    fVar49 = fRam0000000140c58784;
    fVar52 = fRam0000000140c58788;
    fVar55 = fRam0000000140c5878c;
    uVar77 = _DAT_140b60d90;
    uVar78 = _UNK_140b60d94;
    uVar79 = _UNK_140b60d98;
    uVar80 = _UNK_140b60d9c;
    fVar81 = DAT_140b60de0;
    fVar82 = _UNK_140b60de4;
    fVar83 = _UNK_140b60de8;
    fVar84 = _UNK_140b60dec;
    do {
      local_668 = 0;
      uVar40 = local_664;
      do {
        auVar74._0_4_ = ~uVar24 & _DAT_140b60900;
        auVar74._4_4_ = ~uVar16 & _UNK_140b60904;
        auVar74._8_4_ = ~uVar75 & _UNK_140b60908;
        auVar74._12_4_ = ~uVar76 & _UNK_140b6090c;
        local_558 = (longlong)(int)(local_668 * DAT_140c41720 + uVar40 * DAT_140c41724);
        uVar31 = *(uint *)(local_558 + local_570);
        uVar14 = *(uint *)(local_558 + 2 + local_570);
        auVar58._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar58._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar58._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar58._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar65._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar65._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar65._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar65._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar58 = auVar58 | auVar74;
        auVar65 = auVar65 | auVar74;
        fVar47 = auVar58._0_4_;
        fVar50 = auVar58._4_4_;
        fVar53 = auVar58._8_4_;
        fVar56 = auVar58._12_4_;
        if (*(ushort *)(local_558 + 2 + local_570) < *(ushort *)(local_558 + local_570)) {
          fVar57 = auVar65._0_4_ - fVar47;
          fVar62 = auVar65._4_4_ - fVar50;
          fVar63 = auVar65._8_4_ - fVar53;
          fVar64 = auVar65._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar65._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar65._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar65._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar65._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + local_570);
        lVar36 = 0x10;
        pauVar26 = (undefined1 (*) [16])local_4d8;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar58;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar65;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar36 = lVar36 + -1;
        } while (lVar36 != 0);
        uVar31 = *(uint *)(local_558 + lVar22);
        uVar14 = *(uint *)(local_558 + 2 + lVar22);
        auVar59._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar59._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar59._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar59._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar66._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar66._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar66._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar66._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar59 = auVar59 | auVar74;
        auVar66 = auVar66 | auVar74;
        fVar47 = auVar59._0_4_;
        fVar50 = auVar59._4_4_;
        fVar53 = auVar59._8_4_;
        fVar56 = auVar59._12_4_;
        if (*(ushort *)(local_558 + 2 + lVar22) < *(ushort *)(local_558 + lVar22)) {
          fVar57 = auVar66._0_4_ - fVar47;
          fVar62 = auVar66._4_4_ - fVar50;
          fVar63 = auVar66._8_4_ - fVar53;
          fVar64 = auVar66._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar66._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar66._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar66._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar66._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + lVar22);
        pauVar26 = (undefined1 (*) [16])local_2d8;
        lVar22 = 0x10;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar59;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar66;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar22 = lVar22 + -1;
        } while (lVar22 != 0);
        uVar31 = *(uint *)(local_558 + local_528);
        uVar14 = *(uint *)(local_558 + 2 + local_528);
        auVar60._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar60._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar60._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar60._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar67._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar67._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar67._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar67._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar60 = auVar60 | auVar74;
        auVar67 = auVar67 | auVar74;
        fVar47 = auVar60._0_4_;
        fVar50 = auVar60._4_4_;
        fVar53 = auVar60._8_4_;
        fVar56 = auVar60._12_4_;
        if (*(ushort *)(local_558 + 2 + local_528) < *(ushort *)(local_558 + local_528)) {
          fVar57 = auVar67._0_4_ - fVar47;
          fVar62 = auVar67._4_4_ - fVar50;
          fVar63 = auVar67._8_4_ - fVar53;
          fVar64 = auVar67._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar67._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar67._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar67._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar67._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + local_528);
        lVar22 = 0x10;
        pauVar26 = (undefined1 (*) [16])local_3d8;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar60;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar67;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar22 = lVar22 + -1;
        } while (lVar22 != 0);
        uVar31 = *(uint *)(local_558 + lVar17);
        uVar14 = *(uint *)(local_558 + 2 + lVar17);
        auVar61._0_4_ = (uint)((float)(int)(uVar31 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar61._4_4_ = (uint)((float)(int)(uVar31 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar61._8_4_ = (uint)((float)(int)(uVar31 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar61._12_4_ = (uint)((float)(int)(uVar31 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar68._0_4_ = (uint)((float)(int)(uVar14 & uVar79) * fVar83 * fVar52) & uVar24;
        auVar68._4_4_ = (uint)((float)(int)(uVar14 & uVar78) * fVar82 * fVar49) & uVar16;
        auVar68._8_4_ = (uint)((float)(int)(uVar14 & uVar77) * fVar81 * fVar73) & uVar75;
        auVar68._12_4_ = (uint)((float)(int)(uVar14 & uVar80) * fVar84 * fVar55) & uVar76;
        auVar61 = auVar61 | auVar74;
        auVar68 = auVar68 | auVar74;
        fVar47 = auVar61._0_4_;
        fVar50 = auVar61._4_4_;
        fVar53 = auVar61._8_4_;
        fVar56 = auVar61._12_4_;
        if (*(ushort *)(local_558 + 2 + lVar17) < *(ushort *)(local_558 + lVar17)) {
          fVar57 = auVar68._0_4_ - fVar47;
          fVar62 = auVar68._4_4_ - fVar50;
          fVar63 = auVar68._8_4_ - fVar53;
          fVar64 = auVar68._12_4_ - fVar56;
          fVar46 = _DAT_140b7ac10 * fVar57;
          fVar48 = _UNK_140b7ac14 * fVar62;
          fVar51 = _UNK_140b7ac18 * fVar63;
          fVar54 = _UNK_140b7ac1c * fVar64;
          fVar57 = _DAT_140b7ac70 * fVar57 + fVar47;
          fVar62 = _UNK_140b7ac74 * fVar62 + fVar50;
          fVar63 = _UNK_140b7ac78 * fVar63 + fVar53;
          fVar64 = _UNK_140b7ac7c * fVar64 + fVar56;
        }
        else {
          fVar57 = 0.0;
          fVar62 = 0.0;
          fVar63 = 0.0;
          fVar64 = 0.0;
          fVar46 = (auVar68._0_4_ - fVar47) * _DAT_140b7ac50;
          fVar48 = (auVar68._4_4_ - fVar50) * _UNK_140b7ac54;
          fVar51 = (auVar68._8_4_ - fVar53) * _UNK_140b7ac58;
          fVar54 = (auVar68._12_4_ - fVar56) * _UNK_140b7ac5c;
        }
        uVar31 = *(uint *)(local_558 + 4 + lVar17);
        pauVar26 = (undefined1 (*) [16])&local_1d8;
        lVar17 = 0x10;
        do {
          uVar14 = uVar31 & 3;
          if (uVar14 == 0) {
            *pauVar26 = auVar61;
          }
          else if (uVar14 == 1) {
            *pauVar26 = auVar68;
          }
          else if (uVar14 == 2) {
            *(float *)*pauVar26 = fVar46 + fVar47;
            *(float *)((longlong)*pauVar26 + 4) = fVar48 + fVar50;
            *(float *)((longlong)*pauVar26 + 8) = fVar51 + fVar53;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar54 + fVar56;
          }
          else {
            *(float *)*pauVar26 = fVar57;
            *(float *)((longlong)*pauVar26 + 4) = fVar62;
            *(float *)((longlong)*pauVar26 + 8) = fVar63;
            *(float *)((longlong)*pauVar26 + 0xc) = fVar64;
          }
          pauVar26 = pauVar26 + 1;
          uVar31 = uVar31 >> 2;
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        uVar31 = uVar40 * 4;
        uVar14 = local_668 * 4;
        lVar22 = 0;
        uVar15 = uVar31 + 4;
        local_638[2] = uVar14 + 4;
        local_638[0] = uVar14;
        local_638[1] = uVar31;
        local_5f0 = 0;
        local_638[3] = uVar15;
        lVar17 = 0;
        lVar36 = local_558;
        if ((int)uVar31 < (int)uVar15) {
          lVar43 = (longlong)(int)uVar31;
          do {
            if ((int)uVar14 < (int)local_638[2]) {
              lVar42 = (longlong)local_660[0];
              lVar36 = (longlong)local_650[0];
              lVar17 = (longlong)local_650[1];
              lVar38 = (longlong)local_650[2];
              lVar41 = (longlong)local_650[3];
              lVar34 = lVar22 << 4;
              local_530 = lVar42;
              local_5c0 = lVar36;
              local_578 = lVar17;
              local_5f0 = local_5f0 + (ulonglong)(local_638[2] - uVar14);
              local_520 = lVar38;
              local_568 = lVar41;
              lVar44 = (longlong)(int)uVar14;
              lVar35 = lVar34;
              uVar24 = uVar14;
              do {
                fVar73 = 0.0;
                if ((uVar31 < 0x41) && (uVar24 < 0x41)) {
                  fVar73 = (float)*(byte *)(DAT_140c4191c * lVar43 + 1 +
                                           DAT_140c41918 * lVar44 + local_538) * fVar37 *
                           *(float *)(*(longlong *)(local_580 + 0x20) + 0x60);
                  lVar36 = local_5c0;
                }
                if (fVar11 <= *(float *)((longlong)&uStack_4d0 + lVar34 + 4)) {
                  local_4f8[0] = (_DAT_140b7a790 * *(float *)((longlong)local_2d8 + lVar34) +
                                 *(float *)((longlong)local_4d8 + lVar34)) - _DAT_140b7b240;
                  local_4f8[1] = (_UNK_140b7a794 * *(float *)((longlong)local_2d8 + lVar34 + 4) +
                                 *(float *)((longlong)local_4d8 + lVar34 + 4)) - _UNK_140b7b244;
                  local_4f8[2] = (_UNK_140b7a798 * *(float *)((longlong)&uStack_2d0 + lVar34) +
                                 *(float *)((longlong)&uStack_4d0 + lVar34)) - DAT_140b7b248;
                  local_4f8[3] = ((fVar12 - local_4f8[0]) - local_4f8[1]) - local_4f8[2];
                  auVar9._4_4_ = local_4f8[1];
                  auVar9._0_4_ = local_4f8[0];
                  auVar9._8_4_ = local_4f8[2];
                  auVar9._12_4_ = local_4f8[3];
                  auVar58 = maxps(ZEXT816(0),auVar9);
                  auVar6._4_4_ = _UNK_140b7b244;
                  auVar6._0_4_ = _DAT_140b7b240;
                  auVar6._8_4_ = DAT_140b7b248;
                  auVar6._12_4_ = _UNK_140b7b24c;
                  local_5b8 = minps(auVar58,auVar6);
                }
                else {
                  local_5b8 = ZEXT816(0);
                }
                auVar58 = *(undefined1 (*) [16])((longlong)&local_1d8 + lVar34);
                lVar22 = (longlong)local_660[1];
                auVar70._4_4_ = *(undefined4 *)(local_5b8 + (longlong)local_660[2] * 4);
                auVar70._0_4_ = *(undefined4 *)(local_5b8 + lVar42 * 4);
                fVar49 = *(float *)((longlong)local_3d8 + lVar34);
                fVar52 = *(float *)((longlong)local_3d8 + lVar34 + 4);
                fVar55 = *(float *)((longlong)local_3d8 + lVar34 + 8);
                fVar81 = *(float *)((longlong)local_3d8 + lVar34 + 0xc);
                auVar70._8_4_ = *(undefined4 *)(local_5b8 + (longlong)local_660[2] * 4);
                auVar70._12_4_ = *(undefined4 *)(local_5b8 + (longlong)local_660[3] * 4);
                auVar69._8_8_ = auVar70._8_8_;
                auVar69._4_4_ = *(undefined4 *)(local_5b8 + lVar22 * 4);
                auVar69._0_4_ = *(undefined4 *)(local_5b8 + lVar42 * 4);
                auVar8._8_8_ = uStack_540;
                auVar8._0_8_ = local_548;
                auVar65 = minps(auVar69,auVar8);
                *(float *)((longlong)local_4d8 + lVar34) = auVar65._0_4_ * fVar73;
                *(float *)((longlong)local_4d8 + lVar34 + 4) = auVar65._4_4_ * fVar73;
                *(float *)((longlong)&uStack_4d0 + lVar34) = auVar65._8_4_ * fVar73;
                *(float *)((longlong)&uStack_4d0 + lVar34 + 4) = auVar65._12_4_ * fVar73;
                if (fVar11 <= fVar81) {
                  local_4e8[0] = (_DAT_140b7a790 * auVar58._0_4_ + fVar49) - _DAT_140b7b240;
                  local_4e8[1] = (_UNK_140b7a794 * auVar58._4_4_ + fVar52) - _UNK_140b7b244;
                  local_4e8[2] = (_UNK_140b7a798 * auVar58._8_4_ + fVar55) - DAT_140b7b248;
                  local_4e8[3] = ((fVar12 - local_4e8[0]) - local_4e8[1]) - local_4e8[2];
                  auVar10._4_4_ = local_4e8[1];
                  auVar10._0_4_ = local_4e8[0];
                  auVar10._8_4_ = local_4e8[2];
                  auVar10._12_4_ = local_4e8[3];
                  auVar58 = maxps(ZEXT816(0),auVar10);
                  auVar5._4_4_ = _UNK_140b7b244;
                  auVar5._0_4_ = _DAT_140b7b240;
                  auVar5._8_4_ = DAT_140b7b248;
                  auVar5._12_4_ = _UNK_140b7b24c;
                  local_598 = minps(auVar58,auVar5);
                }
                else {
                  local_598 = ZEXT816(0);
                }
                auVar72._4_4_ = *(undefined4 *)(local_598 + lVar38 * 4);
                auVar72._0_4_ = *(undefined4 *)(local_598 + lVar36 * 4);
                fVar73 = fVar12 - fVar73;
                auVar72._8_4_ = *(undefined4 *)(local_598 + lVar38 * 4);
                auVar72._12_4_ = *(undefined4 *)(local_598 + lVar41 * 4);
                auVar71._8_8_ = auVar72._8_8_;
                auVar71._4_4_ = *(undefined4 *)(local_598 + lVar17 * 4);
                auVar71._0_4_ = *(undefined4 *)(local_598 + lVar36 * 4);
                auVar58 = minps(auVar71,auVar7);
                *(float *)((longlong)local_3d8 + lVar34) = fVar73 * auVar58._0_4_;
                *(float *)((longlong)local_3d8 + lVar34 + 4) = fVar73 * auVar58._4_4_;
                *(float *)((longlong)local_3d8 + lVar34 + 8) = fVar73 * auVar58._8_4_;
                *(float *)((longlong)local_3d8 + lVar34 + 0xc) = fVar73 * auVar58._12_4_;
                if (((local_610 != 0) && (uVar31 < 0x40)) && (uVar24 < 0x40)) {
                  lVar17 = (longlong)(int)(DAT_140c41950 * uVar24 + uVar31 * DAT_140c41954);
                  bVar3 = *(byte *)(lVar17 + local_588);
                  bVar30 = *(byte *)(lVar17 + local_560);
                  bVar39 = bVar30;
                  if (*(float *)((longlong)local_3d8 + lVar35 + 0xc) <
                      *(float *)((longlong)&uStack_4d0 + lVar35 + 4)) {
                    bVar39 = bVar3;
                  }
                  bVar28 = bVar30;
                  if (*(float *)((longlong)local_3d8 + lVar35 + 8) <
                      *(float *)((longlong)&uStack_4d0 + lVar35)) {
                    bVar28 = bVar3;
                  }
                  bVar29 = bVar30;
                  if (*(float *)((longlong)local_3d8 + lVar35 + 4) <
                      *(float *)((longlong)local_4d8 + lVar35 + 4)) {
                    bVar29 = bVar3;
                  }
                  if (*(float *)((longlong)local_3d8 + lVar35) <
                      *(float *)((longlong)local_4d8 + lVar35)) {
                    bVar30 = bVar3;
                  }
                  *(byte *)(lVar17 + local_610) =
                       (((bVar39 >> (local_500._4_1_ & 0x1f) & local_518[0xc]) << 2 |
                        bVar28 >> ((byte)local_500 & 0x1f) & local_518[8]) << 2 |
                       bVar29 >> (bStack_504 & 0x1f) & local_518[4]) << 2 |
                       bVar30 >> (local_508._0_1_ & 0x1f) & local_518[0];
                  lVar22 = local_610;
                  lVar36 = local_5c0;
                  lVar17 = local_578;
                  lVar38 = local_520;
                  lVar41 = local_568;
                  lVar42 = local_530;
                }
                fVar73 = *(float *)((longlong)local_3d8 + lVar34) +
                         *(float *)((longlong)local_4d8 + lVar34);
                fVar49 = *(float *)((longlong)local_3d8 + lVar34 + 4) +
                         *(float *)((longlong)local_4d8 + lVar34 + 4);
                fVar52 = *(float *)((longlong)local_3d8 + lVar34 + 8) +
                         *(float *)((longlong)&uStack_4d0 + lVar34);
                fVar55 = *(float *)((longlong)local_3d8 + lVar34 + 0xc) +
                         *(float *)((longlong)&uStack_4d0 + lVar34 + 4);
                *(float *)((longlong)local_4d8 + lVar34) = fVar73;
                *(float *)((longlong)local_4d8 + lVar34 + 4) = fVar49;
                *(float *)((longlong)&uStack_4d0 + lVar34) = fVar52;
                *(float *)((longlong)&uStack_4d0 + lVar34 + 4) = fVar55;
                auVar45._4_4_ = -(uint)(fVar49 != 0.0);
                auVar45._0_4_ = -(uint)(fVar73 != 0.0);
                auVar45._8_4_ = -(uint)(fVar52 != 0.0);
                auVar45._12_4_ = -(uint)(fVar55 != 0.0);
                iVar13 = movmskps((int)lVar22,auVar45);
                if (iVar13 != 0) {
                  *(undefined4 *)((longlong)&uStack_4d0 + lVar34 + 4) = 0x3f800000;
                }
                uVar24 = uVar24 + 1;
                lVar35 = lVar35 + 0x10;
                lVar34 = lVar34 + 0x10;
                lVar44 = lVar44 + 1;
                lVar22 = local_5f0;
                uVar14 = local_638[0];
                uVar15 = local_638[3];
              } while ((int)uVar24 < (int)local_638[2]);
            }
            uVar31 = uVar31 + 1;
            lVar43 = lVar43 + 1;
            lVar36 = local_558;
            uVar24 = _DAT_140b608c0;
            uVar16 = _UNK_140b608c4;
            uVar75 = _UNK_140b608c8;
            uVar76 = _UNK_140b608cc;
            fVar73 = _DAT_140c58780;
            fVar49 = fRam0000000140c58784;
            fVar52 = fRam0000000140c58788;
            fVar55 = fRam0000000140c5878c;
            uVar77 = _DAT_140b60d90;
            uVar78 = _UNK_140b60d94;
            uVar79 = _UNK_140b60d98;
            uVar80 = _UNK_140b60d9c;
            fVar81 = DAT_140b60de0;
            fVar82 = _UNK_140b60de4;
            fVar83 = _UNK_140b60de8;
            fVar84 = _UNK_140b60dec;
            uVar40 = local_664;
          } while ((int)uVar31 < (int)uVar15);
        }
        if (local_5d8 != 0) {
          uVar32 = 0;
          do {
            uVar23 = uVar32 + 0x10;
            *(undefined8 *)((longlong)&local_1d8 + uVar32) =
                 *(undefined8 *)((longlong)local_4d8 + uVar32);
            *(undefined8 *)((longlong)afStack_1d0 + uVar32) =
                 *(undefined8 *)((longlong)&uStack_4d0 + uVar32);
            uVar32 = uVar23;
          } while (uVar23 < 0x100);
          puVar1 = (uint *)(lVar36 + local_5d8);
          local_678 = 0x40000;
          FUN_140267380(puVar1,&local_1d8,CONCAT71((int7)((ulonglong)lVar17 >> 8),1));
          uVar24 = *puVar1;
          uVar16 = *(uint *)((longlong)puVar1 + 2);
          fVar73 = (float)((uint)((float)(int)(uVar24 & _UNK_140b60d98) * _UNK_140b60de8 *
                                 fRam0000000140c58788) & _DAT_140b608c0 |
                          ~_DAT_140b608c0 & _DAT_140b60900);
          fVar49 = (float)((uint)((float)(int)(uVar24 & _UNK_140b60d94) * _UNK_140b60de4 *
                                 fRam0000000140c58784) & _UNK_140b608c4 |
                          ~_UNK_140b608c4 & _UNK_140b60904);
          fVar52 = (float)((uint)((float)(int)(uVar24 & _DAT_140b60d90) * DAT_140b60de0 *
                                 _DAT_140c58780) & _UNK_140b608c8 | ~_UNK_140b608c8 & _UNK_140b60908
                          );
          fVar55 = (float)((uint)((float)(int)(uVar24 & _UNK_140b60d9c) * _UNK_140b60dec *
                                 fRam0000000140c5878c) & _UNK_140b608cc |
                          ~_UNK_140b608cc & _UNK_140b6090c);
          fVar81 = (float)((uint)((float)(int)(uVar16 & _UNK_140b60d98) * _UNK_140b60de8 *
                                 fRam0000000140c58788) & _DAT_140b608c0 |
                          ~_DAT_140b608c0 & _DAT_140b60900);
          fVar82 = (float)((uint)((float)(int)(uVar16 & _UNK_140b60d94) * _UNK_140b60de4 *
                                 fRam0000000140c58784) & _UNK_140b608c4 |
                          ~_UNK_140b608c4 & _UNK_140b60904);
          fVar83 = (float)((uint)((float)(int)(uVar16 & _DAT_140b60d90) * DAT_140b60de0 *
                                 _DAT_140c58780) & _UNK_140b608c8 | ~_UNK_140b608c8 & _UNK_140b60908
                          );
          fVar84 = (float)((uint)((float)(int)(uVar16 & _UNK_140b60d9c) * _UNK_140b60dec *
                                 fRam0000000140c5878c) & _UNK_140b608cc |
                          ~_UNK_140b608cc & _UNK_140b6090c);
          if (*(ushort *)((longlong)puVar1 + 2) < (ushort)*puVar1) {
            fVar47 = _DAT_140b7ac10 * (fVar81 - fVar73);
            fVar50 = _UNK_140b7ac14 * (fVar82 - fVar49);
            fVar53 = _UNK_140b7ac18 * (fVar83 - fVar52);
            fVar56 = _UNK_140b7ac1c * (fVar84 - fVar55);
            fVar57 = _DAT_140b7ac70 * (fVar81 - fVar73) + fVar73;
            fVar62 = _UNK_140b7ac74 * (fVar82 - fVar49) + fVar49;
            fVar63 = _UNK_140b7ac78 * (fVar83 - fVar52) + fVar52;
            fVar64 = _UNK_140b7ac7c * (fVar84 - fVar55) + fVar55;
          }
          else {
            fVar57 = 0.0;
            fVar62 = 0.0;
            fVar63 = 0.0;
            fVar64 = 0.0;
            fVar47 = (fVar81 - fVar73) * _DAT_140b7ac50;
            fVar50 = (fVar82 - fVar49) * _UNK_140b7ac54;
            fVar53 = (fVar83 - fVar52) * _UNK_140b7ac58;
            fVar56 = (fVar84 - fVar55) * _UNK_140b7ac5c;
          }
          uVar24 = puVar1[1];
          pfVar27 = local_2d8;
          lVar17 = 0x10;
          do {
            uVar16 = uVar24 & 3;
            if (uVar16 == 0) {
              *pfVar27 = fVar73;
              pfVar27[1] = fVar49;
              pfVar27[2] = fVar52;
              pfVar27[3] = fVar55;
            }
            else if (uVar16 == 1) {
              *pfVar27 = fVar81;
              pfVar27[1] = fVar82;
              pfVar27[2] = fVar83;
              pfVar27[3] = fVar84;
            }
            else if (uVar16 == 2) {
              *pfVar27 = fVar47 + fVar73;
              pfVar27[1] = fVar50 + fVar49;
              pfVar27[2] = fVar53 + fVar52;
              pfVar27[3] = fVar56 + fVar55;
            }
            else {
              *pfVar27 = fVar57;
              pfVar27[1] = fVar62;
              pfVar27[2] = fVar63;
              pfVar27[3] = fVar64;
            }
            pfVar27 = pfVar27 + 4;
            uVar24 = uVar24 >> 2;
            lVar17 = lVar17 + -1;
          } while (lVar17 != 0);
          uVar32 = 0;
          do {
            fVar73 = *(float *)((longlong)local_4d8 + uVar32 + 4);
            fVar49 = *(float *)((longlong)&uStack_4d0 + uVar32);
            uVar23 = uVar32 + 0x10;
            fVar52 = *(float *)((longlong)&uStack_2d0 + uVar32);
            *(float *)((longlong)local_2d8 + uVar32) =
                 (_DAT_140b7ac50 +
                 (*(float *)((longlong)local_4d8 + uVar32) -
                 *(float *)((longlong)local_2d8 + uVar32)) * _DAT_140b7ac50) * _DAT_140b7b1b0;
            *(float *)((longlong)local_2d8 + uVar32 + 4) =
                 (_UNK_140b7ac54 +
                 (fVar73 - *(float *)((longlong)local_2d8 + uVar32 + 4)) * _UNK_140b7ac54) *
                 _UNK_140b7b1b4;
            *(float *)((longlong)&uStack_2d0 + uVar32) =
                 (_UNK_140b7ac58 + (fVar49 - fVar52) * _UNK_140b7ac58) * _UNK_140b7b1b8;
            *(float *)((longlong)&uStack_2d0 + uVar32 + 4) = fVar12 * _UNK_140b7b1bc;
            uVar32 = uVar23;
          } while (uVar23 < 0x100);
          uVar32 = 0;
          do {
            uVar23 = uVar32 + 0x10;
            *(undefined8 *)((longlong)&local_1d8 + uVar32) =
                 *(undefined8 *)((longlong)local_2d8 + uVar32);
            *(undefined8 *)((longlong)afStack_1d0 + uVar32) =
                 *(undefined8 *)((longlong)&uStack_2d0 + uVar32);
            uVar32 = uVar23;
          } while (uVar23 < 0x100);
          local_678 = 0x40000;
          FUN_140267380(local_5d0 + lVar36,&local_1d8,1);
          uVar24 = _DAT_140b608c0;
          uVar16 = _UNK_140b608c4;
          uVar75 = _UNK_140b608c8;
          uVar76 = _UNK_140b608cc;
          fVar73 = _DAT_140c58780;
          fVar49 = fRam0000000140c58784;
          fVar52 = fRam0000000140c58788;
          fVar55 = fRam0000000140c5878c;
          uVar77 = _DAT_140b60d90;
          uVar78 = _UNK_140b60d94;
          uVar79 = _UNK_140b60d98;
          uVar80 = _UNK_140b60d9c;
          fVar81 = DAT_140b60de0;
          fVar82 = _UNK_140b60de4;
          fVar83 = _UNK_140b60de8;
          fVar84 = _UNK_140b60dec;
          uVar40 = local_664;
        }
        local_668 = local_668 + 1;
        lVar17 = local_5c8;
        lVar22 = local_5a8;
      } while (local_668 < 0x11);
      local_664 = uVar40 + 1;
    } while (local_664 < 0x11);
    if (local_5e0 != (longlong *)0x0) {
      (**(code **)(*local_5e0 + 8))();
    }
    if (local_618 != (longlong *)0x0) {
      (**(code **)(*local_618 + 8))();
    }
    if (local_600 != (longlong *)0x0) {
      (**(code **)(*local_600 + 8))();
    }
    if (local_5f8 != (longlong *)0x0) {
      (**(code **)(*local_5f8 + 8))();
    }
    if (local_608 != (longlong *)0x0) {
      (**(code **)(*local_608 + 8))();
    }
    if (local_5e8 != (longlong *)0x0) {
      (**(code **)(*local_5e8 + 8))();
    }
    if (local_620 != (longlong *)0x0) {
      (**(code **)(*local_620 + 8))();
    }
    if (local_628 != (longlong *)0x0) {
      (**(code **)(*local_628 + 8))();
    }
  }
  return;
}



==== FUN_1403c17d0 @ 1403c17d0 ====

int FUN_1403c17d0(longlong param_1,uint *param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  undefined *puVar12;
  uint uVar13;
  uint local_res10;
  uint uStackX_14;
  uint local_res18;
  uint uStackX_1c;
  int local_res20;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar15;
  undefined8 uVar14;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar16;
  undefined8 local_50;
  undefined8 local_48;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar1 = *param_3;
  uVar2 = *param_2;
  uVar13 = param_2[1];
  uVar3 = param_3[1];
  local_res10 = uVar1;
  uStackX_14 = uVar3;
  local_res18 = uVar2;
  uStackX_1c = uVar13;
  local_res20 = param_4;
  if (((299 < (int)uVar1) || (uVar3 == 0xffffffff)) || ((uVar1 == 0 && (0x1e < uVar3)))) {
    FUN_1403cc530(param_1,0x1b);
    return 0x1b;
  }
  lVar6 = FUN_1403ac780(param_1 + 0xa0,&local_res18);
  lVar7 = FUN_1403ac780(param_1 + 0xa0,&local_res10);
  lVar8 = *(longlong *)(param_1 + 0x78);
  if (((lVar8 == 0) || (*(int *)(lVar8 + 0x250) != 0)) || (*(int *)(lVar8 + 0x80) == 0x17)) {
    return 0x39;
  }
  cVar4 = FUN_14053bc30(lVar8,&local_res10);
  if (cVar4 != '\0') {
    return 0x20;
  }
  iVar5 = *(int *)(param_1 + 0x6644);
  if (lVar6 == 0) {
    FUN_1403a6770(iVar5 == 0x43,1);
    return 1;
  }
  uVar14 = CONCAT44(uVar15,(uint)(iVar5 == 0x42));
  iVar5 = FUN_1403ad100(param_1,lVar6,lVar7,&local_res10,uVar14,
                        CONCAT44(uVar16,(uint)(iVar5 == 0x43)));
  uVar15 = (undefined4)((ulonglong)uVar14 >> 0x20);
  if (iVar5 != 0) {
    FUN_1403a6770();
    return iVar5;
  }
  if (local_res20 != 0) goto LAB_1403c1ae6;
  if (((uVar1 & 0xfffffff6) == 0) && (uVar1 != 1)) {
    if (((*(byte *)(*(longlong *)(lVar6 + 0x40) + 0x150) & 0x10) != 0) &&
       (iVar5 = FUN_14056a3f0(), iVar5 == 0)) {
      uVar9 = (ulonglong)(byte)local_res10 << 8 | (ulonglong)(uVar3 & 0xff);
      if ((int)uVar2 < 300) {
        uVar11 = (ulonglong)(byte)local_res18 << 8 | (ulonglong)(uVar13 & 0xff);
      }
      else {
        uVar11 = 0xffffffffffffffff;
      }
      puVar12 = &DAT_1409e9fac;
      pcVar10 = "ItemConfirmSoulboundOnEquip";
      uVar13 = uVar3;
      goto LAB_1403c1ab6;
    }
    iVar5 = FUN_1403d8bc0();
    if (iVar5 == 0) goto LAB_1403c19e1;
    uVar9 = (ulonglong)(byte)local_res10 << 8 | (ulonglong)(uVar3 & 0xff);
    if ((int)uVar2 < 300) {
      uVar11 = (ulonglong)(byte)local_res18 << 8 | (ulonglong)(uVar13 & 0xff);
      uVar13 = uVar3;
    }
    else {
      uVar11 = 0xffffffffffffffff;
      uVar13 = uVar3;
    }
  }
  else {
LAB_1403c19e1:
    if ((((uVar2 & 0xfffffff6) != 0) || (uVar2 == 1)) || (lVar7 == 0)) {
LAB_1403c1ae6:
      if ((*(int *)(*(longlong *)(param_1 + 0x78) + 0x2ac) != 0) && ((uVar2 == 0 || (uVar1 == 0))))
      {
        if ((DAT_140dc2280 & 1) == 0) {
          DAT_140dc2280 = DAT_140dc2280 | 1;
          lVar8 = FUN_140200220(0x149);
          if (lVar8 == 0) {
            DAT_140dc2284 = 0x5dc;
          }
          else {
            DAT_140dc2284 = *(undefined4 *)(lVar8 + 4);
          }
        }
        uVar14 = CONCAT44(uVar15,DAT_140dc2284);
        FUN_14046a3d0(*(undefined8 *)(param_1 + 0x78),0,0,0,uVar14);
        uVar15 = (undefined4)((ulonglong)uVar14 >> 0x20);
      }
      FUN_14046a3d0(*(undefined8 *)(param_1 + 0x78),3,0,0x309,CONCAT44(uVar15,10000));
      local_50 = CONCAT44(uStackX_1c,local_res18);
      local_48 = CONCAT44(uStackX_14,local_res10);
      FUN_1403f4900(param_1,0x182,&local_50);
      *(undefined4 *)(lVar6 + 0x8c) = 0;
      if (lVar7 != 0) {
        *(undefined4 *)(lVar7 + 0x8c) = 0;
      }
      return 0;
    }
    if (((*(byte *)(*(longlong *)(lVar7 + 0x40) + 0x150) & 0x10) != 0) &&
       (iVar5 = FUN_14056a3f0(lVar7), iVar5 == 0)) {
      if ((int)uVar2 < 300) {
        uVar9 = (ulonglong)(byte)local_res18 << 8 | (ulonglong)(uVar13 & 0xff);
      }
      else {
        uVar9 = 0xffffffffffffffff;
      }
      puVar12 = &DAT_1409e9fac;
      uVar11 = (ulonglong)(byte)local_res10 << 8 | (ulonglong)(uVar3 & 0xff);
      pcVar10 = "ItemConfirmSoulboundOnEquip";
      goto LAB_1403c1ab6;
    }
    iVar5 = FUN_1403d8bc0(lVar7);
    if (iVar5 == 0) goto LAB_1403c1ae6;
    if ((int)uVar2 < 300) {
      uVar9 = (ulonglong)(byte)local_res18 << 8 | (ulonglong)(uVar13 & 0xff);
    }
    else {
      uVar9 = 0xffffffffffffffff;
    }
    uVar11 = (ulonglong)(byte)local_res10 << 8 | (ulonglong)(uVar3 & 0xff);
  }
  puVar12 = &DAT_1409ea01c;
  pcVar10 = "ItemConfirmClearRestockOnEquip";
LAB_1403c1ab6:
  FUN_1400ea3e0(*(undefined8 *)(DAT_140c65898 + 0x7340),pcVar10,puVar12,uVar13,uVar11,uVar9);
  return 0;
}



==== FUN_140432f20 @ 140432f20 ====

undefined4 FUN_140432f20(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 local_18;
  undefined4 local_10;
  
  if (param_2 == 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    return 1;
  }
  puVar2 = (undefined8 *)FUN_140059170(param_1,0x10);
  puVar3 = (undefined8 *)FUN_14018b280(0x10);
  if (puVar3 == (undefined8 *)0x0) {
    puVar3 = (undefined8 *)0x0;
  }
  else {
    puVar3[1] = param_2;
    *puVar3 = &PTR_FUN_140b6fe30;
  }
  puVar2[1] = puVar3;
  *puVar2 = 0x3950;
  lVar1 = *(longlong *)(param_1 + 0x20);
  local_18 = FUN_140062650(param_1,"Game.GalacticArchiveArticle",0x1b);
  local_10 = 4;
  FUN_14005e8e0(param_1,lVar1 + 0xa0,&local_18,*(undefined8 *)(param_1 + 0x10));
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058bf0(param_1,0xfffffffe);
  return 1;
}



==== FUN_1404739b0 @ 1404739b0 ====

void FUN_1404739b0(longlong param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                  uint param_6)

{
  short sVar1;
  wchar_t wVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  int *piVar11;
  longlong lVar12;
  longlong lVar13;
  longlong *plVar14;
  ulonglong uVar15;
  undefined4 uVar16;
  undefined2 *puVar17;
  bool bVar18;
  undefined8 local_138;
  longlong local_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  longlong local_118;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined1 local_108 [16];
  longlong local_f8;
  longlong local_f0;
  longlong local_d8;
  longlong local_d0;
  longlong local_48;
  
  if (param_2 == 0) {
    plVar8 = (longlong *)FUN_1403d90d0(DAT_140c65898,*(undefined4 *)(param_1 + 0xc0));
    if ((plVar8 != (longlong *)0x0) && (iVar4 = (**(code **)(*plVar8 + 0x20))(plVar8), iVar4 != 0))
    {
      return;
    }
    FUN_14045bf30(param_1,0,0);
    return;
  }
  lVar9 = FUN_1401fdbe0(param_2);
  if (lVar9 == 0) {
    return;
  }
  if ((*(int *)(lVar9 + 0x38) != 0) && (iVar4 = FUN_14047be00(param_1), iVar4 != 0)) {
    return;
  }
  lVar10 = FUN_1403d90d0(DAT_140c65898,param_3);
  lVar12 = *(longlong *)(DAT_140c65898 + 0x78);
  local_118 = lVar12;
  if ((*(int *)(lVar9 + 0x2c) != 0) && (*(int *)(param_1 + 0x1428) != 0x3f)) {
    FUN_140470650(param_1,1,1);
  }
  if ((*(int *)(lVar9 + 0x38) == 0) ||
     (((*(int *)(lVar9 + 0x3c) == *(int *)(param_1 + 0x1b8) &&
       (param_2 == *(int *)(param_1 + 0x1cc))) ||
      (FUN_14045bf30(param_1,*(int *)(lVar9 + 0x3c),param_2), *(int *)(param_1 + 0x1d0) == param_2))
     )) {
    FUN_140474400(param_1,param_2,1);
  }
  if (param_5 == 0) {
    iVar4 = *(int *)(lVar9 + 0xc);
  }
  else if (lVar10 == 0) {
    iVar4 = *(int *)(lVar9 + 0x4c);
  }
  else if (lVar10 == param_1) {
    iVar4 = *(int *)(lVar9 + 0x28);
  }
  else {
    iVar4 = *(int *)(lVar9 + 0x1c);
  }
  uVar5 = FUN_140470540(param_1,iVar4);
  *(undefined4 *)(param_1 + 0x1d8) = uVar5;
  if ((iVar4 != 0) &&
     ((((*(int *)(lVar9 + 0x38) == 0 || (*(int *)(lVar9 + 0x3c) == 0)) ||
       ((*(int *)(lVar9 + 0x3c) == 7 && (iVar4 != *(int *)(lVar9 + 0x54))))) &&
      (*(longlong *)(param_1 + 0x16e8) != 0)))) {
    uVar5 = FUN_140470540(param_1,iVar4);
    piVar11 = (int *)(**(code **)(**(longlong **)(param_1 + 0x16e8) + 0x1a8))
                               (*(longlong **)(param_1 + 0x16e8),uVar5,param_4);
    lVar12 = local_118;
    if (*piVar11 != 0x96) {
      iVar3 = *(int *)(param_1 + 0x1428);
      FUN_140470b80(param_1,~piVar11[2] & 1,piVar11[2] & 8);
      if ((*(int *)(param_1 + 0x1428) == 0x3f) != (iVar3 == 0x3f)) {
        uVar5 = FUN_140470540(param_1,iVar4);
        piVar11 = (int *)(**(code **)(**(longlong **)(param_1 + 0x16e8) + 0x1a8))
                                   (*(longlong **)(param_1 + 0x16e8),uVar5,param_4);
        if (*piVar11 == 0x96) {
          uVar7 = *(uint *)(param_1 + 0x1428);
          lVar12 = local_118;
          if (*(longlong *)(param_1 + 0xcc0) != 0) {
            uVar6 = FUN_140467ed0(param_1);
            *(uint *)(param_1 + 0x142c) = *(uint *)(param_1 + 0x142c) & 0xfffffffb;
            *(uint *)(param_1 + 0x142c) = *(uint *)(param_1 + 0x142c) | ~uVar7 & 4;
            uVar7 = *(uint *)(param_1 + 0x142c);
            if (((uVar6 & 0xfffffff6) == 0) && (uVar6 != 1)) {
              uVar7 = 0x3f;
            }
            lVar12 = local_118;
            if (*(uint *)(param_1 + 0x1428) != uVar7) {
              if (uVar7 == 0x3f) {
                FUN_140195d70(param_1 + 0x1430);
                FUN_140195d70(param_1 + 0x1478);
                (**(code **)(**(longlong **)(param_1 + 0xcc0) + 0xa8))
                          (*(longlong **)(param_1 + 0xcc0),3,3);
                *(undefined4 *)(param_1 + 0x14c0) = 1;
                if (*(longlong *)(param_1 + 0x16e8) != 0) {
                  FUN_140471ef0(param_1,1,1);
                  FUN_140471ef0(param_1,1,0);
                }
              }
              else if (*(uint *)(param_1 + 0x1428) == 0x3f) {
                local_138 = local_138 & 0xffffffff00000000;
                local_128 = 0x40471e50;
                uStack_124 = 1;
                local_120 = 0;
                uStack_11c = 0;
                local_130 = param_1;
                FUN_140195960(param_1 + 0x1430,0x96,&local_138,4);
                local_128 = 0x40471ea0;
                uStack_124 = 1;
                local_138 = local_138 & 0xffffffff00000000;
                local_120 = 0;
                uStack_11c = 0;
                local_130 = param_1;
                FUN_140195960(param_1 + 0x1478,0x96,&local_138,4);
                *(undefined4 *)(param_1 + 0x14c0) = 1;
              }
              if ((uVar7 & 4) != 0) {
                FUN_140195d70(param_1 + 0x1398);
              }
              if ((uVar7 & 0x10) != 0) {
                FUN_140195d70(param_1 + 0x13e0);
              }
              *(uint *)(param_1 + 0x1428) = uVar7;
              lVar12 = local_118;
            }
          }
          goto LAB_140473ee0;
        }
      }
      uVar15 = (ulonglong)piVar11[4];
      if (*piVar11 == iVar4) {
        if (uVar15 < 8) {
          uVar16 = *(undefined4 *)(&DAT_140b670f0 + uVar15 * 4);
        }
        else {
          uVar16 = 9;
        }
      }
      else if (uVar15 < 8) {
        uVar16 = *(undefined4 *)(&DAT_140b67110 + uVar15 * 4);
      }
      else {
        uVar16 = 0xd;
      }
      lVar12 = FUN_1404695e0(param_1);
      if ((((*(int *)(param_1 + 0x12e0) != 0) && (*(float *)(param_1 + 0x12d4) == 0.0)) &&
          (DAT_140b79cc4 < (float)(*(uint *)(param_1 + 0x12c8) & DAT_140b7b500))) &&
         (((*(int *)(param_1 + 0x1354) == 0 || ((*(byte *)(piVar11 + 1) & 2) != 0)) ||
          ((lVar12 != 0 &&
           ((*(uint *)(*(longlong *)(*(longlong *)(lVar12 + 0x138) + 0x70) + 0x108) & 0x400000) != 0
           )))))) {
        *(undefined4 *)(param_1 + 0x1310) = 1;
        *(undefined4 *)(param_1 + 0x12d4) = 0x3e19999a;
        local_138 = 0;
        local_130 = 0x3f800000;
        local_128 = 0;
        uStack_124 = 0;
        local_120 = 0;
        uStack_11c = 0;
        (**(code **)(**(longlong **)(param_1 + 0x16e8) + 0x248))
                  (*(longlong **)(param_1 + 0x16e8),7,&local_138);
      }
      local_138 = CONCAT44(param_4,uVar5);
      local_130 = 0x3f800000;
      uStack_124 = 2;
      local_120 = 0;
      uStack_11c = 0;
      local_128 = uVar16;
      (**(code **)(**(longlong **)(param_1 + 0x16e8) + 0x248))
                (*(longlong **)(param_1 + 0x16e8),4,&local_138);
      plVar8 = *(longlong **)(param_1 + 0x15e0);
      lVar12 = local_118;
      if (((plVar8 != (longlong *)0x0) && (*(int *)((longlong)plVar8 + 0x1a4) != 0)) &&
         ((*(undefined4 *)((longlong)plVar8 + 0x1a4) = 0, (int)plVar8[0x35] == 2 ||
          (((int)plVar8[0x3f] == 0 || (*(int *)((longlong)plVar8 + 0x1fc) != 0)))))) {
        (**(code **)(*plVar8 + 0x50))(plVar8,1);
        lVar12 = local_118;
      }
    }
  }
LAB_140473ee0:
  plVar8 = (longlong *)(param_1 + 0x1a0);
  if ((*(int *)plVar8 != 0) && (*(longlong *)(param_1 + 0x1a8) != 0)) {
    uVar7 = FUN_1405e2410(DAT_140c65ba0,plVar8,1);
    param_6 = param_6 | uVar7;
  }
  if (param_6 == 0) {
    FUN_1404dde90(local_108);
    lVar13 = FUN_14018b280(0x60);
    if (lVar13 == 0) {
      plVar14 = (longlong *)0x0;
    }
    else {
      plVar14 = (longlong *)FUN_1404db7e0(lVar13,param_1);
    }
    lVar13 = 0;
    local_130 = 0;
    local_128 = 0;
    uStack_124 = 0;
    local_120 = 0;
    uStack_11c = 0;
    sVar1 = DAT_140b0a7c8;
    while (sVar1 != 0) {
      lVar13 = lVar13 + 1;
      sVar1 = (&DAT_140b0a7c8)[lVar13];
    }
    FUN_14001c1b0(&local_138,&DAT_140b0a7c8,&DAT_140b0a7c8 + lVar13);
    FUN_1400b7480(local_108,plVar14);
    (**(code **)(*plVar14 + 0x48))(plVar14,&local_138);
    if (local_130 != 0) {
      FUN_14018b900(local_130,0);
    }
    if (param_5 == 0) {
      if (lVar12 == param_1) {
        FUN_1400b75f0(local_108,*(undefined4 *)(lVar9 + 8));
      }
      else {
        FUN_1400b75f0(local_108,*(undefined4 *)(lVar9 + 4));
      }
    }
    else if (lVar10 == 0) {
      if (lVar12 == param_1) {
        FUN_1400b75f0(local_108,*(undefined4 *)(lVar9 + 0x48));
      }
      else {
        FUN_1400b75f0(local_108,*(undefined4 *)(lVar9 + 0x44));
      }
    }
    else {
      lVar13 = FUN_14018b280(0x60);
      if (lVar10 == param_1) {
        if (lVar13 == 0) {
          plVar14 = (longlong *)0x0;
        }
        else {
          plVar14 = (longlong *)FUN_1404db7e0(lVar13,lVar10);
        }
        lVar10 = 0;
        local_130 = 0;
        local_128 = 0;
        uStack_124 = 0;
        local_120 = 0;
        uStack_11c = 0;
        wVar2 = u_target_140b0a7d8[0];
        while (wVar2 != L'\0') {
          lVar10 = lVar10 + 1;
          wVar2 = L"target"[lVar10];
        }
        FUN_14001c1b0(&local_138,L"target",L"target" + lVar10);
        FUN_1400b7480(local_108,plVar14);
        (**(code **)(*plVar14 + 0x48))(plVar14,&local_138);
        if (local_130 != 0) {
          FUN_14018b900(local_130,0);
        }
        if (lVar12 == param_1) {
          uVar5 = *(undefined4 *)(lVar9 + 0x24);
        }
        else {
          uVar5 = *(undefined4 *)(lVar9 + 0x20);
        }
      }
      else {
        if (lVar13 == 0) {
          plVar14 = (longlong *)0x0;
        }
        else {
          plVar14 = (longlong *)FUN_1404db7e0(lVar13,lVar10);
        }
        lVar13 = 0;
        local_130 = 0;
        local_128 = 0;
        uStack_124 = 0;
        local_120 = 0;
        uStack_11c = 0;
        wVar2 = u_target_140b0a7d8[0];
        while (wVar2 != L'\0') {
          lVar13 = lVar13 + 1;
          wVar2 = L"target"[lVar13];
        }
        FUN_14001c1b0(&local_138,L"target",L"target" + lVar13);
        FUN_1400b7480(local_108,plVar14);
        (**(code **)(*plVar14 + 0x48))(plVar14,&local_138);
        if (local_130 != 0) {
          FUN_14018b900(local_130,0);
        }
        if (lVar12 == param_1) {
          uVar5 = *(undefined4 *)(lVar9 + 0x18);
        }
        else if (lVar12 == lVar10) {
          uVar5 = *(undefined4 *)(lVar9 + 0x14);
        }
        else {
          uVar5 = *(undefined4 *)(lVar9 + 0x10);
        }
      }
      FUN_1400b75f0(local_108,uVar5);
    }
    if ((local_f8 != local_f0) && (local_d8 != local_d0)) {
      if ((lVar12 == param_1) || ((*(int *)plVar8 == 0 || (*(longlong *)(param_1 + 0x1a8) == 0)))) {
        lVar9 = FUN_1400b7660(local_108);
        FUN_140474b80(param_1,0x1b,*(undefined8 *)(lVar9 + 8));
      }
      else {
        local_118 = *plVar8;
        uStack_110 = *(undefined4 *)(param_1 + 0x1a8);
        uStack_10c = *(undefined4 *)(param_1 + 0x1ac);
        lVar9 = FUN_1400b7660(local_108);
        puVar17 = &DAT_140b7b704;
        if (*(undefined2 **)(param_1 + 0x10) != (undefined2 *)0x0) {
          puVar17 = *(undefined2 **)(param_1 + 0x10);
        }
        uVar5 = FUN_140405ac0(DAT_140c658a0,&local_118,puVar17,*(undefined8 *)(lVar9 + 8));
        local_138 = 0;
        local_130 = 0;
        local_128 = 0;
        uStack_124 = 0;
        local_120 = 0;
        uStack_11c = 0;
        lVar9 = FUN_1400b7660(local_108);
        local_138 = *(ulonglong *)(lVar9 + 8);
        bVar18 = false;
        if (*(longlong *)(DAT_140c65898 + 0x78) != 0) {
          bVar18 = *(int *)(param_1 + 8) == *(int *)(*(longlong *)(DAT_140c65898 + 0x78) + 8);
        }
        puVar17 = &DAT_140b7b704;
        if (*(undefined2 **)(param_1 + 0x10) != (undefined2 *)0x0) {
          puVar17 = *(undefined2 **)(param_1 + 0x10);
        }
        FUN_1404045c0(DAT_140c658a0,0x1b,0,*(undefined4 *)(param_1 + 8),puVar17,0,0,&local_138,
                      bVar18,0,0,0,uVar5,*(undefined1 *)(param_1 + 0x1b2));
      }
    }
    if (local_48 != 0) {
      FUN_14018b900(local_48,0);
    }
    FUN_1400b7390(local_108);
  }
  return;
}



==== FUN_1404daac0 @ 1404daac0 ====

undefined8 FUN_1404daac0(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 31000) == 0) &&
     ((*(longlong *)(param_1 + 0x7198) == 0 ||
      (*(int *)(*(longlong *)(param_1 + 0x7198) + 0x50) == 0)))) {
    plVar2 = *(longlong **)(param_1 + 0x7588);
    uVar3 = 0x18;
  }
  else {
    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                      (*(longlong **)(param_1 + 0x7588),0x1b);
    if (iVar1 != 0) {
      return 1;
    }
    plVar2 = *(longlong **)(param_1 + 0x7588);
    uVar3 = 0x1d;
  }
  iVar1 = (**(code **)(*plVar2 + 200))(plVar2,uVar3);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                    (*(longlong **)(param_1 + 0x7588),0x20);
  if (((iVar1 != 0) &&
      (iVar1 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                         (*(longlong **)(param_1 + 0x7588),0x2f), iVar1 != 0)) &&
     (iVar1 = FUN_14055a260(param_1 + 0x7330), iVar1 == 0)) {
    return 1;
  }
  return 0;
}



==== FUN_1404dad90 @ 1404dad90 ====

bool FUN_1404dad90(longlong param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 31000) != 0) ||
     ((*(longlong *)(param_1 + 0x7198) != 0 &&
      (*(int *)(*(longlong *)(param_1 + 0x7198) + 0x50) != 0)))) {
    iVar1 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                      (*(longlong **)(param_1 + 0x7588),0x19);
    return iVar1 != 0;
  }
  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                    (*(longlong **)(param_1 + 0x7588),0x1b);
  if (iVar1 != 0) {
    return true;
  }
  iVar1 = FUN_1404dac20(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = (**(code **)(**(longlong **)(param_1 + 0x7588) + 200))
                        (*(longlong **)(param_1 + 0x7588),0x1d), iVar1 != 0)) {
    return true;
  }
  return false;
}



==== FUN_14050f270 @ 14050f270 ====

undefined8 FUN_14050f270(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined4 local_10;
  
  FUN_140057020(param_1,"DialogSys",&PTR_s_GetState_140b6a7c0);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_Inactive",0x14);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_TopicChoice",0x17);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_QuestAccept",0x17);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_QuestComplete",0x19);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_QuestIncomplete",0x1b);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_Vending",0x13);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_Training",0x14);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_TradeskillTraining",0x1e);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"DialogState_CraftingStation",0x1b);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  return 0;
}



==== FUN_140513900 @ 140513900 ====

undefined8 FUN_140513900(longlong param_1)

{
  undefined8 *puVar1;
  double *pdVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0();
  }
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  uVar4 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar1 + 1) = 5;
  *puVar1 = uVar4;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  iVar3 = DAT_140c7d620;
  FUN_140058710(param_1,"iPath",5);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d630;
  FUN_140058710(param_1,"nTotalDamageGiven",0x11);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d638;
  FUN_140058710(param_1,"nTotalCriticalDamageGiven",0x19);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d634;
  FUN_140058710(param_1,"nTotalCriticalHits",0x12);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d63c;
  FUN_140058710(param_1,"nTotalVulnerableDamageGiven",0x1b);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d62c;
  FUN_140058710(param_1,"nTotalDamageTaken",0x11);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d628;
  FUN_140058710(param_1,"nDeaths",7);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  iVar3 = DAT_140c7d624;
  FUN_140058710(param_1,"nKills",6);
  pdVar2 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  return 1;
}



==== FUN_1405512f0 @ 1405512f0 ====

void FUN_1405512f0(longlong param_1,undefined4 param_2,uint param_3)

{
  longlong lVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 *_Dst;
  undefined1 *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 in_stack_ffffffffffffff88;
  undefined1 local_68 [8];
  undefined2 *local_60;
  undefined2 *local_58;
  undefined2 *local_50;
  undefined1 local_48 [8];
  longlong local_40;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  uVar9 = (ulonglong)param_3;
  if (param_3 == *(uint *)(param_1 + 0x10)) {
    return;
  }
  if (*(uint *)(param_1 + 0x10) < param_3) {
    return;
  }
  lVar1 = *(longlong *)(param_1 + 0x18 + uVar9 * 8);
  if (lVar1 == 0) {
    return;
  }
  if ((*(byte *)(lVar1 + 8) & 8) != 0) {
    return;
  }
  local_60 = (undefined2 *)FUN_14018b280(0x10);
  local_50 = local_60 + 8;
  if (local_60 != (undefined2 *)0x0) {
    *local_60 = 0;
  }
  local_58 = local_60;
  FUN_140551d40(param_1,uVar9,local_68,1);
  puVar2 = local_60;
  if (((longlong)local_58 - (longlong)local_60 & 0xfffffffffffffffeU) == 0) goto LAB_14055159c;
  iVar3 = FUN_140551840(param_1,param_3);
  iVar4 = FUN_1405515c0(param_1,param_3);
  _Dst = (undefined2 *)FUN_14018b280(2);
  local_50 = _Dst + 1;
  local_60 = _Dst;
  memcpy(_Dst,&DAT_1409f27c4,0);
  if (_Dst != (undefined2 *)0x0) {
    *_Dst = 0;
  }
  local_58 = _Dst;
  if (iVar4 < iVar3) {
    iVar5 = FUN_140553750(param_1,param_3);
    if (iVar5 == 0) {
      uVar6 = FUN_140551630(param_1,uVar9);
      puVar7 = (undefined1 *)FUN_14018efa0(local_48,L"%s (%d%%)",puVar2,uVar6);
    }
    else {
      puVar7 = (undefined1 *)
               FUN_14018efa0(local_48,L"%s (%d/%d)",puVar2,iVar4,CONCAT44(uVar6,iVar3));
    }
    if (puVar7 != local_68) {
      FUN_14001c480(local_68,*(undefined8 *)(puVar7 + 8),*(undefined8 *)(puVar7 + 0x10));
      _Dst = local_60;
    }
    if (local_40 != 0) {
      FUN_14018b900(local_40,0);
    }
    if ((*(uint *)(lVar1 + 4) < 0x23) &&
       ((0x500000010U >> ((ulonglong)*(uint *)(lVar1 + 4) & 0x3f) & 1) != 0)) {
      uVar8 = 0x19;
      goto LAB_140551515;
    }
  }
  else {
    uVar8 = FUN_14034bdd0();
    puVar7 = (undefined1 *)FUN_14018efa0(local_48,L"%s (%s)",puVar2,uVar8);
    if (puVar7 != local_68) {
      FUN_14001c480(local_68,*(undefined8 *)(puVar7 + 8),*(undefined8 *)(puVar7 + 0x10));
      _Dst = local_60;
    }
    if (local_40 != 0) {
      FUN_14018b900(local_40,0);
    }
    if (*(int *)(lVar1 + 4) == 5) {
      uVar8 = 0x1b;
    }
    else {
      uVar8 = 0x7a;
      if (*(int *)(*(longlong *)(param_1 + 8) + 0x120) == 0) {
        uVar8 = 0x1a;
      }
    }
LAB_140551515:
    FUN_140051af0(1,uVar8);
  }
  lVar1 = *(longlong *)(DAT_140c65898 + 0x78);
  if (lVar1 != 0) {
    if ((*(uint *)(*(longlong *)(param_1 + 8) + 0xc) & 0x80000) == 0) {
      FUN_140430b90(*(undefined8 *)(DAT_140c65898 + 0x7340),*(undefined4 *)(lVar1 + 8),_Dst);
    }
    else {
      FUN_1400ea3e0(*(undefined8 *)(DAT_140c65898 + 0x7340),"ContractFloater",&DAT_1409e9544,
                    *(undefined4 *)(lVar1 + 8),_Dst,param_2);
    }
  }
  if (_Dst != (undefined2 *)0x0) {
    FUN_14018b900(_Dst,0);
  }
LAB_14055159c:
  if (puVar2 != (undefined2 *)0x0) {
    FUN_14018b900(puVar2,0);
  }
  return;
}



==== FUN_1406625d0 @ 1406625d0 ====

undefined4 FUN_1406625d0(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  undefined8 local_28;
  undefined4 local_20;
  
  FUN_1400569b0(param_1,"Game.Quest");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = puVar1[-2];
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(puVar1 + -1);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"__index",7);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  ppuVar5 = &PTR_DAT_140c5b8c0;
  puVar6 = PTR_DAT_140c5b8c0;
  while (puVar6 != (undefined *)0x0) {
    puVar6 = ppuVar5[1];
    if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
        *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
      FUN_14005e2c0(param_1);
    }
    lVar3 = FUN_140060ab0(param_1,0);
    *(undefined **)(lVar3 + 0x20) = puVar6;
    plVar2 = *(longlong **)(param_1 + 0x10);
    *plVar2 = lVar3;
    *(undefined4 *)(plVar2 + 1) = 6;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    puVar6 = *ppuVar5;
    uVar4 = FUN_1400580e0(param_1,0xfffffffe);
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (puVar6[lVar3] != '\0');
    local_28 = FUN_140062650(param_1,puVar6);
    local_20 = 4;
    FUN_14005ea50(param_1,uVar4,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    ppuVar5 = ppuVar5 + 2;
    puVar6 = *ppuVar5;
  }
  *(undefined8 *)(param_1 + 0x10) = uVar4;
  FUN_140057020(param_1,"Quest",&PTR_DAT_140b6fcc0);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x3ff0000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_Item",0x15);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_Reputation",0x1b);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_Money",0x16);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_TradeSkillXp",0x1d);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_GrantTradeskill",0x20);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_AccountItem",0x1c);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_AccountCurrency",0x20);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_GenericUnlockAccount",0x25);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4022000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_GenericUnlockCharacter",0x27);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4024000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"Quest2RewardType_RotationEssence",0x20);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Unknown",0x12);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Accepted",0x13);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Achieved",0x13);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Completed",0x14);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Botched",0x12);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Mentioned",0x14);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Abandoned",0x14);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"QuestState_Ignored",0x12);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0xbff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"kQuestInvalidChecklistIndex",0x1b);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"kQuestMaxObjective",0x12);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0xbff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"kQuestInvalidObjectiveIdx",0x19);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"kQuestInvalidQuestId",0x14);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x40c3880000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = FUN_140062650(param_1,"kQuestShareAcceptTimeoutMs",0x1a);
  local_20 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_28,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  FUN_140058710(param_1,"QuestRepeatPeriod",0x11);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  uVar4 = FUN_14005c1b0(param_1,0,0);
  lVar3 = 5;
  *puVar1 = uVar4;
  *(undefined4 *)(puVar1 + 1) = 5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  do {
    FUN_1400f06f0(param_1);
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  return 1;
}



==== FUN_14066a570 @ 14066a570 ====

undefined8 FUN_14066a570(longlong param_1)

{
  undefined4 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 local_18;
  undefined4 local_10;
  
  plVar2 = *(longlong **)(param_1 + 0x18);
  plVar3 = *(longlong **)(param_1 + 0x10);
  plVar5 = (longlong *)&DAT_140a12138;
  if (plVar2 < plVar3) {
    plVar5 = plVar2;
  }
  if ((int)plVar5[1] == 2) {
    lVar6 = *plVar5;
LAB_14066a5b3:
    if (lVar6 != 0) {
      plVar5 = (longlong *)&DAT_140a12138;
      if (plVar2 < plVar3) {
        plVar5 = plVar2;
      }
      iVar4 = (int)plVar5[1];
      if ((iVar4 == 5) || (iVar4 == 7)) {
        lVar6 = *(longlong *)(*plVar5 + 0x10);
      }
      else {
        lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0xe0 + (longlong)iVar4 * 8);
      }
      if (lVar6 != 0) {
        *plVar3 = lVar6;
        *(undefined4 *)(plVar3 + 1) = 5;
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
        lVar6 = *(longlong *)(param_1 + 0x20);
        local_18 = FUN_140062650(param_1,"Game.GalacticArchiveArticle",0x1b);
        local_10 = 4;
        FUN_14005e8e0(param_1,lVar6 + 0xa0,&local_18,*(undefined8 *)(param_1 + 0x10));
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
        lVar6 = *(longlong *)(param_1 + 0x10);
        uVar7 = 0;
        puVar1 = (undefined4 *)(lVar6 + -0x20);
        if (((undefined4 *)(lVar6 + -0x10) == &DAT_140a12138) || (puVar1 == &DAT_140a12138)) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_14005ac20((undefined4 *)(lVar6 + -0x10),puVar1);
        }
        *(undefined4 **)(param_1 + 0x10) = puVar1;
        *(undefined4 *)(lVar6 + -0x18) = 1;
        *puVar1 = (int)CONCAT71((int7)((ulonglong)uVar7 >> 8),iVar4 != 0);
        goto LAB_14066a697;
      }
    }
  }
  else if ((int)plVar5[1] == 7) {
    lVar6 = *plVar5 + 0x30;
    goto LAB_14066a5b3;
  }
  *(undefined4 *)plVar3 = 0;
  *(undefined4 *)(plVar3 + 1) = 1;
LAB_14066a697:
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  return 1;
}



==== FUN_14066c710 @ 14066c710 ====

undefined8 FUN_14066c710(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  undefined8 local_18;
  undefined4 local_10;
  
  FUN_1400569b0(param_1,"Game.GalacticArchiveEntry");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = puVar1[-2];
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(puVar1 + -1);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"__index",7);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  ppuVar5 = &PTR_DAT_140c5be20;
  puVar6 = PTR_DAT_140c5be20;
  while (puVar6 != (undefined *)0x0) {
    puVar6 = ppuVar5[1];
    if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
        *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
      FUN_14005e2c0(param_1);
    }
    lVar3 = FUN_140060ab0(param_1,0);
    *(undefined **)(lVar3 + 0x20) = puVar6;
    plVar2 = *(longlong **)(param_1 + 0x10);
    *plVar2 = lVar3;
    *(undefined4 *)(plVar2 + 1) = 6;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    puVar6 = *ppuVar5;
    uVar4 = FUN_1400580e0(param_1,0xfffffffe);
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (puVar6[lVar3] != '\0');
    local_18 = FUN_140062650(param_1,puVar6);
    local_10 = 4;
    FUN_14005ea50(param_1,uVar4,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    ppuVar5 = ppuVar5 + 2;
    puVar6 = *ppuVar5;
  }
  *(undefined8 *)(param_1 + 0x10) = uVar4;
  FUN_140057020(param_1,"GalacticArchiveEntry",&PTR_DAT_140b6fd00);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryEnum_Text",0x15);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryEnum_TextAboveArt",0x1d);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryEnum_TextBelowArt",0x1d);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryEnum_EldanArchive",0x1d);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryHeaderEnum_Text",0x1b);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryHeaderEnum_TextWithPortrait",0x27);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"ArchiveEntryHeaderEnum_TextWithIcon",0x23);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  return 1;
}



==== FUN_140679e50 @ 140679e50 ====

undefined8 FUN_140679e50(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  undefined *puVar6;
  undefined8 local_38;
  undefined4 local_30;
  
  FUN_1400569b0(param_1,"Game.PathMission");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = puVar1[-2];
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(puVar1 + -1);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"__index",7);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  ppuVar5 = &PTR_DAT_140c5c490;
  puVar6 = PTR_DAT_140c5c490;
  while (puVar6 != (undefined *)0x0) {
    puVar6 = ppuVar5[1];
    if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
        *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
      FUN_14005e2c0(param_1);
    }
    lVar3 = FUN_140060ab0(param_1,0);
    *(undefined **)(lVar3 + 0x20) = puVar6;
    plVar2 = *(longlong **)(param_1 + 0x10);
    *plVar2 = lVar3;
    *(undefined4 *)(plVar2 + 1) = 6;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    puVar6 = *ppuVar5;
    uVar4 = FUN_1400580e0(param_1,0xfffffffe);
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (puVar6[lVar3] != '\0');
    local_38 = FUN_140062650(param_1,puVar6);
    local_30 = 4;
    FUN_14005ea50(param_1,uVar4,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    ppuVar5 = ppuVar5 + 2;
    puVar6 = *ppuVar5;
  }
  *(undefined8 *)(param_1 + 0x10) = uVar4;
  FUN_140057020(param_1,"PathMission",&PTR_DAT_140b6fe10);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathType_Soldier",0x16);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathType_Settler",0x16);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathType_Scientist",0x18);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathType_Explorer",0x17);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionState_NoMission",0x1a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionState_Unlocked",0x19);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionState_Started",0x18);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionState_Complete",0x19);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Soldier_Holdout",0x1f);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Soldier_Assassinate",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Soldier_Demolition",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Soldier_Rescue",0x1e);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Soldier_SWAT",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x4020000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Soldier_Script",0x1e);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4033000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Settler_Hub",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4022000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Settler_Script",0x1e);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4035000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Settler_Infrastructure",0x26);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x4039000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Settler_Mayor",0x1d);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x403a000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Settler_Sheriff",0x1f);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x403b000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Settler_Scout",0x1d);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_Scan",0x1e);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_ScanChecklist",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4034000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_FieldStudy",0x24);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4024000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_Script",0x20);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4036000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_Experimentation",0x29);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4037000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_SpecimenSurvey",0x28);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x4038000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Scientist_DatacubeDiscovery",0x2b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_Area",0x1d);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4026000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_Script",0x1f);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4028000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_Door",0x1d);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x402a000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_ScavengerHunt",0x26);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402e000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_Vista",0x1e);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4030000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_ExploreZone",0x24);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4031000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_ActivateChecklist",0x2a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4032000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathMissionType_Explorer_PowerMap",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailUnknown",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailTimeOut",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailDefenceDeath",0x28);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailNoParticipants",0x2a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailLeaveArea",0x25);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailDeath",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailLostResources",0x29);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_FailParticipation",0x29);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_ScriptCancel",0x24);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4022000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PlayerPathSoldierResult_Success",0x1f);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathSoldierEventType_Holdout",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PathSoldierEventType_Defend",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_Timed");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_TimedDefend");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_TowerDefense");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_WhackAMole");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_WhackAMoleTimed");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_StopTheThieves");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PathSoldierEventType_StopTheThievesTimed");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PlayerPathSoldierEventMode_Inactive");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PlayerPathSoldierEventMode_Setup");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PlayerPathSoldierEventMode_InitialDelay");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"PlayerPathSoldierEventMode_Active");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"SoldierActivateMode_Count");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"SoldierActivateMode_Checklist");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"SoldierActivateMode_DelayedChecklist");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"SettlerAvenue_Economy");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"SettlerAvenue_QualityOfLife");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"SettlerAvenue_Security");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"TowerDefenseImprovementType_Trap");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"TowerDefenseImprovementType_Wall");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"TowerDefenseImprovementType_Turret");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"TowerDefenseImprovementType_Support");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"TowerDefenseImprovementType_Recruit");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ExplorerScavengerClueType_ActivateCreature");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ExplorerScavengerClueType_CreatureDrop");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ExplorerScavengerClueType_Dig");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistExperimentationResult_Incorrect");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistExperimentationResult_CorrectPattern");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistExperimentationResult_Correct");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_Flora");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_Fauna");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_Tech");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_Mineral");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_Elemental");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_Magic");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058a40(param_1,0xfffffffe,"ScientistCreatureType_History");
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400f0490(param_1);
  return 1;
}



==== FUN_140687d40 @ 140687d40 ====

undefined4 FUN_140687d40(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  longlong lVar6;
  undefined *puVar7;
  undefined8 local_38;
  undefined4 local_30;
  
  FUN_1400569b0(param_1,"Game.PublicEvent");
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = puVar1[-2];
  *(undefined4 *)(puVar1 + 1) = *(undefined4 *)(puVar1 + -1);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"__index",7);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  ppuVar5 = &PTR_DAT_140c5ca00;
  puVar7 = PTR_DAT_140c5ca00;
  while (puVar7 != (undefined *)0x0) {
    puVar7 = ppuVar5[1];
    if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
        *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
      FUN_14005e2c0(param_1);
    }
    lVar3 = FUN_140060ab0(param_1,0);
    *(undefined **)(lVar3 + 0x20) = puVar7;
    plVar2 = *(longlong **)(param_1 + 0x10);
    *plVar2 = lVar3;
    *(undefined4 *)(plVar2 + 1) = 6;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
    puVar7 = *ppuVar5;
    uVar4 = FUN_1400580e0(param_1,0xfffffffe);
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (puVar7[lVar3] != '\0');
    local_38 = FUN_140062650(param_1,puVar7);
    local_30 = 4;
    FUN_14005ea50(param_1,uVar4,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    ppuVar5 = ppuVar5 + 2;
    puVar7 = *ppuVar5;
  }
  *(undefined8 *)(param_1 + 0x10) = uVar4;
  FUN_140057020(param_1,"PublicEvent",&PTR_DAT_140b6fe60);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventParticipantRemoveReason_Logout",0x29);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventParticipantRemoveReason_CompleteSuccess",0x32);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventParticipantRemoveReason_CompleteFailure",0x32);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventParticipantRemoveReason_LeftArea",0x2b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardTier_None",0x1a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardTier_Bronze",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardTier_Silver",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardTier_Gold",0x1a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardType_None",0x1a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardType_Individual",0x20);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardType_Speed",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardType_Completion",0x20);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardType_Nightmare",0x1f);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventRewardType_Script",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_WorldEvent",0x1a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Dungeon",0x17);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_PVP_Warplot",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_PVP_Battleground_Vortex",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_PVP_Battleground_HoldTheLine",0x2c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_PVP_Battleground_Cannon",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_PVP_Battleground_Sabotage",0x29);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Malgrave",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x4020000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Hycrest",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4022000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Skywatch",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4028000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Whitevale",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Galeras",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x402e000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Astrovoid",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4031000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_Farside",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4024000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_PVP_Arena",0x19);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4026000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  lVar6 = 0x18;
  local_38 = FUN_140062650(param_1,"PublicEventType_SubEvent",0x18);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402a000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_NorthernWilds",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4030000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_LiveEvent",0x19);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4032000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Adventure_LevianBay",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4033000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Shiphand",0x18);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4035000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_NonCombatEvent",0x1e);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4036000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"PublicEventType_Raid",0x14);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar3 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  FUN_140058710(param_1,"PublicEventStatType",0x13);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  uVar4 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar1 + 1) = 5;
  *puVar1 = uVar4;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  do {
    FUN_1400f06f0(param_1);
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar4 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar4,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  return 1;
}



==== FUN_1406a47d0 @ 1406a47d0 ====

undefined8 FUN_1406a47d0(longlong param_1)

{
  undefined8 *puVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 extraout_XMM0_Qa;
  longlong local_res10;
  
  lVar5 = FUN_140056ab0(param_1,1,"Game.ICComm");
  lVar6 = 0;
  iVar4 = 0;
  lVar7 = lVar6;
  if (lVar5 != 0) {
    lVar7 = *(longlong *)(lVar5 + 8);
  }
  lVar5 = FUN_140056bb0(param_1,2);
  if (lVar5 != 0) {
    FUN_14018d320(&local_res10,lVar5);
    lVar6 = local_res10;
  }
  iVar3 = FUN_1403e1170(lVar6,0x1b);
  if (iVar3 == 0) {
    puVar1 = *(undefined8 **)(param_1 + 0x10);
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 1) = 3;
  }
  else {
    lVar7 = *(longlong *)(lVar7 + 0x68);
    if (*(int *)(lVar7 + 0x2c) != 0) {
      iVar4 = FUN_140631240(extraout_XMM0_Qa,*(undefined8 *)(lVar7 + 0x18),
                            *(undefined4 *)(lVar7 + 0x28),lVar5,0);
    }
    pdVar2 = *(double **)(param_1 + 0x10);
    *(undefined4 *)(pdVar2 + 1) = 3;
    *pdVar2 = (double)iVar4;
  }
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (lVar6 != 0) {
    (**(code **)(*(longlong *)(lVar6 + -0x10) + 8))(lVar6 + -0x10);
  }
  return 1;
}



==== FUN_1406a48d0 @ 1406a48d0 ====

undefined8 FUN_1406a48d0(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  double *pdVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 extraout_XMM0_Qa;
  longlong local_res10;
  undefined1 local_38 [8];
  longlong local_30;
  
  lVar3 = FUN_140056ab0(param_1,1,"Game.ICComm");
  lVar6 = 0;
  iVar2 = 0;
  lVar7 = lVar6;
  if (lVar3 != 0) {
    lVar7 = *(longlong *)(lVar3 + 8);
  }
  uVar4 = FUN_140056bb0(param_1,2);
  FUN_14018f2d0(local_38,uVar4);
  lVar3 = FUN_140056bb0(param_1,3);
  if (lVar3 != 0) {
    FUN_14018d320(&local_res10,lVar3);
    lVar6 = local_res10;
  }
  iVar1 = FUN_1403e1170(lVar6,0x1b);
  if (iVar1 == 0) {
    pdVar5 = *(double **)(param_1 + 0x10);
    *pdVar5 = 0.0;
  }
  else {
    lVar7 = *(longlong *)(lVar7 + 0x68);
    if (*(int *)(lVar7 + 0x2c) != 0) {
      iVar2 = FUN_140631240(extraout_XMM0_Qa,*(undefined8 *)(lVar7 + 0x18),
                            *(undefined4 *)(lVar7 + 0x28),lVar3,local_30);
    }
    pdVar5 = *(double **)(param_1 + 0x10);
    *pdVar5 = (double)iVar2;
  }
  *(undefined4 *)(pdVar5 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (lVar6 != 0) {
    (**(code **)(*(longlong *)(lVar6 + -0x10) + 8))(lVar6 + -0x10);
  }
  if (local_30 != 0) {
    FUN_14018b900(local_30,0);
  }
  return 1;
}



==== FUN_1406f26c0 @ 1406f26c0 ====

undefined8 FUN_1406f26c0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 local_18;
  undefined4 local_10;
  
  lVar1 = *(longlong *)(param_2 + 0x10);
  DAT_140c65c48 = param_1;
  FUN_140057020(lVar1,"Tooltip",&PTR_s_GetItemTooltipForm_140b725a0);
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4071800000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipWidth",0xc);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4068800000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipLeftColumn",0x11);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4055000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipRightColumn",0x12);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Default",0x1b);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Grid",0x18);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_ItemData",0x1c);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_ItemInstance",0x20);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Spell",0x19);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4014000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_GameCommand",0x1f);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4018000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Map",0x17);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x401c000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_UnitOrProp",0x1e);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4020000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Macro",0x19);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4022000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Reputation",0x1e);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4024000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Money",0x19);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4026000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_TradeSkill",0x1e);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x4028000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_Xp",0x16);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(lVar1 + 0x10);
  *puVar2 = 0x402a000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + 0x10;
  lVar3 = *(longlong *)(lVar1 + 0x10);
  local_18 = FUN_140062650(lVar1,"TooltipGenerateType_PetCommand",0x1e);
  local_10 = 4;
  FUN_14005ea50(lVar1,lVar3 + -0x20,&local_18,*(longlong *)(lVar1 + 0x10) + -0x10);
  *(longlong *)(lVar1 + 0x10) = *(longlong *)(lVar1 + 0x10) + -0x20;
  return param_1;
}



==== FUN_140709460 @ 140709460 ====

undefined8 FUN_140709460(longlong param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  double *pdVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint *puVar8;
  longlong *plVar9;
  longlong *plVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined4 uVar17;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_48 [8];
  longlong local_40;
  
  FUN_140057020(param_1,"GameLib");
  uVar16 = 0;
  uVar4 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c653ec == 0) && (iVar5 = FUN_140211ce0(), -1 < iVar5)) {
      uVar4 = (**(code **)(*DAT_140c64278 + 0x28))();
    }
  }
  else {
    uVar4 = (*DAT_140c63838)(&PTR_u_LuaEvent_140a6b2b0,DAT_140c63858);
  }
  uVar11 = uVar16;
  if (uVar4 != 0) {
    do {
      if (DAT_140c63848 == (code *)0x0) {
        if ((DAT_140c653ec == 0) && (iVar5 = FUN_140211ce0(), -1 < iVar5)) {
          lVar6 = (**(code **)(*DAT_140c64278 + 0x20))(DAT_140c64278,uVar11);
          goto LAB_14070953b;
        }
      }
      else {
        lVar6 = (*DAT_140c63848)(&PTR_u_LuaEvent_140a6b2b0,uVar11);
LAB_14070953b:
        if (lVar6 != 0) {
          uVar1 = *(ulonglong *)(lVar6 + 8);
          uVar12 = uVar16;
          if ((uVar1 != 0) && (uVar1 <= DAT_140c3fe70)) {
            uVar12 = DAT_140c3fe68 + uVar1;
          }
          FUN_14018f0e0(local_48,uVar12);
          lVar6 = local_40;
          if (local_40 == 0) {
            *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 8) = 0;
          }
          else {
            lVar13 = -1;
            do {
              lVar13 = lVar13 + 1;
            } while (*(char *)(local_40 + lVar13) != '\0');
            if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
                *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
              FUN_14005e2c0(param_1);
            }
            puVar2 = *(undefined8 **)(param_1 + 0x10);
            uVar7 = FUN_140062650(param_1,lVar6);
            *(undefined4 *)(puVar2 + 1) = 4;
            *puVar2 = uVar7;
          }
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
          lVar13 = *(longlong *)(param_1 + 0x10);
          lVar14 = -1;
          do {
            lVar14 = lVar14 + 1;
          } while (*(char *)(lVar6 + lVar14) != '\0');
          local_58 = FUN_140062650(param_1,lVar6);
          local_50 = 4;
          FUN_14005ea50(param_1,lVar13 + -0x20,&local_58,*(longlong *)(param_1 + 0x10) + -0x10);
          *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
          if (lVar6 != 0) {
            FUN_14018b900(lVar6,0);
          }
        }
      }
      uVar15 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar15;
    } while (uVar15 < uVar4);
  }
  local_58 = FUN_140062650(param_1,"GameLib",7);
  local_50 = 4;
  FUN_14005e8e0(param_1,param_1 + 0x78,&local_58,*(undefined8 *)(param_1 + 0x10));
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"RezType",7);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"WakeHere",8);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Holocrypt",9);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"ExitInstance",0xc);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4040000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"SpellCasterLocation",0x13);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"WakeHereServiceToken",0x14);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4050000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"CodeEnumMapOverlayType",0x16);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,&DAT_140b439c8,4);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Object",6);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"PathObjective",0xd);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"QuestObjective",0xe);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"TrackedUnit",0xb);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"CodeEnumEquipItemResult",0x17);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,&DAT_1409f883c,2);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Cooldown",8);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Invalid",7);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4014000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"LevelTooLow",0xb);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"WrongClass",10);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"WrongRace",9);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"CodeEnumAddonSaveLevel",0x16);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"General",7);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Account",7);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Realm",5);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Character",9);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"CodeEnumInputDevice",0x13);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,&DAT_140b43a74,4);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Keyboard",8);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Mouse",5);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"CodeEnumInputEventType",0x16);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,&DAT_1409f8864,3);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Click",5);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,&DAT_140b43a34,4);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"DoubleClick",0xb);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"DoubleHold",10);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Rapid",5);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4014000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"CodeEnumInputMouse",0x12);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,&DAT_140b439f0,4);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Right",5);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_140062650(param_1,"Middle",6);
  *(undefined4 *)(puVar2 + 1) = 4;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar7 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar7,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumInputModifier",0x15);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumInputModifierScancode",0x1d);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumInputSets",0x11);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumInputKeyLookupGroup",0x1b);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"CodeEnumDamageType",0x12);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumMissType",0x10);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumCombatResult",0x14);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar7 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"CodeEnumRace",0xc);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumClass",0xd);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumRecallCommand",0x15);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumPetStance",0x11);
  FUN_140058900(param_1);
  uVar11 = uVar16;
  do {
    if ((1 << ((byte)uVar11 & 0x1f) & 1U) != 0) break;
    uVar4 = (int)uVar11 + 1;
    uVar11 = (ulonglong)uVar4;
  } while (uVar4 < 5);
  FUN_1400eff50(param_1);
  uVar11 = uVar16;
  do {
    if ((1 << ((byte)uVar11 & 0x1f) & 2U) != 0) break;
    uVar4 = (int)uVar11 + 1;
    uVar11 = (ulonglong)uVar4;
  } while (uVar4 < 5);
  FUN_1400eff50(param_1);
  uVar11 = uVar16;
  do {
    if ((1 << ((byte)uVar11 & 0x1f) & 4U) != 0) break;
    uVar4 = (int)uVar11 + 1;
    uVar11 = (ulonglong)uVar4;
  } while (uVar4 < 5);
  FUN_1400eff50(param_1);
  uVar11 = uVar16;
  do {
    if ((1 << ((byte)uVar11 & 0x1f) & 8U) != 0) break;
    uVar4 = (int)uVar11 + 1;
    uVar11 = (ulonglong)uVar4;
  } while (uVar4 < 5);
  FUN_1400eff50(param_1);
  uVar11 = uVar16;
  do {
    if ((1 << ((byte)uVar11 & 0x1f) & 0x10U) != 0) break;
    uVar4 = (int)uVar11 + 1;
    uVar11 = (ulonglong)uVar4;
  } while (uVar4 < 5);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar6 = FUN_140200220(0x285);
  if (lVar6 == 0) {
    iVar5 = 10000;
  }
  else {
    iVar5 = *(int *)(lVar6 + 4);
  }
  pdVar3 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar3 + 1) = 3;
  *pdVar3 = (double)iVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar6 = *(longlong *)(param_1 + 0x10);
  local_58 = FUN_140062650(param_1,"ElderPointsPerGem",0x11);
  local_50 = 4;
  FUN_14005ea50(param_1,lVar6 + -0x20,&local_58,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar6 = FUN_140200220(0x285);
  if (lVar6 == 0) {
    iVar5 = 15000;
  }
  else {
    iVar5 = *(int *)(lVar6 + 8);
  }
  pdVar3 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar3 + 1) = 3;
  *pdVar3 = (double)iVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar6 = *(longlong *)(param_1 + 0x10);
  local_58 = FUN_140062650(param_1,"ElderPointsDailyMax",0x13);
  local_50 = 4;
  FUN_14005ea50(param_1,lVar6 + -0x20,&local_58,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar6 = FUN_140200220(0x285);
  if (lVar6 == 0) {
    iVar5 = 100;
  }
  else {
    iVar5 = *(int *)(lVar6 + 0xc);
  }
  pdVar3 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar3 + 1) = 3;
  *pdVar3 = (double)iVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar6 = *(longlong *)(param_1 + 0x10);
  local_58 = FUN_140062650(param_1,"ElderGemsMax",0xc);
  local_50 = 4;
  FUN_14005ea50(param_1,lVar6 + -0x20,&local_58,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  FUN_140058710(param_1,"CodeEnumUserText",0x10);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumUserTextFilterClass",0x1b);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"CodeEnumExitEvent",0x11);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumDuelState",0x11);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumZonePvpRules",0x14);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  uVar17 = 0x1f;
  FUN_1400f0490(param_1);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4024000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar6 = *(longlong *)(param_1 + 0x10);
  local_58 = FUN_140062650(param_1,"knMaxBankBagSlots",0x11);
  local_50 = 4;
  FUN_14005ea50(param_1,lVar6 + -0x20,&local_58,*(longlong *)(param_1 + 0x10) + -0x10,uVar17);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  FUN_140058710(param_1,"CodeEnumItemSlots",0x11);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumZoneCompletionType",0x1a);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CityDirectionType",0x11);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"CodeEnumConfirmButtonType",0x19);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"GuildHolomark",0xd);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"TelegraphColorSet",0x11);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"MapZone",7);
  FUN_140058900(param_1);
  while (DAT_140c658f8 != 0) {
    puVar8 = (uint *)(**(code **)(**(longlong **)(DAT_140c658f8 + 0x40) + 0x20))();
    if ((ulonglong)*puVar8 / 0x30 <= uVar16) break;
    if ((((DAT_140c658f8 != 0) &&
         (plVar9 = (longlong *)FUN_1404483b0((ulonglong)*puVar8,uVar16), plVar9 != (longlong *)0x0))
        && (plVar10 = (longlong *)(**(code **)(*plVar9 + 0x18))(plVar9), plVar10 != (longlong *)0x0)
        ) && ((uVar11 = (**(code **)(*plVar10 + 0x30))(plVar10), (uVar11 & 4) != 0 &&
              (uVar11 = (**(code **)(*plVar10 + 0x30))(plVar10), (uVar11 & 1) == 0)))) {
      (**(code **)*plVar9)(plVar9);
      (**(code **)(*plVar9 + 0x10))(plVar9);
      FUN_1400f06f0(param_1);
    }
    uVar16 = uVar16 + 1;
  }
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"CodeEnumHintType",0x10);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CodeEnumMoveSpeed",0x11);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_140058710(param_1,"CodeEnumHoloMark",0x10);
  FUN_140058900(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  FUN_1400eff50(param_1);
  lVar6 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar6 + -0x30,lVar6 + -0x20,lVar6 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  FUN_1400f0490(param_1);
  uVar17 = 4;
  FUN_1400f0490(param_1);
  local_58 = FUN_140062650(param_1,"GameLib",7);
  local_50 = 4;
  FUN_14005ea50(param_1,param_1 + 0x78,&local_58,*(longlong *)(param_1 + 0x10) + -0x10,uVar17);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  return 1;
}



==== FUN_14072fae0 @ 14072fae0 ====

undefined8 FUN_14072fae0(longlong param_1)

{
  ulonglong uVar1;
  short *psVar2;
  wchar_t wVar3;
  short sVar4;
  double *pdVar5;
  undefined8 *puVar6;
  longlong lVar7;
  size_t _Size;
  void *pvVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  short *psVar13;
  short *psVar14;
  longlong lVar15;
  uint uVar16;
  longlong lVar17;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_68 [8];
  void *local_60;
  undefined2 *local_58;
  void *local_50;
  undefined1 local_48 [8];
  longlong local_40;
  
  FUN_140057020(param_1,"ChatSystemLib",&PTR_s_GetChannels_140b74710);
  uVar16 = 0;
  if (DAT_140c63838 == (code *)0x0) {
    if ((DAT_140c6528c != 0) || (iVar10 = FUN_1401f1e80(), iVar10 < 0)) goto LAB_14072fd8d;
    uVar9 = (**(code **)(*DAT_140c64728 + 0x28))();
  }
  else {
    uVar9 = (*DAT_140c63838)(&PTR_u_ChatChannel_140a69870,DAT_140c63858);
  }
  if (uVar9 != 0) {
    do {
      piVar12 = (int *)0x0;
      if (DAT_140c63848 == (code *)0x0) {
        piVar11 = piVar12;
        if ((DAT_140c6528c == 0) && (iVar10 = FUN_1401f1e80(), -1 < iVar10)) {
          piVar11 = (int *)(**(code **)(*DAT_140c64728 + 0x20))(DAT_140c64728,uVar16);
        }
      }
      else {
        piVar11 = (int *)(*DAT_140c63848)(&PTR_u_ChatChannel_140a69870,uVar16,DAT_140c63858);
      }
      local_60 = (void *)0x0;
      local_50 = (void *)0x0;
      wVar3 = u_ChatChannel_140a613b8[0];
      while (wVar3 != L'\0') {
        piVar12 = (int *)((longlong)piVar12 + 1);
        wVar3 = L"ChatChannel"[(longlong)piVar12];
      }
      lVar17 = (longlong)piVar12 * 2 >> 1;
      uVar1 = lVar17 + 1;
      if (uVar1 < 0x7fffffffffffffff) {
        lVar7 = uVar1 * 2;
        local_60 = (void *)FUN_14018b280(lVar7,0);
        local_50 = (void *)(lVar7 + (longlong)local_60);
      }
      pvVar8 = local_60;
      _Size = lVar17 * 2;
      memcpy(local_60,L"ChatChannel",_Size);
      local_58 = (undefined2 *)(_Size + (longlong)pvVar8);
      psVar14 = (short *)0x0;
      psVar13 = psVar14;
      if (local_58 != (undefined2 *)0x0) {
        *local_58 = 0;
      }
      do {
        psVar2 = &DAT_1409f909e + (longlong)psVar13;
        psVar13 = (short *)((longlong)psVar13 + 1);
      } while (*psVar2 != 0);
      FUN_14001c310(local_68,&DAT_1409f909c,&DAT_1409f909c + (longlong)psVar13 * 2);
      uVar1 = *(ulonglong *)(piVar11 + 2);
      psVar13 = psVar14;
      if ((uVar1 != 0) && (uVar1 <= DAT_140c3fe70)) {
        psVar13 = (short *)(DAT_140c3fe68 + uVar1);
      }
      sVar4 = *psVar13;
      while (sVar4 != 0) {
        psVar14 = (short *)((longlong)psVar14 + 1);
        sVar4 = psVar13[(longlong)psVar14];
      }
      FUN_14001c310(local_68);
      pvVar8 = local_60;
      pdVar5 = *(double **)(param_1 + 0x10);
      iVar10 = *piVar11;
      *(undefined4 *)(pdVar5 + 1) = 3;
      *pdVar5 = (double)iVar10;
      *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
      FUN_14018f0e0(local_48,local_60);
      lVar7 = local_40;
      lVar17 = *(longlong *)(param_1 + 0x10);
      lVar15 = -1;
      do {
        lVar15 = lVar15 + 1;
      } while (*(char *)(local_40 + lVar15) != '\0');
      local_78 = FUN_140062650(param_1,local_40);
      local_70 = 4;
      FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
      *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
      if (lVar7 != 0) {
        FUN_14018b900(lVar7,0);
      }
      if (pvVar8 != (void *)0x0) {
        FUN_14018b900(pvVar8,0);
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < uVar9);
  }
LAB_14072fd8d:
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x3ff0000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_PassOwner",0x1b);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4000000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_AddModerator",0x1e);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4008000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_RemoveModerator",0x21);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4010000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_Muted",0x17);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4014000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_Unmuted",0x19);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4018000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_Kicked",0x18);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4020000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_AddPassword",0x1d);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4022000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelAction_RemovePassword",0x20);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x3ff0000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_DoesntExist",0x1d);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4000000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_BadPassword",0x1d);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4008000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NoPermissions",0x1f);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4010000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NoSpeaking",0x1c);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4014000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_Muted",0x17);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4018000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_Throttled",0x1b);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4020000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotInGroup",0x1c);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4022000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotInGuild",0x1c);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4024000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotInSociety",0x1e);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4026000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotGuildOfficer",0x21);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4028000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_AlreadyMember",0x1f);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x402a000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_BadName",0x19);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x402c000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotMember",0x1b);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x402e000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotInWarParty",0x1f);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar6 + 1) = 3;
  *puVar6 = 0x4030000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_NotWarPartyOfficer",0x24);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4031000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_InvalidMessageText",0x24);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4032000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_InvalidPasswordText",0x25);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4033000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_TruncatedText",0x1f);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar6 + 1) = 3;
  *puVar6 = 0x4034000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_InvalidCharacterName",0x26);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4035000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_GMMuted",0x19);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4037000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_TooManyCustomChannels",0x27);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar6 = *(undefined8 **)(param_1 + 0x10);
  *puVar6 = 0x4038000000000000;
  *(undefined4 *)(puVar6 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar17 = *(longlong *)(param_1 + 0x10);
  local_78 = FUN_140062650(param_1,"ChatChannelResult_MissingEntitlement",0x24);
  local_70 = 4;
  FUN_14005ea50(param_1,lVar17 + -0x20,&local_78,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  return 1;
}



==== FUN_14074be90 @ 14074be90 ====

undefined8 FUN_14074be90(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined4 local_30;
  
  FUN_140057020(param_1,"P2PTrading",&PTR_s_CanInitiateTrade_140b753a0);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_ErrorInitiating",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_PlayerLogOut",0x1f);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_PlayerCanceled",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_PlayerAcceptedInvite",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_PlayerDeclinedInvite",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_MissingPlayer",0x20);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_InitiatorCommitted",0x25);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_InitiatorUnCommitted",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_TargetCommitted",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4022000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_TargetUnCommitted",0x24);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4024000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_NothingToTrade",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4026000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_FinishedSuccess",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4028000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_DbFailedToInit",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x402a000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_DbFailed",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_ErrorAddingItem",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402e000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_ErrorRemovingItem",0x24);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4030000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_TargetBusy",0x1d);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x4031000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_TargetNotAllowedToTrade",0x2a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4032000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeResultCode_InviteFailedNoTrading",0x28);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_Ok",0x10);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_Params",0x14);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_MissingPlayer",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_NoTarget",0x16);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4010000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_AlreadyTrading",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x401c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_InVehicle",0x17);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_TargetRangeMax",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4024000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_InCombat",0x16);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4026000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_Dead",0x12);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4028000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_TargetFaction",0x1b);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402a000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_ItemAlreadyInTradeSession",0x27);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402c000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_ItemNotInTradeSession",0x23);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x402e000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_ItemNotFoundInInventory",0x25);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4030000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_DifferentRealms",0x1d);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4031000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_BindUnique",0x18);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4032000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_NotEnoughMoney",0x1c);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4014000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_PlayerHasNotAccepted",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4018000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_PlayerNotOwnerOfItem",0x22);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4022000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_WaitingOnDbTransaction",0x24);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4033000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_MissingEntitlement",0x20);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4034000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_PrivilegeRestricted",0x21);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4035000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"P2PTradeError_TooManyItems",0x1a);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4020000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_38 = FUN_140062650(param_1,"kMaxTradeItems",0xe);
  local_30 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_38,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  return 1;
}



==== FUN_14074ff00 @ 14074ff00 ====

undefined4 FUN_14074ff00(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  FUN_140057020(param_1,"AchievementsLib",&PTR_s_GetAchievements_140b754c0);
  FUN_140058710(param_1,"CodeEnumAchievementCategory",0x1b);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  uVar2 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar1 + 1) = 5;
  lVar3 = 0x102;
  *puVar1 = uVar2;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  do {
    FUN_1400f06f0(param_1);
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  uVar2 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar2,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  return 1;
}



==== FUN_140750220 @ 140750220 ====

undefined8 * FUN_140750220(undefined8 *param_1,longlong param_2)

{
  double dVar1;
  float fVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 local_28;
  undefined4 local_20;
  
  *(undefined4 *)(param_1 + 5) = 0x3f800000;
  *(undefined8 *)((longlong)param_1 + 0x2c) = 0x3f800000;
  *(undefined4 *)((longlong)param_1 + 0x24) = 0xffffffff;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined8 *)((longlong)param_1 + 0x34) = 0;
  *(undefined8 *)((longlong)param_1 + 0x3c) = 0;
  *(undefined4 *)((longlong)param_1 + 0x44) = 0;
  plVar4 = (longlong *)FUN_1400580e0(param_2,0xffffffff);
  iVar3 = (int)plVar4[1];
  if ((iVar3 == 5) || (iVar3 == 7)) {
    lVar5 = *(longlong *)(*plVar4 + 0x10);
  }
  else {
    lVar5 = *(longlong *)(*(longlong *)(param_2 + 0x20) + 0xe0 + (longlong)iVar3 * 8);
  }
  if (lVar5 != 0) {
    plVar4 = *(longlong **)(param_2 + 0x10);
    *plVar4 = lVar5;
    *(undefined4 *)(plVar4 + 1) = 5;
    *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  }
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fTime",5);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(int *)param_1 = (int)(longlong)((float)dVar1 * DAT_140b7a164);
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fScale",6);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)(param_1 + 7) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)((longlong)param_1 + 0x2c) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"nColor",6);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x3c) = 1;
    iVar3 = FUN_140056d60(param_2,0xffffffff);
    *(int *)((longlong)param_1 + 0x24) = iVar3 + -0x1000000;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fAlpha",6);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)(param_1 + 8) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)(param_1 + 5) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fRotation",9);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x44) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)(param_1 + 6) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fVelocityDirection",0x12);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)((longlong)param_1 + 4) = (float)dVar1;
    *(float *)(param_1 + 1) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fVelocityDirectionRange",0x17);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  fVar2 = DAT_140b79e48;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)(param_1 + 1) = (float)dVar1 * fVar2 + *(float *)(param_1 + 1);
    *(float *)((longlong)param_1 + 4) = *(float *)((longlong)param_1 + 4) - (float)dVar1 * fVar2;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fVelocityMagnitude",0x12);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)((longlong)param_1 + 0xc) = (float)dVar1;
    *(float *)(param_1 + 2) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fVelocityMagnitudeRange",0x17);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)(param_1 + 2) = (float)dVar1 * fVar2 + *(float *)(param_1 + 2);
    *(float *)((longlong)param_1 + 0xc) = *(float *)((longlong)param_1 + 0xc) - (float)dVar1 * fVar2
    ;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fAccelerationDirection",0x16);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)((longlong)param_1 + 0x14) = (float)dVar1;
    *(float *)(param_1 + 3) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fAccelerationDirectionRange",0x1b);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)(param_1 + 3) = (float)dVar1 * fVar2 + *(float *)(param_1 + 3);
    *(float *)((longlong)param_1 + 0x14) =
         *(float *)((longlong)param_1 + 0x14) - (float)dVar1 * fVar2;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fAccelerationMagnitude",0x16);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)((longlong)param_1 + 0x1c) = (float)dVar1;
    *(float *)(param_1 + 4) = (float)dVar1;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  lVar5 = *(longlong *)(param_2 + 0x10);
  local_28 = FUN_140062650(param_2,"fAccelerationMagnitudeRange",0x1b);
  local_20 = 4;
  FUN_14005e8e0(param_2,lVar5 + -0x10,&local_28,*(undefined8 *)(param_2 + 0x10));
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 0x10;
  if ((*(undefined8 **)(param_2 + 0x10) == &DAT_140a12148) ||
     (*(int *)(*(undefined8 **)(param_2 + 0x10) + -1) != 0)) {
    *(undefined4 *)((longlong)param_1 + 0x34) = 1;
    dVar1 = (double)FUN_140056c40(param_2,0xffffffff);
    *(float *)(param_1 + 4) = (float)dVar1 * fVar2 + *(float *)(param_1 + 4);
    *(float *)((longlong)param_1 + 0x1c) =
         *(float *)((longlong)param_1 + 0x1c) - (float)dVar1 * fVar2;
  }
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + -0x10;
  return param_1;
}



==== FUN_140757c50 @ 140757c50 ====

undefined8 FUN_140757c50(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined4 local_10;
  
  FUN_140057020(param_1,"CommunicatorLib",&PTR_s_GetMessageLayoutForQuest_140b75840);
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorPortraitPlacement_Left",0x22);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorPortraitPlacement_Right",0x23);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorOverlay_Default",0x1b);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorOverlay_LightStatic",0x1f);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorOverlay_HeavyStatic",0x1f);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorBackground_Default",0x1e);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x3ff0000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorBackground_Exiles",0x1d);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4000000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorBackground_Dominion",0x1f);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *puVar1 = 0x4008000000000000;
  *(undefined4 *)(puVar1 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorBackground_Drusera",0x1e);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar1 = *(undefined8 **)(param_1 + 0x10);
  *(undefined4 *)(puVar1 + 1) = 3;
  *puVar1 = 0x4010000000000000;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_18 = FUN_140062650(param_1,"CommunicatorBackground_TheEntity",0x20);
  local_10 = 4;
  FUN_14005ea50(param_1,lVar2 + -0x20,&local_18,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  return 1;
}



==== FUN_140761170 @ 140761170 ====

undefined8 FUN_140761170(longlong param_1)

{
  double *pdVar1;
  undefined8 *puVar2;
  float fVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  undefined8 local_48;
  undefined4 local_40;
  
  FUN_140057020(param_1,"MarketplaceLib",&PTR_s_GetCommodityFamilies_140b75f60);
  lVar4 = FUN_140200220(0x439);
  if (lVar4 == 0) {
    iVar6 = 200;
  }
  else {
    iVar6 = *(int *)(lVar4 + 0xc);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar6;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kMaxCommodityOrder",0x12);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4024000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kAuctionSearchMaxIds",0x14);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4018000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kAuctionSearchMaxFilters",0x18);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x403e000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kAuctionSearchPageSize",0x16);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x447);
  iVar6 = 0xc;
  if (lVar4 == 0) {
    iVar7 = 0xc;
  }
  else {
    iVar7 = *(int *)(lVar4 + 4);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kAuctionSearchMaxResults",0x18);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x433);
  if (lVar4 == 0) {
    iVar7 = 0xc;
  }
  else {
    iVar7 = *(int *)(lVar4 + 4);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar7;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kItemAuctionRake",0x10);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x433);
  if (lVar4 != 0) {
    iVar6 = *(int *)(lVar4 + 8);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar6;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kCommodityAuctionRake",0x15);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x46a);
  if (lVar4 == 0) {
    iVar6 = 500;
  }
  else {
    iVar6 = *(int *)(lVar4 + 4);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)iVar6;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"knCommodityBuyOrderTaxMinimum",0x1d);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x46a);
  fVar8 = DAT_140b79d60;
  if (lVar4 != 0) {
    fVar8 = *(float *)(lVar4 + 0x18);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)fVar8;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kfCommodityBuyOrderTaxMultiplier",0x20);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x432);
  fVar8 = DAT_140b7a01c;
  fVar3 = DAT_140b7a01c;
  if (lVar4 != 0) {
    fVar3 = *(float *)(lVar4 + 0x18);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)fVar3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kItemAuctionListTimeDays",0x18);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  lVar4 = FUN_140200220(0x432);
  if (lVar4 != 0) {
    fVar8 = *(float *)(lVar4 + 0x1c);
  }
  pdVar1 = *(double **)(param_1 + 0x10);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)fVar8;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  lVar4 = *(longlong *)(param_1 + 0x10);
  local_48 = FUN_140062650(param_1,"kCommodityOrderListTimeDays",0x1b);
  local_40 = 4;
  FUN_14005ea50(param_1,lVar4 + -0x20,&local_48,*(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x10;
  FUN_140058710(param_1,"AuctionEventType",0x10);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar5 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058710(param_1,&DAT_140b4d4d4,4);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,&DAT_1409f978c,3);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,&DAT_140b4d724,4);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"Expire",6);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"Cancel",6);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar4 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar4 + -0x30,lVar4 + -0x20,lVar4 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"AuctionPostResult",0x11);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar5 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058710(param_1,&DAT_1409f97d4,2);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"DbFailure",9);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4014000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"Item_BadId",10);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4018000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"NotEnoughToFillQuantity",0x17);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4033000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"NotEnoughCash",0xd);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4034000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"NotReady",8);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4056400000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CannotFillOrder",0xf);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4056800000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"TooManyOrders",0xd);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4057800000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"OrderTooBig",0xb);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4057c00000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"NotFound",8);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4058000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"BidTooLow",9);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4058400000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"OwnItem",7);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4058800000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"BidTooHigh",10);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4058c00000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"AlreadyHasBid",0xd);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4059000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionDisabled",0x13);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x405ec00000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"CommodityDisabled",0x11);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x405f000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"TooManyBids",0xb);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4062400000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar4 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar4 + -0x30,lVar4 + -0x20,lVar4 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"AuctionSort",0xb);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar5 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058710(param_1,"MinBid",6);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"Buyout",6);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"TimeLeft",8);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"Property",8);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar4 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar4 + -0x30,lVar4 + -0x20,lVar4 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterData",0x15);
  if (*(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x70) <=
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x78)) {
    FUN_14005e2c0(param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  uVar5 = FUN_14005c1b0(param_1,0,0);
  *(undefined4 *)(puVar2 + 1) = 5;
  *puVar2 = uVar5;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  FUN_140058710(param_1,"ItemAuctionFilterPropertyMin",0x1c);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterPropertyMax",0x1c);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x3ff0000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterLevel",0x16);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4000000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterQuality",0x18);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4008000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterRuneSlot",0x19);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4010000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterBuyoutMax",0x1a);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4014000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  FUN_140058710(param_1,"ItemAuctionFilterEquippableBy",0x1d);
  puVar2 = *(undefined8 **)(param_1 + 0x10);
  *puVar2 = 0x4018000000000000;
  *(undefined4 *)(puVar2 + 1) = 3;
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + 0x10;
  uVar5 = FUN_1400580e0(param_1,0xfffffffd);
  FUN_14005ea50(param_1,uVar5,*(longlong *)(param_1 + 0x10) + -0x20,
                *(longlong *)(param_1 + 0x10) + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  lVar4 = *(longlong *)(param_1 + 0x10);
  FUN_14005ea50(param_1,lVar4 + -0x30,lVar4 + -0x20,lVar4 + -0x10);
  *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -0x20;
  return 1;
}



==== FUN_14091f420 @ 14091f420 ====

ushort * FUN_14091f420(undefined8 *param_1,ushort *param_2,longlong param_3)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  ushort uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined8 *puVar11;
  ushort *puVar12;
  longlong lVar13;
  longlong lVar14;
  ushort *puVar15;
  int iVar16;
  ushort uVar17;
  undefined8 uVar18;
  bool bVar19;
  bool bVar20;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar22;
  ulonglong uVar21;
  int local_68;
  int local_60;
  longlong local_58;
  longlong local_50;
  
  uVar22 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  piVar4 = (int *)*param_1;
  puVar7 = (undefined8 *)0x0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  if (*piVar4 == 0) {
    puVar7 = (undefined8 *)FUN_14092d590(piVar4,0x50);
  }
  if (*piVar4 != 0) {
    return (ushort *)0x0;
  }
  FUN_1407e4830(puVar7,0,0x50);
  uVar8 = *(undefined8 *)(param_3 + 0x10);
  puVar7[4] = param_2;
  *puVar7 = uVar8;
  *(undefined8 **)(param_3 + 0x10) = puVar7;
  uVar17 = *param_2;
  uVar5 = 0x7d;
  if ((ushort)(uVar17 - 0x8c) < 2) {
    param_2 = param_2 + 1;
    uVar5 = uVar17;
  }
  uVar17 = *param_2;
  puVar12 = param_2 + 2;
  puVar15 = param_2;
  if (((uVar17 == 0x81) || (uVar17 == 0x86)) && (*puVar12 == 0x8b)) {
    *(undefined8 *)(param_3 + 0x10) = *puVar7;
    do {
      puVar12 = param_2 + param_2[1];
      param_2 = param_2 + param_2[1];
    } while (*puVar12 == 0x71);
    return param_2 + 2;
  }
  do {
    puVar1 = puVar15 + puVar15[1];
    puVar15 = puVar15 + puVar15[1];
  } while (*puVar1 == 0x71);
  uVar2 = *puVar15;
  puVar15 = param_2 + param_2[1];
  bVar19 = param_2[param_2[1]] == 0x71;
  if (((uVar17 == 0x81) || (uVar17 == 0x86)) && (bVar19 = *puVar12 != 0x89, *puVar12 == 0x8a)) {
    uVar3 = param_2[3];
    if ((param_1[0x1a] == 0) || (uVar3 == 0xffff)) {
      bVar19 = false;
    }
    else {
      iVar16 = *(int *)(param_1[0x1a] + 0x18);
      if (iVar16 == 0) {
        bVar19 = uVar3 != 0;
      }
      else {
        bVar19 = uVar3 != *(ushort *)(param_1[1] + 4 + (longlong)iVar16 * 2);
      }
    }
  }
  if (uVar17 == 0x81) {
    if (1 < (ushort)(param_2[param_2[1]] - 0x73)) goto LAB_14091f6ac;
    uVar17 = 0x86;
LAB_14091f641:
    local_68 = *(int *)(param_1[2] + ((longlong)param_2 - param_1[1] >> 1) * 4);
    *(int *)(puVar7 + 9) = local_68;
    if (uVar17 == 0x7b) {
      uVar6 = FUN_14092ef20(param_1,param_2,0);
      *(undefined4 *)(puVar7 + 8) = uVar6;
    }
  }
  else {
    if (uVar17 == 0x7c) {
      uVar17 = 0x7b;
      goto LAB_14091f641;
    }
    if ((uVar17 == 0x7f) || (uVar17 == 0x84)) {
      uVar3 = *puVar12;
      local_60 = (uint)uVar3 + (uint)uVar3;
      if (*(char *)((ulonglong)uVar3 + param_1[3]) == '\0') {
        local_68 = *(int *)(param_1 + 4) + (uint)uVar3 * 8;
      }
      else {
        local_68 = *(int *)((longlong)param_1 + 0x24) + local_60 * 8;
      }
      *(int *)(puVar7 + 9) = local_68;
      puVar12 = param_2 + 3;
    }
    else if (((ushort)(uVar17 - 0x7b) < 0xc) && ((0x881U >> (uVar17 - 0x7b & 0x1f) & 1) != 0))
    goto LAB_14091f641;
  }
LAB_14091f6ac:
  iVar16 = 0;
  if ((uVar2 == 0x73) || ((uVar2 == 0x74 && (uVar5 != 0x8d)))) {
    iVar16 = 1;
  }
  if (uVar5 == 0x8c) {
    iVar16 = iVar16 + 1;
  }
  if (iVar16 != 0) {
    FUN_14091b4d0(param_1);
  }
  iVar16 = 0;
  if ((uVar2 == 0x73) || ((uVar2 == 0x74 && (uVar5 != 0x8d)))) {
    if (*piVar4 == 0) {
      piVar4[0x1a] = 0;
      uVar22 = 0;
      FUN_14092aa10(piVar4,0x102,0xfffffffffffffff8,0x200,0);
    }
    iVar16 = 1;
  }
  if (uVar5 == 0x8c) {
    if (*piVar4 == 0) {
      piVar4[0x1a] = 0;
      uVar22 = 0;
      FUN_14092aa10(piVar4,0x102,(longlong)((-1 - iVar16) * 8),6,0);
    }
LAB_14091f781:
    if (uVar2 == 0x74) goto LAB_14091f78b;
    if ((uVar2 != 0x73) || (local_58 = FUN_140932570(piVar4), !bVar19)) goto LAB_14091f7a4;
    if (uVar17 != 0x7b) {
      if (uVar17 < 0x82) {
        puVar7[5] = local_58;
      }
      goto LAB_14091f7a4;
    }
LAB_14091f7ae:
    iVar16 = *(int *)(puVar7 + 8);
    if (iVar16 < 0) {
      if (uVar2 == 0x74) {
        uVar8 = CONCAT44(uVar22,0x10b);
        FUN_140932690(piVar4,6,3,0,uVar8,(longlong)local_68);
        uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
        FUN_14091b4d0(param_1,2);
        uVar8 = CONCAT44(uVar22,6);
        FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar8,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),3);
        FUN_140932690(piVar4,6,0x102,0xfffffffffffffff0,uVar8,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),2);
        FUN_140932a90(piVar4,0x1b,0x10b,(longlong)local_68,uVar8,0,0x200,8);
        uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      }
      else {
        if ((uVar2 == 0x73) || (bVar19)) {
          uVar8 = CONCAT44(uVar22,2);
          FUN_140932690(piVar4,6,0x10b,(longlong)local_68,uVar8,0);
          uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
          FUN_14091b4d0(param_1,1);
          uVar8 = CONCAT44(uVar22,6);
          lVar13 = -8;
          goto LAB_14091ffaf;
        }
        lVar13 = (longlong)local_68;
        uVar18 = 0x10b;
        uVar8 = CONCAT44(uVar22,2);
LAB_14091ffb5:
        FUN_140932690(piVar4,6,uVar18,lVar13,uVar8,0);
        uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      }
    }
    else if (((ushort)(uVar2 - 0x73) < 2) || (bVar19)) {
      FUN_14091b4d0(param_1,iVar16 + 2);
      uVar8 = CONCAT44(uVar22,0x10b);
      FUN_140932690(piVar4,6,1,0,uVar8,(longlong)local_68);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),2);
      FUN_140932a90(piVar4,0x1b,3,0,uVar8,0,0x200,(longlong)(*(int *)(puVar7 + 8) * 8 + 0x10));
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),6);
      FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar8,0);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),3);
      FUN_140932690(piVar4,6,0x10b,(longlong)local_68,uVar8,0);
      uVar21 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
      FUN_140932690(piVar4,6,0x102,0xfffffffffffffff0,uVar21,0);
      uVar21 = uVar21 & 0xffffffff00000000;
      FUN_14092fa70(param_1,param_2,*(int *)(puVar7 + 8) + 1,2,uVar21);
      uVar22 = (undefined4)(uVar21 >> 0x20);
    }
    else {
      FUN_14091b4d0(param_1,iVar16 + 1);
      uVar8 = CONCAT44(uVar22,0x10b);
      FUN_140932690(piVar4,6,1,0,uVar8,(longlong)local_68);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),2);
      FUN_140932a90(piVar4,0x1b,3,0,uVar8,0,0x200,(longlong)(*(int *)(puVar7 + 8) * 8 + 8));
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),3);
      FUN_140932690(piVar4,6,0x10b,(longlong)local_68,uVar8,0);
      uVar21 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
      FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar21,0);
      uVar21 = uVar21 & 0xffffffff00000000;
      FUN_14092fa70(param_1,param_2,*(undefined4 *)(puVar7 + 8),1,uVar21);
      uVar22 = (undefined4)(uVar21 >> 0x20);
    }
  }
  else {
    if (uVar5 != 0x8d) goto LAB_14091f781;
    if (*piVar4 == 0) {
      piVar4[0x1a] = 0;
      uVar8 = CONCAT44(uVar22,0x102);
      puVar9 = (undefined1 *)FUN_14092d140(piVar4,1,6,0,uVar8,0xfffffffffffffff8);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      if (puVar9 != (undefined1 *)0x0) {
        *puVar9 = 0x8b;
      }
    }
    if (uVar2 != 0x74) {
      FUN_14092ec50(param_1,1);
      uVar8 = CONCAT44(uVar22,0x200);
      local_50 = FUN_140931b80(piVar4,0,6,0,uVar8,0);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      goto LAB_14091f781;
    }
    if ((uVar17 == 0x7b) || (0x81 < uVar17)) {
      uVar8 = CONCAT44(uVar22,0x200);
      lVar14 = FUN_140931b80(piVar4,1,6,0,uVar8,0);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x102);
      FUN_140932690(piVar4,6,6,0,uVar8,0xfffffffffffffff0);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      lVar13 = FUN_140932450(piVar4,0x16);
      lVar10 = FUN_140932570(piVar4);
      if ((lVar14 != 0) && (lVar10 != 0)) {
        *(ulonglong *)(lVar14 + 0x10) = *(ulonglong *)(lVar14 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(lVar14 + 0x10) = *(ulonglong *)(lVar14 + 0x10) | 1;
        *(longlong *)(lVar14 + 0x18) = lVar10;
      }
      if ((uVar17 == 0x7b) && (-1 < *(int *)(puVar7 + 8))) {
        uVar8 = CONCAT44(uVar22,0x10b);
        FUN_140932690(piVar4,6,1,0,uVar8,(longlong)local_68);
        lVar14 = (longlong)(*(int *)(puVar7 + 8) + 1) << 3;
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x101);
      }
      else {
        lVar14 = (longlong)local_68;
        uVar8 = CONCAT44(uVar22,0x10b);
      }
      local_50 = FUN_140931b80(piVar4,0,6,0,uVar8,lVar14);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      lVar14 = FUN_140932570(piVar4);
    }
    else {
      uVar8 = CONCAT44(uVar22,0x200);
      lVar13 = FUN_140931b80(piVar4,1,6,0,uVar8,0);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x102);
      FUN_140932690(piVar4,6,6,0,uVar8,0xfffffffffffffff0);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      lVar14 = FUN_140932570(piVar4);
    }
    if ((lVar13 != 0) && (lVar14 != 0)) {
      *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) | 1;
      *(longlong *)(lVar13 + 0x18) = lVar14;
    }
LAB_14091f78b:
    uVar8 = FUN_140932570(piVar4);
    puVar7[6] = uVar8;
LAB_14091f7a4:
    if (uVar17 == 0x7b) goto LAB_14091f7ae;
    if ((uVar17 == 0x7f) || (uVar17 == 0x84)) {
      if (*(char *)(((longlong)local_60 >> 1) + param_1[3]) == '\0') {
        FUN_14091b4d0(param_1,3);
        uVar8 = CONCAT44(uVar22,0x10b);
        FUN_140932690(piVar4,6,1,0,uVar8,
                      (longlong)*(int *)((longlong)param_1 + 0x24) + (longlong)local_60 * 8);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x10b);
        FUN_140932690(piVar4,6,3,0,uVar8,
                      (longlong)*(int *)((longlong)param_1 + 0x24) + (longlong)(local_60 + 1) * 8);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
        FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar8,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x10b);
        FUN_140932690(piVar4,6,1,0,uVar8,(longlong)local_68);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),3);
        FUN_140932690(piVar4,6,0x102,0xfffffffffffffff0,uVar8,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),6);
        FUN_140932690(piVar4,6,0x10b,(longlong)local_68,uVar8,0);
        lVar13 = -0x18;
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
      }
      else {
        FUN_14091b4d0(param_1,2);
        lVar13 = (longlong)local_68;
        uVar8 = CONCAT44(uVar22,0x10b);
        FUN_140932690(piVar4,6,1,0,uVar8,lVar13);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x10b);
        FUN_140932690(piVar4,6,3,0,uVar8,lVar13 + 8);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),6);
        FUN_140932690(piVar4,6,0x10b,lVar13,uVar8,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
        FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar8,0);
        uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),3);
        lVar13 = -0x10;
      }
LAB_14091ffaf:
      uVar18 = 0x102;
      goto LAB_14091ffb5;
    }
    if ((uVar17 - 0x82 & 0xfffb) == 0) {
      uVar8 = CONCAT44(uVar22,0x10b);
      FUN_140932690(piVar4,6,3,0,uVar8,(longlong)local_68);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      FUN_14091b4d0(param_1,1);
      uVar8 = CONCAT44(uVar22,6);
      FUN_140932690(piVar4,6,0x10b,(longlong)local_68,uVar8,0);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),3);
      lVar13 = -8;
      goto LAB_14091ffaf;
    }
    if (bVar19) {
      FUN_14091b4d0(param_1,1);
      uVar8 = CONCAT44(uVar22,6);
      FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar8,0);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
  }
  puVar11 = (undefined8 *)0x0;
  if ((uVar17 == 0x81) || (uVar17 == 0x86)) {
    uVar3 = *puVar12;
    if (uVar3 == 0x87) {
      uVar8 = 0x10b;
      lVar13 = (longlong)*(int *)((longlong)param_1 + 0x24) + 8;
      uVar18 = CONCAT44(uVar22,0x10b);
      lVar14 = (longlong)*(int *)((longlong)param_1 + 0x24) +
               (longlong)(int)((uint)puVar12[1] * 2) * 8;
LAB_14092048e:
      uVar8 = FUN_140931b80(piVar4,0,uVar8,lVar14,uVar18,lVar13);
      uVar22 = (undefined4)((ulonglong)uVar18 >> 0x20);
      FUN_14091b490(piVar4,puVar7 + 8,uVar8);
      puVar12 = puVar12 + 2;
    }
    else if (uVar3 == 0x88) {
      uVar3 = puVar12[1];
      uVar8 = CONCAT44(uVar22,0x10b);
      lVar13 = FUN_140931b80(piVar4,1,0x10b,
                             (longlong)*(int *)((longlong)param_1 + 0x24) +
                             (longlong)(int)((uint)uVar3 + (uint)uVar3) * 8,uVar8,
                             (longlong)*(int *)((longlong)param_1 + 0x24) + 8);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),2);
      FUN_140932690(piVar4,6,0x10b,0x18,uVar8,0);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
      FUN_140932690(piVar4,6,0x10b,0,uVar8,param_1[0x13]);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
      FUN_140932690(piVar4,6,0x10b,8,uVar8,param_1[0x14]);
      uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
      FUN_140932690(piVar4,6,1,0,uVar8,
                    (ulonglong)(longlong)*(int *)((longlong)param_1 + 0x24) >> 3 |
                    (longlong)(int)((uint)uVar3 << 8));
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      FUN_1409337f0(piVar4,2,0);
      uVar8 = CONCAT44(uVar22,0x200);
      FUN_140932690(piVar4,6,3,0,uVar8,param_1[0x12]);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      FUN_1409322b0(piVar4,0x1b,0x200,FUN_1409294f0);
      uVar8 = CONCAT44(uVar22,0x10b);
      FUN_140932690(piVar4,6,2,0,uVar8,0x18);
      uVar18 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
      uVar8 = FUN_140931b80(piVar4,0,1,0,uVar18,0);
      uVar22 = (undefined4)((ulonglong)uVar18 >> 0x20);
      FUN_14091b490(piVar4,puVar7 + 8,uVar8);
      lVar14 = FUN_140932570(piVar4);
      if ((lVar13 != 0) && (lVar14 != 0)) {
        *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) | 1;
        *(longlong *)(lVar13 + 0x18) = lVar14;
      }
      puVar12 = puVar12 + 2;
    }
    else if ((ushort)(uVar3 - 0x89) < 2) {
      puVar7[8] = 0;
      lVar13 = param_1[0x1a];
      uVar3 = puVar12[1];
      if (lVar13 == 0) {
        bVar20 = false;
      }
      else if (uVar3 == 0xffff) {
        bVar20 = true;
      }
      else if (*(int *)(lVar13 + 0x18) == 0) {
        bVar20 = uVar3 == 0;
      }
      else {
        bVar20 = uVar3 == *(ushort *)(param_1[1] + 4 + (longlong)*(int *)(lVar13 + 0x18) * 2);
      }
      if (*puVar12 == 0x89) {
        if (bVar20) goto LAB_1409204b2;
      }
      else {
        if (bVar20) {
LAB_1409204b2:
          puVar12 = puVar12 + 2;
          goto LAB_1409204d1;
        }
        if (lVar13 != 0) {
          uVar8 = CONCAT44(uVar22,2);
          FUN_140932690(piVar4,6,0x10b,0x18,uVar8,0);
          uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
          FUN_140932690(piVar4,6,0x10b,0,uVar8,param_1[0x13]);
          uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
          FUN_140932690(piVar4,6,0x10b,8,uVar8,param_1[0x14]);
          uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
          FUN_140932690(piVar4,6,0x10b,0x10,uVar8,
                        *(undefined2 *)
                         (param_1[1] + 4 + (longlong)*(int *)(param_1[0x1a] + 0x18) * 2));
          uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
          FUN_140932690(piVar4,6,1,0,uVar8,uVar3);
          uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
          FUN_1409337f0(piVar4,2,0);
          uVar8 = CONCAT44(uVar22,0x200);
          FUN_140932690(piVar4,6,3,0,uVar8,param_1[0x12]);
          uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
          FUN_1409322b0(piVar4,0x1b,0x200,FUN_1409293f0);
          uVar8 = CONCAT44(uVar22,0x10b);
          FUN_140932690(piVar4,6,2,0,uVar8,0x18);
          lVar14 = 0;
          lVar13 = 0;
          uVar18 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),0x200);
          uVar8 = 1;
          goto LAB_14092048e;
        }
      }
      puVar12 = puVar15;
      if (*puVar15 == 0x71) {
        puVar12 = puVar15 + 2;
        puVar15 = puVar15 + puVar15[1];
      }
    }
    else {
      if (*piVar4 == 0) {
        puVar11 = (undefined8 *)FUN_14092d590(piVar4,0x40);
      }
      if (*piVar4 != 0) {
        return (ushort *)0x0;
      }
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[5] = 0;
      puVar11[6] = 0;
      puVar11[7] = 0;
      puVar11[4] = puVar12;
      puVar7[8] = puVar11;
      puVar12 = (ushort *)FUN_14091d1b0(param_1,puVar12,puVar11,1);
    }
  }
LAB_1409204d1:
  FUN_140925310(param_1,puVar12,puVar15);
  if (*piVar4 != 0) {
    return (ushort *)0x0;
  }
  if (uVar17 == 0x7b) {
    if (*(int *)(puVar7 + 8) < 0) {
      uVar8 = CONCAT44(uVar22,0x10b);
      FUN_140932690(piVar4,6,2,0,uVar8,(longlong)local_68);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      if (uVar2 == 0x73) {
        uVar8 = 0;
LAB_140920541:
        uVar18 = CONCAT44(uVar22,0x102);
        FUN_140932690(piVar4,6,3,0,uVar18,uVar8);
        uVar22 = (undefined4)((ulonglong)uVar18 >> 0x20);
      }
      else if (uVar2 == 0x74) {
        uVar8 = CONCAT44(uVar22,0x102);
        FUN_140932690(piVar4,6,0x10b,(longlong)local_68,uVar8,0);
        uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      }
    }
    else {
      if (((ushort)(uVar2 - 0x73) < 2) || (iVar16 = 1, bVar19)) {
        iVar16 = 2;
      }
      uVar8 = CONCAT44(uVar22,0x10b);
      FUN_140932a90(piVar4,0x19,2,0,uVar8,(longlong)local_68,0x200,
                    (longlong)(iVar16 + *(int *)(puVar7 + 8)) << 3);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      if (uVar2 == 0x73) {
        uVar8 = 0xfffffffffffffff8;
        goto LAB_140920541;
      }
    }
  }
  iVar16 = 0;
  if ((uVar2 != 0x72) || (uVar5 != 0x7d)) {
    iVar16 = 1;
  }
  if ((bVar19) && (uVar17 != 0x7b)) {
    iVar16 = iVar16 + 1;
  }
  if (iVar16 != 0) {
    FUN_14091b4d0(param_1);
  }
  iVar16 = 0;
  if (uVar2 == 0x72) {
    if (uVar5 != 0x7d) {
      uVar8 = CONCAT44(uVar22,0x200);
      goto LAB_140920668;
    }
  }
  else {
    uVar8 = CONCAT44(uVar22,6);
LAB_140920668:
    FUN_140932690(piVar4,6,0x102,0xfffffffffffffff8,uVar8,0);
    uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
    iVar16 = 1;
  }
  if (bVar19) {
    if (uVar17 != 0x7b) {
      uVar8 = CONCAT44(uVar22,0x200);
      FUN_140932690(piVar4,6,0x102,(longlong)((-1 - iVar16) * 8),uVar8,0);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
    }
    if (uVar2 != 0x73) {
      uVar8 = FUN_140932570(piVar4);
      puVar7[5] = uVar8;
    }
  }
  if (local_60 != 0) {
    uVar8 = CONCAT44(uVar22,0x10b);
    FUN_140932690(piVar4,6,1,0,uVar8,(longlong)local_68);
    uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),6);
    FUN_140932690(piVar4,6,0x10b,
                  (longlong)*(int *)((longlong)param_1 + 0x24) + (longlong)(local_60 + 1) * 8,uVar8,
                  0);
    uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20),1);
    FUN_140932690(piVar4,6,0x10b,
                  (longlong)*(int *)((longlong)param_1 + 0x24) + (longlong)local_60 * 8,uVar8,0);
    uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
  }
  if (uVar2 == 0x73) {
    if ((uVar17 == 0x7b) || (0x81 < uVar17)) {
      if (bVar19) {
        uVar8 = FUN_140932570(piVar4);
        puVar7[5] = uVar8;
      }
      uVar8 = CONCAT44(uVar22,6);
      if (uVar17 == 0x7b) {
        lVar13 = FUN_140931b80(piVar4,1,3,0,uVar8,0);
        uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
        goto LAB_140920812;
      }
      lVar13 = FUN_140931b80(piVar4,1,0x10b,(longlong)local_68,uVar8,0);
      uVar22 = (undefined4)((ulonglong)uVar8 >> 0x20);
      if ((lVar13 != 0) && (local_58 != 0)) {
        *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) | 1;
        *(longlong *)(lVar13 + 0x18) = local_58;
      }
      if (uVar5 != 0x8c) {
        FUN_14092ec50(param_1,1);
      }
    }
    else {
      lVar13 = FUN_140932450(piVar4,0x16);
LAB_140920812:
      if ((lVar13 != 0) && (local_58 != 0)) {
        *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) & 0xfffffffffffffffd;
        *(longlong *)(lVar13 + 0x18) = local_58;
        *(ulonglong *)(lVar13 + 0x10) = *(ulonglong *)(lVar13 + 0x10) | 1;
      }
    }
    uVar8 = FUN_140932570(piVar4);
    puVar7[6] = uVar8;
  }
  if (uVar5 == 0x8c) {
    uVar8 = FUN_140932570(piVar4);
    puVar7[7] = uVar8;
  }
  else if (uVar5 == 0x8d) {
    lVar13 = *(longlong *)(param_3 + 0x28);
    lVar14 = FUN_140932450(piVar4,0x16);
    if ((lVar14 != 0) && (lVar13 != 0)) {
      *(ulonglong *)(lVar14 + 0x10) = *(ulonglong *)(lVar14 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar14 + 0x10) = *(ulonglong *)(lVar14 + 0x10) | 1;
      *(longlong *)(lVar14 + 0x18) = lVar13;
    }
    if (local_50 != 0) {
      lVar13 = FUN_140932570(piVar4);
      if (lVar13 != 0) {
        *(ulonglong *)(local_50 + 0x10) = *(ulonglong *)(local_50 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(local_50 + 0x10) = *(ulonglong *)(local_50 + 0x10) | 1;
        *(longlong *)(local_50 + 0x18) = lVar13;
      }
      if ((uVar17 == 0x7b) && (-1 < *(int *)(puVar7 + 8))) {
        FUN_140932690(piVar4,6,2,0,CONCAT44(uVar22,0x10b),(longlong)local_68);
        uVar8 = FUN_140932450(piVar4,0x17);
        FUN_14091b490(piVar4,param_1 + 0x20,uVar8);
      }
      else if (uVar2 == 0x74) {
        if (uVar17 != 0x7b) {
          FUN_14092ec50(param_1,1);
        }
        goto LAB_14092087b;
      }
    }
  }
  if (((uVar2 != 0x72) && (uVar5 != 0x8d)) || (uVar5 == 0x8c)) {
    FUN_140928600(param_1);
  }
LAB_14092087b:
  uVar17 = *puVar15;
  while (uVar17 == 0x71) {
    puVar12 = puVar15 + puVar15[1];
    puVar15 = puVar15 + puVar15[1];
    uVar17 = *puVar12;
  }
  return puVar15 + 2;
}



==== FUN_140923e20 @ 140923e20 ====

void FUN_140923e20(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  ushort *puVar2;
  int *piVar3;
  longlong *plVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  ushort uVar13;
  ushort uVar14;
  ushort *puVar15;
  int iVar16;
  undefined4 uVar17;
  ushort uVar18;
  bool bVar19;
  uint local_res18;
  uint local_res20;
  undefined8 local_60;
  longlong local_58;
  
  puVar2 = *(ushort **)(param_2 + 0x20);
  piVar3 = (int *)*param_1;
  local_res20 = 0xffffffff;
  local_res18 = 0xffffffff;
  local_60 = 0;
  local_58 = 0;
  iVar1 = *(int *)(param_1[2] + ((longlong)puVar2 - param_1[1] >> 1) * 4);
  iVar16 = -0x10;
  uVar17 = 0x10b;
  if (iVar1 == 0) {
    uVar17 = 0x102;
  }
  iVar6 = -8;
  if (iVar1 != 0) {
    iVar16 = iVar1 + 8;
    iVar6 = iVar1;
  }
  uVar13 = *puVar2;
  if ((ushort)(uVar13 - 0x21) < 0xd) {
    uVar18 = 0x1d;
LAB_140923f16:
    puVar15 = puVar2 + 1;
    if (((ushort)(uVar13 - 0x27) < 3) || (uVar13 == 0x2d)) {
      uVar14 = *puVar15;
      puVar15 = puVar2 + 2;
      local_res20 = (uint)uVar14;
    }
    uVar14 = uVar13;
    if (uVar18 == 0) {
      uVar18 = *puVar15;
      puVar15 = puVar15 + 1;
    }
  }
  else {
    if ((ushort)(uVar13 - 0x2e) < 0xd) {
      sVar5 = -0xd;
      uVar18 = 0x1e;
LAB_140923f13:
      uVar13 = uVar13 + sVar5;
      goto LAB_140923f16;
    }
    if ((ushort)(uVar13 - 0x3b) < 0xd) {
      sVar5 = -0x1a;
      uVar18 = 0x1f;
      goto LAB_140923f13;
    }
    if ((ushort)(uVar13 - 0x48) < 0xd) {
      sVar5 = -0x27;
      uVar18 = 0x20;
      goto LAB_140923f13;
    }
    if ((ushort)(uVar13 - 0x55) < 0xd) {
      sVar5 = -0x34;
      uVar18 = 0;
      goto LAB_140923f13;
    }
    puVar15 = puVar2 + 1;
    uVar7 = 0x11;
    if (0x6b < uVar13) {
      uVar7 = (uint)*puVar15;
    }
    lVar12 = (longlong)(int)uVar7;
    uVar14 = puVar2[lVar12];
    uVar18 = uVar13;
    if ((ushort)(uVar14 - 0x62) < 6) {
      uVar14 = uVar14 - 0x41;
    }
    else {
      local_res20 = (uint)puVar2[lVar12 + 2];
      local_res18 = (uint)puVar15[lVar12];
      if (local_res18 == 0) {
        uVar14 = (uVar14 != 0x68) + 0x27;
      }
      if (local_res20 == puVar15[lVar12]) {
        uVar14 = 0x29;
      }
    }
  }
  switch(uVar14) {
  case 0x21:
  case 0x23:
  case 0x27:
  case 0x68:
    if ((uVar18 == 0x11) || (uVar18 == 0x16)) {
      lVar12 = FUN_140932570(piVar3);
      for (plVar4 = *(longlong **)(param_2 + 0x18); plVar4 != (longlong *)0x0;
          plVar4 = (longlong *)plVar4[1]) {
        lVar10 = *plVar4;
        if ((lVar10 != 0) && (lVar12 != 0)) {
          *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) & 0xfffffffffffffffd;
          *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) | 1;
          *(longlong *)(lVar10 + 0x18) = lVar12;
        }
      }
      if (*piVar3 == 0) {
        piVar3[0x1a] = 0;
        puVar9 = (undefined1 *)FUN_14092d140(piVar3,1,6,0,0x102,0xfffffffffffffff8);
        if (puVar9 != (undefined1 *)0x0) {
          *puVar9 = 0x8b;
        }
      }
      FUN_14092ec50(param_1,1);
      lVar12 = *(longlong *)(param_2 + 0x28);
      lVar10 = FUN_140931b80(piVar3,1,6,0,0x200,0);
      if (lVar10 == 0) {
        return;
      }
      if (lVar12 == 0) {
        return;
      }
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) | 1;
      *(longlong *)(lVar10 + 0x18) = lVar12;
      return;
    }
    if (uVar14 == 0x27) {
      local_res18 = 0;
LAB_140924009:
      FUN_140932690(piVar3,6,1,0,uVar17,(longlong)iVar16);
      FUN_140932690(piVar3,6,6,0,uVar17,(longlong)iVar6);
      lVar12 = FUN_140931b80(piVar3,5,1,0,0x200,(longlong)(int)(local_res18 + 1));
      FUN_140932a90(piVar3,0x1b,uVar17,(longlong)iVar16,1,0,0x200,1);
    }
    else {
      if (0x23 < uVar14) goto LAB_140924009;
      FUN_140932690(piVar3,6,6,0,uVar17,(longlong)iVar6);
      lVar12 = FUN_140931b80(piVar3,5,6,0,uVar17,(longlong)iVar16);
    }
    FUN_1409318f0(param_1);
    FUN_140932690(piVar3,6,uVar17,(longlong)iVar6,6,0);
    lVar10 = *(longlong *)(param_2 + 0x28);
    lVar8 = FUN_140932450(piVar3,0x16);
    if ((lVar8 != 0) && (lVar10 != 0)) {
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) | 1;
      *(longlong *)(lVar8 + 0x18) = lVar10;
    }
    if (uVar14 == 0x68) {
      uVar11 = FUN_140932570(piVar3);
      FUN_140931600(*(undefined8 *)(param_2 + 0x18),uVar11);
    }
    lVar10 = FUN_140932570(piVar3);
    if ((lVar12 != 0) && (lVar10 != 0)) {
      *(ulonglong *)(lVar12 + 0x10) = *(ulonglong *)(lVar12 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar12 + 0x10) = *(ulonglong *)(lVar12 + 0x10) | 1;
      *(longlong *)(lVar12 + 0x18) = lVar10;
    }
    if (iVar1 == 0) {
      FUN_14092ec50(param_1,2);
    }
    bVar19 = uVar14 == 0x23;
    break;
  case 0x22:
  case 0x24:
    FUN_140932690(piVar3,6,6,0,uVar17,(longlong)iVar6);
    FUN_140921800(param_1,uVar18,puVar15,&local_60);
    FUN_140932690(piVar3,6,uVar17,(longlong)iVar6,6,0);
    lVar12 = *(longlong *)(param_2 + 0x28);
    lVar10 = FUN_140932450(piVar3,0x16);
    if ((lVar10 != 0) && (lVar12 != 0)) {
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) | 1;
      *(longlong *)(lVar10 + 0x18) = lVar12;
    }
    uVar11 = FUN_140932570(piVar3);
    FUN_140931600(local_60,uVar11);
    if (iVar1 == 0) {
      FUN_14092ec50(param_1,1);
    }
    bVar19 = uVar14 == 0x24;
    break;
  case 0x25:
    lVar8 = (longlong)iVar6;
    FUN_140932690(piVar3,6,6,0,uVar17,lVar8);
    FUN_140932690(piVar3,6,uVar17,lVar8,0x200,0);
    lVar12 = *(longlong *)(param_2 + 0x28);
    lVar10 = FUN_140931b80(piVar3,1,6,0,0x200,0);
    if ((lVar10 != 0) && (lVar12 != 0)) {
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) | 1;
      *(longlong *)(lVar10 + 0x18) = lVar12;
    }
    lVar10 = FUN_140932450(piVar3,0x16);
    uVar11 = FUN_140932570(piVar3);
    FUN_140931600(*(undefined8 *)(param_2 + 0x18),uVar11);
    FUN_140932690(piVar3,6,6,0,uVar17,lVar8);
    FUN_140932690(piVar3,6,uVar17,lVar8,0x200,0);
    lVar12 = *(longlong *)(param_2 + 0x28);
    lVar8 = FUN_140932450(piVar3,0x16);
    if ((lVar8 != 0) && (lVar12 != 0)) {
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) | 1;
      *(longlong *)(lVar8 + 0x18) = lVar12;
    }
    goto LAB_140924636;
  case 0x26:
    FUN_140932690(piVar3,6,6,0,uVar17,(longlong)iVar6);
    FUN_140932690(piVar3,6,uVar17,(longlong)iVar6,0x200,0);
    lVar10 = FUN_140931b80(piVar3,0,6,0,0x200,0);
    FUN_140921800(param_1,uVar18,puVar15,&local_60);
    lVar12 = *(longlong *)(param_2 + 0x28);
    lVar8 = FUN_140932450(piVar3,0x16);
    if ((lVar8 != 0) && (lVar12 != 0)) {
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) | 1;
      *(longlong *)(lVar8 + 0x18) = lVar12;
    }
    uVar11 = FUN_140932570(piVar3);
    FUN_140931600(local_60,uVar11);
LAB_140924636:
    lVar12 = FUN_140932570(piVar3);
    if ((lVar10 != 0) && (lVar12 != 0)) {
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) | 1;
      *(longlong *)(lVar10 + 0x18) = lVar12;
    }
    if (iVar1 != 0) {
      return;
    }
    FUN_14092ec50(param_1,1);
    return;
  case 0x28:
  case 0x69:
    if (uVar14 == 0x69) {
      local_58 = FUN_140932570(piVar3);
      FUN_140931600(*(undefined8 *)(param_2 + 0x18),local_58);
    }
    FUN_140932690(piVar3,6,6,0,uVar17,(longlong)iVar6);
    FUN_140921800(param_1,uVar18,puVar15,&local_60);
    FUN_140932690(piVar3,6,1,0,uVar17,(longlong)iVar16);
    FUN_140932690(piVar3,6,uVar17,(longlong)iVar6,6,0);
    FUN_140932a90(piVar3,0x19,1,0,1,0,0x200,1);
    FUN_140932690(piVar3,6,uVar17,(longlong)iVar16,1,0);
    if (uVar14 == 0x69) {
      lVar12 = FUN_140931b80(piVar3,2,1,0,0x200,(longlong)(int)(local_res18 + 1));
      if ((lVar12 != 0) && (local_58 != 0)) {
        *(ulonglong *)(lVar12 + 0x10) = *(ulonglong *)(lVar12 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(lVar12 + 0x10) = *(ulonglong *)(lVar12 + 0x10) | 1;
        *(longlong *)(lVar12 + 0x18) = local_58;
      }
      if (local_res20 != 0) goto LAB_1409244ba;
      lVar12 = *(longlong *)(param_2 + 0x28);
      lVar10 = FUN_140932450(piVar3,0x16);
    }
    else {
LAB_1409244ba:
      lVar12 = *(longlong *)(param_2 + 0x28);
      lVar10 = FUN_140931b80(piVar3,2,1,0,0x200,(longlong)(int)(local_res20 + 2));
    }
    if ((lVar10 != 0) && (lVar12 != 0)) {
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) & 0xfffffffffffffffd;
      *(longlong *)(lVar10 + 0x18) = lVar12;
      *(ulonglong *)(lVar10 + 0x10) = *(ulonglong *)(lVar10 + 0x10) | 1;
    }
    uVar11 = FUN_140932570(piVar3);
    FUN_140931600(local_60,uVar11);
    if (iVar1 == 0) {
      FUN_14092ec50(param_1,2);
    }
    goto switchD_140923fdf_caseD_2a;
  case 0x29:
  case 0x2b:
    goto switchD_140923fdf_caseD_29;
  default:
    goto switchD_140923fdf_caseD_2a;
  }
  if (bVar19) {
switchD_140923fdf_caseD_29:
    uVar11 = FUN_140932570(piVar3);
    FUN_140931600(*(undefined8 *)(param_2 + 0x18),uVar11);
  }
switchD_140923fdf_caseD_2a:
  return;
}



==== FUN_140930010 @ 140930010 ====

undefined8 FUN_140930010(undefined8 *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 *puVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong *local_res8;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar14;
  ulonglong uVar12;
  undefined8 uVar13;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  piVar2 = (int *)*param_1;
  lVar7 = 0;
  bVar4 = false;
  local_res8 = (longlong *)0x0;
  if (param_2 == 0) {
    if (param_3 == 0) {
      if ((*(int *)((longlong)param_1 + 0x54) - 1U < 2) ||
         (lVar8 = lVar7, 0xff < *(int *)(param_1 + 0xb))) {
        lVar8 = 0;
        bVar4 = true;
      }
      goto LAB_14093038a;
    }
  }
  else {
    lVar8 = 0;
    if (param_3 == 0) goto LAB_14093038a;
  }
  if (*piVar2 == 0) {
    piVar2[0x1a] = 0;
    uVar10 = CONCAT44(uVar14,5);
    puVar5 = (undefined1 *)FUN_14092d140(piVar2,1,6,0,uVar10,0);
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    if (puVar5 != (undefined1 *)0x0) {
      *puVar5 = 0x89;
    }
  }
  if ((*(int *)((longlong)param_1 + 0x54) == 0) && (0xff < *(int *)(param_1 + 0xb))) {
    lVar9 = FUN_140932570(piVar2);
    uVar10 = CONCAT44(uVar14,6);
    FUN_140932a90(piVar2,0x19,6,0,uVar10,0,0x200,2);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),7);
    lVar8 = FUN_140931b80(piVar2,3,6,0,uVar10,0);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),0x106);
    FUN_140932690(piVar2,9,1,0,uVar10,0xfffffffffffffffe);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),0x106);
    FUN_140932690(piVar2,9,3,0,uVar10,0);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),0x200);
    lVar6 = FUN_140931b80(piVar2,1,1,0,uVar10,
                          (longlong)(ulonglong)*(uint *)(param_1 + 0xb) >> 8 & 0xff);
    if ((lVar6 != 0) && (lVar9 != 0)) {
      *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) | 1;
      *(longlong *)(lVar6 + 0x18) = lVar9;
    }
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),0x200);
    lVar6 = FUN_140931b80(piVar2,1,3,0,uVar10,*(undefined1 *)(param_1 + 0xb));
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    if ((lVar6 != 0) && (lVar9 != 0)) {
      *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) | 1;
      *(longlong *)(lVar6 + 0x18) = lVar9;
    }
    lVar9 = FUN_140932570(piVar2);
    if ((lVar8 != 0) && (lVar9 != 0)) {
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) | 1;
      *(longlong *)(lVar8 + 0x18) = lVar9;
    }
    uVar10 = CONCAT44(uVar14,6);
    FUN_140932a90(piVar2,0x1b,0x10b,(longlong)*(int *)(param_1 + 7),uVar10,0,0x200,2);
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
  }
  else {
    uVar10 = CONCAT44(uVar14,7);
    lVar8 = FUN_140931b80(piVar2,3,6,0,uVar10,0);
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    lVar9 = FUN_140932570(piVar2);
    if (*piVar2 == 0) {
      iVar1 = *(int *)(param_1 + 7);
      piVar2[0x1a] = 0;
      uVar14 = 0;
      FUN_14092aa10(piVar2,0x10b,(longlong)iVar1 + 0x30,6,0);
    }
    FUN_1409309e0(param_1);
    FUN_14091c090(param_1,*(undefined4 *)((longlong)param_1 + 0x54),&local_res8,1);
    uVar10 = CONCAT44(uVar14,7);
    lVar6 = FUN_140931b80(piVar2,2,6,0,uVar10,0);
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    if ((lVar6 != 0) && (lVar9 != 0)) {
      *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) | 1;
      *(longlong *)(lVar6 + 0x18) = lVar9;
    }
    lVar9 = FUN_140932570(piVar2);
    if ((lVar8 != 0) && (lVar9 != 0)) {
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) | 1;
      *(longlong *)(lVar8 + 0x18) = lVar9;
    }
    if (*piVar2 == 0) {
      iVar1 = *(int *)(param_1 + 7);
      piVar2[0x1a] = 0;
      uVar14 = 0;
      FUN_14092aa10(piVar2,0x10b,(longlong)iVar1 + 0x30,6,0);
    }
    lVar9 = FUN_140932570(piVar2);
    for (plVar3 = local_res8; plVar3 != (longlong *)0x0; plVar3 = (longlong *)plVar3[1]) {
      lVar6 = *plVar3;
      if ((lVar6 != 0) && (lVar9 != 0)) {
        *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) | 1;
        *(longlong *)(lVar6 + 0x18) = lVar9;
      }
    }
  }
  uVar10 = CONCAT44(uVar14,5);
  FUN_140932690(piVar2,6,6,0,uVar10,0);
  uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
LAB_14093038a:
  lVar6 = FUN_140932450(piVar2,0x16);
  lVar9 = lVar7;
  if (bVar4) {
    lVar7 = FUN_140932570(piVar2);
    uVar10 = CONCAT44(uVar14,6);
    FUN_140932a90(piVar2,0x19,6,0,uVar10,0,0x200,2);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),7);
    lVar8 = FUN_140931b80(piVar2,3,6,0,uVar10,0);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),0x106);
    FUN_140932690(piVar2,9,1,0,uVar10,0);
    uVar12 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),1);
    FUN_140932a90(piVar2,0x21b,0,0,uVar12,0,0x200,*(undefined1 *)(param_1 + 0xb));
    uVar12 = uVar12 & 0xffffffff00000000;
    FUN_140932fc0(piVar2,6,1,0,uVar12,0,0);
    uVar10 = CONCAT44((int)(uVar12 >> 0x20),1);
    FUN_140932a90(piVar2,0x21,1,0,uVar10,0,0x200,1);
    uVar10 = CONCAT44((int)((ulonglong)uVar10 >> 0x20),6);
    FUN_140932a90(piVar2,0x19,6,0,uVar10,0,1,0);
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
    lVar9 = FUN_140932450(piVar2,0x16);
  }
  uVar10 = FUN_140932570(piVar2);
  if ((bVar4) || (*(int *)((longlong)param_1 + 0x13c) != 0)) {
    uVar13 = CONCAT44(uVar14,0x106);
    FUN_140932690(piVar2,9,1,0,uVar13,0);
    uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
    if (bVar4) {
      uVar13 = CONCAT44(uVar14,0x200);
      lVar11 = FUN_140931b80(piVar2,0,1,0,uVar13,
                             (longlong)(ulonglong)*(uint *)(param_1 + 0xb) >> 8 & 0xff);
      uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
      if ((lVar11 != 0) && (lVar7 != 0)) {
        *(ulonglong *)(lVar11 + 0x10) = *(ulonglong *)(lVar11 + 0x10) & 0xfffffffffffffffd;
        *(ulonglong *)(lVar11 + 0x10) = *(ulonglong *)(lVar11 + 0x10) | 1;
        *(longlong *)(lVar11 + 0x18) = lVar7;
      }
    }
  }
  uVar13 = CONCAT44(uVar14,6);
  FUN_140932a90(piVar2,0x19,6,0,uVar13,0,0x200,2);
  if (*(int *)((longlong)param_1 + 0x13c) != 0) {
    uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),0x200);
    lVar7 = FUN_140931b80(piVar2,2,1,0,uVar13,0xd800);
    uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),1);
    FUN_140932a90(piVar2,0x1e,1,0,uVar13,0,0x200,0xfc00);
    uVar12 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),1);
    FUN_140932a90(piVar2,0x21b,0,0,uVar12,0,0x200,0xd800);
    FUN_140932fc0(piVar2,6,1,0,uVar12 & 0xffffffff00000000,0,0);
    FUN_140932a90(piVar2,0x21,1,0,1,0,0x200,1);
    FUN_140932a90(piVar2,0x19,6,0,6,0,1,0);
    lVar11 = FUN_140932570(piVar2);
    if ((lVar7 != 0) && (lVar11 != 0)) {
      *(ulonglong *)(lVar7 + 0x10) = *(ulonglong *)(lVar7 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar7 + 0x10) = *(ulonglong *)(lVar7 + 0x10) | 1;
      *(longlong *)(lVar7 + 0x18) = lVar11;
    }
  }
  lVar7 = FUN_140932570(piVar2);
  if ((lVar6 != 0) && (lVar7 != 0)) {
    *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) & 0xfffffffffffffffd;
    *(ulonglong *)(lVar6 + 0x10) = *(ulonglong *)(lVar6 + 0x10) | 1;
    *(longlong *)(lVar6 + 0x18) = lVar7;
  }
  if (bVar4) {
    lVar7 = FUN_140932570(piVar2);
    if ((lVar8 != 0) && (lVar7 != 0)) {
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar8 + 0x10) = *(ulonglong *)(lVar8 + 0x10) | 1;
      *(longlong *)(lVar8 + 0x18) = lVar7;
    }
    lVar7 = FUN_140932570(piVar2);
    if ((lVar9 != 0) && (lVar7 != 0)) {
      *(ulonglong *)(lVar9 + 0x10) = *(ulonglong *)(lVar9 + 0x10) & 0xfffffffffffffffd;
      *(ulonglong *)(lVar9 + 0x10) = *(ulonglong *)(lVar9 + 0x10) | 1;
      *(longlong *)(lVar9 + 0x18) = lVar7;
    }
  }
  return uVar10;
}


