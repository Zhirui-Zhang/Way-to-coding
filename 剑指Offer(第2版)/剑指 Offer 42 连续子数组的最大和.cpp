法1：动态规划法，想不明白啊啊啊啊，自己好蠢
执行用时：20 ms, 在所有 C++ 提交中击败了62.27% 的用户
内存消耗：22.4 MB, 在所有 C++ 提交中击败了51.42% 的用户
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //if(nums.empty())    return 0;     不需要这句话，题目中已经说明数组不为空
        int res = nums[0], cur = nums[0];       //令res cur均为nums[0]
        for(int i = 1; i < nums.size(); i++)    //从nums[1]开始迭代即可
        {
            cur = max(nums[i], nums[i]+cur);    
            //cur决定是更新历史最大值还是抛弃它，使用新的数组元素作为最大值
            res = max(res, cur);
            //res其实就是记录cur的历史最大值，作为最终输出
        }
        return res;
    }
};
