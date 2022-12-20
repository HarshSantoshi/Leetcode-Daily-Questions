class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>unlocked(n,0);
        queue<int>q;
        q.push(0);
        unlocked[0]=1;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int k:rooms[current]){
                if(unlocked[k]==0){
                    q.push(k);
                    unlocked[k]=1;
                }
            }
        }
         for(int i=0;i<n;i++){
            if(!unlocked[i]){
                return false;
            }
        }
        return true;
     }
};
