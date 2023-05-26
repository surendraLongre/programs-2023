#include<bits/stdc++.h>
using namespace std;

bool gamePlay=true;

class TicTacToe {
	char arr[3][3]={
		{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}
	};

	string current_player{};
	string player1{}, player2{};
	int value{};

	public:
	TicTacToe(){
		getName(player1, 1);
		getName(player2, 2);
		current_player=player1;
		cout<<endl;
		drawGame();
	};
	void drawGame() {
		for(int i=0; i!=3; i++) {
			for(int j=0; j!=3; j++) {
				if(arr[i][j]=='X')
					cout<<" "<<"\033[31m"<<arr[i][j]<<"\033[0m"<<" ";
				else if(arr[i][j]=='O') 
					cout<<" "<<"\033[34m"<<arr[i][j]<<"\033[0m"<<" ";
				else
					cout<<" "<<arr[i][j]<<" ";
				if(j!=2) cout<<"|";
			}		
			if(i!=2){
				cout<<endl;
				for(int k=0; k!=9; k++) cout<<"-"; cout<<"--"<<endl;
			}
		}
		cout<<endl;
	}

	void getName(string &player, int player_num) {
name1:
		cout<<"Enter player "<<player_num<<"  name: ";
		getline(cin, player);
		if(player1=="" || !isalpha(player1[0])) goto name1;
	}

	void getInput() {
		system("clear");
		drawGame();
input:
		cout<<current_player<<", please enter the value: ";
		cin>>value;
		if(cin.fail()) {
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout<<"bad entry, please enter a \"number\"\n";
			goto input;
		}
		if(value<0 || value>9 || isalpha(value)) goto input;
		int i{}, j{};
		if(value%3!=0) {
			i=value/3;
			j=value%3-1;
		}
		else {
			i=value/3-1;
			j=2;
		}
		if(int(arr[i][j])!=32){
			cout<<"This value is already taken, please enter a valid value\n";
			goto input;
		}	
		arr[i][j]=(current_player==player1?'X':'O');
		drawGame();
		whoWon();
		current_player=current_player==player1?player2:player1;
	}

	void whoWon() {
		for(int i=0; i!=3; i++) {
			if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][2]!=32) gameEnd();
			if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[2][i]!=32) gameEnd();
		}
		if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[2][2]!=32) gameEnd();
		if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[2][0]!=32) gameEnd();
	}

	void gameEnd() {
		cout<<"______________Congratulations "<<current_player<<" won! ______________________________"<<endl;
		gamePlay=false;
	}	
};

int main() 
{
	int i=9;
	TicTacToe game1;
	while(i-- && gamePlay)  
		game1.getInput();
	if(gamePlay) cout<<"__________________Draw_________________________"<<endl;
}
