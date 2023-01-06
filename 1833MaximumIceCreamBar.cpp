  int maxIceCream(vector<int>&costs  , int coins){
        sort(costs.begin() , costs.end());
        int n = costs.size();
        int i=0;
        for(i=0;i<n;i++){
            if(costs[i]<=coins){
                coins -= costs[i];
            }
            else{
                break;
            }
        }
        return i;
    }
