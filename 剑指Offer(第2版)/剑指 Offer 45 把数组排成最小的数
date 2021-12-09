法1：lambda内置表达式，很简单，但是不好记   核心[capture](parameters) mutable ->return-type{statement}
执行用时：4 ms, 在所有 C++ 提交中击败了95.05% 的用户
内存消耗：11 MB, 在所有 C++ 提交中击败了65.80% 的用户
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> temp;  //临时数组，里面的元素为字符串类型
        for(auto num : nums)
        {
            temp.push_back(to_string(num));
        }
        sort(temp.begin(), temp.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});  //这里的两个引用&可以省略
        //或者写成auto compare = [](string s1, string s2){return s1 + s2 < s2 + s1;}
        //sort(temp.begin(), temp.end(), compare);
        string res;    //最终输出的字符串
        for(auto s : temp)
        {
            res += s;
        }
        return res;
    }
};

法2：快速排序法，即分而治之，递归法，应用模板
执行用时：8 ms, 在所有 C++ 提交中击败了70.10% 的用户
内存消耗：11.2 MB, 在所有 C++ 提交中击败了19.29% 的用户
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> temp;    //temp和res意义同上，主要是记住快排算法模板
        for(auto num : nums)
        {
            temp.push_back(to_string(num));
        }
        quickSort(temp, 0, temp.size() - 1);
        string res;   
        for(auto s : temp)
        {
            res += s;
        }
        return res;
    }
private:
    void quickSort(vector<string>& temp, int left, int right)
    {
        if(left >= right)    return;
        int i = left, j = right;
        while(i < j)    //快排模板，判断条件稍微有所调整
        {
            while(temp[j] + temp[left] >= temp[left] + temp[j] && i < j)    j--;
            while(temp[i] + temp[left] <= temp[left] + temp[i] && i < j)    i++;
            swap(temp[i], temp[j]);     //当前面大于pivot，后面小于时，交换i j
        }
        swap(temp[i], temp[left]);  //退出后再交换，将基准换到正确的位置
        quickSort(temp, left, i - 1);   //分别递归前半部分和后半部分
        quickSort(temp, i + 1, right);
    }
};
