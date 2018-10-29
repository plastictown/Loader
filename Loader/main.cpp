#include <iostream>
#include "animal_interface.hpp"

using namespace std;

int main(int argc, char** argv)
{
  AnimalLoader cat, cow;
  std::cout << "trying to load module cat.dll" << endl;
  bool bcat = cat.load_image("cat.dll");
  if (bcat) cout << "module loaded" << endl;
  else cout << "can't load module" << endl;

  std::cout << "trying to load module cow.dll" << endl;
  bool bcow = cow.load_image("cow.dll");
  if (bcow) cout << "module loaded" << endl;
  else cout << "can't load module" << endl;

  if (!bcat && !bcow)
  {
    cout << "nothing to do. Abort." << endl;
    return 1;
  }

  if (bcat)
  {
    cat.print_sound();
    cat.print_weight();
  }
  if (bcow)
  {
    cow.print_sound();
    cow.print_weight();
  }
  cin.get();
  return 0;
}