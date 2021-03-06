#include "Header.h"

int main() {
	logIn(); // Make user and login to play JackBlack

	std::vector<Card> cards{}; // A vector for keeping all the different cards
	makeCards(cards); // All the cards are created and pushed into the cards vector
	introToJackBlack(); 
	jackBlack(cards); // Gaming
	return 0; // Only gets here when you decide you are done with JackBlack
}

// Here you log with a username and password
void logIn() {
	std::vector<User> users{}; // A vector named users that will be filled with users?

	while (correctPassWord == 0) {
		system("cls");

		char yn{};

		std::string insertUserName{}; // For logging in
		std::string insertPassWord{}; // For logging in

		std::cout << "There are " << users.size() << " users currently playing JackBlack on our site." << std::endl << std::endl; // Testing purpose
	
		std::cout << "----- Welcome to JackBlack -----\n" << std::endl;
		std::cout << "Before you can play you must log in or create a new user" << std::endl;
		std::cout << "Are you a (1)new user or do you want to (2)log in\n" << std::endl; 
		yn = _getch();
				
		if (yn == '1') { // Making an account
			createUser(users);
		}
		if (yn == '2') { // Logging in
			if (users.size() == 0) {
				std::cout << "Please make an account first :)";
				Sleep(1000);
			}
			else {
				std::cout << "Insert your username:" << std::endl;
				std::getline(std::cin, insertUserName); // This is where user name is inserted
				std::cout << std::endl;

				for (int logInLoop = 0; logInLoop < users.size(); logInLoop++) { // This loop is going to check the vector for user names and then ask for the password to that user
					if (insertUserName == users[logInLoop].userName) {
					
						for (int i = 0; i < 3; i++) { // For loop that will terminate program after three failed attempts
							if (i == 3) {
								std::cout << "The password has bees entered wrong too many times\n" << "We will now terminate the login attempt" << std::endl;
								exit(0);
							}
							std::cout << "Enter the password for that account ;" << std::endl;
							std::getline(std::cin, insertPassWord);
							if (insertPassWord == users[logInLoop].passWord) {
								std::cout << "Login successful! Welcome" << users[logInLoop].userName << "\n" << "We will bring you to JackBlack in just a moment" << std::endl;
								correctPassWord = 1;
								Sleep(2000);
								break; // Should this be included? Need more testing
							}
							std::cout << std::endl;
							clearCin();
						}
					}
				}
			}
		}
	}
}

// Here you crate a username and password
void createUser(std::vector<User>& users) {
	User temp_user{};
	
	std::cout << "Enter a user name:\n";	
	std::cin >> temp_user.userName;
	std::cout << std::endl << std::endl << "Your user name is " << temp_user.userName << std::endl;
	std::cout << "Enter a password you will remember:\n";
	std::cin >> temp_user.passWord;
	std::cout << "Your password is " << temp_user.passWord << std::endl;
	users.push_back(temp_user); // Inserts all of temp_users values into the users vector
	clearCin();
	Sleep(500);
	std::cout << "For security reasons we require you to use your newly made log in credentials to log in to our site\n" << std::endl;
	Sleep(1000);
}

// Create a vector full of Card
void makeCards(std::vector<Card>& cards) {
	Card temp_card{};

	for (int j = 1; j <= 4; j++) { // For the suit
		for (int i = 1; i <= 13; i++) { // For the court/number

			// This part decides which court or number the card has and also what point value it will have in JackBlack
			if (i == 1) {
				temp_card.cardValue = 1;
				temp_card.court = "Ace";
			}
			if (i == 11) {
				temp_card.cardValue = 10;
				temp_card.court = "Jack";
			}
			if (i == 12) {
				temp_card.cardValue = 10;
				temp_card.court = "Queen";
			}
			if (i == 13) {
				temp_card.cardValue = 10;
				temp_card.court = "King";
			}
			if (i >= 2 && i <= 10) { // Number cards
				temp_card.cardValue = i;
				temp_card.court = std::to_string(i); // to_string converts the numerical value of the int to a character value whithout changing the character displayed
			}

			// This part decides which suit the card has	
			if (j == 1) {
				temp_card.cardSuit = " of Spades";
			}
			if (j == 2) {
				temp_card.cardSuit = " of Hearts";
			}
			if (j == 3) {
				temp_card.cardSuit = " of Diamonds";
			}
			if (j == 4) {
				temp_card.cardSuit = " of Clubs";
			}

			// Seeing if every card are created correctly 
			//std::cout << "Card: " << temp_card.court << temp_card.cardSuit << "\tCard score value : " << temp_card.cardValue << "\t"; // What card we just made
			cards.push_back(temp_card);
			//std::cout << "This is card #" << cards.size() << std::endl; // Check how many cards have been made so far
		}
	}
}

