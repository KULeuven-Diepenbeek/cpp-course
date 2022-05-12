#include <iostream>
using namespace std;

class Student {
private:
    int leeftijd;
public:
    Student(int leeftijd) : leeftijd(leeftijd) {}
    //friend bool operator>(const Student& student1, const Student& student2);
};
/*
bool operator>(const Student& student1, const Student& student2) {
    return student1.leeftijd > student2.leeftijd;
}*/

int main() {
    Student jaak(20), lowie(10); 
    cout << "wie is ouder? " << (jaak > lowie) << endl;
    return 0;
}