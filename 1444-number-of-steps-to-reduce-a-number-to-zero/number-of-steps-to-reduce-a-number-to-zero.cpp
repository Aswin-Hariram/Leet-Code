class Solution {
public:
    
    int solve(int n){
        if(n<=0) return 0;
        if(n%2 == 0){
            return 1 + solve(n/2);
        }
        else{
            return 1 + solve(n-1);
        }
        return 0;
    }
    int numberOfSteps(int num) {
        return solve(num);
    }
};