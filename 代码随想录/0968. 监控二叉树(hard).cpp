法1：贪心+DFS，难点在于分析当前节点的三个状态，0表示未被覆盖，1表示有摄像头，2表示已被覆盖
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了76.41% 的用户
内存消耗：20.8 MB, 在所有 C++ 提交中击败了14.16% 的用户
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) ++res;      // 注意特殊情况的判断，当左右节点都是有覆盖时，根节点无覆盖，必须在根节点加一个摄像头
        return res;
    }
private:
    int res;
    int dfs(TreeNode* root) {           // 需要遍历整棵树且处理返回的状态，故需要返回值
        // 0表示未被覆盖，1表示有摄像头，2表示已被覆盖
        if (!root) return 2;            // 很关键，如果为空节点，为使得其爷爷节点增加摄像头，需要假设其被覆盖
        int left = dfs(root->left);
        int right = dfs(root->right);   // 后序遍历，记录左右节点状态
        if (left == 0 || right == 0) {          // 左右有一个未被覆盖，就得增加一个摄像头，并返回1
            ++res;                      
            // 注意这条语句需要先处理，防止当前节点左侧有摄像头，右侧没有，导致left = 2, right = 0，需要加一个摄像头的情况
            return 1;
        } else if (left == 2 && right == 2) {
            return 0;  // 左右均为2，则未被覆盖，返回0
        } else {
            return 2;  // 否则说明左右至少有一个摄像头，且左右节点都被覆盖，可返回2状态
        }
    }
};