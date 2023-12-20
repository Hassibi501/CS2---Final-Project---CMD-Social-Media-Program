/*
 * SMUsers.hpp
 *
 *  Created on: May 18, 2023
 *      Author: lorde
 */

#ifndef SMUSERS_HPP_
#define SMUSERS_HPP_
#include <string>
#include "Date.hpp"

class SMUsers {
public:
	SMUsers();
	virtual ~SMUsers();

	const std::string& getFirstName() const;
	void setFirstName(const std::string &firstName);
	const std::string& getLastName() const;
	void setLastName(const std::string &lastName);
	const Date& getMembershipDate() const;
	void setMembershipDate(const Date &membershipDate);
	const std::string& getUserId() const;
	void setUserId(std::string userId);

private:
	std::string userID;
	std::string firstName;
	std::string lastName;
	Date membershipDate;
};

#endif /* SMUSERS_HPP_ */
