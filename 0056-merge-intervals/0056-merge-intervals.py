class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        sortedInt = sorted(intervals)
        currentInterval = sortedInt[0]
        for interval in sortedInt[1:]:
            if currentInterval[1] >= interval[0]:
                currentInterval[1] = max(interval[1], currentInterval[1])
            else:
                result.append(currentInterval)  
                currentInterval = interval
        result.append(currentInterval)
        return result          
