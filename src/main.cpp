#include <gpiod.hpp>
#include <gpiodcxx/chip.hpp>
#include <iostream>
#include <unistd.h>
#include <utility>

const unsigned int MOTOR_EN            = 26;
const unsigned int MOTOR_LEFT_FORWARD  = 11;
const unsigned int MOTOR_LEFT_BACK     = 8;
const unsigned int MOTOR_RIGHT_FORWARD = 10;
const unsigned int MOTOR_RIGHT_BACK    = 9;

class Robot
{
public:
    Robot() : chip(::gpiod::chip("/dev/gpiochip0")), request(chip.prepare_request())
    {
        request.set_consumer("robot");
        request.add_line_settings(MOTOR_EN, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::ACTIVE));
        request.do_request();
    }

    ~Robot()
    {
        stop();
        request.add_line_settings(MOTOR_EN, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::INACTIVE));
        request.do_request();
    }

    void go_forward()
    {
        request.add_line_settings({MOTOR_LEFT_FORWARD, MOTOR_RIGHT_FORWARD}, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::ACTIVE));
        request.do_request();
    }

    void go_back()
    {
        request.add_line_settings({MOTOR_LEFT_BACK, MOTOR_RIGHT_BACK}, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::ACTIVE));
        request.do_request();
    }

    void turn_right()
    {
        request.add_line_settings({MOTOR_LEFT_FORWARD, MOTOR_RIGHT_BACK}, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::ACTIVE));
        request.do_request();
    }

    void turn_left()
    {
        request.add_line_settings({MOTOR_LEFT_BACK, MOTOR_RIGHT_FORWARD}, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::ACTIVE));
        request.do_request();
    }

    void stop()
    {
        request.add_line_settings({MOTOR_LEFT_BACK, MOTOR_LEFT_FORWARD, MOTOR_RIGHT_BACK, MOTOR_RIGHT_FORWARD}, ::gpiod::line_settings().set_direction(::gpiod::line::direction::OUTPUT)
                                                            .set_output_value(::gpiod::line::value::INACTIVE));
        request.do_request();
    }

    Robot(Robot&) = delete;
    Robot operator=(Robot&) = delete;

    ::gpiod::chip chip;
    ::gpiod::request_builder request;
};

int main (void)
{
    Robot robot;

    robot.go_forward();
    usleep(2000000);
    robot.stop();

    robot.go_back();
    usleep(2000000);
    robot.stop();

    robot.turn_right();
    usleep(2000000);
    robot.stop();

    robot.turn_left();
    usleep(2000000);
    robot.stop();

    return 0 ;
}
