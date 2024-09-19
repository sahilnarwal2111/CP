#include<iostream>
#include <numeric>
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
//---------------Code-----------------------//



void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> arr(m);
    vector<pair<int,int>> que(q);
    for(auto &i : arr)
        cin >> i;
    for(int i = 0 ; i < q; i++){
        cin >> que[i].first;
        que[i].second = i;
    }
    sort(arr.begin(), arr.end());
    sort(que.begin(), que.end());

    int k = 0;
    vector<int> ans(q, -1);
    for(auto &p : que){
        int d = p.first;
        if(d > arr[m-1] || d < arr[0]){
            if(d > arr[m-1]){
                // cout << n - arr[m-1] << endl;
                ans[p.second] =  n - arr[m-1];

            }else{
                // cout << arr[0] - 1 << endl;
                ans[p.second] = arr[0] - 1;
            }

            continue;;
        }
        // need to find interval in which d lies
        while(k < m && arr[k] < d){
            k++;
        }

        int low = arr[k-1];
        int high = arr[k];
        int mid = (low + high) / 2;
        int diff = abs(d - mid);
        int x = min(d - low, high - d);

        if(d > mid && (low + high) % 2 == 1){
            x--;
        }
        ans[p.second] = diff + x;
        // cout << diff + x << endl;
    }
    for(auto &i : ans)
        cout << i << endl;
    


}



signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    // #endif

    int t;
    cin >> t;
    
    while(t--)
        solve();
    return 0;
}