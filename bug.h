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
    West,
    Count
};

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;

public:
    Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size);
    virtual ~Bug();

    virtual void move() = 0;

    bool isWayBlocked();

    int getId() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    std::list<std::pair<int, int>> getPath() const;
};

#endif // BUG_H