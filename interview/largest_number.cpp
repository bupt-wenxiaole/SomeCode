#include <string>
#include <iostream>
#include <vector>
using namespace std;


static bool compare(string &s1,string &s2)
{
    return s1+s2>s2+s1;
}

string largestNumber(vector<int> &num)
{
    vector<string> arr;

    for(int i : num)
        arr.push_back(to_string(i));

    sort(arr.begin(), arr.end(),compare);

    string ret;
    for(string s:arr)
        ret+=s;

    if(ret[0]=='0' && ret.size()>0)       //如果输入的数组是[0,0,0,0,0],则返回"0"即可，即排序完第一个数是0，那么后面的所有数都是0
        return "0";
    return ret;

}

int main(int argc, char const *argv[])
{
    int num[5]={3,30,34,5,9};

    vector <int> v(num,num+5);
    string result=largestNumber(v);
    cout<<result<<endl;
    return 0;
}