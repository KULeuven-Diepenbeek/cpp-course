#ifndef _DIERENTUIN_H
#define _DIERENTUIN_H

#include <vector>
#include "dier.h"
#include "voedsel.h"

class Dierentuin {
private:
	std::vector<Dier*> dieren;
	
public:
	void steel(Dier* dier) {
		dieren.push_back(dier);
	}
	bool voeder(std::vector<Voedsel*> eten);
};

#endif