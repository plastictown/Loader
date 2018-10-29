// cat.cpp: определяет экспортированные функции для приложения DLL.
//
#include "stdafx.h"
#include "cat.h"

const char* sound()
{
  return "[ Meow ]";
}

float weight()
{
  return 3.5f;
}