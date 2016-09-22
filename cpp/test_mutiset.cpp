#include <iostream>
#include <set>
#include <vector>
#include <typeinfo>
using namespace std;

int main(int argc, char const *argv[])
{   
    int a[] = {0, 1, 2, 3, 3, 3,4, 5};
    vector<int> vi(a, a + 8);
    multiset<int> msi(vi.begin(), vi.end());
    cout << typeid(multiset<int>::key_type).name() << endl;
    auto begin = msi.lower_bound(3);
    auto end = msi.upper_bound(3);
    while(begin != end)
    {
        cout << *begin << endl;
        ++begin;
    }
    pair<multiset<int>::iterator, multiset<int>::iterator> res = msi.equal_range(3);
    while(res.first != res.second)
    {
        cout << *res.first << endl;
        res.first++;
    }
    return 0;
}