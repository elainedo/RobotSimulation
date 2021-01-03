#ifndef POSITION_H
#define POSITION_H

class Position {
    public:
        Position(void) : x_(0), y_(0) {}
        Position(double in_x, double in_y) : x_(in_x), y_(in_y) { }

    double x(void) const { return x_; }
    double y(void) const { return y_; }
    void x(double x) { x_ = x; }
    void y(double y) { y_ = y; }

    /**
     * @brief Load a new Position and set to this Position.
     *
     * @param other Position loaded.
     */
    Position& operator=(const Position& other) {
        this->x_ = other.x_;
        this->y_ = other.y_;
        return *this;
    }

    bool operator==(const Position& other) const {
        if (this->x_ == other.x_ && this->y_ == other.y_)
            return true;
        return false;
    }


private:
    double x_;
    double y_;
};

#endif