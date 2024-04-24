#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include "board.h"

int main() {
    Board board;
    board.initializeBoardFromFile("bugs.txt");
    std::vector<Bug*> bug_vector = board.getBugVector();

    for (Bug* bug : bug_vector) {
        std::cout << bug->getId() << " " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper") << " "
                  << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") "
                  << bug->getSize() << " " << static_cast<int>(bug->getDirection()) << " "
                  << (dynamic_cast<Hopper*>(bug) ? dynamic_cast<Hopper*>(bug)->getHopLength() : 0) << " "
                  << (bug->isAlive() ? "Alive" : "Dead") << std::endl;
    }

    for (Bug* bug : bug_vector) {
        bug->move();
    }
    for (Bug* bug : bug_vector) {
        delete bug;
    }
    return 0;
}



