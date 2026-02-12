from collections import defaultdict

class Solution(object):
    def groupAnagrams(self, strs):
        result = defaultdict(list)
        for word in strs:
            key = tuple(sorted(word))
            result[key].append(word)
        return list(result.values())
