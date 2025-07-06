// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#define double long double
#define endl "\n";
#define int long long
#define all(a) a.begin(), a.end()           
using namespace std;
bool func(string &str){
    for(auto &ch : str)
        if(ch == '1') return 1;
    return 0;
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<int> tmp(k);
        for(auto &j : tmp)
            cin >> j;
        arr[i] = tmp;
    }
    // sort(all(arr), [](vector<int> &v1, vector<int> &v2){
    //     return v1[0] < v2[0];
    // });
    int split = 0, combine = 0;
    // this is for internal dividing
    // vector<int> count(n, 0);
    // int idx =0 ;
    // for(auto &vec : arr){
    //     int sz  = vec.size();
    //     int cur = 0;
    //     for(int i = 1; i < sz; i++){
    //         if(vec[i - 1] > vec[i]){
    //             // we need to find index for vec[i-1] to be inserted
    //             if(vec[i-1] > vec.back()){
    //                 split++;
    //                 cur++;
    //             }else {
    //                 split += 2;
    //                 cur += 2;
    //             }
    //         }
    //     }
    //     // sort(all(vec));
    //     count[idx++] = cur;
    // }
    // for(auto vec : arr){
    //     for(auto i : vec)
    //         cout << i << " ";
    //     cout << endl;
    // }
    // for(auto i : count)
    //     cout << i << " ";
    // cout << endl;
    // for(int i = 1; i < n; i++){
    //     if(count[i] + 1 == arr[i].size() && arr[i].size() > 1) continue;
    //     if(arr[i-1].back() > arr[i][0]){
    //         split++;
    //     }
    // }
    split = 0;
    vector<pair<int,int>> vec;
    int counter = 0;
    for(auto v : arr)
        for(auto i : v)
            vec.push_back({i, counter++});
        
    sort(all(vec));
    for(auto p : vec){
        cout << p.first << " " << p.second << endl;
    }
    for(int i = 1; i < vec.size(); i++){
        if(vec[i].second != vec[i-1].second + 1) {
            split++;
            i++;
        }
    }
    cout << split << " " << n + split - 1 << endl;
        
}       
signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("sahil.txt", "w", stdout); 
    #endif 
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
}