#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include "board.h"
#include <filesystem>


int main() {
    // Print the current working directory
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Construct the absolute file path
    std::string absoluteFilePath = "C:/Users/adria/CLionProjects/C++_CA/bugs.txt";

    // Create a board and initialize it from the file
    Board board;
    board.initializeBoardFromFile(absoluteFilePath);

    std::vector<Bug*> bug_vector = board.getBugVector();
    for (const Bug* bug : bug_vector) {
        std::cout << "Bug ID: " << bug->getId() << ", Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << std::endl;
    }

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

    int bugId;
    std::cout << "Enter bug ID to find: ";
    std::cin >> bugId;
    board.displayBugDetails(bugId);

    for (Bug* bug : bug_vector) {
        delete bug;
    }

    return 0;
}
