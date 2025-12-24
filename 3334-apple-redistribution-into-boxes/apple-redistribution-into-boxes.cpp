class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n= apple.size();
        int m = capacity.size();
        int sum1=0;
        int sum2 =0;
        int count =0;
        for(int i =0;i<n;i++)
        {
            sum1 += apple[i];
        }
        sort(capacity.rbegin(),capacity.rend());
        for(int i =0;i<m;i++)
        {
            sum2 += capacity[i];
            count++;
            if(sum2 >= sum1)
            {
                return count;

            }
        }
        return -1;
    }
};