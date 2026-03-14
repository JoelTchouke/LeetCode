class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        history = {}
        for i in range(len(nums)):
            num = nums[i]
            if num in history:
                conditionVal = i - history[num]
                if conditionVal <= k:
                    return True
            history[num] = i
        return False