法1：递归调用+左右子树分治，自己想出了主要解法，判断递归条件时i的位置出现失误，应使用双指针i j
时间O(n^2)→递归N乘遍历N  空间O(n)→递归深度
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了42.51% 的用户
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty() || postorder.size() == 1)    return true;  //特殊情况处理，可省略
        return isTree(postorder, 0, postorder.size()-1);
    }

private:
    bool isTree(vector<int>& postorder, int left, int right)
    {
        if(left >= right)    return true;  //返回条件，没有左子树时j-1<right即left>right，左子树为1时left=right，都为真
        int i = left;
        for(; i < right; i++)
        {
            if(postorder[i] > postorder[right])    break;
        }
        int j = i;  //j为当前最后一个right根节点的左子树位置，i为右子树位置，i的值理应等于right，即右半部分的val值都大于root
        for(; i < right; i++)
        {
            if(postorder[i] < postorder[right])     break;
        }
        return (i == right) && isTree(postorder, left, j-1) && isTree(postorder, j, right-1); //分治：分别调用左右子树
    }
};

法2：利用单调栈，反向遍历数组入栈并记录根节点值，想不到，故省略，可以看答案解析尝试理解。
时间空间复杂度均为O(N)
