//字符流中第一个不重复出现的数字V2
#include <iostream>
using namespace std;

class FistSingleCharInStream
{
public:
    FistSingleCharInStream():index(0)
    {
        for(int i = 0; i < 256; i++)
            hash[i] = -1;
    }
    void insert(char x)
    {
        if(hash[x] == -1)
            hash[x] = index++;
        else if(hash[x] >= 0)
            hash[x] = -2;
    }
    char curFisrtSingle()
    {
        char ch = '\0';
        int minIndex = 0X7FFFFFFF;
        for(int i = 0; i < 256; i++)
        {
            if(hash[i] >= 0 && hash[i] < minIndex)
            {
                ch = (char) i;
                minIndex = hash[i];
            }
        }
        return ch;
    }


private:
    int hash[256];  //i表示字符对应的ASC2值，hash[i] = -1时表示该字符尚未出现， >= 0表示该字符首次出现时的
                    //在字符流中的下标，= -2 时表示该字符重复出现过。
    int index;
};

int main(int argc, char const *argv[])
{
    FistSingleCharInStream fs;
    char temp; 
    while(cin >> temp)
    {
        fs.insert(temp);
        cout << fs.curFisrtSingle() << endl;
    } 
    return 0;
}