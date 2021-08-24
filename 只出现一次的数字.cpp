//采用异或运算，相同数字异或为0，这样全部异或就能得到只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) {
            ret ^= e;
        }

        return ret;
    }

};
