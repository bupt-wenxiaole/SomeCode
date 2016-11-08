#include <iostream>
#include <vector>
using namespace std;

template<typename C>
void print2nd(const C& container)
{
    if(container.size() >= 2)
    {
        typename C::const_iterator iter(container.begin()); //使用关键字typename标示嵌套从属类型
        ++iter;
        int value = *iter;
        cout << value;
    }
}
template<typename IterT>
void workWithIterator(IterT iter)
{
    typedef typename iterator_traits<IterT>::value_type value_type; 
    value_type temp(*iter);
    cout << temp << endl;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4};
    vector<int> vi(arr, arr + 4); 
    print2nd<vector<int> >(vi);
    cout << "\n";
    vector<string> vs = {"abc", "def", "ghi"}; 
    for(auto iter = vs.begin(); iter != vs.end(); ++iter)
        workWithIterator(iter);
    return 0;
}