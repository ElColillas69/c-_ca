//
// Created by adria on 4/24/2024.
//

#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <utility>
#include <list>
#include "bug.h"

enum class Direction {
    North,
    East,
    South,
    West
};

class Bug {
private:
    int Id;
    std::pair<int, int> Position;
    Direction Direction;
    int Size;
    bool Alive;
    std::list<std::pair<int, int>> Path;

public:
    Bug(int id, std::pair<int, int> position, enum Direction direction, int size)
            : Id(id), Position(position), Direction(direction), Size(size), Alive(true) {}

    ~Bug() = default;

    bool isWayBlocked() {
        int x = Position.first;
        int y = Position.second;
        int maxX = 20;
        int maxY = 20;

        switch (Direction) {
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
        return Id;
    }

    std::pair<int, int> getPosition() const {
        return Position;
    }

    enum Direction getDirection() const {
        return Direction;
    }

    int getSize() const {
        return Size;
    }

    bool isAlive() const {
        return Alive;
    }

    std::list<std::pair<int, int>> getPath() const {
        return Path;
    }

    void setPath(const std::list<std::pair<int, int>>& newPath) {
        Path = newPath;
    }
};

#endif // BUG_H
