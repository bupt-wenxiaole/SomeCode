//简单的正则表达Parser
//对应一些与Python RE模块输出对比
#include <iostream>
#include <assert.h>
using namespace std;

bool compare(const char* p, const char* q)  //简单的一个类比函数
{
    if(p == NULL || q == NULL)
        return false;
    if(*p == '\0' && *q == '\0')
        return true;
    if(*p == '\0' || *q == '\0')
        return false;
    if(*p == *q && *p != '\0')
        return compare(p + 1, q + 1);
    else
        return false;
}
bool match(const char* str, const char *pattern)
{
    assert(str != NULL && pattern != NULL);
    if(*str == '\0' && *pattern == '\0')
        return true;
    if(*str != '\0' && *pattern == '\0')
        return true;
    //下面这个if判断比较特殊，要考虑的情况比较多
    if(*(pattern + 1) == '*')//以aaa匹配a*匹配为例
    {
        if((*str == *pattern && *str != '\0') || (*pattern == '.' && *str != '\0'))
            return match(str + 1, pattern + 2) || //a*匹配一个a
                   match(str, pattern + 2) ||   //a*匹配0个a
                   match(str + 1, pattern); //a*匹配多个a
        else
            return match(str, pattern + 2); //a*匹配0个其他字符，以aaa匹配b*为例
    }
    if((*str == *pattern && *str != '\0') || (*pattern == '.' && *str != '\0'))
        return match(str + 1, pattern + 1);
    return false;
}


int main(int argc, char const *argv[])
{
    const char *p = "abc";
    const char *q = "acc";
    cout << compare(p, q) << endl;
    //以下测试用例均与python RE模块中的match保持一致
    cout << match("aa", "aaaaa") << endl;  
    cout << match("aaa", "a*") << endl;  
    cout << match("aa", "a.") << endl;
    cout << match("aaa", "ab*a*") << endl;
    cout << match("a", "b*b") << endl;
    return 0;
}