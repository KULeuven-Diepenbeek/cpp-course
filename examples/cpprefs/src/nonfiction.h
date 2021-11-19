#ifndef _NONFICTION_H
#define _NONFICTION_H

#include <string>

class Nonfiction : public Book {
private:
	std::string title;
public:
	Nonfiction(std::string theTitle, int pages) : Book(pages), title(theTitle) {}

	int getQuality() override { return 20; };
	std::string getTitle() { return title; };
};

#endif
