#include "punt.h"
#include <iostream>

// TODO uncomment this line and see what it does in the compiled .o files
// see https://kuleuven-diepenbeek.github.io/cpp-course/cpp/inheritance/
// use "nm [file] | c++filt"
extern template int punt(int x);

void punt1() {
  auto pt = punt<int>(5);  // template<int> compiled

  std::cout << "punt1:" << pt << std::endl;
}
