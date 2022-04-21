法1：单调栈法，存储元素的位置，只有当当前元素比栈顶元素值大时才弹出栈顶元素，并计算当前矩形面积，否则持续入栈
时间O(N)  空间O(N)  
执行用时：16 ms, 在所有 C++ 提交中击败了10.49% 的用户
内存消耗：17.7 MB, 在所有 C++ 提交中击败了5.04% 的用户
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> s;
        for(int i = 0; i < height.size(); ++i)
        {
            while(!s.empty() && height[i] > height[s.top()])    // 当前值大于栈顶时，考虑计算矩形面积
            {
                int temp = s.top();
                s.pop();                  // 先记录栈顶元素位置，后弹出
                if(s.empty())    break;   // 若弹出后栈为空，说明无法构成矩形，break
                int width = i - s.top() - 1;      // 分别计算矩形的长和宽，注意计算方式
                int length = min(height[i], height[s.top()]) - height[temp];
                res += width * length;    // 加入到res结果中
            }
            s.push(i);        // 将新元素的位置入栈
        }
        return res;
    }
};

法2：双指针法，分别记录左右指针的当前位置和历史最高值
时间O(N)  空间O(1)
执行用时：12 ms, 在所有 C++ 提交中击败了37.09% 的用户
内存消耗：17.3 MB, 在所有 C++ 提交中击败了5.04% 的用户
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int leftHeight = 0, rightHeight = 0;
        while(left < right)     // 左右指针相等时没意义，不可能组成矩形，所以当left==right时退出循环
        {
            leftHeight = max(height[left], leftHeight);     // 记录左右历史最高值
            rightHeight = max(height[right], rightHeight);
            if(leftHeight < rightHeight)        // 哪边矮说明可能与历史最高值之间存在高度差，计算一下然后移动该指针
            {
                res += leftHeight - height[left];
                left++;
            }
            else
            {
                res += rightHeight - height[right];
                right--;
            }
        }
        return res;
    }
};
