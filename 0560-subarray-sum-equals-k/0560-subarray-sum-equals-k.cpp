class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ns = nums.size();
        int count = 0, sum = 0;
        map<int,int> mp;
        mp.insert({0,1});

        for( int i = 0; i< ns; i++) {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum] = mp[sum] + 1;
        }

        return count;        
    }
};