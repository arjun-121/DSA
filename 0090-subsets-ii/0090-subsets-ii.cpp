class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = nums.size();
        
        sort(nums.begin(), nums.end());

        set<vector<int>> subsets;
        // vector<int> v ;
        // subsets.insert(v);

        for(int i = 0 ; i < pow(2,size) ; i++) {
            int temp = i;
            int k = 0;
            vector<int> tempVec;
            
            do {
                // cout << "temp ->> " << temp << "  ";
                if( temp & 1) {
                    tempVec.push_back(nums[k]);
                    
                }
                temp = temp >> 1;
                k++;
                // cout << "temp ->> " << temp << "\n";
            }
            while(temp);

            subsets.insert(tempVec);
            // for(auto it = tempVec.begin(); it != tempVec.end(); it++) {
            //     cout << *it << " -> ";
            // }
            // cout<<endl;
        }

        vector<vector<int>>ans;

        for(auto it = subsets.begin() ; it != subsets.end(); it++) {
            ans.push_back(*it);
        }

        return ans;
        
    }
};