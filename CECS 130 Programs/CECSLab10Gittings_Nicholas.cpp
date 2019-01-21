#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

/*
Nick Gittings
CECS 130-1
3D Tic Tac Toe Board
*/

//Global boolean and counter to be used in functions/main
int iPlayerWinCounter = 0;
int iAiWinCounter = 0;
int iTurnCounter = 0;
bool bGameWon = false;

//Declaring class game
class game
{
	public:
		
	string Cells[3][3][3] = {{{"A1", "B1", "C1"}, {"A2", "B2", "C2"}, {"A3", "B3", "C3"}}, {{"D1", "E1", "F1"}, {"D2", "E2", "F2"}, {"D3","E3", "F3"}}, {{"G1", "H1", "I1"}, {"G2", "H2", "I2"}, {"G3", "H3", "I3"}}}; 
	string PlayerSymbol;
	string AiSymbol;
	
	void determine_symbol();
	void create_board();
	void player_turn(string PlayerSymbol);
	void ai_turn(string AiSymbol);
	void check_win();
};

int main()
{
	//Declaring object of class game and elements of game.
	//game tictactoe;
	
	srand (time(NULL));
	
	bool bRunning = true;
	int Program_Type, random;
	
	//Creating menu and game loop
	do
	{
		//cout << iTurnCounter << tictactoe.PlayerSymbol << iPlayerWinCounter << endl;
		cout << "Tic Tac Toe Ver 1.0" << endl;
		cout << "1. Play Against AI" << endl;
		cout << "2. Quit" << endl;
		cin >> Program_Type;
		
		switch(Program_Type)
		{
			case 1:
			{
				game tictactoe;
				tictactoe.determine_symbol();
				bGameWon = false;
				random = rand() % 2;
				cout << "Flipping coin..." << endl;
				
				if(random == 0)
				{
					cout << "You go first!" << endl;
					tictactoe.create_board();
					while(bGameWon == false)
					{
						tictactoe.player_turn(tictactoe.PlayerSymbol);
						if(iTurnCounter == 27)
						{
							tictactoe.check_win();
							bGameWon = true;
							break;
						}
						tictactoe.ai_turn(tictactoe.AiSymbol);
						tictactoe.create_board();
					}
				}
				else if (random == 1)
				{
					cout << "You go second!" << endl;
					while(bGameWon == false)
					{
						tictactoe.ai_turn(tictactoe.AiSymbol);
						if(iTurnCounter == 27)
						{
							tictactoe.check_win();
							bGameWon = true;
							break;
						}
						tictactoe.create_board();
						tictactoe.player_turn(tictactoe.PlayerSymbol);
					}
				}
				break;
			}
			case 2:
			{
				cout << "Exiting..." << endl;
				bRunning = false;
				break;
			}
			default:
			{
				cout << "Invalid input..." << endl;
			}
		}
	}
	while(bRunning == true);	
	
	return 0;
}

/* Functions */

//Determines player and ai symbol
void game::determine_symbol()
{
	string temp;
	bool bChoosing_Symbol = true;
	
	while(bChoosing_Symbol == true)
	{
		cout << "Choose X or O" << endl;
		cin >> temp;
		if(temp == "X")
		{
			PlayerSymbol = temp;
			AiSymbol = "O";
			bChoosing_Symbol = false;
		}
		else if (temp == "O")
		{
			PlayerSymbol = temp;
			AiSymbol = "X";
			bChoosing_Symbol = false;
		}
		else
		{
			cout << "Incorrect Input" << endl;
		}
	}
}

//Creates Tic Tac Toe Board
void game::create_board()
{
	int i,j = 0,k = 0;
	
	for(i = 0; i < 3; i++)
	{
		if(i == 0)
		{
			cout << "Top" << endl;
		}
		if(i == 1)
		{
			cout << "Middle" << endl;
		}
		if(i == 2)
		{
			cout << "Bottom" << endl;
		}
		
		cout << "__________________________" << endl << endl;
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++)
			{
				cout << Cells[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << "__________________________" << endl;
	}
}

void game::player_turn(string PlayerSymbol)
{
	string player_choice;
	bool bPlayerChoosing = true;
	int i,j,k;
	//Takes player's choice of cell
	cout << "Your turn! Choose a cell..." << endl;
	
	//While loop to keep player choosing till an appropriate cell is chosen
	do
	{
		cin >> player_choice;
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				for(k = 0; k < 3; k++)
				{
					if(player_choice == Cells[i][j][k])
					{
						if(player_choice != AiSymbol && player_choice != PlayerSymbol)
						{
							Cells[i][j][k] = PlayerSymbol;
							bPlayerChoosing = false;
						}
						else
						{
							cout << "Incorrect Input or cell already taken" << endl;
						}
					}
				}
			}
			
		}
	}while(bPlayerChoosing == true);
	iTurnCounter++;
}

