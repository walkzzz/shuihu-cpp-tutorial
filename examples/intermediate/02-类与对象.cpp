/**
 * @file 02-类与对象.cpp
 * @brief 进阶阶段示例：类与对象
 * 
 * 聚义寨故事：
 * 头领档案需要详细记录，类就是创建档案的模板。
 */

#include <iostream>
#include <string>
#include <vector>

class Leader {
private:
    std::string name;
    std::string nickname;
    int troops;
    std::string weapon;

public:
    // 构造函数
    Leader(const std::string& n, const std::string& c, int b, const std::string& w)
        : name(n), nickname(c), troops(b), weapon(w) {}
    
    // const 成员函数
    void assignTroops() const {
        std::cout << nickname << " - " << name 
                  << " 持" << weapon 
                  << " 带" << troops << "兵马听令!" << std::endl;
    }
    
    // 链式调用
    Leader& reinforce(int increment) {
        troops += increment;
        return *this;
    }
    
    Leader& changeWeapon(const std::string& newWeapon) {
        weapon = newWeapon;
        return *this;
    }
    
    // Getter
    int getTroops() const { return troops; }
    std::string getName() const { return name; }
};

// 头领管理类
class LeaderManager {
private:
    std::vector<Leader> leaders;

public:
    void addLeader(const Leader& leader) {
        leaders.push_back(leader);
    }
    
    void assignTroops() const {
        for (const auto& leader : leaders) {
            leader.assignTroops();
        }
    }
    
    int getTotalTroops() const {
        int total = 0;
        for (const auto& leader : leaders) {
            total += leader.getTroops();
        }
        return total;
    }
};

int main() {
    std::cout << "类与对象示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 创建头领管理
    LeaderManager juyiZhai;
    
    // 添加头领
    juyiZhai.addLeader(Leader("林冲", "豹子头", 5000, "长枪"));
    juyiZhai.addLeader(Leader("鲁智深", "花和尚", 3000, "禅杖"));
    juyiZhai.addLeader(Leader("武松", "行者", 2000, "双刀"));
    
    // 点将
    juyiZhai.assignTroops();
    
    std::cout << "===============================" << std::endl;
    std::cout << "总兵力：" << juyiZhai.getTotalTroops() << "人" << std::endl;
    
    std::cout << "===============================" << std::endl;
    
    // 链式调用示例
    Leader songJiang ("宋江", "及时雨", 1000, "宝剑");
    songJiang.reinforce (500).changeWeapon ("长枪");
    songJiang.assignTroops ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
