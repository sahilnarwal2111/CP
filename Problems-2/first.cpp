// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by June 2025                         ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define endl "\n";
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()           
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int mod_exp(int base, int exp, int mod) {int result = 1; while (exp > 0) { if (exp % 2 == 1) { result = (result * base) % mod;} base = (base * base) % mod; exp /= 2; } return result; }
int mod_inv(int b, int mod){ return mod_exp(b, mod - 2, mod); }
int mod_add(int a, int b, int mod) {return (a + b) % mod;}
int mod_pro(int a, int b, int mod) {return (a * b) % mod;}
int mod_sub(int a, int b, int mod) {return (a - b + mod) % mod;}
int mod_div(int a, int b, int mod) { return (1LL * a * mod_inv(b, mod)) % mod ;}
//-----------------------------------------------------------------------------------------------------------------------------------------------

class SegmentTree{
public:
    vector<int> tree, lazy, arr;
    int n;
    SegmentTree(vector<int> &nums){
        arr = nums;
        n = sz(arr);
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        for(auto & i : lazy) 
            i = 0;
        build(0, 0, n - 1);
    }
    int leftChild(int idx){
        return 2 * idx + 1;
    }
    int rightChild(int idx){
        return 2 * idx + 2;
    }
    void build(int idx, int st, int end){
        if(st == end){
            tree[idx] = arr[st];
            return;
        }
        int mid = (st + end) / 2;
        build(leftChild(idx), st, mid);
        build(rightChild(idx), mid + 1, end);
        tree[idx] = tree[leftChild(idx)] + tree[rightChild(idx)];

    }
    void push(int idx, int st, int end){
        if(lazy[idx]){
            tree[idx] += (end - st + 1) * lazy[idx];
            if(st != end){
                lazy[leftChild(idx)] += lazy[idx];
                lazy[rightChild(idx)] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    int sum(int idx, int st, int end, int leftQuery, int rightQuery){
        push(idx, st, end);

        if(end < leftQuery || st > rightQuery){ 
            return 0;
        }
        if(st == end){
            return tree[idx];
        }

        if(st >= leftQuery && end <= rightQuery){
            return tree[idx];
        }
        
        int mid = (st + end) / 2;
        int leftValue = sum(leftChild(idx), st, mid, leftQuery, rightQuery);
        int rightValue = sum(rightChild(idx), mid + 1, end, leftQuery, rightQuery);

        return leftValue + rightValue;
    }

    void update(int idx, int st, int end, int leftQuery, int rightQuery, int val){
        push(idx, st, end);
        
        if(st > rightQuery || end < leftQuery) {
            return;
        }
        if(st >= leftQuery && end <= rightQuery){
            lazy[idx] += val;
            push(idx, st, end);
            return;
        }

        int mid = (st + end) /2 ;
        update(leftChild(idx), st, mid, leftQuery, rightQuery, val);
        update(rightChild(idx), mid + 1, end, leftQuery, rightQuery, val);
        tree[idx] = tree[leftChild(idx)] + tree[rightChild(idx)];
    }

}; 


void solve(int t, int currentTestCase) {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for(auto &i : arr) 
        i = 0;
    SegmentTree *st = new SegmentTree(arr);
    while(c--){
        int type;
        cin >> type;
        int p, q;
        cin >> p >> q;
        p--;
        q--;  
        if(type){
            // sum
            cout << st->sum(0, 0, n - 1, p, q) << endl;
        }else{ 
            // update
            int v; 
            cin >> v;
            st->update(0, 0, n - 1, p, q, v);
            // cout << p << " " << q << " " << v << endl;
            // for(auto &i : st->tree){
            //     cout << i << " ";
            // }
            // cout << endl;
        }   
    }
    delete st;    
}
signed main() {
    #ifndef ONLINE_JUDGE
        auto begin = std::chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("Error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);  
        freopen("output.txt", "w", stdout); 
    #endif  
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(t, i);
    }

    #ifndef ONLINE_JUDGE
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}