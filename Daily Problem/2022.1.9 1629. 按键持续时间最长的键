法1：模拟遍历即可，记录每次的时长和最大字符
时间O(N)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：10.4 MB, 在所有 C++ 提交中击败了69.58% 的用户
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int time = releaseTimes[0], n = releaseTimes.size();
        for(int i = 1; i < n; ++i)
        {
            int temp = releaseTimes[i] - releaseTimes[i-1];
            if(temp == time)    res = max(res, keysPressed[i]);
            if(temp > time)    res = keysPressed[i];
            time = max(time, temp);
        }
        return res;
    }
};
