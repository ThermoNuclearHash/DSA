#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    vector<int> segTree;
    int n;
    void build(vector<int>& arr, int start, int end, int index) {
        if(start == end) {
            segTree[index] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        int left = 2*index+1, right = 2*index+2;
        build(arr, start, mid, left);
        build(arr, mid+1, end, right);
        segTree[index] = segTree[left]+segTree[right];	
    }
    void update(vector<int>& arr, int start, int end, int index, int pos, int value) {
        // cout<<start<<"   "<<end<<"   "<<index<<endl;
        if(start == end) {
            arr[pos] = value;
            segTree[index] = arr[pos];
            return;
        }
        int mid = (start+end)/2;
        if(pos <= mid) update(arr, start, mid, 2*index+1, pos, value);
        else update(arr, mid+1, end, 2*index+2, pos, value);
        segTree[index] = segTree[2*index+1]+segTree[2*index+2];
    }
    int query(int start, int end, int index, int l, int r) {
        // cout<<start<<"   "<<end<<"   "<<index<<"   "<<l<<"   "<<r<<endl;
        if(start >= l && end <= r) return segTree[index];
        if(l > end || r < start) return 0;
        int mid = (start+end)/2;
        int leftAns = query(start, mid, index*2+1, l, r);
        int rightAns = query(mid+1, end, index*2+2, l, r);
        return leftAns+rightAns;
    }
public: 
    SegmentTree(int n) {
        this->n = n;
        segTree.resize(4*n-1, 0);
    }
    void debug(vector<int>& arr) {
        for(auto el: arr) cout<<el<<"   ";
        cout<<endl;
    }
    void debug() {
        for(auto el: segTree) cout<<el<<"   ";
        cout<<endl;
    }
    void build(vector<int>& arr) {
        build(arr, 0, arr.size()-1, 0);
    }
    void query(int start, int end) {
        cout<<query(0, n-1, 0, start, end)<<endl;
    }
    void update(vector<int>& arr, int pos, int value) {
        update(arr, 0, n-1, 0, pos, value);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    SegmentTree tree = SegmentTree(arr.size());
    tree.debug(arr);
    tree.build(arr);
    tree.debug();
    tree.query(0, 4);
    tree.update(arr, 5, 22);
    tree.debug(arr);
    tree.debug();
    tree.query(5, 7);
    return 0;
}