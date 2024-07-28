class Solution {
public:
    string convert(string s, int num) {
        if(num==1) return s;
        int n=s.size(), idx=0, row=0;
        vector<string> vec(num, "");
        while(idx<n) {
            while(idx<n && row<num) {
                vec[row]+=s[idx];
                idx++;
                row++;
            }
            row-=2;
            while(idx<n && row>0) {
                vec[row]+=s[idx];
                idx++;
                row--;
            }
        }
        string res="";
        for(string &st:vec) res+=st;
        return res;
    }
};