/*************************************************************************************************
洗牌算法：从前往后扫，第一个位置随机从后面54个选出来一个换到前面来，第二个位置从剩下的53个选出来一个换到第二个位置上,依次类推
证明为什么该洗牌算法是对的：一共有n!的情况，每回洗牌得到一种确定结果的概率是1/n*1/(n-1)*1/(n-2)....=1/n!
*************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void shuffle(int A[],int length)
{
    int index;
    int toexchange;
    srand((unsigned)time(NULL));
    
    for(index=0;index<54;index++)
    {
        toexchange=index+rand()%(length-index);
        swap(&A[index],&A[toexchange]);
    }

}

int main(int argc, char const *argv[])
{
    int a[54];
    for(int i=0;i<54;++i)
    {
        a[i]=i;
    }
    shuffle(a,54);
    for(int i=0;i<54;++i)
    {
        printf("%d---",a[i]);
    }

    return 0;
}