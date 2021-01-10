#ifndef MOTION_HANDLER_H_
#define MOTION_HANDLER_H_

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A motion handler base class representing different kinds of motion
 * handler of different arena entities.
 *
 * There would be some kinds of motion handlers derived from this class.
 * RobotMotionHandler is an example.
 */

class MotionHandler {
public:
    MotionHandler() :
        speed_(5),
        max_speed_(10),
        heading_angle_(0),
        max_angle_(360) {}

    virtual ~MotionHandler(void) {}

    double get_speed(void) const { return speed_; }
    void set_speed(double sp) { speed_ = sp; }

    double get_heading_angle(void) const { return heading_angle_;}
    void set_heading_angle(double ha) { heading_angle_ = ha; }

    virtual double get_max_speed(void) const { return max_speed_; }
    virtual void set_max_speed(double ms) { max_speed_ = ms; }

    virtual double get_max_angle(void) const { return max_angle_; }
    virtual void set_max_angle(double ma) { max_angle_ = ma; }

private:
    double speed_;
    double max_speed_;
    double heading_angle_;
    double max_angle_;
};

#endif