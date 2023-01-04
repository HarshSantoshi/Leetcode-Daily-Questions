class Solution
{
    public:
    int dp[101][101];
    int LCS(string X , string Y , int m , int n){
        if(m==0 || n==0){
            return 0;
        }
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(X[i-1]==Y[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        return m+n - LCS(X , Y , m , n);
    }
};
