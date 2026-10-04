class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Create a min-heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        for (int num : nums) {
            min_heap.push(num);
            // If heap size exceeds k, remove the smallest element
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // The top of the min-heap is the k-th largest element
        return min_heap.top();
    }
};