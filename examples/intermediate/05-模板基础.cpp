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
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// 类模板 - 万能兵器库
template<typename T>
class WeaponStore {
private:
    std::vector<T> weapons;

public:
    void add(const T& weapon) {
        weapons.push_back(weapon);
    }
    
    T get(int index) const {
        if (index >= 0 && index < weapons.size()) {
            return weapons[index];
        }
        return T();
    }
    
    int size() const {
        return weapons.size();
    }
    
    void display() const {
        std::cout << "兵器库内容 (" << size() << "件):" << std::endl;
        for (size_t i = 0; i < weapons.size(); ++i) {
            std::cout << "  [" << i << "] " << weapons[i] << std::endl;
        }
    }
};

// 模板特化 - 字符串兵器库
template<>
class WeaponStore<std::string> {
private:
    std::vector<std::string> weapons;

public:
    void add(const std::string& weapon) {
        weapons.push_back(weapon);
    }
    
    std::string get(int index) const {
        if (index >= 0 && index < weapons.size()) {
            return weapons[index];
        }
        return "";
    }
    
    int size() const {
        return weapons.size();
    }
    
    void display() const {
        std::cout << "兵器库内容 (" << size() << "件):" << std::endl;
        for (size_t i = 0; i < weapons.size(); ++i) {
            std::cout << "  [" << i << "] 🗡️ " << weapons[i] << std::endl;
        }
    }
};

int main() {
    std::cout << "模板基础示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 函数模板
    std::cout << "最大值 (3, 7) = " << maxValue(3, 7) << std::endl;
    std::cout << "最大值 (5.5, 3.2) = " << maxValue(5.5, 3.2) << std::endl;
    std::cout << std::endl;
    
    // 整数兵器库
    WeaponStore<int> intStore;
    intStore.add(10);
    intStore.add(20);
    intStore.add(30);
    intStore.display();
    
    std::cout << std::endl;
    
    // 字符串兵器库（特化版本）
    WeaponStore<std::string> weaponStore;
    weaponStore.add("青龙刀");
    weaponStore.add("丈八蛇矛");
    weaponStore.add("双股剑");
    weaponStore.display();
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
