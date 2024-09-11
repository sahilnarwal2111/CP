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

bool perfectSquare(int n){
    int low = 0, high = n;
    int mid;
    while (low <= high){
        mid = (low + high)/2;
        if(mid * mid == n) return 1;
        if(mid * mid > n){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 2; i <= n ; i++){
        int c = i;
        int b = i - 1;
        int cSq = i * i;
        int bSq = b * b;
        int aSq = cSq - bSq;
        
        if(perfectSquare(aSq)){
        cout<< aSq << " " << bSq << " " << cSq << endl;
            cnt++;
        }
    }
    
    cout << cnt << endl;
}
 

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}