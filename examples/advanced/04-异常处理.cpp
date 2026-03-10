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
class InsufficientGrainException : public std::runtime_error {
public:
    InsufficientGrainException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class InsufficientTroopsException : public std::runtime_error {
public:
    InsufficientTroopsException(const std::string& msg)
        : std::runtime_error(msg) {}
};

void checkGrain(int grain) {
    if (grain < 1000) {
        throw InsufficientGrainException("粮草只有 " + std::to_string(grain) + "石，不足 1000 石!");
    }
    std::cout << "粮草充足：" << grain << "石" << std::endl;
}

void checkTroops(int troops) {
    if (troops < 1000) {
        throw InsufficientTroopsException("兵力只有 " + std::to_string(troops) + "人，不足 1000 人!");
    }
    std::cout << "兵力充足：" << troops << "人" << std::endl;
}

void prepareExpedition(int grain，int troops) {
    try {
        checkGrain(grain);
        checkTroops(troops);
        std::cout << "准备完毕，可以出征!" << std::endl;
    } catch (const InsufficientGrainException& e) {
        std::cerr << "【军法】粮草问题：" << e.what() << std::endl;
        throw; // 重新抛出
    } catch (const InsufficientTroopsException& e) {
        std::cerr << "【军法】兵力问题：" << e.what() << std::endl;
    }
}

int main() {
    std::cout << "异常处理示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    try {
        std::cout << "\n【出征 1】" << std::endl;
        prepareExpedition(5000, 5000);
        
        std::cout << "\n【出征 2】" << std::endl;
        prepareExpedition(500, 5000);
        
        std::cout << "\n【出征 3】" << std::endl;
        prepareExpedition(5000, 500);
    } catch (const std::exception& e) {
        std::cerr << "【总军法】出征失败：" << e.what() << std::endl;
    }
    
    std::cout << "\n===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
