class Solution {
public:
    void dfs(int n, int x, int y, string path, vector<string>& answer)
    {
        if(y == n)
        {
            answer.push_back(path);
            return;
        }
        if(x < n)
            dfs(n, x + 1, y, path + '(', answer);
        if(x > y)
            dfs(n, x, y + 1, path + ')', answer);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        dfs(n, 0, 0, "", answer);
        return answer;
    }
};