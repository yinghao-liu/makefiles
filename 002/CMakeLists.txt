cmake_minimum_required(VERSION 3.10)

# set the project name
project(main VERSION 1.0.0.0)
configure_file(mainConfig.h.in mainConfig.h)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable
add_executable(main main.cpp)


# sub module
option(USE_MA "Use ModuleA implementation" ON)
if(USE_MA)
	add_subdirectory(moduleA)
	target_link_libraries(main PUBLIC moduleA)
	list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/moduleA")
endif()


# include dir, should in the end of CMakeLists.txt
target_include_directories(main PUBLIC 
						"${PROJECT_BINARY_DIR}"
						"${EXTRA_INCLUDES}"
						)
