#include "TicTacToe.h"

int main()
{
	Tictactoe game;
	
	
	game.gameMode(); //game mode choice 
	game.displayBoard();

	do {
		cout << "Please enter your available move :";

		char choice;
		cin >> choice;

		game.terminateGame(choice);
		game.userChoice = (int)choice - 48;
		
		if (game.updateBoard(game.userChoice, userMark)){
			game.displayBoard();
			game.delay();
			if (game.gameMChoice == true) {
				game.computerChoice = game.generateComputerChoice();
			}
			else if (game.gameMChoice == false) {
				game.computerChoice = game.advancedGenerateComputerChoice();
			}
			
			game.updateBoard(game.computerChoice, computerMark);
			
			game.displayBoard();

			switch (game.checkGame()) {
			case gameOnGoing: //loop back around as game still ongoing
				break;
			case gameFinished:
				cout << "Game is over: No winner" << endl;
				break;
			case userWins:
				cout << "User wins" << endl;
				break;
			case computerWins:
				cout << "Computer wins" << endl;
				break;
			case gameDrawOver:
				cout << "It's a draw" << endl;
				break;
			}

		}
		else {
			if (game.terminate == true) {
				//do nothing -- loop back around etc...
			}
			else {
				cout << "Error: Please select another space" << endl;
			}
				// go around again
		}

	} while (game.active);

	return 0;
}


