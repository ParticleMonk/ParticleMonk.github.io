
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <sstream>
#include "Header.h"


date::date() {
	year = 0000;
	month = 00;
	day = 00;
}

date date::get_date() {
	date temp_date;

	temp_date.year = 0000;
	temp_date.month = 00;
	temp_date.day = 00;

	return temp_date;
}

string date::get_S_date() {
	string s_date;

	s_date = year + '/' + month + '/' + day;

	return s_date;
}

int date::get_difference(date incoming_date)
{
	vector <int> months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31, 29 };
	int diff_y = 0, diff_m = 0, diff_d = 0, lesser_year = 0, greater_year = 0;

	if (incoming_date.year != year) {
		if (year > incoming_date.year) {
			lesser_year = incoming_date.year;
			greater_year = year;
		}
		else {
			lesser_year = year;
			greater_year = incoming_date.year;
		}
		for (int x = lesser_year; lesser_year < greater_year - 1; x++) {
			if (x % 4 == 0) {
				diff_y += 366;
			}
			else {
				diff_y += 365;
			}
		}
	}
	else if (incoming_date.month != month) {
		if (incoming_date.year == year) {
			if (incoming_date.month > month) {
				for (int x = incoming_date.month; x < month - 1; x++) {
					if ((year % 4) == 0 && x == 3) {
						diff_m += months.at(12);
					}
					else {
						diff_m += months.at(x - 1);
					}
				}
			}
			else {
				for (int x = month; x < incoming_date.month - 1; x++) {
					if ((year % 4) == 0 && x == 3) {
						diff_m += months.at(12);
					}
					else {
						diff_m += months.at(x - 1);
					}
				}
			}
		}
		else {
			if (incoming_date.year == greater_year) {
				for (int x = month; x == incoming_date.month - 1; x++) {
					if ((greater_year % 4) == 0 && x == 3) {
						diff_m += months.at(12);
					}
					else {
						diff_m += months.at(0);
					}
					if (x == 11) {
						x = -1;
					}
				}
			}
			else {
				for (int x = incoming_date.month; x == month - 1; x++) {
					if ((greater_year % 4) == 0 && x == 3) {
						diff_m += months.at(12);
					}
					else {
						diff_m += months.at(x);
					}
					if (x == 11) {
						x = -1;
					}
				}
			}
		}
	}
	else if (incoming_date.day != day) {
		if (incoming_date.month == month) {
			diff_d += abs(day - incoming_date.day);
		}
		else {
			if (month > incoming_date.month) {
				for (int x = day; x == incoming_date.month; x++) {
					diff_d++;
					if (x == months.at(month)) {
						x = 0;
					}
				}
			}
			else {
				for (int x = incoming_date.day; x == month; x++) {
					diff_d++;
					if (x == months.at(incoming_date.month)) {
						x = 0;
					}
				}
			}
		}
	}
	return diff_y + diff_m + diff_y;
}

void date::set_date(string date_s) {
	string sday, smonth, syear;
	
	cout << date_s;

	smonth = date_s.substr(0, 4);
	sday = date_s.substr(3, 2);
	syear = date_s.substr(6, 2);
	
	istringstream nday(sday);
	istringstream nmonth(smonth);
	istringstream nyear(syear);

	nday >> day;
	nmonth >> month;
	nyear >> year;

}

date CreateDate(string date_incoming)
{
	date tempDate;
	tempDate.set_date(date_incoming);
	return tempDate;

}