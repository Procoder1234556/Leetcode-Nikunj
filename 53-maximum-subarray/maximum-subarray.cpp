class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = nums[0];
        int maxsum = nums[0];
        for(size_t i = 1; i < nums.size(); ++i){
            currentsum = max(nums[i],nums[i]+currentsum);
            maxsum = max(currentsum,maxsum);
        }
        return maxsum;
    }
    
};