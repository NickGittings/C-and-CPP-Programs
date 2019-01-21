#include <iostream>
#include <string>
#include <cstdlib>
#include<time.h>
using namespace std;

class Nick{
	void game::Nick_turn(string NickSymbol)
{
	bool bNickChoosing = true;
	
	cout << "Nick's turn" << endl;
	
	//Ai choses random string in array Cells to check if used and if not then repeats random till one is found
	do
	{
		int i = (rand() % 3);
		int j = (rand() % 3);
		int k = (rand() % 3);

		//Change to your nasty strings ill just use random cuz im too lazy to actually make true ai
		if(Cells[i][j][k] != NickSymbol && Cells[i][j][k] != JamesSymbol)
		{
			Cells[i][j][k] = NickSymbol;
			bNickChoosing = false;
		}
	}while(bNickChoosing == true);
	iTurnCounter++;
}

void game::check_win()
{
	int i,j,k;
	
	for(i = 0; i < 3; i++)
	{
		//Checking 2D Diagonal
		if(Cells[i][0][0] == NickSymbol && Cells[i][1][1] == NickSymbol && Cells[i][2][2] == NickSymbol || Cells[i][0][2] == NickSymbol && Cells[i][1][1] == NickSymbol && Cells[i][2][0] == NickSymbol)
		{
			iNickWinCounter++;
		}
		
		//Checking 2D Horizontal
		for(j = 0; j < 3; j++)
		{
			if(Cells[i][j][0] == NickSymbol && Cells[i][j][1] == NickSymbol && Cells[i][j][2] == NickSymbol)
			{
				iNickWinCounter++;
			}		
		}
		//Checking 2D Vertical
		for(k = 0; k < 3; k++)
		{
			if(Cells[i][0][k] == NickSymbol && Cells[i][1][k] == NickSymbol && Cells[i][2][k] == NickSymbol)
			{
				iNickWinCounter++;
			}
		}
	}
	
	//Checking 3D Vertical
	for(j = 0; j < 3; j++)
	{
		for(k = 0; k < 3; k++)
		{
			if(Cells[0][j][k] == NickSymbol && Cells[1][j][k] == NickSymbol && Cells[2][j][k] == NickSymbol)
			{
				iNickWinCounter++;
			}
		}
	}

	//Checking 3D Diagonal
	if(Cells[0][0][0] == NickSymbol && Cells[1][1][1] == NickSymbol && Cells[2][2][2] == NickSymbol || Cells[2][2][0] == NickSymbol && Cells[1][1][1] == NickSymbol && Cells[0][1][2] == NickSymbol || Cells[0][2][2] == NickSymbol && Cells[1][1][1] == NickSymbol && Cells[2][0][0] == NickSymbol || Cells[0][2][1] == NickSymbol && Cells[1][1][1] == NickSymbol && Cells[2][0][2] == NickSymbol )
	{
		iNickWinCounter++;
	}
	
	//Display Win/Loss
	if(iNickWinCounter > iJamesWinCounter)
	{
		cout << "You Win! Score: " << iNickWinCounter << "-" << iJamesWinCounter << endl;
	}
	else if(iNickWinCounter > iJamesWinCounter)
	{
		cout << "You Lose!" << iNickWinCounter << "-" << iJamesWinCounter << endl;
	}
	else if(iNickWinCounter == iJamesWinCounter)
	{
		cout << "Tie!" << endl;
	}
	
	game::create_board();
	system("PAUSE");
}


};
class James : public Nick{
	public:
	int Play,P1,Cchoice,Pchoice,End,x,confused;
	string A1;string A2;string A3;string B1;string B2;string B3;string C1;string C2;string C3;string D4;string D5;string D6;string E4;string E5;string E6;string F4;string F5;string F6;
	string G7; string G8; string G9;string H7; string H8; string H9;string I7; string I8; string I9;string Quad;
	int z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12,z13,z14,z15,z16,z17,z18,z19,z20,z21,z22,z23,z24,z25,z26,z27,z28,z29,z30,z31,z32,z33,z34,z35,z36,z37,z38,z39,z40,z41,z42,z43,z44,z45,z46,z47,z48,z49;
	int JamesScore = 0;
int computer(){
		while(x != 1){
				Cchoice = (rand()%27);
				if(E5.empty()){Cchoice = 14;}
				switch(Cchoice){
					case 1:
						if(A1.empty()){
							A1 = "O";
							x = 1;
							break;
						}
					case 2: 
						if(A2.empty()){
							A2 = "O";
							x = 1;
							break;
						}
					case 3:
						if(A3.empty()){
							A3 = "O";
							x = 1;
							break;
					}
					case 4: 
						if(B1.empty()){
							B1 = "O";
							x = 1;
							break;
						}
					case 5:
						if(B2.empty()){
							B2 = "O";
							x = 1;
							break;
						}	
					case 6:
						if(B3.empty()){
							B3 = "O";
							x = 1;
							break;
						}
					case 7:
						if(C1.empty()){
							C1 = "O";
							x = 1;
							break;
						}
					case 8:
						if(C2.empty()){
							C2 = "O";
							x = 1;
							break;
						}
					case 9:
						if(C3.empty()){
							C3 = "O";
							x = 1;
							break;
						}
					case 10:
						if(D4.empty()){
							D4 = "O";
							x = 1;
							break;
						}
					case 11:
						if(D5.empty()){
							D5 = "O";
							x = 1;
							break;
						}
					case 12:
						if(D6.empty()){
							D6 = "O";
							x = 1;
							break;
						}
					case 13:
						if(E4.empty()){
							E4 = "O";
							x = 1;
							break;
						}
					case 14:
						if(E5.empty()){
							E5 = "O";
							x = 1;
							break;
						}
					case 15:
						if(E6.empty()){
							E6 = "O";
							x = 1;
							break;
						}
					case 16:
						if(F4.empty()){
							F4 = "O";
							x = 1;
							break;
						}
					case 17:
						if(F5.empty()){
							F5 = "O";
							x = 1;
							break;
						}
					case 18:
						if(F6.empty()){
							F6 = "O";
							x = 1;
							break;
						}
					case 19:
						if(G7.empty()){
							G7 = "O";
							x = 1;
							break;
						}
					case 20:
						if(G8.empty()){
							G8 = "O";
							x = 1;
							break;
						}
					case 21:
						if(G9.empty()){
							G9 = "O";
							x = 1;
							break;
						}
					case 22:
						if(H7.empty()){
							H7 = "O";
							x = 1;
							break;
						}
					case 23:
						if(H8.empty()){
							H8 = "O";
							x = 1;
							break;
						}
					case 24:
						if(H9.empty()){
							H9 = "O";
							x = 1;
							break;
						}
					case 25:
						if(I7.empty()){
							I7 = "O";
							x = 1;
							break;
						}
					case 26:
						if(I8.empty()){
							I8 = "O";
							x = 1;
							break;
						}
					case 27:
						if(I9.empty()){
							I9 = "O";
							x = 1;
							break;
						}
				}
		}
	x = 0;
}
int Winner(){
	if((A1 == "X" || A1 == "O")&& A1 == A2 && A2 == A3 && z1 != 1){
		if(A1 == "O"){
		JamesScore++;
		z1 = 1;
		}	
	}
	if((B1 == "X" || B1 == "O") && B1 == B2 && B2 == B3&& z2 != 1){
		if(B1 == "O"){	
		JamesScore++;
		z2 = 1;
		}		 
	}
	if((C1 == "X" || C1 == "O")&& C1 == C2 && C2 == C3 && z3 != 1){
		if(C1 == "O"){
		JamesScore++;
		z3 = 1;
		}
	}
	if((A1 == "X" || A1 == "O") && B2 == A1 && C3 == B2 && z4 != 1){
		if(A1 == "O"){
		JamesScore++;
		z4 = 1;
		}
	}
	if((C1 == "X" || C1 == "O")&& B2 == C1 && A3 == B2&& z5 != 1){
		if(C1 == "O"){
		JamesScore++;
		z5 = 1;
		}
	}
	if((A1 == "X" || A1 == "O")&& B1 == A1 && C1 == B1 && z6 != 1){
		if(A1 == "O"){
		JamesScore++;
		z6 = 1;
		}
	}
	if((A2 == "X" || A2 == "O")&& B2 == A2 && C2 == B2 && z7 != 1){
		if(A2 == "O"){
		JamesScore++;
		z7 = 1;
		}
	}
	if((A3 == "X" || A3 == "O")&& B3 == A3 && C3 == B3 && z8 != 1){
		if(A3 == "O"){
		JamesScore++;
		z8 = 1;
		}
	}
	if((A1 == "X" || A1 == "O")&&A1 == D4 && D4 == G7 && z9 != 1){
		if(A1 == "O"){
		JamesScore++;
		z9 = 1;
		}	 
	}
	if((A2 == "X" || A2 == "O")&&A2 == D5 && D5 == G8&& z10 != 1){
		if(A2 == "O"){
		JamesScore++;
		z10 = 1;
		}
	}
	if((A3 == "X" || A3 == "O")&& A3 == D6 && D6 == G9&& z11 != 1){
		if(A3 == "O"){
		JamesScore++;
		z11 = 1;
		}	 
	}
	if((B1 == "X" || B1 == "O")&& B1 == E4 && E4 == H7&& z12 != 1){
		if(B1 == "O"){
		JamesScore++;
		z12 = 1;
		}
	}
	if((B2 == "X" || B2 == "O")&& B2 == E5 && E5 == H8&& z13 != 1){
		if(B2 == "O"){
		JamesScore++;
		z13 = 1;
		}
	}
	if((B3 == "X" || B3 == "O")&& B3 == E6 && E6 == H9 && z14 != 1){
		if(B3 == "O"){
		JamesScore++;
		z14 = 1;
		}
	}
	if((C1 == "X" || C1 == "O")&& C1 == F4 && F4 == I7 && z15 != 1){
		if(C1 == "O"){
		JamesScore++;
		z15 = 1;
		}
	}
	if((C2 == "X" || C2 == "O")&& C2 == F5 && F5 == I8 && z16 != 1){
		if(C2 == "O"){
		JamesScore++;
		z16 = 1;
		}
	}
	if((C3 == "X" || C3 == "O")&& C3 == F6 && F6 == I9 && z17 != 1){
		if(C3 == "O"){
		JamesScore++;
		z17 = 1;
		}
	}
	if((A1 == "X" || A1 == "O")&& A1 == D5 && D5 == G9 && z18 != 1){
		if(A1 == "O"){
		JamesScore++;
		z18 = 1;
		}
	}
	if((D4 == "X" || D4 == "O")&&D4 == D5 && D5 == D6 && z19 != 1){
		if(D4 == "O"){
		JamesScore++;
		z19 = 1;
		}
	}
	if((E4 == "X" || E4 == "O")&&E4 == E5 && E5 == E6 && z20 != 1){
		if(E4 == "O"){
		JamesScore++;
		z20 = 1;
		}
	}
	if((F4 == "X" || F4 == "O")&&F4 == F5 && F5 == F6 && z21 != 1){
		if(F4 == "O"){
		JamesScore++;
		z21 = 1;
		}
	}
	if((D4 == "X" || D4 == "O")&&D4 == E4 && E4 == F4 && z22 != 1){
		if(D4 == "O"){
		JamesScore++;
		z22 = 1;
		}
	}
	if((D5 == "X" || D5 == "O")&&D5 == E5 && E5 == F5 && z23 != 1){
		if(D5 == "O"){
		JamesScore++;
		z23 = 1;
		}
	}
	if((D6 == "X" || D6 == "O")&&D6 == E6 && E6 == F6 && z24 != 1){
		if(D6 == "O"){
		JamesScore++;
		z24 = 1;
		}
	}
	if((G7 == "X" || G7 == "O")&&G7 == H7 && H7 == I7 && z25 != 1){
		if(G7 == "O"){
		JamesScore++;
		z25 = 1;
		}
	}
	if((G8 == "X" || G8 == "O")&&G8 == H8 && H8 == I8 && z26 != 1){
		if(G8 == "O"){
		JamesScore++;
		z26 = 1;
		}
	}
	if((G9 == "X" || G9 == "O")&&G9 == H9 && H9 == I9 && z27 != 1){
		if(G9 == "O"){
		JamesScore++;
		z27 = 1;
		}
	}
	if((G7 == "X" || G7 == "O")&&G7 == G8 && G8 == G9 && z28 != 1){
		if(G7 == "O"){
		JamesScore++;
		z28 = 1;
		}
	}
	if((H7 == "X" || H7 == "O")&&H7 == H8 && H8 == H9 && z29 != 1){
		if(H7 == "O"){
		JamesScore++;
		z29 = 1;
		}
	}
	if((I7 == "X" || I7 == "O")&&I7 == I8 && I8 == I9 && z30 != 1){
		if(I7 == "O"){
		JamesScore++;
		z30 = 1;
		}
	}
	if((C1 == "X" || C1 == "O")&&C1 == E4 && E4 == G7 && z31 != 1){
		if(C1 == "O"){
		JamesScore++;
		z31 = 1;
		}
	}
	if((D6 == "X" || D6 == "O")&&D6 == E5 && E5 == F4 && z32 != 1){
		if(D6 == "O"){
		JamesScore++;
		z32 = 1;
		}
	}
	if((A3 == "X" || A3 == "O")&&A3 == D5 && D5 == G7 && z33 != 1){
		if(A3 == "O"){
		JamesScore++;
		z33 = 1;
		}
	}
	if((A3 == "X" || A3 == "O")&&A3 == E6 && E6 == I9 && z34 != 1){
		if(A3 == "O"){
		JamesScore++;
		z34 = 1;
		}
	}
	if((C3 == "X" || C3 == "O")&&C3 == E6 && E6 == G9 && z35 != 1){
		if(A3 == "O"){
		JamesScore++;
		z35 = 1;
		}
	}	
	if((C3 == "X" || C3 == "O")&&C3 == F5 && F5 == I7 && z36 != 1){
		if(C3 == "O"){
		JamesScore++;
		z36 = 1;
		}
	}
	if((C1 == "X" || C1 == "O")&&C1 == F5 && F5 == I9 && z37 != 1){
		if(C1 == "O"){
		JamesScore++;
		z37 = 1;
		}
	}
	if((A1 == "X" || A1 == "O")&&A1 == E5 && E5 == I9 && z38 != 1){
		if(A1 == "O"){
		JamesScore++;
		z38 = 1;
		}
	}
	if((A3 == "X" || A3 == "O")&&A3 == E5 && E5 == I7 && z39 != 1){
		if(A3 == "O"){
		JamesScore++;
		z39 = 1;
		}
	}
	if((C1 == "X" || C1 == "O")&&C1 == E5 && E5 == G9 && z40 != 1){
		if(C1 == "O"){
		JamesScore++;
		z40 = 1;
		}
	}
	if((C3 == "X" || C3 == "O")&&C3 == E5 && E5 == G7 && z41 != 1){
		if(C3 == "O"){
		JamesScore++;
		z41 = 1;
		}
	}
	if((D4 == "X" || D4 == "O")&&D4 == E5 && E5 == F6 && z42 != 1){
		if(D4 == "O"){
		JamesScore++;
		z42 = 1;
		}
	}
	if((G7 == "X" || G7 == "O")&&G7 == H8 && H8 == I9 && z43 != 1){
		if(G7 == "O"){
		JamesScore++;
		z43 = 1;
		}
	}
	if((A1 == "X" || A1 == "O")&&A1 == E4 && E4 == I7 && z44 != 1){
		if(A1 == "O"){
		JamesScore++;
		z44 = 1;
		}
	}
	if((G9 == "X" || G9 == "O")&&G9 == H8 && H8 == I7 && z45 != 1){
		if(G9 == "O"){
		JamesScore++;
		z45 = 1;
		}
	}
	if((A2 == "X" || A2 == "O")&&A2 == E5 && E5 == I8 && z46 != 1){
		if(A2 == "O"){
		JamesScore++;
		z46 = 1;
		}
	}
	if((B1 == "X" || B1 == "O")&&B1 == E5 && E5 == H9 && z47 != 1){
		if(B1 == "O"){
		JamesScore++;
		z47 = 1;
		}
	}
	if((C3 == "X" || C3 == "O")&&C3 == E5 && E5 == H7 && z48 != 1){
		if(C3 == "O"){
		JamesScore++;
		z48 = 1;
		}
	}
	if((A2 == "X" || A2 == "O")&&A2 == E5 && E5 == I8 && z49 != 1){
		if(A2 == "O"){
		JamesScore++;
		z49 = 1;
		}
	}
}
};
int main(){
	int JamesWin,NickWin;int JamesScore = 0; int NickScore = 0;
	int P1,Play,GameNumber = 1;
	string answer;
	James Jam;
	cout<<"Welcome to Tic-Tac-Toe"<<endl;
	cout<<"Would you like to play a tournament? Y/N"<<endl;
	cin>>answer;
while(answer != "N" || answer != "n"){
	while(GameNumber != 10){
		srand((unsigned)time(0));
		P1 = (rand() % 2);
		cout<<"Game "<<GameNumber<<" being played."<<endl;
	while (Play != 27){
		if(P1 == 0||P1 == 2||P1 == 4||P1 == 6||P1 == 8||P1 == 10||P1 == 12||P1 ==14||P1 ==16||P1 ==18||P1 ==20||P1 ==22||P1 ==24||P1 ==26||P1 ==28)
		{
			cout<<"Nick's Turn"<<endl;
			//Nick AI
		}
		if(P1 == 1||P1 == 3||P1 == 5||P1 == 7||P1 == 9||P1 == 11||P1 ==13||P1 ==15||P1 ==17||P1 ==19||P1 ==21||P1 ==23||P1 ==25||P1 ==27||P1 ==29)
		{
			cout<<"James' Turn"<<endl;
			Jam.computer();
		}
		Jam.Winner();
		P1++;
		Play++;
		}
		cout<<"Game Over"<<endl;
		if(JamesScore > NickScore){
			cout<<"James wins game "<<GameNumber<<endl;
			JamesWin++;
		}
		if(NickScore > JamesScore){
			cout<<"Nick wins game "<<GameNumber<<endl;
			NickWin++;
		}
		GameNumber++;	
	}
	cout<<"Tournament finished"<<endl;
	if(NickWin > JamesWin){cout<<"Nick wins the tournament "<<NickWin<<"to "<<JamesWin<<endl;}
	if(JamesWin > NickWin){cout<<"James wins the tournament "<<JamesWin<<"to "<<NickWin<<endl;}
}
return 0;
}

