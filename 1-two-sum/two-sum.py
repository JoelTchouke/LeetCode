class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if target - nums[i] in seen:
                return [i, seen[complement]]
            else:
                seen[nums[i]] = i
        return []


        

