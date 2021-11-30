法1：哈希表法，时间O(N)，空间O(N)，复杂度略高，不建议
执行用时：16 ms, 在所有 C++ 提交中击败了68.54% 的用户
内存消耗：18.4 MB, 在所有 C++ 提交中击败了27.51% 的用户
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, n = nums.size();
        unordered_map<int, int> un_map;
        for(auto num : nums)
        {
            un_map[num]++;
        }
        for(auto [k, v] : un_map)
        {
            if(v > n/2)
            {
                res = k;
                break;
            }
        }
        return res;
    }
};

法2：摩尔投票法，从头开始遍历数组，初始众数为首位元素，vote为出现次数，若相同则+1，不同则-1，
    若等于0，则相当于同归于尽，定下一个数为众数，直至遍历结束，众数一定是出现一半以上的数字
时间O(N)  空间O(1)
执行用时：4 ms, 在所有 C++ 提交中击败了99.85% 的用户
内存消耗：18.3 MB, 在所有 C++ 提交中击败了64.17% 的用户
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, mode = 0;    
        // mode表示从头开始遍历数组中的众数，vote表示当前众数的票数，若相同则+1，不同则-1，若等于0，则相当于同归于尽，定下一个数为众数
        for(auto num : nums)
        {
            if(vote == 0)    
            {
                mode = num;
                vote++;
            }
            else if(num == mode)    vote++;
            else    vote--;
        }
        return mode;
    }
};

法3：排序法，排序后中点元素一定是寻找的元素，时间O(NlogN)，空间O(logN)，代码略
