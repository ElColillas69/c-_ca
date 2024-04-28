#include "dasher.h"
#include <iostream>

Dasher::Dasher(int id, int x, int y, int direction, int size) : Bug(id, x, y, direction, size) {
}

Dasher::~Dasher() {
}

void Dasher::move() {
    std::cout << "Dasher " << id << " moves." << std::endl;
}
