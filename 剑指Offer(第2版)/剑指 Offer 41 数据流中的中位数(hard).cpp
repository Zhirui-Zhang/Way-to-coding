法1：二分法插入，执行用时太长了，时间空间均为O(n)，需要继续精简，降低时间复杂度
执行用时：260 ms, 在所有 C++ 提交中击败了10.67% 的用户
内存消耗：40.7 MB, 在所有 C++ 提交中击败了44.57% 的用户
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    void addNum(int num) {
        int left = 0, right = cur.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(num < cur[mid])    right = mid - 1;
            else left = mid + 1;
        }
        cur.insert(cur.begin() + left, num);  //在找到的位置之前插入该值
    }
    
    double findMedian() {
        int n = cur.size();
        if(n % 2 == 0)    return (cur[n/2] + cur[n/2 - 1]) / 2.0;   //如果为偶数，返回两数平均值，注意除数为float类型的2.0，否则输出的是int类型
        else    return cur[n/2];
    }
private:
    vector<int> cur;
};

法2：大顶堆（从大到小排序，用来保存较小的一半）+小顶堆（从小到大排序，用来保存较大的一半）法
时间O(logn) 空间O(n)
执行用时：92 ms, 在所有 C++ 提交中击败了81.65% 的用户
内存消耗：40.8 MB, 在所有 C++ 提交中击败了34.46% 的用户
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    void addNum(int num) {
        int n = max_heap.size(), m = min_heap.size();
        if (n == m)         //n==m意味当前为偶数，注意无论奇偶都要先插入另一个堆中，排好序后弹出其堆顶放入新堆中
        {
            min_heap.push(num);
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
        else    //否则为奇数
        {
            max_heap.push(num);
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
    }

    double findMedian() {
        int n = max_heap.size(), m = min_heap.size();   
        //若偶数返回大堆顶和小堆顶平均值，为奇数返回大堆顶即为中位数
        return n == m ? (max_heap.top() + min_heap.top())/2.0 : max_heap.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> max_heap;   //less可省略，默认大顶堆，存较小数
    priority_queue<int, vector<int>, greater<int>> min_heap;    //greater<int>为小顶堆，存较大数
};
