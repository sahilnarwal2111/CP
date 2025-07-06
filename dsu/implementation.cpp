#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll N = 5e6+6;

vector<ll> parent(N, N + 1), Size(N, 0ll);

void make(ll v){
    parent[v] = v;
    Size[v] = 1ll;
}

ll find(ll v){
    if(parent[v] == v) {
        return v;
    }else{
        return find(parent[v]);
    }
}

ll Union(ll a, ll b){
    ll parent_of_a = find(a);
    ll parent_of_b = find(b);
    if(parent_of_a == parent_of_b){
        return parent_of_a;
    } 
    if(Size[parent_of_a] > Size[parent_of_b]){
        parent[parent_of_b] = parent_of_a;
        Size[parent_of_a]+=Size[parent_of_b];
        return parent[parent_of_b];
    }else{
        parent[parent_of_a] = parent_of_b;
        Size[parent_of_b]+=Size[parent_of_a];
        return parent[parent_of_a];
    }
    
}

signed main(){
    ll n, m;
    cin >> n >> m;
    // //taking input for m groups
    for(ll i = 1; i <= m ; i++){
        ll k;
        cin >> k;
        // cout << k << endl;
        if(k == 0) continue;
        ll initalParent;
        for(ll j = 0; j < 1; j++){
            ll cur;
            cin >> cur;
            if(parent[cur] == N + 1) make(cur);
            initalParent = find(cur);
        }    
        for(ll j = 1; j < k ; j++){
            ll cur;
            cin >> cur;
            if(parent[cur] == N + 1){
                make(cur);
            }
                Union(initalParent, cur);
            
        }   
    }
    for(ll i = 1; i <= n; i++){
        if(parent[i] != N + 1){
            cout << Size[find(i)] << " ";
        }
        else cout << 1 << " ";
    }
    cout << endl;
    return 0;
}