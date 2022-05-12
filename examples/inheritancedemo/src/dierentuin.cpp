
#include "dierentuin.h"

bool Dierentuin::voeder(std::vector<Voedsel*> eten) {
	for(int i = 0; i < dieren.size(); i++) {
		Dier* huidigDier = dieren.at(i);
		Voedsel* huidigVoedsel = eten.at(i);

		if(!huidigDier->kanEten(*huidigVoedsel)) {
			return false;
		}
	}

	return true;
}
