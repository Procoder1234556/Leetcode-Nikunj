class Solution {
public:
    int countAtMost(vector<int>& nums, int X) {
        int streak = 0;
        int total = 0;
        for (int x : nums) {
            if (x <= X) {
                streak++;
            } else {
                streak = 0;
            }
            total += streak;
        }
        return total;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countAtMost(nums, right) - countAtMost(nums, left - 1);
    }
};