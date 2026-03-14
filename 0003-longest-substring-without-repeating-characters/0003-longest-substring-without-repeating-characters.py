class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        start = 0
        end = 0
        sub = ""
        subLen = 0
        while(end != (len(s))):
            if (s[end] in sub):
                sub = ""
                start += 1
                end = start
            sub += s[end]
            end += 1
            subl = end - start
            if subl > subLen:
                    subLen = subl
        return subLen

