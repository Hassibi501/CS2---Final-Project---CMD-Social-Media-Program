/*
 * Date.hpp
 *
 *  Created on: Apr 12, 2023
 *      Author: lorde
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include<string>


class Date {
public:
	Date();
	virtual ~Date();

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	bool setDay(int Day);
	bool setMonth(int Month);
	bool setYear(int Year);

	std::string getDate() const;

	std::string toString();



private:
	int year, month, day;
};

#endif /* DATE_HPP_ */
