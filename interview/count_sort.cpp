/*****************************************
@计数排序一些注意的点
@author:xiaolewen_bupt
@2016/5/4
******************************************/


#include <iostream>
#include <stdlib.h>


#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
//求数组长度宏的用法

void count_sort(int A[],int length)
{
    int max_num=99;    //待排序的数字中最大的值
    int hashtable[max_num+1];
    for(int i=0;i<=max_num;++i)
        hashtable[i]=0;
    for(int i=0;i<length;i++)
    {
        if(A[i]<0||A[i]>max_num)
            throw new std::exception();
        hashtable[A[i]]++;

    }
        
    int index=0;
    for(int i=0;i<=max_num;++i)
    {
        for(int j=0;j<hashtable[i];j++)
        {
            A[index]=i;
            index++;
        }
    }

}


int main(int argc, char const *argv[])
{
    int A[]={2,5,6,10,9,20,24,27,6,78};
    int len;
    GET_ARRAY_LEN(A,len);
    count_sort(A,len);
    for(int i=0;i<len;++i)
    {
        printf("%d\n",A[i]);
    }
    return 0;
}