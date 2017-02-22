class Solution {
public:
    void mirror(vector<vector<int>>& matrix)
    {
        for(int i = 0, j = matrix.size() - 1;  i < j; i++, j--)
        {
            for(int k = 0; k < matrix[0].size(); k++)
            {
                swap(matrix[i][k], matrix[j][k]);
            }
        }
    }
    void trans(vector<vector<int>>& matrix)
    {
        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = i; j < matrix[0].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        mirror(matrix);
        trans(matrix);
    }
};