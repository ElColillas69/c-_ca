//
// Created by adria on 4/24/2024.
//

#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : private Bug {
private:
    int hopLength;

public:
    Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength);
    void move() override;

    using Bug::isPathBlocked;
};

#endif // HOPPER_H
