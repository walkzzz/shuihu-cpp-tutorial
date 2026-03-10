/**
 * @file 04-运算符重载.cpp
 * @brief 进阶阶段示例：运算符重载
 * 
 * 聚义寨故事：
 * 好汉之间可以切磋比武，我们需要定义比较规则。
 */

#include <iostream>
#include <string>

class 好汉 {
private:
    std::string 姓名;
    std::string 绰号;
    int 武力值;

public:
    好汉 (const std::string& n, const std::string& c, int v)
        : 姓名 (n), 绰号 (c), 武力值 (v) {}
    
    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const 好汉& h) {
        os << h.绰号 << " - " << h.姓名 << " (武力:" << h.武力值 << ")";
        return os;
    }
    
    // 相等运算符重载
    bool operator==(const 好汉& other) const {
        return 武力值 == other.武力值;
    }
    
    // 不相等运算符重载
    bool operator!=(const 好汉& other) const {
        return 武力值 != other.武力值;
    }
    
    // 大于运算符重载
    bool operator>(const 好汉& other) const {
        return 武力值 > other.武力值;
    }
    
    // 小于运算符重载
    bool operator<(const 好汉& other) const {
        return 武力值 < other.武力值;
    }
    
    // 加法运算符重载 - 合力
    好汉 operator+(const 好汉& other) const {
        return 好汉 (姓名 + "+" + other.姓名，"双雄", 武力值 + other.武力值);
    }
    
    // 前置递增
    好汉& operator++() {
        ++武力值;
        return *this;
    }
    
    // 后置递增
    好汉 operator++(int) {
        好汉 temp = *this;
        ++(*this);
        return temp;
    }
    
    int 获取武力值 () const { return 武力值; }
};

int main() {
    std::cout << "运算符重载示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    好汉 林冲 ("林冲", "豹子头", 95);
    好汉 鲁智深 ("鲁智深", "花和尚", 90);
    好汉 武松 ("武松", "行者", 92);
    
    // 输出运算符
    std::cout << "好汉 1: " << 林冲 << std::endl;
    std::cout << "好汉 2: " << 鲁智深 << std::endl;
    std::cout << "好汉 3: " << 武松 << std::endl;
    std::cout << std::endl;
    
    // 比较运算符
    std::cout << "林冲 > 鲁智深？" << (林冲 > 鲁智深 ? "是" : "否") << std::endl;
    std::cout << "林冲 < 武松？" << (林冲 < 武松 ? "是" : "否") << std::endl;
    std::cout << "鲁智深 == 武松？" << (鲁智深 == 武松 ? "是" : "否") << std::endl;
    std::cout << std::endl;
    
    // 加法运算符 - 合力
    好汉 合力 = 林冲 + 鲁智深;
    std::cout << "合力：" << 合力 << std::endl;
    std::cout << std::endl;
    
    // 递增运算符
    std::cout << "鲁智深原武力：" << 鲁智深。获取武力值 () << std::endl;
    ++鲁智深;
    std::cout << "修炼后武力：" << 鲁智深。获取武力值 () << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
