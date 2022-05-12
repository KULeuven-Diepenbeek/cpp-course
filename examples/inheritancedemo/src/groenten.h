#ifndef _GROENTEN_H
#define _GROENTEN_H

#include <string>
#include "voedsel.h"

class Groenten : public Voedsel {
private:
    std::string naam;
public:
    Groenten(std::string denaam) : naam(denaam) {}
    int voedingswaarde() override { return 15; }
    inline std::string getNaam() { return naam; };
};

#endif
