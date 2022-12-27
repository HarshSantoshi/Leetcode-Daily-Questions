class Solution {
public:

//T.C=O(nlogn)
//S.C=O(1)
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        int count=0;
    
        for(int i=0;i<n;i++){
            rocks[i]=(capacity[i]-rocks[i]);
        }
        sort(rocks.begin(),rocks.end());
        for(int i=0;i<n;i++){
            if(rocks[i]==0){
                count++;
            }
            else {
                if(additionalRocks>=rocks[i]){
                    additionalRocks-=rocks[i];
                    count++;
                }
            }
        }
        return count;
        
    }
};
