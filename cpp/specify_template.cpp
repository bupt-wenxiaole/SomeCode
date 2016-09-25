//模板特例化的一个例子，模板实例化在编译时执行，编译器根据调用参数类型去生成对应的函数。模板特例化相当于
//由程序员接管这项工作，注意模板特例化的语法特征
#include <iostream>
using namespace std;
template <typename T>
int f(const T& a, const T&b)
{
    cout << "普通版本" << endl;
    return 0;
}

template<>
int f(const char* a, const char* b)
{
    cout << "特例化版本" << endl;
    return 0;
}


int main(int argc, char const *argv[])
{
    f("abc", "def");
    const char * const p = "abc";
    const char * const q = "def";
    f(p, q);
    return 0;
}