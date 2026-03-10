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
    const std::string 寨主 = "宋江";
    std::cout << "寨主：" << 寨主 << std::endl;
    
    // 整型 - 各军兵力
    int 总兵力 = 0;
    const int 马军 = 5000;
    const int 步军 = 3000;
    const int 水军 = 2000;
    
    // 浮点型 - 粮草比例
    const double 粮草比例 = 0.75;
    
    // 字符串 - 口号
    const std::string 口号 = "替天行道";
    
    // 布尔型 - 战备状态
    const bool 战备状态 = true;
    
    // 计算总兵力
    总兵力 = 马军 + 步军 + 水军;
    
    // 输出统计
    std::cout << "马军：" << 马军 << "人" << std::endl;
    std::cout << "步军：" << 步军 << "人" << std::endl;
    std::cout << "水军：" << 水军 << "人" << std::endl;
    std::cout << "粮草比例：" << 粮草比例 << std::endl;
    std::cout << "口号：" << 口号 << std::endl;
    std::cout << "战备状态：" << (战备状态 ? "是" : "否") << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "总兵力：" << 总兵力 << "人" << std::endl;
    
    return 0;
}
