/*
 * SMUsers.cpp
 *
 *  Created on: May 18, 2023
 *      Author: lorde
 */

#include "SMUsers.hpp"

SMUsers::SMUsers() {
	// TODO Auto-generated constructor stub
	this->firstName = "Unknown";
	this->lastName = "Unknown";
	this->userID = "Unknown";



}

SMUsers::~SMUsers() {
	// TODO Auto-generated destructor stub
}

const std::string& SMUsers::getFirstName() const {
	return firstName;
}

void SMUsers::setFirstName(const std::string &firstName) {
	if (firstName.size() == 0){
		throw "Error: First name can not be blank.";
	}
	else {
		this->firstName = firstName;
	}
}

const std::string& SMUsers::getLastName() const {
	return lastName;
}

void SMUsers::setLastName(const std::string &lastName) {
	if (lastName.size() == 0){
		throw "Error: Last name can not be blank.";
	}
	else {
		this->lastName = lastName;
	}
}

const Date& SMUsers::getMembershipDate() const {
	return membershipDate;
}

void SMUsers::setMembershipDate(const Date &membershipDate) {
	this->membershipDate = membershipDate;
}

const std::string& SMUsers::getUserId() const {
	return userID;
}

void SMUsers::setUserId(std::string userId) {
	if (userId <= " "){
		throw "Error: User ID can not be less than or equal to 0.";
	}
	else {
		userID = userId;
	}
}
