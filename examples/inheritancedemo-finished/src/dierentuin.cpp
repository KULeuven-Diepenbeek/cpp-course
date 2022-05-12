
#include "dierentuin.h"
#include "dier.h"

void Dierentuin::koopDier(Dier& dier) {
	dieren.push_back(std::make_shared<Dier>(dier));
}

bool Dierentuin::voeder(std::vector<Voedsel*> eten) {
	for(int i = 0; i < eten.size(); i++) {
		Dier* huidigDier = dieren.at(i).get();
		Voedsel* huidigVoedsel = eten.at(i);

		if(!huidigDier->kanEten(*huidigVoedsel)) {
			return false;
		}
	}
	return true;
}
