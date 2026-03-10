/**
 * @file 02-第一个程序.cpp
 * @brief 第 2 章 第一个程序 - 聚义厅第一声号令
 * 
 * 聚义寨故事：
 * 宋江在聚义厅发出第一声号令，众好汉听令。
 * 这是 C++ 程序的第一个函数调用示例。
 */

#include <iostream>
#include <string>

// 点将函数 - 相当于聚义厅点将
void 点将 (const std::string& 绰号，const std::string& 姓名，int 兵力) {
    std::cout << 绰号 << " - " << 姓名 << " 带" << 兵力 << "兵马听令!" << std::endl;
}

int main() {
    std::cout << "聚义厅点将!" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 点将示例
    点将 ("豹子头", "林冲", 5000);
    点将 ("花和尚", "鲁智深", 3000);
    点将 ("行者", "武松", 2000);
    
    std::cout << "===============================" << std::endl;
    std::cout << "点将完毕!" << std::endl;
    
    return 0;
}
