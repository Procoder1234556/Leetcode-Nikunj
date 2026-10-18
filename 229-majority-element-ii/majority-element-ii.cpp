#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int count1 = 0, count2 = 0;
        long long element1 = 1e18, element2 = 1e18; // Use a value outside constraints
        
        // First pass: find up to two potential candidates
        for (int num : nums) {
            if (num == element1) {
                count1++;
            } else if (num == element2) {
                count2++;
            } else if (count1 == 0) {
                element1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                element2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Second pass: verify the actual frequencies of the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == element1) count1++;
            else if (num == element2) count2++;
        }
        
        std::vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(element1);
        if (count2 > threshold) result.push_back(element2);
        
        return result;
    }
};
