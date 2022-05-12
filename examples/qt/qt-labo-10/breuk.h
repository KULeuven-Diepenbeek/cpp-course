#ifndef BREUK_H
#define BREUK_H

#include <iostream>

class Breuk
{
private:
    int teller, noemer;
public:
    Breuk(int teller, int noemer) : teller(teller), noemer(noemer) {}
    Breuk operator+(Breuk& otehr);
    friend std::ostream& operator<<(std::ostream& os, Breuk& breuk);

    int getTeller() { return teller; }
    int getNoemer() { return noemer; }
};

#endif // BREUK_H
