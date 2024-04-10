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
#define mod (ll)(1e9+7)
#define int long long
#define ll long long
#define endl '\n'
using namespace std;

void solve() {  
  int n ; cin>>n;
  int sum ; cin>>sum;
  if(sum % 2 == 0){
    int arr[n];
    int q = sum/n;
    for(int i = 0; i < n ; i++) arr[i] =q ;
    int r = sum % n;
    if(r % 2 == 0){
      for(int i = 0 ; i < r ; i++){
        arr[i]++;
      }
      for(int i = 0 ; i < n ; i++) cout<<arr[i]<<" ";
      cout<<endl;
    }
    else{
      cout<<-1<<endl;
      return;
    } 
  }
  else{
    cout<<-1<<endl;
  }
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}