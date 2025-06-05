class Solution {
public:
    int fillCups(vector<int>& amount) {
        int total = amount[0] + amount[1] + amount[2];
        int maxCup = max({amount[0], amount[1], amount[2]});
        return max(maxCup, (total + 1) / 2);
    }
};