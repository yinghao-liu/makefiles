# add a library
add_library(app1 SHARED 
			app1.cpp)

target_include_directories(app1 INTERFACE
						${CMAKE_CURRENT_SOURCE_DIR}
			            )
