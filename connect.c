#include <stdio.h>
#define ROWS 6
#define COLUMNS 7

void initializeGrid(char grid[ROWS][COLUMNS]);
void printGrid(char grid[ROWS][COLUMNS]);
int TokenNumber();
void makeMove(char grid[ROWS][COLUMNS], int column, char player);
int checkVerticalWin(char grid[ROWS][COLUMNS], char player, int token);
int checkHorizontalWin(char grid[ROWS][COLUMNS], char player, int token);
int checkDiagonalWin(char grid[ROWS][COLUMNS], char player, int token);

int main(){
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {
        int token = TokenNumber();
        char grid[ROWS][COLUMNS];
        initializeGrid(grid);
        printGrid(grid);

        char currentPlayer = 'R';
        int column;
        int totalMoves = 0;

        for (int move = 1; move <= ROWS * COLUMNS; move++) {
            printf("Player %c, pick a column (1-7): \n", currentPlayer);
            scanf("%d", &column);

            if (column-1 >=0  && column-1 < COLUMNS) {
                makeMove(grid, column-1, currentPlayer);
                printGrid(grid);

                int x = checkVerticalWin(grid, currentPlayer, token);
                int y = checkHorizontalWin(grid, currentPlayer, token);
                int z = checkDiagonalWin(grid, currentPlayer, token);

                if (x == 1 || y == 1 || z == 1) {
                    printf("%c has won the game\n", currentPlayer);
                    break;
                }

                totalMoves++;

                if (totalMoves == ROWS * COLUMNS) {
                    printf("The game is a draw!\n");
                    break;
                }

                currentPlayer = (currentPlayer == 'R') ? 'Y' : 'R';
            } else {
                printf("Invalid column. Please enter a valid column (1-7).\n");
            }
        }

        printf("Game over. Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

        if (playAgain == 'Y' || playAgain == 'y') {
            printf("Starting a new game...\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}

void printGrid(char grid[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int TokenNumber(){
    int token;
    printf("Enter the tokens needed for a win: \n");
    scanf("%d",&token);
    return token;
}

void initializeGrid(char grid[ROWS][COLUMNS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void makeMove(char grid[ROWS][COLUMNS], int column, char player) {
    if (column >= 0 && column < COLUMNS) {
        for (int row = ROWS - 1; row >= 0; row--) {
            if (grid[row][column] == ' ') {
                grid[row][column] = player;
                return;
            }
        }
    }
}
int checkHorizontalWin(char grid[ROWS][COLUMNS], char player, int tokensToWin) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLUMNS - tokensToWin; j++) {
            int count = 0;
            for (int k = 0; k < tokensToWin; k++) {
                if (grid[i][j + k] == player) {
                    count++;
                } else {
                    count = 0;
                }
            }
            if (count >= tokensToWin) {
                return 1;
            }
        }
    }
    return 0;
}

int checkVerticalWin(char grid[ROWS][COLUMNS], char player, int tokensToWin) {
    for (int i = 0; i <= ROWS - tokensToWin; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int count = 0;
            for (int k = 0; k < tokensToWin; k++) {
                if (grid[i + k][j] == player) {
                    count++;
                } else {
                    count = 0;
                }
            }
            if (count >= tokensToWin) {
                return 1;
            }
        }
    }
    return 0;
}

int checkDiagonalWin(char grid[ROWS][COLUMNS], char player, int tokensToWin) {
    for (int i = 0; i <= ROWS - tokensToWin; i++) {
        for (int j = 0; j <= COLUMNS - tokensToWin; j++) {
            int count = 0;
            for (int k = 0; k < tokensToWin; k++) {
                if (grid[i + k][j + k] == player) {
                    count++;
                } else {
                    count = 0;
                }
            }
            if (count >= tokensToWin) {
                return 1;
            }
        }
    }

    for (int i = 0; i <= ROWS - tokensToWin; i++) {
        for (int j = COLUMNS - 1; j >= tokensToWin - 1; j--) {
            int count = 0;
            for (int k = 0; k < tokensToWin; k++) {
                if (grid[i + k][j - k] == player) {
                    count++;
                } else {
                    count = 0;
                }
            }
            if (count >= tokensToWin) {
                return 1;
            }
        }
    }

    return 0;
}
