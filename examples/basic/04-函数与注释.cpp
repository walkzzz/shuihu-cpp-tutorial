/**
 * @file 04-函数与注释.cpp
 * @brief 第 4 章 函数与注释 - 聚义寨的号令与军令状
 * 
 * 聚义寨故事：
 * 聚义寨的号令需要清晰明确，军令状需要详细说明。
 * 函数就像号令，注释就像军令状，让代码清晰易懂。
 */

#include <iostream>
#include <string>

/**
 * @brief 计算军功
 * @param 斩将数 斩杀敌将数量
 * @param 俘虏数 俘虏敌军数量
 * @return 军功总分
 * 
 * 军功计算规则：
 * - 每斩一将：10 分
 * - 每俘一人：5 分
 */
int 计算军功 (int 斩将数，int 俘虏数) {
    return 斩将数 * 10 + 俘虏数 * 5;
}

/**
 * @brief 评定军功等级
 * @param 军功 军功总分
 * @return 等级字符串
 */
std::string 评定等级 (int 军功) {
    if (军功 >= 100) {
        return "特等功";
    } else if (军功 >= 50) {
        return "一等功";
    } else if (军功 >= 20) {
        return "二等功";
    } else {
        return "三等功";
    }
}

int main() {
    std::cout << "聚义寨军功评定系统" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 计算各位头领的军功
    int 林冲军功 = 计算军功 (5, 10);
    int 鲁智深军功 = 计算军功 (3, 15);
    int 武松军功 = 计算军功 (10, 5);
    
    // 输出评定结果
    std::cout << "林冲：" << 林冲军功 << "分 - " << 评定等级 (林冲军功) << std::endl;
    std::cout << "鲁智深：" << 鲁智深军功 << "分 - " << 评定等级 (鲁智深军功) << std::endl;
    std::cout << "武松：" << 武松军功 << "分 - " << 评定等级 (武松军功) << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "评定完毕!" << std::endl;
    
    return 0;
}
