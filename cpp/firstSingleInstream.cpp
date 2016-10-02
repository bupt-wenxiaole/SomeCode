//字符流中第一个只出现一次的字符
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void operationMap(char cur,map<char, int>& hash)
{
    map<char, int>::iterator iter = hash.find(cur);
    if(iter == hash.end())
        hash[cur] = 1;
    else
        iter -> second++;
}

int main(int argc, char const *argv[])
{
    char cur;
    string res;
    map<char, int> mapi;
    while(cin >> cur)
    {
        res += cur;
        cout << res << endl; 
        operationMap(cur, mapi);
        for(int i = 0; i < res.length(); i++)
        {
            if(mapi[res[i]] == 1)
            {
                cout << res[i] << endl;
                break;
            }

        }
    }
    return 0;
}
