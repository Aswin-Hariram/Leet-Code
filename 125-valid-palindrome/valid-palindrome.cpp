class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        
        int left = 0;
        int right = n-1;

        while(left<=right){
            char l = s[left];
            char r = s[right];
            if(!isalnum(l)){
                left++;
                continue;
            }
            if(!isalnum(r)){
                right--;
                continue;
            }
            cout<<"comparing "<<l<<" and "<<r<<endl;
            if(tolower(l)!=tolower(r)){
                
                return false;
            }
            left++;
            right--;


        }
        
        return true;
    }
};