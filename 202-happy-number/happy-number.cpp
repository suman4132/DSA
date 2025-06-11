class Solution {
public:
    bool isHappy(int n) {
        int sum = n, x = n;
        while(sum > 9)
        {
            sum =0;
            while( x > 0)
            {
                int d = x%10;
                sum += d*d;
                x /= 10;
            }
            x = sum;

        }
        if( sum == 7 ||sum == 1)
         return true;
        return false; 
    }
};