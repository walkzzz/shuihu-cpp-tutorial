/**
 * @file 05-所有权与引用.cpp
 * @brief 第 5 章 所有权与引用 - 兵马调配的奥秘
 * 
 * 聚义寨故事：
 * 梁山泊兵马调配有讲究，有的头领可以独立带兵，
 * 有的只是暂时借用。C++ 中的引用和指针也是如此。
 */

#include <iostream>
#include <string>
#include <memory>

// 头领结构体
struct Leader {
    std::string name;
    int troops;
};

// 值传递 - 复制一份
void assignLeader (Leader leader) {
    std::cout << leader.name << " 带" << leader.troops << "兵马听令!" << std::endl;
}

// 引用传递 - 不复制，直接访问
void checkTroops (const Leader& leader) {
    std::cout << leader.name << " 兵力：" << leader.troops << std::endl;
}

// 引用传递 - 可以修改
void reinforceTroops (Leader& leader, int increment) {
    leader.troops += increment;
    std::cout << leader.name << " 增兵" << increment << "，现有" << leader.troops << std::endl;
}

// 智能指针示例
void smartPointerExample () {
    std::cout << "\n智能指针示例:" << std::endl;
    
    // unique_ptr - 独占所有权
    std::unique_ptr<Leader> linChong = std::make_unique<Leader>(Leader{"林冲", 5000});
    std::cout << "林冲兵力：" << linChong->troops << std::endl;
    
    // shared_ptr - 共享所有权
    std::shared_ptr<Leader> luZhishen = std::make_shared<Leader>(Leader{"鲁智深", 3000});
    std::shared_ptr<Leader> luZhishen2 = luZhishen;
    std::cout << "鲁智深兵力：" << luZhishen->troops << std::endl;
    std::cout << "引用计数：" << luZhishen.use_count() << std::endl;
}

int main() {
    std::cout << "聚义寨兵马调配系统" << std::endl;
    std::cout << "===============================" << std::endl;
    
    Leader linChong {"林冲", 5000};
    
    // 引用传递 - 不复制
    checkTroops (linChong);
    
    // 引用传递 - 修改原值
    reinforceTroops (linChong, 1000);
    checkTroops (linChong);
    
    // 值传递 - 复制
    assignLeader (linChong);
    
    std::cout << "===============================" << std::endl;
    
    // 智能指针示例
    smartPointerExample ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "调配完毕!" << std::endl;
    
    return 0;
}
