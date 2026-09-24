class Solution {
public:
    int findMin(vector<int>& arr) {
        if(arr.size() == 1)
            return arr[0];
        
        int low = 0 , high = arr.size()-1;
        
        while(low < high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[high];
    }
};