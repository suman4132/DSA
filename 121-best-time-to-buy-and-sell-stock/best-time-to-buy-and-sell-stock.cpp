class Solution {
public:
    int maxProfit(vector<int>& price) {
        //initialize the profit an zero
        int profit  = 0;
        //initialize the buy an maximum 
        int buy = INT_MAX;
        // we will iterate and find maximum value
        for(int i =0;i<price.size();i++)
        {
            // here compare the buying price and selling price 
            if(buy > price[i])
             buy = price[i];
            // calculate the maximum profit 
             profit = max(profit , price[i] - buy);
        }
        // return the profit 
        return profit;
    }
};