法1：模拟法，由于只有三个值，就很简单了，每次记录5元和10元的个数，若有20元，优先用10元找钱
时间O(N)  空间O(1)
执行用时：76 ms, 在所有 C++ 提交中击败了86.81% 的用户
内存消耗：81.3 MB, 在所有 C++ 提交中击败了87.92% 的用户
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0;       // a b分别表示5元和10元的数量
        for (auto bill : bills) {
            if (bill == 5) {
                ++a;
            } else if (bill == 10) {
                if (a >= 1) {
                    --a;
                    ++b;
                } else {
                    return false;
                }
            } else {
                if (a >= 3 || (a >= 1 && b >= 1)) {
                    if (b >= 1) {
                        --b;
                        --a;
                    } else {
                        a -= 3;
                    }
                } else {
                    return false;
                }
            }
        }  
        return true;
    }
};