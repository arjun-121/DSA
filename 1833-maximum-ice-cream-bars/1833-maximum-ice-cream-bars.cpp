class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        int rem = coins;
        for(int i = 0; i< costs.size();i++) {
            if(rem >= costs[i]) {
                count ++;
                rem = rem - costs[i];
            }
        }
        return count;
    }
};