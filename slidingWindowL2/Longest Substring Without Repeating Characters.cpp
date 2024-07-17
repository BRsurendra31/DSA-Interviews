class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> ans;
        int maxx = 0;
        int start = 0;
        int end = 0;

        while (start < s.size()) {
            auto it = find(ans.begin(), ans.end(), s[start]);
            if (it == ans.end()) {
                ans.push_back(s[start]);
                maxx = max(maxx, start - end + 1);
                start++;
            } else {
                while (it != ans.end()) {
                    ans.erase(ans.begin());
                    end++;
                    it = find(ans.begin(), ans.end(), s[start]);
                }
                ans.push_back(s[start]);
                start++;
            }
        }

        return maxx;
    }
};


// eASY one 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.length();
        int index[256];

        for(int i=0; i<256; i++) {
            index[i]=-1;
        }

        int begin=0, maxLength=0;

        for(int i=0; i<n; i++) {
            if(index[s[i]]>=begin) {
                begin= index[s[i]]+1;
            }

            index[s[i]]= i;
            maxLength= max(maxLength, i-begin+1);
        }
        return maxLength;
    }
};

