
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1 || n==2){
            return n;
        }
        int count=0 ;
        int temp;
        for(int i=0;i<n;i++){     
            temp=0;
            unordered_map<double,int>map;
            double slope =0.0;
            for(int j=0;j<n;j++){
                int currmax=INT_MIN;
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int dy =y2-y1;
                int dx = x2-x1;
                if(dy==0 &&dx==0){
                    temp++;
                    continue;
                }
                if(dx!=0)
                    slope =dy*(1.0)/dx;  
                else
                    slope=INT_MAX;
                map[slope]++;
                
            }
            if(map.size()==0){
                count = temp;
            }
            else {
                for(auto slope:map){
                count = max(count , slope.second + temp);
            }
            }
        }
        return count ;
        
    }
};
