#include <string>
#include <map>
using namespace std;

int longestKSubstr(string s, int k) {
    int len = s.length();
    map<char, int> mp;
    int l = 0, r = 0, maxsize = 0;
    while(r < len) {
        mp[s[r]]++;
        if(mp.size() > k) {
            mp[s[l]]--;
            if(mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        } 
        if(mp.size() == k) {
            maxsize = max(maxsize, r-l+1);
        }
        r++;
    }
    if(maxsize == 0) return -1;
    return maxsize;
}