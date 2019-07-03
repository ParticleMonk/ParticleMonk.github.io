#include <iostream>
#include "Library.h"
#include <string>

using namespace std; 

int main() {

	Library library;
	library.addEmployee("Adam");
	library.addEmployee("Sam");
	library.addEmployee("Ann");

	library.addBook("Chemistry");
	library.addBook("Software Engineering");

	library.circulateBook("Chemistry", Date(2015, 3, 1));
	library.circulateBook("Software Engineering", Date(2015, 4, 1));

	library.passOn("Chemistry", Date(2015, 3, 5));
	library.passOn("Chemistry", Date(2015, 3, 7));
	library.passOn("Chemistry", Date(2015, 3, 15)); 

	library.passOn("Software Engineering", Date(2015, 4, 5));
	library.passOn("Software Engineering", Date(2015, 4, 10));
	library.passOn("Software Engineering", Date(2015, 4, 15));

	return 0; 
}