法1：贪心法，思路有点绕，要一直循环该字符串，直到有任意一方无法发言为止，举例：DDRRR最终是D获胜
时间O(N)最多两轮就能结束循环  空间O(1)
执行用时：8 ms, 在所有 C++ 提交中击败了53.56% 的用户
内存消耗：6.6 MB, 在所有 C++ 提交中击败了84.72% 的用户
class Solution {
public:
    string predictPartyVictory(string senate) {
        // R = true表示本轮循环结束后，字符串里依然有R。D同理
        bool R = true, D = true;
        // 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
        int flag = 0;
        while (R && D) { // 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
            R = false;
            D = false;
            for (int i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    if (flag < 0) senate[i] = 'P'; // 消灭R，设置为'P'，表示Pass（任意）
                    else R = true; // 如果没被消灭，本轮循环结束仍有R
                    flag++;        // 能发言的R数目+1
                }
                if (senate[i] == 'D') {
                    if (flag > 0) senate[i] = 'P';  // 消灭D，设置为'P'，表示Pass（任意）
                    else D = true;  // 如果没被消灭，本轮循环结束仍有D
                    flag--;         // 能发言的D数目+1
                }   
            }
        }
        // 循环结束之后，R和D只能有一个为true
        return R ? "Radiant" : "Dire";
    }
};