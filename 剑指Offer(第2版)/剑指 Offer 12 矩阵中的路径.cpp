法1：DFS搜索，也就是递归调用，需要注意的细节比较多，好好回顾一下
思考一下复杂度，时间为O(3^k*M*N)，因为每次除了不往回走剩下三个方向，最多各去k次，外部最多遍历M*N，
             空间为O(k)，因为递归深度最多为k，函数返回后，系统调用的栈空间会释放
执行用时：12 ms, 在所有 C++ 提交中击败了99.23% 的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了94.47% 的用户
class Solution {
public:
    bool aroundExist(vector<vector<char>>& board, int i, int j, string& word, int k)  //这里调用函数注意形参string &为引用word拷贝，否则复制拷贝浪费大量时间！！！
    {
        int n = board.size(), m = board[0].size();
        if(i < 0 || i >=n || j < 0 || j >= m || board[i][j] != word[k])    return false;    
        //这里是关键点，判断返回false和true的条件，只有当word遍历完成即k = word.size()-1时才返回true
        if(k == word.size() - 1)    return true;
        board[i][j] = ' ';      //将当前board中的元素设为空，防止重复搜索；
        //以 下->右->左->上的顺序依次搜索下一个word中的字符
        if(aroundExist(board, i + 1, j, word, k + 1) || aroundExist(board, i, j + 1, word, k + 1) || 
           aroundExist(board, i, j - 1, word, k + 1) || aroundExist(board, i - 1, j, word, k + 1))
                return true;
        board[i][j] = word[k];  //无论递归搜索成功与否，将board置为原始值，防止下一次搜索时该值改变了
        //同时，如果找到完全一样的字符串，一路返回true，不必还原board的值，直接出去就行了
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())    return false;   //其实判断空可以省略，题目说明不为空
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if(aroundExist(board, i, j, word, 0))    return true;
        }
        return false;
    }
};
