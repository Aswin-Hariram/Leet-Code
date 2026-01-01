class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;    // just add one and return
                return digits;
            }
            digits[i] = 0;       // if digit was 9, it becomes 0
        }

        // All digits were 9 (ex: 999 -> 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
