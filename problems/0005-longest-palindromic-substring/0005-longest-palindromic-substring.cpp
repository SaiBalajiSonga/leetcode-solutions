class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        int current_max = 0;
        int max_len = 0;
        int startIndex = 0;
        for(int i =0;i<s.length();i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            current_max = max(len1, len2);
            if(current_max > max_len){
                max_len = current_max;
                startIndex = i - (current_max - 1)/2;
            }
        }
        return s.substr(startIndex, max_len);
    }
private:
    int expand(string& s, int left, int right){
        while(left >= 0 && right < s.length() && s[left]==s[right]){
            --left;
            ++right;
        }
        return right - left - 1;
    }
};