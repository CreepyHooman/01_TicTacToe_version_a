#include <iostream>
#include <string>
#include <random>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>



/*
********************************************

* current bugs 04_08_2024
 
 - clean up the code
 - gameOverFunction needs a simpler logic to be used in infinite TicTacTie
 - if you type the number of the already filled field, it will count it as a round
 - if the rounds are passed and there is no winner, there should be a cout about it




*********************************************
*/

const int possibleRounds = 9;
const int fieldSize = 7;



// dice roll function 

int diceRollSum(std::string player)
{
	std::string playa = player;
	int thrownNumb = 0;
	int sumOfNumbs = 0;

	for (int i = 0; i < 6; i++)
	{
		std::cout << playa << " Press any key to 'throw' the dice...";

		_getch();

		int randSeed = time(0);
		srand(randSeed);
		thrownNumb = 1 + rand() % 6;

		std::cout << " " << thrownNumb << std::endl;;

		sumOfNumbs += thrownNumb;

	}

	std::cout << "The total sum of numbers is " << sumOfNumbs << "." << std::endl;

	return sumOfNumbs;

}



// global variable game field

char gameField[fieldSize][fieldSize] =
{
	{'-','-','-','-','-','-','-'},
	{'|',' ','|',' ','|',' ','|'},
	{'|','-','|','-','|','-','|'},
	{'|',' ','|',' ','|',' ','|'},
	{'|','-','|','-','|','-','|'},
	{'|',' ','|',' ','|',' ','|'},
	{'-','-','-','-','-','-','-'}
};




// function to display game field

void displayGameField()
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n";

	for (int a = 0; a < 7; a++)
	{
		for (int b = 0; b < 7; b++)
		{
			std::cout << gameField[a][b] << ' ';
		}

		std::cout << "\n";
	}

	std::cout << "\n\n\n\n\n\n\n\n\n\n";
}



bool gameOverFunction(char field[fieldSize][fieldSize], int gameRounds)
{
	
	if (gameRounds >= possibleRounds)
	{
		return true;
	}

	

	// diagonals
	else if (field[3][3] != ' ' && field[3][3] == field[1][1] && field[3][3] == field[5][5])
	{
		return true;
	}


	else if (field[3][3] != ' ' && field[3][3] == field[1][5] && field[3][3] == field[5][1])
	{
		return true;
	}

	// rows
	else if (field[1][1] != ' ' && field[1][1] == field[1][3] && field[1][3] == field[1][5])
	{
		return true;
	}


	else if (field[3][1] != ' ' && field[3][1] == field[3][3] && field[3][3] == field[3][5])
	{
		return true;
	}

	else if (field[5][1] != ' ' && field[5][1] == field[5][3] && field[5][3] == field[5][5])
	{
		return true;
	}

	// columns

	else if (field [1][1] != ' ' && field[1][1] == field[3][1] && field[3][1] == field[5][1])
	{
		return true;
	}
	
	else if (field[1][3] != ' ' && field[1][3] == field[3][3] && field[3][3] == field[5][3])
	{
		return true;
	}

	else if (field[1][5] != ' ' && field[1][5] == field[3][5] && field[3][5] == field[5][5])
	{
		return true;
	}

	else
	{
		return false;
	}
}





int main()
{
	//variables

	std::string player01;
	std::string player02;
	std::string firstPlayer;
	std::string secondPlayer;

	std::cout << "***   TIC TAC TOE GAME    ***\n\n";

	std::cout << "First let's have the names of both players.\n\n\n" 
				 "Player 01 type your name: \n";

	std::cin >> player01;

	std::cout << "\n\n";

	std::cout << "Now Player02 type you name: \n";

	std::cin >> player02;

	std::cout << "\n\n";

	std::cout << "Each player is going to throw 'digital dice' 6 times. The sum of thrown numbers will decide who starts the game.\n\n";

	


	// dice roll

	int player01Sum = diceRollSum(player01);

	std::cout << "\nAnd now the other player.\n\n";

	int player02Sum = diceRollSum(player02);

	if (player01Sum > player02Sum)
	{
		firstPlayer = player01;
		secondPlayer = player02;
	}

	else
	{
		firstPlayer = player02;
		secondPlayer = player01;
	}

	std::cout << "The player one is " << firstPlayer << " and the player two is " << secondPlayer << "." << std::endl;


	// key assignation

	char chosenKey;
	char firstPlayerKey = ' ';
	char secondPlayerKey = ' ';
	std::cout << firstPlayer << " please choose between x and o: ";

	std::cin >> chosenKey;

	if (chosenKey == 'x')
	{
		firstPlayerKey = chosenKey;
		secondPlayerKey = 'o';
	}

	else
	{
		firstPlayerKey = 'o';
		secondPlayerKey = 'x';
	}


	std::cout << "Player " << firstPlayer << ": " << firstPlayerKey << std::endl;
	std::cout << "Player " << secondPlayer << ": " << secondPlayerKey << std::endl;



	//game field original state

	std::cout << " *** GAME FIELD *** \n\n\n";

	std::cout << " The fields are assignated with numbers.\n\n";


	char gameFieldExample[7][7] =
	{
		{'-','-','-','-','-','-','-'},
		{'|','1','|','2','|','3','|'},
		{'|','-','|','-','|','-','|'},
		{'|','4','|','5','|','6','|'},
		{'|','-','|','-','|','-','|'},
		{'|','7','|','8','|','9','|'},
		{'-','-','-','-','-','-','-'}
	};

	for (int a = 0; a < 7; a++)
	{
		for (int b = 0; b < 7; b++)
		{
			std::cout << gameFieldExample[a][b] << " ";
		}

		std::cout << "\n";
	}

	
	std::cout << "To continue press any key...";

	_getch();
	
	


	//display game field

	displayGameField();

	int a = 1;
	int d = 0;
	int chosenMove;
	char tmpKey = ' ';

	
	
	// game loop

	int rounds = 1;
	std::string currentPlayer;

	while (a <= 9)
	{



		if (a % 2 != 0)
		{
			d = a % 2;
			std::cout << firstPlayer << " choose your move. Type the number of the field.\n";
			std::cin >> chosenMove;
			tmpKey = firstPlayerKey;
			currentPlayer = firstPlayer;
		}

		else
		{
			d = a % 2;
			std::cout << secondPlayer << " choose your move. Type the number of the field. \n";
			std::cin >> chosenMove;
			tmpKey = secondPlayerKey;
			currentPlayer = secondPlayer;
		}

		a++;


		// switch statement

		switch (chosenMove)
		{
		case 1:
			gameField[1][1] = tmpKey;
			break;

		case 2:
			gameField[1][3] = tmpKey;
			break;

		case 3:
			gameField[1][5] = tmpKey;
			break;

		case 4:
			gameField[3][1] = tmpKey;
			break;

		case 5:
			gameField[3][3] = tmpKey;
			break;

		case 6:
			gameField[3][5] = tmpKey;
			break;

		case 7:
			gameField[5][1] = tmpKey;
			break;

		case 8:
			gameField[5][3] = tmpKey;
			break;

		case 9:
			gameField[5][5] = tmpKey;
			break;

		default:
			std::cout << "This won't work." << std::endl;
		}

		


		displayGameField();

		if (gameOverFunction(gameField, rounds) == true)
		{
			std::cout << "The game is over.\n";
			break;
		}

		
		rounds++;
		


	}
	
	std::cout << "The winner is: " << currentPlayer << ".";
	

	return 0;
}

	

	
	