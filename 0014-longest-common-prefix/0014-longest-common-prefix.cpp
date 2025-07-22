class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = "";
        int letterIndex = 0;

        while (true) {
            char currentChar = 0;

            for (int i = 0; i < strs.size(); i++) {
                if (letterIndex >= strs[i].size()) 
                    return prefix;

                if (i == 0) {
                    currentChar = strs[i][letterIndex];
                } else {
                    if (strs[i][letterIndex] != currentChar) {
                        return prefix;
                    }
                }
            }

            prefix += currentChar;
            letterIndex++;
        }

        return prefix;
    }
};
