
#include <iostream>

#include "vlees.h"
#include "kat.h"
#include "groenten.h"
#include "dierentuin.h"

int main() {
	Kat miauw;
	Vlees hesp;
	Groenten spruitjes("groene spruitjes");

	std::cout << "kat beweegt: " << miauw.beweeg() << std::endl;
	std::cout << "kan een kat spruitjes eten? " << miauw.kanEten(spruitjes) << std::endl;
	std::cout << "een hesperolleke dan? " << miauw.kanEten(hesp) << std::endl;

	Dierentuin gaiaZoo;
	gaiaZoo.steel(&miauw);

	std::vector<Voedsel*> troggen;
	troggen.push_back(&spruitjes);

	std::cout << "kan dierentuin voederen? ";
	std::cout << gaiaZoo.voeder(troggen);
	std::cout << std::endl;
}
