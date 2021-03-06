法1：直接sort函数  时间O(nlogn)，空间O(logn)
执行用时：24 ms, 在所有 C++ 提交中击败了83.22% 的用户
内存消耗：18.7 MB, 在所有 C++ 提交中击败了48.63% 的用户
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;     //直接return vector<int> (arr.begin(), arr.begin() + k)更好一点
    }
};

法2：快速排序法  时间平均O(nlogn)最坏O(N^2)  空间最好O(logn) 最坏O(n)
执行用时：44 ms, 在所有 C++ 提交中击败了11.49% 的用户
内存消耗：18.3 MB, 在所有 C++ 提交中击败了73.71% 的用户
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() - 1);
        return vector<int> (arr.begin(), arr.begin() + k);
    }
private:
    void quickSort(vector<int>& arr, int left, int right)
    {
        if(left >= right)    return;
        int i = left, j = right;    // 设置哨兵为left即首元素
        while(i < j)
        {
            while(arr[j] >= arr[left] && i < j)   j--;
            while(arr[i] <= arr[left] && i < j)   i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[left]);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
};

法3：基于快排的改进方法，快速选择，时间O(n)   空间O(logn)
第一次快排遍历后哨兵位置为i，同时前i个数字为最小的i个数字，此时若i>k，则递归解决(left, i-1)找到前k个最小的数即可，若哨兵<k，则找(i+1, right)，若等于，直接返回
执行用时：28 ms, 在所有 C++ 提交中击败了64.26% 的用户
内存消耗：18.2 MB, 在所有 C++ 提交中击败了91.48% 的用户
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, k, 0, arr.size() - 1);   //参数增加一个k的判断
        return vector<int> (arr.begin(), arr.begin() + k);
    }
private:
    void quickSort(vector<int>& arr, int k, int left, int right)
    {
        if(left >= right)    return;
        int i = left, j = right;    // 设置哨兵为left即首元素
        while(i < j)
        {
            while(arr[j] >= arr[left] && i < j)   j--;
            while(arr[i] <= arr[left] && i < j)   i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[left]);    //交换后判断哨兵和k的大小关系
        if(i > k)    quickSort(arr, k, left, i - 1);
        else if(i < k)    quickSort(arr, k, i + 1, right);
        else return;
    }
};

法4：利用大顶堆（注意是大顶堆，从大到小排序），即STL中的优先队列priority_queue——默认按降序排列
先存放前k个arr中的数字，随后依次遍历比较，若小于堆顶的数字，则把堆顶（当前最大值）弹出，该数字压入
时间O(nlogk)  空间O(k)
执行用时：28 ms, 在所有 C++ 提交中击败了64.26% 的用户
内存消耗：19.2 MB, 在所有 C++ 提交中击败了21.32% 的用户
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0)      return res;     //先判断k==0的情况，否则后面q.pop()访问越界
        priority_queue<int> q;
        for(int i = 0; i < k; i++)    q.push(arr[i]);   //先存放k个数字
        for(int i = k; i < arr.size(); i++)     //从k开始遍历，依次比较
        {   
            if(arr[i] < q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++)
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
