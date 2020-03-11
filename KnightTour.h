//
// Created by Jakub Jirák on 11/03/2020.
//

#ifndef KNIGHTTOURPROBLEM_KNIGHTTOUR_H
#define KNIGHTTOURPROBLEM_KNIGHTTOUR_H
#pragma once

#include <vector>
#include <array>

using std::vector;

class KnightTour {
    //Step counter
    vector<vector<int>> solutionMatrix;
    //horizontal moves
    const static std::array<int, 8> xMoves;
    //vertical moves
    const static std::array<int, 8> yMoves;
    constexpr static int BOARD_SIZE = 8;

public:
    KnightTour();

    void solveKnightTourProblem();

    bool solveProblem(int stepCount, int x, int y);

    bool isValidMove(int x, int y);

    void showSolution();

private:
    void boardInit();
};


#endif //KNIGHTTOURPROBLEM_KNIGHTTOUR_H
