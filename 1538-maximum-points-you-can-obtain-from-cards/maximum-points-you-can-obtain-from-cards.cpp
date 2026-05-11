class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int totalSum = 0;

        for(int x : cardPoints) {
            totalSum += x;
        }

        // Take all cards
        if(k == n) return totalSum;

        int windowSize = n - k;  // not pick

        int curSum = 0;

        int left =0;
        int minTotal = INT_MAX;

        for(int right = 0;right<n;right++){

            curSum += cardPoints[right];

            if(right - left + 1 == windowSize){
                minTotal = min(minTotal, curSum);


                curSum -= cardPoints[left];
                left++;

            }

        }

        return totalSum - minTotal;
    }
};