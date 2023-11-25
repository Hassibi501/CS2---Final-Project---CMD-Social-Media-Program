/*
 * Date.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: lorde
 */

#include "Date.hpp"

Date::Date(){
this->day = 0;
this->month = 0;
this->year = 0;
}

Date:: ~Date(){

}

bool Date::setDay(int day) {
    if (this->month == 0 || this->year == 0) {
        this->day = 0;
        return false;
    }

    if ((this->month % 2 == 0 && this->month < 7 && this->month != 2)
            || (this->month == 9) || (this->month == 11)) {
        if (day > 0 && day <= 30) {
            this->day = day;
            return true;
        }
    }
    if ((this->month % 2 == 1 && this->month < 8) || (this->month == 8)
            || (this->month == 10) || (this->month == 12)) {
        if (day > 0 && day <= 31) {
            this->day = day;
            return true;
        }
    }
    if (this->month == 2 && day > 0 && day <= 28) {
        this->day = day;
        return true;
    }
    return false;
}

int Date::getMonth() const {
    return month;
}

bool Date::setMonth(int month) {
    if (this->year > 0) {
        if (month > 0 && month <= 12) {
            this->month = month;
            return true;
        } else
            return false;
    } else
        return false;
}

int Date::getYear() const {
    return year;
}

bool Date::setYear(int year) {
    if (year > 0 && year <= 9999) {
        this->year = year;
        return true;
    }
    return false;
}



std::string Date:: getDate()const {
	return std::to_string (year) +  "/" + std::to_string(month) + "/" + std::to_string(day);
	//return "" + Year + "/" + Month + "/" + Day + "\n";
}

std::string Date:: toString() {
		return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year) + '\n';
	}

