#include <iostream>

void test1(){
    std::cout << "Who goes with F\145rgus?\012" << std::endl;
    return;
}

// Practice 2.8
void test2(){
    std::cout << "2M" << std::endl;
    std::cout << 2 << "\t" << 'M' << std::endl;
    return;
}

int main(){
    test1();
    test2();
    return 0;
}