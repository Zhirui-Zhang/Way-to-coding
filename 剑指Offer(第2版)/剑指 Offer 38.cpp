法1：DFS，回溯法，自己想到的和答案还不太一样，我的想法是例f(a b c) -> a+f(b c) -> a+b+f(c) -> a+b+c，但是好像不太适合遍历，二刷的时候再结合答案自己试试？
答案的是建立了一个visited判断是否已经访问过  时间O(N!N) 全部排列共有N!个，每个排列平均需要O(n)的时间来生成  空间O(N)递归深度
执行用时：20 ms, 在所有 C++ 提交中击败了80.89% 的用户
内存消耗：19.9 MB, 在所有 C++ 提交中击败了62.14% 的用户
class Solution {
public:
    vector<string> permutation(string s) {
        int n = s.size();
        visited.assign(n, false);   // 将visited设置为n个false
        sort(s.begin(), s.end());   // 使用sort函数对字符串排序，使重复的字符相邻
        string temp;
        dfs(s, 0, n, temp);
        return res;
    }
private:
    vector<string> res;     // 最终返回的字符串型数组
    vector<bool> visited;   // 记录每个字符是否已经被访问过
    void dfs(string& s, int i, int n, string& temp)
    {
        if(i == n)          // 这里的参数i就是一个记录递归深度的数据，无实际意义，只有当i==n时说明已经凑齐n个字符，可以添加到res中了
        {
            res.push_back(temp);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(visited[j] || (j > 0 && !visited[j-1] && s[j-1] == s[j]))    continue;
            // visited[j]=true时表示已经访问过，continue到下一个节点，后面的条件是当节点未遍历且相邻字符不是重复字符时，则将该字符加入排列字符串中，依次递归遍历
            // 这里需要强调的是除非原数组s中有重复的元素，否则(j > 0 && !visited[j-1] && s[j-1] == s[j])永远为false，是否continue只取决于visited[j]，即例[a b c]中只考虑前面即可
            // 而当用例为[a b b]时，当abb->ab->a后j=2时v[0]=T v[1]=F v[2]=F 从而(j > 0 && !visited[j-1] && s[j-1] == s[j])为true执行continue跳出本次循环进行bab等序列
            visited[j] = true;          // 该字符置为true
            temp.push_back(s[j]);       // 插入到temp中
            dfs(s, i + 1, n, temp);     // 继续递归
            temp.pop_back();            // 递归返回后弹出
            visited[j] = false;         // 将该字符置为false
        }
    }
};

法2：自带函数，几行搞定，具体输出情况略，next_permutation(first, last); next_permutation()返回布尔值，作用是以字典序取得[first,last)所标示之序列的下一个排列组合
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        do{
            res.emplace_back(s);
        }while(next_permutation(s.begin(), s.end()));

        return res;
    }
};
