class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0];
        int maxVal = nums[0];
        int gMax = nums[0];
        int gMin = nums[0];
        int ans = max(abs(gMax), abs(gMin));
        for(int i = 1; i < n ;i++) {
            if((minVal + nums[i]) < nums[i]) {
                minVal += nums[i];
            }
            else {
                minVal = nums[i];
            }
            gMin = min(gMin, minVal);

            if((maxVal + nums[i]) > nums[i]) {
                maxVal += nums[i];
            }
            else {
                maxVal = nums[i];
            }
            gMax = max(gMax, maxVal);

            ans = max(ans, max(abs(gMax), abs(gMin)));
        }

        return ans;
    }
};