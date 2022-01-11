法1：单调队列法，重复题还想了好久才写出来，真菜啊，引入双向队列deque
时间复杂度O(N)，空间为O(K)
※该队列中下标对应的元素是严格单调递减的，队首下标对应的元素就是滑动窗口中的最大值※
执行用时：208 ms, 在所有 C++ 提交中击败了85.02% 的用户
内存消耗：128.7 MB, 在所有 C++ 提交中击败了76.83% 的用户
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        dq.push_back(nums[0]);
        for(int i = 1; i < k; i++)    // 寻找第一轮中的最大值
        {
            while(!dq.empty() && nums[i] > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        for(int i = k; i < nums.size(); ++i)  // 依次向后遍历，记录每一轮的最大值，同时需要注意是否队首元素已经被淘汰，需要出队
        {
            if(nums[i - k] == dq.front())   dq.pop_front();
            while(!dq.empty() && nums[i] > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            res.push_back(dq.front());
        }
        return res;
    }
};
