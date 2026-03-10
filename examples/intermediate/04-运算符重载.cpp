/**
 * @file 04-运算符重载.cpp
 * @brief 进阶阶段示例：运算符重载
 * 
 * 聚义寨故事：
 * 好汉之间可以切磋比武，我们需要定义比较规则。
 */

#include <iostream>
#include <string>

class Hero {
private:
    std::string name;
    std::string nickname;
    int power;

public:
    Hero (const std::string& n, const std::string& c, int v)
        : name (n), nickname (c), power (v) {}
    
    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const Hero& h) {
        os << h.nickname << " - " << h.name << " (武力:" << h.power << ")";
        return os;
    }
    
    // 相等运算符重载
    bool operator==(const Hero& other) const {
        return power == other.power;
    }
    
    // 不相等运算符重载
    bool operator!=(const Hero& other) const {
        return power != other.power;
    }
    
    // 大于运算符重载
    bool operator>(const Hero& other) const {
        return power > other.power;
    }
    
    // 小于运算符重载
    bool operator<(const Hero& other) const {
        return power < other.power;
    }
    
    // 加法运算符重载 - 合力
    Hero operator+(const Hero& other) const {
        return Hero (name + "+" + other.name, "双雄", power + other.power);
    }
    
    // 前置递增
    Hero& operator++() {
        ++power;
        return *this;
    }
    
    // 后置递增
    Hero operator++(int) {
        Hero temp = *this;
        ++(*this);
        return temp;
    }
    
    int getPower () const { return power; }
};

int main() {
    std::cout << "运算符重载示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    Hero linChong ("林冲", "豹子头", 95);
    Hero luZhishen ("鲁智深", "花和尚", 90);
    Hero wuSong ("武松", "行者", 92);
    
    // 输出运算符
    std::cout << "好汉 1: " << linChong << std::endl;
    std::cout << "好汉 2: " << luZhishen << std::endl;
    std::cout << "好汉 3: " << wuSong << std::endl;
    std::cout << std::endl;
    
    // 比较运算符
    std::cout << "林冲 > 鲁智深？" << (linChong > luZhishen ? "是" : "否") << std::endl;
    std::cout << "林冲 < 武松？" << (linChong < wuSong ? "是" : "否") << std::endl;
    std::cout << "鲁智深 == 武松？" << (luZhishen == wuSong ? "是" : "否") << std::endl;
    std::cout << std::endl;
    
    // 加法运算符 - 合力
    Hero combinedForce = linChong + luZhishen;
    std::cout << "合力：" << combinedForce << std::endl;
    std::cout << std::endl;
    
    // 递增运算符
    std::cout << "鲁智深原武力：" << luZhishen.getPower () << std::endl;
    ++luZhishen;
    std::cout << "修炼后武力：" << luZhishen.getPower () << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
