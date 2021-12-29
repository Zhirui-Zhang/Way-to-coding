法1：四指针暴力法，只向前不后退，遍历到所有的四元组合后退出
时间O(N^4)  空间O(1)
执行用时：140 ms, 在所有 C++ 提交中击败了40.68% 的用户
内存消耗：10.2 MB, 在所有 C++ 提交中击败了68.77% 的用户
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        for(int a = 0; a < nums.size() - 3; a++)
        {
            for(int b = a + 1; b < nums.size() - 2; b++)
            {
                for(int c = b + 1; c < nums.size() - 1; c++)
                {
                    for(int d = c + 1; d < nums.size(); d++)
                    {
                        if(nums[a] + nums[b] + nums[c] == nums[d])    res++;
                    }
                }
            }
        }
    return res;
    }
};

法2：哈希表法，存储nums[d]，注意c是倒序前进的，从倒数第二个下标向前遍历，直至nums[2]，每次更新nums[c+1]的哈希值，就相当于d了
时间O(N^3)  空间O(min(n,C))
执行用时：36 ms, 在所有 C++ 提交中击败了74.80% 的用户
内存消耗：10.6 MB, 在所有 C++ 提交中击败了22.83% 的用户
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> un_map;
        for (int c = n - 2; c >= 2; --c) {
            ++un_map[nums[c + 1]];
            for (int a = 0; a < c - 1; ++a) {
                for (int b = a + 1; b < c; ++b) {
                    int sum = nums[a] + nums[b] + nums[c];
                    if (un_map.count(sum)) {
                        ans += un_map[sum];
                    }
                }
            }
        }
        return ans;
    }
};

法3：哈希表进阶，存储nums[d]-nums[c]，先逆序枚举 b。在 b 减小的过程中，c 的取值范围是逐渐增大的：即从 b+1 减小到 b 时，c 的取值范围中多了 b+1 这一项，而其余的项不变
因此我们只需要将所有满足 c=b+1 且 d>c 的 c,d 对应的 nums[d]−nums[c] 加入哈希表即可
时间O(N^2) 空间O(min(n,C)^2)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> un_map;
        for (int b = n - 3; b >= 1; --b) {
            for (int d = b + 2; d < n; ++d) {
                ++un_map[nums[d] - nums[b + 1]];
            }
            for (int a = 0; a < b; ++a) {
                int sum = nums[a] + nums[b]; 
                if (un_map.count(sum)) {
                    ans += un_map[sum];
                }
            }
        }
        return ans;
    }
};
