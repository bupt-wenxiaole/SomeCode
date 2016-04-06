/************************************************************************************************
关于STL 中vector 空间不够时
vector做出push_back操作，如果capacity()和size()相同了，就是当前的vector已经满了之后，是需要做重新分配的，
而且重新分配空间的操作过程是这样的，重新分配一个大的空间，然后将vector中的元素通过拷贝函数再拷贝给新分配的vector，
如果vector本来就已经很大了，那么在满了的情况下继续push_back，就会在后台有一个相当大的工程要做了。
**************************************************************************************************/


#include <iostream>  
#include <cstdlib>  
#include <vector>  
  
using namespace std;  
  
template<class T>  
void display_size_capacity(std::vector<T>& vt)  
{  
    std::cout << "size=" << vt.size() <<endl;  
    std::cout << "capacity=" << vt.capacity() <<endl;  
}  
  
class MyClass  
{  
public:  
    MyClass()  
    {  
        cout << "construction" << endl;  
    }  
    MyClass(const MyClass& p)  
    {  
        cout << "copy construction" << endl;  
    }  
    ~MyClass()  
    {  
        cout << "destruction" << endl;  
    }  
};  
  
int main()  
{  
    vector<MyClass> my_vector;  
    MyClass a;     //调用构造函数
    MyClass b;     //调用构造函数
    my_vector.push_back(a);    //调用拷贝构造函数
    display_size_capacity(my_vector);    //size=1,cap=1
    my_vector.push_back(b);   //调用拷贝构造函数,将b拷贝放入vector，同时这个时候原来的空间已经满了，
                              //分配一段新的更大的内存空间：大小为2，将原来元素和新元素拷贝到新的空间，
                              //同时释放原来的空间
    display_size_capacity(my_vector);  //size=2,cap=2
 
    return 0;  
}  