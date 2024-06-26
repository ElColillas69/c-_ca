#ifndef BUG_H
#define BUG_H

#include <utility> // For std::pair
#include <list> // For std::list

enum class Direction {
    North = 1,
    East,
    South,
    West,
    Count
};

class Bug {
public:
    Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size);

    Bug(int i, int i1, int i2, int i3, int i4);

    virtual ~Bug();

    virtual void move() = 0;
    virtual bool isWayBlocked() = 0;
    int getId() const;

    virtual std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    void kill();
    const std::list<std::pair<int, int>> & getPath() const;

protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
};

#endif
