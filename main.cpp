#include <iostream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include "board.h"

int main() {
    std::vector<Bug*> bug_vector;
    Board board;
    board.initializeBoardFromFile("bugs.txt");

    bug_vector = board.getBugVector();

    for (Bug* bug : bug_vector) {
        bug->move();
    }
    for (Bug* bug : bug_vector) {
        delete bug;
    }
    return 0;
}


