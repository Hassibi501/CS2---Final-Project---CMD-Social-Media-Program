/*
 * SMUserPosts.hpp
 *
 *  Created on: May 18, 2023
 *      Author: lorde
 */

#ifndef SMUSERPOSTS_HPP_
#define SMUSERPOSTS_HPP_
#include "Date.hpp"
#include <string>
struct PostTime {
	int hour;
	int minute;
	int second;
};
class SMUserPosts {
public:
	SMUserPosts();
	virtual ~SMUserPosts();

	const Date& getDateOfPost() const;
	void setDateOfPost(const Date &dateOfPost);
	const std::string& getPostsText() const;
	void setPostsText(const std::string &postsText);
	const std::string& getUserIdPost() const;
	void setUserIdPost(std::string &userIdPost);
	int getHour() const;
	void setHour(int hour);
	int getMinute() const;
	void setMinute(int minute);
	int getSecond() const;
	void setSecond(int second);

	std::string getPostTime()const;

private:
	std::string userIDPost;
	Date dateOfPost;

	PostTime postTime;
	std::string postsText;
};

#endif /* SMUSERPOSTS_HPP_ */
