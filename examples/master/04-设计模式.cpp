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
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute() const = 0;
};

class SoundEastAttackWest : public Strategy {
public:
    void execute() const override {
        std::cout << "【声东击西】佯攻东面，实取西面!" << std::endl;
    }
};

class SurroundWeiSaveZhao : public Strategy {
public:
    void execute() const override {
        std::cout << "【围魏救赵】攻其必救，解围之道!" << std::endl;
    }
};

class Strategist {
private:
    std::unique_ptr<Strategy> currentStrategy;

public:
    void setStrategy(std::unique_ptr<Strategy> strategy) {
        currentStrategy = std::move(strategy);
    }
    
    void offerStrategy() const {
        if (currentStrategy) {
            currentStrategy->execute();
        }
    }
};

int main() {
    std::cout << "设计模式示例 - 策略模式" << std::endl;
    std::cout << "===============================" << std::endl;
    
    Strategist wuYong;
    
    // 使用声东击西
    wuYong.setStrategy (std::make_unique<SoundEastAttackWest>());
    wuYong.offerStrategy ();
    
    // 切换为围魏救赵
    wuYong.setStrategy (std::make_unique<SurroundWeiSaveZhao>());
    wuYong.offerStrategy ();
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
