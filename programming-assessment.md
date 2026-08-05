# C++ 和 Python 编程水平综合检测

## 使用说明

本检测分为 **C++** 和 **Python** 两部分，每部分分为三个等级：
- **基础**（每题 5 分，共 25 分）—— 计算机专业必须掌握
- **进阶**（每题 8 分，共 24 分）—— 扎实编程能力
- **高级**（每题 12 分，共 24 分）—— 深入语言机制

**请先尝试自己解题，不要查资料，不要用 AI**，之后再对照答案和评分标准。

---

# 第一部分：C++

## 一、基础（每题 5 分）

### 题 1：指针与引用

以下代码的输出是什么？如果有错误，请指出。

```cpp
#include <iostream>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(x, y);
    std::cout << x << " " << y << std::endl;
    return 0;
}
```

### 题 2：内存管理

以下代码存在什么问题？请列举所有问题。

```cpp
class MyArray {
public:
    int* data;
    int size;

    MyArray(int s) : size(s) {
        data = new int[size];
    }

    ~MyArray() {
        delete[] data;
    }

    void print() {
        for (int i = 0; i < size; i++)
            std::cout << data[i] << " ";
    }
};

int main() {
    MyArray arr1(5);
    MyArray arr2 = arr1;  // 拷贝
    arr1.data[0] = 42;
    arr2.print();          // 会输出什么？
    return 0;
}
```

### 题 3：const 正确性

以下代码能否编译？如果不能，为什么？

```cpp
class Person {
    std::string name;
public:
    Person(const std::string& n) : name(n) {}
    std::string& getName() { return name; }
};

void printName(const Person& p) {
    std::cout << p.getName() << std::endl;
}
```

### 题 4：虚函数机制

请写出以下代码的输出。

```cpp
#include <iostream>

class Base {
public:
    virtual void f() { std::cout << "Base::f" << std::endl; }
    void g() { std::cout << "Base::g" << std::endl; }
};

class Derived : public Base {
public:
    void f() override { std::cout << "Derived::f" << std::endl; }
    void g() { std::cout << "Derived::g" << std::endl; }
};

int main() {
    Derived d;
    Base* ptr = &d;
    ptr->f();
    ptr->g();
    d.g();
    return 0;
}
```

### 题 5：STL 基础

用 STL 容器和算法完成：给定一个 `std::vector<int>`，移除所有偶数，然后对剩余元素降序排序。写出代码。

代码：
```cpp
#include <iostream>
#include <vector>

int main(){
    long long n;
    vector<int>[n];# 我都忘记vector是不是这么定义的了。。。
    # 不查资料的话，已经写不下去了
    # 后面的题目就不用说，看都看不懂，也不会做
}
                                                        


```

---

## 二、进阶（每题 8 分）

### 题 6：RAII 与智能指针

标题看不懂。。。

以下代码中 `main` 函数的执行顺序是什么？（即各行的 `std::cout` 输出顺序）

```cpp
#include <iostream>
#include <memory>

struct Resource {
    int id;
    Resource(int i) : id(i) { std::cout << "Acquire " << id << std::endl; }
    ~Resource() { std::cout << "Release " << id << std::endl; }
    void use() { std::cout << "Using " << id << std::endl; }
};

void process(std::unique_ptr<Resource> r) {
    r->use();
}

int main() {
    auto r1 = std::make_unique<Resource>(1);
    auto r2 = std::make_unique<Resource>(2);
    r1->use();
    process(std::move(r1));
    r2->use();
    // r1 现在是什么状态？
    return 0;
}
```

### 题 7：模板

实现一个模板函数 `findMin`，接受任意类型的容器（如 `vector`、`list`、`array`），返回其中最小元素的迭代器。如果容器为空，返回 `end()` 迭代器。要求使用模板和迭代器。

```cpp
// 写出你的实现
template<typename Container>
??? findMin(Container& c) {
    // ...
}
```

### 题 8：移动语义

以下代码中，`push_back` 会调用几次拷贝构造、几次移动构造？（假设 vector 初始 capacity 为 0，扩容策略为翻倍）

```cpp
#include <vector>
#include <string>
#include <iostream>

struct Widget {
    std::string data;
    Widget(const std::string& s) : data(s) {
        std::cout << "Copy ctor: " << data << std::endl;
    }
    Widget(std::string&& s) : data(std::move(s)) {
        std::cout << "Move ctor: " << data << std::endl;
    }
};

int main() {
    std::vector<Widget> v;
    v.push_back(Widget("A"));
    v.push_back(Widget("B"));
    v.push_back(Widget("C"));
    return 0;
}
```

---

## 三、高级（每题 12 分）

### 题 9：虚表与多态

