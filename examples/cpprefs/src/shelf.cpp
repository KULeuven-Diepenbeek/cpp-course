
#include "shelf.h"
#include "book.h"

#include <iostream>

void Shelf::buy(Book& book) {
	//std::cout << "buying book with " << book.getPages() << " pages" << std::endl;
	books.push_back(&book);
}