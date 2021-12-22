法1：双指针法，其实就是滑动窗口，设置左右两个指针，重点是※两个指针都只前进不后退※，直接两者相遇退出循环
先排除暴力法，太复杂，我自己想到的双指针太麻烦了，需要新建从1~target/2的数组再遍历，直接超时，可能是空间超出了
时间O(N)左右指针均移(target/2+1)  空间O(1)不算答案中已经所需的数组，只需要常数的存储空间
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了61.93% 的用户
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;    // 结果数组  target至少是3 当target=1or2时res为空
        vector<int> temp;           // 临时数组
        int left = 1, right = 2;    // 注意，这里的两个指针都只加不减，很关键，免得还得回头，太麻烦了
        while(left < right)         // 退出条件，其实这里就是两者都等于target/2 + 1
        {
            int sum = (left + right) * (right - left + 1) / 2;
            if(sum == target)
            {
                temp.clear();       // 记得先清空临时数组
                for(int i = left; i <= right; i++)
                {
                    temp.push_back(i);
                }   
                res.push_back(temp); 
                left++;
            }
            else if(sum > target)    left++;  // 和大了左指针移
            else    right++;                  // 和小了右指针移
        }
        return res;
    }
};

法2：二次函数求根公式解的，代码略，复杂度同上
