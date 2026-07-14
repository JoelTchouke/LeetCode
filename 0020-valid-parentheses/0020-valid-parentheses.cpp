class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> pairs = {
            {')', '('}, 
            {']', '['}, 
            {'}', '{'}
        };        
        for (char c : s) {
            auto it = pairs.find(c);
            if (it == pairs.end()) {
                stack.push(c);
            }
            else {
                if(stack.empty()) return false;
                if (stack.top() == pairs[c]) stack.pop();
                else break;
            }
        }
        return stack.empty();
    }
};