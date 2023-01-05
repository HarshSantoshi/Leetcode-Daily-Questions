
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
//   int dp[201][201];
//   int solve(int n , int k){
//       if(k==1||k==0){
//             return k;
//         }
//         if(n==1){
//             return k;
//         }
//         if(dp[n][k]!=-1){
//             return dp[n][k];
//         }
//         int mn= INT_MAX;
//         for(int floor =1 ;floor<=k;floor++){
//             int breakAns = solve(n-1 , floor-1);
//             int nobreakAns = solve(n , k-floor);
//             int worstAns = 1 + max(breakAns , nobreakAns);
//             mn = min(mn , worstAns);
//         }
//         return dp[n][k]=mn;
//   }
//     int eggDrop(int n, int k) 
//     {
//         // your code here
//         memset(dp,-1,sizeof(dp));
//         int ans = solve(n,k);
//         return ans;
//     }
int f(int floors, int eggs,vector <vector <int>> &dp){
    if(eggs == 1) return floors; //if we have only one egg left, we will start from bottom most floor.
    if(floors == 0) return 0; //if we have no floors, we dont require any step.
    
    if(dp[floors][eggs] != -1) return dp[floors][eggs]; // if we have already explored the floors with these many 
                                                        //remaining eggs, we can reuse it to save time.
    
    int low = 1, high = floors; 
    int mini = INT_MAX; // to store minimum no of steps.
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        int notBreak = f(floors-mid, eggs, dp); //if egg doesn't break, try from above floors.
        int breaks = f(mid-1, eggs-1, dp); //if egg breaks, we will try from below floors.
        
        if(breaks > notBreak){
            mini = min(mini, breaks + 1);
            high = mid - 1;
        } else{
            mini = min(mini, notBreak + 1);
            low = mid + 1;
        }
    }
    
    return dp[floors][eggs] = mini; // while returning the answer, store the ans so that we can use it again.
}

int eggDrop(int eggs, int floors) {
    vector <vector <int>> dp(floors+1, vector <int> (eggs+1, -1));
    
    return f(floors, eggs, dp);
}

};
