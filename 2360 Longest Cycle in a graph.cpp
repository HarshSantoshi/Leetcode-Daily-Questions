class Solution {
public:
    void dfs(int node , vector<int>&vis , vector<int>&edges , vector<int>&dis_arr  ,int dist, int &ans){
        if(node!=-1){
            if(!vis[node]){
                vis[node]=1;
                dis_arr[node]=dist;
                dfs(edges[node], vis , edges , dis_arr , dist+1 , ans);
            }
            else{
                ans = max(ans,dist - dis_arr[node]);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0);
        vector<int>dis_arr(n,0);
        int ans=-1
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , vis , edges , dis_arr ,0 ans);
            }
        }
        return ans;
    }
};
