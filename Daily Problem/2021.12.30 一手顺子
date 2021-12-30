法1：排序+哈希，还挺简单的，先对hand数组排序，之后哈希表统计一个每个元素的个数之后遍历，若连续的值在哈希表中没有计数即返回false
时间(NlogN)  空间O(N)
执行用时：52 ms, 在所有 C++ 提交中击败了88.85% 的用户
内存消耗：26 MB, 在所有 C++ 提交中击败了75.54% 的用户
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)    return false;   // 如果长度不是groupSize的整数倍时，直接返回false即可
        sort(hand.begin(), hand.end());
        unordered_map<int, int> un_map;
        for(auto num : hand)
        {
            ++un_map[num];
        }
        for(int i = 0; i < n; i++)
        {
            if(un_map[hand[i]] == 0)    continue;
            for(int j = hand[i]; j < hand[i] + groupSize; j++)
            {
                if(un_map[j] == 0)    return false;
                --un_map[j];
            }
        }
        return true;
    }
};
