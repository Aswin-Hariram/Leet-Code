class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++){
            if(i>0 && letters[i]==letters[i-1]) continue;
            if(letters[i]>target){
                return letters[i];
            }
        }
        return letters[0];
    }
};