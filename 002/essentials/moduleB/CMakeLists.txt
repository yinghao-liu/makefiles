# add a library
add_library(moduleB OBJECT mb.cpp)

target_include_directories(moduleB PUBLIC
						"../../include/essentials"
			            )
