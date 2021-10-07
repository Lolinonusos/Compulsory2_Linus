#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>

struct User { // For creating new users
std::string userName; // 
std::string passWord; // 
};

struct Card {
	int value{};
};

void logIn(); // task 1
void createUser(std::vector<User>&);

void jackBlack(); // Main jack black function

void logIn() {

	char yn{};
	std::vector<User> users{};

	std::cout << "----- Welcome to JackBlack -----\n" << std::endl;
	std::cout << "Before you can play you must log in or create a new user" << std::endl;
	std::cout << "Are you a (1)new user or do you want to (2)log in"; 
	yn = _getch();
	//yn = tolower(yn); // Currently not neccesary

	// Do try to make an arrow menu
	
	if (yn == '1') { // Making an account
		createUser(users);
	}
	else if (yn == '2') { // Logging in



	}
}

void createUser(std::vector<User>& users) {
	User temp_user{};
std::cout << "Enter a user name:\n";
getline(std::cin, temp_user.userName);
std::cout << std::endl << std::endl << "Your user name is now " << temp_user.userName << std::endl;
std::cout << "Enter a password you will remember:\n";
getline(std::cin, temp_user.passWord);
std::cout << "Your password is " << temp_user.passWord << std::endl;
Sleep(500);
std::cout << "For security reasons we require you to use your newly made log in credentials to log in to our site";
Sleep(1000);
}

void printCards(); // For debugging, checking if all cards exist

int main() {
	logIn();

	return 0;
	std::vector<Card> cards; // A vector for keeping all the different cards
}

void printCards() {

}

void jackBlack() {

}