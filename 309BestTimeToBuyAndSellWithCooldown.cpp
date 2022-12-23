class Solution {
public:
// int solve(vector<int>&prices , int ind , int buy, vector<vector<int>>&dp){
//     if(ind>=prices.size())return 0;
//     if(dp[ind][buy]!=-1) return dp[ind][buy];

// int profit =0;
//     if(buy){
//         int buyStock = -prices[ind] +  solve(prices , ind+1, 0,dp);
//         int skip = 0 + solve(prices, ind+1 , 1,dp);
//        return  dp[ind][1] = max(buyStock ,skip);
//     }
    
//         int sellStock = prices[ind]+  solve(prices , ind+2,1,dp);
//         int skip = 0+solve(prices , ind+1,0 ,dp);
//        return  dp[ind][0]= max(sellStock ,skip);
    
//     // return profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>>dp(n+1 , vector<int>(2,-1));
//         return solve(prices,0 , 1,dp);
//     }
int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}
};
