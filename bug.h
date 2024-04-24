//
// Created by adria on 4/24/2024.
//

#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>

enum class Direction {
    North = 1,
    East,
    South,
    West
};

class Bug {
protected:
    int myId;
    std::pair<int, int> myPosition;
    Direction myDirection;
    int mySize;
    bool myAlive;
    std::list<std::pair<int, int>> myPath;

public:
    Bug(int id, std::pair<int, int> position, Direction direction, int size);
    virtual ~Bug();

    virtual void move() = 0;
    bool isPathBlocked();

    int getId() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    std::list<std::pair<int, int>> getPath() const;
};

#endif // BUG_H
