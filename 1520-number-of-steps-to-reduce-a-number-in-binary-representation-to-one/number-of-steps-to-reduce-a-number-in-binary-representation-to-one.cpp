class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.length();
        
        // Traverse from right to left (ignore first bit)
        for(int i = n - 1; i > 0; i--) {
            
            int bit = (s[i] - '0') + carry;
            
            if(bit == 1) {
                // odd case
                steps += 2;
                carry = 1;
            } else {
                // even case
                steps += 1;
            }
        }
        
        // If carry remains, one extra step
        return steps + carry;
    }
};