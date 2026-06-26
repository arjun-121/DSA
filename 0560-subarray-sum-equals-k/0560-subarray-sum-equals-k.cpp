class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ns = nums.size();
        if(ns == 1) {
            return  nums[0] == k ? 1 : 0;
        }
        vector<int> preSum(ns, 0);
        preSum[0] = nums[0];
        // preSum
        for(int i = 1 ; i< ns ; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }

        int count = 0;
        for(int j = 0; j < ns; j++ ) {
            if(preSum[j] == k)
                count++;
        }

        for(int i = 0; i< ns-1; i++) {
            for(int j = i+1; j< ns; j++) {
                if((preSum[j] - preSum[i]) == k)
                    count++;
            }
        }
        return count;
        
    }
};