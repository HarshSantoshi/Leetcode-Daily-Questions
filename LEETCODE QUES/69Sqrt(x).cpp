class Solution {
public:
    int mySqrt(int x){

        //Newton Method 
    //    long r = x;
    //    while(r*r>x)
    //    r=(r+x/r)/2;
    //    return r;


    //Using Binary Search 
    if (0 == x) return 0;
    if(x==1||x==2)return 1;
        int left = 1, right = x/2, ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
