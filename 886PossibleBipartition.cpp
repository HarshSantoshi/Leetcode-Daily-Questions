class Solution {
public:
bool isBipartite(vector<vector<int>>&adj , vector<int>&color , int node , int n){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int ele:adj[curr]){
            if(color[ele]==color[curr]) return false;       //odd edges 
            if(color[ele] ==-1){
                color[ele]= 1-color[curr];  //opposite color as of ele
                q.push(ele);
            }
        }

    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            vector<int> color(n+1,-1);
            //Make an adjacency List
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        //Traverse every person
        for(int i=1;i<=n;i++){
           if(color[i]==-1){
               if(!isBipartite(adj , color , i , n)){
                   return false;
               }
           }
        }
        
        return true;
    }
};  
