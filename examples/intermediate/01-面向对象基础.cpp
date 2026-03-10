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
class 头领 {
private:
    std::string 姓名;
    std::string 绰号;
    int 兵力;

public:
    // 构造函数
    头领 (const std::string& n, const std::string& c, int b)
        : 姓名 (n), 绰号 (c), 兵力 (b) {}
    
    // Getter 方法
    std::string 获取姓名 () const { return 姓名; }
    std::string 获取绰号 () const { return 绰号; }
    int 获取兵力 () const { return 兵力; }
    
    // Setter 方法
    void 设置兵力 (int b) { 兵力 = b; }
    
    // 成员方法
    void 点将 () const {
        std::cout << 绰号 << " - " << 姓名 << " 带" << 兵力 << "兵马听令!" << std::endl;
    }
};

int main() {
    std::cout << "面向对象基础示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 创建对象
    头领 林冲 ("林冲", "豹子头", 5000);
    头领 鲁智深 ("鲁智深", "花和尚", 3000);
    头领 武松 ("武松", "行者", 2000);
    
    // 调用方法
    林冲。点将 ();
    鲁智深。点将 ();
    武松。点将 ();
    
    std::cout << "===============================" << std::endl;
    
    // 使用 Getter
    std::cout << 林冲。获取姓名 () << " 的绰号是：" << 林冲。获取绰号 () << std::endl;
    std::cout << "初始兵力：" << 林冲。获取兵力 () << std::endl;
    
    // 使用 Setter
    林冲。设置兵力 (6000);
    std::cout << "增兵后：" << 林冲。获取兵力 () << std::endl;
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
