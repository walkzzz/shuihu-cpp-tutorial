# 🚀 水浒聚义寨 C++ 教程 - 快速开始

> 5 分钟快速上手，开始你的 C++ 修炼之路！

## ⚡ 三步开始

### 步骤 1：环境准备（2 分钟）

**Windows 用户：**
```powershell
# 安装 Visual Studio 2022 Community（免费）
# 下载地址：https://visualstudio.microsoft.com/zh-hans/
# 安装时选择"C++ 桌面开发"工作负载
```

**macOS 用户：**
```bash
xcode-select --install
brew install cmake
```

**Linux 用户：**
```bash
# Ubuntu/Debian
sudo apt update && sudo apt install g++ cmake make

# Fedora/RHEL
sudo dnf install gcc-c++ cmake make
```

### 步骤 2：克隆教程（1 分钟）

```bash
git clone https://github.com/walkzzz/shuihu-cpp-tutorial
cd shuihu-cpp-tutorial
```

### 步骤 3：运行第一个示例（2 分钟）

```bash
# 创建构建目录
mkdir build && cd build

# 配置项目
cmake ..

# 编译第一个示例
cmake --build . --target basic-01 --config Release

# 运行
./basic-01              # Linux/macOS
.\Release\basic-01.exe  # Windows
```

**预期输出：**
```
Hello 聚义寨!
C++ 教程第 1 章示例
打造兵器，开始修炼!

C++ 版本：C++17

环境搭建成功!
```

---

## 📚 学习路线

### 入门阶段（5 章）
```bash
# 依次运行
cmake --build . --target basic-01 && ./basic-01
cmake --build . --target basic-02 && ./basic-02
cmake --build . --target basic-03 && ./basic-03
cmake --build . --target basic-04 && ./basic-04
cmake --build . --target basic-05 && ./basic-05
```

### 进阶阶段（5 章）
```bash
cmake --build . --target intermediate-01 && ./intermediate-01
cmake --build . --target intermediate-02 && ./intermediate-02
cmake --build . --target intermediate-03 && ./intermediate-03
cmake --build . --target intermediate-04 && ./intermediate-04
cmake --build . --target intermediate-05 && ./intermediate-05
```

### 高级阶段（5 章）
```bash
cmake --build . --target advanced-01 && ./advanced-01
cmake --build . --target advanced-02 && ./advanced-02
cmake --build . --target advanced-03 && ./advanced-03
cmake --build . --target advanced-04 && ./advanced-04
cmake --build . --target advanced-05 && ./advanced-05
```

### 骨灰阶段（4 章）
```bash
cmake --build . --target master-01 && ./master-01
cmake --build . --target master-02 && ./master-02
cmake --build . --target master-03 && ./master-03
cmake --build . --target master-04 && ./master-04
```

---

## 🎯 学习建议

### ✅ 应该做的

1. **按顺序学习** - 不要跳章，每章都是后续的基础
2. **亲手敲代码** - 不要只看不练
3. **理解错误** - 编译错误是最好的老师
4. **完成练习** - docs/exercises/ 中的练习题

### ❌ 不应该做的

1. ~~只看不练~~ - 编程是实践出来的
2. ~~死记硬背~~ - 理解概念比记忆语法更重要
3. ~~跳过基础~~ - 基础不牢，地动山摇
4. ~~害怕错误~~ - 错误是学习的机会

---

## 💡 常见问题

### Q: 编译失败怎么办？

**A:** 检查以下几点：
1. 编译器是否正确安装
2. CMake 版本是否 >= 3.15
3. 是否在正确的目录运行命令
4. 查看详细错误信息

### Q: 中文乱码怎么办？

**A:** 
- Windows: 确保文件编码为 UTF-8
- Linux/macOS: 设置 `export LANG=zh_CN.UTF-8`

### Q: 如何调试程序？

**A:**
```bash
# 编译 Debug 版本
cmake --build . --target basic-01 --config Debug

# 使用调试器
gdb ./basic-01          # Linux
lldb ./basic-01         # macOS
```

---

## 🔗 下一步

完成快速开始后：

1. 📖 阅读完整 README.md
2. 📚 开始学习 `01-入门阶段` 详细文档
3. 💪 完成练习题
4. 🎯 挑战实战项目

---

**聚义寨·AI 破局，就此启程！** 🏮

**GitHub**: https://github.com/walkzzz/shuihu-cpp-tutorial
