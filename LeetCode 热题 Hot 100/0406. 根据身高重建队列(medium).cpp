法1：贪心+排序法，注意这种类型题，如果出现两个需要排序的维度，一般都是一个正排一个反排，然后根据排序后的下标依次插入即可
时间O(N^2)因为排序需要NlogN，而遍历people并insert插入需要外层N*内层N=N^2  空间O(logN)快排复杂度
执行用时：144 ms, 在所有 C++ 提交中击败了41.85% 的用户
内存消耗：12.3 MB, 在所有 C++ 提交中击败了39.96% 的用户
class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y){      // 注意lambda表达式一定是返回static类型，否则编译不通过！！！
        if(x[0] == y[0]){                                 // 第一个维度反排，第二个维度正排
            return x[1] < y[1];
        }
        else{
            return x[0] > y[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for(auto p : people){
            res.insert(res.begin()+p[1], p);              
            // 这里非常巧妙，根据第二个维度k确定插入的位置，因为前面的k个元素一定比他高，而他比后面的矮，所以也不会影响后面的k值
            // 注意insert的用法为，在res.begin()+p[1]元素！前面！插入元素p
        }
        return res;
    }
};

优化：用链表可以提高时间效率，因为链表的插入不需要移动剩余元素的位置
执行用时：28 ms, 在所有 C++ 提交中击败了97.91% 的用户
内存消耗：13.2 MB, 在所有 C++ 提交中击败了23.64% 的用户
class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y){
        if(x[0] == y[0]){
            return x[1] < y[1];
        }
        else{
            return x[0] > y[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<vector<int>> res;      // res设为vector<int>类型的链表
        sort(people.begin(), people.end(), cmp);
        for(auto p : people){
            int i = p[1];           // 插入方式与上面大同小异，但是注意list迭代器不能+n，只能++，所以需要循环找到每次插入的位置
            auto it = res.begin();
            while(i--){
                it++;
            }
            res.insert(it, p);      // 注意写法
        }
        return vector<vector<int>>(res.begin(), res.end());     // 还有最后返回的写法，直接返回一个新构建的对象即可，免得还得新构建一个vector，遍历push_back，太愚蠢
    }
};
