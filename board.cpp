//
// Created by adria on 4/24/2024.
//
#include "board.h"
#include "bug.h"
#include <fstream>
#include <iostream>
#include "crawler.h"
#include "hopper.h"
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>

class ostrtime;

class ostrtime;

Board::Board() = default;

int remove(std::vector<Bug *>::iterator iterator, std::vector<Bug *>::iterator iterator1, Bug *pBug);

Board::~Board() {
    for (Bug* bug : bugVector) {
        delete bug;
    }
}

void Board::initializeBoardFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::cout << "Opened file: " << filename << std::endl;

    std::stringstream fileContentStream;

    fileContentStream << file.rdbuf();

    file.close();

    std::string fileContent = fileContentStream.str();

    std::cout << "File contents:" << std::endl;
    std::cout << fileContent << std::endl;

    int id, x, y, direction, size;
    int lineNumber = 0;

    std::stringstream ss(fileContent);
    std::string line;
    while (std::getline(ss, line)) {
        std::istringstream iss(line);
        if (!(iss >> id >> x >> y >> direction >> size)) {
            std::cerr << "Error parsing line: " << lineNumber << std::endl;
            continue;
        }

        lineNumber++;
        std::cout << "Line " << lineNumber << ": " << id << " " << x << " " << y << " " << direction << " " << size
                  << std::endl;

        if (direction < 0 || direction >= static_cast<int>(Direction::Count)) {
            std::cerr << "Error: Invalid direction value on line " << lineNumber << std::endl;
            continue;
        }
        auto dir = static_cast<Direction>(direction);
        Bug *bug;
        if (dir == Direction::North || dir == Direction::South) {
            bug = new Crawler(id, std::make_pair(x, y), dir, size);
        } else {
            bug = new Hopper(id, std::make_pair(x, y), dir, size, 3);
        }
        bugVector.push_back(bug);
    }

    std::cout << "Number of bugs read: " << bugVector.size() << std::endl;
    if (bugVector.empty()) {
        std::cout << "No bugs were read from the file." << std::endl;
    } else {
        std::cout << "Bug IDs in bugVector: ";
        for (const auto& bug : bugVector) {
            std::cout << bug->getId() << " ";
        }
        std::cout << std::endl;
    }
}

    std::vector<Bug*> Board::getBugVector() const {
        return bugVector;
    }
    void Board::displayBugDetails(int bugId) const {
        bool found = false;
        std::cout << "Bug IDs in bugVector: ";
        for (const Bug* bug : bugVector) {
            std::cout << bug->getId() << " ";
        }
        std::cout << std::endl;

        for (const Bug* bug : bugVector) {
            if (bug->getId() == bugId) {
                found = true;
                std::cout << "Bug " << bugId << " found. Details:" << std::endl;
                std::cout << "ID: " << bug->getId() << std::endl;
                std::cout << "Type: " << (dynamic_cast<const Crawler*>(bug) ? "Crawler" : "Hopper") << std::endl;
                std::cout << "Location: (" << bug->getPosition().first << "," << bug->getPosition().second << ")" << std::endl;
                std::cout << "Size: " << bug->getSize() << std::endl;
                std::cout << "Direction: " << static_cast<int>(bug->getDirection()) << std::endl;
                if (dynamic_cast<const Hopper*>(bug)) {
                    std::cout << "Hop Length: " << dynamic_cast<const Hopper*>(bug)->getHopLength() << std::endl;
                }
                std::cout << "Status: " << (bug->isAlive() ? "Alive" : "Dead") << std::endl;
                break;
            }
        }
        if (!found) {
            std::cout << "Bug " << bugId << " not found." << std::endl;
        }
    }

void Board::displayLifeHistory() const {
    for (const Bug* bug : bugVector) {
        std::cout << bug->getId() << " ";
        if (dynamic_cast<const Crawler*>(bug)) {
            std::cout << "Crawler ";
        } else if (dynamic_cast<const Hopper*>(bug)) {
            std::cout << "Hopper ";
        }
        std::cout << "Path: ";
        for (const auto& position : bug->getPath()) {
            std::cout << "(" << position.first << "," << position.second << "),";
        }
        std::cout << " " << (bug->isAlive() ? "Alive!" : "Dead!") << std::endl;
    }
}

void Board::moveBug(int bugId) {
    for (Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            if (bug->isWayBlocked()) {
                std::cout << "Bug " << bugId << " cannot move" << std::endl;
            } else {
                auto& positionVector = board[bug->getPosition()];
                positionVector.erase(std::remove(positionVector.begin(), positionVector.end(), bug), positionVector.end());

                bug->move();

                board[bug->getPosition()].push_back(bug);

                std::cout << "Bug " << bugId << " has moved to (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << std::endl;
            }
            return;
        }
    }
    std::cout << "No bug found with ID " << bugId << std::endl;
}

void Board::killBug(int bugId) {
    for (Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            if (!bug->isAlive()) {
                std::cout << "Bug " << bugId << " is already dead" << std::endl;
            } else {
                bug->kill();
                std::cout << "Bug " << bugId << " has been killed" << std::endl;
            }
            return;
        }
    }
    std::cout << "No bug found with ID " << bugId << std::endl;
}

void Board::displayBoard() const {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            Bug* bug = getBugAtPosition(std::make_pair(i, j));
            if (bug != nullptr) {
                std::cout << bug->getId() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}
Bug* Board::getBugAtPosition(std::pair<int, int> position) const {
    for (Bug* bug : bugVector) {
        if (bug->getPosition() == position) {
            return bug;
        }
    }
    return nullptr;
}

void Board::tapBoard() {
    for (Bug* bug : bugVector) {
        if (bug->isAlive()) {
            bug->move();
        }
    }
}

void Board::writeLifeHistoryToFile() const {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
    auto str = oss.str();

    std::ofstream file("bugs_life_history_" + str + ".out");
    if (!file) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return;
    }

    for (const Bug* bug : bugVector) {
        file << bug->getId() << " ";
        if (dynamic_cast<const Crawler*>(bug)) {
            file << "Crawler ";
        } else if (dynamic_cast<const Hopper*>(bug)) {
            file << "Hopper ";
        }
        file << "Path: ";
        for (const auto& position : bug->getPath()) {
            file << "(" << position.first << "," << position.second << "),";
        }
        file << " " << (bug->isAlive() ? "Alive!" : "Dead!") << std::endl;
    }

    file.close();
}