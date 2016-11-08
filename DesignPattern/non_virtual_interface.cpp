//virtual 函数动态绑定，而缺省参数值却是静态绑定，所以绝不重新定义继承而来的缺省参数值
//使用NVI手法 non-virtual-interface
#include <iostream>

class Shape
{
public:
    enum Shapecolor {Red, Green, Blue};
    void draw(Shapecolor color = Red)
    {
        doDraw(color);
    }
private:
    virtual void doDraw(Shapecolor color) const = 0;

};

class Rectangle : public Shape
{
private:
    virtual void doDraw(Shapecolor color) const
    {
        std::cout << "draw with : " << color << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    Shape* ptr = new Rectangle;
    ptr -> draw(Shape::Blue);
    return 0;
}