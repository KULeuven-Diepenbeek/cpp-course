
#include "shelf.h"
#include "book.h"

#include <iostream>

void Shelf::buyNonfiction(Nonfiction book) {
	// this WON'T work: no matching member function for call to 'push_back'
	// books.push_back(&book);

	// we'll need to cast it
	// static casting and assigning to the abstract class type doesn't work: allocating an object of abstract class type 'Book'
	// Book baseBook = static_cast<Book>(book);

	// For this to work, we need to use pointers
	// the trouble is, buyNonfiction(Nonfiction book) accepts a STACK var, creating and destroying a copy
	// putting us again in the dangling pointer situation. 
	Book* baseBook = static_cast<Book*>(&book);

	books.push_back(baseBook);
}

void Shelf::buy(Book& book) {
	// move the reference to here, does this work?
	// can't directly take reference of rvalue reference result from std::move -- see https://en.cppreference.com/w/cpp/utility/move
	Book&& local = std::move(book);

	books.push_back(&local);
}
