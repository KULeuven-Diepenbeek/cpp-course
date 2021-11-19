
#include "shelf.h"
#include "book.h"

#include <iostream>
#include <utility>

// version 1: pass as a const lvalue reference, creating a COPY
void Shelf::buyNonfiction(const Nonfiction& book) {
	std::cout << "  // pass in as const lval ref" << std::endl;
	nonfictionBooks.push_back(book); // creates a copy
}

// version 2: pass as a rvalue reference, MOVING (stealing) the original contents (hence no const)
// after this is moved, book can still exist, but is in an unknown state, and can at any time be destructed
// that means we should assign nullptr to pointer members of the old object, if any. 
void Shelf::buyNonfiction(Nonfiction&& book) {
	std::cout << "  // pass in as rvalue ref" << std::endl;
	nonfictionBooks.push_back(std::move(book)); // steals properties -- provides no guarantees to original object
}

/**
 * below is a buyNonfiction version which attempts to push to the abstract books vector, requiring casts etc
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
*/

void Shelf::buy(Book& book) {
	// move the reference to here, does this work?
	// can't directly take reference of rvalue reference result from std::move -- see https://en.cppreference.com/w/cpp/utility/move
	Book&& local = std::move(book);

	// answer: it does NOT -- the object is destroyed after this method is called.
	books.push_back(&local);
}
