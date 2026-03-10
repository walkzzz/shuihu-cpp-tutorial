/**
 * @file 05-模板基础.cpp
 * @brief 进阶阶段示例：模板基础
 * 
 * 聚义寨故事：
 * 聚义寨有万能兵器库，可以存放各种类型的兵器。
 * 模板就是 C++ 的"万能兵器"。
 */

#include <iostream>
#include <string>
#include <vector>

// 函数模板 - 万能比较
template<typename T>
T 最大值 (T a, T b) {
    return (a > b) ? a : b;
}

// 类模板 - 万能兵器库
template<typename T>
class 兵器库 {
private:
    std::vector<T> 兵器列表;

public:
    void 添加 (const T& 兵器) {
        兵器列表.push_back (兵器);
    }
    
    T 获取 (int 索引) const {
        if (索引 >= 0 && 索引 < 兵器列表.size()) {
            return 兵器列表 [索引];
        }
        return T();
    }
    
    int 数量 () const {
        return 兵器列表.size();
    }
    
    void 展示 () const {
        std::cout << "兵器库内容 (" << 数量 () << "件):" << std::endl;
        for (size_t i = 0; i < 兵器列表.size(); ++i) {
            std::cout << "  [" << i << "] " << 兵器列表 [i] << std::endl;
        }
    }
};

// 模板特化 - 字符串兵器库
template<>
class 兵器库<std::string> {
private:
    std::vector<std::string> 兵器列表;

public:
    void 添加 (const std::string& 兵器) {
        兵器列表.push_back (兵器);
    }
    
    std::string 获取 (int 索引) const {
        if (索引 >= 0 && 索引 < 兵器列表.size()) {
            return 兵器列表 [索引];
        }
        return "";
    }
    
    int 数量 () const {
        return 兵器列表.size();
    }
    
    void 展示 () const {
        std::cout << "兵器库内容 (" << 数量 () << "件):" << std::endl;
        for (size_t i = 0; i < 兵器列表.size(); ++i) {
            std::cout << "  [" << i << "] 🗡️ " << 兵器列表 [i] << std::endl;
        }
    }
};

int main() {
    std::cout << "模板基础示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 函数模板
    std::cout << "最大值 (3, 7) = " << 最大值 (3, 7) << std::endl;
    std::cout << "最大值 (5.5, 3.2) = " << 最大值 (5.5, 3.2) << std::endl;
    std::cout << std::endl;
    
    // 整数兵器库
    兵器库<int> 整数库;
    整数库。添加 (10);
    整数库。添加 (20);
    整数库。添加 (30);
    整数库。展示 ();
    
    std::cout << std::endl;
    
    // 字符串兵器库（特化版本）
    兵器库<std::string> 武器库;
    武器库。添加 ("青龙刀");
    武器库。添加 ("丈八蛇矛");
    武器库。添加 ("双股剑");
    武器库。展示 ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
