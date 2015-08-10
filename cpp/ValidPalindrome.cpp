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
	bool isPalindrome(string s)
	{
		transform(s.begin(),s.end(),s.begin(),::tolower);
		string::iterator left=s.begin(),right=s.end();
		while(left<right)
		{
			if (!::isalnum(*left))
				left++;
			else if(!::isalnum(*right))
				right--;
			else if((*left)!=(*right))
				return false;
			else 
				{left++,right--;}

		}
		return true;
	}
};


int main(int argc, char const *argv[])
{
	string test="abb";
	Solution s;
	bool ret=s.isPalinderome(test);
	cout<<ret<<endl;
	return 0;
}