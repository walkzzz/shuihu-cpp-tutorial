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

class 头领 {
private:
    std::string 姓名;
    std::string 绰号;
    int 兵力;
    std::string 武器;

public:
    // 构造函数
    头领 (const std::string& n, const std::string& c, int b, const std::string& w)
        : 姓名 (n), 绰号 (c), 兵力 (b), 武器 (w) {}
    
    // const 成员函数
    void 点将 () const {
        std::cout << 绰号 << " - " << 姓名 
                  << " 持" << 武器 
                  << " 带" << 兵力 << "兵马听令!" << std::endl;
    }
    
    // 链式调用
    头领& 增兵 (int 增量) {
        兵力 += 增量;
        return *this;
    }
    
    头领& 换武器 (const std::string& 新武器) {
        武器 = 新武器;
        return *this;
    }
    
    // Getter
    int 获取兵力 () const { return 兵力; }
    std::string 获取姓名 () const { return 姓名; }
};

// 头领管理类
class 头领管理 {
private:
    std::vector<头领> 头领列表;

public:
    void 添加头领 (const 头领& 头领) {
        头领列表.push_back(头领);
    }
    
    void 点将 () const {
        for (const auto& 头领 : 头领列表) {
            头领。点将 ();
        }
    }
    
    int 总兵力 () const {
        int 总 = 0;
        for (const auto& 头领 : 头领列表) {
            总 += 头领。获取兵力 ();
        }
        return 总;
    }
};

int main() {
    std::cout << "类与对象示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 创建头领管理
    头领管理 聚义寨;
    
    // 添加头领
    聚义寨。添加头领 (头领 ("林冲", "豹子头", 5000, "长枪"));
    聚义寨。添加头领 (头领 ("鲁智深", "花和尚", 3000, "禅杖"));
    聚义寨。添加头领 (头领 ("武松", "行者", 2000, "双刀"));
    
    // 点将
    聚义寨。点将 ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "总兵力：" << 聚义寨。总兵力 () << "人" << std::endl;
    
    std::cout << "===============================" << std::endl;
    
    // 链式调用示例
    头领 宋江 ("宋江", "及时雨", 1000, "宝剑");
    宋江。增兵 (500).换武器 ("长枪");
    宋江。点将 ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
