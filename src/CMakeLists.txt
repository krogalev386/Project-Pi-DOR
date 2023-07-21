add_executable(gpio_app
    main.cpp
)

target_link_libraries(gpio_app
    PUBLIC
        gpiodcxx
        robot
)
