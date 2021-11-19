
#include <iostream>
#include "shelf.h"
#include "nonfiction.h"

void buyRandomBooksFor(Shelf& shelf) {
	for(int i = 0; i < 3456793; i++) {
		// needs to be an explicit variable because of type/inheritance system
		// otherwise: non-const lvalue reference to type 'Book' cannot bind to a temporary of type 'Nonfiction'
		Nonfiction* someBook = new Nonfiction("cool title " + std::to_string(i), i + 1);

		// if we pass in a Nonfiction object, it gets COPIED!
		shelf.buy(*someBook);
		someBook->setPages(666);
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
