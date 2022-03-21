class Solution {
public:
    bool isPalindrome(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
    bool validPalindrome(string s) {
        if(isPalindrome(s))
            return true;
        int n = s.length();
        string str = "";
        for(int i = 0; i < n; i++) {
            if(s[i]==s[n-1-i]) continue;
            else {
                string t = s, r = s;
                t.erase(n-1-i,1);
                r.erase(i,1);
                return isPalindrome(t) || isPalindrome(r);
            }
        }
        return false;
    }
};