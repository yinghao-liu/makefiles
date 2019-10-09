# add a library
add_library(moduleA OBJECT ma.cpp ma_in.cpp)

target_include_directories(moduleA PUBLIC
						"../../include/essentials"
			            )
