class Solution{
public:
    int dp[101][101];
    int solve(int arr[] , int i , int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int tempAns = solve(arr, i , k ) + solve(arr , k+1 , j) + arr[i-1]*arr[k]*arr[j];
            if(ans>tempAns){
                ans = tempAns;
            }
        }
        return  ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp , -1 , sizeof(dp));
        int ans = solve(arr , 1 , N-1);
        return ans;
    }
};
