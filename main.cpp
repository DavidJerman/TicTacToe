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
