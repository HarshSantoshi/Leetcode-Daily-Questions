class Solution {
public:

    vector<int>res;

    vector<vector<int>>graph;

    vector<int>solve(int s , string &labels  , int par){
        vector<int>ans(26,0);
        ans[labels[s]-'a']++;
        for(int i=0;i<graph[s].size();i++){
            if(graph[s][i]==par){
                continue;
            }
            vector<int>sub = solve(i , labels , s);
            for(int i=0;i<26;i++)
            {
                ans[i]+=sub[i];
            }
        }

        res[s]=ans[labels[s]-'a'];

        return ans;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        res.resize(n,0);
        graph.resize(n,vector<int>{});
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        solve(0,labels,-1);
        return res;
    }
};
