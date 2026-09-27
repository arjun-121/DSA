class Solution {
public:
    int maxOccur(vector<int> & nums, int target) {
        int low = 0, hi = nums.size() - 1;
        int ans = -1;
        while(low <= hi) {
            int mid = (hi - low) / 2 + low;

            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if( nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    int minOccur(vector<int> & nums, int target) {
        int low = 0, hi = nums.size() - 1;
        int ans = -1;
        while(low <= hi) {
            int mid = (hi - low) / 2 + low;

            if(nums[mid] == target) {
                ans = mid;
                hi = mid - 1;
            }
            else if( nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int min = minOccur(nums, target);
        int max = maxOccur(nums, target);

        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};