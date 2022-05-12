#ifndef _VLEES_H
#define _VLEES_H

#include "voedsel.h"

class Vlees : public Voedsel {
    int voedingswaarde() override { return 10; }
};

#endif
