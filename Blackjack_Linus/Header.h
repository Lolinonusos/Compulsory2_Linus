#pragma once

#include <iostream>
#include <conio.h> // For _getch
#include <Windows.h>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm> // std::shuffle
#include <random>
#include <chrono>
//#include <array>

// All your user names and passwords
struct User {
	std::string userName; // 
	std::string passWord; // 
};

// A nice struct for all the cards
struct Card {
	int cardValue{};		// Point value of a card
	std::string court{};	// Which court or number a card has
	std::string cardSuit{}; // Which of the four suits the card is part of
};

// Values important to the Player and House
struct Player {
	std::vector <Card> hand{}; // This will be the cards the player and house draws to their hands
	unsigned int capital{ 100 }; // Money
	unsigned int points{}; // Summary of card point values
} player, house;

// Task 1 
void logIn(); // Input password and stuff
void createUser(std::vector<User>&); // Create username and password, also & is very cool and awesome, makes function go brrrrr
int logInLoop{};
int correctPassWord = 0;

// Task 2 relevant 
void makeCards(std::vector<Card>&); // Make the cards, find out how to randomize and draw later
void introToJackBlack(); // A little menu
void jackBlack(std::vector<Card>&); // Main jack black function
void restock(std::vector<Card>&); // Randomize cards
void rules(); // Just text

// Misc. global stuff
void clearCin();