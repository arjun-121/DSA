class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        int n = s.size();

        int i = 0;
        int ans = 0;
        while(i < n) {
            if(s[i] == '(') {
                st.push("(");
            }
            else {
                int curr = 0;
                while(!st.empty() && st.top() != "(") {
                    curr += stoi(st.top());
                    st.pop();
                }
                st.pop();
                if(!curr) {
                    st.push(to_string(1));
                }
                else {
                    st.push(to_string(2*curr));
                }
            }
            i++;
        }
        while(!st.empty()){
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
        
    }
};