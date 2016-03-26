#include <vector>
#include <string>
#include <iostream>

using namespace std;


void Greycode(int n,vector<string> &grey)
{
    
    if(n == 1)
    {
        grey.push_back("0");
        grey.push_back("1");
        return;
    }

    Greycode(n-1,grey);
    for(int i=0;i<grey.size();++i)   //给每个前面都加0
    {
        grey[i]='0'+grey[i];
    }
    for(int i=grey.size()-1;i>=0;--i)     //将加的0换成加的1，然后加入,注意循环必须倒叙写否则这个循环跳不出来，因为vector的长度始终在涨
    {
        string temp = grey[i];
        temp[0]='1';
        grey.push_back(temp);
    }
    return;
}

int main(int argc, char const *argv[])
{
    vector<string> res;
    Greycode(3,res);
    for (int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}