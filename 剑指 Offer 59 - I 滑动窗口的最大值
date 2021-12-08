法1：暴力遍历法，啥技巧性操作都没用上，评价还贼高，也不知道为啥是困难题...
用例[1 3 -1 -3 1 3 6 7]
时间O(NK)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了99.62% 的用户
内存消耗：15.3 MB, 在所有 C++ 提交中击败了86.16% 的用户
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())    return res;
        int max = nums[0];                                // max保存当前k长度中的最大值
        for(int i = 0; i < k; i++)                        // 第一轮遍历k个值，记录最大值max
        {
            if(nums[i] > max)    max = nums[i];
        }
        res.push_back(max);
        for(int i = k; i < nums.size(); i++)              // 第二轮继续遍历，依次向后移动一个元素，若该元素比max大，直接记录，若当前最大值即将移出，遍历新的k个元素找到最大值并保存
        {
            if(nums[i] >= max)
            {
                max = nums[i];
            }
            else if(nums[i - k] == max)
            {
                max = nums[i];
                for(int j = i - k + 1; j < i; j++)
                {
                    if(nums[j] > max)    max = nums[j];
                }
            }
            res.push_back(max);
        }
        return res;
    }
};

法2：单调队列法，可能原题目的意思是时间复杂度应为O(N)，空间为O(K)，所以需要改进该算法，引入双向队列deque
※该队列中下标对应的元素是严格单调递减的，队首下标对应的元素就是滑动窗口中的最大值※
执行用时：16 ms, 在所有 C++ 提交中击败了84.49% 的用户
内存消耗：15.4 MB, 在所有 C++ 提交中击败了75.52% 的用户
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())    return res;
        deque<int> dq;                                              
        // 注意dq中存放的是当前最大值代表的元素下标而并非元素本身，其实可以存入元素本身的，这里抄的一个答案懒得改了，二轮再说吧
        for(int i = 0; i < k; i++)                                  // 第一轮遍历，存入前k个元素中下标最大的值，从尾部插入，保证nums[dq.front()]始终为前k个元素中的最大值
        {
            while(!dq.empty() && nums[i] >= nums[dq.back()])    
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);                             // 存入头部下标代表的元素，即前k个元素中的最大值

        for(int i = k; i < nums.size(); i++)                         // 第二轮遍历
        {
            while(!dq.empty() && nums[i] >= nums[dq.back()])         // 这里代码同理，保证dq.front()始终为k个元素中最大元素的下标
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() <= i - k)                                  // 这里是重点，判断当前头部的下标值是否需要被淘汰
            {
                dq.pop_front();
            }
            res.push_back(nums[dq.front()]);                         // 存入这一轮中的最大值 
        }
        return res;
    }
};
