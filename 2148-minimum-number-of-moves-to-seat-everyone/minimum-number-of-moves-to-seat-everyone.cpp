class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& st) {
        int result = 0;
        sort(seats.begin(),seats.end());
        sort(st.begin(),st.end());
        for(int i = 0;i < seats.size(); i++){
            result += abs(st[i] - seats[i]);
        }
        return result;
    }
};