class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        sortNum = sorted(nums)
        for i in range(len(sortNum)):
            if i > 0 and sortNum[i] == sortNum[i - 1]:
                continue
            j = i + 1
            k = len(sortNum) - 1
            while(j < k):

                sum3 = sortNum[i] + sortNum[j] + sortNum[k]
                if sum3 > 0:
                    k -= 1
                elif sum3 < 0:
                    j += 1
                else:
                    res.append([sortNum[i], sortNum[j], sortNum[k]])
                    j += 1
                    k -= 1
                    while j < k and sortNum[j] == sortNum[j - 1]:
                        j += 1

                    while j < k and sortNum[k] == sortNum[k + 1]:
                        k -= 1

        return res
