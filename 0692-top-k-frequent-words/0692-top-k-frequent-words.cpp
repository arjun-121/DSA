class Solution {
public:

// Comparator function to sort pairs 
// according to second value 
static bool cmp(pair<string, int>& a, 
        pair<string, int>& b) 
{ 
    if(a.second != b.second) {
        return a.second > b.second; 
    }
    return a.first < b.first;
} 


    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> word_map;

        for(int i =0; i< words.size();i++) {
            word_map[words[i]] += 1;
        }

        // Declare vector of pairs 
        vector<pair<string, int> > A; 

        // Copy key-value pair from Map 
        // to vector of pairs 
        for (auto& it : word_map) { 
            A.push_back(it); 
        } 

        // Sort using comparator function 
        sort(A.begin(), A.end(), cmp);

        for (auto& it : A) { 

        cout << it.first << ' '
            << it.second << endl; 
        }  
        
        vector<string> ans;
        for(auto& it : A) {
            
            if(k) {
                ans.push_back(it.first);
                k--;
            }
            else
                break;
            
        }
        return ans;
        
    }
};