请实现一个简单的 **表达式求值器**：
- 基类 `Expr` 有纯虚函数 `double evaluate()`。
- 派生类 `Number`（存一个 double 值）。
- 派生类 `Add`（存 `left` 和 `right` 两个 `Expr*`）。
- 派生类 `Multiply`（同上）。

要求写出完整的类定义，并展示用 `std::vector<std::unique_ptr<Expr>>` 管理对象。

### 题 10：线程安全与互斥锁

以下单例模式的实现有什么问题？请指出并修正。

```cpp
class Singleton {
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;
```

---

# 第二部分：Python

## 一、基础（每题 5 分）

### 题 1：数据结构

以下代码的输出是什么？

```python
a = [1, 2, 3]
b = a
a.append(4)
print(b)

c = (1, 2, [3, 4])
c[2].append(5)
print(c)

d = {"key": [1, 2]}
e = d.copy()
d["key"].append(3)
print(e)
```

### 题 2：列表推导式

用一行代码生成 1 到 100 中所有能被 3 整除但不能被 5 整除的数的平方构成的列表。

### 题 3：函数参数

以下代码的输出是什么？为什么？

```python
def add_to_list(val, target=[]):
    target.append(val)
    return target

print(add_to_list(1))
print(add_to_list(2))
print(add_to_list(3, [10]))
print(add_to_list(4))
```

### 题 4：类与继承

以下代码的输出是什么？

```python
class Animal:
    sound = "..."
    def __init__(self, name):
        self.name = name
    def speak(self):
        return f"{self.name} says {self.sound}"

class Dog(Animal):
    sound = "Woof"
    def __init__(self, name, breed):
        super().__init__(name)
        self.breed = breed

d = Dog("Buddy", "Golden Retriever")
print(d.speak())
print(Dog.sound)
print(Animal.sound)
```

### 题 5：异常处理

写出以下代码的输出。

```python
def foo():
    try:
        print("A")
        raise ValueError("oops")
        print("B")
    except ValueError:
        print("C")
        return "from except"
    finally:
        print("D")

result = foo()
print(result)
```

---

## 二、进阶（每题 8 分）

### 题 6：装饰器

实现一个装饰器 `@retry(n)`，当被装饰的函数抛出异常时，自动重试最多 `n` 次。如果 n 次都失败，则抛出最后一次的异常。

```python
@retry(3)
def unreliable():
    # ... 可能失败的代码
    pass
```

### 题 7：生成器

实现一个生成器函数 `chunked(iterable, n)`，将可迭代对象按每组 `n` 个元素分组。

```python
list(chunked([1, 2, 3, 4, 5, 6, 7], 3))
# 期望输出: [[1, 2, 3], [4, 5, 6], [7]]
```

### 题 8：上下文管理器

实现一个上下文管理器 `Timer`，用于测量代码块的执行时间，并可用 `with` 语句使用。要求使用 `__enter__` 和 `__exit__` 方法。

```python
with Timer() as t:
    # some_code()
    pass
print(t.elapsed)  # 输出执行时间（秒）
```

---

## 三、高级（每题 12 分）

### 题 9：描述符

实现一个描述符类 `Validated`，用于类属性的类型检查：

```python
class Person:
    name = Validated(str)
    age = Validated(int)

    def __init__(self, name, age):
        self.name = name
        self.age = age

p = Person("Alice", 30)  # OK
p = Person("Bob", "old")  # 应抛出 TypeError
```

### 题 10：异步编程

用 `asyncio` 实现：并发地从 3 个 URL 获取数据（用 `asyncio.sleep` 模拟网络请求延迟），并返回所有结果。要求写出完整的 `async/await` 代码。

---

# 答案与评分

## C++ 答案

### 题 1 答案

**输出：`10 20`**

`swap` 函数按值传递参数，交换的是局部副本，不影响 `main` 中的 `x` 和 `y`。

要修复，应使用引用参数：`void swap(int& a, int& b)`

### 题 2 答案

**双重释放（double free）问题**。
- `arr2 = arr1` 执行默认的**浅拷贝**，两个对象的 `data` 指针指向同一块内存。
- 程序结束时，两个对象的析构函数都会调用 `delete[]`，同一块内存被释放两次，导致未定义行为。
- 缺少拷贝构造函数和拷贝赋值运算符（违反**三法则**）。

### 题 3 答案

**不能编译。** `getName()` 不是 `const` 成员函数，但 `printName` 的参数是 `const Person&`，在 const 对象上不能调用非 const 成员函数。

修复：将 `getName()` 声明为 `const`，并返回 `const std::string&`：
```cpp
const std::string& getName() const { return name; }
```

### 题 4 答案

```
Derived::f
Base::g
Derived::g
```

