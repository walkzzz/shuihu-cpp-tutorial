/**
 * @file 01-环境搭建.cpp
 * @brief 第 1 章 环境搭建 - 打造兵器
 * 
 * 聚义寨故事：
 * 梁山好汉要打造兵器，需要先准备铁匠铺、熔炉、铁锤等工具。
 * 学习 C++ 也是如此，需要安装编译器、编辑器、调试器等。
 */

#include <iostream>

int main() {
    std::cout << "Hello 聚义寨!" << std::endl;
    std::cout << "C++ 教程第 1 章示例" << std::endl;
    std::cout << "打造兵器，开始修炼!" << std::endl;
    std::cout << std::endl;
    
    // 输出 C++ 版本信息
    std::cout << "C++ 版本：";
    #if __cplusplus == 201703L
        std::cout << "C++17" << std::endl;
    #elif __cplusplus == 202002L
        std::cout << "C++20" << std::endl;
    #elif __cplusplus == 202302L
        std::cout << "C++23" << std::endl;
    #else
        std::cout << "其他版本 (" << __cplusplus << ")" << std::endl;
    #endif
    
    std::cout << std::endl;
    std::cout << "环境搭建成功!" << std::endl;
    
    return 0;
}
