
#include <iostream>
#include "shelf.h"
#include "nonfiction.h"

void buyRandomBooksFor(Shelf& shelf) {
	for(int i = 0; i < 3456793; i++) {
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
		someBook.setPages(666); // verify we've modified the object instead of on a copy.
	}

	std::cout << "bought " << shelf.getAmountOfBooks() << " books" << std::endl;
}

int main() {
	std::cout << "cpp refs example" << std::endl;

	Shelf bookshelf;
	buyRandomBooksFor(bookshelf);

	std::cout << "currently " << bookshelf.getAmountOfBooks() << " books" << std::endl;
	std::cout << "example 100: " << bookshelf.read(100)->getPages() << " pages" << std::endl;


	return 0;
}
