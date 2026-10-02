class Solution {
public:
    void generate(vector<string> &ans , string str , int n , int m){
        if(n==0 && m==0){
            ans.push_back(str);
            return;
        }
        if( m >0) generate(ans , str + ')' , n ,m-1 );
        
        if(n>0) generate(ans , str + '(' , n-1 , m+1);
        
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans , "" , n , 0);
        return ans;
        
    }
};