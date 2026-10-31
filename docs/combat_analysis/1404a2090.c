
bool FUN_1404a2090(undefined8 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  switch(param_2) {
  case 1:
    return param_3 == param_4;
  case 2:
    return param_3 != param_4;
  case 3:
    return param_4 < param_3;
  case 4:
    return param_4 <= param_3;
  case 5:
    return param_3 < param_4;
  case 6:
    return param_3 <= param_4;
  default:
    return false;
  }
}

