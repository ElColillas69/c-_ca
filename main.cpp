#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include "board.h"
#include <filesystem>


int main() {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    std::string absoluteFilePath = "../bugs.txt";

    Board board;
    board.initializeBoardFromFile(absoluteFilePath);

    std::vector<Bug*> bugVector = board.getBugVector();
    for (const Bug* bug : bugVector) {
        std::cout << "Bug ID: " << bug->getId() << ", Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << std::endl;
    }

    for (Bug* bug : bugVector) {
        std::cout << bug->getId() << " " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper") << " "
                  << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") "
                  << bug->getSize() << " " << static_cast<int>(bug->getDirection()) << " "
                  << (dynamic_cast<Hopper*>(bug) ? dynamic_cast<Hopper*>(bug)->getHopLength() : 0) << " "
                  << (bug->isAlive() ? "Alive" : "Dead") << std::endl;
    }

    for (Bug* bug : bugVector) {
        bug->move();
    }

    int bugId;
    std::cout << "Enter bug ID to find: ";
    std::cin >> bugId;
    board.displayBugDetails(bugId);

    for (Bug* bug : bugVector) {
        delete bug;
    }

    return 0;
}
