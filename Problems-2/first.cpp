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
#define int long long
#define endl '\n'
using namespace std;

bool vectSort(const vector<int>& v1, const vector<int>& v2){
    return v1[1] < v2[1];
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin>>t;
    while(t--){
        int n, p; cin>>n>>p;
        vector<vector<int> > arr(n,vector<int>(2,0));
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i][0];
        }
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i][1];
        }
        sort(arr.begin(), arr.end(), vectSort); 
        int cost = p;
        int itr = 0;
        for(int persons = 2; persons <= n ; persons++){
            if(arr[itr][0]>0){
                if(arr[itr][1]<p){
                    cost+=arr[itr][1];
                    arr[itr][0]--;
                }else{
                    cost+=p;
                }
            }else {
                itr++;
                persons--;
            }
        }
        cout<<cost<<endl;       
    }

    return 0;
}