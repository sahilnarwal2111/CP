#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode{
    int maxVal;
};

class SegmentTree{
public:
    int n;
    vector<SegmentTreeNode> tree;
    vector<int> lazy;
    SegmentTree(int size){
        n = size;
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int indexOfRoot, int low, int high, vector<int> &arr){
        if(low == high){
            tree[low].maxVal = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build((indexOfRoot * 2 )+ 1, low, mid, arr);
        build((indexOfRoot * 2) + 2, mid +1 , high, arr);
        //backtrack step
        tree[indexOfRoot].maxVal = max(tree[2 * indexOfRoot + 1].maxVal, tree[2 * indexOfRoot + 2].maxVal);
        
    }
    int query(int idx, int rangeLow, int rangeHigh, int l, int r){
        if(rangeLow >= l && rangeHigh <= r){
            // it lies completely inside
            return tree[idx].maxVal;
        }
        if(rangeLow > r || rangeHigh < l){
            return INT_MIN;
        }
        int mid = (l + r) / 2;
        int oneAnswer = query(2 * idx + 1, rangeLow, rangeHigh, l, mid);
        int twoAnswer = query(2 * idx + 2, rangeLow, rangeHigh, mid + 1, r);
        return max(oneAnswer, twoAnswer);

    }   

    void pointUpdate(int ind, int low, int high, int node, int val){
        if(low == high) {
            tree[low].maxVal += val;
        }else{
            int mid = (low + high) >> 1;
            if(node >= low && node <= mid){
                pointUpdate(2 * ind + 1, low, high, node, val);
            }else{
                pointUpdate(2 * ind + 2, low , high, node, val);
            }
            tree[ind].maxVal += val;
        }
    }

    void rangeUpdate(int ind, int low, int high, int l, int r, int val){
        if(lazy[ind] != 0){
            tree[ind].maxVal += lazy[ind] * (high - low + 1);
            if(low != high){
                lazy[2 * ind + 1] = lazy[ind];
                lazy[2 * ind + 2] = lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(low > r || high < l || low > high) return ;

        if(low  >= l && high <= r){
            tree[ind].maxVal += (high - low + 1) * val;
            if(low != high){
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            return;
        }
        int mid = (low + high) >> 1;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid + 1, high, l , r, val);
        tree[ind].maxVal = tree[2 * ind + 1].maxVal + tree[2 * ind + 2].maxVal;


    }
    int sumQueryLazy(int ind, int low, int high, int l, int r){
        if(lazy[ind] != 0){
            tree[ind].maxVal += lazy[ind] * (high - low + 1);
            if(low != high){
                lazy[2 * ind + 1] = lazy[ind];
                lazy[2 * ind + 2] = lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(low > r || high < l || low > high) return 0;

    }

};


int main(){



    return 0;
}