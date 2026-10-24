class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;  int r = (int)height.size() - 1;
        int leftmax = 0;  int rightmax = 0; int water = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > leftmax) leftmax = height[l];
                water += leftmax - height[l];
                l++;                       // added
            }
            else {
                if (height[r] > rightmax) rightmax = height[r];
                water += rightmax - height[r];
                r--;                       // added
            }
        }
        return water;
    }
};