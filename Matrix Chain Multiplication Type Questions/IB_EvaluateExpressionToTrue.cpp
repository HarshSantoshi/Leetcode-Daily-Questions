


int mod =1003;

int solve(string &s , int i , int j , bool isTrue , vector<vector<vector<int>>>&dp){
    if(i>j){
        return false;
    }
    if(i==j){
        if(isTrue){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    
    int ans =0;
    for(int k=i+1 ;k<=j-1;k=k+2){
        int Lt = solve(s , i , k-1 , true ,dp);
        int Lf = solve(s , i , k-1 ,false ,dp);
        int Rt = solve(s , k+1 , j , true ,dp) ;
        int Rf = solve(s , k+1 , j , false ,dp);
        if(s[k]=='&'){
            if(isTrue){
                ans= (ans + (Lt*Rt)%mod)%mod ;
            }
            else{
                ans= (ans + (Lt *Rf )%mod+ (Lf*Rt)%mod + (Lf * Rf)%mod)%mod;
            }
        }
        else if(s[k]=='|'){
            if(isTrue){
                ans= (ans + (Lt*Rt)%mod + (Lt*Rf)%mod + (Lf*Rt)%mod)%mod;
            }
            else{
                ans= (ans + (Lf*Rf)%mod)%mod;
            }
        }
       else {
            if(isTrue){
                ans= (ans + (Lt*Rf)%mod + (Lf*Rt)%mod)%mod;
            }
            else{
                ans = (ans +(Lt*Rt)%mod + (Lf *Rf)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ans;
}

int Solution::cnttrue(string A) {
    int n = A.size();
    vector<vector<vector<int>>>dp(n ,vector<vector<int>>(n,vector<int>(2,-1)));
    int ans = solve(A , 0 , n-1 , 1 ,dp);
    return ans;
}
