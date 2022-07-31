/*
	TIC TAC TOE

	PSEUDOCODE:
	(1) PRINT empty board and welcome message
	(2) GET coordinate from first player (X)
	(3) CHECK if the move is valid otherwise display error message and ask again
	(4) UPDATE board with the player move
	(5) GET coordinate from second player(o)
	(6) CHECK if move is  valid
	(7) UPDATE board with new move
	(8) REPEAT previous steps
	(9) CHECK for winner or draw after each move
   (10) ASK user to play again

   MADE BY Dario Calle Reyes 2-22-22
*/

#include <iostream>
using namespace std;

void displayBoard(char board[3][3]);
void clearBoard(char board[3][3]);
void executeTurn(bool player, char board[3][3]);
int gameOver(char board[3][3]);

int main()
{
	char board[3][3];
	char userChoice = 'y';
	int player = 0, answer;

	while (userChoice == 'Y' || userChoice == 'y') {
		//(1) PRINT empty board and welcome message
		clearBoard(board);
		displayBoard(board);
		while (true) {
			//(2) GET coordinate from first player (X)
			//(3) CHECK if the move is valid otherwise display error message and ask again
			//(4) UPDATE board with the player move
			executeTurn(player, board);
			answer = gameOver(board);

			//(9) CHECK for winner or draw after each move
			if (answer == 0) {
				cout << " X IS THE WINNER!!!" << endl;
				displayBoard(board);
				break;
			}
			else if (answer == 1) {
				cout << " O IS THE WINNER!!!" << endl;
				displayBoard(board);
				break;
			}
			else if (answer == 2) {
				cout << "\n DRAW! NOBODY WINS!" << endl;
				displayBoard(board);
				break;
			}
			else {
				displayBoard(board);
			}

			player = 1;

			executeTurn(player, board);
			answer = gameOver(board);

			if (answer == 0) {
				cout << " X IS THE WINNER!!!" << endl;
				displayBoard(board);
				break;
			}
			else if (answer == 1) {
				cout << " O IS THE WINNER!!!" << endl;
				displayBoard(board);
				break;
			}
			else if (answer == 2) {
				cout << "\n DRAW! NOBODY WINS!" << endl;
				displayBoard(board);
				break;
			}
			else {
				displayBoard(board);
			}
			player = 0;
		}
		//(10) ASK user to play again
		cout << " Another game? Enter Y or y for yes. \n ";
		cin >> userChoice;
	}
	cout << " Thank you for playing!";

	return 0;
}

void displayBoard(char board[3][3]) {

	cout << " -----------------" << endl;
	cout << " |R\\C| 0 | 1 | 2 |" << endl;
	cout << " -----------------" << endl;

	for (int i = 0; i <= 2; i++) {
		cout << " | " << i;

		for (int j = 0; j <= 2; j++) {
			cout << " | " << board[i][j];

			if (j == 2) {
				cout << " |";
			}
			
		}

		cout << endl;
		cout << " -----------------" << endl;
	}

	cout << endl;
}

void clearBoard(char board[3][3]) {

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			board[i][j] = ' ';
		}
	}

	cout << " New Game: X goes first." << endl << endl;
}

void executeTurn(bool player, char board[3][3]) {

	int row, column;

	while (true) {
		if (player == 0) {
			cout << " X's turn." << endl;
			cout << " Where do you want your X placed?" << endl;
			cout << " Please enter row number and column number separated by a space. \n ";
			cin >> row >> column; //(2) GET coordinate from first player (X)
			cout << " You have entered row #" << row << endl;
			cout << "           and column #" << column << endl;


		}
		else if (player == 1) {
			cout << " O's turn." << endl;
			cout << " Where do you want your O placed?" << endl;
			cout << " Please enter row number and column number separated by a space. \n ";
			cin >> row >> column; //(5) GET coordinate from second player(o)
			cout << " You have entered row #" << row << endl;
			cout << "           and column #" << column << endl;


		}

		//(3) CHECK if the move is valid otherwise display error messageand ask again
		if (row > 2 || row < 0 || column > 2 || column < 0) {
			cout << " Invalid entry: try again." << endl;
			cout << " Row & column numbers must be either 0, 1, or 2." << endl << endl;
			continue; 
		}
		else if (board[row][column] != ' ') {
			cout << " That cell is already taken." << endl;
			cout << " Please make another selection." << endl << endl;
			continue;
		}

		else {
			cout << " Thank you for your selection." << endl;
			break;
		}
	}
	//(4) UPDATE board with the player move
	if (player == 0) {
		board[row][column] = 'X';
	}
	else if (player == 1) {
		board[row][column] = 'o';
	}

}

int gameOver(char board[3][3]) {

	for (int i = 0; i <= 2; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			if (board[i][0] == 'X') {
				return 0;
			}
			else if (board[i][0] == 'o') {
				return 1;
			}

		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
			if (board[0][i] == 'X') {
				return 0;
			}
			else if (board[0][i] == 'o') {
				return 1;
			}
		}
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
			if (board[0][i] == 'X') {
				return 0;
			}
			else if (board[0][i] == 'o') {
				return 1;
			}
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
			if (board[0][i] == 'X') {
				return 0;
			}
			else if (board[0][i] == 'o') {
				return 1;
			}
		}
	}

	int counter = 0;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (board[i][j] == ' ') {
				counter++;
			}
		}
	}

	if (counter != 0) {
		return -1;
	}
	else {
		return 2;
	}
}