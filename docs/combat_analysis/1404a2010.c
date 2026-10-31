
bool FUN_1404a2010(undefined8 param_1,undefined4 param_2,float param_3,float param_4)

{
  switch(param_2) {
  case 1:
    if (param_3 == param_4) {
      return true;
    }
    break;
  case 2:
    if (param_3 != param_4) {
      return true;
    }
    break;
  case 3:
    return param_4 < param_3;
  case 4:
    return param_4 <= param_3;
  case 5:
    return param_3 < param_4;
  case 6:
    return param_3 <= param_4;
  }
  return false;
}

