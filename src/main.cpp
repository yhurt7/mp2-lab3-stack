#include <iostream>
#include "TFormuls.h"
#include "TStack.h"

int main() {
  TFormuls a("(2+3)+4*7/2");
  a.Process();
  std::cout<<a.CheckFormuls()<<std::endl;
  std::cout<<a.Calculate()<<std::endl;
  std::cout<<a.GetPostfix();
  return 0;
}

