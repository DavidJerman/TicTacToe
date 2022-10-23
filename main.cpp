#include <iostream>

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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
