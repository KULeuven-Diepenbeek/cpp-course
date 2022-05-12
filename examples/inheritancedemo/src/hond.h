#ifndef _HOND_H
#define _HOND_H

#include "viervoeter.h"
#include "voedsel.h"

class Hond : public Viervoeter {
public:
    int beweeg() override {
        return 10 * aantalPoten;
    }
    bool kanEten(const Voedsel &voedsel) override {
        return true;
    }
};

#endif
