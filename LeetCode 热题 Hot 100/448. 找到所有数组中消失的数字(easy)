法1：遍历法，应该是复杂度O(N)吧，这个a b +1 -1的关系刚开始把自己绕蒙了，其实在纸上依次写出来其实程序就好写了
时间O(N)  空间O(1)
执行用时：48 ms, 在所有 C++ 提交中击败了50.89% 的用户
内存消耗：32.9 MB, 在所有 C++ 提交中击败了53.63% 的用户
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(nums[i] != 0){
                int a = nums[i] - 1;
                int b = nums[a] - 1;
                while(nums[a] != 0){      // 沿着一路找下去，如果下标-1对应的值不为0，继续循环
                    nums[a] = 0;
                    a = b;
                    b = nums[a] - 1;
                }
            }
        }
        for(int i = 0; i < n; ++i){       // 最后输出时注意，缺少的值是下标+1！！！
            if(nums[i] != 0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

改进版：每次对下标-1的值+n，注意要先取模，避免已经被增加过，之后遍历若值<=n说明没出现过
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
