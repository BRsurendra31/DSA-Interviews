
class Solution {
public:
    static bool cmp(string a, string b) {
        string s1 = a + b;
        string s2 = b + a;
        return s1 > s2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (auto n : nums) {
            str.push_back(to_string(n));
        }
        sort(str.begin(), str.end(), cmp);
        string ans = "";
        for (auto each : str) {
            ans += each;
        }
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};




// Using Custom Comparator
class Solution {
public:
    static bool cmp(string a, string b) {
        string s1 = a + b;//30 3
        string s2 = b + a;//3 30
        return s1 > s2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (auto n : nums) {
            str.push_back(to_string(n));
        }
        sort(str.begin(), str.end(), cmp);
        string ans = "";
        for (auto each : str) {
            ans += each;
        }
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};