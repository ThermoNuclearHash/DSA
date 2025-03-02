#include <vector>
#include <map>
using namespace std;

//https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

int totalFruits(vector<int> &arr) {
    int n = arr.size();
    int l = 0, r = 0, maxlen = 0;
    map<int, int> mp;
    while(r < n) {
        mp[arr[r++]]++;
        if(mp.size() > 2) {
            mp[arr[l]]--;
            if(mp[arr[l]] == 0) mp.erase(arr[l]);
            l++;
        }
        if(mp.size() <= 2) maxlen = max(maxlen, r-l);
    }
    return maxlen;
}