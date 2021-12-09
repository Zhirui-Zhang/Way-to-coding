法1：DP动态规划，其实和斐波那契数列差不多，但继续相加的前提是  0<=十位数字*10+个位数字<=25 很遗憾，我想出来了  但是细节没弄懂  一直没写对  怎么提交都是错误  草  妈的
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了44.86% 的用户
class Solution {
public:
    int translateNum(int num) {
        int a = 1, b = 1, x = 0, y = num % 10;  
        //x存储十位数字，y存储个位数字，a为结果，b为中间过程
        while(num != 0)
        {
            num /= 10;
            x = num % 10;
            int temp = 10 * x + y;  //此时的十位数字
            if(temp > 25 || temp < 10)    b = a;     //大于25或者小于10,注意此处需要让上一位结果等于当前位，以继续循环
            else    //小于26则是斐波那契数列
            {
                int temp_num = a;
                a += b;
                b = temp_num;
            }
            y = x;  //更新个位数字
        }
        return a;
    }
};

我自己写的最终改进版：其实本质是迭代法+双指针法
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了80.78% 的用户
class Solution {
public:
    int translateNum(int num) {
        int res = 1, res_pre = 0, second = num % 100;   //先初步判断前指针的值是0还是1
        if(second >= 10 && second <=25)  res_pre = 1;     
        while(num > 9)
        {
            second = num % 100;
            if(second >= 10 && second <=25) 
            //一定要注意是同时大于10且小于25才可以斐波那契数列 否则使上一个指针挪到当前位置
            {
                int temp = res;
                res += res_pre;
                res_pre = temp;
            }
            else    res_pre = res;
            num /= 10;
        }
        return res;
    }
};
