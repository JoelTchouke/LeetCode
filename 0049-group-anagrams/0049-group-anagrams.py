class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        my_dict = {}
        res = []
        for s in strs:
            key = tuple(sorted(s))
            my_dict[key] = my_dict.get(key, []) + [s]
        for arr in my_dict.values():
            res.append(arr)
        return res
