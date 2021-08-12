class Solution {
public:
    bool isValid(string s) {
        int sSize = s.size();
        if (sSize == 0 || sSize % 2 == 1) {
            return false;
        }

        unordered_map<char, char> hashMap = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        stack<char> stk;
        for (auto c : s) {
            // 找不到，说明是正向的括号，入栈
            if (hashMap.count(c) == 0) {
                stk.push(c);
            } else {
                // 找到，说明是反括号，直接跟栈顶值比较，如果不一样，就不是有效字符串
                if (stk.empty() || stk.top() != hashMap[c]) {
                    return false;
                }
                stk.pop();
            }

        }

        return stk.empty();
    }
};