- `ptr->f()`：`f` 是虚函数，通过虚表调用 `Derived::f`。
- `ptr->g()`：`g` 不是虚函数，静态绑定，调用 `Base::g`。
- `d.g()`：直接调用 `Derived::g`。

### 题 5 答案

```cpp
#include <vector>
#include <algorithm>

std::vector<int> process(std::vector<int> nums) {
    nums.erase(
        std::remove_if(nums.begin(), nums.end(),
                       [](int x) { return x % 2 == 0; }),
        nums.end()
    );
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    return nums;
}
```

### 题 6 答案

输出顺序：
```
Acquire 1
Acquire 2
Using 1
Using 1
Release 1
Using 2
Release 2
```

`process(std::move(r1))` 将 `r1` 的所有权转移给参数 `r`，`r1` 变为 `nullptr`。`r` 在函数结束时会析构，释放 `Resource(1)`。

### 题 7 答案

```cpp
template<typename Container>
typename Container::iterator findMin(Container& c) {
    if (c.begin() == c.end()) return c.end();
    auto min_it = c.begin();
    for (auto it = c.begin(); it != c.end(); ++it) {
        if (*it < *min_it) min_it = it;
    }
    return min_it;
}
```

关键点：返回类型 `typename Container::iterator` 前的 `typename` 关键字是必须的（依赖名称）。

### 题 8 答案

vector 扩容过程：
1. push_back("A")：capacity 0→1，移动构造 A
2. push_back("B")：capacity 1→2，移动 A 到新空间，移动构造 B
3. push_back("C")：capacity 2→4，移动 A 到新空间，移动 B 到新空间，移动构造 C

**输出 6 次 Move ctor**（没有任何 Copy ctor，因为使用了 `Widget(string&&)` 构造函数和移动语义）。

实际上当扩容发生时有拷贝发生——这是常见陷阱。但这里 `Widget` 没有定义拷贝构造函数却有移动构造函数，所以编译器不会生成隐式拷贝构造函数（因为用户定义了移动构造）。这意味着扩容时的"拷贝"实际上是移动。总共 **6 次移动构造**。

### 题 9 答案

```cpp
#include <iostream>
#include <vector>
#include <memory>

class Expr {
public:
    virtual double evaluate() const = 0;
    virtual ~Expr() = default;
};

class Number : public Expr {
    double value;
public:
    Number(double v) : value(v) {}
    double evaluate() const override { return value; }
};

class Add : public Expr {
    std::unique_ptr<Expr> left, right;
public:
    Add(std::unique_ptr<Expr> l, std::unique_ptr<Expr> r)
        : left(std::move(l)), right(std::move(r)) {}
    double evaluate() const override {
        return left->evaluate() + right->evaluate();
    }
};

class Multiply : public Expr {
    std::unique_ptr<Expr> left, right;
public:
    Multiply(std::unique_ptr<Expr> l, std::unique_ptr<Expr> r)
        : left(std::move(l)), right(std::move(r)) {}
    double evaluate() const override {
        return left->evaluate() * right->evaluate();
    }
};

// 使用示例
// auto expr = std::make_unique<Add>(
//     std::make_unique<Number>(3),
//     std::make_unique<Multiply>(
//         std::make_unique<Number>(4),
//         std::make_unique<Number>(5)
//     )
// );
// std::cout << expr->evaluate(); // 3 + 4*5 = 23
```

### 题 10 答案

**问题：线程不安全。** 多个线程可能同时通过 `if (instance == nullptr)` 检查，导致对象被创建多次。

C++11 及以后的最简修复（Meyer's Singleton）：
```cpp
class Singleton {
    Singleton() {}
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};
```
`static` 局部变量的初始化在 C++11 中是线程安全的。

---

## Python 答案

### 题 1 答案

```
[1, 2, 3, 4]
(1, 2, [3, 4, 5])
{'key': [1, 2, 3]}
```

- `b = a` 是引用绑定，修改 `a` 会影响 `b`。
- 元组不可变，但元组内的可变元素（列表）可以被修改。
- `dict.copy()` 是浅拷贝，嵌套的列表仍共享引用。

### 题 2 答案

```python
[x**2 for x in range(1, 101) if x % 3 == 0 and x % 5 != 0]
```

### 题 3 答案

```
[1]
[1, 2]
[10, 3]
[1, 2, 4]
```

**原因：Python 的默认参数在函数定义时只求值一次。** `target=[]` 创建的列表在多次调用间是同一个对象。第 3 次调用传入了新列表 `[10]`，所以不受影响，但第 4 次调用仍使用之前那个共享的默认列表。

### 题 4 答案

```
Buddy says Woof
Woof
...
```

- `Dog.sound` 是 `"Woof"`（类属性，被重写了）。
- `Animal.sound` 是 `"..."`（类属性未被子类修改）。

### 题 5 答案

