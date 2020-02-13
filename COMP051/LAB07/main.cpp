#include <iostream>

using namespace std;

//#2
void printBoard(char board[][3]) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << board[row][column] << " ";
        }
        cout << endl;
    }
}

//#3
bool isFilled(char board[][3], int row, int column) {
    return (board[row][column] != 'e');
}

//#4
void move(char board[][3], char player) {
    int rowCheck, columnCheck;
    cout << "Player " << player << ": please enter the coordinates of your move <row col>: ";
    cin >> rowCheck; //TODO add error cases
    cin >> columnCheck;


    while (isFilled(board, rowCheck, columnCheck) ||
            (rowCheck > 2 || rowCheck < 0) ||
            (columnCheck > 2 || columnCheck < 0)) {
        if (rowCheck > 2 || rowCheck < 0 || columnCheck > 2 || columnCheck < 0) {
            cout << "ERROR: Invalid coordinate <" << rowCheck << " " << columnCheck << ">. Please fill an empty spot." << endl;
        } else if (isFilled(board, rowCheck, columnCheck))
            cout << "ERROR: That spot is filled. Please fill an empty spot." << endl;
        cin >> rowCheck;
        cin >> columnCheck;
    }

    board[rowCheck][columnCheck] = player;

    printBoard(board);
}

bool isBoardFilled(char board[][3]) {
    bool isBoardFilled = true;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!isFilled(board, x, y))
                isBoardFilled = false;
        }
    }
    return isBoardFilled;
}

//#6
bool isGameOver(char board[][3], bool &win) {
    for (int x = 0; x < 3; x++) {
        if (board[x][0] != 'e' && board[x][0] == board[x][1] && board[x][1] == board[x][2]) {
            win = true;
            return true;
        }
    }
    for (int y = 0; y < 3; y++) {
        if (board[0][y] != 'e' && board[0][y] == board[1][y] && board[1][y] == board[2][y]) {
            win = true;
            return true;
        }
    }
    if (isBoardFilled(board))
        return true;

    if  ((board[0][0] != 'e' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
           || (board[0][2] != 'e' && board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        win = true;
        return true;
    }
    return false;
}

int main() {

    //#1
    char board[3][3];

    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            board[row][column] = 'e';
        }
    }

    bool isPlayerOnesMove = true;
    bool gameOver = false;
    bool winOrTie = false;

    while (!gameOver) {
        if (isPlayerOnesMove) {
            move(board, 'X');
            isPlayerOnesMove = false;
        } else {
            move(board, 'O');
            isPlayerOnesMove = true;
        }
        gameOver = isGameOver(board, winOrTie);
    }

    char winner;
    if (isPlayerOnesMove)
        winner = 'O';
    else
        winner = 'X';

    if (isBoardFilled(board) && !winOrTie)
        cout << "Andrew wins, Jeremy loses!" << endl;
    else
        cout << "Player " << winner << " has won!" << endl;
    system("PAUSE");

    return 0;
}