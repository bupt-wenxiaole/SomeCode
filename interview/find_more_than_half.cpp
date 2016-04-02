/*******************************************************************************
数组中有个元素的出现次数超过数组长度的一半，找出这个数
比如 0,1,0,1,1
或者 0,0,1,1,1
来回抵消后要找的数的个数大于等于1
********************************************************************************/
#include <iostream>
using namespace std;

int func(int A[],int n)
{
    int currentAxis;
    int currentnum=0;
    for(int i=0;i<n;i++)
    {
        if(currentnum==0)
        {
            currentAxis=A[i];
            currentnum=1;
        }
        else
        {
            if(currentAxis==A[i])
                currentnum++;
            else
                currentnum--;
        }
    }
    return currentAxis;
}

int main(int argc, char const *argv[])
{
    int data1[]={0,1,0,1,0,1,0,1,0,1,0};
    int axis1=func(data1,5);
    cout<<axis1<<endl;
    int data2[]={0,0,1,1,1};
    int axis2=func(data2,5);
    cout<<axis2<<endl;
    return 0;
}


