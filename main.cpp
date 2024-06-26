
#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"

int main() {
    Board board;

    board.initializeBoardFromFile("../bugs.txt");

    while (true) {
        std::cout
                << "Please enter an option (1: Display bug, 2: Display life history, 3: Move bug, 4: Kill bug, 5: Display board, 6: Tap board, 7: Write life history to file, 0: Exit): ";
        int option;
        std::cin >> option;

        if (option == 0) {
            break;
        } else if (option == 1) {
            std::cout << "Please enter the ID of bug: ";
            int bugId;
            std::cin >> bugId;
            board.displayBugDetails(bugId);
        } else if (option == 2) {
            board.displayLifeHistory();
        } else if (option == 3) {
            std::cout << "Please enter the ID of the bug you want to move: ";
            int bugId;
            std::cin >> bugId;
            board.moveBug(bugId);
        } else if (option == 4) {
            std::cout << "Please enter the ID of the bug you want to kill: ";
            int bugId;
            std::cin >> bugId;
            board.killBug(bugId);
        } else if (option == 5) {
            board.displayBoard();
        } else if (option == 6) {
            board.tapBoard();
        } else if (option == 7) {
            board.writeLifeHistoryToFile();
        }
    }
}