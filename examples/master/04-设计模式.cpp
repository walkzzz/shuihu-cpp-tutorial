/**
 * @file 04-设计模式.cpp
 * @brief 骨灰阶段示例：设计模式
 * 
 * 聚义寨故事：
 * 三十六计中的策略，就像设计模式。
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// 策略模式
class 计谋 {
public:
    virtual ~计谋 () = default;
    virtual void 施展 () const = 0;
};

class 声东击西 : public 计谋 {
public:
    void 施展 () const override {
        std::cout << "【声东击西】佯攻东面，实取西面!" << std::endl;
    }
};

class 围魏救赵 : public 计谋 {
public:
    void 施展 () const override {
        std::cout << "【围魏救赵】攻其必救，解围之道!" << std::endl;
    }
};

class 军师 {
private:
    std::unique_ptr<计谋> 当前计谋;

public:
    void 设置计谋 (std::unique_ptr<计谋> 计谋) {
        当前计谋 = std::move(计谋);
    }
    
    void 献计 () const {
        if (当前计谋) {
            当前计谋->施展 ();
        }
    }
};

int main() {
    std::cout << "设计模式示例 - 策略模式" << std::endl;
    std::cout << "===============================" << std::endl;
    
    军师 吴用;
    
    // 使用声东击西
    吴用。设置计谋 (std::make_unique<声东击西>());
    吴用。献计 ();
    
    // 切换为围魏救赵
    吴用。设置计谋 (std::make_unique<围魏救赵>());
    吴用。献计 ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
