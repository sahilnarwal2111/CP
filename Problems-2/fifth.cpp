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

void solve() {   
    int n; cin>>n;
    string str ; cin>>str;
    int start = -1;
    for(int i = 0 ; i < n; i+=2){
        if(str[i]!= str[i+1]){
            start = i;
            break;
        }
    }
    int end = -1;
    for(int i = n - 1; i > 0 ; i = i - 2){
        if(str[i]!= str[i-1]){
            end = i;
            break;
        }
        
    }
    if(start == -1 || end == -1){
        cout<<0<<endl;
        return;
    }
    if(end == start + 1){
        cout<<1<<endl;
        cout<<start + 1<<endl;
        return;
    }
    int mid = (start + end) / 2;
    
    string s1 = "", s2 ="";
    for(int i =start ; i <= mid ; i++){
        s1 += str[i];
    }
    for(int i = mid + 1; i <= end; i++){
        s2 += str[i];
    }
    bool flag = true;
    int size = s1.size();
    if(s1[0] == s1[size-1]){
        for(int i = 0 ; i < size; i++){
            if(s1[i] != s2[size-1-i]){
                flag = false;
                break;
            }
        }
    }
    else if(s1[0] == s2[0]){
        for(int i = 0 ; i < size; i++){
            if(s1[i] != s2[i]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout<<size<<endl;
        for(int i = 0; i < 2 * size ;i+=2){
            cout<<(i+start + 1)<<" ";
        }
        cout<<endl;
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
