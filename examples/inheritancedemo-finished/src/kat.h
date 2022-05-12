#ifndef _KAT_H
#define _KAT_H

#include <typeinfo>
#include "viervoeter.h"
#include "voedsel.h"
#include "vlees.h"

// forward definition of class vlees
//class Vlees;

class Kat : public Viervoeter {
private:
    int aantalKeerBewogen;
public:
    bool kanEten(const Voedsel &voedsel) override {
        return typeid(voedsel) == typeid(Vlees);
    }

    int beweeg() override {
        aantalKeerBewogen++;
        int velocity = aantalKeerBewogen >= 2 ? 5 : 15;
        return velocity * aantalPoten;
    }
};

#endif
