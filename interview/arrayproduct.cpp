/*******************************************************************************
输入：一个长度为n的整数数组 input;
输出：一个长度为n的整数数组 result,满足result[i]=input数组中除了input[i]之外的所有数乘积
例如 input={2,3,4,5} 输出result={60,40,30,24}
要求：时间复杂度o(n),空间复杂度o(1)
********************************************************************************/
#include <iostream>
using namespace std;

int *func(int *input,int n)
{
    int *result =new int[10];
    result[0]=1;
    for(int i=1;i<n;i++)
    {
        result[i]=result[i-1]*input[i-1];
    }
    result[0]=input[n-1];
    for(int i=n-2;i>0;--i)
    {
        result[i] *= result[0];
        result[0] *= input[i];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int input[]={2,3,4,5};
    int *result=func(input,4);
    for (int i = 0; i < 4; ++i)
    {  
        cout<<result[i]<<" ";
    }
    cout<<endl;


    return 0;
}



