class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans = {0};
        int n = temperatures.size();
        if(n == 1) {
            return ans;
        }

        stack< int> st;
        st.push(n - 1);

        for(int i = n-2 ; i >= 0 ; i-- ) {
            int temp = temperatures[i];

            while(!st.empty() && temperatures[st.top()] <= temp) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(0);
            }
            else {
                ans.push_back(st.top() - i);
            }
            st.push(i);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};