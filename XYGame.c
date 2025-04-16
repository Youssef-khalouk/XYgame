# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <conio.h>
# include <ctype.h>

char board[3][3];
void clearBoard(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j]= ' ';
		}
	}
}
void printBoard(){
	printf("\n\n\t\t %c  | %c  | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("\t\t ---|----|---\n");
	printf("\t\t %c  | %c  | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("\t\t ---|----|---\n");
	printf("\t\t %c  | %c  | %c \n\n", board[2][0], board[2][1], board[2][2]);
}
void userChoose(){
	int x , y;
	int v = 0;
	while(v==0){
		while(v==0){
			fflush(stdin);
			printf("\n Enter your Number of row (1/3):");
			scanf("%d", &x);
			if(x==1||x==2||x==3){
				break;
			}else{
				printf("Invalide Number!!");
			}
		}
		while(v==0){
			fflush(stdin);
			printf("\n Enter your Number of colummen (1/3):");
			scanf("%d", &y);
			if(y==1||y==2||y==3){
				break;
			}else{
				printf("Invalide Number!!");
			}
		}
		if (board[y-1][x-1] == ' '){
			board[y-1][x-1] = 'X';
			break;
		}else{
			printf("The box is choosen allridy!\n");
		}
	}
}
void computerChoose(){
	int x,y;
	int v =0;
	while(v==0){
		x = rand()%3;
		y = rand()%3;
		if (board[y][x]== ' '){
			board[y][x] = 'O';
			break;
		}
	}
}
char cheackWiner(){
	for(int i =0; i<3; i++){
		if (board[i][0]==board[i][1]&&board[i][0]==board[i][2]){
			return board[i][0];
		}else if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]){
			return board[0][i];
		}
	}
	if (board[0][0]==board[1][1]&&board[0][0]==board[2][2]){
		return board[0][0];
	}else if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]){
		return board[2][0];
	}else{
		return ' ';
	}
}
int freeSpaces(){
	int x=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]== ' '){
				x++;
			}
		}
	}
	return x;
}
void startGame(){
	clearBoard();
	printBoard();
	int freeS =9;
	int x =1;
	char winner;
	while (x==1){
		userChoose();
		printBoard();
		winner = cheackWiner();
		freeS = freeSpaces();
		if (winner == 'X'){
			printf("You win !\n");
			break;
		}else if(winner == 'O'){
			printf("You lose the game !\n");
			break;
		}else if(freeS == 0){
			printf("No one win!  Game Over!\n");
			break;
		}		
		computerChoose();
		printBoard();
		winner = cheackWiner();
		freeS = freeSpaces();
		if (winner == 'X'){
			printf("You win !\n");
			break;
		}else if(winner == 'O'){
			printf("You lose the game !\n");
			break;
		}else if(freeS == 0){
			printf("No one win!  Game Over!\n");
			break;
		}
	}
	fflush(stdin);
	char response;
	printf("\nWould you like to play again? (Y/N): ");
	scanf(" %c", &response);
	if (response=='y'|| response=='Y'){
		startGame();
	}
}
int main(){
	srand(time(0));
	printf("Welcom to the game :)");
	startGame();
	printf("thanks for playing :)");
	return 0;
}