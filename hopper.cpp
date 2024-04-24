//
// Created by adria on 4/24/2024.
//

#include "hopper.h"
#include <cstdlib>

Hopper::Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength)
        : Bug(_id, _position, _direction, _size), hopLength(_hopLength) {}

void Hopper::move() {
    if (alive) {
        if (!isPathBlocked()) {
            int hopDistance = std::min(hopLength, 20);
            switch (direction) {
                case Direction::North:
                    position.second -= hopDistance;
                    break;
                case Direction::East:
                    position.first += hopDistance;
                    break;
                case Direction::South:
                    position.second += hopDistance;
                    break;
                case Direction::West:
                    position.first -= hopDistance;
                    break;
                default:
                    throw std::logic_error("Invalid direction");
            }
            path.push_back(position);
        } else {
            int randomDir = rand() % 4 + 1; // 1-4
            direction = static_cast<Direction>(randomDir);
            move();
        }
    }
}
