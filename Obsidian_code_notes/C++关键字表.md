# C++ 关键字表

C++11 共 73 个关键字，C++20 增至 83 个。以下按用途分组。

## 基本类型（10个）

| 关键字 | 含义 |
|--------|------|
| `bool` | 布尔类型 |
| `char` | 字符类型 |
| `short` | 短整型 |
| `int` | 整型 |
| `long` | 长整型 |
| `float` | 单精度浮点 |
| `double` | 双精度浮点 |
| `void` | 空类型（无返回值/无类型） |
| `wchar_t` | 宽字符类型 |
| `auto` | 类型自动推导（C++11 重新定义） |

## 类型修饰符（6个）

| 关键字 | 含义 |
|--------|------|
| `signed` | 带符号 |
| `unsigned` | 无符号 |
| `const` | 常量，值不可修改 |
| `volatile` | 易变的，禁止编译器优化 |
| `constexpr` | 常量表达式（C++11） |
| `decltype` | 获取表达式类型（C++11） |

## 控制流（12个）

| 关键字 | 含义 |
|--------|------|
| `if` | 条件判断 |
| `else` | 否则分支 |
| `switch` | 多路分支 |
| `case` | switch 分支标签 |
| `default` | switch 默认分支 |
| `while` | while 循环 |
| `do` | do-while 循环 |
| `for` | for 循环 |
| `break` | 跳出循环/switch |
| `continue` | 跳过本次循环剩余部分 |
| `goto` | 无条件跳转 |
| `return` | 返回（可带值） |

## 复合类型与内存（8个）

| 关键字 | 含义 |
|--------|------|
| `sizeof` | 获取类型/对象大小（字节） |
| `new` | 动态分配内存 |
| `delete` | 释放动态分配的内存 |
| `nullptr` | 空指针字面量（C++11） |
| `alignas` | 指定对齐方式（C++11） |
| `alignof` | 获取对齐方式（C++11） |
| `typeid` | 运行时类型信息 |
| `typedef` | 类型别名（老用法，推荐用 `using`） |

## 类与对象（12个）

| 关键字 | 含义 |
|--------|------|
| `class` | 定义类 |
| `struct` | 定义结构体（默认 public） |
| `union` | 定义联合体 |
| `enum` | 定义枚举 |
| `public` | 公有访问权限 |
| `protected` | 保护访问权限 |
| `private` | 私有访问权限 |
| `this` | 指向当前对象的指针 |
| `virtual` | 虚函数 |
| `override` | 显式覆盖虚函数（C++11） |
| `final` | 禁止覆盖/禁止继承（C++11） |
| `friend` | 友元声明 |

## 构造与对象生命周期（7个）

| 关键字            | 含义                |
| -------------- | ----------------- |
| `explicit`     | 禁止隐式类型转换（构造函数）    |
| `static`       | 静态（多个含义）          |
| `mutable`      | 即使对象是 const 也可修改  |
| `thread_local` | 线程局部存储（C++11）     |
| `register`     | 建议寄存器存储（C++17 废弃） |
| `noexcept`     | 不抛出异常（C++11）      |
| `using`        | 类型别名 / 引入名字空间成员   |

## 异常处理（3个）

| 关键字 | 含义 |
|--------|------|
| `try` | 尝试执行（可能抛异常） |
| `catch` | 捕获异常 |
| `throw` | 抛出异常 |

## 名字空间（2个）

| 关键字 | 含义 |
|--------|------|
| `namespace` | 定义名字空间 |
| `inline` | 内联（函数/名字空间） |

## 运算符替代名（5个）

| 关键字 | 等价于 |
|--------|--------|
| `and` | `&&` |
| `or` | `\|\|` |
| `not` | `!` |
| `and_eq` | `&=` |
| `or_eq` | `\|=` |
| `not_eq` | `!=` |
| `xor` | `^` |
| `xor_eq` | `^=` |
| `bitand` | `&` |
| `bitor` | `\|` |
| `compl` | `~` |

## 其他（8个）

| 关键字 | 含义 |
|--------|------|
| `template` | 模板 |
| `typename` | 类型名（模板中） |
| `export` | 导出模板（C++11 废弃，C++20 模块） |
| `extern` | 外部声明 |
| `operator` | 运算符重载 |
| `static_cast` | 静态类型转换 |
| `dynamic_cast` | 动态类型转换 |
| `const_cast` | 去掉 const 属性 |
| `reinterpret_cast` | 位级别重新解释类型 |
| `asm` | 内联汇编（极少使用） |

> **记忆技巧**：写代码时常用的就 20 个左右——`int` `double` `char` `bool` `if` `else` `for` `while` `return` `class` `struct` `public` `private` `virtual` `const` `static` `new` `delete` `auto` `nullptr`。其余遇到再查就好，不用死记。
