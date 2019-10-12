# add a library
add_library(app2 SHARED 
			app2.cpp)

target_include_directories(app2 INTERFACE
						${CMAKE_CURRENT_SOURCE_DIR}
			            )
