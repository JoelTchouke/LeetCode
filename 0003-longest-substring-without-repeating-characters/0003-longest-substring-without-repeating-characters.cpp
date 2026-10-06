#include <unordered_set>
#include <algorithm>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int subStart = 0; 
        std::unordered_set<char> ch;

        for (int i = 0; i < s.size(); i++) 
        {
            while (ch.find(s[i]) != ch.end()) 
            {
                ch.erase(s[subStart]);
                subStart++;
            }
            ch.insert(s[i]);
            maxLength = std::max(maxLength, (i + 1) - subStart);
        }

        return maxLength;
    }
};
