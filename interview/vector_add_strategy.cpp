/*******************************************
关于STL 中vector的空间增长策略的测试
*******************************************/

#include <vector>  
#include <algorithm>  
#include <iostream>  
#include <memory>  
using namespace std;
template<class T>  
void display_size_capacity(std::vector<T>& vt)  
{  
    std::cout << "size=" << vt.size() <<endl;  
    std::cout << "capacity=" << vt.capacity() <<endl;  
}  
  
using namespace std;  
int main()  
{  
    size_t i;  
    std::allocator<int> a ;  
    vector<int> iv(2, 9);  
    display_size_capacity(iv);  
    iv.push_back(1);  
    display_size_capacity(iv);  
    iv.push_back(2);  
    display_size_capacity(iv);  
    iv.push_back(3);  
    display_size_capacity(iv);  
    iv.push_back(4);  
    display_size_capacity(iv);
    iv.push_back(5);  
    display_size_capacity(iv);
    iv.push_back(6);  
    display_size_capacity(iv);
    iv.push_back(7);  
    display_size_capacity(iv);        
    return 0;  
}  
