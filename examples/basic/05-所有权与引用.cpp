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
struct 头领 {
    std::string 姓名;
    int 兵力;
};

// 值传递 - 复制一份
void 点将 (头领 头领) {
    std::cout << 头领。姓名 << " 带" << 头领。兵力 << "兵马听令!" << std::endl;
}

// 引用传递 - 不复制，直接访问
void 查看兵力 (const 头领& 头领) {
    std::cout << 头领。姓名 << " 兵力：" << 头领。兵力 << std::endl;
}

// 引用传递 - 可以修改
void 增兵 (头领& 头领，int 增量) {
    头领。兵力 += 增量;
    std::cout << 头领。姓名 << " 增兵" << 增量 << "，现有" << 头领。兵力 << std::endl;
}

// 智能指针示例
void 智能指针示例 () {
    std::cout << "\n智能指针示例:" << std::endl;
    
    // unique_ptr - 独占所有权
    std::unique_ptr<头领> 林冲 = std::make_unique<头领>(头领{"林冲", 5000});
    std::cout << "林冲兵力：" << 林冲->兵力 << std::endl;
    
    // shared_ptr - 共享所有权
    std::shared_ptr<头领> 鲁智深 = std::make_shared<头领>(头领{"鲁智深", 3000});
    std::shared_ptr<头领> 鲁智深 2 = 鲁智深;
    std::cout << "鲁智深兵力：" << 鲁智深->兵力 << std::endl;
    std::cout << "引用计数：" << 鲁智深.use_count() << std::endl;
}

int main() {
    std::cout << "聚义寨兵马调配系统" << std::endl;
    std::cout << "===============================" << std::endl;
    
    头领 林冲 {"林冲", 5000};
    
    // 引用传递 - 不复制
    查看兵力 (林冲);
    
    // 引用传递 - 修改原值
    增兵 (林冲，1000);
    查看兵力 (林冲);
    
    // 值传递 - 复制
    点将 (林冲);
    
    std::cout << "===============================" << std::endl;
    
    // 智能指针示例
    智能指针示例 ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "调配完毕!" << std::endl;
    
    return 0;
}
