#ifndef _BOOK_H
#define _BOOK_H

class Book {
protected:
	int pages;
public:
	Book(int p) : pages(p) {};
	
	int getPages() { return pages; };
	void setPages(int p) { pages = p; };
	virtual int getQuality() = 0;
};

#endif
