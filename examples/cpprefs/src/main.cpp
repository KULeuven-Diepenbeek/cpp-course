
#include <iostream>
#include "shelf.h"
#include "nonfiction.h"

void buySpecificNonfictionBooksFor(Shelf& shelf) {
	for(int i = 1; i <= 10; i++) {
		// this STACK variable can be stolen thanks to the rvalue reference buy implementation
		Nonfiction someBook("cool title " + std::to_string(i), i);

		// by using MOVE, we convert lvalue variable someBook to an rvalue reference, avoiding creating another book
		shelf.buyNonfiction(std::move(someBook));

		// by passing in the lvalue variable someBook as is, we ultimately create a copy, even if the parameter is a REFERENCE
		//shelf.buyNonfiction(someBook);
		std::cout << "bought book " << i << std::endl;
	}

	std::cout << "TOTAL: bought " << shelf.getAmountOfNonfictionBooks() << " books" << std::endl;

	// since readNonfiction returns a REFERENCE, we don't need to bother with ->
	std::cout << "example 4: " << shelf.readNonfiction(4).getPages() << " pages" << std::endl;
}


void buyRandomBooksFor(Shelf& shelf) {
	for(int i = 0; i < 10; i++) {
		// needs to be an explicit variable because of type/inheritance system
		// otherwise: non-const lvalue reference to type 'Book' cannot bind to a temporary of type 'Nonfiction'

		// If this is a STACK variable and we pass it as a value object, it'll be copied in!
		// this is IMPOSSIBLE for abstract classes:
		// allocating an object of abstract class type 'Book'

		// alt. option 1: use a REFERENCE
		/// if this is a STACK variable and we pass it as a REFERENCE (&), it'll be gone after this method ends!
		// creating undefined behavior, such as printing 4564978 as page number #100 instead of the expected 100.
		// this is NOT easily visible when compiled with Clang...
		Nonfiction someBook("cool title " + std::to_string(i), i + 1);

		// alt. option 2: move the referencein the buy method using std::move

		// alt. option 3: create a pointer.
		//Nonfiction* someBook = new Nonfiction("cool title " + std::to_string(i), i + 1);

		shelf.buy(someBook);
		std::cout << "bought book " << i << std::endl;
		someBook.setPages(666); // verify we've modified the object instead of on a copy.
	}

	std::cout << "TOTAL: bought " << shelf.getAmountOfBooks() << " books" << std::endl;
	std::cout << "example 4: " << shelf.read(4)->getPages() << " pages" << std::endl;
}


/**
 * Inspect "best practices" by browsing through "decent" C++ codebases, such as:
 * https://github.com/lballabio/QuantLib
 * https://github.com/catchorg/Catch2
 * https://github.com/scummvm/scummvm
 * Conclusion? Lots of const Type& references, no std::ref() usages, little ::move(), reduce raw pointer usage to bare minimum
 * Performance-based code such as some Scumm engines do rely on * more often than other codebases. 
 */ 
int main() {
	std::cout << "cpp refs example" << std::endl;

	Shelf bookshelf;
	//buyRandomBooksFor(bookshelf);

	buySpecificNonfictionBooksFor(bookshelf);

	std::cout << " -- all done!" << std::endl;
	// all "killed book x" statements beyond this point are because of variable 'bookshelf's end of life.

	return 0;
}
