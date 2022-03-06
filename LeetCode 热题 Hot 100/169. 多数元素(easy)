法1：摩尔投票法，做过略，一时居然没想起来
时间O(N)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了98.89% 的用户
内存消耗：19 MB, 在所有 C++ 提交中击败了99.03% 的用户
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, curNum = 0;
        for(auto num : nums)
        {
            if(vote == 0)   
            {
                vote++;
                curNum = num;
            }
            else if(num == curNum)    vote++;
            else    vote--;
        }
        return curNum;
    }
};
