
#include "Header.h"
using namespace std;

bool employee::has_read(string bookTitle)
{
	for (int i = 0; i < read.size(); ++i) {
		if (read.at(i) == bookTitle);
		return true;
	}
	return false;
}

void employee::add_book_to_history(string bookTitle)
{
	read.push_back(bookTitle);
}

employee NewEmployee(string newName)
{
	employee tempEmployee(newName);
	return tempEmployee;

}