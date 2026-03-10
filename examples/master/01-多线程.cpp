/**
 * @file 01-多线程.cpp
 * @brief 骨灰阶段示例：多线程
 * 
 * 聚义寨故事：
 * 梁山多路出兵，需要协调配合。
 */

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void 出兵 (const std::string& 路线，int 兵力) {
    std::cout << "【" << 路线 << "】出兵" << 兵力 << "人" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "【" << 路线 << "】到达目的地!" << std::endl;
}

int main() {
    std::cout << "多线程示例 - 多路出兵" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::vector<std::thread> 线程列表;
    
    // 创建多个线程
    线程列表.emplace_back(出兵，"东路", 1000);
    线程列表.emplace_back(出兵，"西路", 1500);
    线程列表.emplace_back(出兵，"南路", 2000);
    线程列表.emplace_back(出兵，"北路", 2500);
    
    // 等待所有线程完成
    for (auto& 线程 : 线程列表) {
        线程.join();
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "所有兵马到达指定位置!" << std::endl;
    
    return 0;
}
