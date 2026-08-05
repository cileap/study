# Day1

```cpp
#include <iostream>
/* iostream 是 iostream 和 ostream
 分别表示输入流和输出流
 一个流是一个字符序列，stream想要表达的是：
 随着时间的推移，字符是顺序生成或消耗的
 除了 cin 和 cout 还有 cerr 和 clog
*/
int main(){
    std::cout << "Hello,world! " << std::endl;
    return 0;
}
```

```cpp
int main(){
    int v1 = 0,v2 = 0;
    std::cin >> v1 >> v2;  
    std::cout << v1 << v2;
    return 0;
}
/**
 * 这里的>>是输入运算符，接受一个istream作为左侧运算对象
 * >> 从istream读入数据，并存入后面的给定对象中，所以，数据的传递方向是向右
 * >> 的方向也是向右，由此理解
 * 需要注意的是 : >> 返回左侧运算对象作为计算结果，因此返回 istream
 * 这也是为什么了可以连续用两个 >>
 * 等价于 (std::cin >> v1 ) >> v2 ;
 * 
 * cout 和 << 同理，只是ostream而已，不多赘述
 * 
 * 
/
```

