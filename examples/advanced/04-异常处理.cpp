/**
 * @file 04-异常处理.cpp
 * @brief 高级阶段示例：异常处理
 * 
 * 聚义寨故事：
 * 军法处置，处理各种突发情况。
 */

#include <iostream>
#include <stdexcept>
#include <string>

// 自定义异常
class 粮草不足异常 : public std::runtime_error {
public:
    粮草不足异常 (const std::string& msg)
        : std::runtime_error(msg) {}
};

class 兵力不足异常 : public std::runtime_error {
public:
    兵力不足异常 (const std::string& msg)
        : std::runtime_error(msg) {}
};

void 检查粮草 (int 粮草) {
    if (粮草 < 1000) {
        throw 粮草不足异常 ("粮草只有 " + std::to_string(粮草) + "石，不足 1000 石!");
    }
    std::cout << "粮草充足：" << 粮草 << "石" << std::endl;
}

void 检查兵力 (int 兵力) {
    if (兵力 < 1000) {
        throw 兵力不足异常 ("兵力只有 " + std::to_string(兵力) + "人，不足 1000 人!");
    }
    std::cout << "兵力充足：" << 兵力 << "人" << std::endl;
}

void 准备出征 (int 粮草，int 兵力) {
    try {
        检查粮草 (粮草);
        检查兵力 (兵力);
        std::cout << "准备完毕，可以出征!" << std::endl;
    } catch (const 粮草不足异常& e) {
        std::cerr << "【军法】粮草问题：" << e.what() << std::endl;
        throw; // 重新抛出
    } catch (const 兵力不足异常& e) {
        std::cerr << "【军法】兵力问题：" << e.what() << std::endl;
    }
}

int main() {
    std::cout << "异常处理示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    try {
        std::cout << "\n【出征 1】" << std::endl;
        准备出征 (5000, 5000);
        
        std::cout << "\n【出征 2】" << std::endl;
        准备出征 (500, 5000);
        
        std::cout << "\n【出征 3】" << std::endl;
        准备出征 (5000, 500);
    } catch (const std::exception& e) {
        std::cerr << "【总军法】出征失败：" << e.what() << std::endl;
    }
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