```
A
C
D
from except
```

`finally` 块始终执行（在 `return` 之前执行，但不截获返回值）。即使 `except` 中有 `return`，`finally` 也会在返回前执行。

### 题 6 答案

```python
import functools

def retry(n):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            last_exc = None
            for _ in range(n):
                try:
                    return func(*args, **kwargs)
                except Exception as e:
                    last_exc = e
            raise last_exc
        return wrapper
    return decorator
```

### 题 7 答案

```python
def chunked(iterable, n):
    chunk = []
    for item in iterable:
        chunk.append(item)
        if len(chunk) == n:
            yield chunk
            chunk = []
    if chunk:
        yield chunk
```

### 题 8 答案

```python
import time

class Timer:
    def __enter__(self):
        self.start = time.time()
        return self

    def __exit__(self, *args):
        self.elapsed = time.time() - self.start
        return False  # 不抑制异常
```

### 题 9 答案

```python
class Validated:
    def __init__(self, expected_type):
        self.expected_type = expected_type
        self.data = {}

    def __get__(self, obj, objtype=None):
        return self.data.get(obj)

    def __set__(self, obj, value):
        if not isinstance(value, self.expected_type):
            raise TypeError(
                f"Expected {self.expected_type.__name__}, "
                f"got {type(value).__name__}"
            )
        self.data[obj] = value
```

### 题 10 答案

```python
import asyncio

async def fetch(url, delay):
    await asyncio.sleep(delay)  # 模拟网络请求
    return f"Result from {url}"

async def main():
    tasks = [
        fetch("url1", 1),
        fetch("url2", 2),
        fetch("url3", 1.5),
    ]
    results = await asyncio.gather(*tasks)
    return results

# asyncio.run(main())
```

---

## 评分标准

### C++ 等级划分（满分 73 分）

| 分数 | 等级 | 说明 |
|------|------|------|
| 0-20 | 入门 | 需要从基础语法开始系统学习 |
| 21-35 | 基础 | 掌握语法但缺乏对内存模型的理解 |
| 36-55 | 进阶 | 可以使用 C++ 开发，但需加强现代 C++ |
| 56-73 | 熟练 | 理解语言机制，可以应对大部分开发任务 |

### Python 等级划分（满分 73 分）

| 分数 | 等级 | 说明 |
|------|------|------|
| 0-20 | 入门 | 需要系统学习 Python 基础 |
| 21-35 | 基础 | 能写脚本但需加强 Pythonic 思维 |
| 36-55 | 进阶 | 理解 Python 特性，可以进行项目开发 |
| 56-73 | 熟练 | 深入理解语言机制，能写出优质 Python 代码 |

---

## 学习建议

### 如果你 C++ 得分 < 36

1. **补基础**：阅读《C++ Primer》（第 5 版）前 12 章，重点是指针、引用、类和动态内存。
2. **动手练习**：在 [LeetCode](https://leetcode.com) 上用 C++ 刷 30 道简单题，强制自己不用 AI。
3. **理解内存模型**：学习栈 vs 堆、RAII、三/五法则。

### 如果你 C++ 得分 36-55

1. **学习现代 C++**：《Effective Modern C++》（Scott Meyers）—— 移动语义、智能指针、lambda、auto。
2. **看 STL 源码**：了解 vector、map、unordered_map 的实现原理。
3. **项目实践**：写一个简单的 key-value 存储引擎或线程池。

### 如果你 Python 得分 < 36

1. **补基础**：《Python Crash Course》或官方 tutorial。
2. **练习 Pythonic 写法**：列表推导、生成器表达式、解包、`enumerate`、`zip`。
3. **刷题**：用 Python 刷 LeetCode/牛客网，感受 Python 的表达力。

### 如果你 Python 得分 36-55

1. **深入学习**：《Fluent Python》（Ramalho）—— 理解 Python 对象模型、描述符、元类。
2. **了解标准库**：`itertools`、`collections`、`functools`、`asyncio`。
3. **项目实践**：用 Django/FastAPI 写一个 Web 应用，或用 asyncio 写一个爬虫。

### 通用建议

1. **关闭 AI 辅助 3 个月**：这是最重要的建议。编程能力只能在实践中培养，每次让 AI 写代码，你就失去了一次学习机会。
2. **每天写代码**：哪怕 30 分钟。用 Git 记录，建立 GitHub 贡献墙。
3. **阅读好代码**：推荐阅读 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) 和 [The Hitchhiker's Guide to Python](https://docs.python-guide.org/)。
4. **计算机基础同步补**：算法（刷 LeetCode）、操作系统（CSAPP/MIT 6.S081）、计算机网络、数据库。

---

完成检测后，把你各题的答案和得分告诉我，我可以进一步分析你的薄弱环节并给出针对性建议。
