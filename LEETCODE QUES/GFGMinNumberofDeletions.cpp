int dp[1001][1001];

int LCS(string a , string b , int n , int m){
  
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
    
}
int minDeletions(string str, int n) { 
    string reverseStr  = str;
    reverse(reverseStr.begin() , reverseStr.end());
    int lengthOfLCS = LCS(str , reverseStr  , n , n);
    int ans = n - lengthOfLCS;
    return ans;
} 
