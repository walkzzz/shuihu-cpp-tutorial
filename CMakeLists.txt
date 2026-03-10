cmake_minimum_required(VERSION 3.15)
project(shuihu-cpp-tutorial VERSION 1.0.0 LANGUAGES CXX)

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 项目信息
set(PROJECT_DESCRIPTION "水浒风格 C++ 教程 - 用聚义寨故事教你学会 C++")
set(PROJECT_AUTHOR "聚义寨 C++ 教程 <shuihu@clawd.org.cn>")

# 编译选项
if(MSVC)
    add_compile_options(/W4 /utf-8)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# 主程序
add_executable(shuihu-cpp-tutorial src/main.cpp)

# 入门阶段示例
add_executable(basic-01 examples/basic/01-环境搭建.cpp)
add_executable(basic-02 examples/basic/02-第一个程序.cpp)
add_executable(basic-03 examples/basic/03-变量与数据类型.cpp)
add_executable(basic-04 examples/basic/04-函数与注释.cpp)
add_executable(basic-05 examples/basic/05-所有权与引用.cpp)

# 进阶阶段示例
add_executable(intermediate-01 examples/intermediate/01-面向对象基础.cpp)
add_executable(intermediate-02 examples/intermediate/02-类与对象.cpp)
add_executable(intermediate-03 examples/intermediate/03-继承与多态.cpp)
add_executable(intermediate-04 examples/intermediate/04-运算符重载.cpp)
add_executable(intermediate-05 examples/intermediate/05-模板基础.cpp)

# 高级阶段示例
add_executable(advanced-01 examples/advanced/01-智能指针.cpp)
add_executable(advanced-02 examples/advanced/02-标准库容器.cpp)
add_executable(advanced-03 examples/advanced/03-Lambda 表达式.cpp)
add_executable(advanced-04 examples/advanced/04-异常处理.cpp)
add_executable(advanced-05 examples/advanced/05-移动语义.cpp)

# 骨灰阶段示例
add_executable(master-01 examples/master/01-多线程.cpp)
add_executable(master-02 examples/master/02-并发与原子操作.cpp)
add_executable(master-03 examples/master/03-内存管理.cpp)
add_executable(master-04 examples/master/04-设计模式.cpp)

# 安装目标
install(TARGETS shuihu-cpp-tutorial DESTINATION bin)
install(DIRECTORY examples DESTINATION share/shuihu-cpp-tutorial)
install(DIRECTORY docs DESTINATION share/shuihu-cpp-tutorial)
