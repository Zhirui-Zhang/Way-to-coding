法1：DFS，还比较好想，居然没超时
时间O(2^N)  空间O(N)
执行用时：1300 ms, 在所有 C++ 提交中击败了10.94% 的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了82.48% 的用户
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0, 0);
        return res;
    }
private:
    int res;
    void dfs(vector<int>& nums, int target, int i, int cur){
        if(i == nums.size()){
            if(cur == target){
                res++;
            }
            return;
        }
        dfs(nums, target, i+1, cur+nums[i]);
        dfs(nums, target, i+1, cur-nums[i]);
    }
};

法2：DP，经典01背包法，和之前分割子集那道题有点像，难点是把问题转换为数学公式，算法已写在笔记上，同时初始dp[0]=1和子集不太一样，递推公式也有所不同
时间O(N*M)N为nums数组长度  空间O(M)M为half大小
执行用时：4 ms, 在所有 C++ 提交中击败了97.43% 的用户
内存消耗：9.1 MB, 在所有 C++ 提交中击败了37.39% 的用户
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto num : nums){                   // 先计算整个nums数组的全部取正数时的和
            sum += num;
        }       
        if((sum + target) % 2 == 1 || abs(target) > sum){    
            // 特殊情况判断，如果总和为奇数或者目标的绝对值比sum都大时，不可能满足部分和等于该值，返回0
            return 0;
        }
        int half = (sum + target) / 2;          // dp[j]表示填满j（包括j）这么大容积的包，有dp[j]种方法
        vector<int> dp(half+1, 0);
        dp[0] = 1;                              // 注意dp[0]初始为0，即什么也不取就能满足dp[0]
        for(int i = 0; i < nums.size(); ++i){
            for(int j = half; j >= nums[i]; --j){   // 注意内层循环为倒序遍历，且终止条件至nums[i]
                dp[j] += dp[j-nums[i]];         // 递推公式
            }
        }
        return dp[half];
    }
};
