class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
    int total_count =0;
    for(auto& ar : arr)
    {
       int m = min(truckSize, ar[0]);
       total_count += ar[1]*m;
       truckSize -= m;
       if(truckSize == 0)
       break;
    }
    return total_count;
    }
};