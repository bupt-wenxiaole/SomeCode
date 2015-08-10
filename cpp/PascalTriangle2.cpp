#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <ctime>
#include <string>
#include <queue>

using namespace std;


class Solution
{
public:
	std::vector<int> getRow(int rowIndex)
	{
		std::vector<int> array;
		for(int i=0;i<=rowIndex;++i)
		{
			for(int j=i-1;j>0;--j)
			{
				array[j]=array[j-1]+array[j];

			}
			array.push_back(1);

		}
		return array;
	}
};
void printvector(const std::vector<int> &v)
{
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<',';
}
int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> result=s.getRow(13);
	printvector(result);
}