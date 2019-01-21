#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

/*
Nick Gittings
CECS 130-1
Tic Tac Toe Board
*/

//Global boolean and counter to be used in functions/main
int iTurnCounter = 0;
bool bGameWon = false;

//Declaring class game
class game
{
	public:
		
	string Cells[9] = {"A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3"}; 
	string PlayerSymbol;
	string AiSymbol;
	
	void determine_symbol();
	void create_board();
	void player_turn(string PlayerSymbol);
	void ai_turn(string AiSymbol);
	void check_win();
	void reset_gamestate();
};

int main()
{
	//Declaring object of class game and elements of game.
	game tictactoe;
	/*tictactoe.PlayerSymbol;
	tictactoe.AiSymbol;
	tictactoe.Cells;*/
	
	srand (time(NULL));
	
	bool bRunning = true;
	int Program_Type, random;
	
	//Creating menu and game loop
	do
	{
		cout << "Tic Tac Toe Ver 1.0" << endl;
		cout << "1. Play Against AI" << endl;
		cout << "2. Quit" << endl;
		cin >> Program_Type;
		
		switch(Program_Type)
		{
			case 1:
				tictactoe.determine_symbol();
				bGameWon = false;
			
				cout << "Flipping coin..." << endl;
				random = rand() % 2;
				if(random == 0)
				{
					cout << "You go first!" << endl;
					tictactoe.create_board();
					while(bGameWon == false)
					{
						tictactoe.player_turn(tictactoe.PlayerSymbol);
						tictactoe.check_win();
						if(bGameWon == true)
						{
							break;
						}
						tictactoe.ai_turn(tictactoe.AiSymbol);
						tictactoe.check_win();
						if(bGameWon == true)
						{
							break;
						}
						tictactoe.create_board();
					}
				}
				else if (random == 1)
				{
					while(bGameWon == false)
					{
						cout << "You go second!" << endl;
						tictactoe.ai_turn(tictactoe.AiSymbol);
						tictactoe.create_board();
						tictactoe.check_win();
						if(bGameWon == true)
						{
							break;
						}
						tictactoe.player_turn(tictactoe.PlayerSymbol);
						tictactoe.check_win();
						if(bGameWon == true)
						{
							break;
						}
					}
				}
				//tictactoe.reset_gamestate(Cells[9], PlayerSymbol, AiSymbol);
				break;
			
			case 2:
				cout << "Exiting..." << endl;
				bRunning = false;
				break;
				
			default:
				cout << "Invalid input..." << endl;
			
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
	cout << "        A      B        C" << endl;
	cout << "----------------------------" << endl;
	cout << "  1 |    " << Cells[0] <<" |     " << Cells[1] << " |     " << Cells[2] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "  2 |    " << Cells[3] <<" |     " << Cells[4] << " |     " << Cells[5] << " | " << endl;
	cout << "----------------------------" << endl;
	cout << "  3 |    " << Cells[6] <<" |     " << Cells[7] << " |     " << Cells[8] << " | " << endl;
	cout << "----------------------------" << endl;
}

void game::player_turn(string PlayerSymbol)
{
	string player_choice;
	bool bPlayerChoosing = true;
	int i;
	
	//Takes player's choice of cell
	cout << "Your turn! Choose a cell..." << endl;
	
	//While loop to keep player choosing till an appropriate cell is chosen
	do
	{
		cin >> player_choice;
		for(i = 0; i <= 9; i++)
		{
			if(player_choice == Cells[i])
			{
				if(player_choice != AiSymbol && player_choice != PlayerSymbol)
				{
					Cells[i] = PlayerSymbol;
					bPlayerChoosing = false;
				}
			}
		}
		if(player_choice != Cells[i] && bPlayerChoosing == true)
		{
			cout << "Incorrect Input or cell already taken" << endl;
		}
	}while(bPlayerChoosing == true);
	
	iTurnCounter ++;
}

void game::ai_turn(string AiSymbol)
{
	string ai_choice;
	bool bAiChoosing = true;
	
	cout << "Ai's turn" << endl;
	
	//Ai choses random string in array Cells to check if used and if not then repeats random till one is found
	do
	{
		int i = (rand() % 10);
	
		if(Cells[i] != PlayerSymbol && Cells[i] != AiSymbol)
		{
			Cells[i] = AiSymbol;
			bAiChoosing = false;
		}
	}while(bAiChoosing == true);
	
	iTurnCounter ++;
}

//Checks win condition
void game::check_win()
{
	if((Cells[0] == PlayerSymbol && Cells[1] == PlayerSymbol && Cells[2] == PlayerSymbol) || (Cells[3] == PlayerSymbol && Cells[4] == PlayerSymbol && Cells[5] == PlayerSymbol) || (Cells[6] == PlayerSymbol && Cells[7] == PlayerSymbol && Cells[8] == PlayerSymbol) || (Cells[0] == PlayerSymbol && Cells[4] == PlayerSymbol && Cells[8] == PlayerSymbol) || (Cells[2] == PlayerSymbol && Cells[4] == PlayerSymbol && Cells[8] == PlayerSymbol))
	{
		cout << "You win!" << endl;
		bGameWon = true;
	}
	
	else if((Cells[0] == AiSymbol && Cells[1] == AiSymbol && Cells[2] == AiSymbol) || (Cells[3] == AiSymbol && Cells[4] == AiSymbol && Cells[5] == AiSymbol) || (Cells[6] == AiSymbol && Cells[7] == AiSymbol && Cells[8] == AiSymbol) || (Cells[0] == AiSymbol && Cells[4] == AiSymbol && Cells[8] == AiSymbol) || (Cells[2] == AiSymbol && Cells[4] == AiSymbol && Cells[8] == AiSymbol))
	{
		cout << "You lose!" << endl;
		bGameWon = true;
	}
	
	//Counter reaches 9 then game is tied
	else if(iTurnCounter == 9 && bGameWon == false)
	{
		cout << "Tie!" << endl;
		bGameWon = true;
	}
}

void game::reset_gamestate()
{
	int i;
	string Cells[9] = {"A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3"}; 
	string PlayerSymbol = "\0";
	string AiSymbol = "\0";
}
