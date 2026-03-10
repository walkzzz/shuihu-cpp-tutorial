/**
 * @file 01-智能指针.cpp
 * @brief 高级阶段示例：智能指针
 * 
 * 聚义寨故事：
 * 兵符制度确保兵马不会失控，智能指针确保内存不会泄漏。
 */

#include <iostream>
#include <memory>
#include <string>

class 头领 {
private:
    std::string 姓名;
    int 兵力;

public:
    头领 (const std::string& n, int b) : 姓名 (n), 兵力 (b) {
        std::cout << "【创建】" << 姓名 << " 带" << 兵力 << "兵马" << std::endl;
    }
    
    ~头领 () {
        std::cout << "【析构】" << 姓名 << " 交还兵权" << std::endl;
    }
    
    void 点将 () const {
        std::cout << 姓名 << " 带" << 兵力 << "兵马听令!" << std::endl;
    }
    
    int 获取兵力 () const { return 兵力; }
    std::string 获取姓名 () const { return 姓名; }
};

void unique_ptr 示例 () {
    std::cout << "\n=== unique_ptr 示例 (独占所有权) ===" << std::endl;
    
    std::unique_ptr<头领> 林冲 = std::make_unique<头领>("林冲", 5000);
    林冲->点将 ();
    
    // 转移所有权
    std::unique_ptr<头领> 林冲 2 = std::move(林冲);
    // 林冲->点将 (); // 错误！所有权已转移
    
    if (林冲 2) {
        林冲 2->点将 ();
    }
}

void shared_ptr 示例 () {
    std::cout << "\n=== shared_ptr 示例 (共享所有权) ===" << std::endl;
    
    std::shared_ptr<头领> 鲁智深 = std::make_shared<头领>("鲁智深", 3000);
    std::cout << "引用计数：" << 鲁智深.use_count() << std::endl;
    
    {
        std::shared_ptr<头领> 鲁智深 2 = 鲁智深;
        std::cout << "复制后引用计数：" << 鲁智深.use_count() << std::endl;
        鲁智深 2->点将 ();
    }
    
    std::cout << "作用域结束后引用计数：" << 鲁智深.use_count() << std::endl;
    鲁智深->点将 ();
}

void weak_ptr 示例 () {
    std::cout << "\n=== weak_ptr 示例 (弱引用) ===" << std::endl;
    
    std::shared_ptr<头领> 武松 = std::make_shared<头领>("武松", 2000);
    std::weak_ptr<头领> 武松 weak = 武松;
    
    std::cout << "weak_ptr 是否有效：" << !weak.expired() << std::endl;
    
    if (auto 武松 temp = 武松 weak.lock()) {
        武松 temp->点将 ();
    }
    
    武松.reset();
    std::cout << "shared_ptr 释放后，weak_ptr 是否有效：" << !weak.expired() << std::endl;
}

int main() {
    std::cout << "智能指针示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    unique_ptr 示例 ();
    shared_ptr 示例 ();
    weak_ptr 示例 ();
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成！所有内存自动释放" << std::endl;
    
    return 0;
}
