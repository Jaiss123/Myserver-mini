# 指定 cmake 版本，跟安装的版本保持一致
cmake_minimum_required(VERSION 3.4.1)

add_definitions("-Wall -g -lphread")

# 指定 c++ 标准
set(CMAKE_CXX_STANDARD 11)
 
# 输出编译信息
message("Hello Alan!!! Start compile!")
 
# 设置源码根路径，即 cpp 目录
set(SRC_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message(${SRC_ROOT_PATH})
 
# 定义要编译的文件列表变量
file(GLOB CPP_FILES_IN_UTILS "${SRC_ROOT_PATH}/*.cpp")
 
# 设置要编译的源文件
set(
        SOURCE_FILES
        ${CPP_FILES_IN_UTILS}
        ${SRC_ROOT_PATH}/main.cpp
)
 
# include 头文件目录
include_directories(${SRC_ROOT_PATH}/)
 
# 编译成可执行文件，如果编译动态库可以用：target_link_libraries
add_executable(server ${SOURCE_FILES})
target_link_libraries(server -lpthread)
