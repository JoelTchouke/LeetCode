class Solution {
public:
    bool isPalindrome(int x) {
        string originalNumber = std::to_string(x);
        string reverseNumber = "";
        for(int i = originalNumber.size() - 1; i >= 0; i--)
        {
            reverseNumber += originalNumber[i];    
        }

        return originalNumber == reverseNumber;
    }
};