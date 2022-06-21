法1：先分割每个字符串存入vector<string>，随后遍历v利用deque判断是否需要弹出上一级，最后遍历deque输出
时间O(N)  空间O(N)
执行用时：8 ms, 在所有 C++ 提交中击败了42.95% 的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了66.78% 的用户
class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> v;
        deque<string> dq;
        for(auto c : path)    // 分割字符串
        {
            if(c != '/')    temp += c;
            else
            {
                if(temp.empty())    continue;
                v.push_back(temp);
                temp.clear();
            }
        }
        if(!temp.empty())    v.push_back(temp);   // 注意最后若不为 / 需要将之前积累的temp存入v中
        for(auto c : v)
        {
            if(c == ".")    continue;
            if(c == "..")   
            {
                if(!dq.empty())    dq.pop_back();  // 不为空时，弹出尾部即上一级目录
            }
            else dq.push_back(c);
        }
        if(dq.empty())     return "/";  // 若为空返回 /
        while(!dq.empty())
        {
            res += '/';
            res += dq.front();
            dq.pop_front();
        }
        return res;
    }
};

法2：只利用一个vector存储分割的字符串，在每次push_back之前判断temp中的具体情况，决定push or pop or continue
执行用时：4 ms, 在所有 C++ 提交中击败了88.71% 的用户
内存消耗：7.3 MB, 在所有 C++ 提交中击败了90.17% 的用户
class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> v;
        for(auto c : path)
        {
            if(c != '/')    temp += c;
            else
            {
                if(temp.empty() || temp == ".")    
                {
                    temp = "";
                    continue;
                }
                if(temp == "..")
                {
                    if(!v.empty())    v.pop_back();
                }    
                else v.push_back(temp);
                temp = "";
            }
        }
        if(!temp.empty() && temp != ".")    // 判断最后一次的temp情况
        {
            if(temp == "..")
            {
                if(!v.empty())    v.pop_back();
            }    
            else v.push_back(temp);
        }
        if(v.empty())    return "/";
        for(int i = 0; i < v.size(); ++i)
        {
            res += "/";
            res += v[i];
        }
        return res;
    }
};
