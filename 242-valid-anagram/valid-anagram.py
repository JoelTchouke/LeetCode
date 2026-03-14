class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        tLetters = {}
        sLetters = {}
        for i in range(len(s)):
            if s[i] not in t:
                return False
            sLetters[s[i]] = sLetters.get(s[i], 0) + 1
            tLetters[t[i]] = tLetters.get(t[i], 0) + 1
        return tLetters == sLetters
        
