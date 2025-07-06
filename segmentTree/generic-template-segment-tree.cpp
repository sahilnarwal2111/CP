#include<bits/stdc++.h>
using namespace std;
#define ll long long


// template<typename Node, typename Update>
// struct SegTree {
//     vector<Node> tree;
//     vector<ll> arr;
// }
// struct Node1 {
//     ll val; // may change
//     Node1() {
//         val = 1e9;      // may change
//     }
//     Node1(ll p1) { //Actual Node
//         val = p1;       // may change
//     }
//     void merge(Node1 &l, Node1 &r) {
//         val = min(l.val, r.val);        // may change
//     }
// };

// struct Update1 {
//     ll val; // may change
//     Update1(ll p1) { // Actual Update
//         val = p1; // may change
//     }
//     void apply(Node1 &a) { // apply change to give node
//         a.val = val; // may change
//         a.val = __gcd(a.val, val);
//     }
// };




int main(){
    // int n;
    // cin >> n;
    // vector<ll> arr(n);
    // for(int i = 0; i <n; i++){
    //     cin >> arr[i];
    // }
    // SegTree<Node1, Update1> sg = SegTree<Node1, Update1>(n, arr);
    // int q;
    // cin >> q;
    // while(q--){
    //     int type;
    //     cin >> type;
    //     if(type == 1){
    //         int i, x;
    //         cin >> i >> x;
    //         sg.make_update(i, x);
    //     }else{
    //         int l, r;
    //         cin >> l >> r;
    //         cout << sg.make_query(l, r).val << endl;
    //     }
    // }
    // freopen("output.txt", "w", stdout); 
    
    for(int i = 40 ; i > 0; i--){
        cout << i << " ";

    }
    cout << endl;
}