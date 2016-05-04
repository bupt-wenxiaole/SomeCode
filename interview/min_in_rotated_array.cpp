/************************************************************************************************************
@旋转数组的最小数字
@思路：index1,index2,mid_index,保持index1位于前半段的递增数组中，index2位与后半段的递增数组中，当二者相隔为1时，index2即为所求
@2016/05/04
***************************************************************************************************************/


#include <iostream>
#include <stdlib.h>
#include <assert.h>


#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
//求数组长度宏的用法


int min_value(int *A,int index1,int index2)
{
    int min=A[index1];
    for(int i=index1+1;i<=index2;++i)
    {
        if(A[i]<=min)
            min=A[i];
    }
    return min;
}


int min_in_rotated_array(int A[],int length)
{
    assert(A!=NULL && length>0);
    int index1=0;
    int index2=length-1;
    int midindex=index1;   //初始化为1，
    while(A[index1]>=A[index2])
    {
        
        if(index2-index1==1)
        {
            midindex=index2;
            break;
        }
        midindex=(index1+index2)/2;
        if(A[index1]==A[midindex] && A[midindex]==A[index2])
            return min_value(A,index1,index2);

        if(A[midindex]>=A[index1])
            index1=midindex;
        else if(A[midindex]<A[index2])
            index2=midindex;
    }
    return A[midindex];

}



int main(int argc, char const *argv[])
{
    int A[]={6,7,8,1,2,3,4,5};
    int len;
    GET_ARRAY_LEN(A,len);
    int result=min_in_rotated_array(A,len);
    printf("%d\n",result );
    return 0;
}

