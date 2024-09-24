#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<numeric>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ios>
// #define ll long long
#define int long long
using namespace std;
 
void solve(){
    int n, rD;
    cin >> n >> rD;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    int cnt = 0;
    int l = 0, r = 0;
    for(r = 0; r < n ; r++){
        while(arr[r] - arr[l] > rD){
            cnt += (n - r);
            l++;
        }
    }   
    r = n - 1;
    while(l < r){
        if(arr[r] - arr[l] > rD){
            cnt += 1;
            l++;
        }else{
            break;
        }
    }
    cout << cnt << endl;    
    
}
 // 0 1 2 3 4 5
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    return 0;
}