#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>

class Book {
protected:
	int pages;
public:
	Book(int p) : pages(p) {};
	virtual ~Book() {
		std::cout << "  \\\\ killed book " << pages << std::endl;
	};
	
	int getPages() const { return pages; };
	void setPages(int p) { pages = p; };
	virtual int getQuality() const = 0;
};

#endif
