/**
 * @file 02-并发与原子操作.cpp
 * @brief 骨灰阶段示例：并发与原子操作
 * 
 * 聚义寨故事：
 * 军令如山，需要确保命令准确传达。
 */

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> troopCount {0};

void reinforceTroops(int increment) {
    for (int i = 0; i < increment; ++i) {
        troopCount.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::cout << "并发与原子操作示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::vector<std::thread> threads;
    
    // 创建 10 个线程，每个线程增兵 1000 次
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(reinforceTroops, 1000);
    }
    
    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }
    
    std::cout << "最终兵力：" << troopCount << std::endl;
    std::cout << "期望兵力：10000" << std::endl;
    std::cout << "原子操作确保计数准确!" << std::endl;
    
    return 0;
}
