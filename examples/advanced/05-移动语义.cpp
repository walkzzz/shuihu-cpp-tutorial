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

class 粮草库 {
private:
    std::vector<int> 粮草;
    std::string 名称;

public:
    粮草库 (const std::string& n, int 初始量)
        : 名称 (n) {
        粮草.resize(初始量);
        std::cout << "【构造】" << 名称 << " 创建 (" << 初始量 << "石)" << std::endl;
    }
    
    // 拷贝构造函数
    粮草库 (const 粮草库& other)
        : 名称 (other.名称 + "_copy") {
        粮草 = other.粮草;
        std::cout << "【拷贝】" << 名称 << " 被复制" << std::endl;
    }
    
    // 移动构造函数
    粮草库 (粮草库&& other) noexcept
        : 名称 (std::move(other.名称)) {
        粮草 = std::move(other.粮草);
        std::cout << "【移动】" << 名称 << " 被移动 (高效!)" << std::endl;
    }
    
    // 拷贝赋值
    粮草库& operator=(const 粮草库& other) {
        if (this != &other) {
            名称 = other.名称 + "_copy";
            粮草 = other.粮草;
            std::cout << "【拷贝赋值】" << 名称 << std::endl;
        }
        return *this;
    }
    
    // 移动赋值
    粮草库& operator=(粮草库&& other) noexcept {
        if (this != &other) {
            名称 = std::move(other.名称);
            粮草 = std::move(other.粮草);
            std::cout << "【移动赋值】" << 名称 << " (高效!)" << std::endl;
        }
        return *this;
    }
    
    ~粮草库 () {
        std::cout << "【析构】" << 名称 << std::endl;
    }
};

粮草库 创建粮草库 (const std::string& 名称，int 量) {
    return 粮草库 (名称，量);
}

int main() {
    std::cout << "移动语义示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    std::cout << "\n=== 返回值优化 (RVO) ===" << std::endl;
    auto 库 1 = 创建粮草库 ("前线粮草库", 10000);
    
    std::cout << "\n=== 移动语义 ===" << std::endl;
    auto 库 2 = std::move(库 1);
    
    std::cout << "\n=== vector 自动使用移动语义 ===" << std::endl;
    std::vector<粮草库> 总粮草库;
    总粮草库.push_back(创建粮草库 ("后方粮草库", 20000));
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
