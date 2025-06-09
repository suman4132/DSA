class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int count =0;
        sort(people.begin(),people.end());
        int left =0,right = n-1;
        while(left <= right)
        {
           if(people[left]+people[right] <= limit)
           {
            left++;
           }
           right--;
           count++;
        }
        return count;
    }
};