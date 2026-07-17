class Solution {
public:

    double solve(double x, int n){

        if(n == 0) return 1;

        double half = solve(x, n / 2);

        if(n % 2 == 0){
            return half * half;
        }
        else{
            return x * half * half;
        }
    }

    double myPow(double x, int n) {
        bool f = false;
        if(n==INT_MIN){
            n+=1;
            f=true;
        }

        int N = n;

        // Handle negative powers
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        if(f) return x * solve(x,N);
        return solve(x, N);
    }
};