class Solution {
public:
    bool findTarget(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int target)
    {
        if(x1 > x2 || y1 > y2)
            return false;
        int midx = (x1 + x2) / 2;
        int midy = (y1 + y2) / 2;
        if(target == matrix[midx][midy])
            return true;
        return target > matrix[midx][midy] ?
        (findTarget(matrix, midx + 1, y1, x2, midy, target) || findTarget(matrix, x1, midy + 1, x2, y2, target)):
        (findTarget(matrix, midx, y1, x2, midy - 1, target) || findTarget(matrix, x1, y1, midx - 1, y2, target));
            
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        return findTarget(matrix, 0, 0, m - 1, n - 1, target);
    }
        
};