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
#define int long long
#define ll long long
#define endl '\n'
using namespace std;
/// cd "/Users/sahilnarwal/Documents/CP/Problems-2/" && g++ --std=c++20 dijsktra.cpp -o dijsktra && "/Users/sahilnarwal/Documents/CP/Problems-2/"dijsktra
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


bool func(int x, vector<int>& cities, vector<int> & towers){
    // thinking of a two pointer approach
    
    int n = cities.size(), m = towers.size();
    
    int i = 0, j = 0;   
    while(i < n && j < m){
        int mini = towers[j] - x;
        int maxi = towers[j] + x;
        while(cities[i] >= mini && cities[i] <= maxi && i < n){
            i++;
        }
        j++;
    }
    return i >= n;
    
}
void solve(){
    int n, m ;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for(auto &i : arr1)
        cin >> i;
    for(auto &i : arr2)
        cin >> i;
    int low = 0, high = 1e18;
    int mid, ans;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    while(low <= high){
        mid = (low + high)/2;
        if(func(mid ,arr1, arr2)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << '\n';
}



signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--){
        solve();
    // }
    
    return 0;
}



