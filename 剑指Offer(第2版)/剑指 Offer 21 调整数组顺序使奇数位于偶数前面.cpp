法1：双指针法  首尾各一个指针  若为偶奇则交换swap() 否则分情况讨论  直至pre>=cur结束
执行用时：20 ms, 在所有 C++ 提交中击败了52.56% 的用户
内存消耗：17.8 MB, 在所有 C++ 提交中击败了29.59% 的用户
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int pre = 0, cur = nums.size() - 1;
        while(pre < cur)
        {
            if(nums[pre] % 2 == 0 && nums[cur] % 2 == 1)
            {
                swap(nums[pre], nums[cur]);
                pre++;
                cur--;
            }
            else if(nums[pre] % 2 == 0)    cur--;
            else if(nums[cur] % 2 == 1)    pre++;
            else
            {
                pre++;
                cur--;
            }
        }
        return nums;
    }
};

优化版：一直找，直到pre为偶，cur为奇，swap后各自加减1
执行用时：12 ms, 在所有 C++ 提交中击败了96.03% 的用户
内存消耗：17.7 MB, 在所有 C++ 提交中击败了50.56% 的用户
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int pre = 0, cur = nums.size() - 1;
        while(pre < cur)
        {
            if(nums[pre] % 2 == 1)    
            {
                pre++;
                continue;
            }
            if(nums[cur] % 2 == 0)   
            {
                cur--;
                continue;
            }
            swap(nums[pre++], nums[cur--]);
        }
        return nums;
    }
};
