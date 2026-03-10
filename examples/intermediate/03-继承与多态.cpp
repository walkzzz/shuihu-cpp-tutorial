/**
 * @file 03-继承与多态.cpp
 * @brief 进阶阶段示例：继承与多态
 * 
 * 聚义寨故事：
 * 梁山有好汉、军师、医师等不同角色，
 * 他们有一些共同特征，也有各自特长。
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 基类：梁山人物
class LiangshanPerson {
protected:
    std::string name;
    int ability;

public:
    LiangshanPerson(const std::string& n, int v) : name(n), ability(v) {}
    virtual ~LiangshanPerson() = default;
    
    virtual void introduce() const {
        std::cout << "姓名：" << name << ", 能力：" << ability << std::endl;
    }
    
    // 纯虚函数 - 抽象方法
    virtual void skill() const = 0;
    
    std::string getName() const { return name; }
};

// 派生类：好汉
class Hero : public LiangshanPerson {
private:
    std::string nickname;
    std::string weapon;

public:
    Hero(const std::string& n, const std::string& c, int v, const std::string& w)
        : LiangshanPerson(n, v), nickname(c), weapon(w) {}
    
    void introduce() const override {
        std::cout << "【好汉】" << nickname << " - " << name 
                  << ", 武器：" << weapon 
                  << ", 武力：" << ability << std::endl;
    }
    
    void skill() const override {
        std::cout << "  → 施展武艺：" << weapon << "攻击!" << std::endl;
    }
};

// 派生类：军师
class Strategist : public LiangshanPerson {
private:
    std::string strategy;

public:
    Strategist(const std::string& n, int v, const std::string& j)
        : LiangshanPerson(n, v), strategy(j) {}
    
    void introduce() const override {
        std::cout << "【军师】" << name 
                  << ", 擅长：" << strategy 
                  << ", 智力：" << ability << std::endl;
    }
    
    void skill() const override {
        std::cout << "  → 献计：" << strategy << "!" << std::endl;
    }
};

// 派生类：医师
class Doctor : public LiangshanPerson {
private:
    std::string medicalSkill;

public:
    Doctor(const std::string& n, int v, const std::string& y)
        : LiangshanPerson(n, v), medicalSkill(y) {}
    
    void introduce() const override {
        std::cout << "【医师】" << name 
                  << ", 擅长：" << medicalSkill 
                  << ", 医术：" << ability << std::endl;
    }
    
    void skill() const override {
        std::cout << "  → 施治：" << medicalSkill << "治疗!" << std::endl;
    }
};

int main() {
    std::cout << "继承与多态示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 多态容器
    std::vector<std::unique_ptr<LiangshanPerson>> juyiZhai;
    
    juyiZhai.push_back(std::make_unique<Hero>("林冲", "豹子头", 95, "长枪"));
    juyiZhai.push_back(std::make_unique<Hero>("鲁智深", "花和尚", 90, "禅杖"));
    juyiZhai.push_back(std::make_unique<Strategist>("吴用", 98, "连环计"));
    juyiZhai.push_back(std::make_unique<Doctor>("安道全", 92, "针灸"));
    
    // 多态调用
    for (const auto& person : juyiZhai) {
        person->introduce();
        person->skill();
        std::cout << std::endl;
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
