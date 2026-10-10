class Solution {
public:
    void subsetSum(int i, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& subset, int target, int currSum) {

        // base condition
        if(currSum == target) {
            ans.push_back(subset);
            return;
        }


        // if(currSum > target)
        //     return;
            
        
        // if( i == candidates.size()) {
        //     return;
        // }

       
        // if we include and required to be included
        // subset.push_back(candidates[i]);
        // currSum += candidates[i];
        // subsetSum(i+1, candidates, ans, subset, target, currSum);
        // // if((currSum + candidates[i]) <= target) {
        // //     subset.push_back(candidates[i]);
        // //     currSum += candidates[i];
        // //     subsetSum(i+1, candidates, ans, subset, target, currSum);
        // // }

        // // if we exclude
        // subset.pop_back();
        // currSum -= candidates[i];
        // subsetSum(i+1, candidates, ans, subset, target, currSum);
        for(int idx=i;idx<candidates.size();idx++){
            if(idx>i && candidates[idx]==candidates[idx-1])continue;
            if(currSum+candidates[idx]<=target){
                subset.push_back(candidates[idx]);
                subsetSum(idx+1,candidates,ans,subset,target,currSum+candidates[idx]);
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> tempVec;
        vector<int> subset;
        subsetSum(0, candidates, tempVec, subset, target, 0);
        
        return tempVec;
        
    }
};