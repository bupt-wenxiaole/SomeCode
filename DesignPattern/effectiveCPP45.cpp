//运用成员函数模板接受所有兼容类型
//运用原始指针确定转换类型
#include <iostream>
class Top
{


};

class Middle : public Top
{

};

class Bottom : public Middle
{

};
template<typename T>
class SmartPtr
{
public:
    template <typename U>
    SmartPtr(const SmartPtr<U>& other) : 
    helderPtr(other.get())
    {
        std::cout << "copy constructor" << std::endl;


    }
    SmartPtr(T* realPtr)
    {
        std::cout << "constructor" << std::endl;
        helderPtr = realPtr;
    }
    T* get() const
    {
        return helderPtr;
    }
private:
    T* helderPtr;

};
int main(int argc, char const *argv[])
{
    
    SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);
    return 0;
}