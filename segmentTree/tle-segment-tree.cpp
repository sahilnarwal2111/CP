#include<bits/stdc++.h>
using namespace std;
vector<int> arr(10000);
vector<int> sgt(4 * 10000);

int leftChild(int index){
    return 2 * index;
}
int rightChild(int index){
    return 2 * index + 1;
}
int combineChilds(int left, int right){
    return left + right;
}
void build(int l, int r, int index){
    if(l == r){
        sgt[index] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, leftChild(index));
    build(m + 1, r, rightChild(index));

    sgt[index] = combineChilds(sgt[leftChild(index)], sgt[rightChild(index)]);
}

void update(int l, int r, int index, int update_index, int update_value){
    // leaf node
    if(l == r){
        sgt[index] = update_value; 
    }

    int m = (l + r) / 2;
    if(m >= update_index){
        // left side
        update(l, m, leftChild(index), update_index, update_value);
    }else{
        // right side
        update(m + 1, r, rightChild(index), update_index, update_value);
    }
    sgt[index] = combineChilds(sgt[leftChild(index)], sgt[rightChild(index)]);
}

int query(int l, int r, int index, int s, int e){
    // s and e are the asked range query in question
    // 1. doesn't overlap
    if(l > e || r < s) 
        return 0;

    // 2. completly overlap
    if(s >= l && e >= r){
        return sgt[index];
    }

    // partially overlap
    int m = (l + r) /2 ;
    int leftContribution = query(l, m, leftChild(index), s, e);
    int rightContribution = query(m + 1, r, rightChild(index), s, e);
    return combineChilds(leftContribution, rightContribution);
}

void solve(){
    int n;
    cin >> n;
    for(auto &i : arr)
        cin >> i;
    build(0, n - 1, 1);
    int q;
    cin >> q;
    while(q--){
        int type; 
        cin >> type;
        if(type == 1){
            // update query
            int index, x;
            cin >> index >> x;
            update(0, n - 1, 1, index - 1, x);
        }else{
            int l , r;
            cin >> l >> r;
            cout <<  query(0, n - 1, 1, l - 1, r - 1) << endl;
        }
    }
}