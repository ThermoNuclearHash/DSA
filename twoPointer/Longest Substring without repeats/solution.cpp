#include <string>
#include <mem.h>
using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

int lengthOfLongestSubstring(string s) {
    bool hash[256];
    memset(hash, false, 256);
    int maxlen = 0;
    int l = 0, r = 0, n = s.length();
    while(r < n) {
        if(hash[s[r]]) {
            while(s[l] != s[r]) {
                hash[s[l]] = false;
                l++;
            }
            l++;
        } else {
            hash[s[r]] = true;
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}