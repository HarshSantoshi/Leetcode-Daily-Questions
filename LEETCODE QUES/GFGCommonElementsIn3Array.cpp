class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int>res;
            int count =0;
          int i=0,j=0,k=0;
          while(i<n1 && j<n2 && k<n3){
              if(A[i]<B[j])i++;
              else if(B[j]<C[k])j++;
             else if(C[k]<A[i])k++;
              
              if(A[i]==B[j] && A[i]==C[k]){
                if(res.size()==0){
                    res.push_back(A[i]);
                    count++;
                }
               else if(res[count-1]!=A[i]){
                    res.push_back(A[i]);
                  count++;
                }
                 
                  i++;
                  j++;
                  k++;
              }
          }
            
            return res;
        }

};
