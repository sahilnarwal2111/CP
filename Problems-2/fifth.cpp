#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>

#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define int long long
#define endl '\n'
using namespace std;

bool rec(vector<int> & arr1, vector<int> & arr2, int i , int j , int cnt1, int cnt2, int k, int val){

}

void solve(){
    int n, m,k;
    cin>>n>>m>>k;
    int a1[n],a2[m];
    for(int i = 0 ; i < n ; i++) cin>>a1[i];
    for(int i = 0 ; i < m ; i++) cin>>a2[i];

    unordered_set<int> s1 ;
    unordered_set<int> s2 ;

    for(int i = 0 ; i < n ; i++){
        if(a1[i] <= k){
            s1.insert(a1[i]);
        }
    }
    for(int i = 0 ; i < m ; i++){
        if(a2[i] <= k){
            s2.insert(a2[i]);
        }
    }
    
    vector<int> arr1;
    vector<int> arr2;

    for(int x : s1) arr1.push_back(x);
    for(int x : s2) arr2.push_back(x);

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    unordered_set<int> s;
    for(int x : arr1) s.insert(x);
    for(int x : arr2) s.insert(x);

    if(arr1.size() < k/2) {
        cout<<"NO"<<endl;
        return;
    }
    if(arr2.size() < k/2) {
        cout<<"NO"<<endl;
        return;
    }

    int sum = 0;
    for(int x : s){
        sum += x;

    }
    int sum_needed = k * (k + 1);
    sum_needed /= 2;

    if(sum_needed == sum){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    
    

}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

