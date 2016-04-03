/******************************************
@健壮的内存拷贝函数以及测试
@xiaolewen_bupt
@ 2016-4-3
*******************************************/

#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void* memcpy_(void* dst,const void* src,int count)    //还是那句话，在传入变量时用const
{
    assert(dst!=NULL && src!=NULL);   //首先不能传入空指针
    
    unsigned char* dst_tmp = (unsigned char *)dst;   //这句很重要，首先做一次类型强转,因为void* 类型的指针无法进行算数运算
    unsigned char* src_tmp = (unsigned char *)src;   //编译器直接报错：error: arithmetic on a pointer to void
    
    assert(!(dst_tmp<=src_tmp && dst_tmp+count>src_tmp));   //地址不能有重叠，分两种情况进行考虑
    assert(!(dst_tmp>=src_tmp && src_tmp+count>dst_tmp));   
 
    while(count--)
    {
        *dst_tmp = *src_tmp;
        dst_tmp++;
        src_tmp++;
    }
    return dst;
}
typedef struct A
{
    int a;
    char b;
}A;

int main(int argc, char const *argv[])
{
    A instance_of_A;
    instance_of_A.a=0;
    instance_of_A.b='h';
    A* ptr1=&instance_of_A;

    A* ptr2=(A*)malloc(sizeof(A));

    memcpy_(ptr2,ptr1,sizeof(A));

    cout<<ptr2->a<<endl;
    cout<<ptr1->b<<endl;



    return 0;
}