class Solution{
public:
    int dp[1001][1001];
    bool isPalindrome(string s , int i , int j){
        if(i==j)return true;
        if(i>j)return true;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve( string s , int i , int j){
        if(i>=j ){
             return 0;
        }
        if(isPalindrome(s , i , j))return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i ; k<j;k++){
            // int tempAns = 1 + solve(s ,i , k) + solve( s , k+1 , j);
            int left =0 , right =0;
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else{
                left = solve(s , i , k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }
            else{
                right = solve(s , k+1 , j);
                dp[k+1][j]=right;
            }
            int tempAns = 1+ left + right;
            if(mn>tempAns){
                mn = tempAns;
            }
        }
        return dp[i][j]= mn;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        memset(dp,-1 , sizeof(dp));
        int ans = solve( str , 0 , n-1);
        return ans;
    }
};
