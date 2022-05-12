//
// Created by Wouter Groeneveld on 08/11/18.
//

#include "interval.h"

Interval Interval::operator+(Interval& other) {
    int begin = this->begin < other.begin ? this->begin : other.begin;
    int einde = this->einde > other.einde ? this->einde : other.einde;

    return Interval(begin, einde);
}

bool Interval::inclusief(int ander) {
    return ander >= begin && ander <= einde;
}
