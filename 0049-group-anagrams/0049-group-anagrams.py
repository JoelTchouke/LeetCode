from collections import defaultdict

class Solution(object):
    def groupAnagrams(self, strs):
        dic = {}
        res = []
        for st in strs:
            key = tuple(sorted(st))
            if key not in dic:
                dic[key] = []
            dic[key].append(st)
        for val in dic.values():
            res.append(val)
        return res