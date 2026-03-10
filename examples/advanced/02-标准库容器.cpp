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
    std::vector<std::string> weaponStore = {"青龙刀", "丈八蛇矛", "双股剑", "方天画戟"};
    
    for (const auto& weapon : weaponStore) {
        std::cout << "  - " << weapon << std::endl;
    }
    
    // map - 关联容器
    std::cout << "\n=== map (头领兵力册) ===" << std::endl;
    std::map<std::string, int> troopRegistry;
    troopRegistry["林冲"] = 5000;
    troopRegistry["鲁智深"] = 3000;
    troopRegistry["武松"] = 2000;
    
    for (const auto& [name, troops] : troopRegistry) {
        std::cout << "  " << name << ": " << troops << "人" << std::endl;
    }
    
    // set - 集合容器
    std::cout << "\n=== set (好汉名录) ===" << std::endl;
    std::set<std::string> heroDirectory = {"宋江", "吴用", "林冲", "鲁智深"};
    
    heroDirectory.insert("武松");
    heroDirectory.insert("林冲"); // 重复，不会插入
    
    std::cout << "好汉数量：" << heroDirectory.size() << std::endl;
    for (const auto& hero : heroDirectory) {
        std::cout << "  - " << hero << std::endl;
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
