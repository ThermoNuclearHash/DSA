#include <vector>
using namespace std;

//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

int maxScore(vector<int>& cardPoints, int k) {
    int l = 0, r = k-1, n = cardPoints.size();
    int sum = 0;
    for(int i = l; i <= r; i++) {
        sum += cardPoints[i];
    }
    l = n-1;
    int maxSum = sum;
    while(r >= 0) {
        sum += cardPoints[l--];
        sum -= cardPoints[r--];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}