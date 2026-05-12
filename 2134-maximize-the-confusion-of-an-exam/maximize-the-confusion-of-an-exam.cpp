class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> freq;
        int maxFreq = 0;


        int left = 0;
        int ans = 0;
        for(int right = 0; right<answerKey.size();right++){

            freq[answerKey[right]]++;

            maxFreq = max(maxFreq, freq[answerKey[right]]);

            while((right-left+1)-maxFreq > k) {
                freq[answerKey[left]]--;
                left++;
            }

            ans = max(ans,(right-left)+1);

        }
        return ans;
    }
};