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
	int cardValue{}; // Number value of card
	int cardColour{}; // We'll see whats better, colours or just 4 of each card
};

void logIn(); // task 1
void createUser(std::vector<User>&);
int logInLoop{};
int correctPassWord = 0;

void makeCards(std::vector<Card>&); // Make the cards, find out how to randomize and draw later
void introToJackBlack();
void jackBlack(); // Main jack black function
void rules();
struct Player {
	std::vector <Card> hand{}; // This will be the cards the player and house draws to their hands
	int capital{ 100 };
} player, house;

void clearCin();

void logIn() {
	std::vector<User> users{}; // A vector named users that will be filled with users?

	while (correctPassWord == 0) {

		char yn{};

		std::string insertUserName{}; // For logging in
		std::string insertPassWord{}; // For logging in

		std::cout << users.size() << std::endl << std::endl; // Testing purpose
	
		std::cout << "----- Welcome to JackBlack -----\n" << std::endl;
		std::cout << "Before you can play you must log in or create a new user" << std::endl;
		std::cout << "Are you a (1)new user or do you want to (2)log in" << std::endl; 
		yn = _getch();
	
		// Do try to make an arrow menu later
		
		if (yn == '1') { // Making an account
			createUser(users);
		}
		else if (yn == '2') { // Logging in
		/*	if (users.size() == 0) {
				std::cout << "It seems like we don't have any registered accounts at all... Please be our first :)";
			}*/
			//else {
			clearCin();
			std::getline(std::cin, insertUserName);
	
			// Make this for loop global?
			for (int logInLoop = 0; logInLoop < users.size(); logInLoop++) { // This loop is going to check the vector for user names and then ask for the password to that user
				if (insertUserName == users[logInLoop].userName) {
					
					for (int i = 0; i < 3; i++) { // For loop that will terminate if password is entered wrong too many times
						if (i == 3) {
							std::cout << "The password has bees entered wrong too many times\n" << "We will now terminate the login attempt" << std::endl;
							exit(0);
						}
						std::cout << "Enter the password for that account; << std::endl";
						std::getline(std::cin, insertPassWord);
						if (insertPassWord == users[logInLoop].passWord) {
							std::cout << "Login successful! Welcome" << users[logInLoop].userName << "\n" << "We will bring you to JackBlack in just a moment" << std::endl;
							correctPassWord = 1;
						}
					}
				}
			}	
		}
	}
}

void createUser(std::vector<User>& users) {
	User temp_user{};
	
	std::cout << "Enter a user name:\n";
	
	std::cin >> temp_user.userName;
	std::cout << std::endl << std::endl << "Your user name is now " << temp_user.userName << std::endl;
	std::cout << "Enter a password you will remember:\n";
	std::cin >> temp_user.passWord;
	std::cout << "Your password is " << temp_user.passWord << std::endl;
	users.push_back(temp_user); // Inserts all of temp_users values into the users vector
	Sleep(500);
	std::cout << "For security reasons we require you to use your newly made log in credentials to log in to our site\n" << std::endl;
	Sleep(1000);
}

void printCards(); // For debugging, checking if all cards exist

int main() {
	//logIn();

	std::vector<Card> cards; // A vector for keeping all the different cards
	introToJackBlack();
	jackBlack();
	return 0;
}

void printCards() {

}

void introToJackBlack() {
	char oneTwo{};

	system("cls");
	
	std::cout << "Hello, welcome to JackBlack.\n" << "I am the dealer and take the role of the house.\n" << std::endl;
	std::cout << "Do you know the rules of JackBlack? " << std::endl;
	std::cout << "1. Yes\t" << "2. No\n";
	std::cin >> oneTwo;
	switch (oneTwo) {
	case '1':
		std::cout << "Excellent, let us play then.";
		break;
	case '2':
		rules();
		break;
	}
}


void jackBlack() {
	int bet{};

	while (true)
	{
		bet = 0; // Resets the bet to 0
		clearCin();
		while (bet < 10  || bet > house.capital || bet > player.capital) { // Loops here until bet amount is reasonable

			system("cls");
			std::cout << "You can always press H to view the rules again\n" << std::endl;
			std::cout << "You have " << player.capital << "$ " << "\t The House has " << house.capital << "$\n" << std::endl; // HUD to show capital of players
			std::cout << "Insert amount you would like to bet: ";
			std::cin >> bet;
			if (bet < 10) {
				std::cout << "You need to bet at least 10$." << std::endl;
				Sleep(500);
			}
			if (bet > house.capital) {
				std::cout << "I cannot match you bet.";
				Sleep(500);
			}
			if (bet > player.capital) {
				std::cout << "You don't have enough money for that.";
				Sleep(500);
			}
		}
		std::cout << "You bet " << bet << "$";
	
	}
}

void rules() {
	system("cls");
	char gotIt{};
	
	std::cout << "These are the rules of JackBlack:\n" << std::endl;
	std::cout << "Or course, there are a total of 52 ards. Each card has a point value betwwen 1-11:" << std::endl;
	std::cout << "The card 2-10 has the same point value as their numbers." << std::endl;
	std::cout << "Jacks, Queens, and Kings all have a point value of 10." << std::endl;
	std::cout << "Aces are special as you can decide which point value of either 1 or 11 you want." << std::endl;
	std::cout << "You may draw as many cards as you like, until you reach 21 points. If you go above 21 points you lose the round." << std::endl;
	std::cout << "When you are finished drawing cards I will draw cards until I match or get more points than you." << std::endl;
	std::cout << "If I match your point value it is a draw, and we play again without any losses." << std::endl;
	std::cout << "The minimum fee you must bet to play a round is 10$. I will always match your bet, so you cannot bet more money than I have." << std::endl;
	std::cout << "We play until one of us loses all of our capital, or you decide to close the program.\n" << std::endl;
	
	std::cout << "When you got it, you just press a button to continue.";
	gotIt = _getch();
	system("cls");
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}