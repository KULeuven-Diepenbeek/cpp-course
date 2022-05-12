#include "interval.h"
#include <iostream>

using namespace std;

int main() {
    Interval i(10, 20);

    cout << "zit 15 tussen 10 en 20? " << (i.inclusief(15) ? "ja" : "nee") << endl;
    return 0;
}