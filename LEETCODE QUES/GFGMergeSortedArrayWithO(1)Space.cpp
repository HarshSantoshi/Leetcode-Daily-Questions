class Solution{
    public:
        //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m){
        int i =0 , j=0 , k=n-1;
        while(i<=k && j<m){
            
            if(arr1[i]<arr2[j])i++;
            
            else {
                swap(arr1[k],arr2[j]);
                k--;
                j++;
            }
        }
        //Sort 1st array
        sort(arr1,arr1+n);
        
        
        //Sort 2nd array
        sort(arr2, arr2+m);
    }
};
