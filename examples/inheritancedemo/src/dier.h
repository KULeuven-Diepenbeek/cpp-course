#ifndef _DIER_H
#define _DIER_H

#include "voedsel.h"

class Dier {
public:
    // these methods are purely virtual (=0)
    // see https://kuleuven-diepenbeek.github.io/cpp-course/cpp/inheritance/ for more information
    virtual bool kanEten(const Voedsel& voedsel) = 0;
    virtual int beweeg() = 0;
};

#endif
