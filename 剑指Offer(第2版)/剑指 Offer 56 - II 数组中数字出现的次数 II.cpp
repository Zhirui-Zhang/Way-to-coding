法1：位运算，关键在于发现逐位和加起来后只有出现一次的那些位上对3取模不为0，其他位%3均为0，由于最长有32位，所以bit数组初始化为32个0
该方法可以推广至出现n次，仅一个数字出现一次的情况中
时间O(32*N)=O(N)  空间O(32)=O(1)
执行用时：32 ms, 在所有 C++ 提交中击败了68.93% 的用户
内存消耗：15.7 MB, 在所有 C++ 提交中击败了80.89% 的用户
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 假设例为[9 1 7 9 7 9 7]
        vector<int> bit(32, 0);    // bit数组为32个0，因为题中最大数字为2^31是int类型，有32位，数组长度max=10000，假设每一位都为1，最多累加才10000<2^31
        for(auto num : nums)
        {
            for(int i = 0; i < 32; i++)
            {
                bit[i] += (num & 1);    // num & 1的目的：除了最低位可能为1，其余均设为0不管，最低位若为1则和为1，加到bit数组中
                num >>= 1;              // 随后num右移一位,循环32次，最终bit为3337 (前面28位略去，均为0)
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            bit[i] %= 3;                // 逐位对3取余，最终bit为0001，转换为2进制数即res=1
            res += bit[i] * pow(2, i);  // 还可以写成 res <<= 1; res += bit[i] % 3
        }
        return res;
    }
};

法2：哈希表，说实话用hashmap太low了，而且空间复杂度过高，不建议使用
时间O(N)  空间O(N)
执行用时：32 ms, 在所有 C++ 提交中击败了68.93% 的用户
内存消耗：18.1 MB, 在所有 C++ 提交中击败了18.84% 的用户
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> un_map;
        for(auto num : nums)
        {
            un_map[num]++;
        }
        int res = 0;
        for(auto unit : un_map)     // 还可以写成for(auto [k, v] : un_map){if(v == 1) res = k;}这种，还可以写成迭代器iter->second
        {
            if(unit.second == 1)    
            {
                res = unit.first;
                break;
            }
        }
        return res;
    }
};

法3：先sort()排序后遍历，更拉跨，时间O(NlogN)，省略不写
