#include "TicTacToe.h"


Tictactoe::Tictactoe(void) {
	static bool firstTime = false;
	if (firstTime == false) {
		srand((unsigned)time(0));
		firstTime = true;
	}
}


void Tictactoe::displayBoard(void) {

	system("cls");
	cout << "Players: User-X : Computer-O" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << board[0] << "   " << board[1] << "    " << board[2] << "  " << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << board[3] << "   " << board[4] << "    " << board[5] << "  " << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << board[6] << "   " << board[7] << "    " << board[8] << "  " << endl;
	cout << "    |    |    " << endl;
}


bool Tictactoe::updateBoard(int choice, char playerMark) {
	bool boardUpdated = false;
	
	
	 if ((choice > 0 && choice < 10) &&
		(board[choice - 1] != userMark) &&
		(board[choice - 1] != computerMark))
	{
		board[choice - 1] = playerMark;
		boardUpdated = true;
	}
	 
	return boardUpdated;
}

//function which generates a randoim computer choice 
int Tictactoe::generateComputerChoice(void) {

	unsigned int choice;
	do {
		choice = rand() % 8 + 1;
	} while ((board[choice - 1] == userMark || board[choice - 1] == computerMark) &&
		countAvailableSpaces()>0);
	return choice;
}


gameStatus Tictactoe::checkGame(void) {
	gameStatus gameStatus = gameOnGoing;

	if (checkforWinningLines(userMark)) {
		gameStatus = userWins;
		active = false;
	}
	else if (checkforWinningLines(computerMark)) {
		gameStatus = computerWins;
		active = false;
	}
	else if (gameDraw() == true || 0 == countAvailableSpaces()) {
	 gameStatus = gameDrawOver;
	 active = false;
	}
	else if (0 == countAvailableSpaces()) {
		gameStatus = gameFinished;
		active = false;
	}
	return gameStatus;
}

// function to check if there is a winner
bool Tictactoe::checkforWinningLines(char playerMark) {
	bool foundWinningLine = false;

		// Check horizontal lines
	if ((board[0] == playerMark && board[1] == playerMark && board[2] == playerMark) ||
		(board[3] == playerMark && board[4] == playerMark && board[5] == playerMark) ||
		(board[6] == playerMark && board[7] == playerMark && board[8] == playerMark) ||
		// Check vertical lines
		(board[0] == playerMark && board[3] == playerMark && board[6] == playerMark) ||
		(board[1] == playerMark && board[4] == playerMark && board[7] == playerMark) ||
		(board[2] == playerMark && board[5] == playerMark && board[8] == playerMark) ||
		// Check diagonal lines
		(board[0] == playerMark && board[4] == playerMark && board[8] == playerMark) ||
		(board[2] == playerMark && board[4] == playerMark && board[6] == playerMark)) {
		foundWinningLine = true;
	}
	return foundWinningLine;
}


int Tictactoe::countAvailableSpaces(void) {
	int spacesRemaining = 0;

	for (int i = 0; i < 9; i++) {
		if (board[i] != userMark && board[i] != computerMark) {
			spacesRemaining++;
		}
	}
	return spacesRemaining;
}


