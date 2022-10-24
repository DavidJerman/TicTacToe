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

bool chooseAndCheckCell(int gameBoard[3][3], char cell, int player) {
    int i = (cell - 1) / 3;
    int j = (cell - 1) % 3;
    if (gameBoard[i][j]) return false;
    else gameBoard[i][j] = player;
    return true;
}

void chooseCell(int gameBoard[3][3], int player) {
    std::cout << "Choose a cell for "
              << (player == 1 ? "X" : "O")
              << "!\n"
              << "[1-9]"
              << std::endl;
    char in;

    while (std::cin >> in) {
        if (chooseAndCheckCell(gameBoard, in - 48, player))
            return;
        std::cout << "Invalid cell!" << std::endl;
    }
}

void printGameBoard(int gameBoard[3][3]) {
    std::cout << "==============================" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << (gameBoard[i][j] == 2 ? "O" : (gameBoard[i][j] == 1 ? "X" : "*"))
                      << " ";
        }
        std::cout << std::endl;
    }
}

// -1 / game over
//  0 / game still in progress
//  1 / X won
//  2 / O won
bool checkIsFull(int gameBoard[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (gameBoard[i][j] == 0)
                return false;
    return true;
}

int checkRows(int gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] &&
            gameBoard[i][1] == gameBoard[i][2] &&
            gameBoard[i][2] != 0)
            return gameBoard[i][0];
    }
    return 0;
}

int checkColumns(int gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[0][i] == gameBoard[1][i] &&
            gameBoard[1][i] == gameBoard[2][i] &&
            gameBoard[2][i] != 0)
            return gameBoard[0][i];
    }
    return 0;
}

int checkDiagonals(int gameBoard[3][3]) {
    if (gameBoard[0][0] == gameBoard[1][1] &&
        gameBoard[1][1] == gameBoard[2][2] &&
        gameBoard[2][2] != 0)
        return gameBoard[0][0];
    if (gameBoard[0][2] == gameBoard[1][1] &&
        gameBoard[1][1] == gameBoard[2][0] &&
        gameBoard[2][0] != 0)
        return gameBoard[0][2];
    return 0;
}

int checkGameState(int gameBoard[3][3]) {
    auto winner = checkRows(gameBoard);
    if (winner > 0)
        return winner;
    winner = checkColumns(gameBoard);
    if (winner > 0)
        return winner;
    winner = checkDiagonals(gameBoard);
    if (winner > 0)
        return winner;
    if (checkIsFull(gameBoard)) return -1;
    return 0;
}

void resetGameBoard(int gameBoard[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            gameBoard[i][j] = 0;
}

void playNewGame(int gameBoard[3][3]) {
    int player = 1;

    resetGameBoard(gameBoard);

    while (true) {
        printGameBoard(gameBoard);
        chooseCell(gameBoard, player);
        if (player == 1) player = 2;
        else player = 1;
        auto res = checkGameState(gameBoard);
        if (res == -1) {
            std::cout << "Game Over! No winner!" << std::endl;
            return;
        }
        if (res == 0) continue;
        printWinner(res);
        return;
    }
}

int main() {
    char in;
    int gameBoard[3][3]{{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};

    greetUser();
    printMainMenu();

    // Main game loop
    while (std::cin >> in) {
        switch (in) {
            case '1':
                playNewGame(gameBoard);
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
