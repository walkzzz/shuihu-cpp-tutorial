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

class 粮草 {
private:
    int 数量;

public:
    粮草 (int n) : 数量 (n) {
        std::cout << "【分配】粮草 " << 数量 << "石" << std::endl;
    }
    
    ~粮草 () {
        std::cout << "【释放】粮草 " << 数量 << "石" << std::endl;
    }
    
    int 获取数量 () const { return 数量; }
};

void 演示分配 () {
    std::cout << "\n=== 栈分配 ===" << std::endl;
    粮草 栈粮草 (100);
    std::cout << "栈粮草数量：" << 栈粮草。获取数量 () << std::endl;
    
    std::cout << "\n=== 堆分配 (unique_ptr) ===" << std::endl;
    auto 堆粮草 = std::make_unique<粮草>(200);
    std::cout << "堆粮草数量：" << 堆粮草->获取数量 () << std::endl;
    
    std::cout << "\n=== 作用域结束，自动释放 ===" << std::endl;
}

int main() {
    std::cout << "内存管理示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    演示分配 ();
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成！所有内存自动释放" << std::endl;
    
    return 0;
}
