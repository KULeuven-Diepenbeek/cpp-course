#ifndef _NONFICTION_H
#define _NONFICTION_H

#include <string>
#include <iostream>

class Nonfiction : public Book {
private:
	std::string title;
public:
	// new object constructor
	Nonfiction(std::string theTitle, int pages) : Book(pages), title(theTitle) {
		std::cout << "  -- NEW nonfiction with #" << pages << " pages" << std::endl;
	}
	// copy constructor
	Nonfiction(const Nonfiction& other) : Book(other.pages), title(other.title) {
		std::cout << "  -- COPY nonfiction with #" << pages << " pages" << std::endl;	
	}
	// copy assignment constructor
	// this is automatically synthesized if not present; copying everything non-static by value.
	Nonfiction& operator=(const Nonfiction other) {
		std::cout << "  -- COPY/ASS nonfiction with #" << pages << " pages" << std::endl;
		pages = other.pages;
		title = other.title;

		return *this;
	}
	// move constructor: only used with rvalue ref calls such as with std::move
	// primitive values (other.pages) are still copied
	// this is NOT automatically synthesized. If not present, the C++ compiler will default to the copy operator
	Nonfiction(Nonfiction &&other) noexcept : Book(other.pages), title(std::move(other.title)) {
		std::cout << "  -- MOVE nonfiction with #" << pages << " pages" << std::endl;
	}
	// the destructor is defined in Book.h, no special pointers to clean up here

	int getQuality() const override { return 20; };
	std::string getTitle() const { return title; };
};

#endif
