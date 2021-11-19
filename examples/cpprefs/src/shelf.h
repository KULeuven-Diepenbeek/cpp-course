#ifndef _SHELF_H
#define _SHELF_H

#include <vector>
#include "book.h"

class Shelf {
private:
	std::vector<Book*> books;
public:
	void buy(Book& book);
	Book* read(int i) { return books.at(i); };
	int getAmountOfBooks() { return books.size(); };
};

#endif
