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
    void dfs(TreeNode* root, int targetSum){    //常规BFS写法，后序遍历，注意剪枝
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

改进版：不用BFS，而是第一次遍历的是起点，不会求和累加。确定起点之后的第二次遍历，经过的所有节点都会被累加，成为路径和的一部分
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return pathWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);  
        //！！！注意这里是两个不同的函数！！！我擦，看了好久没看出来，气死了，算自己节点的pathWith(Root)函数并递归计算左右节点path(Sum)函数
    }

    int pathWithRoot(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + pathWithRoot(root->left, sum) + pathWithRoot(root->right, sum);
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
