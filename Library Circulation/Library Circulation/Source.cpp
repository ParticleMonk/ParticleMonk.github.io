#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int main() {

	Library library;
	library.add_employee(NewEmployee("Adam"));
	library.add_employee(NewEmployee("Sam"));
	library.add_employee(NewEmployee("Ann"));


	
	/*library.circulate_book("Chemistry");
	library.circulate_book("Software Engineering");*/

	library.circulate_book("Life", CreateDate("2015/03/01"));
	library.circulate_book("Software Engineering", CreateDate("2015/4/1"));
	

	
	library.pass_on("Chemistry", CreateDate("2015/4/5"));
	library.pass_on("Chemistry", CreateDate("2015/3/7"));
	library.pass_on("Chemistry", CreateDate("2015/3/15"));

	library.pass_on("Software Engineering", CreateDate("2015/4/5"));
	library.pass_on("Software Engineering", CreateDate("2015/4/10"));
	library.pass_on("Software Engineering", CreateDate("2015/4/15"));

	return 0;
}