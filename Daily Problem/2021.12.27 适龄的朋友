法1：排序+双指针法，边界条件不好想，同时有个特殊条件，即当x<=14时，不存在y<x使得 y>x/2+7
时间O(NlogN)  空间O(log)
执行用时：44 ms, 在所有 C++ 提交中击败了54.93% 的用户
内存消耗：36.4 MB, 在所有 C++ 提交中击败了70.15% 的用户
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0, pre = 0, cur = 0;
        sort(ages.begin(), ages.end());
        for(auto age : ages)        // age表示截止到age之前存在的发送对数
        {
            if(age < 15)    continue;
            while(ages[pre] <= age/2+7)    pre++;
            while(cur+1 < ages.size() && ages[cur+1] <= age)     cur++;
            res += cur - pre;
        }
        return res;
    }
};

法2：桶排序，建立一个空间为120的数组，表示每单个年龄的人数，同时利用双指针，用户 x1 能发送请求的 用户 y1 的年龄范围为 [ages[x1]/2+8,ages[x1]]
 其中 左边界 是 单调不减的 , 所以我们从小到大来枚举年龄 , 用 low 来标记 能发送请求的用户年龄的下界大小 , sum 来记录符合要求的用户的个数,
 那么在 枚举年龄不断 右移 的过程中 l是也是不断右移 , 那么此时更新下 sum即可 , 那么对应的请求数量也就比较好求了
 class Solution {
public:
    int n;
    int dp[125] = {0};// 每一个数字的个数，即桶
    int numFriendRequests(vector<int>& s) {
        n = s.size();
        int res = 0;
        for(auto& i : s) {
            dp[i] ++;
        }
        int l = 0;// 左指针
        int sum = 0;// 符合条件的数字的个数
        for(int i = 1;i < 125;i ++) {
            if(!dp[i]) continue; 
            int low = i / 2 + 8;// 最小的符合条件的年龄
            // 如果 i >= low 那么 年龄为 i 的之间的人 可以两两相互发送请求
            if(i >= low) res += (dp[i] - 1) * dp[i];
            // 更新窗口 把不满足条件的年龄去除
            while(l < i && l < low) {
                sum -= dp[l ++];
            }
            res += dp[i] * sum;
            sum += dp[i];
        }
        return res;
    }
};
