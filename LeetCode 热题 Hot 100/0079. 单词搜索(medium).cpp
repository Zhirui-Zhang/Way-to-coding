法1：DFS，做过的题却卡在一个细节上，还得巩固啊，自己写的不太好，后面有以前抄的版本，有待改善
时间O(3^K*M*N)  空间O(K)K为word长度
执行用时：184 ms, 在所有 C++ 提交中击败了91.19% 的用户
内存消耗：7.8 MB, 在所有 C++ 提交中击败了49.61% 的用户
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size();++j)
            {
                if(dfs(board, word, i, j, 0))    return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int m, int n, int pos)
    {
        if(pos == word.size() - 1 && board[m][n] == word[pos])    return true;
        if(board[m][n] != word[pos])    return false;
        else    // else为当board[m][n] == word[pos]但还没全部匹配成功时
        {
            int temp = board[m][n];
            board[m][n] = '/';
            bool res = ((m-1>=0 && dfs(board, word, m-1, n, pos+1)) || (m+1<board.size() && dfs(board, word, m+1, n, pos+1)) 
                    || (n-1>=0 && dfs(board, word, m, n-1, pos+1)) || (n+1<board[0].size() && dfs(board, word, m, n+1, pos+1)));
            board[m][n] = temp;
            return res;
        }
    }
};

以前版本：
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
