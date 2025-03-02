#include <string>
using namespace std;

//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

int numberOfSubstrings(string s) {
    int hash[3] = {0, 0, 0};
    int lenOfChars = 0;
    int l = 0, r = 0, n = s.length(), ans = 0;
    while(r < n && l < n) {
        if(hash[s[r]-'a'] == 0) lenOfChars++;
        hash[s[r]-'a']++;
        if(lenOfChars == 3) {
            ans += n-r;
            hash[s[l]-'a']--;
            if(hash[s[l]-'a'] == 0) lenOfChars--;
            l++;
            hash[s[r]-'a']--;
            if(hash[s[r]-'a'] == 0) lenOfChars--;
            r--;
        }
        r++;
    }
    return ans;
}