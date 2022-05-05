法1：DFS+BFS，感觉太笨了，检查所有节点向下的所有路径，只是我想的其他巧解都写不出来
时间O(N^2)  空间O(N)
执行用时：28 ms, 在所有 C++ 提交中击败了39.98% 的用户
内存消耗：15.4 MB, 在所有 C++ 提交中击败了45.87% 的用户
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)    return 0;
        queue<TreeNode*> q;
        q.push(root);       // 先BFS，遍历所有节点，把所有节点送入DFS
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            dfs(tmp, targetSum);
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
        }
        return res;
    }
private:
    int res;
    void dfs(TreeNode* root, long targetSum){    //常规BFS写法，后序遍历，注意剪枝
        if(!root){
            return;
        }
        targetSum -= root->val;
        if(targetSum == 0){
            res++;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        targetSum += root->val;   
    }
};

改进版：不用BFS，而是双重递归，分别计算考虑root节点的值和不考虑root节点，转而计算其左右节点的路径和
时间O(N^2)  空间O(N)
执行用时：20 ms, 在所有 C++ 提交中击败了57.64% 的用户
内存消耗：15.4 MB, 在所有 C++ 提交中击败了60.43% 的用户
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)    return 0;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return res;
    }
private:
    int res;
    void dfs(TreeNode* root, long targetSum) {      // 注意这里为了避免测试用例溢出，采用long类型
        if (!root) {
            return;
        }
        targetSum -= root->val;
        if (targetSum == 0) {                       // 等于targetSum值时不能直接返回，因为继续向下计算可能还存在不同的路径符合要求
            res++;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);  
    }
};

法2：前缀和的方法，现在没啥心情了，先复制一个示例，下次一定
时间O(N)  空间O(N)
class Solution {
private:
    unordered_map<int, int> prefix;         // <前缀和，其出现次数>
    void dfs(TreeNode* root, int sum, int cur_sum, int& res)
    {
        if (!root) return;
        cur_sum += root->val;               // 更新前缀和
        // 当前路径中存在以当前节点为终点的和为sum的子路径
        if (prefix.find(cur_sum - sum) != prefix.end())
            res += prefix[cur_sum - sum];
        prefix[cur_sum]++;                  // 将当前节点加入路径
        dfs(root->left, sum, cur_sum, res); // 在其左子树中递归寻找
        dfs(root->right, sum, cur_sum, res);// 在其右子树中递归寻找
        prefix[cur_sum]--;                  // 回溯
    }
public:
    int pathSum(TreeNode* root, int sum) 
    {
        int res = 0;    // 满足条件的路径数量
        prefix[0] = 1;  // 前缀和为0的路径只有一条：哪个节点都不选
        dfs(root, sum, 0, res);
        return res;
    }
};