// A little menu to decide if you want to see the rules before playing
void introToJackBlack() { 
	char oneTwo{};

	system("cls");
	
	std::cout << "Hello, welcome to JackBlack.\n" << "I am the dealer and take the role of the house.\n" << std::endl;
	std::cout << "Do you know the rules of JackBlack? " << std::endl;
	std::cout << "1. Yes\t" << "2. No\n";
	oneTwo = _getch();
	switch (oneTwo) {
	case '1':
		std::cout << "Excellent, let us play then.";
		Sleep(500);
		break;
	case '2':
		rules();
		break;
	default:
		rules();
		break;
	}
}

// Gaming
void jackBlack(std::vector<Card>& cards) {
	unsigned int bet{}; // Amount of money the player and house bets
	unsigned int pot{}; // Amount of money the player and house receives when winning a round
	char drawCard{ 'y' }; // yes no input
	int playerWon{};
	int houseWon{};
	int turnCount{}; 
	char playAnotherGame{ 'y' };

	while (playAnotherGame == 'y') {

		while (player.capital != 0 && house.capital != 0) {
			restock(cards); // Restock the order of cards

			while (bet < 10  || bet > house.capital || bet > player.capital) { // Loops here until bet amount is acceptable

				system("cls");
				//std::cout << "You can always press H to view the rules again\n" << std::endl;
				std::cout << "You have " << player.capital << "$ " << "\t The House has " << house.capital << "$\n" << std::endl; // HUD to show capital of players and what will be won
				std::cout << "Pot: " << pot << "$\n" << std::endl;
					
				std::cout << "Insert amount you would like to bet: ";
				std::cin >> bet;
				clearCin();

				if (bet < 10) {
					std::cout << "You need to bet at least 10$." << std::endl;
					Sleep(1000);
				}
				if (bet > house.capital) {
					std::cout << "I cannot match that bet.";
					Sleep(1000);
				}
				if (bet > player.capital) {
					std::cout << "You don't have enough money for that.";
					Sleep(1000);
				}		
			}

			player.capital = player.capital - bet;
			house.capital = house.capital - bet;

			system("cls");
			//std::cout << "You can always press H to view the rules again\n" << std::endl;
			std::cout << "I've had some trouble with clearCin as you'll have to press enter some extra times??";
			std::cout << "You have " << player.capital << "$ " << "\t The House has " << house.capital << "$\n" << std::endl;
			pot = bet * 2;
			std::cout << "Pot: " << pot << "$\n" << std::endl;
	
			std::cout << "You bet " << bet << "$" << std::endl;
			std::cout << "Winner of this round receives " << pot << "$\n" << std::endl;

			// The player's turn to draw cards
			for (turnCount; turnCount < cards.size(); turnCount++) { 
				drawCard = 'y';
				if (drawCard == 'y') {
					cards[turnCount];
					std::cout << "You drew a " << cards[turnCount].court << cards[turnCount].cardSuit << std::endl;
					
					// Choose what the Aces point value is going to be
					if (cards[turnCount].court == "Ace") {
						std::cout << "Do you want it to be worth 1 point or 11 points?\n" << "Press button 1 for 1 point or button 2 for 11 points\n";
						char aceSelect{};
						while (aceSelect != '1' || aceSelect == '2') {

							aceSelect = _getch();
						
							switch (aceSelect) {
							case '1':
								cards[turnCount].cardValue = 1;
								break;
							case '2':
								cards[turnCount].cardValue = 11;
								break;
							default:
								std::cout << "Use '1' or '2' key.";
								break;
								clearCin();
							}
						}
						std::cout << "It is worth " << cards[turnCount].cardValue << " points\n" << std::endl;
					}
					else {
						std::cout << "It is worth " << cards[turnCount].cardValue << " points\n" << std::endl;
					}
				}
				player.points = player.points + cards[turnCount].cardValue;

				// The player lost the round
				if (player.points > 21) {
					std::cout << "You got " << player.points << " and have lost this round.\n" << std::endl;
					Sleep(2000);
					houseWon = 1;
					break;
				}
				
				std::cout << "You currently have " << player.points << " points" << std::endl << std::endl;
				std::cout << "Do you want to draw another card? y/n \n" << std::endl;
				
				drawCard = _getch();
				drawCard = tolower(drawCard);
								
				// End the players turn
				if (drawCard == 'n') {
					break;
				}
			}
			
			// The house's turn to draw cards, only run this if the player hasn't lost
			// Since the house draws cards after the player I must make sure that the house continues to draw the cards that come next
			if (player.points <= 21) {

				system("cls");
				//std::cout << "You can always press H to view the rules again\n" << std::endl;
				std::cout << "You have " << player.capital << "$ " << "\t The House has " << house.capital << "$\n" << std::endl; // HUD to show capital of players
				std::cout << "Pot: " << pot << "$\n" << std::endl;
				
				// The house continues to draw until it gets the amount or more points than the player
				while (house.points <= player.points ) {
					turnCount++;
					cards[turnCount];
					std::cout << "I drew a " << cards[turnCount].court << cards[turnCount].cardSuit << std::endl;
				
					// When the house gets an ace
					if (cards[turnCount].court == "Ace") {
						if (house.points > 10) {
							cards[turnCount].cardValue = 1;
						}
						else {
							cards[turnCount].cardValue = 11;
						}
					}

					std::cout << "It is worth " << cards[turnCount].cardValue << " points\n" << std::endl;
				
					house.points = house.points + cards[turnCount].cardValue;
					std::cout << "I now have " << house.points << " points." << std::endl << std::endl;


					// House loses
					if (house.points > 21) {
						std::cout << "Ah I got " << house.points << " points, you've won this round\n" << std::endl;
						Sleep(2000);
						playerWon = 1;
						break;
					}
					// Tie
					else if (house.points == player.points) {
						std::cout << "We both got " << house.points << " so this round is a tie\n" << std::endl;
						Sleep(2000);
						break;
					}
					// House won
					else if (house.points > player.points) {
						std::cout << "I've got " << house.points << " points and won this round.\n" << std::endl;
						Sleep(2000);
						houseWon = 1;
						break;
					}
					
					Sleep(1500);
				}
			}
			


			// Giving money to the winner
			if (playerWon == 1) {
				player.capital = player.capital + pot;
			}
			if (houseWon == 1) {
				house.capital = house.capital + pot;
			}
			// Return amount of money that was bet when you have a tie
			else if (playerWon == 0 && houseWon == 0) {
				player.capital = player.capital + bet;
				house.capital = house.capital + bet;
			}

			std::cout << "You have " << player.capital << "$ " << "\t The House has " << house.capital << "$\n" << std::endl; // HUD to show capital of players
			std::cout << "Pot: " << pot << "$\n" << std::endl;

			// Resetting values for next round
			drawCard = 'y';
			turnCount = 0; 

			bet = 0;
			pot = 0;

			player.points = 0;
			house.points = 0;
			
			playerWon = 0;
			houseWon = 0;
		}

		// One of you lost all of their money
		if (player.capital == 0) {
			std::cout << "Ah, out of cash? Don't worry, we have an ATM right over there.\n" << std::endl;
			player.capital = 100;
		}
		if (house.capital == 0) {
			std::cout << "Oh, you won all of my cash, just give me moment.\n" << std::endl;
			house.capital = 100;
		}
		
		Sleep(1000);
		std::cout << "Do you want to play another round? y/n\n" << std::endl;
		std::cin >> playAnotherGame;
	}
}

