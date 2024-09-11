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

bool check(int x, vector<int> & arr, bool answer){
    int n = arr.size();
    if(x > (n - 1) / 2) return false;

    vector<int>  tmp = arr;
    int cnt = 0;
    int k = 0;
    for(int i = 1; i < n && cnt < x; i+=2){
        tmp[i] = arr[k++];
    }

    k = n - 1;
    cnt = 0;
    for(int i = 0 ; i < n && cnt <= x ; i+= 2){
        tmp[i] = arr[k--];
    }
    bool flag = true;
    cnt = 0;
    for(int i = 1 ; i < n - 1; i++){
        if(tmp[i] < tmp[i-1] && tmp[i] < tmp[i+1])
            cnt++;
    }

    if(answer){
        for(auto &i : tmp){
            cout << i << " ";
        
        }
        cout << endl;
    }
    return cnt >= x;
}

void solve(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());

    int low = 0, high = n ;
    int mid ,ans;
    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid, arr, false)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }

    }
    cout << ans << endl;
    check(ans, arr, true);

    
    

}



signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    // int t;
    // cin >> t;
    
    // while(t--)
        solve();
    return 0;
}