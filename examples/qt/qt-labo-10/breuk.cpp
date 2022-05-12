#include "breuk.h"

#include <iostream>

Breuk Breuk::operator+(Breuk& other) {
    return Breuk(teller + other.teller, noemer + other.noemer);
}

std::ostream& operator<<(std::ostream& os, Breuk& breuk) {
    os << std::to_string(breuk.teller) << "/" << std::to_string(breuk.noemer) << std::endl;
    return os;
}
