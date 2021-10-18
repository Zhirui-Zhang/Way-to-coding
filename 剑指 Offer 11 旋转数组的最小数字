法1：sort函数后返回nums[0]
执行用时：4 ms, 在所有 C++ 提交中击败了85.12% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了26.76% 的用户
class Solution {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
};

法2：二分法
！重点是判断条件！
< 时令 right = mid
= 时令 right--
执行用时：8 ms, 在所有 C++ 提交中击败了41.23% 的用户
内存消耗：11.9 MB, 在所有 C++ 提交中击败了9.67% 的用户
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        //int i;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(numbers[mid] > numbers[right])   left = mid + 1;
            else if(numbers[mid] == numbers[right])    right--;
            else    right = mid;
        }
        return numbers[left];
    }
};
