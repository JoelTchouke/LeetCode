class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        result = []
        intervals.append(newInterval)
        newIntervals = sorted(intervals)
        currentInterval = newIntervals[0]
        for interval in newIntervals[1:]:
            if currentInterval[1] >= interval[0]:
                currentInterval[1] = max(currentInterval[1], interval[1])
            else:
                result.append(currentInterval)
                currentInterval = interval
        result.append(currentInterval)
        return result
        