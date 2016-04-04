/************************************************************************************************
@字符串转换为整数：比如"345"转换为345
@要注意的点：1.判断是否为空。2.记录前面的正负号。3.判断输入是否合法，即每个字符是否在0－9之间。4.判断是否会溢出
主要循环只有一句:之前的数*10+当前的数
int num=0;
char* digit=str;
while(*digit!='\0')
{
    num=num*10+(*digit-'\0')
    
}
@xiaolewen_bupt
@2016/04/04
************************************************************************************************/
#include <iostream>
#include <assert.h>
using namespace std;
enum status { valid=0, invalid }; //枚举类型  标志转换出的结果是否有效
status st;
int strtoint(const char* str)
{
    st=invalid;
    assert(str!=NULL);
    const char *digit=str;
    bool minus=false;

    if(*digit=='+')
    {
        digit++;
    }
    else if(*digit=='-')
    {
        digit++;
        minus=true;
    }

    long long num=0;

    while(*digit !='\0')
    {
        if(*digit>='0' && *digit <='9')
        {
            num=num*10+(*digit-'0');
            if(num > std::numeric_limits<int>::max())
            {
                num=0;
                break;
            }
            digit++;
        }
        else
        {
            num=0;
            break;
        }
    }
    if('\0' == *digit)
    {
        st=valid;
        if(minus)
            num=0-num;
    }
    return num;
}

int main(int argc, char const *argv[])
{
    //const char *p="33232";
    //const char *p="+33232";
    //const char *p="-33232";
    const char *p="320ab3";
    int num=strtoint(p);
    cout<<num;
    return 0;
}