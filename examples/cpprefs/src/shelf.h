#ifndef _SHELF_H
#define _SHELF_H

#include <vector>
#include "book.h"
#include "nonfiction.h"

class Shelf {
private:
	std::vector<Book*> books;
	std::vector<Nonfiction> nonfictionBooks;
	// do you want to store references? use std::vector<std::reference_wrapper<Nonfiction>> (and std::ref() to convert lvalue to rvalue)

public:
	void buy(Book& book);
	void buyNonfiction(const Nonfiction& book);
	void buyNonfiction(Nonfiction&& book);

	// returning a pointer as an lvalue is dangerous: it states "do whatever you want, here's the address."
	Book* read(int i) { return books.at(i); };
	int getAmountOfBooks() { return books.size(); };

	// returning a reference simplifies code and reduces functionality to rvalue. Adding const is even better
	// if const is added, methods called with the ref also should be declared const (after parenthesis before brackets, e.g. getPages() in book.h)
	// if const was NOT added, readNonfiction(3) = Nonfiction("new book", 5); would be a VALID statement!!
	const Nonfiction& readNonfiction(int i)  { return nonfictionBooks.at(i); };
	int getAmountOfNonfictionBooks() { return nonfictionBooks.size(); };

};

#endif
