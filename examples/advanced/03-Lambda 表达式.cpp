/**
 * @file 03-Lambda 表达式.cpp
 * @brief 高级阶段示例：Lambda 表达式
 * 
 * 聚义寨故事：
 * 军师锦囊，即用即弃的妙计。
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Lambda 表达式示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::vector<int> 兵力 = {5000, 3000, 8000, 1000, 6000};
    
    // 简单 Lambda - 输出兵力
    std::cout << "\n=== 原始兵力 ===" << std::endl;
    std::for_each(兵力.begin(), 兵力.end(),
        [](int b) {
            std::cout << "  " << b << "人" << std::endl;
        }
    );
    
    // 带捕获的 Lambda - 增兵
    int 增量 = 1000;
    std::cout << "\n=== 增兵后 ===" << std::endl;
    std::for_each(兵力.begin(), 兵力.end(),
        [增量](int b) {
            std::cout << "  " << (b + 增量) << "人" << std::endl;
        }
    );
    
    // 修改捕获 - 实际增兵
    std::cout << "\n=== 实际增兵 ===" << std::endl;
    std::for_each(兵力.begin(), 兵力.end(),
        [&增量](int& b) {
            b += 增量;
        }
    );
    
    // 排序 Lambda
    std::cout << "\n=== 排序后 (从大到小) ===" << std::endl;
    std::sort(兵力.begin(), 兵力.end(),
        [](int a, int b) {
            return a > b;
        }
    );
    
    for (int b : 兵力) {
        std::cout << "  " << b << "人" << std::endl;
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
