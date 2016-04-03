#include <iostream>
using namespace std;
#include <assert.h>


char* strcat_(char *dst,const char *src)
{
    assert(dst!=NULL & src!=NULL);
    char *dst_tmp=dst;
    while(*dst!='\0')
        dst++;    //指针++是根据实际指向的类型长度++的
    while((*dst++ = *src++) != '\0');
    *dst='\0';
    return dst_tmp;
}


int main(int argc, char const *argv[])
{
    char a[10]="abcde";
    const char *b="fgh";
    strcat_(a,b);
    cout<<a<<endl;
    return 0;
}