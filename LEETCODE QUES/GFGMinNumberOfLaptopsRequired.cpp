class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        map<int,int>mp;
        for(int i=0;i<N;i++){
            mp[start[i]]+=1;
            mp[end[i]]-=1;
        }
        vector<pair<int,int>>combine;
        for(auto it:mp){
            combine.push_back(it);
        }
        int c= 0 , ans=0;
        for(pair<int,int>i:combine){
            c+=i.second;
            ans = max(ans , c);
        }
        
        return ans;
    }
};
