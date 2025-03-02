#include <vector>
using namespace std;

//https://leetcode.com/problems/max-consecutive-ones-iii/

int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0, z = 0, n = nums.size();
    int maxlen = 0;
    while(r < n) {
        if(nums[r] == 0) {
            z++;
        }
        r++;
        if(z > k) {
            if(nums[l++] == 0) z--;
        }
        maxlen = max(maxlen, r-l);
    }
    return maxlen;
}