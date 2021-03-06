法1：set容器，对每个元素进行存储后遍历，但实际上复杂度应该是O(NlogN)？  因为每次插入set中需要排序,时间为logN  所以其实不满足条件  而且第二层循环中二叉搜索树find函数也为logN
时间O(NlogN)  空间O(N)
执行用时: 96 ms
内存消耗: 30.9 MB
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        int res = 1, temp = 1;
        set<int> st;
        for(auto num : nums)
        {
            st.insert(num);
        }
        for(auto s : st)
        {
            if(st.find(s+1) != st.end())    temp++;
            else    temp = 1;
            res = max(temp, res);
        }
        return res;
    }
};

法2：哈希表法，不用插入时排序，而是在第二次遍历时注意是否为连续数组的头部，是则开始循环统计个数  不是则退出  而且注意unordered_set不允许重复，即在插入过程中如果元素重复直接剔除，减少后续遍历次数
例[100 4 200 1 3 2]中，只有当遍历到 100 200 1这三个数时，会进入循环查看是否连续并计数，而到4 3 2三个数时不会进入if语句中，故时间复杂度为O(N)
官方解释：只有当一个数是连续序列的第一个数的情况下才会进入内层循环，然后在内层循环中匹配连续序列中的数，因此数组中的每个数只会进入内层循环一次
时间O(N)  空间O(N)
执行用时：52 ms, 在所有 C++ 提交中击败了85.44% 的用户
内存消耗：30 MB, 在所有 C++ 提交中击败了79.62% 的用户
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        int res = 1, temp = 1;
        unordered_set<int> st;
        for(auto num : nums)
        {
            st.insert(num);
        }
        for(auto s : st)
        {
            if(st.find(s-1) == st.end())
            {
                int cur = 1;
                int curNum = s;
                while(st.find(curNum+1) != st.end())
                {
                    cur++;
                    curNum++;
                }
                res = max(cur, res);
            }
        }
        return res;
    }
};
