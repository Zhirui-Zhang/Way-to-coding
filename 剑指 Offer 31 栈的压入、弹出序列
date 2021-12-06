法1：愚蠢的遍历法，flag记录遍历过程中当前push数组的最高点，若index > flag，更新flag值，否则查看两者之间的值是否弹出（即访问过为true），若未访问过说明跨了两个值弹出，则为false
时间O(N^2)内外两层遍历，效果很不好  空间O(N)visited数组占用N
执行用时：20 ms, 在所有 C++ 提交中击败了5.50% 的用户
内存消耗：14.4 MB, 在所有 C++ 提交中击败了99.59% 的用户
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty())    return true;                    // 判断空，其实可以省略
        int flag = 0, index = 0;
        vector<bool> visited(pushed.size(), false);           // 该数组记录是否num已经遍历过
        for(auto num : popped)                                // 外层遍历pop数组
        {
              
            for(int i = 0; i < pushed.size(); i++)            // 内层遍历push数组，查找pop数组中的值对应的push数组中的元素下标，记为index
            {
                if(pushed[i] == num)
                {
                    visited[i] = true;
                    index = i;
                    break;
                }
            }
            if(num == popped[0] || flag < index)              // 若num为pop第一个值或者index > flag，更新flag值
            {
                flag = index;
                continue;
            }
            if(flag > index)                                  // 若index < flag，再次遍历push数组中下标为[index+1, flag)的元素是否已经弹出(未弹出为false)，未弹出返回false
            {
                for(int i = index + 1; i < flag; i++)
                {
                    if(visited[i] == false)    return false;
                }
            }
        }
        return true;
    }
};

法2：模拟法，即利用辅助栈stack模拟push中的弹入弹出序列，若不符合则返回false
时间  空间均为O(N)，只需要遍历一遍即可，同时栈的大小为N
执行用时：8 ms, 在所有 C++ 提交中击败了70.82% 的用户
内存消耗：14.7 MB, 在所有 C++ 提交中击败了45.49% 的用户
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for(auto num : pushed)
        {
            s.push(num);                                    // 一直压入栈直至栈顶元素等于pop数组中的元素
            while(!s.empty() && popped[i] == s.top())       // 注意这里的判断条件要把s.empty()放在前面，否则会报错堆溢出，因为有可能s已经弹空但还在访问它的栈顶
            {
                s.pop();
                i++;
            }
        }
        if(s.empty())    return true;                       // 最后循环结束有两种情况，一种是辅助栈s已经弹空说明顺序全部符合，返回true，否则s不空说明顺序不对，返回false
        else return false;
    }
};
