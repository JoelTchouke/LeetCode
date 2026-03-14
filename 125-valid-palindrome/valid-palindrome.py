class Solution(object):
    def isPalindrome(self, s):
        newS = ""

        for c in s:
            if c.isalpha() or c.isdigit():
                newS += c.lower()

        l = len(newS)

        for i in range(l):
            if newS[i] != newS[l - i - 1]:
                return False

        return True