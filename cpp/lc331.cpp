class Solution {
public:
    //二叉树n个节点，2n个指针，其中有(n - 1)个空指针，（除了根节点外每个节点都有一个指针指向它）, 2n - (n - 1) = n + 1个空指针
    bool isValidSerialization(string preorder) {
        //首先c++中没有split函数，通过istringstream来完成这个功能
        vector<string> temp_preorder;
        string token;
        istringstream iss(preorder);
        while(getline(iss, token, ','))
        {
            temp_preorder.push_back(token);
        }
        int count = 0;
        for(int i = 0; i < temp_preorder.size() - 1; ++i)
        {
            if(i == 0 && temp_preorder[i] == "#")
                return false;
            if(temp_preorder[i] != "#")
                count++;
            else
            {
                if(count == 0)  //出现连续的三个#
                    return false;
                count--;
            }
        }
        if(count == 0 && temp_preorder[temp_preorder.size() - 1] == "#") //最后一个一定是null,之前的null和非空节点个数相同
            return true;
        else
            return false;
    }
};