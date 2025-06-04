class Solution {
public:
    int addDigits(int num) {
        

        while(num > 9)
        {
            int sum =0,r;
            
            while(num != 0)
            {
                int r = num%10;
                sum += r;
                num /= 10;
            }
             num = sum;
        }
        return num;


    }
};