class Solution {
public:
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;
        /**
        1101
        if LSB + carry = 1, I want to add 1 and make the carry 1 then keep shifting left (dividing by 2) and adding 2 steps
        if LSB is 1 and carry is 1, make the carry 1 and keep shifting to left adding 1 step
        if LSB is 0, I want to just keep shifting left adding 1 step 
        **/
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(i == 0 && ((s[i] - '0') + carry) == 1)
            {
              break;  
            }
            if((s[i] == '0' && carry == 1) || (s[i] == '1' && carry == 0))
            {
                carry = 1;
                steps += 2;
            }
            else if(s[i] == '1' && carry == 1)
            {
                carry = 1;
                steps++;
            }
            else
            {
                carry = 0;
                steps++;
            }
        }
        return steps;
    }
};