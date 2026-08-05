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
    std::cin >> v1 >> v2; // 这里的>>是 
    std::cout << v1 << v2;
    return 0;
}

```

