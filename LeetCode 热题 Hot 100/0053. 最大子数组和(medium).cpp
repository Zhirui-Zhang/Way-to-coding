法1：DP法，做过的题并不难，拓展思路分治法见下
时间O(N)  空间O(1)
执行用时：92 ms, 在所有 C++ 提交中击败了55.24% 的用户
内存消耗：66.2 MB, 在所有 C++ 提交中击败了37.78% 的用户
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], temp = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            temp = max(temp+nums[i], nums[i]);
            res = max(temp, res);
        }
        return res;
    }
};

法2：分治法，类似于归并排序，中心思想就是分别递归计算左侧连续最大值，右侧连续最大值和跨中心连续最大值三者中的最大值，然后返回
取例1，左侧[-2 1 -3 4] leftMax=4  右侧[-1 2 1 -5] rightMax=3  计算得crossMax = leftCrossMax + rightCrossMax = 4+2=6  故最终结果为6
相较DP有些麻烦，了解即可，其实就是归并排序
时间O(NlogN)  空间O(logN)
执行用时：144 ms, 在所有 C++ 提交中击败了5.65% 的用户
内存消耗：66.1 MB, 在所有 C++ 提交中击败了75.58% 的用户
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n-1);
    }
private:    
    int dfs(vector<int>& nums, int left, int right)
    {
        if(left >= right)    return nums[left];
        int mid = (left + right) / 2;
        int leftMax = dfs(nums, left, mid);     // 左侧连续最大值
        int rightMax = dfs(nums, mid + 1, right);   // 右侧连续最大值
        
        // 下面计算横跨两个子序列的最大值
        // 计算包含左侧子序列最后一个元素的子序列最大值，注意要包含最后一个nums[mid]，否则不是连续的，所以从后往前计算
        int leftCrossMax = nums[mid]; 
        int leftCrossSum = 0;
        for (int i = mid ; i >= left ; i --) {
            leftCrossSum += nums[i];
            leftCrossMax = max(leftCrossSum, leftCrossMax);
        }
        // 计算包含右侧子序列最后一个元素的子序列最大值，注意要包含第一个nums[mid+1]，否则不是连续的，所以从前往后计算
        int rightCrossMax = nums[mid+1];
        int rightCrossSum = 0;
        for (int i = mid + 1; i <= right ; i ++) {
            rightCrossSum += nums[i];
            rightCrossMax = max(rightCrossSum, rightCrossMax);
        }
        // 计算左右两侧跨中心的子序列的最大值
        int crossMax = leftCrossMax + rightCrossMax;
        
        return max({leftMax, rightMax, crossMax});  // 比较三者，返回最大值，使用C++11新特性初始化列表
    }
};
