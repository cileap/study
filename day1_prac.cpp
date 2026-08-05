#include <iostream>

void test1(){
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << /* "*/  "/*"  /*"   */ << std::endl;

}

void test2(){
    /*
    int sum = 0,val = 50;                            
    while(val <= 100){      
        sum += val;         
        ++val;              
    }
    */
    // for改写
    int sum = 0;
    for(int val = 50;val<=100;val++){
        sum+=val;
    }  
    std::cout << sum << std::endl;
}

void test3(){
    /*int val = 10;
    while(val >= 0){
        std::cout << val << ' ';
        val--;
    }
    */
    // for改写
    for(int val = 10;val>=0;val--){
        std::cout << val << ' ';
    }
    std::cout << std::endl ;
}

void test4(){
    std::cout << "Please enter two different numbers" << std::endl;
    int n1 = 0,n2 = 0;
    std::cin >> n1 >> n2;
    /*
    if(n1 > n2){
        while (n2 < n1 - 1)
        {
            n2 ++;
            std::cout << n2 << ' ';
        }
        return;
    }
    else if(n1 < n2){
        while ( n1 < n2 - 1 )
        {
            n1++;
            std::cout << n1 << ' ';
        }
        return;   
    }
    else {
        std::cout << "The numbers are same!";
        test4();
    }
    */
    // for改写
    if(n1 == n2){
        std::cout << "The two numbers are same!";
        test4();
    }
    else if(n2 - n1 == 1 || n1 - n2 == 1){
        std::cout << "Please enter bigger numbers.";
        test4();
    }
    else{
        int smaller = (n1 > n2) ? n2 : n1;
        int bigger = (n1 > n2) ? n1 : n2;
        for(int i = smaller + 1; i < bigger;i++){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}
