cmake_minimum_required(VERSION 3.10)

# set the project name
project(main VERSION 1.0.0.0)
configure_file(mainConfig.h.in mainConfig.h)

# add the executable
add_executable(main main.cpp)


# include dir, should in the end of CMakeLists.txt
target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR})

