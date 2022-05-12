#ifndef _VIERVOETER_H
#define _VIERVOETER_H

#include "dier.h"

class Viervoeter : public Dier {
protected:
    int aantalPoten;

public:
    Viervoeter() : aantalPoten(4) {}
};

#endif
