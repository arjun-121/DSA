class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        map<int, int > freqMap;
        int smallest = INT_MAX;
        for(int i = 0; i< nums.size(); i++) {
            freqMap[nums[i]] += 1;
            smallest = min(smallest, nums[i]);
        }

        int prev = smallest;
        int maxWin = 0;
        int currWin = 0;
        for(const auto &[key, value] : freqMap) {
            cout << key << "  " << value << "  " << (key - prev) <<  "\n";
            if( ( key - prev ) < 2 ) {
                prev = key;
                currWin += 1;
                maxWin = max(maxWin, currWin);
            }
            else {
                maxWin = max(maxWin, currWin);
                currWin = 1;
                prev = key;
            }
        }

        return maxWin;
        
        
    }
};