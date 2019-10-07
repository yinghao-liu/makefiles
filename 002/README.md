# 002 CMake of a large project

## Description
`mkdir build && cd build && cmake .. && make`

## note
when use `option` at first time, it set as a cache variable, `cmake -L` to check Cache values.  
then, if *variable* is already set as a normal or cache variable, then the command 'option' does nothing.  
so, if you change the option you should remove the entries from CMake cache by using `-U <globbing_expr>` option of cmake.

## reference
1. [tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#guide:CMake%20Tutorial)
2. [cmake option](https://cmake.org/cmake/help/latest/command/option.html)

