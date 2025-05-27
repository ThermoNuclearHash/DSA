#include <iostream>
#include <vector>

using namespace std;

class Lifter {
    vector<vector<int>> table;
    int mx = 17;
public:
    void build(vector<int>& parents) {
        int n = parents.size();
        table.resize(mx, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            table[0][i] = parents[i];
        }
        for(int i = 1; i < mx; i++) {
            for(int j = 0; j < n; j++) {
                if(table[i-1][j] != -1) table[i][j] = table[i-1][table[i-1][j]];
            }
        }
    }
    int query(int a, int k) {
        for(int i = 0; i < mx; i++) {
            if(a == -1) {
                return a;
            }
            int mask = (1<<i);
            if((k&mask) > 0) {
                a = table[i][a];
            }
        }
        return a;
    }
};

int main() {
    vector<int> parents = {-1, 0, 0, 1, 1, 2, 2};
    Lifter treelifter = Lifter();
    treelifter.build(parents);
    treelifter.query(5, 2);
    treelifter.query(5, 1);
    treelifter.query(1, 4);
    treelifter.query(3, 2);
    return 0;
}