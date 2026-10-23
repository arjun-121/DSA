class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int maxK = -1;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                // cout << "skipped -> " << i << "\n";
                i++;
                continue;
            }
            else {
                if(maxK != -1) {
                    maxK = maxK & i;
                }
                else
                    maxK = i;

                i++;
    
            }

            // int currNum = nums[i];
            // int swapNum = nums[currNum];
            // maxK = (currNum & swapNum) > maxK ? (currNum & swapNum) : maxK;

            // nums[i] = swapNum;
            // nums[currNum] = currNum;

            // if(nums[i] == i)
            //     i++;
            
        }

        return ( maxK == -1 )? 0 : maxK;
        
    }
};