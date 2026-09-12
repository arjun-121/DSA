class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        vector<int> ans;
        while( i < j) {
            int currSum = numbers[i] + numbers[j];
            if(currSum == target) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if (currSum < target) {
                i++;
            }
            else 
                j--;
        }
        return ans;
    }
};