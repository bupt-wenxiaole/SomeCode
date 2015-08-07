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

class Solution{
public:
	std::vector<std::vector<int> > generate(int numRows)
	{
		vector<vector<int> > result;
		
		if (numRows==0)
			return result;
		result.push_back(vector<int>(1,1));  //第一行
		for(int i=2;i<=numRows;++i)
			{
				vector<int> curRow(i,1);  //当前行
				const vector<int> &prev=result[i-2];
				for(int j=1;j<i-1;++j)    //除了两头的两个1之外，剩下的元素都是上一行左上角和右上角元素之和
					{
						curRow[j]=prev[j-1]+prev[j];
					}
				result.push_back(curRow);
			}

		return result;
				
	}
};
void printvector(const vector<vector<int> > &v)
{
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<v[i].size();++j)
			cout<<v[i][j]<<',';
		cout<<endl;
	}
		
}
int main(int argc, char const *argv[])
{
	Solution s;
	vector<vector<int> > result=s.generate(5);
	printvector(result);
	return 0;
}



