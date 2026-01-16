class Solution {
public:

    bool isPalindrome(string st,int s,int e){

        while(s<=e){
            if(st[s++]!=st[e--]){
                return false;
            }
        }
        return true;
    }

    void partition(int index,string s,vector<vector<string>> &ans,vector<string> &temp){
        if(s.length()==index){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                partition(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;

        partition(0,s,ans,temp);
        return ans;
    }
};