#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
#define endl '\n'
#define int long long
using namespace std;

void solve(){
    int n, k; cin>>n>>k;
    int b = k /2;
    int f = k - b;
    
    int arr[n]; for(int i = 0 ; i < n ; i++ ) cin>>arr[i];

    int sunk = 0;
    int i = 0;
    while(i < n && sunk < n){
        if(arr[i] == f){
            sunk++;
            arr[i] = 0;
            f = 0;
            break;
        }
        else if(arr[i] > f){
            arr[i] = arr[i] -f;
            f =0 ;
            break;
        }
        else{
            f = f - arr[i];
            arr[i] = 0;
            sunk++;
        }
        i++;
    }
    int j = n-1;
    while(j >=0 && sunk < n){
        if(arr[j] == b){
            arr[j] = 0;
            b =0 ;
            sunk++;
            break;
        }
        else if(arr[j] > b){
            arr[j] = arr[j] - b;
            b =0;
            break;
        }
        else{
            b = b - arr[j];
            arr[j] = 0;
            sunk++;
        }
        j--;
    }
    cout<<sunk<<endl;
        

}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t ; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}