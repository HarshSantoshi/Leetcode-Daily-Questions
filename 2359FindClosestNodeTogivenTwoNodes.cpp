class Solution {
public:
    void distances(vector<int>&node , int distance , vector<int>&edges ,  int n){
        if(n!=-1 && node[n]==-1){
            node[n]=distance;
            distances(node , distance +1 , edges , edges[n]);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>node1vec(n,-1);
        vector<int>node2vec(n,-1);
        distances(node1vec , 0 , edges , node1);
        distances(node2vec , 0 , edges , node2);
        int ans =-1;
        int minValue = INT_MAX;
        for(int i=0;i<n;i++){
            if(min(node1vec[i],node2vec[i])>=0 && max(node1vec[i],node2vec[i])<minValue ){
                minValue = max(node1vec[i],node2vec[i]);
                ans=i;
            }
        }
        return ans;

    }
};
