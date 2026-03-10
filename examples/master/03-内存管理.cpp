/**
 * @file 03-内存管理.cpp
 * @brief 骨灰阶段示例：内存管理
 * 
 * 聚义寨故事：
 * 粮草管理需要精打细算，内存也是如此。
 */

#include <iostream>
#include <memory>
#include <vector>

class Grain {
private:
    int amount;

public:
    Grain(int n) : amount(n) {
        std::cout << "【分配】粮草 " << amount << "石" << std::endl;
    }
    
    ~Grain() {
        std::cout << "【释放】粮草 " << amount << "石" << std::endl;
    }
    
    int getAmount() const { return amount; }
};

void demonstrateAllocation() {
    std::cout << "\n=== 栈分配 ===" << std::endl;
    Grain stackGrain(100);
    std::cout << "栈粮草数量：" << stackGrain.getAmount() << std::endl;
    
    std::cout << "\n=== 堆分配 (unique_ptr) ===" << std::endl;
    auto heapGrain = std::make_unique<Grain>(200);
    std::cout << "堆粮草数量：" << heapGrain->getAmount() << std::endl;
    
    std::cout << "\n=== 作用域结束，自动释放 ===" << std::endl;
}

int main() {
    std::cout << "内存管理示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    demonstrateAllocation();
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成！所有内存自动释放" << std::endl;
    
    return 0;
}
