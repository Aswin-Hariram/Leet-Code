class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;

        int n = s.size();
        
        int wordLen = words[0].size();
        int wordCount = words.size();

        int windowLen = wordLen * wordCount;

        unordered_map<string,int> target;

        for(string w : words){
            target[w]++;
        }

        for(int i = 0; i < wordLen; i++){

            int left = i;
            int count = 0;

            unordered_map<string,int> window;

            for(int right = i; right + wordLen <= n; right += wordLen){

                string word = s.substr(right, wordLen);

                if(target.count(word)){

                    window[word]++;
                    count++;

                    while(window[word] > target[word]){

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count == wordCount){

                        res.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                }
                else{

                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return res;
    }
};