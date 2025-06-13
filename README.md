# LeetCodeCpp

本项目是一个用 C++ 实现的 LeetCode 算法题解仓库，涵盖了常见的算法与数据结构分类，适合刷题、复习和参考。

## 目录结构

```
.
├── Binary/                # 位运算相关题目
├── BitOperation/          # 位操作相关题目
├── DataStructure/         # 数据结构相关题目
│   ├── Complicated/       # 复杂数据结构
│   └── Simple/            # 简单数据结构
├── DivideAndConquer/      # 分治算法
├── DynamicProgramming/    # 动态规划
├── Greedy/                # 贪心算法
│   └── ex/                # 贪心算法扩展题
├── MathProblem/           # 数学问题
├── Pointer/               # 指针相关题目
│   ├── Graph/             # 图结构
│   ├── List/              # 链表
│   └── Tree/              # 树
├── QuestionOfTheDay/      # 每日一题
├── Search/                # 搜索算法
├── Sort/                  # 排序算法
├── String/                # 字符串处理
├── Two-pointer/           # 双指针算法
└── README.md              # 项目说明
```

## 编译与运行

本项目采用 MinGW-w64 (g++) 进行编译。你可以直接在 VS Code 中使用内置任务编译当前激活的 `.cpp` 文件，或手动在命令行编译：

```powershell
# 编译(请修改.vscode中的配置为你自己本地的目录)
.\\mingw64\\bin\\g++.exe -g 源文件.cpp -o 输出文件.exe

# 运行
.\输出文件.exe
```

> 推荐使用 VS Code 的任务面板（快捷键 Ctrl+Shift+B）自动编译当前文件。

## 题解说明

- 每个分类下的 `.cpp` 文件为对应题目的 C++ 实现。
- `pch.cpp` 和 `pch.h` 为预编译头文件，加快编译速度。
  - 如果在编写代码过程中存在pch.h未导入的头文件，请自行导入，或者留言提醒我，我会及时更新。

## 贡献指南

欢迎提交 PR 或 issue 共同完善题解：

1. 新增题解请按分类放入对应文件夹，命名为 `题目名.cpp`。
2. 代码需包含题目描述、思路简述和注释。
3. 保持代码风格统一，建议使用 C++17 及以上标准。

## 许可证

本项目采用 MIT License，欢迎自由使用和分享。
