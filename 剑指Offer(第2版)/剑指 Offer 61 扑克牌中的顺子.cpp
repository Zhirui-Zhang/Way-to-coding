法1：普通法，STL中的sort函数，排序后先检查0的个数，然后遍历查看前后数组顺序
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了47.88% 的用户
class Solution {
public:
    bool isStraight(vector<int>& nums) {  
        sort(nums.begin(), nums.end());
        int zero_num = 0, i = 0;  //查看0的个数并定位到第一个不为0的位置
        for(; i < 5; i++)     
        {
            if(nums[i] == 0)    zero_num++;
            else break;
        }
        for(; i < 4; i++)
        {
            int temp = nums[i+1] - nums[i];
            if(temp == 0 || temp > zero_num + 1)    return false; //若前后相等后者后面过大，返回false
            zero_num = zero_num - temp + 1;   //否则zero减
        }
        return true;  //顺利退出则返回真
    }
};

改进版：遍历一次即可
class Solution {
public:
    bool isStraight(vector<int>& nums) {  
        sort(nums.begin(), nums.end());
        int zero_num = 0;   //统计0的个数
        for(int i = 0; i < 4; i++)    
        {
            if(nums[i] == 0)    
            {
                zero_num++;
                continue;
            }
            int temp = nums[i+1] - nums[i];
            if(temp == 0 || temp > zero_num + 1)    return false;
            zero_num = zero_num - temp + 1;
        }
        return true;
    }
};