//function for the game drawn logic
bool Tictactoe::gameDraw(void) {
	bool gameDraw = false;


	//mulitple boolean variables used for debugging etc, 
	//of course could have been all encapsulated in one if statment with one variable

	bool firstHorizontal = false;
	bool secondHorizontal = false;
	bool thirdHorizontal = false;
	bool firstVerticle = false;
	bool secondVertical = false;
	bool thirdVertical = false;
	bool firstDiagonal = false;
	bool secondDiagonal = false;

	
	if ((board[0] == userMark && board[1] == computerMark) ||
		(board[0] == computerMark && board[1] == userMark) ||
		(board[1] == computerMark && board[2] == userMark) ||
		(board[2] == computerMark && board[1] == userMark) ||
		(board[0] == computerMark && board[2] == userMark) ||
		(board[2] == computerMark && board[0] == userMark)) {
		firstHorizontal = true;
	} if ((board[3] == userMark && board[4] == computerMark) ||
		(board[3] == computerMark && board[4] == userMark) ||
		(board[4] == computerMark && board[5] == userMark) ||
		(board[5] == computerMark && board[4] == userMark) ||
		(board[3] == computerMark && board[5] == userMark) ||
		(board[5] == computerMark && board[3] == userMark)) {
		secondHorizontal = true;
	} if ((board[6] == userMark && board[7] == computerMark) ||
		(board[6] == computerMark && board[7] == userMark) ||
		(board[7] == computerMark && board[8] == userMark) ||
		(board[8] == computerMark && board[7] == userMark) ||
		(board[6] == computerMark && board[8] == userMark) ||
		(board[8] == computerMark && board[6] == userMark)) {
		thirdHorizontal = true;
	} if ((board[0] == userMark && board[3] == computerMark) ||
		(board[0] == computerMark && board[3] == userMark) ||
		(board[3] == computerMark && board[6] == userMark) ||
		(board[6] == computerMark && board[3] == userMark) ||
		(board[0] == computerMark && board[6] == userMark) ||
		(board[6] == computerMark && board[0] == userMark)) {
		firstVerticle = true;
	}if ((board[1] == userMark && board[4] == computerMark) ||
		(board[1] == computerMark && board[4] == userMark) ||
		(board[4] == computerMark && board[7] == userMark) ||
		(board[7] == computerMark && board[4] == userMark) ||
		(board[1] == computerMark && board[7] == userMark) ||
		(board[7] == computerMark && board[1] == userMark)) {
		secondVertical = true;
	}if ((board[2] == userMark && board[5] == computerMark) ||
		(board[2] == computerMark && board[5] == userMark) ||
		(board[5] == computerMark && board[8] == userMark) ||
		(board[8] == computerMark && board[5] == userMark) ||
		(board[2] == computerMark && board[8] == userMark) ||
		(board[8] == computerMark && board[2] == userMark)) {
		thirdVertical = true;
	}if ((board[0] == userMark && board[4] == computerMark) ||
		(board[0] == computerMark && board[4] == userMark) ||
		(board[4] == computerMark && board[8] == userMark) ||
		(board[8] == computerMark && board[4] == userMark) ||
		(board[0] == computerMark && board[8] == userMark) ||
		(board[8] == computerMark && board[0] == userMark)){
		firstDiagonal = true;
	}if ((board[2] == userMark && board[4] == computerMark) ||
		(board[2] == computerMark && board[4] == userMark) ||
		(board[4] == computerMark && board[6] == userMark) ||
		(board[6] == computerMark && board[4] == userMark) ||
		(board[2] == computerMark && board[6] == userMark) ||
		(board[6] == computerMark && board[2] == userMark)) {
		secondDiagonal = true;
	}


	/*logic based off if each vertical horizontal or diagonal line is winnable, could be condensed into
	one variable however this form of multiple variables suited debugging more*/

	if ((firstHorizontal == true && secondHorizontal == true && thirdHorizontal == true &&
		firstVerticle == true && secondVertical == true && thirdVertical == true &&
		firstDiagonal == true && secondDiagonal == true) || 
	//
		(secondHorizontal == true && thirdHorizontal == true &&
		firstVerticle == true && secondVertical == true && thirdVertical == true &&
		firstDiagonal == true && secondDiagonal == true) ||
	//
		(firstHorizontal == true && thirdHorizontal == true &&
		firstVerticle == true && secondVertical == true && thirdVertical == true &&
		firstDiagonal == true && secondDiagonal == true) ||
	// 
		(firstHorizontal == true && secondHorizontal == true  &&
		firstVerticle == true && secondVertical == true && thirdVertical == true &&
		firstDiagonal == true && secondDiagonal == true) ||
	//
		(firstHorizontal == true && secondHorizontal == true && thirdHorizontal == true &&
		 secondVertical == true && thirdVertical == true &&
		 firstDiagonal == true && secondDiagonal == true) ||
	//
		(firstHorizontal == true && secondHorizontal == true && thirdHorizontal == true &&
		firstVerticle == true &&  thirdVertical == true &&
		firstDiagonal == true && secondDiagonal == true) ||
	// 
		(firstHorizontal == true && secondHorizontal == true && thirdHorizontal == true &&
		 firstVerticle == true && secondVertical == true &&
	     firstDiagonal == true && secondDiagonal == true)||
	//
		(firstHorizontal == true && secondHorizontal == true && thirdHorizontal == true &&
		 firstVerticle == true && secondVertical == true && thirdVertical == true &&
		 secondDiagonal == true) ||
   //
		(firstHorizontal == true && secondHorizontal == true && thirdHorizontal == true &&
		 firstVerticle == true && secondVertical == true && thirdVertical == true &&
		 firstDiagonal == true)) {
		gameDraw = true;
	}

	return gameDraw;
}


void Tictactoe::delay(void) {
	Sleep(delay_ms);
}

