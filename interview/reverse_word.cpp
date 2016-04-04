/*************************************************************************
@字符串按单词逆序：首先对按空格分割的单词逐个进行逆序，最后对整个字符串进行逆序
主要是如何做到按单词进行逆序，通过两个指针一快一慢
@xiaole_wen
@2016/04/04
**************************************************************************/

#include <assert.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
void reverseWord(char* low,char* high)    //非递归写法
{
    assert(low!=NULL && high!=NULL);
    while(low<high)
    {
        char tmp = *low;
        *low = *high;
        *high = tmp;
        low++;
        high--;
    }
}

//void reverseWord(char* low,char *high)   //递归控制范围
//{
//    assert(low!=NULL && high!=NULL);
//    if (low >= high)
//        return;    
//    char tmp = *low;           
//    *low = *high;
//    *high = tmp;
//    reverseWord(low+1,high-1);
//}
//
//
void reverseStence(char *s)      //按单词翻转整个句子
{
    char* p=s;
    char* q=s;
    while(*q !='\0')    //q尚未走到整个句子的末尾
    {
        if(*q == ' ')
        {
            reverseWord(p,q-1);
            q++;   //q指向下一个单词的第一个字母
            p=q;
        }
        else
        {
            q++;
        }
    }
    reverseWord(p,q-1);  //逆序最后一个单词
    reverseWord(s,q-1);  //逆序整个句子
}


int main(int argc, char const *argv[])
{
    //char p[]="abc";    //只能用栈数组而不是const char* p="abc"
    //char* s = p; 
    //char* e=p;
    //while (*e != '\0')
    //{
    //    e++;
    //}
    //reverseWord(s,e-1);
    //printf("%s\n", p);    //输出c风格的字符串用cout会出现末尾%的情况，如果用printf可以避免这个问题

    char p[]="Today is Friday!";
    reverseStence(p);
    printf("%s\n", p);

    return 0;
}
