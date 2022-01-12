法1：队列q，重复题，时间还是久了点，关键点是转换为完全二叉树，缺少的节点用null表示，便于区分，不为空则入队，解string时先分解data，然后根据父节点和子节点下标的关系确定左右子节点并入队
时间(N)  空间O(N)
执行用时：28 ms, 在所有 C++ 提交中击败了98.71% 的用户
内存消耗：32.1 MB, 在所有 C++ 提交中击败了72.89% 的用户
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(!root)    return res;
        queue<TreeNode*> q;
        q.push(root);
        res += to_string(root->val) + ",";    // 注意写法，可以在 += 后面直接写 + ，用逗号区分每个节点的数字间隔
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(!temp->left)    res += "null,";    // 左右分别讨论是否为空节点，若空则不入队，只在原string后加 null 即可
            else    
            {
                res += to_string(temp->left->val) + ",";
                q.push(temp->left);
            }
            if(!temp->right)    res += "null,";
            else    
            {
                res += to_string(temp->right->val) + ",";
                q.push(temp->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())    return NULL;
        vector<string> v;
        string s;
        for(auto d : data)    // 根据逗号位置分割字符串
        {
            if(d == ',')    
            {
                v.push_back(s);
                s = "";
            }
            else s += d;
        }
        TreeNode* root = new TreeNode(stoi(v[0]));  // 建立根节点，用于返回值
        queue<TreeNode*> q;
        q.push(root);
        for(int i = 0; i <= v.size()/2-1; ++i)    // 父节点下标最多到 v.size()/2-1
        {
            TreeNode* temp = q.front();
            q.pop();
            if(v[2*i+1] != "null")    
            {
                temp->left = new TreeNode(stoi(v[2*i+1]));
                q.push(temp->left);
            }
            if(v[2*i+2] != "null")    
            {
                temp->right = new TreeNode(stoi(v[2*i+2]));
                q.push(temp->right);
            }
        }
        return root;
    }
};
