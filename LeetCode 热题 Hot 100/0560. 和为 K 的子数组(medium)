法1：哈希表+前缀和，思路很妙，即sum(i,j)=sum(0,j)-sum(0,i)，每次测试sum-k对应的值是否出现过，若出现累加即可，例题记录在笔记中
时间O(N)  空间O(N)
执行用时：68 ms, 在所有 C++ 提交中击败了59.15% 的用户
内存消耗：35.1 MB, 在所有 C++ 提交中击败了96.00% 的用户
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> un_map;      // 记录前缀和，key为前n个元素的总和，value为该key出现的次数
        un_map[0] = 1;                       // 注意初始值，un[0]=1表示若元素值等于k则直接+1
        for(auto num : nums){
            sum += num;                      // sum为遍历的前缀和
            if(un_map.find(sum-k) != un_map.end()){
                res += un_map[sum-k];        // 若之前出现过该key值，res加对应的value值
            }
            un_map[sum]++;                   // 每轮都将该key值对应的value+1
        }
        return res;
    }
};
