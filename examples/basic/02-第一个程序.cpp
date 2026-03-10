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
void assignTroops(const std::string& nickname, const std::string& name, int troops) {
    std::cout << nickname << " - " << name << " 带" << troops << "兵马听令!" << std::endl;
}

int main() {
    std::cout << "聚义厅点将!" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 点将示例
    assignTroops("豹子头", "林冲", 5000);
    assignTroops("花和尚", "鲁智深", 3000);
    assignTroops("行者", "武松", 2000);
    
    std::cout << "===============================" << std::endl;
    std::cout << "点将完毕!" << std::endl;
    
    return 0;
}
