class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        string textC = "balloon";
        int maxNumber = 0;
        int i = 0;
        for(char c : text)
        {
            freq[c]++;
        }
        while(1)
        {
            if(freq.find(textC[i]) == freq.end() || freq[textC[i]] == 0) break;
            else freq[textC[i]]--;
            if (textC[i] == 'n')
            {
                i = 0;
                maxNumber++;
            }
            else i++;
        }
        return maxNumber;

    }
};