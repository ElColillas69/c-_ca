//
// Created by adria on 4/24/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "bug.h"
#include <iostream>
#include <fstream>

class Board {
private:
    std::vector<Bug*> bugVector;

public:
    Board();
    ~Board();

    void initializeBoardFromFile(const std::string& filename);
    std::vector<Bug*> getBugVector() const;
    void displayBugDetails(int bugId) const;
};

#endif // BOARD_H
