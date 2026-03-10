# 🏮 水浒聚义寨 C++ 教程

> **水浒风格 · 故事教学 · 从零到精通**

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## 📖 教程简介

本教程采用《水浒传》聚义寨主题，通过生动的故事和类比，带你轻松学习 C++ 编程语言。

**🔗 GitHub 仓库**: https://github.com/walkzzz/shuihu-cpp-tutorial

## 🎯 特色

| 编程概念 | 聚义寨比喻 |
|----------|-----------|
| 类与对象 | 头领档案 |
| 继承与多态 | 英雄本色 |
| 智能指针 | 兵符制度 |
| 模板 | 万能兵器 |
| 多线程 | 多路出兵 |

## 📚 教程结构

```
shuihu-cpp-tutorial/
├── CMakeLists.txt          # CMake 构建配置
├── src/
│   └── main.cpp            # 主程序入口
├── examples/               # 19 个示例代码
│   ├── basic/              # 入门阶段 (5 个)
│   ├── intermediate/       # 进阶阶段 (5 个)
│   ├── advanced/           # 高级阶段 (5 个)
│   └── master/             # 骨灰阶段 (4 个)
├── docs/                   # 详细文档
│   ├── README.md           # 文档说明
│   ├── 编译指南.md         # 编译配置
│   ├── 知识索引.md         # 知识点查找
│   ├── 项目总结.md         # 项目总结
│   └── exercises/          # 练习题
├── QuickStart.md           # 快速开始指南
├── LICENSE                 # MIT 许可证
└── README.md               # 本文件
```

## 🚀 快速开始

### 1. 环境要求

- C++17 或更高版本
- CMake 3.15+
- 编译器：GCC/Clang/MSVC

### 2. 克隆仓库

```bash
git clone https://github.com/walkzzz/shuihu-cpp-tutorial
cd shuihu-cpp-tutorial
```

### 3. 构建项目

```bash
# 创建构建目录
mkdir build && cd build

# 配置
cmake ..

# 构建所有目标
cmake --build . --config Release

# 运行主程序
./shuihu-cpp-tutorial  # Linux/macOS
shuihu-cpp-tutorial.exe  # Windows

# 运行示例
./basic-01  # Linux/macOS
basic-01.exe  # Windows
```

### 4. 运行示例

```bash
# 入门阶段
cmake --build . --target basic-01 && ./basic-01

# 进阶阶段
cmake --build . --target intermediate-02 && ./intermediate-02

# 高级阶段
cmake --build . --target advanced-01 && ./advanced-01
```

## 📖 学习路线

### 📘 入门阶段（5 章）

1. **环境搭建** - 打造兵器
2. **第一个程序** - 聚义厅第一声号令
3. **变量与数据类型** - 梁山泊的兵马分类
4. **函数与注释** - 聚义寨的号令与军令状
5. **所有权与引用** - 兵马调配的奥秘

### 📗 进阶阶段（5 章）

1. **面向对象基础** - 英雄排位
2. **类与对象** - 头领档案
3. **继承与多态** - 多种身份
4. **运算符重载** - 兵器比拼
5. **模板基础** - 万能兵器

### 📕 高级阶段（5 章）

1. **智能指针** - 兵符制度
2. **标准库容器** - 兵器库
3. **Lambda 表达式** - 锦囊妙计
4. **异常处理** - 军法处置
5. **移动语义** - 神行太保

### 📔 骨灰阶段（4 章）

1. **多线程** - 多路出兵
2. **并发与原子操作** - 军令如山
3. **内存管理** - 粮草管理
4. **设计模式** - 三十六计

## 🏆 口诀

> 聚义寨中论 C++，
> 二十章节写春秋。
> 类与对象见真章，
> 智能指针显神通。
> 编译器如裴宣面，
> 铁面无私保安全。
> 众头领若勤修炼，
> C++ 江湖任我行！

## 📊 项目信息

- **19 个** 可运行示例代码
- **20 章** 完整教程内容
- **完整文档体系** - 快速开始、编译指南、知识索引、项目总结、练习题
- **标准 CMake 项目结构**
- **MIT 许可证** - 完全开源免费
- **持续更新中**

## 🤝 贡献

欢迎 Star、Fork、PR！

1. Star 仓库支持一下
2. Fork 到你自己的账号
3. 创建特性分支
4. 提交更改
5. 开启 Pull Request

## 📄 许可证

MIT License - 详见 LICENSE 文件

---

**聚义寨·AI 破局，就此启程！** 🏮

**GitHub**: https://github.com/walkzzz/shuihu-cpp-tutorial
