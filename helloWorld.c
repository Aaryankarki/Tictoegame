#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("%c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces() {
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove() {
    int x, y;
    do {
        printf("Enter the row (1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter the column (1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ') {
            printf("Invalid move! Try again.\n");
        } else {
            board[x][y] = PLAYER;
            break;
        }
    } while (1);
}

void computerMove() {
    srand(time(0));
    int x, y;
    
    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("You Win!\n");
    } else if (winner == COMPUTER) {
        printf("You Lose!\n");
    } else {
        printf("It's a Tie!\n");
    }
}

int main() {
    char winner = ' ';
    resetBoard();
    printBoard();

    while (winner == ' ' && checkFreeSpaces() != 0) {
        playerMove();
        computerMove();
        printBoard();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
    }

    printWinner(winner);
    return 0;
}
