#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
using namespace std;


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};


int choice;
int row,column;
char turn = 'X';
bool draw = false;

void colorized(int i)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, i);
}

void display_board()
{



    cout<<"\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<<board[0][0]<<"   |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<<board[1][0]<<"   |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<<board[2][0]<<"   |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}



void player_turn()
{
    if(turn == 'X')
    {
        cout<<"\n\tPlayer 1(X) turn : ";
    }
    else if(turn == 'O')
    {
        cout<<"\n\tPlayer 2(O) turn : ";
    }


    cin >> choice;
     colorized(12);


    switch(choice)
    {
    case 1:
        row=0;
        column=0;
        break;
    case 2:
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;
        break;
    case 4:
        row=1;
        column=0;
        break;
    case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
    case 7:
        row=2;
        column=0;
        break;
    case 8:
        row=2;
        column=1;
        break;
    case 9:
        row=2;
        column=2;
        break;
    default:
        cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {

        board[row][column] = 'X';
        turn = 'O';
        colorized(12);
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {

        board[row][column] = 'O';
        turn = 'X';
        colorized(11);
    }
    else
    {

        cout<<"Box already filled!\n Please choose another!!\n\n";
        player_turn();
    }


}



bool gameover()
{

    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;



    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;


    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;


    draw = true;
    return false;
}



int main()
{
    cout<<"\tWelcom to Tick Tac Toe game!!!!!\t\t\t";
    cout<<"PLAYER 1(x) & PLAYER 2(o) \n\n";
    while(gameover())
    {
        display_board();
        player_turn();
        gameover();
    }



                if(turn == 'O' && draw == false  )
                {
                    cout<<"\n\nCongratulations!Player with 'X' has won the game\n\n";

                }
                else if(turn == 'X' && draw == false)
                {
                    cout<<"\n\nCongratulations!Player with 'O' has won the game\n\n";

                }
                else
                    cout<<"\n\nGAME DRAW!!!\n\n";


}
