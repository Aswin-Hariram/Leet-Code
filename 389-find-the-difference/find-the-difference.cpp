class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mapp;
        for(char c:s){
            mapp[c]++;
        }

        for(char c:t){
            if(mapp[c]>0){
                mapp[c]--;

            }
            else{
                return c;
            }
        }
        return ' ';
    }
};