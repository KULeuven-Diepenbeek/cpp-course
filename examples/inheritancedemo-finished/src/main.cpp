
#include <iostream>

#include "vlees.h"
#include "kat.h"
#include "groenten.h"

#include "dierentuin.h"
#include "sjieketuin.h"

int main() {
	Kat miauw;
	Vlees hesp;
	Groenten spruitjes("groene spruitjes");

	std::cout << "kat beweegt: " << miauw.beweeg() << std::endl;
	std::cout << "kan een kat spruitjes eten? " << miauw.kanEten(spruitjes) << std::endl;
	std::cout << "een hesperolleke dan? " << miauw.kanEten(hesp) << std::endl;

	Dierentuin tuin;
	tuin.koopDier(static_cast<Dier&>(miauw));
	std::vector<Voedsel*> eten;
	eten.push_back(&hesp);

	std::cout << "kan de dierentuin iedereen te eten geven? " << std::endl;
	std::cout << tuin.voeder(eten) << std::endl;

	Sjieketuin<Kat> sjiek;
	sjiek.koopDier(miauw);

	std::cout << "kan de SJIEKE tuin iedereen te eten geven? " << std::endl;
	std::cout << sjiek.voeder(eten) << std::endl;
}
