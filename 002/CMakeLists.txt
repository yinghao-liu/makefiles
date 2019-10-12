cmake_minimum_required(VERSION 3.10)

# set the project name
project(main VERSION 1.0.0.0)
configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp
			$<TARGET_OBJECTS:moduleA>
			$<TARGET_OBJECTS:moduleB>
			)
# essentials are all object library
add_subdirectory("essentials/moduleA")
add_subdirectory("essentials/moduleB")

# libs include components and applications
# components include thirdparty and open source project
add_library(foo STATIC IMPORTED)
set_property(TARGET foo PROPERTY IMPORTED_LOCATION 
			"${PROJECT_SOURCE_DIR}/libs/x64/components/lib3rdparty.a"
			)
add_library(bar STATIC IMPORTED)
set_property(TARGET bar PROPERTY IMPORTED_LOCATION 
			"${PROJECT_SOURCE_DIR}/libs/x64/components/libopensource.a"
			)

target_link_libraries(${PROJECT_NAME} PUBLIC 
					foo
					bar
					)

# applications are individual modules
# sub module(applications)
# use -U option to remove
add_subdirectory("applications/app1")
target_link_libraries(${PROJECT_NAME} PUBLIC app1)
option(APP2 "Use ModuleA implementation" ON)
if(APP2)
	add_subdirectory("applications/app2")
	target_link_libraries(${PROJECT_NAME} PUBLIC app2)
endif()


# include dir, should in the end of taget build
target_include_directories(${PROJECT_NAME} PUBLIC 
						"${PROJECT_BINARY_DIR}"
						"include/essentials"
						"include/components"
						)


# install
set(CMAKE_INSTALL_PREFIX "./install")
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h"
		DESTINATION include
	    )


# test
# Add a test to the project to be run by ctest(1).
enable_testing()

# does the application run
add_test(NAME Runs COMMAND ${PROJECT_NAME} anything)

# does the usage message work?
add_test(NAME Usage COMMAND ${PROJECT_NAME})
set_tests_properties(Usage
					PROPERTIES PASS_REGULAR_EXPRESSION "Usage:"
	    			)

include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
include(CPack)
