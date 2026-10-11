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
            // to get the min value till the index
            minVal = min((minVal + nums[i]), nums[i]);
            // to get the max value till the index
            maxVal = max((maxVal + nums[i]), nums[i]);
            // to get the possible values
            ans = max(ans, max(maxVal, abs(minVal)));

        }

        return ans;
    }
};