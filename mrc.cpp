
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>


bool isWin(char game[3][3]){
	bool win = false;
	if ((game[0][0]!= ' ') && (game[0][0] == game[0][1] && game[0][1] == game[0][2])) win = true;
	if ((game[1][0]!= ' ') && (game[1][0] == game[1][1] && game[1][1] == game[1][2])) win = true;
	if ((game[2][0]!= ' ') && (game[2][0] == game[2][1] && game[2][1] == game[2][2])) win = true;
	// column
	if ((game[0][0]!= ' ') && (game[0][0] == game[1][0] && game[1][0] == game[2][0])) win = true;
	if ((game[1][0]!= ' ') && (game[0][1] == game[1][1] && game[1][1] == game[2][1])) win = true;
	if ((game[2][0]!= ' ') && (game[0][2] == game[1][2] && game[1][2] == game[2][2])) win = true;
	// diagonal
	if ((game[0][0]!= ' ') && (game[0][0] == game[1][1] && game[1][1] == game[2][2])) win = true;
	if ((game[0][2]!= ' ') && (game[0][2] == game[1][1] && game[1][1] == game[2][0])) win = true;
	return win;
}

void showBoard(char game[3][3]){
	// show the game to console
	std::cout << game[0][0] << "|" << game[0][1] << "|" << game[0][2] << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << game[1][0] << "|" << game[1][1] << "|" << game[1][2] << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << game[2][0] << "|" << game[2][1] << "|" << game[2][2] << std::endl;
}

bool isAvailable(char tmp){
    if (tmp == ' ')
        return true;
    else
        return false;
}

int  main(){
	int i, j;
	char game[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; // Tic-tac-toe
	
	char player1 = 'X';
	char player2 = 'O';
	bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
	std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;
    for (int n=0; n<9; n++){
		turn = !turn;  // use the not-operator to change true to false or false to true.
		if (turn == false)
			std::cout << "Player 1: ";
		else
			std::cout << "Player 2: ";
		std::cout << "Which cell to mark? i:[1..3], j:[1..3]: "; 
		
		std::cin >> i >> j;
		if(cin.fail()){
		    std::cout << "Input should be two integer ranged in {0, 1, 2}" << std::endl; 
		    cin.clear();
		    cin.ignore(10000,'\n');
		    turn = !turn;
		    continue;
		}

		if ( i < 0 || i > 2 || j < 0 || j > 2 ){  
		    std::cout << "Input integer should be ranged in {0, 1, 2}" << std::endl; 
            n--;
		}else if (!isAvailable(game[i][j])){
		    std::cout << "This position has been inputted" << std::endl; 
        }else{
            if (turn == false)
                game[i][j] = player1;
            else 
                game[i][j] = player2;
            if (isWin(game)){
                std::cout << "Win!" << std::endl;
                break; // need to terminate the problem
            }
        }
        showBoard(game);
        if (n==8) // all celles with i=0 to 2 have been inputted above but no winner yet
            std::cout << "Tie!" << std::endl;
	}
	
	return 1;
}
