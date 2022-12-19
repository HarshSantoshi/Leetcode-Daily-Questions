// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
int n = temp.size();
      vector<int>ans(n,0);
      int i=0;
      int j=1;
      while(i!=n-1){
          if(j==n){
              ans.push_back(0);
              i++;
              j=i+1;
          }
          if(temp[j]>=temp[i]){
              ans.push_back(j-i);
              i++;
              j=i+1;
          }
          else if(temp[j]<temp[i]){
              j++;
          }
      }
      

      return ans;
    }
int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<int>temp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        temp.push_back(a);
    }
    vector<int>ans =  dailyTemperatures(temp);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}