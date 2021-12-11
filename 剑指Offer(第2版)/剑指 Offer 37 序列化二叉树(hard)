法1：独创秘籍，如果左子树为空加入字符'L'，右子树为空加入字符'R'，否则在每个子树的val后面加上'+'，即当树为[1,3,NULL,NULL,4]时，string为"1+3+RL4+LR"
时间O(N)  空间O(N)
执行用时：32 ms, 在所有 C++ 提交中击败了93.94% 的用户
内存消耗：27.8 MB, 在所有 C++ 提交中击败了96.59% 的用户
class Codec {
public:

    // 将输入的树变为字符串，正常的BFS算法，利用队列q实现层序遍历，注意函数to_string()的应用
    string serialize(TreeNode* root) {
        string res;
        if(root == NULL)    return res;
        queue<TreeNode*> q;
        q.push(root);
        res += to_string(root->val);
        res += '+';
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL)     
            {
                q.push(temp->left);
                res += to_string(temp->left->val);
                res += '+';
            }
            else    res += 'L';   // 若左子树不为空，入队并'+'，若为空，填入'L'
            if(temp->right != NULL)     
            {
                q.push(temp->right);
                res += to_string(temp->right->val);
                res += '+';   
            }
            else    res += 'R';   // 若右子树不为空，入队并'+'，若为空，填入'R'
        }
        return res; 
    }

    // 将字符串再转变为树，利用双指针记录字符串中某个数值的前后顺序（如-1  20这种就占两个字符位），注意及时调整指针的位置，此外，※将字符串转换为数字利用函数stoi()※
    TreeNode* deserialize(string data) {
        if(data.empty())    return NULL;
        int pre = 0, cur = 0;   // 首尾指针
        while(data[cur] != '+')    cur++;   // 先找到根节点的值并构造出相应的string num，然后构建根节点并将其入队
        string num(data, pre, cur - pre);
        pre = ++cur;
        TreeNode* root = new TreeNode(stoi(num));
        queue<TreeNode*> q;
        q.push(root);
        bool leftTree = false;              // 设置布尔变量，记录下一个节点是右子树还是左子树
        for(; cur < data.size(); cur++)
        {
            if(data[cur] == 'L')
            {
                pre = cur + 1;              // 这里注意如果是L或者R或者+时，下一个就有可能是数字了，因此将pre指针移动至cur下一位，而当else时一定是数字，所以不能移动pre指针
                leftTree = true;            // 下一次是右子树
            }
            if(data[cur] == 'R')
            {
                leftTree = false;           // 下一次是左子树
                pre = cur + 1;
                q.pop();                    // 同时弹出当前节点
            }
            if(data[cur] == '+')            // 重点是出现+时，记录之前所有的字符并转化为数值，建立son节点入队，根据bool值判断该插入左or右子树，若插入右子树后应出队parent节点
            {
                TreeNode* parent = q.front();
                string num(data, pre, cur - pre);
                TreeNode* son = new TreeNode(stoi(num));
                q.push(son);
                if(leftTree)    // 插入右子树
                {
                    parent->right = son;
                    q.pop();
                }
                else            // 插入左子树
                {
                    parent->left = son;
                }
                leftTree = !leftTree;         // 将bool值取反
                pre = cur + 1;
            }
        }
        return root;
    }
};

网上的版本：看起来不错，将原树变为完全二叉树，空节点记为NULL，每个节点之间用 , 隔开
class Codec {
public:
    string serialize(TreeNode* root) {
        string res;
        // 如果根为空
        if(root == nullptr) {
            return res;
        } 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* demo = q.front();
            q.pop();
            if(demo != nullptr) {
                res += to_string(demo -> val) + ",";
                q.push(demo -> left);
                q.push(demo -> right);
            } else {
                res += "null,";
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if(data == "") {
            return nullptr;
        }
        vector<string> vals;
        // 根据 , 分割字符串，vals中存放的是每个节点对应的字符串，空节点为NULL
        string s;
        for(int i = 0; i < data.size(); i ++) {
            if(data[i] == ',') {
                vals.push_back(s);
                s = "";
            } else {
                s += data[i];
            }
        }
        TreeNode* root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode*> q;
        q.push(root);
        // 标记当前根的位置
        int i = 0;
        while(!q.empty()) {
            TreeNode* demo = q.front();
            q.pop();
            // 有左节点
            if(vals[i * 2 + 1] != "null") {
                demo -> left = new TreeNode(atoi(vals[i * 2 + 1].c_str()));
                q.push(demo -> left);
            }
            // 有右节点
            if(vals[i * 2 + 2] != "null") {
                demo -> right = new TreeNode(atoi(vals[i * 2 + 2].c_str()));
                q.push(demo -> right);
            }
            i ++;
        }
        return root;
    }
};
