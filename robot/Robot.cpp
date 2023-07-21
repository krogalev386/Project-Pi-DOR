#include <gpiod.hpp>
#include <gpiodcxx/chip.hpp>

#include "Robot.hpp"

Robot::Robot() : chip(::gpiod::chip("/dev/gpiochip0")), request(chip.prepare_request())
{
    request.set_consumer("robot");
    request.add_line_settings(MOTOR_EN,
                             ::gpiod::line_settings()
                                        .set_direction(::gpiod::line::direction::OUTPUT)
                                        .set_output_value(::gpiod::line::value::ACTIVE));
    request.do_request();
};

Robot::~Robot()
{
    stop();
    request.add_line_settings(MOTOR_EN,
                              ::gpiod::line_settings()
                                        .set_direction(::gpiod::line::direction::OUTPUT)
                                        .set_output_value(::gpiod::line::value::INACTIVE));
    request.do_request();
};

void Robot::go_forward()
{
    request.add_line_settings({MOTOR_LEFT_FORWARD, MOTOR_RIGHT_FORWARD},
                                ::gpiod::line_settings()
                                        .set_direction(::gpiod::line::direction::OUTPUT)
                                        .set_output_value(::gpiod::line::value::ACTIVE));
    request.do_request();
};

void Robot::go_back()
{
    request.add_line_settings({MOTOR_LEFT_BACK, MOTOR_RIGHT_BACK},
                                ::gpiod::line_settings()
                                        .set_direction(::gpiod::line::direction::OUTPUT)
                                        .set_output_value(::gpiod::line::value::ACTIVE));
    request.do_request();
};

void Robot::turn_right()
{
    request.add_line_settings({MOTOR_LEFT_FORWARD, MOTOR_RIGHT_BACK},
                                ::gpiod::line_settings()
                                        .set_direction(::gpiod::line::direction::OUTPUT)
                                        .set_output_value(::gpiod::line::value::ACTIVE));
    request.do_request();
};

void Robot::turn_left()
{
    request.add_line_settings({MOTOR_LEFT_BACK, MOTOR_RIGHT_FORWARD},
                                ::gpiod::line_settings()
                                        .set_direction(::gpiod::line::direction::OUTPUT)
                                        .set_output_value(::gpiod::line::value::ACTIVE));
    request.do_request();
};

void Robot::stop()
{
    request.add_line_settings({MOTOR_LEFT_BACK, MOTOR_LEFT_FORWARD,
                               MOTOR_RIGHT_BACK, MOTOR_RIGHT_FORWARD},
                                ::gpiod::line_settings()
                                            .set_direction(::gpiod::line::direction::OUTPUT)
                                            .set_output_value(::gpiod::line::value::INACTIVE));
    request.do_request();
};
