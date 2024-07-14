class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            int left=i,right=i;
            while((left>=0 && right<n) && s[left]==s[right]){
                int x=right-left+1;
                
                if(x>len){
                    len=x;
                    ans=s.substr(left,len);
                }
                left--;
                right++;
            }
            left=i,right=i+1;

            while((left>=0 && right<n) && s[left]==s[right]){
                 int x=right-left+1;
                
                if(x>len){
                    len=x;
                    ans=s.substr(left,len);
                }
                left--;
                right++;
            }
        }

        return ans;
    }
};