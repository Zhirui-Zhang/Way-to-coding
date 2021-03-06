法1：回溯法，每次从上一次的位置开始递归，不要回头，注意两种不同的返回情况，同时每次回溯后对temp进行弹出
！我第一次先对candidates进行了排序，但其实我的写法并不需要排序，因为是全排列，举出了所有例子，并不需要根据大小进行回溯！
时间O(S)S为所有可行解的长度之和，这个复杂度不好分析，可取O(n*2^n)作为上界，实际远达不到  空间O(target)
执行用时：4 ms, 在所有 C++ 提交中击败了91.66% 的用户 
内存消耗：10.7 MB, 在所有 C++ 提交中击败了64.30% 的用户 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);                     // 当前下标为0
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
    void dfs(vector<int>& candidates, int pos, int target)
    {
        if(target == 0)             // 目标为0时应存储当前temp数组，然后返回弹出上一个元素
        {
            res.push_back(temp);
            return;
        }
        if(target < 0)              // 目标<0时应返回弹出上一个元素
        {
            return;
        }
        for(; pos < candidates.size(); ++pos)    // 注意从当前位置开始遍历下一次加入的元素值，将其加入temp中，dfs后弹出
        {
            temp.push_back(candidates[pos]);
            dfs(candidates, pos, target - candidates[pos]);
            temp.pop_back();        // 弹出很重要！！！
        }
    }
};
