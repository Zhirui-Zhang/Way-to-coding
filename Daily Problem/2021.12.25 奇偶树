法：BFS层序遍历，注意要记录上一次的节点值，写的太罗嗦了，下面有改进版
时间O(N)  空间O(N)
执行用时：224 ms, 在所有 C++ 提交中击败了82.13% 的用户
内存消耗：147.2 MB, 在所有 C++ 提交中击败了76.60% 的用户
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root->val % 2 == 0)    return false;
        queue<TreeNode*> q;
        q.push(root);
        int row = 1, cur = 0;   // 记录当前行数和上一次的节点值
        while(!q.empty())
        {
            for(int i = q.size(); i > 0; --i)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left == nullptr && temp->right == nullptr)    continue;    // 如果左右都为空没必要比较，下一个节点即可
                if(temp->left != nullptr)    // 左不为空，根据上一次节点值大小并结合本节点值是否满足奇偶情况返回，否则入队并记录左节点值
                {

                    if(row % 2 == 1)
                    {
                        if(temp->left->val % 2 == 1 || (cur != 0 && cur <= temp->left->val))    return false;   
                    }
                    else
                    {
                        if(temp->left->val % 2 == 0 || (cur != 0 && cur >= temp->left->val))    return false;
                    }
                    cur = temp->left->val;
                    q.push(temp->left);
                }
                if(temp->right != nullptr)    
                {
                    if(row % 2 == 1)         // 右不为空同理，根据上一次节点值大小并结合本节点值是否满足奇偶情况返回，否则入队并记录右节点值
                    {
                        if(temp->right->val % 2 == 1 || (cur != 0 && cur <= temp->right->val))    return false;     
                    }
                    else
                    {
                        if(temp->right->val % 2 == 0 || (cur != 0 && cur >= temp->right->val))    return false;
                    }
                    cur = temp->right->val;
                    q.push(temp->right);
                }
            }
            cur = 0;  // 一层遍历结束后，节点值归0
            ++row;    // 行数+1
        }
        return true;
    }
};

官方改进版：
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;      // 当前层数
        while (!q.empty()) {
            int size = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;  // 这里很关键，根据层数奇偶性决定前一个值是MAX 还是 MIN
            for (int i = 0; i < size; i++) {
                TreeNode * node = q.front();
                q.pop();
                int curv = node->val;
                if (level % 2 == curv % 2) {        // 如果当前节点值奇偶性和层数奇偶性相同，返回false
                    return false;
                }
                if ((level % 2 == 0 && curv <= prev) || (level % 2 == 1 && curv >= prev)) {     // 根据层数奇偶性判断节点单调性情况
                    return false;
                }
                prev = curv;        // 更新上一个节点值
                if (node->left != nullptr) {    // 将左右节点入队
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            level++;
        }
        return true;
    }
};
