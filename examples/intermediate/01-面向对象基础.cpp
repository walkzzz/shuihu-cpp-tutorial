/**
 * @file 01-面向对象基础.cpp
 * @brief 进阶阶段示例：面向对象基础
 * 
 * 聚义寨故事：
 * 梁山泊有好汉、喽啰、马匹等不同角色，
 * 面向对象让我们能够清晰地描述这些角色。
 */

#include <iostream>
#include <string>

// 类定义：头领
class Leader {
private:
    std::string name;
    std::string nickname;
    int troops;

public:
    // 构造函数
    Leader(const std::string& n, const std::string& c, int b)
        : name(n), nickname(c), troops(b) {}
    
    // Getter 方法
    std::string getName() const { return name; }
    std::string getNickname() const { return nickname; }
    int getTroops() const { return troops; }
    
    // Setter 方法
    void setTroops(int b) { troops = b; }
    
    // 成员方法
    void assignTroops() const {
        std::cout << nickname << " - " << name << " 带" << troops << "兵马听令!" << std::endl;
    }
};

int main() {
    std::cout << "面向对象基础示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 创建对象
    Leader linChong("林冲", "豹子头", 5000);
    Leader luZhishen("鲁智深", "花和尚", 3000);
    Leader wuSong("武松", "行者", 2000);
    
    // 调用方法
    linChong.assignTroops();
    luZhishen.assignTroops();
    wuSong.assignTroops();
    
    std::cout << "===============================" << std::endl;
    
    // 使用 Getter
    std::cout << linChong.getName() << " 的绰号是：" << linChong.getNickname() << std::endl;
    std::cout << "初始兵力：" << linChong.getTroops() << std::endl;
    
    // 使用 Setter
    linChong.setTroops(6000);
    std::cout << "增兵后：" << linChong.getTroops() << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
