add_library(robot
    Robot.cpp
)

target_link_libraries(robot
    PUBLIC
        gpiodcxx
)

target_include_directories(robot
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
