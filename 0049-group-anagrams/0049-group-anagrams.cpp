class Solution {
public:

    // vector<vector<string>> checkAnagram(vector<string> & strs) {
    //     string tempStr = strs[0];
    //     int sizeOfStr = tempStr.size();
    //     map<char, int> charMap;

    //     for(auto &it : tempStr ) {
    //         charMap[*it] += 1;
    //     }

    //     for(int i = 1; i < strs.size(); i++ ) {
    //         string newStr = strs[i];

    //         if(newStr.size() != sizeOfStr) {
    //             vector<string>
    //         }
    //     }

    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // int strLen = strs.size();

        // // 1. Get the sum of chars and create map
        // map<int, vector<string>> strMap;

        // for(int i = 0; i < strLen; i++) {
        //     int chrSum = 0;
        //     string tempStr = strs[i];
        //     for(int j = 0; j < tempStr.size(); j++) {
        //         chrSum += int(tempStr[j] - 'a' + 1);
        //     }

        //     strMap[chrSum].push_back(tempStr);
        // }

        // vector<vector<string>> ans;

        // for(auto &it : strMap) {    
        //     vector<string> vecStr = it.second;
        //     if(vecStr.size() > 1) {
        //         vector<vector<string>> tempAns = checkAnagram(it.second);
        //     }
        //     else {
        //         ans.push_back(vecStr);
        //     }
        // }

        // return ans;

        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string tempStr = s;
            sort(tempStr.begin(), tempStr.end());
            mp[tempStr].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto& p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;

        
    }
};