


This project is designed to simulate a simple social media platform through a C++ application, focusing on user and post-management. It involves creating, managing, and displaying social media users and their posts, with data stored in Standard Template Library (STL) Maps and MultiMaps and sourced from CSV files. The project is segmented into several key requirements, each building towards a comprehensive system. The project effectively simulates a basic framework for a social media platform, using C++ classes, STL containers, file I/O, and dynamic memory management. It showcases my ability to integrate various C++ features and principles, including object-oriented programming, data validation, and user interaction through a console-based menu system.

# Files Needed to Run Project:

[SMUsers.csv](https://github.com/Hassibi501/CS2---Final-Project---CMD-Social-Media-Program/files/14813117/SMUsers.csv)[SMUserPosts.csv](https://github.com/Hassibi501/CS2---Final-Project---CMD-Social-Media-Program/files/14813114/SMUserPosts.csv)

[SMUserPosts.csv](https://github.com/Hassibi501/CS2---Final-Project---CMD-Social-Media-Program/files/14813112/SMUserPosts.csv)# Project Description:


# Project Feature Showcase:

### Menu Option #1:Users

Displays all users and information about them from `SMUsers.csv`.

<img src="https://i.imgur.com/0fX4xYz.jpeg" alt="436bbaf5e82540c762d4c53269777172.png" width="600" height="413" class="jop-noMdConv">

### Menu Option #2: Displaying Specific User

Displays the information of only one specific user by entering their user ID.

<img src="https://i.imgur.com/PffrakV.jpeg" alt="eclipse_1AVjLSik1p.jpg" width="600" height="216" class="jop-noMdConv">

### Menu Option #3: User Posts

Displays the posts of all users from `SMUserPosts.csv`.

<img src="https://i.imgur.com/JTLDM9P.jpeg" alt="A8DWVt2Nvn.jpg" width="887" height="184" class="jop-noMdConv">

### Menu Option #4: Specific User Post

Displays all the posts from only one specific user by entering their user ID. It also displays the user's information.

<img src="https://i.imgur.com/It1In7F.jpeg" alt="fNlTGUz7H6.jpg" width="528" height="189" class="jop-noMdConv">

### Error Handling and Validation Feature:

My project only displays data from users located in `SMUsers.csv`:

![https://i.imgur.com/qFBBBRQ.jpeg](https://i.imgur.com/qFBBBRQ.jpeg)

If a user in `SMUserPosts.csv` does not exist like the users highlighted in red then my code will generate a text file reporting that these users do not exist. My program will also not display user info from users that do not exist in `SMUsers.csv`.

<img src="https://i.imgur.com/Nq6cFoL.jpeg" alt="s6puPIzSge.jpg" width="519" height="183" class="jop-noMdConv">

This is the text file that reports if a user does not exist.

![https://i.imgur.com/kLLtVFu.jpeg](https://i.imgur.com/kLLtVFu.jpeg)

&nbsp;

# Project Components:

1.  **SMUser and SMUserPost Classes**: I created two primary classes where `SMUser` handles user information (User ID, First Name, Last Name, Date of Membership) and `SMUserPost` manages post details (User ID, Date of Post, Time of Post, Post Text). Each class includes private attributes with public accessors and mutators, ensuring data integrity through validation checks.
    
2.  **File Handling**: My code reads user and post data from `SMUsers.csv` and `SMUserPosts.csv` files, respectively. It populates a Map for user data and a MultiMap for post data, implementing error handling to manage duplicates and invalid entries, directing these issues to separate error log files.
    
3.  **User Interaction**: Through a simple console menu, users can display all registered users, a specific user, all posts, or posts from a specific user.
    
4.  **Data Display and Management**: Utilizing `iomanip` for formatting, my code presents user details and their posts in a structured and readable format. It also includes functionality to clear dynamic memory allocations upon exit, ensuring no memory leaks.
    
5.  **Error Handling and Validation**:  Invalid or problematic entries are logged, and the system provides feedback on missing files or data inconsistencies.
    
