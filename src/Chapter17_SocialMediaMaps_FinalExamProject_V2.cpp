//============================================================================
// Name        : Chapter17_SocialMediaMaps_FinalExamProject.cpp
// Author      : Hassieb Hassieb
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;
#include "SMUsers.hpp"
#include "SMUserPosts.hpp"



void clearCin() {
	cin.clear();
	cin.ignore(32768, '\n');
}
//
int main() {
int menuOptions = 0;
ifstream inputFile;
string inputRecord, tempString, fileNameInput;

map <string, SMUsers*> smusersMap;
map <string, SMUsers*>::iterator smusersMapIt;

multimap <string, SMUserPosts*> smusersMultiMap;
multimap <string, SMUserPosts*>::iterator smusersMultiMapIt;

string userName;
SMUsers* userInput = nullptr;

ofstream userErrorsFile("UserErrors.txt");
ofstream postErrorsFile("PostErrors.txt");


inputFile.open("SMUsers.csv");
	if (!inputFile) {
		cout << "Error: Can not access the input file. Please try again." << endl;
		return 0;
	}//if statement to check if file has opened correctly or not
	while (!inputFile.eof()) {
		SMUsers* tempObject = nullptr;
		try {

		getline(inputFile, inputRecord);
		if(inputRecord.size() == 0){
			continue;
		}
		stringstream strStream(inputRecord);
		tempObject = new SMUsers;

		try{
			getline(strStream, tempString, ',');
			tempObject->setUserId(tempString);

			getline(strStream, tempString, ',');
			tempObject->setFirstName(tempString);

			getline(strStream, tempString, ',');
			tempObject->setLastName(tempString);

			Date tempDate;
			getline(strStream, tempString, ',');
			if (!tempDate.setYear(stoi(tempString))){
				userErrorsFile << "Error: Year is invalid for user " << "\"" <<  tempObject->getUserId() << "\"" << " year that was inputed was" << "\"" << tempString << "\"" << endl;
				delete tempObject;
				continue;
			}//if


			getline(strStream, tempString, ',');
			if (!tempDate.setMonth(stoi(tempString))){
				userErrorsFile << "Error: Month is invalid for user " << "\"" <<  tempObject->getUserId() << "\"" << " month that was inputed was" << "\"" << tempString << "\"" << endl;
				delete tempObject;
				continue;
			}//if


			getline(strStream, tempString, ',');
			if (!tempDate.setDay(stoi(tempString))){
				userErrorsFile << "Error: Day is invalid for user " << "\"" <<  tempObject->getUserId() << "\"" << " day that was inputed was" << "\"" << tempString << "\"" << endl;
				delete tempObject;
				continue;
			}//if

			tempObject->setMembershipDate(tempDate);

			smusersMap.insert(make_pair(tempObject->getUserId(), tempObject));
		}//try
		catch (const char* e) {
	        cout << endl;
	        userErrorsFile  << e << endl;
	        delete tempObject;
	        continue;
	    }//catch

		}//try
		catch (const char* e){
			cout << endl;
			userErrorsFile  << e << endl;
			delete tempObject;
			continue;
				}//catch
		catch (invalid_argument &e){
			cout << endl;
			userErrorsFile  << "Error: User " << "\"" << tempObject->getUserId() << "\"" <<" has inputed an invalid Numeric Value. Numeric that was inputed was " << "\"" << tempString << "\"" << endl;
			delete tempObject;
			continue;
						}//catch
	}//while
	inputFile.close();
    userErrorsFile.close();



	//SMUserPosts
	inputFile.open("SMUserPosts.csv");
	if (inputFile.fail()) {
		cout << endl;
		cout << "Error: Can not access the input file. Please try again." << endl;
		return 0;
	}//if statement to check if file has opened correctly or not

	while (!inputFile.eof()) {
		SMUserPosts* tempObject = nullptr;

		getline(inputFile, inputRecord);
		try{
			if(inputRecord.size() == 0){
				continue;
			}
		stringstream strStream(inputRecord);
		tempObject = new SMUserPosts;
		getline(strStream, tempString, ',');
		if (smusersMap.count(tempString) == 0){
			postErrorsFile << "User " << "\"" << tempObject->getUserIdPost() << "\"" << " does not exist in SMUsers.csv." << endl;
			delete tempObject;
			continue;
		}//if
		else {
			tempObject->setUserIdPost(tempString);
		}//else

		Date tempDate;
		getline(strStream, tempString, ',');
		if (!tempDate.setYear(stoi(tempString))){
			postErrorsFile  << "Error: Year is invalid for user " << "\"" <<  tempObject->getUserIdPost() << "\"" << " year that was inputed was" << "\"" << tempString << "\"" << endl;
			delete tempObject;
			continue;
		}


		getline(strStream, tempString, ',');
		if (!tempDate.setMonth(stoi(tempString))){
			postErrorsFile  << "Error: Month is invalid for user " << "\"" <<  tempObject->getUserIdPost() << "\"" << " month that was inputed was" << "\"" << tempString << "\"" << endl;
			delete tempObject;
			continue;
		}

		getline(strStream, tempString, ',');
		if (!tempDate.setDay(stoi(tempString))){
			postErrorsFile  << "Error: Day is invalid for user " << "\"" <<  tempObject->getUserIdPost() << "\"" << " day that was inputed was" << "\"" << tempString << "\"" << endl;
			delete tempObject;
			continue;
		}

		tempObject->setDateOfPost(tempDate);

		getline(strStream, tempString, ',');
		tempObject->setHour(stoi(tempString));

		getline(strStream, tempString, ',');
		tempObject->setMinute(stoi(tempString));

		getline(strStream, tempString, ',');
		tempObject->setSecond(stoi(tempString));

		getline(strStream, tempString, ',');
		tempObject->setPostsText(tempString);



		smusersMultiMap.insert(make_pair(tempObject->getUserIdPost(),tempObject));
		}//try
		catch (char const *e){
			postErrorsFile  << e << endl;
			delete tempObject;
			continue;

		}//catch
		catch (invalid_argument &e){
			postErrorsFile << "Error: User " << "\"" << tempObject->getUserIdPost() << "\"" <<" has inputed an invalid Numeric Value. Numeric that was inputed was " << "\""  << tempString << "\"" << endl;

			delete tempObject;
			continue;
		}//catch
		}//while
	inputFile.close();
	postErrorsFile.close();

while (menuOptions != 5){
	cout << "Select option from the menu: " << endl;
	cout << "----------------------------" << endl;
	cout << endl;
	cout << "1. Display all Users." << endl;
	cout << "2. Display a Specific User." << endl;
	cout << "3. Display all posts." << endl;
	cout << "4. Display posts from a Specific User." << endl;
	cout << "5. Exit the program." << endl;
	cout << endl;
cin >> menuOptions;
clearCin();


switch (menuOptions){
	case 1:

	cout << endl;
	cout << left << setw(17) << "User Id:" //moves Last Name Setw
		<< setw(18) << "Last Name:"			//moves First Name Setw
		 << setw(19) << "First Name:"		//moves Date Setw
		 << setw(24) << "Date (Y/M/D):"		//Total Posts Setw
		 << "Total Posts:"
	<<endl;

	cout << left << setw(17) << "--------" //moves Last Name Setw
		<< setw(18) << "----------"			//moves First Name Setw
		 << setw(19) << "-----------"		//moves Date Setw
		 << setw(24) << "-------------"		//Total Posts Setw
		 << "------------"
	<<endl;

		for (auto x: smusersMap) {
			cout << left << setw(10) << x.first << "\t"								//moves Last Name Setw
					<< left << setw(18) << x.second->getFirstName()					//moves First Name Setw
					<< left << setw(20) << x.second->getLastName()					//moves Date Setw
					<< left << setw(35) << x.second->getMembershipDate().getDate()	//Total Posts Setw
					 << smusersMultiMap.count(x.first)
				<<endl;
		}//for

		cout << endl;

			break;
		case 2:
			try{

			userInput = new SMUsers;
			cout << endl;
			cout << "Please enter the user ID you are looking for: " << endl;
			cout<< "-----------------------------------------------" << endl;
			cin >> userName;
			clearCin();
			cout << endl;

			userInput->setUserId(userName);
			cout << "User Id: " << smusersMap.at(userName)->getUserId() << endl;
			cout << "Last Name: " << smusersMap.at(userName)->getFirstName() << endl;
			cout << "First Name: " << smusersMap.at(userName)->getLastName() << endl;
			cout << "Total Posts: " << smusersMultiMap.count(userName) << endl;
			cout << endl;
			}
			catch (const out_of_range& e){
				cout << "Error: User with ID " << userName << " does not exist." << endl;			}
			break;
		case 3:

			cout << endl;
				cout << left << setw(16) << "User Id:" 			//moves Date
					<< setw(23) << "Date(Y/M/D):"				//moves Time
					 << setw(29) << "Time of Post (H:M:S):"		//moves Text
					 << setw(24) << "Post:"
				<<endl;

				cout << left << setw(16) << "--------" 			//moves Date
					<< setw(23) << "------------"				//moves Time
					 << setw(29) << "--------------------"		//moves Text
					 << setw(24) << "-----"
				<<endl;

			for (auto x: smusersMultiMap) {
				cout << left << setw(16)  << x.first						//moves Date
					<< setw(23) << x.second->getDateOfPost().getDate()		//moves Time
					<< setw(28) << x.second->getPostTime()					//moves Text
					<< x.second->getPostsText()
					<<endl;
			}//for
			cout << endl;

			break;
		case 4:
			cout << endl;
			cout << "Please enter the user ID you are looking for: " << endl;
			cout << "---------------------------------------------" << endl;
			cin >> userName;
			clearCin();
			try {

				if (smusersMultiMap.count(userName) == 0){
					cout << endl;
					cout << "User has not posted anything." << endl;
				}
				else {
					cout << endl;
					cout << "User Id: " << smusersMap.at(userName)->getUserId() << endl;
					cout<< "Last Name: " << smusersMap.at(userName)->getLastName() << endl;
					cout<< "First Name: " << smusersMap.at(userName)->getFirstName() << endl;
					cout << "Total Posts: " << smusersMultiMap.count(userName) << endl;
					cout << endl;

					cout << left << setw(5) << "Time of Post (H:M:S):"
						<< setw(15) << right << "Post:" << endl;

					cout << left << setw(5) << "---------------------"
						<< setw(15) << right << "-----" << endl;
					auto range = smusersMultiMap.equal_range(userName);
					for (smusersMultiMapIt = range.first; smusersMultiMapIt != range.second; smusersMultiMapIt++){
						cout << left << setw(30) << (*smusersMultiMapIt).second->getPostTime()
							 << setw(20) << right << (*smusersMultiMapIt).second->getPostsText() << endl;
					}//for


				}//else





			}//try
			catch (const out_of_range& e){
				cout << "Error: User name does not exist." << endl;
			}//catch
			cout << endl;
			break;
		case 5: {
		    ifstream userErrorsFileDisplay("UserErrors.txt");
		    if (userErrorsFileDisplay) {
		    	cout << endl;
		        cout << "Data from UserErrors.txt:" << endl;
		        cout << "-------------------------" << endl;
		        cout << endl;
		        string line;
		        while (getline(userErrorsFileDisplay, line)) {
		            cout << line << endl;
		        }
		        userErrorsFileDisplay.close();
		    } else {
		        cout << "UserErrors.txt not found." << endl;
		    }

		    ifstream postErrorsFileDisplay("PostErrors.txt");
		    if (postErrorsFileDisplay) {
		    	cout << endl;
		        cout << "Data from PostErrors.txt:" << endl;
		        cout << "--------------------------" << endl;
		        cout << endl;
		        string line;
		        while (getline(postErrorsFileDisplay, line)) {
		            cout << line << endl;
		        }
		        postErrorsFileDisplay.close();
		    } else {
		        cout << "PostErrors.txt not found." << endl;

		    }
		}
		cout << endl;

		for (smusersMapIt = smusersMap.begin(); smusersMapIt!= smusersMap.end(); smusersMapIt++){
			delete smusersMapIt->second;
			smusersMapIt->second = nullptr;
		}

		for (smusersMultiMapIt = smusersMultiMap.begin(); smusersMultiMapIt!= smusersMultiMap.end(); smusersMultiMapIt++){
			delete smusersMultiMapIt->second;
			smusersMultiMapIt->second = nullptr;
		}

		smusersMap.clear();
		smusersMultiMap.clear();

		break;
		default:
			cout << "Error: Please select a valid option from the menu." << endl;
		}//switch
}//while1



	cout << "End of Program" << endl; // prints End of Program
	return 0;
}//MAIN
