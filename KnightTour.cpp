//
// Created by Jakub Jirák on 11/03/2020.
//

#include "KnightTour.h"
#include <iostream>
#include <iomanip>

using std::cout;

const std::array<int, 8> KnightTour::xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
const std::array<int, 8> KnightTour::yMoves = {1, 2, 2, 1, -1, -2, -2, -1};

KnightTour::KnightTour() {
    solutionMatrix.resize(BOARD_SIZE);
    for (auto &subMatrix: solutionMatrix) {
        subMatrix.resize(BOARD_SIZE);
    }

    boardInit();
}

void KnightTour::solveKnightTourProblem() {
    solutionMatrix[0][0] = 0;
    if (!solveProblem(1, 0, 0)) {
        cout << "Sorry, but no feasible solution found...";
        return;
    }

    showSolution();
}

bool KnightTour::solveProblem(int stepCount, int x, int y) {
    if (stepCount == BOARD_SIZE * BOARD_SIZE) {
        return true;
    }

    for (size_t i = 0; i < xMoves.size(); ++i) {
        int nextX = x + xMoves[i];
        int nextY = y + yMoves[i];

        if (isValidMove(nextX, nextY)) {
            solutionMatrix[nextX][nextY] = stepCount;
            if (solveProblem(stepCount + 1, nextX, nextY)) {
                return true;
            }
            solutionMatrix[nextX][nextY] = INT_MIN;
        }
    }
    return false;
}

bool KnightTour::isValidMove(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE)
        return false;
    if (y < 0 || y >= BOARD_SIZE)
        return false;
    if (solutionMatrix[x][y] != INT_MIN)
        return false;

    return true;
}

void KnightTour::showSolution() {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        cout << std::left;

        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            cout << std::setw(2) << solutionMatrix[i][j] << std::setw(2) << ' ';
        }
        cout << "\n";
    }
}

void KnightTour::boardInit() {
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            solutionMatrix[i][j] = INT_MIN;
        }
    }
}