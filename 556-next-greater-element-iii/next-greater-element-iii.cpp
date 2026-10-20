#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int nextGreaterElement(int n) {
        std::string digits = std::to_string(n);
        int len = digits.length();
        
        // Step 1: Find the first decreasing digit from the right
        int i = len - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }
        
        // If no such element is found, it's already the largest permutation
        if (i < 0) return -1;
        
        // Step 2: Find the smallest digit to the right of i that is greater than digits[i]
        int j = len - 1;
        while (digits[j] <= digits[i]) {
            j--;
        }
        
        // Step 3: Swap digits at i and j
        std::swap(digits[i], digits[j]);
        
        // Step 4: Reverse the suffix to make it the smallest possible permutation
        std::reverse(digits.begin() + i + 1, digits.end());
        
        // Step 5: Convert back to integer and handle 32-bit signed integer overflow
        long long result = std::stoll(digits);
        
        return result > INT_MAX ? -1 : static_cast<int>(result);
    }
};
