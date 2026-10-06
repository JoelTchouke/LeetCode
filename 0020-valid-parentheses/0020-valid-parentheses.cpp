#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        unordered_map<char, char> matches = {{')', '('}, {']','['}, {'}','{'}};
        for (char c: s)
        {
            if(!st.empty() && st.top() == matches[c]) st.pop();
            else st.push(c);
        }

        return st.empty();
    }
};