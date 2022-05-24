法1：DP，核心思想和分割等和子集的那道题其实一样，有点没转过来弯，就是分成两堆相等的石头互撞
时间O(MN)  空间O(M)M为石头总重量的一半，N为stones数组长度
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：8.1 MB, 在所有 C++ 提交中击败了75.76% 的用户
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto s : stones) {
            sum += s;           
        }
        int half = sum / 2;             // 先计算石头总重量，然后计算一半的重量
        vector<int> dp(half + 1, 0);
        for (int i = 0; i < stones.size(); ++i) {       // DP内外层遍历，寻找是否能凑成一半重量
            for (int j = half; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[half];      // 注意最后的判断，若sum为奇数一定不成功，减去可凑成最大值的2倍即是结果
    }
};