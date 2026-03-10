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

class Leader {
private:
    std::string name;
    int troops;

public:
    Leader(const std::string& n, int b) : name(n), troops(b) {
        std::cout << "【创建】" << name << " 带" << troops << "兵马" << std::endl;
    }
    
    ~Leader() {
        std::cout << "【析构】" << name << " 交还兵权" << std::endl;
    }
    
    void assignTroops() const {
        std::cout << name << " 带" << troops << "兵马听令!" << std::endl;
    }
    
    int getTroops() const { return troops; }
    std::string getName() const { return name; }
};

void uniquePtrExample() {
    std::cout << "\n=== unique_ptr 示例 (独占所有权) ===" << std::endl;
    
    std::unique_ptr<Leader> linChong = std::make_unique<Leader>("林冲", 5000);
    linChong->assignTroops();
    
    // 转移所有权
    std::unique_ptr<Leader> linChong2 = std::move(linChong);
    // linChong->assignTroops(); // 错误！所有权已转移
    
    if (linChong2) {
        linChong2->assignTroops();
    }
}

void sharedPtrExample() {
    std::cout << "\n=== shared_ptr 示例 (共享所有权) ===" << std::endl;
    
    std::shared_ptr<Leader> luZhishen = std::make_shared<Leader>("鲁智深", 3000);
    std::cout << "引用计数：" << luZhishen.use_count() << std::endl;
    
    {
        std::shared_ptr<Leader> luZhishen2 = luZhishen;
        std::cout << "复制后引用计数：" << luZhishen.use_count() << std::endl;
        luZhishen2->assignTroops();
    }
    
    std::cout << "作用域结束后引用计数：" << luZhishen.use_count() << std::endl;
    luZhishen->assignTroops();
}

void weakPtrExample() {
    std::cout << "\n=== weak_ptr 示例 (弱引用) ===" << std::endl;
    
    std::shared_ptr<Leader> wuSong = std::make_shared<Leader>("武松", 2000);
    std::weak_ptr<Leader> wuSongWeak = wuSong;
    
    std::cout << "weak_ptr 是否有效：" << !wuSongWeak.expired() << std::endl;
    
    if (auto wuSongTemp = wuSongWeak.lock()) {
        wuSongTemp->assignTroops();
    }
    
    wuSong.reset();
    std::cout << "shared_ptr 释放后，weak_ptr 是否有效：" << !wuSongWeak.expired() << std::endl;
}

int main() {
    std::cout << "智能指针示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    uniquePtrExample();
    sharedPtrExample();
    weakPtrExample();
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成！所有内存自动释放" << std::endl;
    
    return 0;
}
