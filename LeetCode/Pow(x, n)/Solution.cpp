class Solution {
public:
    double getPower(double x, long n){
        double ans = 1;
        while(n > 0){
            if(n % 2 == 0){
                x *= x;
                n >>= 1;
            }else{
                ans *= x;
                n--;
            }
        }
        return ans;
    }
    
    double myPow(double x, long n) {
        double ans = getPower(x, abs(n));
        if(n < 0) ans = 1 / ans;
        return ans;
    }
};