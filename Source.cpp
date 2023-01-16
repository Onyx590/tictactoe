#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

char board[ROWS][COLS] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

void drawBoard()
{
    cout << "Tic Tac Toe Game" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void playerMove(char player)
{
    int move;
    cout << "Player " << player << ", enter a number: ";
    cin >> move;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == move + '0')
            {
                board[i][j] = player;
            }
        }
    }
}

char checkWin()
{
    //check rows
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    //check columns
    for (int i = 0; i < COLS; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    return '/';
}

int main()
{
    drawBoard();
    while (true)
    {
        playerMove('X');
        drawBoard();
        if (checkWin() == 'X')
        {
            cout << "X wins!" << endl;
            break;
        }

        playerMove('O');
        drawBoard();
        if (checkWin() == 'O')
        {
            cout << "O wins!" << endl;
            break;
        }
    }
    return 0;
}
