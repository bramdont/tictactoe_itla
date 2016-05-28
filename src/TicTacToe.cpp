#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3]; //Possible values are X, O and _ (for blank positions)
char player = 'X';

//Give initial values to the board matrix
void init()
{
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			board[i][j] = '_';
		}
	}



}

void clearScreen(){
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

bool validate(int number){
	if(number >= 1 && number <= 3){
		return true;
	}else{
		cout << "Please pick a value between 1 and 3" << endl;
		return  false;
	}
}

bool gameover()
{
    if (board [1][1] != '-' || board [2][2] != '-' || board [3][3] != '-')
    {
        if (board [1][1] == board [1][2] && board [1][2] == board [1][3])
        {
            cout << "Player " << player << " win." << endl;
            return true;
        }
         else if (board [2][1] == board [2][2] && board [2][2] == board [2][3])
        {
            cout << "Player " << player << " win." << endl;
            return true;
        }
        else if (board [3][1] == board [3][2] && board [3][2] == board [3][3])
        {
            cout << "Player " << player << " win." << endl;
            return true;
        }
        else if (board [1][1] == board [2][1] && board [2][1] == board [3][1])
        {
            cout << "Player " << player << " win." << endl;
            return true;
        }
        else if (board [1][2] == board [2][2] && board [2][2] == board [3][2])
        {
            cout << "Player " << player << " win." << endl;
            return true;
        }
        else if (board [1][3] == board [2][3] && board [2][3] == board [3][3])
        {
            cout << "Player " << player << " win." << endl;
            return true;
        }
        else if (board [1][1] == board [2][2] && board [2][2] == board [3][3])
        {
            cout << "Player " << player << "win." << endl;
            return true;
        }
        else if (board [1][3] == board [2][2] && board [2][2] == board [3][1])
        {
            cout << "Player " << player << "win." << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
	return false;
}

void showBoard()
{
	while(!gameover())
	{
		clearScreen();
		int row = 0;
		int col = 0;

		cout << "It's " << player << "'s turn" << endl;
		//printing column numbers
		cout << "\t";
		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
		}
		cout << endl;

		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
			for(int j = 0 ; j < 3 ; j++)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl;
		}
		do
		{
			cout << "In what row would you like to play? =>";
			cin >> row;
		}while(!validate(row));
		do
		{
			cout << "In what column would you like to play? => ";
			cin >> col;
		}while(!validate(col));
		board[row - 1][col - 1] = player;
		player = player == 'X' ? 'O' : 'X';
	}
}
