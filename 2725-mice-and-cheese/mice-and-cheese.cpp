class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int total = 0;
        vector<int> diff;
        for (int i = 0; i < n; ++i) {
            total += reward2[i]; 
            diff.push_back(reward1[i] - reward2[i]); 
        }

        sort(diff.rbegin(), diff.rend()); 

        for (int i = 0; i < k; ++i) {
            total += diff[i]; 
        }
        return total;
    }
};