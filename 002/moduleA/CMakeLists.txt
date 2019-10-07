# add a library
add_library(moduleA ma.cpp ma_in.cpp)

target_include_directories(moduleA INTERFACE
						${CMAKE_CURRENT_SOURCE_DIR}
			            )
