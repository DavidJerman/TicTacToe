#include <iostream>

void greetUser() {
    std::cout << "Welcome to the Tic-Tac-Toe game!" << std::endl;
}

void printMainMenu() {
    std::cout << "==============================\n"
              << "1) New game\n"
              << "2) About the game\n"
              << "3) Exit\n"
              << "=============================="
              << std::endl;
}

void printAbout() {
    std::cout << "==============================\n"
              << "Tic-Tac-Toe\n"
              << "Version: 2022.10.22\n"
              << "=============================="
              << std::endl;
}

void printWinner(int player) {
    std::cout << "Player "
              << (player == 1 ? "X" : "O")
              << " has won!"
              << std::endl;
}

void printInputErrorMessage() {
    std::cout << "Wrong input!" << std::endl;
}

bool chooseAndCheckCell(char cell) {

}

void chooseCell(int player) {
    std::cout << "Choose a cell for "
              << (player == 1 ? "X" : "O")
              << "!\n"
              << "[1-9]"
              << std::endl;
    char in;

    while (std::cin >> in) {
        if (chooseAndCheckCell(in))
            return;
    }
}

void playNewGame() {

}

void printGameBoard(int board[3][3]) {
    std::cout << "==============================" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << (board[i][j] == 2 ? "O" : (board[i][j] == 1 ? "X" : " "))
                      << " ";
        }
        std::cout << std::endl;
    }
}

// -1 / game over
//  0 / game still in progress
//  1 / X won
//  2 / O won
bool checkIsFull(int state[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (state[i][j] == 0)
                return false;
    return true;
}

int checkRows(int state[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (state[i][0] == state[i][1] && state[i][2] != 0)
            return state[i][0];
    }
    return 0;
}

int checkColumns(int state[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (state[0][i] == state[1][i] && state[2][i] != 0)
            return state[0][i];
    }
    return 0;
}

int checkDiagonals(int state[3][3]) {
    if (state[0][0] == state[1][1] == state[2][2] != 0)
        return state[0][0];
    if (state[0][2] == state[1][1] == state[2][0] != 0)
        return state[0][2];
    return 0;
}

int checkGameState(int state[3][3]) {
    auto winner = checkRows(state);
    if (winner > 0)
        return winner;
    winner = checkColumns(state);
    if (winner > 0)
        return winner;
    winner = checkDiagonals(state);
    if (winner > 0)
        return winner;
    if (checkIsFull(state)) return -1;
    return 0;
}

void resetGameBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

int main() {
    char in;
    int state[3][3]{{0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}};

    greetUser();
    printMainMenu();

    // Main game loop
    while (std::cin >> in) {
        switch (in) {
            case '1':
                playNewGame();
                break;
            case '2':
                printAbout();
                break;
            case '3':
                exit(0);
            default:
                printInputErrorMessage();
        }
        printMainMenu();
    }
    return 0;
}
