class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int ts = temperatures.size();

        vector<int> ans (ts,0);
        stack<pair<int,int>> st;

        ans[ts- 1] = 0;
        st.push({temperatures[ts-1], ts-1 });

        for( int i = ts - 2 ; i >= 0 ; i-- ) {

            // if(!st.empty() && temperatures[i] < st.top().first ) {
            //     ans[i] = st.top().second - i; 
            //     st.push({temperatures[i], i});
            // }
            // else {
                while( !st.empty() && st.top().first  <= temperatures[i] ) {
                    st.pop();
                }
                if(st.empty()) {
                    ans[i] = 0;
                }
                else {
                    ans[i] = st.top().second - i; 
                }
                st.push({temperatures[i], i});
            // }
        }
        return ans;
    }
};