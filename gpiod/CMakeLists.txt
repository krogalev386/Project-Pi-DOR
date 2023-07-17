ExternalProject_Add(
    gpiod
    GIT_REPOSITORY      git://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git
    GIT_TAG             v2.0.1
    CONFIGURE_COMMAND   ${PROJECT_SOURCE_DIR}/build/gpiod/gpiod-prefix/src/gpiod/autogen.sh --enable-tools=yes --enable-bindings-cxx=yes --prefix=${PROJECT_SOURCE_DIR}/build/Gpiod
    UPDATE_COMMAND      ""
    BUILD_COMMAND       make
    INSTALL_COMMAND     make install
)

if(NOT EXISTS ${PROJECT_SOURCE_DIR}/build/Gpiod)
    execute_process(COMMAND mkdir ${PROJECT_SOURCE_DIR}/build/Gpiod)
endif()

add_library(gpiodcxx INTERFACE)
target_link_libraries(gpiodcxx
    INTERFACE
        ${PROJECT_SOURCE_DIR}/build/Gpiod/lib/libgpiodcxx.a
        ${PROJECT_SOURCE_DIR}/build/Gpiod/lib/libgpiod.a
)

target_include_directories(gpiodcxx
    INTERFACE
        ${PROJECT_SOURCE_DIR}/build/Gpiod/include
)

add_dependencies(gpiodcxx gpiod)
