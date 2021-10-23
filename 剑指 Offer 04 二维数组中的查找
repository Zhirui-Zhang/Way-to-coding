法1：逐行二分法，时间复杂度O(mlogn)
执行用时：20 ms, 在所有 C++ 提交中击败了79.87% 的用户
内存消耗：12.6 MB, 在所有 C++ 提交中击败了90.80% 的用户
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())  return false;
        int left = 0, right = matrix[0].size() - 1, n = matrix[0].size() - 1, m = matrix.size();
        for(int i = 0; i < m; i++)
        {
            left = 0; right = n;
            while(left <= right)
            {
                int mid = (left + right) / 2;
                if(matrix[i][mid] > target)
                {
                    right = mid - 1;
                }
                else if(matrix[i][mid] < target)
                {
                    left = mid + 1;
                }
                else return true;
            }       
        }
        return false;
    }
};

法2：当成二叉搜索树做，以左下角元素为根节点，上面数小于它，右面数字大于它，时间复杂度O(M+N)
执行用时：24 ms, 在所有 C++ 提交中击败了44.53% 的用户
内存消耗：12.7 MB, 在所有 C++ 提交中击败了64.69% 的用户
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = 0, m = matrix.size() - 1;
        while(m >= 0 && n < matrix[0].size())   
        //这里两句语句是有顺序的，如果反过来写当matrix为[]时访问matrix[0]会发生索引越界异常，而这样写会产生短路效应，有效地避免matrix为[]或者为[[]]的情况！！
        //注意[]为空，即0行0列，[[]]为一行0列
        {
            if(matrix[m][n] < target)    n++;
            else if(matrix[m][n] > target)    m--;    
            else return true;
        }
        return false;
    }
};
