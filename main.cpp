#include <iostream>

void greetUser() {
    std::cout << "Welcome to the Tic-Tac-Toe game!" << std::endl;
}

void printMainMenu() {
    std::cout << "=============================="
              << "1) New game\n"
              << "2) About the game\n"
              << "3) Exit"
              << "=============================="
              << std::endl;
}

int main() {
    char in;

    greetUser();
    printMainMenu();

    // Main game loop
    while (std::cin >> in) {


        printMainMenu();
    }
    return 0;
}
