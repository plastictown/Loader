// cow.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "cow.h"

const char* sound()
{
  return "[ Mooo ]";
}

float weight()
{
  return 100.0f;
}

