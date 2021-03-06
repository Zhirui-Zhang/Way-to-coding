法1：DFS优先搜索，自己的方法，空间复杂度有点低
执行用时：4 ms, 在所有 C++ 提交中击败了95.64% 的用户
内存消耗：19.5 MB, 在所有 C++ 提交中击败了38.35% 的用户
class Solution {
public:
    void calSum(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& temp, int cur)
    {
        if(root == NULL)    return;
        else if(root->left == NULL && root->right == NULL)
        {
            if(cur + root->val == target)   //这里不让cur += root->val是为了防止cur发生改变
            {
                temp.push_back(root->val);
                res.push_back(temp);
                temp.erase(temp.end() - 1);     //注意删去temp最后一个节点再返回
            }
            return;
        }
        else
        {
            cur += root->val;
            temp.push_back(root->val);
            calSum(root->left, target, res, temp, cur);
            calSum(root->right, target, res, temp, cur);
            cur -= root->val;      //注意改变cur值并删去temp最后一个节点再返回
            temp.erase(temp.end() - 1);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;  //最终输出二维数组
        vector<int> temp; //临时存放一维数组
        int cur = 0;  //当前路径和
        calSum(root, target, res, temp, cur);
        return res;
    }
};

改进版：
执行用时：8 ms, 在所有 C++ 提交中击败了76.81% 的用户
内存消耗：19.3 MB, 在所有 C++ 提交中击败了78.58% 的用户
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void calSum(TreeNode* root, int target, int cur)
    {
        if(root == NULL)    return;
        cur += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && cur == target)    res.push_back(temp);
        calSum(root->left, target, cur);
        calSum(root->right, target, cur);
        cur -= root->val;      //注意改变cur值并删去temp最后一个节点再返回
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        calSum(root, target, 0);
        return res;
    }
};
