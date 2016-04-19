#include <stdlib.h>
#include <stdio.h>

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void Bubblesort(int A[],int n)
{
    for(int i=0;i<n-1;i++)   //只用冒n-1次泡，因为最后一次的那个数已经被排好，不需要再冒。
    {
        bool flag = false;  //标志这趟冒泡中是否有交换
        for(int j=n-1;j>i;j--)
        {
            if(A[j-1]>A[j])  //逆序
            {
                swap(A[j-1],A[j]);
                flag=true;
            }
        }
        if(flag==false)
            return;
    }
}


int main(int argc, char const *argv[])
{
    int A[]={0,3,4,2,9,1,7,9,8,0};
    Bubblesort(A,10);
    for(int i=0;i<10;i++)
        printf("%d  ",A[i] );
    return 0;
}

