//字符流的中位数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T> 
class dynamicArray
{
public:
    void Insert(T num)
    {
        if(((min.size() + max.size()) & 0x1)== 0)  //0,2,4..... 插入大顶堆
        {
            if(min.size() > 0 && num > min[0]) //该插入大顶堆的元素比小顶堆中有些元素大。需要进行一次置换
            {
                min.push_back(num); //将该元素插入小顶堆
                push_heap(min.begin(), min.end(), greater<T>());  //重新调整小顶堆，现在的堆顶是最小的那个值，这个值需要放到大顶堆里
                num = min[0]; //保存该值，然后删除该值
                pop_heap(min.begin(), min.end(), greater<T>()); //第一个元素放到了堆的最后，其余元素构成一个小顶堆
                min.pop_back();
            }
            //正常情况下，该数应该插入大顶堆中中
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
        else //1, 3, 5, 7 ....插入小顶堆
        {
            if(min.size() > 0 && num < max[0])  //该数字应该插入小顶堆中，但发现该数字不符合小顶堆的所有数字都比大顶堆中的所有数字大
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());
                num = max[0]; //拿到大顶堆中最大的那个数，插入到小顶堆中，使其保持原来的性质
                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
    }
    T getMidNum()
    {
        T sizeSum = min.size() + max.size();
        if(sizeSum == 0)
            throw logic_error("empty!");   //使用exception的派生类
        if((sizeSum & 0x1) == 0)
            return sizeSum / 2;
        else
            return max[0];
    }    
private:
    vector<T> min; //小顶堆，包含大的那批元素
    vector<T> max; //大顶堆，包含小的那批元素

    /* data */
};
int main(int argc, char const *argv[])
{
    dynamicArray<int> da;
    int temp;
    while(cin >> temp)
    {
        da.Insert(temp);
        cout << da.getMidNum() << endl;
    }
    return 0;
}