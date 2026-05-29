class Solution {
public:
    int sumOfDigit(int num){
        int sum = 0;

        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int n:nums){
            int temp = sumOfDigit(n);
            res = min(res,temp);

        }
        return res;
    }
};