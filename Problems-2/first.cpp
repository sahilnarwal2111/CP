#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cstdlib>
#include <numeric>
#include <climits>
#define mod (ll)(1e9+7)
// #define int long long
#define ll long long
#define endl '\n'
using namespace std;
<<<<<<< HEAD
<<<<<<< HEAD
/// cd "/Users/sahilnarwal/Documents/CP/Problems-2/" && g++ --std=c++20 dijsktra.cpp -o dijsktra && "/Users/sahilnarwal/Documents/CP/Problems-2/"dijsktra
=======

>>>>>>> parent of ef77915 (CP)
vector<int> factors(int n){
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i * i <= n ; i++){
        while(n % i == 0){
            ans.push_back(i);
            n /= i;
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
=======

void solve() {   
    int n, k;
    cin>>n>>k;
    string str; cin>>str;
    int f[26];
    for(int i = 0 ; i < 26 ; i++) f[i]  = 0;
    for(int i = 0 ; i < n ; i++){
        int idx = str[i] - 'a';
        f[idx]++;
    }
    int odd = 0;
    int even = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(f[i] & 1) odd++;
        else even++;
    }
    if(odd == 1) {
        cout<<"YES"<<endl;
        return ;
    }
    if(odd - 1 > k ){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;





>>>>>>> parent of 9ac6304 (day - 3)
}


int gcd(int a, int b){
    vector<int> f1 = factors(a);
    vector<int> f2 = factors(b);
    // for(auto el : f1) cout<<el<<" ";
    // cout<<endl;
    // for(auto el : f2) cout<<el<<" ";
    // cout<<endl;
    unordered_map<int, int > um1, um2;
    for(auto el : f1) um1[el]++;
    for(auto el : f2) um2[el]++;
    int ans = 1;
    for(auto itr = um1.begin(); itr != um1.end(); itr++){
        int pn = itr->first;
        if(um2[itr->first] > 0){
            int f = min(itr->second, um2[itr->first]);
            while(f--){
                ans *= (itr->first);
            }
        }
    }
    return ans;
}

void solve() {   
    int n, q; cin>>n>>q;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    int sum = 0;
    int pre[n];
    pre[0] = arr[0];
    for(int i = 1 ; i < n ; i++){
        pre[i] = pre[i-1] + arr[i];
    }
    for(int i = 0 ; i < n ; i++) sum += arr[i];
    while(q--){
        int l, r, k ; 
        cin>>l>>r>>k;
        int tmp = k * (r - l + 1);
        int s = 0;
        if(l == 1){
            s = pre[r-1];
        }
        else{
            s = pre[r-1] - pre[l-2];
        }
        int v1 = sum - s;
        int v2 = tmp;
        int f = v1 + v2;
        if(f & 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
<<<<<<< HEAD


<<<<<<< HEAD

=======
    // int v1, v2;
    // int ans = 0;
    // // up a //left b
    // v1 = y1 + a;
    // v2 = x1 - b;
    // //check
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 - b == x2 && v1 - a == y2) {
    //     ans++;
    // }

    // //up a // right b
    // v1 = y1 + a;
    // v2 = x1 + b;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 + b == x2 && v1 - a == y2) {
    //     ans++;
    // }

    // // left a // up b
    // v1 = y1 + b;
    // v2 = x1 + a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 + b == y2 && v2 - a == x2) {
    //     ans++;
    // }

    // //left a // down b
    // v1 = y1 - b;
    // v2 = x1 + a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 - b == y2 && v2 - a == x2) {
    //     ans++;
    // }

    // // down a right b
    // v1 = y1 - a;
    // v2 = x1 + b;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 + b == x2 && v1 +a == y2) {
    //     ans++;
    // }

    // //down a left b
    // v1 = y1 - a;
    // v2 = x1 - b;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 - b == x2 && v1 + a == y2) {
    //     ans++;
    // }

    // //left a down b
    // v1 = y1 - b;
    // v2 = x1 - a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 - b == y2 && v2 + a == x2) {
    //     ans++;
    // }

    // //left a up b
    // v1 = y1 + b;
    // v2 = x1 - a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 + b == y2 && v2 + a == x2) {
    //     ans++;
    // }


    // //     // up a //left b
    // // v1 = y1 + b;
    // // v2 = x1 - a;
    // // //check
    // // if(v2 - a == x2 && v1 - b == y2) ans++;

    // // //up a // right b
    // // v1 = y1 + b;
    // // v2 = x1 + a;
    // // if(v2 + a == x2 && v1 - b == y2) ans++;

    // // // left a // up b
    // // v1 = y1 + a;
    // // v2 = x1 + b;
    // // if(v1 + a == y2 && v2 - b == x2) ans++;

    // // //left a // down b
    // // v1 = y1 - a;
    // // v2 = x1 + b;
    // // if(v1 - a == y2 && v2 - b == x2) ans++;

    // // // down a right b
    // // v1 = y1 - b;
    // // v2 = x1 + a;
    // // if(v2 + a == x2 && v1 +b == y2) ans++;

    // // //down a left b
    // // v1 = y1 - b;
    // // v2 = x1 - a;
    // // if(v2 - a == x2 && v1 + b == y2) ans++;

    // // //left a down b
    // // v1 = y1 - a;
    // // v2 = x1 - b;
    // // if(v1 - a == y2 && v2 + b == x2) ans++;

    // // //left a up b
    // // v1 = y1 + a;
    // // v2 = x1 - b;
    // // if(v1 + a == y2 && v2 + b == x2) ans++;

    // cout<<ans<<endl;
>>>>>>> parent of 9ac6304 (day - 3)
=======
>>>>>>> parent of ef77915 (CP)
