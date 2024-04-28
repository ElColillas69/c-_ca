#ifndef DASHER_H
#define DASHER_H

#include "bug.h"

class Dasher : public Bug {
public:
    // Constructor
    Dasher(int id, int x, int y, int direction, int size);

    // Destructor
    ~Dasher();

    // Function to move the bug
    void move() override;
};

#endif // DASHER_H