#include <string>
#include <algorithm>
using namespace std;

//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

int numberOfSubstrings(string s) {
    int hash[3] = {-1, -1, -1};
    int n = s.length(), ans = 0;
    for(int i = 0; i < n; i++) {
        hash[s[i]-'a'] = i;
        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1) {
            ans += (1+min({hash[0], hash[1], hash[2]}));
        }
    }
    return ans;
}