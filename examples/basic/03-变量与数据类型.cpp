/**
 * @file 03-变量与数据类型.cpp
 * @brief 第 3 章 变量与数据类型 - 梁山泊的兵马分类
 * 
 * 聚义寨故事：
 * 梁山泊兵马分为马军、步军、水军，各有不同。
 * C++ 中也有不同的数据类型，用于存储不同种类的信息。
 */

#include <iostream>
#include <string>

int main() {
    std::cout << "梁山泊兵马统计" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 字符串类型 - 寨主姓名
    const std::string leader = "宋江";
    std::cout << "寨主：" << leader << std::endl;
    
    // 整型 - 各军兵力
    int totalTroops = 0;
    const int cavalry = 5000;
    const int infantry = 3000;
    const int navy = 2000;
    
    // 浮点型 - 粮草比例
    const double foodRatio = 0.75;
    
    // 字符串 - 口号
    const std::string slogan = "替天行道";
    
    // 布尔型 - 战备状态
    const bool warReady = true;
    
    // 计算总兵力
    totalTroops = cavalry + infantry + navy;
    
    // 输出统计
    std::cout << "马军：" << cavalry << "人" << std::endl;
    std::cout << "步军：" << infantry << "人" << std::endl;
    std::cout << "水军：" << navy << "人" << std::endl;
    std::cout << "粮草比例：" << foodRatio << std::endl;
    std::cout << "口号：" << slogan << std::endl;
    std::cout << "战备状态：" << (warReady ? "是" : "否") << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "总兵力：" << totalTroops << "人" << std::endl;
    
    return 0;
}
