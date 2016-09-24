//构造函数求1+2+3+4+5+....+n
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        n++;
        sum += n;
    }
    int result()
    {
        return sum;
    }
private:
    static int n;
    static int sum;
};
int A::n = 0;
int A::sum = 0;

int main(int argc, char const *argv[])
{
    A* pa = new A[100];
    cout << pa[0].result() << endl;
    delete[] pa;
    return 0;
}