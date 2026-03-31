#include <algorithm>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Define a Min-Heap priority queue
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int n : nums) {
            minHeap.push(n);
            // Keep only k largest elements in the heap
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the Min-Heap is the kth largest element
        return minHeap.top();
    }
};