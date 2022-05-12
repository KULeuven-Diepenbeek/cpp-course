#ifndef _SJIEKETUIN_H
#define _SJIEKETUIN_H

#include <vector>
#include "voedsel.h"
#include "dier.h"

template<typename T> class Sjieketuin {
private:
	// use templating here instead of dierentuin pointer crap!
	std::vector<T> dieren;
public:
	bool voeder(std::vector<Voedsel*> eten);
	void koopDier(T dier) {
		dieren.push_back(dier);
	}
};

// this CANNOT be placed in a cpp file
// see https://stackoverflow.com/questions/1022623/c-shared-library-with-templates-undefined-symbols-error/
template<typename T> bool Sjieketuin<T>::voeder(std::vector<Voedsel*> eten) {
	for(int i = 0; i < eten.size(); i++) {
		T huidigDier = dieren.at(i);
		Voedsel* huidigVoedsel = eten.at(i);

		if(!huidigDier.kanEten(*huidigVoedsel)) {
			return false;
		}
	}
	return true;
}

#endif
