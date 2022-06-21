法1：自己做的遍历记录法，就是太麻烦了
时间O(M+N)   空间O(N)
执行用时：132 ms, 在所有 C++ 提交中击败了94.86% 的用户
内存消耗：59.2 MB, 在所有 C++ 提交中击败了83.20% 的用户
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int length = trust.size();
        vector<bool> num(n + 1, false);         // 记录每个人是否出现在trust[i][0]即入度中
        for(int i = 0; i < length; ++i)
        {
            num[trust[i][0]] = true;
        }
        int temp = 0, cur = 1;
        bool only = false;
        for(; cur < num.size(); ++cur)
        {
            if(!num[cur] && !only)              // 只有当没出现在trust[i][0]且唯一的一个人出现时，temp才有可能代表法官，即法官出度是否为0
            {
                temp = cur;
                only = true;
            }
            else if(num[cur])    continue;
            else break;
        }
        if(!only || cur != num.size())    return -1;
        int num1 = 0;
        for(int i = 0; i < length; ++i)         // 统计当trust[i][1]为法官时，是否其余的所有人都相信他，即入度为n-1
        {
            if(trust[i][1] == temp)    num1++;
        }
        if(num1 != n-1)    return  -1;
        return temp;
    }
};


法2：有向图的入度和出图应用，根据法官的入度为n-1，出度为0来返回
时间O(M+N)    空间O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1);
        vector<int> outDegrees(n + 1);
        for (int i = 0; i < trust.size(); ++i) {      // 遍历trust数组，记录每个人的入度和出度
            int x = trust[i][0], y = trust[i][1];
            ++inDegrees[y];
            ++outDegrees[x];
        }
        for (int i = 1; i <= n; ++i) {                // 统计每个人的入度和出度，找到法官
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
