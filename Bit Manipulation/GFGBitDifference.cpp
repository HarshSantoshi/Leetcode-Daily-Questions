
/*
You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B
*/

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int count =0;
        if(a==0 && b==0){
            return 0;
        }
        if(a==0){
            while(b>0){
                if(b&1){
                    count++;
                }
                b=b>>1;
            }
            return count;
        }
        if(b==0){
            while(a>0){
                if(a&1){
                    count++;
                }
                a=a>>1;
            }
            return count;
        }

        while(a>0 || b>0){
            int c =a&1;
            int d= b&1;
            if((c == 0 && d == 0) || (c!=0 && d!=0)){
                //Both are having last bit same
            }
            else{
             
                count++;
            }
            a=a>>1;
            b=b>>1;
        }
        return count;
        
    }
};
