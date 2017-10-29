#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>


using namespace std;


const char userMark = 'X';
const char computerMark = 'O';

enum gameStatus { gameOnGoing, userWins, computerWins, gameDrawOver, gameFinished };

class Tictactoe {

private:
	DWORD delay_ms = 1000;
	char board[9] = { '1','2','3','4','5','6','7','8','9' };

	

public:
	bool active = true;
	Tictactoe();
	void displayBoard(void);
	bool updateBoard(int choice, char playerMark);
	int generateComputerChoice(void);
	gameStatus checkGame(void);
	bool checkforWinningLines(char playerMark);
	int countAvailableSpaces(void);
	void delay(void);

	//Additional
	bool Tictactoe::gameDraw(void);
	int Tictactoe::advancedGenerateComputerChoice(void);
	int computerChoice;
	bool gameMode(void);
	

	bool gameMChoice;
	bool terminateGame(char choice);
	int userChoice = 0;
	bool terminate;

};

