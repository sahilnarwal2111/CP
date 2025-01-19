// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
#define int long long
#define endl "\n";
#define all(a) a.begin(), a.end()           
using namespace std;
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;     
        }
        base = (base * base) % mod; 
        exp /= 2; 
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    vector<pair<int,int>> ans;
    int idxOfNonZeroElement = -1;
    for(int i = 0; i < n; i++){
        if(arr[i]){
            idxOfNonZeroElement = i;
            break;
        }
    }
    if(idxOfNonZeroElement != -1){
        for(int i = 0 ; i < n; i++){
            if(arr[i] == 0){
                arr[i] = arr[idxOfNonZeroElement];
                ans.push_back({i + 1, idxOfNonZeroElement + 1});
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(arr[i - 1] > arr[i]){
            if(arr[i] < 0 && arr[i-1] < 0){
                // you have decrement arr[i-1]
                while(arr[i-1] > arr[i]){
                    arr[i-1] += arr[i];
                    ans.push_back({i, i + 1});
                }
            }else if(arr[i] > 0 && arr[i -1] > 0){
                // both are positive
                while(arr[i-1] > arr[i]){
                    arr[i] += arr[i-1];
                    ans.push_back({i + 1, i});
                }
            }else{
                // they are of different sign
                // if(arr[])
                while(arr[i-1] > arr[i]){
                    arr[i] += arr[i-1];
                    ans.push_back({i + 1, i});
                }
            }
        }
    }
    cout << ans.size() << endl;
    if(ans.size() > 31){
        cout << "Limit Exceeded !";
    }else{
        for(auto p : ans)
            cout << p.first << " " << p.second << endl;

    }
}


signed main(){
    int t;
    cin >> t;
    while(t--)
        solve();
   
    // cout << ceil(0.0 / 1.0) << endl;
}