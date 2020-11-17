#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Sollicitant {
protected:
	vector<string> diplomas;
public:
	bool geschiktVoor(string diploma);
};
bool Sollicitant::geschiktVoor(string diploma) {
	return find(diplomas.begin(), diplomas.end(), diploma) != diplomas.end();
}

class Universitair : public Sollicitant {
public:
	Universitair() {
		diplomas.push_back("master in de dingesologie");
	};
};

class Doctor : public Sollicitant {
public:
	Doctor() {
		diplomas.push_back("doctor in de blaatschappen");
	};
};

class Vacature {
private:
	string onderwerp;
	int aantalSollicitanten;
	vector<string> diplomas;
public:
	Vacature(string o, string diploma) : onderwerp(o), aantalSollicitanten(0) {
		diplomas.push_back(diploma);
	};
	int getAantalSollicitanten() { return aantalSollicitanten; };
	string getOnderwerp() { return onderwerp; };
	bool solliciteer(const Sollicitant& sollicitant);
};
bool Vacature::solliciteer(const Sollicitant& sollicitant) {
	aantalSollicitanten++;
	for(auto diploma : diplomas) {
		if(sollicitant.geschiktVoor(diploma)) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << "we gaan solliciteren..." << endl;

	Universitair joske;
	Doctor jefke;
	Vacature cooleJob("super programmeur", "doctor in de blaatschappen");

	cout << "mag universitair joske als programmeur beginnen? " << cooleJob.solliciteer(joske) << endl;
	cout << "mag doctor jefke als programmeur beginnen? " << cooleJob.solliciteer(jefke) << endl;

	cout << "done! bye!" << endl;
	return 0;
}

