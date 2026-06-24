class Solution {
    public:
        double myPow(double x, int n) {
            long long N = n;
            double ans = 1.0;
            if(N==0){
                return 1.0;
            }
            if(N<0){
                N = -N;
                x = 1/x;
            }
            double p = x;
            while(N>0){
                if(N & 1){
                    ans = ans*p;
                }
                p = p*p;
                N = N/2;
            }
            return ans;
        }
};