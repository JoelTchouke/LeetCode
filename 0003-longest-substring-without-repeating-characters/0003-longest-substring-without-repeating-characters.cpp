#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substring;
        int left = 0;
        int right= 0;
        int maxSubstring = 0;
        while(right != s.size())
        {
            if(substring.find(s[right]) == substring.end())
            {
                substring.insert(s[right]);
                maxSubstring = max(maxSubstring, (right - left + 1));
                right++;
            }
            else
            {
                substring.erase(s[left]);
                left++;
            }

        }

        return maxSubstring;
    }
};