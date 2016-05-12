#include <iostream>

template <typename T>
class NameObject
{
public:
    NameObject(const char* name,const T& value):
    nameValue(name),
    objectValue(value)
    {}
    NameObject(const std::string& name,const T& value):
    nameValue(name),
    objectValue(value)
    {}
    void print_name_value()
    {
        std::cout<<nameValue<<std::endl;
    }
    void print_object_value()
    {
        std::cout<<objectValue<<std::endl;
    }
    NameObject(const NameObject& no)
    {
        std::cout<<"copy constructor"<<std::endl;
        this->nameValue = no.nameValue;
        this->objectValue = no.objectValue;
    }
    NameObject& operator = (const NameObject& rhs)
    {
        std::cout<<"copy assignment"<<std::endl;
        nameValue = rhs.nameValue;
        objectValue = rhs.objectValue;
        return *this;
    }
private:
    std::string nameValue;
    T objectValue;
};


int main(int argc, char const *argv[])
{
    NameObject<int> NO("aaa",2);
    NO.print_name_value();
    NO.print_object_value();
    NameObject<int> no2(NO);
    no2.print_name_value();
    no2.print_object_value();
    NameObject<int> no3 = NO;    //no3在此定义，此时调用的是拷贝构造而不是赋值运算符.
    no3.print_name_value();
    no2.print_object_value();
    no2 = no3;
    return 0;
}