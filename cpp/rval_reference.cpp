//右值引用重载
//g++ -std=c++11
#include <iostream>
using namespace std;
void process_value(int& i) 
{ 
    std::cout << "LValue processed: " << i << std::endl; 
} 

void process_value(int&& i) 
{ 
    std::cout << "RValue processed: " << i << std::endl; 
} 

int main() 
{ 
    int a = 0; 
    process_value(a); 
    process_value(1); 
}
