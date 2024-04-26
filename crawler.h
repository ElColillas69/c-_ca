//
// Created by adria on 4/24/2024.
//

#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size);
    void move() override;

    using Bug::isWayBlocked;
};

#endif // CRAWLER_H