#include "punt.h"
#include <iostream>

void punt2() {
  auto pt = punt<int>(4);  // template<int> compiled - opnieuw!!

  std::cout << "punt2:" << pt << std::endl;
}
