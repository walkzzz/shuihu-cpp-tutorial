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

void sendTroops(const std::string& route, int troops) {
    std::cout << "【" << route << "】出兵" << troops << "人" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "【" << route << "】到达目的地!" << std::endl;
}

int main() {
    std::cout << "多线程示例 - 多路出兵" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::vector<std::thread> threads;
    
    // 创建多个线程
    threads.emplace_back(sendTroops, "东路", 1000);
    threads.emplace_back(sendTroops, "西路", 1500);
    threads.emplace_back(sendTroops, "南路", 2000);
    threads.emplace_back(sendTroops, "北路", 2500);
    
    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "所有兵马到达指定位置!" << std::endl;
    
    return 0;
}
