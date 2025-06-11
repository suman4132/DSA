class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        unordered_map<char,int>temp;

        for(int i =0;i<n;i++)
        {
            temp[s[i]]++;
        }
        vector<int>odd;
        vector<int>even;
        for(auto c : temp)
        {
            if(c.second %2 != 0)
            {
                odd.push_back(c.second);
            }
            else
            {
                even.push_back(c.second);
            }
        }
        int m = *max_element(odd.begin(), odd.end());
        int k = *min_element(even.begin(), even.end());

        return m - k;
    }
};