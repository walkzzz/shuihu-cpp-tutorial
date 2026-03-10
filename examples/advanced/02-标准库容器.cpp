/**
 * @file 02-标准库容器.cpp
 * @brief 高级阶段示例：标准库容器
 * 
 * 聚义寨故事：
 * 兵器库需要分类存放各种兵器。
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

int main() {
    std::cout << "标准库容器示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // vector - 顺序容器
    std::cout << "\n=== vector (顺序兵器库) ===" << std::endl;
    std::vector<std::string> 兵器库 = {"青龙刀", "丈八蛇矛", "双股剑", "方天画戟"};
    
    for (const auto& 兵器 : 兵器库) {
        std::cout << "  - " << 兵器 << std::endl;
    }
    
    // map - 关联容器
    std::cout << "\n=== map (头领兵力册) ===" << std::endl;
    std::map<std::string, int> 兵力册;
    兵力册 ["林冲"] = 5000;
    兵力册 ["鲁智深"] = 3000;
    兵力册 ["武松"] = 2000;
    
    for (const auto& [姓名，兵力] : 兵力册) {
        std::cout << "  " << 姓名 << ": " << 兵力 << "人" << std::endl;
    }
    
    // set - 集合容器
    std::cout << "\n=== set (好汉名录) ===" << std::endl;
    std::set<std::string> 好汉名录 = {"宋江", "吴用", "林冲", "鲁智深"};
    
    好汉名录.insert ("武松");
    好汉名录.insert ("林冲"); // 重复，不会插入
    
    std::cout << "好汉数量：" << 好汉名录.size () << std::endl;
    for (const auto& 好汉 : 好汉名录) {
        std::cout << "  - " << 好汉 << std::endl;
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
