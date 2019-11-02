class Solution {
public:
    int minSteps(int n) {
        int ret = 0;
        while(n > 1){
            int flag = 1;
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    ret += i;
                    flag = 0;
                    n /= i;
                    break;
                }
            }
            if(flag) {
                ret += n;
                break;
            }
        }
        return ret;
    }
};