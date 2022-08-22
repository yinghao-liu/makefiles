# 002 

CMake of a large project

`mkdir build && cd build && cmake .. && make`, then
`make install` or `ctest`

## Description

cmake使用一个CMakeLists.txt文件作为构建说明。

### simple 

源码只有一个main.cpp的最简单的示例：

```cmake
cmake_minimum_required(VERSION 3.10)

# set the project name
project(main)

# add the executable
add_executable(main main.cpp)
```

### 添加头文件

使用`target_include_directories`命令添加，其格式为

```cmake
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
```

其中的`INTERFACE`, `PUBLIC` 和`PRIVATE` 指定其后参数的作用域， `PRIVATE` 和`PUBLIC` 会使用target的 [`INCLUDE_DIRECTORIES`](https://cmake.org/cmake/help/latest/prop_tgt/INCLUDE_DIRECTORIES.html#prop_tgt:INCLUDE_DIRECTORIES) 属性. `PUBLIC` 和`INTERFACE` 会使用target的 [`INTERFACE_INCLUDE_DIRECTORIES`](https://cmake.org/cmake/help/latest/prop_tgt/INTERFACE_INCLUDE_DIRECTORIES.html#prop_tgt:INTERFACE_INCLUDE_DIRECTORIES) 属性，详见参考3,5

本例中，有一个头文件位于`include/version.h`,添加头文件路径：

```cmake
target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/include")
```

### 添加库

使用`target_link_libraries`命令添加，其格式为

```cmake
target_link_libraries(<target> ... <item>... ...)
```

每个`item`可以是下面的其中一种类型：

- 一个库目标名
- 一个库文件的全路径
- 底层使用的库名
- 链接标志





#### 添加系统库



#### 添加自定义库

















### 添加配置项

project可以指定项目的版本号等信息，格式如下：

```cmake
project(<PROJECT-NAME> [<language-name>...])
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [DESCRIPTION <project-description-string>]
        [HOMEPAGE_URL <url-string>]
        [LANGUAGES <language-name>...])
```

例如，

```cmake
project(main VERSION 1.1.1.0)
```

会分别设置以下变量：

PROJECT_VERSION, <PROJECT-NAME>_VERSION

PROJECT_VERSION_MAJOR, <PROJECT-NAME>_VERSION_MAJOR

PROJECT_VERSION_MINOR, <PROJECT-NAME>_VERSION_MINOR

PROJECT_VERSION_PATCH, <PROJECT-NAME>_VERSION_PATCH

PROJECT_VERSION_TWEAK, <PROJECT-NAME>_VERSION_TWEAK

那这些变量如何传递给源码呢？是通过头文件。

通过`configure_file`命令可以将配置文件生成头文件，例如

```cmake
configure_file(main.h.in main.h)
```

其中main.h.in是一个头文件的模板

```cmake
#define PROJECT_NAME "${PROJECT_NAME}"
#define PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}"
#define PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}"
```

`configure_file`命令会将main.h.in文件中的变量经过替换后生成main.h，放在编译目录中，而源文件包含该头文件后，就可以使用这些变量了。







### 交叉编译

创建一个交叉编译的cmake文件arm-linux.cmake，如下：

```cmake
set(CMAKE_SYSTEM_NAME linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabi-g++)
```

之后使用`--toolchain`（3.21之后）或`CMAKE_TOOLCHAIN_FILE`指定交叉编译工具链文件即可，如下：

```cmake
cmake --toolchain ../arm-linux.cmake ..
```

或

```shell
cmake -DCMAKE_TOOLCHAIN_FILE=../arm-linux.cmake ..
```

##### 描述

CMake使用一套工具链编译、链接库和创建归档，工具链是通过语言的使能来启用的，在标准构建中，CMake自动检测主机的工具链。而在交叉编译场景下，工具链文件需要被指定以明确编译器和工具路径。

##### 语言

语言是通过`project`命令使能的，语言相关的内置变量，例如`CMAKE_CXX_COMPILER` 和`CMAKE_CXX_COMPILER_ID`通过`project`命令被设置，若未指定，它会被隐式生成，默认使能的语言是`C`和`CXX`

当一个语言被使能，CMake会为这个语言查找一个编译器，并检测一些信息，例如编译器的提供方和版本、目标的架构和位宽等。

##### 变量和属性

有几个和使能的语言相关的变量：

`CMAKE_<LANG>_COMPILER` 是指定语言编译器的全路径。

`CMAKE_<LANG>_COMPILER_ID` 是CMake使用的编译器的标识符。

`CMAKE_<LANG>_COMPILER_VERSION` 是编译器的版本

`CMAKE_<LANG>_FLAGS` 在编译特定语言的文件时会被添加到编译命令中



##### 交叉编译

如果`cmake`调用时带着命令行参数`--toolchain path-to-file`或者`-DCMAKE_TOOLCHAIN_FILE=path-to-file`，那么，该文件会被加载并设置编译器相关的变量，交叉编译时，变量`CMAKE_CROSSCOMPILING`会被设置为true。



##### linux下的交叉编译

一个典型的linux下的交叉编译工具链文件内容如下：

```cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /home/devel/rasp-pi-rootfs)
set(CMAKE_STAGING_PREFIX /home/devel/stage)

set(tools /home/devel/gcc-4.7-linaro-rpi-gnueabihf)
set(CMAKE_C_COMPILER ${tools}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
```

`CMAKE_SYSTEM_NAME` 是CMake构建的目标平台的标识符

`CMAKE_SYSTEM_PROCESSOR` 是CMake构建的目标架构的标识符

`CMAKE_SYSROOT` 是可选的，如果sysroot可用可被指定，（见gcc的--sysroot）

`CMAKE_STAGING_PREFIX`也是可选的，用来指定安装路径，变量`CMAKE_INSTALL_PREFIX`同样也可以用来指定安装路径，即使是在交叉编译环境下。



## note
when use `option` at first time, it set as a cache variable, `cmake -L` to check Cache values.  
then, if *variable* is already set as a normal or cache variable, then the command 'option' does nothing.  
so, if you change the option you should remove the entries from CMake cache by using `-U <globbing_expr>` option of cmake.

## reference
1. [tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
2. [cmake option](https://cmake.org/cmake/help/latest/command/option.html)
3. [PRIVATE,PUBLIC,INTERFA](https://blog.csdn.net/turbock/article/details/90034787)
4. [cmake-cant-find-imported-library](https://stackoverflow.com/questions/23565564/cmake-cant-find-imported-library)
5. [CMake 中的 PUBLIC，PRIVATE，INTERFACE](https://www.jianshu.com/p/07761ff7838e)
6. [Cmake Cross Compile UserGuide-交叉编译](https://www.cnblogs.com/uestc-mm/p/15666249.html)
7. [cmake 交叉编译](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html)

