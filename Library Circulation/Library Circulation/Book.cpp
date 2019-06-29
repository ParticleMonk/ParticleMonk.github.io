#include "Header.h"
//Creates a new instance of a book with these default values for each attribute
book::book(string name, date dateIncoming)
{
	this->name = name;
	start_date.set_date(dateIncoming.get_S_date());
}

//Incremements the amount of times the book has used
void book::use()
{
	times_used += 1;
}

//updates the current date to the date passed in
void book::update_current(date newdate)
{
	current_date.set_date(newdate.get_S_date());
}

//Returns the current date 
date book::get_current_date()
{
	return current_date;
}

//Returns the date the book started in circulation
date book::get_start_date()
{
	return start_date;
}

//Returns the name of the book 
string book::get_name()
{
	return name;
}

//Returns the usage of the book in days 
int book::get_usage()
{
	return times_used;
}