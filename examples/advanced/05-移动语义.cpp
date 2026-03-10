/**
 * @file 05-移动语义.cpp
 * @brief 高级阶段示例：移动语义
 * 
 * 聚义寨故事：
 * 神行太保日行八百里，移动语义让数据"飞奔"起来。
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Granary {
private:
    std::vector<int> grains;
    std::string name;

public:
    Granary (const std::string& n, int initialAmount)
        : name (n) {
        grains.resize(initialAmount);
        std::cout << "【构造】" << name << " 创建 (" << initialAmount << "石)" << std::endl;
    }
    
    // 拷贝构造函数
    Granary (const Granary& other)
        : name (other.name + "_copy") {
        grains = other.grains;
        std::cout << "【拷贝】" << name << " 被复制" << std::endl;
    }
    
    // 移动构造函数
    Granary (Granary&& other) noexcept
        : name (std::move(other.name)) {
        grains = std::move(other.grains);
        std::cout << "【移动】" << name << " 被移动 (高效!)" << std::endl;
    }
    
    // 拷贝赋值
    Granary& operator=(const Granary& other) {
        if (this != &other) {
            name = other.name + "_copy";
            grains = other.grains;
            std::cout << "【拷贝赋值】" << name << std::endl;
        }
        return *this;
    }
    
    // 移动赋值
    Granary& operator=(Granary&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            grains = std::move(other.grains);
            std::cout << "【移动赋值】" << name << " (高效!)" << std::endl;
        }
        return *this;
    }
    
    ~Granary () {
        std::cout << "【析构】" << name << std::endl;
    }
};

Granary createGranary (const std::string& name, int amount) {
    return Granary (name, amount);
}

int main() {
    std::cout << "移动语义示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::cout << "\n=== 返回值优化 (RVO) ===" << std::endl;
    auto granary1 = createGranary ("前线粮草库", 10000);
    
    std::cout << "\n=== 移动语义 ===" << std::endl;
    auto granary2 = std::move(granary1);
    
    std::cout << "\n=== vector 自动使用移动语义 ===" << std::endl;
    std::vector<Granary> allGranaries;
    allGranaries.push_back(createGranary ("后方粮草库", 20000));
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
