法1：原地修改法，很巧妙，关键是当左子树不为空时，一路遍历直至找到左子树的最右节点，交换两次后将左子树置空，再进行下一轮右子树的循环
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了85.57% 的用户
内存消耗：12.3 MB, 在所有 C++ 提交中击败了67.20% 的用户
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root)                                           // 当根节点非空时进入循环交换
        {
            if(root->left)
            {
                TreeNode* temp = root->left;
                while(temp->right)    temp = temp->right;     // 目的是找到当前根节点下左子树的最右节点，即例中节点4的位置
                temp->right = root->right;                    // 让4的右节点指向5
                root->right = root->left;                     // 让1的右节点指向2
                root->left = nullptr;                         // 让1的左节点指向空
            }
            root = root->right;                               // 开始下一轮遍历
        }
        return;
    }
};

法2：DFS递归法，其实用前序遍历就可以，只不过题目中进阶要求空间为O(1)
时间O(N)  空间O(N)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)    return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->left;
        if(temp==NULL)    return;
        while(temp->right)    temp=temp->right;
        temp->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};

法3：BFS，借助栈进行一次前序遍历即可，注意设置两个节点，root随便一定，最后再让root等于需要返回的节点

！！！
注意在尝试BFS的时候，每次我借助之前写的前序遍历代码时都会报错，信息为
Line 171: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0b6 for type 'TreeNode *', which requires 8 byte alignment (stl_deque.h)
0xbebebebebebec0b6: note: pointer points here
妈的，弄了一下午都不知道为啥会报错，用官方题解一下子就通过了，艹
更新：
终于是他妈的弄明白了，整了半天是抄的前序遍历模板代码有问题，在最后的时候可能发生s为空并访问的情况，所以要提前判断一下是否会为空，ctmd你自己没试试就发题解啊，害老子白忙活一下午
！！！

执行用时：12 ms, 在所有 C++ 提交中击败了5.19% 的用户
内存消耗：12.4 MB, 在所有 C++ 提交中击败了58.51% 的用户
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = new TreeNode(0);        // 新建一个节点用来返回，最后已经将原树的结构修改过了，所以不用指定返回哪个具体节点
        while(root || !s.empty())     
        {
            while(root)                
            {
                if(root->right)    s.push(root->right);
                cur->right = root;
                cur->left = nullptr;
                cur = cur->right;
                root = root->left;
            }
            if(!s.empty())
            {
                root = s.top();               
                s.pop();
            }
        }
        return; 
    }
};
