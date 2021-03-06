法1：哈希表unordered_map中的count函数，遍历nums，count(key)若存在返回1，否则赋值<key, value>
执行用时：44 ms, 在所有 C++ 提交中击败了42.46% 的用户
内存消耗：26.8 MB, 在所有 C++ 提交中击败了36.62% 的用户
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> un_map;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(un_map.count(nums[i]))   return nums[i];
            un_map[nums[i]] = 1;
        }
        return {};
    }
};
精简版：
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> un_map;    //value值设为布尔值更好
        //int n = nums.size();
        for(int num : nums)     //实现遍历vector功能
        {
            if(un_map[num])   return num;   
            un_map[num] = true;
        }
        return {};
    }
};

法2：原地交换法，交换元素使得nums中每个元素都和其下标一一对应，即nums[0]=0,nums[1]=1（如果元素存在的话）
※这里利用题目中描述的长度为n的数组在0~n-1范围内必有重复的条件※
执行用时：36 ms, 在所有 C++ 提交中击败了66.78% 的用户
内存消耗：22.3 MB, 在所有 C++ 提交中击败了97.58% 的用户
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == nums[nums[i]])
            {
                if(nums[i] == i) ;
                else    return nums[i];
            }
            else if(nums[nums[i]] == i)   return i;
            else
            {
            int temp = nums[i];
            nums[i] = nums[nums[i]];
            nums[temp] = temp;
            }    
        }
        return -1;
    }
};
精简版：
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {  //这里很巧妙，唯一能够使得i++的条件是nums[i]=i，否则一直交换
                i++;
                continue;   //continue用法！！
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);    //使用swap函数！！
        }
        return -1;
    }
};
