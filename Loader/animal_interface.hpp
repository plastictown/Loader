#pragma once
#ifndef __ANIMAL_INTERFACE_HPP__
#define __ANIMAL_INTERFACE_HPP__

#include <string>
#include <iostream>
#if defined (WIN32) || defined (_WIN32) || defined (_MSC_VER)
#include <Windows.h>

typedef const char* (*sound_func)();
typedef float(*weight_func)();

struct AnimalLoader
{
  sound_func sf = nullptr;
  weight_func wf = nullptr;
  HMODULE hm = NULL;

  bool load_image(const std::string& path)
  {
    hm = LoadLibraryA(path.c_str());
    if (hm == NULL)// can't load module
      return false;

    sf = (sound_func)GetProcAddress(hm, "sound");
    wf = (weight_func)GetProcAddress(hm, "weight");
    if (sf == nullptr && wf == nullptr)
      return false;
    return true;
  }

  ~AnimalLoader()
  {
    if (hm != NULL)
    {
      FreeLibrary(hm);
      sf = nullptr;
      wf = nullptr;
    }
  }

  void print_sound()
  {
    if (sf != nullptr)
      std::cout << "sound: " << sf() << std::endl;
    else
      std::cout << "sound func not loaded" << std::endl;
  }

  void print_weight()
  {
    if (wf != nullptr)
      std::cout << "weight: " << wf() << std::endl;
    else
      std::cout << "weight func not loaded" << std::endl;
  }

};

#endif // !WIN32

#endif // !__ANIMAL_INTERFACE_HPP__
