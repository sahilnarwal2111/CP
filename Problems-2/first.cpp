// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <cstdlib>
// #define mod (ll)(1e9+7)
// #define int long long
// #define endl '\n'
// using namespace std;
// void solve(){
//     int n, m; cin>>n>>m;
//     vector<int> arr(n,0) ;
//     for(int i = 0 ; i < n ; i++) cin>>arr[i];

//     for(int i = 0 ; i < arr.size(); i++){
//         if(arr[i] < m){
//             if(i + 1 < arr.size()){
//                 arr[i+1]+=arr[i];
//                 arr.erase(arr.begin() + i);
//                 i--; 
//             }
//         }
//     }
//     while(arr.size()>1 && arr[arr.size()-1] < m){
//         arr[arr.size()-2]+=arr[arr.size()-1];
//         arr.pop_back();
//     }
//     cout<<arr.size()<<endl;
// }
// signed main(){
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int t; cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
#define int long long
using namespace std;

void solve(){
    int n, m; 
    cin >> n >> m;
    vector<int> arr(n, 0);

    for(int i = 0 ; i < n ; i++) 
        cin >> arr[i];

    int result = 0;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] >= m) {
            result++;
            continue;
        }
        currentSum = arr[i];
        int j = i + 1;
        while(j < n && currentSum < m) {
            currentSum += arr[j++];
        }
        if(currentSum >= m) {
            result++;
            i = j - 1;
        }
    }

    cout << result << endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; 
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
