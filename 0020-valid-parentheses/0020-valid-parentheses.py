class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) % 2 != 0:
            return False
        stack = []
        mapMatch = {')':'(', ']':'[','}':'{'}
        for c in s:
            if c not in mapMatch:
                stack.append(c)
            else:
                if not stack:
                    return False
                top = stack.pop()
                if top != mapMatch[c]:
                    return False
        return (not stack)

                