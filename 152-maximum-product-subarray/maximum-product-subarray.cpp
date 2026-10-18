class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxprod = nums[0];
       int minprod = nums[0];
       int globalmax = nums[0];


       for(int i = 1; i < nums.size(); ++i){
          int currentelement = nums[i];
          if (currentelement < 0 ){
            swap(maxprod,minprod);
          }
          maxprod = max(currentelement , currentelement*maxprod);
          minprod = min(currentelement, currentelement*minprod);
          globalmax = max(maxprod,globalmax);

       } 
       return globalmax;
    }
};