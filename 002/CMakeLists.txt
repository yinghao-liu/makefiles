cmake_minimum_required(VERSION 3.10)

# set the project name
project(main VERSION 1.0.0.0)
configure_file(mainConfig.h.in mainConfig.h)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable
#add_executable(main main.cpp)
add_executable(main main.cpp $<TARGET_OBJECTS:moduleA> $<TARGET_OBJECTS:moduleB>)
add_subdirectory("essentials/moduleA")
add_subdirectory("essentials/moduleB")
#target_link_libraries(main PUBLIC moduleA)

# sub module
option(USE_MA "Use ModuleA implementation" ON)
if(USE_MA)
endif()


# include dir, should in the end of taget build
target_include_directories(main PUBLIC 
						"${PROJECT_BINARY_DIR}"
						"include/essentials"
						)


# install
set(CMAKE_INSTALL_PREFIX "./install")
install(TARGETS main DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/mainConfig.h"
		DESTINATION include
	    )


# test
# Add a test to the project to be run by ctest(1).
enable_testing()

# does the application run
add_test(NAME Runs COMMAND main anything)

# does the usage message work?
add_test(NAME Usage COMMAND main)
set_tests_properties(Usage
					PROPERTIES PASS_REGULAR_EXPRESSION "Usage:"
	    			)

include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
include(CPack)