// Restock the order of cards
void restock(std::vector<Card>& cards) {

	// Gives a seed based on the system clock
	unsigned seed = (std::chrono::system_clock::now().time_since_epoch().count());

	// Shuffles the cards vector
	std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));

	// To visualize the shuffle
	//for (int i = 0; i < cards.size(); i++) {
	//	std::cout << "Card: " << cards[i].court << cards[i].cardSuit << "\tCard score value : " << cards[i].cardValue << std::endl; 
	//}
}

// Rules of the game
void rules() { 
	system("cls");
	char gotIt{};
	
	std::cout << "These are the rules of JackBlack:\n" << std::endl;
	std::cout << "Or course, there are a total of 52 cards. Each card has a point value betwwen 1-11:" << std::endl;
	std::cout << "The card 2-10 has the same point value as their numbers." << std::endl;
	std::cout << "Jacks, Queens, and Kings all have a point value of 10." << std::endl;
	std::cout << "Aces are special as you can decide which point value of either 1 or 11 you want." << std::endl;
	std::cout << "You may draw as many cards as you like, until you reach 21 points. If you go above 21 points you lose the round." << std::endl;
	std::cout << "When you are finished drawing cards I will draw cards until I match or get more points than you." << std::endl;
	std::cout << "If I match your point value it is a draw, and we play again without any losses." << std::endl;
	std::cout << "The minimum fee you must bet to play a round is 10$. I will always match your bet, so you cannot bet more money than I have." << std::endl;
	std::cout << "We play until one of us loses all of our capital, or you decide to close the program.\n" << std::endl;
	Sleep(5000);
	std::cout << "Press any button to continue.";
	gotIt = _getch();
	system("cls");
}

// Clear buffer from cin
void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}