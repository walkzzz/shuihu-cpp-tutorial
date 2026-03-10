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
 * @param enemyGenerals 斩杀敌将数量
 * @param prisoners 俘虏敌军数量
 * @return 军功总分
 * 
 * 军功计算规则：
 * - 每斩一将：10 分
 * - 每俘一人：5 分
 */
int calculateMerit (int enemyGenerals, int prisoners) {
    return enemyGenerals * 10 + prisoners * 5;
}

/**
 * @brief 评定军功等级
 * @param merit 军功总分
 * @return 等级字符串
 */
std::string evaluateRank (int merit) {
    if (merit >= 100) {
        return "特等功";
    } else if (merit >= 50) {
        return "一等功";
    } else if (merit >= 20) {
        return "二等功";
    } else {
        return "三等功";
    }
}

int main() {
    std::cout << "聚义寨军功评定系统" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 计算各位头领的军功
    int linChongMerit = calculateMerit (5, 10);
    int luZhishenMerit = calculateMerit (3, 15);
    int wuSongMerit = calculateMerit (10, 5);
    
    // 输出评定结果
    std::cout << "林冲：" << linChongMerit << "分 - " << evaluateRank (linChongMerit) << std::endl;
    std::cout << "鲁智深：" << luZhishenMerit << "分 - " << evaluateRank (luZhishenMerit) << std::endl;
    std::cout << "武松：" << wuSongMerit << "分 - " << evaluateRank (wuSongMerit) << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "评定完毕!" << std::endl;
    
    return 0;
}
