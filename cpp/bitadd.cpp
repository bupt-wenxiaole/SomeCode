//不用加减乘除实现加法
#include <iostream>
using namespace std;

int sum(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2; 
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry; 
    }while(num2 != 0);
    return sum;
}
int main(int argc, char const *argv[])
{
    cout << sum(100,200) << endl;
    return 0;
}