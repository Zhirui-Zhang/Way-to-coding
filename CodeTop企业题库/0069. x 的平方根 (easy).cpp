法1：二分法，设置左右边界，注意记录中间mid的值保存到res中
时间O(logN)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.7 MB, 在所有 C++ 提交中击败了87.22% 的用户
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((long)mid * mid < x) {
                left = mid + 1;
            }
            else if ((long)mid * mid > x) right = mid - 1;
            else return mid;
        }
        return right;
    }
};

法2：牛顿迭代法，求导与x轴交点的值为下一次迭代的x值，可以指定精度为1e-7以上确定小数范围，每次迭代值为 xi+1=1/2(xi+C/xi)
时间O(logN)  空间O(1)
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了60.81% 的用户
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;   // 特殊情况必须处理，否则会导致0做除数
        double C = x, x0 = x;   // 注意所有的变量都要设置为double类型，否则fabs比较时无法缩小精度
        while (true) {
            double x1 = 0.5 * (x0 + C / x0);    
            // 函数fabs的作用是求浮点数x的绝对值；函数abs的作用是求x的绝对值
            if (fabs(x0 - x1) < 1e-7) return (int)x0;
            x0 = x1; 
        }
        return (int)x0;
    }
};