#ifndef _DIERENTUIN_H
#define _DIERENTUIN_H

#include <vector>
#include <memory>
#include "voedsel.h"
#include "dier.h"

class Dierentuin {
private:
	// using "Dier" causes "error: allocating an object of abstract class type 'Dier'"
	// because we're using the copy constructor!
	std::vector<std::shared_ptr<Dier>> dieren;
public:
	bool voeder(std::vector<Voedsel*> eten);
	void koopDier(Dier& dier);
};

#endif
