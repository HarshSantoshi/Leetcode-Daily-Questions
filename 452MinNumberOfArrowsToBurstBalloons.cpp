class Solution {
public:
    bool static cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() ,cmp);
        int n = points.size();
        if(n==0 || n==1){
            return n;
        }
        vector<bool>vis(n , false);
        int count =1;
        int last = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0] > last){
                count++;
                last = points[i][1];
            }
        }
        return count;
        
        return count;
        
    }
};
