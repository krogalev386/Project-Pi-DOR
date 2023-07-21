#pragma once
#include <gpiod.hpp>
#include <gpiodcxx/chip.hpp>

const unsigned int MOTOR_EN            = 26;
const unsigned int MOTOR_LEFT_FORWARD  = 11;
const unsigned int MOTOR_LEFT_BACK     = 8;
const unsigned int MOTOR_RIGHT_FORWARD = 10;
const unsigned int MOTOR_RIGHT_BACK    = 9;

class Robot
{
public:
    Robot();
    ~Robot();

    Robot(Robot&) = delete;
    Robot operator=(Robot&) = delete;

    void go_forward();
    void go_back();
    void turn_right();
    void turn_left();
    void stop();

private:
    ::gpiod::chip chip;
    ::gpiod::request_builder request;
};