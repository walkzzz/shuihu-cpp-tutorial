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
class 梁山人物 {
protected:
    std::string 姓名;
    int 能力值;

public:
    梁山人物 (const std::string& n, int v) : 姓名 (n), 能力值 (v) {}
    virtual ~梁山人物 () = default;
    
    virtual void 介绍 () const {
        std::cout << "姓名：" << 姓名 << ", 能力：" << 能力值 << std::endl;
    }
    
    // 纯虚函数 - 抽象方法
    virtual void 技能 () const = 0;
    
    std::string 获取姓名 () const { return 姓名; }
};

// 派生类：好汉
class 好汉 : public 梁山人物 {
private:
    std::string 绰号;
    std::string 武器;

public:
    好汉 (const std::string& n, const std::string& c, int v, const std::string& w)
        : 梁山人物 (n, v), 绰号 (c), 武器 (w) {}
    
    void 介绍 () const override {
        std::cout << "【好汉】" << 绰号 << " - " << 姓名 
                  << ", 武器：" << 武器 
                  << ", 武力：" << 能力值 << std::endl;
    }
    
    void 技能 () const override {
        std::cout << "  → 施展武艺：" << 武器 << "攻击!" << std::endl;
    }
};

// 派生类：军师
class 军师 : public 梁山人物 {
private:
    std::string 计谋;

public:
    军师 (const std::string& n, int v, const std::string& j)
        : 梁山人物 (n, v), 计谋 (j) {}
    
    void 介绍 () const override {
        std::cout << "【军师】" << 姓名 
                  << ", 擅长：" << 计谋 
                  << ", 智力：" << 能力值 << std::endl;
    }
    
    void 技能 () const override {
        std::cout << "  → 献计：" << 计谋 << "!" << std::endl;
    }
};

// 派生类：医师
class 医师 : public 梁山人物 {
private:
    std::string 医术;

public:
    医师 (const std::string& n, int v, const std::string& y)
        : 梁山人物 (n, v), 医术 (y) {}
    
    void 介绍 () const override {
        std::cout << "【医师】" << 姓名 
                  << ", 擅长：" << 医术 
                  << ", 医术：" << 能力值 << std::endl;
    }
    
    void 技能 () const override {
        std::cout << "  → 施治：" << 医术 << "治疗!" << std::endl;
    }
};

int main() {
    std::cout << "继承与多态示例" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // 多态容器
    std::vector<std::unique_ptr<梁山人物>> 聚义寨;
    
    聚义寨.push_back(std::make_unique<好汉>("林冲", "豹子头", 95, "长枪"));
    聚义寨.push_back(std::make_unique<好汉>("鲁智深", "花和尚", 90, "禅杖"));
    聚义寨.push_back(std::make_unique<军师>("吴用", 98, "连环计"));
    聚义寨.push_back(std::make_unique<医师>("安道全", 92, "针灸"));
    
    // 多态调用
    for (const auto& 人物 : 聚义寨) {
        人物->介绍 ();
        人物->技能 ();
        std::cout << std::endl;
    }
    
    std::cout << "===============================" << std::endl;
    std::cout << "示例完成!" << std::endl;
    
    return 0;
}