void game::ai_turn(string AiSymbol)
{
	string ai_choice;
	bool bAiChoosing = true;
	
	cout << "Ai's turn" << endl;
	
	//Ai choses random string in array Cells to check if used and if not then repeats random till one is found
	do
	{
		int i = (rand() % 3);
		int j = (rand() % 3);
		int k = (rand() % 3);
	
		if(Cells[i][j][k] != PlayerSymbol && Cells[i][j][k] != AiSymbol)
		{
			Cells[i][j][k] = AiSymbol;
			bAiChoosing = false;
		}
	}while(bAiChoosing == true);
	iTurnCounter++;
}

//Checks win condition
void game::check_win()
{
	int i,j,k;
	
	for(i = 0; i < 3; i++)
	{
		//Checking 2D Diagonal
		if(Cells[i][0][0] == PlayerSymbol && Cells[i][1][1] == PlayerSymbol && Cells[i][2][2] == PlayerSymbol || Cells[i][0][2] == PlayerSymbol && Cells[i][1][1] == PlayerSymbol && Cells[i][2][0] == PlayerSymbol)
		{
			iPlayerWinCounter++;
		}
		
		//Checking 2D Horizontal
		for(j = 0; j < 3; j++)
		{
			if(Cells[i][j][0] == PlayerSymbol && Cells[i][j][1] == PlayerSymbol && Cells[i][j][2] == PlayerSymbol)
			{
				iPlayerWinCounter++;
			}		
		}
		//Checking 2D Vertical
		for(k = 0; k < 3; k++)
		{
			if(Cells[i][0][k] == PlayerSymbol && Cells[i][1][k] == PlayerSymbol && Cells[i][2][k] == PlayerSymbol)
			{
				iPlayerWinCounter++;
			}
		}
	}
	
	//Checking 3D Vertical
	for(j = 0; j < 3; j++)
	{
		for(k = 0; k < 3; k++)
		{
			if(Cells[0][j][k] == PlayerSymbol && Cells[1][j][k] == PlayerSymbol && Cells[2][j][k] == PlayerSymbol)
			{
				iPlayerWinCounter++;
			}
		}
	}

	//Checking 3D Diagonal
	if(Cells[0][0][0] == PlayerSymbol && Cells[1][1][1] == PlayerSymbol && Cells[2][2][2] == PlayerSymbol || Cells[2][2][0] == PlayerSymbol && Cells[1][1][1] == PlayerSymbol && Cells[0][1][2] == PlayerSymbol || Cells[0][2][2] == PlayerSymbol && Cells[1][1][1] == PlayerSymbol && Cells[2][0][0] == PlayerSymbol || Cells[0][2][1] == PlayerSymbol && Cells[1][1][1] == PlayerSymbol && Cells[2][0][2] == PlayerSymbol )
	{
		iPlayerWinCounter++;
	}
	
	/* Ai Check */
	for(i = 0; i < 3; i++)
	{
		//Checking 2D Diagonal
		if(Cells[i][0][0] == AiSymbol && Cells[i][1][1] == AiSymbol && Cells[i][2][2] == AiSymbol || Cells[i][0][2] == AiSymbol && Cells[i][1][1] == AiSymbol && Cells[i][2][0] == AiSymbol)
		{
			iAiWinCounter++;
		}
		
		//Checking 2D Horizontal
		for(j = 0; j < 3; j++)
		{
			if(Cells[i][j][0] == AiSymbol && Cells[i][j][1] == AiSymbol && Cells[i][j][2] == AiSymbol)
			{
				iPlayerWinCounter++;
			}		
		}
		//Checking 2D Vertical
		for(k = 0; k < 3; k++)
		{
			if(Cells[i][0][k] == AiSymbol && Cells[i][1][k] == AiSymbol && Cells[i][2][k] == AiSymbol)
			{
				iAiWinCounter++;
			}
		}
	}
	
	//Checking 3D Vertical
	for(j = 0; j < 3; j++)
	{
		for(k = 0; k < 3; k++)
		{
			if(Cells[0][j][k] == AiSymbol && Cells[1][j][k] == AiSymbol && Cells[2][j][k] == AiSymbol)
			{
				iAiWinCounter++;
			}
		}
	}

	//Checking 3D Diagonal
	if(Cells[0][0][0] == AiSymbol && Cells[1][1][1] == AiSymbol && Cells[2][2][2] == AiSymbol || Cells[2][2][0] == AiSymbol && Cells[1][1][1] == AiSymbol && Cells[0][1][2] == AiSymbol || Cells[0][2][2] == AiSymbol && Cells[1][1][1] == AiSymbol && Cells[2][0][0] == AiSymbol || Cells[0][2][1] == AiSymbol && Cells[1][1][1] == AiSymbol && Cells[2][0][2] == AiSymbol )
	{
		iAiWinCounter++;
	}
	
	//Display Win/Loss
	if(iPlayerWinCounter > iAiWinCounter)
	{
		cout << "You Win! Score: " << iPlayerWinCounter << "-" << iAiWinCounter << endl;
	}
	else if(iAiWinCounter > iPlayerWinCounter)
	{
		cout << "You Lose!" << iPlayerWinCounter << "-" << iAiWinCounter << endl;
	}
	else if(iPlayerWinCounter == iAiWinCounter)
	{
		cout << "Tie!" << endl;
	}
	
	game::create_board();
	system("PAUSE");
}
