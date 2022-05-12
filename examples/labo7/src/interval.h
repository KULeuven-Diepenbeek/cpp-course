#ifndef _INTERVAL_H
#define _INTERVAL_H

class Interval {
private:
    int begin, einde;
public:
    Interval(int begin, int einde) : begin(begin), einde(einde) {}
    bool inclusief(int ander);
    int getBegin() { return begin; };
    int getEinde() { return einde; };

    Interval operator+(Interval& other);
};

#endif