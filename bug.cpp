//
// Created by adria on 4/24/2024.
//

#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <utility>
#include <list>

enum class Direction {
    North,
    East,
    South,
    West
};

class Bug {
private:
    int myId;
    std::pair<int, int> myPosition;
    Direction myDirection;
    int mySize;
    bool myAlive;
    std::list<std::pair<int, int>> myPath;

public:
    Bug(int id, std::pair<int, int> position, Direction direction, int size)
            : myId(id), myPosition(position), myDirection(direction), mySize(size), myAlive(true) {}

    ~Bug() = default;

    bool isPathBlocked() {
        int x = myPosition.first;
        int y = myPosition.second;
        int maxX = 20;
        int maxY = 20;

        switch (myDirection) {
            case Direction::North:
                return y == 0;
            case Direction::East:
                return x == maxX - 1;
            case Direction::South:
                return y == maxY - 1;
            case Direction::West:
                return x == 0;
            default:
                throw std::logic_error("Invalid direction");
        }
    }

    int getId() const {
        return myId;
    }

    std::pair<int, int> getPosition() const {
        return myPosition;
    }

    Direction getDirection() const {
        return myDirection;
    }

    int getSize() const {
        return mySize;
    }

    bool isAlive() const {
        return myAlive;
    }

    std::list<std::pair<int, int>> getPath() const {
        return myPath;
    }

    void setPath(const std::list<std::pair<int, int>>& newPath) {
        myPath = newPath;
    }
};

#endif // BUG_H
