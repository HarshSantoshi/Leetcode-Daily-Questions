#include<bits/stdc++.h>
#include<algorithm>
class Solution {
public:
int minimum(int a ,int b){
    if(a>b){
        return b;
    }
    return a;
}
int maximum(int a,int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
    int maxProfit(vector<int>& prices) {
        int minsoFar=prices[0];
        int maxProf =0;
        for(int i=0;i<prices.size();i++){

            minsoFar=minimum(minsoFar,prices[i]);
            int profit = prices[i]-minsoFar;
            maxProf =maximum(maxProf,profit);
        }
        return maxProf;
    }
};