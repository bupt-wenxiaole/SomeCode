#include <set>
#include <iostream>
#include <vector>
using namespace std;

typedef multiset<int, greater<int> > BigHeap;
typedef multiset<int, greater<int> > :: iterator BigHeapIter;


void GreatLeastK(const vector<int>& data, int length, BigHeap& result, int k)
{
    if(length <=0 || k <= 0)
        return;
    for(int i = 0; i < length; i++)
    {
        BigHeapIter iter = result.begin();
        if(result.size() < k)
        {
            result.insert(data[i]);
        }
        else if(data[i] < *iter)
        {
            result.erase(iter);
            result.insert(data[i]);
        }
            
    }    
}

int main(int argc, char const *argv[])
{
    int data_array[] = {10, 2, 5, 3, 22 ,20, 4, 5};
    vector<int> test(data_array, data_array+8);
    BigHeap result;
    GreatLeastK(test, 8, result, 2);
    BigHeapIter iter = result.begin();
    for( ; iter != result.end(); iter++)
    {
        cout << *iter << " ";

    }
    cout << endl;
    return 0;
}
