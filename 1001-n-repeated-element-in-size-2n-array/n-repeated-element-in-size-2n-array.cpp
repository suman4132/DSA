class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n  = nums.size()/2 ;
        unordered_map<int,int>temp;
        for(int i = 0;i<nums.size();i++)
        {
            temp[nums[i]]++;
        }
        for(auto i : temp)
        {
            if( i.second == n)
            {
                return i.first;
            }
        }
        return -1;
    }
};