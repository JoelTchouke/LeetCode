class Solution {
public:
    bool isPalindrome(int x) {
        string originalNumber = std::to_string(x);
        int start = 0;
        int end = originalNumber.size() - 1;
        bool decision = true;
        for(int i = 0; i < int(originalNumber.size() / 2); i++)
        {
            if(originalNumber[start] != originalNumber[end])
            {
                decision = false;
            }
            start++;
            end--;
        }
        return decision;
    }
};