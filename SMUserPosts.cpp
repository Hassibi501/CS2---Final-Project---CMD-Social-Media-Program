/*
 * SMUserPosts.cpp
 *
 *  Created on: May 18, 2023
 *      Author: lorde
 */

#include "SMUserPosts.hpp"

SMUserPosts::SMUserPosts() {
	// TODO Auto-generated constructor stub
	this->userIDPost = "Unknown";
	this->postsText = "Unknown";
	this->postTime.hour = 0;
	this->postTime.minute = 0;
	this->postTime.second = 0;

}

SMUserPosts::~SMUserPosts() {
	// TODO Auto-generated destructor stub
}

const Date& SMUserPosts::getDateOfPost() const {
	return dateOfPost;
}

void SMUserPosts::setDateOfPost(const Date &dateOfPost) {
	this->dateOfPost = dateOfPost;
}

const std::string& SMUserPosts::getPostsText() const {
	return postsText;
}

void SMUserPosts::setPostsText(const std::string &postsText) {
	if (postsText.size() == 0)
		throw "Error: Post can not be blank";
	else {
		this->postsText = postsText;
	}
}

const std::string& SMUserPosts::getUserIdPost() const {
	return userIDPost;
}

void SMUserPosts::setUserIdPost(std::string &userIdPost) {
	userIDPost = userIdPost;
}

int SMUserPosts::getHour() const {
	return postTime.hour;
}

void SMUserPosts::setHour(int hour) {
	if (hour < 0 || hour >= 24){
		throw "Error: Hours can not be less than or equal to 0.";
	}
	else {
		postTime.hour = hour;
	}
}

int SMUserPosts::getMinute() const {
	return postTime.minute;
}

void SMUserPosts::setMinute(int minute) {
	if (minute < 0 || minute > 60){
		throw "Error: Minutes can not be less than or equal to 0.";
	}
	else {
		postTime.minute = minute;
	}
}

int SMUserPosts::getSecond() const {
	return postTime.second;
}

void SMUserPosts::setSecond(int second) {
	if (second < 0 || second > 60){
			throw "Error: Seconds can not be less than or equal to 0.";
		}
		else {
			postTime.second = second;
		}
}

std::string SMUserPosts:: getPostTime()const{
	return std::to_string(this->postTime.hour) + ":" + std::to_string(this->postTime.minute) + ":" + std::to_string(this->postTime.second);
}

