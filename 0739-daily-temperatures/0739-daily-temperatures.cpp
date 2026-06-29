class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int ts = temperatures.size();
        vector<int> ans (ts,0);
        int maxVal = temperatures[ts-1];
        ans[ts - 1] = 0;

        for(int i = ts - 2; i >= 0 ; i--) {
            if(temperatures[i] >= maxVal) {
                maxVal = temperatures[i];
                ans[i] = 0;
                continue;
            }

            if( temperatures[i] < temperatures[i+1] ) {
                ans[i] = 1;
            }
            else {
                int k = ans[i+1];
                while( k > 0) {
                    if(temperatures[i] >= temperatures[i+1+k]){
                        k += ans[i+k+1];
                    }
                    else {
                        break;
                    }
                }
                ans[i] = k+1;
            }   
        }
        return ans;
    }
};