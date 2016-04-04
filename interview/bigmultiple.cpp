/*********************************************************************
@大整数乘法:与手算加法略有不同，先算好每一位上进位之前的数字，然后扫描一遍进位
@xiaolewen_bupt
@2016/04/04
*********************************************************************/
#include <string.h>
#include <iostream>
using namespace std;

void  multi(const char*a,const char *b)
{

    int la=strlen(a);
    int lb=strlen(b);
    int *result= new int[la+lb];
    memset(result,0,sizeof(int)*(la+lb));   //memset函数把从第一个参数开始，长度为第三个参数个字节的内存全部置为0

    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            result[i+j+1]+=(a[i]-'0')*(b[j]-'0');   //注意是'0'而不是'\0','\0'用于字符串结束
        }
    }
    for(int i=la+lb-1;i>=0;i--)
    {
        result[i-1]+=result[i]/10;
        result[i]%=10;
    }
    for (int i=0;i<la+lb;i++)
    {
        cout<<result[i];
    }
    delete []result;
}

int main(int argc, char const *argv[])
{
    const char* a="23";
    const char* b="47";
    multi(a,b);

    return 0;
}

