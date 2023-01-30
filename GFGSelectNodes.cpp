class Solution{
  public:
  int count =0;
  vector<bool>vis;
    bool solvedfs(vector<vector<int>>&adj , int parent ){
        vis[parent]=true;
        bool selected =false;
        for(auto child : adj[parent]){
            //Child should not be visited and child not selected
            if(!vis[child] && !solvedfs(adj , child)){
                selected = true;
            }
        }
        if(selected == true){
            count++;
        }
        return selected;
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<vector<int>>adj(N+1);
        vis = vector<bool>(N+1,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        solvedfs(adj ,1);
        return count ;
        
    }
};
