法1：拒绝采样法，数学原理为：
已知 rand_N() 可以等概率的生成[1, N]范围的随机数
那么：(rand_X() - 1) × Y + rand_Y() ==> 可以等概率的生成[1, X * Y]范围的随机数，即实现了 rand_XY()
所以用两个rand7()可以实现rand49()，但是41-49不全，需要拒绝采样，进入下一次循环
可参考题解 https://leetcode.cn/problems/implement-rand10-using-rand7/solution/cong-zui-ji-chu-de-jiang-qi-ru-he-zuo-dao-jun-yun-/ 
时间 O(1)最好一次成功，最坏永远不成功O(∞)  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了72.49% 的用户
内存消耗：7.8 MB, 在所有 C++ 提交中击败了99.08% 的用户
class Solution {
public:
    int rand10() {
        while (true) {
            int a = (rand7() - 1) * 7;      // 生成 0 7 14 21 28 35 42
            int b = rand7();                // 生成 1 2  3  4  5  6  7
            int res = a + b;                // 生成 rand49() 1-49
            if (res <= 40) return (res - 1) % 10 + 1;     // 取前40个，能形成4个1-10循环，保证概率相同
        }
        return -1;
    }
};

优化：目的是减少rand7的重复调用，可以利用已经产生的rand49()，若大于40，再次利用rand9()和rand7()形成rand63()，若大于63再利用rand3()和rand7()形成rand21()减少循环次数
class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7();     
            int b = rand7();                        // 生成 1 2 3 4 5 6 7
            int res = (a - 1) * 7 + b;              // 生成 rand49() 1-49
            if (res <= 40) return (res - 1) % 10 + 1;     // 取前40个，能形成4个1-10循环，保证概率相同

            a = res - 40; // rand 9
            b = rand7();
            res = (a - 1) * 7 + b; // rand 63
            if (res <= 60) return (res - 1) % 10 + 1;     // 取前6组1-10，否则再利用生成的rand63()
            
            a = res - 60; // rand 3
            b = rand7();
            res = (a - 1) * 7 + b; // rand 21
            if (res <= 20) return (res - 1) % 10 + 1;     // 取前2组1-10，否则无法再利用生成的rand21()，因为减去20就剩rand1()了，只能进入下一次循环
        }
        return -1;
    }
};