//funciton for the logic behind the advanced gamemode
int Tictactoe::advancedGenerateComputerChoice(void) {

	//optimal opener
	if (board[4] != computerMark && board[4] != userMark) {
		computerChoice = 4;
	}

	//attack logic -> holds higher pirority than defence
	// Check horizontal lines
	//1
	else if (board[0] == computerMark && board[1] == computerMark && board[2] != userMark && board[2] != computerMark) {
		computerChoice = 2;

	}
	else if (board[1] == computerMark && board[2] == computerMark && board[0] != userMark && board[0] != computerMark) {
		computerChoice = 0;

	}
	else if (board[0] == computerMark && board[2] == computerMark && board[1] != userMark && board[1] != computerMark) {
		computerChoice = 1;

	}
	//2
	else if (board[3] == computerMark && board[4] == computerMark && board[5] != userMark && board[5] != computerMark) {
		computerChoice = 5;

	}
	else if (board[4] == computerMark && board[5] == computerMark && board[3] != userMark && board[3] != computerMark) {
		computerChoice = 3;

	}
	else if (board[3] == computerMark && board[5] == computerMark && board[4] != userMark && board[4] != computerMark) {
		computerChoice = 4;

	}
	//3
	else if (board[6] == computerMark && board[7] == computerMark && board[8] != userMark && board[8] != computerMark) {
		computerChoice = 8;

	}
	else if (board[7] == computerMark && board[8] == computerMark && board[6] != userMark && board[6] != computerMark) {
		computerChoice = 6;

	}
	else if (board[6] == computerMark && board[8] == computerMark && board[7] != userMark && board[7] != computerMark) {
		computerChoice = 7;

	}

	// Check vertical lines
	//1
	else if (board[0] == computerMark && board[3] == computerMark && board[6] != userMark && board[6] != computerMark) {
		computerChoice = 6;

	}
	else if (board[3] == computerMark && board[6] == computerMark && board[0] != userMark && board[0] != computerMark) {
		computerChoice = 0;

	}
	else if (board[0] == computerMark && board[6] == computerMark && board[3] != userMark && board[3] != computerMark) {
		computerChoice = 3;

	}
	//2
	else if (board[1] == computerMark && board[4] == computerMark && board[7] != userMark && board[7] != computerMark) {
		computerChoice = 7;

	}
	else if (board[4] == computerMark && board[7] == computerMark && board[1] != userMark && board[1] != computerMark) {
		computerChoice = 1;

	}
	else if (board[1] == computerMark && board[7] == computerMark && board[4] != userMark && board[4] != computerMark) {
		computerChoice = 4;

	}
	//3
	else if (board[2] == computerMark && board[5] == computerMark && board[8] != userMark && board[8] != computerMark) {
		computerChoice = 8;

	}
	else if (board[5] == computerMark && board[8] == computerMark && board[2] != userMark && board[2] != computerMark) {
		computerChoice = 2;

	}
	else if (board[2] == computerMark && board[8] == computerMark && board[5] != userMark && board[5] != computerMark) {
		computerChoice = 5;

	}
	// Check diagonal lines
	//1
	else if (board[0] == computerMark && board[4] == computerMark && board[8] != userMark && board[8] != computerMark) {
		computerChoice = 8;

	}
	else if (board[4] == computerMark && board[8] == computerMark && board[0] != userMark && board[0] != computerMark) {
		computerChoice = 0;

	}
	else if (board[0] == computerMark && board[8] == computerMark && board[4] != userMark && board[4] != computerMark) {
		computerChoice = 4;

	}
	//2
	else if (board[2] == computerMark && board[4] == computerMark && board[6] != userMark && board[6] != computerMark) {
		computerChoice = 6;

	}
	else if (board[4] == computerMark && board[6] == computerMark && board[2] != userMark && board[2] != computerMark) {
		computerChoice = 2;

	}
	else if (board[2] == computerMark && board[6] == computerMark && board[4] != userMark && board[4] != computerMark) {
		computerChoice = 4;

	}

	//defence logic -> Second in priority
	// Check horizontal lines
	//1
	else if (board[0] == userMark && board[1] == userMark && board[2] != userMark && board[2] != computerMark) {
	computerChoice = 2;
 
	} 
	else if (board[1] == userMark && board[2] == userMark && board[0] != userMark && board[0] != computerMark) {
	computerChoice = 0;
 
	}
	else if (board[0] == userMark && board[2] == userMark  && board[1] != userMark && board[1] != computerMark) {
	computerChoice = 1;
 
	}
	//2
	else if (board[3] == userMark && board[4] == userMark && board[5] != userMark && board[5] != computerMark) {
	computerChoice = 5;
	 
	}else if (board[4] == userMark && board[5] == userMark  && board[3] != userMark && board[3] != computerMark) {
	computerChoice = 3;
	 
	}else if (board[3] == userMark && board[5] == userMark && board[4] != userMark && board[4] != computerMark) {
	computerChoice = 4;
	 
	}
	//3
	else if (board[6] == userMark && board[7] == userMark  && board[8] != userMark && board[8] != computerMark) {
	computerChoice = 8;
	 
	}else if (board[7] == userMark && board[8] == userMark  && board[6] != userMark && board[6] != computerMark) {
	computerChoice = 6;
	 
	}else if (board[6] == userMark && board[8] == userMark  && board[7] != userMark && board[7] != computerMark) {
	computerChoice = 7; 
	}

	// Check vertical lines
	//1
	else if (board[0] == userMark && board[3] == userMark  && board[6] != userMark && board[6] != computerMark) {
	computerChoice = 6;
	 
	}else if (board[3] == userMark && board[6] == userMark && board[0] != userMark && board[0] != computerMark) {
	computerChoice = 0;
	 
	}else if (board[0] == userMark && board[6] == userMark  && board[3] != userMark && board[3] != computerMark) {
	computerChoice = 3;
	}

	//2
	else if (board[1] == userMark && board[4] == userMark  && board[7] != userMark && board[7] != computerMark) {
	computerChoice = 7;
	 
	}else if (board[4] == userMark && board[7] == userMark  && board[1] != userMark && board[1] != computerMark) {
	computerChoice = 1;
	 
	}else if (board[1] == userMark && board[7] == userMark && board[4] != userMark && board[4] != computerMark) {
	computerChoice = 4;
	 
	}
	//3
	else if (board[2] == userMark && board[5] == userMark  && board[8] != userMark && board[8] != computerMark) {
	computerChoice = 8;
	 
	}else if (board[5] == userMark && board[8] == userMark && board[2] != userMark && board[2] != computerMark) {
	computerChoice = 2;
	 
	}else if (board[2] == userMark && board[8] == userMark && board[5] != userMark && board[5] != computerMark) {
	computerChoice = 5;
	 
	}
	// Check diagonal lines
	//1
	else if (board[0] == userMark && board[4] == userMark  && board[8] != userMark && board[8] != computerMark) {
	computerChoice = 8;
	 
	}else if (board[4] == userMark && board[8] == userMark && board[0] != userMark && board[0] != computerMark) {
	computerChoice = 0;
	 
	}else if (board[0] == userMark && board[8] == userMark && board[4] != userMark && board[4] != computerMark) {
	computerChoice = 4;
	 
	}
	//2
	else if (board[2] == userMark && board[4] == userMark  && board[6] != userMark && board[6] != computerMark) {
	computerChoice = 6;
	 
	}else if (board[4] == userMark && board[6] == userMark && board[2] != userMark && board[2] != computerMark) {
	computerChoice = 2;
	 
	}else if (board[2] == userMark && board[6] == userMark && board[4] != userMark && board[4] != computerMark) {
	computerChoice = 4;
	 
	}

	//Random corner moves if no other attack / defence moves available
	else  {
		do {
			int choice = rand() % 8 + 1;
			if (choice == 1) {
				computerChoice = 0;
			}
			else if (choice == 2) {
				computerChoice = 2;
			}
			else if (choice == 2) {
				computerChoice = 2;
			}
			else if (choice == 3) {
				computerChoice = 2;
			}
			else if (choice == 4) {
				computerChoice = 6;
			}
			else if (choice == 5) {
				computerChoice = 6;
			}
			else if (choice == 6) {
				computerChoice = 6;
			}
			else if (choice == 7) {
				computerChoice = 8;
			}
			else if (choice == 8) {
				computerChoice = 8;
			}
			else if (choice == 9) {
				computerChoice = 8;
			}
		} while ((board[computerChoice] == userMark || board[computerChoice] == computerMark) &&
			countAvailableSpaces()>0);
	}

	return (computerChoice+1);
}


//funciton to set gamemode variable (*refer to main for implimentation of said variable*)
bool Tictactoe::gameMode(void){

	cout << "Welcome to Tic Tac Toe!!!\n";
	delay();
	cout << "Would you like to play easy or hard mode? (E or H)\n";
	char gameModeChoice;
	cin >> gameModeChoice;
	

	if (gameModeChoice == 'e' || gameModeChoice == 'E') {
		gameMChoice = true;
	}
	else if (gameModeChoice == 'h' || gameModeChoice == 'H') {
		gameMChoice = false;
	}
	else {
		cout << "Invalid Input...\n";
		delay();
		cout << "Playing in Easy mode...\n";
		delay();
	}
	cout << "Game starting !!\n";
	delay();
	cout << "Type Q at any time to terminate the game\n";
	delay();
	delay();

	return false;
}


//funciton to terminate the game if char q input
bool Tictactoe::terminateGame(char choice)
{
	
	if (choice == 'q' || choice == 'Q') {
		cout << "Terminating the game...\n";
		terminate = true;
		active = false;
	}
	else {
		terminate = false;
	}
	return false;
}

