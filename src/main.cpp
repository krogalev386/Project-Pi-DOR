#include <gpiod.hpp>
#include <gpiodcxx/chip.hpp>
#include <iostream>
#include <unistd.h>
#include <utility>

#include "Robot.hpp"

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
